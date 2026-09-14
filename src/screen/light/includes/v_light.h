#ifndef __VIEW_LIGHT_H_
#define __VIEW_LIGHT_H_

#include "lvgl.h"
#include "screen_id.h"
#include "v_button.h"
#include "v_color_picker.h"
#include "vm_light.h"

typedef struct {
  Screen_ID screen_id;
  V_Button_t *headlight_btn;
  V_Button_t *bodylight_btn;
  V_Color_Picker_t *color_picker;
  VM_Light_t *vm;
} V_Light_t;

void V_Light_Render(lv_obj_t *container);

#endif // __VIEW_LIGHT_H_