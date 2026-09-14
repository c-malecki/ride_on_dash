#include "display_driver.h"
// drivers
#include "esp_lcd_ili9341.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch_xpt2046.h"
// libs
#include "esp_err.h"

/* STATIC VARS */

static esp_lcd_panel_io_handle_t io_handle = NULL;
static esp_lcd_panel_handle_t panel_handle = NULL;
static esp_lcd_touch_handle_t touch_handle = NULL;

/* FORWARD PROTO DEP */

esp_err_t init_panel(void);
esp_err_t init_touch(void);

/* INTERFACE */

esp_err_t DISPLAY_DRIVER_Init(void) {
  spi_bus_config_t spi_bus_lcd = {
      .sclk_io_num = LCD_PIN_SPI_CLK,
      .mosi_io_num = LCD_PIN_SPI_MOSI,
      .miso_io_num = LCD_PIN_SPI_MISO,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 240 * 320 * sizeof(uint16_t),
  };
  esp_err_t err = spi_bus_initialize(SPI2_HOST, &spi_bus_lcd, SPI_DMA_CH_AUTO);
  if (err != ESP_OK) {
    return err;
  }

  err = init_panel();
  if (err != ESP_OK) {
    return err;
  }

  err = init_touch();
  if (err != ESP_OK) {
    return err;
  }

  return ESP_OK;
}

esp_lcd_panel_io_handle_t DISPLAY_DRIVER_Get_IO_Handle(void) {
  return io_handle;
}

esp_lcd_panel_handle_t DISPLAY_DRIVER_Get_Panel_Handle(void) {
  return panel_handle;
}

esp_lcd_touch_handle_t DISPLAY_DRIVER_Get_Touch_Handle(void) {
  return touch_handle;
}

/* SETUP */

esp_err_t init_panel(void) {
  gpio_config_t bk_gpio_config = {.mode = GPIO_MODE_OUTPUT,
                                  .pin_bit_mask = (1ULL << LCD_PIN_LED)};
  esp_err_t err = gpio_config(&bk_gpio_config);
  if (err != ESP_OK) {
    return err;
  }

  err = gpio_set_level(LCD_PIN_LED, 1);
  if (err != ESP_OK) {
    return err;
  }

  esp_lcd_panel_io_spi_config_t io_config = {
      .dc_gpio_num = LCD_PIN_DC,
      .cs_gpio_num = LCD_PIN_CS,
      .pclk_hz = 20 * 1000 * 1000,
      .lcd_cmd_bits = 8,
      .lcd_param_bits = 8,
      .spi_mode = 0,
      .trans_queue_depth = 10,
  };
  err = esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)SPI2_HOST,
                                 &io_config, &io_handle);
  if (err != ESP_OK) {
    return err;
  }

  esp_lcd_panel_dev_config_t panel_config = {
      .reset_gpio_num = LCD_PIN_RST,
      .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
      .bits_per_pixel = 16,
  };

  err = esp_lcd_new_panel_ili9341(io_handle, &panel_config, &panel_handle);
  if (err != ESP_OK) {
    return err;
  }

  err = esp_lcd_panel_reset(panel_handle);
  if (err != ESP_OK) {
    return err;
  }

  err = esp_lcd_panel_init(panel_handle);
  if (err != ESP_OK) {
    return err;
  }

  err = esp_lcd_panel_swap_xy(panel_handle, true);
  if (err != ESP_OK) {
    return err;
  }

  return esp_lcd_panel_disp_on_off(panel_handle, true);
}

esp_err_t init_touch(void) {
  esp_lcd_panel_io_handle_t touch_io_handle = NULL;
  esp_lcd_panel_io_spi_config_t touch_io_config =
      ESP_LCD_TOUCH_IO_SPI_XPT2046_CONFIG(LCD_PIN_T_CS);
  ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)SPI2_HOST,
                                           &touch_io_config, &touch_io_handle));

  esp_lcd_touch_config_t touch_config = {
      .x_max = 240,
      .y_max = 320,
      .rst_gpio_num = GPIO_NUM_NC,
      .int_gpio_num = LCD_PIN_T_IRQ,
      .flags =
          {
              .swap_xy = 1,
              .mirror_x = 1,
              .mirror_y = 1,
          },
  };

  return esp_lcd_touch_new_spi_xpt2046(touch_io_handle, &touch_config,
                                       &touch_handle);
}