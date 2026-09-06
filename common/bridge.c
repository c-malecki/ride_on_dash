#include "bridge.h"
#include "_color.h"
#include "car_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/idf_additions.h"
#include "freertos/projdefs.h"
#include "freertos/semphr.h"
#include "style.h"
// #include "ui_engine.h"

#include "esp_log.h"

static Bridge_Model_t BRIDGE_MODEL;

void BRIDGE_MODEL_INIT(void) {
  lv_subject_init_int(&BRIDGE_MODEL.headlight_color, COLOR_NONE);
  lv_subject_init_int(&BRIDGE_MODEL.bodylight_color, COLOR_NONE);
}

void BRIDGE_MODEL_SET_PROP(Bridge_Model_Prop_ID prop_id, uint32_t value) {

  switch (prop_id) {

  case BRIDGE_MODEL_PROP_HEADLIGHT_COLOR: {
    lv_subject_set_int(&BRIDGE_MODEL.headlight_color, value);

    System_Action_t action = {
        .action_id = SYSTEM_ACTION_ID_SET_HEADLIGHT,
        .value = value,
    };

    if (xQueueSend(system_event_queue, &action, pdMS_TO_TICKS(50))) {
      ESP_LOGW("BRIDGE", "system action queue full, dropped action = "
                         "SYSTEM_ACTION_ID_SET_HEADLIGHT");
    }
    break;
  }

  case BRIDGE_MODEL_PROP_BODYLIGHT_COLOR: {
    lv_subject_set_int(&BRIDGE_MODEL.bodylight_color, value);

    System_Action_t action = {
        .action_id = SYSTEM_ACTION_ID_SET_BODYLIGHT,
        .value = value,
    };

    if (xQueueSend(system_event_queue, &action, pdMS_TO_TICKS(50))) {
      ESP_LOGW("BRIDGE", "system action queue full, dropped action = set "
                         "SYSTEM_ACTION_ID_SET_BODYLIGHT");
    }

    break;
  }

  case BRIDGE_MODEL_PROP_NONE:
    break;
  }
}

///////////////

static void change_light_button_color_observer_cb(lv_observer_t *observer,
                                                  lv_subject_t *subject) {
  Bridge_Model_Prop_ID prop_id =
      (Bridge_Model_Prop_ID)(uintptr_t)lv_observer_get_user_data(observer);

  if (prop_id != BRIDGE_MODEL_PROP_HEADLIGHT_COLOR &&
      prop_id != BRIDGE_MODEL_PROP_BODYLIGHT_COLOR) {
    return;
  }

  lv_obj_t *btn = lv_observer_get_target_obj(observer);

  Color_ID color_id = lv_subject_get_int(subject);
  const lv_color_t *color = UI_Color_Table_Find_By_ID(color_id);
  lv_obj_set_style_bg_color(btn, *color, LV_PART_MAIN | LV_STATE_DEFAULT);

  if (prop_id == BRIDGE_MODEL_PROP_HEADLIGHT_COLOR) {

  } else {
  }
}

void BRIDGE_MODEL_SET_UI_CB(Bridge_Model_Prop_ID prop_id, lv_obj_t *obj,
                            void *user_data) {
  switch (prop_id) {

  case BRIDGE_MODEL_PROP_HEADLIGHT_COLOR: {
    lv_subject_add_observer_obj(&BRIDGE_MODEL.headlight_color,
                                change_light_button_color_observer_cb, obj,
                                user_data);
    break;
  }

  case BRIDGE_MODEL_PROP_BODYLIGHT_COLOR: {
    lv_subject_add_observer_obj(&BRIDGE_MODEL.bodylight_color,
                                change_light_button_color_observer_cb, obj,
                                user_data);
    break;
  }

  case BRIDGE_MODEL_PROP_NONE:
    break;
  }
}
