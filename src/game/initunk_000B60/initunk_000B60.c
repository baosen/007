#include "chrobjdata.h"

void sub_GAME_7F000B60(void) {
  player_gait_object.offset_obj_table = (int)&player_gait_hdr;
}
