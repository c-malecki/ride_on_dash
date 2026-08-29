#ifndef __UI_H_
#define __UI_H_

#include "lvgl.h"
#include <stddef.h>

struct view_base;

typedef enum {
  UI_SCREEN_ID_NONE = 0,
  UI_SCREEN_ID_HOME,
  UI_SCREEN_ID_ACCESSORY,
  UI_SCREEN_ID_COLOR_PICKER,
  UI_SCREEN_ID_COUNT,
} UI_Screen_ID;

typedef void (*view_create_fn)(struct view_base *self, lv_obj_t *parent);
typedef void (*view_destroy_fn)(struct view_base *self);
typedef void (*engine_navigate_cb)(UI_Screen_ID screen_id);
typedef void (*screen_render_fn)(lv_obj_t *screen);
typedef void (*ui_element_render_fn)(lv_obj_t *parent);

typedef struct view_base {
  view_create_fn create;
  view_destroy_fn destroy;
  engine_navigate_cb
      navigate; // set in UI_Engine_Load_Screen in app/engine/engine.c
  void *ctx;    // presenter or view-owned data, cast by implementer
} UI_View_Base_t;

typedef struct presenter_base {
  void (*init)(struct presenter_base *self);
  void (*destroy)(struct presenter_base *self);
  void *view;  // pointer to owning view
  void *model; // pointer to owning model(s)
} UI_Presenter_Base_t;

typedef struct ui_element {
  UI_Screen_ID screen_id;
  // UI_View_Base_t view_base;
  // UI_Presenter_Base_t presenter_base;
  // lv_obj_t *lv_obj;
  ui_element_render_fn render_fn;
} UI_Element_t;

#endif // __UI_H_