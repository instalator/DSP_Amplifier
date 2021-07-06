/*
 * File:           S:\!Усилитель\Усилитель 4_0\sigma_project\test\test_project_a2b_IC_2.h
 *
 * Created:        Tuesday, June 01, 2021 1:47:19 PM
 * Description:    test_project_a2b:IC 2 program data.
 *
 * This software is distributed in the hope that it will be useful,
 * but is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * This software may only be used to program products purchased from
 * Analog Devices for incorporation by you into audio products that
 * are intended for resale to audio product end users. This software
 * may not be distributed whole or in any part to third parties.
 *
 * Copyright ©2021 Analog Devices, Inc. All rights reserved.
 */
#ifndef __TEST_PROJECT_A2B_IC_2_H__
#define __TEST_PROJECT_A2B_IC_2_H__

#include "SigmaStudioFW.h"
#include "test_project_a2b_IC_2_REG.h"

#define DEVICE_ARCHITECTURE_IC_2                  "AD24xx"
#define DEVICE_ADDR_IC_2                          0x68

/* DSP Parameter (Coefficient) Data */
#define PARAM_SIZE_IC_2 0
#define PARAM_ADDR_IC_2 0
ADI_REG_TYPE Param_Data_IC_2[PARAM_SIZE_IC_2] = {

};



/*
 * Default Download
 */
#define DEFAULT_DOWNLOAD_SIZE_IC_2 0

void default_download_IC_2() {
}

#endif
