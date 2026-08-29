#ifndef __INPUT_H_
#define __INPUT_H_

#include "lvgl.h"

typedef enum {
  INPUT_ID_NONE = 0,
  INPUT_ID_NAV_TO_LIGHT,
  INPUT_ID_SHOW_HEADLIGHT_CONTROL,
  INPUT_ID_SHOW_BODYLIGHT_CONTROL,
} Input_ID;

void Input_Handle_LV_Event(lv_event_t *lv_event);

#endif // __INPUT_H_