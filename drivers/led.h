#ifndef __LED_H_
#define __LED_H_

#include "esp_err.h"
#include "util.h"
#include <stdbool.h>

esp_err_t LED_Init(void);
void LED_SetHeadlights(App_Color_ID app_color_id);
void LED_SetBodylights(App_Color_ID app_color_id);

#endif // __LED_H_