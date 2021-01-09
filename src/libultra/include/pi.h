// Ultra64 Parallel Interface.
#ifndef _ULTRA64_PI_H_
#define _ULTRA64_PI_H_

typedef struct {
  unsigned int errStatus;
  void *dramAddr;
  void *C2Addr;
  unsigned int sectorSize;
  unsigned int C1ErrNum;
  unsigned int C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
  unsigned int cmdType;
  unsigned short transferMode;
  unsigned short blockNum;
  int sectorNum;
  unsigned int devAddr;
  unsigned int bmCtlShadow;
  unsigned int seqCtlShadow;
  __OSBlockInfo block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s {
  struct OSPiHandle_s *next;
  unsigned char type;
  unsigned char latency;
  unsigned char pageSize;
  unsigned char relDuration;
  unsigned char pulse;
  unsigned char domain;
  unsigned int baseAddress;
  unsigned int speed;
  __OSTranxInfo transferInfo;
} OSPiHandle;

typedef struct {
  unsigned char type;
  unsigned int address;
} OSPiInfo;

typedef struct {
  unsigned short type;
  unsigned char pri;
  unsigned char status;
  OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
  OSIoMesgHdr hdr;
  void *dramAddr;
  unsigned int devAddr;
  unsigned int size;
  OSPiHandle *piHandle; // from the official definition
} OSIoMesg;

enum {
  OS_READ, // device -> RDRAM
  OS_WRITE // device <- RDRAM
};

enum { OS_MESG_PRI_NORMAL, OS_MESG_PRI_HIGH };

int osPiStartDma(OSIoMesg *mb, int priority, int direction,
                 unsigned int devAddr, void *vAddr, unsigned int nbytes,
                 OSMesgQueue *mq);
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf,
                       int cmdMsgCnt);
OSMesgQueue *osPiGetCmdQueue(void);
int osPiWriteIo(unsigned int devAddr, unsigned int data);
int osPiReadIo(unsigned int devAddr, unsigned int *data);

#endif
