#ifndef _LVL_H_
#define _LVL_H_

struct ramrom_struct {
  unsigned int *address;
  unsigned int unk;
};

extern int clock_timer;
extern float global_timer_delta;
extern int record_slot_num;

#endif
