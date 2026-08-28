#include "_system.h"
#include "led_driver.h"

QueueHandle_t system_event_queue = NULL;

esp_err_t System_Init(void) {
  // drivers
  esp_err_t err = LED_Init();

  // err = Sound_Init();
  // ESP_ERROR_CHECK(err);

  // err = Storage_Init();
  // ESP_ERROR_CHECK(err);

  system_event_queue = xQueueCreate(5, sizeof(Bridge_Event_t));

  return err;
}

void System_Event_Consume(Bridge_Event_t bridge_event) {
  switch (bridge_event.sys_binding_id) {

  case SYSTEM_BINDING_SET_STRIP_COLOR: {
    // TODO
    break;
  }

  case SYSTEM_BINDING_NONE:
    break;
  }
}