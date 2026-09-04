#include "ui_engine.h"
#include "binding.h"
#include "display_driver.h"
#include "esp_err.h"
#include "model.h"
#include "ui_screens.h"

QueueHandle_t ui_event_queue = NULL;

/* STATIC VARS */

static UI_Model_t ui_model;

/* FORWARD PROTO DEP */

void load_screen(UI_Screen_ID screen_id);

/* INTERFACE */

esp_err_t UI_Engine_Init(void) {
  ui_event_queue = xQueueCreate(5, sizeof(Bridge_Event_t));

  esp_err_t err = Display_Driver_Init();
  if (err != ESP_OK) {
    return err;
  }

  lv_obj_t *main_screen = lv_obj_create(NULL);
  lv_obj_set_size(main_screen, 320, 240);
  lv_obj_set_style_bg_color(main_screen, lv_color_hex(0xf7ffff), 0);
  lv_screen_load(main_screen);

  UI_Model_Init(&ui_model);
  ui_model.main_screen_obj = main_screen;

  load_screen(UI_SCREEN_ID_HOME);

  return ESP_OK;
};

void UI_Engine_Event_Consume(Bridge_Event_t bridge_event) {
  switch (bridge_event.app_binding_id) {

  case BINDING_APP_SET_LED_UI_COLOR: {
    // TODO: UI model binding
    break;
  }

  case BINDING_APP_NONE:
    break;
  }
}

void load_screen(UI_Screen_ID screen_id) {
  lv_obj_t *old_container = lv_obj_get_child(ui_model.main_screen_obj, 0);

  if (old_container != NULL) {
    lv_obj_delete_async(old_container);
  }

  lv_obj_t *new_container = lv_obj_create(ui_model.main_screen_obj);

  const UI_Screen_t *screen = UI_Screens_Find_By_ID(screen_id);

  if (screen->render_fn != NULL) {
    screen->render_fn(new_container);
  }
}
