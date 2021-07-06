#include "StreamString.h"
#define DBG_OUTPUT_PORT Serial
File fsUploadFile;
String _updaterError;

void _setUpdaterError() {
    StreamString str;
    Update.printError(str);
    _updaterError = str.c_str();
}

void httpUpdate() {
    web_server.on("/update", HTTP_POST, [&]() {
        if (Update.hasError()) {
            web_server.send(200, F("text/html"), String(F("Update error: ")) + _updaterError);
        } else {
            web_server.client().setNoDelay(true);
            web_server.send_P(200, PSTR("text/html"), "OK");
            delay(100);
            web_server.client().stop();
            ESP.restart();
        }
    }, [&]() {
        HTTPUpload& upload = web_server.upload();
        if (upload.status == UPLOAD_FILE_START) {
            _updaterError = String();
            //WiFiUDP::stopAll();
            //uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000; // TODO need fixed
            if (!Update.begin(/*maxSketchSpace*/)) { //start with max available size
                _setUpdaterError();
            }
        } else if (upload.status == UPLOAD_FILE_WRITE && !_updaterError.length()) {
            if (Update.write(upload.buf, upload.currentSize) != upload.currentSize) {
                _setUpdaterError();
            }
        } else if (upload.status == UPLOAD_FILE_END && !_updaterError.length()) {
            if (Update.end(true)) { //true to set the size to the current progress
            } else {
                _setUpdaterError();
            }
        } else if (upload.status == UPLOAD_FILE_ABORTED) {
            Update.end();
        }
        delay(0);
    });
}

//format bytes
String formatBytes(size_t bytes) {
    if (bytes < 1024) {
        return String(bytes) + "B";
    } else if (bytes < (1024 * 1024)) {
        return String(bytes / 1024.0) + "KB";
    } else if (bytes < (1024 * 1024 * 1024)) {
        return String(bytes / 1024.0 / 1024.0) + "MB";
    } else {
        return String(bytes / 1024.0 / 1024.0 / 1024.0) + "GB";
    }
}

String getContentType(String filename) {
    if (web_server.hasArg("download")) {
        return "application/octet-stream";
    } else if (filename.endsWith(".htm")) {
        return "text/html";
    } else if (filename.endsWith(".html")) {
        return "text/html";
    } else if (filename.endsWith(".css")) {
        return "text/css";
    } else if (filename.endsWith(".js")) {
        return "application/javascript";
    } else if (filename.endsWith(".png")) {
        return "image/png";
    } else if (filename.endsWith(".gif")) {
        return "image/gif";
    } else if (filename.endsWith(".jpg")) {
        return "image/jpeg";
    } else if (filename.endsWith(".ico")) {
        return "image/x-icon";
    } else if (filename.endsWith(".xml")) {
        return "text/xml";
    } else if (filename.endsWith(".pdf")) {
        return "application/x-pdf";
    } else if (filename.endsWith(".zip")) {
        return "application/x-zip";
    } else if (filename.endsWith(".gz")) {
        return "application/x-gzip";
    }
    return "text/plain";
}

bool exists(String path) {
    bool yes = false;
    File file = SPIFFS.open(path, "r");
    if (!file.isDirectory()) {
        yes = true;
    }
    file.close();
    return yes;
}

String listSettingsJSON(void) {
    DynamicJsonDocument jsonBuffer(1024);
    jsonBuffer["mqtt_server"] = MQTT_SERVER;
    jsonBuffer["mqtt_port"] = MQTT_PORT;
    jsonBuffer["mqtt_user"] = MQTT_USER;
    jsonBuffer["mqtt_pass"] = MQTT_PASSWORD;
    jsonBuffer["mqtt_client_id"] = MQTT_CLIENT_ID;
    jsonBuffer["mqtt_topic"] = MQTT_TOPIC;
    jsonBuffer["host_name"] = HOST_NAME;
    jsonBuffer["retain"] = retain;
    String json_str;
    serializeJson(jsonBuffer, json_str);
    return json_str;
}

String listParamJSON(void) {
    DynamicJsonDocument jsonBuffer(4096);
    uint8_t _buf[4];
    for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
        for (int iIn = 0; iIn < MOD_NXMMIXER_INPUT; iIn++) {
            dsp_I2C_Read(MOD_NXMMIXER1_ALG0_START_ADDR + (iOut * 10) + iIn, 4, _buf, 0);
            uint32_t val = (_buf[0] << 24) | (_buf[1] << 16) | (_buf[2] << 8) | _buf[3];
            jsonBuffer["V_" + intToConcatZero(iOut) + intToConcatZero(iIn)] = fixedToFloat(val, 8, 24) * 100;
        }
    }
    for (int iOut = 0; iOut < MOD_NXMMIXER_OUTPUT; iOut++) {
        dsp_I2C_Read(MOD_MUTE_DEVICE_START_ADDR + iOut, 4, _buf, 0);
        if (_buf[3] == 0) {
            jsonBuffer["M_" + intToConcatZero(iOut)] = 1;
        } else {
            jsonBuffer["M_" + intToConcatZero(iOut)] = 0;
        }
    }
    jsonBuffer["host_name"] = HOST_NAME;
    jsonBuffer["ver"] = FM_VERSION;
    String json_str;
    serializeJson(jsonBuffer, json_str);
    return json_str;
}

