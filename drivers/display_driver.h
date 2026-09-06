#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include "esp_err.h"
#include "esp_lcd_ili9341.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch_xpt2046.h"

/*
  LCD
*/

#define LCD_PIN_SPI_MOSI (11)
#define LCD_PIN_SPI_CLK (12)
#define LCD_PIN_SPI_MISO (13)
#define LCD_PIN_DC (8)
#define LCD_PIN_RST (9)
#define LCD_PIN_CS (10)
#define LCD_PIN_LED (18)
#define LCD_PIN_T_IRQ (16)
#define LCD_PIN_T_CS (17)

esp_err_t DISPLAY_DRIVER_Init(void);

esp_lcd_panel_io_handle_t DISPLAY_DRIVER_Get_IO_Handle(void);
esp_lcd_panel_handle_t DISPLAY_DRIVER_Get_Panel_Handle(void);
esp_lcd_touch_handle_t DISPLAY_DRIVER_Get_Touch_Handle(void);

#endif // __DISPLAY_H_