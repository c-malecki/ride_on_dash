#include "v_color_picker.h"

static V_Color_Picker_CB registered_color_picker_cb = NULL;

const char *color_picker_map[] = {"OFF", "W", "R", "O", "\n",
                                  "Y",   "G", "B", "V", ""};

static const Common_Color_ID picker_colors[8] = {
    COMMON_COLOR_NONE,   COMMON_COLOR_WHITE,  COMMON_COLOR_RED,
    COMMON_COLOR_ORANGE, COMMON_COLOR_YELLOW, COMMON_COLOR_GREEN,
    COMMON_COLOR_BLUE,   COMMON_COLOR_VIOLET,
};

static void value_select_event_cb(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_VALUE_CHANGED) {
    return;
  }

  lv_obj_t *bm = lv_event_get_target(lv_event);
  uint32_t idx = lv_buttonmatrix_get_selected_button(bm);
  Common_Color_ID color_id = picker_colors[idx];

  registered_color_picker_cb(color_id);
}

static void draw_cb(lv_event_t *lv_event) {
  lv_draw_task_t *draw_task = lv_event_get_draw_task(lv_event);
  lv_draw_dsc_base_t *draw_base = lv_draw_task_get_draw_dsc(draw_task);

  if (draw_base->part != LV_PART_ITEMS) {
    return;
  }
  // id1 should be the idx of the btn in the map
  if (draw_base->id1 >= COMMON_COLOR_COUNT) {
    return;
  }

  lv_draw_fill_dsc_t *fill = lv_draw_task_get_fill_dsc(draw_task);
  if (!fill) {
    return;
  }

  fill->color =
      *Common_Color_Find_Entry(picker_colors[draw_base->id1])->lv_color;
}

V_Color_Picker_t V_Color_Picker_Create(lv_obj_t *parent,
                                       const V_Color_Picker_Cfg_t *v_cfg) {
  lv_obj_t *button_matrix = lv_buttonmatrix_create(parent);
  lv_obj_set_size(button_matrix, 320, 240);
  lv_buttonmatrix_set_map(button_matrix, color_picker_map);

  lv_obj_set_style_text_opa(button_matrix, LV_OPA_TRANSP, LV_PART_ITEMS);
  lv_obj_set_style_border_width(button_matrix, 2, LV_PART_ITEMS);
  lv_obj_set_style_border_color(button_matrix, lv_color_black(), LV_PART_ITEMS);

  lv_obj_add_flag(button_matrix, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
  lv_obj_add_event_cb(button_matrix, draw_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
  lv_obj_add_event_cb(button_matrix, value_select_event_cb,
                      LV_EVENT_VALUE_CHANGED, NULL);

  V_Color_Picker_t v_color_picker = {
      .lv_bm = button_matrix,
  };

  registered_color_picker_cb = v_cfg->on_select_cb;

  return v_color_picker;
}