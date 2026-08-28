#include "_system.h"
// drivers
#include "led_driver.h"
// controllers
#include "led_controller.h"

QueueHandle_t system_event_queue = NULL;

/* FORWARD PROTO DEP */

esp_err_t init_drivers(void);
esp_err_t init_controllers(void);

/* INTERFACE */

esp_err_t System_Init(void) {
  system_event_queue = xQueueCreate(5, sizeof(Bridge_Event_t));

  esp_err_t err = init_drivers();
  err = init_controllers();

  return err;
}

// Handle routing bridge_event to intended controller
void System_Event_Consume(Bridge_Event_t bridge_event) {
  switch (bridge_event.sys_binding_id) {

  case BINDING_SYSTEM_SET_LED_STRIP_COLOR: {
    LED_Controller_Handle_Bridge_Event(bridge_event);
    break;
  }

  case BINDING_SYSTEM_NONE:
    break;
  }
}

/* SETUP */

esp_err_t init_drivers(void) {
  esp_err_t err = LED_Init();

  // err = Sound_Init();
  // ESP_ERROR_CHECK(err);

  // err = Storage_Init();
  // ESP_ERROR_CHECK(err);

  return err;
}

esp_err_t init_controllers(void) {
  esp_err_t err = LED_Controller_Init(LED_Driver_Get_Set_Strip_Color_CB());

  return err;
}