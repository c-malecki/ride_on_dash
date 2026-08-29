#include "ui_table.h"
#include "home.h"
#include "ui.h"

const UI_Element_t *ui_element_table[UI_SCREEN_ID_COUNT] = {
    [UI_SCREEN_ID_HOME] = &UI_Screen_Home,
};

const size_t ui_element_table_size =
    sizeof(ui_element_table) / sizeof(ui_element_table[0]);

const UI_Element_t *UI_Find_Element_By_Screen_ID(UI_Screen_ID screen_id) {
  if (screen_id >= UI_SCREEN_ID_COUNT || ui_element_table[screen_id] == NULL) {
    return NULL; // Or return a fallback/boot screen safely
  }
  return ui_element_table[screen_id];
}

uint8_t UI_Element_Get_Entry_Count(void) { return UI_SCREEN_ID_COUNT; }

////////////////
////////////////
////////////////
////////////////

// #include "presenter_home.h"

// static Presenter_Home_t presenter_home;

// void init() {
//   Presenter_Home_Create(&presenter_home);
//   Presenter_Home_Init(&presenter_home.base);

//   Model_Accessory_Init(&model_accessory);
//   Presenter_Accessory_Create(&presenter_accessory, &model_accessory);
//   Presenter_Accessory_Init(&presenter_accessory.base);

//   Model_Color_Picker_Init(&model_color_picker);
//   Presenter_Color_Picker_Create(&presenter_color_picker,
//   &model_color_picker,
// LED_Controller_Binding_Set_Strip_CB(),
//                                 NULL);
//   Presenter_Color_Picker_Init(&presenter_color_picker.base);
// }

// const UI_Element_t ui_screen_table[] = {
//     {
//         .screen_id = UI_SCREEN_ID_HOME,

//         // .render_fn = Home_Screen_Render,
//     },
// };

// const size_t ui_screen_table_size =
//     sizeof(ui_screen_table) / sizeof(ui_screen_table[0]);