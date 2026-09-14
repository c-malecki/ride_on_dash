#include "car.h"

#include "display_driver.h"
#include "led_driver.h"
// #include "sound_driver.h"
#include "storage_driver.h"

#include "_lvgl.h"
#include "main_screen.h"

#include "freertos/idf_additions.h"
#include "freertos/semphr.h"

/* STATIC VARS */

static SemaphoreHandle_t lvgl_mutex = NULL;

/* PRIVATE PROTO */

static void lvgl_timer_task(void *arg);

/* INTERFACE */

void Car_Init(void) {
  esp_err_t err = DISPLAY_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  err = LED_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  // err = SOUND_DRIVER_Init();
  // ESP_ERROR_CHECK(err);

  err = STORAGE_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  lvgl_mutex = xSemaphoreCreateMutex();

  LVGL_Init(DISPLAY_DRIVER_Get_IO_Handle(), DISPLAY_DRIVER_Get_Panel_Handle(),
            DISPLAY_DRIVER_Get_Touch_Handle());

  Main_Screen_Init();

  xTaskCreatePinnedToCore(lvgl_timer_task, "lvgl_timer_task", 16384, NULL, 7,
                          NULL, 1);
}

/* PRIVATE */

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