/*!
\copyright  Copyright (c) 2018 Qualcomm Technologies International, Ltd.\n
            All Rights Reserved.\n
            Qualcomm Technologies International, Ltd. Confidential and Proprietary.
\file       rules_engine.c
\brief	    Engine for processing application defined rules.
*/

#include <stdlib.h>

#include <vmtypes.h>
#include <panic.h>

#include <logging.h>
#include <system_clock.h>

#include "rules_engine.h"

/*! \{
    Macros for diagnostic output that can be suppressed.
    Allows debug of the rules module at two levels. */
#define RULES_LOG_INFO(...)       //DEBUG_LOG(__VA_ARGS__)

#define RULES_LOG(...)         DEBUG_LOG(__VA_ARGS__)
/*! \} */

/* Enable logging of the time taken to run rules */
//#define RULES_ENGINE_TIMING_LOG_ENABLED

/*! Macro to split a uint64 into 2 uint32 that the debug macro can handle. */
#define PRINT_ULL(x)   ((uint32)(((x) >> 32) & 0xFFFFFFFFUL)),((uint32)((x) & 0xFFFFFFFFUL))


/*! \brief Current rule status */
typedef enum
{
    /*! rule has not been processed at all */
    rule_status_not_done,
    /*! rule has been called, but did not generated an action */
    rule_status_ignored,
    /*! rule has been called, generated an action, but has not yet been completed */
    rule_status_in_progress,
    /*! rule has been called, generated an action and completed */
    rule_status_complete,
    /*! rule has been called, did not generate an action at this time due to incomplete
        rule preconditions, the rule must be reevaluated when subsequent events occur. */
    rule_status_deferred
} rule_status_t;

/*! \brief The current state of a single rule */
typedef struct
{
    rule_status_t status;
} rule_state_t;

/*! \brief A complete rule set object (rules + state). */
struct rule_set_tag
{
    /*! Set of active events */
    rule_events_t events;

    /*! Set of rules. */
    const rule_entry_t *rules;
    /*! Number of rules in the set. */
    size_t rules_count;

    /*! Current state of each rule */
    rule_state_t *rules_state;

    /*! Message contents data for rules that wish to run with parameters. */
    void* rule_message_data;
    /*! Size of the data in #rule_message_data */
    size_t size_rule_message_data;

    /*! Client task to send the event generated by a rule to. */
    Task event_task;

    /*! Set of tasks registered to receive notification that rules are
     *  no longer in progress. */
    task_list_t nop_tasks;

    /*! MessageId to send to Tasks in the #nop_tasks list when rules are
     *  no longer in progress. */
    MessageId nop_message_id;
};


/*****************************************************************************/

/*! \brief Directly set the status of a rule.
    Guards against setting the status of a rule that carrys the
    rule_flag_always_evaluate property.

    \param rule Rule to set status for.
    \param new_status Status to set.
*/
static void RulesEngine_SetRuleStatus(const rule_entry_t *rule, rule_state_t *rule_state, rule_status_t new_status)
{
    if (rule->flags == rule_flag_always_evaluate)
    {
        RULES_LOG("Cannot set status of rule_flag_always_evaluate rule");
        Panic();
    }
    else
    {
        rule_state->status = new_status;
    }
}

/*! \brief Update the status of a rule.
    \return bool TRUE if the status of a rule was updated, FALSE otherwise.

    This function will also check if all rules for an event are now complete,
    i.e. rule_status_complete, if so it will automatically clear that event.
*/
static bool RulesEngine_UpdateRuleStatus(rule_set_t rule_set, MessageId message, rule_status_t status, rule_status_t new_status, rule_events_t event)
{
    int rule_index;
    rule_events_t event_mask = 0;
    bool did_set_status = FALSE;

    for (rule_index = 0; rule_index < rule_set->rules_count; rule_index++)
    {
        const rule_entry_t *rule = &rule_set->rules[rule_index];
        rule_state_t *rule_state = &rule_set->rules_state[rule_index];
        if ((rule->message == message) && (rule_state->status == status) && (rule->events & event))
        {
            RULES_LOG_INFO("RulesEngine_SetStatus, rule %d, status %d", rule_index, new_status);
            RulesEngine_SetRuleStatus(rule, rule_state, new_status);
            did_set_status = TRUE;
            /* Build up set of events where rules are complete */
            event_mask |= rule->events;
        }
    }

    /* Check if all rules for an event are now complete, if so clear event */
    for (rule_index = 0; rule_index < rule_set->rules_count; rule_index++)
    {
        const rule_entry_t *rule = &rule_set->rules[rule_index];
        rule_state_t *rule_state = &rule_set->rules_state[rule_index];
        if (rule->events & event)
        {
            /* Clear event if this rule is not complete */
            if (rule_state->status != rule_status_complete)
                event_mask &= ~rule->events;
        }
    }

    if (event_mask)
    {
        RULES_LOG_INFO("RulesEngine_SetStatus, event %08lx%08lx complete", PRINT_ULL(event_mask));
        RulesEngine_ResetEvent(rule_set, event_mask);
    }

    return did_set_status;
}

