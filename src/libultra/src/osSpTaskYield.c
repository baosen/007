void osSpTaskYield(void) {
  enum { SPSTATUS_SET_SIGNAL0 = 1024 };
  __osSpSetStatus(SPSTATUS_SET_SIGNAL0);
}
