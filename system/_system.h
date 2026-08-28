#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "bridge.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t system_event_queue;

esp_err_t System_Init(void);

void System_Event_Consume(Bridge_Event_t bridge_event);

#endif // __SYSTEM_H_