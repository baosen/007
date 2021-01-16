const char *get_compile_time(void) {
#ifdef VERSION_US
  return "Jun 29 1997 20:46:05";
#elif VERSION_JP
  return "Jul 10 1997 14:53:37";
#else
#error "You forgot to define which version of the game to compile."
#endif
}
