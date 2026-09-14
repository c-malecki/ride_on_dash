#ifndef __UI_ENGINE_H_
#define __UI_ENGINE_H_

#include "esp_err.h"
#include "esp_lcd_ili9341.h"
#include "esp_lcd_touch_xpt2046.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "lvgl.h"

extern QueueHandle_t UI_ENGINE_event_queue;

typedef enum {
  UI_ENGINE_ACTION_ID_NONE = 0,
} UI_ENGINE_Action_t;

typedef enum {
  UI_ENGINE_SCREEN_ID_SPLASH = 0,
  UI_ENGINE_SCREEN_ID_HOME,
  UI_ENGINE_SCREEN_ID_LIGHT,
  UI_ENGINE_SCREEN_ID_COUNT,
} UI_ENGINE_Screen_ID;

esp_err_t UI_ENGINE_Init(esp_lcd_panel_io_handle_t io_handle,
                         esp_lcd_panel_handle_t panel_handle,
                         esp_lcd_touch_handle_t touch_handle);
void UI_ENGINE_Navigate(UI_ENGINE_Screen_ID screen_id);
void UI_ENGINE_Execute_Action(UI_ENGINE_Action_t *action);

#endif // __UI_ENGINE_H_