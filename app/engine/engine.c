#include "engine.h"
#include "ui.h"

static UI_View_Base_t current_screen;

void UI_Engine_Init(void) { UI_Engine_Load_Screen(UI_SCREEN_ID_HOME); }

void UI_Engine_Load_Screen(UI_Screen_ID screen_id) {
  if (current_screen.destroy) {
    current_screen.destroy(&current_screen);
  }

  current_screen = (UI_View_Base_t){.navigate = UI_Engine_Load_Screen};

  // switch (screen_id) {
  // case UI_SCREEN_ID_HOME: {
  //   current_screen.ctx = &presenter_home;
  //   View_Home_Create(&current_screen, lv_screen_active());
  //   break;
  // }

  // case UI_SCREEN_ID_ACCESSORY: {
  //   current_screen.ctx = &presenter_accessory;
  //   View_Accessory_Create(&current_screen, lv_screen_active());
  //   break;
  // }

  // case UI_SCREEN_ID_COLOR_PICKER: {
  //   current_screen.ctx = &presenter_color_picker;
  //   View_Color_Picker_Create(&current_screen, lv_screen_active());
  //   break;
  // }

  // case UI_SCREEN_ID_NONE:

  //   break;
  // }
}