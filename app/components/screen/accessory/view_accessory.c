#include "view_accessory.h"
#include "core/lv_obj.h"
#include "core/lv_obj_pos.h"
#include "core/lv_observer.h"
#include "display/lv_display.h"
#include "model_accessory.h"
#include "model_color_picker.h"
#include "presenter_accessory.h"
#include "presenter_color_picker.h"
#include "util.h"
#include "view_base.h"
#include "view_color_picker.h"
#include "view_helpers.h"

static Model_Color_Picker_t model_color_picker;
static Presenter_Color_Picker_t presenter_color_picker;

static void on_light_btn_press(lv_event_t *lv_event) {
  lv_event_code_t code = lv_event_get_code(lv_event);
  if (code != LV_EVENT_CLICKED) {
    return;
  }
}

static void on_color_selected(void *ctx, App_Color_ID color_id) {
  Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)ctx;

  // fires both the nav-button UI observer and the LED observer
  Model_Accessory_Set_Btn_Color_Headlights(presenter->model, color_id);
  // Modal_Close(); // however you're tracking/deleting the modal obj
}

/**/

static void btn_color_headlight_observer_cb(lv_observer_t *observer,
                                            lv_subject_t *subject) {
  lv_obj_t *headlight_btn = lv_observer_get_target_obj(observer);

  App_Color_ID color_id = (App_Color_ID)lv_subject_get_int(subject);
  lv_color_t color = View_Helper_Get_LV_Color(color_id);

  lv_obj_set_style_bg_color(headlight_btn, color, 0);
}

void View_Accessory_Create(View_Base_t *self, lv_obj_t *parent) {
  Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)self->ctx;
  Model_Accessory_t *model = presenter->model;

  // layout
  lv_obj_t *grid = View_Helper_Create_Grid(parent, VIEW_HELPER_GRID_2x1);

  // button
  lv_obj_t *headlight_btn = lv_button_create(grid);
  lv_obj_set_size(headlight_btn, 70, 70);
  lv_obj_set_style_radius(headlight_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(headlight_btn, 0, 0);
  lv_color_t btn_color = View_Helper_Get_LV_Color(APP_COLOR_YELLOW);
  lv_obj_set_style_bg_color(headlight_btn, btn_color, 0);
  lv_obj_set_grid_cell(headlight_btn, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);

  lv_obj_t *headlight_label = lv_label_create(headlight_btn);
  lv_obj_set_style_text_font(headlight_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(headlight_label, LV_SYMBOL_LEFT);
  lv_obj_set_style_align(headlight_label, LV_ALIGN_CENTER, 0);

  // change btn color based on current selected color/LED
  lv_subject_add_observer_obj(&model->btn_color_headlights,
                              btn_color_headlight_observer_cb, headlight_btn,
                              NULL);

  // color_picker
  Model_Color_Picker_Init(&model_color_picker);
  Presenter_Color_Picker_Create(&presenter_color_picker, &model_color_picker,
                                on_color_selected, presenter);
  Presenter_Color_Picker_Init(&presenter_color_picker.base);

  static View_Base_t view_color_picker = {.ctx = &presenter_color_picker};
  lv_obj_t *color_picker =
      View_Color_Picker_Create(&view_color_picker, lv_layer_top());
  lv_obj_center(color_picker);
  lv_obj_bind_flag_if_eq(color_picker, &model->show_color_picker,
                         LV_OBJ_FLAG_HIDDEN, 1);
};