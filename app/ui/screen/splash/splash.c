#include "splash.h"
#include "style.h"

static void ui_splash_screen_render_fn(lv_obj_t *parent) {
  lv_obj_t *grid = UI_Style_Create_Grid(parent, UI_STYLE_GRID_1x1);

  lv_obj_t *led = lv_led_create(grid);
  lv_obj_set_grid_cell(led, LV_GRID_ALIGN_CENTER, 0, 0, LV_GRID_ALIGN_CENTER, 0,
                       0);
  lv_led_set_color(led, UI_Style_Get_LV_Color(COLOR_BLUE));
  lv_led_on(led);
}

const UI_Screen_t UI_Screen_Splash = {
    .screen_id = UI_SCREEN_ID_SPLASH,
    .render_fn = ui_splash_screen_render_fn,
};