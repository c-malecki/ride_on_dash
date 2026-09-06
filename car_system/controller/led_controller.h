#ifndef __LED_CONTROLLER_H_
#define __LED_CONTROLLER_H_

#include "_color.h"
#include "bridge.h"
#include "esp_err.h"
#include "led_driver.h"

typedef struct {
  Color_ID headlight_color;
  Color_ID bodylight_color;
} LED_Controller_t;

esp_err_t LED_Controller_Init(LED_Driver_Set_Strip_Color_CB driver_cb);

void LED_Controller_Handle_Bridge_Event(Bridge_Event_t bridge_event);

#endif // __LED_CONTROLLER_H_