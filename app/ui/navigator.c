#include "navigator.h"
#include "led_controller.h"
#include "ui_helpers.h"
//
#include "model_accessory.h"
#include "model_color_picker.h"
#include "presenter_accessory.h"
#include "presenter_color_picker.h"
#include "presenter_home.h"
#include "view_accessory.h"
#include "view_base.h"
#include "view_color_picker.h"
#include "view_home.h"

static View_Base_t current_screen;

static Presenter_Home_t presenter_home;

static Model_Accessory_t model_accessory;
static Presenter_Accessory_t presenter_accessory;

static Model_Color_Picker_t model_color_picker;
static Presenter_Color_Picker_t presenter_color_picker;

void Navigator_Init(void) {
  Presenter_Home_Create(&presenter_home);
  Presenter_Home_Init(&presenter_home.base);

  Model_Accessory_Init(&model_accessory);
  Presenter_Accessory_Create(&presenter_accessory, &model_accessory);
  Presenter_Accessory_Init(&presenter_accessory.base);

  Model_Color_Picker_Init(&model_color_picker);
  Presenter_Color_Picker_Create(&presenter_color_picker, &model_color_picker,
                                LED_Controller_Binding_Set_Strip_CB(), NULL);
  Presenter_Color_Picker_Init(&presenter_color_picker.base);

  Navigator_Load_Screen(UI_SCREEN_ID_HOME);
}

void Navigator_Load_Screen(UI_Screen_ID screen_id) {
  if (current_screen.destroy) {
    current_screen.destroy(&current_screen);
  }

  current_screen = (View_Base_t){.navigate = Navigator_Load_Screen};

  switch (screen_id) {
  case UI_SCREEN_ID_HOME: {
    current_screen.ctx = &presenter_home;
    View_Home_Create(&current_screen, lv_screen_active());
    break;
  }

  case UI_SCREEN_ID_ACCESSORY: {
    current_screen.ctx = &presenter_accessory;
    View_Accessory_Create(&current_screen, lv_screen_active());
    break;
  }

  case UI_SCREEN_ID_COLOR_PICKER: {
    current_screen.ctx = &presenter_color_picker;
    View_Color_Picker_Create(&current_screen, lv_screen_active());
    break;
  }

  case UI_SCREEN_ID_NONE:

    break;
  }
}