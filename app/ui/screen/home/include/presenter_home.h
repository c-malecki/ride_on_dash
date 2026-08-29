#ifndef __PRESENTER_HOME_H_
#define __PRESENTER_HOME_H_

#include "ui.h"

typedef struct {
  UI_Presenter_Base_t base;
} Presenter_Home_t;

void Presenter_Home_Create(Presenter_Home_t *presenter);
void Presenter_Home_Init(UI_Presenter_Base_t *self);

#endif // __PRESENTER_HOME_H_