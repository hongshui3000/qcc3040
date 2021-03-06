/****************************************************************************
 * Copyright (c) 2011 - 2017 Qualcomm Technologies International, Ltd.
****************************************************************************/
/**
 * \file  opmgr.c
 * \ingroup  opmgr
 *
 * Operator Manager main file. <br>
 * This file contains the operator manager functionality <br>
 */

/****************************************************************************
Include Files
*/

#include "opmgr_private.h"

/****************************************************************************
Private Type Declarations
*/

/****************************************************************************
Private Constant Declarations
*/

/****************************************************************************
Private Macro Declarations
*/

/****************************************************************************
Private Variable Definitions
*/

/** Pointer to head of "local" operators list. If multicore, then all OpMgrs
 *  running on P0 and secondary Pn processors will see this in their own private DRAMs.
 */
OPERATOR_DATA* oplist_head = NULL;

/* Pointer to head of 'remote' operators list - only used by P0 OpMgr.
 * If separate images are built, then this is compiled out in P1, otherwise in
 * the case of common image, it will be present in P1 but not used.
 */
#if defined(SUPPORTS_MULTI_CORE)
/** P0 book keeping of remote ops on P1, this is not the same as P1 local op list!
 *  Unlike local op lists, this list will only point to 'core' op data objects,
 *  as operator extra data is not allocated on P0 for remote ops.
 */
DM_P0_RW_ZI OPERATOR_DATA* remote_oplist_head = NULL;
static OPERATOR_DATA* find_op_data_in_list(unsigned int id, OPERATOR_DATA* list_head);
#endif



/****************************************************************************
Private Function Declarations
*/

/****************************************************************************
Private Function Definitions
*/

/**
 * \brief Finds all operators connected to the source ep of operator A and request that
 * they no longer kick A.
 *
 * \param this_op The operator to that doesn't want to recieve kicks from
 * other operators any more.
 */
static void opmgr_stop_sources_being_kicked(OPERATOR_DATA *this_op)
{
    unsigned i;
    /* Go through all the connections and remove the connection from the
     * kick propagation table of the other operator */
    for (i = 0; i < this_op->cap_data->max_sources; i++)
    {
        ENDPOINT *ep = stream_get_connected_ep_from_id(opmgr_create_endpoint_id(INT_TO_EXT_OPID(this_op->id), i, SOURCE));

        if (ep != NULL)
        {
            unsigned ep_id = stream_ep_id_from_ep(ep);

            if ((ep_id & STREAM_EP_OP_BIT) != 0)
            {
                opmgr_kick_prop_table_remove(ep_id);
            }
            else
            {
                stream_disable_kicks_from_endpoint(ep);
            }

            /* The operator could be kicked by the tail sink endpoint (operator) of the
             * in place chain. */
            in_place_cancel_tail_kick(ep);
        }
    }
}


/**
 * \brief Finds all operators connected to the sink ep of operator A and request that
 * they no longer kick A.
 *
 * \param this_op The operator to that doesn't want to recieve kicks from
 * other operators any more.
 */
static void opmgr_stop_sinks_being_kicked(OPERATOR_DATA *this_op)
{
    unsigned i;
    /* Go through all the connections and remove the connection from the
     * kick propagation table of the other operator */
    for (i=0; i < this_op->cap_data->max_sinks; i++)
    {
        ENDPOINT *ep = stream_get_connected_ep_from_id(opmgr_create_endpoint_id(INT_TO_EXT_OPID(this_op->id), i, SINK));

        if (ep != NULL)
        {
            unsigned ep_id = stream_ep_id_from_ep(ep);

            if ((ep_id & STREAM_EP_OP_BIT) != 0)
            {
                opmgr_kick_prop_table_remove(ep_id);
            }
            else
            {
                stream_disable_kicks_from_endpoint(ep);
            }
        }
    }
}

/* \brief Count the number of operators with matching capability in a given list of operators.
 *        If capability ID is zero, count all operators.
 */
