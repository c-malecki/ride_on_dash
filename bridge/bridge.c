#include "bridge.h"

// QueueHandle_t bridge_event_queue = NULL;

// void Bridge_Queue_Init(void) { xQueueCreate(10, sizeof(Bridge_Event_t)); }

// void Brdige_Event_Consume(Bridge_Event_t bridge_event) {

// };

Bridge_Event_t Bridge_Event_Create(System_Binding_ID sys_binding_id,
                                   App_Binding_ID app_binding_id,
                                   uint32_t payload) {
  return (Bridge_Event_t){
      .sys_binding_id = sys_binding_id,
      .app_binding_id = app_binding_id,
      .payload = payload,
  };
};