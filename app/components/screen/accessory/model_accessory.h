#ifndef __MODEL_ACCESSORY_H_
#define __MODEL_ACCESSORY_H_

#include "lvgl.h"
#include "util.h"

typedef struct {
  lv_subject_t show_color_picker;
  lv_subject_t btn_color_headlights; // App_Color_ID
} Model_Accessory_t;

void Model_Accessory_Init(Model_Accessory_t *model);

void Model_Accessory_Set_Show_Color_Picker(Model_Accessory_t *model, bool show);
void Model_Accessory_Set_Btn_Color_Headlights(Model_Accessory_t *model,
                                              App_Color_ID color_id);

#endif // __MODEL_ACCESSORY_H_