#ifndef _BONDTYPES_H_
#define _BONDTYPES_H_
#include "bondconstants.h"

struct color {
  unsigned char r, g, b, a;
};

struct colorfloat {
  float r, g, b, a;
};

typedef struct CHRdata CHRdata;

/* unfinished struct, WIP */
struct CHRdata {
  unsigned short chrnum;
  char accuracyrating;
  char speedrating;
  unsigned char firecountleft;
  unsigned char firecountright;
  char headnum;
  char actiontype;
  char sleep;
  char invalidmove;
  char numclosearghs;
  char numarghs;
  unsigned char fadealpha;
  char arghrating;
  char aimendcount;
  char bodynum;
  /* 0x0010 */
  unsigned char grenadeprob;
  char flinchcnt;
  short hidden;
  int chrflags;
  void *pad;
  void *model;
  /* 0x0020 */
  void *field_20;
  float chrwidth;
  float chrheight;
  void *bondpos; /* HACK - reused as fadeout counter on death, checks if pointer
                    at 7F02B774 */
  /* 0x0030 */
  int field_30;
  short field_34;
  char field_36;
  char field_37;
  char field_38;
  char field_39;
  char field_3A;
  char field_3B;
  int path_target_position;
  /* 0x0040 */
  int field_40;
  int field_44;
  int field_48;
  int field_4C;
  /* 0x0050 */
  int field_50;
  int field_54;
  char type_of_motion;
  char distance_counter_or_something;
  short distance_to_target;
  int field_5C;
  /* 0x0060 */
  int target_position;
  int field_64;
  int field_68;
  int field_6C;
  /* 0x0070 */
  int path_segment_coverage;
  int path_segment_length;
  int field_78;
  int field_7C;
  /* 0x0080 */
  int field_80;
  int field_84;
  int field_88;
  int field_8C;
  /* 0x0090 */
  int field_90;
  int segment_coverage;
  int segment_length;
  int field_9C;
  /* 0x00A0 */
  int field_A0;
  float sumground;
  float manground;
  float ground;
  /* 0x00B0 */
  float fallspeed[3];
  float prevpos[3];
  /* 0x00B8 */
  int lastwalk60;
  int lastmoveok60;
  /* 0x00D0 */
  float visionrange;
  int lastseetarget60;
  float lastvisibletarg[3];
  /* 0x00E4 */
  void *field_E4;
  int timeshooter;
  float hearingscale;
  /* 0x00F0 */
  int lastheartarget60;
  unsigned char shadecol[4];
  unsigned char nextcol[4];
  float damage;
  /* 0x0100 */
  float maxdamage;
  void *ailist;
  unsigned short aioffset;
  unsigned short aireturnlist;
  unsigned char flags;  /* used by ai commands 81-85 */
  unsigned char flags2; /* used by ai commands 86-8A */
  unsigned char BITFIELD;
  unsigned char random;
  /* 0x0110 */
  int timer60;
  unsigned short padpreset1; /* ID PAD_PRESET */
  unsigned short chrpreset1; /* ID CHR_PRESET */
  unsigned short
      chrseeshot; /* ID CHR_SEE_SHOT - ignores invincible/armoured guards */
  unsigned short chrseedie; /* ID CHR_SEE_DIE */
  /* 0x011C */
  float field_11C[2];
  float field_124[2];
  float field_12C[2];
  /* 0x0134 */
  int field_134;
  int field_138;
  float shotbondsum;
  /* 0x0140 */
  float aimuplshoulder;
  float aimuprshoulder;
  float aimupback;
  float aimsideback;
  /* 0x0150 */
  float aimendlshoulder;
  float aimendrshoulder;
  float aimendback;
  float aimendsideback;
  /* 0x0160 */
  int *handle_positiondata[2];
  int *ptr_SEbuffer1;
  int *ptr_SEbuffer2;
  /* 0x0170 */
  int *ptr_SEbuffer3;
  int *ptr_SEbuffer4;
  int field_178;
  int field_17C;
  /* 0x0180 */
  char field_180;
  char field_181;
  char field_182;
  char field_183;
  int field_184;
  int field_188;
  int field_18C;
  /* 0x0190 */
  int field_190;
  int field_194;
  int field_198;
  int field_19C;
  /* 0x01A0 */
  int field_1A0;
  int field_1A4;
  int field_1A8;
  char field_1AC;
  char field_1AD;
  char field_1AE;
  char field_1AF;
  /* 0x01B0 */
  int field_1B0;
  int field_1B4;
  int field_1B8;
  int field_1BC;
  /* 0x01C0 */
  int field_1C0;
  int field_1C4;
  int field_1C8;
  int field_1CC;
  /* 0x01D0 */
  int field_1D0;
  int field_1D4;
  int *handle_positiondata_hat;
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
