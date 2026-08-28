#include "led_controller.h"
#include "led_driver.h"
#include "util.h"

static Util_Color_ID headlight_color = UTIL_COLOR_NONE;
static Util_Color_ID bodylight_color = UTIL_COLOR_NONE;

static void bind_driver_led_set_strip_color(LED_Strip_ID strip_id,
                                            Util_Color_ID color_id) {
  LED_Set_Strip_Color(strip_id, color_id);
}

LED_Controller_Set_Strip_CB LED_Controller_Binding_Set_Strip_CB(void) {
  return &bind_driver_led_set_strip_color;
}