#ifndef _ULTRA64_TYPES_H_
#define _ULTRA64_TYPES_H_

typedef int bool;
enum { false = 0, true = 1 };

typedef long int Mtx_t[4][4];
typedef union {
  Mtx_t m;
  long long int forc_structure_alignment;
} Mtx;

#endif
