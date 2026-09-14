#ifndef __COMMON_LAYOUT_H_
#define __COMMON_LAYOUT_H_

#include "lvgl.h"

/* LAYOUTS */

typedef enum {
  COMMON_LAYOUT_GRID_1x1 = 0,
  COMMON_LAYOUT_GRID_2x1,
  COMMON_LAYOUT_GRID_3x2,
} Common_Layout_Grid_ID;

void Common_Layout_Grid(lv_obj_t *container, Common_Layout_Grid_ID grid_id);

#endif // __COMMON_LAYOUT_H_