#ifndef __MODEL_ACCESSORY_H_
#define __MODEL_ACCESSORY_H_

#include "lvgl.h"
#include "util.h"

typedef enum {
  MODEL_ACCESSORY_LED_NONE = 0,
  MODEL_ACCESSORY_LED_HEADLIGHTS,
  MODEL_ACCESSORY_LED_BODYLIGHTS,
} Model_Accessory_LED;

typedef struct {
  lv_subject_t color_picker_show;    // bool
  lv_subject_t selected_lights;      // Model_Accessory_LED
  lv_subject_t btn_headlights_color; // App_Color_ID
  lv_subject_t btn_bodylights_color; // App_Color_ID
} Model_Accessory_t;

void Model_Accessory_Init(Model_Accessory_t *model);

void Model_Accessory_Set_Show_Color_Picker(Model_Accessory_t *model, bool show);

Model_Accessory_LED
Model_Accessory_Get_Selected_Lights(Model_Accessory_t *model);
void Model_Accessory_Set_Selected_Lights(Model_Accessory_t *model,
                                         Model_Accessory_LED selected_lights);

void Model_Accessory_Set_Btn_Color_Headlights(Model_Accessory_t *model,
                                              App_Color_ID color_id);

void Model_Accessory_Set_Btn_Color_Bodylights(Model_Accessory_t *model,
                                              App_Color_ID color_id);

#endif // __MODEL_ACCESSORY_H_