#ifndef __DEFINITIONS_H_
#define __DEFINITIONS_H_

#include "lvgl.h"
#include <stdint.h>

/* SCREENS */

typedef enum {
  UI_SCREEN_ID_SPLASH = 0,
  UI_SCREEN_ID_HOME,
  UI_SCREEN_ID_LIGHT,
  UI_SCREEN_ID_COUNT,
} UI_Screen_ID;

typedef void (*ui_render_fn)(lv_obj_t *parent);

typedef struct ui_screen {
  UI_Screen_ID screen_id;
  ui_render_fn render_fn;
} UI_Screen_t;

/* INPUTS */

typedef enum {
  UI_INPUT_ID_COLOR_PICKER = 0,
} UI_Input_ID;

typedef struct ui_input {
  UI_Input_ID input_id;
  ui_render_fn render_fn;
} UI_Input_t;

/* ACTIONS */

typedef enum {
  UI_ACTION_ID_NAVIGATE,
  UI_ACTION_ID_SET_PROP,
  UI_ACTION_ID_COUNT,
} UI_Action_ID;

typedef struct {
  UI_Action_ID action_id;
  union {
    uint32_t screen_id;
    struct {
      uint32_t model_prop_id;
      uint32_t value;
    } model_prop_data;
  } payload;
} UI_Action_t;

#endif // __DEFINITIONS_H_