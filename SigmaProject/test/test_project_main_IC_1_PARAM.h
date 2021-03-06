/*
 * File:           S:\!APMLIFIER\Amplifier 4_0\sigma_project\test\test_project_main_IC_1_PARAM.h
 *
 * Created:        Friday, July 02, 2021 10:41:02 AM
 * Description:    test_project_main:IC 1 parameter RAM definitions.
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
#ifndef __TEST_PROJECT_MAIN_IC_1_PARAM_H__
#define __TEST_PROJECT_MAIN_IC_1_PARAM_H__


/* Module SPDIF RX - Asrc Input with Gain*/
#define MOD_SPDIFRX_COUNT                              2
#define MOD_SPDIFRX_DEVICE                             "IC1"
#define MOD_SPDIFRX_ALG0_GAIN1_ADDR                    0
#define MOD_SPDIFRX_ALG0_GAIN1_VALUE                   SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_SPDIFRX_ALG0_GAIN1_TYPE                    SIGMASTUDIOTYPE_8_24
#define MOD_SPDIFRX_ALG0_GAIN0_ADDR                    20
#define MOD_SPDIFRX_ALG0_GAIN0_VALUE                   SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_SPDIFRX_ALG0_GAIN0_TYPE                    SIGMASTUDIOTYPE_8_24

/* Module SafeLoadModule - SafeLoadModule*/
#define MOD_SAFELOADMODULE_COUNT                       10
#define MOD_SAFELOADMODULE_DEVICE                      "IC1"
#define MOD_SAFELOADMODULE_DATA_SAFELOAD0_ADDR         24576
#define MOD_SAFELOADMODULE_DATA_SAFELOAD1_ADDR         24577
#define MOD_SAFELOADMODULE_DATA_SAFELOAD2_ADDR         24578
#define MOD_SAFELOADMODULE_DATA_SAFELOAD3_ADDR         24579
#define MOD_SAFELOADMODULE_DATA_SAFELOAD4_ADDR         24580
#define MOD_SAFELOADMODULE_ADDRESS_SAFELOAD_ADDR       24581
#define MOD_SAFELOADMODULE_NUM_SAFELOAD_ADDR           24582

/* Module NxM Mixer1 - NxM Mixer*/
#define MOD_NXMMIXER1_COUNT                            80
#define MOD_NXMMIXER1_DEVICE                           "IC1"
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0000_ADDR 21
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0000_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0000_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0001_ADDR 22
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0001_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0001_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0002_ADDR 23
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0002_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0002_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0003_ADDR 24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0003_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0003_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0004_ADDR 25
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0004_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0004_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0005_ADDR 26
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0005_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0005_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0006_ADDR 27
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0006_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0006_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0007_ADDR 28
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0007_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.00158489319246111)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0007_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0008_ADDR 29
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0008_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0446683592150963)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0008_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0009_ADDR 30
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0009_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0009_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0100_ADDR 31
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0100_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1.99526231496888)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0100_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0101_ADDR 32
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0101_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0101_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0102_ADDR 33
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0102_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0102_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0103_ADDR 34
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0103_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0103_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0104_ADDR 35
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0104_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0104_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0105_ADDR 36
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0105_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0105_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0106_ADDR 37
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0106_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0001)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0106_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0107_ADDR 38
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0107_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.223872113856834)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0107_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0108_ADDR 39
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0108_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(0.0316227766016838)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0108_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0109_ADDR 40
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0109_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1.12201845430196)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0109_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0200_ADDR 41
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0200_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0200_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0201_ADDR 42
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0201_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0201_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0202_ADDR 43
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0202_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0202_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0203_ADDR 44
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0203_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0203_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0204_ADDR 45
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0204_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0204_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0205_ADDR 46
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0205_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0205_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0206_ADDR 47
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0206_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0206_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0207_ADDR 48
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0207_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0207_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0208_ADDR 49
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0208_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0208_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0209_ADDR 50
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0209_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0209_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0300_ADDR 51
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0300_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0300_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0301_ADDR 52
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0301_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0301_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0302_ADDR 53
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0302_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0302_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0303_ADDR 54
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0303_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0303_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0304_ADDR 55
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0304_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0304_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0305_ADDR 56
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0305_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0305_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0306_ADDR 57
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0306_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0306_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0307_ADDR 58
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0307_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0307_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0308_ADDR 59
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0308_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0308_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0309_ADDR 60
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0309_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0309_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0400_ADDR 61
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0400_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0400_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0401_ADDR 62
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0401_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0401_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0402_ADDR 63
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0402_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0402_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0403_ADDR 64
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0403_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0403_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0404_ADDR 65
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0404_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0404_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0405_ADDR 66
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0405_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0405_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0406_ADDR 67
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0406_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0406_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0407_ADDR 68
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0407_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0407_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0408_ADDR 69
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0408_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0408_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0409_ADDR 70
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0409_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0409_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0500_ADDR 71
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0500_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0500_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0501_ADDR 72
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0501_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0501_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0502_ADDR 73
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0502_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0502_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0503_ADDR 74
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0503_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0503_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0504_ADDR 75
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0504_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0504_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0505_ADDR 76
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0505_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0505_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0506_ADDR 77
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0506_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0506_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0507_ADDR 78
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0507_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0507_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0508_ADDR 79
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0508_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0508_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0509_ADDR 80
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0509_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0509_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0600_ADDR 81
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0600_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0600_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0601_ADDR 82
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0601_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0601_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0602_ADDR 83
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0602_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0602_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0603_ADDR 84
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0603_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0603_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0604_ADDR 85
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0604_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0604_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0605_ADDR 86
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0605_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0605_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0606_ADDR 87
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0606_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0606_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0607_ADDR 88
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0607_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0607_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0608_ADDR 89
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0608_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0608_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0609_ADDR 90
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0609_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0609_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0700_ADDR 91
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0700_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0700_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0701_ADDR 92
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0701_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0701_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0702_ADDR 93
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0702_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0702_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0703_ADDR 94
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0703_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0703_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0704_ADDR 95
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0704_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0704_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0705_ADDR 96
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0705_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0705_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0706_ADDR 97
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0706_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0706_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0707_ADDR 98
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0707_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1.12201845430196)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0707_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0708_ADDR 99
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0708_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0708_TYPE SIGMASTUDIOTYPE_8_24
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0709_ADDR 100
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0709_VALUE SIGMASTUDIOTYPE_8_24_CONVERT(1)
#define MOD_NXMMIXER1_ALG0_NXNMIXS3004P6ALG1VOL0709_TYPE SIGMASTUDIOTYPE_8_24

