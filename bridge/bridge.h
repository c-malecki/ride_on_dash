#ifndef __BRIDGE_H_
#define __BRIDGE_H_

#include "binding.h"

typedef struct {
  Binding_System_ID sys_binding_id;
  Binding_App_ID app_binding_id;
  void *payload;
} Bridge_Event_t;

Bridge_Event_t Bridge_Event_Create(Binding_System_ID sys_binding_id,
                                   Binding_App_ID app_binding_id,
                                   void *payload);

#endif // __BRIDGE_H_