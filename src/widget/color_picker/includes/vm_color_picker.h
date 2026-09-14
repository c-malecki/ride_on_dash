#ifndef __VM_COLOR_PICKER_H_
#define __VM_COLOR_PICKER_H_

#include "colors.h"
#include "lvgl.h"

typedef void (*VM_Color_Picker_CB)(Common_Color_ID color_id);

typedef struct {
  VM_Color_Picker_CB on_select_cb;
  void *ctx;
} VM_Color_Picker_t;

typedef struct {
  VM_Color_Picker_CB on_select_cb;
} VM_Color_Picker_Cfg_t;

VM_Color_Picker_t VM_Color_Picker_Create(const VM_Color_Picker_Cfg_t *cfg);

void VM_Color_Picker_Set_Color(VM_Color_Picker_t *vm, Common_Color_ID color_id);
void VM_Color_Picker_Set_Label(VM_Color_Picker_t *vm, const char *label);

#endif // __VM_COLOR_PICKER_H_