#ifndef __VIEW_BASE_H_
#define __VIEW_BASE_H_

#include "ui_helpers.h"

struct view_base;

typedef void (*view_create_fn)(struct view_base *self, lv_obj_t *parent);
typedef void (*view_destroy_fn)(struct view_base *self);
typedef void (*navigator_cb)(UI_Screen_ID screen_id);

typedef struct view_base {
  view_create_fn create;
  view_destroy_fn destroy;
  navigator_cb navigate; // set by Navigator_Load_Screen
  void *ctx;             // presenter or view-owned data, cast by implementer
} View_Base_t;

#endif // __VIEW_BASE_H_