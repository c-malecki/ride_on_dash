#ifndef __V_HOME_H_
#define __V_HOME_H_

#include "lvgl.h"
#include "screen_id.h"
#include "v_button.h"

typedef struct {
  Screen_ID screen_id;
  V_Button_t *light_nav_btn;
} V_Home_t;

void V_Home_Render(lv_obj_t *container);

#endif // __V_HOME_H_