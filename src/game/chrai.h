#ifndef _CHRAI_H_
#define _CHRAI_H_

struct sfx_register_struct {
  unsigned int field_0x0;
  unsigned int field_0x4;
  unsigned int field_0x8;
  unsigned int field_0xc;
  unsigned int field_0x10;
  unsigned int field_0x14;
};

struct struct_0 {
  int anonymous_0;
  int anonymous_1;
  int anonymous_2;
  int anonymous_3;
  int anonymous_4;
  void *anonymous_5;
  int anonymous_6;
};

struct struct_5 {
  int anonymous_0;
  void *anonymous_1;
  int anonymous_2;
};

struct struct_12 {
  int anonymous_0;
  char anonymous_1;
  char anonymous_2;
  char anonymous_3;
  char anonymous_4;
  int anonymous_5;
  int anonymous_6;
  void *anonymous_7;
};

struct struct_16 {
  int anonymous_0;
  int anonymous_1;
  int anonymous_2;
  int anonymous_3;
  int anonymous_4;
  int anonymous_5;
  void *anonymous_6;
};

struct struct_20 {
  int anonymous_0;
  int anonymous_1;
  int anonymous_2;
  int anonymous_3;
  int anonymous_4;
  int anonymous_5;
  int anonymous_6;
  int anonymous_7;
  int anonymous_8;
  int anonymous_9;
  int anonymous_10;
  int anonymous_11;
  int anonymous_12;
  int anonymous_13;
  int anonymous_14;
  int anonymous_15;
  int anonymous_16;
  int anonymous_17;
  int anonymous_18;
  void *anonymous_19;
};

extern unsigned int D_800312A0[];
extern unsigned int D_800312B4[];
extern unsigned int D_800312C8[];
extern unsigned int D_800312F4[];
extern unsigned int D_80031310[];
extern struct struct_5 D_80031950[];
extern struct struct_0 D_800319D4;
extern struct struct_0 D_800319F0;
extern struct struct_0 D_80031A0C;
extern struct struct_0 D_80031A28;
extern struct struct_0 D_80031A44;
extern struct struct_0 D_80031A60;
extern struct struct_0 D_80031A7C;
extern struct struct_0 D_80031A98;
extern struct struct_0 D_80031AB4;
extern struct struct_0 D_80031AD0;
extern struct struct_5 D_80031AEC[];
extern struct struct_12 D_80031B10[];
extern struct struct_12 D_80031B24[];
extern struct struct_12 D_80031B38[];
extern struct struct_12 D_80031B4C[];
extern unsigned int D_80031B60[];
extern struct struct_16 D_80031BB4;
extern struct struct_16 D_80031BD0;
extern struct struct_16 D_80031BEC;
extern unsigned int D_80031C08[];
extern unsigned int D_80031C80[];
extern unsigned int D_80031D30[];
extern struct struct_20 D_80031D58;
extern unsigned int monitor_animation_microcode[];
extern unsigned int dword_D_80031F00[];
extern unsigned int dword_D_80031F44[];
extern float gas_damage_flag;
extern unsigned int gas_cutoff_flag;
extern struct object_standard *ptr_setup_objects;

#endif
