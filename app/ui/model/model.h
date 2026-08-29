#ifndef __MODEL_H_
#define __MODEL_H_

#include "lvgl.h"
#include "ui_definitions.h"
#include <stdint.h>

typedef struct {
  UI_Model_Prop_ID prop_id;
  lv_subject_t value;
} UI_Model_Prop_t;

typedef struct {
  lv_obj_t *main_screen_obj;
  UI_Model_Prop_t model_props[];
} UI_Model_t;

void UI_Model_Init(UI_Model_t *model);

void UI_Model_Set_Prop(UI_Model_t *model, UI_Model_Prop_ID prop_id,
                       uint32_t value);

#endif // __MODEL_H_