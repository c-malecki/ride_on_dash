#include "button_base.h"
#include "style.h"

void UI_Button_Base_Apply(lv_obj_t *btn,
                          const UI_Button_Base_Config_t *config) {
  lv_obj_set_size(btn, 70, 70);
  lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_CENTER, config->col, 1,
                       LV_GRID_ALIGN_CENTER, config->row, 1);

  const lv_color_t *color = UI_Color_Table_Find_By_ID(config->color);
  lv_obj_set_style_bg_color(btn, *color, 0);

  if (config->label != NULL) {
    lv_obj_t *label = lv_label_create(btn);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_28, 0);
    lv_label_set_text(label, config->label);
    lv_obj_set_style_align(label, LV_ALIGN_CENTER, 0);
  }
}