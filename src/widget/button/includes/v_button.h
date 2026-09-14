#ifndef __V_BUTTON_H_
#define __V_BUTTON_H_

#include "colors.h"
#include "lvgl.h"
#include "misc/lv_event.h"

typedef struct {
  Common_Color_ID color_id;
  const char *label;
  int32_t size;
  int32_t row;
  int32_t col;
} V_Button_Cfg_t;

typedef struct {
  lv_obj_t *lv_btn;
  lv_obj_t *lv_label;
} V_Button_t;

V_Button_t V_Button_Create(lv_obj_t *parent, const V_Button_Cfg_t *v_cfg);
void V_Button_Bind_LV_Event_CB(V_Button_t *v_btn, lv_event_cb_t lv_event_cb,
                               void *user_data);
void V_Button_Bind_Color_Obsever_CB(V_Button_t *v_btn,
                                    lv_subject_t *vm_color_subject);

#endif // __V_BUTTON_H_