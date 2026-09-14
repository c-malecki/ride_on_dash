#ifndef __LED_DRIVER_H_
#define __LED_DRIVER_H_

#include "colors.h"
#include "esp_err.h"
#include "misc/lv_color.h"
#include <stdbool.h>

/*
  WS2812 LEDs
*/

#ifdef DEVELOPMENT
/* Development Configuration */
#define LED_STRIP_MAX_LEDS (1)
#define LOG_LEVEL LOG_LEVEL_INFO
#else
/* Production Configuration */
#define LED_STRIP_MAX_LEDS (10)
#define LOG_LEVEL LOG_LEVEL_ERROR
#endif

#define LED_PIN_HLL_DC (1)
#define LED_PIN_HLR_DC (2)
#define LED_PIN_BLL_DC (41)
#define LED_PIN_BLR_DC (42)

typedef enum {
  LED_STRIP_NONE = 0,
  LED_STRIP_HEADLIGHTS,
  LED_STRIP_BODYLIGHTS,
} LED_Strip_ID;

// typedef struct {
//   LED_Strip_ID strip_id;
//   Common_Color_ID color_id;
// } LED_Set_Strip_Color_Arg_t;

// typedef void (*LED_Driver_Set_Strip_Color_CB)(LED_Set_Strip_Color_Arg_t
// *arg);

esp_err_t LED_DRIVER_Init(void);
void LED_DRIVER_Set_Strip_Color(LED_Strip_ID strip_id, lv_color_t color);

// LED_Driver_Set_Strip_Color_CB LED_Driver_Get_Set_Strip_Color_CB(void);

#endif // __LED_DRIVER_H_