static unsigned opmgr_get_ops_count_in_oplist(unsigned int capid, OPERATOR_DATA* oplist)
{
    OPERATOR_DATA* cur_op;
    unsigned int op_count = 0;

    /* Patch point */
    patch_fn_shared(opmgr);

    /* Several callers will need a count of operators for a certain cap ID or count of all */
    /* operators. So pulling this down to this level, so all callers don't duplicate code. */
    /* For a zero capid, it will return number of all operators that are instantiated. */
    for( cur_op = oplist; cur_op != NULL; cur_op = cur_op->next )
    {
        if ( (capid == 0) || ((capid != 0) && (capid == cur_op->cap_data->id)) )
        {
            op_count++;
        }
    }
    return op_count;
}

/****************************************************************************
Public Function Definitions
*/

/*
 * opmgr_init
 * Dummy init functiom, needed by all static tasks
 */
void opmgr_task_init(void **data)
{
}

/****************************************************************************
 *
 * opmgr_lookup_cap_data_for_cap_id
 *
 */
const CAPABILITY_DATA* opmgr_lookup_cap_data_for_cap_id(CAP_ID cap_id)
{
    unsigned i;
    int num_caps;
    patch_fn_shared(opmgr);

    /* TODO: for the downloadable capabilities, this mechanism to move to a more
       dynamic one, where the static database PLUS any downloaded stuff gets counted nicely */
    for (num_caps = 0; capability_data_table[num_caps] != NULL; num_caps++);

    PL_PRINT_P1(TR_OPMGR, "Number of caps in cap data table: %d \n", num_caps);

    for(i=0; i < num_caps; i++)
    {
        if(capability_data_table[i]->id == cap_id)
        {
            return (capability_data_table[i]);
        }
    }
#ifdef INSTALL_CAP_DOWNLOAD_MGR
    DOWNLOAD_CAP_DATA_DB* cap_download_data_ptr =*cap_download_data_list; ;

    /* No static capability found, try searching in the download table */
    while ((cap_download_data_list != NULL) && (cap_download_data_ptr != NULL))
    {
        if ((cap_download_data_ptr->cap)->id == cap_id)
        {
            return cap_download_data_ptr->cap;
        }
        cap_download_data_ptr = cap_download_data_ptr->next;
    }
#endif
    return NULL;
}

#ifdef INSTALL_CAP_DOWNLOAD_MGR
/****************************************************************************
 *
 * opmgr_add_cap_download_data
 *
 */
bool opmgr_add_cap_download_data(CAPABILITY_DATA* cap_data)
{
    DOWNLOAD_CAP_DATA_DB* cap_download_data_ptr = *cap_download_data_list;
    DOWNLOAD_CAP_DATA_DB** cap_download_data_tmp = cap_download_data_list;

    patch_fn_shared(opmgr);

    /* Find tail */
    while ((cap_download_data_list != NULL) && (cap_download_data_ptr != NULL))
    {
        /* Save address where to store new entry */
        cap_download_data_tmp = &(cap_download_data_ptr->next);
        /* Check it doesn't exist already */
        if ((cap_download_data_ptr->cap)->id == cap_data->id)
        {
            return FALSE;
        }
        cap_download_data_ptr = cap_download_data_ptr->next;
    }
    /* Add new entry */
    *cap_download_data_tmp = xzpmalloc(sizeof(DOWNLOAD_CAP_DATA_DB));
    if ((*cap_download_data_tmp) == NULL)
    {
        return FALSE;
    }
    (*cap_download_data_tmp)->cap = cap_data;
    (*cap_download_data_tmp)->status = CAP_INSTALLED;
    (*cap_download_data_tmp)->next = NULL;
    return TRUE;
}

/****************************************************************************
 *
 * opmgr_remove_cap_download_data
 *
 */
bool opmgr_remove_cap_download_data(unsigned cap_id)
{
    DOWNLOAD_CAP_DATA_DB** cap_download_data_tmp = cap_download_data_list;
    DOWNLOAD_CAP_DATA_DB* cap_download_data_ptr = *cap_download_data_list;

    patch_fn_shared(opmgr);

    while ((cap_download_data_list != NULL) && (cap_download_data_ptr != NULL))
    {
        /* Find the capability with id cap_id */
        if ((cap_download_data_ptr->cap)->id == cap_id)
        {
            if ((cap_download_data_ptr->status != CAP_INSTALLED) && (cap_download_data_ptr->status != CAP_DOWNLOADED))
            {
                /* Capability in wrong state*/
                return FALSE;
            }
            else
            {
                *cap_download_data_tmp = cap_download_data_ptr->next;
                pfree(cap_download_data_ptr);
                return TRUE;
            }
        }
        else
        {
            cap_download_data_tmp = &(cap_download_data_ptr->next);
            cap_download_data_ptr = cap_download_data_ptr->next;
        }
    }
    /* Capability not found */
    return FALSE;
}

