/*!
\copyright  Copyright (c) 2020 Qualcomm Technologies International, Ltd.
            All Rights Reserved.
            Qualcomm Technologies International, Ltd. Confidential and Proprietary.
\version    
\file       
\brief      Constant data needed for the key used to authenticate the 
            devic etest service.

The Device Test Service key is generated by the host and compiled into
the application.
*/

#include "device_test_service_key.h"

const DTS_AUTH_KEY_T device_test_service_auth_key = {
    {
        0x7b,     /* 00 */
        0x0e,     /* 01 */
        0x19,     /* 02 */
        0xc6,     /* 03 */
        0xd9,     /* 04 */
        0xb7,     /* 05 */
        0x4a,     /* 06 */
        0xcc,     /* 07 */
        0x99,     /* 08 */
        0x6d,     /* 09 */
        0x35,     /* 10 */
        0x61,     /* 11 */
        0xa9,     /* 12 */
        0x74,     /* 13 */
        0x5a,     /* 14 */
        0x7f      /* 15 */
    }
};