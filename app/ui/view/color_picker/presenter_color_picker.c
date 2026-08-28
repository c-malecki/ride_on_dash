#include "presenter_color_picker.h"
// #include "esp_log.h"
#include "_color.h"
#include "model_color_picker.h"

void Presenter_Color_Picker_Create(Presenter_Color_Picker_t *presenter,
                                   Model_Color_Picker_t *model,
                                   //  LED_Controller_Set_Strip_CB on_select_cb,
                                   void *on_select_ctx) {
  presenter->model = model;
  // presenter->on_select_cb = on_select_cb;
  presenter->on_select_ctx = on_select_ctx;
  presenter->base.init = Presenter_Color_Picker_Init;
  presenter->base.model = model;
}

void Presenter_Color_Picker_Init(Presenter_Base_t *self) {
  Presenter_Color_Picker_t *presenter = (Presenter_Color_Picker_t *)self;
  Model_Color_Picker_Set_Selected_Color(presenter->model, COLOR_NONE);
}

void Presenter_Color_Picker_Select(Presenter_Color_Picker_t *presenter,
                                   Color_ID color_id) {
  // if (presenter->on_select_cb) {
  // typedef void (*LED_Controller_Set_Strip_CB)(LED_Strip_ID, Color_ID)
  //   ESP_LOGI("PRESENTER_COLOR_PICKER", "deref presenter->on_select_ctx");
  //   LED_Strip_ID strip_id = *((LED_Strip_ID *)presenter->on_select_ctx);
  //   presenter->on_select_cb(strip_id, color_id);
  // }
  // optional: only needed if the picker itself
  // highlights the current selection
  // Model_Color_Picker_Set_Selected_Color(presenter->model, color_id);
}