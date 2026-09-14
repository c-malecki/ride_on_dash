#ifndef __M_LIGHT_H_
#define __M_LIGHT_H_

#include "colors.h"

typedef struct {
  Common_Color_ID headlights;
  Common_Color_ID bodylights;
} M_Light_t;

void M_Light_Init(void);

#endif // __M_LIGHT_H_