/****************************************************************************
 *
 * opmgr_get_download_cap_status
 *
 */
bool opmgr_get_download_cap_status(CAP_ID cap_id, CAP_DOWNLOAD_STATUS *status)
{
    DOWNLOAD_CAP_DATA_DB* cap_download_data_ptr = *cap_download_data_list;

    patch_fn_shared(opmgr);

    while ((cap_download_data_list != NULL) &&  (cap_download_data_ptr != NULL))
    {
        /* Find the capability with id cap_id */
        if ((cap_download_data_ptr->cap)->id == cap_id)
        {
            *status = cap_download_data_ptr->status;
            return TRUE;
        }
        else
        {
            cap_download_data_ptr = cap_download_data_ptr->next;
        }
    }
    /* Capability not found */
    return FALSE;
}

/****************************************************************************
 *
 * opmgr_set_download_cap_status
 *
 */
bool opmgr_set_download_cap_status(CAP_ID cap_id, CAP_DOWNLOAD_STATUS status)
{
    DOWNLOAD_CAP_DATA_DB* cap_download_data_ptr =  *cap_download_data_list;

    patch_fn_shared(opmgr);

    while ((cap_download_data_list != NULL) && (cap_download_data_ptr != NULL))
    {
        /* Find the capability with id cap_id */
        if ((cap_download_data_ptr->cap)->id == cap_id)
        {
            cap_download_data_ptr->status = status;
            return TRUE;
        }
        else
        {
            cap_download_data_ptr = cap_download_data_ptr->next;
        }
    }
    /* Capability not found */
    return FALSE;
}

bool opmgr_cap_is_instantiated(CAP_ID cap_id)
{
    if (opmgr_get_ops_count(cap_id) + opmgr_get_remote_ops_count(cap_id) > 0)
    {
        return TRUE;
    }
    return FALSE;
}
#endif /* INSTALL_CAP_DOWNLOAD_MGR */

/****************************************************************************
 *
 * opmgr_get_processing_time
 *
 * Return worst-case run time of selected operators, in microseconds.
 * (In practice, only used for SCO to-air, to ensure hard deadlines are met.)
 *
 * FIXME: it would be preferable if this weren't hardcoded.
 *
 */
unsigned int opmgr_get_processing_time(unsigned int sink_id, unsigned int words_to_process)
{
    /* Process time on local ops only */
    OPERATOR_DATA *cur_op = get_op_data_from_id(get_opid_from_opidep(sink_id));

    patch_fn_shared(opmgr);

    if (cur_op->cap_data->id == CAP_ID_SWBS_ENC)
    {
        /* 1400us is empirically enough for Crescendo SQIF @240MHz with a
         * full HFP graph (including cVc, which makes a difference).
         * 2000us is empirically enough for StrePlus SQIF @120MHz
         * in a simple graph without cVc (just AEC_REFERENCE). */
        return 2000;
    }
    else if (cur_op->cap_data->id == CAP_ID_WBS_ENC)
    {
        /* 1250us is empirically enough for StrePlus SQIF @32MHz with a
         * simple graph with just WBS operators and AEC_REFERENCE. */
        return 1250;
    }
    else if (cur_op->cap_data->id == CAP_ID_SCO_SEND)
    {
        /* 1300us is empirically enough for StrePlus SQIF @32MHz with a
         * simple graph with just NBS operators and AEC_REFERENCE.
         * (StrePlus SCO_SEND does more work than previous chips',
         * since it includes a CVSD encoder. FIXME: conditionalise
         * this on CVSD_CODEC_SOFTWARE?)
         * (Unfortunately, this is more than a Bluetooth slot-pair.)
         *
         * With the fix from B-280479, SCO_SEND can still miss the
         * deadline when set to 1300us, so changing this to 1400us. */
        return 1400;
    }
    else
    {
        /* Unsupported operator. */
        /* FIXME: we should probably complain or panic here. */
        return 0;
    }
}

/****************************************************************************
 *
 * opmgr_get_op_capid
 *
 */
