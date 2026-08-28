#ifndef __PRESENTER_COLOR_PICKER_H_
#define __PRESENTER_COLOR_PICKER_H_

#include "led_controller.h"
#include "model_color_picker.h"
#include "presenter_base.h"

typedef struct {
  Presenter_Base_t base;
  Model_Color_Picker_t *model;
  LED_Controller_Set_Strip_CB on_select_cb;
  void *on_select_ctx;
} Presenter_Color_Picker_t;

void Presenter_Color_Picker_Create(Presenter_Color_Picker_t *presenter,
                                   Model_Color_Picker_t *model,
                                   LED_Controller_Set_Strip_CB on_select_cb,
                                   void *on_select_ctx);
void Presenter_Color_Picker_Init(Presenter_Base_t *self);
void Presenter_Color_Picker_Select(Presenter_Color_Picker_t *presenter,
                                   Util_Color_ID color_id);

#endif // __PRESENTER_COLOR_PICKER_H_