#include "Arduino.h"
#include "definitions.h"
#include <Ticker.h>
#include <Wire.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ArduinoOTA.h>
#include <ETH.h>
#include <Update.h>
//#include <ESPmDNS.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <SPIFFS.h>
#include <WebSockets.h>
#include <WebSocketsServer.h>
#include "define_AD242x.h"

static bool eth_connected = false;
unsigned long prevtime = 0;
Ticker ticker;
WiFiClient mqttclient;
PubSubClient mqtt(mqttclient);
WebServer web_server(WEBSERVER_PORT);
WebSocketsServer ws = WebSocketsServer(WEBSOCKET_PORT);
WiFiServer sigma_tcp(SIGMA_TCP_PORT/*, 1*/);

#include "functions.h"
#include "dsp.h"
//#include "ble.h"
#include "ethernet.h"
#include "websocket.h"
#include "mqtt.h"
#include "fsbrowser.h"
#include "spif_fs.h"
#include "sigma_tcp.h"
#include "TAS6424.h"
#include "a2b.h"
#include "after_functions.h"

void setup() {
    Serial.begin(115200);
    Wire.begin(SDA_PIN, SCL_PIN, 400000);
    gpio_setup();
    ethernet_setup();
    delay(1000);
    //ble_setup();
    if (SPIFFS.begin()) {
        spiffs_setup();
    }
    mqtt_setup();
    fsbrowser_setup();
    websocket_setup();
    sigma_tcp_setup();
    a2b_init();
    //MDNS.addService("http", "tcp", 80);
    //MDNS.addService("ws", "tcp", 81);
    ticker.detach();
    digitalWrite(LED_STATUS, HIGH);
}

void loop() {
    readTriggers();
    if (eth_connected) {
        checkMQTT();
        delay(2);
        web_server.handleClient();
        delay(2);
        ws.loop();
        delay(2);
        check_sigma();
        delay(2);
    }
    if (millis() - prevtime >= 10000) {
        chk_fault_TAS6424(); // Чтение регистров ошибок на усилителе
        nxnMixTopic();
        outputMuteTopic();
        prevtime = millis();
    }
}