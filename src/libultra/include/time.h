#ifndef _ULTRA64_TIME_H_
#define _ULTRA64_TIME_H_
#include <message.h>

typedef struct OSTimer_str {
  struct OSTimer_str *next, *prev;
  unsigned long long interval, remaining;
  OSMesgQueue *mq;
  OSMesg *msg;
} OSTimer;

typedef unsigned long long OSTime;

OSTime osGetTime(void);
void osSetTime(OSTime time);
unsigned int osSetTimer(OSTimer *, OSTime, unsigned long long, OSMesgQueue *,
                        OSMesg);

#endif
