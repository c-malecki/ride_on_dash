#include "v_light.h"
#include "colors.h"
#include "esp_log.h"
#include "layout.h"
#include "vm_light.h"
#include <stdint.h>

static void handle_color_picker(Common_Color_ID color_id);

/* Local State */

static V_Light_t v_light = {SCREEN_ID_LIGHT, NULL, NULL, NULL, NULL};

static const VM_Light_Cfg_t vm_light_cfg = {
    VM_LIGHT_NONE,
    COMMON_COLOR_NONE,
    COMMON_COLOR_NONE,
};

const V_Button_Cfg_t headlight_btn_cfg = {
    .color_id = COMMON_COLOR_GRAY,
    .label = LV_SYMBOL_LEFT,
    .size = 70,
    .row = 0,
    .col = 0,
};

const V_Button_Cfg_t bodylight_btn_cfg = {
    .color_id = COMMON_COLOR_GRAY,
    .label = LV_SYMBOL_POWER,
    .size = 70,
    .row = 0,
    .col = 1,
};

const V_Color_Picker_Cfg_t color_picker_cfg = {
    .on_select_cb = handle_color_picker,
};

/* Events */

static void handle_color_picker(Common_Color_ID color_id) {
  VM_Light_Set_Selected_Light_Color(v_light.vm, color_id);
}

static void screen_light_select_event(lv_event_t *lv_event) {
  ESP_LOGI("v_light", "screen_light_select_event");
  VM_Light_Selection selected_light =
      (VM_Light_Selection)(uintptr_t)lv_event_get_user_data(lv_event);
  VM_Light_Set_Show_Color_Picker(v_light.vm, 1);
  VM_Light_Set_Selected_Light(v_light.vm, selected_light);
}

/* Observers */

// static void set_show_color_picker_observer(lv_observer_t *observer,
// lv_subject_t *subject) {

// }

/* Interface */

void V_Light_Render(lv_obj_t *container) {
  ESP_LOGI("v_light", "V_Light_Render");

  Common_Layout_Grid(container, COMMON_LAYOUT_GRID_2x1);

  static VM_Light_t vm_light;
  VM_Light_Init(&vm_light, &vm_light_cfg);
  v_light.vm = &vm_light;

  // top layer
  V_Color_Picker_t color_picker =
      V_Color_Picker_Create(lv_layer_top(), &color_picker_cfg);
  v_light.color_picker = &color_picker;
  VM_Light_Bind_Color_Picker(v_light.vm, color_picker.lv_bm);

  // left side
  V_Button_t v_btn_headlight = V_Button_Create(container, &headlight_btn_cfg);
  v_light.headlight_btn = &v_btn_headlight;
  V_Button_Bind_LV_Event_CB(v_light.headlight_btn, screen_light_select_event,
                            (void *)VM_LIGHT_HEADLIGHT);
  V_Button_Bind_Color_Obsever_CB(v_light.headlight_btn,
                                 &v_light.vm->headlight_color);

  // right side
  V_Button_t v_btn_bodylight = V_Button_Create(container, &bodylight_btn_cfg);
  v_light.bodylight_btn = &v_btn_bodylight;
  V_Button_Bind_LV_Event_CB(v_light.bodylight_btn, screen_light_select_event,
                            (void *)VM_LIGHT_BODYLIGHT);
  V_Button_Bind_Color_Obsever_CB(v_light.bodylight_btn,
                                 &v_light.vm->bodylight_color);
}
