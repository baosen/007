#ifndef _ULTRA64_MESSAGE_H_
#define _ULTRA64_MESSAGE_H_
#include <thread.h>

enum {
  OS_EVENT_SW1,
  OS_EVENT_SW2,
  OS_EVENT_CART,
  OS_EVENT_COUNTER,
  OS_EVENT_SP,
  OS_EVENT_SI,
  OS_EVENT_AI,
  OS_EVENT_VI,
  OS_EVENT_PI,
  OS_EVENT_DP,
  OS_EVENT_CPU_BREAK,
  OS_EVENT_SP_BREAK,
  OS_EVENT_FAULT,
  OS_EVENT_THREADSTATUS,
  OS_EVENT_PRENMI
};

typedef unsigned int OSEvent;
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
  OSThread *mtqueue, *fullqueue;
  int validCount, first, msgCount;
  OSMesg *msg;
} OSMesgQueue;

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, int count);
int osSendMesg(OSMesgQueue *mq, OSMesg msg, int flag);
int osJamMesg(OSMesgQueue *mq, OSMesg msg, int flag);
int osRecvMesg(OSMesgQueue *mq, OSMesg *msg, int flag);
void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg);
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, unsigned int retraceCount);
int osContStartReadData(OSMesgQueue *mq);

#endif