/* Module DC1_2 - DC Input Entry*/
#define MOD_ADC_VOL_DC1_2_COUNT                        1
#define MOD_ADC_VOL_DC1_2_DEVICE                       "IC1"
#define MOD_ADC_VOL_DC1_2_DCINPALG145X1VALUE_ADDR      101
#define MOD_ADC_VOL_DC1_2_DCINPALG145X1VALUE_VALUE     SIGMASTUDIOTYPE_12_20_CONVERT(2000)
#define MOD_ADC_VOL_DC1_2_DCINPALG145X1VALUE_TYPE      SIGMASTUDIOTYPE_12_20

/* Module Mute1 - Mute*/
#define MOD_MUTE1_COUNT                                1
#define MOD_MUTE1_DEVICE                               "IC1"
#define MOD_MUTE1_MUTENOSLEWADAU145XALG1MUTE_ADDR      102
#define MOD_MUTE1_MUTENOSLEWADAU145XALG1MUTE_FIXPT     0x00000001
#define MOD_MUTE1_MUTENOSLEWADAU145XALG1MUTE_VALUE     SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_MUTENOSLEWADAU145XALG1MUTE_TYPE      SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_2 - Mute*/
#define MOD_MUTE1_2_COUNT                              1
#define MOD_MUTE1_2_DEVICE                             "IC1"
#define MOD_MUTE1_2_MUTENOSLEWADAU145XALG2MUTE_ADDR    103
#define MOD_MUTE1_2_MUTENOSLEWADAU145XALG2MUTE_FIXPT   0x00000001
#define MOD_MUTE1_2_MUTENOSLEWADAU145XALG2MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_2_MUTENOSLEWADAU145XALG2MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_3 - Mute*/
#define MOD_MUTE1_3_COUNT                              1
#define MOD_MUTE1_3_DEVICE                             "IC1"
#define MOD_MUTE1_3_MUTENOSLEWADAU145XALG3MUTE_ADDR    104
#define MOD_MUTE1_3_MUTENOSLEWADAU145XALG3MUTE_FIXPT   0x00000001
#define MOD_MUTE1_3_MUTENOSLEWADAU145XALG3MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_3_MUTENOSLEWADAU145XALG3MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_4 - Mute*/
#define MOD_MUTE1_4_COUNT                              1
#define MOD_MUTE1_4_DEVICE                             "IC1"
#define MOD_MUTE1_4_MUTENOSLEWADAU145XALG4MUTE_ADDR    105
#define MOD_MUTE1_4_MUTENOSLEWADAU145XALG4MUTE_FIXPT   0x00000001
#define MOD_MUTE1_4_MUTENOSLEWADAU145XALG4MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_4_MUTENOSLEWADAU145XALG4MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_5 - Mute*/
#define MOD_MUTE1_5_COUNT                              1
#define MOD_MUTE1_5_DEVICE                             "IC1"
#define MOD_MUTE1_5_MUTENOSLEWADAU145XALG5MUTE_ADDR    106
#define MOD_MUTE1_5_MUTENOSLEWADAU145XALG5MUTE_FIXPT   0x00000001
#define MOD_MUTE1_5_MUTENOSLEWADAU145XALG5MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_5_MUTENOSLEWADAU145XALG5MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_6 - Mute*/
#define MOD_MUTE1_6_COUNT                              1
#define MOD_MUTE1_6_DEVICE                             "IC1"
#define MOD_MUTE1_6_MUTENOSLEWADAU145XALG6MUTE_ADDR    107
#define MOD_MUTE1_6_MUTENOSLEWADAU145XALG6MUTE_FIXPT   0x00000001
#define MOD_MUTE1_6_MUTENOSLEWADAU145XALG6MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_6_MUTENOSLEWADAU145XALG6MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_7 - Mute*/
#define MOD_MUTE1_7_COUNT                              1
#define MOD_MUTE1_7_DEVICE                             "IC1"
#define MOD_MUTE1_7_MUTENOSLEWADAU145XALG7MUTE_ADDR    108
#define MOD_MUTE1_7_MUTENOSLEWADAU145XALG7MUTE_FIXPT   0x00000001
#define MOD_MUTE1_7_MUTENOSLEWADAU145XALG7MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_7_MUTENOSLEWADAU145XALG7MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module Mute1_8 - Mute*/
#define MOD_MUTE1_8_COUNT                              1
#define MOD_MUTE1_8_DEVICE                             "IC1"
#define MOD_MUTE1_8_MUTENOSLEWADAU145XALG8MUTE_ADDR    109
#define MOD_MUTE1_8_MUTENOSLEWADAU145XALG8MUTE_FIXPT   0x00000001
#define MOD_MUTE1_8_MUTENOSLEWADAU145XALG8MUTE_VALUE   SIGMASTUDIOTYPE_INTEGER_CONVERT(1)
#define MOD_MUTE1_8_MUTENOSLEWADAU145XALG8MUTE_TYPE    SIGMASTUDIOTYPE_INTEGER

