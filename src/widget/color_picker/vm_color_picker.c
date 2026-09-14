#include "vm_color_picker.h"

VM_Color_Picker_t VM_Color_Picker_Create(const VM_Color_Picker_Cfg_t *cfg) {
  VM_Color_Picker_t vm;

  vm.on_select_cb = cfg->on_select_cb;

  return vm;
}