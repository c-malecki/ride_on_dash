#ifndef __LAYOUT_H_
#define __LAYOUT_H_

#include "lvgl.h"

/* LAYOUTS */

typedef enum {
  UI_LAYOUT_GRID_1x1 = 0,
  UI_LAYOUT_GRID_2x1,
  UI_LAYOUT_GRID_3x2,
} UI_LAYOUT_Grid_ID;

void UI_LAYOUT_Create_Grid(lv_obj_t *container, UI_LAYOUT_Grid_ID grid_id);

#endif // __LAYOUT_H_