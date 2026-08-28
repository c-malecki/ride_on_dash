#include "view_home.h"
// #include "presenter_home.h"
#include "ui_helpers.h"

static void on_nav_btn_press(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_CLICKED)
    return;
  View_Base_t *self = lv_event_get_user_data(lv_event);
  self->navigate(UI_SCREEN_ID_ACCESSORY);
}

static void View_Home_Destroy(View_Base_t *self) {
  lv_obj_clean(lv_screen_active());
}

void View_Home_Create(View_Base_t *self, lv_obj_t *parent) {
  self->create = View_Home_Create;
  self->destroy = View_Home_Destroy;
  // Presenter_Home_t *presenter = (Presenter_Home_t *)self->ctx;

  lv_obj_t *grid = UI_Helper_Create_Grid(parent, UI_HELPER_GRID_3x2);

  // light select button
  lv_obj_t *light_select_btn = lv_button_create(grid);
  lv_obj_set_size(light_select_btn, 70, 70);
  lv_obj_set_style_radius(light_select_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(light_select_btn, 0, 0);
  lv_obj_set_grid_cell(light_select_btn, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(light_select_btn, on_nav_btn_press, LV_EVENT_CLICKED,
                      self);

  lv_color_t light_select_btn_color = UI_Helper_Get_LV_Color(COLOR_YELLOW);
  lv_obj_set_style_bg_color(light_select_btn, light_select_btn_color, 0);

  // light select label
  lv_obj_t *light_select_label = lv_label_create(light_select_btn);
  lv_obj_set_style_text_font(light_select_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(light_select_label, LV_SYMBOL_LEFT);
  lv_obj_set_style_align(light_select_label, LV_ALIGN_CENTER, 0);
}