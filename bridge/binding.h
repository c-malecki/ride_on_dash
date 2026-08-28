#ifndef __BINDING_H_
#define __BINDING_H_

typedef enum {
  BINDING_SYSTEM_NONE = 0,
  BINDING_SYSTEM_SET_LED_STRIP_COLOR,
} Binding_System_ID;

typedef enum {
  BINDING_APP_NONE = 0,
  BINDING_APP_SET_LED_UI_COLOR,
} Binding_App_ID;

#endif // __BINDING_H_