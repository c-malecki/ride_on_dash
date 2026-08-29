#ifndef __UI_TABLE_H_
#define __UI_TABLE_H_

#include "ui.h"
#include <stddef.h>

extern const UI_Element_t ui_screen_table[];
extern const size_t ui_screen_table_size;

const UI_Element_t *UI_Find_Element_By_Screen_ID(UI_Screen_ID screen_id);
uint8_t UI_Element_Get_Entry_Count(void);

extern const UI_Element_t *ui_element_table[];
extern const size_t ui_element_table_size;

// typedef struct {
//   UI_Screen_ID screen_id;
//   screen_render_fn render_fn;
// } UI_Screen_Entry_t;

// extern const UI_Screen_Entry_t ui_screen_table[];
// extern const size_t ui_screen_table_size;

#endif // __UI_TABLE_H_