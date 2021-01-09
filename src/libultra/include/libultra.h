#ifndef _LIBULTRA_H_
#define _LIBULTRA_H_

enum { TV_TYPE_PAL, TV_TYPE_NTSC, TV_TYPE_MPAL };
enum { RESET_TYPE_COLD_RESET, RESET_TYPE_NMI, RESET_TYPE_BOOT_DISK };

extern unsigned int osTvType;
extern unsigned int osRomBase;
extern unsigned int osResetType;
extern unsigned char osAppNmiBuffer[64];
extern unsigned long long osClockRate;

#endif
