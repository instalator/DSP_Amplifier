char buffer[100];

#define UINT32_GET_BIT_RANGE(data, high_pos, low_pos) \
((((uint32_t)data)<<(32-(high_pos)-1))>>(32-(high_pos)+(low_pos)-1))
#define UINT32_GET_BIT(data, pos) \
((((uint32_t)data)>>(pos)) & 1)

void tick() {
    digitalWrite(LED_STATUS, !digitalRead(LED_STATUS));
}

void gpio_setup() {
    pinMode(LED_STATUS, OUTPUT);
    //pinMode(RESET_ADAU1452, OUTPUT);
    //digitalWrite(RESET_ADAU1452, HIGH);
    //delay(500);
    pinMode(A2B_IRQ, INPUT);
    pinMode(TRIGGER_1, INPUT);
    pinMode(TRIGGER_2, INPUT);
    ticker.attach(0.2, tick);
}

void resetConfig() {
    ticker.attach(0.1, tick);
    delay(3000);
    SPIFFS.remove("/config.json");
    delay(5000);
    //ESP.eraseConfig();
    ESP.restart();
}

/**
 * Convert float to const char
 * @param f - float value
 * @returns  const char buffer
*/
const char *FloatToChar(float f) {
    dtostrf(f, 5, 6, buffer);
    return buffer;
}

/**
 * Int to String and concat zero if < 10
 * @param val - int value
 * @returns  String xx
*/
String intToConcatZero(int val) {
    return val < 10 ? String(0) + String(val) : String(val);
}

/**
 * Convert 8.24 to float
 * @param data
 * @param fmt_num
 * @param fmt_frac
 * @returns  value_float
*/
static float fixedToFloat(uint32_t data, uint8_t fmt_num, uint8_t fmt_frac) {
    uint8_t sign_bit = fmt_num + fmt_frac - 1;
    uint32_t sign_value = UINT32_GET_BIT(data, sign_bit);
    uint32_t value_uint = UINT32_GET_BIT_RANGE(data, sign_bit - 1, fmt_frac);
    float value_float = 0.00;
    if (sign_value == 0) {   //positive number
        value_float = (float) value_uint;
    } else {   //negative number
        uint32_t value_max = 2 << (fmt_num - 2);  //2^fmt_num
        value_float = -(float) (value_max - value_uint);
    }
    float f = 1;
    for (int32_t i = fmt_frac - 1; i >= 0; i--) {
        f /= 2;
        if (UINT32_GET_BIT_RANGE(data, i, i)) {
            value_float += f;
        }
    }
    return value_float;
}

/**
 * Convert int32 to 4 byte hex
 * @param value
 * @param buffer
 * @returns:  None
*/
void int32ToBuffer(int32_t value, uint8_t *buffer) {
    buffer[0] = (value >> 24) & 0xFF;
    buffer[1] = (value >> 16) & 0xFF;
    buffer[2] = (value >> 8) & 0xFF;
    buffer[3] = value & 0xFF;
}

int32_t floatToInt32(double value) { return round(value * (0x01 << 24)); }

/**
  *   Converts a 5.23 float value to 5-byte HEX and stores it to a buffer
  *  @param value
  *  @param buffer
  *  @returns:  None
*/
void floatToFixed(float value, uint8_t *buffer) {  // Convert float to 4 byte hex
    int32_t fixedval = (value * ((int32_t) 1 << 23));
    buffer[0] = (fixedval >> 24) & 0xFF;
    buffer[1] = (fixedval >> 16) & 0xFF;
    buffer[2] = (fixedval >> 8) & 0xFF;
    buffer[3] = fixedval & 0xFF;
}

/**
  *   Converts a 28.0 integer value to 5-byte HEX and stores it to a buffer
  *  @param value Value to convert
  *  @param buffer Buffer to store the converted data to
  *  @returns:  None
*/
void intToFixed(int32_t value, uint8_t *buffer) {
    // Store the 4 bytes in the passed buffer
    //buffer[0] = 0x00; // First must be empty
    buffer[0] = (value >> 24) & 0xFF;
    buffer[1] = (value >> 16) & 0xFF;
    buffer[2] = (value >> 8) & 0xFF;
    buffer[3] = value & 0xFF;
}

/**
  *   Converts a 5.23 float value to int 28.0
  *  @param value Value to convert
  *  @returns:  int32_t Converted value
*/
int32_t floatToInt(float value) {
    return (value * ((int32_t) 1 << 23)); // Convert float 5.23 to int 28.0
}
