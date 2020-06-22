// -----------------------------------------------------------------------------
// Copyright (c) 2020                  Qualcomm Technologies International, Ltd.
//
#include "cvc_recv_gen_c.h"

#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvNB[] = {
   0x00002080u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x0CCCCC00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x003D6100u,			// AEQ_ATK_TC
   0x7FC29F00u,			// AEQ_ATK_1MTC
   0x003D6100u,			// AEQ_DEC_TC
   0x7FC29F00u,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000005u,			// AEQ_LOW_BAND_INDEX
   0x00000008u,			// AEQ_LOW_BANDWIDTH
   0x03000000u,			// AEQ_LOG2_LOW_BANDWIDTH
   0x00000013u,			// AEQ_MID_BANDWIDTH
   0x043F7800u,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000018u,			// AEQ_HIGH_BANDWIDTH
   0x0495C000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Eu,			// AEQ_MID1_BAND_INDEX
   0x00000021u,			// AEQ_MID2_BAND_INDEX
   0x00000039u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvWB[] = {
   0x00002080u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x066A4A00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x003D6100u,			// AEQ_ATK_TC
   0x7FC29F00u,			// AEQ_ATK_1MTC
   0x003D6100u,			// AEQ_DEC_TC
   0x7FC29F00u,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000005u,			// AEQ_LOW_BAND_INDEX
   0x00000008u,			// AEQ_LOW_BANDWIDTH
   0x03000000u,			// AEQ_LOG2_LOW_BANDWIDTH
   0x00000013u,			// AEQ_MID_BANDWIDTH
   0x043F7800u,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000018u,			// AEQ_HIGH_BANDWIDTH
   0x0495C000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Eu,			// AEQ_MID1_BAND_INDEX
   0x00000021u,			// AEQ_MID2_BAND_INDEX
   0x00000039u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#if defined(INSTALL_OPERATOR_CVC_24K)
#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvUWB[] = {
   0x00002080u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x066A4A00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x0028EF36u,			// AEQ_ATK_TC
   0x7FD710CAu,			// AEQ_ATK_1MTC
   0x0028EF36u,			// AEQ_DEC_TC
   0x7FD710CAu,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000004u,			// AEQ_LOW_BAND_INDEX
   0x00000005u,			// AEQ_LOW_BANDWIDTH
   0x0395C01Au,			// AEQ_LOG2_LOW_BANDWIDTH
   0x0000000Cu,			// AEQ_MID_BANDWIDTH
   0x0395C01Au,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000010u,			// AEQ_HIGH_BANDWIDTH
   0x04000000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Au,			// AEQ_MID1_BAND_INDEX
   0x00000016u,			// AEQ_MID2_BAND_INDEX
   0x00000026u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#endif


#if defined(INSTALL_OPERATOR_CVC_32K)
#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvSWB[] = {
   0x00002080u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x066A4A00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x003D6100u,			// AEQ_ATK_TC
   0x7FC29F00u,			// AEQ_ATK_1MTC
   0x003D6100u,			// AEQ_DEC_TC
   0x7FC29F00u,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000005u,			// AEQ_LOW_BAND_INDEX
   0x00000008u,			// AEQ_LOW_BANDWIDTH
   0x03000000u,			// AEQ_LOG2_LOW_BANDWIDTH
   0x00000013u,			// AEQ_MID_BANDWIDTH
   0x043F7800u,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000018u,			// AEQ_HIGH_BANDWIDTH
   0x0495C000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Eu,			// AEQ_MID1_BAND_INDEX
   0x00000021u,			// AEQ_MID2_BAND_INDEX
   0x00000039u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#endif


#if defined(INSTALL_OPERATOR_CVC_48K)
#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvFB[] = {
   0x00002080u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x066A4A00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x0028EF36u,			// AEQ_ATK_TC
   0x7FD710CAu,			// AEQ_ATK_1MTC
   0x0028EF36u,			// AEQ_DEC_TC
   0x7FD710CAu,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000004u,			// AEQ_LOW_BAND_INDEX
   0x00000005u,			// AEQ_LOW_BANDWIDTH
   0x0395C01Au,			// AEQ_LOG2_LOW_BANDWIDTH
   0x0000000Cu,			// AEQ_MID_BANDWIDTH
   0x0395C01Au,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000010u,			// AEQ_HIGH_BANDWIDTH
   0x04000000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Au,			// AEQ_MID1_BAND_INDEX
   0x00000016u,			// AEQ_MID2_BAND_INDEX
   0x00000026u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#endif


#if defined(INSTALL_OPERATOR_CVC_RECEIVE)
#ifndef __GNUC__ 
_Pragma("datasection CONST")
#endif /* __GNUC__ */

static unsigned defaults_cvc_recvFE[] = {
   0x00002000u,			// RCV_CONFIG
   0x00000000u,			// RCV_PEQ_CONFIG
   0x00000001u,			// RCV_PEQ_GAIN_EXP
   0x40000000u,			// RCV_PEQ_GAIN_MANT
   0x344180D4u,			// RCV_PEQ_STAGE1_B2
   0x8E595358u,			// RCV_PEQ_STAGE1_B1
   0x40000000u,			// RCV_PEQ_STAGE1_B0
   0x344180D4u,			// RCV_PEQ_STAGE1_A2
   0x8E595358u,			// RCV_PEQ_STAGE1_A1
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_B2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_B1
   0x40000000u,			// RCV_PEQ_STAGE2_B0
   0x2C1D29DCu,			// RCV_PEQ_STAGE2_A2
   0x9BD3ED52u,			// RCV_PEQ_STAGE2_A1
   0x1FC70C99u,			// RCV_PEQ_STAGE3_B2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_B1
   0x40000000u,			// RCV_PEQ_STAGE3_B0
   0x1FC70C99u,			// RCV_PEQ_STAGE3_A2
   0xB6E221C9u,			// RCV_PEQ_STAGE3_A1
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_B2
   0xD2A98245u,			// RCV_PEQ_STAGE4_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE4_B0
   0x1D7DAE82u,			// RCV_PEQ_STAGE4_A2
   0xD2A98245u,			// RCV_PEQ_STAGE4_A1
   0xE65614E0u,			// RCV_PEQ_STAGE5_B2
   0x464F440Bu,			// RCV_PEQ_STAGE5_B1
   0x7FFFFFFFu,			// RCV_PEQ_STAGE5_B0
   0xE65614E0u,			// RCV_PEQ_STAGE5_A2
   0x464F440Bu,			// RCV_PEQ_STAGE5_A1
   0x00000001u,			// RCV_PEQ_SCALE1
   0x00000001u,			// RCV_PEQ_SCALE2
   0x00000001u,			// RCV_PEQ_SCALE3
   0x00000000u,			// RCV_PEQ_SCALE4
   0x00000000u,			// RCV_PEQ_SCALE5
   0x40000000u,			// RCVGAIN_MANTISSA
   0x00000001u,			// RCVGAIN_EXPONENT
   0x40000000u,			// PT_RCVGAIN_MANTISSA
   0x00000001u,			// PT_RCVGAIN_EXPONENT
   0x06000000u,			// RCV_VAD_ATTACK_TC
   0x06000000u,			// RCV_VAD_DECAY_TC
   0x0010624Eu,			// RCV_VAD_ENVELOPE_TC
   0x0063D70Au,			// RCV_VAD_INIT_FRAME_THRESH
   0x40000000u,			// RCV_VAD_RATIO
   0x00800000u,			// RCV_VAD_MIN_SIGNAL
   0xFD400000u,			// RCV_VAD_MIN_MAX_ENVELOPE
   0x00500000u,			// RCV_VAD_DELTA_THRESHOLD
   0x00E56042u,			// RCV_VAD_COUNT_THRESHOLD
   0x02000000u,			// RCV_AGC_G_INITIAL
   0x0CCCCC00u,			// RCV_AGC_TARGET
   0x0099999Au,			// RCV_AGC_ATTACK_TC
   0x0099999Au,			// RCV_AGC_DECAY_TC
   0x04000000u,			// RCV_AGC_A_90_PK
   0x04000000u,			// RCV_AGC_D_90_PK
   0x0B3F3000u,			// RCV_AGC_G_MAX
   0x5A9DF600u,			// RCV_AGC_START_COMP
   0x40000000u,			// RCV_AGC_COMP
   0x65AC8B00u,			// RCV_AGC_INP_THRESH
   0x18000000u,			// RCV_AGC_SP_ATTACK
   0x0F9E4CFBu,			// RCV_AGC_AD_THRESH1
   0xF21482C0u,			// RCV_AGC_AD_THRESH2
   0x00A1E800u,			// RCV_AGC_G_MIN
   0x003D6100u,			// AEQ_ATK_TC
   0x7FC29F00u,			// AEQ_ATK_1MTC
   0x003D6100u,			// AEQ_DEC_TC
   0x7FC29F00u,			// AEQ_DEC_1MTC
   0x03526900u,			// AEQ_LO_GOAL_LOW
   0x02534A00u,			// AEQ_LO_GOAL_MID
   0x02534A00u,			// AEQ_LO_GOAL_HIGH
   0x01A93400u,			// AEQ_HI_GOAL_LOW
   0x00FF1F00u,			// AEQ_HI_GOAL_MID
   0x00000000u,			// AEQ_HI_GOAL_HIGH
   0x06A4D400u,			// BEX_HI2_GOAL_LOW
   0x04A69400u,			// BEX_HI2_GOAL_MID
   0x02A85500u,			// BEX_HI2_GOAL_HIGH
   0xFAAF5700u,			// BEX_TOTAL_ATT_LOW
   0xFC038100u,			// BEX_TOTAL_ATT_MID
   0xFD57AC00u,			// BEX_TOTAL_ATT_HIGH
   0x00000000u,			// BEX_NOISE_LVL_FLAGS
   0x00000001u,			// BEX_LOW_STEP
   0x00000001u,			// BEX_HIGH_STEP
   0x084E0800u,			// AEQ_POWER_TH
   0xFC038100u,			// AEQ_MIN_GAIN
   0x03FC7F00u,			// AEQ_MAX_GAIN
   0x00000001u,			// AEQ_VOL_STEP_UP_TH1
   0x00000002u,			// AEQ_VOL_STEP_UP_TH2
   0x00AA1500u,			// AEQ_LOW_STEP
   0x01815100u,			// AEQ_LOW_STEP_INV
   0x00550A00u,			// AEQ_HIGH_STEP
   0x0302A800u,			// AEQ_HIGH_STEP_INV
   0x00000005u,			// AEQ_LOW_BAND_INDEX
   0x00000008u,			// AEQ_LOW_BANDWIDTH
   0x03000000u,			// AEQ_LOG2_LOW_BANDWIDTH
   0x00000013u,			// AEQ_MID_BANDWIDTH
   0x043F7800u,			// AEQ_LOG2_MID_BANDWIDTH
   0x00000018u,			// AEQ_HIGH_BANDWIDTH
   0x0495C000u,			// AEQ_LOG2_HIGH_BANDWIDTH
   0x0000000Eu,			// AEQ_MID1_BAND_INDEX
   0x00000021u,			// AEQ_MID2_BAND_INDEX
   0x00000039u,			// AEQ_HIGH_BAND_INDEX
   0x66666600u,			// RCV_OMS_HFK_AGGR
   0x00000001u			// OMS_HI_RES_MODE
};
#endif



unsigned *CVC_RECV_GetDefaults(unsigned capid){
	switch(capid){
		case 0x001D: return defaults_cvc_recvNB;
		case 0x4008: return defaults_cvc_recvNB;
		case 0x001F: return defaults_cvc_recvWB;
		case 0x4009: return defaults_cvc_recvWB;
#if defined (INSTALL_OPERATOR_CVC_24K)
		case 0x0053: return defaults_cvc_recvUWB;
		case 0x400B: return defaults_cvc_recvUWB;
#endif
#if defined (INSTALL_OPERATOR_CVC_32K)
		case 0x0054: return defaults_cvc_recvSWB;
		case 0x400C: return defaults_cvc_recvSWB;
#endif
#if defined (INSTALL_OPERATOR_CVC_48K)
		case 0x0055: return defaults_cvc_recvFB;
		case 0x400D: return defaults_cvc_recvFB;
#endif
#if defined (INSTALL_OPERATOR_CVC_RECEIVE)
		case 0x001B: return defaults_cvc_recvFE;
		case 0x400A: return defaults_cvc_recvFE;
#endif
	}
	return((unsigned *)0);
}
