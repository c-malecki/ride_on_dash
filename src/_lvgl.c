#include "_lvgl.h"
// drivers
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_timer.h"
// libs
#include "esp_err.h"

/* STATIC VARS */

static lv_display_t *disp = NULL;
static lv_indev_t *indev = NULL;

static esp_lcd_touch_handle_t ref_touch_handle = NULL;

/* */

void LVGL_Init(esp_lcd_panel_io_handle_t io_handle,
               esp_lcd_panel_handle_t panel_handle,
               esp_lcd_touch_handle_t touch_handle);

/* SETUP */

static void lvgl_tick_cb(void *arg) { lv_tick_inc(2); }

static void touchpad_read_cb(lv_indev_t *indev, lv_indev_data_t *data) {
  esp_lcd_touch_point_data_t point;
  uint8_t point_count = 0;

  esp_err_t err = esp_lcd_touch_read_data(ref_touch_handle);
  if (err != ESP_OK) {
    data->state = LV_INDEV_STATE_RELEASED;
    return;
  }

  bool pressed = esp_lcd_touch_get_data(ref_touch_handle, &point, &point_count,
                                        1) == ESP_OK &&
                 point_count > 0;
  if (pressed) {
    data->point.x = point.x;
    data->point.y = point.y;
    data->state = LV_INDEV_STATE_PRESSED;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

static bool flush_ready_cb(esp_lcd_panel_io_handle_t panel_io,
                           esp_lcd_panel_io_event_data_t *edata,
                           void *user_ctx) {
  lv_display_t *disp = (lv_display_t *)user_ctx;
  lv_display_flush_ready(disp);
  return false;
}

static void flush_exec_cb(lv_display_t *disp, const lv_area_t *area,
                          uint8_t *px_map) {
  esp_lcd_panel_handle_t panel =
      (esp_lcd_panel_handle_t)lv_display_get_user_data(disp);

  uint32_t w = lv_area_get_width(area);
  uint32_t h = lv_area_get_height(area);
  lv_draw_sw_rgb565_swap(px_map, w * h);

  esp_lcd_panel_draw_bitmap(panel, area->x1, area->y1, area->x2 + 1,
                            area->y2 + 1, (uint16_t *)px_map);
}

void LVGL_Init(esp_lcd_panel_io_handle_t io_handle,
               esp_lcd_panel_handle_t panel_handle,
               esp_lcd_touch_handle_t touch_handle) {
  ref_touch_handle = touch_handle;

  lv_init();

  disp = lv_display_create(320, 240);

  static lv_color_t buf1[320 * 20];
  lv_display_set_buffers(disp, buf1, NULL, sizeof(buf1),
                         LV_DISPLAY_RENDER_MODE_PARTIAL);

  lv_display_set_flush_cb(disp, flush_exec_cb);
  lv_display_set_user_data(disp, panel_handle);

  esp_lcd_panel_io_callbacks_t iccbs = {.on_color_trans_done = flush_ready_cb};
  esp_lcd_panel_io_register_event_callbacks(io_handle, &iccbs, disp);

  indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, touchpad_read_cb);
  lv_indev_set_display(indev, disp);

  const esp_timer_create_args_t lvgl_tick_timer_args = {
      .callback = &lvgl_tick_cb, .name = "lvgl_tick"};
  esp_timer_handle_t lvgl_tick_timer = NULL;
  ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, 2000));
}