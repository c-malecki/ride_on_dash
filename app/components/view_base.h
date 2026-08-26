#ifndef __VIEW_BASE_H_
#define __VIEW_BASE_H_

#include "lvgl.h"
#include "presenter_base.h"
#include "ui_helpers.h"
#include <stdint.h>

typedef void (*navigator_cb)(UI_Screen_ID screen_id);

typedef struct view_base {
  void (*create)(struct view_base *self, lv_obj_t *parent);
  void (*destroy)(struct view_base *self);
  navigator_cb navigate; // set by Navigator_Load_Screen
  void *ctx;             // presenter or view-owned data, cast by implementer
} View_Base_t;

#endif // __VIEW_BASE_H_