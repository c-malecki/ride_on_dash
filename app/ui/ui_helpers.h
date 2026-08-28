#ifndef __UI_HELPERS_H_
#define __UI_HELPERS_H_

#include "lvgl.h"
#include "util.h"

typedef enum {
  UI_SCREEN_ID_NONE = 0,
  UI_SCREEN_ID_HOME,
  UI_SCREEN_ID_ACCESSORY,
  UI_SCREEN_ID_COLOR_PICKER,
} UI_Screen_ID;

typedef enum {
  UI_HELPER_GRID_NONE = 0,
  UI_HELPER_GRID_2x1,
  UI_HELPER_GRID_3x2,
} UI_Helper_Grid_ID;

lv_color_t UI_Helper_Get_LV_Color(Util_Color_ID color_id);

lv_obj_t *UI_Helper_Create_Grid(lv_obj_t *parent, UI_Helper_Grid_ID grid_id);

#endif // __UI_HELPERS_H_