unsigned int opmgr_get_op_capid(unsigned int ep_id)
{
    /* Look in local oplist. It actually is not used
     * by Streams or anyone currently.
     */
    OPERATOR_DATA *cur_op = get_op_data_from_id(get_opid_from_opidep(ep_id));
    if (cur_op == NULL)
    {
        /* This request only ever comes from Streams, so we should panic if we
         *  can't find the relevant operator. */
        PL_PRINT_P0(TR_OPMGR, "opmgr_get_op_capid: can't find operator\n");
        panic_diatribe(PANIC_AUDIO_OPERATOR_NOT_FOUND, ep_id);
    }

    return cur_op->cap_data->id;
}

/****************************************************************************
 *
 * opmgr_get_capid_from_opid
 *
 */
bool opmgr_get_capid_from_opid(unsigned opid, unsigned *capid)
{
    /* Look in local oplist. */
    OPERATOR_DATA *cur_op = get_op_data_from_id(EXT_TO_INT_OPID(opid));

    if (cur_op == NULL)
    {
        /* no operator with this opid found */
        return FALSE;
    }

    /* operator found, get the cap id from operator data */
    *capid =  cur_op->cap_data->id;
    return TRUE;
}

/****************************************************************************
 *
 * opmgr_get_ops_count
 *
 */
unsigned int opmgr_get_ops_count(CAP_ID capid)
{
    return opmgr_get_ops_count_in_oplist(capid, oplist_head);
}

#if defined(SUPPORTS_MULTI_CORE)
unsigned int opmgr_get_remote_ops_count(CAP_ID capid)
{
    return (PROC_PRIMARY_CONTEXT() ?
             opmgr_get_ops_count_in_oplist(capid, remote_oplist_head) : 0);
}

unsigned int opmgr_get_list_remote_ops_count(unsigned int num_ops,
                                             unsigned int *op_list,
                                             PROC_ID_NUM proc_id)
{
    unsigned int i, id;
    unsigned int n = 0;
    OPERATOR_DATA* entry;

    /* Patch point */
    patch_fn_shared(opmgr);

    for (i=0; i<num_ops; i++)
    {
        id = EXT_TO_INT_OPID(op_list[i]);
        entry = find_op_data_in_list(id, remote_oplist_head);
        n += ((entry != NULL)&&(entry->processor_id==proc_id));
    }

    return n;
}

PROC_ID_NUM opmgr_get_processor_id_from_opid(unsigned ext_opid)
{
    OPERATOR_DATA* op_data;

    op_data = get_anycore_op_data_from_id(EXT_TO_INT_OPID(ext_opid));
    if (op_data == NULL)
    {
        return PROC_PROCESSOR_INVALID;
    }

    return op_data->processor_id;
}

PROC_ID_NUM opmgr_get_processor_id(unsigned ep_id)
{
    OPERATOR_DATA* op_data;

    op_data = get_anycore_op_data_from_id(get_opid_from_opidep(ep_id));
    if (op_data == NULL)
    {
        return PROC_PROCESSOR_INVALID;
    }

    return op_data->processor_id;
}

/*
 * As it stands, it only gets op data from remote list of ops
 * (it only exists on P0 when separate images are built).
 * If we are on secondary core, and this gets called, it returns NULL.
 */
OPERATOR_DATA* get_remote_op_data_from_id(unsigned int id)
{
    return (PROC_PRIMARY_CONTEXT() ? find_op_data_in_list(id, remote_oplist_head) : NULL);
}
#endif /* defined(SUPPORTS_MULTI_CORE) */

/****************************************************************************
 *
 * opmgr_does_op_exist
 *
 */
