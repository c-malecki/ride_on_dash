#include "color_picker.h"
#include "_color.h"
#include "core/lv_obj_style_gen.h"
#include "style.h"
#include "widgets/buttonmatrix/lv_buttonmatrix.h"

/* Local State */

static color_picker_cb registered_color_picker_cb = NULL;

static const Color_ID picker_colors[8] = {
    COLOR_NONE,   COLOR_WHITE, COLOR_RED,  COLOR_ORANGE,
    COLOR_YELLOW, COLOR_GREEN, COLOR_BLUE, COLOR_VIOLET,
};

static void value_select_event_cb(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_VALUE_CHANGED) {
    return;
  }

  lv_obj_t *bm = lv_event_get_target(lv_event);
  uint32_t idx = lv_buttonmatrix_get_selected_button(bm);
  Color_ID color_id = picker_colors[idx];

  registered_color_picker_cb(color_id);
}

static void draw_cb(lv_event_t *lv_event) {
  lv_draw_task_t *draw_task = lv_event_get_draw_task(lv_event);
  lv_draw_dsc_base_t *draw_base = lv_draw_task_get_draw_dsc(draw_task);

  if (draw_base->part != LV_PART_ITEMS) {
    return;
  }
  // id1 should be the idx of the btn in the map
  if (draw_base->id1 >= COLOR_COUNT) {
    return;
  }

  lv_draw_fill_dsc_t *fill = lv_draw_task_get_fill_dsc(draw_task);
  if (!fill) {
    return;
  }

  fill->color = *UI_Color_Table_Find_By_ID(
      CFG_Color_Find_Entry(draw_base->id1)->color_id);
}

const char *color_picker_map[] = {"OFF", "W", "R", "O", "\n",
                                  "Y",   "G", "B", "V", ""};

void UI_Color_Picker_Apply(lv_obj_t *button_matrix,
                           const UI_Color_Picker_Config_t *config) {
  registered_color_picker_cb = config->color_picker_cb;

  lv_obj_set_size(button_matrix, 320, 240);
  lv_buttonmatrix_set_map(button_matrix, color_picker_map);

  lv_obj_set_style_text_opa(button_matrix, LV_OPA_TRANSP, LV_PART_ITEMS);
  lv_obj_set_style_border_width(button_matrix, 2, LV_PART_ITEMS);
  lv_obj_set_style_border_color(button_matrix, lv_color_black(), LV_PART_ITEMS);

  lv_obj_add_flag(button_matrix, LV_OBJ_FLAG_SEND_DRAW_TASK_EVENTS);
  lv_obj_add_event_cb(button_matrix, draw_cb, LV_EVENT_DRAW_TASK_ADDED, NULL);
  lv_obj_add_event_cb(button_matrix, value_select_event_cb,
                      LV_EVENT_VALUE_CHANGED, NULL);
}

/*


static void color_picker_select_event_cb(lv_event_t *lv_event) {
  if (lv_event_get_code(lv_event) != LV_EVENT_CLICKED)
    return;

  // lv_obj_t *bm = lv_event_get_target(lv_event);
  // UI_View_Base_t *self = lv_event_get_user_data(lv_event);
  // Presenter_Color_Picker_t *presenter = (Presenter_Color_Picker_t
  // *)self->ctx;

  // uint32_t idx = lv_buttonmatrix_get_selected_button(bm);
  // Color_ID color_id = picker_colors[idx];

  // handles communicating to hardware system controllers
  // Presenter_Color_Picker_Select(presenter, color_id);
}



*/