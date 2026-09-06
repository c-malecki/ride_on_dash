#ifndef __CAR_SYSTEM_H_
#define __CAR_SYSTEM_H_

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t system_event_queue;

esp_err_t CAR_SYSTEM_Init(void);

typedef enum {
  SYSTEM_ACTION_ID_COUNT = 0,
  SYSTEM_ACTION_ID_SET_HEADLIGHT,
  SYSTEM_ACTION_ID_SET_BODYLIGHT,
} System_Action_ID;

typedef struct {
  System_Action_ID action_id;
  uint32_t value;
} System_Action_t;

void System_Execute_Action(System_Action_t *action);
// void System_Set_LED_Strip(LED_Set_Strip_Color_Arg_t *arg);

#endif // __CAR_SYSTEM_H_