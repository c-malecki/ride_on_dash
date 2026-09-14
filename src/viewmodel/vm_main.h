#ifndef __VM_MAIN_H_
#define __VM_MAIN_H_

#include "lvgl.h"
#include "misc/lv_types.h"

typedef struct {
  lv_obj_t *main_car_screen;
  lv_subject_t current_screen_id;
  lv_subject_t show_home_btn;
} VM_Main_t;

void VM_Main_Init(void);

// typedef enum {
//   CAR_SCREEN_ID_SPLASH = 0,
//   CAR_SCREEN_ID_HOME,
//   CAR_SCREEN_ID_LIGHT,
//   CAR_SCREEN_ID_COUNT,
// } Car_Screen_ID;

// void Car_Screen_Navigate(Car_Screen_ID screen_id);

#endif // __VM_MAIN_H_