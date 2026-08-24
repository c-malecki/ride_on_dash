#include "util.h"

static const App_Color_t app_color_none = {0, 0, 0}; // LED values in comments
static const App_Color_t app_color_white = {255, 255, 255}; // 127, 127, 127
static const App_Color_t app_color_red = {255, 0, 0};       // 127, 0, 0
static const App_Color_t app_color_orange = {255, 128, 0};  // 127, 64, 0
static const App_Color_t app_color_yellow = {255, 255, 0};  // 127, 127, 0
static const App_Color_t app_color_green = {0, 255, 0};     // 0, 127, 0
static const App_Color_t app_color_blue = {0, 0, 255};      // 0, 0, 127
static const App_Color_t app_color_violet = {128, 0, 255};  // 64, 0, 127,
static const App_Color_t app_color_gray = {96, 125, 139};   // 48, 75, 70

static const App_Color_Table_Entry_t APP_COLOR_TABLE[APP_COLOR_COUNT] = {
    {
        APP_COLOR_NONE,
        &app_color_none,
        "NONE",
    },
    {APP_COLOR_WHITE, &app_color_white, "WHITE"},
    {APP_COLOR_RED, &app_color_red, "RED"},
    {APP_COLOR_ORANGE, &app_color_orange, "ORANGE"},
    {APP_COLOR_YELLOW, &app_color_yellow, "YELLOW"},
    {APP_COLOR_GREEN, &app_color_green, "GREEN"},
    {APP_COLOR_BLUE, &app_color_blue, "BLUE"},
    {APP_COLOR_VIOLET, &app_color_violet, "VIOLET"},
    {APP_COLOR_GRAY, &app_color_gray, "GRAY"},
};

const App_Color_Table_Entry_t *App_Color_Get_Entry(App_Color_ID color_id) {
  if (color_id >= APP_COLOR_COUNT) {
    return &APP_COLOR_TABLE[APP_COLOR_NONE];
  }
  return &APP_COLOR_TABLE[color_id];
}

uint8_t App_Color_Get_Count(void) { return APP_COLOR_COUNT; }