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
} App_Color_ID;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} App_Color_t;

extern const App_Color_t app_color_none;
extern const App_Color_t app_color_white;
extern const App_Color_t app_color_red;
extern const App_Color_t app_color_orange;
extern const App_Color_t app_color_yellow;
extern const App_Color_t app_color_green;
extern const App_Color_t app_color_blue;
extern const App_Color_t app_color_violet;
extern const App_Color_t app_color_gray;

App_Color_t App_Color_Lookup(App_Color_ID app_color_id);

#endif // __UTIL_H_