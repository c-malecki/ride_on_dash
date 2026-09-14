#include "main_screen.h"
#include "colors.h"
#include "esp_log.h"
#include "screen_id.h"
#include "v_home.h"
#include "v_light.h"

static Main_Screen_t main_screen;

/* */

static void load_screen(Screen_ID screen_id);
static void home_btn_cb(lv_event_t *lv_event);

/* INTERFACE */

void Main_Screen_Init() {
  lv_obj_t *screen_obj = lv_obj_create(NULL);
  lv_obj_set_size(screen_obj, 320, 240);
  lv_obj_set_style_bg_color(screen_obj, lv_color_hex(0xf7ffff), 0);
  lv_screen_load(screen_obj);

  main_screen.main_screen_obj = screen_obj;

  // init system top layer
  lv_obj_t *home_btn = lv_button_create(lv_layer_top());
  lv_obj_set_size(home_btn, 40, 40);
  lv_obj_set_style_radius(home_btn, 4, 0);
  lv_obj_set_style_border_width(home_btn, 1, 0);
  lv_obj_set_style_border_color(home_btn, lv_color_black(), 0);
  lv_obj_set_pos(home_btn, 10, 10);
  lv_obj_add_event_cb(home_btn, home_btn_cb, LV_EVENT_CLICKED, NULL);

  const lv_color_t *color =
      Common_Color_Find_Entry(COMMON_COLOR_GRAY)->lv_color;
  lv_obj_set_style_bg_color(home_btn, *color, 0);

  lv_obj_t *label = lv_label_create(home_btn);
  lv_obj_set_style_text_font(label, &lv_font_montserrat_14, 0);
  lv_label_set_text(label, LV_SYMBOL_HOME);
  lv_obj_set_style_align(label, LV_ALIGN_CENTER, 0);

  lv_subject_init_int(&main_screen.show_home_btn, 0);
  lv_obj_bind_flag_if_eq(home_btn, &main_screen.show_home_btn,
                         LV_OBJ_FLAG_HIDDEN, 0);

  load_screen(SCREEN_ID_HOME);
}

void Main_Screen_Render(Screen_ID screen_id) { load_screen(screen_id); }

/* PRIVATE */

static void load_screen(Screen_ID screen_id) {
  lv_obj_t *old_container = lv_obj_get_child(main_screen.main_screen_obj, 0);

  if (old_container != NULL) {
    lv_obj_delete_async(old_container);
  }

  lv_obj_t *new_container = lv_obj_create(main_screen.main_screen_obj);

  lv_subject_set_int(&main_screen.show_home_btn,
                     screen_id == SCREEN_ID_HOME ? 0 : 1);
  main_screen.cur_screen_id = screen_id;

  switch (screen_id) {

  case SCREEN_ID_HOME: {
    V_Home_Render(new_container);
    break;
  }

  case SCREEN_ID_LIGHT: {
    V_Light_Render(new_container);
    break;
  }

  case SCREEN_ID_SPLASH: {

    break;
  }

  case SCREEN_ID_COUNT:
    break;
  }
}

static void home_btn_cb(lv_event_t *lv_event) {
  lv_event_code_t code = lv_event_get_code(lv_event);
  if (code != LV_EVENT_CLICKED) {
    return;
  }

  Main_Screen_Render(SCREEN_ID_HOME);
}
