#ifndef __LED_DRIVER_H_
#define __LED_DRIVER_H_

#include "_color.h"
#include "esp_err.h"
#include <stdbool.h>

typedef enum {
  LED_STRIP_NONE = 0,
  LED_STRIP_HEADLIGHTS,
  LED_STRIP_BODYLIGHTS,
} LED_Strip_ID;

esp_err_t LED_Init(void);
void LED_Set_Strip_Color(LED_Strip_ID strip_id, Color_ID color_id);

#endif // __LED_DRIVER_H_