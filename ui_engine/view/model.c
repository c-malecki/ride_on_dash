#include "model.h"
#include "_color.h"
#include "ui_definitions.h"

/*

  TODO: Register observer CBs from input or something like that?

*/

UI_Model_Prop_t ui_model_prop_table[UI_MODEL_PROP_ID_COUNT] = {
    [UI_MODEL_PROP_ID_NONE] = {.prop_id = UI_MODEL_PROP_ID_NONE},
    [UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID] =
        {.prop_id = UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID},
    [UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID] =
        {.prop_id = UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID},
};

void UI_Model_Init(UI_Model_t *model) {
  lv_subject_init_int(
      &ui_model_prop_table[UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID].value,
      COLOR_NONE);
  model->model_props[UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID] =
      ui_model_prop_table[UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID];

  lv_subject_init_int(
      &ui_model_prop_table[UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID].value,
      COLOR_NONE);
  model->model_props[UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID] =
      ui_model_prop_table[UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID];
}

void UI_Model_Set_Prop(UI_Model_t *model, UI_Model_Prop_ID prop_id,
                       uint32_t value) {
  switch (prop_id) {

  case UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID: {
    lv_subject_set_int(
        &model->model_props[UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID].value, value);
    break;
  }

  case UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID: {
    lv_subject_set_int(
        &model->model_props[UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID].value, value);
    break;
  }

  case UI_MODEL_PROP_ID_NONE: {
    break;
  }

  case UI_MODEL_PROP_ID_COUNT: {
    break;
  }
  }
}