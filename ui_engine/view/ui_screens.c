#include "ui_screens.h"
#include "home.h"
#include "light.h"
#include "splash.h"

const UI_Screen_t *ui_screen_table[UI_SCREEN_ID_COUNT] = {
    [UI_SCREEN_ID_SPLASH] = &UI_Screen_Splash,
    [UI_SCREEN_ID_HOME] = &UI_Screen_Home,
    [UI_SCREEN_ID_LIGHT] = &UI_Screen_Light,
};

const size_t ui_screen_table_size =
    sizeof(ui_screen_table) / sizeof(ui_screen_table[0]);

const UI_Screen_t *UI_Screens_Find_By_ID(UI_Screen_ID screen_id) {
  if (screen_id >= UI_SCREEN_ID_COUNT || ui_screen_table[screen_id] == NULL) {
    return ui_screen_table[UI_SCREEN_ID_SPLASH];
  }
  return ui_screen_table[screen_id];
}

uint8_t UI_Screens_Get_Entry_Count(void) { return UI_SCREEN_ID_COUNT; }