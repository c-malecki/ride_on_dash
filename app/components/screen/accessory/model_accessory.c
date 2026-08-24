#include "model_accessory.h"
#include "util.h"

void Model_Accessory_Init(Model_Accessory_t *model) {
  lv_subject_init_int(&model->show_color_picker, 0);
  lv_subject_init_int(&model->btn_color_headlights, APP_COLOR_NONE);
}

void Model_Accessory_Set_Show_Color_Picker(Model_Accessory_t *model,
                                           bool show) {
  lv_subject_set_int(&model->btn_color_headlights, show);
}

void Model_Accessory_Set_Btn_Color_Headlights(Model_Accessory_t *model,
                                              App_Color_ID color_id) {
  lv_subject_set_int(&model->btn_color_headlights, color_id);
}