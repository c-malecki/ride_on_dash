#include "bridge.h"

Bridge_Event_t Bridge_Event_Create(System_Binding_ID sys_binding_id,
                                   App_Binding_ID app_binding_id,
                                   void *payload) {
  return (Bridge_Event_t){
      .sys_binding_id = sys_binding_id,
      .app_binding_id = app_binding_id,
      .payload = payload,
  };
};