#include "vm_button.h"

VM_Button_t VM_Button_Create(const VM_Button_Cfg_t *cfg) {
  VM_Button_t vm;

  const lv_color_t *color = Common_Color_Find_Entry(cfg->color_id)->lv_color;

  vm.color = *color;
  vm.label = cfg->label;
  vm.size = cfg->size;
  vm.col = cfg->col;
  vm.row = cfg->row;
  vm.ctx = cfg->vm_ctx;

  return vm;
}
