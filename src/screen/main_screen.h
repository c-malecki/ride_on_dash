#ifndef __MAIN_SCREEN_H_
#define __MAIN_SCREEN_H_

#include "lvgl.h"
#include "screen_id.h"

typedef struct {
  Screen_ID cur_screen_id;
  lv_obj_t *main_screen_obj;
  lv_subject_t show_home_btn;
} Main_Screen_t;

typedef void(screen_render_fn)(lv_obj_t *container);

void Main_Screen_Init();
void Main_Screen_Render(Screen_ID screen_id);
// void Main_Screen_Render(screen_render_fn render_fn);

#endif // __MAIN_SCREEN_H_