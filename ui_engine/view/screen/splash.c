#include "splash.h"
#include "colors.h"
#include "layout.h"

void Render_Splash(lv_obj_t *container) {
  UI_LAYOUT_Create_Grid(container, UI_LAYOUT_GRID_1x1);

  lv_obj_t *led = lv_led_create(container);
  lv_obj_set_grid_cell(led, LV_GRID_ALIGN_CENTER, 0, 0, LV_GRID_ALIGN_CENTER, 0,
                       0);
  const lv_color_t *color = ROD_Color_Find_Entry(ROD_COLOR_BLUE)->color;
  lv_led_set_color(led, *color);
  lv_led_on(led);
}