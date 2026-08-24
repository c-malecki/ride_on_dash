#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdint.h>

typedef enum {
  APP_COLOR_NONE = 0,
  APP_COLOR_WHITE,
  APP_COLOR_RED,
  APP_COLOR_ORANGE,
  APP_COLOR_YELLOW,
  APP_COLOR_GREEN,
  APP_COLOR_BLUE,
  APP_COLOR_VIOLET,
  APP_COLOR_GRAY,
  APP_COLOR_COUNT,
} App_Color_ID;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} App_Color_t;

typedef struct {
  App_Color_ID color_id;
  const App_Color_t *color;
  const char *label;
} App_Color_Table_Entry_t;

const App_Color_Table_Entry_t *App_Color_Get_Entry(App_Color_ID color_id);
uint8_t App_Color_Get_Count(void);

#endif // __UTIL_H_