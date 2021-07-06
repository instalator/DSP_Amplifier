/*******************************************************************************
Copyright (c) 2021 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @brief: This file contains I2C command sequence to be followed for discovery 
*         and configuration of A2B nodes for an A2B schematic
* @version: $Revision$
* @date: Tuesday, June 01, 2021-10:51:54 PM
* I2C Command File Version - 1.0.0
* A2B DLL version- 19.3.0
* A2B Stack DLL version- 19.3.0.0
* SigmaStudio version- 4.06.000.1812
* Developed by: Automotive Software and Systems team, Bangalore, India
* THIS IS A SIGMASTUDIO GENERATED FILE
*****************************************************************************/

/*! \addtogroup ADI_A2B_DISCOVERY_CONFIG ADI_A2B_DISCOVERY_CONFIG 
* @{
*/
#ifndef _ADI_A2B_I2C_LIST_H_ 
#define _ADI_A2B_I2C_LIST_H_ 

/*! \struct ADI_A2B_DISCOVERY_CONFIG 
A2B discovery config unit structure 
*/
typedef struct 
 { 
/*!  Device address */
	unsigned char nDeviceAddr;

/*!  Operation code */
	unsigned char eOpCode;

/*! Reg Sub address width (in bytes) */
	unsigned char nAddrWidth;

/*! Reg Sub address */
	unsigned int nAddr;

/*! Reg data width (in bytes) */
	unsigned char nDataWidth;

/*! Reg data count (in bytes) */
	unsigned short nDataCount;

/*! Config Data */
	unsigned char* paConfigData;


} ADI_A2B_DISCOVERY_CONFIG;

#define WRITE   ((unsigned char) 0x00u)
#define READ    ((unsigned char) 0x01u)
#define DELAY   ((unsigned char) 0x02u)
#define INVALID ((unsigned char) 0xffu)

#define CONFIG_LEN (88) 


static unsigned char gaConfig_AD242xMasterNode0_CONTROL_Data0[1] =
{
	0x84u	
};

static unsigned char gaConfig_AD242xMasterNode0_A2BDelay_Data1[1] =
{
	0x19u	
};

static unsigned char gaConfig_AD242xMasterNode0_INTTYPE_Data2[1] =
{
	0x00u	
};

static unsigned char gaConfig_AD242xMasterNode0_INTMSK0_Data3[1] =
{
	0x7Fu	
};

static unsigned char gaConfig_AD242xMasterNode0_INTMSK2_Data4[1] =
{
	0x0Fu	
};

static unsigned char gaConfig_AD242xMasterNode0_RESPCYCS_Data5[1] =
{
	0x90u	
};

static unsigned char gaConfig_AD242xMasterNode0_CONTROL_Data6[1] =
{
	0x01u	
};

static unsigned char gaConfig_AD242xMasterNode0_I2SGCFG_Data7[1] =
{
	0xA2u	
};

static unsigned char gaConfig_AD242xMasterNode0_A2BDelay_Data10[1] =
{
	0x32u	
};

static unsigned char gaConfig_AD242xMasterNode0_SWCTL_Data14[1] =
{
	0x21u	
};

static unsigned char gaConfig_AD242xMasterNode0_DISCVRY_Data16[1] =
{
	0x8Cu	
};

static unsigned char gaConfig_AD242xSlaveESP_LUPSLOTS_Data3[1] =
{
	0x02u	
};

static unsigned char gaConfig_AD242xSlaveESP_I2SGCFG_Data5[1] =
{
	0xE0u	
};

static unsigned char gaConfig_AD242xSlaveESP_I2SCFG_Data6[1] =
{
	0x98u	
};

static unsigned char gaConfig_AD242xSlaveESP_GPIODAT_Data7[1] =
{
	0x60u	
};

static unsigned char gaConfig_AD242xSlaveESP_CLK1CFG_Data9[1] =
{
	0x81u	
};

static unsigned char gaConfig_AD242xSlaveESP_GPIODINV_Data11[1] =
{
	0x20u	
};

static unsigned char gaConfig_AD242xSlaveESP_INTMSK0_Data13[1] =
{
	0x10u	
};

static unsigned char gaConfig_AD242xSlaveESP_CHIPSet_Data14[1] =
{
	0x11u	
};

