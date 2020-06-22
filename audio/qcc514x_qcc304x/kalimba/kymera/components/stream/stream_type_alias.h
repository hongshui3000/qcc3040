/****************************************************************************
 * Copyright (c) 2011 - 2019 Qualcomm Technologies International, Ltd.
****************************************************************************/
/**
 * \defgroup stream Stream Subsystem
 *
 * \file  stream_type_alias.h
 *
 * Public header file for stream types.
 * Currently just aliases ACCMD types.
 *
 */

#ifndef STREAM_TYPE_ALIAS_H
#define STREAM_TYPE_ALIAS_H

/****************************************************************************
Include Files
*/

#if defined(CHIP_BASE_HYDRA)
#include "accmd_prim.h"
typedef ACCMD_CONFIG_KEY STREAM_CONFIG_KEY;
#endif

/****************************************************************************
Public Type Declarations
*/

/**
 * ACCMD types are hidden from stream by using typedef aliases
 */

#if defined(CHIP_BASE_HYDRA)
#define STREAM_CONFIG_KEY_STREAM_AUDIO_DISABLE_ENDPOINT_PROCESSING \
         ACCMD_CONFIG_KEY_STREAM_AUDIO_DISABLE_ENDPOINT_PROCESSING
#define STREAM_CONFIG_KEY_STREAM_AUDIO_SAMPLE_PERIOD_DEVIATION \
         ACCMD_CONFIG_KEY_STREAM_AUDIO_SAMPLE_PERIOD_DEVIATION
#define STREAM_CONFIG_KEY_STREAM_AUDIO_SINK_DELAY \
         ACCMD_CONFIG_KEY_STREAM_AUDIO_SINK_DELAY
#define STREAM_CONFIG_KEY_STREAM_AUDIO_SOURCE_METADATA_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_AUDIO_SOURCE_METADATA_ENABLE
#define STREAM_CONFIG_KEY_STREAM_CODEC_INPUT_GAIN \
         ACCMD_CONFIG_KEY_STREAM_CODEC_INPUT_GAIN
#define STREAM_CONFIG_KEY_STREAM_CODEC_OUTPUT_GAIN \
         ACCMD_CONFIG_KEY_STREAM_CODEC_OUTPUT_GAIN
#define STREAM_CONFIG_KEY_STREAM_DIGITAL_MIC_INPUT_GAIN \
         ACCMD_CONFIG_KEY_STREAM_DIGITAL_MIC_INPUT_GAIN
#define STREAM_CONFIG_KEY_STREAM_RM_ENABLE_DEFERRED_KICK \
         ACCMD_CONFIG_KEY_STREAM_RM_ENABLE_DEFERRED_KICK
#define STREAM_CONFIG_KEY_STREAM_RM_ENABLE_HW_ADJUST \
         ACCMD_CONFIG_KEY_STREAM_RM_ENABLE_HW_ADJUST
#define STREAM_CONFIG_KEY_STREAM_RM_ENABLE_SW_ADJUST \
         ACCMD_CONFIG_KEY_STREAM_RM_ENABLE_SW_ADJUST
#define STREAM_CONFIG_KEY_STREAM_RM_USE_RATE_ADJUST_OPERATOR \
         ACCMD_CONFIG_KEY_STREAM_RM_USE_RATE_ADJUST_OPERATOR
#define STREAM_CONFIG_KEY_STREAM_SPDIF_OUTPUT_RATE \
         ACCMD_CONFIG_KEY_STREAM_SPDIF_OUTPUT_RATE
#define STREAM_CONFIG_KEY_STREAM_AUDIO_SAMPLE_SIZE \
         ACCMD_CONFIG_KEY_STREAM_AUDIO_SAMPLE_SIZE
#define STREAM_CONFIG_KEY_STREAM_SPDIF_SET_EP_FORMAT \
         ACCMD_CONFIG_KEY_STREAM_SPDIF_SET_EP_FORMAT