/*! \brief Run a single rule */
static rule_action_t RulesEngine_RunRule(rule_set_t rule_set, int rule_index)
{
    const rule_entry_t *rule = &rule_set->rules[rule_index];
#ifdef RULES_ENGINE_TIMING_LOG_ENABLED
    rtime_t start = SystemClockGetTimerTime();
    rule_action_t action = rule->rule();
    rtime_t finish = SystemClockGetTimerTime();
    RULES_LOG("RulesEngine_Check timing rule %d took %u us", rule_index, rtime_sub(finish, start));
    return action;
#else
    return rule->rule();
#endif
}

/*! \brief Run all the rules */
static void RulesEngine_RunRules(rule_set_t rule_set)
{
    int rule_index;
    rule_events_t events = rule_set->events;

    RULES_LOG_INFO("RulesEngine_RunRules, starting events %08lx%08lx", PRINT_ULL(events));

    for (rule_index = 0; rule_index < rule_set->rules_count; rule_index++)
    {
        const rule_entry_t *rule = &rule_set->rules[rule_index];
        rule_state_t *rule_state = &rule_set->rules_state[rule_index];
        rule_action_t action;

        /* On check rules that match event */
        if ((rule->events & events) == rule->events ||
             rule->flags == rule_flag_always_evaluate)
        {
            /* Skip rules that are now complete */
            if (rule_state->status == rule_status_complete)
                continue;

            /* Stop checking rules for this event if rule is in progress */
            if (rule_state->status == rule_status_in_progress)
            {
                events &= ~rule->events;
                RULES_LOG_INFO("RulesEngine_RunRules, in progress, filtered events %08lx%08lx", PRINT_ULL(events));
                continue;
            }

            /* Run the rule */
            RULES_LOG_INFO("RulesEngine_RunRules, running rule %d, status %d, events %08lx%08lx",
                                                    rule_index, rule_state->status, PRINT_ULL(events));
            action = RulesEngine_RunRule(rule_set, rule_index);

            /* handle result of the rule */
            if ((action == rule_action_run) ||
                (action == rule_action_run_with_param))
            {
                RULES_LOG_INFO("RulesEngine_RunRules, rule in progress");

                /* mark rule as in progress, but not if this is an always
                 * evaluate rule */
                if (rule->flags != rule_flag_always_evaluate)
                {
                    RulesEngine_SetRuleStatus(rule, rule_state, rule_status_in_progress);
                }

                /* Send rule message to tasks in list. */
                if (action == rule_action_run)
                {
                    PanicFalse(rule_set->size_rule_message_data == 0);
                    PanicFalse(rule_set->rule_message_data == NULL);

                    /* for no parameters just send the message with id */
                    MessageSend(rule_set->event_task, rule->message, NULL);
                }
                else if (action == rule_action_run_with_param)
                {
                    PanicFalse(rule_set->size_rule_message_data != 0);
                    PanicFalse(rule_set->rule_message_data != NULL);

                    /* for rules with parameters, use the message data that
                     * the rule will have placed in conn_rules already */
                    MessageSend(rule_set->event_task, rule->message, rule_set->rule_message_data);

                    /* do not need to free rule_message_data, it has been
                     * used in the message system and will be freed once
                     * automatically once delivered, just clean up local
                     * references */
                    rule_set->rule_message_data = NULL;
                    rule_set->size_rule_message_data = 0;
                }

                /* Stop checking rules for this event
                 * we only want to continue processing rules for this event after
                 * it has been marked as completed */
                if (rule->flags != rule_flag_always_evaluate)
                    events &= ~rule->events;
                continue;
            }
            else if (action == rule_action_complete)
            {
                RULES_LOG_INFO("RulesEngine_RunRules, rule complete");
                if (rule->flags != rule_flag_always_evaluate)
                    RulesEngine_UpdateRuleStatus(rule_set, rule->message, rule_state->status, rule_status_complete, rule->events);
            }
            else if (action == rule_action_ignore)
            {
                RULES_LOG_INFO("RulesEngine_RunRules, rule ignored");
                if (rule->flags != rule_flag_always_evaluate)
                    RulesEngine_UpdateRuleStatus(rule_set, rule->message, rule_state->status, rule_status_complete, rule->events);
            }
            else if (action == rule_action_defer)
            {
                RULES_LOG_INFO("RulesEngine_RunRules, rule deferred");
                RulesEngine_SetRuleStatus(rule, rule_state, rule_status_deferred);
            }
        }
    }
}

static void RulesEngine_Check(rule_set_t rule_set)
{
#ifdef RULES_ENGINE_TIMING_LOG_ENABLED
    rtime_t start = SystemClockGetTimerTime();
    RulesEngine_RunRules(rule_set);
    rtime_t finish = SystemClockGetTimerTime();
    RULES_LOG("RulesEngine_Check timing total run time %u us", rtime_sub(finish, start));
#else
    RulesEngine_RunRules(rule_set);
#endif
}

/*****************************************************************************/

