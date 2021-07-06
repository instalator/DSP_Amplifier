#include "define_TAS6424.h"

#define TAS1_ADDR 0x6A
#define TAS2_ADDR 0x6B
#define TAS3_ADDR 0x6C
#define TAS4_ADDR 0x6D

/*void A2B_Reset_TAS6424() { // сброс через шину A2B
  writeByte(A2B_MASTER_ADDR, 0x01, 0x00); //Выбираем  ноду для отправки команды
  writeByte(0x69, 0x01, 0x00);
  writeByte(0x69, 0x00, 0x6A); // Устанавливаем адрес устройства которому отправляем команду 
  writeByte(A2B_MASTER_ADDR, 0x01, 0x20); 
  writeByte(0x69, 0x00, 0x80); // Данные на таргет
  writeByte(A2B_MASTER_ADDR, 0x01, 0x00);
}*/

void Reset_TAS6424() {
    unsigned char reg_data[] = {TAS6424_MODE_CTRL, TAS6424_RESET};
    a2b_NodeI2CSlaveWrite(0x00, TAS1_ADDR, &reg_data[0u]); // Сброс TAS1_ADDR на 0 ноде
    a2b_NodeI2CSlaveWrite(0x00, TAS2_ADDR, &reg_data[0u]); // Сброс TAS2_ADDR на 0 ноде
}

void reset_fault_TAS6424() {
    unsigned char reg_data[] = {TAS6424_MISC_CTRL3, TAS6424_CLEAR_FAULT};
    a2b_NodeI2CSlaveWrite(0x00, TAS1_ADDR, &reg_data[0u]);
}

