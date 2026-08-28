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

  system_event_queue = xQueueCreate(10, sizeof(System_Event_t));

  return err;
}

void System_Consume_Event(System_Event_t system_event) {
  switch (system_event.binding_id) {

  case SYSTEM_BINDING_SET_STRIP_COLOR: {
    // TODO
    break;
  }

  case SYSTEM_BINDING_NONE:
    break;
  }
}

System_Event_t System_Event_Create(System_Binding_ID binding_id,
                                   uint32_t payload) {
  return (System_Event_t){
      .binding_id = binding_id,
      .payload = payload,
  };
}