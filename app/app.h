#ifndef __APP_H_
#define __APP_H_

#include "bridge.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t app_event_queue;

esp_err_t App_Init(void);

void App_Event_Consume(Bridge_Event_t bridge_event);

#endif // __APP_H_