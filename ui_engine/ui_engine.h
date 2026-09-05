#ifndef __UI_ENGINE_H_
#define __UI_ENGINE_H_

#include "esp_err.h"
#include "lvgl.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/semphr.h"

// extern QueueHandle_t ui_event_queue;

typedef enum {
  UI_SCREEN_ID_SPLASH = 0,
  UI_SCREEN_ID_HOME,
  UI_SCREEN_ID_LIGHT,
  UI_SCREEN_ID_COUNT,
} UI_Screen_ID;

esp_err_t UI_Engine_Init(void);
void UI_Engine_Navigate(UI_Screen_ID screen_id);

#endif // __UI_ENGINE_H_