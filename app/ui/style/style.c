#include "style.h"
#include "_color.h"

const lv_style_const_prop_t style_grid_props[] = {
    LV_STYLE_CONST_WIDTH(320),
    LV_STYLE_CONST_HEIGHT(240),
    LV_STYLE_CONST_BORDER_WIDTH(0),
    LV_STYLE_CONST_LAYOUT(LV_LAYOUT_GRID),
};
LV_STYLE_CONST_INIT(style_grid, style_grid_props);

const int32_t grid_cols_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};
const int32_t grid_cols_3[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

const int32_t grid_rows_1[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
const int32_t grid_rows_2[] = {LV_GRID_FR(1), LV_GRID_FR(1),
                               LV_GRID_TEMPLATE_LAST};

lv_color_t UI_Style_Get_LV_Color(Color_ID color_id) {
  const Color_Table_Entry_t *color = CFG_Color_Find_Entry(color_id);
  return lv_color_make(color->color->r, color->color->g, color->color->b);
}

lv_obj_t *UI_Style_Create_Grid(lv_obj_t *parent, UI_Style_Grid_ID grid_id) {
  lv_obj_t *grid = lv_obj_create(parent);
  lv_obj_add_style(grid, &style_grid, 0);

  switch (grid_id) {
  case UI_STYLE_GRID_2x1:
    lv_obj_set_grid_dsc_array(grid, grid_cols_2, grid_rows_1);
    break;

  case UI_STYLE_GRID_3x2:
    lv_obj_set_grid_dsc_array(grid, grid_cols_3, grid_rows_2);
    break;

  case UI_STYLE_GRID_1x1:
    lv_obj_set_grid_dsc_array(grid, grid_cols_1, grid_rows_1);
    break;
  }

  return grid;
}