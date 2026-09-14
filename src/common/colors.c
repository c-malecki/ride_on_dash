#include "colors.h"

static const lv_color_t color_none = LV_COLOR_MAKE(
    COMMON_COLOR_NONE_R, COMMON_COLOR_NONE_G, COMMON_COLOR_NONE_B);

static const lv_color_t color_white = LV_COLOR_MAKE(
    COMMON_COLOR_WHITE_R, COMMON_COLOR_WHITE_G, COMMON_COLOR_WHITE_B);

static const lv_color_t color_red =
    LV_COLOR_MAKE(COMMON_COLOR_RED_R, COMMON_COLOR_RED_G, COMMON_COLOR_RED_B);

static const lv_color_t color_orange = LV_COLOR_MAKE(
    COMMON_COLOR_ORANGE_R, COMMON_COLOR_ORANGE_G, COMMON_COLOR_ORANGE_B);

static const lv_color_t color_yellow = LV_COLOR_MAKE(
    COMMON_COLOR_YELLOW_R, COMMON_COLOR_YELLOW_G, COMMON_COLOR_YELLOW_B);

static const lv_color_t color_green = LV_COLOR_MAKE(
    COMMON_COLOR_GREEN_R, COMMON_COLOR_GREEN_G, COMMON_COLOR_GREEN_B);

static const lv_color_t color_blue = LV_COLOR_MAKE(
    COMMON_COLOR_BLUE_R, COMMON_COLOR_BLUE_G, COMMON_COLOR_BLUE_B);

static const lv_color_t color_violet = LV_COLOR_MAKE(
    COMMON_COLOR_VIOLET_R, COMMON_COLOR_VIOLET_G, COMMON_COLOR_VIOLET_B);

static const lv_color_t color_gray = LV_COLOR_MAKE(
    COMMON_COLOR_GRAY_R, COMMON_COLOR_GRAY_G, COMMON_COLOR_GRAY_B);

static const Common_Color_Table_Entry_t COMMON_COLOR_Table[COMMON_COLOR_COUNT] =
    {
        {
            COMMON_COLOR_NONE,
            &color_none,
            "NONE",
        },
        {COMMON_COLOR_WHITE, &color_white, "WHITE"},
        {COMMON_COLOR_RED, &color_red, "RED"},
        {COMMON_COLOR_ORANGE, &color_orange, "ORANGE"},
        {COMMON_COLOR_YELLOW, &color_yellow, "YELLOW"},
        {COMMON_COLOR_GREEN, &color_green, "GREEN"},
        {COMMON_COLOR_BLUE, &color_blue, "BLUE"},
        {COMMON_COLOR_VIOLET, &color_violet, "VIOLET"},
        {COMMON_COLOR_GRAY, &color_gray, "GRAY"},
};

const Common_Color_Table_Entry_t *
Common_Color_Find_Entry(Common_Color_ID Common_Color_ID) {
  if (Common_Color_ID >= COMMON_COLOR_COUNT) {
    return &COMMON_COLOR_Table[COMMON_COLOR_NONE];
  }
  return &COMMON_COLOR_Table[Common_Color_ID];
}

uint8_t Common_Color_Get_Entry_Count(void) { return COMMON_COLOR_COUNT; }