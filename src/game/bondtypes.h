#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "bondconstants.h"

struct color {
  unsigned char r, g, b, a;
};

struct watchMenuObjectiveText {
  unsigned int id;
  enum WATCH_BRIEFING_PAGE menu;
  unsigned short reserved;
  unsigned short text;
  struct watchMenuObjectiveText *nextentry;
};

//! FIXME all but text field cannot be trusted
struct objective_entry {
  unsigned int id;
  enum WATCH_BRIEFING_PAGE menu;
  unsigned short reserved;
  unsigned short text;
  struct watchMenuObjectiveText *nextentry;
};

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

typedef struct sGlobalImageTable {
  unsigned int globalDL_0x000[30];
  unsigned int globalDL_0x078[42];
  unsigned int globalDL_0x120[42];
  unsigned int globalDL_0x1c8[42];
  unsigned int globalDL_0x270[42];
  unsigned int globalDL_0x318[42];
  unsigned int globalDL_0x3c0[42];
  unsigned int globalDL_0x468[42];
  unsigned int globalDL_0x510[42];
  unsigned int globalDL_0x5b8[42];
  unsigned int globalDL_0x660[42];
  unsigned int globalDL_0x708[42];
  unsigned int globalDL_0x7b0[42];
  unsigned int globalDL_0x858[42];
  unsigned int globalDL_0x900[42];
  unsigned int globalDL_0x9a8[42];
  unsigned int globalDL_0xa50[30];
  struct sImageTableEntry s_genericimage[1];
  struct sImageTableEntry s_impactimages[20];
  struct sImageTableEntry s_explosion_smokeimages[6];
  struct sImageTableEntry s_scattered_explosions[5];
  struct sImageTableEntry s_flareimage1[1];
  struct sImageTableEntry s_flareimage2[1];
  struct sImageTableEntry s_flareimage3[1];
  struct sImageTableEntry s_flareimage4[1];
  struct sImageTableEntry s_flareimage5[1];
  struct sImageTableEntry s_ammo9mmimage[1];
  struct sImageTableEntry s_rifleammoimage[1];
  struct sImageTableEntry s_shotgunammoimage[1];
  struct sImageTableEntry s_knifeammoimage[1];
  struct sImageTableEntry s_glammoimage[1];
  struct sImageTableEntry s_rocketammoimage[1];
  struct sImageTableEntry s_genericmineammoimage[1];
  struct sImageTableEntry s_grenadeammoimage[1];
  struct sImageTableEntry s_magnumammoimage[1];
  struct sImageTableEntry s_goldengunammoimage[1];
  struct sImageTableEntry s_remotemineammoimage[1];
  struct sImageTableEntry s_timedmineammoimage[1];
  struct sImageTableEntry s_proxmineammoimage[1];
  struct sImageTableEntry s_tankammoimage[1];
  struct sImageTableEntry s_crosshairimage[1];
  struct sImageTableEntry s_betacrosshairimage[1];
  struct sImageTableEntry s_glassoverlayimage[2];
  struct sImageTableEntry s_monitorimages[50];
  struct sImageTableEntry s_skywaterimages[3];
  struct sImageTableEntry s_mainfolderimages[6];
  struct sImageTableEntry s_mpradarimages[1];
  struct sImageTableEntry s_mpcharselimages[64];
  struct sImageTableEntry s_mpstageselimages[17];
} sGlobalImageTable;

#endif
