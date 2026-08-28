#include "model_color_picker.h"
#include "util.h"

void Model_Color_Picker_Init(Model_Color_Picker_t *model) {
  lv_subject_init_int(&model->selected_color, UTIL_COLOR_NONE);
};

void Model_Color_Picker_Set_Selected_Color(Model_Color_Picker_t *model,
                                           Util_Color_ID color_id) {
  lv_subject_set_int(&model->selected_color, color_id);
};