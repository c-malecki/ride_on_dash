#include "led_controller.h"
#include "esp_err.h"
#include "led_driver.h"

static LED_Controller_t controller;
static LED_Driver_Set_Strip_Color_CB registered_driver_cb = NULL;

static void led_controller_set_strip_color(LED_Set_Strip_Color_Arg_t *arg) {
  registered_driver_cb(arg);

  if (arg->strip_id == LED_STRIP_BODYLIGHTS) {
    controller.headlight_color = arg->color_id;
  } else {
    controller.bodylight_color = arg->color_id;
  }
}

/* */

esp_err_t LED_Controller_Init(LED_Driver_Set_Strip_Color_CB driver_cb) {
  if (driver_cb == NULL)
    return ESP_ERR_INVALID_ARG;

  registered_driver_cb = driver_cb;

  controller.headlight_color = COLOR_NONE;
  controller.bodylight_color = COLOR_NONE;

  return ESP_OK;
}

void LED_Controller_Handle_Bridge_Event(Bridge_Event_t bridge_event) {
  // TODO: expand events or something if there are other cases to handle?
  // like not just color but a pattern/light show
  LED_Set_Strip_Color_Arg_t *arg =
      (LED_Set_Strip_Color_Arg_t *)bridge_event.payload;
  led_controller_set_strip_color(arg);
}
