#ifndef __VM_BUTTON_H_
#define __VM_BUTTON_H_

#include "colors.h"
#include "lvgl.h"

typedef struct {
  Common_Color_ID color_id;
  const char *label;
  int32_t size;
  int32_t row;
  int32_t col;
  void *vm_ctx;
} VM_Button_Cfg_t;

typedef struct {
  lv_color_t color;
  const char *label;
  int32_t size;
  int32_t row;
  int32_t col;
  void (*on_change_system_cb)(void *ctx);
  void *ctx;
} VM_Button_t;

VM_Button_t VM_Button_Create(const VM_Button_Cfg_t *cfg);

void VM_Button_Bind_Color_Obsever_CB(lv_subject_t *vm_color_subject);

#endif // __VM_BUTTON_H_