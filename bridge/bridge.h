#ifndef __BRIDGE_H_
#define __BRIDGE_H_

#include "lvgl.h"
#include <stdint.h>

typedef enum {
  BRIDGE_MODEL_PROP_NONE = 0,
  BRIDGE_MODEL_PROP_HEADLIGHT_COLOR,
  BRIDGE_MODEL_PROP_BODYLIGHT_COLOR,
} Bridge_Model_Prop_ID;

typedef struct {
  /* UI and System mapped */
  lv_subject_t headlight_color; // BRIDGE_MODEL_PROP_HEADLIGHT_COLOR
  lv_subject_t bodylight_color; // BRIDGE_MODEL_PROP_BODYLIGHT_COLOR
  /* System Only */

  /* UI Only */
} Bridge_Model_t;

void BRIDGE_MODEL_INIT(void);
void BRIDGE_MODEL_SET_UI_CB(Bridge_Model_Prop_ID prop_id, lv_obj_t *obj,
                            void *user_data);
void BRIDGE_MODEL_SET_PROP(Bridge_Model_Prop_ID prop_id, uint32_t value);

typedef struct {
  Bridge_Model_Prop_ID prop_id;
  void *payload;
} Bridge_Event_t;

#endif // __BRIDGE_H_