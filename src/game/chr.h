#ifndef _CHR_H_
#define _CHR_H_

struct animation_something {
  int anonymous_0;
  int field_4;
  int field_8;
  float field_C;
  int field_10;
  int field_14;
  float field_18;
  struct struck_animation_table *field_1C;
  int field_20;
  struct struck_animation_table *field_24;
  int field_28;
};

struct struck_animation_table {
  void *anonymous_0;
  int anonymous_1;
  float anonymous_2;
  float anonymous_3;
  int anonymous_4;
  float sfx1_timer_60;
  float sfx2_timer_60;
};

struct explosion_death_animation {
  int anonymous_0;
  int anonymous_1;
  float anonymous_2;
  float anonymous_3;
  float anonymous_4;
  float anonymous_5;
  float anonymous_6;
};

struct explosion_animation {
  void *explosion_death_animation;
  int count;
};

struct weapon_firing_animation_table {
  int anonymous_0;
  float anonymous_1;
  float anonymous_2;
  float anonymous_3;
  float anonymous_4;
  float anonymous_5;
  float anonymous_6;
  float anonymous_7;
  float anonymous_8;
  float anonymous_9;
  float anonymous_10;
  float anonymous_11;
  float anonymous_12;
  float anonymous_13;
  float anonymous_14;
  float anonymous_15;
  float anonymous_16;
  float anonymous_17;
};

extern struct animation_something D_8002C914;

extern struct struck_animation_table D_8002CE54[];
extern struct struck_animation_table D_8002DF10[];
extern struct struck_animation_table D_8002CEE0[];
extern struct struck_animation_table D_8002DF64[];
extern struct struck_animation_table D_8002CF6C[];
extern struct struck_animation_table D_8002DFB8[];
extern struct struck_animation_table D_8002D014[];
extern struct struck_animation_table D_8002E028[];
extern struct struck_animation_table D_8002D0A0[];
extern struct struck_animation_table D_8002E07C[];
extern struct struck_animation_table D_8002D12C[];
extern struct struck_animation_table D_8002E0D0[];
extern struct struck_animation_table D_8002D1D4[];
extern struct struck_animation_table D_8002E140[];
extern struct struck_animation_table D_8002D3B0[];
extern struct struck_animation_table D_8002E23C[];
extern struct struck_animation_table D_8002D6DC[];
extern struct struck_animation_table D_8002E300[];
extern struct struck_animation_table D_8002D768[];
extern struct struck_animation_table D_8002E354[];
extern struct struck_animation_table D_8002D7F4[];
extern struct struck_animation_table D_8002E3A8[];
extern struct struck_animation_table D_8002D880[];
extern struct struck_animation_table D_8002E418[];
extern struct struck_animation_table D_8002D90C[];
extern struct struck_animation_table D_8002E46C[];
extern struct struck_animation_table D_8002D998[];
extern struct struck_animation_table D_8002E4C0[];
extern struct struck_animation_table D_8002DA24[];
extern struct struck_animation_table D_8002E530[];
extern struct struck_animation_table D_8002DCE0[];
extern struct struck_animation_table D_8002E5BC[];

extern struct weapon_firing_animation_table rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table rifle_firing_animation_group5[];
extern struct weapon_firing_animation_table rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table rifle_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table pistol_firing_animation_group6[];
extern struct weapon_firing_animation_table pistol_firing_animation_group4[];
extern struct weapon_firing_animation_table pistol_firing_animation_group5[];
extern struct weapon_firing_animation_table doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table doubles_firing_animation_group3[];
extern struct weapon_firing_animation_table
    crouched_rifle_firing_animation_group1[];
extern struct weapon_firing_animation_table
    crouched_rifle_firing_animation_groupA[];
extern struct weapon_firing_animation_table
    crouched_rifle_firing_animation_group2[];
extern struct weapon_firing_animation_table
    crouched_rifle_firing_animation_group3[];
extern struct weapon_firing_animation_table
    crouched_pistol_firing_animation_group1[];
extern struct weapon_firing_animation_table
    crouched_pistol_firing_animation_group2[];
extern struct weapon_firing_animation_table
    crouched_pistol_firing_animation_group3[];
extern struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group1[];
extern struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group2[];
extern struct weapon_firing_animation_table
    crouched_doubles_firing_animation_group3[];

extern struct weapon_firing_animation_table D_80030078;
extern struct weapon_firing_animation_table D_800300C0;
extern struct weapon_firing_animation_table D_80030108;
extern struct weapon_firing_animation_table D_80030150;
extern struct weapon_firing_animation_table D_80030198;
extern struct weapon_firing_animation_table D_800301E0;
extern struct weapon_firing_animation_table D_80030228;
extern struct weapon_firing_animation_table D_80030270;
extern struct weapon_firing_animation_table D_800302B8;
extern struct weapon_firing_animation_table D_80030300;
extern struct weapon_firing_animation_table D_80030348;
extern struct weapon_firing_animation_table D_80030390;
extern struct weapon_firing_animation_table D_800303D8;
extern struct weapon_firing_animation_table D_80030420;
extern struct weapon_firing_animation_table D_80030468;
extern struct weapon_firing_animation_table D_800304B0;
extern struct weapon_firing_animation_table D_800304F8;
extern struct weapon_firing_animation_table D_80030540;
extern struct weapon_firing_animation_table D_80030588;
extern struct weapon_firing_animation_table D_800305D0;
extern struct weapon_firing_animation_table D_80030618;
extern struct weapon_firing_animation_table D_80030660;
extern struct weapon_firing_animation_table D_800306A8;
extern struct weapon_firing_animation_table D_800306F0;
extern struct weapon_firing_animation_table D_80030738;
extern struct weapon_firing_animation_table D_80030780;
extern struct weapon_firing_animation_table D_800307C8;
extern struct weapon_firing_animation_table D_80030810;
extern struct weapon_firing_animation_table D_80030858;
extern struct weapon_firing_animation_table D_800308A0;
extern struct weapon_firing_animation_table D_800308E8;
extern struct weapon_firing_animation_table D_80030930;

extern float animation_rate;
extern int D_8002C904;
extern int D_8002C908;
extern int D_8002C90C;
extern int D_8002C910;

extern int D_8002CC58;
extern int show_patrols_flag;
extern int player1_guardID;
extern int ptr_guard_data;
extern int num_guards;
extern int D_8002CC6C[];
extern int D_8002CCA8;
extern int D_8002CCAC;
extern int D_8002CCB0;
extern int D_8002CCB4;
extern unsigned char D_8002CCB8;
extern int num_bodies;
extern int num_male_heads;
extern int num_female_heads;
extern int list_of_bodies[];
extern int random_male_heads[];
extern int random_female_heads[];
#endif
