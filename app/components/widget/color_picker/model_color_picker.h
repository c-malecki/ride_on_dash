#ifndef __MODEL_COLOR_PICKER_H_
#define __MODEL_COLOR_PICKER_H_

#include "lvgl.h"
#include "util.h"

typedef struct {
  lv_subject_t selected_color; // App_Color_ID
} Model_Color_Picker_t;

void Model_Color_Picker_Init(Model_Color_Picker_t *model);
void Model_Color_Picker_Set_Color(Model_Color_Picker_t *model,
                                  App_Color_ID color_id);

#endif // __MODEL_COLOR_PICKER_H_