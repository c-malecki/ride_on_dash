#include "_system.h"
#include "led_driver.h"

QueueHandle_t system_event_queue = NULL;
/* FORWARD PROTO DEP */

/* INTERFACE */

esp_err_t System_Init(void) {
  system_event_queue = xQueueCreate(5, sizeof(System_Action_t));

  esp_err_t err = LED_Init();

  // err = Sound_Init();
  // ESP_ERROR_CHECK(err);

  // err = Storage_Init();
  // ESP_ERROR_CHECK(err);

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