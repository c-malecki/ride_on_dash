#include "input.h"
#include "ui_definitions.h"

void Input_Handle_LV_Event(lv_event_t *lv_event) {
  Input_ID *input_id = (Input_ID *)lv_event_get_user_data(lv_event);

  if (input_id == NULL)
    return;

  switch (*input_id) {

  case INPUT_ID_NAV_TO_LIGHT: {
    // UI_Engine_Load_Screen(UI_Screen_ID screen_id) break;
  }

  case INPUT_ID_SHOW_HEADLIGHT_CONTROL: {

    break;
  }

  case INPUT_ID_SHOW_BODYLIGHT_CONTROL: {

    break;
  }

    // case INPUT_ID_LIGHT_CONTROL_SELECT: {   // bridge binding }

  case INPUT_ID_NONE:
    break;
  }
}