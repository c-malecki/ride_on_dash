#ifndef __APP_H_
#define __APP_H_

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t app_event_queue;

typedef enum {
  APP_BINDING_NONE = 0,
} App_Binding_ID;

typedef struct {
  App_Binding_ID binding_id;
  uint32_t payload;
} App_Event_t;

esp_err_t App_Init(void);

void App_Consume_Event(App_Event_t app_event);
App_Event_t App_Event_Create(App_Binding_ID binding_id, uint32_t payload);

#endif // __APP_H_