bool opmgr_does_op_exist(void* op_data)
{
    OPERATOR_DATA* temp;

    patch_fn_shared(opmgr);

    if(op_data != NULL)
    {
        /**
         * Only look in local oplist. To look in oplists on multiple
         * cores, create a new function, but currently nothing needs
         * to use such a function.
         */
        for(temp = oplist_head; temp != NULL; temp = temp->next)
        {
            if (op_data == temp)
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

/****************************************************************************
 *
 * opmgr_get_op_task_from_epid
 *
 */
BGINT_TASK opmgr_get_op_task_from_epid(unsigned opidep)
{
    /* Only look at local list, as long as this is only called on OpMgr that
     * has tasks for local operators. Remote ones are kicked/poked differently,
     * not having tasks in OpMgr that is not local to those operators.
     */
    OPERATOR_DATA *cur_op = get_op_data_from_id(get_opid_from_opidep(opidep));

    if (cur_op)
    {
        BGINT_TASK bg;
        if (sched_find_bgint(cur_op->task_id, &bg))
        {
            return bg;
        }
    }

    return NULL;
}

/****************************************************************************
 *
 * opmgr_create_endpoint_id
 *
 */
unsigned int opmgr_create_endpoint_id(unsigned int opid, unsigned int idx,
                                         ENDPOINT_DIRECTION dir)
{
    unsigned int type;
    patch_fn_shared(opmgr);

    /* Validate opid */
    if ((opid & STREAM_EP_TYPE_MASK) != STREAM_EP_OP_BIT ||
        (opid & STREAM_EP_CHAN_MASK) != 0)
    {
        /* opid is invalid */
        PL_PRINT_P0(TR_STREAM, "opmgr_create_endpoint_id: opid is invalid\n");
        return 0;
    }

    /* Validate idx */
    if ((idx & ~STREAM_EP_CHAN_MASK) != 0)
    {
        /* idx is invalid */
        PL_PRINT_P0(TR_STREAM, "opmgr_create_endpoint_id: idx is invalid\n");
        return 0;
    }

    /* Derive operator type bits from direction */
    type = (dir == SOURCE) ? STREAM_EP_OP_SOURCE : STREAM_EP_OP_SINK;

    /* Generate the external operator endpoint id */
    return (type | opid | idx);
}

/****************************************************************************
*
* opmgr_set_kick_flags
*
*/

void opmgr_stop_kicks(unsigned int op_id, STOP_KICK side)
{
    OPERATOR_DATA *cur_op;
    patch_fn_shared(opmgr);

    /* Look in local op lists: judging from its use, i.e. on graphs,
     * it should  only look in local list - Stream and OpMgr will act
     * on actual ops in their own (local) graph.
     */
    cur_op = get_op_data_from_id(op_id);

    if (cur_op == NULL)
    {
        /* This request only ever comes from Streams, so we should panic if we
         *  can't find the relevant operator. */
        PL_PRINT_P0(TR_OPMGR, "Can't find op_id!\n");
        panic_diatribe(PANIC_AUDIO_OPERATOR_NOT_FOUND, op_id);
    }
    else
    {
        cur_op->stop_chain_kicks = side;
        /* If there are already other operators connected to this operator then
         * we need to tell all of them to stop kicking this capability. */
        if (side == SOURCE_SIDE)
        {
            /* disable the sources being kicked. */
            opmgr_stop_sources_being_kicked(cur_op);
        }
        else if (side == SINK_SIDE)
        {
            /* disable the sinks being kicked. */
            opmgr_stop_sinks_being_kicked(cur_op);
        }
        else /* BOTH_SIDES */
        {
            opmgr_stop_sources_being_kicked(cur_op);
            opmgr_stop_sinks_being_kicked(cur_op);
        }
    }
}

/****************************************************************************
*
* opmgr_get_num_sink_terminals
*
*/
unsigned opmgr_get_num_sink_terminals(unsigned opid)
{
    OPERATOR_DATA *cur_op;
    unsigned num_sinks = 0;

    opid = EXT_TO_INT_OPID(opid);

    /*
     * Stream and OpMgr will act on
     * actual ops in their own (local) graph.
     */
    cur_op = get_anycore_op_data_from_id(opid);

    if( cur_op != NULL )
    {
        num_sinks = cur_op->cap_data->max_sinks;
    }

    return num_sinks;
}

unsigned opmgr_get_num_source_terminals(unsigned opid)
{
    OPERATOR_DATA *cur_op;
    unsigned num_sources = 0;

    opid = EXT_TO_INT_OPID(opid);

    /*
     * Stream and OpMgr will act on
     * actual ops in their own (local) graph.
     */
    cur_op = get_anycore_op_data_from_id(opid);

    if( cur_op != NULL )
    {
        num_sources = cur_op->cap_data->max_sources;
    }

    return num_sources;
}

bool opmgr_get_max_sources_and_sinks_for_cap_id(CAP_ID capid, uint16 *max_sources, uint16 *max_sinks)
{
    const CAPABILITY_DATA *cap_info;

    if ((max_sources == NULL) || (max_sinks == NULL))
    {
        return FALSE;
    }

    /* Get the cap data based on the ID */
    cap_info = opmgr_lookup_cap_data_for_cap_id(capid);
    if (cap_info == NULL)
    {
        return FALSE;
    }

    *max_sources = (uint16)cap_info->max_sources;
    *max_sinks = (uint16)cap_info->max_sinks;

    return TRUE;
}

#ifdef PROFILER_ON
/**
 * opmgr_get_operator_mips
 */
unsigned opmgr_get_operator_mips(unsigned op_id)
{

    /* Lookup the first operator */
    /* Only looking at specific processor */
    OPERATOR_DATA *op = get_op_data_from_id(EXT_TO_INT_OPID(op_id));
    if ((op != NULL) && (op->profiler != NULL))
    {
        return op->profiler->cpu_fraction;
    }
    else
    {
        return INVALID_MIPS_USAGE;
    }
}
#endif
/****************************************************************************
Private Function Definitions
*/

/**
 * \brief Tell streams to kill the operator endpoints before the operator is destroyed.
 *        It is possible that return value and/or more arguments would be needed in future.
 *
 * \param  op_data Pointer to the operator data for the operator.
 *
 *  \return True if the operation was successful, False otherwise.
 */
bool opmgr_destroy_op_endpoints(OPERATOR_DATA* op_data)
{
    /* An operator can only be destroyed if it is stopped. So check this and
     * fail the command before any state gets torn down.
     */
    /* Operator is created remotely - NOTE: we should not end up here on a
     * secondary OpMgr with processor_id set to 0 (primary)! */
    if (PROC_ON_SAME_CORE(op_data->processor_id))
    {
        if (OP_RUNNING == op_data->state)
        {
            return FALSE;
        }
    }
    else
    {
        /* Operator not on this core (which is executing this).
           That is, on P0 and operator is on Px. Nothing to do
           in this case. Or on Px and operator is on P0 - but
           this should never happen, guaranteed by the aggregate
           function on P0, which forwards Px-only reqs to Px.
           Nothing to do, so avoid going through stream_destroy_
           all_operators_endpoints, and return TRUE here.
        */
        return TRUE;
    }

    /* It is important to destroy the sinks first as we probably need to traverse
     * the graph to work out what the current topology is. If the sources went
     * first then we might end up with a chain flopping around we don't know about.
     */
    return stream_destroy_all_operators_endpoints(INT_TO_EXT_OPID(op_data->id),
                                                    op_data->cap_data->max_sinks,
                                                    op_data->cap_data->max_sources);
}


static OPERATOR_DATA* find_op_data_in_list(unsigned int id, OPERATOR_DATA* list_head)
{
    OPERATOR_DATA* entry = list_head;

    while ((entry != NULL) && (entry->id != id))
    {
        entry = entry->next;
    }

    return entry;
}

/****************************************************************************
 *
 * get_op_data_from_id
 *
 * SINGLECORE: it searches local list and return the entry.
 * MULTICORE: it searches in local and remote op lists and return the entry.
 *            (It only exist on P0 when separate image is built).
 */
OPERATOR_DATA* get_op_data_from_id(unsigned int id)
{
    OPERATOR_DATA* entry = find_op_data_in_list(id, oplist_head);
    return entry;
}

/****************************************************************************
 *
 * get_anycore_op_data_from_id
 *
 * SINGLECORE: it searches local list and return the entry.
 * MULTICORE: it searches in local and remote op lists and return the entry.
 *            (It only exist on P0 when separate image is built).
 */
OPERATOR_DATA* get_anycore_op_data_from_id(unsigned int id)
{
    OPERATOR_DATA* entry = find_op_data_in_list(id, oplist_head);

    /* If we are on P0, and haven't found in local list then look among remote ops */
    if (PROC_PRIMARY_CONTEXT() && (entry == NULL))
    {
        entry = find_op_data_in_list(id, remote_oplist_head);
    }
    return entry;
}

/**
 * \brief    Remove the operator data from the operator list
 *
 * \param    id  operator id
 */
void remove_op_data_from_list(unsigned int id, OPERATOR_DATA** op_list)
{
    OPERATOR_DATA **p, *cur_op;
    patch_fn_shared(opmgr);

    /* Delete the entry from remote operator list */
    cur_op = find_op_data_in_list(id, *op_list);

    if(cur_op != NULL)
    {
        p = op_list;
        while(*p && *p != cur_op) p = &((*p)->next);
        if(*p)
        {
            *p = cur_op->next;
            pfree(cur_op);
        }
    }
    else
    {
        /* This indicates something has corrupted the list.*/
        panic_diatribe(PANIC_AUDIO_OPERATOR_NOT_FOUND, id);
    }

}

/****************************************************************************
 *
 * is_op_running
 *
 */
bool is_op_running(unsigned int op_id)
{
    OPERATOR_DATA* operator = get_anycore_op_data_from_id(op_id);
    if (operator)
    {
        if ((operator->state) == OP_RUNNING)
        {
            return TRUE;
        }
    }
    /* The operator doesn't exist or it's not running*/
    return FALSE;
}

/****************************************************************************
 *
 * get_is_source_from_opidep
 *
 */
bool get_is_source_from_opidep(unsigned int opidep)
{
    return ((opidep & STREAM_EP_TYPE_MASK) == STREAM_EP_OP_SOURCE);
}

/****************************************************************************
 *
 * get_is_sink_from_opidep
 *
 */
bool get_is_sink_from_opidep(unsigned int opidep)
{
    return ((opidep & STREAM_EP_TYPE_MASK) == STREAM_EP_OP_SINK);
}

/****************************************************************************
 *
 * get_opid_from_opidep
 *
 */
unsigned int get_opid_from_opidep(unsigned int opidep)
{
    return ((opidep & STREAM_EP_OPID_MASK) >> STREAM_EP_OPID_POSN);
}

/****************************************************************************
 *
 * get_ext_opid_from_opidep
 *
 */
unsigned int get_ext_opid_from_opidep(unsigned int opidep)
{
    return INT_TO_EXT_OPID(get_opid_from_opidep(opidep));
}

/****************************************************************************
 *
 * get_terminal_from_opidep
 *
 */
unsigned int get_terminal_from_opidep(unsigned int opidep)
{
    return ((opidep & STREAM_EP_CHAN_MASK) >> STREAM_EP_CHAN_POSN);
}

/****************************************************************************
 *
 * get_opidep_from_opid_and_terminal
 *
 */
unsigned int get_opidep_from_opid_and_terminalid(unsigned int op_id, unsigned int terminal_id)
{
    unsigned int id = ((terminal_id & STREAM_EP_CHAN_MASK) | ((op_id<<STREAM_EP_OPID_POSN) & STREAM_EP_OPID_MASK));

    if(terminal_id&TERMINAL_SINK_MASK)
    {
        id |= STREAM_EP_OP_SINK;
    }
    else
    {
        id |= STREAM_EP_OP_SOURCE;
    }
    return id;
}

/****************************************************************************
 * opmgr_is_opidep_valid
 */
bool opmgr_is_opidep_valid(unsigned int opidep)
{
    unsigned terminal_num = get_terminal_from_opidep(opidep);
    OPERATOR_DATA *op_data = get_anycore_op_data_from_id(get_opid_from_opidep(opidep));

    /* If the operator exists and the terminal id is within range of the maximum
     * number of sinks/sources then it is valid. */
    if (op_data != NULL)
    {
        if ((get_is_sink_from_opidep(opidep)) != 0)
        {
            if (terminal_num < op_data->cap_data->max_sinks)
            {
                return TRUE;
            }
        }
        else
        {
            if (terminal_num < op_data->cap_data->max_sources)
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}

/****************************************************************************
 *
 * get_ext_opid_from_int
 *
 */
unsigned int get_ext_opid_from_int(unsigned int opid)
{
    return (((opid << STREAM_EP_OPID_POSN) & STREAM_EP_OPID_MASK) |
            STREAM_EP_OP_BIT );
}

/**
 * \brief   Sets the creator client id for all operators in an array.
 *          Panics if an operator in the list is not found.
 * \param   client_id Client id of the owner and creator
 * \param   num_ops Number of required operators
 * \param   op_array Array of ids of the required operators.
 */
void opmgr_set_creator_id(CONNECTION_PEER client_id,
                          unsigned num_ops,
                          const EXT_OP_ID *op_list)
{
    CONNECTION_LINK con_id;
    unsigned i;
    OPERATOR_DATA * op_data;
    for (i = 0; i < num_ops; i++)
    {
        INT_OP_ID op_id = EXT_TO_INT_OPID(op_list[i]);
        op_data = get_anycore_op_data_from_id(op_id);
        if (op_data == NULL)
        {
            panic_diatribe(PANIC_AUDIO_OPERATOR_NOT_FOUND, op_list[i]);
        }
        LOCK_INTERRUPTS;
        op_data->creator_client_id = client_id;
        con_id = PACK_CON_ID((CONNECTION_PEER) client_id,
                             GET_CON_ID_RECV_ID(op_data->con_id));
        op_data->con_id = con_id;
        UNLOCK_INTERRUPTS;
    }
}

const OP_UNSOLICITED_MSG * opmgr_make_simple_unsolicited_message(unsigned op_id,
                                                                 CONNECTION_PEER client_id,
                                                                 unsigned msg_id,
                                                                 unsigned *length)
{
    OP_UNSOLICITED_MSG * msg;
    msg = pnew(OP_UNSOLICITED_MSG);
    msg->op_id = op_id;
    msg->client_id = (unsigned) client_id;
    msg->msg_id= msg_id;
    msg->length = 0;
    *length = UNSOLICITED_MSG_HEADER_SIZE;
    return msg;
}

/*
 *  \brief construct a simple unsolicited message without a payload
 *  \param op_id operator id
 *  \param client_id the external owner's client id, 0xFF if invalid.
 *  \param msg_id message id
 *  \param msg_len message payload length in words
 *  \param msg_id message payload
 *  \param pointer to the length of the message constructed
 */
const OP_UNSOLICITED_MSG * opmgr_make_unsolicited_message(unsigned op_id,
                                                          CONNECTION_PEER client_id,
                                                          unsigned msg_id,
                                                          unsigned msg_len,
                                                          unsigned *msg_body,
                                                          unsigned *length)
{
    OP_UNSOLICITED_MSG * msg;
    *length = sizeof(OP_UNSOLICITED_MSG)/sizeof(unsigned) +msg_len;
    msg = (OP_UNSOLICITED_MSG *) pnewn(*length, unsigned);
    msg->op_id = op_id;
    msg->client_id = (unsigned) client_id;
    msg->msg_id= msg_id;
    msg->length = msg_len;
    memcpy(msg->payload, msg_body, msg_len * sizeof(unsigned));
    return msg;
}

OPMGR_ADAPTOR_MSG opmgr_get_adaptor(CONNECTION_LINK con_id)
{
    return (OPMGR_ADAPTOR_MSG) adaptor_get_target(con_id);
}

bool opmgr_get_generic_value_from_operator(unsigned int endpoint_id,
                                           OPMSG_CONFIGURATION_KEYS key,
                                           uint32 *result)
{
    OPMSG_GET_CONFIG_RESULT get_config_result;
    bool success;

    get_config_result.value = 0;
    success = opmgr_get_config_msg_to_operator(endpoint_id,
                                               key,
                                               &get_config_result);
    *result = get_config_result.value;
    return success;
}

void opmgr_get_terminal_details_from_operator(unsigned int endpoint_id,
                                              uint32 *result)
{
    OPMSG_GET_CONFIG_RESULT get_config_result;

    get_config_result.value = OPMSG_GET_CONFIG_TERMINAL_DETAILS_NONE;
    opmgr_get_config_msg_to_operator(endpoint_id,
                                     OPMSG_OP_TERMINAL_DETAILS,
                                     &get_config_result);
    *result = get_config_result.value;
}

bool opmgr_get_ratematch_measure_from_operator(unsigned int endpoint_id,
                                               int *sp_deviation,
                                               RATE_RELATIVE_RATE *measurement)
{
    OPMSG_GET_CONFIG_RESULT msg_result;
    bool success;
    msg_result.value = 0;

    success = opmgr_get_config_msg_to_operator(endpoint_id,
                                               OPMSG_OP_TERMINAL_RATEMATCH_MEASUREMENT,
                                               &msg_result);

    *sp_deviation = msg_result.rm_measurement.sp_deviation;
    *measurement = msg_result.rm_measurement.measurement;
    return success;
}

