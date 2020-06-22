// -----------------------------------------------------------------------------
// Copyright (c) 2020                  Qualcomm Technologies International, Ltd.
//
#ifndef __CVC_SEND_GEN_ASM_H__
#define __CVC_SEND_GEN_ASM_H__

// CodeBase IDs
.CONST $M.GEN.CVC_SEND_1M_HS_NB_CAP_ID       	0x0023;
.CONST $M.GEN.CVC_SEND_1M_HS_NB_ALT_CAP_ID_0       	0x4012;
.CONST $M.GEN.CVC_SEND_1M_HS_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_1M_HS_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_HS_WB_CAP_ID       	0x0024;
.CONST $M.GEN.CVC_SEND_1M_HS_WB_ALT_CAP_ID_0       	0x4013;
.CONST $M.GEN.CVC_SEND_1M_HS_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_1M_HS_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_NB_CAP_ID       	0x0025;
.CONST $M.GEN.CVC_SEND_2M_HSE_NB_ALT_CAP_ID_0       	0x4014;
.CONST $M.GEN.CVC_SEND_2M_HSE_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_2M_HSE_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_WB_CAP_ID       	0x0026;
.CONST $M.GEN.CVC_SEND_2M_HSE_WB_ALT_CAP_ID_0       	0x4015;
.CONST $M.GEN.CVC_SEND_2M_HSE_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_HSE_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSB_NB_CAP_ID       	0x0027;
.CONST $M.GEN.CVC_SEND_2M_HSB_NB_ALT_CAP_ID_0       	0x4016;
.CONST $M.GEN.CVC_SEND_2M_HSB_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_2M_HSB_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSB_WB_CAP_ID       	0x0028;
.CONST $M.GEN.CVC_SEND_2M_HSB_WB_ALT_CAP_ID_0       	0x4017;
.CONST $M.GEN.CVC_SEND_2M_HSB_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_HSB_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_SPKR_NB_CAP_ID       	0x0029;
.CONST $M.GEN.CVC_SEND_1M_SPKR_NB_ALT_CAP_ID_0       	0x4018;
.CONST $M.GEN.CVC_SEND_1M_SPKR_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_1M_SPKR_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_SPKR_WB_CAP_ID       	0x002A;
.CONST $M.GEN.CVC_SEND_1M_SPKR_WB_ALT_CAP_ID_0       	0x4003;
.CONST $M.GEN.CVC_SEND_1M_SPKR_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_1M_SPKR_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_SPKRB_NB_CAP_ID       	0x002D;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_NB_ALT_CAP_ID_0       	0x4019;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_SPKRB_WB_CAP_ID       	0x002E;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_WB_ALT_CAP_ID_0       	0x401A;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_AUTO_NB_CAP_ID       	0x001C;
.CONST $M.GEN.CVC_SEND_1M_AUTO_NB_ALT_CAP_ID_0       	0x400E;
.CONST $M.GEN.CVC_SEND_1M_AUTO_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_1M_AUTO_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_AUTO_WB_CAP_ID       	0x001E;
.CONST $M.GEN.CVC_SEND_1M_AUTO_WB_ALT_CAP_ID_0       	0x400F;
.CONST $M.GEN.CVC_SEND_1M_AUTO_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_1M_AUTO_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_AUTO_NB_CAP_ID       	0x0020;
.CONST $M.GEN.CVC_SEND_2M_AUTO_NB_ALT_CAP_ID_0       	0x4010;
.CONST $M.GEN.CVC_SEND_2M_AUTO_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_2M_AUTO_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_AUTO_WB_CAP_ID       	0x0021;
.CONST $M.GEN.CVC_SEND_2M_AUTO_WB_ALT_CAP_ID_0       	0x4011;
.CONST $M.GEN.CVC_SEND_2M_AUTO_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_AUTO_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRB_NB_CAP_ID       	0x0044;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_NB_ALT_CAP_ID_0       	0x401B;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRB_WB_CAP_ID       	0x0045;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_WB_ALT_CAP_ID_0       	0x401C;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRB_NB_CAP_ID       	0x0046;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_NB_ALT_CAP_ID_0       	0x401D;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRB_WB_CAP_ID       	0x0047;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_WB_ALT_CAP_ID_0       	0x401E;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSE_NB_CAP_ID       	0x004B;
.CONST $M.GEN.CVC_SEND_3M_HSE_NB_ALT_CAP_ID_0       	0x401F;
.CONST $M.GEN.CVC_SEND_3M_HSE_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_3M_HSE_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSE_WB_CAP_ID       	0x004C;
.CONST $M.GEN.CVC_SEND_3M_HSE_WB_ALT_CAP_ID_0       	0x4020;
.CONST $M.GEN.CVC_SEND_3M_HSE_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_3M_HSE_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSB_NB_CAP_ID       	0x004D;
.CONST $M.GEN.CVC_SEND_3M_HSB_NB_ALT_CAP_ID_0       	0x4021;
.CONST $M.GEN.CVC_SEND_3M_HSB_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_3M_HSB_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSB_WB_CAP_ID       	0x004E;
.CONST $M.GEN.CVC_SEND_3M_HSB_WB_ALT_CAP_ID_0       	0x4022;
.CONST $M.GEN.CVC_SEND_3M_HSB_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_3M_HSB_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_NB_CAP_ID       	0x004F;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_NB_ALT_CAP_ID_0       	0x4023;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_WB_CAP_ID       	0x0050;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_WB_ALT_CAP_ID_0       	0x4024;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_WB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_NB_CAP_ID       	0x0051;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_NB_ALT_CAP_ID_0       	0x4025;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_NB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_NB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_WB_CAP_ID       	0x0052;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_WB_ALT_CAP_ID_0       	0x4026;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_WB_SAMPLE_RATE       	8000;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_AUTO_UWB_CAP_ID       	0x0056;
.CONST $M.GEN.CVC_SEND_1M_AUTO_UWB_ALT_CAP_ID_0       	0x4027;
.CONST $M.GEN.CVC_SEND_1M_AUTO_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_1M_AUTO_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_AUTO_SWB_CAP_ID       	0x0057;
.CONST $M.GEN.CVC_SEND_1M_AUTO_SWB_ALT_CAP_ID_0       	0x4028;
.CONST $M.GEN.CVC_SEND_1M_AUTO_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_1M_AUTO_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_AUTO_FB_CAP_ID       	0x0058;
.CONST $M.GEN.CVC_SEND_1M_AUTO_FB_ALT_CAP_ID_0       	0x4029;
.CONST $M.GEN.CVC_SEND_1M_AUTO_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_1M_AUTO_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_AUTO_UWB_CAP_ID       	0x0059;
.CONST $M.GEN.CVC_SEND_2M_AUTO_UWB_ALT_CAP_ID_0       	0x402A;
.CONST $M.GEN.CVC_SEND_2M_AUTO_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_2M_AUTO_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_AUTO_SWB_CAP_ID       	0x005A;
.CONST $M.GEN.CVC_SEND_2M_AUTO_SWB_ALT_CAP_ID_0       	0x402B;
.CONST $M.GEN.CVC_SEND_2M_AUTO_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_2M_AUTO_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_AUTO_FB_CAP_ID       	0x005B;
.CONST $M.GEN.CVC_SEND_2M_AUTO_FB_ALT_CAP_ID_0       	0x402C;
.CONST $M.GEN.CVC_SEND_2M_AUTO_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_2M_AUTO_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_HS_UWB_CAP_ID       	0x005C;
.CONST $M.GEN.CVC_SEND_1M_HS_UWB_ALT_CAP_ID_0       	0x402D;
.CONST $M.GEN.CVC_SEND_1M_HS_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_1M_HS_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_HS_SWB_CAP_ID       	0x005D;
.CONST $M.GEN.CVC_SEND_1M_HS_SWB_ALT_CAP_ID_0       	0x402E;
.CONST $M.GEN.CVC_SEND_1M_HS_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_1M_HS_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_HS_FB_CAP_ID       	0x005E;
.CONST $M.GEN.CVC_SEND_1M_HS_FB_ALT_CAP_ID_0       	0x402F;
.CONST $M.GEN.CVC_SEND_1M_HS_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_1M_HS_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_UWB_CAP_ID       	0x005F;
.CONST $M.GEN.CVC_SEND_2M_HSE_UWB_ALT_CAP_ID_0       	0x4030;
.CONST $M.GEN.CVC_SEND_2M_HSE_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_2M_HSE_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_SWB_CAP_ID       	0x0060;
.CONST $M.GEN.CVC_SEND_2M_HSE_SWB_ALT_CAP_ID_0       	0x4031;
.CONST $M.GEN.CVC_SEND_2M_HSE_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_2M_HSE_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_FB_CAP_ID       	0x0061;
.CONST $M.GEN.CVC_SEND_2M_HSE_FB_ALT_CAP_ID_0       	0x4032;
.CONST $M.GEN.CVC_SEND_2M_HSE_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_2M_HSE_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSB_UWB_CAP_ID       	0x0062;
.CONST $M.GEN.CVC_SEND_2M_HSB_UWB_ALT_CAP_ID_0       	0x4033;
.CONST $M.GEN.CVC_SEND_2M_HSB_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_2M_HSB_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSB_SWB_CAP_ID       	0x0063;
.CONST $M.GEN.CVC_SEND_2M_HSB_SWB_ALT_CAP_ID_0       	0x4034;
.CONST $M.GEN.CVC_SEND_2M_HSB_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_2M_HSB_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSB_FB_CAP_ID       	0x0064;
.CONST $M.GEN.CVC_SEND_2M_HSB_FB_ALT_CAP_ID_0       	0x4035;
.CONST $M.GEN.CVC_SEND_2M_HSB_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_2M_HSB_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSE_UWB_CAP_ID       	0x0065;
.CONST $M.GEN.CVC_SEND_3M_HSE_UWB_ALT_CAP_ID_0       	0x4036;
.CONST $M.GEN.CVC_SEND_3M_HSE_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_3M_HSE_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSE_SWB_CAP_ID       	0x0066;
.CONST $M.GEN.CVC_SEND_3M_HSE_SWB_ALT_CAP_ID_0       	0x4037;
.CONST $M.GEN.CVC_SEND_3M_HSE_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_3M_HSE_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSE_FB_CAP_ID       	0x0067;
.CONST $M.GEN.CVC_SEND_3M_HSE_FB_ALT_CAP_ID_0       	0x4038;
.CONST $M.GEN.CVC_SEND_3M_HSE_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_3M_HSE_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSB_UWB_CAP_ID       	0x0068;
.CONST $M.GEN.CVC_SEND_3M_HSB_UWB_ALT_CAP_ID_0       	0x4039;
.CONST $M.GEN.CVC_SEND_3M_HSB_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_3M_HSB_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSB_SWB_CAP_ID       	0x0069;
.CONST $M.GEN.CVC_SEND_3M_HSB_SWB_ALT_CAP_ID_0       	0x403A;
.CONST $M.GEN.CVC_SEND_3M_HSB_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_3M_HSB_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_HSB_FB_CAP_ID       	0x006A;
.CONST $M.GEN.CVC_SEND_3M_HSB_FB_ALT_CAP_ID_0       	0x403B;
.CONST $M.GEN.CVC_SEND_3M_HSB_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_3M_HSB_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_SPKR_UWB_CAP_ID       	0x006B;
.CONST $M.GEN.CVC_SEND_1M_SPKR_UWB_ALT_CAP_ID_0       	0x403C;
.CONST $M.GEN.CVC_SEND_1M_SPKR_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_1M_SPKR_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_SPKR_SWB_CAP_ID       	0x006C;
.CONST $M.GEN.CVC_SEND_1M_SPKR_SWB_ALT_CAP_ID_0       	0x403D;
.CONST $M.GEN.CVC_SEND_1M_SPKR_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_1M_SPKR_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_1M_SPKR_FB_CAP_ID       	0x006D;
.CONST $M.GEN.CVC_SEND_1M_SPKR_FB_ALT_CAP_ID_0       	0x403E;
.CONST $M.GEN.CVC_SEND_1M_SPKR_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_1M_SPKR_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_SPKRB_UWB_CAP_ID       	0x006E;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_UWB_ALT_CAP_ID_0       	0x403F;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_SPKRB_SWB_CAP_ID       	0x006F;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_SWB_ALT_CAP_ID_0       	0x4040;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_SPKRB_FB_CAP_ID       	0x0070;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_FB_ALT_CAP_ID_0       	0x4041;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_2M_SPKRB_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRB_UWB_CAP_ID       	0x0071;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_UWB_ALT_CAP_ID_0       	0x4042;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRB_SWB_CAP_ID       	0x0072;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_SWB_ALT_CAP_ID_0       	0x4043;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRB_FB_CAP_ID       	0x0073;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_FB_ALT_CAP_ID_0       	0x4044;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_3M_SPKRB_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRB_UWB_CAP_ID       	0x0074;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_UWB_ALT_CAP_ID_0       	0x4045;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRB_SWB_CAP_ID       	0x0075;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_SWB_ALT_CAP_ID_0       	0x4046;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRB_FB_CAP_ID       	0x0076;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_FB_ALT_CAP_ID_0       	0x4047;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_4M_SPKRB_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_UWB_CAP_ID       	0x0077;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_UWB_ALT_CAP_ID_0       	0x4048;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_SWB_CAP_ID       	0x0078;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_SWB_ALT_CAP_ID_0       	0x4049;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_FB_CAP_ID       	0x0079;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_FB_ALT_CAP_ID_0       	0x404A;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_UWB_CAP_ID       	0x007A;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_UWB_ALT_CAP_ID_0       	0x404B;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_UWB_SAMPLE_RATE       	24000;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_UWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_SWB_CAP_ID       	0x007B;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_SWB_ALT_CAP_ID_0       	0x404C;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_SWB_SAMPLE_RATE       	32000;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_SWB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_FB_CAP_ID       	0x007C;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_FB_ALT_CAP_ID_0       	0x404D;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_FB_SAMPLE_RATE       	48000;
.CONST $M.GEN.CVC_SEND_4M_SPKRCIRC_FB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA_WB_CAP_ID       	0x007D;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA_WB_ALT_CAP_ID_0       	0x4086;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA4B_WB_CAP_ID       	0x007E;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA4B_WB_ALT_CAP_ID_0       	0x4087;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA4B_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_3M_SPKRCIRC_VA4B_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_VA_WAKEON_WB_CAP_ID       	0x0080;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_WAKEON_WB_ALT_CAP_ID_0       	0x4091;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_WAKEON_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_WAKEON_WB_VERSION_MAJOR       	5;

