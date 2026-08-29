#include "engine.h"
#include "input.h"
#include "model.h"
#include "ui_screens.h"

/*

void UI_Model_Set_Prop(UI_Model_t *model, UI_Model_Prop_ID prop_id,
                       uint32_t value)

*/

static UI_Model_t ui_model;

void UI_Engine_Init(void) {
  UI_Model_Init(&ui_model);

  UI_Engine_Load_Screen(UI_SCREEN_ID_HOME);
}

void UI_Engine_Load_Screen(UI_Screen_ID screen_id) {
  if (ui_model.main_screen_obj != NULL) {
    lv_obj_delete(ui_model.main_screen_obj);
  }

  const UI_Screen_t *screen = UI_Screens_Find_By_ID(screen_id);

  if (screen->render_fn != NULL) {
    screen->render_fn(ui_model.main_screen_obj);
  }
}