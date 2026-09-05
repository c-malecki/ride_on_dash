#ifndef __BUTTON_BASE_H_
#define __BUTTON_BASE_H_

#include "_color.h"
#include "lvgl.h"

typedef struct {
  Color_ID color;
  const char *label;
  int32_t row;
  int32_t col;
} UI_Button_Base_Config_t;

void UI_Button_Base_Apply(lv_obj_t *btn, const UI_Button_Base_Config_t *config);

#endif // __BUTTON_BASE_H_