#include "util.h"

static const Util_Color_t util_color_none = {0, 0, 0}; // LED values in comments
static const Util_Color_t util_color_white = {255, 255, 255}; // 127, 127, 127
static const Util_Color_t util_color_red = {255, 0, 0};       // 127, 0, 0
static const Util_Color_t util_color_orange = {255, 128, 0};  // 127, 64, 0
static const Util_Color_t util_color_yellow = {255, 255, 0};  // 127, 127, 0
static const Util_Color_t util_color_green = {0, 255, 0};     // 0, 127, 0
static const Util_Color_t util_color_blue = {0, 0, 255};      // 0, 0, 127
static const Util_Color_t util_color_violet = {128, 0, 255};  // 64, 0, 127,
static const Util_Color_t util_color_gray = {96, 125, 139};   // 48, 75, 70

static const Util_Color_Table_Entry_t Util_Color_Table[UTIL_COLOR_COUNT] = {
    {
        UTIL_COLOR_NONE,
        &util_color_none,
        "NONE",
    },
    {UTIL_COLOR_WHITE, &util_color_white, "WHITE"},
    {UTIL_COLOR_RED, &util_color_red, "RED"},
    {UTIL_COLOR_ORANGE, &util_color_orange, "ORANGE"},
    {UTIL_COLOR_YELLOW, &util_color_yellow, "YELLOW"},
    {UTIL_COLOR_GREEN, &util_color_green, "GREEN"},
    {UTIL_COLOR_BLUE, &util_color_blue, "BLUE"},
    {UTIL_COLOR_VIOLET, &util_color_violet, "VIOLET"},
    {UTIL_COLOR_GRAY, &util_color_gray, "GRAY"},
};

const Util_Color_Table_Entry_t *UTIL_Get_Color(Util_Color_ID color_id) {
  if (color_id >= UTIL_COLOR_COUNT) {
    return &Util_Color_Table[UTIL_COLOR_NONE];
  }
  return &Util_Color_Table[color_id];
}

uint8_t Util_Color_Get_Count(void) { return UTIL_COLOR_COUNT; }