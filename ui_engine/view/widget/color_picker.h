#ifndef __COLOR_PICKER_H_
#define __COLOR_PICKER_H_

#include "_color.h"
#include "definitions.h"
#include "lvgl.h"

typedef void (*color_picker_cb)(Color_ID color_id);

typedef struct {
  color_picker_cb color_picker_cb;
} UI_Color_Picker_Config_t;

void UI_Color_Picker_Apply(lv_obj_t *button_matrix,
                           const UI_Color_Picker_Config_t *config);

#endif // __COLOR_PICKER_H_