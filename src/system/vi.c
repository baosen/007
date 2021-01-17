#include <message.h>
#include <thread.h>

OSMesg vi_c_debug_MSG[8];
OSMesgQueue vi_c_debug_MQ;

void *vi_c_debug_notice_list[6] = {0};
void *enddl[] = {0xB8000000, 0};

void start_nulled_entry(void) {}

void init_vi_c_debug(void) {
  set_debug_notice_list_entry(&vi_c_debug_notice_list, "vi_c_debug");
  osCreateMesgQueue(&vi_c_debug_MQ, &vi_c_debug_MSG, 8);
}
