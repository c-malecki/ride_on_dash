#ifndef __SCREENS_H_
#define __SCREENS_H_

#include "definitions.h"
#include <stddef.h>

const UI_Screen_t *UI_Screens_Find_By_ID(UI_Screen_ID screen_id);
uint8_t UI_Screens_Get_Entry_Count(void);

extern const UI_Screen_t *ui_screen_table[];
extern const size_t ui_screen_table_size;

#endif // __SCREENS_H_