uint8_t handlerWriteDSPRegister(uint8_t *payload) {
    uint16_t regAddr = strtol(strtok((char *) payload + 1, "|"), NULL, 16);
    char *str = strtok(NULL, "|");
    char tmp[3];
    tmp[2] = '\0';
    uint8_t bytes[strlen(str)];
    uint8_t count = 0;
    for (uint8_t i = 0; i < strlen(str); i += 2) {
        tmp[0] = str[i];
        tmp[1] = str[i + 1];
        bytes[count] = strtol(tmp, NULL, 16);
        count++;
    }
    return dsp_I2C_Write(regAddr, count, bytes);
}

uint8_t handlerWriteA2BRegister(uint8_t *payload) {
    uint8_t bytes[2];
    uint8_t node = strtol(strtok((char *) payload + 2, "|"), NULL, 16);
    uint8_t slaveAddr = strtol(strtok(NULL, "|"), NULL, 16);
    uint16_t _bytes = strtol(strtok(NULL, "|"), NULL, 16);
    bytes[0] = _bytes >> 8;
    bytes[1] = _bytes & 0xff;
    return a2b_NodeI2CSlaveWrite(node, slaveAddr, bytes);
}

String handlerReadDSPRegister(uint8_t *payload) {
    uint16_t regAddr = strtol(strtok((char *) payload + 1, "|"), NULL, 16);
    uint8_t count = strtol(strtok(NULL, "|"), NULL, 16);
    uint8_t buf[count];
    dsp_I2C_Read(regAddr, count, buf, 0);
    String str;
    for (byte i = 0; i < count; i++) {
        if (buf[i] < 16) {
            str += "0";
            str += String(buf[i], HEX);
        } else {
            str += String(buf[i], HEX);
        }
    }
    return str;
}

String handlerReadA2BRegister(uint8_t *payload) {
    uint8_t node = strtol(strtok((char *) payload + 2, "|"), NULL, 16);
    uint8_t slaveAddr = strtol(strtok(NULL, "|"), NULL, 16);
    uint8_t AddrReg = strtol(strtok(NULL, "|"), NULL, 16);
    uint8_t res = a2b_NodeI2CSlaveRead(node, slaveAddr, AddrReg);
    String str;
    if (res < 16) {
        str += "0";
    }
    str += String(res, HEX);
    return str;
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t lenght) {
    switch (type) {
        case WStype_DISCONNECTED:
            Serial.printf("ws: [%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED: {
            IPAddress ip = ws.remoteIP(num);
            Serial.printf("ws: [%u] client connected from %d.%d.%d.%d \n", num, ip[0], ip[1], ip[2], ip[3]);
            ws.sendTXT(num, "Connected");
        }
            break;
        case WStype_TEXT: {
            Serial.printf("ws: [%u] client send command: %s\n", num, payload);
            uint8_t res = 4;
            if (payload[0] == 'W') {
                //// W[uint16_t reg][bytes]  WFFFF|FFFFFFFF  W0066|00000001
                //// W[uint8_t node][uint8_t slaveAddr][bytes(addr,data)] WN0|FF|FF00  WN00|6A|2180
                if (payload[1] == 'N') {
                    res = handlerWriteA2BRegister(payload);
                } else {
                    res = handlerWriteDSPRegister(payload);
                }
                if (res == 0) {
                    ws.sendTXT(num, "OK");
                } else {
                    ws.sendTXT(num, "Error");
                }
            } else if (payload[0] == 'R') {
                //// R[uint16_t reg][unsigned short count]  RFFFF|FF  R0066|04
                //// R[uint8_t node][uint8_t slaveAddr][unsigned char AddrReg] RN00|FF|FF  RN00|6A|0F
                String str;
                if (payload[1] == 'N') {
                    str = handlerReadA2BRegister(payload);
                } else {
                    str = handlerReadDSPRegister(payload);
                }
                ws.sendTXT(num, str);
            } else if (payload[0] == 'P') { //Save to config.json
                DynamicJsonDocument jsonBuffer(1024);
                DeserializationError error = deserializeJson(jsonBuffer, payload);
                //serializeJson(jsonBuffer, DBG_OUTPUT_PORT);
                if (!error) {
                    strcpy(MQTT_SERVER, jsonBuffer["mqtt_server"]);
                    strcpy(MQTT_PORT, jsonBuffer["mqtt_port"]);
                    strcpy(MQTT_USER, jsonBuffer["mqtt_user"]);
                    strcpy(MQTT_PASSWORD, jsonBuffer["mqtt_pass"]);
                    strcpy(MQTT_CLIENT_ID, jsonBuffer["mqtt_client_id"]);
                    strcpy(MQTT_TOPIC, jsonBuffer["mqtt_topic"]);
                    strcpy(HOST_NAME, jsonBuffer["host_name"]);
                    strcpy(retain, jsonBuffer["retain"]);
                    File configFile = SPIFFS.open("/config.json", "w");
                    if (!configFile) {
                        ticker.attach(0.1, tick);
                    } else {
                        //serializeJson(jsonBuffer, Serial);
                        serializeJson(jsonBuffer, configFile);
                        configFile.close();
                    }
                    ws.sendTXT(num, "OK");
                } else {
                    //DBG_OUTPUT_PORT.println("failed to load json config");
                    ws.sendTXT(num, "failed to load json config");
                }
            } else if (payload[0] == 'V') { // V14_66 V14_10
                payload[lenght] = '\0';
                String _payload = String((char *) payload);
                uint8_t buf[4];
                byte input = _payload.substring(2).toInt();
                byte output = _payload.substring(1, 2).toInt() * 10;
                float vol = _payload.substring(4).toFloat() / 100.0000; //TODO Decibel Conversion
                int32ToBuffer(floatToInt32(vol), buf);
                dsp_I2C_Write((MOD_NXMMIXER1_ALG0_START_ADDR + output + input), 4, buf);
                ws.sendTXT(num, "OK");
            } else if (payload[0] == 'M') { //  M1_1  M1_0
                uint8_t buf[4];
                payload[lenght] = '\0';
                String _payload = String((char *) payload);
                byte output = _payload.substring(1, 2).toInt() - 1;
                byte st = _payload.substring(3).toInt();
                if (st == 1) {
                    intToFixed(0, buf);
                } else {
                    intToFixed(1, buf);
                }
                dsp_I2C_Write((MOD_MUTE_DEVICE_START_ADDR + output), 4, buf);
                ws.sendTXT(num, "OK");
            } else if (payload[0] == 'Q') { // Reboot ESP
                ws.sendTXT(num, "OK");
                ticker.attach(0.1, tick);
                delay(3000);
                ESP.restart();
            } else if (payload[0] == 'T') {
                ws.sendTXT(num, "OK");
                resetConfig();
            } else {
                //checkPayload(payload, num);
            }
        }
        default:
            break;
    }
}

void websocket_setup() {
    ws.begin();
    ws.onEvent(webSocketEvent);
}