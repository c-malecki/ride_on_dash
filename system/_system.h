#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t system_event_queue;

typedef enum {
  SYSTEM_BINDING_NONE = 0,
  SYSTEM_BINDING_SET_STRIP_COLOR,
} System_Binding_ID;

typedef struct {
  System_Binding_ID binding_id;
  uint32_t payload;
} System_Event_t;

esp_err_t System_Init(void);

void System_Consume_Event(System_Event_t system_event);
System_Event_t System_Event_Create(System_Binding_ID binding_id,
                                   uint32_t payload);

#endif // __SYSTEM_H_