static unsigned char gaConfig_Amp_1_3_ResetADAU1978_Data0[1] =
{
	0x80u	
};

static unsigned char gaConfig_Amp_1_3_TDM_Data2[1] =
{
	0x42u	
};

static unsigned char gaConfig_AD242xSlaveAmplifier1_I2SGCFG_Data7[1] =
{
	0x22u	
};

static unsigned char gaConfig_AD242xSlaveAmplifier1_DNMASK0_Data13[1] =
{
	0xFFu	
};

static unsigned char gaConfig_AD242xSlaveAmplifier1_CHIPSet_Data17[1] =
{
	0x6Au	
};

static unsigned char gaConfig_Amp_1_1_Gainlevel_Data2[1] =
{
	0x30u	
};

static unsigned char gaConfig_Amp_1_1_48kHz_Data3[1] =
{
	0x46u	
};

static unsigned char gaConfig_Amp_1_1_48fS_Data4[1] =
{
	0x72u	
};

static unsigned char gaConfig_AD242xMasterNode0_I2SCFG_Data30[1] =
{
	0x99u	
};

static unsigned char gaConfig_AD242xMasterNode0_DNSLOTS_Data33[1] =
{
	0x08u	
};

static unsigned char gaConfig_AD242xMasterNode0_SLOTFMT_Data39[1] =
{
	0x44u	
};

static unsigned char gaConfig_AD242xMasterNode0_DATCTL_Data40[1] =
{
	0x03u	
};

#define	gaConfig_AD242xMasterNode0_SWCTL_Data8		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_DISCVRY_Data9		gaConfig_AD242xMasterNode0_RESPCYCS_Data5
#define	gaConfig_AD242xMasterNode0_INTPND2_Data11		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_INTPND2_Data12		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADR_Data13		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_VENDOR_Data0		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_PRODUCT_Data1		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_VERSION_Data2		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_NODEADR_Data15		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_SWCTL_Data3		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_A2BDelay_Data17		gaConfig_AD242xMasterNode0_A2BDelay_Data10
#define	gaConfig_AD242xMasterNode0_INTPND2_Data18		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_INTPND2_Data19		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADR_Data20		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveESP_VENDOR_Data0		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveESP_PRODUCT_Data1		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveESP_VERSION_Data2		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_NODEADR_Data21		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_SWCTL_Data4		gaConfig_AD242xMasterNode0_SWCTL_Data14
#define	gaConfig_AD242xMasterNode0_NODEADR_Data22		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveESP_I2CCFG_Data4		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveESP_GPIOOEN_Data8		gaConfig_AD242xSlaveESP_GPIODAT_Data7
#define	gaConfig_AD242xSlaveESP_CLK2CFG_Data10		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveESP_SUSCFG_Data12		gaConfig_AD242xSlaveESP_GPIODINV_Data11
#define	gaConfig_AD242xMasterNode0_NODEADRSet_Data23		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADREnable_Data24		gaConfig_AD242xMasterNode0_SWCTL_Data14
#define	gaConfig_Amp_1_3_PowerUP_Data1		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_Amp_1_3_Gain1_Data3		gaConfig_AD242xSlaveESP_I2SGCFG_Data5
#define	gaConfig_Amp_1_3_Gain2_Data4		gaConfig_AD242xSlaveESP_I2SGCFG_Data5
#define	gaConfig_AD242xMasterNode0_NODEADRDisable_Data25		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADR_Data26		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_LDNSLOTS_Data5		gaConfig_Amp_1_3_ResetADAU1978_Data0
#define	gaConfig_AD242xSlaveAmplifier1_I2CCFG_Data6		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveAmplifier1_I2SCFG_Data8		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveAmplifier1_GPIODAT_Data9		gaConfig_AD242xSlaveESP_GPIODAT_Data7
#define	gaConfig_AD242xSlaveAmplifier1_GPIOOEN_Data10		gaConfig_AD242xSlaveESP_GPIODAT_Data7
#define	gaConfig_AD242xSlaveAmplifier1_CLK1CFG_Data11		gaConfig_AD242xSlaveESP_CLK1CFG_Data9
#define	gaConfig_AD242xSlaveAmplifier1_CLK2CFG_Data12		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xSlaveAmplifier1_GPIODINV_Data14		gaConfig_AD242xSlaveESP_GPIODINV_Data11
#define	gaConfig_AD242xSlaveAmplifier1_SUSCFG_Data15		gaConfig_AD242xSlaveESP_GPIODINV_Data11
#define	gaConfig_AD242xSlaveAmplifier1_INTMSK0_Data16		gaConfig_AD242xSlaveESP_INTMSK0_Data13
#define	gaConfig_AD242xMasterNode0_NODEADRSet_Data27		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_NODEADREnable_Data28		gaConfig_AD242xSlaveESP_GPIODINV_Data11
#define	gaConfig_Amp_1_1_ResetTAS6424_Data0		gaConfig_Amp_1_3_ResetADAU1978_Data0
#define	gaConfig_Amp_1_1_Clearall_Data1		gaConfig_Amp_1_3_ResetADAU1978_Data0
#define	gaConfig_Amp_1_1_ALLSTATE_Data5		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_NODEADRDisable_Data29		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_CLK1CFG_Data31		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADR_Data32		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_UPSLOTS_Data18		gaConfig_AD242xSlaveESP_LUPSLOTS_Data3
#define	gaConfig_AD242xMasterNode0_UPSLOTS_Data34		gaConfig_AD242xSlaveESP_LUPSLOTS_Data3
#define	gaConfig_AD242xMasterNode0_NODEADR_Data35		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xSlaveAmplifier1_SWCTL_Data19		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_SWCTL_Data36		gaConfig_AD242xMasterNode0_CONTROL_Data6
#define	gaConfig_AD242xMasterNode0_NODEADR_Data37		gaConfig_Amp_1_3_ResetADAU1978_Data0
#define	gaConfig_AD242xMasterNode0_NODEADR_Data38		gaConfig_AD242xMasterNode0_INTTYPE_Data2
#define	gaConfig_AD242xMasterNode0_CONTROL_Data41		gaConfig_AD242xMasterNode0_CONTROL_Data6