#define STREAM_CONFIG_KEY_STREAM_CODEC_AOV_MODE_ON \
        ACCMD_CONFIG_KEY_STREAM_CODEC_AOV_MODE_ON
#define STREAM_CONFIG_KEY_STREAM_DIGITAL_MIC_AOV_MODE_ON \
        ACCMD_CONFIG_KEY_STREAM_DIGITAL_MIC_AOV_MODE_ON
#endif /* CHIP_BASE_HYDRA */

#if defined(HAVE_ANC_HARDWARE)
/**
 * ACCMD enum members are hidden from stream by using macro aliases
 */

#define STREAM_ANC_IIR_FILTER_FB_NUM_COEFFS \
         ACCMD_ANC_IIR_FILTER_FB_NUM_COEFFS
#define STREAM_ANC_IIR_FILTER_FFA_NUM_COEFFS \
         ACCMD_ANC_IIR_FILTER_FFA_NUM_COEFFS
#define STREAM_ANC_IIR_FILTER_FFB_NUM_COEFFS \
         ACCMD_ANC_IIR_FILTER_FFB_NUM_COEFFS

#define STREAM_ANC_CONTROL_ACCESS_SELECT_ENABLES_SHIFT \
         ACCMD_ANC_CONTROL_ACCESS_SELECT_ENABLES_SHIFT

#define STREAM_CONFIG_KEY_STREAM_ANC_INSTANCE \
         ACCMD_CONFIG_KEY_STREAM_ANC_INSTANCE
#define STREAM_CONFIG_KEY_STREAM_ANC_INPUT \
         ACCMD_CONFIG_KEY_STREAM_ANC_INPUT
#define STREAM_CONFIG_KEY_STREAM_ANC_FFA_DC_FILTER_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFA_DC_FILTER_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_FFB_DC_FILTER_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFB_DC_FILTER_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_SM_LPF_FILTER_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_SM_LPF_FILTER_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_FFA_DC_FILTER_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFA_DC_FILTER_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_FFB_DC_FILTER_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFB_DC_FILTER_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_SM_LPF_FILTER_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_SM_LPF_FILTER_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_FFA_GAIN \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFA_GAIN
#define STREAM_CONFIG_KEY_STREAM_ANC_FFB_GAIN \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFB_GAIN
#define STREAM_CONFIG_KEY_STREAM_ANC_FB_GAIN \
         ACCMD_CONFIG_KEY_STREAM_ANC_FB_GAIN
#define STREAM_CONFIG_KEY_STREAM_ANC_FFA_GAIN_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFA_GAIN_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_FFB_GAIN_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFB_GAIN_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_FB_GAIN_SHIFT \
         ACCMD_CONFIG_KEY_STREAM_ANC_FB_GAIN_SHIFT
#define STREAM_CONFIG_KEY_STREAM_ANC_FFA_ADAPT_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFA_ADAPT_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_FFB_ADAPT_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_FFB_ADAPT_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_FB_ADAPT_ENABLE \
         ACCMD_CONFIG_KEY_STREAM_ANC_FB_ADAPT_ENABLE
#define STREAM_CONFIG_KEY_STREAM_ANC_CONTROL \
         ACCMD_CONFIG_KEY_STREAM_ANC_CONTROL

#define STREAM_ANC_CONTROL_FB_TUNE_DSM_EN_MASK \
         ACCMD_ANC_CONTROL_FB_TUNE_DSM_EN_MASK
#define STREAM_ANC_CONTROL_FB_ON_FBMON_IS_TRUE_MASK \
         ACCMD_ANC_CONTROL_FB_ON_FBMON_IS_TRUE_MASK
#define STREAM_ANC_CONTROL_DMIC_X2_A_SEL_MASK \
        ACCMD_ANC_CONTROL_DMIC_X2_A_SEL_MASK