.CONST $M.GEN.CVC_SEND_2M_HSE_VA_BARGEIN_WB_CAP_ID       	0x0081;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_BARGEIN_WB_ALT_CAP_ID_0       	0x4092;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_BARGEIN_WB_SAMPLE_RATE       	16000;
.CONST $M.GEN.CVC_SEND_2M_HSE_VA_BARGEIN_WB_VERSION_MAJOR       	5;

// Constant Values
.CONST $M.GEN.CVC_SEND.CONSTANT.CNG_SHAPE_brown 		0x00000000;
.CONST $M.GEN.CVC_SEND.CONSTANT.CNG_SHAPE_pink  		0x00000001;
.CONST $M.GEN.CVC_SEND.CONSTANT.CNG_SHAPE_white 		0xFFFFFFFF;
.CONST $M.GEN.CVC_SEND.CONSTANT.CNG_SHAPE_blue  		0x00000002;
.CONST $M.GEN.CVC_SEND.CONSTANT.CNG_SHAPE_purple		0x00000003;


// Piecewise Disables
// HFK_CONFIG bits
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_AEC         		0x00000001;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_RER         		0x00000002;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_CNG         		0x00000004;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_HD          		0x00000008;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_DMS         		0x00000010;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_HARM        		0x00000020;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_WNR         		0x00000040;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_NFLOOR      		0x00000080;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_AGC         		0x00000400;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_NDVC        		0x00000800;
.CONST $M.GEN.CVC_SEND.CONFIG.HFK.BYP_FBC         		0x00001000;
// DMSS_CONFIG bits
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_ASF        		0x00000001;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_MGDC       		0x00000002;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_NC         		0x00000004;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_TP         		0x00000010;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_RNR        		0x00000020;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_SPP        		0x00000100;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_VAD_S      		0x00000200;
.CONST $M.GEN.CVC_SEND.CONFIG.DMSS.BYP_MGDCPERSIST		0x00000400;


