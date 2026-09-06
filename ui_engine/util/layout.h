#ifndef __UTIL_LAYOUT_H_
#define __UTIL_LAYOUT_H_

#include "lvgl.h"

/* LAYOUTS */

typedef enum {
  UTIL_LAYOUT_GRID_1x1 = 0,
  UTIL_LAYOUT_GRID_2x1,
  UTIL_LAYOUT_GRID_3x2,
} UTIL_Layout_Grid_ID;

void UTIL_Layout_Grid(lv_obj_t *container, UTIL_Layout_Grid_ID grid_id);

#endif // __UTIL_LAYOUT_H_