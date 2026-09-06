#include "car_system.h"
#include "display_driver.h"
#include "led_driver.h"
// #include "sound_driver.h"
#include "storage_driver.h"

QueueHandle_t system_event_queue = NULL;
/* FORWARD PROTO DEP */

/* INTERFACE */

esp_err_t CAR_SYSTEM_Init(void) {
  system_event_queue = xQueueCreate(5, sizeof(System_Action_t));

  esp_err_t err = DISPLAY_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  err = LED_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  // err = SOUND_DRIVER_Init();
  // ESP_ERROR_CHECK(err);

  err = STORAGE_DRIVER_Init();
  ESP_ERROR_CHECK(err);

  return err;
}

void System_Execute_Action(System_Action_t *action) {
  if (action == NULL) {
    return;
  }

  switch (action->action_id) {

  case SYSTEM_ACTION_ID_SET_HEADLIGHT: {
    LED_DRIVER_Set_Strip_Color(LED_STRIP_HEADLIGHTS, action->value);
    break;
  }

  case SYSTEM_ACTION_ID_SET_BODYLIGHT: {
    LED_DRIVER_Set_Strip_Color(LED_STRIP_BODYLIGHTS, action->value);
    break;
  }

  case SYSTEM_ACTION_ID_COUNT:
    break;
  }
}