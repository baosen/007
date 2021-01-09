// Ultra64 Video Interface.
#ifndef _ULTRA64_VI_H_
#define _ULTRA64_VI_H_
#include <message.h>

/* Special Features */
#define OS_VI_GAMMA_ON 0x0001
#define OS_VI_GAMMA_OFF 0x0002
#define OS_VI_GAMMA_DITHER_ON 0x0004
#define OS_VI_GAMMA_DITHER_OFF 0x0008
#define OS_VI_DIVOT_ON 0x0010
#define OS_VI_DIVOT_OFF 0x0020
#define OS_VI_DITHER_FILTER_ON 0x0040
#define OS_VI_DITHER_FILTER_OFF 0x0080

#define OS_VI_GAMMA 0x08
#define OS_VI_GAMMA_DITHER 0x04
#define OS_VI_DIVOT 0x10
#define OS_VI_DITHER_FILTER 0x10000
#define OS_VI_UNK200 0x200
#define OS_VI_UNK100 0x100

typedef struct {
  unsigned int ctrl;
  unsigned int width;
  unsigned int burst;
  unsigned int vSync;
  unsigned int hSync;
  unsigned int leap;
  unsigned int hStart;
  unsigned int xScale;
  unsigned int vCurrent;
} OSViCommonRegs;

typedef struct {
  unsigned int origin;
  unsigned int yScale;
  unsigned int vStart;
  unsigned int vBurst;
  unsigned int vIntr;
} OSViFieldRegs;

typedef struct {
  unsigned char type;
  OSViCommonRegs comRegs;
  OSViFieldRegs fldRegs[2];
} OSViMode;

typedef struct {
  unsigned short unk00; // some kind of flags.  swap buffer sets to 0x10
  unsigned short retraceCount;
  void *buffer;
  OSViMode *unk08;
  unsigned int features;
  OSMesgQueue *mq;
  OSMesg *msg;
  unsigned int unk18;
  unsigned int unk1c;
  unsigned int unk20;
  float unk24;
  unsigned short unk28;
  unsigned int unk2c;
} OSViContext;

void osCreateViManager(OSPri pri);
void osViSetMode(OSViMode *mode);
void osViBlack(unsigned char active);
void osViSetSpecialFeatures(unsigned int func);
void osViSwapBuffer(void *vaddr);

enum {
  OS_VI_NTSC_LPN1, /* NTSC */
  OS_VI_NTSC_LPF1,
  OS_VI_NTSC_LAN1,
  OS_VI_NTSC_LAF1,
  OS_VI_NTSC_LPN2,
  OS_VI_NTSC_LPF2,
  OS_VI_NTSC_LAN2,
  OS_VI_NTSC_LAF2,
  OS_VI_NTSC_HPN1,
  OS_VI_NTSC_HPF1,
  OS_VI_NTSC_HAN1,
  OS_VI_NTSC_HAF1,
  OS_VI_NTSC_HPN2,
  OS_VI_NTSC_HPF2,

  OS_VI_PAL_LPN1, /* PAL */
  OS_VI_PAL_LPF1,
  OS_VI_PAL_LAN1,
  OS_VI_PAL_LAF1,
  OS_VI_PAL_LPN2,
  OS_VI_PAL_LPF2,
  OS_VI_PAL_LAN2,
  OS_VI_PAL_LAF2,
  OS_VI_PAL_HPN1,
  OS_VI_PAL_HPF1,
  OS_VI_PAL_HAN1,
  OS_VI_PAL_HAF1,
  OS_VI_PAL_HPN2,
  OS_VI_PAL_HPF2,

  OS_VI_MPAL_LPN1, /* MPAL - mainly Brazil */
  OS_VI_MPAL_LPF1,
  OS_VI_MPAL_LAN1,
  OS_VI_MPAL_LAF1,
  OS_VI_MPAL_LPN2,
  OS_VI_MPAL_LPF2,
  OS_VI_MPAL_LAN2,
  OS_VI_MPAL_LAF2,
  OS_VI_MPAL_HPN1,
  OS_VI_MPAL_HPF1,
  OS_VI_MPAL_HAN1,
  OS_VI_MPAL_HAF1,
  OS_VI_MPAL_HPN2,
  OS_VI_MPAL_HPF2,

  OS_VI_FPAL_LPN1, /* FPAL - Full screen PAL */
  OS_VI_FPAL_LPF1,
  OS_VI_FPAL_LAN1,
  OS_VI_FPAL_LAF1,
  OS_VI_FPAL_LPN2,
  OS_VI_FPAL_LPF2,
  OS_VI_FPAL_LAN2,
  OS_VI_FPAL_LAF2,
  OS_VI_FPAL_HPN1,
  OS_VI_FPAL_HPF1,
  OS_VI_FPAL_HAN1,
  OS_VI_FPAL_HAF1,
  OS_VI_FPAL_HPN2,
  OS_VI_FPAL_HPF2
};

extern OSViMode osViModeTable[]; /* Global VI mode table */

#endif
