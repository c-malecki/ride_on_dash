#include "_color.h"

static const Color_t color_none = {0, 0, 0};        // LED values in comments
static const Color_t color_white = {255, 255, 255}; // 127, 127, 127
static const Color_t color_red = {255, 0, 0};       // 127, 0, 0
static const Color_t color_orange = {255, 128, 0};  // 127, 64, 0
static const Color_t color_yellow = {255, 255, 0};  // 127, 127, 0
static const Color_t color_green = {0, 255, 0};     // 0, 127, 0
static const Color_t color_blue = {0, 0, 255};      // 0, 0, 127
static const Color_t color_violet = {128, 0, 255};  // 64, 0, 127,
static const Color_t color_gray = {96, 125, 139};   // 48, 75, 70

static const Color_Table_Entry_t Color_Table[COLOR_COUNT] = {
    {
        COLOR_NONE,
        &color_none,
        "NONE",
    },
    {COLOR_WHITE, &color_white, "WHITE"},
    {COLOR_RED, &color_red, "RED"},
    {COLOR_ORANGE, &color_orange, "ORANGE"},
    {COLOR_YELLOW, &color_yellow, "YELLOW"},
    {COLOR_GREEN, &color_green, "GREEN"},
    {COLOR_BLUE, &color_blue, "BLUE"},
    {COLOR_VIOLET, &color_violet, "VIOLET"},
    {COLOR_GRAY, &color_gray, "GRAY"},
};

const Color_Table_Entry_t *CFG_Color_Find_Entry(Color_ID color_id) {
  if (color_id >= COLOR_COUNT) {
    return &Color_Table[COLOR_NONE];
  }
  return &Color_Table[color_id];
}

uint8_t CFG_Color_Get_Entry_Count(void) { return COLOR_COUNT; }