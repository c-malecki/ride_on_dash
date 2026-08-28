#include "_system.h"
#include "app.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/semphr.h"
#include "lvgl.h"
#include "portmacro.h"

static SemaphoreHandle_t lvgl_mutex = NULL;

static void lvgl_app_task(void *arg) {
  const TickType_t period = pdMS_TO_TICKS(10);
  TickType_t last_wake = xTaskGetTickCount();

  while (1) {
    // TODO: CHECK IF THIS IS POSSIBLE
    App_Event_t app_event;
    if (xQueueReceive(app_event_queue, &app_event, portMAX_DELAY)) {
      App_Consume_Event(app_event);
    }

    // WEE WOO WEE WOO ^^^^^^^^^^^

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
  System_Event_t system_event;
  while (1) {
    if (xQueueReceive(system_event_queue, &system_event, portMAX_DELAY)) {
      System_Consume_Event(system_event);
    }
  }
}

void app_main(void) {
  esp_err_t err = System_Init();
  ESP_ERROR_CHECK(err);

  lvgl_mutex = xSemaphoreCreateMutex();

  err = App_Init();
  ESP_ERROR_CHECK(err);

  xTaskCreatePinnedToCore(lvgl_app_task, "lvgl_app_task", 16384, NULL, 7, NULL,
                          1);

  xTaskCreatePinnedToCore(system_task, "system_task", 8192, NULL, 5, NULL, 0);
}