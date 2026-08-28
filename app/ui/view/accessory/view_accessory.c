#include "view_accessory.h"
// #include "model_accessory.h"
// #include "presenter_accessory.h"
#include "ui_helpers.h"
#include "view_base.h"

static void on_nav_btn_press(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_CLICKED)
    return;
  View_Base_t *self = lv_event_get_user_data(lv_event);
  self->navigate(UI_SCREEN_ID_COLOR_PICKER);
}

/**/

void View_Accessory_Create(View_Base_t *self, lv_obj_t *parent) {
  // Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)self->ctx;
  // Model_Accessory_t *model = presenter->model;

  // layout
  lv_obj_t *grid = UI_Helper_Create_Grid(parent, UI_HELPER_GRID_2x1);

  // headlights button
  lv_obj_t *headlight_btn = lv_button_create(grid);
  lv_obj_set_size(headlight_btn, 70, 70);
  lv_obj_set_style_radius(headlight_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(headlight_btn, 0, 0);
  lv_obj_set_grid_cell(headlight_btn, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(headlight_btn, on_nav_btn_press, LV_EVENT_CLICKED, self);

  lv_color_t hl_btn_color = UI_Helper_Get_LV_Color(UTIL_COLOR_YELLOW);
  lv_obj_set_style_bg_color(headlight_btn, hl_btn_color, 0);

  // headlights label
  lv_obj_t *headlight_label = lv_label_create(headlight_btn);
  lv_obj_set_style_text_font(headlight_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(headlight_label, LV_SYMBOL_LEFT);
  lv_obj_set_style_align(headlight_label, LV_ALIGN_CENTER, 0);

  // bodylights button
  lv_obj_t *bodylight_btn = lv_button_create(grid);
  lv_obj_set_size(bodylight_btn, 70, 70);
  lv_obj_set_style_radius(bodylight_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(bodylight_btn, 0, 0);
  lv_obj_set_grid_cell(bodylight_btn, LV_GRID_ALIGN_CENTER, 1, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(bodylight_btn, on_nav_btn_press, LV_EVENT_CLICKED, self);

  lv_color_t bl_btn_color = UI_Helper_Get_LV_Color(UTIL_COLOR_YELLOW);
  lv_obj_set_style_bg_color(bodylight_btn, bl_btn_color, 0);

  // bodylights label
  lv_obj_t *bodylight_label = lv_label_create(bodylight_btn);
  lv_obj_set_style_text_font(bodylight_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(bodylight_label, LV_SYMBOL_DRIVE);
  lv_obj_set_style_align(bodylight_label, LV_ALIGN_CENTER, 0);
};

/*

static Model_Color_Picker_t model_color_picker;
static Presenter_Color_Picker_t presenter_color_picker;

static void inj_color_picker_cb(Util_Color_ID color_id) {}

static void on_bodylight_btn_press(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_CLICKED)
    return;

  // lv_obj_t *btn = lv_event_get_target(lv_event);
  View_Base_t *self = lv_event_get_user_data(lv_event);
  Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)self->ctx;

  Model_Accessory_Set_Selected_Lights(presenter->model,
                                      MODEL_ACCESSORY_LED_BODYLIGHTS);
  Model_Accessory_Set_Show_Color_Picker(presenter->model, true);
}

static void on_color_selected(void *ctx, Util_Color_ID color_id) {
  Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)ctx;

  Model_Accessory_LED selected_light =
      Model_Accessory_Get_Selected_Lights(presenter->model);

  // fires both the nav-button UI observer and the LED observer
  if (selected_light == MODEL_ACCESSORY_LED_HEADLIGHTS) {
    Model_Accessory_Set_Btn_Color_Headlights(presenter->model, color_id);
  } else if (selected_light == MODEL_ACCESSORY_LED_BODYLIGHTS) {
    Model_Accessory_Set_Btn_Color_Bodylights(presenter->model, color_id);
  }

  Model_Accessory_Set_Selected_Lights(presenter->model,
                                      MODEL_ACCESSORY_LED_NONE);
  Model_Accessory_Set_Show_Color_Picker(presenter->model, false);
}


  // color_picker
  // Model_Color_Picker_Init(&model_color_picker);
  // Presenter_Color_Picker_Create(&presenter_color_picker, &model_color_picker,
  //                               on_color_selected, presenter);
  // Presenter_Color_Picker_Init(&presenter_color_picker.base);

  // static View_Base_t view_color_picker = {.ctx = &presenter_color_picker};
  // lv_obj_t *color_picker =
  //     View_Color_Picker_Create(&view_color_picker, lv_layer_top());
  // lv_obj_center(color_picker);
  // lv_obj_bind_flag_if_eq(color_picker, &model->color_picker_show,
  //                        LV_OBJ_FLAG_HIDDEN, 0);

*/
