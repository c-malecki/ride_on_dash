#ifndef __COLORS_H_
#define __COLORS_H_

#include "lvgl.h"
#include <stdint.h>

#ifdef DEVELOPMENT
/* Development Configuration */

#else
/* Production Configuration */

#endif

#define ROD_COLOR_NONE_R 0
#define ROD_COLOR_NONE_G 0
#define ROD_COLOR_NONE_B 0

#define ROD_COLOR_WHITE_R 255
#define ROD_COLOR_WHITE_G 255
#define ROD_COLOR_WHITE_B 255

#define ROD_COLOR_RED_R 255
#define ROD_COLOR_RED_G 0
#define ROD_COLOR_RED_B 0

#define ROD_COLOR_ORANGE_R 255
#define ROD_COLOR_ORANGE_G 128
#define ROD_COLOR_ORANGE_B 0

#define ROD_COLOR_YELLOW_R 255
#define ROD_COLOR_YELLOW_G 255
#define ROD_COLOR_YELLOW_B 0

#define ROD_COLOR_GREEN_R 0
#define ROD_COLOR_GREEN_G 255
#define ROD_COLOR_GREEN_B 0

#define ROD_COLOR_BLUE_R 0
#define ROD_COLOR_BLUE_G 0
#define ROD_COLOR_BLUE_B 255

#define ROD_COLOR_VIOLET_R 128
#define ROD_COLOR_VIOLET_G 0
#define ROD_COLOR_VIOLET_B 255

#define ROD_COLOR_GRAY_R 96
#define ROD_COLOR_GRAY_G 125
#define ROD_COLOR_GRAY_B 139

typedef enum {
  ROD_COLOR_NONE = 0,
  ROD_COLOR_WHITE,
  ROD_COLOR_RED,
  ROD_COLOR_ORANGE,
  ROD_COLOR_YELLOW,
  ROD_COLOR_GREEN,
  ROD_COLOR_BLUE,
  ROD_COLOR_VIOLET,
  ROD_COLOR_GRAY,
  ROD_COLOR_COUNT,
} ROD_Color_ID;

typedef struct {
  ROD_Color_ID ROD_color_id;
  const lv_color_t *color;
  const char *label;
} ROD_Color_Table_Entry_t;

const ROD_Color_Table_Entry_t *ROD_Color_Find_Entry(ROD_Color_ID ROD_color_id);
uint8_t ROD_Color_Get_Entry_Count(void);

#endif // __COLORS_H_