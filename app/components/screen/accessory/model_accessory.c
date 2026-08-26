#include "model_accessory.h"
#include "core/lv_observer.h"
#include "util.h"
#include <stdbool.h>

void Model_Accessory_Init(Model_Accessory_t *model) {
  lv_subject_init_int(&model->color_picker_show, false);
  lv_subject_init_int(&model->selected_lights, MODEL_ACCESSORY_LED_NONE);
  lv_subject_init_int(&model->btn_headlights_color, APP_COLOR_NONE);
  lv_subject_init_int(&model->btn_bodylights_color, APP_COLOR_NONE);
}

void Model_Accessory_Set_Show_Color_Picker(Model_Accessory_t *model,
                                           bool show) {
  lv_subject_set_int(&model->color_picker_show, show);
}

Model_Accessory_LED
Model_Accessory_Get_Selected_Lights(Model_Accessory_t *model) {
  return (Model_Accessory_LED)lv_subject_get_int(&model->selected_lights);
}

void Model_Accessory_Set_Selected_Lights(Model_Accessory_t *model,
                                         Model_Accessory_LED selected_lights) {
  lv_subject_set_int(&model->selected_lights, selected_lights);
}

void Model_Accessory_Set_Btn_Color_Headlights(Model_Accessory_t *model,
                                              App_Color_ID color_id) {
  lv_subject_set_int(&model->btn_headlights_color, color_id);
}

void Model_Accessory_Set_Btn_Color_Bodylights(Model_Accessory_t *model,
                                              App_Color_ID color_id) {
  lv_subject_set_int(&model->btn_bodylights_color, color_id);
}