// Statistic Block
.CONST $M.GEN.CVC_SEND.STATUS.CUR_MODE_OFFSET      		0*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.SYS_CONTROL_OFFSET   		1*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.COMPILED_CONFIG      		2*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_ADC_LEFT_OFFSET 		3*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_ADC_RIGHT_OFFSET		4*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_SCO_OUT_OFFSET  		5*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.NDVC_NOISE_EST_OFFSET		6*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.NDVC_VOL_ADJ_OFFSET  		7*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.SND_AGC_SPEECH_LVL   		8*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.SND_AGC_GAIN         		9*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.AEC_COUPLING_OFFSET  		10*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.WNR_POWER            		11*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.WNR_WIND_PHASE       		12*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.WIND_FLAG            		13*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.MUTE_FLAG            		14*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.OMNI_FLAG            		15*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_ADC_MIC3_OFFSET 		16*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_ADC_MIC4_OFFSET 		17*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_AEC_REF_OFFSET  		18*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.FBC_POWER_DROP       		19*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.NLP_TIER_HC_ACTIVE   		20*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.PEAK_VA1_OFFSET      		21*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.STATUS.BLOCK_SIZE                	22;

// System Mode
.CONST $M.GEN.CVC_SEND.SYSMODE.STATIC           		0;
.CONST $M.GEN.CVC_SEND.SYSMODE.STANDBY          		1;
.CONST $M.GEN.CVC_SEND.SYSMODE.FULL             		2;
.CONST $M.GEN.CVC_SEND.SYSMODE.LOWVOLUME        		3;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_LEFT   		4;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_RIGHT  		5;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_MIC3   		6;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_MIC4   		7;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_AEC_REF		8;
.CONST $M.GEN.CVC_SEND.SYSMODE.MAX_MODES        		9;

