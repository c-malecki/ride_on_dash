#ifndef __LED_DRIVER_H_
#define __LED_DRIVER_H_

#include "_color.h"
#include "esp_err.h"
#include <stdbool.h>

typedef enum {
  LED_STRIP_NONE = 0,
  LED_STRIP_HEADLIGHTS,
  LED_STRIP_BODYLIGHTS,
} LED_Strip_ID;

typedef struct {
  LED_Strip_ID strip_id;
  Color_ID color_id;
} LED_Set_Strip_Color_Arg_t;

typedef void (*LED_Driver_Set_Strip_Color_CB)(LED_Set_Strip_Color_Arg_t *arg);

esp_err_t LED_Init(void);
void LED_DRIVER_Set_Strip_Color(LED_Strip_ID strip_id, Color_ID color_id);

LED_Driver_Set_Strip_Color_CB LED_Driver_Get_Set_Strip_Color_CB(void);

#endif // __LED_DRIVER_H_