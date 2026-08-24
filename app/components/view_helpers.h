#ifndef __VIEW_HELPERS_H_
#define __VIEW_HELPERS_H_

#include "lvgl.h"
#include "util.h"

typedef enum {
  VIEW_HELPER_GRID_NONE = 0,
  VIEW_HELPER_GRID_2x1,
  VIEW_HELPER_GRID_3x2,
} View_Helper_Grid_ID;

lv_color_t View_Helper_Get_LV_Color(App_Color_ID app_color_id);

lv_obj_t *View_Helper_Create_Grid(lv_obj_t *parent,
                                  View_Helper_Grid_ID grid_id);

#endif // __VIEW_HELPERS_H_