#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "bondconstants.h"

struct color {
  unsigned char r, g, b, a;
};

struct object_standard {
  unsigned short extrascale : 2;
  unsigned char hidden2 : 1;
  unsigned char type : 1;
  unsigned short obj;
  unsigned short pad;
  unsigned int flags;
  unsigned int flags2;
  void *runtime_ptr_obj_posdata;
  void *runtime_ptr_obj_instance_controller;
  void *runtime_MATRIX0;
  void *runtime_MATRIX1;
  void *runtime_MATRIX2;
  void *runtime_MATRIX3;
  void *runtime_MATRIX4;
  void *runtime_MATRIX5;
  void *runtime_MATRIX6;
  void *runtime_MATRIX7;
  void *runtime_MATRIX8;
  void *runtime_MATRIX9;
  void *runtime_MATRIXA;
  void *runtime_MATRIXB;
  void *runtime_MATRIXC;
  void *runtime_MATRIXD;
  void *runtime_MATRIXE;
  void *runtime_MATRIXF;
  float runtime_x_pos;
  float runtime_y_pos;
  float runtime_z_pos;
  int runtime_bitflags;
  int ptr_allocated_collisiondata_block;
  int field_6C;
  float field_70;
  short damage;
  short maxdamage;
  char field_78;
  char field_79;
  char field_7A;
  char field_7B;
  char field_7C;
  char field_7D;
  char field_7E;
  char field_7F;
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
