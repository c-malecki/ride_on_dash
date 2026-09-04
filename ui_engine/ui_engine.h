#ifndef __UI_ENGINE_H_
#define __UI_ENGINE_H_

#include "bridge.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t ui_event_queue;

esp_err_t UI_Engine_Init(void);

void UI_Engine_Event_Consume(Bridge_Event_t bridge_event);

#endif // __UI_ENGINE_H_