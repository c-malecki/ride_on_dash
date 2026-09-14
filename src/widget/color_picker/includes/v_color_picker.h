#ifndef __V_COLOR_PICKER_H_
#define __V_COLOR_PICKER_H_

#include "colors.h"
#include "lvgl.h"

typedef void (*V_Color_Picker_CB)(Common_Color_ID color_id);

typedef struct {
  V_Color_Picker_CB on_select_cb;
} V_Color_Picker_Cfg_t;

typedef struct {
  lv_obj_t *lv_bm;
} V_Color_Picker_t;

V_Color_Picker_t V_Color_Picker_Create(lv_obj_t *parent,
                                       const V_Color_Picker_Cfg_t *v_cfg);

#endif // __V_COLOR_PICKER_H_