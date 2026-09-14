#ifndef __VM_LIGHT_H_
#define __VM_LIGHT_H_

#include "colors.h"
#include "lvgl.h"
#include <stdbool.h>

typedef enum {
  VM_LIGHT_NONE = 0,
  VM_LIGHT_HEADLIGHT,
  VM_LIGHT_BODYLIGHT,
} VM_Light_Selection;

typedef struct {
  lv_subject_t show_color_picker;
  lv_subject_t selected_light;
  lv_subject_t headlight_color;
  lv_subject_t bodylight_color;
} VM_Light_t;

typedef struct {
  VM_Light_Selection selected_light_init;
  Common_Color_ID headlight_color_init;
  Common_Color_ID bodylight_color_init;
} VM_Light_Cfg_t;

void VM_Light_Init(VM_Light_t *vm_light, const VM_Light_Cfg_t *vm_cfg);

void VM_Light_Bind_Color_Picker(VM_Light_t *vm_light, lv_obj_t *lv_bm_obj);

void VM_Light_Set_Show_Color_Picker(VM_Light_t *vm_light, bool show);

void VM_Light_Set_Selected_Light(VM_Light_t *vm_light,
                                 VM_Light_Selection selected_light);
VM_Light_Selection VM_Light_Get_Selected_Light(VM_Light_t *vm_light);

void VM_Light_Set_Selected_Light_Color(VM_Light_t *vm_light,
                                       Common_Color_ID color_id);

#endif // __VM_LIGHT_H_