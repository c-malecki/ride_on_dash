#include "bridge.h"

Bridge_Event_t Bridge_Event_Create(Binding_System_ID sys_binding_id,
                                   Binding_App_ID app_binding_id,
                                   void *payload) {
  return (Bridge_Event_t){
      .sys_binding_id = sys_binding_id,
      .app_binding_id = app_binding_id,
      .payload = payload,
  };
};