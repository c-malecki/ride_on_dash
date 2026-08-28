#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdint.h>

typedef enum {
  UTIL_COLOR_NONE = 0,
  UTIL_COLOR_WHITE,
  UTIL_COLOR_RED,
  UTIL_COLOR_ORANGE,
  UTIL_COLOR_YELLOW,
  UTIL_COLOR_GREEN,
  UTIL_COLOR_BLUE,
  UTIL_COLOR_VIOLET,
  UTIL_COLOR_GRAY,
  UTIL_COLOR_COUNT,
} Util_Color_ID;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} Util_Color_t;

typedef struct {
  Util_Color_ID color_id;
  const Util_Color_t *color;
  const char *label;
} Util_Color_Table_Entry_t;

const Util_Color_Table_Entry_t *UTIL_Get_Color(Util_Color_ID color_id);
uint8_t Util_Color_Get_Count(void);

#endif // __UTIL_H_