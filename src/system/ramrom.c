// This file contains code to handle reading and writing rom addresses.
#include <message.h>
#include <pi.h>
#include <thread.h>

void romCreateMesgQueue(void);
void romCopy(void *target, void *source, unsigned int size);
int romCopyAligned(void *target, void *source, int length);
void romWrite(void *source, void *target, unsigned int size);

#define align_addr_zero(X) ((((X) + 0xF) | 0xF) ^ 0xF)
#define align_addr_even(X) (((X) | 1) ^ 1)

OSIoMesg memoryMesgMB;
OSMesg memoryMesg;
OSMesgQueue memoryMesgQueue;

// creates a message queue
void romCreateMesgQueue(void) {
  osCreateMesgQueue(&memoryMesgQueue, &memoryMesg, 1);
}

// invalidate cache and do pi dma
void doRomCopy(void *target, void *source, unsigned int size) {
  osInvalDCache(target, size);
  osPiStartDma(&memoryMesgMB, 0, 0, source, target, size, &memoryMesgQueue);
}

// receives a message queue
void romReceiveMesg(void) { osRecvMesg(&memoryMesgQueue, 0, 1); }

// copy from rom to ram
void romCopy(void *target, void *source, unsigned int size) {
  doRomCopy(target, source, size);
  romReceiveMesg();
}

// aligns data, does a romCopy(), then returns aligned pointer to target
int romCopyAligned(void *target, void *source, int length) {
  int target_offset;
  int *target_aligned, *source_aligned, *source_offset;
  source_aligned = align_addr_even((int)source);
  source_offset = (int)source - (int)source_aligned;
  target_aligned = align_addr_zero((int)target);
  target_offset = source_offset;
  romCopy(target_aligned, source_aligned,
          align_addr_zero((int)source_offset + length));
  return ((int)target_aligned + target_offset);
}

// actually writes to rom (buffer on Indy)
void doRomWrite(void *source, void *target, unsigned int size) {
  osWritebackDCache(source, size);
  osPiStartDma(&memoryMesgMB, 0, 1, target, source, size, &memoryMesgQueue);
}

// let's write to the rom (buffer on Indy)
void romWrite(void *source, void *target, unsigned int size) {
  doRomWrite(source, target, size);
  romReceiveMesg();
}
