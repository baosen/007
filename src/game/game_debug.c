int D_8004EAE0[4] = {0};

void something_game_c_debug_related(void) {
  get_ptr_debug_notice_list_entry(&D_8004EAE0, "game_c_debug");
}

void reset_mem_bank_5(void) {
  sub_GAME_7F0BD234();
  mempResetBank(5);
  something_mem_bank_a0(5);
}

void sub_GAME_7F0D1A7C(void) {
  mempNullNextEntryInBank(5);
  something_mem_bank_a0(5);
}