#include "bridge.h"
#include "car_system.h"
#include "display_driver.h"
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

static void car_system_task(void *arg) {
  CAR_SYSTEM_Action_t car_system_action;
  while (1) {
    if (xQueueReceive(CAR_SYSTEM_event_queue, &car_system_action,
                      portMAX_DELAY)) {
      CAR_SYSTEM_Execute_Action(&car_system_action);
    }
  }
}

static void ui_engine_task(void *arg) {
  UI_ENGINE_Action_t ui_engine_action;
  while (1) {
    if (xQueueReceive(UI_ENGINE_event_queue, &ui_engine_action,
                      portMAX_DELAY)) {
      UI_ENGINE_Execute_Action(&ui_engine_action);
    }
  }
}

void app_main(void) {
  lvgl_mutex = xSemaphoreCreateMutex();

  esp_err_t err = CAR_SYSTEM_Init();
  ESP_ERROR_CHECK(err);

  err = UI_ENGINE_Init(DISPLAY_DRIVER_Get_IO_Handle(),
                       DISPLAY_DRIVER_Get_Panel_Handle(),
                       DISPLAY_DRIVER_Get_Touch_Handle());
  ESP_ERROR_CHECK(err);

  BRIDGE_MODEL_INIT();

  xTaskCreatePinnedToCore(lvgl_timer_task, "lvgl_timer_task", 16384, NULL, 7,
                          NULL, 1);

  xTaskCreatePinnedToCore(car_system_task, "car_system_task", 8192, NULL, 5,
                          NULL, 0);
}