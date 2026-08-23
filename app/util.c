#include "util.h"

const App_Color_t g_color_none = {0, 0, 0};        // LED values in comments
const App_Color_t g_color_white = {255, 255, 255}; // 127, 127, 127
const App_Color_t g_color_red = {255, 0, 0};       // 127, 0, 0
const App_Color_t g_color_orange = {255, 128, 0};  // 127, 64, 0
const App_Color_t g_color_yellow = {255, 255, 0};  // 127, 127, 0
const App_Color_t g_color_green = {0, 255, 0};     // 0, 127, 0
const App_Color_t g_color_blue = {0, 0, 255};      // 0, 0, 127
const App_Color_t g_color_violet = {128, 0, 255};  // 64, 0, 127,
const App_Color_t g_color_gray = {96, 125, 139};   // 48, 75, 70

App_Color_t App_Color_Lookup(App_Color_ID app_color_id) {
  switch (app_color_id) {
  case APP_COLOR_WHITE:
    return app_color_white;
  case APP_COLOR_RED:
    return app_color_red;
  case APP_COLOR_ORANGE:
    return app_color_orange;
  case APP_COLOR_YELLOW:
    return app_color_yellow;
  case APP_COLOR_GREEN:
    return app_color_green;
  case APP_COLOR_BLUE:
    return app_color_blue;
  case APP_COLOR_VIOLET:
    return app_color_violet;
  case APP_COLOR_GRAY:
    return app_color_gray;
  default:
    return app_color_none;
  }
}