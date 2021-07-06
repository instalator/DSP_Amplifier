#include "BluetoothA2DPSink.h"

BluetoothA2DPSink a2dp_sink;

void ble_setup() {
  //https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/i2s.html
  //https://esp32.com/viewtopic.php?t=10674
  static const i2s_config_t i2s_config = {
    .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX),
    .sample_rate = 44100, // 44100 corrected by info from bluetooth
    .bits_per_sample = (i2s_bits_per_sample_t) 16,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = 0, // default interrupt priority
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false
  };
  static const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_BCLK_PIN,
    .ws_io_num = I2S_LRCLK_PIN,
    .data_out_num = I2S_DOUT_PIN,
    .data_in_num = I2S_PIN_NO_CHANGE
  };
  a2dp_sink.set_i2s_config(i2s_config);
  a2dp_sink.set_pin_config(pin_config);

  periph_module_enable(PERIPH_I2S0_MODULE); // Enable the I2S peripheral
  WRITE_PERI_REG(I2S_CLKM_CONF_REG(0),  // Set I2S0 clock to 40 MHz
                 I2S_CLK_EN |           // Use PLL_D2_CLK which is 160MHz
                 (0 << I2S_CLKM_DIV_A_S) |
                 (0 << I2S_CLKM_DIV_B_S) |
                 (4 << I2S_CLKM_DIV_NUM_S));

  // outputs I2S0_CLK on CLK_OUT2
  WRITE_PERI_REG(PIN_CTRL, (0xf << CLK_OUT1_S) |(0x0 << CLK_OUT2_S) | (0x0 << CLK_OUT3_S));
  // Output CLK_OUT1 on GPIO3 (U0RXD),
  // hardware needs a 1k serial resistor here to avoid USB UART driving...
  PIN_FUNC_SELECT(GPIO_PIN_REG_3, FUNC_U0RXD_CLK_OUT2);
  a2dp_sink.start(HOST_NAME);
}
