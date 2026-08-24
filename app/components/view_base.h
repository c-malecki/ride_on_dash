#ifndef __VIEW_BASE_H_
#define __VIEW_BASE_H_

#include "lvgl.h"

typedef struct view_base {
  void (*create)(struct view_base *self, lv_obj_t *parent);
  void (*destroy)(struct view_base *self);
  void *ctx; // presenter or view-owned data, cast by implementer
} View_Base_t;

#endif // __VIEW_BASE_H_