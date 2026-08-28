#ifndef __LED_CONTROLLER_H_
#define __LED_CONTROLLER_H_

#include "led_driver.h"
#include "util.h"

typedef void (*LED_Controller_Set_Strip_CB)(LED_Strip_ID strip_id,
                                            Util_Color_ID color_id);
LED_Controller_Set_Strip_CB LED_Controller_Binding_Set_Strip_CB(void);

#endif // __LED_CONTROLLER_H_