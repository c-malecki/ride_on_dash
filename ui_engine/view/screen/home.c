#include "home.h"
#include "input.h"
#include "style.h"

static void ui_home_screen_button_press(lv_event_t *lv_event) {
  Input_Handle_LV_Event(lv_event);
}

static void ui_home_screen_render_fn(lv_obj_t *container) {
  UI_Style_Create_Grid(container, UI_STYLE_GRID_3x2);

  // light select button
  lv_obj_t *light_select_btn = lv_button_create(container);
  lv_obj_set_size(light_select_btn, 70, 70);
  lv_obj_set_style_radius(light_select_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(light_select_btn, 0, 0);
  lv_obj_set_grid_cell(light_select_btn, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(light_select_btn, ui_home_screen_button_press,
                      LV_EVENT_CLICKED, (void *)UI_INPUT_ID_NAV_TO_LIGHT);

  lv_color_t light_select_btn_color = UI_Style_Get_LV_Color(COLOR_YELLOW);
  lv_obj_set_style_bg_color(light_select_btn, light_select_btn_color, 0);

  // light select label
  lv_obj_t *light_select_label = lv_label_create(light_select_btn);
  lv_obj_set_style_text_font(light_select_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(light_select_label, LV_SYMBOL_LEFT);
  lv_obj_set_style_align(light_select_label, LV_ALIGN_CENTER, 0);
}

const UI_Screen_t UI_Screen_Home = {
    .screen_id = UI_SCREEN_ID_HOME,
    .render_fn = ui_home_screen_render_fn,
};