#ifndef __CAR_SYSTEM_H_
#define __CAR_SYSTEM_H_

#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

extern QueueHandle_t CAR_SYSTEM_event_queue;

esp_err_t CAR_SYSTEM_Init(void);

typedef enum {
  CAR_SYSTEM_ACTION_ID_NONE = 0,
  CAR_SYSTEM_ACTION_ID_SET_HEADLIGHT,
  CAR_SYSTEM_ACTION_ID_SET_BODYLIGHT,
} CAR_SYSTEM_Action_ID;

typedef struct {
  CAR_SYSTEM_Action_ID action_id;
  uint32_t value;
} CAR_SYSTEM_Action_t;

void CAR_SYSTEM_Execute_Action(CAR_SYSTEM_Action_t *action);
// void System_Set_LED_Strip(LED_Set_Strip_Color_Arg_t *arg);

#endif // __CAR_SYSTEM_H_