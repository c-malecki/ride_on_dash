#include "app.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "led_driver.h"
#include "lvgl.h"
// #include "sound.h"
// #include "storage.h"

static SemaphoreHandle_t lvgl_mutex = NULL;

static void lvgl_task(void *arg) {
  const TickType_t period = pdMS_TO_TICKS(10);
  TickType_t last_wake = xTaskGetTickCount();

  while (1) {
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_timer_handler();
    xSemaphoreGive(lvgl_mutex);

    vTaskDelayUntil(&last_wake, period);
  }
}

void app_main(void) {
  // drivers
  esp_err_t err = LED_Init();
  ESP_ERROR_CHECK(err);

  // err = Sound_Init();
  // ESP_ERROR_CHECK(err);

  // err = Storage_Init();
  // ESP_ERROR_CHECK(err);

  lvgl_mutex = xSemaphoreCreateMutex();

  // lvgl app setup (Model-View-Presenter)
  err = App_LVGL_Setup();
  ESP_ERROR_CHECK(err);

  // start execution with task
  xTaskCreatePinnedToCore(lvgl_task, "lvgl_task", 16384, NULL, 5, NULL, 1);
}