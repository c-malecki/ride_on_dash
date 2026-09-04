#ifndef __STYLE_H_
#define __STYLE_H_

#include "_color.h"
#include "lvgl.h"

/* COLORS */

const lv_color_t *UI_Color_Table_Find_By_ID(Color_ID color_id);
uint8_t UI_Color_Table_Get_Count(void);

extern const lv_color_t *ui_color_table[];
extern const size_t ui_color_table_size;

/* LAYOUTS */

typedef enum {
  UI_STYLE_GRID_1x1 = 0,
  UI_STYLE_GRID_2x1,
  UI_STYLE_GRID_3x2,
} UI_Style_Grid_ID;

void UI_Style_Create_Grid(lv_obj_t *container, UI_Style_Grid_ID grid_id);

#endif // __STYLE_H_