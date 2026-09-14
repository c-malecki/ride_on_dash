#ifndef __COMMON_COLORS_H_
#define __COMMON_COLORS_H_

#include "lvgl.h"
#include <stdint.h>

#ifdef DEVELOPMENT
/* Development Configuration */

#else
/* Production Configuration */

#endif

#define COMMON_COLOR_NONE_R 0
#define COMMON_COLOR_NONE_G 0
#define COMMON_COLOR_NONE_B 0

#define COMMON_COLOR_WHITE_R 255
#define COMMON_COLOR_WHITE_G 255
#define COMMON_COLOR_WHITE_B 255

#define COMMON_COLOR_RED_R 255
#define COMMON_COLOR_RED_G 0
#define COMMON_COLOR_RED_B 0

#define COMMON_COLOR_ORANGE_R 255
#define COMMON_COLOR_ORANGE_G 128
#define COMMON_COLOR_ORANGE_B 0

#define COMMON_COLOR_YELLOW_R 255
#define COMMON_COLOR_YELLOW_G 255
#define COMMON_COLOR_YELLOW_B 0

#define COMMON_COLOR_GREEN_R 0
#define COMMON_COLOR_GREEN_G 255
#define COMMON_COLOR_GREEN_B 0

#define COMMON_COLOR_BLUE_R 0
#define COMMON_COLOR_BLUE_G 0
#define COMMON_COLOR_BLUE_B 255

#define COMMON_COLOR_VIOLET_R 128
#define COMMON_COLOR_VIOLET_G 0
#define COMMON_COLOR_VIOLET_B 255

#define COMMON_COLOR_GRAY_R 96
#define COMMON_COLOR_GRAY_G 125
#define COMMON_COLOR_GRAY_B 139

typedef enum {
  COMMON_COLOR_NONE = 0,
  COMMON_COLOR_WHITE,
  COMMON_COLOR_RED,
  COMMON_COLOR_ORANGE,
  COMMON_COLOR_YELLOW,
  COMMON_COLOR_GREEN,
  COMMON_COLOR_BLUE,
  COMMON_COLOR_VIOLET,
  COMMON_COLOR_GRAY,
  COMMON_COLOR_COUNT,
} Common_Color_ID;

typedef struct {
  Common_Color_ID Common_Color_ID;
  const lv_color_t *lv_color;
  const char *label;
} Common_Color_Table_Entry_t;

const Common_Color_Table_Entry_t *
Common_Color_Find_Entry(Common_Color_ID Common_Color_ID);
uint8_t Common_Color_Get_Entry_Count(void);

#endif // __COMMON_COLORS_H_