#include "presenter_home.h"

void Presenter_Home_Create(Presenter_Home_t *presenter) {
  presenter->base.init = Presenter_Home_Init;
}

void Presenter_Home_Init(UI_Presenter_Base_t *self) {}