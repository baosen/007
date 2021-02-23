#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "bondconstants.h"

typedef struct sImageTableEntry {
  unsigned int index;
  unsigned char width;
  unsigned char height;
  unsigned char level;
  unsigned char format;
  unsigned char depth;
  unsigned char flagsS;
  unsigned char flagsT;
  unsigned char pad;
} sImageTableEntry;

#endif
