#include "led_driver.h"
#include "_color.h"
#include "hardware.h"
#include "led_strip.h"
#include "led_strip_types.h"
#include <stdbool.h>
#include <stdint.h>

static led_strip_handle_t strip_hll_handle;
static led_strip_handle_t strip_hlr_handle;
static led_strip_handle_t strip_bll_handle;
static led_strip_handle_t strip_blr_handle;

static const led_strip_config_t hll_config = {
    .strip_gpio_num = LED_PIN_HLL_DC,
    .max_leds = LED_STRIP_MAX_LEDS,
    .led_model = LED_MODEL_WS2812,
    .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    .flags.invert_out = false,
};

static const led_strip_config_t hlr_config = {
    .strip_gpio_num = LED_PIN_HLR_DC,
    .max_leds = LED_STRIP_MAX_LEDS,
    .led_model = LED_MODEL_WS2812,
    .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    .flags.invert_out = false,
};

static const led_strip_config_t bll_config = {
    .strip_gpio_num = LED_PIN_BLL_DC,
    .max_leds = LED_STRIP_MAX_LEDS,
    .led_model = LED_MODEL_WS2812,
    .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    .flags.invert_out = false,
};

static const led_strip_config_t blr_config = {
    .strip_gpio_num = LED_PIN_BLR_DC,
    .max_leds = LED_STRIP_MAX_LEDS,
    .led_model = LED_MODEL_WS2812,
    .color_component_format = LED_STRIP_COLOR_COMPONENT_FMT_GRB,
    .flags.invert_out = false,
};

static const led_strip_rmt_config_t rmt_config = {
    .clk_src = RMT_CLK_SRC_DEFAULT,
    .resolution_hz = 10 * 1000 * 1000, // 10MHz
    .flags.with_dma = false,
};

esp_err_t LED_Init(void) {
  esp_err_t err =
      led_strip_new_rmt_device(&hll_config, &rmt_config, &strip_hll_handle);
  if (err != ESP_OK) {
    return err;
  }

  err = led_strip_new_rmt_device(&hlr_config, &rmt_config, &strip_hlr_handle);
  if (err != ESP_OK) {
    return err;
  }

  err = led_strip_new_rmt_device(&bll_config, &rmt_config, &strip_bll_handle);
  if (err != ESP_OK) {
    return err;
  }

  return led_strip_new_rmt_device(&blr_config, &rmt_config, &strip_blr_handle);
}

static void led_driver_set_strip_color(LED_Set_Strip_Color_Arg_t *arg) {
  const Color_Table_Entry_t *color = CFG_Color_Find_Entry(arg->color_id);

  switch (arg->strip_id) {
  case LED_STRIP_HEADLIGHTS: {

    led_strip_clear(strip_hll_handle);
    led_strip_clear(strip_hlr_handle);
    for (uint8_t i = 0; i < LED_STRIP_MAX_LEDS; i++) {
      led_strip_set_pixel(strip_hll_handle, i, color->color->r, color->color->g,
                          color->color->b);
      led_strip_set_pixel(strip_hlr_handle, i, color->color->r, color->color->g,
                          color->color->b);
    }
    led_strip_refresh(strip_hll_handle);
    led_strip_refresh(strip_hlr_handle);
    break;
  }

  case LED_STRIP_BODYLIGHTS: {

    led_strip_clear(strip_bll_handle);
    led_strip_clear(strip_blr_handle);
    for (uint8_t i = 0; i < LED_STRIP_MAX_LEDS; i++) {
      led_strip_set_pixel(strip_bll_handle, i, color->color->r, color->color->g,
                          color->color->b);
      led_strip_set_pixel(strip_blr_handle, i, color->color->r, color->color->g,
                          color->color->b);
    }
    led_strip_refresh(strip_bll_handle);
    led_strip_refresh(strip_blr_handle);
    break;
  }

  case LED_STRIP_NONE:
    break;
  }
}

LED_Driver_Set_Strip_Color_CB LED_Driver_Get_Set_Strip_Color_CB(void) {
  return &led_driver_set_strip_color;
}

//

void LED_DRIVER_Set_Strip_Color(LED_Strip_ID strip_id, Color_ID color_id) {
  const Color_Table_Entry_t *color = CFG_Color_Find_Entry(color_id);

  switch (strip_id) {
  case LED_STRIP_HEADLIGHTS: {

    led_strip_clear(strip_hll_handle);
    led_strip_clear(strip_hlr_handle);
    for (uint8_t i = 0; i < LED_STRIP_MAX_LEDS; i++) {
      led_strip_set_pixel(strip_hll_handle, i, color->color->r, color->color->g,
                          color->color->b);
      led_strip_set_pixel(strip_hlr_handle, i, color->color->r, color->color->g,
                          color->color->b);
    }
    led_strip_refresh(strip_hll_handle);
    led_strip_refresh(strip_hlr_handle);
    break;
  }

  case LED_STRIP_BODYLIGHTS: {

    led_strip_clear(strip_bll_handle);
    led_strip_clear(strip_blr_handle);
    for (uint8_t i = 0; i < LED_STRIP_MAX_LEDS; i++) {
      led_strip_set_pixel(strip_bll_handle, i, color->color->r, color->color->g,
                          color->color->b);
      led_strip_set_pixel(strip_blr_handle, i, color->color->r, color->color->g,
                          color->color->b);
    }
    led_strip_refresh(strip_bll_handle);
    led_strip_refresh(strip_blr_handle);
    break;
  }

  case LED_STRIP_NONE:
    break;
  }
}