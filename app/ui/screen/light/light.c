#include "light.h"
#include "input.h"
#include "style.h"

static void ui_light_screen_button_press(lv_event_t *lv_event) {
  Input_Handle_LV_Event(lv_event);
}

static void ui_light_screen_render_fn(lv_obj_t *parent) {
  lv_obj_t *grid = UI_Style_Create_Grid(parent, UI_STYLE_GRID_2x1);

  // headlights button
  lv_obj_t *headlight_btn = lv_button_create(grid);
  lv_obj_set_size(headlight_btn, 70, 70);
  lv_obj_set_style_radius(headlight_btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_style_border_width(headlight_btn, 0, 0);
  lv_obj_set_grid_cell(headlight_btn, LV_GRID_ALIGN_CENTER, 0, 1,
                       LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_add_event_cb(headlight_btn, ui_light_screen_button_press,
                      LV_EVENT_CLICKED,
                      (void *)UI_INPUT_ID_SHOW_HEADLIGHT_CONTROL);

  lv_color_t hl_btn_color = UI_Style_Get_LV_Color(COLOR_YELLOW);
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
  lv_obj_add_event_cb(bodylight_btn, ui_light_screen_button_press,
                      LV_EVENT_CLICKED,
                      (void *)UI_INPUT_ID_SHOW_BODYLIGHT_CONTROL);

  lv_color_t bl_btn_color = UI_Style_Get_LV_Color(COLOR_YELLOW);
  lv_obj_set_style_bg_color(bodylight_btn, bl_btn_color, 0);

  // bodylights label
  lv_obj_t *bodylight_label = lv_label_create(bodylight_btn);
  lv_obj_set_style_text_font(bodylight_label, &lv_font_montserrat_28, 0);
  lv_label_set_text(bodylight_label, LV_SYMBOL_DRIVE);
  lv_obj_set_style_align(bodylight_label, LV_ALIGN_CENTER, 0);
}

const UI_Screen_t UI_Screen_Light = {
    .screen_id = UI_SCREEN_ID_LIGHT,
    .render_fn = ui_light_screen_render_fn,
};