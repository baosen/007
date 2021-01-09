#ifndef _ULTRA64_INTERRUPT_H_
#define _ULTRA64_INTERRUPT_H_

typedef unsigned int OSIntMask;

OSIntMask osGetIntMask(void);
OSIntMask osSetIntMask(OSIntMask);

#endif