/*! \brief Initialise a rule set with the given rules. */
rule_set_t RulesEngine_CreateRuleSet(const rule_set_init_params_t *params)
{
    PanicNull((rule_set_init_params_t *)params);
    PanicNull(params->event_task);

    rule_set_t rule_set = PanicUnlessMalloc(sizeof(*rule_set));
    memset(rule_set, 0, sizeof(*rule_set));

    rule_set->events = 0;
    rule_set->rules = params->rules;
    rule_set->rules_count = params->rules_count;
    rule_set->rules_state = PanicUnlessMalloc(sizeof(*rule_set->rules_state) * params->rules_count);
    for (int i = 0; i < rule_set->rules_count; i++)
    {
        rule_set->rules_state[i].status = rule_status_not_done;
    }
    TaskList_Initialise(&rule_set->nop_tasks);
    rule_set->nop_message_id = params->nop_message_id;
    rule_set->event_task = params->event_task;

    return rule_set;
}

/*! \brief Free any resources used by a rule set. */
void RulesEngine_DestroyRuleSet(rule_set_t rule_set)
{
    TaskList_RemoveAllTasks(&rule_set->nop_tasks);
    free(rule_set->rules_state);
    free(rule_set);
}

/*! \brief Set an event or events */
void RulesEngine_SetEvent(rule_set_t rule_set, rule_events_t event_mask)
{
    rule_set->events |= event_mask;
    RULES_LOG_INFO("RulesEngine_SetEvent, new event %08lx%08lx, events %08lx%08lx", PRINT_ULL(event_mask), PRINT_ULL(rule_set->events));

    RulesEngine_Check(rule_set);
}

/*! \brief Reset/clear an event or events */
void RulesEngine_ResetEvent(rule_set_t rule_set, rule_events_t event)
{
    int rule_index;

    rule_set->events &= ~event;
    //RULES_LOG_INFO("RulesEngine_ResetEvent, new event %08lx%08lx, events %08lx%08lx", PRINT_ULL(event), PRINT_ULL(rule_set->events));

    /* Walk through matching rules resetting the status */
    for (rule_index = 0; rule_index < rule_set->rules_count; rule_index++)
    {
        const rule_entry_t *rule = &rule_set->rules[rule_index];
        rule_state_t *rule_state = &rule_set->rules_state[rule_index];

        if (rule->events & event
            && rule->flags != rule_flag_always_evaluate)
        {
            //RULES_LOG_INFO("RulesEngine_ResetEvent, resetting rule %d", rule_index);
            RulesEngine_SetRuleStatus(rule, rule_state, rule_status_not_done);
        }
    }
}

/*! \brief Get set of active events */
rule_events_t RulesEngine_GetEvents(rule_set_t rule_set)
{
    return rule_set->events;
}

/*! \brief Mark rules as complete from messaage ID */
void RulesEngine_SetRuleComplete(rule_set_t rule_set, MessageId message)
{
    RulesEngine_SetRuleWithEventComplete(rule_set, message, RULE_EVENT_ALL_EVENTS_MASK);
}

/*! \brief Mark rules as complete from message ID and set of events */
void RulesEngine_SetRuleWithEventComplete(rule_set_t rule_set, MessageId message, rule_events_t event)
{
    bool did_complete_in_progress_rule = RulesEngine_UpdateRuleStatus(rule_set, message, rule_status_in_progress, rule_status_complete, event);

    /* if we have just completed a previously 'in-progress' rule and there
     * are no more rules in-progress (for which rule_flag_progress_matters
     * is set) then indicate to registered clients that the rules engine
     * has nothing in progress */
    if (did_complete_in_progress_rule &&
        !RulesEngine_InProgress(rule_set))
    {
        TaskList_MessageSendId(&rule_set->nop_tasks, rule_set->nop_message_id);
    }

    RulesEngine_Check(rule_set);
}

/*! \brief Copy rule param data for the engine to put into action messages. */
void RulesEngine_CopyRunParams(rule_set_t rule_set, const void* param, size_t size_param)
{
    PanicNotNull(rule_set->rule_message_data);

    rule_set->rule_message_data = PanicUnlessMalloc(size_param);
    rule_set->size_rule_message_data = size_param;
    memcpy(rule_set->rule_message_data, param, size_param);
}

/*! \brief Determine if there are still rules in progress. */
bool RulesEngine_InProgress(rule_set_t rule_set)
{
    int rule_index;
    bool rc = FALSE;

    for (rule_index = 0; rule_index < rule_set->rules_count; rule_index++)
    {
        const rule_entry_t *rule = &rule_set->rules[rule_index];
        rule_state_t *rule_state = &rule_set->rules_state[rule_index];

        if ((rule->flags == rule_flag_progress_matters) &&
            (rule_state->status == rule_status_in_progress))
        {
            RULES_LOG("RulesEngine_InProgress rule %u in progress", rule_index);
            rc = TRUE;
        }
    }
    return rc;
}

/*! \brief Register a task to receive notifications that no rules are in progress. */
void RulesEngine_NopClientRegister(rule_set_t rule_set, Task task)
{
    TaskList_AddTask(&rule_set->nop_tasks, task);
}
