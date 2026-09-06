#ifndef __COLOR_H_
#define __COLOR_H_

#include <stdint.h>

#ifdef DEVELOPMENT
/* Development Configuration */

#else
/* Production Configuration */

#endif

typedef enum {
  COLOR_NONE = 0,
  COLOR_WHITE,
  COLOR_RED,
  COLOR_ORANGE,
  COLOR_YELLOW,
  COLOR_GREEN,
  COLOR_BLUE,
  COLOR_VIOLET,
  COLOR_GRAY,
  COLOR_COUNT,
} Color_ID;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} Color_t;

typedef struct {
  Color_ID color_id;
  const Color_t *color;
  const char *label;
} Color_Table_Entry_t;

const Color_Table_Entry_t *CFG_Color_Find_Entry(Color_ID color_id);
uint8_t CFG_Color_Get_Entry_Count(void);

#endif // __COLOR_H_