bool handleFileRead(String path) {
    DBG_OUTPUT_PORT.println("handleFileRead: " + path);
    if (path.endsWith("/")) {
        path += "index.html";
    }
    String contentType = getContentType(path);
    String pathWithGz = path + ".gz";
    if (exists(pathWithGz) || exists(path)) {
        if (exists(pathWithGz)) {
            path += ".gz";
        }
        File file = SPIFFS.open(path, "r");
        web_server.streamFile(file, contentType);
        file.close();
        return true;
    }
    return false;
}

void handleFileUpload() {
    if (web_server.uri() != "/edit") {
        return;
    }
    HTTPUpload &upload = web_server.upload();
    if (upload.status == UPLOAD_FILE_START) {
        String filename = upload.filename;
        if (!filename.startsWith("/")) {
            filename = "/" + filename;
        }
        DBG_OUTPUT_PORT.print("handleFileUpload Name: ");
        DBG_OUTPUT_PORT.println(filename);
        fsUploadFile = SPIFFS.open(filename, "w");
        filename = String();
    } else if (upload.status == UPLOAD_FILE_WRITE) {
        //DBG_OUTPUT_PORT.print("handleFileUpload Data: "); DBG_OUTPUT_PORT.println(upload.currentSize);
        if (fsUploadFile) {
            fsUploadFile.write(upload.buf, upload.currentSize);
        }
    } else if (upload.status == UPLOAD_FILE_END) {
        if (fsUploadFile) {
            fsUploadFile.close();
        }
        DBG_OUTPUT_PORT.print("handleFileUpload Size: ");
        DBG_OUTPUT_PORT.println(upload.totalSize);
    }
}

void handleFileDelete() {
    if (web_server.args() == 0) {
        return web_server.send(500, "text/plain", "BAD ARGS");
    }
    String path = web_server.arg(0);
    DBG_OUTPUT_PORT.println("handleFileDelete: " + path);
    if (path == "/") {
        return web_server.send(500, "text/plain", "BAD PATH");
    }
    if (!exists(path)) {
        return web_server.send(404, "text/plain", "FileNotFound");
    }
    SPIFFS.remove(path);
    web_server.send(200, "text/plain", "");
    path = String();
}

void handleFileCreate() {
    if (web_server.args() == 0) {
        return web_server.send(500, "text/plain", "BAD ARGS");
    }
    String path = web_server.arg(0);
    DBG_OUTPUT_PORT.println("handleFileCreate: " + path);
    if (path == "/") {
        return web_server.send(500, "text/plain", "BAD PATH");
    }
    if (exists(path)) {
        return web_server.send(500, "text/plain", "FILE EXISTS");
    }
    File file = SPIFFS.open(path, "w");
    if (file) {
        file.close();
    } else {
        return web_server.send(500, "text/plain", "CREATE FAILED");
    }
    web_server.send(200, "text/plain", "");
    path = String();
}

void handleFileList() {
    if (!web_server.hasArg("dir")) {
        web_server.send(500, "text/plain", "BAD ARGS");
        return;
    }

    String path = web_server.arg("dir");
    DBG_OUTPUT_PORT.println("handleFileList: " + path);

    File root = SPIFFS.open(path);
    path = String();

    String output = "[";
    if (root.isDirectory()) {
        File file = root.openNextFile();
        while (file) {
            if (output != "[") {
                output += ',';
            }
            output += "{\"type\":\"";
            output += (file.isDirectory()) ? "dir" : "file";
            output += "\",\"name\":\"";
            output += String(file.name()).substring(1);
            output += "\"}";
            file = root.openNextFile();
        }
    }
    output += "]";
    web_server.send(200, "text/json", output);
}

void fsbrowser_setup() {
    DBG_OUTPUT_PORT.print("\n");
    DBG_OUTPUT_PORT.setDebugOutput(true);

    //SERVER INIT
    //list directory
    web_server.on("/list", HTTP_GET, handleFileList); // list?dir=/
    //load editor
    web_server.on("/edit", HTTP_GET, []() {
        if (!handleFileRead("/edit.htm")) {
            web_server.send(404, "text/plain", "FileNotFound");
        }
    });
    //create file
    web_server.on("/edit", HTTP_PUT, handleFileCreate);
    //delete file
    web_server.on("/edit", HTTP_DELETE, handleFileDelete);

    web_server.on("/edit", HTTP_POST, []() {
        web_server.send(200, "text/plain", "");
    }, handleFileUpload);

    web_server.onNotFound([]() {
        if (!handleFileRead(web_server.uri())) {
            web_server.send(404, "text/plain", "FileNotFound");
        }
    });

    web_server.on("/all", HTTP_GET, []() {
        String json = "{";
        json += "\"heap\":" + String(ESP.getFreeHeap());
        json += ", \"analog\":" + String(analogRead(A0));
        json += ", \"gpio\":" + String((uint32_t)(0));
        json += "}";
        web_server.send(200, "text/json", json);
        json = String();
    });

    web_server.on("/get_param", []() {
        web_server.sendHeader("Access-Control-Allow-Origin", "*");
        web_server.send(200, "application/json", listParamJSON());
    });
    web_server.on("/get_settings", []() {
        web_server.sendHeader("Access-Control-Allow-Origin", "*");
        web_server.send(200, "application/json", listSettingsJSON());
    });
    httpUpdate();
    web_server.begin();
    DBG_OUTPUT_PORT.println("HTTP server started");
}