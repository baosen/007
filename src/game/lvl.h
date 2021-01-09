#ifndef _LVL_H_
#define _LVL_H_

struct ramrom_struct {
  unsigned int *address;
  unsigned int unk;
};

extern int D_800483C4;
extern int clock_timer;
extern int global_timer;
extern float global_timer_delta;
extern unsigned int *ptr_jfont_DL;
extern int dword_CODE_bss_8008C264;
extern int dword_CODE_bss_8008C268;
extern int dword_CODE_bss_8008C26C;
extern char ramrom_data_target[0x380];
extern int record_slot_num;
extern int *address_demo_loaded;
extern int dword_CODE_bss_8008C5F8;

#endif