// System Mode
.CONST $M.GEN.CVC_SEND.SYSMODE.STATIC           		0;
.CONST $M.GEN.CVC_SEND.SYSMODE.STANDBY          		1;
.CONST $M.GEN.CVC_SEND.SYSMODE.FULL             		2;
.CONST $M.GEN.CVC_SEND.SYSMODE.LOWVOLUME        		3;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_LEFT   		4;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_RIGHT  		5;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_MIC3   		6;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_MIC4   		7;
.CONST $M.GEN.CVC_SEND.SYSMODE.PASS_THRU_AEC_REF		8;
.CONST $M.GEN.CVC_SEND.SYSMODE.MAX_MODES        		9;

// System Control
.CONST $M.GEN.CVC_SEND.CONTROL.MODE_OVERRIDE		0x2000;
.CONST $M.GEN.CVC_SEND.CONTROL.MUTE_OVERRIDE		0x0001;
.CONST $M.GEN.CVC_SEND.CONTROL.OMNI_OVERRIDE		0x0002;

// W_Flag

// Mute Control

// Omni Mode Control

// NLP State

// Parameter Block
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_HFK_CONFIG             		0*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMSS_CONFIG            		1*ADDR_PER_WORD;
// NDVC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_HYSTERESIS        		2*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_ATK_TC            		3*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_DEC_TC            		4*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_NUMVOLSTEPS       		5*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_MAXNOISELVL       		6*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_MINNOISELVL       		7*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_LOW_FREQ          		8*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NDVC_HIGH_FREQ         		9*ADDR_PER_WORD;
// Send PEQ
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_CONFIG         		10*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_GAIN_EXP       		11*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_GAIN_MANT      		12*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE1_B2      		13*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE1_B1      		14*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE1_B0      		15*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE1_A2      		16*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE1_A1      		17*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE2_B2      		18*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE2_B1      		19*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE2_B0      		20*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE2_A2      		21*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE2_A1      		22*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE3_B2      		23*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE3_B1      		24*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE3_B0      		25*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE3_A2      		26*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE3_A1      		27*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE4_B2      		28*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE4_B1      		29*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE4_B0      		30*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE4_A2      		31*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE4_A1      		32*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE5_B2      		33*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE5_B1      		34*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE5_B0      		35*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE5_A2      		36*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_STAGE5_A1      		37*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_SCALE1         		38*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_SCALE2         		39*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_SCALE3         		40*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_SCALE4         		41*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_PEQ_SCALE5         		42*ADDR_PER_WORD;
// Pre-Gain and Pass-Through Gain
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SNDGAIN_MANTISSA       		43*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SNDGAIN_EXPONENT       		44*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_PT_SNDGAIN_MANTISSA    		45*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_PT_SNDGAIN_EXPONENT    		46*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VA_GAIN_MANTISSA       		47*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VA_GAIN_EXPONENT       		48*ADDR_PER_WORD;
// Send AGC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_G_INITIAL      		49*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_TARGET         		50*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_ATTACK_TC      		51*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_DECAY_TC       		52*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_A_90_PK        		53*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_D_90_PK        		54*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_G_MAX          		55*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_START_COMP     		56*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_COMP           		57*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_INP_THRESH     		58*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_SP_ATTACK      		59*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_AD_THRESH1     		60*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_AD_THRESH2     		61*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_G_MIN          		62*ADDR_PER_WORD;
// SND AGC Echo/Noise hold module
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_ECHO_HOLD      		63*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_SND_AGC_NOISE_HOLD     		64*ADDR_PER_WORD;
// DMSS Control
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMSS_LPN_MIC           		65*ADDR_PER_WORD;
// ASF
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_BEAM0_AGGR         		66*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_MIC_DISTANCE       		67*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_BETA               		68*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DOA0                   		69*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DOA1                   		70*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_WNR_AGGR               		71*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_WNR_THRESHOLD          		72*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_WNR_HOLD               		73*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_WNR_THRESH_PHASE       		74*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_WNR_THRESH_COHERENCE   		75*ADDR_PER_WORD;
// MGDC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_MGDC_MAXCOMP           		76*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_MGDC_TH                		77*ADDR_PER_WORD;
// Send NS
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NS_POWER               		78*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMS_AGGR               		79*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMS_RESIDUAL_NFLOOR    		80*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMS_NSN_AGGR           		81*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMS_AGGR_VA            		82*ADDR_PER_WORD;
// NC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NC_TAP                 		83*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NC_AGGR                		84*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NC_RPT                 		85*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NC_CTRL_BIAS           		86*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_NC_CTRL_TRANS          		87*ADDR_PER_WORD;
// RNR
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RNR_AGGR               		88*ADDR_PER_WORD;
// AEC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_LVMODE_THRES           		89*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_REF_DELAY              		90*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_AEC_FILTER_LENGTH      		91*ADDR_PER_WORD;
// CNG and DTC
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_CNG_Q                  		92*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_CNG_SHAPE              		93*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DTC_AGGR               		94*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_MAX_LPWRX_MARGIN       		95*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ENABLE_AEC_REUSE       		96*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_AEC_REF_LPWR_HB        		97*ADDR_PER_WORD;
// RER (AUTO or SPEAKER)
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RER_ADAPT              		98*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RER_AGGRESSIVENESS     		99*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RER_POWER              		100*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RERDT_OFF_THRESHOLD    		101*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RERDT_AGGRESSIVENESS   		102*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_RERDT_POWER            		103*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_LMS_FREQ               		104*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_HDV_GAIN_CNTRL         		105*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_AEC_LRM_MODE           		106*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_AEC_NS_CNTRL           		107*ADDR_PER_WORD;
// HD
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_HD_THRESH_GAIN         		108*ADDR_PER_WORD;
// FDNLP/VSM
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_TIER2_THRESH           		109*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_HB_TIER1           		110*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_LB_TIER1           		111*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_MAX_ATT_TIER1      		112*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_HB_TIER1         		113*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_LB_TIER1         		114*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_MB_TIER1         		115*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_NBINS_TIER1      		116*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ATT_TIER1        		117*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ATT_THRESH_TIER1 		118*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ECHO_THRESH_TIER1		119*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_HB_TIER2           		120*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_LB_TIER2           		121*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_VSM_MAX_ATT_TIER2      		122*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_HB_TIER2         		123*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_LB_TIER2         		124*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_MB_TIER2         		125*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_NBINS_TIER2      		126*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ATT_TIER2        		127*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ATT_THRESH_TIER2 		128*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_FDNLP_ECHO_THRESH_TIER2		129*ADDR_PER_WORD;
// AUTO control
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_MIC_SWITCH             		130*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_DMP_MODE               		131*ADDR_PER_WORD;
// Headset 3mic and Speaker Circular
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_ARRAY_TYPE         		132*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_MICDIST_B          		133*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_BETA_B             		134*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_DOA0_B             		135*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_ASF_BEAM0_MODE         		136*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.OFFSET_HPF_ON                 		137*ADDR_PER_WORD;
.CONST $M.GEN.CVC_SEND.PARAMETERS.STRUCT_SIZE                  		138;


#endif // __CVC_SEND_GEN_ASM_H__
