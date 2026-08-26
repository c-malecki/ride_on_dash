#include "navigator.h"
#include "esp_log.h"
#include "lvgl.h"
#include "ui_helpers.h"
//
#include "model_accessory.h"
#include "presenter_accessory.h"
#include "presenter_home.h"
#include "view_accessory.h"
#include "view_base.h"
#include "view_home.h"

static View_Base_t current_screen;

static Presenter_Home_t presenter_home;

static Model_Accessory_t model_accessory;
static Presenter_Accessory_t presenter_accessory;

void Navigator_Init(void) {
  Presenter_Home_Create(&presenter_home);
  Presenter_Home_Init(&presenter_home.base);

  Model_Accessory_Init(&model_accessory);
  Presenter_Accessory_Create(&presenter_accessory, &model_accessory);
  Presenter_Accessory_Init(&presenter_accessory.base);

  Navigator_Load_Screen(UI_SCREEN_ID_HOME);
}

void Navigator_Load_Screen(UI_Screen_ID screen_id) {
  ESP_LOGI("NAVIGATOR", "lv_obj_clean(lv_screen_active())");
  if (current_screen.destroy) {
    lv_obj_clean(lv_screen_active());
    // current_screen.destroy(&current_screen);
  }

  current_screen = (View_Base_t){.navigate = Navigator_Load_Screen};
  ESP_LOGI("NAVIGATOR", "current_screen = (View_Base_t)");

  switch (screen_id) {
  case UI_SCREEN_ID_HOME: {
    ESP_LOGI("NAVIGATOR", "nav to HOME");
    current_screen.ctx = &presenter_home;
    View_Home_Create(&current_screen, lv_screen_active());
    break;
  }

  case UI_SCREEN_ID_ACCESSORY: {
    ESP_LOGI("NAVIGATOR", "nav to ACCESSORY");
    current_screen.ctx = &presenter_accessory;
    View_Accessory_Create(&current_screen, lv_screen_active());
    break;
  }

  case UI_SCREEN_ID_NONE:

    break;
  }
}