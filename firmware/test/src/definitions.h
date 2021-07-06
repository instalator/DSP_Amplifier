
#define FM_VERSION "0.0.1"

#define DEBUG

bool USE_TOPIC_SET = false; // Раздельные топики MQTT для управления (SET\#) и статуса

#define WEBSERVER_PORT          80                 // Порт вебсервера
#define WEBSOCKET_PORT          81                 // Порт для вебсокета
#define SIGMA_TCP_PORT          8086               // Порт сокета для TCPi SigmaStudio
#define A2B_MASTER_ADDR         0x68               // I2C адрес мастер ноды A2B
#define A2B_FOR_SLAVE_ADDR      0x69               // I2C адрес мастер ноды A2B для отправки на слейв
#define DSP_I2C_ADDRESS         (0x70 >> 1) & 0xFE // I2C адрес ADAU

//#define WEBSOCKETS_NETWORK_TYPE NETWORK_ESP32_ETH
//#define WEBSOCKETS_SERVER_CLIENT_MAX (10)

char MQTT_SERVER[41] = "192.168.88.10";     // IP адрес MQTT сервера
char MQTT_PORT[6] = "1883";                 // Порт MQTT сервера
char MQTT_USER[21] = "";                    // Пользователь для подключения к MQTT серверу
char MQTT_PASSWORD[21] = "";                // Пароль для подключения к MQTT серверу
char MQTT_CLIENT_ID[21] = "DSP_Amplifier";  // ID клиента MQTT
char MQTT_TOPIC[41] = "Amplifier/";         // Главный топик MQTT
char HOST_NAME[21] = "DSP Amplifier";       // Наименование хоста
char retain[6] = "false";

#define MOD_NXMMIXER1_ALG0_START_ADDR   21  // Адрес первого регулятора mixer
#define MOD_MUTE_DEVICE_START_ADDR      102 // Адрес первого регулятора mute
#define MOD_NXMMIXER_OUTPUT             8   // Количество выходов миксера
#define MOD_NXMMIXER_INPUT              10  // Количество входов миксера

/**
 *  hardware pin define
 */
#define TRIGGER_1       34  // Триггерный вход 1
#define TRIGGER_2       35  // Триггерный вход 2
#define LED_STATUS      15  // Светодиод статуса на верхней панели
#define RESET_LAN8720   5   // Пин для сброса чипа lan8720
#define RESET_ADAU1452  4   // Пин для сброса чипа adau1452
#define A2B_IRQ         2   // !for rev 2 Вход прерываний от A2B
#define SDA_PIN         33  // I2C SDA
#define SCL_PIN         32  // I2C SCL
#define I2S_BCLK_PIN    16  // I2S BCLK Pin
#define I2S_LRCLK_PIN   12  // I2S LRCLK Pin
#define I2S_DOUT_PIN    17  // I2S Data Out Pin

#ifdef DEBUG
#define DEBUG_PRINT(...)   Serial.print(F(#__VA_ARGS__" = ")); Serial.print (__VA_ARGS__); Serial.print(F(" "))
#else
#define DEBUG_PRINT(...)
#endif
#ifdef DEBUG
#define DEBUG_PRINTLN(...) DEBUG_PRINT(__VA_ARGS__); Serial.println()
#else
#define DEBUG_PRINTLN(...)
#endif

//debug("Chip started: %s, Flash size: %u \n", id.c_str(), ESP.getFlashChipRealSize());
/*#ifdef DEBUG
#define debug(format, ...) Serial.printf_P((PGM_P)F(format), ## __VA_ARGS__)
#else
#define debug(format, ...)
#endif*/
