int D_8004EAE0[4] = {0};

void something_game_c_debug_related(void) {
  set_debug_notice_list_entry(&D_8004EAE0, "game_c_debug");
}

void reset_mem_bank_5(void) {
  sub_GAME_7F0BD234();
  mempResetBank(5);
  obBlankResourcesLoadedInBank(5);
}

void null_mem_bank_5(void) {
  mempNullNextEntryInBank(5);
  obBlankResourcesLoadedInBank(5);
}