void chk_fault_TAS6424() {
    Serial.print("1-TAS6424: WARN - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS1_ADDR, TAS6424_WARN), HEX);
    Serial.print(" /GLOB_FAULT1 - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS1_ADDR, TAS6424_GLOB_FAULT1), HEX);
    Serial.print(" /CHANNEL_STATE - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS1_ADDR, TAS6424_CHANNEL_STATE), HEX);
    Serial.print(" /CHANNEL_FAULT - ");
    Serial.println(a2b_NodeI2CSlaveRead(0x00, TAS1_ADDR, TAS6424_CHANNEL_FAULT), HEX);

    Serial.print("2-TAS6424: WARN - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS2_ADDR, TAS6424_WARN), HEX);
    Serial.print(" /GLOB_FAULT1 - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS2_ADDR, TAS6424_GLOB_FAULT1), HEX);
    Serial.print(" /CHANNEL_STATE - ");
    Serial.print(a2b_NodeI2CSlaveRead(0x00, TAS2_ADDR, TAS6424_CHANNEL_STATE), HEX);
    Serial.print(" /CHANNEL_FAULT - ");
    Serial.println(a2b_NodeI2CSlaveRead(0x00, TAS2_ADDR, TAS6424_CHANNEL_FAULT), HEX);
}

/*
void chk_fault() {
  Serial.print("TAS6424_WARN - ");
  Serial.println(readByte(TAS1_ADDR, TAS6424_WARN), HEX);
  Serial.print("TAS6424_GLOB_FAULT1 - ");
  Serial.println(readByte(TAS1_ADDR, TAS6424_GLOB_FAULT1), HEX);
  Serial.print("TAS6424_CHANNEL_STATE - ");
  Serial.println(readByte(TAS1_ADDR, TAS6424_CHANNEL_STATE), HEX);
  Serial.print("TAS6424_CHANNEL_FAULT - ");
  Serial.println(readByte(TAS1_ADDR, TAS6424_CHANNEL_FAULT), HEX);
}

void Reset_TAS6424() {
  writeByte(TAS1_ADDR, TAS6424_MODE_CTRL, TAS6424_RESET);
  writeByte(TAS2_ADDR, TAS6424_MODE_CTRL, TAS6424_RESET);
  //I2C2.writeByte(TAS3_ADDR, TAS6424_MODE_CTRL, TAS6424_RESET);
  //I2C2.writeByte(TAS4_ADDR, TAS6424_MODE_CTRL, TAS6424_RESET);
  delay(500);
}

void tas_init() {
  Reset_TAS6424();
  delay(1000);
  writeByte(TAS1_ADDR, TAS6424_MISC_CTRL3, TAS6424_CLEAR_FAULT); //Clear fault 0x80
  writeByte(TAS1_ADDR, TAS6424_MISC_CTRL1, 0x30); //Gain level 1 = 7.6 V peak output voltage 0x30
  writeByte(TAS1_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_RATE_48000); //48 kHz
  writeByte(TAS1_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_LEFTJ); //Left justified (16-bit or 24-bit) 0x45
  writeByte(TAS1_ADDR, TAS6424_MISC_CTRL2, 0x72); // 48 × fS (2.12 MHz / not supported), 64x OSR, 45 degrees output-phase switching offset 0x72
  //writeByte(TAS1_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_TDM_SLOT_SWAP);
  writeByte(TAS1_ADDR, TAS6424_CH_STATE_CTRL, TAS6424_ALL_STATE_PLAY); //ALL_STATE_PLAY 0x00

  writeByte(TAS2_ADDR, TAS6424_MISC_CTRL3, TAS6424_CLEAR_FAULT); //Clear fault
  writeByte(TAS2_ADDR, TAS6424_MISC_CTRL1, 0x30); //Gain level 1 = 7.6 V peak output voltage
  writeByte(TAS3_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_TDM_SLOT_LAST);
  //writeByte(TAS2_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_TDM_SLOT_SWAP);
  writeByte(TAS2_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_RATE_48000); //48 kHz
  writeByte(TAS2_ADDR, TAS6424_SAP_CTRL, TAS6424_SAP_LEFTJ); //Left justified (16-bit or 24-bit)
  writeByte(TAS2_ADDR, TAS6424_MISC_CTRL2, 0x72); // 48 × fS (2.12 MHz / not supported), 64x OSR, 45 degrees output-phase switching offset
  writeByte(TAS2_ADDR, TAS6424_CH_STATE_CTRL, TAS6424_ALL_STATE_PLAY); //ALL_STATE_PLAY
}


*/
/*
   One thing I would do different is after reset bit 7 register 0x00, you can clear the fault bit 7 register 0x21. Do this while the device is in standby, i.e. standby is asserted.
  void vInitial_TAS6424(void) {
  // Go out standby mode
  STANDBY_DISABLE();
  // Wait for DC Diagnostic Finish
  vDelayNxUnitTime(TAS6424_InitialTime);
  // Reset TAS6424
  vI2C_RamdomWrite(MODE_CONTROL, 0x80);
  vI2C_RamdomWrite(MODE_CONTROL, 0);
  vI2C_RamdomWrite(MISC_CONTROL1, 0x30);
  // vI2C_RamdomWrite(MISC_CONTROL2, 0x62); // 10 × fS (441 kHz / 480 kHz), 64x OSR, 45 degrees output-phase switching offset
  vI2C_RamdomWrite(SAP_CONTROL, 0x44); // Input sample rate is 48KHz and input format is I2S 16bits ro 24bits
  // vI2C_RamdomWrite(MISC_CONTROL4, 0x40); // 3.7Hz
  // vI2C_RamdomWrite(DC_DIAG_CONTROL1, 1);
  vI2C_RamdomWrite(MISC_CONTROL3, 0x88); // Clear nFault
  // vI2C_RamdomWrite(CLIP_CONTROL, 0); // Clip Disable
  vTAS6424_SetVolumeLevel(DEFAULT_VOLUME_LEVEL); // Set volume level to -18dB
  vI2C_RamdomWrite(CH_STATE_CONTROL, 0); // Set all channel to play mode

  // bI2C_RamdomRead(CH_FAULTS);
  // bI2C_RamdomRead(GLOBAL_FAULTS1);
  // bI2C_RamdomRead(GLOBAL_FAULTS2);
  // bI2C_RamdomRead(WARNINGS);
  // bI2C_RamdomRead(MISC_CONTROL3);
  // bI2C_RamdomRead(ILIMIT_STATUS);
  }*/
