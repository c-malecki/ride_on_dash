#ifndef __PRESENTER_BASE_H_
#define __PRESENTER_BASE_H_

typedef struct presenter_base {
  void (*init)(struct presenter_base *self);
  void (*destroy)(struct presenter_base *self);
  void *view;  // pointer to owning view
  void *model; // pointer to owning model(s)
} Presenter_Base_t;

#endif // __PRESENTER_BASE_H_