ADI_A2B_DISCOVERY_CONFIG gaA2BConfig[CONFIG_LEN] =
{

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000012u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_CONTROL_Data0[0]},	/* CONTROL */
	{0x00u,	DELAY,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_A2BDelay_Data1[0]},	/* A2B_Delay */
	{0x68u,	READ,	0x01u,	0x00000017u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTTYPE_Data2[0]},	/* INTTYPE */
	{0x68u,	WRITE,	0x01u,	0x0000001Bu,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTMSK0_Data3[0]},	/* INTMSK0 */
	{0x68u,	WRITE,	0x01u,	0x0000001Du,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTMSK2_Data4[0]},	/* INTMSK2 */
	{0x68u,	WRITE,	0x01u,	0x0000000Fu,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_RESPCYCS_Data5[0]},	/* RESPCYCS */
	{0x68u,	WRITE,	0x01u,	0x00000012u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_CONTROL_Data6[0]},	/* CONTROL */
	{0x68u,	WRITE,	0x01u,	0x00000041u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_I2SGCFG_Data7[0]},	/* I2SGCFG */
	{0x68u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_SWCTL_Data8[0]},	/* SWCTL */
	{0x68u,	WRITE,	0x01u,	0x00000013u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_DISCVRY_Data9[0]},	/* DISCVRY */
	{0x00u,	DELAY,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_A2BDelay_Data10[0]},	/* A2B_Delay */
	{0x68u,	READ,	0x01u,	0x0000001Au,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTPND2_Data11[0]},	/* INTPND2 */
	{0x68u,	WRITE,	0x01u,	0x0000001Au,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTPND2_Data12[0]},	/* INTPND2 */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data13[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	READ,	0x01u,	0x00000002u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_VENDOR_Data0[0]},	/* VENDOR */
	{0x69u,	READ,	0x01u,	0x00000003u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_PRODUCT_Data1[0]},	/* PRODUCT */
	{0x69u,	READ,	0x01u,	0x00000004u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_VERSION_Data2[0]},	/* VERSION */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_SWCTL_Data14[0]},	/* SWCTL */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data15[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_SWCTL_Data3[0]},	/* SWCTL */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000013u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_DISCVRY_Data16[0]},	/* DISCVRY */
	{0x00u,	DELAY,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_A2BDelay_Data17[0]},	/* A2B_Delay */
	{0x68u,	READ,	0x01u,	0x0000001Au,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTPND2_Data18[0]},	/* INTPND2 */
	{0x68u,	WRITE,	0x01u,	0x0000001Au,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_INTPND2_Data19[0]},	/* INTPND2 */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data20[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave ESP --*/
	{0x69u,	READ,	0x01u,	0x00000002u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_VENDOR_Data0[0]},	/* VENDOR */
	{0x69u,	READ,	0x01u,	0x00000003u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_PRODUCT_Data1[0]},	/* PRODUCT */
	{0x69u,	READ,	0x01u,	0x00000004u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_VERSION_Data2[0]},	/* VERSION */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data21[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_SWCTL_Data4[0]},	/* SWCTL */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data22[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave ESP --*/
	{0x69u,	WRITE,	0x01u,	0x0000000Cu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_LUPSLOTS_Data3[0]},	/* LUPSLOTS */
	{0x69u,	WRITE,	0x01u,	0x0000003Fu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_I2CCFG_Data4[0]},	/* I2CCFG */
	{0x69u,	WRITE,	0x01u,	0x00000041u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_I2SGCFG_Data5[0]},	/* I2SGCFG */
	{0x69u,	WRITE,	0x01u,	0x00000042u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_I2SCFG_Data6[0]},	/* I2SCFG */
	{0x69u,	WRITE,	0x01u,	0x0000004Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_GPIODAT_Data7[0]},	/* GPIODAT */
	{0x69u,	WRITE,	0x01u,	0x0000004Du,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_GPIOOEN_Data8[0]},	/* GPIOOEN */
	{0x69u,	WRITE,	0x01u,	0x00000059u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_CLK1CFG_Data9[0]},	/* CLK1CFG */
	{0x69u,	WRITE,	0x01u,	0x0000005Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_CLK2CFG_Data10[0]},	/* CLK2CFG */
	{0x69u,	WRITE,	0x01u,	0x0000008Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_GPIODINV_Data11[0]},	/* GPIODINV */
	{0x69u,	WRITE,	0x01u,	0x0000005Cu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_SUSCFG_Data12[0]},	/* SUSCFG */
	{0x69u,	WRITE,	0x01u,	0x0000001Bu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_INTMSK0_Data13[0]},	/* INTMSK0 */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADRSet_Data23[0]},	/* NODEADR - Set the node address */

	/*-- COMMANDS FOR DEVICE - AD242x Slave ESP --*/
	{0x69u,	WRITE,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveESP_CHIPSet_Data14[0]},	/* CHIP - Set the chip address */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADREnable_Data24[0]},	/* NODEADR - Enable PERI */

	/*-- COMMANDS FOR DEVICE - Amp_1_3 --*/
	{0x69u,	WRITE,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_Amp_1_3_ResetADAU1978_Data0[0]},	/* Reset ADAU1978 */
	{0x69u,	WRITE,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_Amp_1_3_PowerUP_Data1[0]},	/* Power UP */
	{0x69u,	WRITE,	0x01u,	0x00000005u,	0x01u,	0x0001u,	&gaConfig_Amp_1_3_TDM_Data2[0]},	/* TDM */
	{0x69u,	WRITE,	0x01u,	0x0000000Au,	0x01u,	0x0001u,	&gaConfig_Amp_1_3_Gain1_Data3[0]},	/* Gain 1 */
	{0x69u,	WRITE,	0x01u,	0x0000000Bu,	0x01u,	0x0001u,	&gaConfig_Amp_1_3_Gain2_Data4[0]},	/* Gain 2 */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADRDisable_Data25[0]},	/* NODEADR - Disable PERI */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data26[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x0000000Bu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_LDNSLOTS_Data5[0]},	/* LDNSLOTS */
	{0x69u,	WRITE,	0x01u,	0x0000003Fu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_I2CCFG_Data6[0]},	/* I2CCFG */
	{0x69u,	WRITE,	0x01u,	0x00000041u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_I2SGCFG_Data7[0]},	/* I2SGCFG */
	{0x69u,	WRITE,	0x01u,	0x00000042u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_I2SCFG_Data8[0]},	/* I2SCFG */
	{0x69u,	WRITE,	0x01u,	0x0000004Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_GPIODAT_Data9[0]},	/* GPIODAT */
	{0x69u,	WRITE,	0x01u,	0x0000004Du,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_GPIOOEN_Data10[0]},	/* GPIOOEN */
	{0x69u,	WRITE,	0x01u,	0x00000059u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_CLK1CFG_Data11[0]},	/* CLK1CFG */
	{0x69u,	WRITE,	0x01u,	0x0000005Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_CLK2CFG_Data12[0]},	/* CLK2CFG */
	{0x69u,	WRITE,	0x01u,	0x00000065u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_DNMASK0_Data13[0]},	/* DNMASK0 */
	{0x69u,	WRITE,	0x01u,	0x0000008Au,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_GPIODINV_Data14[0]},	/* GPIODINV */
	{0x69u,	WRITE,	0x01u,	0x0000005Cu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_SUSCFG_Data15[0]},	/* SUSCFG */
	{0x69u,	WRITE,	0x01u,	0x0000001Bu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_INTMSK0_Data16[0]},	/* INTMSK0 */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADRSet_Data27[0]},	/* NODEADR - Set the node address */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_CHIPSet_Data17[0]},	/* CHIP - Set the chip address */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADREnable_Data28[0]},	/* NODEADR - Enable PERI */

	/*-- COMMANDS FOR DEVICE - Amp_1_1 --*/
	{0x69u,	WRITE,	0x01u,	0x00000000u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_ResetTAS6424_Data0[0]},	/* Reset TAS6424 */
	{0x69u,	WRITE,	0x01u,	0x00000021u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_Clearall_Data1[0]},	/* Clear all fault */
	{0x69u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_Gainlevel_Data2[0]},	/* Gain level 1 = 7.6 V peak output voltage */
	{0x69u,	WRITE,	0x01u,	0x00000003u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_48kHz_Data3[0]},	/* 48 kHz / Left justified */
	{0x69u,	WRITE,	0x01u,	0x00000002u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_48fS_Data4[0]},	/* 48 × fS 2.12 MHz */
	{0x69u,	WRITE,	0x01u,	0x00000004u,	0x01u,	0x0001u,	&gaConfig_Amp_1_1_ALLSTATE_Data5[0]},	/* ALL STATE PLAY */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADRDisable_Data29[0]},	/* NODEADR - Disable PERI */
	{0x68u,	WRITE,	0x01u,	0x00000042u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_I2SCFG_Data30[0]},	/* I2SCFG */
	{0x68u,	WRITE,	0x01u,	0x00000059u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_CLK1CFG_Data31[0]},	/* CLK1CFG */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data32[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x0000000Eu,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_UPSLOTS_Data18[0]},	/* UPSLOTS */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x0000000Du,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_DNSLOTS_Data33[0]},	/* DNSLOTS */
	{0x68u,	WRITE,	0x01u,	0x0000000Eu,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_UPSLOTS_Data34[0]},	/* UPSLOTS */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data35[0]},	/* NODEADR */

	/*-- COMMANDS FOR DEVICE - AD242x Slave Amplifier 1 --*/
	{0x69u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xSlaveAmplifier1_SWCTL_Data19[0]},	/* SWCTL */

	/*-- COMMANDS FOR DEVICE - AD242x Master Node0 --*/
	{0x68u,	WRITE,	0x01u,	0x00000009u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_SWCTL_Data36[0]},	/* SWCTL */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data37[0]},	/* NODEADR */
	{0x68u,	WRITE,	0x01u,	0x00000001u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_NODEADR_Data38[0]},	/* NODEADR */
	{0x68u,	WRITE,	0x01u,	0x00000010u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_SLOTFMT_Data39[0]},	/* SLOTFMT */
	{0x68u,	WRITE,	0x01u,	0x00000011u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_DATCTL_Data40[0]},	/* DATCTL */
	{0x68u,	WRITE,	0x01u,	0x00000012u,	0x01u,	0x0001u,	&gaConfig_AD242xMasterNode0_CONTROL_Data41[0]},	/* CONTROL */
};

#endif /* _ADI_A2B_I2C_LIST_H_ */

