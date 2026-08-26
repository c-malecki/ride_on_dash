#include "view_color_picker.h"
#include "presenter_color_picker.h"
#include "ui_helpers.h"
#include "util.h"

static void draw_cb(lv_event_t *lv_event);

static const App_Color_ID picker_colors[8] = {
    APP_COLOR_NONE,   APP_COLOR_WHITE, APP_COLOR_RED,  APP_COLOR_ORANGE,
    APP_COLOR_YELLOW, APP_COLOR_GREEN, APP_COLOR_BLUE, APP_COLOR_VIOLET,
};

static void color_picker_event_cb(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_CLICKED)
    return;

  lv_obj_t *bm = lv_event_get_target(lv_event);
  View_Base_t *self = lv_event_get_user_data(lv_event);
  Presenter_Color_Picker_t *presenter = (Presenter_Color_Picker_t *)self->ctx;

  uint32_t idx = lv_buttonmatrix_get_selected_button(bm);
  App_Color_ID color_id = picker_colors[idx];

  Presenter_Color_Picker_Select(presenter, color_id);
}

lv_obj_t *View_Color_Picker_Create(View_Base_t *self, lv_obj_t *parent) {
  // Presenter_Color_Picker_t *presenter = (Presenter_Color_Picker_t
  // *)self->ctx; Model_Color_Picker_t *model = presenter->model;

  static const char *map[10];

  map[0] = App_Color_Get_Entry(APP_COLOR_NONE)->label;
  map[1] = App_Color_Get_Entry(APP_COLOR_WHITE)->label;
  map[2] = App_Color_Get_Entry(APP_COLOR_RED)->label;
  map[3] = App_Color_Get_Entry(APP_COLOR_ORANGE)->label;
  map[4] = App_Color_Get_Entry(APP_COLOR_YELLOW)->label;
  map[5] = "\n";
  map[6] = App_Color_Get_Entry(APP_COLOR_GREEN)->label;
  map[7] = App_Color_Get_Entry(APP_COLOR_BLUE)->label;
  map[8] = App_Color_Get_Entry(APP_COLOR_VIOLET)->label;
  map[9] = "";

  lv_obj_t *bm = lv_buttonmatrix_create(parent);
  lv_obj_set_size(bm, 320, 240);
  lv_buttonmatrix_set_map(bm, map);

  lv_obj_set_style_text_opa(bm, LV_OPA_TRANSP, LV_PART_ITEMS);
  lv_obj_set_style_border_width(bm, 2, LV_PART_ITEMS);
  lv_obj_set_style_border_color(bm, lv_color_black(), LV_PART_ITEMS);

  lv_obj_add_flag(bm, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
  lv_obj_add_event_cb(bm, draw_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
  lv_obj_add_event_cb(bm, color_picker_event_cb, LV_EVENT_VALUE_CHANGED, self);
  // lv_obj_add_event_cb(bm, color_picker_event_cb, LV_EVENT_VALUE_CHANGED,
  // self);

  return bm;
}

static void draw_cb(lv_event_t *lv_event) {
  lv_draw_task_t *draw_task = lv_event_get_draw_task(lv_event);
  lv_draw_dsc_base_t *draw_base = lv_draw_task_get_draw_dsc(draw_task);

  if (draw_base->part != LV_PART_ITEMS) {
    return;
  }
  // id1 should be the idx of the btn in the map
  if (draw_base->id1 >= APP_COLOR_COUNT) {
    return;
  }

  lv_draw_fill_dsc_t *fill = lv_draw_task_get_fill_dsc(draw_task);
  if (!fill) {
    return;
  }

  fill->color =
      UI_Helper_Get_LV_Color(App_Color_Get_Entry(draw_base->id1)->color_id);
}