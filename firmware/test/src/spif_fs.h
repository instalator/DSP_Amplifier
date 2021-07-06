#define FORMAT_FILESYSTEM false

void saveConfig() {
    DynamicJsonDocument jsonBuffer(512);
    jsonBuffer["mqtt_server"] = MQTT_SERVER;
    jsonBuffer["mqtt_port"] = MQTT_PORT;
    jsonBuffer["mqtt_user"] = MQTT_USER ? MQTT_USER : '\0';
    jsonBuffer["mqtt_pass"] = MQTT_PASSWORD ? MQTT_PASSWORD : '\0';
    jsonBuffer["mqtt_client_id"] = MQTT_CLIENT_ID ? MQTT_CLIENT_ID : "module";
    if (MQTT_TOPIC[strlen(MQTT_TOPIC) - 1] != '/') {
        byte l = strlen(MQTT_TOPIC);
        MQTT_TOPIC[l] = '/';
        MQTT_TOPIC[l + 1] = '\0';
    }
    jsonBuffer["mqtt_topic"] = MQTT_TOPIC;
    jsonBuffer["host_name"] = HOST_NAME;
    jsonBuffer["retain"] = retain;
    File configFile = SPIFFS.open("/config.json", "w");
    if (!configFile) {
        //ticker.attach(0.1, tick);
        //failed to open config file for writing
    } else {
        //serializeJson(jsonBuffer, Serial);
        serializeJson(jsonBuffer, configFile);
        configFile.close();
    }
}

void spiffs_setup() {
    if (FORMAT_FILESYSTEM) SPIFFS.format();

    if (SPIFFS.exists("/config.json")) {
        File configFile = SPIFFS.open("/config.json", "r");
        if (configFile) {
            size_t size = configFile.size();
            std::unique_ptr<char[]> buf(new char[size]);
            configFile.readBytes(buf.get(), size);
            DynamicJsonDocument jsonBuffer(1024);
            DeserializationError error = deserializeJson(jsonBuffer, buf.get());
            //serializeJson(jsonBuffer, DBG_OUTPUT_PORT);
            if (!error) {
                if (!jsonBuffer.containsKey("host_name")) {
                    jsonBuffer["host_name"] = HOST_NAME;
                }
                if (!jsonBuffer.containsKey("retain")) {
                    jsonBuffer["retain"] = retain;
                }
                strcpy(MQTT_SERVER, jsonBuffer["mqtt_server"]);
                strcpy(MQTT_PORT, jsonBuffer["mqtt_port"]);
                strcpy(MQTT_USER, jsonBuffer["mqtt_user"]);
                strcpy(MQTT_PASSWORD, jsonBuffer["mqtt_pass"]);
                strcpy(MQTT_CLIENT_ID, jsonBuffer["mqtt_client_id"]);
                strcpy(MQTT_TOPIC, jsonBuffer["mqtt_topic"]);
                strcpy(HOST_NAME, jsonBuffer["host_name"]);
                strcpy(retain, jsonBuffer["retain"]);
            } else {
                saveConfig();
                //Serial.println("failed to load json config");
            }
        } else {
            saveConfig();
        }
    } else {
        //Serial.println("failed SPIFFS.exists");
        saveConfig();
    }
}