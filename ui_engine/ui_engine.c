#include "ui_engine.h"
#include "display_driver.h"
#include "esp_err.h"
#include "home.h"
#include "light.h"
#include "splash.h"

// QueueHandle_t ui_event_queue = NULL;

/* STATIC VARS */

static lv_obj_t *main_screen_obj;

/* PRIVATE PROTO */

void load_screen(UI_Screen_ID screen_id);

/* INTERFACE */

esp_err_t UI_Engine_Init(void) {
  // ui_event_queue = xQueueCreate(5, sizeof(Bridge_Event_t));

  esp_err_t err = Display_Driver_Init();
  if (err != ESP_OK) {
    return err;
  }

  lv_obj_t *main_screen = lv_obj_create(NULL);
  lv_obj_set_size(main_screen, 320, 240);
  lv_obj_set_style_bg_color(main_screen, lv_color_hex(0xf7ffff), 0);
  lv_screen_load(main_screen);

  main_screen_obj = main_screen;

  load_screen(UI_SCREEN_ID_HOME);

  return ESP_OK;
};

void UI_Engine_Navigate(UI_Screen_ID screen_id) { load_screen(screen_id); }

/* PRIVATE */

void load_screen(UI_Screen_ID screen_id) {
  lv_obj_t *old_container = lv_obj_get_child(main_screen_obj, 0);

  if (old_container != NULL) {
    lv_obj_delete_async(old_container);
  }

  lv_obj_t *new_container = lv_obj_create(main_screen_obj);

  switch (screen_id) {

  case UI_SCREEN_ID_HOME: {
    Render_Home(new_container);
    break;
  }

  case UI_SCREEN_ID_LIGHT: {
    Render_Light(new_container);
    break;
  }

  case UI_SCREEN_ID_SPLASH: {
    Render_Splash(new_container);
    break;
  }

  case UI_SCREEN_ID_COUNT:
    break;
  }
}