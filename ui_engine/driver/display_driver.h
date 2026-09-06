#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include "esp_err.h"

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

esp_err_t Display_Driver_Init(void);

#endif // __DISPLAY_H_