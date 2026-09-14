#include "v_button.h"
#include "colors.h"
#include "core/lv_obj_event.h"
#include "misc/lv_event.h"

V_Button_t V_Button_Create(lv_obj_t *parent, const V_Button_Cfg_t *v_cfg) {
  // VM_Button_t vm = VM_Button_Create(vm_cfg);

  V_Button_t v_btn = {
      // .vm = &vm,
  };

  lv_obj_t *lv_btn = lv_button_create(parent);

  lv_obj_set_size(lv_btn, v_cfg->size, v_cfg->size);

  lv_obj_set_style_radius(lv_btn, 8, 0);
  lv_obj_set_style_border_width(lv_btn, 1, 0);
  lv_obj_set_style_border_color(lv_btn, lv_color_black(), 0);

  const lv_color_t *lv_color =
      Common_Color_Find_Entry(v_cfg->color_id)->lv_color;
  lv_obj_set_style_bg_color(lv_btn, *lv_color, 0);

  lv_obj_set_grid_cell(lv_btn, LV_GRID_ALIGN_CENTER, v_cfg->col, 1,
                       LV_GRID_ALIGN_CENTER, v_cfg->row, 1);

  if (v_cfg->label != NULL) {
    lv_obj_t *label = lv_label_create(lv_btn);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_28, 0);
    lv_label_set_text(label, v_cfg->label);
    lv_obj_set_style_align(label, LV_ALIGN_CENTER, 0);

    v_btn.lv_label = label;
  }

  v_btn.lv_btn = lv_btn;

  return v_btn;
}

void V_Button_Bind_LV_Event_CB(V_Button_t *v_btn, lv_event_cb_t lv_event_cb,
                               void *user_data) {
  lv_obj_add_event_cb(v_btn->lv_btn, lv_event_cb, LV_EVENT_CLICKED, user_data);
}

/* */

static void color_observer_cb(lv_observer_t *observer, lv_subject_t *subject) {
  lv_obj_t *btn = lv_observer_get_target(observer);
  lv_obj_set_style_bg_color(btn, lv_subject_get_color(subject), 0);
}

void V_Button_Bind_Color_Obsever_CB(V_Button_t *v_btn,
                                    lv_subject_t *vm_color_subject) {
  lv_subject_add_observer_obj(vm_color_subject, color_observer_cb,
                              v_btn->lv_btn, NULL);
}