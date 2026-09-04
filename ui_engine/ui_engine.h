#ifndef __UI_ENGINE_H_
#define __UI_ENGINE_H_

#include "bridge.h"
#include "definitions.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

/* MODEL */

typedef enum {
  UI_MODEL_PROP_NONE = 0,
  UI_MODEL_PROP_HEADLIGHT_COLOR,
  UI_MODEL_PROP_BODYLIGHT_COLOR,
} UI_Model_Prop_ID;

typedef struct {
  lv_subject_t headlight_color;
  lv_subject_t bodylight_color;
} UI_Model_Light_t;

typedef struct {
  lv_obj_t *main_screen_obj;
  UI_Model_Light_t model_light;
} UI_Model_t;

extern QueueHandle_t ui_event_queue;

esp_err_t UI_Engine_Init(void);

void UI_Engine_Event_Consume(Bridge_Event_t bridge_event);
void UI_Engine_Screen_Register_Inputs();
void UI_Engine_Execute_Action(const UI_Action_t *action);

#endif // __UI_ENGINE_H_