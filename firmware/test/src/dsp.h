
//Проверка самозагрузки DSP - reading back the status of Register 0xF427 (PANIC_FLAG) and Register 0xF428 (PANIC_CODE)
/*void ADAU1452_read_core_status(void){
    uint16_t address, status;
    uint8_t temp[2];
    address = 0xF405;
    adau1452_spi_read(address, temp, 2);
    status = temp[1] + (temp[0] << 8);
//#ifdef ADAU1452_DEBUG
//    DBG_PRINTF_TS("ADAU1452 core status:0x%04x\n", status);
//#endif
}*/

/**
 * Записать данные в регистр ADAU
 * @param regAddr - адрес регистра ADAU
 * @param count - длина передаваемых данных
 * @param bytes - Отправляемые данные на слейв
 * @returns  Wire.endTransmission()
 *          - 0 success\n
 *          - 1 data too long to fit in transmit buffer\n
 *          - 2 received NACK on transmit of address\n
 *          - 3 received NACK on transmit of data\n
 *          - 4 other error
*/
uint8_t dsp_I2C_Write(uint16_t regAddr, unsigned short count, const uint8_t *bytes) {
    Wire.beginTransmission(DSP_I2C_ADDRESS);
    Wire.write(regAddr >> 8);
    Wire.write(regAddr & 0xff);
    for (int i = 0; i < count; i++) {
        Wire.write(bytes[i]);
    }
    return Wire.endTransmission();
}

uint8_t dsp_I2C_Read(uint16_t regAddr, unsigned short count, uint8_t *buf, uint8_t size) {
    Wire.beginTransmission(DSP_I2C_ADDRESS);
    Wire.write(regAddr >> 8);
    Wire.write(regAddr & 0xff);
    Wire.endTransmission(true);
    if (Wire.requestFrom(DSP_I2C_ADDRESS, count)) {
        while (Wire.available()) {
            buf[size] = Wire.read();
            size++;
        }
    }
    return 0; // if < 0 false;
}

/**
 * Читаем один байт
 * @param devAddr - адрес устройства
 * @param regAddr - адрес регистра
 * @return response Прочитанные данные
 */
uint8_t readByte(uint8_t devAddr, uint8_t regAddr) {
    uint8_t response = 0;
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.endTransmission(true);
    if (Wire.requestFrom(devAddr, uint8_t(1))) {
        while (Wire.available()) {
            response = Wire.read();
        }
    }
    return response;
}

/**
 * Записать один байт
 * @param devAddr - адрес устройства
 * @param regAddr - адрес регистра
 * @param byte - байт для записи
 * @return  Wire.endTransmission()
 */
uint8_t writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t byte) {
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.write(byte);
    return Wire.endTransmission();
}

/**
 * Передать несколько байт трансиверу A2B
 * @param devAddr - адрес устройства
 * @param count - количество передаваемых байт
 * @param bytes - данные
 * @return Wire.endTransmission()
 */
uint8_t a2b_I2C_Write(unsigned short devAddr, unsigned short count, unsigned char *bytes) {
    Wire.beginTransmission(devAddr);
    for (uint8_t i = 0; i < count; i++) {
        Wire.write(bytes[i]);
    }
    return Wire.endTransmission();
}

/**
 * Отправить данные в регистр на слейв на шине A2B по номеру ноды A2B
 * @param node - Номер ноды в сети A2B
 * @param slaveAddr - i2c адрес слейва на ноде A2B
 * @param bytes - Отправляемые данные на слейв
 * @returns  Wire.endTransmission()
*/
uint8_t a2b_NodeI2CSlaveWrite(uint8_t node, uint8_t slaveAddr, unsigned char *bytes) {
    writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, node); //Выбираем  ноду для отправки команды
    writeByte(A2B_FOR_SLAVE_ADDR, REG_AD242X0_NODEADR, REG_AD242X0_NODEADR_RESET); // REG_AD242X0_NODEADR_RESET
    writeByte(A2B_FOR_SLAVE_ADDR, REG_AD242X0_CHIP,
              slaveAddr); // Устанавливаем адрес устройства(слейва) на ноде, которому отправляем команду
    writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, 0x20);
    //Настроили ноду для прямой работы по i2c со слейвами на ее шине.
    writeByte(A2B_FOR_SLAVE_ADDR, bytes[0], bytes[1]); // Данные на таргет bytes[0] - регистр, bytes[1] - значение
    return writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, REG_AD242X0_NODEADR_RESET); // REG_AD242X0_NODEADR_RESET
}

/**
 * Чтение данных регистра со слейва на шине A2B по номеру ноды A2B
 * @param node - Номер ноды в сети A2B
 * @param slaveAddr - i2c адрес слейва на ноде A2B
 * @param AddrReg - Адрес регистра на слейве для чтения
 * @returns  response Прочитанные данные
*/
uint8_t a2b_NodeI2CSlaveRead(uint8_t node, uint8_t slaveAddr, unsigned char AddrReg) {
    //readByte(uint8_t Addr, uint8_t AddrReg)
    writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, node); //Выбираем  ноду для отправки команды
    writeByte(A2B_FOR_SLAVE_ADDR, REG_AD242X0_NODEADR, REG_AD242X0_NODEADR_RESET); // REG_AD242X0_NODEADR_RESET
    writeByte(A2B_FOR_SLAVE_ADDR, REG_AD242X0_CHIP,
              slaveAddr); // Устанавливаем адрес устройства(слейва) на ноде, которому отправляем команду
    writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, 0x20);
    //Настроили ноду для прямой работы по i2c со слейвами на ее шине.
    uint8_t response = readByte(A2B_FOR_SLAVE_ADDR,
                                AddrReg); // Данные на таргет bytes[0] - регистр, bytes[1] - значение
    writeByte(A2B_MASTER_ADDR, REG_AD242X0_NODEADR, REG_AD242X0_NODEADR_RESET); // REG_AD242X0_NODEADR_RESET
    return response;
}