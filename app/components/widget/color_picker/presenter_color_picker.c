#include "presenter_color_picker.h"
#include "model_color_picker.h"
#include "util.h"

void Presenter_Color_Picker_Create(Presenter_Color_Picker_t *presenter,
                                   Model_Color_Picker_t *model,
                                   Color_Picker_Select_Cb on_select_cb,
                                   void *on_select_ctx) {
  presenter->model = model;
  presenter->on_select_cb = on_select_cb;
  presenter->on_select_ctx = on_select_ctx;
  presenter->base.init = Presenter_Color_Picker_Init;
  presenter->base.model = model;
}

void Presenter_Color_Picker_Init(Presenter_Base_t *self) {
  Presenter_Color_Picker_t *presenter = (Presenter_Color_Picker_t *)self;
  Model_Color_Picker_Set_Color(presenter->model, APP_COLOR_NONE);
}

void Presenter_Color_Picker_Select(Presenter_Color_Picker_t *presenter,
                                   App_Color_ID color_id) {
  if (presenter->on_select_cb) {
    presenter->on_select_cb(presenter->on_select_ctx, color_id);
  }
  // optional: only needed if the picker itself
  // highlights the current selection
  // Model_Color_Picker_Set_Color(presenter->model, color_id);
}