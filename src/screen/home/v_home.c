#include "v_home.h"
#include "colors.h"
#include "esp_log.h"
#include "layout.h"
#include "main_screen.h"
#include "screen_id.h"
#include "v_button.h"
#include <stdint.h>

const V_Button_Cfg_t light_btn_cfg = {
    .color_id = COMMON_COLOR_GRAY,
    .label = LV_SYMBOL_POWER,
    .size = 70,
    .row = 0,
    .col = 0,
};

/* Local State */

static V_Home_t v_home = {SCREEN_ID_HOME, NULL};

/* Events */

static void home_navigate_touch(lv_event_t *lv_event) {
  Screen_ID screen_id = (Screen_ID)(uintptr_t)lv_event_get_user_data(lv_event);
  Main_Screen_Render(screen_id);
}

/* Render */

void V_Home_Render(lv_obj_t *container) {
  ESP_LOGI("v_home", "V_Home_Render");

  Common_Layout_Grid(container, COMMON_LAYOUT_GRID_3x2);

  V_Button_t v_btn = V_Button_Create(container, &light_btn_cfg);
  v_home.light_nav_btn = &v_btn;
  V_Button_Bind_LV_Event_CB(v_home.light_nav_btn, home_navigate_touch,
                            (void *)SCREEN_ID_LIGHT);
};

// const lv_color_t rainbow_colors[] = {
//     LV_COLOR_MAKE(0, 0, 0),     LV_COLOR_MAKE(255, 255, 255),
//     LV_COLOR_MAKE(255, 0, 0),   LV_COLOR_MAKE(255, 128, 0),
//     LV_COLOR_MAKE(255, 255, 0), LV_COLOR_MAKE(0, 255, 0),
//     LV_COLOR_MAKE(0, 0, 255),   LV_COLOR_MAKE(128, 0, 255),
// };
