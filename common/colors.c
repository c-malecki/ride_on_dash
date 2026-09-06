#include "colors.h"

static const lv_color_t color_none =
    LV_COLOR_MAKE(ROD_COLOR_NONE_R, ROD_COLOR_NONE_G, ROD_COLOR_NONE_B);

static const lv_color_t color_white =
    LV_COLOR_MAKE(ROD_COLOR_WHITE_R, ROD_COLOR_WHITE_G, ROD_COLOR_WHITE_B);

static const lv_color_t color_red =
    LV_COLOR_MAKE(ROD_COLOR_RED_R, ROD_COLOR_RED_G, ROD_COLOR_RED_B);

static const lv_color_t color_orange =
    LV_COLOR_MAKE(ROD_COLOR_ORANGE_R, ROD_COLOR_ORANGE_G, ROD_COLOR_ORANGE_B);

static const lv_color_t color_yellow =
    LV_COLOR_MAKE(ROD_COLOR_YELLOW_R, ROD_COLOR_YELLOW_G, ROD_COLOR_YELLOW_B);

static const lv_color_t color_green =
    LV_COLOR_MAKE(ROD_COLOR_GREEN_R, ROD_COLOR_GREEN_G, ROD_COLOR_GREEN_B);

static const lv_color_t color_blue =
    LV_COLOR_MAKE(ROD_COLOR_BLUE_R, ROD_COLOR_BLUE_G, ROD_COLOR_BLUE_B);

static const lv_color_t color_violet =
    LV_COLOR_MAKE(ROD_COLOR_VIOLET_R, ROD_COLOR_VIOLET_G, ROD_COLOR_VIOLET_B);

static const lv_color_t color_gray =
    LV_COLOR_MAKE(ROD_COLOR_GRAY_R, ROD_COLOR_GRAY_G, ROD_COLOR_GRAY_B);

static const ROD_Color_Table_Entry_t ROD_Color_Table[ROD_COLOR_COUNT] = {
    {
        ROD_COLOR_NONE,
        &color_none,
        "NONE",
    },
    {ROD_COLOR_WHITE, &color_white, "WHITE"},
    {ROD_COLOR_RED, &color_red, "RED"},
    {ROD_COLOR_ORANGE, &color_orange, "ORANGE"},
    {ROD_COLOR_YELLOW, &color_yellow, "YELLOW"},
    {ROD_COLOR_GREEN, &color_green, "GREEN"},
    {ROD_COLOR_BLUE, &color_blue, "BLUE"},
    {ROD_COLOR_VIOLET, &color_violet, "VIOLET"},
    {ROD_COLOR_GRAY, &color_gray, "GRAY"},
};

const ROD_Color_Table_Entry_t *ROD_Color_Find_Entry(ROD_Color_ID ROD_color_id) {
  if (ROD_color_id >= ROD_COLOR_COUNT) {
    return &ROD_Color_Table[ROD_COLOR_NONE];
  }
  return &ROD_Color_Table[ROD_color_id];
}

uint8_t ROD_Color_Get_Entry_Count(void) { return ROD_COLOR_COUNT; }