/* Module IndirectParamAccessModule - IndirectParamAccessModule*/
#define MOD_INDIRECTPARAMACCESSMODULE_COUNT            18
#define MOD_INDIRECTPARAMACCESSMODULE_DEVICE           "IC1"
#define MOD_INDIRECTPARAMACCESSMODULE_START_ADDRESS_ADDR 24583
#define MOD_INDIRECTPARAMACCESSMODULE_NUM_OF_LOADS_AND_TRIGGER_ADDR 24584
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_00_00_ADDR 24585
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_00_01_ADDR 24586
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_00_02_ADDR 24587
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_00_03_ADDR 24588
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_01_00_ADDR 24589
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_01_01_ADDR 24590
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_01_02_ADDR 24591
#define MOD_INDIRECTPARAMACCESSMODULE_NXM_MIXER1_VOL_01_03_ADDR 24592
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES0_ADDR  24593
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES1_ADDR  24594
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES2_ADDR  24595
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES3_ADDR  24596
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES4_ADDR  24597
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES5_ADDR  24598
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES6_ADDR  24599
#define MOD_INDIRECTPARAMACCESSMODULE_ADDRESSES7_ADDR  24600

/* Module Slew vol 1_2 - Single Slew Ext Vol*/
#define MOD_ADC_VOL_SLEWVOL1_2_COUNT                   1
#define MOD_ADC_VOL_SLEWVOL1_2_DEVICE                  "IC1"
#define MOD_ADC_VOL_SLEWVOL1_2_SLEW_MODE_ADDR          24603
#define MOD_ADC_VOL_SLEWVOL1_2_SLEW_MODE_FIXPT         0x00003CF0
#define MOD_ADC_VOL_SLEWVOL1_2_SLEW_MODE_VALUE         SIGMASTUDIOTYPE_INTEGER_CONVERT(15600)
#define MOD_ADC_VOL_SLEWVOL1_2_SLEW_MODE_TYPE          SIGMASTUDIOTYPE_INTEGER

#endif
