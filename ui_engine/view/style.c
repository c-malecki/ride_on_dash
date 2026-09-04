#include "style.h"
#include "_color.h"

/* COLORS */

static const lv_color_t ui_color_none = LV_COLOR_MAKE(0, 0, 0);
static const lv_color_t ui_color_white = LV_COLOR_MAKE(255, 255, 255);
static const lv_color_t ui_color_red = LV_COLOR_MAKE(255, 0, 0);
static const lv_color_t ui_color_orange = LV_COLOR_MAKE(255, 128, 0);
static const lv_color_t ui_color_yellow = LV_COLOR_MAKE(255, 255, 0);
static const lv_color_t ui_color_green = LV_COLOR_MAKE(0, 255, 0);
static const lv_color_t ui_color_blue = LV_COLOR_MAKE(0, 0, 255);
static const lv_color_t ui_color_violet = LV_COLOR_MAKE(128, 0, 255);
static const lv_color_t ui_color_gray = LV_COLOR_MAKE(96, 125, 139);

const lv_color_t *ui_color_table[COLOR_COUNT] = {
    [COLOR_NONE] = &ui_color_none,     [COLOR_WHITE] = &ui_color_white,
    [COLOR_RED] = &ui_color_red,       [COLOR_ORANGE] = &ui_color_orange,
    [COLOR_YELLOW] = &ui_color_yellow, [COLOR_GREEN] = &ui_color_green,
    [COLOR_BLUE] = &ui_color_blue,     [COLOR_VIOLET] = &ui_color_violet,
    [COLOR_GRAY] = &ui_color_gray,
};

const size_t ui_color_table_size =
    sizeof(ui_color_table) / sizeof(ui_color_table[0]);

const lv_color_t *UI_Color_Table_Find_By_ID(Color_ID color_id) {
  if (color_id >= COLOR_COUNT) {
    return ui_color_table[COLOR_NONE];
  }
  return ui_color_table[color_id];
}

uint8_t UI_Color_Table_Get_Count(void) { return COLOR_COUNT; }

/* LAYOUTS */

const int32_t grid_cols_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_3[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

const int32_t grid_rows_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_rows_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

void UI_Style_Create_Grid(lv_obj_t *container, UI_Style_Grid_ID grid_id) {
  lv_obj_set_layout(container, LV_LAYOUT_GRID);
  lv_obj_set_width(container, 320);
  lv_obj_set_height(container, 240);
  lv_obj_set_style_border_width(container, 0, 0);

  switch (grid_id) {
  case UI_STYLE_GRID_2x1:
    lv_obj_set_grid_dsc_array(container, grid_cols_2, grid_rows_1);
    break;

  case UI_STYLE_GRID_3x2:
    lv_obj_set_grid_dsc_array(container, grid_cols_3, grid_rows_2);
    break;

  case UI_STYLE_GRID_1x1:
    lv_obj_set_grid_dsc_array(container, grid_cols_1, grid_rows_1);
    break;
  }
}