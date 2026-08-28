#ifndef __STYLE_H_
#define __STYLE_H_

#include "_color.h"
#include "lvgl.h"

typedef enum {
  UI_STYLE_GRID_NONE = 0,
  UI_STYLE_GRID_2x1,
  UI_STYLE_GRID_3x2,
} UI_Style_Grid_ID;

lv_color_t UI_Style_Get_LV_Color(Color_ID color_id);

lv_obj_t *UI_Style_Create_Grid(lv_obj_t *parent, UI_Style_Grid_ID grid_id);

#endif // __STYLE_H_