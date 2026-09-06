#include "layout.h"

/* LAYOUTS */

const int32_t grid_cols_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_3[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

const int32_t grid_rows_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_rows_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

void UTIL_Layout_Grid(lv_obj_t *container, UTIL_Layout_Grid_ID grid_id) {
  lv_obj_set_layout(container, LV_LAYOUT_GRID);
  lv_obj_set_width(container, 320);
  lv_obj_set_height(container, 240);
  lv_obj_set_style_border_width(container, 0, 0);

  switch (grid_id) {
  case UTIL_LAYOUT_GRID_2x1:
    lv_obj_set_grid_dsc_array(container, grid_cols_2, grid_rows_1);
    break;

  case UTIL_LAYOUT_GRID_3x2:
    lv_obj_set_grid_dsc_array(container, grid_cols_3, grid_rows_2);
    break;

  case UTIL_LAYOUT_GRID_1x1:
    lv_obj_set_grid_dsc_array(container, grid_cols_1, grid_rows_1);
    break;
  }
}