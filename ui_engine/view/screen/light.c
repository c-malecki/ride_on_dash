#include "light.h"
#include "_color.h"
#include "button_base.h"
#include "color_picker.h"
#include "definitions.h"
#include "style.h"
#include "ui_engine.h"
#include <stdbool.h>

/* Local State */

typedef enum {
  EDITING_NONE,
  EDITING_HEADLIGHT,
  EDITING_BODYLIGHT
} selected_light;

static struct {
  selected_light selected_light;
  lv_subject_t show_color_picker;
  // lv_obj_t *color_picker_modal;
  // lv_obj_t *headlight_btn;
  // lv_obj_t *bodylight_btn;
} local_view_state;

/* UI Actions */

static void handle_color_picker(Color_ID color_id) {
  UI_Model_Prop_ID prop_id = UI_MODEL_PROP_NONE;

  switch (local_view_state.selected_light) {
  case EDITING_HEADLIGHT: {
    prop_id = UI_MODEL_PROP_HEADLIGHT_COLOR;
    break;
  }

  case EDITING_BODYLIGHT: {
    prop_id = UI_MODEL_PROP_BODYLIGHT_COLOR;
    break;
  }

  case EDITING_NONE:
    break;
  }

  const UI_Action_t *action = &(const UI_Action_t){
      .action_id = UI_ACTION_ID_SET_PROP,
      .payload.model_prop_data.model_prop_id = prop_id,
      .payload.model_prop_data.value = color_id,
  };

  UI_Engine_Execute_Action(action);

  local_view_state.selected_light = EDITING_NONE;
  lv_subject_set_int(&local_view_state.show_color_picker, 0);
}

static void select_light_to_edit(lv_event_t *lv_event) {
  selected_light selection =
      (selected_light)(uintptr_t)lv_event_get_user_data(lv_event);
  local_view_state.selected_light = selection;
  lv_subject_set_int(&local_view_state.show_color_picker, 1);
}

/* UI Configs */

const UI_Button_Base_Config_t headlight_btn_cfg = {
    .color = COLOR_NONE,
    .label = LV_SYMBOL_LEFT,
    .row = 0,
    .col = 0,
};

const UI_Button_Base_Config_t bodylight_btn_cfg = {
    .color = COLOR_GRAY,
    .label = LV_SYMBOL_LEFT,
    .row = 0,
    .col = 1,
};

const UI_Color_Picker_Config_t color_picker_cfg = {
    .color_picker_cb = handle_color_picker,
};

/* Render Function */

static void render(lv_obj_t *container) {
  UI_Style_Create_Grid(container, UI_STYLE_GRID_2x1);

  lv_obj_t *headlight_btn = lv_button_create(container);
  UI_Button_Base_Apply(headlight_btn, &headlight_btn_cfg);
  lv_obj_add_event_cb(headlight_btn, select_light_to_edit, LV_EVENT_CLICKED,
                      (void *)EDITING_HEADLIGHT);

  // local_view_state.headlight_btn = headlight_btn;

  lv_obj_t *bodylight_btn = lv_button_create(container);
  UI_Button_Base_Apply(bodylight_btn, &bodylight_btn_cfg);
  lv_obj_add_event_cb(bodylight_btn, select_light_to_edit, LV_EVENT_CLICKED,
                      (void *)EDITING_BODYLIGHT);

  // local_view_state.bodylight_btn = bodylight_btn;

  lv_obj_t *bm = lv_buttonmatrix_create(lv_layer_top());
  UI_Color_Picker_Apply(bm, &color_picker_cfg);

  lv_subject_init_int(&local_view_state.show_color_picker, 0);
  lv_obj_bind_flag_if_eq(bm, &local_view_state.show_color_picker,
                         LV_OBJ_FLAG_HIDDEN, 0);
}

/* Export */

const UI_Screen_t UI_Screen_Light = {
    .screen_id = UI_SCREEN_ID_LIGHT,
    .render_fn = render,
};

//////////

// static void on_color_selected(lv_event_t *e) {
// lv_obj_t *wheel = lv_event_get_target(e);

// Wait until the user finishes selecting (e.g., releases the wheel or presses
// an OK button) if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED &&
// !lv_indev_is_dragging(lv_indev_get_act())) {
//     lv_color_t selected_color = lv_colorwheel_get_rgb(wheel);

// 4. Construct a single rich action bundle to send to the engine
// UI_Action_t action = {
//     .action_id = UI_ACTION_ID_SET_PROP,
//     .payload.prop_data = {
// Map local target context back to global property IDs
//         .prop_id = (local_view_state.current_target == EDITING_HEADLIGHT) ?
//                     UI_MODEL_PROP_ID_HEADLIGHT :
//                     UI_MODEL_PROP_ID_BODYLIGHT,
//         .value = lv_color_to_u32(selected_color)
//     }
// };

// Send to Engine Controller
// UI_Engine_Execute_Action(&action);

// Clean up the local color picker widget automatically
// lv_obj_delete(local_view_state.color_picker_modal);
// local_view_state.color_picker_modal = NULL;
// local_view_state.current_target = EDITING_NONE;
// }
// }

// Make the color picker "dumb" and local: just create/show it right here
// local_view_state.color_picker_modal =
// lv_colorwheel_create(lv_screen_active(), true);
// lv_obj_center(local_view_state.color_picker_modal);

// Bind a local callback to the color picker
// lv_obj_add_event_cb(local_view_state.color_picker_modal, on_color_selected,
// LV_EVENT_VALUE_CHANGED, NULL);