#define STREAM_ANC_CONTROL_DMIC_X2_B_SEL_MASK \
        ACCMD_ANC_CONTROL_DMIC_X2_B_SEL_MASK
#endif /* HAVE_ANC_HARDWARE */

#if defined(CHIP_BASE_HYDRA)
typedef ACCMD_INFO_KEY STREAM_INFO_KEY;

#define STREAM_INFO_KEY_AUDIO_SAMPLE_RATE \
         ACCMD_INFO_KEY_AUDIO_SAMPLE_RATE
#define STREAM_INFO_KEY_AUDIO_LOCALLY_CLOCKED \
         ACCMD_INFO_KEY_AUDIO_LOCALLY_CLOCKED
#define STREAM_INFO_KEY_AUDIO_SAMPLE_PERIOD_DEVIATION \
         ACCMD_INFO_KEY_AUDIO_SAMPLE_PERIOD_DEVIATION
#define STREAM_INFO_KEY_ENDPOINT_EXISTS \
         ACCMD_INFO_KEY_ENDPOINT_EXISTS
#define STREAM_INFO_KEY_AUDIO_HW_RM_AVAILABLE \
         ACCMD_INFO_KEY_AUDIO_HW_RM_AVAILABLE

typedef enum
{
    STREAM_AUDIO_SAMPLE_SIZE_13BITS_16CLKS = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_13BITS_16CLKS,
    STREAM_AUDIO_SAMPLE_SIZE_16BITS_16CLKS = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_16BITS_16CLKS,
    STREAM_AUDIO_SAMPLE_SIZE_8BITS_16CLKS = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_8BITS_16CLKS,
    STREAM_AUDIO_SAMPLE_SIZE_8BITS_8CLKS = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_8BITS_8CLKS,
    STREAM_AUDIO_SAMPLE_SIZE_16 = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_16,
    STREAM_AUDIO_SAMPLE_SIZE_24 = ACCMD_STREAM_AUDIO_SAMPLE_SIZE_24
} STREAM_AUDIO_SAMPLE_SIZE;

#elif defined(CHIP_BASE_BC7)

/** Enumeration of keys for the XAP_KAL_MSG_AUDIO_INFO_REQ message.
 *  Note this enum appears to have been forked and extended in ACCMD_INFO_KEY.
 */
typedef enum
{
    /** Key to request the audio sample rate */
    AUDIO_CONFIG_SAMPLE_RATE = 0x0000,
    /** Key to request whether the audio hardware is locally or remotely clocked */
    AUDIO_CONFIG_LOCALLY_CLOCKED = 0x0001,
    /** Key to request the hardware instance of an audio sink/source */
    AUDIO_CONFIG_INSTANCE = 0x0002,
    /** Key to request the hardware channel of an audio sink/source */
    AUDIO_CONFIG_CHANNEL = 0x0003,
    /** Key to request the Audio Sample format, i.e. 8,13,16 or 24 bit */
    AUDIO_CONFIG_SAMPLE_FORMAT = 0x0004
} AUDIO_CONFIG;

typedef AUDIO_CONFIG                          STREAM_INFO_KEY;
#define STREAM_INFO_KEY_AUDIO_SAMPLE_RATE \
                 AUDIO_CONFIG_SAMPLE_RATE
#define STREAM_INFO_KEY_AUDIO_LOCALLY_CLOCKED \
                 AUDIO_CONFIG_LOCALLY_CLOCKED
#define STREAM_INFO_KEY_AUDIO_INSTANCE \
                 AUDIO_CONFIG_INSTANCE
#define STREAM_INFO_KEY_AUDIO_CHANNEL \
                 AUDIO_CONFIG_CHANNEL
#define STREAM_INFO_KEY_AUDIO_SAMPLE_FORMAT \
                 AUDIO_CONFIG_SAMPLE_FORMAT

#else

#error "Adaptor not implemented for this chip"

#endif

#endif /* STREAM_TYPE_ALIAS_H */
