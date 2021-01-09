int __osGetCurrFaultedThread(void) {
  extern int __osFaultedThread;
  return __osFaultedThread;
}
