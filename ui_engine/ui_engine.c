#include "ui_engine.h"
#include "_lvgl.h"
#include "colors.h"
#include "esp_err.h"
#include "home.h"
#include "light.h"
#include "splash.h"

// QueueHandle_t ui_event_queue = NULL;

/* STATIC VARS */

static lv_obj_t *main_screen_obj;
static lv_subject_t show_home_btn;

/* PRIVATE PROTO */

void load_screen(UI_Screen_ID screen_id);
static void home_btn_cb(lv_event_t *lv_event);

/* INTERFACE */

esp_err_t UI_ENGINE_Init(esp_lcd_panel_io_handle_t io_handle,
                         esp_lcd_panel_handle_t panel_handle,
                         esp_lcd_touch_handle_t touch_handle) {
  // ui_event_queue = xQueueCreate(5, sizeof(Bridge_Event_t));

  LVGL_Init(io_handle, panel_handle, touch_handle);

  lv_obj_t *main_screen = lv_obj_create(NULL);
  lv_obj_set_size(main_screen, 320, 240);
  lv_obj_set_style_bg_color(main_screen, lv_color_hex(0xf7ffff), 0);
  lv_screen_load(main_screen);

  main_screen_obj = main_screen;

  lv_obj_t *home_btn = lv_button_create(lv_layer_top());
  lv_obj_set_size(home_btn, 40, 40);
  lv_obj_set_style_radius(home_btn, 4, 0);
  lv_obj_set_style_border_width(home_btn, 1, 0);
  lv_obj_set_style_border_color(home_btn, lv_color_black(), 0);
  lv_obj_set_pos(home_btn, 10, 10);
  lv_obj_add_event_cb(home_btn, home_btn_cb, LV_EVENT_CLICKED, NULL);

  const lv_color_t *color = ROD_Color_Find_Entry(ROD_COLOR_GRAY)->color;
  lv_obj_set_style_bg_color(home_btn, *color, 0);

  lv_obj_t *label = lv_label_create(home_btn);
  lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
  lv_label_set_text(label, LV_SYMBOL_HOME);
  lv_obj_set_style_align(label, LV_ALIGN_CENTER, 0);

  lv_subject_init_int(&show_home_btn, 0);
  lv_obj_bind_flag_if_eq(home_btn, &show_home_btn, LV_OBJ_FLAG_HIDDEN, 0);

  load_screen(UI_SCREEN_ID_HOME);

  return ESP_OK;
};

void UI_ENGINE_Navigate(UI_Screen_ID screen_id) {
  lv_subject_set_int(&show_home_btn, screen_id == UI_SCREEN_ID_HOME ? 0 : 1);
  load_screen(screen_id);
}

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

static void home_btn_cb(lv_event_t *lv_event) {
  lv_event_code_t code = lv_event_get_code(lv_event);
  if (code != LV_EVENT_CLICKED) {
    return;
  }

  UI_ENGINE_Navigate(UI_SCREEN_ID_HOME);
}