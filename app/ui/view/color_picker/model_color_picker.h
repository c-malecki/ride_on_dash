#ifndef __MODEL_COLOR_PICKER_H_
#define __MODEL_COLOR_PICKER_H_

#include "_color.h"
#include "lvgl.h"

typedef struct {
  lv_subject_t selected_color; // Color_ID
} Model_Color_Picker_t;

void Model_Color_Picker_Init(Model_Color_Picker_t *model);
void Model_Color_Picker_Set_Selected_Color(Model_Color_Picker_t *model,
                                           Color_ID color_id);

#endif // __MODEL_COLOR_PICKER_H_