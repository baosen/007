#ifndef _ULTRA64_THREAD_H_
#define _ULTRA64_THREAD_H_

/* Recommended priorities for system threads */
#define OS_PRIORITY_MAX 255
#define OS_PRIORITY_VIMGR 254
#define OS_PRIORITY_RMON 250
#define OS_PRIORITY_RMONSPIN 200
#define OS_PRIORITY_PIMGR 150
#define OS_PRIORITY_SIMGR 140
#define OS_PRIORITY_APPMAX 127
#define OS_PRIORITY_IDLE 0

enum { OS_STATE_STOPPED = 1, OS_STATE_RUNNABLE };
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8

typedef int OSPri;
typedef int OSId;

typedef union {
  struct {
    float f_odd, f_even;
  } f;
} __OSfp;

typedef struct {
  /* registers */
  unsigned long long at, v0, v1, a0, a1, a2, a3;
  unsigned long long t0, t1, t2, t3, t4, t5, t6, t7;
  unsigned long long s0, s1, s2, s3, s4, s5, s6, s7;
  unsigned long long t8, t9, gp, sp, s8, ra;
  unsigned long long lo, hi;
  unsigned int sr, pc, cause, badvaddr, rcp;
  unsigned int fpcsr;
  __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
  __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct {
  unsigned int flag;
  unsigned int count;
  unsigned long long time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
  struct OSThread_s *next;
  OSPri priority;
  struct OSThread_s **queue;
  struct OSThread_s *tlnext;
  unsigned short state;
  unsigned short flags;
  OSId id;
  int fp;
  __OSThreadprofile_s *thprof;
  __OSThreadContext context;
} OSThread;

void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *), void *arg,
                    void *sp, OSPri pri);
OSId osGetThreadId(OSThread *thread);
OSPri osGetThreadPri(OSThread *thread);
void osSetThreadPri(OSThread *thread, OSPri pri);
void osStartThread(OSThread *thread);
void osStopThread(OSThread *thread);

#endif
