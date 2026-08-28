#ifndef __BRIDGE_H_
#define __BRIDGE_H_

#include "freertos/idf_additions.h"
#include "freertos/semphr.h"

// extern QueueHandle_t bridge_event_queue;

typedef enum {
  SYSTEM_BINDING_NONE = 0,
  SYSTEM_BINDING_SET_STRIP_COLOR,
} System_Binding_ID;

typedef enum {
  APP_BINDING_NONE = 0,
} App_Binding_ID;

typedef struct {
  System_Binding_ID sys_binding_id;
  App_Binding_ID app_binding_id;
  void *payload;
} Bridge_Event_t;

// void Bridge_Queue_Init(void);
// void Bridge_Event_Consume(Bridge_Event_t bridge_event);
Bridge_Event_t Bridge_Event_Create(System_Binding_ID sys_binding_id,
                                   App_Binding_ID app_binding_id,
                                   void *payload);

#endif // __BRIDGE_H_