#include "presenter_accessory.h"
#include "led_driver.h"
#include "model_accessory.h"
#include "util.h"

static void led_headlight_observer_cb(lv_observer_t *observer,
                                      lv_subject_t *subject) {
  Util_Color_ID color_id = (Util_Color_ID)lv_subject_get_int(subject);
  LED_Set_Strip_Color(LED_STRIP_HEADLIGHTS, color_id);
}

static void led_bodylight_observer_cb(lv_observer_t *observer,
                                      lv_subject_t *subject) {
  Util_Color_ID color_id = (Util_Color_ID)lv_subject_get_int(subject);
  LED_Set_Strip_Color(LED_STRIP_BODYLIGHTS, color_id);
}

void Presenter_Accessory_Create(Presenter_Accessory_t *presenter,
                                Model_Accessory_t *model) {
  presenter->model = model;
  presenter->base.init = Presenter_Accessory_Init;
  presenter->base.model = model;
}

void Presenter_Accessory_Init(Presenter_Base_t *self) {
  Presenter_Accessory_t *presenter = (Presenter_Accessory_t *)self;

  // hypothetical example
  // Util_Color_ID saved_headlight_color_id;
  // if (storage_service_get_uint32("headlight_color",
  // &saved_headlight_color_id) == OK) {
  // Model_Accessory_Set_Btn_Color_Headlights(presenter->model,
  // saved_headlight_color_id);
  // }

  // hardware observers
  lv_subject_add_observer(&presenter->model->btn_headlights_color,
                          led_headlight_observer_cb, NULL);

  lv_subject_add_observer(&presenter->model->btn_bodylights_color,
                          led_bodylight_observer_cb, NULL);

  Model_Accessory_Set_Btn_Color_Headlights(presenter->model, UTIL_COLOR_NONE);
  Model_Accessory_Set_Btn_Color_Bodylights(presenter->model, UTIL_COLOR_NONE);
}