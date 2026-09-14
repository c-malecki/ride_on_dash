#include "vm_light.h"
#include "esp_log.h"

/*

TODO: add hardware observer clalbacks

*/

void VM_Light_Init(VM_Light_t *vm_light, const VM_Light_Cfg_t *cfg) {
  const lv_color_t *headlight_color =
      Common_Color_Find_Entry(cfg->headlight_color_init)->lv_color;
  const lv_color_t *bodylight_color =
      Common_Color_Find_Entry(cfg->bodylight_color_init)->lv_color;

  lv_subject_init_int(&vm_light->show_color_picker, 0);
  lv_subject_init_int(&vm_light->selected_light, VM_LIGHT_NONE);
  lv_subject_init_color(&vm_light->headlight_color, *headlight_color);
  lv_subject_init_color(&vm_light->bodylight_color, *bodylight_color);
}

void VM_Light_Bind_Color_Picker(VM_Light_t *vm_light, lv_obj_t *lv_bm_obj) {
  ESP_LOGI("v_light", "VM_Light_Bind_Color_Picker");
  lv_obj_bind_flag_if_eq(lv_bm_obj, &vm_light->show_color_picker,
                         LV_OBJ_FLAG_HIDDEN, 0);
}

/* */

void VM_Light_Set_Show_Color_Picker(VM_Light_t *vm_light, bool show) {
  ESP_LOGI("v_light", "VM_Light_Set_Show_Color_Picker");
  lv_subject_set_int(&vm_light->show_color_picker, show);
}

/* */

void VM_Light_Set_Selected_Light(VM_Light_t *vm_light,
                                 VM_Light_Selection selected_light) {
  ESP_LOGI("v_light", "VM_Light_Set_Selected_Light");
  lv_subject_set_int(&vm_light->selected_light, selected_light);
}

VM_Light_Selection VM_Light_Get_Selected_Light(VM_Light_t *vm_light) {
  return (VM_Light_Selection)lv_subject_get_int(&vm_light->selected_light);
}

/* */

void VM_Light_Set_Selected_Light_Color(VM_Light_t *vm_light,
                                       Common_Color_ID color_id) {
  ESP_LOGI("v_light", "VM_Light_Set_Selected_Light_Color");
  const lv_color_t *lv_color = Common_Color_Find_Entry(color_id)->lv_color;

  VM_Light_Selection selected_light =
      (VM_Light_Selection)lv_subject_get_int(&vm_light->selected_light);

  switch (selected_light) {

  case VM_LIGHT_HEADLIGHT: {
    lv_subject_set_color(&vm_light->headlight_color, *lv_color);
    break;
  }

  case VM_LIGHT_BODYLIGHT: {
    lv_subject_set_color(&vm_light->bodylight_color, *lv_color);
    break;
  }

  case VM_LIGHT_NONE: {
    return;
  }
  }

  lv_subject_set_int(&vm_light->show_color_picker, 0);
  lv_subject_set_int(&vm_light->selected_light, VM_LIGHT_NONE);
}