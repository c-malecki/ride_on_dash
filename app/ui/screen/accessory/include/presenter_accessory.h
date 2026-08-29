#ifndef __PRESENTER_ACCESSORY_H_
#define __PRESENTER_ACCESSORY_H_

#include "model_accessory.h"
#include "ui.h"

typedef struct {
  UI_Presenter_Base_t base;
  Model_Accessory_t *model;
} Presenter_Accessory_t;

/* setup */

void Presenter_Accessory_Create(Presenter_Accessory_t *presenter,
                                Model_Accessory_t *model);
void Presenter_Accessory_Init(UI_Presenter_Base_t *self);

/* interface */

#endif // __PRESENTER_ACCESSORY_H_