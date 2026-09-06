#ifndef __LVGL_H_
#define __LVGL_H_

#include "esp_lcd_ili9341.h"
#include "esp_lcd_touch_xpt2046.h"

void LVGL_Init(esp_lcd_panel_io_handle_t io_handle,
               esp_lcd_panel_handle_t panel_handle,
               esp_lcd_touch_handle_t touch_handle);

#endif // __LVGL_H_