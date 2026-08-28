#ifndef __LED_CONTROLLER_H_
#define __LED_CONTROLLER_H_

#include "_color.h"
#include "led_driver.h"

typedef void (*LED_Controller_Set_Strip_CB)(LED_Strip_ID strip_id,
                                            Color_ID color_id);
LED_Controller_Set_Strip_CB LED_Controller_Binding_Set_Strip_CB(void);

#endif // __LED_CONTROLLER_H_