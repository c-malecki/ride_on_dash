#ifndef __UI_IDS_H_
#define __UI_IDS_H_

#include "lvgl.h"

typedef enum {
  UI_INPUT_ID_NONE = 0,
  UI_INPUT_ID_NAV_TO_LIGHT,
  UI_INPUT_ID_SHOW_HEADLIGHT_CONTROL,
  UI_INPUT_ID_SHOW_BODYLIGHT_CONTROL,
} UI_Input_ID;

typedef enum {
  UI_MODEL_PROP_ID_NONE = 0,
  UI_MODEL_PROP_ID_HEADLIGHT_COLOR_ID,
  UI_MODEL_PROP_ID_BODYLIGHT_COLOR_ID,
  UI_MODEL_PROP_ID_COUNT,
} UI_Model_Prop_ID;

typedef enum {
  UI_SCREEN_ID_SPLASH = 0,
  UI_SCREEN_ID_HOME,
  UI_SCREEN_ID_LIGHT,
  UI_SCREEN_ID_COUNT,
} UI_Screen_ID;

typedef void (*ui_screen_render_fn)(lv_obj_t *parent);

typedef struct ui_screen {
  UI_Screen_ID screen_id;
  ui_screen_render_fn render_fn;
} UI_Screen_t;
#endif // __UI_IDS_H_