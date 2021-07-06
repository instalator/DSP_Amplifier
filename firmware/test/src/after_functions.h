unsigned long trigger1Time = 0, trigger2Time = 0;
bool flag1 = false, flag2 = false;

void readTriggers() {
    int tr1 = !digitalRead(TRIGGER_1);
    int tr2 = !digitalRead(TRIGGER_2);
    if (tr1 && !flag1 && millis() - trigger1Time > 100) {
        trigger1Time = millis();
        flag1 = true;
        mqtt_publish("trigger/tr_1_click", "true");
        mqtt_publish("trigger/tr_1_hold", "false");
        ws.broadcastTXT("tr_1_click");
    }
    if (tr1 && flag1 && millis() - trigger1Time > 1000) {
        trigger1Time = millis();
        mqtt_publish("trigger/tr_1_click", "false");
        mqtt_publish("trigger/tr_1_hold", "true");
        ws.broadcastTXT("tr_1_hold");
    }
    if (!tr1 && flag1 && millis() - trigger1Time > 500) {
        flag1 = false;
        trigger1Time = millis();
        mqtt_publish("trigger/tr_1_click", "false");
        mqtt_publish("trigger/tr_1_hold", "false");
        ws.broadcastTXT("tr_1_false");
    }
    if (tr2 && !flag2 && millis() - trigger2Time > 100) {
        trigger2Time = millis();
        flag2 = true;
        mqtt_publish("trigger/tr_2_click", "true");
        mqtt_publish("trigger/tr_2_hold", "false");
        ws.broadcastTXT("tr_2_click");
    }
    if (tr2 && flag2 && millis() - trigger2Time > 1000) {
        trigger2Time = millis();
        mqtt_publish("trigger/tr_2_click", "false");
        mqtt_publish("trigger/tr_2_hold", "true");
        ws.broadcastTXT("tr_2_hold");
    }
    if (!tr2 && flag2 && millis() - trigger2Time > 500) {
        flag2 = false;
        trigger2Time = millis();
        mqtt_publish("trigger/tr_2_click", "false");
        mqtt_publish("trigger/tr_2_hold", "false");
        ws.broadcastTXT("tr_2_false");
    }
}