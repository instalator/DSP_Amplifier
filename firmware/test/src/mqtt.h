unsigned long reconnectMqttTimeOut = 5000;
bool rePublishTopics = false;

void publishTopics();

String Topic(String s) {
    return (String(MQTT_TOPIC) + s);
}

void mqtt_publish(String t, const char *st) {
    if (rePublishTopics) {
        mqtt.publish(Topic(t).c_str(), st);
    }
}

/**
 * Публикуем топики миксера и читаем текущие значения регистров
 * @param None
 * @returns None
*/
void nxnMixTopic() {
    uint8_t buf[4];
    for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
        for (int iIn = 0; iIn < MOD_NXMMIXER_INPUT; iIn++) {
            dsp_I2C_Read(MOD_NXMMIXER1_ALG0_START_ADDR + (iOut * 10) + iIn, 4, buf, 0);
            uint32_t val = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
            //DEBUG_PRINTLN(val);
            //DEBUG_PRINTLN(fixedToFloat(val, 8, 24) * 100);
            mqtt_publish(String("NXMMIXERVOL/") + String("NXMMIXERVOL_") +
                         intToConcatZero(iOut) + intToConcatZero(iIn),
                         FloatToChar(fixedToFloat(val, 8, 24) * 100)); //TODO Decibel Conversion
        }
    }
}

/**
 * Публикуем топики Mute и читаем текущие значения регистров
 * @param None
 * @returns None
*/
void outputMuteTopic() {
    uint8_t buf[4];
    for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
        dsp_I2C_Read(MOD_MUTE_DEVICE_START_ADDR + iOut, 4, buf, 0);
        if (buf[3] == 0) {
            mqtt_publish(String("OUTPUT/") + String("MUTE_") + intToConcatZero(iOut), "true");
        } else {
            mqtt_publish(String("OUTPUT/") + String("MUTE_") + intToConcatZero(iOut), "false");
        }
    }
}

/**
 * Публикация топиков при подключении к MQTT серверу
 * @param None
 * @returns None
*/
void publishTopics() {
    mqtt_publish("connection", "true");
    mqtt_publish("status", "online");
    mqtt_publish("register/write", "");
    mqtt_publish("register/read", "");
    mqtt_publish("trigger/tr_1_click", "false");
    mqtt_publish("trigger/tr_1_hold", "false");
    mqtt_publish("trigger/tr_2_click", "false");
    mqtt_publish("trigger/tr_2_hold", "false");
    nxnMixTopic();
    outputMuteTopic();
    if (USE_TOPIC_SET) {
        mqtt_publish("register/set/write", "");
        mqtt_publish("register/set/read", "");
        for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
            mqtt_publish(String("set/") + String("MUTE_") + intToConcatZero(iOut), "true");
        }
        for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
            for (int iIn = 0; iIn < MOD_NXMMIXER_INPUT; iIn++) {
                mqtt_publish(String("NXMMIXERVOL/") + String("NXMMIXERVOL_") +
                             intToConcatZero(iOut) + intToConcatZero(iIn), "");
            }
        }
        mqtt.subscribe(Topic("set/#").c_str());
        mqtt.subscribe(Topic("register/set/#").c_str());
    } else {
        mqtt.subscribe(Topic("#").c_str());
    }
}

void callback(char *_topic, byte *_payload, unsigned int length) {
    _payload[length] = '\0';
    String topic = String(_topic);
    String payload = String((char *) _payload);
    topic.substring(topic.lastIndexOf("/"));

    String cmd = topic.substring(topic.lastIndexOf("/") + 1);
    uint8_t buf[4];
    ///////////
    if (payload == "" || cmd.equals("connection") || cmd.equals("status")) {
        return;
    }
    if (cmd.substring(0, 11).equals("NXMMIXERVOL")) {
        byte input = cmd.substring(14).toInt();
        byte output = cmd.substring(12, 14).toInt() * 10;
        float vol = payload.toFloat() / 100.0000; //TODO Decibel Conversion
        //DEBUG_PRINT(vol, 6);
        //DEBUG_PRINT(floatToInt32(vol), HEX);
        //DEBUG_PRINTLN((MOD_NXMMIXER1_ALG0_START_ADDR + output + input), HEX);
        int32ToBuffer(floatToInt32(vol), buf);
        //DEBUG_PRINT(buf[0], HEX);
        //DEBUG_PRINT(buf[1], HEX);
        //DEBUG_PRINT(buf[2], HEX);
        //DEBUG_PRINTLN(buf[3], HEX);
        dsp_I2C_Write((MOD_NXMMIXER1_ALG0_START_ADDR + output + input), 4, buf);
        nxnMixTopic();
    } else if (cmd.substring(0, 4).equals("MUTE")) {
        byte output = cmd.substring(5).toInt();
        if (payload == "true" || payload == "1") {
            intToFixed(0, buf);
        } else {
            intToFixed(1, buf);
        }
        dsp_I2C_Write((MOD_MUTE_DEVICE_START_ADDR + output), 4, buf);
        outputMuteTopic();
    } else if (cmd.equals("write")) {
        //// W[uint16_t reg][bytes]  WFFFF|FFFFFFFF  W0066|00000001
        //// W[uint8_t node][uint8_t slaveAddr][bytes(addr,data)] WN0|FF|FF00  WN00|6A|2180
        if (payload[0] == 'W') {
            uint8_t res = 4;
            if (payload[1] == 'N') {
                res = handlerWriteA2BRegister(_payload);
            } else {
                res = handlerWriteDSPRegister(_payload);
            }
            if (res == 0) {
                mqtt_publish("register/write", "OK");
            } else {
                mqtt_publish("register/write", "Error");
            }
        }
    } else if (cmd.equals("read")) {
        //// R[uint16_t reg][unsigned short count]  RFFFF|FF  R0066|04
        //// R[uint8_t node][uint8_t slaveAddr][unsigned char AddrReg] RN00|FF|FF  RN00|6A|0F
        if (payload[0] == 'R') {
            String str;
            if (payload[1] == 'N') {
                str = handlerReadA2BRegister(_payload);
            } else {
                str = handlerReadDSPRegister(_payload);
            }
            mqtt_publish("register/read", str.c_str());
        }
    }
    //////////
}

void mqtt_setup() {
    String strBuff = String(MQTT_PORT);
    uint16_t port = strtol(strBuff.c_str(), NULL, 0);
    mqtt.setServer(MQTT_SERVER, port);
    mqtt.setCallback(callback);
}

void mqttReconnect() {
    ticker.attach(2, tick);
    Serial.println("mqtt Reconnect");
    if (!mqtt.connected()) {
        if (MQTT_USER[0] != '\0' || MQTT_PASSWORD[0] != '\0') {
            mqtt.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD, Topic("status").c_str(), 0, true, "offline");
        } else {
            mqtt.connect(MQTT_CLIENT_ID, Topic("status").c_str(), 0, true, "offline");
        }
        ticker.detach();
        digitalWrite(LED_STATUS, HIGH);
    }
}

void checkMQTT() {
    if (!mqtt.connected()) {
        if (millis() - reconnectMqttTimeOut > 5000) {
            reconnectMqttTimeOut = millis();
            rePublishTopics = false;
            mqttReconnect();
        }
    } else {
        mqtt.loop();
        if (!rePublishTopics) {
            rePublishTopics = true;
            publishTopics();
        }
    }
}
