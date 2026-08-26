#include "presenter_home.h"
#include "util.h"

void Presenter_Home_Create(Presenter_Home_t *presenter) {
  presenter->base.init = Presenter_Home_Init;
}

void Presenter_Home_Init(Presenter_Base_t *self) {}