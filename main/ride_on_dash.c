#include "_system.h"
#include "bridge.h"
#include "esp_err.h"
#include "freertos/idf_additions.h"
#include "freertos/semphr.h"
#include "lvgl.h"
#include "ui_engine.h"

static SemaphoreHandle_t lvgl_mutex = NULL;

static void lvgl_timer_task(void *arg) {
  const TickType_t period = pdMS_TO_TICKS(10);
  TickType_t last_wake = xTaskGetTickCount();

  while (1) {
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_timer_handler();
    xSemaphoreGive(lvgl_mutex);

    vTaskDelayUntil(&last_wake, period);
  }
}

/*
  TODO:

  Bridge translation later that will somehow take something from
  the ui app and pipe it into the system event queue

*/

static void system_task(void *arg) {
  System_Action_t system_action;
  while (1) {
    if (xQueueReceive(system_event_queue, &system_action, portMAX_DELAY)) {
      System_Execute_Action(&system_action);
    }
  }
}

// static void ui_engine_task(void *arg) {
//   Bridge_Event_t bridge_event;
//   while (1) {
//     if (xQueueReceive(ui_event_queue, &bridge_event, portMAX_DELAY)) {
//       UI_Engine_Event_Consume(bridge_event);
//     }
//   }
// }

void app_main(void) {
  lvgl_mutex = xSemaphoreCreateMutex();

  esp_err_t err = System_Init();
  ESP_ERROR_CHECK(err);

  err = UI_Engine_Init();
  ESP_ERROR_CHECK(err);

  BRIDGE_MODEL_INIT();

  xTaskCreatePinnedToCore(lvgl_timer_task, "lvgl_timer_task", 16384, NULL, 7,
                          NULL, 1);

  xTaskCreatePinnedToCore(system_task, "system_task", 8192, NULL, 5, NULL, 0);
}