#include "home.h"
#include "button_base.h"
#include "colors.h"
#include "layout.h"
#include "ui_engine.h"
#include <stdint.h>

/* Local State */

/* UI Actions */

static void ui_home_screen_button_press(lv_event_t *lv_event) {
  UI_ENGINE_Screen_ID screen_id =
      (UI_ENGINE_Screen_ID)(uintptr_t)lv_event_get_user_data(lv_event);

  UI_ENGINE_Navigate(screen_id);
}

/* UI Configs */

const UI_Button_Base_Config_t light_btn_cfg = {
    .color_id = ROD_COLOR_GRAY,
    .label = LV_SYMBOL_POWER,
    .row = 0,
    .col = 0,
};

// const lv_color_t rainbow_colors[] = {
//     LV_COLOR_MAKE(0, 0, 0),     LV_COLOR_MAKE(255, 255, 255),
//     LV_COLOR_MAKE(255, 0, 0),   LV_COLOR_MAKE(255, 128, 0),
//     LV_COLOR_MAKE(255, 255, 0), LV_COLOR_MAKE(0, 255, 0),
//     LV_COLOR_MAKE(0, 0, 255),   LV_COLOR_MAKE(128, 0, 255),
// };

/* Render Function */

void Render_Home(lv_obj_t *container) {
  UI_LAYOUT_Create_Grid(container, UI_LAYOUT_GRID_3x2);
  lv_obj_t *light_btn = lv_button_create(container);

  UI_Button_Base_Apply(light_btn, &light_btn_cfg);
  lv_obj_add_event_cb(light_btn, ui_home_screen_button_press, LV_EVENT_CLICKED,
                      (void *)UI_ENGINE_SCREEN_ID_LIGHT);
}

// static void render(lv_obj_t *container) {
//   UI_LAYOUT_Create_Grid(container, UI_LAYOUT_GRID_3x2);
//   lv_obj_t *light_btn = lv_button_create(container);

//   UI_Button_Base_Apply(light_btn, &light_btn_cfg);
//   lv_obj_add_event_cb(light_btn, ui_home_screen_button_press,
//   LV_EVENT_CLICKED,
//                       (void *)&ui_home_screen_action);

//   static lv_grad_dsc_t rainbow_grad;
//   lv_grad_init_stops(&rainbow_grad, rainbow_colors, NULL, NULL,
//                      sizeof(rainbow_colors) / sizeof(lv_color_t));

//   lv_grad_horizontal_init(&rainbow_grad);

//   static lv_style_t style_rainbow;
//   lv_style_init(&style_rainbow);
//   lv_style_set_bg_grad(&style_rainbow, &rainbow_grad);
//   lv_style_set_bg_opa(&style_rainbow, LV_OPA_COVER);

//   lv_obj_add_style(light_btn, &style_rainbow, LV_PART_MAIN);
// }

/* Export */

// const UI_Screen_t UI_Screen_Home = {
//     .screen_id = UI_SCREEN_ID_HOME,
//     .render_fn = render,
// };
