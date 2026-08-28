#include "led_controller.h"
#include "_color.h"
#include "led_driver.h"

static Color_ID headlight_color = COLOR_NONE;
static Color_ID bodylight_color = COLOR_NONE;

static void bind_driver_led_set_strip_color(LED_Strip_ID strip_id,
                                            Color_ID color_id) {
  LED_Set_Strip_Color(strip_id, color_id);
}

LED_Controller_Set_Strip_CB LED_Controller_Binding_Set_Strip_CB(void) {
  return &bind_driver_led_set_strip_color;
}