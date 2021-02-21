#include "bondtypes.h"

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

asm(R"
glabel load_body_head_if_not_loaded
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(c_item_entries) 
  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
  sll   $t6, $t6, 2
  addu  $v0, $t6, $t7
  lw    $a2, ($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t8, ($a2)
  move  $a0, $a2
  bnezl $t8, .L7F0232D8
   move  $v0, $zero
  jal   load_object_into_memory
   lw    $a1, 4($v0)
  b     .L7F0232D8
   li    $v0, 1
  move  $v0, $zero
.L7F0232D8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051D90
.word 0x3dccccce /*0.10000001*/
glabel D_80051D94
.word 0x3f4ccccd /*0.80000001*/
glabel D_80051D98
.word 0x0
glabel D_80051D9C
.word 0x0

.text
glabel maybe_load_models_for_guards
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(c_item_entries) 
  addiu $t8, %lo(c_item_entries) # addiu $t8, $t8, -0x21f0
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lui   $at, %hi(D_80051D90)
  lwc1  $f6, %lo(D_80051D90)($at)
  lwc1  $f4, 8($v0)
  addiu $sp, $sp, -0x38
  lwc1  $f10, 0xc($v0)
  mul.s $f8, $f4, $f6
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x38($sp)
  move  $s0, $a2
  move  $s1, $a3
  sw    $a1, 0x3c($sp)
  swc1  $f8, 0x34($sp)
  sw    $zero, 0x2c($sp)
  li    $a0, 12
  sw    $v0, 0x24($sp)
  jal   cheatCheckIfOn
   swc1  $f10, 0x30($sp)
  beqz  $v0, .L7F023364
   lwc1  $f16, 0x34($sp)
  lui   $at, %hi(D_80051D94)
  lwc1  $f18, %lo(D_80051D94)($at)
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x34($sp)
.L7F023364:
  lw    $t9, ($s0)
  lw    $t0, 0x24($sp)
  bnez  $t9, .L7F02337C
   move  $a0, $s0
  jal   load_object_into_memory
   lw    $a1, 4($t0)
.L7F02337C:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $s0
  lw    $t1, 0x24($sp)
  lw    $v0, 0x3c($sp)
  lbu   $t2, 0x11($t1)
  bnezl $t2, .L7F0233F4
   lw    $t1, 0x4c($sp)
  bltzl $v0, .L7F0233F4
   lw    $t1, 0x4c($sp)
  lw    $t3, 8($s0)
  lw    $t4, 0x10($t3)
  beqz  $t4, .L7F0233F0
   sw    $t4, 0x2c($sp)
  lw    $t6, ($s1)
  sll   $t7, $v0, 2
  addu  $t7, $t7, $v0
  bnez  $t6, .L7F0233D8
   move  $a0, $s1
  sll   $t7, $t7, 2
  lui   $a1, %hi(c_item_entries+4)
  addu  $a1, $a1, $t7
  jal   load_object_into_memory
   lw    $a1, %lo(c_item_entries+4)($a1)
.L7F0233D8:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $s1
  lh    $t8, 0x14($s0)
  lh    $t9, 0x14($s1)
  addu  $t0, $t8, $t9
  sh    $t0, 0x14($s0)
.L7F0233F0:
  lw    $t1, 0x4c($sp)
.L7F0233F4:
  bnezl $t1, .L7F02340C
   lw    $t2, 0x4c($sp)
  jal   get_aircraft_obj_instance_controller
   move  $a0, $s0
  sw    $v0, 0x4c($sp)
  lw    $t2, 0x4c($sp)
.L7F02340C:
  beqz  $t2, .L7F023490
   move  $a0, $t2
  jal   set_obj_instance_controller_scale
   lw    $a1, 0x34($sp)
  lw    $a0, 0x4c($sp)
  jal   sub_GAME_7F06CE84
   lw    $a1, 0x30($sp)
  beqz  $s1, .L7F023490
   lw    $t3, 0x24($sp)
  lbu   $t4, 0x11($t3)
  bnezl $t4, .L7F023494
   lw    $ra, 0x1c($sp)
  lh    $t5, 0x14($s0)
  lh    $t6, 0x14($s1)
  move  $a2, $s1
  subu  $t7, $t5, $t6
  sh    $t7, 0x14($s0)
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06C3B4
   lw    $a0, 0x4c($sp)
  lw    $t8, 0x48($sp)
  bnezl $t8, .L7F023494
   lw    $ra, 0x1c($sp)
  lh    $t9, 0xc($s1)
  blezl $t9, .L7F023494
   lw    $ra, 0x1c($sp)
  lw    $t0, 8($s1)
  lw    $a1, ($t0)
  beql  $a1, $zero, .L7F023494
   lw    $ra, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x4c($sp)
  sw    $zero, ($v0)
.L7F023490:
  lw    $ra, 0x1c($sp)
.L7F023494:
  lw    $v0, 0x4c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051D90
.word 0x3dccccce /*0.10000001*/
glabel D_80051D94
.word 0x3f4ccccd /*0.80000001*/
glabel D_80051D98
.word 0x0
glabel D_80051D9C
.word 0x0
.text
glabel maybe_load_models_for_guards
  sll   $t7, $a0, 2
  addu  $t7, $t7, $a0
  lui   $t8, %hi(c_item_entries) # $t8, 0x8004
  addiu $t8, %lo(c_item_entries) # addiu $t8, $t8, -0x21c0
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lui   $at, %hi(D_80051D90) # $at, 0x8005
  lwc1  $f6, %lo(D_80051D90)($at)
  lwc1  $f4, 8($v0)
  addiu $sp, $sp, -0x38
  lwc1  $f10, 0xc($v0)
  mul.s $f8, $f4, $f6
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x38($sp)
  move  $s0, $a2
  move  $s1, $a3
  sw    $a1, 0x3c($sp)
  swc1  $f8, 0x34($sp)
  sw    $zero, 0x2c($sp)
  li    $a0, 12
  sw    $v0, 0x24($sp)
  jal   cheatCheckIfOn
   swc1  $f10, 0x30($sp)
  beqz  $v0, .Ljp7F023664
   lw    $a0, 0x38($sp)
  jal   jp_only_7F0209EC
   lw    $a1, 0x3c($sp)
  beqz  $v0, .Ljp7F023664
   lwc1  $f16, 0x34($sp)
  lui   $at, %hi(D_80051D94) # $at, 0x8005
  lwc1  $f18, %lo(D_80051D94)($at)
  mul.s $f4, $f16, $f18
  swc1  $f4, 0x34($sp)
.Ljp7F023664:
  lw    $t9, ($s0)
  lw    $t0, 0x24($sp)
  bnez  $t9, .Ljp7F02367C
   move  $a0, $s0
  jal   load_object_into_memory
   lw    $a1, 4($t0)
.Ljp7F02367C:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $s0
  lw    $t1, 0x24($sp)
  lw    $t3, 0x3c($sp)
  lbu   $t2, 0x11($t1)
  bnezl $t2, .Ljp7F0236F4
   lw    $t2, 0x4c($sp)
  bltzl $t3, .Ljp7F0236F4
   lw    $t2, 0x4c($sp)
  lw    $t4, 8($s0)
  lw    $t5, 0x10($t4)
  beqz  $t5, .Ljp7F0236F0
   sw    $t5, 0x2c($sp)
  lw    $t7, ($s1)
  sll   $t8, $t3, 2
  addu  $t8, $t8, $t3
  bnez  $t7, .Ljp7F0236D8
   move  $a0, $s1
  sll   $t8, $t8, 2
  lui   $a1, %hi(c_item_entries+4)
  addu  $a1, $a1, $t8
  jal   load_object_into_memory
   lw    $a1, %lo(c_item_entries+4)($a1)
.Ljp7F0236D8:
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   move  $a0, $s1
  lh    $t9, 0x14($s0)
  lh    $t0, 0x14($s1)
  addu  $t1, $t9, $t0
  sh    $t1, 0x14($s0)
.Ljp7F0236F0:
  lw    $t2, 0x4c($sp)
.Ljp7F0236F4:
  bnezl $t2, .Ljp7F02370C
   lw    $t4, 0x4c($sp)
  jal   get_aircraft_obj_instance_controller
   move  $a0, $s0
  sw    $v0, 0x4c($sp)
  lw    $t4, 0x4c($sp)
.Ljp7F02370C:
  beqz  $t4, .Ljp7F023790
   move  $a0, $t4
  jal   set_obj_instance_controller_scale
   lw    $a1, 0x34($sp)
  lw    $a0, 0x4c($sp)
  jal   sub_GAME_7F06CE84
   lw    $a1, 0x30($sp)
  beqz  $s1, .Ljp7F023790
   lw    $t5, 0x24($sp)
  lbu   $t6, 0x11($t5)
  bnezl $t6, .Ljp7F023794
   lw    $ra, 0x1c($sp)
  lh    $t7, 0x14($s0)
  lh    $t3, 0x14($s1)
  move  $a2, $s1
  subu  $t8, $t7, $t3
  sh    $t8, 0x14($s0)
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06C3B4
   lw    $a0, 0x4c($sp)
  lw    $t9, 0x48($sp)
  bnezl $t9, .Ljp7F023794
   lw    $ra, 0x1c($sp)
  lh    $t0, 0xc($s1)
  blezl $t0, .Ljp7F023794
   lw    $ra, 0x1c($sp)
  lw    $t1, 8($s1)
  lw    $a1, ($t1)
  beql  $a1, $zero, .Ljp7F023794
   lw    $ra, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x4c($sp)
  sw    $zero, ($v0)
.Ljp7F023790:
  lw    $ra, 0x1c($sp)
.Ljp7F023794:
  lw    $v0, 0x4c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
    
");
#endif

asm(R"
glabel sub_GAME_7F0234A8
  addiu $sp, $sp, -0x20
  lw    $t6, 0x30($sp)
  sw    $ra, 0x1c($sp)
  sw    $zero, 0x14($sp)
  jal   maybe_load_models_for_guards
   sw    $t6, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel retrieve_header_for_body_and_head
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  lui   $t7, %hi(c_item_entries) 
  addiu $t7, %lo(c_item_entries) # addiu $t7, $t7, -0x21f0
  sll   $t6, $t6, 2
  addu  $a3, $t6, $t7
  lw    $t8, ($a3)
  addiu $sp, $sp, -0x30
  andi  $t9, $a2, 1
  sw    $ra, 0x1c($sp)
  sw    $zero, 0x28($sp)
  move  $v1, $zero
  beqz  $t9, .L7F023510
   sw    $t8, 0x2c($sp)
  b     .L7F023544
   li    $v1, 1
.L7F023510:
  andi  $t0, $a2, 2
  beqz  $t0, .L7F023544
   nop   
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  jal   get_random_value
   sw    $a3, 0x20($sp)
  andi  $v1, $v0, 1
  sltiu $t1, $v1, 1
  move  $v1, $t1
  lw    $a0, 0x30($sp)
  lw    $a1, 0x34($sp)
  lw    $a3, 0x20($sp)
.L7F023544:
  bltzl $a1, .L7F023574
   lw    $a2, 0x2c($sp)
  lbu   $t2, 0x11($a3)
  sll   $t3, $a1, 2
  addu  $t3, $t3, $a1
  bnez  $t2, .L7F023570
   sll   $t3, $t3, 2
  lui   $t4, %hi(c_item_entries)
  addu  $t4, $t4, $t3
  lw    $t4, %lo(c_item_entries)($t4)
  sw    $t4, 0x28($sp)
.L7F023570:
  lw    $a2, 0x2c($sp)
.L7F023574:
  lw    $a3, 0x28($sp)
  jal   sub_GAME_7F0234A8
   sw    $v1, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

int get_current_random_body(void) {
  extern int list_of_bodies[];
  extern int current_random_body;
  return list_of_bodies[current_random_body];
}

asm(R"
glabel select_psuedorandom_heads
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  lui   $t7, %hi(c_item_entries+16)
  addu  $t7, $t7, $t6
  lbu   $t7, %lo(c_item_entries+16)($t7)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $t7, .L7F023638
   lui   $t3, %hi(current_random_female_head) 
  jal   get_random_value
   nop   
  lui   $t8, %hi(current_random_male_head) 
  lw    $t8, %lo(current_random_male_head)($t8)
  andi  $t9, $v0, 3
  lui   $t1, %hi(num_male_heads) 
  lw    $t1, %lo(num_male_heads)($t1)
  addu  $t0, $t8, $t9
  div   $zero, $t0, $t1
  mfhi  $v1
  sll   $t2, $v1, 2
  lui   $v1, %hi(random_male_heads)
  addu  $v1, $v1, $t2
  bnez  $t1, .L7F023614
   nop   
  break 7
.L7F023614:
  li    $at, -1
  bne   $t1, $at, .L7F02362C
   lui   $at, 0x8000
  bne   $t0, $at, .L7F02362C
   nop   
  break 6
.L7F02362C:
  lw    $v1, %lo(random_male_heads)($v1)
  b     .L7F023650
   lw    $ra, 0x14($sp)
.L7F023638:
  lw    $t3, %lo(current_random_female_head)($t3)
  lui   $v1, %hi(random_female_heads)
  sll   $t4, $t3, 2
  addu  $v1, $v1, $t4
  lw    $v1, %lo(random_female_heads)($v1)
  lw    $ra, 0x14($sp)
.L7F023650:
  addiu $sp, $sp, 0x18
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel get_random_head
  sll   $t6, $a0, 2
  addu  $t6, $t6, $a0
  sll   $t6, $t6, 2
  lui   $t7, %hi(c_item_entries+16)
  addu  $t7, $t7, $t6
  lbu   $t7, %lo(c_item_entries+16)($t7)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $t7, .L7F0236C4
   nop   
  jal   get_random_value
   nop   
  lui   $t8, %hi(num_male_heads) 
  lw    $t8, %lo(num_male_heads)($t8)
  lui   $v1, %hi(random_male_heads)
  divu  $zero, $v0, $t8
  mfhi  $t9
  sll   $t0, $t9, 2
  addu  $v1, $v1, $t0
  bnez  $t8, .L7F0236B8
   nop   
  break 7
.L7F0236B8:
  lw    $v1, %lo(random_male_heads)($v1)
  b     .L7F0236FC
   lw    $ra, 0x14($sp)
.L7F0236C4:
  jal   get_random_value
   nop   
  lui   $t1, %hi(num_female_heads) 
  lw    $t1, %lo(num_female_heads)($t1)
  lui   $v1, %hi(random_female_heads)
  divu  $zero, $v0, $t1
  mfhi  $t2
  sll   $t3, $t2, 2
  addu  $v1, $v1, $t3
  lw    $v1, %lo(random_female_heads)($v1)
  bnez  $t1, .L7F0236F8
   nop   
  break 7
.L7F0236F8:
  lw    $ra, 0x14($sp)
.L7F0236FC:
  addiu $sp, $sp, 0x18
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel expand_09_characters
  addiu $sp, $sp, -0x60
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x60($sp)
  sw    $a2, 0x68($sp)
  lhu   $t6, 6($a1)
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  move  $s0, $a1
  addu  $a0, $t7, $t8
  lw    $a1, 0x28($a0)
  addiu $t9, $sp, 0x54
  sw    $t9, 0x10($sp)
  sw    $a0, 0x5c($sp)
  lui   $a2, 0x41a0
  jal   sub_GAME_7F056850
   addiu $a3, $sp, 0x48
  beqz  $v0, .L7F0238FC
   li    $t0, -1
  sw    $t0, 0x30($sp)
  lhu   $v0, 8($s0)
  li    $at, 65535
  bnel  $v0, $at, .L7F023794
   sw    $v0, 0x34($sp)
  jal   get_current_random_body
   nop   
  b     .L7F023794
   sw    $v0, 0x34($sp)
  sw    $v0, 0x34($sp)
.L7F023794:
  lw    $t1, 0x34($sp)
  lui   $t3, %hi(c_item_entries+17)
  sll   $t2, $t1, 2
  addu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $t3, $t3, $t2
  lbu   $t3, %lo(c_item_entries+17)($t3)
  bnezl $t3, .L7F0237DC
   lw    $a0, 0x34($sp)
  lh    $v0, 0x16($s0)
  bltz  $v0, .L7F0237CC
   nop   
  b     .L7F0237D8
   sw    $v0, 0x30($sp)
.L7F0237CC:
  jal   select_psuedorandom_heads
   lw    $a0, 0x34($sp)
  sw    $v0, 0x30($sp)
.L7F0237D8:
  lw    $a0, 0x34($sp)
.L7F0237DC:
  lw    $a1, 0x30($sp)
  jal   retrieve_header_for_body_and_head
   lhu   $a2, 0x14($s0)
  beqz  $v0, .L7F0238FC
   sw    $v0, 0x38($sp)
  lw    $v0, 0x5c($sp)
  lwc1  $f12, 0x18($v0)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x20($v0)
  swc1  $f0, 0x3c($sp)
  jal   LoadNext_PrevActionBlock
   lhu   $a0, 0xa($s0)
  lw    $a0, 0x38($sp)
  addiu $a1, $sp, 0x48
  lw    $a2, 0x3c($sp)
  lw    $a3, 0x54($sp)
  jal   replace_GUARDdata_with_actual_values
   sw    $v0, 0x10($sp)
  beqz  $v0, .L7F0238FC
   move  $a0, $v0
  jal   set_current_objposdata_plus_0x28
   sw    $v0, 0x44($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x44($sp)
  lw    $t4, 0x44($sp)
  lhu   $t5, 4($s0)
  li    $at, 0x4F800000 # 4294967296.000000
  lw    $v0, 4($t4)
  sh    $t5, ($v0)
  lhu   $t6, 0x10($s0)
  mtc1  $t6, $f4
  bgez  $t6, .L7F02386C
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F02386C:
  li    $at, 0x447A0000 # 1000.000000
  mtc1  $at, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  div.s $f16, $f6, $f10
  swc1  $f16, 0xec($v0)
  lhu   $t7, 0x12($s0)
  mtc1  $t7, $f18
  bgez  $t7, .L7F02389C
   cvt.s.w $f4, $f18
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L7F02389C:
  swc1  $f4, 0xd0($v0)
  lhu   $t8, 0xc($s0)
  sh    $t8, 0x114($v0)
  lhu   $t9, 0xe($s0)
  sh    $t9, 0x116($v0)
  lw    $t0, 0x30($sp)
  sb    $t0, 6($v0)
  lw    $t1, 0x34($sp)
  sb    $t1, 0xf($v0)
  lhu   $v1, 0x14($s0)
  andi  $t2, $v1, 4
  beql  $t2, $zero, .L7F0238E4
   andi  $t5, $v1, 8
  lw    $t3, 0x14($v0)
  ori   $t4, $t3, 2
  sw    $t4, 0x14($v0)
  lhu   $v1, 0x14($s0)
  andi  $t5, $v1, 8
.L7F0238E4:
  beql  $t5, $zero, .L7F0238FC
   sw    $v0, 0x18($s0)
  lw    $t6, 0x14($v0)
  ori   $t7, $t6, 0x10
  sw    $t7, 0x14($v0)
  sw    $v0, 0x18($s0)
.L7F0238FC:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");

asm(R"
glabel check_if_item_held_like_pistol
  addiu $sp, $sp, -0x18
  beqz  $a0, .L7F023934
   sw    $ra, 0x14($sp)
  lw    $v0, 4($a0)
  li    $a1, 256
  jal   check_special_attributes
   lb    $a0, 0x80($v0)
  b     .L7F02393C
   lw    $ra, 0x14($sp)
.L7F023934:
  move  $v0, $zero
  lw    $ra, 0x14($sp)
.L7F02393C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F023948
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x34($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lw    $a0, 0x2c($sp)
  sw    $v0, 0x28($sp)
  beqz  $a0, .L7F02398C
   nop   
  bnez  $v0, .L7F0239BC
   nop   
.L7F02398C:
  bnez  $a0, .L7F02399C
   nop   
  beqz  $v0, .L7F0239BC
   nop   
.L7F02399C:
  jal   check_if_item_held_like_pistol
   nop   
  bnez  $v0, .L7F0239BC
   nop   
  jal   check_if_item_held_like_pistol
   lw    $a0, 0x28($sp)
  beqz  $v0, .L7F023A14
   lw    $t8, 0x28($sp)
.L7F0239BC:
  jal   get_random_value
   nop   
  lui   $t6, %hi(ptr_animation_table) 
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f4
  lw    $t6, %lo(ptr_animation_table)($t6)
  lwc1  $f6, 0x34($sp)
  lui   $t7, %hi(0x00008194) # $t7, 1
  addiu $t7, %lo(0x00008194) # addiu $t7, $t7, -0x7e6c
  lw    $a0, 0x1c($s0)
  andi  $a2, $v0, 1
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  addu  $a1, $t6, $t7
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $a0, 0x1c($s0)
  li    $a1, 0
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  b     .L7F023A84
   lw    $ra, 0x24($sp)
.L7F023A14:
  bnez  $t8, .L7F023A24
   lw    $t9, 0x2c($sp)
  beql  $t9, $zero, .L7F023A84
   lw    $ra, 0x24($sp)
.L7F023A24:
  lw    $a2, 0x2c($sp)
  lui   $t0, %hi(ptr_animation_table) 
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  lw    $t0, %lo(ptr_animation_table)($t0)
  lwc1  $f10, 0x34($sp)
  lui   $t1, %hi(0x0000001C) # $t1, 0
  addiu $t1, %lo(0x0000001C) # addiu $t1, $t1, 0x1c
  lw    $a0, 0x1c($s0)
  sltu  $t2, $zero, $a2
  move  $a2, $t2
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $t0, $t1
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lw    $a0, 0x1c($s0)
  li    $a1, 0
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x42f0
  lw    $ra, 0x24($sp)
.L7F023A84:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F023A94
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  jal   sub_GAME_7F02D184
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  li    $t6, 1
  li    $t7, 2
  sb    $t6, 7($a0)
  sw    $zero, 0x2c($a0)
  sw    $zero, 0x30($a0)
  sw    $zero, 0x34($a0)
  sw    $zero, 0x38($a0)
  sw    $t7, 0x3c($a0)
  jal   get_random_value
   sw    $zero, 0x40($a0)
  li    $at, 120
  divu  $zero, $v0, $at
  lw    $a0, 0x18($sp)
  mfhi  $t8
  lwc1  $f12, 0x1c($sp)
  lw    $t0, 0x1c($a0)
  addiu $t9, $t8, 0xb4
  li    $at, 0x3F800000 # 1.000000
  sw    $t9, 0x44($a0)
  mtc1  $at, $f4
  lwc1  $f2, 0xa4($t0)
  li    $at, 0x42FE0000 # 127.000000
  mov.s $f0, $f12
  c.eq.s $f4, $f2
  nop   
  bc1tl .L7F023B20
   mtc1  $at, $f2
  div.s $f0, $f12, $f2
  mtc1  $at, $f2
.L7F023B20:
  nop   
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F023B3C
   trunc.w.s $f6, $f0
  mov.s $f0, $f2
  trunc.w.s $f6, $f0
.L7F023B3C:
  mfc1  $a1, $f12
  mfc1  $t2, $f6
  jal   sub_GAME_7F023948
   sb    $t2, 8($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F023A94
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  jal   sub_GAME_7F02D184
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  li    $t6, 1
  li    $t7, 2
  sb    $t6, 7($a0)
  sw    $zero, 0x2c($a0)
  sw    $zero, 0x30($a0)
  sw    $zero, 0x34($a0)
  sw    $zero, 0x38($a0)
  sw    $t7, 0x3c($a0)
  jal   get_random_value
   sw    $zero, 0x40($a0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f14
  li    $at, 120
  divu  $zero, $v0, $at
  lw    $a0, 0x18($sp)
  mfhi  $t8
  lwc1  $f12, 0x1c($sp)
  lw    $t0, 0x1c($a0)
  addiu $t9, $t8, 0xb4
  sw    $t9, 0x44($a0)
  lwc1  $f2, 0xa4($t0)
  li    $at, 0x42FE0000 # 127.000000
  mov.s $f0, $f12
  c.eq.s $f14, $f2
  nop   
  bc1tl .L7F023E28
   mtc1  $at, $f2
  div.s $f4, $f14, $f2
  mul.s $f0, $f12, $f4
  nop   
  mtc1  $at, $f2
.L7F023E28:
  nop   
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F023E44
   trunc.w.s $f6, $f0
  mov.s $f0, $f2
  trunc.w.s $f6, $f0
.L7F023E44:
  mfc1  $a1, $f12
  mfc1  $t2, $f6
  jal   sub_GAME_7F023948
   sb    $t2, 8($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
    
");
#endif

asm(R"
glabel sub_GAME_7F023B5C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  lb    $t6, 3($a0)
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f2, $f4
  jal   get_007_reaction_speed
   swc1  $f2, 0x1c($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lwc1  $f2, 0x1c($sp)
  lwc1  $f14, 0x24($sp)
  lwc1  $f10, 0x28($sp)
  sub.s $f6, $f12, $f2
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  sub.s $f16, $f10, $f14
  mul.s $f8, $f0, $f6
  add.s $f2, $f8, $f2
  mul.s $f18, $f16, $f2
  div.s $f4, $f18, $f12
  jr    $ra
   add.s $f0, $f4, $f14
");

asm(R"
glabel sub_GAME_7F023BC0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  lb    $v1, 3($a0)
  jal   get_007_reaction_speed
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  li    $a0, 100
  lw    $t0, 0x24($sp)
  subu  $t6, $a0, $v1
  mtc1  $t6, $f4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  cvt.s.w $f6, $f4
  mul.s $f8, $f0, $f6
  trunc.w.s $f10, $f8
  mfc1  $t8, $f10
  nop   
  addu  $v1, $t8, $v1
  subu  $t9, $a0, $v1
  multu $t9, $t0
  mflo  $t1
  nop   
  nop   
  div   $zero, $t1, $a0
  mflo  $v0
  bnez  $a0, .L7F023C34
   nop   
  break 7
.L7F023C34:
  li    $at, -1
  bne   $a0, $at, .L7F023C4C
   lui   $at, 0x8000
  bne   $t1, $at, .L7F023C4C
   nop   
  break 6
.L7F023C4C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F023C54
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  lb    $t6, 0xd($a0)
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f2, $f4
  jal   get_007_reaction_speed
   swc1  $f2, 0x1c($sp)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f12
  lwc1  $f2, 0x1c($sp)
  lwc1  $f14, 0x24($sp)
  lwc1  $f10, 0x28($sp)
  sub.s $f6, $f12, $f2
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  sub.s $f16, $f10, $f14
  mul.s $f8, $f0, $f6
  add.s $f2, $f8, $f2
  mul.s $f18, $f16, $f2
  div.s $f4, $f18, $f12
  jr    $ra
   add.s $f0, $f4, $f14
");

asm(R"
glabel sub_GAME_7F023CB8
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lb    $t6, 7($a0)
  li    $at, 2
  move  $s0, $a0
  bne   $t6, $at, .L7F023DF8
   lui   $a1, 0x4180
  jal   sub_GAME_7F02D184
   nop   
  li    $v0, 1
  li    $t7, 2
  sb    $v0, 7($s0)
  sw    $v0, 0x2c($s0)
  sw    $zero, 0x30($s0)
  sw    $zero, 0x34($s0)
  sw    $zero, 0x38($s0)
  sw    $t7, 0x3c($s0)
  jal   get_random_value
   sw    $zero, 0x40($s0)
  li    $at, 120
  divu  $zero, $v0, $at
  mfhi  $t8
  addiu $t9, $t8, 0xb4
  sw    $t9, 0x44($s0)
  sb    $zero, 8($s0)
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s0)
  lui   $t0, %hi(ptr_animation_table) 
  lw    $t0, %lo(ptr_animation_table)($t0)
  lui   $v1, %hi(0x00006C18) # $v1, 0
  addiu $v1, %lo(0x00006C18) # addiu $v1, $v1, 0x6c18
  addu  $t1, $v1, $t0
  bne   $v0, $t1, .L7F023DA0
   move  $a0, $s0
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  lui   $a1, 0x3f00
  jal   sub_GAME_7F023B5C
   sw    $v1, 0x28($sp)
  lw    $a0, 0x1c($s0)
  lui   $t2, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t2, %lo(ptr_animation_table)($t2)
  lw    $v1, 0x28($sp)
  lb    $a2, 0x24($a0)
  swc1  $f0, 0x10($sp)
  lui   $a3, 0x42da
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $v1, $t2
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x430c
  b     .L7F023E04
   lw    $ra, 0x24($sp)
.L7F023DA0:
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $a0, 0x1c($s0)
  lui   $t3, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t3, %lo(ptr_animation_table)($t3)
  lui   $t4, %hi(0x00000B84) # $t4, 0
  addiu $t4, %lo(0x00000B84) # addiu $t4, $t4, 0xb84
  lb    $a2, 0x24($a0)
  swc1  $f0, 0x10($sp)
  lui   $a3, 0x42f0
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t3, $t4
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4317
  b     .L7F023E04
   lw    $ra, 0x24($sp)
.L7F023DF8:
  jal   sub_GAME_7F023A94
   move  $a0, $s0
  lw    $ra, 0x24($sp)
.L7F023E04:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F023E14
  mtc1  $a1, $f12
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  mfc1  $a1, $f12
  jal   sub_GAME_7F023A94
   sw    $a0, 0x18($sp)
  lw    $t7, 0x18($sp)
  li    $t6, 1
  sw    $t6, 0x40($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F023E48
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F023CB8
   sw    $a0, 0x18($sp)
  lw    $t7, 0x18($sp)
  li    $t6, 1
  sw    $t6, 0x40($t7)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel actor_kneel
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x34($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  sw    $v0, 0x30($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  lw    $a0, 0x34($sp)
  lw    $t6, 0x30($sp)
  beqz  $a0, .L7F023EC0
   nop   
  bnez  $t6, .L7F023EF0
   nop   
.L7F023EC0:
  bnez  $a0, .L7F023ED0
   lw    $t7, 0x30($sp)
  beqz  $t7, .L7F023EF0
   nop   
.L7F023ED0:
  jal   check_if_item_held_like_pistol
   nop   
  bnez  $v0, .L7F023EF0
   nop   
  jal   check_if_item_held_like_pistol
   lw    $a0, 0x30($sp)
  beqz  $v0, .L7F023F5C
   lw    $t1, 0x30($sp)
.L7F023EF0:
  jal   get_random_value
   nop   
  andi  $t8, $v0, 1
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  sw    $t8, 0x2c($sp)
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lui   $t9, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t9, %lo(ptr_animation_table)($t9)
  lui   $t0, %hi(0x00006C18) # $t0, 0
  addiu $t0, %lo(0x00006C18) # addiu $t0, $t0, 0x6c18
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  li    $a3, 0
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t9, $t0
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x41e0
  b     .L7F023FC8
   li    $t6, 2
.L7F023F5C:
  bnez  $t1, .L7F023F68
   lw    $t2, 0x34($sp)
  beqz  $t2, .L7F023FC4
.L7F023F68:
   lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $a2, 0x34($sp)
  lui   $t3, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t3, %lo(ptr_animation_table)($t3)
  lui   $t4, %hi(0x00000B84) # $t4, 0
  addiu $t4, %lo(0x00000B84) # addiu $t4, $t4, 0xb84
  lw    $a0, 0x1c($s0)
  sltu  $t5, $zero, $a2
  move  $a2, $t5
  swc1  $f0, 0x10($sp)
  li    $a3, 0
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t3, $t4
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x41d8
.L7F023FC4:
  li    $t6, 2
.L7F023FC8:
  sb    $t6, 7($s0)
  sb    $zero, 8($s0)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel perform_animation_for_actor
  addiu $sp, $sp, -0x30
  sw    $s1, 0x20($sp)
  lbu   $s1, 0x43($sp)
  li    $at, 0x3F000000 # 0.500000
  sw    $s0, 0x1c($sp)
  mtc1  $at, $f0
  andi  $t6, $s1, 0x80
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  beqz  $t6, .L7F024024
   sw    $a3, 0x3c($sp)
  li    $at, 0xBF000000 # -0.500000
  mtc1  $at, $f0
  nop   
.L7F024024:
  move  $a0, $s0
  jal   sub_GAME_7F02D184
   swc1  $f0, 0x28($sp)
  lw    $t0, 0x38($sp)
  lw    $t1, 0x44($sp)
  lw    $t7, 0x34($sp)
  mtc1  $t0, $f4
  mtc1  $t1, $f6
  lwc1  $f0, 0x28($sp)
  cvt.s.w $f4, $f4
  lui   $a1, %hi(animation_table_ptrs1)
  andi  $a2, $s1, 1
  sll   $t8, $t7, 2
  addu  $a1, $a1, $t8
  cvt.s.w $f8, $f6
  sltu  $t9, $zero, $a2
  mfc1  $a3, $f4
  lw    $a0, 0x1c($s0)
  move  $a2, $t9
  lw    $a1, %lo(animation_table_ptrs1)($a1)
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f0, 0x10($sp)
  lw    $v0, 0x3c($sp)
  bltzl $v0, .L7F0240A8
   andi  $t2, $s1, 0x20
  mtc1  $v0, $f10
  lw    $a0, 0x1c($s0)
  cvt.s.w $f10, $f10
  mfc1  $a1, $f10
  jal   sub_GAME_7F06FDE8
   nop   
  andi  $t2, $s1, 0x20
.L7F0240A8:
  beql  $t2, $zero, .L7F0240D4
   lw    $t3, 0x14($s0)
  lw    $a0, 0x1c($s0)
  li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f18
  lwc1  $f16, 0xb8($a0)
  mul.s $f4, $f16, $f18
  mfc1  $a1, $f4
  jal   sub_GAME_7F06CE84
   nop   
  lw    $t3, 0x14($s0)
.L7F0240D4:
  lui   $at, (0xFDFFFFFF >> 16) # lui $at, 0xfdff
  ori   $at, (0xFDFFFFFF & 0xFFFF) # ori $at, $at, 0xffff
  and   $t4, $t3, $at
  sw    $t4, 0x14($s0)
  andi  $t6, $s1, 2
  andi  $t8, $s1, 4
  andi  $t0, $s1, 8
  andi  $v0, $s1, 0x10
  andi  $t3, $s1, 0x40
  li    $t5, 3
  sltu  $t7, $zero, $t6
  sltu  $t9, $zero, $t8
  sltu  $t1, $zero, $t0
  sltu  $t2, $zero, $v0
  sltu  $t4, $zero, $t3
  sb    $t5, 7($s0)
  sw    $t7, 0x2c($s0)
  sw    $t9, 0x30($s0)
  sw    $t1, 0x34($s0)
  sw    $t2, 0x38($s0)
  beqz  $t2, .L7F024138
   sw    $t4, 0x3c($s0)
  lw    $t5, 0x44($sp)
  b     .L7F02413C
   sb    $t5, 8($s0)
.L7F024138:
  sb    $zero, 8($s0)
.L7F02413C:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F024150
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  move  $a0, $s0
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x34($sp)
  lw    $v1, 0x34($sp)
  move  $a2, $zero
  beqz  $v1, .L7F024198
   nop   
  bnez  $v0, .L7F024198
   nop   
  b     .L7F0241C4
   li    $a2, 1
.L7F024198:
  beqz  $v1, .L7F0241A8
   nop   
  bnez  $v0, .L7F0241B8
   nop   
.L7F0241A8:
  bnezl $v1, .L7F0241C8
   move  $a0, $s0
  bnezl $v0, .L7F0241C8
   move  $a0, $s0
.L7F0241B8:
  jal   get_random_value
   nop   
  andi  $a2, $v0, 1
.L7F0241C4:
  move  $a0, $s0
.L7F0241C8:
  jal   sub_GAME_7F02D184
   sw    $a2, 0x2c($sp)
  lw    $a2, 0x2c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $t6, 19
  sb    $t6, 7($s0)
  sb    $zero, 8($s0)
  li    $at, 0x41800000 # 16.000000
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  mtc1  $at, $f6
  lui   $t8, %hi(0x00005744) # $t8, 0
  addiu $t8, %lo(0x00005744) # addiu $t8, $t8, 0x5744
  lw    $a0, 0x1c($s0)
  lui   $a3, 0x4220
  swc1  $f4, 0x10($sp)
  addu  $a1, $t7, $t8
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x42a4
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel throw_weapon_in_guard_hand
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  jal   sub_GAME_7F02D184
   sw    $a3, 0x34($sp)
  li    $t6, 20
  sb    $t6, 7($s0)
  sb    $zero, 8($s0)
  lw    $t7, 0x34($sp)
  move  $a0, $s0
  lui   $a1, 0x3f00
  beqz  $t7, .L7F0242D0
   lui   $a2, 0x3f4c
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $a2, 0x30($sp)
  lui   $t8, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t8, %lo(ptr_animation_table)($t8)
  lui   $t9, %hi(0x00005964) # $t9, 0
  addiu $t9, %lo(0x00005964) # addiu $t9, $t9, 0x5964
  lw    $a0, 0x1c($s0)
  sltu  $t0, $zero, $a2
  move  $a2, $t0
  swc1  $f0, 0x10($sp)
  li    $a3, 0
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t8, $t9
  b     .L7F024318
   lw    $a0, 0x1c($s0)
.L7F0242D0:
  jal   sub_GAME_7F023B5C
   ori   $a2, $a2, 0xcccd
  lw    $a2, 0x30($sp)
  lui   $t1, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t1, %lo(ptr_animation_table)($t1)
  lui   $t2, %hi(0x00005964) # $t2, 0
  addiu $t2, %lo(0x00005964) # addiu $t2, $t2, 0x5964
  lw    $a0, 0x1c($s0)
  sltu  $t3, $zero, $a2
  move  $a2, $t3
  swc1  $f0, 0x10($sp)
  lui   $a3, 0x42a8
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t1, $t2
  lw    $a0, 0x1c($s0)
.L7F024318:
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4341
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024334
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x3c($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  move  $a0, $s0
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x34($sp)
  lw    $v1, 0x34($sp)
  sw    $zero, 0x2c($sp)
  beqz  $v1, .L7F024380
   nop   
  bnez  $v0, .L7F024380
   li    $t6, 1
  b     .L7F0243B0
   sw    $t6, 0x2c($sp)
.L7F024380:
  beqz  $v1, .L7F024390
   nop   
  bnez  $v0, .L7F0243A0
   nop   
.L7F024390:
  bnezl $v1, .L7F0243B4
   lui   $a1, 0x3f19
  bnezl $v0, .L7F0243B4
   lui   $a1, 0x3f19
.L7F0243A0:
  jal   get_random_value
   nop   
  andi  $t7, $v0, 1
  sw    $t7, 0x2c($sp)
.L7F0243B0:
  lui   $a1, (0x3F19999A >> 16) # lui $a1, 0x3f19
.L7F0243B4:
  lui   $a2, (0x3F75C290 >> 16) # lui $a2, 0x3f75
  ori   $a2, (0x3F75C290 & 0xFFFF) # ori $a2, $a2, 0xc290
  ori   $a1, (0x3F19999A & 0xFFFF) # ori $a1, $a1, 0x999a
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  lwc1  $f4, 0x3c($sp)
  lui   $t9, %hi(0x00005D10) # $t9, 0
  addiu $t9, %lo(0x00005D10) # addiu $t9, $t9, 0x5d10
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x4120
  addu  $a1, $t8, $t9
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4250
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DA0
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80051DA4
.word 0x40c37a15 /*6.1086526*/
.text
glabel actor_shuffle_feet
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   sub_GAME_7F032C4C
   move  $s0, $a0
  lui   $at, %hi(D_80051DA0)
  lwc1  $f4, %lo(D_80051DA0)($at)
  lui   $at, %hi(D_80051DA4)
  move  $a0, $s0
  c.lt.s $f0, $f4
  nop   
  bc1t  .L7F024460
   nop   
  lwc1  $f6, %lo(D_80051DA4)($at)
  c.lt.s $f6, $f0
  nop   
  bc1f  .L7F024480
   nop   
.L7F024460:
  jal   sub_GAME_7F024334
   lui   $a1, 0x4180
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  li    $t6, 18
  sb    $t6, 7($s0)
  b     .L7F024498
   sb    $zero, 8($s0)
.L7F024480:
  jal   check_if_actor_stationary
   move  $a0, $s0
  bnezl $v0, .L7F02449C
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F023CB8
   move  $a0, $s0
.L7F024498:
  lw    $ra, 0x1c($sp)
.L7F02449C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel actor_fawn_on_shoulder
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   sub_GAME_7F02D184
   move  $s0, $a0
  li    $t6, 18
  sb    $t6, 7($s0)
  jal   get_random_value
   sb    $zero, 8($s0)
  lui   $a1, (0x3EB33333 >> 16) # lui $a1, 0x3eb3
  lui   $a2, (0x3F0F5C29 >> 16) # lui $a2, 0x3f0f
  ori   $a2, (0x3F0F5C29 & 0xFFFF) # ori $a2, $a2, 0x5c29
  ori   $a1, (0x3EB33333 & 0xFFFF) # ori $a1, $a1, 0x3333
  sw    $v0, 0x28($sp)
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lw    $a2, 0x28($sp)
  lui   $t7, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x00004384) # $t8, 0
  addiu $t8, %lo(0x00004384) # addiu $t8, $t8, 0x4384
  lw    $a0, 0x1c($s0)
  andi  $t9, $a2, 1
  move  $a2, $t9
  swc1  $f0, 0x10($sp)
  li    $a3, 0
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t7, $t8
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x40e0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DA8
.word 0x3f19999a /*0.60000002*/
.text
glabel actor_look_flustered
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   get_random_value
   move  $s0, $a0
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t6
  sw    $t6, 0x2c($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  li    $t7, 18
  sb    $t7, 7($s0)
  jal   get_random_value
   sb    $zero, 8($s0)
  lui   $at, %hi(D_80051DA8)
  lwc1  $f4, %lo(D_80051DA8)($at)
  li    $at, 0x41800000 # 16.000000
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  mtc1  $at, $f6
  lui   $t9, %hi(0x00005EF0) # $t9, 0
  addiu $t9, %lo(0x00005EF0) # addiu $t9, $t9, 0x5ef0
  lw    $a0, 0x1c($s0)
  andi  $a2, $v0, 1
  lui   $a3, 0x4188
  swc1  $f4, 0x10($sp)
  addu  $a1, $t8, $t9
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $v0, 0x2c($sp)
  move  $a0, $s0
  lui   $a1, 0x4218
  bnez  $v0, .L7F0245F0
   li    $at, 1
  jal   sub_GAME_7F023B5C
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x1c($s0)
  b     .L7F024638
   lw    $ra, 0x24($sp)
.L7F0245F0:
  bne   $v0, $at, .L7F02461C
   move  $a0, $s0
  move  $a0, $s0
  lui   $a1, 0x4284
  jal   sub_GAME_7F023B5C
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x1c($s0)
  b     .L7F024638
   lw    $ra, 0x24($sp)
.L7F02461C:
  lui   $a1, 0x42c0
  jal   sub_GAME_7F023B5C
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x1c($s0)
  lw    $ra, 0x24($sp)
.L7F024638:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel actor_throw_weapon_surrender
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lb    $t6, 7($a0)
  li    $at, 16
  move  $s0, $a0
  beql  $t6, $at, .L7F0247A8
   lw    $ra, 0x24($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  sw    $v0, 0x28($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  li    $t7, 16
  sb    $t7, 7($s0)
  lw    $t8, 0x28($sp)
  lw    $t9, 0x2c($sp)
  bnez  $t8, .L7F0246AC
   nop   
  beqz  $t9, .L7F024740
   nop   
.L7F0246AC:
  jal   get_random_value
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $at, 0x41800000 # 16.000000
  lui   $t0, %hi(ptr_animation_table) 
  lw    $t0, %lo(ptr_animation_table)($t0)
  mtc1  $at, $f6
  lui   $t1, %hi(0x00004504) # $t1, 0
  addiu $t1, %lo(0x00004504) # addiu $t1, $t1, 0x4504
  lw    $a0, 0x1c($s0)
  andi  $a2, $v0, 1
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  addu  $a1, $t0, $t1
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $a0, 0x1c($s0)
  lui   $a1, 0x4220
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  li    $t2, 16
  sb    $t2, 8($s0)
  lw    $t3, 0x2c($sp)
  beqz  $t3, .L7F02471C
   move  $a0, $t3
  jal   sub_GAME_7F04BFD0
   li    $a1, 2
.L7F02471C:
  lw    $a0, 0x28($sp)
  beql  $a0, $zero, .L7F024734
   lhu   $t4, 0x12($s0)
  jal   sub_GAME_7F04BFD0
   li    $a1, 2
  lhu   $t4, 0x12($s0)
.L7F024734:
  ori   $t5, $t4, 1
  b     .L7F02479C
   sh    $t5, 0x12($s0)
.L7F024740:
  jal   get_random_value
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  li    $at, 0x41800000 # 16.000000
  lui   $t6, %hi(ptr_animation_table) 
  lw    $t6, %lo(ptr_animation_table)($t6)
  mtc1  $at, $f10
  lui   $t7, %hi(0x00004384) # $t7, 0
  addiu $t7, %lo(0x00004384) # addiu $t7, $t7, 0x4384
  lw    $a0, 0x1c($s0)
  andi  $a2, $v0, 1
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $t6, $t7
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lw    $a0, 0x1c($s0)
  lui   $a1, 0x41f0
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  li    $t8, 16
  sb    $t8, 8($s0)
.L7F02479C:
  jal   sub_GAME_7F021B20
   move  $a0, $s0
  lw    $ra, 0x24($sp)
.L7F0247A8:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel actor_fade_away
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 7($a0)
  li    $at, 5
  beql  $t6, $at, .L7F0247F4
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F02D184
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  li    $t7, 5
  li    $t8, -1
  sb    $t7, 7($a0)
  sw    $t8, 0x2c($a0)
  sb    $zero, 8($a0)
  lw    $ra, 0x14($sp)
.L7F0247F4:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024800
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x3c($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x34($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lw    $a0, 0x34($sp)
  sw    $v0, 0x30($sp)
  sw    $zero, 0x2c($sp)
  beqz  $a0, .L7F024864
   move  $v1, $zero
  beqz  $v0, .L7F024864
   nop   
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  jal   get_random_value
   sw    $t6, 0x2c($sp)
  b     .L7F0248AC
   andi  $v1, $v0, 1
.L7F024864:
  jal   check_if_item_held_like_pistol
   sw    $v1, 0x28($sp)
  bnez  $v0, .L7F0248AC
   lw    $v1, 0x28($sp)
  lw    $a0, 0x30($sp)
  jal   check_if_item_held_like_pistol
   sw    $v1, 0x28($sp)
  bnez  $v0, .L7F0248AC
   lw    $v1, 0x28($sp)
  lw    $v0, 0x34($sp)
  lw    $t7, 0x30($sp)
  bnez  $v0, .L7F0248A0
   sltu  $t8, $zero, $v0
  beql  $t7, $zero, .L7F0248B0
   move  $a0, $s0
.L7F0248A0:
  jal   get_random_value
   sw    $t8, 0x2c($sp)
  andi  $v1, $v0, 1
.L7F0248AC:
  move  $a0, $s0
.L7F0248B0:
  jal   sub_GAME_7F02D184
   sw    $v1, 0x28($sp)
  lw    $v1, 0x28($sp)
  li    $t9, 11
  sb    $t9, 7($s0)
  bnez  $v1, .L7F024994
   sb    $zero, 8($s0)
  lw    $t0, 0x3c($sp)
  lui   $a1, (0x3F0CCCCD >> 16) # lui $a1, 0x3f0c
  ori   $a1, (0x3F0CCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  beqz  $t0, .L7F024940
   move  $a0, $s0
  lui   $a1, (0x3F0CCCCD >> 16) # lui $a1, 0x3f0c
  lui   $a2, (0x3F6147AF >> 16) # lui $a2, 0x3f61
  ori   $a2, (0x3F6147AF & 0xFFFF) # ori $a2, $a2, 0x47af
  ori   $a1, (0x3F0CCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lui   $t1, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t1, %lo(ptr_animation_table)($t1)
  lui   $t2, %hi(0x00003D9C) # $t2, 0
  addiu $t2, %lo(0x00003D9C) # addiu $t2, $t2, 0x3d9c
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  move  $a2, $zero
  lui   $a3, 0x40a0
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t1, $t2
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x41d8
  b     .L7F024A74
   lw    $ra, 0x24($sp)
.L7F024940:
  lui   $a2, (0x3F6147AF >> 16) # lui $a2, 0x3f61
  jal   sub_GAME_7F023B5C
   ori   $a2, (0x3F6147AF & 0xFFFF) # ori $a2, $a2, 0x47af
  lui   $t3, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t3, %lo(ptr_animation_table)($t3)
  lui   $t4, %hi(0x00003D9C) # $t4, 0
  addiu $t4, %lo(0x00003D9C) # addiu $t4, $t4, 0x3d9c
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  li    $a2, 1
  lui   $a3, 0x40a0
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t3, $t4
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x41d8
  b     .L7F024A74
   lw    $ra, 0x24($sp)
.L7F024994:
  lw    $v0, 0x3c($sp)
  lw    $t5, 0x2c($sp)
  beqz  $v0, .L7F0249AC
   nop   
  beql  $t5, $zero, .L7F0249BC
   lui   $a1, 0x3f33
.L7F0249AC:
  bnez  $v0, .L7F024A18
   lw    $t6, 0x2c($sp)
  beqz  $t6, .L7F024A18
   lui   $a1, (0x3F333333 >> 16) # lui $a1, 0x3f33
.L7F0249BC:
  lui   $a2, (0x3F8F5C29 >> 16) # lui $a2, 0x3f8f
  ori   $a2, (0x3F8F5C29 & 0xFFFF) # ori $a2, $a2, 0x5c29
  ori   $a1, (0x3F333333 & 0xFFFF) # ori $a1, $a1, 0x3333
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lui   $t7, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f8
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x00005554) # $t8, 0
  addiu $t8, %lo(0x00005554) # addiu $t8, $t8, 0x5554
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x40a0
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t7, $t8
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4208
  b     .L7F024A74
   lw    $ra, 0x24($sp)
.L7F024A18:
  lui   $a1, (0x3F333333 >> 16) # lui $a1, 0x3f33
  lui   $a2, (0x3F8F5C29 >> 16) # lui $a2, 0x3f8f
  ori   $a2, (0x3F8F5C29 & 0xFFFF) # ori $a2, $a2, 0x5c29
  ori   $a1, (0x3F333333 & 0xFFFF) # ori $a1, $a1, 0x3333
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lui   $t9, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f10
  lw    $t9, %lo(ptr_animation_table)($t9)
  lui   $t0, %hi(0x000054A0) # $t0, 0
  addiu $t0, %lo(0x000054A0) # addiu $t0, $t0, 0x54a0
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x40a0
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t9, $t0
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4200
  lw    $ra, 0x24($sp)
.L7F024A74:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024A84
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x3c($sp)
  move  $s0, $a0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  move  $a0, $s0
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x34($sp)
  lw    $a2, 0x34($sp)
  move  $a1, $v0
  sw    $zero, 0x2c($sp)
  beqz  $a2, .L7F024AD4
   nop   
  bnez  $v0, .L7F024AD4
   li    $t6, 1
  b     .L7F024B24
   sw    $t6, 0x2c($sp)
.L7F024AD4:
  beqz  $a2, .L7F024AE4
   nop   
  bnez  $v0, .L7F024B14
   nop   
.L7F024AE4:
  bnez  $a2, .L7F024AF4
   move  $a0, $a2
  beqz  $v0, .L7F024B14
   nop   
.L7F024AF4:
  jal   check_if_item_held_like_pistol
   sw    $a1, 0x30($sp)
  bnez  $v0, .L7F024B14
   lw    $a1, 0x30($sp)
  jal   check_if_item_held_like_pistol
   move  $a0, $a1
  beqz  $v0, .L7F024B24
   nop   
.L7F024B14:
  jal   get_random_value
   nop   
  andi  $t7, $v0, 1
  sw    $t7, 0x2c($sp)
.L7F024B24:
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  lw    $v0, 0x3c($sp)
  li    $t8, 12
  sb    $t8, 7($s0)
  beqz  $v0, .L7F024B4C
   sb    $zero, 8($s0)
  lw    $t9, 0x2c($sp)
  beqz  $t9, .L7F024B5C
   nop   
.L7F024B4C:
  bnez  $v0, .L7F024C24
   lw    $t0, 0x2c($sp)
  beqz  $t0, .L7F024C24
   nop   
.L7F024B5C:
  jal   get_random_value
   nop   
  andi  $t1, $v0, 1
  beqz  $t1, .L7F024BCC
   move  $a0, $s0
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lui   $t2, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $t2, %lo(ptr_animation_table)($t2)
  lui   $t3, %hi(0x000047BC) # $t3, 0
  addiu $t3, %lo(0x000047BC) # addiu $t3, $t3, 0x47bc
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x40a0
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t2, $t3
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4244
  b     .L7F024CE8
   lw    $ra, 0x24($sp)
.L7F024BCC:
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lui   $t4, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t4, %lo(ptr_animation_table)($t4)
  lui   $t5, %hi(0x00004A40) # $t5, 0
  addiu $t5, %lo(0x00004A40) # addiu $t5, $t5, 0x4a40
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x4302
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t4, $t5
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x432d
  b     .L7F024CE8
   lw    $ra, 0x24($sp)
.L7F024C24:
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  beqz  $t6, .L7F024C94
   move  $a0, $s0
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lui   $t7, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f8
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x00004A40) # $t8, 0
  addiu $t8, %lo(0x00004A40) # addiu $t8, $t8, 0x4a40
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x41a0
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t7, $t8
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x427c
  b     .L7F024CE8
   lw    $ra, 0x24($sp)
.L7F024C94:
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lui   $t9, %hi(ptr_animation_table) 
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f10
  lw    $t9, %lo(ptr_animation_table)($t9)
  lui   $t0, %hi(0x000047BC) # $t0, 0
  addiu $t0, %lo(0x000047BC) # addiu $t0, $t0, 0x47bc
  lw    $a0, 0x1c($s0)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x2c($sp)
  lui   $a3, 0x42b6
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t9, $t0
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4308
  lw    $ra, 0x24($sp)
.L7F024CE8:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024CF8
  addiu $sp, $sp, -0x48
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $v0, 0x18($a0)
  lwc1  $f6, ($a1)
  lwc1  $f10, 8($a1)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0x10($v0)
  move  $s0, $a0
  sub.s $f0, $f4, $f6
  sw    $a1, 0x4c($sp)
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  jal   sqrtf
   add.s $f12, $f16, $f18
  swc1  $f0, 0x38($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  move  $a0, $s0
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x34($sp)
  lw    $a3, 0x34($sp)
  li    $t6, 1
  move  $a1, $v0
  beqz  $a3, .L7F024D78
   sw    $t6, 0x2c($sp)
  bnez  $v0, .L7F024D88
   nop   
.L7F024D78:
  bnez  $a3, .L7F024D98
   move  $a0, $a3
  bnezl $v0, .L7F024D9C
   sw    $a1, 0x30($sp)
.L7F024D88:
  jal   get_random_value
   sw    $zero, 0x2c($sp)
  b     .L7F024DD4
   andi  $a2, $v0, 1
.L7F024D98:
  sw    $a1, 0x30($sp)
.L7F024D9C:
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x34($sp)
  lw    $a1, 0x30($sp)
  bnez  $v0, .L7F024DC4
   lw    $a3, 0x34($sp)
  move  $a0, $a1
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x34($sp)
  beqz  $v0, .L7F024DD0
   lw    $a3, 0x34($sp)
.L7F024DC4:
  sw    $zero, 0x2c($sp)
  b     .L7F024DD4
   sltu  $a2, $zero, $a3
.L7F024DD0:
  sltu  $a2, $zero, $a3
.L7F024DD4:
  move  $a0, $s0
  jal   sub_GAME_7F02D184
   sw    $a2, 0x28($sp)
  lw    $v0, 0x4c($sp)
  lw    $a2, 0x28($sp)
  li    $t7, 13
  sb    $t7, 7($s0)
  lwc1  $f4, ($v0)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $zero, $f0
  swc1  $f4, 0x2c($s0)
  lwc1  $f6, 4($v0)
  mtc1  $at, $f10
  li    $at, 0x3F000000 # 0.500000
  swc1  $f6, 0x30($s0)
  lwc1  $f8, 8($v0)
  sb    $zero, 8($s0)
  swc1  $f0, 0x40($s0)
  swc1  $f10, 0x38($s0)
  swc1  $f8, 0x34($s0)
  lw    $t8, 0x2c($sp)
  beql  $t8, $zero, .L7F024E98
   mtc1  $at, $f2
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f2
  lui    $at, %hi(D_80030988) # -0.000000
  lwc1  $f18, %lo(D_80030988)($at)
  lwc1  $f16, 0x38($sp)
  li    $at, 0x41800000 # 16.000000
  mul.s $f4, $f18, $f2
  lui   $t1, %hi(ptr_animation_table) 
  mtc1  $at, $f10
  lui   $t2, %hi(0x000040D4) # $t2, 0
  addiu $t2, %lo(0x000040D4) # addiu $t2, $t2, 0x40d4
  lw    $a0, 0x1c($s0)
  mfc1  $a3, $f0
  div.s $f6, $f16, $f4
  trunc.w.s $f8, $f6
  mfc1  $t0, $f8
  nop   
  sw    $t0, 0x3c($s0)
  lw    $t1, %lo(ptr_animation_table)($t1)
  swc1  $f2, 0x10($sp)
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t1, $t2
  b     .L7F024EF0
   lw    $ra, 0x24($sp)
  mtc1  $at, $f2
.L7F024E98:
  lui   $at, %hi(D_80030994)
  lwc1  $f16, %lo(D_80030994)($at)
  lwc1  $f18, 0x38($sp)
  li    $at, 0x41800000 # 16.000000
  mul.s $f4, $f16, $f2
  lui   $t5, %hi(ptr_animation_table) 
  mtc1  $at, $f10
  lui   $t6, %hi(0x0000777C) # $t6, 0
  addiu $t6, %lo(0x0000777C) # addiu $t6, $t6, 0x777c
  lw    $a0, 0x1c($s0)
  mfc1  $a3, $f0
  div.s $f6, $f18, $f4
  trunc.w.s $f8, $f6
  mfc1  $t4, $f8
  nop   
  sw    $t4, 0x3c($s0)
  lw    $t5, %lo(ptr_animation_table)($t5)
  swc1  $f2, 0x10($sp)
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t5, $t6
  lw    $ra, 0x24($sp)
.L7F024EF0:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024F00
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  jal   sub_GAME_7F02D184
   move  $s0, $a0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $t6, 22
  sb    $t6, 7($s0)
  sb    $zero, 8($s0)
  li    $at, 0x41800000 # 16.000000
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  mtc1  $at, $f6
  lui   $t8, %hi(0x00002F94) # $t8, 0
  addiu $t8, %lo(0x00002F94) # addiu $t8, $t8, 0x2f94
  lw    $a0, 0x1c($s0)
  move  $a2, $zero
  lui   $a3, 0x4120
  swc1  $f4, 0x10($sp)
  addu  $a1, $t7, $t8
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $a0, 0x1c($s0)
  lui   $a1, 0x4120
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  lw    $a0, 0x1c($s0)
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4220
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F024F8C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t6, 0x4c($a0)
  lw    $a2, 0x1c($a0)
  lw    $v0, 0x2c($a0)
  andi  $t7, $t6, 0x20
  beql  $t7, $zero, .L7F025004
   lb    $t8, 0x36($a0)
  mtc1  $zero, $f2
  lwc1  $f0, 0x20($v0)
  move  $a0, $a2
  c.le.s $f2, $f0
  nop   
  bc1f  .L7F024FF0
   nop   
  lwc1  $f4, 0x18($v0)
  c.lt.s $f0, $f4
  nop   
  bc1f  .L7F024FF0
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $a2
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
.L7F024FF0:
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x18($v0)
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
  lb    $t8, 0x36($a0)
.L7F025004:
  beql  $t8, $zero, .L7F025050
   mtc1  $zero, $f2
  mtc1  $zero, $f2
  lwc1  $f0, 0x20($v0)
  move  $a0, $a2
  c.le.s $f2, $f0
  nop   
  bc1f  .L7F02503C
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $a2
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
.L7F02503C:
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x18($v0)
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
  mtc1  $zero, $f2
.L7F025050:
  lwc1  $f0, 0x20($v0)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F02507C
   lwc1  $f0, 0x14($v0)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $a2
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
  lwc1  $f0, 0x14($v0)
.L7F02507C:
  move  $a0, $a2
  c.le.s $f2, $f0
  nop   
  bc1f  .L7F0250A4
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $a2
  b     .L7F0250B0
   lw    $ra, 0x14($sp)
.L7F0250A4:
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0xbf80
  lw    $ra, 0x14($sp)
.L7F0250B0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DAC
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DB0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0250BC
  addiu $sp, $sp, -0x30
  andi  $t6, $a1, 2
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0250DC
   sw    $a0, 0x30($sp)
  mtc1  $zero, $f0
  b     .L7F025160
   lw    $ra, 0x14($sp)
.L7F0250DC:
  andi  $t7, $a1, 0x10
  beqz  $t7, .L7F025148
   lw    $a0, 0x30($sp)
  mtc1  $a2, $f4
  lui   $at, %hi(D_80051DAC)
  lwc1  $f8, %lo(D_80051DAC)($at)
  cvt.s.w $f6, $f4
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f16
  lw    $t8, 0x30($sp)
  mul.s $f10, $f6, $f8
  lw    $a0, 0x1c($t8)
  div.s $f12, $f10, $f16
  jal   getsubroty
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  mtc1  $zero, $f18
  lui   $at, %hi(D_80051DB0)
  sub.s $f2, $f12, $f0
  c.lt.s $f2, $f18
  nop   
  bc1f  .L7F025140
   nop   
  lwc1  $f4, %lo(D_80051DB0)($at)
  add.s $f2, $f2, $f4
.L7F025140:
  b     .L7F02515C
   mov.s $f0, $f2
.L7F025148:
  jal   sub_GAME_7F032C78
   addiu $a3, $sp, 0x28
  lw    $a0, 0x30($sp)
  jal   get_distance_actor_to_position
   move  $a1, $v0
.L7F02515C:
  lw    $ra, 0x14($sp)
.L7F025160:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DB4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DB8
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02516C
  addiu $sp, $sp, -0x90
  sw    $ra, 0x3c($sp)
  sw    $s7, 0x38($sp)
  sw    $s6, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a2, 0x98($sp)
  sw    $a3, 0x9c($sp)
  lw    $t6, 0x1c($a0)
  lui   $t8, %hi(D_800309A8) 
  addiu $t8, %lo(D_800309A8) # addiu $t8, $t8, 0x9a8
  sw    $t6, 0x8c($sp)
  lw    $t2, 4($t8)
  lw    $at, ($t8)
  addiu $t7, $sp, 0x60
  lui   $t4, %hi(D_800309B0) 
  addiu $t4, %lo(D_800309B0) # addiu $t4, $t4, 0x9b0
  sw    $t2, 4($t7)
  sw    $at, ($t7)
  lw    $t1, 4($t4)
  lw    $at, ($t4)
  addiu $t3, $sp, 0x58
  li    $t9, 8
  sw    $t1, 4($t3)
  sw    $at, ($t3)
  move  $s1, $a1
  sb    $t9, 7($a0)
  move  $s4, $a0
  li    $s6, 1
  move  $s7, $zero
  lw    $a2, 0xa4($sp)
  jal   sub_GAME_7F0250BC
   lw    $a1, 0xa0($sp)
  lw    $t7, 0x98($sp)
  lui   $at, %hi(D_80051DB8)
  beqz  $t7, .L7F025248
   nop   
  lui   $at, %hi(D_80051DB4)
  lwc1  $f2, %lo(D_80051DB4)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f6
  sub.s $f4, $f2, $f0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  mul.s $f8, $f4, $f6
  div.s $f10, $f8, $f2
  add.s $f18, $f10, $f16
  trunc.w.s $f4, $f18
  mfc1  $s0, $f4
  b     .L7F025278
   slti  $at, $s0, 0x20
.L7F025248:
  lwc1  $f2, %lo(D_80051DB8)($at)
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f6
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  mul.s $f8, $f0, $f6
  div.s $f10, $f8, $f2
  add.s $f18, $f10, $f16
  trunc.w.s $f4, $f18
  mfc1  $s0, $f4
  nop   
  slti  $at, $s0, 0x20
.L7F025278:
  bnez  $at, .L7F025284
   nop   
  move  $s0, $zero
.L7F025284:
  jal   get_random_value
   nop   
  sll   $t6, $s0, 2
  addu  $t5, $s1, $t6
  lw    $v1, ($t5)
  li    $t0, 72
  lw    $t4, 0x14($s4)
  lw    $a1, 4($v1)
  lw    $a2, ($v1)
  andi  $t1, $t4, 0x20
  divu  $zero, $v0, $a1
  mfhi  $a0
  lui   $t9, %hi(ptr_animation_table) 
  bnez  $a1, .L7F0252C4
   nop   
  break 7
.L7F0252C4:
  multu $a0, $t0
  lui   $t7, %hi(0x00000318) # $t7, 0
  move  $s1, $zero
  move  $s2, $zero
  lw    $s3, 0x9c($sp)
  li    $s5, 1
  mflo  $t3
  addu  $a3, $a2, $t3
  beql  $t1, $zero, .L7F025344
   sw    $a3, 0x80($sp)
  lw    $t9, %lo(ptr_animation_table)($t9)
  lw    $t2, ($a3)
  addiu $t7, %lo(0x00000318) # addiu $t7, $t7, 0x318
  addu  $t8, $t9, $t7
  bne   $t8, $t2, .L7F025340
   addiu $t6, $a0, 1
  div   $zero, $t6, $a1
  mfhi  $t5
  bnez  $a1, .L7F025318
   nop   
  break 7
.L7F025318:
  li    $at, -1
  bne   $a1, $at, .L7F025330
   lui   $at, 0x8000
  bne   $t6, $at, .L7F025330
   nop   
  break 6
.L7F025330:
  multu $t5, $t0
  mflo  $t3
  addu  $a3, $t3, $a2
  nop   
.L7F025340:
  sw    $a3, 0x80($sp)
.L7F025344:
  lw    $t4, ($s3)
  move  $a0, $s4
  beql  $t4, $zero, .L7F0253B8
   addiu $s1, $s1, 1
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $s1
  lw    $s0, 4($v0)
  jal   get_automatic_firing_rate
   lb    $a0, 0x80($s0)
  bgez  $v0, .L7F02538C
   addu  $t1, $sp, $s2
  sw    $s5, 0x60($t1)
  lb    $v0, 0x80($s0)
  li    $at, 22
  bnel  $v0, $at, .L7F02539C
   li    $at, 25
  b     .L7F025398
   move  $s6, $zero
.L7F02538C:
  move  $s6, $zero
  move  $s7, $s5
  lb    $v0, 0x80($s0)
.L7F025398:
  li    $at, 25
.L7F02539C:
  beq   $v0, $at, .L7F0253B0
   addu  $t9, $sp, $s2
  li    $at, 24
  bnel  $v0, $at, .L7F0253B8
   addiu $s1, $s1, 1
.L7F0253B0:
  sw    $s5, 0x58($t9)
  addiu $s1, $s1, 1
.L7F0253B8:
  li    $at, 2
  addiu $s2, $s2, 4
  bne   $s1, $at, .L7F025344
   addiu $s3, $s3, 4
  sb    $s5, 0x30($s4)
  lw    $t7, 0x80($sp)
  sb    $zero, 0x31($s4)
  jal   get_random_value
   sw    $t7, 0x2c($s4)
  andi  $t8, $v0, 1
  sb    $t8, 0x32($s4)
  lw    $t2, 0x9c($sp)
  lw    $t6, 4($t2)
  sb    $t6, 0x39($s4)
  lw    $t5, 0x9c($sp)
  lw    $t3, ($t5)
  sb    $t3, 0x38($s4)
  lw    $t4, 0x64($sp)
  sb    $t4, 0x3b($s4)
  lw    $t1, 0x60($sp)
  sb    $t1, 0x3a($s4)
  lw    $t9, 0x5c($sp)
  sb    $t9, 0x3d($s4)
  lw    $t7, 0x58($sp)
  sb    $s6, 0x36($s4)
  sb    $s7, 0x37($s4)
  sw    $zero, 0x40($s4)
  sb    $zero, 0x33($s4)
  sb    $t7, 0x3c($s4)
  lw    $t8, 0x5c($sp)
  lw    $t2, 0x58($sp)
  lw    $t6, 0x5c($sp)
  bnez  $t8, .L7F025448
   nop   
  beqz  $t2, .L7F025468
   lw    $t4, 0xa0($sp)
.L7F025448:
  beqz  $t6, .L7F025460
   lw    $t5, 0x58($sp)
  beqz  $t5, .L7F025460
   li    $t3, 2
  b     .L7F0254C8
   sb    $t3, 0x34($s4)
.L7F025460:
  b     .L7F0254C8
   sb    $s5, 0x34($s4)
.L7F025468:
  andi  $t1, $t4, 0x80
  beqz  $t1, .L7F02547C
   nop   
  b     .L7F025490
   sb    $s5, 0x34($s4)
.L7F02547C:
  jal   get_random_value
   nop   
  andi  $t9, $v0, 3
  addiu $t7, $t9, 2
  sb    $t7, 0x34($s4)
.L7F025490:
  lw    $t8, 0x9c($sp)
  lw    $t2, ($t8)
  beql  $t2, $zero, .L7F0254CC
   lw    $t9, 0xa0($sp)
  lw    $t6, 4($t8)
  beql  $t6, $zero, .L7F0254CC
   lw    $t9, 0xa0($sp)
  jal   get_random_value
   nop   
  lb    $t5, 0x34($s4)
  andi  $t3, $v0, 3
  addu  $t4, $t5, $t3
  addiu $t1, $t4, 2
  sb    $t1, 0x34($s4)
.L7F0254C8:
  lw    $t9, 0xa0($sp)
.L7F0254CC:
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $t9, 0x4c($s4)
  lw    $t7, 0xa4($sp)
  move  $a0, $s4
  lui   $a1, 0x3f00
  sw    $t7, 0x50($s4)
  lw    $t2, 0xa8($sp)
  sw    $zero, 0x58($s4)
  sw    $zero, 0x44($s4)
  sw    $zero, 0x48($s4)
  sb    $zero, 8($s4)
  jal   sub_GAME_7F023B5C
   sw    $t2, 0x54($s4)
  lw    $v0, 0x80($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $a1, ($v0)
  lw    $a3, 0x10($v0)
  swc1  $f0, 0x10($sp)
  lw    $a0, 0x8c($sp)
  lw    $a2, 0x98($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F024F8C
   move  $a0, $s4
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F025560
  addiu $sp, $sp, -0x50
  sw    $ra, 0x24($sp)
  sw    $a1, 0x54($sp)
  sw    $a0, 0x50($sp)
  sw    $a2, 0x58($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x4c($sp)
  lw    $a0, 0x50($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lui   $t7, %hi(D_800309B8) 
  addiu $t7, %lo(D_800309B8) # addiu $t7, $t7, 0x9b8
  lw    $a0, 0x4c($sp)
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x38
  move  $a1, $v0
  sw    $at, ($t6)
  beqz  $a0, .L7F025660
   sw    $t0, 4($t6)
  beqz  $v0, .L7F025660
   nop   
  lw    $a0, 0x50($sp)
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x34($sp)
  lw    $a0, 0x50($sp)
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  lw    $t1, 0x34($sp)
  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
  sltiu $a2, $v0, 1
  beqz  $t1, .L7F025650
   addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
  beql  $v0, $zero, .L7F025654
   sltiu $t9, $a2, 1
  jal   get_random_value
   nop   
  andi  $a2, $v0, 1
  jal   get_random_value
   sw    $a2, 0x44($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t2
  lw    $a2, 0x44($sp)
  bnez  $t2, .L7F025638
   lui   $a1, %hi(ptr_doubles_firing_animation_groups)
  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
  sltiu $t3, $a2, 1
  addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
  sw    $a2, 0x3c($sp)
  b     .L7F0256BC
   sw    $t3, 0x38($sp)
.L7F025638:
  li    $t4, 1
  li    $t5, 1
  addiu $a1, $a1, %lo(ptr_doubles_firing_animation_groups)
  sw    $t4, 0x3c($sp)
  b     .L7F0256BC
   sw    $t5, 0x38($sp)
.L7F025650:
  sltiu $t9, $a2, 1
.L7F025654:
  sw    $a2, 0x3c($sp)
  b     .L7F0256BC
   sw    $t9, 0x38($sp)
.L7F025660:
  jal   check_if_item_held_like_pistol
   sw    $a1, 0x48($sp)
  bnez  $v0, .L7F025680
   lw    $a1, 0x48($sp)
  jal   check_if_item_held_like_pistol
   move  $a0, $a1
  beql  $v0, $zero, .L7F0256A4
   lw    $v0, 0x4c($sp)
.L7F025680:
  lw    $v0, 0x4c($sp)
  lui   $a1, %hi(ptr_pistol_firing_animation_groups)
  addiu $a1, %lo(ptr_pistol_firing_animation_groups) # addiu $a1, $a1, -0xbf8
  sltu  $a2, $zero, $v0
  sltiu $t6, $a2, 1
  sw    $a2, 0x3c($sp)
  b     .L7F0256BC
   sw    $t6, 0x38($sp)
  lw    $v0, 0x4c($sp)
.L7F0256A4:
  lui   $a1, %hi(ptr_rifle_firing_animation_groups)
  addiu $a1, %lo(ptr_rifle_firing_animation_groups) # addiu $a1, $a1, -0x12d8
  sltu  $a2, $zero, $v0
  sltiu $t0, $a2, 1
  sw    $a2, 0x3c($sp)
  sw    $t0, 0x38($sp)
.L7F0256BC:
  lw    $t1, 0x54($sp)
  lw    $t2, 0x58($sp)
  li    $t3, 1
  sw    $t3, 0x18($sp)
  lw    $a0, 0x50($sp)
  addiu $a3, $sp, 0x38
  sw    $t1, 0x10($sp)
  jal   sub_GAME_7F02516C
   sw    $t2, 0x14($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0256F0
  addiu $sp, $sp, -0x50
  sw    $ra, 0x24($sp)
  sw    $a1, 0x54($sp)
  sw    $a0, 0x50($sp)
  sw    $a2, 0x58($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x4c($sp)
  lw    $a0, 0x50($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lui   $t7, %hi(D_800309C0) 
  addiu $t7, %lo(D_800309C0) # addiu $t7, $t7, 0x9c0
  lw    $a0, 0x4c($sp)
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x38
  move  $a1, $v0
  sw    $at, ($t6)
  beqz  $a0, .L7F0257F0
   sw    $t0, 4($t6)
  beqz  $v0, .L7F0257F0
   nop   
  lw    $a0, 0x50($sp)
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x34($sp)
  lw    $a0, 0x50($sp)
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  lw    $t1, 0x34($sp)
  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
  sltiu $a2, $v0, 1
  beqz  $t1, .L7F0257E0
   addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
  beql  $v0, $zero, .L7F0257E4
   sltiu $t9, $a2, 1
  jal   get_random_value
   nop   
  andi  $a2, $v0, 1
  jal   get_random_value
   sw    $a2, 0x44($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t2
  lw    $a2, 0x44($sp)
  bnez  $t2, .L7F0257C8
   lui   $a1, %hi(ptr_crouched_doubles_firing_animation_groups)
  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
  sltiu $t3, $a2, 1
  addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
  sw    $a2, 0x3c($sp)
  b     .L7F02584C
   sw    $t3, 0x38($sp)
.L7F0257C8:
  li    $t4, 1
  li    $t5, 1
  addiu $a1, $a1, %lo(ptr_crouched_doubles_firing_animation_groups)
  sw    $t4, 0x3c($sp)
  b     .L7F02584C
   sw    $t5, 0x38($sp)
.L7F0257E0:
  sltiu $t9, $a2, 1
.L7F0257E4:
  sw    $a2, 0x3c($sp)
  b     .L7F02584C
   sw    $t9, 0x38($sp)
.L7F0257F0:
  jal   check_if_item_held_like_pistol
   sw    $a1, 0x48($sp)
  bnez  $v0, .L7F025810
   lw    $a1, 0x48($sp)
  jal   check_if_item_held_like_pistol
   move  $a0, $a1
  beql  $v0, $zero, .L7F025834
   lw    $v0, 0x4c($sp)
.L7F025810:
  lw    $v0, 0x4c($sp)
  lui   $a1, %hi(ptr_crouched_pistol_firing_animation_groups)
  addiu $a1, %lo(ptr_crouched_pistol_firing_animation_groups) # addiu $a1, $a1, -0x328
  sltu  $a2, $zero, $v0
  sltiu $t6, $a2, 1
  sw    $a2, 0x3c($sp)
  b     .L7F02584C
   sw    $t6, 0x38($sp)
  lw    $v0, 0x4c($sp)
.L7F025834:
  lui   $a1, %hi(ptr_crouched_rifle_firing_animation_groups)
  addiu $a1, %lo(ptr_crouched_rifle_firing_animation_groups) # addiu $a1, $a1, -0x690
  sltu  $a2, $zero, $v0
  sltiu $t0, $a2, 1
  sw    $a2, 0x3c($sp)
  sw    $t0, 0x38($sp)
.L7F02584C:
  lw    $t1, 0x54($sp)
  lw    $t2, 0x58($sp)
  lw    $a0, 0x50($sp)
  addiu $a3, $sp, 0x38
  sw    $zero, 0x18($sp)
  sw    $t1, 0x10($sp)
  jal   sub_GAME_7F02516C
   sw    $t2, 0x14($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02587C
  addiu $sp, $sp, -0x88
  sw    $s2, 0x24($sp)
  move  $s2, $a1
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  move  $s5, $a0
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  move  $s0, $v0
  move  $a0, $s5
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lui   $t7, %hi(D_800309C8) 
  addiu $t7, %lo(D_800309C8) # addiu $t7, $t7, 0x9c8
  lw    $at, ($t7)
  lw    $t0, 4($t7)
  addiu $t6, $sp, 0x70
  lui   $t2, %hi(D_800309D0) 
  addiu $t2, %lo(D_800309D0) # addiu $t2, $t2, 0x9d0
  sw    $at, ($t6)
  sw    $t0, 4($t6)
  lw    $t5, 4($t2)
  lw    $at, ($t2)
  addiu $t1, $sp, 0x68
  lui   $t8, %hi(D_800309D8) 
  addiu $t8, %lo(D_800309D8) # addiu $t8, $t8, 0x9d8
  sw    $t5, 4($t1)
  sw    $at, ($t1)
  lw    $t0, 4($t8)
  lw    $at, ($t8)
  addiu $t9, $sp, 0x60
  move  $s1, $v0
  sw    $t0, 4($t9)
  beqz  $s0, .L7F025A28
   sw    $at, ($t9)
  beqz  $v0, .L7F025A28
   move  $a0, $s5
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  move  $s0, $v0
  move  $a0, $s5
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  beqz  $s0, .L7F025970
   move  $v1, $zero
  beql  $v0, $zero, .L7F025974
   sltiu $t3, $v0, 1
  jal   get_random_value
   nop   
  andi  $t4, $v0, 1
  jal   get_random_value
   sw    $t4, 0x78($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $v1
  b     .L7F025978
   nop   
.L7F025970:
  sltiu $t3, $v0, 1
.L7F025974:
  sw    $t3, 0x78($sp)
.L7F025978:
  bnez  $v1, .L7F0259C8
   li    $s4, 1
  beqz  $s2, .L7F025998
   lui   $t2, %hi(D_800306F0) 
  lui   $t1, %hi(D_80030738) 
  addiu $t1, %lo(D_80030738) # addiu $t1, $t1, 0x738
  b     .L7F0259A0
   sw    $t1, 0x84($sp)
.L7F025998:
  addiu $t2, %lo(D_800306F0) # addiu $t2, $t2, 0x6f0
  sw    $t2, 0x84($sp)
.L7F0259A0:
  lw    $t5, 0x78($sp)
  li    $t7, 1
  li    $v0, 1
  beqz  $t5, .L7F0259BC
   li    $s4, 1
  b     .L7F025AD8
   sw    $t7, 0x74($sp)
.L7F0259BC:
  sw    $v0, 0x70($sp)
  b     .L7F025AD8
   li    $s4, 1
.L7F0259C8:
  bne   $v1, $s4, .L7F0259FC
   nop   
  beqz  $s2, .L7F0259E8
   lui   $t9, %hi(D_80030780) 
  lui   $t6, %hi(D_800307C8) 
  addiu $t6, %lo(D_800307C8) # addiu $t6, $t6, 0x7c8
  b     .L7F0259F0
   sw    $t6, 0x84($sp)
.L7F0259E8:
  addiu $t9, %lo(D_80030780) # addiu $t9, $t9, 0x780
  sw    $t9, 0x84($sp)
.L7F0259F0:
  sw    $s4, 0x74($sp)
  b     .L7F025AD8
   sw    $s4, 0x70($sp)
.L7F0259FC:
  beqz  $s2, .L7F025A14
   lui   $t0, %hi(D_80030810) 
  lui   $t8, %hi(D_80030858) 
  addiu $t8, %lo(D_80030858) # addiu $t8, $t8, 0x858
  b     .L7F025A1C
   sw    $t8, 0x84($sp)
.L7F025A14:
  addiu $t0, %lo(D_80030810) # addiu $t0, $t0, 0x810
  sw    $t0, 0x84($sp)
.L7F025A1C:
  sw    $s4, 0x74($sp)
  b     .L7F025AD8
   sw    $s4, 0x70($sp)
.L7F025A28:
  jal   check_if_item_held_like_pistol
   move  $a0, $s0
  bnezl $v0, .L7F025A48
   sltu  $v0, $zero, $s0
  jal   check_if_item_held_like_pistol
   move  $a0, $s1
  beqz  $v0, .L7F025A90
   sltu  $v0, $zero, $s0
.L7F025A48:
  beqz  $s2, .L7F025A60
   sw    $v0, 0x78($sp)
  lui   $t4, %hi(D_80030738) 
  addiu $t4, %lo(D_80030738) # addiu $t4, $t4, 0x738
  b     .L7F025A6C
   sw    $t4, 0x84($sp)
.L7F025A60:
  lui   $t3, %hi(D_800306F0) 
  addiu $t3, %lo(D_800306F0) # addiu $t3, $t3, 0x6f0
  sw    $t3, 0x84($sp)
.L7F025A6C:
  beqz  $v0, .L7F025A80
   li    $t1, 1
  sw    $t1, 0x74($sp)
  b     .L7F025AD8
   li    $s4, 1
.L7F025A80:
  li    $v0, 1
  sw    $v0, 0x70($sp)
  b     .L7F025AD8
   li    $s4, 1
.L7F025A90:
  sltu  $v0, $zero, $s0
  beqz  $s2, .L7F025AAC
   sw    $v0, 0x78($sp)
  lui   $t2, %hi(D_800306A8) 
  addiu $t2, %lo(D_800306A8) # addiu $t2, $t2, 0x6a8
  b     .L7F025AB8
   sw    $t2, 0x84($sp)
.L7F025AAC:
  lui   $t5, %hi(D_80030660) 
  addiu $t5, %lo(D_80030660) # addiu $t5, $t5, 0x660
  sw    $t5, 0x84($sp)
.L7F025AB8:
  beqz  $v0, .L7F025AD0
   li    $s4, 1
  li    $t7, 1
  sw    $t7, 0x74($sp)
  b     .L7F025AD8
   li    $s4, 1
.L7F025AD0:
  li    $v0, 1
  sw    $v0, 0x70($sp)
.L7F025AD8:
  move  $s1, $zero
  move  $s2, $zero
  addiu $s3, $sp, 0x70
.L7F025AE4:
  lw    $t6, ($s3)
  move  $a0, $s5
  beql  $t6, $zero, .L7F025B38
   addiu $s1, $s1, 1
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $s1
  lw    $s0, 4($v0)
  jal   get_automatic_firing_rate
   lb    $a0, 0x80($s0)
  bgez  $v0, .L7F025B14
   addu  $t9, $sp, $s2
  sw    $s4, 0x68($t9)
.L7F025B14:
  lb    $v0, 0x80($s0)
  li    $at, 25
  addu  $t8, $sp, $s2
  beq   $v0, $at, .L7F025B30
   li    $at, 24
  bnel  $v0, $at, .L7F025B38
   addiu $s1, $s1, 1
.L7F025B30:
  sw    $s4, 0x60($t8)
  addiu $s1, $s1, 1
.L7F025B38:
  li    $at, 2
  addiu $s2, $s2, 4
  bne   $s1, $at, .L7F025AE4
   addiu $s3, $s3, 4
  li    $t0, 9
  sb    $t0, 7($s5)
  jal   get_random_value
   sw    $zero, 0x30($s5)
  li    $at, 0x43C80000 # 400.000000
  mtc1  $at, $f4
  lui   $at, %hi(ai_reaction_speed)
  lwc1  $f6, %lo(ai_reaction_speed)($at)
  sw    $zero, 0x38($s5)
  mul.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t3, $f10
  nop   
  divu  $zero, $v0, $t3
  mfhi  $t1
  addiu $t2, $t1, 0x78
  sw    $t2, 0x34($s5)
  lw    $t5, 0x84($sp)
  bnez  $t3, .L7F025B9C
   nop   
  break 7
.L7F025B9C:
  sw    $zero, 0x40($s5)
  jal   get_random_value
   sw    $t5, 0x3c($s5)
  andi  $t7, $v0, 1
  sw    $t7, 0x44($s5)
  lw    $t6, 0x74($sp)
  mtc1  $zero, $f16
  li    $at, 0x3F000000 # 0.500000
  sb    $t6, 0x49($s5)
  lw    $t9, 0x70($sp)
  mtc1  $at, $f18
  li    $at, 0x41800000 # 16.000000
  sb    $t9, 0x48($s5)
  lw    $t8, 0x6c($sp)
  mtc1  $at, $f4
  lw    $a0, 0x1c($s5)
  sb    $t8, 0x4b($s5)
  lw    $t0, 0x68($sp)
  sb    $t0, 0x4a($s5)
  lw    $t4, 0x64($sp)
  sb    $t4, 0x4d($s5)
  lw    $t3, 0x60($sp)
  sb    $zero, 8($s5)
  swc1  $f16, 0x54($s5)
  sb    $t3, 0x4c($s5)
  lw    $t1, 0x84($sp)
  lw    $a2, 0x78($sp)
  lw    $a1, ($t1)
  lw    $a3, 0x10($t1)
  swc1  $f18, 0x10($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lw    $ra, 0x34($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F025C40
  addiu $sp, $sp, -0x90
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a1, 0x94($sp)
  lw    $t6, 0x1c($a0)
  move  $s2, $a0
  li    $a1, 1
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $t6, 0x8c($sp)
  move  $s0, $v0
  move  $a0, $s2
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lui   $t8, %hi(D_800309E0) 
  sw    $zero, 0x78($sp)
  addiu $t8, %lo(D_800309E0) # addiu $t8, $t8, 0x9e0
  lw    $at, ($t8)
  lw    $t1, 4($t8)
  addiu $t7, $sp, 0x64
  lui   $t3, %hi(D_800309E8) 
  sw    $at, ($t7)
  sw    $t1, 4($t7)
  sw    $zero, 0x5c($sp)
  addiu $t3, %lo(D_800309E8) # addiu $t3, $t3, 0x9e8
  lw    $at, ($t3)
  lw    $t6, 4($t3)
  addiu $t2, $sp, 0x54
  lui   $t9, %hi(D_800309F0) 
  addiu $t9, %lo(D_800309F0) # addiu $t9, $t9, 0x9f0
  sw    $at, ($t2)
  sw    $t6, 4($t2)
  lw    $t1, 4($t9)
  lw    $at, ($t9)
  addiu $t0, $sp, 0x4c
  move  $s1, $v0
  li    $s3, 1
  sw    $t1, 4($t0)
  beqz  $s0, .L7F025D88
   sw    $at, ($t0)
  beqz  $v0, .L7F025D88
   move  $a0, $s2
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  move  $s0, $v0
  move  $a0, $s2
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  beqz  $s0, .L7F025D6C
   sltiu $v1, $v0, 1
  beql  $v0, $zero, .L7F025D70
   li    $t0, 1
  jal   get_random_value
   nop   
  andi  $t5, $v0, 1
  li    $t4, 1
  sw    $t5, 0x7c($sp)
  jal   get_random_value
   sw    $t4, 0x78($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t2
  li    $t8, 1
  bnez  $t2, .L7F025D60
   li    $t7, 1
  lw    $t3, 0x7c($sp)
  sltiu $t6, $t3, 1
  sw    $t6, 0x64($sp)
  b     .L7F025DD8
   sw    $t3, 0x68($sp)
.L7F025D60:
  sw    $t8, 0x68($sp)
  b     .L7F025DD8
   sw    $t7, 0x64($sp)
.L7F025D6C:
  li    $t0, 1
.L7F025D70:
  sltiu $t9, $v1, 1
  sw    $v1, 0x7c($sp)
  sw    $t0, 0x78($sp)
  sw    $v1, 0x68($sp)
  b     .L7F025DD8
   sw    $t9, 0x64($sp)
.L7F025D88:
  jal   check_if_item_held_like_pistol
   move  $a0, $s0
  bnezl $v0, .L7F025DA8
   sltu  $v0, $zero, $s0
  jal   check_if_item_held_like_pistol
   move  $a0, $s1
  beqz  $v0, .L7F025DC4
   sltu  $v0, $zero, $s0
.L7F025DA8:
  li    $t1, 1
  sltiu $t5, $v0, 1
  sw    $v0, 0x7c($sp)
  sw    $t1, 0x78($sp)
  sw    $v0, 0x68($sp)
  b     .L7F025DD8
   sw    $t5, 0x64($sp)
.L7F025DC4:
  sltu  $v0, $zero, $s0
  sltiu $t4, $v0, 1
  sw    $v0, 0x7c($sp)
  sw    $v0, 0x68($sp)
  sw    $t4, 0x64($sp)
.L7F025DD8:
  lw    $v0, 0x94($sp)
  lw    $t2, 0x7c($sp)
  beqz  $v0, .L7F025DF0
   nop   
  beqz  $t2, .L7F025E00
   nop   
.L7F025DF0:
  bnez  $v0, .L7F025E30
   lw    $t3, 0x7c($sp)
  beqz  $t3, .L7F025E30
   nop   
.L7F025E00:
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  beqz  $t6, .L7F025E24
   lui   $t7, %hi(D_80030108) 
  lui   $t8, %hi(D_80030078) 
  addiu $t8, %lo(D_80030078) # addiu $t8, $t8, 0x78
  b     .L7F025E5C
   sw    $t8, 0x88($sp)
.L7F025E24:
  addiu $t7, %lo(D_80030108) # addiu $t7, $t7, 0x108
  b     .L7F025E5C
   sw    $t7, 0x88($sp)
.L7F025E30:
  jal   get_random_value
   nop   
  andi  $t0, $v0, 1
  beqz  $t0, .L7F025E54
   lui   $t1, %hi(D_80030150) 
  lui   $t9, %hi(D_800300C0) 
  addiu $t9, %lo(D_800300C0) # addiu $t9, $t9, 0xc0
  b     .L7F025E5C
   sw    $t9, 0x88($sp)
.L7F025E54:
  addiu $t1, %lo(D_80030150) # addiu $t1, $t1, 0x150
  sw    $t1, 0x88($sp)
.L7F025E5C:
  lw    $t5, 0x78($sp)
  move  $s0, $zero
  move  $a2, $zero
  beqz  $t5, .L7F025E7C
   addiu $a3, $sp, 0x64
  lw    $t4, 0x88($sp)
  addiu $t2, $t4, 0x120
  sw    $t2, 0x88($sp)
.L7F025E7C:
  li    $s1, 1
.L7F025E80:
  lw    $t3, ($a3)
  move  $a0, $s2
  move  $a1, $s0
  beql  $t3, $zero, .L7F025F0C
   addiu $s0, $s0, 1
  sw    $a2, 0x38($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $a3, 0x34($sp)
  lw    $v1, 4($v0)
  lb    $a0, 0x80($v1)
  jal   get_automatic_firing_rate
   sw    $v1, 0x70($sp)
  lw    $v1, 0x70($sp)
  lw    $a2, 0x38($sp)
  bgez  $v0, .L7F025EE0
   lw    $a3, 0x34($sp)
  addu  $t6, $sp, $a2
  sw    $s1, 0x54($t6)
  lb    $v0, 0x80($v1)
  li    $at, 22
  bnel  $v0, $at, .L7F025EF0
   li    $at, 25
  b     .L7F025EEC
   move  $s3, $zero
.L7F025EE0:
  sw    $s1, 0x5c($sp)
  move  $s3, $zero
  lb    $v0, 0x80($v1)
.L7F025EEC:
  li    $at, 25
.L7F025EF0:
  beq   $v0, $at, .L7F025F04
   addu  $t8, $sp, $a2
  li    $at, 24
  bnel  $v0, $at, .L7F025F0C
   addiu $s0, $s0, 1
.L7F025F04:
  sw    $s1, 0x4c($t8)
  addiu $s0, $s0, 1
.L7F025F0C:
  li    $at, 2
  addiu $a2, $a2, 4
  bne   $s0, $at, .L7F025E80
   addiu $a3, $a3, 4
  li    $t7, 10
  sb    $t7, 7($s2)
  lw    $t0, 0x88($sp)
  sb    $zero, 0x31($s2)
  jal   get_random_value
   sw    $t0, 0x2c($s2)
  andi  $t9, $v0, 1
  sb    $t9, 0x32($s2)
  lw    $t1, 0x68($sp)
  sb    $t1, 0x39($s2)
  lw    $t5, 0x64($sp)
  sb    $t5, 0x38($s2)
  lw    $t4, 0x58($sp)
  sb    $t4, 0x3b($s2)
  lw    $t2, 0x54($sp)
  sb    $t2, 0x3a($s2)
  lw    $t3, 0x50($sp)
  sb    $t3, 0x3d($s2)
  lw    $t6, 0x4c($sp)
  sb    $s3, 0x36($s2)
  sb    $t6, 0x3c($s2)
  lw    $t8, 0x5c($sp)
  sb    $t8, 0x37($s2)
  lw    $t7, 0x78($sp)
  sw    $zero, 0x40($s2)
  sb    $zero, 0x33($s2)
  sb    $s1, 0x30($s2)
  sb    $t7, 0x35($s2)
  lw    $t0, 0x50($sp)
  lw    $t9, 0x4c($sp)
  lw    $t1, 0x50($sp)
  bnez  $t0, .L7F025FA8
   nop   
  beqz  $t9, .L7F025FC8
   nop   
.L7F025FA8:
  beqz  $t1, .L7F025FC0
   lw    $t5, 0x4c($sp)
  beqz  $t5, .L7F025FC0
   li    $t4, 2
  b     .L7F026010
   sb    $t4, 0x34($s2)
.L7F025FC0:
  b     .L7F026010
   sb    $s1, 0x34($s2)
.L7F025FC8:
  jal   get_random_value
   nop   
  andi  $t2, $v0, 3
  addiu $t3, $t2, 2
  sb    $t3, 0x34($s2)
  lw    $t6, 0x64($sp)
  lw    $t8, 0x68($sp)
  beql  $t6, $zero, .L7F026014
   lui   $a2, 0x3f4c
  beql  $t8, $zero, .L7F026014
   lui   $a2, 0x3f4c
  jal   get_random_value
   nop   
  lb    $t7, 0x34($s2)
  andi  $t0, $v0, 3
  addu  $t9, $t7, $t0
  addiu $t1, $t9, 2
  sb    $t1, 0x34($s2)
.L7F026010:
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
.L7F026014:
  sw    $s1, 0x4c($s2)
  sw    $zero, 0x50($s2)
  sw    $s1, 0x54($s2)
  sw    $zero, 0x58($s2)
  sw    $zero, 0x44($s2)
  sw    $zero, 0x48($s2)
  sb    $zero, 8($s2)
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  move  $a0, $s2
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t5, 0x88($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f4
  lw    $a1, ($t5)
  lw    $a3, 0x10($t5)
  swc1  $f0, 0x10($sp)
  lw    $a0, 0x8c($sp)
  lw    $a2, 0x7c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lw    $t4, 0x78($sp)
  bnezl $t4, .L7F026118
   lw    $ra, 0x2c($sp)
  beqz  $s3, .L7F0260C4
   lw    $t6, 0x88($sp)
  lw    $t2, 0x88($sp)
  mtc1  $zero, $f2
  lw    $t3, 0x88($sp)
  lwc1  $f0, 0x24($t2)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F0260B4
   lw    $a0, 0x8c($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x8c($sp)
  b     .L7F026118
   lw    $ra, 0x2c($sp)
  lw    $a0, 0x8c($sp)
.L7F0260B4:
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x1c($t3)
  b     .L7F026118
   lw    $ra, 0x2c($sp)
.L7F0260C4:
  mtc1  $zero, $f2
  lwc1  $f0, 0x20($t6)
  lw    $t8, 0x88($sp)
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F0260F8
   lwc1  $f0, 0x14($t8)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x8c($sp)
  b     .L7F026118
   lw    $ra, 0x2c($sp)
  lwc1  $f0, 0x14($t8)
.L7F0260F8:
  c.le.s $f2, $f0
  nop   
  bc1fl .L7F026118
   lw    $ra, 0x2c($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x8c($sp)
  lw    $ra, 0x2c($sp)
.L7F026118:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F026130
  lwc1  $f12, ($a0)
  lwc1  $f4, ($a1)
  lwc1  $f16, 8($a0)
  lwc1  $f6, 8($a1)
  sub.s $f14, $f4, $f12
  lwc1  $f8, ($a3)
  lwc1  $f2, 8($a3)
  addiu $sp, $sp, -0x20
  sub.s $f18, $f6, $f16
  swc1  $f8, ($sp)
  mul.s $f10, $f2, $f14
  lwc1  $f4, ($sp)
  mtc1  $zero, $f8
  mul.s $f6, $f18, $f4
  sub.s $f0, $f10, $f6
  c.eq.s $f0, $f8
  lwc1  $f8, ($sp)
  bc1tl .L7F0261E4
   mtc1  $zero, $f4
  lwc1  $f10, ($a2)
  lw    $v0, 0x30($sp)
  swc1  $f10, 0x14($sp)
  lwc1  $f6, 0x14($sp)
  sub.s $f8, $f6, $f12
  mul.s $f10, $f18, $f8
  lwc1  $f8, 8($a2)
  sub.s $f8, $f16, $f8
  mul.s $f8, $f8, $f14
  add.s $f10, $f10, $f8
  div.s $f2, $f10, $f0
  mul.s $f8, $f4, $f2
  add.s $f10, $f8, $f6
  swc1  $f10, ($v0)
  lwc1  $f4, 4($a3)
  lwc1  $f6, 4($a2)
  mul.s $f8, $f4, $f2
  add.s $f10, $f8, $f6
  swc1  $f10, 4($v0)
  lwc1  $f4, 8($a3)
  lwc1  $f6, 8($a2)
  mul.s $f8, $f4, $f2
  add.s $f10, $f8, $f6
  b     .L7F026244
   swc1  $f10, 8($v0)
  mtc1  $zero, $f4
.L7F0261E4:
  lw    $v0, 0x30($sp)
  c.eq.s $f4, $f8
  nop   
  bc1fl .L7F026234
   swc1  $f12, ($v0)
  mtc1  $zero, $f6
  nop   
  c.eq.s $f6, $f2
  nop   
  bc1fl .L7F026234
   swc1  $f12, ($v0)
  lw    $v0, 0x30($sp)
  lwc1  $f10, ($a2)
  swc1  $f10, ($v0)
  lwc1  $f4, 4($a2)
  swc1  $f4, 4($v0)
  lwc1  $f8, 8($a2)
  b     .L7F026244
   swc1  $f8, 8($v0)
  swc1  $f12, ($v0)
.L7F026234:
  lwc1  $f6, 4($a0)
  swc1  $f6, 4($v0)
  lwc1  $f10, 8($a0)
  swc1  $f10, 8($v0)
.L7F026244:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F02624C
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  sw    $a2, 0x40($sp)
  addiu $a1, $sp, 0x20
  jal   sub_GAME_7F0B28B0
   addiu $a0, $sp, 0x2c
  lw    $t6, 0x40($sp)
  addiu $a0, $sp, 0x2c
  addiu $a1, $sp, 0x20
  lw    $a2, 0x38($sp)
  lw    $a3, 0x3c($sp)
  jal   sub_GAME_7F026130
   sw    $t6, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F026298
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  sw    $a1, 0x3c($sp)
  addiu $a1, $sp, 0x20
  addiu $a0, $sp, 0x2c
  jal   sub_GAME_7F0B28B0
   sw    $a2, 0x40($sp)
  lw    $v1, 0x38($sp)
  lwc1  $f4, 0x20($sp)
  lwc1  $f6, 0x2c($sp)
  lwc1  $f8, 0x34($sp)
  lwc1  $f10, 8($v1)
  lw    $v0, 0x3c($sp)
  sub.s $f14, $f4, $f6
  lwc1  $f4, ($v1)
  lwc1  $f2, ($v0)
  sub.s $f16, $f8, $f10
  lwc1  $f12, 8($v0)
  lw    $a2, 0x40($sp)
  sub.s $f10, $f6, $f4
  mul.s $f18, $f2, $f16
  nop   
  mul.s $f16, $f12, $f10
  lwc1  $f10, 0x28($sp)
  sub.s $f4, $f18, $f16
  sub.s $f18, $f10, $f8
  mul.s $f16, $f18, $f2
  nop   
  mul.s $f10, $f12, $f14
  sub.s $f8, $f10, $f16
  div.s $f0, $f4, $f8
  mul.s $f18, $f14, $f0
  add.s $f10, $f18, $f6
  swc1  $f10, ($a2)
  lwc1  $f4, 0x30($sp)
  lwc1  $f16, 0x24($sp)
  sub.s $f8, $f16, $f4
  mul.s $f18, $f8, $f0
  add.s $f6, $f18, $f4
  swc1  $f6, 4($a2)
  lwc1  $f16, 0x34($sp)
  lwc1  $f10, 0x28($sp)
  sub.s $f8, $f10, $f16
  mul.s $f18, $f8, $f0
  add.s $f4, $f18, $f16
  swc1  $f4, 8($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F026364
  addiu $sp, $sp, -0x68
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  lw    $t6, 0x14($a0)
  move  $s0, $a0
  lwc1  $f12, 0x6c($sp)
  sw    $t6, 0x50($sp)
  lw    $t7, 4($a0)
  jal   sinf
   sw    $t7, 0x4c($sp)
  mtc1  $zero, $f4
  swc1  $f0, 0x5c($sp)
  lwc1  $f12, 0x6c($sp)
  jal   cosf
   swc1  $f4, 0x60($sp)
  lwc1  $f12, 0x70($sp)
  lwc1  $f6, 0x5c($sp)
  swc1  $f0, 0x64($sp)
  lwc1  $f16, 0x64($sp)
  mul.s $f8, $f6, $f12
  lwc1  $f10, 8($s0)
  lwc1  $f4, 0x10($s0)
  mul.s $f18, $f16, $f12
  lw    $a0, 0x4c($sp)
  move  $a1, $zero
  add.s $f2, $f8, $f10
  add.s $f14, $f18, $f4
  swc1  $f2, 0x58($sp)
  jal   set_or_unset_GUARDdata_flag
   swc1  $f14, 0x54($sp)
  jal   sub_GAME_7F0B1CC4
   nop   
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  lwc1  $f2, 0x58($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f14, 0x54($sp)
  mtc1  $at, $f16
  lw    $t8, 0x74($sp)
  lwc1  $f6, 0x78($sp)
  lwc1  $f8, 0x7c($sp)
  mtc1  $zero, $f10
  mfc1  $a3, $f2
  addiu $a0, $sp, 0x50
  swc1  $f14, 0x10($sp)
  sw    $t8, 0x14($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F02644C
   addiu $a0, $s0, 8
  b     .L7F026488
   lwc1  $f2, 0x70($sp)
.L7F02644C:
  addiu $a1, $sp, 0x5c
  jal   sub_GAME_7F02624C
   addiu $a2, $sp, 0x3c
  lwc1  $f18, 0x3c($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f6, 0x44($sp)
  lwc1  $f8, 0x10($s0)
  sub.s $f2, $f18, $f4
  sub.s $f14, $f6, $f8
  mul.s $f10, $f2, $f2
  nop   
  mul.s $f16, $f14, $f14
  jal   sqrtf
   add.s $f12, $f10, $f16
  mov.s $f2, $f0
.L7F026488:
  lw    $a0, 0x4c($sp)
  li    $a1, 1
  jal   set_or_unset_GUARDdata_flag
   swc1  $f2, 0x48($sp)
  lw    $ra, 0x34($sp)
  lwc1  $f2, 0x48($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F0264B0
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  sw    $a0, 0x30($sp)
  addiu $a2, $sp, 0x2c
  addiu $a1, $sp, 0x24
  jal   sub_GAME_7F023160
   addiu $a3, $sp, 0x28
  lwc1  $f4, 0x2c($sp)
  lwc1  $f6, 0x28($sp)
  lw    $a0, 0x30($sp)
  lw    $a1, 0x34($sp)
  lw    $a2, 0x38($sp)
  li    $a3, 31
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F026364
   swc1  $f6, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DBC
.word 0x3fc90fdb /*1.5707964*/
glabel D_80051DC0
.word 0x4096cbe4 /*4.712389*/
glabel D_80051DC4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DC8
.word 0x40490fdb /*3.1415927*/
glabel D_80051DCC
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80051DD0
.word 0x3e32b8c3 /*0.17453294*/
glabel D_80051DD4
.word 0x4016cbe4 /*2.3561945*/
glabel D_80051DD8
.word 0x407b53d2 /*3.926991*/
.text
glabel triggered_on_shot_hit
  addiu $sp, $sp, -0xa0
  li    $t6, 1
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0xa4($sp)
  sw    $t6, 0x9c($sp)
  lw    $v0, 0x18($a0)
  mtc1  $a2, $f12
  li    $at, 6
  sw    $v0, 0x98($sp)
  lw    $t7, 0x1c($a0)
  sw    $zero, 0x90($sp)
  sw    $zero, 0x88($sp)
  sw    $t7, 0x94($sp)
  lbu   $t8, ($v0)
  move  $s0, $a0
  bnel  $t8, $at, .L7F026570
   lb    $v0, 7($s0)
  sw    $a3, 0xac($sp)
  jal   getPlayerCount
   swc1  $f12, 0xa8($sp)
  slti  $at, $v0, 2
  lw    $a3, 0xac($sp)
  beqz  $at, .L7F026F1C
   lwc1  $f12, 0xa8($sp)
  lb    $v0, 7($s0)
.L7F026570:
  lui   $t1, %hi(global_timer) 
  lui   $t3, %hi(D_8002C914) 
  xori  $t9, $v0, 6
  sltiu $v0, $t9, 1
  beqz  $v0, .L7F026598
   lui   $t4, %hi(D_8002C914)
  lw    $t1, %lo(global_timer)($t1)
  lw    $t2, 0x30($s0)
  xor   $v0, $t1, $t2
  sltiu $v0, $v0, 1
.L7F026598:
  lw    $t3, %lo(D_8002C914)($t3)
  li    $a1, -1
  sw    $v0, 0x84($sp)
  beq   $a1, $t3, .L7F0265D8
   move  $a0, $zero
  addiu $v0, $t4, %lo(D_8002C914)
  lw    $v1, ($v0)
.L7F0265B4:
  bnel  $a3, $v1, .L7F0265C8
   lw    $v1, 0x2c($v0)
  b     .L7F0265D8
   sw    $a0, 0x88($sp)
  lw    $v1, 0x2c($v0)
.L7F0265C8:
  addiu $a0, $a0, 1
  addiu $v0, $v0, 0x2c
  bne   $a1, $v1, .L7F0265B4
   nop   
.L7F0265D8:
  lwc1  $f4, 0xfc($s0)
  lwc1  $f6, 0x100($s0)
  li    $at, 7
  c.le.s $f6, $f4
  nop   
  bc1f  .L7F026A44
   nop   
  lui   $at, %hi(D_80051DBC)
  lwc1  $f8, %lo(D_80051DBC)($at)
  lui   $at, %hi(D_80051DC0)
  c.lt.s $f12, $f8
  nop   
  bc1t  .L7F026624
   nop   
  lwc1  $f10, %lo(D_80051DC0)($at)
  c.lt.s $f10, $f12
  nop   
  bc1fl .L7F0267F4
   lw    $t4, 0x90($sp)
.L7F026624:
  jal   get_random_value
   nop   
  li    $at, 20
  divu  $zero, $v0, $at
  mfhi  $t5
  bnezl $t5, .L7F0267F4
   lw    $t4, 0x90($sp)
  jal   getsubroty
   lw    $a0, 0x94($sp)
  lui   $at, %hi(D_80051DC4)
  lwc1  $f18, %lo(D_80051DC4)($at)
  lui   $at, %hi(D_80051DC8)
  lwc1  $f4, %lo(D_80051DC8)($at)
  lui   $at, %hi(D_80051DCC)
  lwc1  $f6, %lo(D_80051DCC)($at)
  add.s $f2, $f0, $f4
  lui   $at, %hi(D_80051DD0)
  lwc1  $f8, %lo(D_80051DD0)($at)
  lui   $a2, 0x4316
  add.s $f12, $f2, $f6
  sub.s $f14, $f2, $f8
  mov.s $f16, $f12
  c.le.s $f18, $f12
  swc1  $f14, 0x70($sp)
  bc1fl .L7F026694
   c.le.s $f18, $f14
  sub.s $f16, $f12, $f18
  c.le.s $f18, $f14
.L7F026694:
  mfc1  $a1, $f16
  bc1f  .L7F0266A8
   nop   
  sub.s $f10, $f14, $f18
  swc1  $f10, 0x70($sp)
.L7F0266A8:
  jal   sub_GAME_7F0264B0
   lw    $a0, 0x98($sp)
  lw    $a0, 0x98($sp)
  lw    $a1, 0x70($sp)
  lui   $a2, 0x4316
  jal   sub_GAME_7F0264B0
   swc1  $f0, 0x6c($sp)
  li    $at, 0x43160000 # 150.000000
  mtc1  $at, $f12
  lwc1  $f2, 0x6c($sp)
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F0267F4
   lw    $t4, 0x90($sp)
  c.lt.s $f0, $f12
  li    $at, 0x41200000 # 10.000000
  bc1fl .L7F0267F4
   lw    $t4, 0x90($sp)
  sub.s $f12, $f2, $f0
  mtc1  $at, $f4
  li    $at, 0xC1200000 # -10.000000
  c.lt.s $f12, $f4
  nop   
  bc1fl .L7F0267F4
   lw    $t4, 0x90($sp)
  mtc1  $at, $f6
  nop   
  c.lt.s $f6, $f12
  nop   
  bc1fl .L7F0267F4
   lw    $t4, 0x90($sp)
  jal   get_random_value
   nop   
  andi  $t6, $v0, 1
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  lui   $t8, %hi(D_8002DEBC) 
  addiu $t8, %lo(D_8002DEBC) # addiu $t8, $t8, -0x2144
  sll   $t7, $t7, 2
  addu  $v1, $t7, $t8
  sw    $v1, 0x64($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  lw    $v1, 0x64($sp)
  li    $t9, 4
  sb    $t9, 7($s0)
  sw    $zero, 0x2c($s0)
  lwc1  $f8, 0x14($v1)
  mtc1  $zero, $f0
  li    $at, 0x41800000 # 16.000000
  swc1  $f8, 0x30($s0)
  lwc1  $f10, 0x18($v1)
  sb    $zero, 8($s0)
  swc1  $f0, 0x38($s0)
  swc1  $f10, 0x34($s0)
  lw    $t1, 0x84($sp)
  mtc1  $at, $f6
  lwc1  $f4, 0xc($v1)
  lw    $a2, 4($v1)
  lw    $a1, ($v1)
  mfc1  $a3, $f0
  sltiu $t2, $t1, 1
  sw    $t2, 0x18($sp)
  lw    $a0, 0x94($sp)
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FC4C
   swc1  $f4, 0x10($sp)
  lw    $v1, 0x64($sp)
  mtc1  $zero, $f8
  lwc1  $f0, 8($v1)
  c.le.s $f8, $f0
  nop   
  bc1fl .L7F0267E0
   lui   $at, 0x4120
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  li    $at, 0x41200000 # 10.000000
.L7F0267E0:
  mtc1  $at, $f10
  li    $t3, 1
  swc1  $f10, 0x24($s0)
  sw    $t3, 0x90($sp)
  lw    $t4, 0x90($sp)
.L7F0267F4:
  lw    $t5, 0x88($sp)
  lui   $t7, %hi(D_8002C914) 
  bnez  $t4, .L7F026A14
   sll   $t6, $t5, 2
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  subu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addiu $t7, %lo(D_8002C914) # addiu $t7, $t7, -0x36ec
  addu  $a2, $t6, $t7
  lw    $t8, 0x1c($a2)
  beqz  $t8, .L7F026A14
   nop   
  lw    $t9, 0x20($a2)
  lw    $t1, 0x84($sp)
  li    $t3, 1
  blez  $t9, .L7F026A14
   sltiu $t2, $t1, 1
  sw    $t2, 0x34($sp)
  sw    $t3, 0x90($sp)
  jal   get_random_value
   sw    $a2, 0x30($sp)
  lw    $a2, 0x30($sp)
  move  $a0, $s0
  lw    $t4, 0x20($a2)
  lw    $t5, 0x1c($a2)
  divu  $zero, $v0, $t4
  mfhi  $v1
  sll   $t6, $v1, 3
  subu  $t6, $t6, $v1
  sll   $t6, $t6, 2
  bnez  $t4, .L7F02687C
   nop   
  break 7
.L7F02687C:
  addu  $t0, $t5, $t6
  jal   sub_GAME_7F02D184
   sw    $t0, 0x5c($sp)
  lw    $t0, 0x5c($sp)
  li    $t7, 4
  sb    $t7, 7($s0)
  sw    $zero, 0x2c($s0)
  lwc1  $f4, 0x14($t0)
  mtc1  $zero, $f0
  li    $at, 0x41800000 # 16.000000
  swc1  $f4, 0x30($s0)
  lwc1  $f6, 0x18($t0)
  sb    $zero, 8($s0)
  swc1  $f0, 0x38($s0)
  swc1  $f6, 0x34($s0)
  lw    $t8, 0x34($sp)
  mtc1  $at, $f10
  lwc1  $f8, 0xc($t0)
  lw    $a2, 4($t0)
  lw    $a1, ($t0)
  mfc1  $a3, $f0
  lw    $a0, 0x94($sp)
  sw    $t8, 0x18($sp)
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FC4C
   swc1  $f8, 0x10($sp)
  lw    $t0, 0x5c($sp)
  lui   $t9, %hi(ptr_animation_table) 
  lw    $t9, %lo(ptr_animation_table)($t9)
  lw    $t3, ($t0)
  lui   $t1, %hi(0x00002E64) # $t1, 0
  addiu $t1, %lo(0x00002E64) # addiu $t1, $t1, 0x2e64
  addu  $t2, $t9, $t1
  bnel  $t2, $t3, .L7F026940
   lwc1  $f0, 8($t0)
  jal   get_random_value
   sw    $t0, 0x5c($sp)
  li    $at, 100
  divu  $zero, $v0, $at
  mfhi  $t4
  lw    $t0, 0x5c($sp)
  beqz  $t4, .L7F02693C
   lw    $a0, 0x94($sp)
  lui   $a1, 0x4371
  jal   sub_GAME_7F06FDE8
   sw    $t0, 0x5c($sp)
  b     .L7F026968
   lw    $t0, 0x5c($sp)
.L7F02693C:
  lwc1  $f0, 8($t0)
.L7F026940:
  mtc1  $zero, $f4
  lw    $a0, 0x94($sp)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F02696C
   lw    $a0, 0xb0($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   sw    $t0, 0x5c($sp)
  lw    $t0, 0x5c($sp)
.L7F026968:
  lw    $a0, 0xb0($sp)
.L7F02696C:
  jal   sub_GAME_7F05DFA8
   sw    $t0, 0x5c($sp)
  mtc1  $zero, $f12
  lw    $t0, 0x5c($sp)
  mov.s $f2, $f0
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F0269B0
   lw    $t7, 0x10($t0)
  lw    $t5, 0x14($s0)
  li    $at, 0x40C00000 # 6.000000
  andi  $t6, $t5, 0x8000
  beql  $t6, $zero, .L7F0269B0
   lw    $t7, 0x10($t0)
  mtc1  $at, $f2
  nop   
  lw    $t7, 0x10($t0)
.L7F0269B0:
  beqz  $t7, .L7F026A14
   nop   
  c.lt.s $f12, $f2
  li    $at, 0x42B40000 # 90.000000
  bc1f  .L7F026A14
   nop   
  mtc1  $at, $f6
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f10
  mul.s $f8, $f2, $f6
  swc1  $f12, 0x3c($s0)
  div.s $f4, $f8, $f10
  swc1  $f4, 0x38($s0)
  lw    $t8, 0xa4($sp)
  lwc1  $f6, ($t8)
  mul.s $f8, $f6, $f2
  swc1  $f8, 0x40($s0)
  lw    $t9, 0xa4($sp)
  lwc1  $f10, 4($t9)
  mul.s $f4, $f10, $f2
  swc1  $f4, 0x44($s0)
  lw    $t1, 0xa4($sp)
  lwc1  $f6, 8($t1)
  mul.s $f8, $f6, $f2
  swc1  $f8, 0x48($s0)
.L7F026A14:
  jal   sub_GAME_7F021B20
   move  $a0, $s0
  jal   increment_num_kills_display_text_in_MP
   nop   
  lw    $t2, 0x14($s0)
  sll   $t3, $t2, 0xb
  bgezl $t3, .L7F026EA0
   lw    $t4, 0x9c($sp)
  jal   inc_cur_civilian_casualties
   nop   
  b     .L7F026EA0
   lw    $t4, 0x9c($sp)
.L7F026A44:
  bne   $a3, $at, .L7F026CC8
   lui   $at, %hi(D_80051DD4)
  lwc1  $f10, %lo(D_80051DD4)($at)
  lui   $at, %hi(D_80051DD8)
  c.lt.s $f10, $f12
  nop   
  bc1fl .L7F026CCC
   lw    $t8, 0x90($sp)
  lwc1  $f4, %lo(D_80051DD8)($at)
  c.lt.s $f12, $f4
  nop   
  bc1fl .L7F026CCC
   lw    $t8, 0x90($sp)
  jal   get_random_value
   nop   
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t4
  sltiu $at, $t4, 2
  beql  $at, $zero, .L7F026CCC
   lw    $t8, 0x90($sp)
  jal   get_random_value
   nop   
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t5
  sw    $t5, 0x54($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  li    $t6, 6
  sb    $t6, 7($s0)
  sw    $zero, 0x2c($s0)
  lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  sb    $zero, 8($s0)
  jal   get_random_value
   sw    $t7, 0x30($s0)
  andi  $t8, $v0, 1
  beqz  $t8, .L7F026BD4
   lui   $t9, %hi(ptr_animation_table) 
  lw    $t9, %lo(ptr_animation_table)($t9)
  lui   $t1, %hi(0x00004CE0) # $t1, 0
  addiu $t1, %lo(0x00004CE0) # addiu $t1, $t1, 0x4ce0
  addu  $t2, $t9, $t1
  jal   get_random_value
   sw    $t2, 0x80($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lw    $t3, 0x84($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f8
  sltiu $t4, $t3, 1
  sw    $t4, 0x18($sp)
  lw    $a0, 0x94($sp)
  lw    $a1, 0x80($sp)
  andi  $a2, $v0, 1
  lui   $a3, 0x4120
  swc1  $f6, 0x10($sp)
  jal   sub_GAME_7F06FC4C
   swc1  $f8, 0x14($sp)
  lw    $v0, 0x54($sp)
  move  $a0, $s0
  lui   $a1, 0x4208
  sltiu $at, $v0, 2
  beql  $at, $zero, .L7F026B6C
   sltiu $at, $v0, 4
  jal   sub_GAME_7F023C54
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026CC4
   li    $t7, 1
  sltiu $at, $v0, 4
.L7F026B6C:
  beqz  $at, .L7F026B98
   lw    $t5, 0x80($sp)
  move  $a0, $s0
  lui   $a1, 0x428e
  jal   sub_GAME_7F023C54
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026CC4
   li    $t7, 1
.L7F026B98:
  lhu   $t6, 4($t5)
  move  $a0, $s0
  lui   $a2, 0x4100
  addiu $t7, $t6, -1
  mtc1  $t7, $f10
  nop   
  cvt.s.w $f10, $f10
  mfc1  $a1, $f10
  jal   sub_GAME_7F023C54
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026CC4
   li    $t7, 1
.L7F026BD4:
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  lui   $t9, %hi(0x00004F14) # $t9, 0
  addiu $t9, %lo(0x00004F14) # addiu $t9, $t9, 0x4f14
  addu  $t1, $t8, $t9
  jal   get_random_value
   sw    $t1, 0x80($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  lw    $t2, 0x84($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  sltiu $t3, $t2, 1
  sw    $t3, 0x18($sp)
  lw    $a0, 0x94($sp)
  lw    $a1, 0x80($sp)
  andi  $a2, $v0, 1
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F06FC4C
   swc1  $f6, 0x14($sp)
  lw    $v0, 0x54($sp)
  move  $a0, $s0
  lui   $a1, 0x4214
  sltiu $at, $v0, 2
  beql  $at, $zero, .L7F026C60
   sltiu $at, $v0, 4
  jal   sub_GAME_7F023C54
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026CC4
   li    $t7, 1
  sltiu $at, $v0, 4
.L7F026C60:
  beqz  $at, .L7F026C8C
   lw    $t4, 0x80($sp)
  move  $a0, $s0
  lui   $a1, 0x428c
  jal   sub_GAME_7F023C54
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026CC4
   li    $t7, 1
.L7F026C8C:
  lhu   $t5, 4($t4)
  move  $a0, $s0
  lui   $a2, 0x4100
  addiu $t6, $t5, -1
  mtc1  $t6, $f8
  nop   
  cvt.s.w $f8, $f8
  mfc1  $a1, $f8
  jal   sub_GAME_7F023C54
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  li    $t7, 1
.L7F026CC4:
  sw    $t7, 0x90($sp)
.L7F026CC8:
  lw    $t8, 0x90($sp)
.L7F026CCC:
  lw    $t9, 0x88($sp)
  lui   $t2, %hi(D_8002C914) 
  bnez  $t8, .L7F026E98
   sll   $t1, $t9, 2
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  addiu $t2, %lo(D_8002C914) # addiu $t2, $t2, -0x36ec
  addu  $a2, $t1, $t2
  lw    $t3, 0x24($a2)
  beql  $t3, $zero, .L7F026E9C
   sw    $zero, 0x9c($sp)
  lw    $t4, 0x28($a2)
  move  $a0, $s0
  li    $a1, 1
  blez  $t4, .L7F026E98
   lw    $t5, 0x84($sp)
  sltiu $t6, $t5, 1
  li    $t7, 1
  sw    $t7, 0x90($sp)
  sw    $t6, 0x34($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $a2, 0x30($sp)
  sw    $v0, 0x50($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lw    $a2, 0x30($sp)
  lui   $t8, %hi(D_8002CAA0) 
  addiu $t8, %lo(D_8002CAA0) # addiu $t8, $t8, -0x3560
  bne   $a2, $t8, .L7F026D68
   lw    $t9, 0x50($sp)
  beqz  $t9, .L7F026D68
   li    $t1, 10
  lui   $a2, %hi(D_8002CACC)
  addiu $a2, %lo(D_8002CACC) # addiu $a2, $a2, -0x3534
  b     .L7F026D8C
   sw    $t1, 0x88($sp)
.L7F026D68:
  lui   $t2, %hi(D_8002CB24) 
  addiu $t2, %lo(D_8002CB24) # addiu $t2, $t2, -0x34dc
  bne   $a2, $t2, .L7F026D8C
   nop   
  beqz  $v0, .L7F026D8C
   li    $t3, 13
  lui   $a2, %hi(D_8002CB50)
  addiu $a2, %lo(D_8002CB50) # addiu $a2, $a2, -0x34b0
  sw    $t3, 0x88($sp)
.L7F026D8C:
  jal   get_random_value
   sw    $a2, 0x30($sp)
  lw    $a2, 0x30($sp)
  move  $a0, $s0
  lw    $t4, 0x28($a2)
  lw    $t5, 0x24($a2)
  divu  $zero, $v0, $t4
  mfhi  $a1
  sll   $t6, $a1, 3
  subu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  bnez  $t4, .L7F026DC4
   nop   
  break 7
.L7F026DC4:
  addu  $v1, $t5, $t6
  jal   sub_GAME_7F02D184
   sw    $v1, 0x44($sp)
  lw    $v1, 0x44($sp)
  li    $t7, 6
  sb    $t7, 7($s0)
  sw    $zero, 0x2c($s0)
  lui   $t8, %hi(global_timer) 
  lw    $t8, %lo(global_timer)($t8)
  sb    $zero, 8($s0)
  li    $at, 0x41800000 # 16.000000
  sw    $t8, 0x30($s0)
  lw    $t9, 0x34($sp)
  mtc1  $at, $f4
  lwc1  $f10, 0xc($v1)
  lw    $a2, 4($v1)
  lw    $a1, ($v1)
  lw    $a0, 0x94($sp)
  li    $a3, 0
  sw    $t9, 0x18($sp)
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FC4C
   swc1  $f10, 0x10($sp)
  lw    $v1, 0x44($sp)
  mtc1  $zero, $f6
  move  $a0, $s0
  lwc1  $f0, 8($v1)
  c.le.s $f6, $f0
  nop   
  bc1fl .L7F026E64
   lw    $t1, ($v1)
  mfc1  $a1, $f0
  jal   sub_GAME_7F023C54
   lui   $a2, 0x4100
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
  b     .L7F026E9C
   sw    $zero, 0x9c($sp)
  lw    $t1, ($v1)
.L7F026E64:
  move  $a0, $s0
  lui   $a2, 0x4100
  lhu   $t2, 4($t1)
  addiu $t3, $t2, -1
  mtc1  $t3, $f8
  nop   
  cvt.s.w $f8, $f8
  mfc1  $a1, $f8
  jal   sub_GAME_7F023C54
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x94($sp)
.L7F026E98:
  sw    $zero, 0x9c($sp)
.L7F026E9C:
  lw    $t4, 0x9c($sp)
.L7F026EA0:
  lw    $t5, 0x90($sp)
  beql  $t4, $zero, .L7F026F20
   lw    $ra, 0x2c($sp)
  beql  $t5, $zero, .L7F026F20
   lw    $ra, 0x2c($sp)
  lw    $a0, 0x160($s0)
  beql  $a0, $zero, .L7F026EEC
   lw    $a0, 0x164($s0)
  lw    $t6, 4($a0)
  lw    $t7, 8($t6)
  andi  $t8, $t7, 0x2000
  bnezl $t8, .L7F026EEC
   lw    $a0, 0x164($s0)
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t9, 0x12($s0)
  ori   $t1, $t9, 1
  sh    $t1, 0x12($s0)
  lw    $a0, 0x164($s0)
.L7F026EEC:
  beql  $a0, $zero, .L7F026F20
   lw    $ra, 0x2c($sp)
  lw    $t2, 4($a0)
  lw    $t3, 8($t2)
  andi  $t4, $t3, 0x2000
  bnezl $t4, .L7F026F20
   lw    $ra, 0x2c($sp)
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t5, 0x12($s0)
  ori   $t6, $t5, 1
  sh    $t6, 0x12($s0)
.L7F026F1C:
  lw    $ra, 0x2c($sp)
.L7F026F20:
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F026F30
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a1, 0x24($sp)
  lb    $v0, 7($a0)
  li    $at, 10
  move  $a2, $a0
  bne   $v0, $at, .L7F02703C
   move  $v1, $zero
  lb    $t6, 0x35($a0)
  beql  $t6, $zero, .L7F026FF4
   lw    $t2, 0x2c($a2)
  lw    $v0, 0x2c($a0)
  lui   $t7, %hi(D_80030198) 
  addiu $t7, %lo(D_80030198) # addiu $t7, $t7, 0x198
  beq   $t7, $v0, .L7F026F94
   lui   $t8, %hi(D_800301E0) 
  addiu $t8, %lo(D_800301E0) # addiu $t8, $t8, 0x1e0
  beq   $t8, $v0, .L7F026F94
   lui   $t9, %hi(D_80030228) 
  addiu $t9, %lo(D_80030228) # addiu $t9, $t9, 0x228
  beq   $t9, $v0, .L7F026F94
   lui   $t0, %hi(D_80030270) 
  addiu $t0, %lo(D_80030270) # addiu $t0, $t0, 0x270
  bnel  $t0, $v0, .L7F027050
   lw    $ra, 0x14($sp)
.L7F026F94:
  lwc1  $f0, 4($v0)
  lwc1  $f12, 0x14($v0)
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f4
  c.lt.s $f12, $f0
  sub.s $f2, $f0, $f4
  bc1fl .L7F026FBC
   lw    $a0, 0x1c($a2)
  mov.s $f2, $f12
  lw    $a0, 0x1c($a2)
.L7F026FBC:
  swc1  $f2, 0x18($sp)
  jal   sub_GAME_7F06F5BC
   sw    $v1, 0x1c($sp)
  lwc1  $f2, 0x18($sp)
  lw    $v1, 0x1c($sp)
  lw    $t1, 0x24($sp)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F027050
   lw    $ra, 0x14($sp)
  swc1  $f2, ($t1)
  b     .L7F02704C
   li    $v1, 1
  lw    $t2, 0x2c($a2)
.L7F026FF4:
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f8
  lwc1  $f6, 4($t2)
  lw    $a0, 0x1c($a2)
  sw    $v1, 0x1c($sp)
  sub.s $f2, $f6, $f8
  jal   sub_GAME_7F06F5BC
   swc1  $f2, 0x18($sp)
  lwc1  $f2, 0x18($sp)
  lw    $v1, 0x1c($sp)
  lw    $t3, 0x24($sp)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F027050
   lw    $ra, 0x14($sp)
  swc1  $f2, ($t3)
  b     .L7F02704C
   li    $v1, 1
.L7F02703C:
  li    $at, 7
  bnel  $v0, $at, .L7F027050
   lw    $ra, 0x14($sp)
  li    $v1, 1
.L7F02704C:
  lw    $ra, 0x14($sp)
.L7F027050:
  addiu $sp, $sp, 0x20
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel play_sound_for_shot_actor
  addiu $sp, $sp, -0x68
  sw    $ra, 0x14($sp)
  sw    $a0, 0x68($sp)
  lw    $a1, 0x18($a0)
  li    $at, 6
  move  $v1, $zero
  lbu   $t7, ($a1)
  move  $a0, $a1
  bnel  $t7, $at, .L7F0270B4
   lw    $t1, 0x68($sp)
  jal   sub_GAME_7F09B15C
   sw    $zero, 0x60($sp)
  sll   $t8, $v0, 2
  lui   $t9, %hi(players_p1)
  addu  $t9, $t9, $t8
  lw    $t9, %lo(players_p1)($t9)
  lw    $v1, 0x60($sp)
  lw    $t0, 0xd8($t9)
  bnezl $t0, .L7F027270
   lw    $ra, 0x14($sp)
  lw    $t1, 0x68($sp)
.L7F0270B4:
  li    $at, 6
  lw    $t9, 0x68($sp)
  lw    $t2, 0x18($t1)
  lbu   $t3, ($t2)
  bnel  $t3, $at, .L7F02713C
   lb    $t0, 0xf($t9)
  jal   getPlayerCount
   sw    $v1, 0x60($sp)
  li    $at, 1
  bne   $v0, $at, .L7F027110
   lw    $v1, 0x60($sp)
  lw    $t4, 0x68($sp)
  lui   $t7, %hi(c_item_entries+16)
  lb    $t5, 0xf($t4)
  sll   $t6, $t5, 2
  addu  $t6, $t6, $t5
  sll   $t6, $t6, 2
  addu  $t7, $t7, $t6
  lbu   $t7, %lo(c_item_entries+16)($t7)
  beqz  $t7, .L7F027160
   nop   
  b     .L7F027160
   li    $v1, 1
.L7F027110:
  lw    $t8, 0x68($sp)
  lw    $a0, 0x18($t8)
  jal   sub_GAME_7F09B15C
   sw    $v1, 0x60($sp)
  jal   get_player_mp_char_gender
   move  $a0, $v0
  beqz  $v0, .L7F027160
   lw    $v1, 0x60($sp)
  b     .L7F027160
   li    $v1, 1
  lb    $t0, 0xf($t9)
.L7F02713C:
  lui   $t2, %hi(c_item_entries+16)
  sll   $t1, $t0, 2
  addu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  addu  $t2, $t2, $t1
  lbu   $t2, %lo(c_item_entries+16)($t2)
  beqz  $t2, .L7F027160
   nop   
  li    $v1, 1
.L7F027160:
  beqz  $v1, .L7F0271F8
   lui   $t0, %hi(female_guard_yelps) 
  lui   $t3, %hi(male_guard_yelps) 
  addiu $v0, $sp, 0x28
  addiu $t3, %lo(male_guard_yelps) # addiu $t3, $t3, 0x9f8
  addiu $t5, $t3, 0x30
  move  $t6, $v0
.L7F02717C:
  lw    $at, ($t3)
  addiu $t3, $t3, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t3)
  sw    $at, -8($t6)
  lw    $at, -4($t3)
  bne   $t3, $t5, .L7F02717C
   sw    $at, -4($t6)
  lhu   $at, ($t3)
  lui   $t7, %hi(male_guard_yelp_counter) 
  lui   $a0, %hi(ptr_sfx_buf)
  sh    $at, ($t6)
  lw    $t7, %lo(male_guard_yelp_counter)($t7)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a2, $zero
  sll   $t8, $t7, 1
  addu  $t9, $v0, $t8
  jal   play_sfx_a1
   lh    $a1, ($t9)
  lui   $v1, %hi(male_guard_yelp_counter)
  lw    $v1, %lo(male_guard_yelp_counter)($v1)
  lui   $at, %hi(male_guard_yelp_counter)
  move  $a0, $v0
  addiu $v1, $v1, 1
  sw    $v1, %lo(male_guard_yelp_counter)($at)
  slti  $at, $v1, 0x19
  bnez  $at, .L7F02725C
   lui   $at, %hi(male_guard_yelp_counter)
  b     .L7F02725C
   sw    $zero, %lo(male_guard_yelp_counter)($at)
.L7F0271F8:
  addiu $t0, %lo(female_guard_yelps) # addiu $t0, $t0, 0xa2c
  lw    $at, ($t0)
  addiu $v0, $sp, 0x20
  lui   $t5, %hi(female_guard_yelp_counter) 
  sw    $at, ($v0)
  lhu   $at, 4($t0)
  lui   $a0, %hi(ptr_sfx_buf)
  move  $a2, $zero
  sh    $at, 4($v0)
  lw    $t5, %lo(female_guard_yelp_counter)($t5)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sll   $t3, $t5, 1
  addu  $t6, $v0, $t3
  jal   play_sfx_a1
   lh    $a1, ($t6)
  lui   $v1, %hi(female_guard_yelp_counter)
  lw    $v1, %lo(female_guard_yelp_counter)($v1)
  lui   $at, %hi(female_guard_yelp_counter)
  move  $a0, $v0
  addiu $v1, $v1, 1
  sw    $v1, %lo(female_guard_yelp_counter)($at)
  slti  $at, $v1, 3
  bnez  $at, .L7F02725C
   lui   $at, %hi(female_guard_yelp_counter)
  sw    $zero, %lo(female_guard_yelp_counter)($at)
.L7F02725C:
  lw    $t7, 0x68($sp)
  lw    $a1, 0x18($t7)
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $ra, 0x14($sp)
.L7F027270:
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DDC
.word 0x3f860a92 /*1.0471976*/
glabel D_80051DE0
.word 0x40a78d36 /*5.2359877*/
glabel D_80051DE4
.word 0x40060a92 /*2.0943952*/
glabel D_80051DE8
.word 0x40860a92 /*4.1887903*/
.text
glabel handles_shot_actors
  addiu $sp, $sp, -0x68
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  lw    $t6, 0x18($a0)
  li    $at, 110
  move  $s0, $a0
  bne   $a1, $at, .L7F02734C
   sw    $t6, 0x60($sp)
  lw    $a0, 0x1d8($a0)
  beql  $a0, $zero, .L7F027350
   lw    $t7, 0x78($sp)
  jal   get_hat_model
   nop   
  li    $at, 5
  bne   $v0, $at, .L7F0272D0
   li    $t8, 8
  b     .L7F02734C
   sw    $t8, 0x6c($sp)
.L7F0272D0:
  li    $at, 3
  beq   $v0, $at, .L7F0272F8
   lui   $t2, %hi(metal_ricochet_SFX) 
  lw    $a0, 0x1d8($s0)
  jal   sub_GAME_7F04BFD0
   li    $a1, 4
  lhu   $t9, 0x12($s0)
  ori   $t0, $t9, 1
  b     .L7F02734C
   sh    $t0, 0x12($s0)
.L7F0272F8:
  addiu $t2, %lo(metal_ricochet_SFX) # addiu $t2, $t2, 0xa3c
  lw    $at, ($t2)
  addiu $t1, $sp, 0x54
  sw    $at, ($t1)
  lhu   $at, 4($t2)
  jal   get_random_value
   sh    $at, 4($t1)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t5
  sll   $t6, $t5, 1
  addu  $a1, $sp, $t6
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  lh    $a1, 0x54($a1)
  jal   play_sfx_a1
   move  $a2, $zero
  lw    $a1, 0x18($s0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
.L7F02734C:
  lw    $t7, 0x78($sp)
.L7F027350:
  lw    $t8, 0x6c($sp)
  beql  $t7, $zero, .L7F0273EC
   lw    $t3, 0x14($s0)
  beqz  $t8, .L7F0273E8
   li    $at, 7
  beq   $t8, $at, .L7F0273D0
   lw    $a0, 0x74($sp)
  li    $at, 8
  beq   $t8, $at, .L7F0273A0
   li    $a1, 1
  li    $at, 15
  beq   $t8, $at, .L7F0273D0
   li    $at, 100
  beq   $t8, $at, .L7F0273B0
   lw    $a0, 0x74($sp)
  li    $at, 110
  beq   $t8, $at, .L7F0273C0
   lw    $a0, 0x74($sp)
  b     .L7F0273E0
   lw    $a0, 0x74($sp)
.L7F0273A0:
  jal   inc_curplayer_hitcount_with_weapon
   lw    $a0, 0x74($sp)
  b     .L7F0273EC
   lw    $t3, 0x14($s0)
.L7F0273B0:
  jal   inc_curplayer_hitcount_with_weapon
   li    $a1, 4
  b     .L7F0273EC
   lw    $t3, 0x14($s0)
.L7F0273C0:
  jal   inc_curplayer_hitcount_with_weapon
   li    $a1, 5
  b     .L7F0273EC
   lw    $t3, 0x14($s0)
.L7F0273D0:
  jal   inc_curplayer_hitcount_with_weapon
   li    $a1, 2
  b     .L7F0273EC
   lw    $t3, 0x14($s0)
.L7F0273E0:
  jal   inc_curplayer_hitcount_with_weapon
   li    $a1, 3
.L7F0273E8:
  lw    $t3, 0x14($s0)
.L7F0273EC:
  lb    $t9, 0xb($s0)
  lui   $at, 0x20
  or    $t1, $t3, $at
  andi  $t4, $t1, 0x10
  addiu $t0, $t9, 1
  sb    $t0, 0xb($s0)
  beqz  $t4, .L7F02741C
   sw    $t1, 0x14($s0)
  jal   sub_GAME_7F0206D4
   move  $a0, $s0
  b     .L7F0277F0
   move  $v0, $zero
.L7F02741C:
  lb    $v0, 7($s0)
  li    $at, 4
  beq   $v0, $at, .L7F0277EC
   li    $at, 5
  beql  $v0, $at, .L7F0277F0
   li    $v0, 1
  jal   sub_GAME_7F05DF84
   lw    $a0, 0x74($sp)
  lw    $t5, 0x78($sp)
  mov.s $f2, $f0
  beql  $t5, $zero, .L7F027474
   lw    $v0, 0x70($sp)
  jal   getPlayerCount
   swc1  $f2, 0x3c($sp)
  li    $at, 1
  bne   $v0, $at, .L7F027470
   lwc1  $f2, 0x3c($sp)
  lui   $at, %hi(ai_health_modifier)
  lwc1  $f4, %lo(ai_health_modifier)($at)
  mul.s $f2, $f2, $f4
  nop   
.L7F027470:
  lw    $v0, 0x70($sp)
.L7F027474:
  lw    $t6, 0x60($sp)
  move  $a0, $s0
  lwc1  $f8, ($v0)
  lwc1  $f6, 8($t6)
  addiu $a1, $sp, 0x44
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x44($sp)
  lwc1  $f18, 4($v0)
  lwc1  $f16, 0xc($t6)
  sub.s $f4, $f16, $f18
  swc1  $f4, 0x48($sp)
  lwc1  $f8, 8($v0)
  lwc1  $f6, 0x10($t6)
  swc1  $f2, 0x3c($sp)
  sub.s $f10, $f6, $f8
  jal   get_distance_actor_to_position
   swc1  $f10, 0x4c($sp)
  lw    $t7, 0x6c($sp)
  li    $at, 200
  li    $v1, 1
  lwc1  $f2, 0x3c($sp)
  bne   $t7, $at, .L7F0274EC
   swc1  $f0, 0x40($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  li    $t8, 15
  sw    $t8, 0x6c($sp)
  mul.s $f2, $f2, $f16
  b     .L7F027514
   lw    $t3, 0x74($sp)
.L7F0274EC:
  lw    $t9, 0x6c($sp)
  li    $at, 201
  bne   $t9, $at, .L7F027510
   li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f18
  li    $t0, 15
  sw    $t0, 0x6c($sp)
  mul.s $f2, $f2, $f18
  nop   
.L7F027510:
  lw    $t3, 0x74($sp)
.L7F027514:
  lw    $t2, 0x6c($sp)
  lw    $t4, 0x6c($sp)
  bnel  $t3, $v1, .L7F027604
   li    $at, 8
  lb    $v0, 7($s0)
  li    $at, 14
  beql  $v1, $v0, .L7F027604
   li    $at, 8
  beq   $v0, $at, .L7F027600
   li    $at, 16
  beq   $v0, $at, .L7F027600
   li    $at, 3
  beq   $v0, $at, .L7F027600
   li    $at, 15
  bne   $v0, $at, .L7F02755C
   nop   
  lbu   $t1, 0x59($s0)
  beqz  $t1, .L7F027600
.L7F02755C:
   lui   $at, %hi(D_80051DDC)
  lwc1  $f4, %lo(D_80051DDC)($at)
  lui   $at, %hi(D_80051DE0)
  c.lt.s $f0, $f4
  nop   
  bc1tl .L7F027594
   lui   $at, 0x3e00
  lwc1  $f6, %lo(D_80051DE0)($at)
  lui   $at, %hi(D_80051DE4)
  c.lt.s $f6, $f0
  nop   
  bc1f  .L7F0275A8
   nop   
  li    $at, 0x3E000000 # 0.125000
.L7F027594:
  mtc1  $at, $f8
  nop   
  mul.s $f2, $f2, $f8
  b     .L7F027604
   li    $at, 8
.L7F0275A8:
  lwc1  $f10, %lo(D_80051DE4)($at)
  lui   $at, %hi(D_80051DE8)
  c.lt.s $f0, $f10
  nop   
  bc1tl .L7F0275DC
   li    $at, 0x3E800000 # 0.250000
  lwc1  $f16, %lo(D_80051DE8)($at)
  li    $at, 0x3F000000 # 0.500000
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F0275F4
   mtc1  $at, $f4
  li    $at, 0x3E800000 # 0.250000
.L7F0275DC:
  mtc1  $at, $f18
  nop   
  mul.s $f2, $f2, $f18
  b     .L7F027604
   li    $at, 8
  mtc1  $at, $f4
.L7F0275F4:
  nop   
  mul.s $f2, $f2, $f4
  nop   
.L7F027600:
  li    $at, 8
.L7F027604:
  bne   $t2, $at, .L7F027620
   li    $at, 0x40800000 # 4.000000
  mtc1  $at, $f6
  nop   
  mul.s $f2, $f2, $f6
  b     .L7F027664
   lw    $t7, 0x18($s0)
.L7F027620:
  li    $at, 15
  bne   $t4, $at, .L7F027634
   lw    $t5, 0x6c($sp)
  b     .L7F027660
   add.s $f2, $f2, $f2
.L7F027634:
  li    $at, 100
  bne   $t5, $at, .L7F02764C
   lw    $t6, 0x6c($sp)
  mtc1  $zero, $f2
  b     .L7F027664
   lw    $t7, 0x18($s0)
.L7F02764C:
  li    $at, 110
  bnel  $t6, $at, .L7F027664
   lw    $t7, 0x18($s0)
  mtc1  $zero, $f2
  nop   
.L7F027660:
  lw    $t7, 0x18($s0)
.L7F027664:
  li    $at, 6
  lbu   $t8, ($t7)
  bnel  $t8, $at, .L7F0276D0
   lwc1  $f10, 0xfc($s0)
  jal   get_cur_playernum
   swc1  $f2, 0x3c($sp)
  sw    $v0, 0x38($sp)
  jal   sub_GAME_7F09B15C
   lw    $a0, 0x18($s0)
  jal   set_cur_player
   move  $a0, $v0
  lw    $t9, 0x70($sp)
  li    $at, 0x3E000000 # 0.125000
  lwc1  $f2, 0x3c($sp)
  mtc1  $at, $f8
  li    $t0, 1
  lwc1  $f14, ($t9)
  lw    $a2, 8($t9)
  mul.s $f12, $f2, $f8
  sw    $t0, 0x10($sp)
  jal   record_damage_kills
   lw    $a3, 0x38($sp)
  jal   set_cur_player
   lw    $a0, 0x38($sp)
  b     .L7F027730
   lw    $t2, 0x6c($sp)
  lwc1  $f10, 0xfc($s0)
.L7F0276D0:
  mtc1  $zero, $f4
  lw    $t3, 0x14($s0)
  add.s $f16, $f10, $f2
  li    $at, 0xBF800000 # -1.000000
  ori   $t1, $t3, 0x100
  sw    $t1, 0x14($s0)
  swc1  $f16, 0xfc($s0)
  lwc1  $f18, 0xfc($s0)
  move  $a0, $s0
  c.lt.s $f18, $f4
  nop   
  bc1fl .L7F027730
   lw    $t2, 0x6c($sp)
  mtc1  $at, $f6
  addiu $a1, $sp, 0x34
  jal   sub_GAME_7F026F30
   swc1  $f6, 0x34($sp)
  bnezl $v0, .L7F027730
   lw    $t2, 0x6c($sp)
  jal   sub_GAME_7F0206D4
   move  $a0, $s0
  b     .L7F0277F0
   move  $v0, $zero
  lw    $t2, 0x6c($sp)
.L7F027730:
  li    $at, 110
  beq   $t2, $at, .L7F0277EC
   li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f8
  move  $a0, $s0
  jal   play_sound_for_shot_actor
   swc1  $f8, 0x30($sp)
  move  $a0, $s0
  jal   sub_GAME_7F026F30
   addiu $a1, $sp, 0x30
  beqz  $v0, .L7F0277D4
   move  $a0, $s0
  lwc1  $f10, 0x30($sp)
  mtc1  $zero, $f16
  nop   
  c.le.s $f16, $f10
  nop   
  bc1fl .L7F02778C
   li    $t4, 7
  mfc1  $a1, $f10
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x1c($s0)
  li    $t4, 7
.L7F02778C:
  sb    $t4, 7($s0)
  lw    $t5, 0x70($sp)
  lwc1  $f18, ($t5)
  swc1  $f18, 0x2c($s0)
  lw    $t6, 0x70($sp)
  lwc1  $f4, 4($t6)
  swc1  $f4, 0x30($s0)
  lw    $t7, 0x70($sp)
  lwc1  $f6, 8($t7)
  swc1  $f6, 0x34($s0)
  lwc1  $f8, 0x40($sp)
  swc1  $f8, 0x38($s0)
  lw    $t8, 0x6c($sp)
  sw    $t8, 0x3c($s0)
  lw    $t9, 0x74($sp)
  sb    $zero, 8($s0)
  b     .L7F0277EC
   sw    $t9, 0x40($s0)
.L7F0277D4:
  lw    $t0, 0x74($sp)
  lw    $a1, 0x70($sp)
  lw    $a2, 0x40($sp)
  lw    $a3, 0x6c($sp)
  jal   triggered_on_shot_hit
   sw    $t0, 0x10($sp)
.L7F0277EC:
  li    $v0, 1
.L7F0277F0:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DEC
.word 0x40c90fdb /*6.2831855*/
glabel D_80051DF0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F027804
  addiu $sp, $sp, -0x58
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a2, 0x60($sp)
  sw    $a3, 0x64($sp)
  lb    $v1, 7($a0)
  li    $at, 5
  move  $s0, $a0
  lw    $a2, 0x1c($a0)
  beq   $v1, $at, .L7F02783C
   lw    $v0, 0x18($a0)
  li    $at, 4
  bnel  $v1, $at, .L7F027848
   lw    $t6, 0x14($s0)
.L7F02783C:
  b     .L7F027BE0
   move  $v0, $zero
  lw    $t6, 0x14($s0)
.L7F027848:
  lui   $at, 0x20
  or    $v1, $t6, $at
  andi  $t8, $v1, 0x10
  beqz  $t8, .L7F027864
   sw    $v1, 0x14($s0)
  b     .L7F027BE0
   move  $v0, $zero
.L7F027864:
  lb    $t9, 0xb($s0)
  lwc1  $f4, 0xfc($s0)
  mtc1  $zero, $f10
  addiu $t0, $t9, 1
  sb    $t0, 0xb($s0)
  lwc1  $f6, 0x60($sp)
  ori   $t1, $v1, 0x100
  sw    $t1, 0x14($s0)
  add.s $f8, $f4, $f6
  swc1  $f8, 0xfc($s0)
  lwc1  $f4, 0xfc($s0)
  c.lt.s $f10, $f4
  nop   
  bc1fl .L7F027BE0
   move  $v0, $zero
  lwc1  $f6, 0x100($s0)
  move  $a0, $a2
  swc1  $f6, 0xfc($s0)
  sw    $a2, 0x54($sp)
  sw    $a1, 0x5c($sp)
  jal   getsubroty
   sw    $v0, 0x50($sp)
  lw    $v0, 0x50($sp)
  lw    $a1, 0x5c($sp)
  swc1  $f0, 0x4c($sp)
  lwc1  $f4, 0x10($v0)
  lwc1  $f8, 8($v0)
  lwc1  $f6, 8($a1)
  lwc1  $f10, ($a1)
  sub.s $f14, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f12, $f8, $f10
  lw    $v0, 0x50($sp)
  lw    $a1, 0x5c($sp)
  mtc1  $zero, $f2
  lwc1  $f8, 8($v0)
  lwc1  $f10, ($a1)
  mov.s $f16, $f0
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x2c($sp)
  lwc1  $f6, 0xc($v0)
  lwc1  $f8, 4($a1)
  sub.s $f10, $f6, $f8
  swc1  $f10, 0x30($sp)
  lwc1  $f10, 0x2c($sp)
  lwc1  $f4, 0x10($v0)
  lwc1  $f6, 8($a1)
  c.eq.s $f2, $f10
  sub.s $f8, $f4, $f6
  bc1f  .L7F027964
   swc1  $f8, 0x34($sp)
  lwc1  $f14, 0x30($sp)
  lwc1  $f18, 0x34($sp)
  c.eq.s $f2, $f14
  nop   
  bc1fl .L7F027968
   lwc1  $f0, 0x2c($sp)
  c.eq.s $f2, $f18
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F027968
   lwc1  $f0, 0x2c($sp)
  mtc1  $at, $f18
  nop   
  swc1  $f18, 0x34($sp)
.L7F027964:
  lwc1  $f0, 0x2c($sp)
.L7F027968:
  lwc1  $f14, 0x30($sp)
  lwc1  $f18, 0x34($sp)
  mul.s $f4, $f0, $f0
  swc1  $f16, 0x48($sp)
  mul.s $f6, $f14, $f14
  add.s $f8, $f4, $f6
  mul.s $f10, $f18, $f18
  jal   sqrtf
   add.s $f12, $f10, $f8
  li    $at, 0x40A00000 # 5.000000
  mtc1  $at, $f4
  lwc1  $f6, 0x60($sp)
  lwc1  $f8, 0x2c($sp)
  lwc1  $f16, 0x48($sp)
  mul.s $f10, $f4, $f6
  lwc1  $f6, 0x30($sp)
  lwc1  $f18, 0x4c($sp)
  c.lt.s $f16, $f18
  div.s $f2, $f10, $f0
  sub.s $f14, $f16, $f18
  mov.s $f12, $f14
  mul.s $f4, $f8, $f2
  lwc1  $f8, 0x34($sp)
  mul.s $f10, $f6, $f2
  nop   
  mul.s $f6, $f8, $f2
  swc1  $f4, 0x2c($sp)
  swc1  $f10, 0x30($sp)
  swc1  $f6, 0x34($sp)
  swc1  $f4, 0xb0($s0)
  lwc1  $f10, 0x30($sp)
  swc1  $f10, 0xb4($s0)
  lwc1  $f8, 0x34($sp)
  bc1f  .L7F027A00
   swc1  $f8, 0xb8($s0)
  lui   $at, %hi(D_80051DEC)
  lwc1  $f6, %lo(D_80051DEC)($at)
  add.s $f12, $f14, $f6
.L7F027A00:
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_80051DF0)
  lwc1  $f8, %lo(D_80051DF0)($at)
  mul.s $f10, $f12, $f4
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  div.s $f6, $f10, $f8
  add.s $f10, $f6, $f4
  trunc.w.s $f8, $f10
  mfc1  $a3, $f8
  nop   
  slti  $at, $a3, 8
  bnez  $at, .L7F027A40
   nop   
  move  $a3, $zero
.L7F027A40:
  jal   get_random_value
   sw    $a3, 0x40($sp)
  lw    $a3, 0x40($sp)
  lui   $t4, %hi(explosion_animation_table) 
  addiu $t4, %lo(explosion_animation_table) # addiu $t4, $t4, -0x16a0
  sll   $t3, $a3, 3
  addu  $a1, $t3, $t4
  lw    $t5, 4($a1)
  lw    $t6, ($a1)
  lui   $t0, %hi(D_8002E648) 
  divu  $zero, $v0, $t5
  mfhi  $a2
  addu  $t7, $t6, $a2
  lb    $t8, ($t7)
  addiu $t0, %lo(D_8002E648) # addiu $t0, $t0, -0x19b8
  bnez  $t5, .L7F027A88
   nop   
  break 7
.L7F027A88:
  sll   $t9, $t8, 3
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $v1, $t9, $t0
  sw    $v1, 0x38($sp)
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  lw    $v1, 0x38($sp)
  li    $t1, 4
  sb    $t1, 7($s0)
  sw    $zero, 0x2c($s0)
  lwc1  $f6, 0x14($v1)
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f4
  mtc1  $zero, $f10
  swc1  $f6, 0x30($s0)
  sb    $zero, 8($s0)
  swc1  $f4, 0x34($s0)
  swc1  $f10, 0x38($s0)
  li    $at, 0x41000000 # 8.000000
  lui   $t3, %hi(ptr_animation_table) 
  lw    $t3, %lo(ptr_animation_table)($t3)
  mtc1  $at, $f6
  lwc1  $f8, 8($v1)
  lw    $t2, ($v1)
  lw    $a3, 0xc($v1)
  lw    $a2, 4($v1)
  lw    $a0, 0x54($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x10($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t2, $t3
  lw    $v1, 0x38($sp)
  mtc1  $zero, $f4
  lwc1  $f0, 0x18($v1)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F027B34
   lw    $t4, 0x64($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x54($sp)
  lw    $t4, 0x64($sp)
.L7F027B34:
  beqz  $t4, .L7F027B44
   nop   
  jal   play_sound_for_shot_actor
   move  $a0, $s0
.L7F027B44:
  jal   sub_GAME_7F021B20
   move  $a0, $s0
  jal   increment_num_kills_display_text_in_MP
   nop   
  lw    $t5, 0x14($s0)
  sll   $t6, $t5, 0xb
  bgezl $t6, .L7F027B70
   lw    $a0, 0x160($s0)
  jal   inc_cur_civilian_casualties
   nop   
  lw    $a0, 0x160($s0)
.L7F027B70:
  beql  $a0, $zero, .L7F027BA4
   lw    $a0, 0x164($s0)
  lw    $t7, 4($a0)
  lw    $t8, 8($t7)
  andi  $t9, $t8, 0x2000
  bnezl $t9, .L7F027BA4
   lw    $a0, 0x164($s0)
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t0, 0x12($s0)
  ori   $t1, $t0, 1
  sh    $t1, 0x12($s0)
  lw    $a0, 0x164($s0)
.L7F027BA4:
  beqz  $a0, .L7F027BD4
   nop   
  lw    $t2, 4($a0)
  lw    $t3, 8($t2)
  andi  $t4, $t3, 0x2000
  bnez  $t4, .L7F027BD4
   nop   
  jal   sub_GAME_7F04BFD0
   li    $a1, 1
  lhu   $t5, 0x12($s0)
  ori   $t6, $t5, 1
  sh    $t6, 0x12($s0)
.L7F027BD4:
  b     .L7F027BE0
   li    $v0, 1
  move  $v0, $zero
.L7F027BE0:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel get_ptrpreset_in_table_matching_tile
  lui   $v0, %hi(ptr_setup_path_tbl)
  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
  move  $a2, $a0
  beql  $v0, $zero, .L7F027C58
   move  $v0, $zero
  lw    $t6, ($v0)
  move  $v1, $v0
  lui   $a1, %hi(ptr_0xxxpresets)
  bltz  $t6, .L7F027C54
   li    $a3, 44
  lw    $a0, ($v0)
  lw    $a1, %lo(ptr_0xxxpresets)($a1)
.L7F027C24:
  multu $a0, $a3
  mflo  $t7
  addu  $v0, $t7, $a1
  lw    $t8, 0x28($v0)
  bnel  $a2, $t8, .L7F027C48
   lw    $a0, 0x10($v1)
  jr    $ra
   move  $v0, $v1

  lw    $a0, 0x10($v1)
.L7F027C48:
  addiu $v1, $v1, 0x10
  bgez  $a0, .L7F027C24
   nop   
.L7F027C54:
  move  $v0, $zero
.L7F027C58:
  jr    $ra
   nop   
");

asm(R"
glabel check_if_any_path_preset_lies_on_tile
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_ptrpreset_in_table_matching_tile
   nop   
  lw    $ra, 0x14($sp)
  sltu  $t6, $zero, $v0
  move  $v0, $t6
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F027C84
  lw    $t6, ($a1)
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f4, ($v0)
  lwc1  $f6, ($a0)
  lwc1  $f8, 8($v0)
  lwc1  $f10, 8($a0)
  sub.s $f2, $f4, $f6
  sub.s $f12, $f8, $f10
  mul.s $f16, $f2, $f2
  nop   
  mul.s $f18, $f12, $f12
  jr    $ra
   add.s $f0, $f16, $f18
");

asm(R"
glabel sub_GAME_7F027CD4
  addiu $sp, $sp, -0x38
  sw    $s4, 0x30($sp)
  move  $s4, $a0
  move  $a0, $a1
  sw    $ra, 0x34($sp)
  sw    $s3, 0x2c($sp)
  lui   $a1, %hi(check_if_any_path_preset_lies_on_tile) # $a1, 0x7f02
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  sw    $s0, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  move  $s3, $zero
  jal   sub_GAME_7F0B2718
   addiu $a1, %lo(check_if_any_path_preset_lies_on_tile) # addiu $a1, $a1, 0x7c60
  beqz  $v0, .L7F027D88
   move  $a0, $v0
  jal   get_ptrpreset_in_table_matching_tile
   nop   
  beqz  $v0, .L7F027D88
   move  $s3, $v0
  move  $a0, $s4
  jal   sub_GAME_7F027C84
   move  $a1, $v0
  lw    $s1, 4($s3)
  lui   $s2, %hi(ptr_setup_path_tbl)
  mov.s $f20, $f0
  lw    $v0, ($s1)
  addiu $s2, %lo(ptr_setup_path_tbl) # addiu $s2, $s2, 0x5d00
  bltzl $v0, .L7F027D8C
   lw    $ra, 0x34($sp)
  lw    $t7, ($s2)
.L7F027D50:
  sll   $t6, $v0, 4
  move  $a0, $s4
  addu  $s0, $t6, $t7
  jal   sub_GAME_7F027C84
   move  $a1, $s0
  c.lt.s $f0, $f20
  nop   
  bc1fl .L7F027D7C
   lw    $v0, 4($s1)
  move  $s3, $s0
  lw    $v0, 4($s1)
.L7F027D7C:
  addiu $s1, $s1, 4
  bgezl $v0, .L7F027D50
   lw    $t7, ($s2)
.L7F027D88:
  lw    $ra, 0x34($sp)
.L7F027D8C:
  move  $v0, $s3
  lw    $s3, 0x2c($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F027DB0
  addiu $sp, $sp, -0x98
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a2, 0xa0($sp)
  lw    $v0, 0x18($a0)
  move  $s0, $a1
  lwc1  $f4, ($s0)
  lw    $a1, 8($v0)
  lw    $a0, 0x14($v0)
  lw    $a2, 0x10($v0)
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 8($s0)
  addiu $t6, $sp, 0x48
  li    $t7, 20
  sw    $t7, 0x1c($sp)
  sw    $t6, 0x18($sp)
  addiu $a3, $sp, 0xa0
  jal   sub_GAME_7F0B0D0C
   swc1  $f6, 0x14($sp)
  blez  $v0, .L7F027E4C
   move  $s2, $v0
  slti  $at, $v0, 0x14
  beqz  $at, .L7F027E4C
   nop   
  blez  $v0, .L7F027E54
   move  $s0, $zero
  addiu $s1, $sp, 0x48
.L7F027E24:
  jal   sub_GAME_7F0B5E50
   lw    $a0, ($s1)
  beqz  $v0, .L7F027E3C
   addiu $s0, $s0, 1
  b     .L7F027E58
   move  $v0, $zero
.L7F027E3C:
  bne   $s0, $s2, .L7F027E24
   addiu $s1, $s1, 4
  b     .L7F027E58
   li    $v0, 1
.L7F027E4C:
  b     .L7F027E58
   move  $v0, $zero
.L7F027E54:
  li    $v0, 1
.L7F027E58:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel sub_GAME_7F027E70
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F027DB0
   lw    $a2, 0x28($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F027E90
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $v0, 0x18($a0)
  lwc1  $f4, ($a2)
  lwc1  $f8, 8($a2)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  sub.s $f12, $f4, $f6
  sub.s $f14, $f8, $f10
  swc1  $f12, 0x20($sp)
  jal   convert_angle_using_inverse
   swc1  $f14, 0x1c($sp)
  lwc1  $f2, 0x20($sp)
  lwc1  $f14, 0x1c($sp)
  lw    $v0, 0x2c($sp)
  mul.s $f18, $f2, $f2
  mtc1  $zero, $f16
  swc1  $f0, 0x18($sp)
  mul.s $f4, $f14, $f14
  li    $t7, 6
  sb    $t7, ($v0)
  swc1  $f16, 0x38($v0)
  jal   sqrtf
   add.s $f12, $f18, $f4
  lw    $t8, 0x2c($sp)
  swc1  $f0, 0x3c($t8)
  lw    $t9, 0x28($sp)
  lw    $a1, 0x18($sp)
  jal   setsubroty
   lw    $a0, 0x1c($t9)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F027F20
  lbu   $t6, 0x58($a0)
  sll   $t7, $t6, 2
  addu  $t8, $a0, $t7
  lw    $v0, 0x40($t8)
  beql  $v0, $zero, .L7F027F84
   lwc1  $f10, 0x2c($a0)
  lw    $t9, ($v0)
  lui   $t1, %hi(ptr_0xxxpresets) 
  lw    $t1, %lo(ptr_0xxxpresets)($t1)
  sll   $t0, $t9, 2
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  subu  $t0, $t0, $t9
  sll   $t0, $t0, 2
  addu  $v1, $t0, $t1
  lwc1  $f4, ($v1)
  swc1  $f4, ($a1)
  lwc1  $f6, 4($v1)
  swc1  $f6, 4($a1)
  lwc1  $f8, 8($v1)
  swc1  $f8, 8($a1)
  lw    $t2, 0x28($v1)
  jr    $ra
   sw    $t2, ($a2)

  lwc1  $f10, 0x2c($a0)
.L7F027F84:
  swc1  $f10, ($a1)
  lwc1  $f16, 0x30($a0)
  swc1  $f16, 4($a1)
  lwc1  $f18, 0x34($a0)
  swc1  $f18, 8($a1)
  lw    $t3, 0x38($a0)
  sw    $t3, ($a2)
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DF4
.word 0x411fffff /*9.999999*/
.text
glabel sub_GAME_7F027FA8
  addiu $sp, $sp, -0x30
  sw    $s1, 0x20($sp)
  move  $s1, $a0
  sw    $ra, 0x24($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  lui   $at, %hi(D_80030984)
  lwc1  $f20, %lo(D_80030984)($at)
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($a0)
  lui   $s0, %hi(ptr_animation_table)
  addiu $s0, %lo(ptr_animation_table) # addiu $s0, $s0, -0x6ac8
  lw    $t6, ($s0)
  lui   $t7, %hi(0x00004070) # $t7, 0
  addiu $t7, %lo(0x00004070) # addiu $t7, $t7, 0x4070
  addu  $t8, $t6, $t7
  bne   $v0, $t8, .L7F027FF8
   lui   $at, %hi(D_8003098C)
  b     .L7F028110
   lwc1  $f20, %lo(D_8003098C)($at)
.L7F027FF8:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t9, ($s0)
  lui   $t0, %hi(0x000040D4) # $t0, 0
  addiu $t0, %lo(0x000040D4) # addiu $t0, $t0, 0x40d4
  addu  $t1, $t9, $t0
  bne   $v0, $t1, .L7F028020
   lui   $at, %hi(D_80030988)
  b     .L7F028110
   lwc1  $f20, %lo(D_80030988)($at)
.L7F028020:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t2, ($s0)
  lui   $v1, %hi(0x000077D4) # $v1, 0
  addiu $v1, %lo(0x000077D4) # addiu $v1, $v1, 0x77d4
  addu  $t3, $v1, $t2
  bne   $v0, $t3, .L7F028048
   lui   $at, %hi(D_80030998)
  b     .L7F028110
   lwc1  $f20, %lo(D_80030998)($at)
.L7F028048:
  lw    $a0, 0x1c($s1)
  jal   sub_GAME_7F06F5AC
   sw    $v1, 0x28($sp)
  lw    $t4, ($s0)
  lui   $t5, %hi(0x0000777C) # $t5, 0
  addiu $t5, %lo(0x0000777C) # addiu $t5, $t5, 0x777c
  addu  $t6, $t4, $t5
  bne   $v0, $t6, .L7F028074
   lui   $at, %hi(D_80030994)
  b     .L7F028110
   lwc1  $f20, %lo(D_80030994)($at)
.L7F028074:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t7, ($s0)
  lui   $t8, %hi(0x00008204) # $t8, 1
  addiu $t8, %lo(0x00008204) # addiu $t8, $t8, -0x7dfc
  addu  $t9, $t7, $t8
  bne   $v0, $t9, .L7F02809C
   lui   $at, %hi(D_80030990)
  b     .L7F028110
   lwc1  $f20, %lo(D_80030990)($at)
.L7F02809C:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t0, 0x28($sp)
  lw    $t1, ($s0)
  lui   $at, %hi(D_800309A4)
  addu  $t2, $t0, $t1
  bne   $v0, $t2, .L7F0280C4
   nop   
  b     .L7F028110
   lwc1  $f20, %lo(D_800309A4)($at)
.L7F0280C4:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t3, ($s0)
  lui   $t4, %hi(0x00008520) # $t4, 1
  addiu $t4, %lo(0x00008520) # addiu $t4, $t4, -0x7ae0
  addu  $t5, $t3, $t4
  bne   $v0, $t5, .L7F0280EC
   lui   $at, %hi(D_800309A0)
  b     .L7F028110
   lwc1  $f20, %lo(D_800309A0)($at)
.L7F0280EC:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s1)
  lw    $t6, ($s0)
  lui   $t7, %hi(0x000084C4) # $t7, 1
  addiu $t7, %lo(0x000084C4) # addiu $t7, $t7, -0x7b3c
  addu  $t8, $t6, $t7
  bne   $v0, $t8, .L7F028110
   lui   $at, %hi(D_8003099C)
  lwc1  $f20, %lo(D_8003099C)($at)
.L7F028110:
  lw    $t9, 0x1c($s1)
  lui   $at, %hi(D_80051DF4)
  lwc1  $f8, %lo(D_80051DF4)($at)
  lwc1  $f4, 0x14($t9)
  lw    $ra, 0x24($sp)
  lw    $s1, 0x20($sp)
  mul.s $f6, $f4, $f20
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  addiu $sp, $sp, 0x30
  mul.s $f0, $f6, $f8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028144
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a0, 0x38($sp)
  jal   sub_GAME_7F06F618
   lw    $a0, 0x1c($a0)
  swc1  $f0, 0x18($sp)
  lw    $a0, 0x38($sp)
  addiu $a1, $sp, 0x20
  jal   sub_GAME_7F027F20
   addiu $a2, $sp, 0x1c
  lw    $a0, 0x38($sp)
  lwc1  $f4, 0x20($sp)
  mtc1  $zero, $f0
  lw    $v0, 0x18($a0)
  lwc1  $f8, 0x28($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  sub.s $f2, $f4, $f6
  sub.s $f12, $f8, $f10
  c.lt.s $f2, $f0
  nop   
  bc1fl .L7F0281A8
   c.lt.s $f12, $f0
  neg.s $f2, $f2
  c.lt.s $f12, $f0
.L7F0281A8:
  nop   
  bc1fl .L7F0281BC
   swc1  $f2, 0x34($sp)
  neg.s $f12, $f12
  swc1  $f2, 0x34($sp)
.L7F0281BC:
  jal   sub_GAME_7F027FA8
   swc1  $f12, 0x30($sp)
  lwc1  $f18, 0x18($sp)
  lwc1  $f2, 0x34($sp)
  lwc1  $f12, 0x30($sp)
  mul.s $f4, $f0, $f18
  lw    $ra, 0x14($sp)
  add.s $f16, $f2, $f12
  addiu $sp, $sp, 0x38
  div.s $f6, $f16, $f4
  trunc.w.s $f8, $f6
  mfc1  $v0, $f8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0281F4
  jr    $ra
   sh    $zero, 0x5a($a0)
");

asm(R"
glabel sub_GAME_7F0281FC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 0x5c($a0)
  li    $at, 6
  beql  $t6, $at, .L7F028280
   lw    $ra, 0x14($sp)
  lhu   $v0, 0x5a($a0)
  lui   $v1, %hi(clock_timer+2)
  bnez  $v0, .L7F028250
   nop   
  jal   sub_GAME_7F028144
   sw    $a0, 0x18($sp)
  sll   $v1, $v0, 1
  addiu $a1, $v1, 0x12c
  lui   $at, 1
  slt   $at, $a1, $at
  bnez  $at, .L7F028248
   lw    $a0, 0x18($sp)
  li    $a1, 65535
.L7F028248:
  b     .L7F02827C
   sh    $a1, 0x5a($a0)
.L7F028250:
  lhu   $v1, %lo(clock_timer+2)($v1)
  addiu $a1, $a0, 0x2c
  slt   $at, $v1, $v0
  bnez  $at, .L7F028278
   subu  $t7, $v0, $v1
  lw    $a2, 0x38($a0)
  jal   plot_course_for_actor
   lbu   $a3, 0x59($a0)
  b     .L7F028280
   lw    $ra, 0x14($sp)
.L7F028278:
  sh    $t7, 0x5a($a0)
.L7F02827C:
  lw    $ra, 0x14($sp)
.L7F028280:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02828C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  addiu $a1, $sp, 0x1c
  addiu $a2, $sp, 0x18
  jal   sub_GAME_7F027F20
   sw    $a0, 0x28($sp)
  lw    $a0, 0x28($sp)
  sb    $zero, 0x5c($a0)
  sb    $zero, 0x5d($a0)
  sb    $zero, 0x5e($a0)
  lwc1  $f4, 0x1c($sp)
  swc1  $f4, 0x60($a0)
  lwc1  $f6, 0x20($sp)
  swc1  $f6, 0x64($a0)
  lwc1  $f8, 0x24($sp)
  jal   sub_GAME_7F0281F4
   swc1  $f8, 0x68($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0282E0
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lbu   $v0, 0x58($a0)
  move  $s0, $a0
  li    $t9, 1
  slti  $at, $v0, 3
  beqz  $at, .L7F028310
   sll   $t7, $v0, 2
  addiu $t6, $v0, 1
  b     .L7F02832C
   sb    $t6, 0x58($a0)
.L7F028310:
  addu  $t8, $s0, $t7
  lw    $a0, 0x40($t8)
  sb    $t9, 0x58($s0)
  lw    $a1, 0x3c($s0)
  addiu $a2, $s0, 0x40
  jal   sub_GAME_7F08F4F0
   li    $a3, 6
.L7F02832C:
  jal   sub_GAME_7F02828C
   move  $a0, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028348
  lw    $v1, 0x30($a0)
  bgez  $a2, .L7F028360
   lw    $a3, ($a1)
  sltiu $t6, $a3, 1
  move  $a3, $t6
  negu  $a2, $a2
.L7F028360:
  blezl $a2, .L7F0283F4
   sw    $a3, ($a1)
.L7F028368:
  beqz  $a3, .L7F0283B4
   addiu $a2, $a2, -1
  lw    $v0, 0x2c($a0)
  addiu $v1, $v1, 1
  sll   $t8, $v1, 2
  lw    $t7, ($v0)
  addu  $t9, $t7, $t8
  lw    $t0, ($t9)
  bgez  $t0, .L7F0283E8
   nop   
  lbu   $t1, 5($v0)
  addiu $v1, $v1, -2
  andi  $t2, $t1, 1
  beqz  $t2, .L7F0283AC
   nop   
  b     .L7F0283E8
   move  $v1, $zero
.L7F0283AC:
  b     .L7F0283E8
   move  $a3, $zero
.L7F0283B4:
  addiu $v1, $v1, -1
  bgez  $v1, .L7F0283E8
   nop   
  lw    $v0, 0x2c($a0)
  li    $v1, 1
  lbu   $t3, 5($v0)
  andi  $t4, $t3, 1
  beql  $t4, $zero, .L7F0283E8
   li    $a3, 1
  lhu   $v1, 6($v0)
  b     .L7F0283E8
   addiu $v1, $v1, -1
  li    $a3, 1
.L7F0283E8:
  bgtz  $a2, .L7F028368
   nop   
  sw    $a3, ($a1)
.L7F0283F4:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0283FC
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  lw    $t6, 0x34($a0)
  move  $a2, $a1
  addiu $a1, $sp, 0x20
  sw    $a0, 0x28($sp)
  jal   sub_GAME_7F028348
   sw    $t6, 0x20($sp)
  lw    $a3, 0x28($sp)
  sll   $t9, $v0, 2
  lui   $a1, %hi(ptr_setup_path_tbl)
  lw    $t7, 0x2c($a3)
  addiu $a1, %lo(ptr_setup_path_tbl) # addiu $a1, $a1, 0x5d00
  lw    $t2, ($a1)
  lw    $t8, ($t7)
  lw    $ra, 0x14($sp)
  lw    $t5, 0x18($a1)
  addu  $v1, $t8, $t9
  lw    $t0, ($v1)
  sll   $t1, $t0, 4
  addu  $a0, $t1, $t2
  lw    $t3, ($a0)
  addiu $sp, $sp, 0x28
  sll   $t4, $t3, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  subu  $t4, $t4, $t3
  sll   $t4, $t4, 2
  jr    $ra
   addu  $v0, $t4, $t5
");

asm(R"
glabel sub_GAME_7F028474
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0283FC
   move  $a1, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028494
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F028474
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  sb    $zero, 0x38($a0)
  sb    $zero, 0x39($a0)
  sb    $zero, 0x3a($a0)
  lwc1  $f4, ($v0)
  swc1  $f4, 0x3c($a0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 0x40($a0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 0x44($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0284DC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  addiu $a1, $a0, 0x34
  jal   sub_GAME_7F028348
   li    $a2, 1
  lw    $a0, 0x18($sp)
  jal   sub_GAME_7F028494
   sw    $v0, 0x30($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028510
  addiu $sp, $sp, -0x70
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lbu   $t6, 3($a1)
  move  $s1, $a0
  li    $t7, -1
  sw    $t7, 0x54($sp)
  addiu $a0, $sp, 0x50
  jal   sub_GAME_7F03E3FC
   sw    $t6, 0x50($sp)
  lui   $s0, %hi(ptr_list_object_lookup_indices)
  lw    $s0, %lo(ptr_list_object_lookup_indices)($s0)
  lui   $s3, %hi(pos_data_entry)
  addiu $s3, %lo(pos_data_entry) # addiu $s3, $s3, -0x63c8
  lh    $v0, ($s0)
  addiu $s6, $sp, 0x40
  addiu $s5, $sp, 0x44
  bltz  $v0, .L7F0285D4
   li    $s4, 1
  li    $s2, 52
.L7F028578:
  multu $v0, $s2
  move  $a1, $s5
  mflo  $t8
  addu  $a0, $t8, $s3
  lbu   $t9, ($a0)
  bnel  $s4, $t9, .L7F0285C8
   lh    $v0, 2($s0)
  jal   sub_GAME_7F03CCB0
   move  $a2, $s6
  lw    $a2, 0x40($sp)
  move  $a0, $s1
  blezl $a2, .L7F0285C8
   lh    $v0, 2($s0)
  jal   sub_GAME_7F03CCD8
   lw    $a1, 0x44($sp)
  beql  $v0, $zero, .L7F0285C8
   lh    $v0, 2($s0)
  b     .L7F0285D8
   move  $v0, $zero
  lh    $v0, 2($s0)
.L7F0285C8:
  addiu $s0, $s0, 2
  bgez  $v0, .L7F028578
   nop   
.L7F0285D4:
  li    $v0, 1
.L7F0285D8:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

asm(R"
glabel sub_GAME_7F028600
  addiu $sp, $sp, -0x68
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  sb    $zero, 9($a0)
  lui   $t6, %hi(global_timer) 
  lw    $t6, %lo(global_timer)($t6)
  move  $s0, $a0
  sw    $t6, 0xcc($a0)
  jal   sub_GAME_7F06F618
   lw    $a0, 0x1c($a0)
  lwc1  $f4, 0x70($sp)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f8, %lo(global_timer_delta)($at)
  mul.s $f6, $f4, $f0
  lw    $v0, 0x6c($sp)
  move  $a0, $s0
  lwc1  $f16, 0x38($v0)
  mul.s $f10, $f6, $f8
  lwc1  $f6, 0x3c($v0)
  add.s $f18, $f16, $f10
  swc1  $f18, 0x38($v0)
  lwc1  $f4, 0x38($v0)
  c.le.s $f6, $f4
  nop   
  bc1fl .L7F028884
   lw    $ra, 0x2c($sp)
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  lw    $v0, 0x74($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  mtc1  $zero, $f8
  lw    $a3, 0x24($s0)
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  li    $t7, 31
  sw    $t7, 0x10($sp)
  addiu $a0, $sp, 0x78
  swc1  $f16, 0x18($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f8, 0x14($sp)
  bgez  $v0, .L7F028828
   lw    $a2, 0x74($sp)
  move  $a0, $a2
  jal   sub_GAME_7F028510
   lw    $a1, 0x78($sp)
  beqz  $v0, .L7F028828
   lw    $a2, 0x74($sp)
  lw    $v1, 0x18($s0)
  lw    $t8, 0x78($sp)
  move  $a1, $a2
  sw    $t8, 0x14($v1)
  lwc1  $f10, ($a2)
  swc1  $f10, 8($v1)
  lwc1  $f18, 4($a2)
  swc1  $f18, 0xc($v1)
  lwc1  $f4, 8($a2)
  swc1  $f4, 0x10($v1)
  lw    $t9, 0x14($s0)
  lw    $a0, 0x1c($s0)
  ori   $t0, $t9, 1
  sw    $t0, 0x14($s0)
  jal   setsuboffset
   sw    $v1, 0x64($sp)
  lw    $v1, 0x64($sp)
  lw    $a0, 0x1c($s0)
  addiu $a3, $s0, 0xac
  addiu $a1, $v1, 8
  jal   sub_GAME_7F01FC10
   move  $a2, $a1
  jal   sub_GAME_7F020D94
   move  $a0, $s0
  lb    $v0, 7($s0)
  li    $at, 14
  lw    $v1, 0x64($sp)
  bnel  $v0, $at, .L7F02876C
   li    $at, 15
  jal   sub_GAME_7F0284DC
   move  $a0, $s0
  jal   sub_GAME_7F028474
   move  $a0, $s0
  move  $a0, $s0
  lw    $a1, 0x6c($sp)
  jal   sub_GAME_7F027E90
   move  $a2, $v0
  b     .L7F028878
   move  $a0, $s0
  li    $at, 15
.L7F02876C:
  bnel  $v0, $at, .L7F028878
   move  $a0, $s0
  lbu   $v0, 0x58($s0)
  sll   $t1, $v0, 2
  addu  $t2, $s0, $t1
  lw    $t3, 0x40($t2)
  bnez  $t3, .L7F0287F8
   nop   
  blez  $v0, .L7F0287E8
   sll   $t4, $v0, 2
  addu  $t5, $s0, $t4
  lw    $a0, 0x3c($t5)
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  lw    $t6, ($a0)
  lwc1  $f6, 8($v1)
  lwc1  $f16, 0x10($v1)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f8, ($v0)
  lwc1  $f10, 8($v0)
  sub.s $f12, $f6, $f8
  jal   convert_angle_using_inverse
   sub.s $f14, $f16, $f10
  mfc1  $a1, $f0
  jal   setsubroty
   lw    $a0, 0x1c($s0)
.L7F0287E8:
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F028878
   move  $a0, $s0
.L7F0287F8:
  jal   sub_GAME_7F0282E0
   move  $a0, $s0
  move  $a0, $s0
  addiu $a1, $sp, 0x40
  jal   sub_GAME_7F027F20
   addiu $a2, $sp, 0x3c
  move  $a0, $s0
  lw    $a1, 0x6c($sp)
  jal   sub_GAME_7F027E90
   addiu $a2, $sp, 0x40
  b     .L7F028878
   move  $a0, $s0
.L7F028828:
  lw    $v0, 0x6c($sp)
  li    $at, 14
  lui   $t0, %hi(global_timer) 
  lwc1  $f18, 0x3c($v0)
  lui   $t1, %hi(global_timer) 
  swc1  $f18, 0x38($v0)
  lb    $t9, 7($s0)
  bne   $t9, $at, .L7F028864
   nop   
  lw    $t0, %lo(global_timer)($t0)
  move  $a0, $s0
  jal   sub_GAME_7F028494
   sw    $t0, 0x78($s0)
  b     .L7F028878
   move  $a0, $s0
.L7F028864:
  lw    $t1, %lo(global_timer)($t1)
  move  $a0, $s0
  jal   sub_GAME_7F02828C
   sw    $t1, 0x9c($s0)
  move  $a0, $s0
.L7F028878:
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $ra, 0x2c($sp)
.L7F028884:
  lw    $s0, 0x28($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028894
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  lb    $v0, 7($a0)
  li    $at, 14
  move  $a3, $a1
  bnel  $v0, $at, .L7F028968
   li    $at, 15
  lb    $t6, 0x38($a0)
  li    $at, 6
  bnel  $t6, $at, .L7F028968
   li    $at, 15
  sw    $a0, 0x40($sp)
  jal   sub_GAME_7F028474
   sw    $a1, 0x44($sp)
  lw    $a0, 0x40($sp)
  lw    $a3, 0x44($sp)
  lwc1  $f16, 0x70($a0)
  lwc1  $f18, 0x74($a0)
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F02890C
   div.s $f0, $f16, $f18
  lwc1  $f4, ($v0)
  swc1  $f4, ($a3)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a3)
  lwc1  $f8, 8($v0)
  b     .L7F028A4C
   swc1  $f8, 8($a3)
  div.s $f0, $f16, $f18
.L7F02890C:
  lw    $t7, 0x18($a0)
  lwc1  $f10, ($v0)
  lwc1  $f2, 8($t7)
  sub.s $f4, $f10, $f2
  mul.s $f6, $f4, $f0
  add.s $f8, $f6, $f2
  swc1  $f8, ($a3)
  lw    $t8, 0x18($a0)
  lwc1  $f10, 4($v0)
  lwc1  $f12, 0xc($t8)
  sub.s $f4, $f10, $f12
  mul.s $f6, $f4, $f0
  add.s $f8, $f6, $f12
  swc1  $f8, 4($a3)
  lw    $t9, 0x18($a0)
  lwc1  $f10, 8($v0)
  lwc1  $f14, 0x10($t9)
  sub.s $f4, $f10, $f14
  mul.s $f6, $f4, $f0
  add.s $f8, $f6, $f14
  b     .L7F028A4C
   swc1  $f8, 8($a3)
  li    $at, 15
.L7F028968:
  bnel  $v0, $at, .L7F028A2C
   lw    $t4, 0x18($a0)
  lb    $t0, 0x5c($a0)
  li    $at, 6
  addiu $a1, $sp, 0x2c
  bne   $t0, $at, .L7F028A28
   addiu $a2, $sp, 0x28
  sw    $a0, 0x40($sp)
  jal   sub_GAME_7F027F20
   sw    $a3, 0x44($sp)
  lw    $a0, 0x40($sp)
  lw    $a3, 0x44($sp)
  lwc1  $f10, 0x2c($sp)
  lwc1  $f16, 0x94($a0)
  lwc1  $f18, 0x98($a0)
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F0289D0
   div.s $f0, $f16, $f18
  swc1  $f10, ($a3)
  lwc1  $f4, 0x30($sp)
  swc1  $f4, 4($a3)
  lwc1  $f6, 0x34($sp)
  b     .L7F028A4C
   swc1  $f6, 8($a3)
  div.s $f0, $f16, $f18
.L7F0289D0:
  lw    $t1, 0x18($a0)
  lwc1  $f8, 0x2c($sp)
  lwc1  $f2, 8($t1)
  sub.s $f10, $f8, $f2
  mul.s $f4, $f10, $f0
  add.s $f6, $f4, $f2
  swc1  $f6, ($a3)
  lw    $t2, 0x18($a0)
  lwc1  $f8, 0x30($sp)
  lwc1  $f12, 0xc($t2)
  sub.s $f10, $f8, $f12
  mul.s $f4, $f10, $f0
  add.s $f6, $f4, $f12
  swc1  $f6, 4($a3)
  lw    $t3, 0x18($a0)
  lwc1  $f8, 0x34($sp)
  lwc1  $f14, 0x10($t3)
  sub.s $f10, $f8, $f14
  mul.s $f4, $f10, $f0
  add.s $f6, $f4, $f14
  b     .L7F028A4C
   swc1  $f6, 8($a3)
.L7F028A28:
  lw    $t4, 0x18($a0)
.L7F028A2C:
  lwc1  $f8, 8($t4)
  swc1  $f8, ($a3)
  lw    $t5, 0x18($a0)
  lwc1  $f10, 0xc($t5)
  swc1  $f10, 4($a3)
  lw    $t6, 0x18($a0)
  lwc1  $f4, 0x10($t6)
  swc1  $f4, 8($a3)
.L7F028A4C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel get_sound_at_range
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x34($sp)
  sw    $a0, 0x30($sp)
  sw    $a2, 0x38($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  lw    $a0, 0x30($sp)
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  move  $a1, $v0
  beqz  $a3, .L7F028AA0
   nop   
  bnez  $v0, .L7F028AB0
   nop   
.L7F028AA0:
  bnez  $a3, .L7F028AC8
   move  $a0, $a3
  bnezl $v0, .L7F028ACC
   sw    $a1, 0x28($sp)
.L7F028AB0:
  jal   get_random_value
   sw    $zero, 0x20($sp)
  lw    $v1, 0x20($sp)
  lw    $t0, 0x30($sp)
  b     .L7F028B10
   andi  $a2, $v0, 1
.L7F028AC8:
  sw    $a1, 0x28($sp)
.L7F028ACC:
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x2c($sp)
  lw    $a1, 0x28($sp)
  lw    $a3, 0x2c($sp)
  bnez  $v0, .L7F028AFC
   lw    $t0, 0x30($sp)
  move  $a0, $a1
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  beqz  $v0, .L7F028B08
   lw    $t0, 0x30($sp)
.L7F028AFC:
  move  $v1, $zero
  b     .L7F028B10
   sltu  $a2, $zero, $a3
.L7F028B08:
  li    $v1, 1
  sltu  $a2, $zero, $a3
.L7F028B10:
  beqz  $v1, .L7F028BEC
   lw    $t3, 0x38($sp)
  lw    $v0, 0x34($sp)
  li    $at, 2
  lui   $t6, %hi(ptr_animation_table) 
  bne   $v0, $at, .L7F028B64
   lui   $t7, %hi(0x00004070) # $t7, 0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t6, %lo(ptr_animation_table)($t6)
  lw    $a0, 0x1c($t0)
  addiu $t7, %lo(0x00004070) # addiu $t7, $t7, 0x4070
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  addu  $a1, $t6, $t7
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028B64:
  li    $at, 1
  bne   $v0, $at, .L7F028BB0
   lui   $t1, %hi(ptr_animation_table) 
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  li    $at, 0x41800000 # 16.000000
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  mtc1  $at, $f10
  lui   $t9, %hi(0x000040D4) # $t9, 0
  addiu $t9, %lo(0x000040D4) # addiu $t9, $t9, 0x40d4
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $t8, $t9
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028BB0:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lw    $t1, %lo(ptr_animation_table)($t1)
  lui   $t2, %hi(0x00004018) # $t2, 0
  addiu $t2, %lo(0x00004018) # addiu $t2, $t2, 0x4018
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f16, 0x10($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t1, $t2
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028BEC:
  beqz  $t3, .L7F028CC8
   lw    $v0, 0x34($sp)
  lw    $v0, 0x34($sp)
  li    $at, 2
  lui   $t4, %hi(ptr_animation_table) 
  bne   $v0, $at, .L7F028C40
   lui   $t5, %hi(0x000077D4) # $t5, 0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t4, %lo(ptr_animation_table)($t4)
  lw    $a0, 0x1c($t0)
  addiu $t5, %lo(0x000077D4) # addiu $t5, $t5, 0x77d4
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  addu  $a1, $t4, $t5
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028C40:
  li    $at, 1
  bne   $v0, $at, .L7F028C8C
   lui   $t8, %hi(ptr_animation_table) 
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  li    $at, 0x41800000 # 16.000000
  lui   $t6, %hi(ptr_animation_table) 
  lw    $t6, %lo(ptr_animation_table)($t6)
  mtc1  $at, $f10
  lui   $t7, %hi(0x0000777C) # $t7, 0
  addiu $t7, %lo(0x0000777C) # addiu $t7, $t7, 0x777c
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $t6, $t7
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028C8C:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lw    $t8, %lo(ptr_animation_table)($t8)
  lui   $t9, %hi(0x00008204) # $t9, 1
  addiu $t9, %lo(0x00008204) # addiu $t9, $t9, -0x7dfc
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f16, 0x10($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t8, $t9
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028CC8:
  li    $at, 2
  bne   $v0, $at, .L7F028D10
   lui   $t1, %hi(ptr_animation_table) 
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lw    $t1, %lo(ptr_animation_table)($t1)
  lui   $t2, %hi(0x000077D4) # $t2, 0
  addiu $t2, %lo(0x000077D4) # addiu $t2, $t2, 0x77d4
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t1, $t2
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028D10:
  li    $at, 1
  bne   $v0, $at, .L7F028D5C
   lui   $t5, %hi(ptr_animation_table) 
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  li    $at, 0x41800000 # 16.000000
  lui   $t3, %hi(ptr_animation_table) 
  lw    $t3, %lo(ptr_animation_table)($t3)
  mtc1  $at, $f10
  lui   $t4, %hi(0x00008520) # $t4, 1
  addiu $t4, %lo(0x00008520) # addiu $t4, $t4, -0x7ae0
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $t3, $t4
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  b     .L7F028D94
   lw    $ra, 0x1c($sp)
.L7F028D5C:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lw    $t5, %lo(ptr_animation_table)($t5)
  lui   $t6, %hi(0x000084C4) # $t6, 1
  addiu $t6, %lo(0x000084C4) # addiu $t6, $t6, -0x7b3c
  lw    $a0, 0x1c($t0)
  li    $a3, 0
  swc1  $f16, 0x10($sp)
  swc1  $f18, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   addu  $a1, $t5, $t6
  lw    $ra, 0x1c($sp)
.L7F028D94:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel play_hit_soundeffect_and_proper_volume
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 0xf($a0)
  lui   $a2, %hi(c_item_entries+16)
  lbu   $a1, 0x59($a0)
  sll   $t7, $t6, 2
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $a2, $a2, $t7
  jal   get_sound_at_range
   lbu   $a2, %lo(c_item_entries+16)($a2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel plot_course_for_actor
  addiu $sp, $sp, -0x68
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x6c($sp)
  sw    $a2, 0x70($sp)
  sw    $a3, 0x74($sp)
  lb    $v0, 7($a0)
  move  $s0, $a0
  lw    $v1, 0x18($a0)
  xori  $t6, $v0, 0xf
  sltiu $v0, $t6, 1
  beqz  $v0, .L7F028E1C
   lbu   $t7, 0x77($sp)
  lbu   $t8, 0x59($a0)
  xor   $v0, $t7, $t8
  sltiu $v0, $v0, 1
.L7F028E1C:
  lw    $a1, 0x14($v1)
  sw    $v1, 0x64($sp)
  sw    $v0, 0x28($sp)
  jal   sub_GAME_7F027CD4
   addiu $a0, $v1, 8
  sw    $v0, 0x60($sp)
  lw    $a0, 0x6c($sp)
  jal   sub_GAME_7F027CD4
   lw    $a1, 0x70($sp)
  lw    $a0, 0x60($sp)
  move  $a1, $v0
  beql  $a0, $zero, .L7F028F98
   move  $v0, $zero
  beqz  $v0, .L7F028F94
   addiu $a2, $sp, 0x44
  li    $a3, 6
  jal   sub_GAME_7F08F4F0
   sw    $v0, 0x5c($sp)
  slti  $at, $v0, 2
  bnezl $at, .L7F028F98
   move  $v0, $zero
  jal   sub_GAME_7F02D184
   move  $a0, $s0
  lw    $v0, 0x6c($sp)
  li    $t9, 15
  sb    $t9, 7($s0)
  lwc1  $f4, ($v0)
  mtc1  $zero, $f10
  swc1  $f4, 0x2c($s0)
  lwc1  $f6, 4($v0)
  swc1  $f6, 0x30($s0)
  lwc1  $f8, 8($v0)
  swc1  $f8, 0x34($s0)
  lw    $t0, 0x70($sp)
  sw    $t0, 0x38($s0)
  lw    $t1, 0x5c($sp)
  sb    $zero, 0x58($s0)
  sw    $t1, 0x3c($s0)
  lw    $t2, 0x74($sp)
  swc1  $f10, 0xa0($s0)
  jal   get_random_value
   sb    $t2, 0x59($s0)
  li    $at, 100
  divu  $zero, $v0, $at
  mfhi  $t3
  li    $t4, -1
  sw    $t3, 0x84($s0)
  sb    $zero, 0x5f($s0)
  sw    $t4, 0x9c($s0)
  lw    $t5, 0x44($sp)
  li    $a1, 2
  addiu $a2, $sp, 0x44
  sw    $t5, 0x40($s0)
  lw    $t6, 0x48($sp)
  sll   $a0, $a1, 2
  addu  $v1, $a2, $a0
  sw    $t6, 0x44($s0)
  lw    $t7, ($v1)
  addu  $v0, $s0, $a0
  move  $a0, $s0
  sw    $t7, 0x40($v0)
  lw    $t8, 4($v1)
  sw    $t8, 0x44($v0)
  lw    $t9, 8($v1)
  sw    $t9, 0x48($v0)
  lw    $t0, 0xc($v1)
  jal   sub_GAME_7F02828C
   sw    $t0, 0x4c($v0)
  sb    $zero, 8($s0)
  lw    $t1, 0x28($sp)
  bnezl $t1, .L7F028F48
   move  $a0, $s0
  jal   play_hit_soundeffect_and_proper_volume
   move  $a0, $s0
  move  $a0, $s0
.L7F028F48:
  addiu $a1, $sp, 0x34
  jal   sub_GAME_7F027F20
   addiu $a2, $sp, 0x30
  lw    $t2, 0x64($sp)
  move  $a0, $s0
  addiu $a1, $sp, 0x34
  lbu   $t3, 1($t2)
  andi  $t4, $t3, 2
  bnez  $t4, .L7F028F8C
   nop   
  jal   sub_GAME_7F027DB0
   lw    $a2, 0x30($sp)
  beqz  $v0, .L7F028F8C
   move  $a0, $s0
  addiu $a1, $s0, 0x5c
  jal   sub_GAME_7F027E90
   addiu $a2, $sp, 0x34
.L7F028F8C:
  b     .L7F028F98
   li    $v0, 1
.L7F028F94:
  move  $v0, $zero
.L7F028F98:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x68
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F028FAC
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x30($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  lw    $a0, 0x30($sp)
  move  $a1, $zero
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $v0, 0x2c($sp)
  lw    $a3, 0x2c($sp)
  move  $a1, $v0
  beqz  $a3, .L7F028FE8
   nop   
  bnez  $v0, .L7F028FF8
   nop   
.L7F028FE8:
  bnez  $a3, .L7F02900C
   move  $a0, $a3
  bnezl $v0, .L7F029010
   sw    $a1, 0x28($sp)
.L7F028FF8:
  jal   get_random_value
   sw    $zero, 0x20($sp)
  lw    $v1, 0x20($sp)
  b     .L7F02904C
   andi  $a2, $v0, 1
.L7F02900C:
  sw    $a1, 0x28($sp)
.L7F029010:
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x2c($sp)
  lw    $a1, 0x28($sp)
  bnez  $v0, .L7F029038
   lw    $a3, 0x2c($sp)
  move  $a0, $a1
  jal   check_if_item_held_like_pistol
   sw    $a3, 0x2c($sp)
  beqz  $v0, .L7F029044
   lw    $a3, 0x2c($sp)
.L7F029038:
  move  $v1, $zero
  b     .L7F02904C
   sltu  $a2, $zero, $a3
.L7F029044:
  li    $v1, 1
  sltu  $a2, $zero, $a3
.L7F02904C:
  beqz  $v1, .L7F029098
   li    $at, 0x3F000000 # 0.500000
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f4
  lw    $t6, 0x30($sp)
  li    $at, 0x41800000 # 16.000000
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  mtc1  $at, $f6
  lui   $t8, %hi(0x00004018) # $t8, 0
  addiu $t8, %lo(0x00004018) # addiu $t8, $t8, 0x4018
  lw    $a0, 0x1c($t6)
  li    $a3, 0
  swc1  $f4, 0x10($sp)
  addu  $a1, $t7, $t8
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  b     .L7F0290EC
   lw    $ra, 0x1c($sp)
.L7F029098:
  mtc1  $at, $f8
  lui   $at, %hi(D_80030984)
  lwc1  $f10, %lo(D_80030984)($at)
  lui   $at, %hi(D_80030990)
  lwc1  $f18, %lo(D_80030990)($at)
  mul.s $f16, $f8, $f10
  lw    $t9, 0x30($sp)
  li    $at, 0x41800000 # 16.000000
  lui   $t0, %hi(ptr_animation_table) 
  lw    $t0, %lo(ptr_animation_table)($t0)
  mtc1  $at, $f4
  lui   $t1, %hi(0x00008204) # $t1, 1
  div.s $f0, $f16, $f18
  addiu $t1, %lo(0x00008204) # addiu $t1, $t1, -0x7dfc
  lw    $a0, 0x1c($t9)
  li    $a3, 0
  addu  $a1, $t0, $t1
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f0, 0x10($sp)
  lw    $ra, 0x1c($sp)
.L7F0290EC:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DF8
.word 0x461c4000 /*10000.0*/
.text
glabel set_actor_on_path
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  lw    $t0, ($a1)
  move  $s0, $a0
  li    $t4, -1
  lw    $t7, ($t0)
  lw    $a3, 0x18($a0)
  move  $a2, $zero
  bltz  $t7, .L7F0291D4
   lui   $t1, %hi(ptr_setup_path_tbl) 
  lui   $t2, %hi(ptr_0xxxpresets) 
  lui   $at, %hi(D_80051DF8)
  lwc1  $f12, %lo(D_80051DF8)($at)
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  lw    $t1, %lo(ptr_setup_path_tbl)($t1)
  li    $t3, 44
  sll   $t8, $a2, 2
.L7F029144:
  addu  $v0, $t0, $t8
  lw    $t9, ($v0)
  sll   $t5, $t9, 4
  addu  $v1, $t5, $t1
  lw    $t6, ($v1)
  multu $t6, $t3
  mflo  $t7
  addu  $a0, $t7, $t2
  lw    $a1, 0x28($a0)
  beql  $a1, $zero, .L7F0291C0
   addiu $a2, $a2, 1
  lw    $t8, 0x14($a3)
  bnel  $t8, $a1, .L7F0291C0
   addiu $a2, $a2, 1
  lwc1  $f4, ($a0)
  lwc1  $f6, 8($a3)
  lwc1  $f8, 8($a0)
  lwc1  $f10, 0x10($a3)
  sub.s $f0, $f4, $f6
  sub.s $f2, $f8, $f10
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f18, $f2, $f2
  add.s $f4, $f16, $f18
  c.lt.s $f4, $f12
  nop   
  bc1f  .L7F0291BC
   nop   
  b     .L7F0291D4
   move  $t4, $a2
.L7F0291BC:
  addiu $a2, $a2, 1
.L7F0291C0:
  sll   $t9, $a2, 2
  addu  $t5, $t0, $t9
  lw    $t6, ($t5)
  bgezl $t6, .L7F029144
   sll   $t8, $a2, 2
.L7F0291D4:
  bgez  $t4, .L7F0291E0
   move  $a0, $s0
  move  $t4, $zero
.L7F0291E0:
  jal   sub_GAME_7F02D184
   sw    $t4, 0x20($sp)
  lw    $t4, 0x20($sp)
  li    $t7, 14
  sb    $t7, 7($s0)
  lw    $t8, 0x2c($sp)
  li    $t9, 1
  sw    $t9, 0x34($s0)
  sw    $t4, 0x30($s0)
  jal   get_random_value
   sw    $t8, 0x2c($s0)
  li    $at, 100
  divu  $zero, $v0, $at
  mtc1  $zero, $f6
  mfhi  $t5
  li    $t6, -1
  sw    $t5, 0x60($s0)
  sb    $zero, 0x3b($s0)
  sw    $t6, 0x78($s0)
  move  $a0, $s0
  jal   sub_GAME_7F028494
   swc1  $f6, 0x7c($s0)
  sb    $zero, 8($s0)
  jal   sub_GAME_7F028FAC
   move  $a0, $s0
  jal   sub_GAME_7F028474
   move  $a0, $s0
  lw    $t7, 0x18($s0)
  move  $a0, $s0
  move  $a1, $v0
  lbu   $t8, 1($t7)
  andi  $t9, $t8, 2
  bnezl $t9, .L7F029288
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F027E70
   sw    $v0, 0x24($sp)
  beqz  $v0, .L7F029284
   lw    $a2, 0x24($sp)
  move  $a0, $s0
  jal   sub_GAME_7F027E90
   addiu $a1, $s0, 0x38
.L7F029284:
  lw    $ra, 0x1c($sp)
.L7F029288:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel update_GUARDdata_timer_to_current
  lui   $t6, %hi(global_timer) 
  lw    $t6, %lo(global_timer)($t6)
  jr    $ra
   sw    $t6, 0xe8($a0)
");

asm(R"
glabel sub_GAME_7F0292A8
  addiu $sp, $sp, -0x50
  li    $t6, 1
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a2, 0x58($sp)
  sw    $zero, 0x4c($sp)
  sw    $t6, 0x48($sp)
  lb    $t7, 7($a0)
  li    $at, 8
  move  $s0, $a1
  bne   $t7, $at, .L7F0292E0
   li    $t1, 1
  lw    $t8, 0x4c($a0)
  sw    $t8, 0x48($sp)
.L7F0292E0:
  lw    $t9, 0x48($sp)
  lw    $t2, 0x58($sp)
  addiu $a3, $sp, 0x40
  andi  $t0, $t9, 2
  beql  $t0, $zero, .L7F029304
   sw    $t2, 0x44($sp)
  b     .L7F0294A8
   sw    $t1, 0x4c($sp)
  sw    $t2, 0x44($sp)
.L7F029304:
  lw    $a2, 0x50($a0)
  sw    $a0, 0x50($sp)
  jal   sub_GAME_7F032C78
   lw    $a1, 0x48($sp)
  lw    $a0, 0x50($sp)
  move  $a1, $zero
  jal   set_or_unset_GUARDdata_flag
   sw    $v0, 0x3c($sp)
  lw    $v0, 0x48($sp)
  lw    $v1, 0x3c($sp)
  lui   $t4, %hi(pPlayer) 
  andi  $t3, $v0, 1
  beqz  $t3, .L7F0293DC
   andi  $t0, $v0, 4
  lw    $t4, %lo(pPlayer)($t4)
  move  $a1, $zero
  lw    $a0, 0xa8($t4)
  jal   sub_GAME_7F08A03C
   sw    $v1, 0x3c($sp)
  jal   get_invisible_to_guards_flag
   nop   
  beqz  $v0, .L7F0293C0
   lw    $v1, 0x3c($sp)
  lwc1  $f4, 8($v1)
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  lw    $a3, ($v1)
  li    $t5, 283
  sw    $t5, 0x14($sp)
  swc1  $f4, 0x10($sp)
  lwc1  $f0, 4($s0)
  addiu $a0, $sp, 0x44
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f2, 4($v1)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f2, 0x24($sp)
  beqz  $v0, .L7F0293C0
   lw    $t6, 0x44($sp)
  lw    $t7, 0x40($sp)
  bne   $t6, $t7, .L7F0293C0
   nop   
  jal   update_GUARDdata_timer_to_current
   lw    $a0, 0x50($sp)
  li    $t8, 1
  sw    $t8, 0x4c($sp)
.L7F0293C0:
  lui   $t9, %hi(pPlayer) 
  lw    $t9, %lo(pPlayer)($t9)
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   lw    $a0, 0xa8($t9)
  b     .L7F0294A0
   lw    $a0, 0x50($sp)
.L7F0293DC:
  beqz  $t0, .L7F029440
   andi  $t5, $v0, 8
  lwc1  $f6, 8($v1)
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  lw    $a3, ($v1)
  li    $t1, 279
  sw    $t1, 0x14($sp)
  swc1  $f6, 0x10($sp)
  lwc1  $f0, 4($s0)
  addiu $a0, $sp, 0x44
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f2, 4($v1)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f2, 0x24($sp)
  beqz  $v0, .L7F02949C
   lw    $t2, 0x44($sp)
  lw    $t3, 0x40($sp)
  li    $t4, 1
  bnel  $t2, $t3, .L7F0294A0
   lw    $a0, 0x50($sp)
  b     .L7F02949C
   sw    $t4, 0x4c($sp)
.L7F029440:
  beqz  $t5, .L7F02949C
   li    $t6, 287
  lwc1  $f8, 8($v1)
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  lw    $a3, ($v1)
  sw    $t6, 0x14($sp)
  swc1  $f8, 0x10($sp)
  lwc1  $f0, 4($s0)
  addiu $a0, $sp, 0x44
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  lwc1  $f2, 4($v1)
  swc1  $f2, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f2, 0x24($sp)
  beqz  $v0, .L7F02949C
   lw    $t7, 0x44($sp)
  lw    $t8, 0x40($sp)
  li    $t9, 1
  bnel  $t7, $t8, .L7F0294A0
   lw    $a0, 0x50($sp)
  sw    $t9, 0x4c($sp)
.L7F02949C:
  lw    $a0, 0x50($sp)
.L7F0294A0:
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
.L7F0294A8:
  lw    $ra, 0x34($sp)
  lw    $v0, 0x4c($sp)
  lw    $s0, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F0294BC
  addiu $sp, $sp, -0x50
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  move  $s0, $a0
  jal   get_invisible_to_guards_flag
   sw    $zero, 0x4c($sp)
  beql  $v0, $zero, .L7F0295C0
   lw    $ra, 0x34($sp)
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x48($sp)
  sw    $v0, 0x44($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x28($s0)
  move  $a0, $s0
  move  $a1, $zero
  sub.s $f8, $f4, $f6
  jal   set_or_unset_GUARDdata_flag
   swc1  $f8, 0x3c($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  move  $a1, $zero
  jal   sub_GAME_7F08A03C
   lw    $a0, 0xa8($t7)
  lw    $v0, 0x48($sp)
  lw    $v1, 0x44($sp)
  lwc1  $f0, 0x3c($sp)
  lw    $t8, 0x14($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  sw    $t8, 0x40($sp)
  lwc1  $f10, 0x10($v1)
  lw    $a2, 0x10($v0)
  lw    $a1, 8($v0)
  lw    $a3, 8($v1)
  mtc1  $zero, $f16
  li    $t9, 283
  sw    $t9, 0x14($sp)
  addiu $a0, $sp, 0x40
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f18, 0x24($sp)
  swc1  $f10, 0x10($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f16, 0x20($sp)
  beqz  $v0, .L7F02959C
   lw    $t1, 0x44($sp)
  lw    $t0, 0x40($sp)
  lw    $t2, 0x14($t1)
  bnel  $t0, $t2, .L7F0295A0
   move  $a0, $s0
  jal   update_GUARDdata_timer_to_current
   move  $a0, $s0
  li    $t3, 1
  sw    $t3, 0x4c($sp)
.L7F02959C:
  move  $a0, $s0
.L7F0295A0:
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lui   $t4, %hi(pPlayer) 
  lw    $t4, %lo(pPlayer)($t4)
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   lw    $a0, 0xa8($t4)
  lw    $ra, 0x34($sp)
.L7F0295C0:
  lw    $v0, 0x4c($sp)
  lw    $s0, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel check_if_position_in_same_room
  addiu $sp, $sp, -0x40
  sw    $ra, 0x2c($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  li    $at, 0x41A00000 # 20.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x28($a0)
  lw    $v0, 0x18($a0)
  sw    $zero, 0x30($sp)
  sub.s $f0, $f4, $f6
  sw    $a0, 0x40($sp)
  move  $a1, $zero
  sw    $v0, 0x3c($sp)
  jal   set_or_unset_GUARDdata_flag
   swc1  $f0, 0x34($sp)
  lw    $v0, 0x3c($sp)
  lw    $v1, 0x44($sp)
  lwc1  $f0, 0x34($sp)
  lw    $t6, 0x14($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  sw    $t6, 0x38($sp)
  lwc1  $f8, 8($v1)
  lw    $a2, 0x10($v0)
  lw    $a1, 8($v0)
  lw    $a3, ($v1)
  mtc1  $zero, $f10
  li    $t7, 275
  sw    $t7, 0x14($sp)
  addiu $a0, $sp, 0x38
  swc1  $f0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f8, 0x10($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F029680
   li    $a1, 1
  lw    $t8, 0x38($sp)
  lw    $t9, 0x48($sp)
  li    $t0, 1
  bne   $t8, $t9, .L7F029680
   nop   
  sw    $t0, 0x30($sp)
.L7F029680:
  jal   set_or_unset_GUARDdata_flag
   lw    $a0, 0x40($sp)
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x30($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051DFC
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E00
.word 0x3fdf66f3 /*1.7453293*/
glabel D_80051E04
.word 0x4091361e /*4.5378561*/
.text
glabel sub_GAME_7F02969C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   getsubroty
   lw    $a0, 0x1c($a0)
  lw    $t7, 0x20($sp)
  lw    $v1, 0x24($sp)
  lw    $v0, 0x18($t7)
  lwc1  $f4, ($v1)
  lwc1  $f8, 8($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  swc1  $f0, 0x18($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f16, 0x18($sp)
  lui   $at, %hi(D_80051DFC)
  lw    $a0, 0x20($sp)
  c.lt.s $f0, $f16
  lw    $a1, 0x24($sp)
  sub.s $f12, $f0, $f16
  bc1f  .L7F02970C
   mov.s $f2, $f12
  lwc1  $f18, %lo(D_80051DFC)($at)
  add.s $f2, $f12, $f18
.L7F02970C:
  lui   $at, %hi(D_80051E00)
  lwc1  $f4, %lo(D_80051E00)($at)
  lui   $at, %hi(D_80051E04)
  c.lt.s $f2, $f4
  nop   
  bc1t  .L7F029740
   nop   
  lwc1  $f6, %lo(D_80051E04)($at)
  move  $v0, $zero
  c.lt.s $f6, $f2
  nop   
  bc1f  .L7F029750
   nop   
.L7F029740:
  jal   check_if_position_in_same_room
   lw    $a2, 0x28($sp)
  b     .L7F029754
   lw    $ra, 0x14($sp)
.L7F029750:
  lw    $ra, 0x14($sp)
.L7F029754:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F029760
  addiu $sp, $sp, -0x40
  sw    $ra, 0x2c($sp)
  lw    $t6, 0x18($a0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x3c($sp)
  lui   $t7, %hi(pPlayer) 
  lw    $t7, %lo(pPlayer)($t7)
  sw    $zero, 0x30($sp)
  move  $a1, $zero
  lw    $a0, 0xa8($t7)
  jal   sub_GAME_7F08A03C
   sw    $v0, 0x38($sp)
  lw    $v1, 0x38($sp)
  lw    $v0, 0x3c($sp)
  li    $t9, 19
  lw    $t8, 0x14($v1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  sw    $t8, 0x34($sp)
  lwc1  $f4, 0x10($v0)
  lw    $a2, 0x10($v1)
  lw    $a1, 8($v1)
  lw    $a3, 8($v0)
  sw    $t9, 0x14($sp)
  swc1  $f4, 0x10($sp)
  lwc1  $f0, 0xc($v1)
  mtc1  $zero, $f6
  addiu $a0, $sp, 0x34
  swc1  $f8, 0x24($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x20($sp)
  beqz  $v0, .L7F029808
   lui   $t4, %hi(pPlayer) 
  lw    $t1, 0x3c($sp)
  lw    $t0, 0x34($sp)
  li    $t3, 1
  lw    $t2, 0x14($t1)
  bne   $t0, $t2, .L7F029808
   nop   
  sw    $t3, 0x30($sp)
.L7F029808:
  lw    $t4, %lo(pPlayer)($t4)
  li    $a1, 1
  jal   sub_GAME_7F08A03C
   lw    $a0, 0xa8($t4)
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x30($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E08
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F02982C
  addiu $sp, $sp, -0x80
  sw    $ra, 0x44($sp)
  sw    $s0, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  sw    $a1, 0x84($sp)
  sw    $a2, 0x88($sp)
  lw    $v0, 4($a0)
  lwc1  $f4, ($a2)
  lui   $at, %hi(D_80051E08)
  lwc1  $f0, 0x24($v0)
  lwc1  $f2, %lo(D_80051E08)($at)
  lwc1  $f8, 8($a2)
  mul.s $f6, $f4, $f0
  move  $s0, $a0
  sw    $zero, 0x5c($sp)
  addiu $a2, $sp, 0x58
  addiu $a1, $sp, 0x50
  addiu $a3, $sp, 0x54
  sw    $v0, 0x7c($sp)
  mul.s $f20, $f6, $f2
  nop   
  mul.s $f10, $f8, $f0
  nop   
  mul.s $f22, $f10, $f2
  jal   sub_GAME_7F023160
   nop   
  lw    $a0, 0x7c($sp)
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  lw    $v0, 0x84($sp)
  lwc1  $f16, 8($s0)
  lwc1  $f18, 0x10($s0)
  lwc1  $f4, ($v0)
  add.s $f0, $f16, $f22
  li    $at, 0x3F800000 # 1.000000
  li    $t8, 31
  add.s $f6, $f4, $f22
  lwc1  $f4, 0x58($sp)
  mfc1  $a3, $f0
  sub.s $f2, $f18, $f20
  addiu $a0, $sp, 0x68
  add.s $f8, $f6, $f20
  lwc1  $f6, 0x54($sp)
  swc1  $f8, 0x70($sp)
  lwc1  $f10, 8($v0)
  mtc1  $zero, $f8
  sub.s $f16, $f10, $f20
  mtc1  $at, $f10
  add.s $f18, $f16, $f22
  swc1  $f18, 0x6c($sp)
  lw    $t7, 0x14($s0)
  sw    $t7, 0x68($sp)
  lw    $a2, 0x10($s0)
  lw    $a1, 8($s0)
  swc1  $f2, 0x74($sp)
  swc1  $f0, 0x78($sp)
  sw    $t8, 0x14($sp)
  swc1  $f2, 0x10($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f6, 0x1c($sp)
  swc1  $f8, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x24($sp)
  lwc1  $f0, 0x78($sp)
  beqz  $v0, .L7F029A6C
   lwc1  $f2, 0x74($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f16, 0x6c($sp)
  lwc1  $f18, 0x58($sp)
  lwc1  $f4, 0x54($sp)
  mtc1  $zero, $f6
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  li    $t9, 31
  sw    $t9, 0x14($sp)
  addiu $a0, $sp, 0x68
  lw    $a3, 0x70($sp)
  swc1  $f16, 0x10($sp)
  swc1  $f8, 0x24($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f4, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x20($sp)
  beqz  $v0, .L7F029A6C
   lw    $t0, 0x84($sp)
  lwc1  $f18, ($t0)
  lwc1  $f10, 8($s0)
  lwc1  $f16, 0x10($s0)
  sub.s $f4, $f18, $f22
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f18, 0x58($sp)
  sub.s $f0, $f10, $f22
  li    $t2, 31
  addiu $a0, $sp, 0x68
  add.s $f6, $f4, $f20
  lwc1  $f4, 0x54($sp)
  mfc1  $a3, $f0
  add.s $f2, $f16, $f20
  swc1  $f6, 0x70($sp)
  lwc1  $f8, 8($t0)
  mtc1  $zero, $f6
  add.s $f10, $f8, $f20
  mtc1  $at, $f8
  add.s $f16, $f10, $f22
  swc1  $f16, 0x6c($sp)
  lw    $t1, 0x14($s0)
  sw    $t1, 0x68($sp)
  lw    $a2, 0x10($s0)
  lw    $a1, 8($s0)
  swc1  $f2, 0x74($sp)
  swc1  $f0, 0x78($sp)
  sw    $t2, 0x14($sp)
  swc1  $f2, 0x10($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f4, 0x1c($sp)
  swc1  $f6, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x24($sp)
  lwc1  $f0, 0x78($sp)
  beqz  $v0, .L7F029A6C
   lwc1  $f2, 0x74($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x6c($sp)
  lwc1  $f16, 0x58($sp)
  lwc1  $f18, 0x54($sp)
  mtc1  $zero, $f4
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  li    $t3, 31
  sw    $t3, 0x14($sp)
  addiu $a0, $sp, 0x68
  lw    $a3, 0x70($sp)
  swc1  $f10, 0x10($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f16, 0x18($sp)
  swc1  $f18, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x20($sp)
  beqz  $v0, .L7F029A6C
   li    $t4, 1
  sw    $t4, 0x5c($sp)
.L7F029A6C:
  lw    $a0, 0x7c($sp)
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $ra, 0x44($sp)
  lw    $v0, 0x5c($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  lw    $s0, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x80
");

asm(R"
glabel sub_GAME_7F029A94
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  mtc1  $a2, $f12
  lwc1  $f4, ($a1)
  lwc1  $f8, 8($a0)
  move  $a2, $a1
  mul.s $f6, $f4, $f12
  add.s $f10, $f6, $f8
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0xc($a0)
  swc1  $f16, 0x20($sp)
  lwc1  $f18, 8($a1)
  lwc1  $f6, 0x10($a0)
  addiu $a1, $sp, 0x1c
  mul.s $f4, $f18, $f12
  add.s $f8, $f4, $f6
  jal   sub_GAME_7F02982C
   swc1  $f8, 0x24($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F029AF0
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  lwc1  $f6, 8($a0)
  lwc1  $f4, ($a1)
  mtc1  $zero, $f0
  sub.s $f8, $f4, $f6
  swc1  $f0, 0x28($sp)
  swc1  $f8, 0x24($sp)
  lwc1  $f4, 0x24($sp)
  lwc1  $f16, 0x10($a0)
  lwc1  $f10, 8($a1)
  c.eq.s $f0, $f4
  sub.s $f18, $f10, $f16
  bc1f  .L7F029B48
   swc1  $f18, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  c.eq.s $f0, $f2
  nop   
  bc1fl .L7F029B4C
   lwc1  $f2, 0x2c($sp)
  b     .L7F029BA0
   li    $v0, 1
.L7F029B48:
  lwc1  $f2, 0x2c($sp)
.L7F029B4C:
  lwc1  $f0, 0x24($sp)
  sw    $a0, 0x30($sp)
  mul.s $f6, $f2, $f2
  sw    $a1, 0x34($sp)
  mul.s $f8, $f0, $f0
  jal   sqrtf
   add.s $f12, $f6, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f16, 0x24($sp)
  lwc1  $f4, 0x2c($sp)
  div.s $f2, $f10, $f0
  lw    $a0, 0x30($sp)
  lw    $a1, 0x34($sp)
  addiu $a2, $sp, 0x24
  mul.s $f18, $f16, $f2
  nop   
  mul.s $f6, $f4, $f2
  swc1  $f18, 0x24($sp)
  jal   sub_GAME_7F02982C
   swc1  $f6, 0x2c($sp)
.L7F029BA0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F029BB0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x18($sp)
  lui   $t6, %hi(global_timer) 
  lw    $a0, 0x18($sp)
  lw    $t6, %lo(global_timer)($t6)
  sw    $t6, 0xd4($a0)
  lwc1  $f4, 8($v0)
  swc1  $f4, 0xd8($a0)
  lwc1  $f6, 0xc($v0)
  swc1  $f6, 0xdc($a0)
  lwc1  $f8, 0x10($v0)
  swc1  $f8, 0xe0($a0)
  lw    $t7, 0x14($v0)
  sw    $t7, 0xe4($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F029C00
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lui   $t8, %hi(global_timer) 
  lhu   $t6, 0x12($a0)
  ori   $t7, $t6, 2
  sh    $t7, 0x12($a0)
  lw    $t8, %lo(global_timer)($t8)
  sw    $t8, 0xf0($a0)
  lwc1  $f4, 8($v0)
  swc1  $f4, 0xd8($a0)
  lwc1  $f6, 0xc($v0)
  swc1  $f6, 0xdc($a0)
  lwc1  $f8, 0x10($v0)
  swc1  $f8, 0xe0($a0)
  lw    $t9, 0x14($v0)
  sw    $t9, 0xe4($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_actor_stationary
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lb    $v0, 7($a0)
  li    $at, 1
  move  $s0, $a0
  bnel  $v0, $at, .L7F029CA0
   li    $at, 3
  lw    $t6, 0x2c($a0)
  bnezl $t6, .L7F029CA0
   li    $at, 3
  lw    $t7, 0x38($a0)
  bnezl $t7, .L7F029CA0
   li    $at, 3
  b     .L7F029D5C
   li    $v0, 1
  li    $at, 3
.L7F029CA0:
  bnel  $v0, $at, .L7F029D48
   li    $at, 14
  lw    $t8, 0x34($s0)
  bnez  $t8, .L7F029D3C
   nop   
  jal   sub_GAME_7F06F610
   lw    $a0, 0x1c($s0)
  mtc1  $zero, $f4
  nop   
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F029CFC
   nop   
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($s0)
  swc1  $f0, 0x24($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x1c($s0)
  lwc1  $f6, 0x24($sp)
  c.le.s $f0, $f6
  nop   
  bc1t  .L7F029D3C
   nop   
.L7F029CFC:
  jal   sub_GAME_7F06F610
   lw    $a0, 0x1c($s0)
  mtc1  $zero, $f8
  nop   
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F029D5C
   move  $v0, $zero
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($s0)
  mtc1  $zero, $f10
  nop   
  c.le.s $f0, $f10
  nop   
  bc1fl .L7F029D5C
   move  $v0, $zero
.L7F029D3C:
  b     .L7F029D5C
   li    $v0, 1
  li    $at, 14
.L7F029D48:
  bnel  $v0, $at, .L7F029D5C
   move  $v0, $zero
  b     .L7F029D5C
   li    $v0, 1
  move  $v0, $zero
.L7F029D5C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E10
.word 0x3ff5be0b /*1.9198622*/
glabel D_80051E14
.word 0x408ba058 /*4.3633232*/
glabel D_80051E18
.word 0x471c4000 /*40000.0*/
glabel D_80051E1C
.word 0x3ff5be0b /*1.9198622*/
glabel D_80051E20
.word 0x408ba058 /*4.3633232*/
glabel D_80051E24
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E28
.word 0x40afede0 /*5.4977875*/
glabel D_80051E2C
.word 0x40490fdb /*3.1415927*/
glabel D_80051E30
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E34
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F029D70
  addiu $sp, $sp, -0x58
  sw    $ra, 0x14($sp)
  sw    $a0, 0x58($sp)
  lw    $v1, 0x18($a0)
  jal   get_curplayer_positiondata
   sw    $v1, 0x54($sp)
  lw    $t7, 0x58($sp)
  lw    $a0, 0x1c($t7)
  jal   getsubroty
   sw    $v0, 0x50($sp)
  lw    $v1, 0x54($sp)
  lw    $a1, 0x50($sp)
  lwc1  $f6, 8($v1)
  lwc1  $f4, 8($a1)
  lwc1  $f10, 0xc($v1)
  lwc1  $f8, 0xc($a1)
  sub.s $f12, $f4, $f6
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x3c($sp)
  lwc1  $f8, 0x10($v1)
  lwc1  $f6, 0x10($a1)
  swc1  $f0, 0x44($sp)
  swc1  $f12, 0x40($sp)
  sub.s $f14, $f6, $f8
  jal   convert_angle_using_inverse
   swc1  $f14, 0x38($sp)
  lwc1  $f16, 0x44($sp)
  lwc1  $f14, 0x38($sp)
  move  $v1, $zero
  c.lt.s $f0, $f16
  lui   $at, %hi(D_80051E0C)
  sub.s $f12, $f0, $f16
  lw    $a0, 0x58($sp)
  bc1f  .L7F029E04
   mov.s $f2, $f12
  lwc1  $f10, %lo(D_80051E0C)($at)
  add.s $f2, $f12, $f10
.L7F029E04:
  sw    $v1, 0x2c($sp)
  swc1  $f2, 0x30($sp)
  jal   sub_GAME_7F032B68
   swc1  $f14, 0x38($sp)
  lw    $v1, 0x2c($sp)
  lwc1  $f2, 0x30($sp)
  beqz  $v0, .L7F029E2C
   lwc1  $f14, 0x38($sp)
  b     .L7F02A008
   li    $v1, 1
.L7F029E2C:
  lwc1  $f4, 0x3c($sp)
  lwc1  $f18, 0x40($sp)
  lw    $t8, 0x58($sp)
  mul.s $f6, $f4, $f4
  li    $at, 0x42C80000 # 100.000000
  lwc1  $f0, 0xd0($t8)
  mul.s $f8, $f18, $f18
  mtc1  $at, $f16
  lui   $at, %hi(D_80051E10)
  mul.s $f4, $f14, $f14
  add.s $f10, $f8, $f6
  mul.s $f8, $f0, $f0
  add.s $f12, $f10, $f4
  mul.s $f6, $f8, $f16
  nop   
  mul.s $f10, $f6, $f16
  c.lt.s $f12, $f10
  nop   
  bc1f  .L7F029EA4
   nop   
  lwc1  $f4, %lo(D_80051E10)($at)
  lui   $at, %hi(D_80051E14)
  c.lt.s $f2, $f4
  nop   
  bc1tl .L7F029EF0
   sw    $v1, 0x2c($sp)
  lwc1  $f8, %lo(D_80051E14)($at)
  c.lt.s $f8, $f2
  nop   
  bc1t  .L7F029EEC
.L7F029EA4:
   lui   $at, %hi(D_80051E18)
  lwc1  $f6, %lo(D_80051E18)($at)
  lui   $at, %hi(D_80051E1C)
  c.lt.s $f12, $f6
  nop   
  bc1f  .L7F02A008
   nop   
  lwc1  $f10, %lo(D_80051E1C)($at)
  lui   $at, %hi(D_80051E20)
  c.lt.s $f2, $f10
  nop   
  bc1tl .L7F029EF0
   sw    $v1, 0x2c($sp)
  lwc1  $f4, %lo(D_80051E20)($at)
  c.lt.s $f4, $f2
  nop   
  bc1f  .L7F02A008
   nop   
.L7F029EEC:
  sw    $v1, 0x2c($sp)
.L7F029EF0:
  swc1  $f2, 0x30($sp)
  jal   square_near_fog_value
   swc1  $f12, 0x1c($sp)
  lwc1  $f12, 0x1c($sp)
  lw    $v1, 0x2c($sp)
  lwc1  $f2, 0x30($sp)
  c.lt.s $f12, $f0
  nop   
  bc1f  .L7F02A008
   nop   
  jal   sqrtf
   swc1  $f2, 0x30($sp)
  lui   $at, %hi(D_80051E24)
  lwc1  $f12, %lo(D_80051E24)($at)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f8
  li    $at, 0x467A0000 # 16000.000000
  mtc1  $at, $f10
  mul.s $f6, $f0, $f8
  lwc1  $f2, 0x30($sp)
  lui   $at, %hi(D_80051E28)
  c.lt.s $f12, $f2
  div.s $f4, $f6, $f10
  trunc.w.s $f8, $f4
  mfc1  $a1, $f8
  bc1f  .L7F029FD4
   nop   
  lwc1  $f6, %lo(D_80051E28)($at)
  lui   $at, %hi(D_80051E2C)
  c.lt.s $f2, $f6
  nop   
  bc1f  .L7F029FD4
   nop   
  lwc1  $f10, %lo(D_80051E2C)($at)
  mov.s $f0, $f2
  lui   $at, %hi(D_80051E30)
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F029F9C
   sub.s $f0, $f0, $f12
  lwc1  $f4, %lo(D_80051E30)($at)
  sub.s $f0, $f4, $f2
  sub.s $f0, $f0, $f12
.L7F029F9C:
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051E34)
  lwc1  $f10, %lo(D_80051E34)($at)
  mul.s $f6, $f0, $f8
  div.s $f4, $f6, $f10
  trunc.w.s $f8, $f4
  mfc1  $t1, $f8
  nop   
  addiu $t2, $t1, 1
  multu $a1, $t2
  mflo  $a1
  nop   
  nop   
.L7F029FD4:
  jal   sub_GAME_7F023BC0
   lw    $a0, 0x58($sp)
  addiu $a1, $v0, 1
  jal   get_random_value
   sw    $a1, 0x24($sp)
  lw    $a1, 0x24($sp)
  divu  $zero, $v0, $a1
  mfhi  $v1
  sltiu $t3, $v1, 1
  move  $v1, $t3
  bnez  $a1, .L7F02A008
   nop   
  break 7
.L7F02A008:
  beqz  $v1, .L7F02A01C
   nop   
  jal   sub_GAME_7F0294BC
   lw    $a0, 0x58($sp)
  move  $v1, $v0
.L7F02A01C:
  beqz  $v1, .L7F02A030
   lw    $a0, 0x58($sp)
  jal   sub_GAME_7F029BB0
   sw    $v1, 0x2c($sp)
  lw    $v1, 0x2c($sp)
.L7F02A030:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x58
  move  $v0, $v1
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02A044
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  lw    $v1, 0x18($a0)
  sw    $a2, 0x30($sp)
  jal   get_curplayer_positiondata
   sw    $v1, 0x24($sp)
  lw    $v1, 0x24($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0x10($v0)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0x10($v1)
  sub.s $f2, $f4, $f6
  sub.s $f14, $f8, $f10
  mul.s $f16, $f2, $f2
  swc1  $f2, 0x1c($sp)
  mul.s $f18, $f14, $f14
  swc1  $f14, 0x18($sp)
  jal   sqrtf
   add.s $f12, $f16, $f18
  lw    $t6, 0x2c($sp)
  lwc1  $f2, 0x1c($sp)
  lwc1  $f14, 0x18($sp)
  lw    $a2, 0x30($sp)
  div.s $f2, $f2, $f0
  beqz  $t6, .L7F02A0C8
   div.s $f14, $f14, $f0
  mtc1  $zero, $f4
  neg.s $f6, $f2
  swc1  $f14, ($a2)
  swc1  $f6, 8($a2)
  b     .L7F02A0DC
   swc1  $f4, 4($a2)
.L7F02A0C8:
  mtc1  $zero, $f10
  neg.s $f8, $f14
  swc1  $f2, 8($a2)
  swc1  $f8, ($a2)
  swc1  $f10, 4($a2)
.L7F02A0DC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02A0EC
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a2, 0x40($sp)
  lw    $a3, 0x18($a0)
  addiu $a2, $sp, 0x28
  jal   sub_GAME_7F02A044
   sw    $a3, 0x34($sp)
  lwc1  $f0, 0x40($sp)
  lwc1  $f4, 0x28($sp)
  lw    $a0, 0x34($sp)
  lwc1  $f18, 0x30($sp)
  mul.s $f6, $f4, $f0
  lwc1  $f8, 8($a0)
  addiu $a1, $sp, 0x1c
  mul.s $f4, $f18, $f0
  addiu $a2, $sp, 0x28
  add.s $f10, $f6, $f8
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0xc($a0)
  swc1  $f16, 0x20($sp)
  lwc1  $f6, 0x10($a0)
  add.s $f8, $f4, $f6
  jal   sub_GAME_7F02982C
   swc1  $f8, 0x24($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02A15C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  move  $s0, $a2
  jal   getsubroty
   lw    $a0, 0x1c($a0)
  lw    $t6, 0x2c($sp)
  mov.s $f12, $f0
  beqz  $t6, .L7F02A1B0
   nop   
  jal   cosf
   swc1  $f12, 0x24($sp)
  mtc1  $zero, $f4
  lwc1  $f12, 0x24($sp)
  swc1  $f0, ($s0)
  jal   sinf
   swc1  $f4, 4($s0)
  neg.s $f6, $f0
  b     .L7F02A1D4
   swc1  $f6, 8($s0)
.L7F02A1B0:
  jal   cosf
   swc1  $f12, 0x24($sp)
  mtc1  $zero, $f10
  neg.s $f8, $f0
  lwc1  $f12, 0x24($sp)
  swc1  $f8, ($s0)
  jal   sinf
   swc1  $f10, 4($s0)
  swc1  $f0, 8($s0)
.L7F02A1D4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02A1E8
  addiu $sp, $sp, -0x38
  sw    $ra, 0x14($sp)
  sw    $a2, 0x40($sp)
  lw    $a3, 0x18($a0)
  addiu $a2, $sp, 0x28
  jal   sub_GAME_7F02A15C
   sw    $a3, 0x34($sp)
  lwc1  $f0, 0x40($sp)
  lwc1  $f4, 0x28($sp)
  lw    $a0, 0x34($sp)
  lwc1  $f18, 0x30($sp)
  mul.s $f6, $f4, $f0
  lwc1  $f8, 8($a0)
  addiu $a1, $sp, 0x1c
  mul.s $f4, $f18, $f0
  addiu $a2, $sp, 0x28
  add.s $f10, $f6, $f8
  swc1  $f10, 0x1c($sp)
  lwc1  $f16, 0xc($a0)
  swc1  $f16, 0x20($sp)
  lwc1  $f6, 0x10($a0)
  add.s $f8, $f4, $f6
  jal   sub_GAME_7F02982C
   swc1  $f8, 0x24($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

int true_if_actor_dying_fading_limping_shot(struct CHRdata *chr) {
  char currentaction = chr->actiontype;
  if ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD) ||
      (currentaction == ACT_PREARGH) ||
      (currentaction == ACT_ARGH) && !(chr->chrflags & CHRFLAG_00000200))
    return 0;
  return 1;
}

int true_if_actor_dying_fading(struct CHRdata *chr) {
  char currentaction = chr->actiontype;
  return ((currentaction == ACT_DIE) || (currentaction == ACT_DEAD));
}

asm(R"
.late_rodata
glabel D_80051E38
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E3C
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E40
.word 0x40afede0 /*5.4977875*/
glabel D_80051E44
.word 0x4016cbe4 /*2.3561945*/
glabel D_80051E48
.word 0x407b53d2 /*3.926991*/
.text
glabel actor_steps_sideways
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   move  $s0, $a0
  beql  $v0, $zero, .L7F02A414
   move  $v0, $zero
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x4c($sp)
  lw    $a0, 0x1c($s0)
  jal   getsubroty
   sw    $v0, 0x48($sp)
  lw    $v0, 0x4c($sp)
  lw    $v1, 0x48($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  lwc1  $f4, 8($v1)
  lwc1  $f8, 0x10($v1)
  swc1  $f0, 0x40($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f16, 0x40($sp)
  lui   $at, %hi(D_80051E38)
  c.lt.s $f0, $f16
  sub.s $f12, $f0, $f16
  bc1f  .L7F02A344
   mov.s $f2, $f12
  lwc1  $f18, %lo(D_80051E38)($at)
  add.s $f2, $f12, $f18
.L7F02A344:
  lui   $at, %hi(D_80051E3C)
  lwc1  $f4, %lo(D_80051E3C)($at)
  lui   $at, %hi(D_80051E40)
  c.lt.s $f2, $f4
  nop   
  bc1t  .L7F02A3A4
   nop   
  lwc1  $f6, %lo(D_80051E40)($at)
  lui   $at, %hi(D_80051E44)
  c.lt.s $f6, $f2
  nop   
  bc1t  .L7F02A3A4
   nop   
  lwc1  $f8, %lo(D_80051E44)($at)
  lui   $at, %hi(D_80051E48)
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F02A414
   move  $v0, $zero
  lwc1  $f10, %lo(D_80051E48)($at)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F02A414
   move  $v0, $zero
.L7F02A3A4:
  jal   get_random_value
   nop   
  andi  $a1, $v0, 1
  sltiu $t7, $a1, 1
  move  $a1, $t7
  sw    $t7, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A1E8
   lui   $a2, 0x42c8
  beqz  $v0, .L7F02A3E4
   lw    $a3, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F024800
   move  $a1, $a3
  b     .L7F02A414
   li    $v0, 1
.L7F02A3E4:
  sltiu $a1, $a3, 1
  sw    $a1, 0x24($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A1E8
   lui   $a2, 0x42c8
  beqz  $v0, .L7F02A410
   lw    $a1, 0x24($sp)
  jal   sub_GAME_7F024800
   move  $a0, $s0
  b     .L7F02A414
   li    $v0, 1
.L7F02A410:
  move  $v0, $zero
.L7F02A414:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E4C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E50
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E54
.word 0x40afede0 /*5.4977875*/
glabel D_80051E58
.word 0x4016cbe4 /*2.3561945*/
glabel D_80051E5C
.word 0x407b53d2 /*3.926991*/
.text
glabel actor_hops_sideways
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   move  $s0, $a0
  beql  $v0, $zero, .L7F02A574
   move  $v0, $zero
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x4c($sp)
  lw    $a0, 0x1c($s0)
  jal   getsubroty
   sw    $v0, 0x48($sp)
  lw    $v0, 0x4c($sp)
  lw    $v1, 0x48($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  lwc1  $f4, 8($v1)
  lwc1  $f8, 0x10($v1)
  swc1  $f0, 0x40($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f16, 0x40($sp)
  lui   $at, %hi(D_80051E4C)
  c.lt.s $f0, $f16
  sub.s $f12, $f0, $f16
  bc1f  .L7F02A4A4
   mov.s $f2, $f12
  lwc1  $f18, %lo(D_80051E4C)($at)
  add.s $f2, $f12, $f18
.L7F02A4A4:
  lui   $at, %hi(D_80051E50)
  lwc1  $f4, %lo(D_80051E50)($at)
  lui   $at, %hi(D_80051E54)
  c.lt.s $f2, $f4
  nop   
  bc1t  .L7F02A504
   nop   
  lwc1  $f6, %lo(D_80051E54)($at)
  lui   $at, %hi(D_80051E58)
  c.lt.s $f6, $f2
  nop   
  bc1t  .L7F02A504
   nop   
  lwc1  $f8, %lo(D_80051E58)($at)
  lui   $at, %hi(D_80051E5C)
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F02A574
   move  $v0, $zero
  lwc1  $f10, %lo(D_80051E5C)($at)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F02A574
   move  $v0, $zero
.L7F02A504:
  jal   get_random_value
   nop   
  andi  $a1, $v0, 1
  sltiu $t7, $a1, 1
  move  $a1, $t7
  sw    $t7, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A1E8
   lui   $a2, 0x4348
  beqz  $v0, .L7F02A544
   lw    $a3, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F024A84
   move  $a1, $a3
  b     .L7F02A574
   li    $v0, 1
.L7F02A544:
  sltiu $a1, $a3, 1
  sw    $a1, 0x24($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A1E8
   lui   $a2, 0x4348
  beqz  $v0, .L7F02A570
   lw    $a1, 0x24($sp)
  jal   sub_GAME_7F024A84
   move  $a0, $s0
  b     .L7F02A574
   li    $v0, 1
.L7F02A570:
  move  $v0, $zero
.L7F02A574:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel actor_runs_sideways
  addiu $sp, $sp, -0x50
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  move  $s1, $a0
  sw    $s0, 0x1c($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sdc1  $f20, 0x10($sp)
  beqz  $v0, .L7F02A6E8
   lui   $t6, %hi(global_timer) 
  lw    $t6, %lo(global_timer)($t6)
  lw    $t7, 0xc8($s1)
  subu  $t8, $t6, $t7
  slti  $at, $t8, 0xb5
  bnezl $at, .L7F02A6EC
   move  $v0, $zero
  jal   get_random_value
   lw    $s0, 0x18($s1)
  mtc1  $v0, $f4
  li    $at, 0x43480000 # 200.000000
  mtc1  $at, $f0
  bgez  $v0, .L7F02A5F0
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F02A5F0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  nop   
  mul.s $f16, $f6, $f10
  nop   
  mul.s $f18, $f16, $f0
  jal   get_random_value
   add.s $f20, $f18, $f0
  andi  $a1, $v0, 1
  sltiu $t9, $a1, 1
  move  $a1, $t9
  move  $a0, $s1
  jal   sub_GAME_7F02A044
   addiu $a2, $sp, 0x3c
  lwc1  $f4, 0x3c($sp)
  lwc1  $f6, 8($s0)
  lwc1  $f18, 0x44($sp)
  mul.s $f8, $f4, $f20
  move  $a0, $s0
  addiu $a1, $sp, 0x30
  mul.s $f4, $f18, $f20
  addiu $a2, $sp, 0x3c
  add.s $f10, $f8, $f6
  swc1  $f10, 0x30($sp)
  lwc1  $f16, 0xc($s0)
  swc1  $f16, 0x34($sp)
  lwc1  $f8, 0x10($s0)
  add.s $f6, $f4, $f8
  jal   sub_GAME_7F02982C
   swc1  $f6, 0x38($sp)
  beqz  $v0, .L7F02A684
   lwc1  $f10, 0x3c($sp)
  move  $a0, $s1
  jal   sub_GAME_7F024CF8
   addiu $a1, $sp, 0x30
  b     .L7F02A6EC
   li    $v0, 1
.L7F02A684:
  lwc1  $f18, 0x44($sp)
  neg.s $f16, $f10
  move  $a0, $s0
  mul.s $f8, $f16, $f20
  neg.s $f4, $f18
  swc1  $f16, 0x3c($sp)
  swc1  $f4, 0x44($sp)
  lwc1  $f6, 8($s0)
  mul.s $f16, $f4, $f20
  addiu $a1, $sp, 0x30
  add.s $f10, $f8, $f6
  addiu $a2, $sp, 0x3c
  swc1  $f10, 0x30($sp)
  lwc1  $f18, 0xc($s0)
  swc1  $f18, 0x34($sp)
  lwc1  $f8, 0x10($s0)
  add.s $f6, $f16, $f8
  jal   sub_GAME_7F02982C
   swc1  $f6, 0x38($sp)
  beqz  $v0, .L7F02A6E8
   move  $a0, $s1
  jal   sub_GAME_7F024CF8
   addiu $a1, $sp, 0x30
  b     .L7F02A6EC
   li    $v0, 1
.L7F02A6E8:
  move  $v0, $zero
.L7F02A6EC:
  lw    $ra, 0x24($sp)
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
.late_rodata
glabel D_80051E60
.word 0x49742400 /*1000000.0*/
.text
glabel actor_walks_and_fires
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   move  $s0, $a0
  beql  $v0, $zero, .L7F02A7E4
   move  $v0, $zero
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x24($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   is_weapon_in_guarddata_hand
   sw    $v0, 0x20($sp)
  bnez  $v0, .L7F02A75C
   lw    $v1, 0x20($sp)
  move  $a0, $s0
  li    $a1, 1
  jal   is_weapon_in_guarddata_hand
   sw    $v1, 0x20($sp)
  beqz  $v0, .L7F02A7E0
   lw    $v1, 0x20($sp)
.L7F02A75C:
  lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  lw    $t8, 0xc8($s0)
  lw    $v0, 0x24($sp)
  subu  $t9, $t7, $t8
  slti  $at, $t9, 0xb5
  bnezl $at, .L7F02A7E4
   move  $v0, $zero
  lwc1  $f4, 8($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f8, 0xc($v1)
  lwc1  $f10, 0xc($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 0x10($v1)
  lwc1  $f18, 0x10($v0)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  lui   $at, %hi(D_80051E60)
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  lwc1  $f18, %lo(D_80051E60)($at)
  move  $a0, $s0
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F02A7E4
   move  $v0, $zero
  jal   sub_GAME_7F02587C
   move  $a1, $zero
  b     .L7F02A7E4
   li    $v0, 1
.L7F02A7E0:
  move  $v0, $zero
.L7F02A7E4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E64
.word 0x49742400 /*1000000.0*/
.text
glabel actor_runs_and_fires
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   move  $s0, $a0
  beql  $v0, $zero, .L7F02A8D8
   move  $v0, $zero
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x24($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   is_weapon_in_guarddata_hand
   sw    $v0, 0x20($sp)
  bnez  $v0, .L7F02A850
   lw    $v1, 0x20($sp)
  move  $a0, $s0
  li    $a1, 1
  jal   is_weapon_in_guarddata_hand
   sw    $v1, 0x20($sp)
  beqz  $v0, .L7F02A8D4
   lw    $v1, 0x20($sp)
.L7F02A850:
  lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  lw    $t8, 0xc8($s0)
  lw    $v0, 0x24($sp)
  subu  $t9, $t7, $t8
  slti  $at, $t9, 0xb5
  bnezl $at, .L7F02A8D8
   move  $v0, $zero
  lwc1  $f4, 8($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f8, 0xc($v1)
  lwc1  $f10, 0xc($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 0x10($v1)
  lwc1  $f18, 0x10($v0)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  lui   $at, %hi(D_80051E64)
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  lwc1  $f18, %lo(D_80051E64)($at)
  move  $a0, $s0
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F02A8D8
   move  $v0, $zero
  jal   sub_GAME_7F02587C
   li    $a1, 1
  b     .L7F02A8D8
   li    $v0, 1
.L7F02A8D4:
  move  $v0, $zero
.L7F02A8D8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E68
.word 0x471c4000 /*40000.0*/
.text
glabel actor_rolls_fires_crouched
  addiu $sp, $sp, -0x48
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   move  $s0, $a0
  beql  $v0, $zero, .L7F02AA08
   move  $v0, $zero
  lw    $t6, 0x18($s0)
  jal   get_curplayer_positiondata
   sw    $t6, 0x44($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   is_weapon_in_guarddata_hand
   sw    $v0, 0x40($sp)
  bnez  $v0, .L7F02A944
   lw    $v1, 0x40($sp)
  move  $a0, $s0
  li    $a1, 1
  jal   is_weapon_in_guarddata_hand
   sw    $v1, 0x40($sp)
  beqz  $v0, .L7F02AA04
   lw    $v1, 0x40($sp)
.L7F02A944:
  lw    $v0, 0x44($sp)
  lwc1  $f4, 8($v1)
  lwc1  $f8, 0xc($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0xc($v0)
  lwc1  $f16, 0x10($v1)
  sub.s $f0, $f4, $f6
  lwc1  $f18, 0x10($v0)
  lui   $at, %hi(D_80051E68)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  lwc1  $f18, %lo(D_80051E68)($at)
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F02AA08
   move  $v0, $zero
  jal   get_random_value
   nop   
  andi  $a1, $v0, 1
  sltiu $t7, $a1, 1
  move  $a1, $t7
  sw    $t7, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A0EC
   lui   $a2, 0x4348
  beqz  $v0, .L7F02A9D8
   lw    $a3, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F025C40
   move  $a1, $a3
  b     .L7F02AA08
   li    $v0, 1
.L7F02A9D8:
  sltiu $a1, $a3, 1
  sw    $a1, 0x24($sp)
  move  $a0, $s0
  jal   sub_GAME_7F02A0EC
   lui   $a2, 0x4348
  beqz  $v0, .L7F02AA04
   lw    $a1, 0x24($sp)
  jal   sub_GAME_7F025C40
   move  $a0, $s0
  b     .L7F02AA08
   li    $v0, 1
.L7F02AA04:
  move  $v0, $zero
.L7F02AA08:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel actor_aim_at_actor
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F02AA74
   lw    $a0, 0x18($sp)
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  bnez  $v0, .L7F02AA5C
   lw    $a0, 0x18($sp)
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  beql  $v0, $zero, .L7F02AA78
   move  $v0, $zero
.L7F02AA5C:
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
  jal   sub_GAME_7F025560
   lw    $a2, 0x20($sp)
  b     .L7F02AA78
   li    $v0, 1
.L7F02AA74:
  move  $v0, $zero
.L7F02AA78:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel actor_kneel_aim_at_actor
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F02AAE0
   lw    $a0, 0x18($sp)
  jal   is_weapon_in_guarddata_hand
   move  $a1, $zero
  bnez  $v0, .L7F02AAC8
   lw    $a0, 0x18($sp)
  jal   is_weapon_in_guarddata_hand
   li    $a1, 1
  beql  $v0, $zero, .L7F02AAE4
   move  $v0, $zero
.L7F02AAC8:
  lw    $a0, 0x18($sp)
  lw    $a1, 0x1c($sp)
  jal   sub_GAME_7F0256F0
   lw    $a2, 0x20($sp)
  b     .L7F02AAE4
   li    $v0, 1
.L7F02AAE0:
  move  $v0, $zero
.L7F02AAE4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02AAF4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lb    $t6, 7($a0)
  li    $at, 8
  move  $v0, $zero
  bne   $t6, $at, .L7F02AB34
   nop   
  lw    $t7, 0x4c($a0)
  andi  $t8, $t7, 0x60
  beqz  $t8, .L7F02AB34
   nop   
  sw    $a1, 0x4c($a0)
  jal   sub_GAME_7F024F8C
   sw    $a2, 0x50($a0)
  b     .L7F02AB34
   li    $v0, 1
.L7F02AB34:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_set_actor_standing_still
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a2, 0x20($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F02ABA0
   lw    $a0, 0x18($sp)
  lb    $t6, 7($a0)
  li    $at, 1
  beql  $t6, $at, .L7F02AB84
   lw    $t7, 0x1c($sp)
  jal   sub_GAME_7F023CB8
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lw    $t7, 0x1c($sp)
.L7F02AB84:
  li    $v0, 1
  sw    $t7, 0x30($a0)
  lw    $t8, 0x20($sp)
  sw    $zero, 0x38($a0)
  sw    $zero, 0x40($a0)
  b     .L7F02ABA4
   sw    $t8, 0x34($a0)
.L7F02ABA0:
  move  $v0, $zero
.L7F02ABA4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E6C
.word 0x3f8ccccd /*1.1*/
.text
glabel actor_moves_to_preset_at_speed
  addiu $sp, $sp, -0x40
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  move  $s0, $a1
  move  $s1, $a0
  sw    $ra, 0x24($sp)
  bltz  $a1, .L7F02AD3C
   sw    $a2, 0x48($sp)
  jal   true_if_actor_dying_fading_limping_shot
   nop   
  beqz  $v0, .L7F02AD3C
   lui   $t6, %hi(setting_007_5) 
  lw    $t6, %lo(setting_007_5)($t6)
  move  $a0, $s1
  slti  $at, $t6, 0xa
  beql  $at, $zero, .L7F02AD40
   move  $v0, $zero
  jal   sub_GAME_7F032F94
   move  $a1, $s0
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F02AC30
   sll   $t9, $v0, 4
  sll   $t7, $v0, 2
  subu  $t7, $t7, $v0
  sll   $t7, $t7, 2
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  subu  $t7, $t7, $v0
  sll   $t7, $t7, 2
  b     .L7F02AC50
   addu  $s0, $t7, $t8
.L7F02AC30:
  lui   $t0, %hi(ptr_2xxxpresets) 
  lw    $t0, %lo(ptr_2xxxpresets)($t0)
  addu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $s0, $t9, $t0
  addu  $s0, $s0, $at
.L7F02AC50:
  lw    $t1, 0x28($s0)
  li    $at, 0x3F000000 # 0.500000
  beqz  $t1, .L7F02AD3C
   sw    $t1, 0x28($sp)
  lwc1  $f4, 0x10($s0)
  mtc1  $at, $f6
  lui   $at, %hi(D_80051E6C)
  move  $a0, $s1
  c.lt.s $f4, $f6
  move  $a1, $s0
  lw    $a2, 0x28($sp)
  bc1f  .L7F02AD24
   nop   
  sw    $t1, 0x38($sp)
  lwc1  $f0, %lo(D_80051E6C)($at)
  lwc1  $f10, 0x24($s1)
  lwc1  $f8, 0xc($s0)
  lwc1  $f4, ($s0)
  mul.s $f16, $f10, $f0
  addiu $a0, $sp, 0x38
  mul.s $f18, $f8, $f16
  add.s $f6, $f18, $f4
  swc1  $f6, 0x2c($sp)
  lwc1  $f8, 0x24($s1)
  lwc1  $f10, 0x10($s0)
  lwc1  $f4, 4($s0)
  mul.s $f16, $f8, $f0
  mfc1  $a3, $f6
  mul.s $f18, $f10, $f16
  add.s $f8, $f18, $f4
  swc1  $f8, 0x30($sp)
  lwc1  $f16, 0x24($s1)
  lwc1  $f10, 0x14($s0)
  lwc1  $f8, 8($s0)
  mul.s $f18, $f16, $f0
  nop   
  mul.s $f4, $f10, $f18
  add.s $f16, $f4, $f8
  swc1  $f16, 0x34($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  jal   sub_GAME_7F0B0BE4
   swc1  $f16, 0x10($sp)
  beqz  $v0, .L7F02AD3C
   move  $a0, $s1
  addiu $a1, $sp, 0x2c
  lw    $a2, 0x38($sp)
  jal   plot_course_for_actor
   lw    $a3, 0x48($sp)
  beql  $v0, $zero, .L7F02AD40
   move  $v0, $zero
  b     .L7F02AD40
   li    $v0, 1
.L7F02AD24:
  jal   plot_course_for_actor
   lw    $a3, 0x48($sp)
  beql  $v0, $zero, .L7F02AD40
   move  $v0, $zero
  b     .L7F02AD40
   li    $v0, 1
.L7F02AD3C:
  move  $v0, $zero
.L7F02AD40:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel if_actor_able_set_on_path
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $a1, .L7F02AD84
   sw    $a0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L7F02AD84
   lw    $a1, 0x1c($sp)
  jal   set_actor_on_path
   lw    $a0, 0x18($sp)
  b     .L7F02AD88
   li    $v0, 1
.L7F02AD84:
  move  $v0, $zero
.L7F02AD88:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E70
.word 0x3eb2b8c3 /*0.34906587*/
glabel D_80051E74
.word 0x40bde44f /*5.9341197*/
glabel D_80051E78
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E7C
.word 0x3f490fdb /*0.78539819*/
glabel D_80051E80
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E84
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E88
.word 0x40c90fdb /*6.2831855*/
glabel D_80051E8C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02AD98
  addiu $sp, $sp, -0xb0
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lb    $t6, 8($a0)
  move  $s0, $a0
  bgtzl $t6, .L7F02B4D0
   lw    $ra, 0x24($sp)
  lw    $t7, 0x2c($a0)
  beql  $t7, $zero, .L7F02AE04
   lw    $a1, 0x30($s0)
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($a0)
  swc1  $f0, 0x3c($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x1c($s0)
  lwc1  $f4, 0x3c($sp)
  move  $a0, $s0
  c.le.s $f0, $f4
  nop   
  bc1f  .L7F02ADF8
   nop   
  jal   sub_GAME_7F023948
   lui   $a1, 0x4100
  sw    $zero, 0x2c($s0)
.L7F02ADF8:
  b     .L7F02B4CC
   sb    $zero, 8($s0)
  lw    $a1, 0x30($s0)
.L7F02AE04:
  blez  $a1, .L7F02B05C
   nop   
  lw    $t8, 0x38($s0)
  move  $a0, $s0
  beqz  $t8, .L7F02AE88
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s0)
  lhu   $t9, 4($v0)
  mtc1  $zero, $f8
  lw    $a1, 0x3c($s0)
  addiu $t4, $t9, -1
  mtc1  $t4, $f6
  move  $a0, $s0
  lui   $a3, 0x3f80
  cvt.s.w $f0, $f6
  swc1  $f8, 0x10($sp)
  mfc1  $a2, $f0
  jal   sub_GAME_7F02C2B0
   nop   
  li    $v1, 1
  beq   $v0, $v1, .L7F02B054
   sw    $v0, 0x3c($s0)
  move  $a0, $s0
  jal   sub_GAME_7F023948
   lui   $a1, 0x4100
  lw    $t5, 0x30($s0)
  sw    $zero, 0x38($s0)
  andi  $t6, $t5, 0x10
  beqz  $t6, .L7F02B054
   nop   
  b     .L7F02B054
   sw    $zero, 0x30($s0)
.L7F02AE88:
  jal   sub_GAME_7F0250BC
   lw    $a2, 0x34($s0)
  lui   $at, %hi(D_80051E70)
  lwc1  $f10, %lo(D_80051E70)($at)
  lui   $at, %hi(D_80051E74)
  c.lt.s $f10, $f0
  nop   
  bc1fl .L7F02B044
   lw    $t8, 0x30($s0)
  lwc1  $f16, %lo(D_80051E74)($at)
  move  $a0, $s0
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F02B044
   lw    $t8, 0x30($s0)
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0xa0($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lw    $a0, 0xa0($sp)
  li    $v1, 1
  sw    $v0, 0x9c($sp)
  sw    $v1, 0x38($s0)
  beqz  $a0, .L7F02AEFC
   sw    $v1, 0x3c($s0)
  bnez  $v0, .L7F02AF2C
   nop   
.L7F02AEFC:
  bnez  $a0, .L7F02AF0C
   nop   
  beqz  $v0, .L7F02AF2C
   nop   
.L7F02AF0C:
  jal   check_if_item_held_like_pistol
   nop   
  bnez  $v0, .L7F02AF2C
   nop   
  jal   check_if_item_held_like_pistol
   lw    $a0, 0x9c($sp)
  beqz  $v0, .L7F02AFB0
   lw    $t6, 0x9c($sp)
.L7F02AF2C:
  jal   get_random_value
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f18
  li    $at, 0x41800000 # 16.000000
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  mtc1  $at, $f4
  lw    $a0, 0x1c($s0)
  lui   $v1, %hi(0x00008204) # $v1, 1
  addiu $v1, %lo(0x00008204) # addiu $v1, $v1, -0x7dfc
  sw    $v1, 0x34($sp)
  andi  $a2, $v0, 1
  li    $a3, 0
  swc1  $f18, 0x10($sp)
  addu  $a1, $v1, $t7
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lui   $t8, %hi(ptr_animation_table) 
  lw    $v1, 0x34($sp)
  lw    $t8, %lo(ptr_animation_table)($t8)
  lw    $a0, 0x1c($s0)
  addu  $t9, $v1, $t8
  lhu   $t4, 4($t9)
  addiu $t5, $t4, -1
  mtc1  $t5, $f6
  nop   
  cvt.s.w $f6, $f6
  mfc1  $a1, $f6
  jal   sub_GAME_7F06FDE8
   nop   
  b     .L7F02B054
   nop   
.L7F02AFB0:
  bnez  $t6, .L7F02AFBC
   lw    $t7, 0xa0($sp)
  beqz  $t7, .L7F02B054
.L7F02AFBC:
   li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  lw    $a2, 0xa0($sp)
  li    $at, 0x41800000 # 16.000000
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  mtc1  $at, $f10
  lw    $a0, 0x1c($s0)
  lui   $v0, %hi(0x00004018) # $v0, 0
  addiu $v0, %lo(0x00004018) # addiu $v0, $v0, 0x4018
  sltu  $t9, $zero, $a2
  move  $a2, $t9
  sw    $v0, 0x34($sp)
  li    $a3, 0
  swc1  $f8, 0x10($sp)
  addu  $a1, $v0, $t8
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lui   $t4, %hi(ptr_animation_table) 
  lw    $v0, 0x34($sp)
  lw    $t4, %lo(ptr_animation_table)($t4)
  lw    $a0, 0x1c($s0)
  addu  $t5, $v0, $t4
  lhu   $t6, 4($t5)
  addiu $t7, $t6, -1
  mtc1  $t7, $f16
  nop   
  cvt.s.w $f16, $f16
  mfc1  $a1, $f16
  jal   sub_GAME_7F06FDE8
   nop   
  b     .L7F02B054
   nop   
  lw    $t8, 0x30($s0)
.L7F02B044:
  andi  $t9, $t8, 0x10
  beqz  $t9, .L7F02B054
   nop   
  sw    $zero, 0x30($s0)
.L7F02B054:
  b     .L7F02B4CC
   sb    $zero, 8($s0)
.L7F02B05C:
  jal   get_random_value
   nop   
  li    $at, 5
  divu  $zero, $v0, $at
  lw    $t6, 0x40($s0)
  mfhi  $t4
  addiu $t5, $t4, 0xe
  beqz  $t6, .L7F02B4CC
   sb    $t5, 8($s0)
  lw    $t7, 0x14($s0)
  andi  $t8, $t7, 0x80
  beql  $t8, $zero, .L7F02B09C
   lw    $t9, 0x44($s0)
  b     .L7F02B4CC
   sw    $zero, 0x40($s0)
  lw    $t9, 0x44($s0)
.L7F02B09C:
  lb    $t4, 8($s0)
  subu  $t5, $t9, $t4
  bgez  $t5, .L7F02B4CC
   sw    $t5, 0x44($s0)
  jal   getsubroty
   lw    $a0, 0x1c($s0)
  lui   $at, %hi(D_80051E78)
  swc1  $f0, 0x70($sp)
  mov.s $f2, $f0
  lwc1  $f12, %lo(D_80051E78)($at)
  addiu $v0, $sp, 0x74
.L7F02B0C8:
  lui   $at, %hi(D_80051E7C)
  lwc1  $f18, %lo(D_80051E7C)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  add.s $f2, $f2, $f18
  mtc1  $zero, $f4
  lui   $a2, %hi(0x447A0001) # $a2, 0x447a
  move  $a3, $zero
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F02B100
   lw    $a0, 0x18($s0)
  sub.s $f2, $f2, $f12
  lw    $a0, 0x18($s0)
.L7F02B100:
  mfc1  $a1, $f2
  swc1  $f2, 0x6c($sp)
  sw    $v0, 0x34($sp)
  swc1  $f6, 0x14($sp)
  jal   sub_GAME_7F026364
   swc1  $f4, 0x10($sp)
  lw    $v0, 0x34($sp)
  lui   $at, %hi(D_80051E80)
  addiu $t7, $sp, 0x94
  lwc1  $f12, %lo(D_80051E80)($at)
  addiu $v0, $v0, 4
  sltu  $at, $v0, $t7
  lwc1  $f2, 0x6c($sp)
  bnez  $at, .L7F02B0C8
   swc1  $f0, -4($v0)
  move  $a2, $zero
  addiu $t2, $sp, 0x44
.L7F02B144:
  sw    $a2, ($t2)
  addiu $a2, %lo(0x447A0001) # addiu $a2, $a2, 1
  slti  $at, $a2, 8
  bnez  $at, .L7F02B144
   addiu $t2, $t2, 4
  move  $a2, $zero
  addiu $t2, $sp, 0x44
  addiu $t0, $sp, 0x44
  li    $a3, 8
  addiu $a0, $sp, 0x74
.L7F02B16C:
  addiu $t3, $a2, 1
  slti  $at, $t3, 8
  move  $a1, $a2
  beqz  $at, .L7F02B2E8
   move  $v0, $t3
  subu  $t1, $a3, $t3
  andi  $t8, $t1, 3
  beqz  $t8, .L7F02B1E4
   addu  $a2, $t8, $t3
  sll   $t9, $v0, 2
  addu  $v1, $t0, $t9
.L7F02B198:
  lw    $t4, ($v1)
  sll   $t7, $a1, 2
  addu  $t8, $t0, $t7
  lw    $t9, ($t8)
  sll   $t5, $t4, 2
  addu  $t6, $a0, $t5
  sll   $t4, $t9, 2
  addu  $t5, $a0, $t4
  lwc1  $f10, ($t5)
  lwc1  $f8, ($t6)
  c.lt.s $f8, $f10
  nop   
  bc1fl .L7F02B1D8
   addiu $v0, $v0, 1
  move  $a1, $v0
  addiu $v0, $v0, 1
.L7F02B1D8:
  bne   $a2, $v0, .L7F02B198
   addiu $v1, $v1, 4
  beq   $v0, $a3, .L7F02B2E8
.L7F02B1E4:
   sll   $t6, $v0, 2
  addu  $v1, $t0, $t6
.L7F02B1EC:
  sll   $t7, $a1, 2
  addu  $t8, $t0, $t7
  lw    $t9, ($t8)
  lw    $t6, ($v1)
  sll   $t4, $t9, 2
  sll   $t7, $t6, 2
  addu  $t8, $a0, $t7
  addu  $t5, $a0, $t4
  lwc1  $f0, ($t5)
  lwc1  $f16, ($t8)
  sll   $t9, $v0, 2
  addu  $t4, $t0, $t9
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F02B244
   lw    $t8, 4($v1)
  lw    $t5, ($t4)
  move  $a1, $v0
  sll   $t6, $t5, 2
  addu  $t7, $a0, $t6
  lwc1  $f0, ($t7)
  lw    $t8, 4($v1)
.L7F02B244:
  sll   $t9, $t8, 2
  addu  $t4, $a0, $t9
  lwc1  $f18, ($t4)
  c.lt.s $f18, $f0
  nop   
  bc1fl .L7F02B280
   lw    $t4, 8($v1)
  addiu $a1, $v0, 1
  sll   $t5, $a1, 2
  addu  $t6, $t0, $t5
  lw    $t7, ($t6)
  sll   $t8, $t7, 2
  addu  $t9, $a0, $t8
  lwc1  $f0, ($t9)
  lw    $t4, 8($v1)
.L7F02B280:
  sll   $t5, $t4, 2
  addu  $t6, $a0, $t5
  lwc1  $f4, ($t6)
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F02B2BC
   lw    $t6, 0xc($v1)
  addiu $a1, $v0, 2
  sll   $t7, $a1, 2
  addu  $t8, $t0, $t7
  lw    $t9, ($t8)
  sll   $t4, $t9, 2
  addu  $t5, $a0, $t4
  lwc1  $f0, ($t5)
  lw    $t6, 0xc($v1)
.L7F02B2BC:
  sll   $t7, $t6, 2
  addu  $t8, $a0, $t7
  lwc1  $f6, ($t8)
  c.lt.s $f6, $f0
  nop   
  bc1fl .L7F02B2E0
   addiu $v0, $v0, 4
  addiu $a1, $v0, 3
  addiu $v0, $v0, 4
.L7F02B2E0:
  bne   $v0, $a3, .L7F02B1EC
   addiu $v1, $v1, 0x10
.L7F02B2E8:
  sll   $t9, $a1, 2
  addu  $v1, $t0, $t9
  lw    $t4, ($v1)
  lw    $v0, ($t2)
  slti  $at, $t3, 7
  sw    $t4, ($t2)
  move  $a2, $t3
  addiu $t2, $t2, 4
  bnez  $at, .L7F02B16C
   sw    $v0, ($v1)
  li    $at, 0x43F50000 # 490.000000
  mtc1  $at, $f10
  lwc1  $f8, 0x74($sp)
  lw    $a2, 0x54($sp)
  li    $a1, -1
  c.lt.s $f8, $f10
  sll   $t5, $a2, 2
  addu  $t6, $a0, $t5
  li    $at, 0x43480000 # 200.000000
  bc1f  .L7F02B450
   nop   
  lwc1  $f16, ($t6)
  mtc1  $at, $f18
  lw    $v0, 0x44($sp)
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F02B360
   nop   
  b     .L7F02B450
   li    $a1, 7
.L7F02B360:
  beqz  $v0, .L7F02B378
   lw    $t7, 0x48($sp)
  beqz  $t7, .L7F02B378
   lw    $t8, 0x4c($sp)
  bnez  $t8, .L7F02B3FC
   li    $v1, 1
.L7F02B378:
  lw    $t9, 0x50($sp)
  li    $v1, 4
  beq   $v1, $t9, .L7F02B390
   nop   
  bne   $v1, $a2, .L7F02B3D4
   nop   
.L7F02B390:
  jal   get_random_value
   nop   
  lui   $at, %hi(D_80051E84)
  lwc1  $f12, %lo(D_80051E84)($at)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t4
  li    $v1, 4
  bnez  $t4, .L7F02B3D4
   addiu $t0, $sp, 0x44
  lw    $t5, 0x50($sp)
  bne   $v1, $t5, .L7F02B3CC
   nop   
  b     .L7F02B450
   li    $a1, 3
.L7F02B3CC:
  b     .L7F02B450
   li    $a1, 4
.L7F02B3D4:
  jal   get_random_value
   nop   
  lui   $at, %hi(D_80051E88)
  lwc1  $f12, %lo(D_80051E88)($at)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $a1
  addiu $a1, $a1, 5
  b     .L7F02B450
   addiu $t0, $sp, 0x44
.L7F02B3FC:
  beq   $v1, $v0, .L7F02B40C
   li    $at, 7
  bne   $v0, $at, .L7F02B450
   nop   
.L7F02B40C:
  lw    $t6, 0x58($sp)
  lw    $t7, 0x5c($sp)
  beqz  $t6, .L7F02B450
   nop   
  beqz  $t7, .L7F02B450
   lw    $t8, 0x60($sp)
  beqz  $t8, .L7F02B450
   nop   
  jal   get_random_value
   nop   
  lui   $at, %hi(D_80051E8C)
  lwc1  $f12, %lo(D_80051E8C)($at)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $a1
  addiu $a1, $a1, 5
  addiu $t0, $sp, 0x44
.L7F02B450:
  bltz  $a1, .L7F02B4C8
   sll   $t9, $a1, 2
  addu  $t4, $t0, $t9
  lw    $a2, ($t4)
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f10
  mtc1  $a2, $f4
  lwc1  $f18, 0x70($sp)
  li    $at, 0x47800000 # 65536.000000
  cvt.s.w $f6, $f4
  mtc1  $at, $f4
  mul.s $f8, $f6, $f12
  nop   
  mul.s $f16, $f8, $f10
  add.s $f0, $f16, $f18
  c.le.s $f12, $f0
  mov.s $f2, $f0
  bc1f  .L7F02B4A0
   nop   
  sub.s $f2, $f0, $f12
.L7F02B4A0:
  mul.s $f6, $f2, $f4
  move  $a0, $s0
  li    $a1, 16
  div.s $f8, $f6, $f12
  trunc.w.s $f10, $f8
  mfc1  $a2, $f10
  jal   check_set_actor_standing_still
   nop   
  b     .L7F02B4D0
   lw    $ra, 0x24($sp)
.L7F02B4C8:
  sw    $zero, 0x40($s0)
.L7F02B4CC:
  lw    $ra, 0x24($sp)
.L7F02B4D0:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xb0
  jr    $ra
   nop   
");

void actor_reset_sleep(struct CHRdata *actor) { actor->sleep = 0; }

asm(R"
glabel sub_GAME_7F02B4E8
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x30($a0)
  move  $s0, $a0
  bnez  $t6, .L7F02B534
   nop   
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($a0)
  swc1  $f0, 0x20($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x1c($s0)
  lwc1  $f4, 0x20($sp)
  c.le.s $f0, $f4
  nop   
  bc1f  .L7F02B534
   nop   
  jal   sub_GAME_7F023CB8
   move  $a0, $s0
.L7F02B534:
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s0)
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x0000B9A8) # $t8, 1
  addiu $t8, %lo(0x0000B9A8) # addiu $t8, $t8, -0x4658
  addu  $t9, $t7, $t8
  bnel  $v0, $t9, .L7F02B5F4
   lb    $t6, 8($s0)
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($s0)
  li    $at, 0x42280000 # 42.000000
  mtc1  $at, $f6
  nop   
  c.le.s $f6, $f0
  nop   
  bc1fl .L7F02B5F4
   lb    $t6, 8($s0)
  lw    $t0, 0x14($s0)
  lui   $t2, %hi(D_80048380) 
  sll   $t1, $t0, 6
  bltzl $t1, .L7F02B5F4
   lb    $t6, 8($s0)
  lw    $t2, %lo(D_80048380)($t2)
  andi  $t3, $t2, 1
  bnezl $t3, .L7F02B5E4
   lw    $t4, 0x14($s0)
  jal   sub_GAME_7F032DE4
   move  $a0, $s0
  li    $at, 0x44480000 # 800.000000
  mtc1  $at, $f8
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 257
  c.lt.s $f0, $f8
  move  $a2, $zero
  bc1fl .L7F02B5E4
   lw    $t4, 0x14($s0)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  lw    $a1, 0x18($s0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lw    $t4, 0x14($s0)
.L7F02B5E4:
  lui   $at, 0x200
  or    $t5, $t4, $at
  sw    $t5, 0x14($s0)
  lb    $t6, 8($s0)
.L7F02B5F4:
  bgtzl $t6, .L7F02B628
   lw    $ra, 0x1c($sp)
  lw    $t7, 0x38($s0)
  beql  $t7, $zero, .L7F02B628
   lw    $ra, 0x1c($sp)
  jal   get_random_value
   nop   
  li    $at, 5
  divu  $zero, $v0, $at
  mfhi  $t8
  addiu $t9, $t8, 0xe
  sb    $t9, 8($s0)
  lw    $ra, 0x1c($sp)
.L7F02B628:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02B638
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lb    $t6, 8($a0)
  move  $s0, $a0
  li    $t7, 16
  bgtzl $t6, .L7F02B764
   lw    $ra, 0x24($sp)
  lw    $a0, 0x1c($a0)
  sb    $t7, 8($s0)
  jal   sub_GAME_7F06F5AC
   sw    $a0, 0x3c($sp)
  lui   $t8, %hi(ptr_animation_table) 
  lw    $t8, %lo(ptr_animation_table)($t8)
  lui   $t9, %hi(0x00004504) # $t9, 0
  addiu $t9, %lo(0x00004504) # addiu $t9, $t9, 0x4504
  addu  $t0, $t8, $t9
  bnel  $v0, $t0, .L7F02B764
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x3c($sp)
  li    $at, 0x42A00000 # 80.000000
  mtc1  $at, $f4
  lui   $t2, %hi(D_80030A44) 
  addiu $t2, %lo(D_80030A44) # addiu $t2, $t2, 0xa44
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F02B764
   lw    $ra, 0x24($sp)
  lw    $at, ($t2)
  addiu $t1, $sp, 0x30
  lw    $t4, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  sw    $t4, 4($t1)
  sw    $at, 8($t1)
  jal   getsubroty
   lw    $a0, 0x3c($sp)
  swc1  $f0, 0x2c($sp)
  jal   sinf
   mov.s $f12, $f0
  neg.s $f6, $f0
  lwc1  $f12, 0x2c($sp)
  jal   cosf
   swc1  $f6, 0x30($sp)
  neg.s $f8, $f0
  addiu $a1, $sp, 0x30
  swc1  $f8, 0x38($sp)
  lw    $a0, 0x18($s0)
  jal   sub_GAME_7F029A94
   lui   $a2, 0x41a0
  bnezl $v0, .L7F02B764
   lw    $ra, 0x24($sp)
  jal   get_random_value
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  li    $at, 0x41800000 # 16.000000
  lui   $t5, %hi(ptr_animation_table) 
  lw    $t5, %lo(ptr_animation_table)($t5)
  mtc1  $at, $f16
  lui   $t6, %hi(0x00004384) # $t6, 0
  addiu $t6, %lo(0x00004384) # addiu $t6, $t6, 0x4384
  lw    $a0, 0x1c($s0)
  andi  $a2, $v0, 1
  lui   $a3, 0x41f0
  swc1  $f10, 0x10($sp)
  addu  $a1, $t5, $t6
  jal   sub_GAME_7F06FCA8
   swc1  $f16, 0x14($sp)
  lw    $a0, 0x1c($s0)
  lui   $a1, 0x41f0
  jal   sub_GAME_7F06FDCC
   lui   $a2, 0x4180
  lw    $ra, 0x24($sp)
.L7F02B764:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel manage_guard_fade
  lw    $v0, 0x2c($a0)
  lui   $t6, %hi(clock_timer) 
  bltzl $v0, .L7F02B7F8
   sw    $zero, 0x2c($a0)
  lw    $t6, %lo(clock_timer)($t6)
  li    $v1, 90
  addu  $t7, $v0, $t6
  slti  $at, $t7, 0x5a
  sw    $t7, 0x2c($a0)
  bnez  $at, .L7F02B7B0
   move  $v0, $t7
  lhu   $t8, 0x12($a0)
  ori   $t9, $t8, 0x20
  jr    $ra
   sh    $t9, 0x12($a0)

.L7F02B7B0:
  subu  $t0, $v1, $v0
  sll   $t1, $t0, 8
  subu  $t1, $t1, $t0
  div   $zero, $t1, $v1
  mflo  $t2
  sb    $t2, 0xc($a0)
  bnez  $v1, .L7F02B7D4
   nop   
  break 7
.L7F02B7D4:
  li    $at, -1
  bne   $v1, $at, .L7F02B7EC
   lui   $at, 0x8000
  bne   $t1, $at, .L7F02B7EC
   nop   
  break 6
.L7F02B7EC:
  jr    $ra
   nop   

  sw    $zero, 0x2c($a0)
.L7F02B7F8:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E90
.word 0x4a742400 /*4000000.0*/
.text
glabel sub_GAME_7F02B800
  addiu $sp, $sp, -0x40
  sw    $ra, 0x3c($sp)
  sw    $s7, 0x38($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  move  $s4, $a0
  move  $s7, $a1
  sw    $s6, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  move  $s3, $zero
  jal   get_numguards
   move  $s2, $zero
  lb    $v1, 7($s4)
  li    $at, 6
  move  $s6, $v0
  bne   $v1, $at, .L7F02B85C
   lui   $s5, %hi(ptr_guard_data)
  b     .L7F02B86C
   lw    $s3, 0x2c($s4)
.L7F02B85C:
  li    $at, 4
  bnel  $v1, $at, .L7F02B870
   slt   $at, $s3, $v0
  lw    $s3, 0x2c($s4)
.L7F02B86C:
  slt   $at, $s3, $v0
.L7F02B870:
  beqz  $at, .L7F02B94C
   sll   $s1, $s3, 4
  subu  $s1, $s1, $s3
  sll   $s1, $s1, 3
  subu  $s1, $s1, $s3
  lui   $at, %hi(D_80051E90)
  lwc1  $f20, %lo(D_80051E90)($at)
  sll   $s1, $s1, 2
  addiu $s5, %lo(ptr_guard_data) # addiu $s5, $s5, -0x339c
  lw    $t6, ($s5)
.L7F02B898:
  addu  $s0, $s1, $t6
  lw    $t7, 0x1c($s0)
  beql  $t7, $zero, .L7F02B934
   addiu $s3, $s3, 1
  lw    $v0, 0x18($s0)
  lw    $v1, 0x18($s4)
  move  $a0, $s0
  lwc1  $f4, 8($v0)
  lwc1  $f6, 8($v1)
  lwc1  $f8, 0xc($v0)
  lwc1  $f10, 0xc($v1)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 0x10($v0)
  lwc1  $f18, 0x10($v1)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  addiu $a1, $v1, 8
  sub.s $f12, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f12, $f12
  add.s $f16, $f8, $f10
  c.lt.s $f16, $f20
  nop   
  bc1fl .L7F02B934
   addiu $s3, $s3, 1
  addiu $s2, $s2, 1
  jal   sub_GAME_7F02969C
   lw    $a2, 0x14($v1)
  beql  $v0, $zero, .L7F02B934
   addiu $s3, $s3, 1
  bnezl $s7, .L7F02B92C
   lh    $t9, ($s4)
  lh    $t8, ($s4)
  b     .L7F02B930
   sh    $t8, 0x118($s0)
  lh    $t9, ($s4)
.L7F02B92C:
  sh    $t9, 0x11a($s0)
.L7F02B930:
  addiu $s3, $s3, 1
.L7F02B934:
  slt   $at, $s3, $s6
  beqz  $at, .L7F02B94C
   addiu $s1, $s1, 0x1dc
  slti  $at, $s2, 4
  bnezl $at, .L7F02B898
   lw    $t6, ($s5)
.L7F02B94C:
  lb    $v1, 7($s4)
  li    $at, 6
  bnel  $v1, $at, .L7F02B968
   li    $at, 4
  b     .L7F02B974
   sw    $s3, 0x2c($s4)
  li    $at, 4
.L7F02B968:
  bnel  $v1, $at, .L7F02B978
   lw    $ra, 0x3c($sp)
  sw    $s3, 0x2c($s4)
.L7F02B974:
  lw    $ra, 0x3c($sp)
.L7F02B978:
  ldc1  $f20, 0x10($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  lw    $s6, 0x34($sp)
  lw    $s7, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
.late_rodata
glabel D_80051E94
.word 0x3e99999a /*0.30000001*/
.text
glabel guard_body_hit_sfx
  addiu $sp, $sp, -0x58
  lui   $t7, %hi(body_hit_SFX) 
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  addiu $t7, %lo(body_hit_SFX) # addiu $t7, $t7, 0xa50
  lw    $at, ($t7)
  lw    $s1, 0x1c($a0)
  addiu $t6, $sp, 0x38
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lw    $t0, 4($t7)
  mtc1  $zero, $f6
  sw    $at, 8($t6)
  lw    $at, 0x10($t7)
  sw    $t0, 4($t6)
  lw    $t0, 0xc($t7)
  sw    $at, 0x10($t6)
  lhu   $at, 0x14($t7)
  sw    $t0, 0xc($t6)
  move  $s0, $a0
  sh    $at, 0x14($t6)
  lwc1  $f4, 0x30($a0)
  c.le.s $f6, $f4
  nop   
  bc1fl .L7F02BA98
   lwc1  $f16, 0x34($s0)
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  lwc1  $f8, 0x30($s0)
  lui   $v0, %hi(D_80030A68)
  lui   $a0, %hi(ptr_sfx_buf)
  c.le.s $f8, $f0
  nop   
  bc1fl .L7F02BA98
   lwc1  $f16, 0x34($s0)
  lw    $v0, %lo(D_80030A68)($v0)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a2, $zero
  sll   $t1, $v0, 1
  addu  $a1, $sp, $t1
  jal   play_sfx_a1
   lh    $a1, 0x38($a1)
  lw    $a1, 0x18($s0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lui   $v0, %hi(D_80030A68)
  lw    $v0, %lo(D_80030A68)($v0)
  lui   $at, %hi(D_80030A68)
  addiu $v0, $v0, 1
  sw    $v0, %lo(D_80030A68)($at)
  slti  $at, $v0, 0xb
  bnez  $at, .L7F02BA84
   lui   $at, %hi(D_80030A68)
  sw    $zero, %lo(D_80030A68)($at)
.L7F02BA84:
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f10
  nop   
  swc1  $f10, 0x30($s0)
  lwc1  $f16, 0x34($s0)
.L7F02BA98:
  mtc1  $zero, $f18
  nop   
  c.le.s $f18, $f16
  nop   
  bc1f  .L7F02BB34
   nop   
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  lwc1  $f4, 0x34($s0)
  lui   $v0, %hi(D_80030A68)
  lui   $a0, %hi(ptr_sfx_buf)
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F02BB34
   nop   
  lw    $v0, %lo(D_80030A68)($v0)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a2, $zero
  sll   $t2, $v0, 1
  addu  $a1, $sp, $t2
  jal   play_sfx_a1
   lh    $a1, 0x38($a1)
  lw    $a1, 0x18($s0)
  move  $a0, $v0
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lui   $v0, %hi(D_80030A68)
  lw    $v0, %lo(D_80030A68)($v0)
  lui   $at, %hi(D_80030A68)
  addiu $v0, $v0, 1
  sw    $v0, %lo(D_80030A68)($at)
  slti  $at, $v0, 0xb
  bnez  $at, .L7F02BB24
   lui   $at, %hi(D_80030A68)
  sw    $zero, %lo(D_80030A68)($at)
.L7F02BB24:
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f6
  nop   
  swc1  $f6, 0x34($s0)
.L7F02BB34:
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  swc1  $f0, 0x34($sp)
  jal   sub_GAME_7F06F5C4
   move  $a0, $s1
  lwc1  $f8, 0x34($sp)
  c.le.s $f0, $f8
  nop   
  bc1fl .L7F02BC64
   move  $a0, $s0
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lui   $t3, %hi(ptr_animation_table) 
  lw    $t3, %lo(ptr_animation_table)($t3)
  lui   $t4, %hi(0x0000540C) # $t4, 0
  addiu $t4, %lo(0x0000540C) # addiu $t4, $t4, 0x540c
  addu  $t5, $t3, $t4
  bne   $v0, $t5, .L7F02BC58
   nop   
  jal   sub_GAME_7F06F5B4
   move  $a0, $s1
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f0
  lui   $at, %hi(D_80051E94)
  lui   $t9, %hi(ptr_animation_table) 
  lw    $t9, %lo(ptr_animation_table)($t9)
  lwc1  $f10, %lo(D_80051E94)($at)
  lui   $s0, %hi(0x00005684) # $s0, 0
  addiu $s0, %lo(0x00005684) # addiu $s0, $s0, 0x5684
  addu  $a1, $s0, $t9
  swc1  $f10, 0x10($sp)
  lhu   $t8, 4($a1)
  mfc1  $a3, $f0
  move  $a0, $s1
  mtc1  $t8, $f16
  sltiu $a2, $v0, 1
  bgez  $t8, .L7F02BBDC
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F02BBDC:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  nop   
  sub.s $f8, $f18, $f6
  sub.s $f10, $f8, $f0
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lui   $t6, %hi(ptr_animation_table) 
  lw    $t6, %lo(ptr_animation_table)($t6)
  move  $a0, $s1
  lui   $a1, 0x3f00
  addu  $t7, $s0, $t6
  lhu   $t0, 4($t7)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t0, $f16
  bgez  $t0, .L7F02BC2C
   cvt.s.w $f4, $f16
  mtc1  $at, $f18
  nop   
  add.s $f4, $f4, $f18
.L7F02BC2C:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f10
  sub.s $f8, $f4, $f6
  sub.s $f16, $f8, $f10
  mfc1  $a2, $f16
  jal   sub_GAME_7F06FE4C
   nop   
  b     .L7F02BC70
   lw    $ra, 0x24($sp)
.L7F02BC58:
  jal   actor_fade_away
   move  $a0, $s0
  move  $a0, $s0
.L7F02BC64:
  jal   sub_GAME_7F02B800
   li    $a1, 1
  lw    $ra, 0x24($sp)
.L7F02BC70:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x58
");

asm(R"
glabel sub_GAME_7F02BC80
  addiu $sp, $sp, -0x28
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x24($sp)
  swc1  $f0, 0x20($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x24($sp)
  lwc1  $f4, 0x20($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BD04
   move  $a0, $s0
  jal   sub_GAME_7F029BB0
   move  $a0, $s0
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x24($sp)
  lui   $t6, %hi(ptr_animation_table) 
  lw    $t6, %lo(ptr_animation_table)($t6)
  lui   $t7, %hi(0x0000540C) # $t7, 0
  addiu $t7, %lo(0x0000540C) # addiu $t7, $t7, 0x540c
  addu  $t8, $t6, $t7
  bne   $v0, $t8, .L7F02BCF8
   move  $a0, $s0
  jal   sub_GAME_7F023E14
   lui   $a1, 0x41d0
  b     .L7F02BD04
   move  $a0, $s0
.L7F02BCF8:
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  move  $a0, $s0
.L7F02BD04:
  jal   sub_GAME_7F02B800
   move  $a1, $zero
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BD20
  addiu $sp, $sp, -0x40
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x3c($sp)
  lw    $a0, 0x3c($sp)
  jal   sub_GAME_7F06F5C4
   swc1  $f0, 0x2c($sp)
  lwc1  $f4, 0x2c($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BD94
   lw    $ra, 0x24($sp)
  lwc1  $f6, 0x2c($s0)
  move  $a0, $s0
  addiu $a1, $sp, 0x30
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 0x30($s0)
  swc1  $f8, 0x34($sp)
  lwc1  $f10, 0x34($s0)
  swc1  $f10, 0x38($sp)
  lw    $t6, 0x40($s0)
  lw    $a3, 0x3c($s0)
  lw    $a2, 0x38($s0)
  jal   triggered_on_shot_hit
   sw    $t6, 0x10($sp)
  lw    $ra, 0x24($sp)
.L7F02BD94:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BDA4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  jal   sub_GAME_7F06F5C4
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BDF4
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F029BB0
   lw    $a0, 0x20($sp)
  lw    $a0, 0x20($sp)
  jal   sub_GAME_7F023E14
   lui   $a1, 0x4120
  lw    $ra, 0x14($sp)
.L7F02BDF4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BE00
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  jal   sub_GAME_7F06F5C4
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BE4C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F029BB0
   lw    $a0, 0x20($sp)
  jal   sub_GAME_7F023E48
   lw    $a0, 0x20($sp)
  lw    $ra, 0x14($sp)
.L7F02BE4C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BE58
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  jal   sub_GAME_7F06F5C4
   swc1  $f0, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BE9C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F023CB8
   lw    $a0, 0x20($sp)
  lw    $ra, 0x14($sp)
.L7F02BE9C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BEA8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x1c($sp)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f4
  nop   
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F02BEE4
   nop   
  jal   start_alarm
   nop   
.L7F02BEE4:
  jal   sub_GAME_7F06F5BC
   lw    $a0, 0x1c($sp)
  swc1  $f0, 0x18($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x1c($sp)
  lwc1  $f6, 0x18($sp)
  c.le.s $f0, $f6
  nop   
  bc1fl .L7F02BF18
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F023E48
   lw    $a0, 0x20($sp)
  lw    $ra, 0x14($sp)
.L7F02BF18:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BF24
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x28($sp)
  lw    $s0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   move  $a0, $s0
  swc1  $f0, 0x20($sp)
  jal   sub_GAME_7F06F5C4
   move  $a0, $s0
  lwc1  $f4, 0x20($sp)
  c.le.s $f0, $f4
  nop   
  bc1fl .L7F02BFD4
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F06F5AC
   move  $a0, $s0
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x00004384) # $t8, 0
  addiu $t8, %lo(0x00004384) # addiu $t8, $t8, 0x4384
  addu  $t9, $t7, $t8
  bne   $v0, $t9, .L7F02BF94
   lw    $a0, 0x28($sp)
  jal   sub_GAME_7F023E14
   lui   $a1, 0x41d0
  b     .L7F02BFD4
   lw    $ra, 0x1c($sp)
.L7F02BF94:
  jal   sub_GAME_7F06F5AC
   move  $a0, $s0
  lui   $t0, %hi(ptr_animation_table) 
  lw    $t0, %lo(ptr_animation_table)($t0)
  lui   $t1, %hi(0x00005D10) # $t1, 0
  addiu $t1, %lo(0x00005D10) # addiu $t1, $t1, 0x5d10
  addu  $t2, $t0, $t1
  bne   $v0, $t2, .L7F02BFC8
   lw    $a0, 0x28($sp)
  jal   sub_GAME_7F023E14
   lui   $a1, 0x41d0
  b     .L7F02BFD4
   lw    $ra, 0x1c($sp)
.L7F02BFC8:
  jal   sub_GAME_7F023E48
   lw    $a0, 0x28($sp)
  lw    $ra, 0x1c($sp)
.L7F02BFD4:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02BFE4
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $a1, 0x44($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $a2, 0x48($sp)
  lw    $v1, 4($v0)
  lb    $a0, 0x80($v1)
  sw    $zero, 0x34($sp)
  jal   get_sound_trigger_rate
   sw    $v1, 0x38($sp)
  lw    $v1, 0x38($sp)
  sb    $v0, 0x33($sp)
  jal   sub_GAME_7F05E014
   lb    $a0, 0x80($v1)
  lw    $t6, 0x48($sp)
  lw    $a1, 0x34($sp)
  sh    $v0, 0x30($sp)
  beqz  $t6, .L7F02C07C
   lbu   $t7, 0x33($sp)
  blezl $t7, .L7F02C07C
   li    $a1, 1
  lhu   $t8, 0x12($s0)
  lw    $t0, 0x44($sp)
  lui   $t4, %hi(global_timer) 
  andi  $t9, $t8, 0x80
  bnez  $t9, .L7F02C07C
   sll   $t1, $t0, 2
  addu  $t2, $s0, $t1
  lw    $t3, 0x178($t2)
  lw    $t4, %lo(global_timer)($t4)
  slt   $at, $t3, $t4
  beqz  $at, .L7F02C07C
   nop   
  b     .L7F02C07C
   li    $a1, 1
  li    $a1, 1
.L7F02C07C:
  beqz  $a1, .L7F02C17C
   lw    $t5, 0x44($sp)
  sll   $t6, $t5, 3
  addu  $v1, $s0, $t6
  lw    $a0, 0x168($v1)
  beql  $a0, $zero, .L7F02C0BC
   lw    $a0, 0x16c($v1)
  jal   sfxGetArg0Unk3F
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F02C0B8
   lw    $v1, 0x28($sp)
  lw    $a0, 0x168($v1)
  jal   sfxDeactivate
   sw    $v1, 0x28($sp)
  lw    $v1, 0x28($sp)
.L7F02C0B8:
  lw    $a0, 0x16c($v1)
.L7F02C0BC:
  beql  $a0, $zero, .L7F02C0E8
   lhu   $t7, 0x30($sp)
  jal   sfxGetArg0Unk3F
   sw    $v1, 0x28($sp)
  beqz  $v0, .L7F02C0E4
   lw    $v1, 0x28($sp)
  lw    $a0, 0x16c($v1)
  jal   sfxDeactivate
   sw    $v1, 0x28($sp)
  lw    $v1, 0x28($sp)
.L7F02C0E4:
  lhu   $t7, 0x30($sp)
.L7F02C0E8:
  beql  $t7, $zero, .L7F02C180
   lw    $ra, 0x1c($sp)
  lw    $t8, 0x168($v1)
  move  $a2, $zero
  lui   $a0, %hi(ptr_sfx_buf)
  bnez  $t8, .L7F02C10C
   lh    $a1, 0x30($sp)
  b     .L7F02C11C
   addiu $a2, $v1, 0x168
.L7F02C10C:
  lw    $t9, 0x16c($v1)
  bnez  $t9, .L7F02C11C
   nop   
  addiu $a2, $v1, 0x16c
.L7F02C11C:
  beqz  $a2, .L7F02C17C
   lbu   $t0, 0x33($sp)
  lw    $t1, 0x44($sp)
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  sw    $t0, 0x28($sp)
  sll   $t2, $t1, 2
  addu  $t3, $s0, $t2
  sw    $t3, 0x24($sp)
  jal   play_sfx_a1
   sw    $a2, 0x2c($sp)
  lw    $a2, 0x2c($sp)
  lw    $a1, 0x18($s0)
  lw    $a0, ($a2)
  jal   sub_GAME_7F053A10
   addiu $a1, $a1, 8
  lui   $t4, %hi(global_timer) 
  lw    $t4, %lo(global_timer)($t4)
  lw    $t5, 0x28($sp)
  lw    $t7, 0x24($sp)
  addu  $t6, $t4, $t5
  sw    $t6, 0x178($t7)
  lhu   $t8, 0x12($s0)
  ori   $t9, $t8, 0x80
  sh    $t9, 0x12($s0)
.L7F02C17C:
  lw    $ra, 0x1c($sp)
.L7F02C180:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051E98
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02C190
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  move  $a1, $a0
  lw    $a0, 0x1c($a0)
  jal   getsubroty
   sw    $a1, 0x18($sp)
  lw    $a1, 0x18($sp)
  lui   $at, %hi(D_80051E98)
  lwc1  $f14, %lo(D_80051E98)($at)
  lwc1  $f4, 0x14c($a1)
  mtc1  $zero, $f16
  lw    $ra, 0x14($sp)
  add.s $f2, $f0, $f4
  addiu $sp, $sp, 0x18
  mov.s $f12, $f16
  c.le.s $f14, $f2
  nop   
  bc1fl .L7F02C1E8
   c.lt.s $f2, $f16
  b     .L7F02C1F8
   sub.s $f2, $f2, $f14
  c.lt.s $f2, $f16
.L7F02C1E8:
  nop   
  bc1fl .L7F02C1FC
   lb    $v0, 7($a1)
  add.s $f2, $f2, $f14
.L7F02C1F8:
  lb    $v0, 7($a1)
.L7F02C1FC:
  li    $at, 8
  beq   $v0, $at, .L7F02C210
   li    $at, 10
  bnel  $v0, $at, .L7F02C220
   li    $at, 25
.L7F02C210:
  lw    $t6, 0x2c($a1)
  b     .L7F02C238
   lwc1  $f12, 0xc($t6)
  li    $at, 25
.L7F02C220:
  bnel  $v0, $at, .L7F02C23C
   c.eq.s $f12, $f16
  lw    $v0, 0x2c($a1)
  beql  $v0, $zero, .L7F02C23C
   c.eq.s $f12, $f16
  lwc1  $f12, 0xc($v0)
.L7F02C238:
  c.eq.s $f12, $f16
.L7F02C23C:
  nop   
  bc1t  .L7F02C274
   nop   
  lw    $t7, 0x1c($a1)
  lb    $t8, 0x24($t7)
  beql  $t8, $zero, .L7F02C260
   add.s $f2, $f2, $f12
  sub.s $f12, $f14, $f12
  add.s $f2, $f2, $f12
.L7F02C260:
  c.le.s $f14, $f2
  nop   
  bc1f  .L7F02C274
   nop   
  sub.s $f2, $f2, $f14
.L7F02C274:
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
.late_rodata
glabel D_80051E9C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02C27C
  lwc1  $f4, 0x144($a0)
  lwc1  $f6, 0x148($a0)
  mtc1  $zero, $f8
  lui   $at, %hi(D_80051E9C)
  add.s $f2, $f4, $f6
  c.lt.s $f2, $f8
  nop   
  bc1f  .L7F02C2A8
   nop   
  lwc1  $f10, %lo(D_80051E9C)($at)
  add.s $f2, $f2, $f10
.L7F02C2A8:
  jr    $ra
   mov.s $f0, $f2
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051EA0
.word 0x3d80adfd /*0.062831856*/
glabel D_80051EA4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EA8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EAC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C2B0
  addiu $sp, $sp, -0x30
  sw    $a3, 0x3c($sp)
  li    $at, 2
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  beq   $a1, $at, .L7F02C4AC
   sw    $a2, 0x38($sp)
  lw    $a0, 0x1c($a0)
  sw    $a3, 0x30($sp)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x2c($sp)
  swc1  $f0, 0x28($sp)
  jal   getsubroty
   lw    $a0, 0x2c($sp)
  lui   $at, %hi(D_80051EA0)
  lwc1  $f4, %lo(D_80051EA0)($at)
  lwc1  $f6, 0x3c($sp)
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  lw    $t7, 0x2c($sp)
  lw    $a3, 0x30($sp)
  li    $at, 8
  lwc1  $f4, 0xa4($t7)
  lb    $v0, 7($a3)
  mov.s $f12, $f0
  mul.s $f18, $f8, $f10
  move  $a0, $a3
  mul.s $f14, $f18, $f4
  bnel  $v0, $at, .L7F02C358
   li    $at, 1
  lw    $a1, 0x4c($a3)
  lw    $a2, 0x50($a3)
  swc1  $f14, 0x18($sp)
  jal   sub_GAME_7F0250BC
   swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  b     .L7F02C3A4
   lwc1  $f14, 0x18($sp)
  li    $at, 1
.L7F02C358:
  bne   $v0, $at, .L7F02C380
   move  $a0, $a3
  lw    $a1, 0x30($a3)
  lw    $a2, 0x34($a3)
  swc1  $f14, 0x18($sp)
  jal   sub_GAME_7F0250BC
   swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  b     .L7F02C3A4
   lwc1  $f14, 0x18($sp)
.L7F02C380:
  sw    $a3, 0x30($sp)
  swc1  $f12, 0x20($sp)
  jal   get_curplayer_positiondata
   swc1  $f14, 0x18($sp)
  lw    $a0, 0x30($sp)
  jal   get_distance_actor_to_position
   addiu $a1, $v0, 8
  lwc1  $f12, 0x20($sp)
  lwc1  $f14, 0x18($sp)
.L7F02C3A4:
  lwc1  $f6, 0x40($sp)
  mtc1  $zero, $f16
  lui   $at, %hi(D_80051EA4)
  sub.s $f2, $f0, $f6
  c.lt.s $f2, $f16
  nop   
  bc1fl .L7F02C3D0
   c.lt.s $f2, $f14
  lwc1  $f0, %lo(D_80051EA4)($at)
  add.s $f2, $f2, $f0
  c.lt.s $f2, $f14
.L7F02C3D0:
  lui   $at, %hi(D_80051EA8)
  lwc1  $f0, %lo(D_80051EA8)($at)
  bc1tl .L7F02C3FC
   add.s $f12, $f12, $f2
  sub.s $f8, $f0, $f14
  lui   $at, %hi(D_80051EAC)
  c.lt.s $f8, $f2
  nop   
  bc1f  .L7F02C428
   nop   
  add.s $f12, $f12, $f2
.L7F02C3FC:
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F02C414
   mfc1  $a1, $f12
  sub.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C414:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
  li    $t8, 3
  b     .L7F02C48C
   sw    $t8, 0x34($sp)
.L7F02C428:
  lwc1  $f10, %lo(D_80051EAC)($at)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F02C46C
   sub.s $f12, $f12, $f14
  add.s $f12, $f12, $f14
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F02C458
   mfc1  $a1, $f12
  sub.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C458:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
  b     .L7F02C490
   lwc1  $f18, 0x28($sp)
  sub.s $f12, $f12, $f14
.L7F02C46C:
  c.lt.s $f12, $f16
  nop   
  bc1fl .L7F02C484
   mfc1  $a1, $f12
  add.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C484:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
.L7F02C48C:
  lwc1  $f18, 0x28($sp)
.L7F02C490:
  lwc1  $f4, 0x38($sp)
  li    $t9, 2
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F02C4B0
   lw    $ra, 0x14($sp)
  sw    $t9, 0x34($sp)
.L7F02C4AC:
  lw    $ra, 0x14($sp)
.L7F02C4B0:
  lw    $v0, 0x34($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");
#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051EA0
.word 0x3d80adfd /*0.062831856*/
glabel D_80051EA4
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EA8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051EAC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C2B0
  addiu $sp, $sp, -0x30
  sw    $a3, 0x3c($sp)
  li    $at, 2
  move  $a3, $a0
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  sw    $a1, 0x34($sp)
  beq   $a1, $at, .L7F02C4AC
   sw    $a2, 0x38($sp)
  lw    $a0, 0x1c($a0)
  sw    $a3, 0x30($sp)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x2c($sp)
  swc1  $f0, 0x28($sp)
  jal   getsubroty
   lw    $a0, 0x2c($sp)
  lui   $at, %hi(D_80051EA0)
  lwc1  $f4, %lo(D_80051EA0)($at)
  lwc1  $f6, 0x3c($sp)
  lui   $at, %hi(jp_global_timer_delta)
  lwc1  $f10, %lo(jp_global_timer_delta)($at)
  mul.s $f8, $f4, $f6
  lw    $t7, 0x2c($sp)
  lw    $a3, 0x30($sp)
  li    $at, 8
  lwc1  $f4, 0xa4($t7)
  lb    $v0, 7($a3)
  mov.s $f12, $f0
  mul.s $f18, $f8, $f10
  move  $a0, $a3
  mul.s $f14, $f18, $f4
  bnel  $v0, $at, .L7F02C358
   li    $at, 1
  lw    $a1, 0x4c($a3)
  lw    $a2, 0x50($a3)
  swc1  $f14, 0x18($sp)
  jal   sub_GAME_7F0250BC
   swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  b     .L7F02C3A4
   lwc1  $f14, 0x18($sp)
  li    $at, 1
.L7F02C358:
  bne   $v0, $at, .L7F02C380
   move  $a0, $a3
  lw    $a1, 0x30($a3)
  lw    $a2, 0x34($a3)
  swc1  $f14, 0x18($sp)
  jal   sub_GAME_7F0250BC
   swc1  $f12, 0x20($sp)
  lwc1  $f12, 0x20($sp)
  b     .L7F02C3A4
   lwc1  $f14, 0x18($sp)
.L7F02C380:
  sw    $a3, 0x30($sp)
  swc1  $f12, 0x20($sp)
  jal   get_curplayer_positiondata
   swc1  $f14, 0x18($sp)
  lw    $a0, 0x30($sp)
  jal   get_distance_actor_to_position
   addiu $a1, $v0, 8
  lwc1  $f12, 0x20($sp)
  lwc1  $f14, 0x18($sp)
.L7F02C3A4:
  lwc1  $f6, 0x40($sp)
  mtc1  $zero, $f16
  lui   $at, %hi(D_80051EA4)
  sub.s $f2, $f0, $f6
  c.lt.s $f2, $f16
  nop   
  bc1fl .L7F02C3D0
   c.lt.s $f2, $f14
  lwc1  $f0, %lo(D_80051EA4)($at)
  add.s $f2, $f2, $f0
  c.lt.s $f2, $f14
.L7F02C3D0:
  lui   $at, %hi(D_80051EA8)
  lwc1  $f0, %lo(D_80051EA8)($at)
  bc1tl .L7F02C3FC
   add.s $f12, $f12, $f2
  sub.s $f8, $f0, $f14
  lui   $at, %hi(D_80051EAC)
  c.lt.s $f8, $f2
  nop   
  bc1f  .L7F02C428
   nop   
  add.s $f12, $f12, $f2
.L7F02C3FC:
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F02C414
   mfc1  $a1, $f12
  sub.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C414:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
  li    $t8, 3
  b     .L7F02C48C
   sw    $t8, 0x34($sp)
.L7F02C428:
  lwc1  $f10, %lo(D_80051EAC)($at)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F02C46C
   sub.s $f12, $f12, $f14
  add.s $f12, $f12, $f14
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F02C458
   mfc1  $a1, $f12
  sub.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C458:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
  b     .L7F02C490
   lwc1  $f18, 0x28($sp)
  sub.s $f12, $f12, $f14
.L7F02C46C:
  c.lt.s $f12, $f16
  nop   
  bc1fl .L7F02C484
   mfc1  $a1, $f12
  add.s $f12, $f12, $f0
  mfc1  $a1, $f12
.L7F02C484:
  jal   setsubroty
   lw    $a0, 0x2c($sp)
.L7F02C48C:
  lwc1  $f18, 0x28($sp)
.L7F02C490:
  lwc1  $f4, 0x38($sp)
  li    $t9, 2
  c.le.s $f4, $f18
  nop   
  bc1fl .L7F02C4B0
   lw    $ra, 0x14($sp)
  sw    $t9, 0x34($sp)
.L7F02C4AC:
  lw    $ra, 0x14($sp)
.L7F02C4B0:
  lw    $v0, 0x34($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");
#endif
#endif

asm(R"
.late_rodata
glabel D_80051EB0
.word 0x481c4000 /*160000.0*/
glabel D_80051EB4
.word 0x3dcccccd /*0.1*/
glabel D_80051EB8
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EBC
.word 0x3dcccccd /*0.1*/
glabel D_80051EC0
.word 0x3e19999a /*0.15000001*/
glabel D_80051EC4
.word 0x3dcccccd /*0.1*/
glabel D_80051EC8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051ECC
.word 0x3ccccccd /*0.025*/
glabel D_80051ED0
.word 0x49742400 /*1000000.0*/
glabel D_80051ED4
.word 0x3dcccccd /*0.1*/
glabel D_80051ED8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EDC
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EE0
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EE4
.word 0x3dcccccd /*0.1*/
glabel D_80051EE8
.word 0x3f0ccccd /*0.55000001*/
glabel D_80051EEC
.word 0x3dcccccd /*0.1*/
glabel D_80051EF0
.word 0x3e19999a /*0.15000001*/
glabel D_80051EF4
.word 0x3dcccccd /*0.1*/
glabel D_80051EF8
.word 0x3d4ccccd /*0.050000001*/
glabel D_80051EFC
.word 0x40490fdb /*3.1415927*/
glabel D_80051F00
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F04
.word 0x49742400 /*1000000.0*/
glabel D_80051F08
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F0C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F10
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F14
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F18
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F1C
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F20
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F24
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F28
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F02C4C0
  addiu $sp, $sp, -0x168
  mtc1  $zero, $f16
  li    $t6, 1
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x16c($sp)
  sw    $a2, 0x170($sp)
  sw    $a3, 0x174($sp)
  sw    $t6, 0x154($sp)
  swc1  $f16, 0x164($sp)
  lb    $v0, 7($a0)
  li    $at, 8
  li    $t0, 1
  bne   $v0, $at, .L7F02C504
   move  $v1, $zero
  lw    $t0, 0x4c($a0)
  b     .L7F02C518
   lw    $v1, 0x50($a0)
.L7F02C504:
  li    $at, 1
  bnel  $v0, $at, .L7F02C51C
   andi  $t7, $t0, 2
  lw    $t0, 0x30($a0)
  lw    $v1, 0x34($a0)
.L7F02C518:
  andi  $t7, $t0, 2
.L7F02C51C:
  bnez  $t7, .L7F02D000
   sw    $a0, 0x168($sp)
  sw    $v1, 0x158($sp)
  sw    $a0, 0x168($sp)
  sw    $t0, 0x15c($sp)
  jal   get_curplayer_positiondata
   swc1  $f16, 0x160($sp)
  lw    $a2, 0x168($sp)
  addiu $t9, $v0, 8
  lw    $t2, 0x15c($sp)
  lw    $t8, 0x18($a2)
  sw    $t9, 0x134($sp)
  andi  $t3, $t2, 1
  sw    $t8, 0x13c($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f6, 8($t8)
  lwc1  $f16, 0x160($sp)
  li    $t6, 1
  sub.s $f8, $f4, $f6
  andi  $t4, $t2, 0x40
  swc1  $f8, 0x150($sp)
  lwc1  $f10, 0xc($v0)
  lwc1  $f18, 0xc($t8)
  sub.s $f4, $f10, $f18
  lwc1  $f18, 0x150($sp)
  swc1  $f4, 0x14c($sp)
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x10($t8)
  mul.s $f4, $f18, $f18
  sw    $t3, 0x28($sp)
  sub.s $f10, $f6, $f8
  lwc1  $f6, 0x14c($sp)
  mul.s $f8, $f6, $f6
  swc1  $f10, 0x148($sp)
  lwc1  $f18, 0x148($sp)
  mul.s $f6, $f18, $f18
  add.s $f10, $f4, $f8
  add.s $f2, $f10, $f6
  beqz  $t3, .L7F02C5F0
   swc1  $f2, 0x144($sp)
  beqz  $t4, .L7F02C5D0
   move  $a0, $a2
  li    $t5, 1
  b     .L7F02C5F4
   sw    $t5, 0x138($sp)
.L7F02C5D0:
  swc1  $f2, 0x2c($sp)
  jal   sub_GAME_7F0294BC
   swc1  $f16, 0x160($sp)
  lwc1  $f2, 0x2c($sp)
  lwc1  $f16, 0x160($sp)
  sw    $v0, 0x138($sp)
  b     .L7F02C5F4
   lw    $a2, 0x168($sp)
.L7F02C5F0:
  sw    $t6, 0x138($sp)
.L7F02C5F4:
  lw    $t7, 0x28($sp)
  lui   $a0, %hi(pPlayer)
  addiu $a1, $sp, 0x120
  beql  $t7, $zero, .L7F02CAE0
   lw    $a0, 0x1c($a2)
  lw    $a0, %lo(pPlayer)($a0)
  swc1  $f2, 0x2c($sp)
  jal   sub_GAME_7F089780
   swc1  $f16, 0x160($sp)
  lw    $t8, 0x168($sp)
  swc1  $f0, 0x130($sp)
  lwc1  $f2, 0x2c($sp)
  lw    $t9, 0x14($t8)
  lwc1  $f16, 0x160($sp)
  lui   $at, %hi(D_80051EB0)
  andi  $t1, $t9, 0x20
  beqz  $t1, .L7F02C84C
   nop   
  lui   $at, %hi(D_80051EB0)
  lwc1  $f4, %lo(D_80051EB0)($at)
  lw    $t2, 0x134($sp)
  c.lt.s $f2, $f4
  nop   
  bc1f  .L7F02C7E0
   nop   
  add.s $f8, $f0, $f0
  lwc1  $f12, 4($t2)
  lw    $t3, 0x13c($sp)
  li    $at, 0x3F000000 # 0.500000
  sub.s $f18, $f12, $f8
  lwc1  $f2, 0xc($t3)
  c.lt.s $f2, $f18
  nop   
  bc1fl .L7F02C6F0
   mtc1  $at, $f4
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f10
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C6A8
   cvt.s.w $f6, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f6, $f6, $f4
.L7F02C6A8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051EB4)
  lwc1  $f10, %lo(D_80051EB4)($at)
  mul.s $f18, $f6, $f8
  lwc1  $f6, 0x178($sp)
  lui    $at, %hi(D_80051EB8)
  mul.s $f4, $f10, $f18
  lwc1  $f10, %lo(D_80051EB8)($at)
  mul.s $f8, $f4, $f6
  lwc1  $f4, 0x130($sp)
  add.s $f18, $f10, $f8
  lwc1  $f10, 0x14c($sp)
  mul.s $f6, $f4, $f18
  sub.s $f8, $f10, $f6
  b     .L7F02CB34
   swc1  $f8, 0x14c($sp)
  mtc1  $at, $f4
.L7F02C6F0:
  nop   
  mul.s $f18, $f0, $f4
  sub.s $f10, $f12, $f18
  c.lt.s $f10, $f2
  nop   
  bc1f  .L7F02C778
   nop   
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f6
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C734
   cvt.s.w $f8, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F02C734:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f18
  lui   $at, %hi(D_80051EBC)
  lwc1  $f6, %lo(D_80051EBC)($at)
  mul.s $f10, $f8, $f18
  lwc1  $f8, 0x178($sp)
  lui   $at, %hi(D_80051EC0)
  mul.s $f4, $f6, $f10
  lwc1  $f6, %lo(D_80051EC0)($at)
  mul.s $f18, $f4, $f8
  lwc1  $f4, 0x130($sp)
  add.s $f10, $f6, $f18
  lwc1  $f6, 0x14c($sp)
  mul.s $f8, $f4, $f10
  sub.s $f18, $f6, $f8
  b     .L7F02CB34
   swc1  $f18, 0x14c($sp)
.L7F02C778:
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f4
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C7A0
   cvt.s.w $f10, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L7F02C7A0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051EC4)
  lwc1  $f4, %lo(D_80051EC4)($at)
  mul.s $f18, $f10, $f8
  lwc1  $f10, 0x178($sp)
  li    $at, 0x3F800000 # 1.000000
  mul.s $f6, $f18, $f4
  mtc1  $at, $f18
  li    $at, 0x42200000 # 40.000000
  mul.s $f8, $f6, $f10
  mtc1  $at, $f6
  add.s $f4, $f8, $f18
  mul.s $f10, $f4, $f6
  b     .L7F02CB34
   swc1  $f10, 0x14c($sp)
.L7F02C7E0:
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f8
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C808
   cvt.s.w $f18, $f8
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F02C808:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80051EC8)
  lwc1  $f8, %lo(D_80051EC8)($at)
  mul.s $f10, $f18, $f6
  lwc1  $f18, 0x178($sp)
  lui   $at, %hi(D_80051ED0)
  mul.s $f4, $f8, $f10
  lwc1  $f8, %lo(D_80051ECC)($at)
  mul.s $f6, $f4, $f18
  lwc1  $f4, 0x130($sp)
  sub.s $f10, $f8, $f6
  lwc1  $f8, 0x14c($sp)
  mul.s $f18, $f4, $f10
  add.s $f6, $f8, $f18
  b     .L7F02CB34
   swc1  $f6, 0x14c($sp)
.L7F02C84C:
  lwc1  $f4, %lo(D_80051ED0)($at)
  lw    $t6, 0x134($sp)
  c.lt.s $f4, $f2
  nop   
  bc1fl .L7F02C960
   lwc1  $f12, 4($t6)
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  li    $at, 3
  divu  $zero, $v0, $at
  mfhi  $t4
  lwc1  $f16, 0x160($sp)
  bnez  $t4, .L7F02C8F0
   nop   
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f10
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C8AC
   cvt.s.w $f8, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f8, $f8, $f18
.L7F02C8AC:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f6
  lui   $at, %hi(D_80051ED4)
  lwc1  $f10, %lo(D_80051ED4)($at)
  mul.s $f4, $f8, $f6
  lwc1  $f8, 0x178($sp)
  lui   $at, %hi(D_80051ED8)
  mul.s $f18, $f10, $f4
  lwc1  $f10, %lo(D_80051ED8)($at)
  mul.s $f6, $f18, $f8
  lwc1  $f18, 0x130($sp)
  add.s $f4, $f10, $f6
  lwc1  $f10, 0x14c($sp)
  mul.s $f8, $f18, $f4
  add.s $f6, $f10, $f8
  b     .L7F02CB34
   swc1  $f6, 0x14c($sp)
.L7F02C8F0:
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f18
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C918
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f10
  nop   
  add.s $f4, $f4, $f10
.L7F02C918:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051EDC)
  lwc1  $f18, %lo(D_80051EDC)($at)
  mul.s $f6, $f4, $f8
  lwc1  $f4, 0x178($sp)
  lui   $at, %hi(D_80051EE0)
  mul.s $f10, $f18, $f6
  lwc1  $f18, %lo(D_80051EE0)($at)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 0x130($sp)
  add.s $f6, $f18, $f8
  lwc1  $f18, 0x14c($sp)
  mul.s $f4, $f10, $f6
  sub.s $f8, $f18, $f4
  b     .L7F02CB34
   swc1  $f8, 0x14c($sp)
  lwc1  $f12, 4($t6)
.L7F02C960:
  lw    $t5, 0x13c($sp)
  li    $at, 0x3F000000 # 0.500000
  sub.s $f10, $f12, $f0
  lwc1  $f2, 0xc($t5)
  c.lt.s $f2, $f10
  nop   
  bc1fl .L7F02C9F0
   mtc1  $at, $f4
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f6
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02C9A8
   cvt.s.w $f18, $f6
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L7F02C9A8:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051EE4)
  lwc1  $f6, %lo(D_80051EE4)($at)
  mul.s $f10, $f18, $f8
  lwc1  $f18, 0x178($sp)
  lui    $at, %hi(D_80051EE8)
  mul.s $f4, $f6, $f10
  lwc1  $f6, %lo(D_80051EE8)($at)
  mul.s $f8, $f4, $f18
  lwc1  $f4, 0x130($sp)
  add.s $f10, $f6, $f8
  lwc1  $f6, 0x14c($sp)
  mul.s $f18, $f4, $f10
  sub.s $f8, $f6, $f18
  b     .L7F02CB34
   swc1  $f8, 0x14c($sp)
  mtc1  $at, $f4
.L7F02C9F0:
  nop   
  mul.s $f10, $f0, $f4
  sub.s $f6, $f12, $f10
  c.lt.s $f6, $f2
  nop   
  bc1f  .L7F02CA78
   nop   
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f18
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02CA34
   cvt.s.w $f8, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f8, $f8, $f4
.L7F02CA34:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80051EEC)
  lwc1  $f18, %lo(D_80051EEC)($at)
  mul.s $f6, $f8, $f10
  lwc1  $f8, 0x178($sp)
  lui   $at, %hi(D_80051EF0)
  mul.s $f4, $f18, $f6
  lwc1  $f18, %lo(D_80051EF0)($at)
  mul.s $f10, $f4, $f8
  lwc1  $f4, 0x130($sp)
  add.s $f6, $f18, $f10
  lwc1  $f18, 0x14c($sp)
  mul.s $f8, $f4, $f6
  sub.s $f10, $f18, $f8
  b     .L7F02CB34
   swc1  $f10, 0x14c($sp)
.L7F02CA78:
  jal   get_random_value
   swc1  $f16, 0x160($sp)
  mtc1  $v0, $f4
  lwc1  $f16, 0x160($sp)
  bgez  $v0, .L7F02CAA0
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f18
  nop   
  add.s $f6, $f6, $f18
.L7F02CAA0:
  li    $at, 0x2F800000 # 0.000000
  mtc1  $at, $f8
  lui   $at, %hi(D_80051EF4)
  lwc1  $f4, %lo(D_80051EF4)($at)
  mul.s $f10, $f6, $f8
  lwc1  $f6, 0x178($sp)
  lui   $at, %hi(D_80051EF8)
  mul.s $f18, $f10, $f4
  lwc1  $f10, %lo(D_80051EF8)($at)
  mul.s $f8, $f18, $f6
  lwc1  $f18, 0x130($sp)
  sub.s $f4, $f8, $f10
  mul.s $f6, $f4, $f18
  b     .L7F02CB34
   swc1  $f6, 0x14c($sp)
  lw    $a0, 0x1c($a2)
.L7F02CAE0:
  jal   getsuboffset
   swc1  $f16, 0x160($sp)
  lw    $a0, 0x168($sp)
  lw    $a1, 0x15c($sp)
  lw    $a2, 0x158($sp)
  jal   sub_GAME_7F032C78
   addiu $a3, $sp, 0x12c
  sw    $v0, 0x134($sp)
  lwc1  $f8, ($v0)
  lwc1  $f10, 0x120($sp)
  lwc1  $f6, 0x124($sp)
  lwc1  $f16, 0x160($sp)
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x150($sp)
  lwc1  $f18, 4($v0)
  lwc1  $f4, 0x128($sp)
  sub.s $f8, $f18, $f6
  swc1  $f8, 0x14c($sp)
  lwc1  $f10, 8($v0)
  sub.s $f18, $f10, $f4
  swc1  $f18, 0x148($sp)
.L7F02CB34:
  lw    $t7, 0x15c($sp)
  lwc1  $f6, 0x150($sp)
  lwc1  $f10, 0x148($sp)
  andi  $t8, $t7, 0x100
  bnezl $t8, .L7F02CB9C
   lw    $t9, 0x138($sp)
  mul.s $f8, $f6, $f6
  swc1  $f16, 0x160($sp)
  mul.s $f4, $f10, $f10
  jal   sqrtf
   add.s $f12, $f8, $f4
  lwc1  $f12, 0x14c($sp)
  jal   convert_angle_using_inverse
   mov.s $f14, $f0
  lui   $at, %hi(D_80051EFC)
  lwc1  $f18, %lo(D_80051EFC)($at)
  lwc1  $f16, 0x160($sp)
  swc1  $f0, 0x164($sp)
  c.le.s $f18, $f0
  lui   $at, %hi(D_80051F00)
  bc1fl .L7F02CB9C
   lw    $t9, 0x138($sp)
  lwc1  $f6, %lo(D_80051F00)($at)
  sub.s $f10, $f0, $f6
  swc1  $f10, 0x164($sp)
  lw    $t9, 0x138($sp)
.L7F02CB9C:
  beql  $t9, $zero, .L7F02D004
   lwc1  $f6, 0x164($sp)
  jal   sub_GAME_7F02C190
   lw    $a0, 0x168($sp)
  lw    $t1, 0x174($sp)
  swc1  $f0, 0x118($sp)
  move  $a1, $zero
  beqz  $t1, .L7F02CBD0
   lw    $a0, 0x168($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   lw    $a0, 0x168($sp)
  b     .L7F02CBD8
   nop   
.L7F02CBD0:
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
.L7F02CBD8:
  beql  $v0, $zero, .L7F02CDB0
   lwc1  $f12, 0x150($sp)
  lbu   $t3, 1($v0)
  lwc1  $f8, 0x144($sp)
  lui   $at, %hi(D_80051F04)
  andi  $t2, $t3, 2
  beql  $t2, $zero, .L7F02CDB0
   lwc1  $f12, 0x150($sp)
  lwc1  $f4, %lo(D_80051F04)($at)
  c.lt.s $f8, $f4
  nop   
  bc1fl .L7F02CDB0
   lwc1  $f12, 0x150($sp)
  lw    $v1, 4($v0)
  move  $a0, $zero
  move  $a2, $zero
  lw    $a3, 0x14($v1)
  lw    $t4, 8($a3)
  lw    $a1, 8($t4)
  lw    $t5, ($a1)
  beqz  $t5, .L7F02CCC0
   sw    $t5, 0x24($sp)
  move  $a0, $a3
  move  $a1, $t5
  jal   sub_GAME_7F06C660
   sw    $a3, 0x110($sp)
  lw    $a3, 0x110($sp)
  move  $a0, $v0
  addiu $a1, $sp, 0xbc
  lw    $t7, 8($a3)
  lw    $t8, 8($t7)
  lw    $t9, ($t8)
  lw    $t1, 4($t9)
  jal   sub_GAME_7F058E78
   sw    $t1, 0xb8($sp)
  jal   sub_GAME_7F078454
   nop   
  move  $a0, $v0
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0xbc
  lw    $v0, 0xb8($sp)
  addiu $a0, $sp, 0xbc
  addiu $a1, $sp, 0xac
  lwc1  $f18, ($v0)
  swc1  $f18, 0xac($sp)
  lwc1  $f6, 4($v0)
  swc1  $f6, 0xb0($sp)
  lwc1  $f10, 8($v0)
  jal   sub_GAME_7F058474
   swc1  $f10, 0xb4($sp)
  lwc1  $f8, 0xac($sp)
  lwc1  $f4, 0xb0($sp)
  lwc1  $f18, 0xb4($sp)
  li    $a0, 1
  swc1  $f8, 0x104($sp)
  swc1  $f4, 0x108($sp)
  b     .L7F02CD18
   swc1  $f18, 0x10c($sp)
.L7F02CCC0:
  lw    $t3, 4($a1)
  move  $a2, $zero
  beqz  $t3, .L7F02CD18
   sw    $t3, 0x24($sp)
  move  $a0, $a3
  jal   sub_GAME_7F06C660
   move  $a1, $t3
  move  $a0, $v0
  jal   sub_GAME_7F058E78
   addiu $a1, $sp, 0x68
  jal   sub_GAME_7F078454
   nop   
  move  $a0, $v0
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x68
  lwc1  $f6, 0x98($sp)
  lwc1  $f10, 0x9c($sp)
  lwc1  $f8, 0xa0($sp)
  li    $a0, 1
  swc1  $f6, 0x104($sp)
  swc1  $f10, 0x108($sp)
  swc1  $f8, 0x10c($sp)
.L7F02CD18:
  beql  $a0, $zero, .L7F02CDB0
   lwc1  $f12, 0x150($sp)
  jal   sinf
   lwc1  $f12, 0x118($sp)
  mtc1  $zero, $f4
  swc1  $f0, 0x50($sp)
  lwc1  $f12, 0x118($sp)
  jal   cosf
   swc1  $f4, 0x54($sp)
  lw    $t4, 0x13c($sp)
  swc1  $f0, 0x58($sp)
  lwc1  $f6, 0x148($sp)
  lwc1  $f18, 8($t4)
  addiu $t5, $sp, 0x5c
  addiu $a1, $sp, 0x44
  sub.s $f10, $f18, $f6
  lwc1  $f18, 0x150($sp)
  addiu $a2, $sp, 0x104
  addiu $a3, $sp, 0x50
  swc1  $f10, 0x44($sp)
  lwc1  $f8, 0xc($t4)
  addiu $a0, $t4, 8
  swc1  $f8, 0x48($sp)
  lwc1  $f4, 0x10($t4)
  sw    $t5, 0x10($sp)
  add.s $f6, $f4, $f18
  jal   sub_GAME_7F026130
   swc1  $f6, 0x4c($sp)
  lw    $t6, 0x134($sp)
  lwc1  $f8, 0x5c($sp)
  lwc1  $f6, 0x64($sp)
  lwc1  $f10, ($t6)
  sub.s $f4, $f10, $f8
  swc1  $f4, 0x150($sp)
  lwc1  $f18, 8($t6)
  sub.s $f10, $f18, $f6
  swc1  $f10, 0x148($sp)
  lwc1  $f12, 0x150($sp)
.L7F02CDB0:
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x148($sp)
  lwc1  $f8, 0x118($sp)
  lui   $at, %hi(D_80051F08)
  lw    $t7, 0x168($sp)
  c.lt.s $f0, $f8
  sub.s $f2, $f0, $f8
  bc1f  .L7F02CDDC
   mov.s $f16, $f2
  lwc1  $f4, %lo(D_80051F08)($at)
  add.s $f16, $f2, $f4
.L7F02CDDC:
  lw    $a0, 0x1c($t7)
  lw    $t8, 8($a0)
  lw    $a1, ($t8)
  jal   extract_id_from_object_structure_microcode
   swc1  $f16, 0x160($sp)
  mtc1  $zero, $f2
  lwc1  $f0, 0x5c($v0)
  lw    $t1, 0x15c($sp)
  lwc1  $f16, 0x160($sp)
  c.lt.s $f2, $f0
  lw    $t9, 0x28($sp)
  andi  $t3, $t1, 0x60
  bc1f  .L7F02CE58
   nop   
  lwc1  $f18, 0x58($v0)
  lui   $at, %hi(D_80051F0C)
  mul.s $f6, $f0, $f18
  sub.s $f16, $f16, $f6
  c.lt.s $f16, $f2
  nop   
  bc1f  .L7F02CE3C
   nop   
  lwc1  $f0, %lo(D_80051F0C)($at)
  add.s $f16, $f16, $f0
.L7F02CE3C:
  lui   $at, %hi(D_80051F10)
  lwc1  $f0, %lo(D_80051F10)($at)
  c.le.s $f0, $f16
  nop   
  bc1f  .L7F02CE58
   nop   
  sub.s $f16, $f16, $f0
.L7F02CE58:
  lui   $at, %hi(D_80051F14)
  beqz  $t9, .L7F02CF34
   lwc1  $f0, %lo(D_80051F14)($at)
  bnez  $t3, .L7F02CF34
   lui   $t2, %hi(global_timer) 
  lw    $t2, %lo(global_timer)($t2)
  lw    $t4, 0x168($sp)
  li    $at, 60
  mtc1  $t2, $f10
  lw    $t5, 0x1c($t4)
  lh    $t8, ($t4)
  cvt.s.w $f8, $f10
  lwc1  $f4, 0xa4($t5)
  swc1  $f16, 0x160($sp)
  mul.s $f18, $f8, $f4
  trunc.w.s $f6, $f18
  mfc1  $t7, $f6
  nop   
  addu  $t9, $t7, $t8
  div   $zero, $t9, $at
  mfhi  $t1
  mtc1  $t1, $f10
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f18
  cvt.s.w $f8, $f10
  mul.s $f4, $f8, $f0
  jal   sinf
   div.s $f12, $f4, $f18
  swc1  $f0, 0x30($sp)
  jal   sub_GAME_7F02D244
   lwc1  $f12, 0x144($sp)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  lwc1  $f8, 0x30($sp)
  lwc1  $f16, 0x160($sp)
  mul.s $f10, $f0, $f6
  mtc1  $zero, $f18
  lui   $at, %hi(D_80051F18)
  mul.s $f4, $f10, $f8
  add.s $f16, $f16, $f4
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F02CF10
   nop   
  lwc1  $f6, %lo(D_80051F18)($at)
  add.s $f16, $f16, $f6
.L7F02CF10:
  lui   $at, %hi(D_80051F1C)
  lwc1  $f10, %lo(D_80051F1C)($at)
  lui   $at, %hi(D_80051F20)
  c.le.s $f10, $f16
  nop   
  bc1f  .L7F02CF34
   nop   
  lwc1  $f8, %lo(D_80051F20)($at)
  sub.s $f16, $f16, $f8
.L7F02CF34:
  lui   $at, %hi(D_80051F24)
  lwc1  $f0, %lo(D_80051F24)($at)
  lui   $at, %hi(D_80051F28)
  lwc1  $f4, %lo(D_80051F28)($at)
  lw    $t3, 0x168($sp)
  lw    $v0, 0x16c($sp)
  c.le.s $f4, $f16
  nop   
  bc1fl .L7F02CF64
   lw    $t2, 0x1c($t3)
  sub.s $f16, $f16, $f0
  lw    $t2, 0x1c($t3)
.L7F02CF64:
  lwc1  $f18, 0x14c($t3)
  lb    $t5, 0x24($t2)
  add.s $f16, $f16, $f18
  beql  $t5, $zero, .L7F02CFC8
   lwc1  $f0, 0x38($v0)
  lw    $v0, 0x16c($sp)
  lwc1  $f0, 0x38($v0)
  neg.s $f0, $f0
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F02CFA4
   lwc1  $f0, 0x3c($v0)
  mov.s $f16, $f0
  b     .L7F02D000
   sw    $zero, 0x154($sp)
  lwc1  $f0, 0x3c($v0)
.L7F02CFA4:
  neg.s $f0, $f0
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F02D004
   lwc1  $f6, 0x164($sp)
  mov.s $f16, $f0
  b     .L7F02D000
   sw    $zero, 0x154($sp)
  lwc1  $f0, 0x38($v0)
.L7F02CFC8:
  c.lt.s $f0, $f16
  nop   
  bc1fl .L7F02CFE8
   lwc1  $f0, 0x3c($v0)
  mov.s $f16, $f0
  b     .L7F02D000
   sw    $zero, 0x154($sp)
  lwc1  $f0, 0x3c($v0)
.L7F02CFE8:
  c.lt.s $f16, $f0
  nop   
  bc1fl .L7F02D004
   lwc1  $f6, 0x164($sp)
  mov.s $f16, $f0
  sw    $zero, 0x154($sp)
.L7F02D000:
  lwc1  $f6, 0x164($sp)
.L7F02D004:
  lw    $a0, 0x168($sp)
  lw    $a1, 0x16c($sp)
  lw    $a2, 0x170($sp)
  lw    $a3, 0x174($sp)
  swc1  $f16, 0x160($sp)
  jal   sub_GAME_7F02D048
   swc1  $f6, 0x10($sp)
  lw    $t6, 0x168($sp)
  lwc1  $f16, 0x160($sp)
  li    $t4, 10
  sb    $t4, 0xe($t6)
  swc1  $f16, 0x15c($t6)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x154($sp)
  addiu $sp, $sp, 0x168
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02D048
  mtc1  $zero, $f16
  lwc1  $f14, 0x10($sp)
  mov.s $f0, $f16
  mov.s $f2, $f16
  beqz  $a1, .L7F02D0C8
   mov.s $f12, $f14
  lwc1  $f0, 0x30($a1)
  c.lt.s $f0, $f14
  nop   
  bc1fl .L7F02D084
   lwc1  $f0, 0x34($a1)
  sub.s $f2, $f14, $f0
  b     .L7F02D09C
   mov.s $f12, $f0
  lwc1  $f0, 0x34($a1)
.L7F02D084:
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F02D0A0
   c.lt.s $f16, $f12
  sub.s $f2, $f14, $f0
  mov.s $f12, $f0
.L7F02D09C:
  c.lt.s $f16, $f12
.L7F02D0A0:
  nop   
  bc1fl .L7F02D0C0
   lwc1  $f6, 0x44($a1)
  lwc1  $f4, 0x40($a1)
  mul.s $f0, $f4, $f12
  b     .L7F02D0C8
   nop   
  lwc1  $f6, 0x44($a1)
.L7F02D0C0:
  mul.s $f0, $f6, $f12
  nop   
.L7F02D0C8:
  beql  $a3, $zero, .L7F02D0EC
   swc1  $f0, 0x154($a0)
  beqz  $a2, .L7F02D0E0
   swc1  $f12, 0x154($a0)
  b     .L7F02D0F0
   swc1  $f12, 0x150($a0)
.L7F02D0E0:
  b     .L7F02D0F0
   swc1  $f0, 0x150($a0)
  swc1  $f0, 0x154($a0)
.L7F02D0EC:
  swc1  $f12, 0x150($a0)
.L7F02D0F0:
  jr    $ra
   swc1  $f2, 0x158($a0)
");

asm(R"
glabel sub_GAME_7F02D0F8
  mtc1  $zero, $f0
  li    $t6, 10
  sb    $t6, 0xe($a0)
  swc1  $f0, 0x154($a0)
  swc1  $f0, 0x150($a0)
  swc1  $f0, 0x158($a0)
  jr    $ra
   swc1  $f0, 0x15c($a0)
");

asm(R"
glabel sub_GAME_7F02D118
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F02D138
   move  $a0, $v0
  jal   sub_GAME_7F052574
   lw    $a1, 0x20($sp)
.L7F02D138:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02D148
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   nop   
  beqz  $v0, .L7F02D170
   move  $a0, $v0
  jal   sub_GAME_7F052604
   nop   
  b     .L7F02D178
   lw    $ra, 0x14($sp)
.L7F02D170:
  move  $v0, $zero
  lw    $ra, 0x14($sp)
.L7F02D178:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02D184
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  move  $a1, $zero
  jal   sub_GAME_7F02D118
   move  $a2, $zero
  lw    $a0, 0x18($sp)
  li    $a1, 1
  jal   sub_GAME_7F02D118
   move  $a2, $zero
  jal   sub_GAME_7F02D0F8
   lw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02D1C4
  addiu $sp, $sp, -0x18
  beqz  $a2, .L7F02D1FC
   sw    $ra, 0x14($sp)
  li    $at, 1
  bnel  $a1, $at, .L7F02D1F0
   lhu   $t8, 0x12($a0)
  lhu   $t6, 0x12($a0)
  ori   $t7, $t6, 4
  b     .L7F02D224
   sh    $t7, 0x12($a0)
  lhu   $t8, 0x12($a0)
.L7F02D1F0:
  ori   $t9, $t8, 8
  b     .L7F02D224
   sh    $t9, 0x12($a0)
.L7F02D1FC:
  li    $at, 1
  bnel  $a1, $at, .L7F02D21C
   lhu   $t2, 0x12($a0)
  lhu   $t0, 0x12($a0)
  andi  $t1, $t0, 0xfffb
  b     .L7F02D224
   sh    $t1, 0x12($a0)
  lhu   $t2, 0x12($a0)
.L7F02D21C:
  andi  $t3, $t2, 0xfff7
  sh    $t3, 0x12($a0)
.L7F02D224:
  bnezl $a2, .L7F02D238
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F02D118
   move  $a2, $zero
  lw    $ra, 0x14($sp)
.L7F02D238:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80051F2C
.word 0x4a1c4000 /*2560000.0*/
glabel D_80051F30
.word 0x3c99a5b7 /*0.018755777*/
glabel D_80051F34
.word 0x491c4000 /*640000.0*/
glabel D_80051F38
.word 0x3d1a1b7b /*0.037623864*/
glabel D_80051F3C
.word 0x481c4000 /*160000.0*/
glabel D_80051F40
.word 0x3d9930a7 /*0.074799828*/
glabel D_80051F44
.word 0x471c4000 /*40000.0*/
glabel D_80051F48
.word 0x3e1930a7 /*0.14959966*/
glabel D_80051F4C
.word 0x3e80adfd /*0.25132743*/
.text
glabel sub_GAME_7F02D244
  lui   $at, %hi(D_80051F2C)
  lwc1  $f4, %lo(D_80051F2C)($at)
  lui   $at, %hi(D_80051F34)
  c.lt.s $f4, $f12
  nop   
  bc1f  .L7F02D26C
   nop   
  lui   $at, %hi(D_80051F30)
  jr    $ra
   lwc1  $f0, %lo(D_80051F30)($at)

.L7F02D26C:
  lwc1  $f6, %lo(D_80051F34)($at)
  lui   $at, %hi(D_80051F3C)
  c.lt.s $f6, $f12
  nop   
  bc1f  .L7F02D290
   nop   
  lui   $at, %hi(D_80051F38)
  jr    $ra
   lwc1  $f0, %lo(D_80051F38)($at)

.L7F02D290:
  lwc1  $f8, %lo(D_80051F3C)($at)
  lui   $at, %hi(D_80051F44)
  c.lt.s $f8, $f12
  nop   
  bc1f  .L7F02D2B4
   nop   
  lui   $at, %hi(D_80051F40)
  jr    $ra
   lwc1  $f0, %lo(D_80051F40)($at)

.L7F02D2B4:
  lwc1  $f10, %lo(D_80051F44)($at)
  lui   $at, %hi(D_80051F4C)
  c.lt.s $f10, $f12
  nop   
  bc1f  .L7F02D2D8
   nop   
  lui   $at, %hi(D_80051F48)
  jr    $ra
   lwc1  $f0, %lo(D_80051F48)($at)

.L7F02D2D8:
  lwc1  $f0, %lo(D_80051F4C)($at)
  jr    $ra
   nop   
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051F50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F58
.word 0x3e23d70a /*0.16*/
glabel D_80051F5C
.word 0x41200419 /*10.001*/
.text
glabel sub_GAME_7F02D2E4
  addiu $sp, $sp, -0x60
  sw    $ra, 0x14($sp)
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  jal   get_curplayer_positiondata
   sw    $a3, 0x6c($sp)
  lw    $t6, 0x60($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lw    $v1, 0x18($t6)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0xc($v1)
  sub.s $f12, $f4, $f6
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x50($sp)
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x10($v1)
  swc1  $f12, 0x54($sp)
  sub.s $f14, $f6, $f8
  jal   convert_angle_using_inverse
   swc1  $f14, 0x4c($sp)
  swc1  $f0, 0x48($sp)
  jal   sub_GAME_7F02C190
   lw    $a0, 0x60($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f18, 0x50($sp)
  lwc1  $f10, 0x48($sp)
  mul.s $f4, $f16, $f16
  lwc1  $f14, 0x4c($sp)
  sub.s $f2, $f10, $f0
  mul.s $f6, $f18, $f18
  swc1  $f0, 0x44($sp)
  mul.s $f10, $f14, $f14
  swc1  $f2, 0x40($sp)
  add.s $f8, $f4, $f6
  add.s $f12, $f8, $f10
  jal   sub_GAME_7F02D244
   swc1  $f12, 0x1c($sp)
  lwc1  $f2, 0x40($sp)
  mtc1  $zero, $f4
  lui   $at, %hi(D_80051F50)
  lw    $t7, 0x64($sp)
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F02D3AC
   c.lt.s $f2, $f0
  lwc1  $f6, %lo(D_80051F50)($at)
  add.s $f2, $f2, $f6
  c.lt.s $f2, $f0
.L7F02D3AC:
  move  $v0, $zero
  lui   $at, %hi(D_80051F54)
  bc1f  .L7F02D3C0
   nop   
  li    $v0, 1
.L7F02D3C0:
  bnez  $v0, .L7F02D3E8
   move  $v1, $v0
  lwc1  $f8, %lo(D_80051F54)($at)
  move  $v1, $zero
  sub.s $f10, $f8, $f0
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F02D3EC
   sw    $v1, ($t7)
  li    $v1, 1
.L7F02D3E8:
  sw    $v1, ($t7)
.L7F02D3EC:
  lw    $t8, 0x68($sp)
  sw    $zero, ($t8)
  jal   check_if_bond_is_invincible
   sw    $v1, 0x24($sp)
  bnez  $v0, .L7F02D620
   lw    $v1, 0x24($sp)
  beql  $v1, $zero, .L7F02D624
   lw    $ra, 0x14($sp)
  jal   sqrtf
   lwc1  $f12, 0x1c($sp)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051F58)
  lwc1  $f4, %lo(D_80051F58)($at)
  lui   $at, %hi(global_timer_delta)
  c.lt.s $f12, $f0
  lwc1  $f6, %lo(global_timer_delta)($at)
  lw    $t9, 0x60($sp)
  mul.s $f2, $f4, $f6
  bc1fl .L7F02D450
   lb    $v0, 2($t9)
  div.s $f8, $f12, $f0
  mul.s $f2, $f2, $f8
  nop   
  lb    $v0, 2($t9)
.L7F02D450:
  blez  $v0, .L7F02D484
   nop   
  mtc1  $v0, $f10
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  cvt.s.w $f4, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  div.s $f8, $f4, $f6
  add.s $f4, $f10, $f8
  mul.s $f2, $f2, $f4
  b     .L7F02D4BC
   nop   
.L7F02D484:
  bgez  $v0, .L7F02D4BC
   slti  $at, $v0, -0x63
  beqz  $at, .L7F02D4A0
   addiu $t0, $v0, 0x64
  mtc1  $zero, $f2
  b     .L7F02D4BC
   nop   
.L7F02D4A0:
  mtc1  $t0, $f6
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f8
  cvt.s.w $f10, $f6
  div.s $f4, $f10, $f8
  mul.s $f2, $f2, $f4
  nop   
.L7F02D4BC:
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f2, 0x2c($sp)
  c.le.s $f0, $f6
  nop   
  bc1f  .L7F02D4F8
   nop   
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  mul.s $f2, $f2, $f0
  b     .L7F02D524
   nop   
.L7F02D4F8:
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  li    $at, 0x41100000 # 9.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80051F5C)
  lwc1  $f8, %lo(D_80051F5C)($at)
  lwc1  $f2, 0x2c($sp)
  sub.s $f4, $f8, $f0
  div.s $f6, $f10, $f4
  mul.s $f2, $f2, $f6
  nop   
.L7F02D524:
  lui   $at, %hi(ai_accuracy_modifier)
  lwc1  $f8, %lo(ai_accuracy_modifier)($at)
  lw    $a0, 0x6c($sp)
  mul.s $f2, $f2, $f8
  jal   get_automatic_firing_rate
   swc1  $f2, 0x2c($sp)
  bgtz  $v0, .L7F02D548
   lwc1  $f2, 0x2c($sp)
  add.s $f2, $f2, $f2
.L7F02D548:
  lw    $a0, 0x6c($sp)
  li    $at, 15
  lw    $v0, 0x60($sp)
  beq   $a0, $at, .L7F02D564
   li    $at, 16
  bnel  $a0, $at, .L7F02D56C
   lwc1  $f10, 0x13c($v0)
.L7F02D564:
  add.s $f2, $f2, $f2
  lwc1  $f10, 0x13c($v0)
.L7F02D56C:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  add.s $f4, $f10, $f2
  swc1  $f4, 0x13c($v0)
  lwc1  $f6, 0x13c($v0)
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F02D624
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F05DF84
   nop   
  jal   get_007_damage_mod
   swc1  $f0, 0x20($sp)
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f10
  lwc1  $f4, 0x20($sp)
  lui   $at, %hi(ai_damage_modifier)
  lwc1  $f8, %lo(ai_damage_modifier)($at)
  mul.s $f6, $f10, $f4
  lw    $t1, 0x6c($sp)
  li    $at, 15
  lwc1  $f14, 0x44($sp)
  li    $a2, -1
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f12, $f0, $f10
  beq   $t1, $at, .L7F02D5E4
   nop   
  li    $at, 16
  bne   $t1, $at, .L7F02D5F8
.L7F02D5E4:
   li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f4
  nop   
  mul.s $f12, $f12, $f4
  nop   
.L7F02D5F8:
  jal   sub_GAME_7F089E4C
   li    $a3, 1
  mtc1  $zero, $f6
  lw    $t2, 0x60($sp)
  jal   check_if_bond_is_invincible
   swc1  $f6, 0x13c($t2)
  beqz  $v0, .L7F02D620
   lw    $t4, 0x68($sp)
  li    $t3, 1
  sw    $t3, ($t4)
.L7F02D620:
  lw    $ra, 0x14($sp)
.L7F02D624:
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");
#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051F50
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F54
.word 0x40c90fdb /*6.2831855*/
glabel D_80051F58
.word 0x3e23d70a /*0.16*/
glabel D_80051F5C
.word 0x41200419 /*10.001*/
.text
glabel sub_GAME_7F02D2E4
  addiu $sp, $sp, -0x60
  sw    $ra, 0x14($sp)
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $a2, 0x68($sp)
  jal   get_curplayer_positiondata
   sw    $a3, 0x6c($sp)
  lw    $t6, 0x60($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lw    $v1, 0x18($t6)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0xc($v1)
  sub.s $f12, $f4, $f6
  sub.s $f4, $f8, $f10
  swc1  $f4, 0x50($sp)
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x10($v1)
  swc1  $f12, 0x54($sp)
  sub.s $f14, $f6, $f8
  jal   convert_angle_using_inverse
   swc1  $f14, 0x4c($sp)
  swc1  $f0, 0x48($sp)
  jal   sub_GAME_7F02C190
   lw    $a0, 0x60($sp)
  lwc1  $f16, 0x54($sp)
  lwc1  $f18, 0x50($sp)
  lwc1  $f10, 0x48($sp)
  mul.s $f4, $f16, $f16
  lwc1  $f14, 0x4c($sp)
  sub.s $f2, $f10, $f0
  mul.s $f6, $f18, $f18
  swc1  $f0, 0x44($sp)
  mul.s $f10, $f14, $f14
  swc1  $f2, 0x40($sp)
  add.s $f8, $f4, $f6
  add.s $f12, $f8, $f10
  jal   sub_GAME_7F02D244
   swc1  $f12, 0x1c($sp)
  lwc1  $f2, 0x40($sp)
  mtc1  $zero, $f4
  lui   $at, %hi(D_80051F50)
  lw    $t7, 0x64($sp)
  c.lt.s $f2, $f4
  nop   
  bc1fl .L7F02D3AC
   c.lt.s $f2, $f0
  lwc1  $f6, %lo(D_80051F50)($at)
  add.s $f2, $f2, $f6
  c.lt.s $f2, $f0
.L7F02D3AC:
  move  $v0, $zero
  lui   $at, %hi(D_80051F54)
  bc1f  .L7F02D3C0
   nop   
  li    $v0, 1
.L7F02D3C0:
  bnez  $v0, .L7F02D3E8
   move  $v1, $v0
  lwc1  $f8, %lo(D_80051F54)($at)
  move  $v1, $zero
  sub.s $f10, $f8, $f0
  c.lt.s $f10, $f2
  nop   
  bc1fl .L7F02D3EC
   sw    $v1, ($t7)
  li    $v1, 1
.L7F02D3E8:
  sw    $v1, ($t7)
.L7F02D3EC:
  lw    $t8, 0x68($sp)
  sw    $zero, ($t8)
  jal   check_if_bond_is_invincible
   sw    $v1, 0x24($sp)
  bnez  $v0, .L7F02D620
   lw    $v1, 0x24($sp)
  beql  $v1, $zero, .L7F02D624
   lw    $ra, 0x14($sp)
  jal   sqrtf
   lwc1  $f12, 0x1c($sp)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f12
  lui   $at, %hi(D_80051F58)
  lwc1  $f4, %lo(D_80051F58)($at)
  lui   $at, %hi(jp_global_timer_delta)
  c.lt.s $f12, $f0
  lwc1  $f6, %lo(jp_global_timer_delta)($at)
  lw    $t9, 0x60($sp)
  mul.s $f2, $f4, $f6
  bc1fl .L7F02D450
   lb    $v0, 2($t9)
  div.s $f8, $f12, $f0
  mul.s $f2, $f2, $f8
  nop   
  lb    $v0, 2($t9)
.L7F02D450:
  blez  $v0, .L7F02D484
   nop   
  mtc1  $v0, $f10
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  cvt.s.w $f4, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  div.s $f8, $f4, $f6
  add.s $f4, $f10, $f8
  mul.s $f2, $f2, $f4
  b     .L7F02D4BC
   nop   
.L7F02D484:
  bgez  $v0, .L7F02D4BC
   slti  $at, $v0, -0x63
  beqz  $at, .L7F02D4A0
   addiu $t0, $v0, 0x64
  mtc1  $zero, $f2
  b     .L7F02D4BC
   nop   
.L7F02D4A0:
  mtc1  $t0, $f6
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f8
  cvt.s.w $f10, $f6
  div.s $f4, $f10, $f8
  mul.s $f2, $f2, $f4
  nop   
.L7F02D4BC:
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f2, 0x2c($sp)
  c.le.s $f0, $f6
  nop   
  bc1f  .L7F02D4F8
   nop   
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  lwc1  $f2, 0x2c($sp)
  mul.s $f2, $f2, $f0
  b     .L7F02D524
   nop   
.L7F02D4F8:
  jal   get_007_accuracy_mod
   swc1  $f2, 0x2c($sp)
  li    $at, 0x41100000 # 9.000000
  mtc1  $at, $f10
  lui   $at, %hi(D_80051F5C)
  lwc1  $f8, %lo(D_80051F5C)($at)
  lwc1  $f2, 0x2c($sp)
  sub.s $f4, $f8, $f0
  div.s $f6, $f10, $f4
  mul.s $f2, $f2, $f6
  nop   
.L7F02D524:
  lui   $at, %hi(ai_accuracy_modifier)
  lwc1  $f8, %lo(ai_accuracy_modifier)($at)
  lw    $a0, 0x6c($sp)
  mul.s $f2, $f2, $f8
  jal   get_automatic_firing_rate
   swc1  $f2, 0x2c($sp)
  bgtz  $v0, .L7F02D548
   lwc1  $f2, 0x2c($sp)
  add.s $f2, $f2, $f2
.L7F02D548:
  lw    $a0, 0x6c($sp)
  li    $at, 15
  lw    $v0, 0x60($sp)
  beq   $a0, $at, .L7F02D564
   li    $at, 16
  bnel  $a0, $at, .L7F02D56C
   lwc1  $f10, 0x13c($v0)
.L7F02D564:
  add.s $f2, $f2, $f2
  lwc1  $f10, 0x13c($v0)
.L7F02D56C:
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  add.s $f4, $f10, $f2
  swc1  $f4, 0x13c($v0)
  lwc1  $f6, 0x13c($v0)
  c.le.s $f8, $f6
  nop   
  bc1fl .L7F02D624
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F05DF84
   nop   
  jal   get_007_damage_mod
   swc1  $f0, 0x20($sp)
  li    $at, 0x3E000000 # 0.125000
  mtc1  $at, $f10
  lwc1  $f4, 0x20($sp)
  lui   $at, %hi(ai_damage_modifier)
  lwc1  $f8, %lo(ai_damage_modifier)($at)
  mul.s $f6, $f10, $f4
  lw    $t1, 0x6c($sp)
  li    $at, 15
  lwc1  $f14, 0x44($sp)
  li    $a2, -1
  mul.s $f10, $f6, $f8
  nop   
  mul.s $f12, $f0, $f10
  beq   $t1, $at, .L7F02D5E4
   nop   
  li    $at, 16
  bne   $t1, $at, .L7F02D5F8
.L7F02D5E4:
   li    $at, 0x40400000 # 3.000000
  mtc1  $at, $f4
  nop   
  mul.s $f12, $f12, $f4
  nop   
.L7F02D5F8:
  jal   sub_GAME_7F089E4C
   li    $a3, 1
  mtc1  $zero, $f6
  lw    $t2, 0x60($sp)
  jal   check_if_bond_is_invincible
   swc1  $f6, 0x13c($t2)
  beqz  $v0, .L7F02D620
   lw    $t4, 0x68($sp)
  li    $t3, 1
  sw    $t3, ($t4)
.L7F02D620:
  lw    $ra, 0x14($sp)
.L7F02D624:
  addiu $sp, $sp, 0x60
  jr    $ra
   nop   
");
#endif
#endif

asm(R"
glabel sub_GAME_7F02D630
  addiu $sp, $sp, -0xc8
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   move  $s0, $a2
  beqz  $v0, .L7F02D720
   move  $a2, $zero
  lbu   $t6, 1($v0)
  lw    $v1, 4($v0)
  andi  $t7, $t6, 2
  beqz  $t7, .L7F02D720
   lw    $a0, 0x14($v1)
  lw    $t8, 8($a0)
  lw    $v0, 8($t8)
  lw    $a1, ($v0)
  beql  $a1, $zero, .L7F02D6DC
   lw    $a1, 4($v0)
  move  $a2, $zero
  jal   sub_GAME_7F06C660
   sw    $a0, 0xbc($sp)
  lw    $a0, 0xbc($sp)
  sw    $v0, 0xb4($sp)
  lw    $t9, 8($a0)
  lw    $t0, 8($t9)
  lw    $t1, ($t0)
  lw    $v1, 4($t1)
  lwc1  $f4, ($v1)
  swc1  $f4, ($s0)
  lwc1  $f6, 4($v1)
  swc1  $f6, 4($s0)
  lwc1  $f8, 8($v1)
  jal   sub_GAME_7F078444
   swc1  $f8, 8($s0)
  move  $a0, $v0
  lw    $a1, 0xb4($sp)
  jal   matrix_4x4_multiply_homogeneous
   addiu $a2, $sp, 0x74
  addiu $a0, $sp, 0x74
  jal   sub_GAME_7F058474
   move  $a1, $s0
  b     .L7F02D720
   li    $a2, 1
  lw    $a1, 4($v0)
.L7F02D6DC:
  beql  $a1, $zero, .L7F02D724
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  jal   sub_GAME_7F078444
   sw    $v0, 0x6c($sp)
  move  $a0, $v0
  lw    $a1, 0x6c($sp)
  jal   matrix_4x4_multiply_homogeneous
   addiu $a2, $sp, 0x2c
  lwc1  $f10, 0x5c($sp)
  li    $a2, 1
  swc1  $f10, ($s0)
  lwc1  $f16, 0x60($sp)
  swc1  $f16, 4($s0)
  lwc1  $f18, 0x64($sp)
  swc1  $f18, 8($s0)
.L7F02D720:
  lw    $ra, 0x1c($sp)
.L7F02D724:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0xc8
  jr    $ra
   move  $v0, $a2
");

asm(R"
.late_rodata
glabel D_80051F60
.word 0x481c4000 /*160000.0*/
glabel D_80051F64
.word 0x3f8e38e3 /*1.111111*/
glabel D_80051F68
.word 0x481c4000 /*160000.0*/
glabel D_80051F6C
.word 0x42055555 /*33.333332*/
glabel D_80051F70
.word 0x3e99999a /*0.30000001*/
glabel D_80051F74
.word 0x3e088888 /*0.13333333*/
glabel D_80051F78
.word 0x461c4000 /*10000.0*/
glabel jpt_80051F7C
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_no_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
 .word weapon_guard_fires_bullet_projectile
.text
glabel sub_GAME_7F02D734
  addiu $sp, $sp, -0x288
  sw    $ra, 0x2c($sp)
  sw    $a1, 0x28c($sp)
  lw    $t6, 0x18($a0)
  sw    $a0, 0x288($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   sw    $t6, 0x284($sp)
  beql  $v0, $zero, .L7F02E260
   lw    $ra, 0x2c($sp)
  sw    $zero, 0x27c($sp)
  sw    $zero, 0x278($sp)
  lw    $t7, 4($v0)
  jal   get_curplayer_positiondata
   sw    $t7, 0x274($sp)
  lw    $a1, 0x288($sp)
  sw    $v0, 0x270($sp)
  li    $at, 8
  lb    $t8, 7($a1)
  li    $v1, 1
  lui   $t2, %hi(global_timer) 
  bnel  $t8, $at, .L7F02D794
   andi  $t9, $v1, 1
  lw    $v1, 0x4c($a1)
  andi  $t9, $v1, 1
.L7F02D794:
  beqz  $t9, .L7F02D7C8
   sw    $t9, 0x44($sp)
  lw    $t2, %lo(global_timer)($t2)
  lw    $t1, 0xe8($a1)
  lw    $t4, 0x274($sp)
  addiu $t3, $t2, -0x78
  slt   $at, $t1, $t3
  beql  $at, $zero, .L7F02D7CC
   lw    $t5, 0x28c($sp)
  jal   get_automatic_firing_rate
   lb    $a0, 0x80($t4)
  bgez  $v0, .L7F02E24C
   lw    $a1, 0x288($sp)
.L7F02D7C8:
  lw    $t5, 0x28c($sp)
.L7F02D7CC:
  sw    $zero, 0x268($sp)
  sw    $zero, 0x264($sp)
  addu  $v0, $a1, $t5
  lbu   $t6, 4($v0)
  addiu $t7, $t6, 1
  sb    $t7, 4($v0)
  lw    $t8, 0x274($sp)
  lb    $a0, 0x80($t8)
  jal   get_automatic_firing_rate
   sw    $v0, 0x40($sp)
  bgez  $v0, .L7F02D810
   lw    $t2, 0x274($sp)
  li    $t9, 1
  li    $t0, 1
  sw    $t9, 0x268($sp)
  b     .L7F02D8D0
   sw    $t0, 0x264($sp)
.L7F02D810:
  jal   get_automatic_firing_rate
   lb    $a0, 0x80($t2)
  lw    $t1, 0x40($sp)
  li    $t5, 1
  lbu   $t3, 4($t1)
  div   $zero, $t3, $v0
  mfhi  $t4
  bnez  $v0, .L7F02D838
   nop   
  break 7
.L7F02D838:
  li    $at, -1
  bne   $v0, $at, .L7F02D850
   lui   $at, 0x8000
  bne   $t3, $at, .L7F02D850
   nop   
  break 6
.L7F02D850:
  bnezl $t4, .L7F02D8CC
   li    $t4, 1
  lw    $t6, 0x274($sp)
  sw    $t5, 0x268($sp)
  jal   get_automatic_firing_rate
   lb    $a0, 0x80($t6)
  lw    $t7, 0x40($sp)
  sll   $t9, $v0, 1
  lw    $t2, 0x274($sp)
  lbu   $t8, 4($t7)
  li    $t3, 1
  div   $zero, $t8, $t9
  bnez  $t9, .L7F02D88C
   nop   
  break 7
.L7F02D88C:
  li    $at, -1
  bne   $t9, $at, .L7F02D8A4
   lui   $at, 0x8000
  bne   $t8, $at, .L7F02D8A4
   nop   
  break 6
.L7F02D8A4:
  mfhi  $t0
  li    $at, 22
  beqz  $t0, .L7F02D8C0
   nop   
  lb    $t1, 0x80($t2)
  bnel  $t1, $at, .L7F02D8D4
   lw    $t5, 0x268($sp)
.L7F02D8C0:
  b     .L7F02D8D0
   sw    $t3, 0x264($sp)
  li    $t4, 1
.L7F02D8CC:
  sw    $t4, 0x278($sp)
.L7F02D8D0:
  lw    $t5, 0x268($sp)
.L7F02D8D4:
  beql  $t5, $zero, .L7F02E228
   lw    $v0, 0x27c($sp)
  sw    $zero, 0x254($sp)
  jal   sub_GAME_7F02C190
   lw    $a0, 0x288($sp)
  swc1  $f0, 0x250($sp)
  jal   sub_GAME_7F02C27C
   lw    $a0, 0x288($sp)
  lw    $t6, 0x284($sp)
  swc1  $f0, 0x24c($sp)
  li    $t8, 1
  lw    $t7, 0x14($t6)
  sw    $t8, 0x27c($sp)
  lw    $a0, 0x288($sp)
  lw    $a1, 0x28c($sp)
  addiu $a2, $sp, 0x240
  jal   sub_GAME_7F02D630
   sw    $t7, 0x23c($sp)
  bnezl $v0, .L7F02D9E8
   lw    $t0, 0x284($sp)
  lw    $v0, 0x284($sp)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f8
  lwc1  $f4, 8($v0)
  lw    $t9, 0x28c($sp)
  li    $at, 1
  swc1  $f4, 0x240($sp)
  lwc1  $f6, 0xc($v0)
  add.s $f10, $f6, $f8
  swc1  $f10, 0x244($sp)
  lwc1  $f4, 0x10($v0)
  bne   $t9, $at, .L7F02D9A0
   swc1  $f4, 0x248($sp)
  jal   cosf
   lwc1  $f12, 0x250($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  lwc1  $f6, 0x240($sp)
  lwc1  $f12, 0x250($sp)
  mul.s $f10, $f0, $f8
  add.s $f4, $f6, $f10
  jal   sinf
   swc1  $f4, 0x240($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  neg.s $f8, $f0
  lwc1  $f4, 0x248($sp)
  mul.s $f10, $f8, $f6
  add.s $f8, $f4, $f10
  b     .L7F02D9E4
   swc1  $f8, 0x248($sp)
.L7F02D9A0:
  jal   cosf
   lwc1  $f12, 0x250($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  neg.s $f6, $f0
  lwc1  $f8, 0x240($sp)
  mul.s $f10, $f6, $f4
  lwc1  $f12, 0x250($sp)
  add.s $f6, $f8, $f10
  jal   sinf
   swc1  $f6, 0x240($sp)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f8
  lwc1  $f4, 0x248($sp)
  mul.s $f10, $f0, $f8
  add.s $f6, $f4, $f10
  swc1  $f6, 0x248($sp)
.L7F02D9E4:
  lw    $t0, 0x284($sp)
.L7F02D9E8:
  lwc1  $f8, 0x248($sp)
  lw    $t1, 0x288($sp)
  lw    $a1, 8($t0)
  lw    $a2, 0x10($t0)
  li    $t2, 2
  sw    $t2, 0x14($sp)
  swc1  $f8, 0x10($sp)
  lwc1  $f4, 0x244($sp)
  lwc1  $f10, 0xac($t1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  sub.s $f0, $f4, $f10
  mtc1  $zero, $f6
  addiu $a0, $sp, 0x23c
  lw    $a3, 0x240($sp)
  swc1  $f0, 0x18($sp)
  swc1  $f0, 0x1c($sp)
  swc1  $f8, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x20($sp)
  beqz  $v0, .L7F02DA48
   lw    $t3, 0x23c($sp)
  b     .L7F02DA5C
   sw    $t3, 0x238($sp)
.L7F02DA48:
  lw    $v0, 0x40($sp)
  lbu   $t4, 4($v0)
  addiu $t5, $t4, -1
  sb    $t5, 4($v0)
  sw    $zero, 0x27c($sp)
.L7F02DA5C:
  lw    $t6, 0x27c($sp)
  li    $t7, 1
  addiu $a1, $sp, 0x240
  beql  $t6, $zero, .L7F02E228
   lw    $v0, 0x27c($sp)
  sw    $zero, 0x234($sp)
  sw    $zero, 0x230($sp)
  sw    $t7, 0x22c($sp)
  lw    $a0, 0x288($sp)
  jal   sub_GAME_7F0292A8
   lw    $a2, 0x238($sp)
  sw    $v0, 0x21c($sp)
  jal   cosf
   lwc1  $f12, 0x24c($sp)
  swc1  $f0, 0x4c($sp)
  jal   sinf
   lwc1  $f12, 0x250($sp)
  lwc1  $f4, 0x4c($sp)
  lwc1  $f12, 0x24c($sp)
  mul.s $f10, $f0, $f4
  jal   sinf
   swc1  $f10, 0x220($sp)
  swc1  $f0, 0x224($sp)
  jal   cosf
   lwc1  $f12, 0x24c($sp)
  swc1  $f0, 0x4c($sp)
  jal   cosf
   lwc1  $f12, 0x250($sp)
  lwc1  $f6, 0x4c($sp)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  mul.s $f18, $f0, $f6
  lwc1  $f8, 0x220($sp)
  lwc1  $f10, 0x240($sp)
  lwc1  $f12, 0x244($sp)
  mul.s $f4, $f8, $f2
  lwc1  $f8, 0x224($sp)
  lw    $a0, 0x288($sp)
  swc1  $f18, 0x228($sp)
  move  $a1, $zero
  add.s $f6, $f4, $f10
  mul.s $f4, $f8, $f2
  nop   
  mul.s $f10, $f18, $f2
  swc1  $f6, 0x258($sp)
  lwc1  $f6, 0x248($sp)
  add.s $f14, $f4, $f12
  add.s $f8, $f10, $f6
  swc1  $f14, 0x25c($sp)
  jal   set_or_unset_GUARDdata_flag
   swc1  $f8, 0x260($sp)
  jal   sub_GAME_7F0B1CC4
   nop   
  lwc1  $f12, 0x244($sp)
  lwc1  $f14, 0x25c($sp)
  lw    $t8, 0x238($sp)
  lwc1  $f4, 0x260($sp)
  li    $t9, 27
  sw    $t9, 0x14($sp)
  addiu $a0, $sp, 0x23c
  lw    $a1, 0x240($sp)
  lw    $a2, 0x248($sp)
  lw    $a3, 0x258($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f12, 0x1c($sp)
  swc1  $f14, 0x20($sp)
  swc1  $f14, 0x24($sp)
  sw    $t8, 0x23c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x10($sp)
  bnez  $v0, .L7F02DBD4
   addiu $a0, $sp, 0x240
  addiu $a1, $sp, 0x220
  jal   sub_GAME_7F02624C
   addiu $a2, $sp, 0x258
  li    $at, 0x41D00000 # 26.000000
  mtc1  $at, $f0
  lwc1  $f6, 0x220($sp)
  lwc1  $f10, 0x258($sp)
  lwc1  $f18, 0x228($sp)
  mul.s $f8, $f0, $f6
  lwc1  $f6, 0x224($sp)
  lwc1  $f14, 0x25c($sp)
  lw    $t0, 0x23c($sp)
  sw    $t0, 0x254($sp)
  sub.s $f4, $f10, $f8
  mul.s $f10, $f0, $f6
  lwc1  $f8, 0x260($sp)
  swc1  $f4, 0x258($sp)
  mul.s $f4, $f0, $f18
  sub.s $f14, $f14, $f10
  sub.s $f6, $f8, $f4
  swc1  $f14, 0x25c($sp)
  swc1  $f6, 0x260($sp)
.L7F02DBD4:
  lw    $a0, 0x288($sp)
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lwc1  $f10, 0x258($sp)
  lwc1  $f8, 0x240($sp)
  lwc1  $f4, 0x25c($sp)
  lwc1  $f6, 0x244($sp)
  sub.s $f2, $f10, $f8
  lwc1  $f8, 0x248($sp)
  lwc1  $f10, 0x260($sp)
  sub.s $f14, $f4, $f6
  mul.s $f4, $f2, $f2
  lw    $t2, 0x274($sp)
  sub.s $f18, $f10, $f8
  mul.s $f6, $f14, $f14
  li    $at, 25
  mul.s $f8, $f18, $f18
  add.s $f10, $f4, $f6
  add.s $f4, $f10, $f8
  swc1  $f4, 0x20c($sp)
  lb    $a3, 0x80($t2)
  bnel  $a3, $at, .L7F02DDE8
   li    $at, 24
  mul.s $f10, $f2, $f2
  lui   $at, %hi(D_80051F60)
  lwc1  $f6, %lo(D_80051F60)($at)
  mul.s $f8, $f14, $f14
  li    $a0, 202
  add.s $f4, $f10, $f8
  mul.s $f10, $f18, $f18
  add.s $f8, $f4, $f10
  c.lt.s $f6, $f8
  nop   
  bc1f  .L7F02DDDC
   nop   
  jal   create_new_item_instance_of_model
   li    $a1, 86
  beqz  $v0, .L7F02E224
   sw    $v0, 0x208($sp)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0x1c8
  lwc1  $f12, 0x24c($sp)
  jal   sub_GAME_7F058570
   addiu $a1, $sp, 0x16c
  lwc1  $f12, 0x250($sp)
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x12c
  addiu $a0, $sp, 0x12c
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x16c
  lui   $at, %hi(D_80051F64)
  lwc1  $f2, %lo(D_80051F64)($at)
  lwc1  $f4, 0x220($sp)
  lwc1  $f10, 0x224($sp)
  lwc1  $f18, 0x228($sp)
  mul.s $f12, $f4, $f2
  lui   $at, %hi(global_timer_delta)
  lwc1  $f0, %lo(global_timer_delta)($at)
  mul.s $f14, $f10, $f2
  lw    $t4, 0x284($sp)
  addiu $t1, $sp, 0x1bc
  mul.s $f16, $f18, $f2
  addiu $t3, $sp, 0x1c8
  sw    $t3, 0x14($sp)
  mul.s $f6, $f12, $f0
  sw    $t1, 0x10($sp)
  swc1  $f14, 0x1b0($sp)
  mul.s $f8, $f14, $f0
  swc1  $f16, 0x1b4($sp)
  swc1  $f12, 0x1ac($sp)
  mul.s $f4, $f16, $f0
  swc1  $f6, 0x1bc($sp)
  lw    $a0, 0x208($sp)
  addiu $a1, $sp, 0x240
  swc1  $f8, 0x1c0($sp)
  lw    $a2, 0x238($sp)
  addiu $a3, $sp, 0x16c
  swc1  $f4, 0x1c4($sp)
  jal   sub_GAME_7F05EB0C
   sw    $t4, 0x18($sp)
  lw    $v1, 0x208($sp)
  lw    $t5, 0x64($v1)
  andi  $t6, $t5, 0x80
  beql  $t6, $zero, .L7F02E228
   lw    $v0, 0x27c($sp)
  lw    $v0, 0x6c($v1)
  li    $t9, -1
  lui   $a0, %hi(ptr_sfx_buf)
  lw    $t7, ($v0)
  li    $a1, 1
  ori   $t8, $t7, 0x80
  sw    $t8, ($v0)
  lw    $v0, 0x6c($v1)
  sh    $t9, 0x82($v1)
  lw    $t0, ($v0)
  ori   $t2, $t0, 0x20
  sw    $t2, ($v0)
  lw    $t1, 0x6c($v1)
  lwc1  $f10, 0x5c($v1)
  swc1  $f10, 0xb0($t1)
  lw    $v0, 0x6c($v1)
  lwc1  $f6, 8($v0)
  swc1  $f6, 0xb4($v0)
  lw    $t3, 0x6c($v1)
  lwc1  $f8, 0x1ac($sp)
  swc1  $f8, 0x10($t3)
  lw    $t4, 0x6c($v1)
  lwc1  $f4, 0x1b0($sp)
  swc1  $f4, 0x14($t4)
  lw    $t5, 0x6c($v1)
  lwc1  $f10, 0x1b4($sp)
  swc1  $f10, 0x18($t5)
  lw    $v0, 0x6c($v1)
  lw    $t6, 0x98($v0)
  addiu $a2, $v0, 0x98
  bnezl $t6, .L7F02DDBC
   lw    $t7, 0x9c($v0)
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F02E228
   lw    $v0, 0x27c($sp)
  lw    $t7, 0x9c($v0)
.L7F02DDBC:
  lui   $a0, %hi(ptr_sfx_buf)
  li    $a1, 1
  bnez  $t7, .L7F02E224
   addiu $a2, $v0, 0x9c
  jal   play_sfx_a1
   lw    $a0, %lo(ptr_sfx_buf)($a0)
  b     .L7F02E228
   lw    $v0, 0x27c($sp)
.L7F02DDDC:
  b     .L7F02E224
   sw    $zero, 0x27c($sp)
  li    $at, 24
.L7F02DDE8:
  bne   $a3, $at, .L7F02DF0C
   lw    $t8, 0x44($sp)
  mul.s $f8, $f2, $f2
  lui   $at, %hi(D_80051F68)
  lwc1  $f6, %lo(D_80051F68)($at)
  mul.s $f4, $f14, $f14
  li    $a0, 203
  add.s $f10, $f8, $f4
  mul.s $f8, $f18, $f18
  add.s $f4, $f10, $f8
  c.lt.s $f6, $f4
  nop   
  bc1f  .L7F02DF04
   nop   
  jal   create_new_item_instance_of_model
   li    $a1, 87
  beqz  $v0, .L7F02E224
   sw    $v0, 0x128($sp)
  jal   matrix_4x4_set_identity
   addiu $a0, $sp, 0xe8
  lui   $at, %hi(D_80051F6C)
  lwc1  $f0, %lo(D_80051F6C)($at)
  lwc1  $f10, 0x220($sp)
  lwc1  $f6, 0x224($sp)
  lwc1  $f18, 0x228($sp)
  mul.s $f8, $f10, $f0
  lwc1  $f12, 0x24c($sp)
  addiu $a1, $sp, 0x9c
  mul.s $f4, $f6, $f0
  nop   
  mul.s $f10, $f18, $f0
  swc1  $f8, 0xdc($sp)
  swc1  $f4, 0xe0($sp)
  jal   sub_GAME_7F058570
   swc1  $f10, 0xe4($sp)
  lwc1  $f12, 0x250($sp)
  jal   sub_GAME_7F0585FC
   addiu $a1, $sp, 0x5c
  addiu $a0, $sp, 0x5c
  jal   matrix_4x4_multiply_homogeneous_in_place
   addiu $a1, $sp, 0x9c
  lw    $a0, 0x128($sp)
  li    $t8, 180
  addiu $t9, $sp, 0xdc
  sh    $t8, 0x82($a0)
  lw    $t2, 0x284($sp)
  addiu $t0, $sp, 0xe8
  sw    $t0, 0x14($sp)
  sw    $t9, 0x10($sp)
  lw    $a2, 0x238($sp)
  addiu $a1, $sp, 0x240
  addiu $a3, $sp, 0x9c
  jal   sub_GAME_7F05EB0C
   sw    $t2, 0x18($sp)
  lw    $v0, 0x128($sp)
  lui   $at, %hi(D_80051F70)
  lw    $t1, 0x64($v0)
  andi  $t3, $t1, 0x80
  beql  $t3, $zero, .L7F02E228
   lw    $v0, 0x27c($sp)
  lwc1  $f8, %lo(D_80051F70)($at)
  lw    $t4, 0x6c($v0)
  lui   $at, %hi(D_80051F74)
  li    $t6, 60
  swc1  $f8, 0x8c($t4)
  lw    $t5, 0x6c($v0)
  lwc1  $f6, %lo(D_80051F74)($at)
  swc1  $f6, 0x94($t5)
  lw    $t7, 0x6c($v0)
  b     .L7F02E224
   sw    $t6, 0xbc($t7)
.L7F02DF04:
  b     .L7F02E224
   sw    $zero, 0x27c($sp)
.L7F02DF0C:
  beqz  $t8, .L7F02DFE8
   lw    $t9, 0x21c($sp)
  beqz  $t9, .L7F02DFE8
   li    $at, 0x41700000 # 15.000000
  lw    $t0, 0x270($sp)
  lwc1  $f10, 0x240($sp)
  mtc1  $at, $f2
  lwc1  $f4, 8($t0)
  lwc1  $f6, 0x220($sp)
  lw    $a0, 0x288($sp)
  sub.s $f8, $f4, $f10
  mul.s $f4, $f6, $f2
  lwc1  $f6, 0x244($sp)
  lwc1  $f10, 0xc($t0)
  addiu $a1, $sp, 0x234
  sub.s $f0, $f8, $f4
  lwc1  $f4, 0x224($sp)
  sub.s $f8, $f10, $f6
  mul.s $f10, $f4, $f2
  lwc1  $f4, 0x248($sp)
  lwc1  $f6, 0x10($t0)
  sub.s $f12, $f8, $f10
  lwc1  $f10, 0x228($sp)
  sub.s $f8, $f6, $f4
  mul.s $f6, $f10, $f2
  lwc1  $f4, 0x20c($sp)
  mul.s $f10, $f0, $f0
  sub.s $f16, $f8, $f6
  mul.s $f8, $f12, $f12
  add.s $f6, $f10, $f8
  mul.s $f10, $f16, $f16
  add.s $f8, $f6, $f10
  c.le.s $f8, $f4
  nop   
  bc1fl .L7F02E018
   lw    $t0, 0x230($sp)
  jal   sub_GAME_7F02D2E4
   addiu $a2, $sp, 0x230
  lw    $t2, 0x230($sp)
  lw    $t3, 0x234($sp)
  lw    $t4, 0x288($sp)
  sltiu $t1, $t2, 1
  beqz  $t3, .L7F02E014
   sw    $t1, 0x22c($sp)
  lb    $v0, 7($t4)
  li    $at, 8
  lui   $t5, %hi(global_timer) 
  beq   $v0, $at, .L7F02DFDC
   lw    $t6, 0x288($sp)
  li    $at, 10
  bnel  $v0, $at, .L7F02E018
   lw    $t0, 0x230($sp)
.L7F02DFDC:
  lw    $t5, %lo(global_timer)($t5)
  b     .L7F02E014
   sw    $t5, 0x48($t6)
.L7F02DFE8:
  lw    $t7, 0x288($sp)
  li    $at, 8
  lui   $t8, %hi(global_timer) 
  lb    $v0, 7($t7)
  lw    $t9, 0x288($sp)
  beq   $v0, $at, .L7F02E00C
   li    $at, 10
  bnel  $v0, $at, .L7F02E018
   lw    $t0, 0x230($sp)
.L7F02E00C:
  lw    $t8, %lo(global_timer)($t8)
  sw    $t8, 0x48($t9)
.L7F02E014:
  lw    $t0, 0x230($sp)
.L7F02E018:
  lw    $a1, 0x270($sp)
  lui   $v1, %hi(dword_CODE_bss_8007BA04)
  beqz  $t0, .L7F02E060
   nop   
  lwc1  $f6, 8($a1)
  lw    $t3, 0x274($sp)
  li    $a2, -1
  swc1  $f6, 0x258($sp)
  lwc1  $f10, 0xc($a1)
  swc1  $f10, 0x25c($sp)
  lwc1  $f4, 0x10($a1)
  swc1  $f4, 0x260($sp)
  lw    $t1, 0x14($a1)
  sw    $t1, 0x254($sp)
  jal   recall_joy2_hits_edit_detail_edit_flag
   lb    $a0, 0x80($t3)
  b     .L7F02E0A4
   lw    $t4, 0x22c($sp)
.L7F02E060:
  lw    $v1, %lo(dword_CODE_bss_8007BA04)($v1)
  lwc1  $f8, 0x20c($sp)
  beqz  $v1, .L7F02E084
   nop   
  lbu   $v0, ($v1)
  li    $at, 3
  beq   $v0, $at, .L7F02E0A0
   li    $at, 6
  beq   $v0, $at, .L7F02E0A0
.L7F02E084:
   lui   $at, %hi(D_80051F78)
  lwc1  $f6, %lo(D_80051F78)($at)
  c.lt.s $f8, $f6
  nop   
  bc1fl .L7F02E0A4
   lw    $t4, 0x22c($sp)
  sw    $zero, 0x22c($sp)
.L7F02E0A0:
  lw    $t4, 0x22c($sp)
.L7F02E0A4:
  lw    $t5, 0x254($sp)
  beql  $t4, $zero, .L7F02E1A0
   lw    $t4, 0x264($sp)
  beqz  $t5, .L7F02E0C8
   addiu $a0, $sp, 0x258
  li    $a1, 1
  lui   $a2, 0x41d0
  jal   sub_GAME_7F0A3E1C
   lbu   $a3, 3($t5)
.L7F02E0C8:
  lui   $a1, %hi(dword_CODE_bss_8007BA04)
  lw    $a1, %lo(dword_CODE_bss_8007BA04)($a1)
  lw    $t6, 0x274($sp)
  li    $a2, -1
  beqz  $a1, .L7F02E190
   lb    $a3, 0x80($t6)
  move  $a0, $a3
  jal   recall_joy2_hits_edit_detail_edit_flag
   li    $a2, -1
  lui   $v1, %hi(dword_CODE_bss_8007BA04)
  lw    $v1, %lo(dword_CODE_bss_8007BA04)($v1)
  li    $at, 3
  lw    $t7, 0x288($sp)
  lbu   $v0, ($v1)
  bnel  $v0, $at, .L7F02E140
   li    $at, 1
  lw    $t8, 0x14($t7)
  li    $a1, 15
  lw    $t0, 0x274($sp)
  andi  $t9, $t8, 0x40
  beql  $t9, $zero, .L7F02E1A0
   lw    $t4, 0x264($sp)
  lw    $a0, 4($v1)
  lb    $a3, 0x80($t0)
  sw    $zero, 0x10($sp)
  jal   handles_shot_actors
   addiu $a2, $sp, 0x220
  b     .L7F02E1A0
   lw    $t4, 0x264($sp)
  li    $at, 1
.L7F02E140:
  beq   $v0, $at, .L7F02E154
   lw    $t1, 0x274($sp)
  li    $at, 4
  bnel  $v0, $at, .L7F02E1A0
   lw    $t4, 0x264($sp)
.L7F02E154:
  jal   sub_GAME_7F05DF84
   lb    $a0, 0x80($t1)
  jal   get_cur_playernum
   swc1  $f0, 0x4c($sp)
  lui   $t3, %hi(dword_CODE_bss_8007BA04) 
  lw    $t3, %lo(dword_CODE_bss_8007BA04)($t3)
  lw    $t2, 0x274($sp)
  lw    $a1, 0x4c($sp)
  lw    $a0, 4($t3)
  lb    $a3, 0x80($t2)
  sw    $v0, 0x10($sp)
  jal   sub_GAME_7F04E0CC
   addiu $a2, $sp, 0x258
  b     .L7F02E1A0
   lw    $t4, 0x264($sp)
.L7F02E190:
  move  $a0, $a3
  jal   recall_joy2_hits_edit_flag
   addiu $a1, $sp, 0x258
  lw    $t4, 0x264($sp)
.L7F02E1A0:
  lw    $t5, 0x274($sp)
  beql  $t4, $zero, .L7F02E1E8
   lw    $t9, 0x264($sp)
  lb    $t6, 0x80($t5)
  addiu $t7, $t6, -4
  sltiu $at, $t7, 0x13
  beqz  $at, .L7F02E1E0
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80051F7C)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80051F7C)($at)
  jr    $t7
   nop   
weapon_guard_fires_bullet_projectile:
  li    $t8, 1
  b     .L7F02E1E4
   sw    $t8, 0x264($sp)
weapon_guard_fires_bullet_no_projectile:
.L7F02E1E0:
  sw    $zero, 0x264($sp)
.L7F02E1E4:
  lw    $t9, 0x264($sp)
.L7F02E1E8:
  lw    $t1, 0x28c($sp)
  lw    $t0, 0x288($sp)
  beqz  $t9, .L7F02E224
   sll   $t3, $t1, 2
  subu  $t3, $t3, $t1
  sll   $t3, $t3, 2
  subu  $t3, $t3, $t1
  lw    $t2, 0x274($sp)
  sll   $t3, $t3, 2
  addu  $a0, $t0, $t3
  addiu $a0, $a0, 0x180
  addiu $a2, $sp, 0x240
  addiu $a3, $sp, 0x258
  jal   sub_GAME_7F061948
   lb    $a1, 0x80($t2)
.L7F02E224:
  lw    $v0, 0x27c($sp)
.L7F02E228:
  lw    $a0, 0x288($sp)
  sltu  $a2, $zero, $v0
  bnez  $a2, .L7F02E244
   nop   
  lw    $a2, 0x278($sp)
  sltu  $t5, $zero, $a2
  move  $a2, $t5
.L7F02E244:
  jal   sub_GAME_7F02BFE4
   lw    $a1, 0x28c($sp)
.L7F02E24C:
  lw    $a0, 0x288($sp)
  lw    $a1, 0x28c($sp)
  jal   sub_GAME_7F02D118
   lw    $a2, 0x27c($sp)
  lw    $ra, 0x2c($sp)
.L7F02E260:
  addiu $sp, $sp, 0x288
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02E26C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lhu   $t6, 0x12($a0)
  move  $a1, $zero
  andi  $t7, $t6, 0xff7f
  andi  $v0, $t7, 0xffff
  andi  $t8, $v0, 8
  beqz  $t8, .L7F02E2AC
   sh    $t7, 0x12($a0)
  jal   sub_GAME_7F02D734
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lhu   $t9, 0x12($a0)
  andi  $t0, $t9, 0xfff7
  andi  $v0, $t0, 0xffff
  sh    $t0, 0x12($a0)
.L7F02E2AC:
  andi  $t1, $v0, 4
  beqz  $t1, .L7F02E2D0
   li    $a1, 1
  jal   sub_GAME_7F02D734
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  lhu   $t2, 0x12($a0)
  andi  $t3, $t2, 0xfffb
  sh    $t3, 0x12($a0)
.L7F02E2D0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02E2E0
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  lw    $v0, 0x2c($a0)
  lui   $t6, %hi(D_80030108) 
  addiu $t6, %lo(D_80030108) # addiu $t6, $t6, 0x108
  beq   $t6, $v0, .L7F02E308
   lui   $t7, %hi(D_80030150) 
  addiu $t7, %lo(D_80030150) # addiu $t7, $t7, 0x150
  bnel  $t7, $v0, .L7F02E3A8
   move  $v0, $zero
.L7F02E308:
  lw    $v0, 0x1c($a0)
  lui   $t0, %hi(D_800300C0) 
  li    $t9, 2
  lb    $t8, 0x24($v0)
  addiu $t0, %lo(D_800300C0) # addiu $t0, $t0, 0xc0
  lui   $a1, (0x3F333333 >> 16) # lui $a1, 0x3f33
  sw    $t8, 0x24($sp)
  sb    $t9, 0x30($a0)
  sw    $t0, 0x2c($a0)
  sb    $zero, 8($a0)
  lui   $a2, (0x3F8F5C29 >> 16) # lui $a2, 0x3f8f
  ori   $a2, (0x3F8F5C29 & 0xFFFF) # ori $a2, $a2, 0x5c29
  ori   $a1, (0x3F333333 & 0xFFFF) # ori $a1, $a1, 0x3333
  jal   sub_GAME_7F023B5C
   sw    $v0, 0x2c($sp)
  li    $at, 0x41B00000 # 22.000000
  mtc1  $at, $f4
  lui   $a1, %hi(D_800300C0)
  lui   $a3, %hi(D_800300C0+0x1C)
  lw    $a3, %lo(D_800300C0+0x1C)($a3)
  lw    $a1, %lo(D_800300C0)($a1)
  lw    $a0, 0x2c($sp)
  lw    $a2, 0x24($sp)
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lui   $at, %hi(D_800300C0+0x14)
  lwc1  $f0, %lo(D_800300C0+0x14)($at)
  mtc1  $zero, $f6
  nop   
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F02E39C
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x2c($sp)
.L7F02E39C:
  b     .L7F02E3A8
   li    $v0, 1
  move  $v0, $zero
.L7F02E3A8:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02E3B8
  addiu $sp, $sp, -0x38
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $t6, 0x2c($a0)
  mtc1  $zero, $f4
  move  $s1, $a0
  lwc1  $f6, 0x24($t6)
  lw    $s0, 0x1c($a0)
  c.lt.s $f4, $f6
  nop   
  bc1f  .L7F02E43C
   nop   
  jal   sub_GAME_7F06F5AC
   move  $a0, $s0
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s1
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t7, 0x2c($s1)
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f8
  lb    $a2, 0x24($s0)
  lw    $a3, 0x24($t7)
  swc1  $f0, 0x10($sp)
  move  $a0, $s0
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f8, 0x14($sp)
  b     .L7F02E488
   lw    $t9, 0x2c($s1)
.L7F02E43C:
  jal   sub_GAME_7F06F5AC
   move  $a0, $s0
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s1
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t8, 0x2c($s1)
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f10
  lb    $a2, 0x24($s0)
  lw    $a3, 0x1c($t8)
  swc1  $f0, 0x10($sp)
  move  $a0, $s0
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f10, 0x14($sp)
  lw    $t9, 0x2c($s1)
.L7F02E488:
  mtc1  $zero, $f16
  lwc1  $f0, 0x14($t9)
  c.le.s $f16, $f0
  nop   
  bc1fl .L7F02E4B0
   lw    $ra, 0x24($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s0
  lw    $ra, 0x24($sp)
.L7F02E4B0:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
.late_rodata
glabel D_80051FC8
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F02E4C0
  addiu $sp, $sp, -0x70
  sw    $ra, 0x44($sp)
  sw    $s3, 0x40($sp)
  sw    $s2, 0x3c($sp)
  sw    $s1, 0x38($sp)
  sw    $s0, 0x34($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  lw    $s3, 0x1c($a0)
  move  $s0, $a0
  jal   sub_GAME_7F06F5BC
   move  $a0, $s3
  lw    $t7, 0x44($s0)
  lw    $t6, 0x48($s0)
  mov.s $f20, $f0
  addiu $t8, $t7, -0x1e
  slt   $at, $t6, $t8
  beql  $at, $zero, .L7F02E638
   lui   $at, 0x3f00
  lw    $t9, 0x54($s3)
  bnezl $t9, .L7F02E638
   lui   $at, 0x3f00
  lw    $a1, 0x2c($s0)
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($a1)
  add.s $f8, $f4, $f6
  c.lt.s $f8, $f0
  nop   
  bc1fl .L7F02E638
   lui   $at, 0x3f00
  lwc1  $f10, 0x1c($a1)
  c.lt.s $f0, $f10
  nop   
  bc1fl .L7F02E638
   lui   $at, 0x3f00
  mtc1  $zero, $f22
  lwc1  $f2, 0x24($a1)
  c.lt.s $f2, $f22
  nop   
  bc1tl .L7F02E580
   lb    $t0, 0x36($s0)
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F02E638
   li    $at, 0x3F000000 # 0.500000
  lb    $t0, 0x36($s0)
.L7F02E580:
  bnez  $t0, .L7F02E614
   nop   
  jal   sub_GAME_7F02E2E0
   move  $a0, $s0
  bnez  $v0, .L7F02E60C
   nop   
  jal   sub_GAME_7F06F5AC
   move  $a0, $s3
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f24
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  mfc1  $a1, $f24
  move  $s1, $v0
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  lw    $t1, 0x2c($s0)
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f16
  lb    $a2, 0x24($s3)
  lw    $a3, 0x1c($t1)
  swc1  $f0, 0x10($sp)
  move  $a0, $s3
  move  $a1, $s1
  jal   sub_GAME_7F06FCA8
   swc1  $f16, 0x14($sp)
  lw    $t2, 0x2c($s0)
  lwc1  $f0, 0x14($t2)
  c.le.s $f22, $f0
  nop   
  bc1f  .L7F02E60C
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s3
.L7F02E60C:
  b     .L7F02E620
   lb    $t3, 0x34($s0)
.L7F02E614:
  jal   sub_GAME_7F02E3B8
   move  $a0, $s0
  lb    $t3, 0x34($s0)
.L7F02E620:
  move  $a0, $s3
  addiu $t4, $t3, 1
  jal   sub_GAME_7F06F5BC
   sb    $t4, 0x33($s0)
  mov.s $f20, $f0
  li    $at, 0x3F000000 # 0.500000
.L7F02E638:
  mtc1  $at, $f24
  mtc1  $zero, $f22
  jal   sub_GAME_7F06F5C4
   move  $a0, $s3
  c.le.s $f0, $f20
  nop   
  bc1fl .L7F02E82C
   lw    $v0, 0x4c($s0)
  lb    $t5, 0x37($s0)
  bnez  $t5, .L7F02E678
   nop   
  lb    $v1, 0x34($s0)
  lb    $v0, 0x33($s0)
  slt   $at, $v1, $v0
  beqz  $at, .L7F02E6B0
   nop   
.L7F02E678:
  jal   sub_GAME_7F02E2E0
   move  $a0, $s0
  bnez  $v0, .L7F02E81C
   nop   
  lw    $t7, 0x4c($s0)
  andi  $t6, $t7, 1
  beqz  $t6, .L7F02E6A0
   nop   
  jal   sub_GAME_7F029BB0
   move  $a0, $s0
.L7F02E6A0:
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F02EBD8
   lw    $ra, 0x44($sp)
.L7F02E6B0:
  bne   $v1, $v0, .L7F02E6CC
   addiu $t8, $v0, 1
  sb    $t8, 0x33($s0)
  jal   sub_GAME_7F02E3B8
   move  $a0, $s0
  b     .L7F02E81C
   nop   
.L7F02E6CC:
  lb    $t9, 0x31($s0)
  li    $at, 0x41400000 # 12.000000
  move  $a0, $s3
  beqz  $t9, .L7F02E81C
   nop   
  lb    $t0, 0x36($s0)
  mov.s $f12, $f24
  beql  $t0, $zero, .L7F02E73C
   lw    $a1, 0x2c($s0)
  lw    $a1, 0x2c($s0)
  lwc1  $f0, 0x20($a1)
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F02E714
   lwc1  $f14, 0x18($a1)
  b     .L7F02E714
   mov.s $f14, $f0
  lwc1  $f14, 0x18($a1)
.L7F02E714:
  lwc1  $f2, 0x24($a1)
  c.lt.s $f22, $f2
  nop   
  bc1f  .L7F02E730
   nop   
  b     .L7F02E760
   mov.s $f20, $f2
.L7F02E730:
  b     .L7F02E760
   lwc1  $f20, 0x1c($a1)
  lw    $a1, 0x2c($s0)
.L7F02E73C:
  lwc1  $f0, 0x20($a1)
  lwc1  $f14, 0x18($a1)
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F02E760
   lwc1  $f20, 0x1c($a1)
  b     .L7F02E760
   mov.s $f20, $f0
  lwc1  $f20, 0x1c($a1)
.L7F02E760:
  sub.s $f0, $f20, $f14
  mtc1  $at, $f2
  li    $at, 0x41800000 # 16.000000
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F02E78C
   mtc1  $at, $f4
  mul.s $f18, $f0, $f24
  b     .L7F02E7B8
   div.s $f12, $f18, $f2
  mtc1  $at, $f4
.L7F02E78C:
  nop   
  c.lt.s $f4, $f0
  nop   
  bc1fl .L7F02E7BC
   lb    $t1, 0x3a($s0)
  mul.s $f6, $f0, $f24
  li    $at, 0x3D800000 # 0.062500
  mtc1  $at, $f8
  nop   
  mul.s $f12, $f6, $f8
  nop   
.L7F02E7B8:
  lb    $t1, 0x3a($s0)
.L7F02E7BC:
  beql  $t1, $zero, .L7F02E7D8
   sb    $zero, 0x31($s0)
  lb    $t2, 0x3b($s0)
  beql  $t2, $zero, .L7F02E7D8
   sb    $zero, 0x31($s0)
  add.s $f12, $f12, $f12
  sb    $zero, 0x31($s0)
.L7F02E7D8:
  swc1  $f14, 0x5c($sp)
  jal   sub_GAME_7F06F5AC
   swc1  $f12, 0x60($sp)
  lwc1  $f14, 0x5c($sp)
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f10
  lwc1  $f12, 0x60($sp)
  lb    $a2, 0x24($s3)
  mfc1  $a3, $f14
  move  $a0, $s3
  move  $a1, $v0
  swc1  $f10, 0x14($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f12, 0x10($sp)
  mfc1  $a1, $f20
  jal   sub_GAME_7F06FDE8
   move  $a0, $s3
.L7F02E81C:
  jal   sub_GAME_7F06F5BC
   move  $a0, $s3
  mov.s $f20, $f0
  lw    $v0, 0x4c($s0)
.L7F02E82C:
  andi  $t3, $v0, 0x40
  bnezl $t3, .L7F02E8E0
   lw    $a1, 0x2c($s0)
  lw    $a1, 0x2c($s0)
  andi  $t4, $v0, 0x20
  move  $a0, $s3
  lwc1  $f2, 0xc($a1)
  beqz  $t4, .L7F02E888
   lwc1  $f12, 4($a1)
  swc1  $f2, 0x50($sp)
  jal   sub_GAME_7F06F5C4
   swc1  $f12, 0x4c($sp)
  lwc1  $f12, 0x4c($sp)
  lwc1  $f2, 0x50($sp)
  move  $a0, $s3
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F02E88C
   lb    $t5, 0x24($s3)
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x50($sp)
  lwc1  $f2, 0x50($sp)
  mov.s $f12, $f0
.L7F02E888:
  lb    $t5, 0x24($s3)
.L7F02E88C:
  move  $a0, $s0
  lui   $a1, 0x3f80
  beqz  $t5, .L7F02E8A8
   lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
  lui   $at, %hi(D_80051FC8)
  lwc1  $f16, %lo(D_80051FC8)($at)
  sub.s $f2, $f16, $f2
.L7F02E8A8:
  ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  swc1  $f2, 0x50($sp)
  jal   sub_GAME_7F023B5C
   swc1  $f12, 0x4c($sp)
  lwc1  $f12, 0x4c($sp)
  lwc1  $f2, 0x50($sp)
  lb    $a1, 0x30($s0)
  mfc1  $a3, $f0
  mfc1  $a2, $f12
  move  $a0, $s0
  jal   sub_GAME_7F02C2B0
   swc1  $f2, 0x10($sp)
  sb    $v0, 0x30($s0)
  lw    $a1, 0x2c($s0)
.L7F02E8E0:
  lwc1  $f18, 0x28($a1)
  c.lt.s $f18, $f20
  nop   
  bc1f  .L7F02E92C
   nop   
  lwc1  $f4, 0x2c($a1)
  move  $a0, $s0
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f20, $f4
  nop   
  bc1f  .L7F02E92C
   nop   
  mtc1  $at, $f6
  lb    $a2, 0x39($s0)
  lb    $a3, 0x38($s0)
  jal   sub_GAME_7F02C4C0
   swc1  $f6, 0x10($sp)
  b     .L7F02E938
   move  $s1, $zero
.L7F02E92C:
  jal   sub_GAME_7F02D0F8
   move  $a0, $s0
  move  $s1, $zero
.L7F02E938:
  move  $s2, $s0
.L7F02E93C:
  lb    $t7, 0x38($s2)
  move  $a0, $s0
  move  $a1, $s1
  beqz  $t7, .L7F02EBBC
   nop   
  lb    $t6, 0x3a($s2)
  bnezl $t6, .L7F02EAE8
   lb    $t1, 0x31($s0)
  lw    $a1, 0x2c($s0)
  move  $a0, $s0
  move  $a2, $zero
  lwc1  $f8, 0x18($a1)
  c.le.s $f8, $f20
  nop   
  bc1f  .L7F02EA78
   nop   
  lwc1  $f10, 0x1c($a1)
  move  $a1, $s1
  c.lt.s $f20, $f10
  nop   
  bc1f  .L7F02EA78
   nop   
  move  $a0, $s0
  jal   sub_GAME_7F02D1C4
   li    $a2, 1
  lb    $t9, 7($s0)
  lui   $t8, %hi(global_timer) 
  lw    $t8, %lo(global_timer)($t8)
  li    $at, 10
  bne   $t9, $at, .L7F02EA60
   sw    $t8, 0x44($s0)
  lw    $a1, 0x2c($s0)
  li    $at, 0x41F00000 # 30.000000
  mtc1  $at, $f4
  lwc1  $f16, 0x1c($a1)
  lwc1  $f18, 0x18($a1)
  sub.s $f0, $f16, $f18
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F02EA4C
   mfc1  $a1, $f24
  trunc.w.s $f6, $f0
  lw    $t0, 0x40($s0)
  li    $t4, 60
  move  $a0, $s3
  mfc1  $t2, $f6
  lui   $a1, (0x3DCCCCCD >> 16) # lui $a1, 0x3dcc
  sll   $t3, $t2, 1
  subu  $t5, $t4, $t3
  slt   $at, $t0, $t5
  bnezl $at, .L7F02EA28
   mfc1  $a2, $f22
  mfc1  $a1, $f24
  mfc1  $a2, $f22
  jal   sub_GAME_7F06FE4C
   move  $a0, $s3
  b     .L7F02EBC8
   addiu $s1, $s1, 1
  mfc1  $a2, $f22
.L7F02EA28:
  jal   sub_GAME_7F06FE4C
   ori   $a1, (0x3DCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  lw    $t7, 0x40($s0)
  addu  $t8, $t7, $t6
  b     .L7F02EBC4
   sw    $t8, 0x40($s0)
  mfc1  $a1, $f24
.L7F02EA4C:
  mfc1  $a2, $f22
  jal   sub_GAME_7F06FE4C
   move  $a0, $s3
  b     .L7F02EBC8
   addiu $s1, $s1, 1
.L7F02EA60:
  mfc1  $a1, $f24
  mfc1  $a2, $f22
  jal   sub_GAME_7F06FE4C
   move  $a0, $s3
  b     .L7F02EBC8
   addiu $s1, $s1, 1
.L7F02EA78:
  jal   sub_GAME_7F02D1C4
   move  $a1, $s1
  lb    $t9, 7($s0)
  li    $at, 10
  move  $a0, $s0
  bne   $t9, $at, .L7F02EAC0
   lui   $a2, 0x3f4c
  mfc1  $a1, $f24
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  jal   sub_GAME_7F023B5C
   move  $a0, $s0
  mfc1  $a1, $f0
  mfc1  $a2, $f22
  jal   sub_GAME_7F06FE4C
   move  $a0, $s3
  b     .L7F02EBC8
   addiu $s1, $s1, 1
.L7F02EAC0:
  mfc1  $a1, $f24
  jal   sub_GAME_7F023B5C
   ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  mfc1  $a1, $f0
  mfc1  $a2, $f22
  jal   sub_GAME_7F06FE4C
   move  $a0, $s3
  b     .L7F02EBC8
   addiu $s1, $s1, 1
  lb    $t1, 0x31($s0)
.L7F02EAE8:
  move  $a0, $s0
  move  $a2, $zero
  bnez  $t1, .L7F02EBAC
   nop   
  lb    $v0, 0x32($s0)
  beq   $s1, $v0, .L7F02EB10
   addu  $t2, $s0, $v0
  lb    $t4, 0x3a($t2)
  bnez  $t4, .L7F02EBAC
   nop   
.L7F02EB10:
  lw    $a1, 0x2c($s0)
  lwc1  $f0, 0x20($a1)
  c.le.s $f22, $f0
  nop   
  bc1fl .L7F02EB50
   c.lt.s $f0, $f22
  c.le.s $f0, $f20
  nop   
  bc1fl .L7F02EB50
   c.lt.s $f0, $f22
  lwc1  $f8, 0x24($a1)
  c.le.s $f20, $f8
  nop   
  bc1tl .L7F02EB74
   lb    $t0, 0x33($s0)
  c.lt.s $f0, $f22
.L7F02EB50:
  nop   
  bc1f  .L7F02EBAC
   nop   
  lwc1  $f10, 0x18($a1)
  c.le.s $f10, $f20
  nop   
  bc1f  .L7F02EBAC
   nop   
  lb    $t0, 0x33($s0)
.L7F02EB74:
  li    $a2, 1
  subu  $t3, $a2, $v0
  addiu $t5, $t0, 1
  sb    $a2, 0x31($s0)
  sb    $t3, 0x32($s0)
  sb    $t5, 0x33($s0)
  lui   $t7, %hi(global_timer) 
  lw    $t7, %lo(global_timer)($t7)
  move  $a0, $s0
  move  $a1, $s1
  jal   sub_GAME_7F02D1C4
   sw    $t7, 0x44($s0)
  b     .L7F02EBC8
   addiu $s1, $s1, 1
.L7F02EBAC:
  jal   sub_GAME_7F02D1C4
   move  $a1, $s1
  b     .L7F02EBC8
   addiu $s1, $s1, 1
.L7F02EBBC:
  jal   sub_GAME_7F02D1C4
   move  $a2, $zero
.L7F02EBC4:
  addiu $s1, $s1, 1
.L7F02EBC8:
  li    $at, 2
  bne   $s1, $at, .L7F02E93C
   addiu $s2, $s2, 1
  lw    $ra, 0x44($sp)
.L7F02EBD8:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  lw    $s0, 0x34($sp)
  lw    $s1, 0x38($sp)
  lw    $s2, 0x3c($sp)
  lw    $s3, 0x40($sp)
  jr    $ra
   addiu $sp, $sp, 0x70
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel D_80051FCC
.word 0x3e4ccccd /*0.2*/
.text
glabel sub_GAME_7F02EBFC
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $s1, 0x1c($a0)
  move  $s0, $a0
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  lw    $v0, 0x58($s0)
  mov.s $f2, $f0
  li    $at, 1
  beql  $v0, $zero, .L7F02ED64
   lw    $v0, 0x4c($s0)
  bne   $v0, $at, .L7F02ECE8
   move  $a0, $s1
  lw    $v0, 0x2c($s0)
  mtc1  $zero, $f4
  lwc1  $f0, 0x24($v0)
  c.le.s $f4, $f0
  nop   
  bc1fl .L7F02EC60
   lwc1  $f2, 0x1c($v0)
  b     .L7F02EC60
   mov.s $f2, $f0
  lwc1  $f2, 0x1c($v0)
.L7F02EC60:
  jal   sub_GAME_7F06F5AC
   swc1  $f2, 0x34($sp)
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lwc1  $f2, 0x34($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lb    $a2, 0x24($s1)
  mfc1  $a3, $f2
  swc1  $f0, 0x10($sp)
  move  $a0, $s1
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $t6, 0x2c($s0)
  mtc1  $zero, $f8
  lwc1  $f0, 0x14($t6)
  c.le.s $f8, $f0
  nop   
  bc1fl .L7F02ECD4
   li    $t7, 2
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s1
  li    $t7, 2
.L7F02ECD4:
  sw    $t7, 0x58($s0)
  jal   sub_GAME_7F02D0F8
   move  $a0, $s0
  b     .L7F02EED0
   lw    $ra, 0x24($sp)
.L7F02ECE8:
  li    $at, 2
  bne   $v0, $at, .L7F02ED60
   move  $a0, $s1
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F02EED0
   lw    $ra, 0x24($sp)
  lw    $t8, 0x4c($s0)
  lw    $t2, 0x54($s0)
  li    $at, -65
  ori   $t9, $t8, 0x20
  sw    $t9, 0x4c($s0)
  and   $t1, $t9, $at
  beqz  $t2, .L7F02ED48
   sw    $t1, 0x4c($s0)
  move  $a0, $s0
  move  $a1, $t1
  jal   sub_GAME_7F025560
   lw    $a2, 0x50($s0)
  b     .L7F02EED0
   lw    $ra, 0x24($sp)
.L7F02ED48:
  move  $a0, $s0
  lw    $a1, 0x4c($s0)
  jal   sub_GAME_7F0256F0
   lw    $a2, 0x50($s0)
  b     .L7F02EED0
   lw    $ra, 0x24($sp)
.L7F02ED60:
  lw    $v0, 0x4c($s0)
.L7F02ED64:
  andi  $t3, $v0, 0x20
  beqz  $t3, .L7F02EDDC
   andi  $t4, $v0, 0x40
  beqz  $t4, .L7F02EDA8
   move  $a0, $s1
  lui   $at, %hi(D_80051FCC)
  lwc1  $f10, %lo(D_80051FCC)($at)
  lw    $a1, 0x2c($s0)
  lb    $a2, 0x39($s0)
  lb    $a3, 0x38($s0)
  move  $a0, $s0
  jal   sub_GAME_7F02C4C0
   swc1  $f10, 0x10($sp)
  bnez  $v0, .L7F02EECC
   li    $t5, 1
  b     .L7F02EECC
   sw    $t5, 0x58($s0)
.L7F02EDA8:
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F02EDE0
   lb    $t9, 0x36($s0)
  lw    $t6, 0x4c($s0)
  li    $t8, 2
  sb    $t8, 0x30($s0)
  ori   $t7, $t6, 0x40
  b     .L7F02EECC
   sw    $t7, 0x4c($s0)
.L7F02EDDC:
  lb    $t9, 0x36($s0)
.L7F02EDE0:
  bnez  $t9, .L7F02EEC4
   nop   
  lw    $t0, 0x2c($s0)
  mtc1  $zero, $f16
  lwc1  $f0, 0x24($t0)
  c.lt.s $f16, $f0
  nop   
  bc1f  .L7F02EEC4
   nop   
  c.le.s $f2, $f0
  move  $a0, $s1
  bc1f  .L7F02EEC4
   nop   
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1f  .L7F02EEC4
   nop   
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t1, 0x2c($s0)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lb    $a2, 0x24($s1)
  lw    $a3, 0x24($t1)
  swc1  $f0, 0x10($sp)
  move  $a0, $s1
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f18, 0x14($sp)
  lb    $t2, 0x37($s0)
  beql  $t2, $zero, .L7F02EEB8
   lw    $t4, 0x2c($s0)
  lw    $t3, 0x2c($s0)
  mtc1  $zero, $f4
  lwc1  $f0, 0x14($t3)
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F02EEC4
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s1
  b     .L7F02EEC4
   nop   
  lw    $t4, 0x2c($s0)
.L7F02EEB8:
  move  $a0, $s1
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x1c($t4)
.L7F02EEC4:
  jal   sub_GAME_7F02E4C0
   move  $a0, $s0
.L7F02EECC:
  lw    $ra, 0x24($sp)
.L7F02EED0:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel D_80051FCC
.word 0x3e4ccccd /*0.2*/

.text
glabel sub_GAME_7F02EBFC
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $s1, 0x1c($a0)
  move  $s0, $a0
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  lw    $v0, 0x58($s0)
  mov.s $f2, $f0
  li    $at, 1
  beql  $v0, $zero, .Ljp7F02F064
   lw    $v0, 0x4c($s0)
  bne   $v0, $at, .Ljp7F02EFF0
   move  $a0, $s1
  lw    $v0, 0x2c($s0)
  mtc1  $zero, $f4
  lwc1  $f0, 0x24($v0)
  c.le.s $f4, $f0
  nop   
  bc1fl .Ljp7F02EF68
   lwc1  $f2, 0x1c($v0)
  b     .Ljp7F02EF68
   mov.s $f2, $f0
  lwc1  $f2, 0x1c($v0)
.Ljp7F02EF68:
  jal   sub_GAME_7F06F5AC
   swc1  $f2, 0x34($sp)
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lwc1  $f2, 0x34($sp)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f6
  lb    $a2, 0x24($s1)
  mfc1  $a3, $f2
  swc1  $f0, 0x10($sp)
  move  $a0, $s1
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $t6, 0x2c($s0)
  mtc1  $zero, $f8
  lwc1  $f0, 0x14($t6)
  c.le.s $f8, $f0
  nop   
  bc1fl .Ljp7F02EFDC
   li    $t7, 2
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s1
  li    $t7, 2
.Ljp7F02EFDC:
  sw    $t7, 0x58($s0)
  jal   sub_GAME_7F02D0F8
   move  $a0, $s0
  b     .Ljp7F02F1D0
   lw    $ra, 0x24($sp)
.Ljp7F02EFF0:
  li    $at, 2
  bne   $v0, $at, .Ljp7F02F060
   move  $a0, $s1
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .Ljp7F02F1D0
   lw    $ra, 0x24($sp)
  lw    $t8, 0x4c($s0)
  lw    $t0, 0x54($s0)
  li    $at, -65
  and   $t9, $t8, $at
  beqz  $t0, .Ljp7F02F048
   sw    $t9, 0x4c($s0)
  move  $a0, $s0
  move  $a1, $t9
  jal   sub_GAME_7F025560
   lw    $a2, 0x50($s0)
  b     .Ljp7F02F1D0
   lw    $ra, 0x24($sp)
.Ljp7F02F048:
  move  $a0, $s0
  lw    $a1, 0x4c($s0)
  jal   sub_GAME_7F0256F0
   lw    $a2, 0x50($s0)
  b     .Ljp7F02F1D0
   lw    $ra, 0x24($sp)
.Ljp7F02F060:
  lw    $v0, 0x4c($s0)
.Ljp7F02F064:
  andi  $t1, $v0, 0x20
  beqz  $t1, .Ljp7F02F0DC
   andi  $t2, $v0, 0x40
  beqz  $t2, .Ljp7F02F0A8
   move  $a0, $s1
  lui   $at, %hi(D_80051FCC) # $at, 0x8005
  lwc1  $f10, %lo(D_80051FCC)($at)
  lw    $a1, 0x2c($s0)
  lb    $a2, 0x39($s0)
  lb    $a3, 0x38($s0)
  move  $a0, $s0
  jal   sub_GAME_7F02C4C0
   swc1  $f10, 0x10($sp)
  bnez  $v0, .Ljp7F02F1CC
   li    $t3, 1
  b     .Ljp7F02F1CC
   sw    $t3, 0x58($s0)
.Ljp7F02F0A8:
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .Ljp7F02F0E0
   lb    $t7, 0x36($s0)
  lw    $t4, 0x4c($s0)
  li    $t6, 2
  sb    $t6, 0x30($s0)
  ori   $t5, $t4, 0x40
  b     .Ljp7F02F1CC
   sw    $t5, 0x4c($s0)
.Ljp7F02F0DC:
  lb    $t7, 0x36($s0)
.Ljp7F02F0E0:
  bnez  $t7, .Ljp7F02F1C4
   nop   
  lw    $t8, 0x2c($s0)
  mtc1  $zero, $f16
  lwc1  $f0, 0x24($t8)
  c.lt.s $f16, $f0
  nop   
  bc1f  .Ljp7F02F1C4
   nop   
  c.le.s $f2, $f0
  move  $a0, $s1
  bc1f  .Ljp7F02F1C4
   nop   
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x38($sp)
  lwc1  $f2, 0x38($sp)
  c.le.s $f0, $f2
  nop   
  bc1f  .Ljp7F02F1C4
   nop   
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x2c($sp)
  move  $a0, $s0
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t9, 0x2c($s0)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f18
  lb    $a2, 0x24($s1)
  lw    $a3, 0x24($t9)
  swc1  $f0, 0x10($sp)
  move  $a0, $s1
  lw    $a1, 0x2c($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f18, 0x14($sp)
  lb    $t0, 0x37($s0)
  beql  $t0, $zero, .Ljp7F02F1B8
   lw    $t2, 0x2c($s0)
  lw    $t1, 0x2c($s0)
  mtc1  $zero, $f4
  lwc1  $f0, 0x14($t1)
  c.le.s $f4, $f0
  nop   
  bc1f  .Ljp7F02F1C4
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   move  $a0, $s1
  b     .Ljp7F02F1C4
   nop   
  lw    $t2, 0x2c($s0)
.Ljp7F02F1B8:
  move  $a0, $s1
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x1c($t2)
.Ljp7F02F1C4:
  jal   sub_GAME_7F02E4C0
   move  $a0, $s0
.Ljp7F02F1CC:
  lw    $ra, 0x24($sp)
.Ljp7F02F1D0:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
    
");
#endif

#endif

asm(R"
glabel sub_GAME_7F02EEE0
  addiu $sp, $sp, -0x48
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x48($sp)
  lb    $t7, 0x35($a0)
  beqz  $t7, .L7F02F3E0
   nop   
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x44($sp)
  lw    $a3, 0x48($sp)
  lui   $t8, %hi(D_80030198) 
  addiu $t8, %lo(D_80030198) # addiu $t8, $t8, 0x198
  lw    $v0, 0x2c($a3)
  lui   $t9, %hi(D_800301E0) 
  mov.s $f12, $f0
  beq   $t8, $v0, .L7F02EF44
   addiu $t9, %lo(D_800301E0) # addiu $t9, $t9, 0x1e0
  beq   $t9, $v0, .L7F02EF44
   lui   $t0, %hi(D_80030228) 
  addiu $t0, %lo(D_80030228) # addiu $t0, $t0, 0x228
  beq   $t0, $v0, .L7F02EF44
   lui   $t1, %hi(D_80030270) 
  addiu $t1, %lo(D_80030270) # addiu $t1, $t1, 0x270
  bne   $t1, $v0, .L7F02F25C
   lui   $t8, %hi(D_800302B8)
.L7F02EF44:
  lwc1  $f4, 0x14($v0)
  lw    $t2, 0x44($sp)
  c.le.s $f4, $f0
  nop   
  bc1f  .L7F02F254
   nop   
  lb    $t3, 0x24($t2)
  li    $at, 0x41800000 # 16.000000
  mtc1  $at, $f2
  sw    $t3, 0x38($sp)
  lb    $t4, 0x39($a3)
  addiu $v1, $v0, 0x120
  beqz  $t4, .L7F02EFB8
   nop   
  lb    $t5, 0x38($a3)
  beqz  $t5, .L7F02EFB8
   nop   
  sw    $v1, 0x3c($sp)
  jal   get_random_value
   swc1  $f2, 0x34($sp)
  andi  $t7, $v0, 1
  lw    $v1, 0x3c($sp)
  bnez  $t7, .L7F02EFB0
   lwc1  $f2, 0x34($sp)
  addiu $v1, $v1, 0x120
  b     .L7F02EFB8
   lw    $a3, 0x48($sp)
.L7F02EFB0:
  addiu $v1, $v1, 0x240
  lw    $a3, 0x48($sp)
.L7F02EFB8:
  lui   $v0, %hi(D_80030078)
  addiu $v0, %lo(D_80030078) # addiu $v0, $v0, 0x78
  addiu $t6, $v0, 0x240
  bne   $v1, $t6, .L7F02EFDC
   move  $a0, $a3
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02EFDC:
  addiu $t8, $v0, 0x288
  bne   $v1, $t8, .L7F02EFF8
   addiu $t9, $v0, 0x2d0
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02EFF8:
  bne   $v1, $t9, .L7F02F010
   addiu $t0, $v0, 0x318
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F010:
  bne   $v1, $t0, .L7F02F028
   addiu $t1, $v0, 0x360
  li    $at, 0x42300000 # 44.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F028:
  bne   $v1, $t1, .L7F02F040
   addiu $t2, $v0, 0x3a8
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F040:
  bne   $v1, $t2, .L7F02F058
   addiu $t3, $v0, 0x3f0
  li    $at, 0x42080000 # 34.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F058:
  bne   $v1, $t3, .L7F02F070
   addiu $t4, $v0, 0x438
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F070:
  bne   $v1, $t4, .L7F02F088
   addiu $t5, $v0, 0x480
  li    $at, 0x42300000 # 44.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F088:
  bne   $v1, $t5, .L7F02F0A0
   addiu $t7, $v0, 0x4c8
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F0A0:
  bne   $v1, $t7, .L7F02F0B8
   addiu $t6, $v0, 0x510
  li    $at, 0x42080000 # 34.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F0B8:
  bne   $v1, $t6, .L7F02F0D0
   addiu $t8, $v0, 0x558
  li    $at, 0x42000000 # 32.000000
  mtc1  $at, $f2
  b     .L7F02F0E4
   li    $t9, 2
.L7F02F0D0:
  bne   $v1, $t8, .L7F02F0E0
   li    $at, 0x42300000 # 44.000000
  mtc1  $at, $f2
  nop   
.L7F02F0E0:
  li    $t9, 2
.L7F02F0E4:
  sb    $t9, 0x30($a3)
  sw    $v1, 0x2c($a3)
  sb    $zero, 8($a3)
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  swc1  $f2, 0x34($sp)
  sw    $v1, 0x3c($sp)
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $v1, 0x3c($sp)
  lwc1  $f2, 0x34($sp)
  lw    $a0, 0x44($sp)
  lw    $a1, ($v1)
  lw    $a3, 0x10($v1)
  swc1  $f0, 0x10($sp)
  lw    $a2, 0x38($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f2, 0x14($sp)
  lw    $t0, 0x48($sp)
  lw    $v1, 0x3c($sp)
  lwc1  $f2, 0x34($sp)
  lb    $t1, 0x36($t0)
  beql  $t1, $zero, .L7F02F190
   lwc1  $f0, 0x20($v1)
  lwc1  $f0, 0x24($v1)
  mtc1  $zero, $f6
  lw    $a0, 0x44($sp)
  c.le.s $f6, $f0
  nop   
  bc1fl .L7F02F17C
   lw    $a1, 0x1c($v1)
  mfc1  $a1, $f0
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F06FDE8
   swc1  $f2, 0x34($sp)
  b     .L7F02F1E8
   lwc1  $f2, 0x34($sp)
  lw    $a1, 0x1c($v1)
.L7F02F17C:
  jal   sub_GAME_7F06FDE8
   swc1  $f2, 0x34($sp)
  b     .L7F02F1E8
   lwc1  $f2, 0x34($sp)
  lwc1  $f0, 0x20($v1)
.L7F02F190:
  mtc1  $zero, $f8
  lw    $a0, 0x44($sp)
  c.le.s $f8, $f0
  nop   
  bc1fl .L7F02F1C0
   lwc1  $f0, 0x14($v1)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   swc1  $f2, 0x34($sp)
  b     .L7F02F1E8
   lwc1  $f2, 0x34($sp)
  lwc1  $f0, 0x14($v1)
.L7F02F1C0:
  mtc1  $zero, $f10
  lw    $a0, 0x44($sp)
  c.le.s $f10, $f0
  nop   
  bc1fl .L7F02F1EC
   lw    $t2, 0x48($sp)
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   swc1  $f2, 0x34($sp)
  lwc1  $f2, 0x34($sp)
.L7F02F1E8:
  lw    $t2, 0x48($sp)
.L7F02F1EC:
  mtc1  $zero, $f16
  lw    $a0, 0x44($sp)
  lw    $t3, 0x2c($t2)
  lwc1  $f18, 0xc($t3)
  c.eq.s $f16, $f18
  nop   
  bc1t  .L7F02F254
   nop   
  lw    $t4, 8($a0)
  lw    $a1, ($t4)
  jal   extract_id_from_object_structure_microcode
   swc1  $f2, 0x34($sp)
  lwc1  $f2, 0x34($sp)
  swc1  $f2, 0x5c($v0)
  lw    $t5, 0x48($sp)
  lw    $t7, 0x2c($t5)
  lwc1  $f4, 0xc($t7)
  neg.s $f6, $f4
  div.s $f8, $f6, $f2
  swc1  $f8, 0x58($v0)
  lw    $t6, 0x38($sp)
  beqz  $t6, .L7F02F254
   nop   
  lwc1  $f10, 0x58($v0)
  neg.s $f16, $f10
  swc1  $f16, 0x58($v0)
.L7F02F254:
  b     .L7F02F3E0
   nop   
.L7F02F25C:
  addiu $t8, $t8, %lo(D_800302B8)
  beq   $t8, $v0, .L7F02F2EC
   lui   $t9, %hi(D_80030300) 
  addiu $t9, %lo(D_80030300) # addiu $t9, $t9, 0x300
  beq   $t9, $v0, .L7F02F2EC
   lui   $t0, %hi(D_80030348) 
  addiu $t0, %lo(D_80030348) # addiu $t0, $t0, 0x348
  beq   $t0, $v0, .L7F02F2EC
   lui   $t1, %hi(D_80030390) 
  addiu $t1, %lo(D_80030390) # addiu $t1, $t1, 0x390
  beq   $t1, $v0, .L7F02F2EC
   lui   $t2, %hi(D_800303D8) 
  addiu $t2, %lo(D_800303D8) # addiu $t2, $t2, 0x3d8
  beq   $t2, $v0, .L7F02F2EC
   lui   $t3, %hi(D_80030420) 
  addiu $t3, %lo(D_80030420) # addiu $t3, $t3, 0x420
  beq   $t3, $v0, .L7F02F2EC
   lui   $t4, %hi(D_80030468) 
  addiu $t4, %lo(D_80030468) # addiu $t4, $t4, 0x468
  beq   $t4, $v0, .L7F02F2EC
   lui   $t5, %hi(D_800304B0) 
  addiu $t5, %lo(D_800304B0) # addiu $t5, $t5, 0x4b0
  beq   $t5, $v0, .L7F02F2EC
   lui   $t7, %hi(D_800304F8) 
  addiu $t7, %lo(D_800304F8) # addiu $t7, $t7, 0x4f8
  beq   $t7, $v0, .L7F02F2EC
   lui   $t6, %hi(D_80030540) 
  addiu $t6, %lo(D_80030540) # addiu $t6, $t6, 0x540
  beq   $t6, $v0, .L7F02F2EC
   lui   $t8, %hi(D_80030588) 
  addiu $t8, %lo(D_80030588) # addiu $t8, $t8, 0x588
  beq   $t8, $v0, .L7F02F2EC
   lui   $t9, %hi(D_800305D0) 
  addiu $t9, %lo(D_800305D0) # addiu $t9, $t9, 0x5d0
  bne   $t9, $v0, .L7F02F3E0
   nop   
.L7F02F2EC:
  lb    $t0, 0x36($a3)
  bnez  $t0, .L7F02F3E0
   nop   
  lwc1  $f2, 0x24($v0)
  mtc1  $zero, $f18
  nop   
  c.lt.s $f18, $f2
  nop   
  bc1f  .L7F02F3E0
   nop   
  c.le.s $f0, $f2
  lw    $a0, 0x44($sp)
  bc1f  .L7F02F3E0
   nop   
  jal   sub_GAME_7F06F5C4
   swc1  $f12, 0x40($sp)
  lwc1  $f12, 0x40($sp)
  c.le.s $f0, $f12
  nop   
  bc1f  .L7F02F3E0
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x44($sp)
  lui   $a2, (0x3F4CCCCD >> 16) # lui $a2, 0x3f4c
  ori   $a2, (0x3F4CCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  sw    $v0, 0x24($sp)
  lw    $a0, 0x48($sp)
  jal   sub_GAME_7F023B5C
   lui   $a1, 0x3f00
  lw    $t2, 0x48($sp)
  lw    $a0, 0x44($sp)
  li    $at, 0x41800000 # 16.000000
  lw    $t3, 0x2c($t2)
  mtc1  $at, $f4
  lb    $a2, 0x24($a0)
  lw    $a3, 0x24($t3)
  swc1  $f0, 0x10($sp)
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lw    $t4, 0x48($sp)
  lw    $t6, 0x48($sp)
  lb    $t5, 0x37($t4)
  beql  $t5, $zero, .L7F02F3D4
   lw    $t8, 0x2c($t6)
  lw    $t7, 0x2c($t4)
  mtc1  $zero, $f6
  lwc1  $f0, 0x14($t7)
  c.le.s $f6, $f0
  nop   
  bc1f  .L7F02F3E0
   nop   
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FDE8
   lw    $a0, 0x44($sp)
  b     .L7F02F3E0
   nop   
  lw    $t8, 0x2c($t6)
.L7F02F3D4:
  lw    $a0, 0x44($sp)
  jal   sub_GAME_7F06FDE8
   lw    $a1, 0x1c($t8)
.L7F02F3E0:
  jal   sub_GAME_7F02E4C0
   lw    $a0, 0x48($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02F3F8
  addiu $sp, $sp, -0x48
  sw    $s0, 0x20($sp)
  move  $s0, $a0
  sw    $ra, 0x24($sp)
  lw    $a0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   sw    $a0, 0x44($sp)
  lw    $t6, 0x44($sp)
  mov.s $f2, $f0
  move  $a2, $zero
  lb    $t7, 0x24($t6)
  move  $a0, $s0
  beqz  $t7, .L7F02F438
   nop   
  b     .L7F02F438
   li    $a2, 1
.L7F02F438:
  move  $a1, $a2
  sw    $a2, 0x3c($sp)
  jal   something_with_weaponpos_of_guarddata_hand
   swc1  $f2, 0x40($sp)
  li    $at, 0x41A00000 # 20.000000
  lwc1  $f2, 0x40($sp)
  mtc1  $at, $f4
  lw    $a2, 0x3c($sp)
  c.le.s $f4, $f2
  nop   
  bc1fl .L7F02F488
   lui   $at, 0x4274
  beql  $v0, $zero, .L7F02F488
   li    $at, 0x42740000 # 61.000000
  lw    $v1, 4($v0)
  li    $at, -2049
  lw    $t8, 0x64($v1)
  and   $t9, $t8, $at
  sw    $t9, 0x64($v1)
  li    $at, 0x42740000 # 61.000000
.L7F02F488:
  mtc1  $at, $f6
  li    $at, 0x42EE0000 # 119.000000
  mtc1  $at, $f8
  c.le.s $f6, $f2
  nop   
  bc1fl .L7F02F4BC
   c.le.s $f8, $f2
  beql  $v0, $zero, .L7F02F4BC
   c.le.s $f8, $f2
  lw    $v1, 4($v0)
  li    $t0, 180
  sh    $t0, 0x82($v1)
  c.le.s $f8, $f2
.L7F02F4BC:
  nop   
  bc1fl .L7F02F4F8
   lw    $a0, 0x44($sp)
  beqz  $v0, .L7F02F4F4
   sll   $t1, $a2, 2
  addu  $t2, $s0, $t1
  lw    $a0, 0x160($t2)
  swc1  $f2, 0x40($sp)
  jal   sub_GAME_7F04BFD0
   li    $a1, 3
  lhu   $t3, 0x12($s0)
  lwc1  $f2, 0x40($sp)
  ori   $t4, $t3, 1
  sh    $t4, 0x12($s0)
.L7F02F4F4:
  lw    $a0, 0x44($sp)
.L7F02F4F8:
  jal   sub_GAME_7F06F5BC
   swc1  $f2, 0x40($sp)
  swc1  $f0, 0x2c($sp)
  jal   sub_GAME_7F06F5C4
   lw    $a0, 0x44($sp)
  lwc1  $f10, 0x2c($sp)
  lwc1  $f2, 0x40($sp)
  li    $at, 0x42AE0000 # 87.000000
  c.le.s $f0, $f10
  nop   
  bc1fl .L7F02F53C
   mtc1  $at, $f16
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F02F594
   lw    $ra, 0x24($sp)
  mtc1  $at, $f16
.L7F02F53C:
  li    $at, 0x42DC0000 # 110.000000
  c.le.s $f16, $f2
  nop   
  bc1fl .L7F02F594
   lw    $ra, 0x24($sp)
  mtc1  $at, $f18
  move  $a0, $s0
  lui   $a1, 0x3f80
  c.le.s $f2, $f18
  lui   $a2, (0x3FCCCCCD >> 16) # lui $a2, 0x3fcc
  bc1fl .L7F02F594
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F023B5C
   ori   $a2, (0x3FCCCCCD & 0xFFFF) # ori $a2, $a2, 0xcccd
  mtc1  $zero, $f4
  mfc1  $a3, $f0
  move  $a0, $s0
  li    $a1, 1
  lui   $a2, 0x42dc
  jal   sub_GAME_7F02C2B0
   swc1  $f4, 0x10($sp)
  lw    $ra, 0x24($sp)
.L7F02F594:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02F5A4
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x30($sp)
  lw    $s0, 0x1c($a0)
  jal   sub_GAME_7F06F5BC
   move  $a0, $s0
  li    $at, 0x42AC0000 # 86.000000
  mtc1  $at, $f4
  mov.s $f2, $f0
  move  $a0, $s0
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F02F650
   move  $a0, $s0
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x28($sp)
  lwc1  $f2, 0x28($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F02F650
   move  $a0, $s0
  jal   sub_GAME_7F06F610
   move  $a0, $s0
  lui   $t7, %hi(ptr_animation_table) 
  li    $at, 0x41C00000 # 24.000000
  mtc1  $at, $f6
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, %hi(0x00006254) # $t8, 0
  addiu $t8, %lo(0x00006254) # addiu $t8, $t8, 0x6254
  move  $a0, $s0
  move  $a2, $zero
  lui   $a3, 0x42ac
  swc1  $f0, 0x10($sp)
  addu  $a1, $t7, $t8
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  move  $a0, $s0
  jal   sub_GAME_7F06FDE8
   lui   $a1, 0x4303
  b     .L7F02F678
   lw    $ra, 0x24($sp)
  move  $a0, $s0
.L7F02F650:
  jal   sub_GAME_7F06F5C4
   swc1  $f2, 0x28($sp)
  lwc1  $f2, 0x28($sp)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F02F678
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F023CB8
   lw    $a0, 0x30($sp)
  lw    $ra, 0x24($sp)
.L7F02F678:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02F688
  jr    $ra
   sw    $a0, ($sp)
");

asm(R"
.late_rodata
glabel D_80051FD0
.word 0x40c90fdb /*6.2831855*/
glabel D_80051FD4
.word 0x40490fdb /*3.1415927*/
glabel D_80051FD8
.word 0x40c90fdb /*6.2831855*/
glabel D_80051FDC
.word 0x3e9930a7 /*0.29919931*/
glabel D_80051FE0
.word 0x3c751aa5 /*0.014959966*/
glabel D_80051FE4
.word 0x3ec90fdb /*0.39269909*/
glabel D_80051FE8
.word 0x3ca0d97c /*0.019634955*/
glabel D_80051FEC
.word 0x3fa0d97c /*1.2566371*/
glabel D_80051FF0
.word 0x3dc90fdb /*0.098174773*/
glabel D_80051FF4
.word 0x3e490fdb /*0.19634955*/
glabel D_80051FF8
.word 0x3c751aa5 /*0.014959966*/
glabel D_80051FFC
.word 0x3ec90fdb /*0.39269909*/
glabel D_80052000
.word 0x3c20d97c /*0.0098174773*/
glabel D_80052004
.word 0x3fa0d97c /*1.2566371*/
glabel D_80052008
.word 0x3d490fdb /*0.049087387*/
glabel D_8005200C
.word 0x3e00adfd /*0.12566371*/
glabel D_80052010
.word 0x3c20d97c /*0.0098174773*/
.text
glabel sub_GAME_7F02F690
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x58($sp)
  sw    $a3, 0x5c($sp)
  lw    $t6, 0x1c($a0)
  lw    $v0, 0x18($a0)
  sw    $t6, 0x48($sp)
  lwc1  $f4, ($a1)
  lwc1  $f8, 8($a1)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lw    $a0, 0x48($sp)
  jal   getsubroty
   swc1  $f0, 0x3c($sp)
  lwc1  $f14, 0x3c($sp)
  swc1  $f0, 0x38($sp)
  move  $v1, $zero
  c.lt.s $f14, $f0
  lui   $at, %hi(D_80051FD0)
  sub.s $f12, $f14, $f0
  lw    $v0, 0x58($sp)
  lw    $t7, 0x48($sp)
  bc1f  .L7F02F704
   mov.s $f2, $f12
  lwc1  $f16, %lo(D_80051FD0)($at)
  add.s $f2, $f12, $f16
.L7F02F704:
  lui   $at, %hi(D_80051FD4)
  lwc1  $f18, %lo(D_80051FD4)($at)
  mov.s $f0, $f2
  lui   $at, %hi(D_80051FD8)
  c.lt.s $f18, $f2
  nop   
  bc1fl .L7F02F730
   li    $at, 2
  lwc1  $f4, %lo(D_80051FD8)($at)
  sub.s $f0, $f4, $f2
  li    $at, 2
.L7F02F730:
  bne   $v0, $at, .L7F02F748
   lui   $at, %hi(D_80051FDC)
  lwc1  $f12, %lo(D_80051FDC)($at)
  lui   $at, %hi(D_80051FE0)
  b     .L7F02F804
   lwc1  $f0, %lo(D_80051FE0)($at)
.L7F02F748:
  li    $at, 1
  bne   $v0, $at, .L7F02F7AC
   lui   $at, %hi(D_80051FE4)
  lwc1  $f6, %lo(D_80051FE4)($at)
  lui   $at, %hi(D_80051FEC)
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F02F778
   nop   
  lui   $at, %hi(D_80051FE8)
  b     .L7F02F7A0
   lwc1  $f12, %lo(D_80051FE8)($at)
.L7F02F778:
  lwc1  $f8, %lo(D_80051FEC)($at)
  lui   $at, %hi(D_80051FF4)
  c.lt.s $f0, $f8
  nop   
  bc1f  .L7F02F79C
   nop   
  lui   $at, %hi(D_80051FF0)
  b     .L7F02F7A0
   lwc1  $f12, %lo(D_80051FF0)($at)
.L7F02F79C:
  lwc1  $f12, %lo(D_80051FF4)($at)
.L7F02F7A0:
  lui   $at, %hi(D_80051FF8)
  b     .L7F02F804
   lwc1  $f0, %lo(D_80051FF8)($at)
.L7F02F7AC:
  lui   $at, %hi(D_80051FFC)
  lwc1  $f10, %lo(D_80051FFC)($at)
  lui   $at, %hi(D_80052004)
  c.lt.s $f0, $f10
  nop   
  bc1f  .L7F02F7D4
   nop   
  lui   $at, %hi(D_80052000)
  b     .L7F02F7FC
   lwc1  $f12, %lo(D_80052000)($at)
.L7F02F7D4:
  lwc1  $f16, %lo(D_80052004)($at)
  lui   $at, %hi(D_8005200C)
  c.lt.s $f0, $f16
  nop   
  bc1f  .L7F02F7F8
   nop   
  lui   $at, %hi(D_80052008)
  b     .L7F02F7FC
   lwc1  $f12, %lo(D_80052008)($at)
.L7F02F7F8:
  lwc1  $f12, %lo(D_8005200C)($at)
.L7F02F7FC:
  lui   $at, %hi(D_80052010)
  lwc1  $f0, %lo(D_80052010)($at)
.L7F02F804:
  lwc1  $f2, 0xa4($t7)
  mfc1  $a1, $f14
  swc1  $f14, 0x3c($sp)
  mul.s $f12, $f12, $f2
  sw    $v1, 0x24($sp)
  addiu $a0, $sp, 0x38
  mul.s $f0, $f0, $f2
  lw    $a2, 0x5c($sp)
  swc1  $f12, 0x14($sp)
  add.s $f18, $f0, $f0
  mfc1  $a3, $f0
  jal   sub_GAME_7F04310C
   swc1  $f18, 0x10($sp)
  lwc1  $f14, 0x3c($sp)
  lwc1  $f4, 0x38($sp)
  lw    $v1, 0x24($sp)
  lw    $t8, 0x5c($sp)
  c.eq.s $f4, $f14
  nop   
  bc1fl .L7F02F868
   lw    $a0, 0x48($sp)
  mtc1  $zero, $f6
  li    $v1, 1
  swc1  $f6, ($t8)
  lw    $a0, 0x48($sp)
.L7F02F868:
  lw    $a1, 0x38($sp)
  jal   setsubroty
   sw    $v1, 0x24($sp)
  lw    $ra, 0x1c($sp)
  lw    $v0, 0x24($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02F888
  addiu $sp, $sp, -0x50
  sw    $ra, 0x2c($sp)
  sw    $s0, 0x20($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  move  $s0, $a0
  lw    $s1, 0x1c($a0)
  jal   get_curplayer_positiondata
   lw    $s2, 0x18($a0)
  lui   $t7, %hi(clock_timer) 
  lw    $t7, %lo(clock_timer)($t7)
  lw    $t6, 0x30($s0)
  lui   $a0, %hi(global_timer)
  lb    $t0, 9($s0)
  addu  $t8, $t6, $t7
  addiu $a0, %lo(global_timer) # addiu $a0, $a0, -0x7c84
  sw    $t8, 0x30($s0)
  lw    $t9, ($a0)
  li    $at, 1
  move  $v1, $v0
  beq   $t0, $at, .L7F02F908
   sw    $t9, 0xc8($s0)
  lw    $t2, ($a0)
  lw    $t1, 0xcc($s0)
  addiu $t3, $t2, -0x3c
  slt   $at, $t1, $t3
  bnez  $at, .L7F02F908
   nop   
  lw    $t4, 0x34($s0)
  slt   $at, $t4, $t8
  beql  $at, $zero, .L7F02F9D8
   lwc1  $f18, 8($v0)
.L7F02F908:
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  swc1  $f0, 0x34($sp)
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lhu   $t6, 4($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s1
  mtc1  $t6, $f4
  li    $a1, 0
  bgez  $t6, .L7F02F944
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F02F944:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lwc1  $f18, 0x34($sp)
  mul.s $f16, $f6, $f10
  c.lt.s $f16, $f18
  nop   
  bc1f  .L7F02F974
   nop   
  jal   sub_GAME_7F06FE90
   lui   $a2, 0x4180
  b     .L7F02F9BC
   nop   
.L7F02F974:
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lhu   $t7, 4($v0)
  move  $a0, $s1
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t7, $f4
  bgez  $t7, .L7F02F9A0
   cvt.s.w $f8, $f4
  mtc1  $at, $f6
  nop   
  add.s $f8, $f8, $f6
.L7F02F9A0:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f10
  lui   $a2, 0x4180
  mul.s $f16, $f8, $f10
  mfc1  $a1, $f16
  jal   sub_GAME_7F06FE90
   nop   
.L7F02F9BC:
  jal   sub_GAME_7F029BB0
   move  $a0, $s0
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F02FC20
   lw    $ra, 0x2c($sp)
  lwc1  $f18, 8($v0)
.L7F02F9D8:
  lwc1  $f4, 8($s2)
  li    $at, 0x43960000 # 300.000000
  mtc1  $at, $f12
  sub.s $f0, $f18, $f4
  lwc1  $f6, 0x10($v0)
  lwc1  $f8, 0x10($s2)
  li    $at, 0xC3960000 # -300.000000
  c.lt.s $f0, $f12
  move  $a0, $s0
  addiu $a1, $v1, 8
  move  $a2, $zero
  bc1f  .L7F02FA5C
   sub.s $f2, $f6, $f8
  mtc1  $at, $f14
  nop   
  c.lt.s $f14, $f0
  nop   
  bc1f  .L7F02FA5C
   nop   
  c.lt.s $f2, $f12
  nop   
  bc1f  .L7F02FA5C
   nop   
  c.lt.s $f14, $f2
  nop   
  bc1f  .L7F02FA5C
   nop   
  jal   sub_GAME_7F029BB0
   move  $a0, $s0
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F02FC20
   lw    $ra, 0x2c($sp)
.L7F02FA5C:
  jal   sub_GAME_7F02F690
   addiu $a3, $s0, 0x54
  beqz  $v0, .L7F02FA70
   li    $t8, 1
  sw    $t8, 0x38($s0)
.L7F02FA70:
  lw    $t9, 0x30($s0)
  move  $a0, $s0
  slti  $at, $t9, 0x15
  bnez  $at, .L7F02FAA4
   li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lw    $a1, 0x3c($s0)
  lb    $a2, 0x49($s0)
  lb    $a3, 0x48($s0)
  jal   sub_GAME_7F02C4C0
   swc1  $f10, 0x10($sp)
  b     .L7F02FAB0
   lw    $t0, 0x38($s0)
.L7F02FAA4:
  jal   sub_GAME_7F02D0F8
   move  $a0, $s0
  lw    $t0, 0x38($s0)
.L7F02FAB0:
  move  $a0, $s0
  li    $a1, 1
  beqz  $t0, .L7F02FC04
   nop   
  lw    $t2, 0x30($s0)
  move  $s1, $zero
  move  $s2, $s0
  slti  $at, $t2, 0x1f
  bnez  $at, .L7F02FC04
   nop   
.L7F02FAD8:
  lb    $t1, 0x48($s2)
  move  $a0, $s0
  move  $a1, $s1
  beqz  $t1, .L7F02FBE4
   nop   
  lb    $t3, 0x4a($s2)
  move  $a0, $s0
  move  $a1, $s1
  bnezl $t3, .L7F02FB14
   lw    $v0, 0x30($s0)
  jal   sub_GAME_7F02D1C4
   li    $a2, 1
  b     .L7F02FBF0
   addiu $s1, $s1, 1
  lw    $v0, 0x30($s0)
.L7F02FB14:
  lw    $t4, 0x40($s0)
  move  $a0, $s0
  move  $a1, $s1
  slt   $at, $t4, $v0
  beqz  $at, .L7F02FBD4
   nop   
  lw    $v1, 0x44($s0)
  negu  $t7, $s1
  addu  $t8, $s0, $t7
  beq   $s1, $v1, .L7F02FB4C
   addu  $t5, $s0, $v1
  lb    $t6, 0x4a($t5)
  bnez  $t6, .L7F02FBD4
   nop   
.L7F02FB4C:
  sw    $v0, 0x40($s0)
  lb    $t9, 0x4b($t8)
  li    $t2, 1
  move  $a0, $s0
  beql  $t9, $zero, .L7F02FB90
   lb    $t5, 0x4c($s2)
  lb    $t0, 0x4c($s2)
  addiu $t1, $v0, 0x5a
  beql  $t0, $zero, .L7F02FB80
   lw    $t3, 0x40($s0)
  b     .L7F02FBB4
   sw    $t1, 0x40($s0)
  lw    $t3, 0x40($s0)
.L7F02FB80:
  addiu $t4, $t3, 0x14
  b     .L7F02FBB4
   sw    $t4, 0x40($s0)
  lb    $t5, 0x4c($s2)
.L7F02FB90:
  beql  $t5, $zero, .L7F02FBAC
   lw    $t8, 0x40($s0)
  lw    $t6, 0x40($s0)
  addiu $t7, $t6, 0xb4
  b     .L7F02FBB4
   sw    $t7, 0x40($s0)
  lw    $t8, 0x40($s0)
.L7F02FBAC:
  addiu $t9, $t8, 0x28
  sw    $t9, 0x40($s0)
.L7F02FBB4:
  lw    $t0, 0x44($s0)
  move  $a1, $s1
  li    $a2, 1
  subu  $t1, $t2, $t0
  jal   sub_GAME_7F02D1C4
   sw    $t1, 0x44($s0)
  b     .L7F02FBF0
   addiu $s1, $s1, 1
.L7F02FBD4:
  jal   sub_GAME_7F02D1C4
   move  $a2, $zero
  b     .L7F02FBF0
   addiu $s1, $s1, 1
.L7F02FBE4:
  jal   sub_GAME_7F02D1C4
   move  $a2, $zero
  addiu $s1, $s1, 1
.L7F02FBF0:
  li    $at, 2
  bne   $s1, $at, .L7F02FAD8
   addiu $s2, $s2, 1
  b     .L7F02FC20
   lw    $ra, 0x2c($sp)
.L7F02FC04:
  jal   sub_GAME_7F02D1C4
   move  $a2, $zero
  move  $a0, $s0
  move  $a1, $zero
  jal   sub_GAME_7F02D1C4
   move  $a2, $zero
  lw    $ra, 0x2c($sp)
.L7F02FC20:
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F02FC34
  lwc1  $f4, ($a2)
  lwc1  $f6, ($a0)
  addiu $sp, $sp, -0x10
  mtc1  $zero, $f16
  sub.s $f8, $f4, $f6
  mtc1  $a3, $f12
  swc1  $f8, 4($sp)
  lwc1  $f4, 8($a0)
  lwc1  $f10, 8($a2)
  sub.s $f6, $f10, $f4
  swc1  $f6, 0xc($sp)
  lwc1  $f0, ($a1)
  lwc1  $f10, 0xc($sp)
  c.eq.s $f16, $f0
  nop   
  bc1fl .L7F02FCC8
   lwc1  $f2, 8($a1)
  lwc1  $f8, 8($a1)
  lwc1  $f2, 0xc($sp)
  c.eq.s $f16, $f8
  nop   
  bc1fl .L7F02FCC8
   lwc1  $f2, 8($a1)
  mul.s $f10, $f2, $f2
  lwc1  $f0, 4($sp)
  move  $v0, $zero
  mul.s $f4, $f0, $f0
  add.s $f6, $f10, $f4
  mul.s $f8, $f12, $f12
  c.le.s $f6, $f8
  nop   
  bc1f  .L7F02FD48
   nop   
  li    $v0, 1
  b     .L7F02FD48
   nop   
  lwc1  $f2, 8($a1)
.L7F02FCC8:
  lwc1  $f8, 4($sp)
  move  $v0, $zero
  mul.s $f4, $f10, $f2
  nop   
  mul.s $f6, $f0, $f8
  add.s $f14, $f4, $f6
  c.lt.s $f16, $f14
  nop   
  bc1f  .L7F02FD48
   nop   
  mul.s $f4, $f2, $f2
  nop   
  mul.s $f6, $f0, $f0
  add.s $f16, $f4, $f6
  mul.s $f4, $f10, $f10
  nop   
  mul.s $f6, $f8, $f8
  nop   
  mul.s $f10, $f14, $f14
  nop   
  mul.s $f8, $f12, $f12
  add.s $f18, $f4, $f6
  sub.s $f4, $f18, $f8
  mul.s $f6, $f4, $f16
  c.le.s $f6, $f10
  nop   
  bc1f  .L7F02FD40
   nop   
  b     .L7F02FD48
   li    $v0, 1
.L7F02FD40:
  b     .L7F02FD48
   move  $v0, $zero
.L7F02FD48:
  jr    $ra
   addiu $sp, $sp, 0x10
");

asm(R"
glabel sub_GAME_7F02FD50
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  mtc1  $a3, $f12
  lwc1  $f0, ($a2)
  lwc1  $f16, ($a0)
  move  $s0, $a1
  sub.s $f2, $f0, $f12
  c.le.s $f16, $f2
  nop   
  bc1fl .L7F02FDA0
   add.s $f2, $f0, $f12
  lwc1  $f4, ($a1)
  c.le.s $f4, $f2
  nop   
  bc1fl .L7F02FDA0
   add.s $f2, $f0, $f12
  b     .L7F02FE64
   move  $v0, $zero
  add.s $f2, $f0, $f12
.L7F02FDA0:
  c.le.s $f2, $f16
  nop   
  bc1fl .L7F02FDD0
   lwc1  $f0, 8($a2)
  lwc1  $f6, ($s0)
  c.le.s $f2, $f6
  nop   
  bc1fl .L7F02FDD0
   lwc1  $f0, 8($a2)
  b     .L7F02FE64
   move  $v0, $zero
  lwc1  $f0, 8($a2)
.L7F02FDD0:
  lwc1  $f14, 8($a0)
  sub.s $f2, $f0, $f12
  c.le.s $f14, $f2
  nop   
  bc1fl .L7F02FE08
   add.s $f2, $f0, $f12
  lwc1  $f8, 8($s0)
  c.le.s $f8, $f2
  nop   
  bc1fl .L7F02FE08
   add.s $f2, $f0, $f12
  b     .L7F02FE64
   move  $v0, $zero
  add.s $f2, $f0, $f12
.L7F02FE08:
  c.le.s $f2, $f14
  nop   
  bc1fl .L7F02FE38
   lwc1  $f18, ($s0)
  lwc1  $f10, 8($s0)
  c.le.s $f2, $f10
  nop   
  bc1fl .L7F02FE38
   lwc1  $f18, ($s0)
  b     .L7F02FE64
   move  $v0, $zero
  lwc1  $f18, ($s0)
.L7F02FE38:
  mtc1  $zero, $f6
  mfc1  $a3, $f12
  sub.s $f4, $f18, $f16
  swc1  $f6, 0x38($sp)
  addiu $a1, $sp, 0x34
  swc1  $f4, 0x34($sp)
  lwc1  $f10, 8($a0)
  lwc1  $f8, 8($s0)
  sub.s $f18, $f8, $f10
  jal   sub_GAME_7F02FC34
   swc1  $f18, 0x3c($sp)
.L7F02FE64:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F02FE78
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lui   $v1, %hi(global_timer)
  lb    $t7, 9($a0)
  addiu $v1, %lo(global_timer) # addiu $v1, $v1, -0x7c84
  lw    $t6, ($v1)
  li    $at, 1
  move  $s0, $a0
  lw    $v0, 0x18($a0)
  lw    $s1, 0x1c($a0)
  beq   $t7, $at, .L7F02FEE4
   sw    $t6, 0xc8($a0)
  lw    $t9, ($v1)
  lw    $t8, 0xcc($a0)
  addiu $a0, $a0, 0xbc
  addiu $t0, $t9, -0x3c
  slt   $at, $t8, $t0
  bnez  $at, .L7F02FEE4
   addiu $a1, $v0, 8
  addiu $a2, $s0, 0x2c
  lw    $a3, 0x38($s0)
  jal   sub_GAME_7F02FD50
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F030080
   move  $a0, $s0
.L7F02FEE4:
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  jal   sub_GAME_7F06F5BC
   move  $a0, $s1
  mtc1  $zero, $f6
  mtc1  $zero, $f4
  move  $a0, $s1
  c.lt.s $f0, $f6
  sub.s $f2, $f0, $f4
  bc1fl .L7F02FF44
   move  $a0, $s1
  jal   sub_GAME_7F06F5AC
   swc1  $f2, 0x34($sp)
  lhu   $t1, 4($v0)
  lwc1  $f2, 0x34($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t1, $f8
  bgez  $t1, .L7F02FF3C
   cvt.s.w $f10, $f8
  mtc1  $at, $f16
  nop   
  add.s $f10, $f10, $f16
.L7F02FF3C:
  add.s $f2, $f2, $f10
  move  $a0, $s1
.L7F02FF44:
  jal   sub_GAME_7F06F5AC
   swc1  $f2, 0x34($sp)
  lhu   $t2, 4($v0)
  lwc1  $f2, 0x34($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t2, $f18
  bgez  $t2, .L7F02FF70
   cvt.s.w $f4, $f18
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F02FF70:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f8
  nop   
  mul.s $f16, $f4, $f8
  c.lt.s $f16, $f2
  nop   
  bc1f  .L7F02FFDC
   nop   
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lhu   $t3, 4($v0)
  mtc1  $zero, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t3, $f10
  bgez  $t3, .L7F02FFBC
   cvt.s.w $f18, $f10
  mtc1  $at, $f6
  nop   
  add.s $f18, $f18, $f6
.L7F02FFBC:
  sub.s $f2, $f18, $f4
  move  $a0, $s1
  lui   $a2, 0x4180
  mfc1  $a1, $f2
  jal   sub_GAME_7F06FE90
   nop   
  b     .L7F030070
   nop   
.L7F02FFDC:
  jal   sub_GAME_7F06F5AC
   move  $a0, $s1
  lhu   $t4, 4($v0)
  li    $at, 0x4F800000 # 4294967296.000000
  move  $a0, $s1
  mtc1  $t4, $f8
  bgez  $t4, .L7F030008
   cvt.s.w $f16, $f8
  mtc1  $at, $f10
  nop   
  add.s $f16, $f16, $f10
.L7F030008:
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  mtc1  $zero, $f4
  mtc1  $zero, $f8
  mul.s $f18, $f16, $f6
  sub.s $f2, $f18, $f4
  c.lt.s $f2, $f8
  nop   
  bc1fl .L7F030064
   mfc1  $a1, $f2
  jal   sub_GAME_7F06F5AC
   swc1  $f2, 0x34($sp)
  lhu   $t5, 4($v0)
  lwc1  $f2, 0x34($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t5, $f10
  bgez  $t5, .L7F03005C
   cvt.s.w $f16, $f10
  mtc1  $at, $f6
  nop   
  add.s $f16, $f16, $f6
.L7F03005C:
  add.s $f2, $f2, $f16
  mfc1  $a1, $f2
.L7F030064:
  move  $a0, $s1
  jal   sub_GAME_7F06FE90
   lui   $a2, 0x4180
.L7F030070:
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F030118
   lw    $ra, 0x1c($sp)
.L7F030080:
  lw    $a1, 0x20($sp)
  li    $a2, 1
  jal   sub_GAME_7F02F690
   addiu $a3, $s0, 0x40
  lw    $v1, 0x3c($s0)
  lui   $t6, %hi(clock_timer) 
  lui   $at, %hi(D_80030988)
  blez  $v1, .L7F0300B4
   nop   
  lw    $t6, %lo(clock_timer)($t6)
  subu  $t7, $v1, $t6
  b     .L7F030114
   sw    $t7, 0x3c($s0)
.L7F0300B4:
  lwc1  $f18, %lo(D_80030988)($at)
  move  $a0, $s1
  jal   sub_GAME_7F06F5AC
   swc1  $f18, 0x2c($sp)
  lui   $t9, %hi(ptr_animation_table) 
  lw    $t9, %lo(ptr_animation_table)($t9)
  lui   $t8, %hi(0x0000777C) # $t8, 0
  addiu $t8, %lo(0x0000777C) # addiu $t8, $t8, 0x777c
  addu  $t0, $t9, $t8
  bne   $v0, $t0, .L7F0300E8
   lui   $at, %hi(D_80030994)
  lwc1  $f4, %lo(D_80030994)($at)
  swc1  $f4, 0x2c($sp)
.L7F0300E8:
  jal   sub_GAME_7F06F618
   move  $a0, $s1
  lui   $at, %hi(global_timer_delta)
  lwc1  $f10, %lo(global_timer_delta)($at)
  lwc1  $f8, 0x2c($sp)
  lwc1  $f18, 0x38($s0)
  mul.s $f6, $f8, $f10
  nop   
  mul.s $f16, $f6, $f0
  add.s $f4, $f18, $f16
  swc1  $f4, 0x38($s0)
.L7F030114:
  lw    $ra, 0x1c($sp)
.L7F030118:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
glabel sub_GAME_7F030128
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  sw    $a3, 0x54($sp)
  sw    $a2, 0x44($sp)
  sw    $zero, 0x40($sp)
  lw    $a0, 0x18($a0)
  addiu $a2, $sp, 0x3c
  addiu $a3, $sp, 0x38
  jal   sub_GAME_7F023160
   addiu $a1, $sp, 0x34
  lw    $a0, 0x48($sp)
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  lw    $v0, 0x4c($sp)
  lw    $v1, 0x54($sp)
  li    $at, 0x3F800000 # 1.000000
  lw    $a1, ($v0)
  lwc1  $f4, 8($v1)
  lw    $a2, 8($v0)
  lw    $a3, ($v1)
  mtc1  $at, $f16
  lw    $t8, 0x5c($sp)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f8, 0x38($sp)
  mtc1  $zero, $f10
  addiu $a0, $sp, 0x44
  swc1  $f4, 0x10($sp)
  sw    $t8, 0x14($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F0301E0
   li    $a1, 1
  lw    $v0, 0x58($sp)
  lw    $t9, 0x44($sp)
  li    $t0, 1
  beql  $v0, $zero, .L7F0301E0
   sw    $t0, 0x40($sp)
  bne   $t9, $v0, .L7F0301E0
   nop   
  sw    $t0, 0x40($sp)
.L7F0301E0:
  jal   set_or_unset_GUARDdata_flag
   lw    $a0, 0x48($sp)
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x40($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0301FC
  addiu $sp, $sp, -0x88
  sw    $s1, 0x48($sp)
  sw    $s0, 0x44($sp)
  move  $s0, $a1
  move  $s1, $a3
  sw    $ra, 0x4c($sp)
  sdc1  $f24, 0x38($sp)
  sdc1  $f22, 0x30($sp)
  sdc1  $f20, 0x28($sp)
  sw    $a0, 0x88($sp)
  sw    $a2, 0x90($sp)
  sw    $zero, 0x68($sp)
  lw    $a0, 0x18($a0)
  addiu $a2, $sp, 0x64
  addiu $a3, $sp, 0x60
  jal   sub_GAME_7F023160
   addiu $a1, $sp, 0x5c
  lwc1  $f4, ($s1)
  lwc1  $f6, ($s0)
  mtc1  $zero, $f24
  sub.s $f8, $f4, $f6
  swc1  $f24, 0x7c($sp)
  swc1  $f8, 0x78($sp)
  lwc1  $f6, 0x78($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f10, 8($s1)
  c.eq.s $f24, $f6
  sub.s $f4, $f10, $f18
  bc1f  .L7F030294
   swc1  $f4, 0x80($sp)
  lwc1  $f16, 0x80($sp)
  li    $t7, 1
  c.eq.s $f24, $f16
  nop   
  bc1fl .L7F030298
   lwc1  $f16, 0x80($sp)
  b     .L7F030488
   sw    $t7, 0x68($sp)
.L7F030294:
  lwc1  $f16, 0x80($sp)
.L7F030298:
  lwc1  $f14, 0x78($sp)
  mul.s $f8, $f16, $f16
  nop   
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lwc1  $f14, 0x78($sp)
  lwc1  $f16, 0x80($sp)
  div.s $f2, $f18, $f0
  lwc1  $f12, 0x98($sp)
  lw    $a0, 0x88($sp)
  move  $a1, $zero
  mul.s $f14, $f14, $f2
  nop   
  mul.s $f16, $f16, $f2
  nop   
  mul.s $f20, $f14, $f12
  swc1  $f14, 0x78($sp)
  mul.s $f22, $f16, $f12
  jal   set_or_unset_GUARDdata_flag
   swc1  $f16, 0x80($sp)
  lw    $t8, 0x90($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  sw    $t8, 0x84($sp)
  lwc1  $f0, ($s0)
  lwc1  $f2, 8($s0)
  lw    $t9, 0x9c($sp)
  add.s $f4, $f0, $f22
  lwc1  $f8, 0x64($sp)
  lwc1  $f10, 0x60($sp)
  sub.s $f6, $f2, $f20
  mfc1  $a3, $f4
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  swc1  $f6, 0x10($sp)
  swc1  $f24, 0x20($sp)
  addiu $a0, $sp, 0x84
  swc1  $f18, 0x24($sp)
  sw    $t9, 0x14($sp)
  swc1  $f8, 0x18($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x1c($sp)
  beqz  $v0, .L7F03047C
   addiu $a0, $sp, 0x84
  lwc1  $f4, ($s0)
  lwc1  $f8, 8($s0)
  lwc1  $f18, ($s1)
  add.s $f6, $f4, $f22
  li    $at, 0x3F800000 # 1.000000
  lw    $t0, 0x9c($sp)
  sub.s $f10, $f8, $f20
  mfc1  $a1, $f6
  lwc1  $f6, 8($s1)
  add.s $f4, $f18, $f22
  mfc1  $a2, $f10
  lwc1  $f10, 0x64($sp)
  sub.s $f8, $f6, $f20
  mfc1  $a3, $f4
  mtc1  $at, $f4
  lwc1  $f18, 0x60($sp)
  swc1  $f8, 0x10($sp)
  swc1  $f24, 0x20($sp)
  sw    $t0, 0x14($sp)
  swc1  $f10, 0x18($sp)
  swc1  $f18, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x24($sp)
  beqz  $v0, .L7F03047C
   lw    $t1, 0x90($sp)
  sw    $t1, 0x84($sp)
  lwc1  $f0, ($s0)
  lwc1  $f2, 8($s0)
  li    $at, 0x3F800000 # 1.000000
  sub.s $f6, $f0, $f22
  mtc1  $at, $f4
  lw    $t2, 0x9c($sp)
  add.s $f8, $f2, $f20
  lwc1  $f10, 0x64($sp)
  lwc1  $f18, 0x60($sp)
  mfc1  $a3, $f6
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  swc1  $f8, 0x10($sp)
  swc1  $f24, 0x20($sp)
  addiu $a0, $sp, 0x84
  sw    $t2, 0x14($sp)
  swc1  $f4, 0x24($sp)
  swc1  $f10, 0x18($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f18, 0x1c($sp)
  beqz  $v0, .L7F03047C
   addiu $a0, $sp, 0x84
  lwc1  $f6, ($s0)
  lwc1  $f10, 8($s0)
  lwc1  $f4, ($s1)
  sub.s $f8, $f6, $f22
  li    $at, 0x3F800000 # 1.000000
  lw    $t3, 0x9c($sp)
  add.s $f18, $f10, $f20
  mfc1  $a1, $f8
  lwc1  $f8, 8($s1)
  sub.s $f6, $f4, $f22
  mfc1  $a2, $f18
  lwc1  $f18, 0x64($sp)
  add.s $f10, $f8, $f20
  mfc1  $a3, $f6
  mtc1  $at, $f6
  lwc1  $f4, 0x60($sp)
  swc1  $f10, 0x10($sp)
  swc1  $f24, 0x20($sp)
  sw    $t3, 0x14($sp)
  swc1  $f18, 0x18($sp)
  swc1  $f4, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f6, 0x24($sp)
  beqz  $v0, .L7F03047C
   li    $t4, 1
  sw    $t4, 0x68($sp)
.L7F03047C:
  lw    $a0, 0x88($sp)
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
.L7F030488:
  lw    $ra, 0x4c($sp)
  lw    $v0, 0x68($sp)
  ldc1  $f20, 0x28($sp)
  ldc1  $f22, 0x30($sp)
  ldc1  $f24, 0x38($sp)
  lw    $s0, 0x44($sp)
  lw    $s1, 0x48($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F0304AC
  addiu $sp, $sp, -0x48
  sw    $ra, 0x2c($sp)
  sw    $a0, 0x48($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  sw    $a3, 0x54($sp)
  sw    $a2, 0x44($sp)
  sw    $zero, 0x40($sp)
  lw    $a0, 0x18($a0)
  addiu $a2, $sp, 0x3c
  addiu $a3, $sp, 0x38
  jal   sub_GAME_7F023160
   addiu $a1, $sp, 0x34
  lw    $a0, 0x48($sp)
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  lw    $v0, 0x54($sp)
  lw    $v1, 0x4c($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f4, 8($v0)
  lw    $a3, ($v0)
  lw    $a1, ($v1)
  lw    $a2, 8($v1)
  mtc1  $at, $f16
  lw    $t8, 0x60($sp)
  lwc1  $f6, 0x3c($sp)
  lwc1  $f8, 0x38($sp)
  mtc1  $zero, $f10
  addiu $a0, $sp, 0x44
  swc1  $f4, 0x10($sp)
  sw    $t8, 0x14($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F0305C0
   lw    $t9, 0x44($sp)
  lw    $v0, 0x58($sp)
  lw    $t0, 0x54($sp)
  sw    $t9, 0x30($sp)
  lwc1  $f18, 8($v0)
  lw    $a3, ($v0)
  lw    $a2, 8($t0)
  lw    $a1, ($t0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lw    $t1, 0x60($sp)
  lwc1  $f4, 0x3c($sp)
  lwc1  $f6, 0x38($sp)
  mtc1  $zero, $f8
  addiu $a0, $sp, 0x30
  swc1  $f18, 0x10($sp)
  sw    $t1, 0x14($sp)
  swc1  $f10, 0x24($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f6, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x20($sp)
  beql  $v0, $zero, .L7F0305C4
   lw    $a0, 0x48($sp)
  lw    $v0, 0x5c($sp)
  lw    $t2, 0x30($sp)
  li    $t3, 1
  beql  $v0, $zero, .L7F0305C0
   sw    $t3, 0x40($sp)
  bnel  $t2, $v0, .L7F0305C4
   lw    $a0, 0x48($sp)
  sw    $t3, 0x40($sp)
.L7F0305C0:
  lw    $a0, 0x48($sp)
.L7F0305C4:
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $ra, 0x2c($sp)
  lw    $v0, 0x40($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0305E0
  addiu $sp, $sp, -0x50
  sw    $s1, 0x30($sp)
  sw    $s0, 0x2c($sp)
  move  $s0, $a3
  move  $s1, $a0
  sw    $ra, 0x34($sp)
  sw    $a1, 0x54($sp)
  sw    $a2, 0x58($sp)
  sw    $a2, 0x4c($sp)
  sw    $zero, 0x48($sp)
  lw    $a0, 0x18($a0)
  addiu $a2, $sp, 0x44
  addiu $a1, $sp, 0x3c
  jal   sub_GAME_7F023160
   addiu $a3, $sp, 0x40
  move  $a0, $s1
  jal   set_or_unset_GUARDdata_flag
   move  $a1, $zero
  lw    $v0, 0x54($sp)
  lwc1  $f4, 8($s0)
  lw    $a3, ($s0)
  lw    $a1, ($v0)
  lw    $a2, 8($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lw    $t7, 0x68($sp)
  lwc1  $f6, 0x44($sp)
  lwc1  $f8, 0x40($sp)
  mtc1  $zero, $f10
  addiu $a0, $sp, 0x4c
  swc1  $f4, 0x10($sp)
  sw    $t7, 0x14($sp)
  swc1  $f16, 0x24($sp)
  swc1  $f6, 0x18($sp)
  swc1  $f8, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F030728
   lw    $t8, 0x4c($sp)
  lw    $v0, 0x60($sp)
  sw    $t8, 0x38($sp)
  lw    $a2, 8($s0)
  lwc1  $f18, 8($v0)
  lw    $a1, ($s0)
  lw    $a3, ($v0)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lw    $t9, 0x68($sp)
  lwc1  $f4, 0x44($sp)
  lwc1  $f6, 0x40($sp)
  mtc1  $zero, $f8
  addiu $a0, $sp, 0x38
  swc1  $f18, 0x10($sp)
  sw    $t9, 0x14($sp)
  swc1  $f10, 0x24($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f6, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x20($sp)
  beqz  $v0, .L7F030728
   move  $a0, $s1
  lwc1  $f16, 0x64($sp)
  lw    $t0, 0x68($sp)
  lw    $a1, 0x54($sp)
  lw    $a2, 0x58($sp)
  move  $a3, $s0
  swc1  $f16, 0x10($sp)
  jal   sub_GAME_7F0301FC
   sw    $t0, 0x14($sp)
  beqz  $v0, .L7F030728
   move  $a0, $s1
  lwc1  $f18, 0x64($sp)
  lw    $t1, 0x68($sp)
  move  $a1, $s0
  lw    $a2, 0x4c($sp)
  lw    $a3, 0x60($sp)
  swc1  $f18, 0x10($sp)
  jal   sub_GAME_7F0301FC
   sw    $t1, 0x14($sp)
  beqz  $v0, .L7F030728
   li    $t2, 1
  sw    $t2, 0x48($sp)
.L7F030728:
  move  $a0, $s1
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $ra, 0x34($sp)
  lw    $v0, 0x48($sp)
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel sub_GAME_7F03074C
  lwc1  $f4, ($a1)
  lwc1  $f6, ($a0)
  addiu $sp, $sp, -0x18
  mtc1  $zero, $f0
  sub.s $f8, $f4, $f6
  swc1  $f8, 0xc($sp)
  lwc1  $f16, 4($a0)
  lwc1  $f10, 4($a1)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x10($sp)
  lwc1  $f6, 8($a0)
  lwc1  $f4, 8($a1)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x14($sp)
  lwc1  $f10, 8($a2)
  swc1  $f0, 4($sp)
  lwc1  $f4, 0x14($sp)
  neg.s $f16, $f10
  swc1  $f16, ($sp)
  lwc1  $f18, ($a2)
  lwc1  $f10, ($sp)
  lwc1  $f16, 0xc($sp)
  swc1  $f18, 8($sp)
  lwc1  $f6, 8($sp)
  mul.s $f8, $f4, $f6
  nop   
  mul.s $f18, $f10, $f16
  add.s $f4, $f8, $f18
  c.lt.s $f0, $f4
  nop   
  bc1t  .L7F030814
   nop   
  lwc1  $f6, ($a0)
  swc1  $f6, 0xc($sp)
  lwc1  $f10, 4($a0)
  swc1  $f10, 0x10($sp)
  lwc1  $f16, 8($a0)
  swc1  $f16, 0x14($sp)
  lwc1  $f8, ($a1)
  swc1  $f8, ($a0)
  lwc1  $f18, 4($a1)
  swc1  $f18, 4($a0)
  lwc1  $f4, 8($a1)
  swc1  $f4, 8($a0)
  lwc1  $f6, 0xc($sp)
  swc1  $f6, ($a1)
  lwc1  $f10, 0x10($sp)
  swc1  $f10, 4($a1)
  lwc1  $f16, 0x14($sp)
  swc1  $f16, 8($a1)
.L7F030814:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
.late_rodata
glabel D_80052014
.word 0x3f733333 /*0.94999999*/
glabel D_80052018
.word 0x3f733333 /*0.94999999*/
glabel D_8005201C
.word 0x3f99999a /*1.2*/
glabel D_80052020
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F03081C
  addiu $sp, $sp, -0xb0
  sw    $s0, 0x30($sp)
  move  $s0, $a1
  sw    $ra, 0x34($sp)
  sw    $a0, 0xb0($sp)
  sw    $a2, 0xb8($sp)
  sw    $a3, 0xbc($sp)
  sw    $zero, 0x88($sp)
  sw    $zero, 0x84($sp)
  sw    $zero, 0x50($sp)
  lw    $a0, 0x18($a0)
  addiu $a3, $sp, 0x48
  addiu $a2, $sp, 0x4c
  jal   sub_GAME_7F023160
   addiu $a1, $sp, 0x44
  lw    $v0, 0xbc($sp)
  lwc1  $f6, ($s0)
  mtc1  $zero, $f0
  lwc1  $f4, ($v0)
  swc1  $f0, 0xa4($sp)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0xa0($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f10, 8($v0)
  c.eq.s $f0, $f8
  sub.s $f6, $f10, $f4
  bc1f  .L7F0308AC
   swc1  $f6, 0xa8($sp)
  lwc1  $f18, 0xa8($sp)
  c.eq.s $f0, $f18
  nop   
  bc1fl .L7F0308B0
   lwc1  $f18, 0xa8($sp)
  b     .L7F030D5C
   li    $v0, 1
.L7F0308AC:
  lwc1  $f18, 0xa8($sp)
.L7F0308B0:
  lwc1  $f16, 0xa0($sp)
  mul.s $f10, $f18, $f18
  nop   
  mul.s $f4, $f16, $f16
  jal   sqrtf
   add.s $f12, $f10, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f16, 0xa0($sp)
  lwc1  $f18, 0xa8($sp)
  div.s $f2, $f6, $f0
  lwc1  $f8, 0xcc($sp)
  lui   $at, %hi(D_80052014)
  lwc1  $f10, %lo(D_80052014)($at)
  lui   $at, %hi(D_80052018)
  lwc1  $f6, %lo(D_80052018)($at)
  lui   $at, %hi(D_8005201C)
  lw    $a0, 0xb0($sp)
  move  $a1, $zero
  mul.s $f16, $f16, $f2
  nop   
  mul.s $f18, $f18, $f2
  nop   
  mul.s $f12, $f16, $f8
  swc1  $f16, 0xa0($sp)
  swc1  $f18, 0xa8($sp)
  mul.s $f4, $f12, $f10
  nop   
  mul.s $f14, $f18, $f8
  swc1  $f4, 0x9c($sp)
  lwc1  $f4, %lo(D_8005201C)($at)
  lui   $at, %hi(D_80052020)
  mul.s $f10, $f14, $f6
  lwc1  $f6, %lo(D_80052020)($at)
  mul.s $f8, $f12, $f4
  swc1  $f10, 0x98($sp)
  mul.s $f10, $f14, $f6
  swc1  $f8, 0x94($sp)
  jal   set_or_unset_GUARDdata_flag
   swc1  $f10, 0x90($sp)
  jal   sub_GAME_7F0B1CC4
   nop   
  lw    $t7, 0xb8($sp)
  lwc1  $f4, 0x98($sp)
  lwc1  $f6, 0x9c($sp)
  sw    $t7, 0xac($sp)
  lwc1  $f2, 8($s0)
  lwc1  $f0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  sub.s $f10, $f2, $f6
  mtc1  $zero, $f6
  lw    $t8, 0xd0($sp)
  add.s $f8, $f0, $f4
  swc1  $f10, 0x10($sp)
  mtc1  $at, $f10
  lwc1  $f4, 0x4c($sp)
  mfc1  $a3, $f8
  lwc1  $f8, 0x48($sp)
  mfc1  $a2, $f2
  mfc1  $a1, $f0
  addiu $a0, $sp, 0xac
  sw    $t8, 0x14($sp)
  swc1  $f6, 0x20($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f10, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x1c($sp)
  beqz  $v0, .L7F030A58
   addiu $a0, $sp, 0xac
  lw    $v0, 0xbc($sp)
  lwc1  $f18, 0xc8($sp)
  lwc1  $f16, ($s0)
  lwc1  $f14, 0x98($sp)
  lwc1  $f12, 8($s0)
  lwc1  $f10, 0x9c($sp)
  add.s $f14, $f16, $f14
  lwc1  $f16, 0xa0($sp)
  lwc1  $f8, ($v0)
  sub.s $f10, $f12, $f10
  mul.s $f16, $f16, $f18
  lwc1  $f12, 0x90($sp)
  lwc1  $f6, 0xa8($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f2, 0x94($sp)
  mul.s $f18, $f6, $f18
  add.s $f12, $f8, $f12
  mfc1  $a1, $f14
  mfc1  $a2, $f10
  lw    $t9, 0xd0($sp)
  sub.s $f2, $f4, $f2
  lwc1  $f4, 0x4c($sp)
  lwc1  $f10, 0x48($sp)
  add.s $f12, $f16, $f12
  mtc1  $zero, $f16
  li    $at, 0x3F800000 # 1.000000
  add.s $f2, $f18, $f2
  mfc1  $a3, $f12
  mtc1  $at, $f12
  swc1  $f4, 0x18($sp)
  swc1  $f2, 0x10($sp)
  sw    $t9, 0x14($sp)
  swc1  $f10, 0x1c($sp)
  swc1  $f16, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f12, 0x24($sp)
  bnez  $v0, .L7F030A7C
.L7F030A58:
   li    $t0, 1
  sw    $t0, 0x88($sp)
  addiu $a0, $sp, 0x78
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x6c
  addiu $a0, $sp, 0x78
  addiu $a1, $sp, 0x6c
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa0
.L7F030A7C:
  lw    $t1, 0xb8($sp)
  lwc1  $f10, 0x98($sp)
  lwc1  $f4, 0x9c($sp)
  sw    $t1, 0xac($sp)
  lwc1  $f2, 8($s0)
  lwc1  $f0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  add.s $f6, $f2, $f4
  mtc1  $zero, $f4
  lw    $t2, 0xd0($sp)
  sub.s $f8, $f0, $f10
  swc1  $f6, 0x10($sp)
  mtc1  $at, $f6
  lwc1  $f10, 0x4c($sp)
  mfc1  $a3, $f8
  lwc1  $f8, 0x48($sp)
  mfc1  $a2, $f2
  mfc1  $a1, $f0
  addiu $a0, $sp, 0xac
  sw    $t2, 0x14($sp)
  swc1  $f4, 0x20($sp)
  swc1  $f10, 0x18($sp)
  swc1  $f6, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x1c($sp)
  beqz  $v0, .L7F030B7C
   addiu $a0, $sp, 0xac
  lw    $v0, 0xbc($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f16, 0x9c($sp)
  lwc1  $f14, 0xa0($sp)
  lwc1  $f12, 0xc8($sp)
  add.s $f16, $f18, $f16
  lwc1  $f18, ($v0)
  mul.s $f14, $f14, $f12
  lwc1  $f10, ($s0)
  lwc1  $f8, 0x98($sp)
  lwc1  $f6, 0x90($sp)
  lwc1  $f4, 0xa8($sp)
  sub.s $f8, $f10, $f8
  lwc1  $f10, 8($v0)
  lwc1  $f2, 0x94($sp)
  sub.s $f6, $f18, $f6
  mul.s $f12, $f4, $f12
  mfc1  $a1, $f8
  add.s $f2, $f10, $f2
  mfc1  $a2, $f16
  lw    $t3, 0xd0($sp)
  add.s $f6, $f14, $f6
  lwc1  $f14, 0x4c($sp)
  lwc1  $f16, 0x48($sp)
  add.s $f2, $f12, $f2
  mfc1  $a3, $f6
  mtc1  $zero, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  swc1  $f2, 0x10($sp)
  swc1  $f14, 0x18($sp)
  sw    $t3, 0x14($sp)
  swc1  $f16, 0x1c($sp)
  swc1  $f6, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f12, 0x24($sp)
  bnez  $v0, .L7F030BA0
.L7F030B7C:
   li    $t4, 1
  sw    $t4, 0x84($sp)
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x54
  addiu $a0, $sp, 0x60
  addiu $a1, $sp, 0x54
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa0
.L7F030BA0:
  lw    $t5, 0x88($sp)
  lw    $t6, 0x84($sp)
  lw    $t7, 0x88($sp)
  beqz  $t5, .L7F030C14
   nop   
  beqz  $t6, .L7F030C14
   addiu $a0, $sp, 0x78
  addiu $a1, $sp, 0x60
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa0
  addiu $a0, $sp, 0x6c
  addiu $a1, $sp, 0x54
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa0
  lw    $a0, 0xc0($sp)
  lwc1  $f10, 0x78($sp)
  lw    $a1, 0xc4($sp)
  swc1  $f10, ($a0)
  lwc1  $f8, 0x7c($sp)
  swc1  $f8, 4($a0)
  lwc1  $f6, 0x80($sp)
  swc1  $f6, 8($a0)
  lwc1  $f4, 0x54($sp)
  swc1  $f4, ($a1)
  lwc1  $f10, 0x58($sp)
  swc1  $f10, 4($a1)
  lwc1  $f8, 0x5c($sp)
  b     .L7F030D4C
   swc1  $f8, 8($a1)
.L7F030C14:
  beqz  $t7, .L7F030C58
   lw    $t8, 0x84($sp)
  lw    $a0, 0xc0($sp)
  lwc1  $f6, 0x78($sp)
  lw    $a1, 0xc4($sp)
  swc1  $f6, ($a0)
  lwc1  $f4, 0x7c($sp)
  swc1  $f4, 4($a0)
  lwc1  $f10, 0x80($sp)
  swc1  $f10, 8($a0)
  lwc1  $f8, 0x6c($sp)
  swc1  $f8, ($a1)
  lwc1  $f6, 0x70($sp)
  swc1  $f6, 4($a1)
  lwc1  $f4, 0x74($sp)
  b     .L7F030D4C
   swc1  $f4, 8($a1)
.L7F030C58:
  beqz  $t8, .L7F030C9C
   lw    $v0, 0xbc($sp)
  lw    $a0, 0xc0($sp)
  lwc1  $f10, 0x60($sp)
  lw    $a1, 0xc4($sp)
  swc1  $f10, ($a0)
  lwc1  $f8, 0x64($sp)
  swc1  $f8, 4($a0)
  lwc1  $f6, 0x68($sp)
  swc1  $f6, 8($a0)
  lwc1  $f4, 0x54($sp)
  swc1  $f4, ($a1)
  lwc1  $f10, 0x58($sp)
  swc1  $f10, 4($a1)
  lwc1  $f8, 0x5c($sp)
  b     .L7F030D4C
   swc1  $f8, 8($a1)
.L7F030C9C:
  lw    $t9, 0xb8($sp)
  li    $at, 0x3F800000 # 1.000000
  lw    $t0, 0xd0($sp)
  sw    $t9, 0xac($sp)
  lwc1  $f6, 8($v0)
  lw    $a3, ($v0)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  swc1  $f6, 0x10($sp)
  mtc1  $at, $f6
  lwc1  $f4, 0x4c($sp)
  lwc1  $f10, 0x48($sp)
  mtc1  $zero, $f8
  addiu $a0, $sp, 0xac
  sw    $t0, 0x14($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f10, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x20($sp)
  beqz  $v0, .L7F030D30
   addiu $a0, $sp, 0xac
  lw    $t1, 0xbc($sp)
  lw    $t2, 0xd0($sp)
  lwc1  $f4, 0x4c($sp)
  lwc1  $f10, 0x48($sp)
  lw    $a1, ($t1)
  lw    $a2, 8($t1)
  lw    $a3, 0xcc($sp)
  sw    $t2, 0x10($sp)
  swc1  $f4, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f10, 0x18($sp)
  bgez  $v0, .L7F030D30
   li    $t3, 1
  b     .L7F030D4C
   sw    $t3, 0x50($sp)
.L7F030D30:
  lw    $a0, 0xc0($sp)
  jal   sub_GAME_7F0B28B0
   lw    $a1, 0xc4($sp)
  lw    $a0, 0xc0($sp)
  lw    $a1, 0xc4($sp)
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa0
.L7F030D4C:
  lw    $a0, 0xb0($sp)
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $v0, 0x50($sp)
.L7F030D5C:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0xb0
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80052024
.word 0x3f733333 /*0.94999999*/
glabel D_80052028
.word 0x3f733333 /*0.94999999*/
glabel D_8005202C
.word 0x3f99999a /*1.2*/
glabel D_80052030
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F030D70
  addiu $sp, $sp, -0xb8
  sw    $s0, 0x30($sp)
  move  $s0, $a1
  sw    $ra, 0x34($sp)
  sw    $a0, 0xb8($sp)
  sw    $a2, 0xc0($sp)
  sw    $a3, 0xc4($sp)
  sw    $zero, 0x90($sp)
  sw    $zero, 0x8c($sp)
  sw    $zero, 0x58($sp)
  lw    $a0, 0x18($a0)
  addiu $a3, $sp, 0x48
  addiu $a2, $sp, 0x4c
  jal   sub_GAME_7F023160
   addiu $a1, $sp, 0x44
  lw    $v0, 0xc4($sp)
  lwc1  $f6, ($s0)
  mtc1  $zero, $f0
  lwc1  $f4, ($v0)
  swc1  $f0, 0xac($sp)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0xa8($sp)
  lwc1  $f8, 0xa8($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f10, 8($v0)
  c.eq.s $f0, $f8
  sub.s $f6, $f10, $f4
  bc1f  .L7F030E00
   swc1  $f6, 0xb0($sp)
  lwc1  $f18, 0xb0($sp)
  c.eq.s $f0, $f18
  nop   
  bc1fl .L7F030E04
   lwc1  $f18, 0xb0($sp)
  b     .L7F0312F8
   li    $v0, 1
.L7F030E00:
  lwc1  $f18, 0xb0($sp)
.L7F030E04:
  lwc1  $f16, 0xa8($sp)
  mul.s $f10, $f18, $f18
  nop   
  mul.s $f4, $f16, $f16
  jal   sqrtf
   add.s $f12, $f10, $f4
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f16, 0xa8($sp)
  lwc1  $f18, 0xb0($sp)
  div.s $f2, $f6, $f0
  lwc1  $f8, 0xd4($sp)
  lui   $at, %hi(D_80052024)
  lwc1  $f10, %lo(D_80052024)($at)
  lui   $at, %hi(D_80052028)
  lwc1  $f6, %lo(D_80052028)($at)
  lui   $at, %hi(D_8005202C)
  lw    $a0, 0xb8($sp)
  move  $a1, $zero
  mul.s $f16, $f16, $f2
  nop   
  mul.s $f18, $f18, $f2
  nop   
  mul.s $f12, $f16, $f8
  swc1  $f16, 0xa8($sp)
  swc1  $f18, 0xb0($sp)
  mul.s $f4, $f12, $f10
  nop   
  mul.s $f14, $f18, $f8
  swc1  $f4, 0xa4($sp)
  lwc1  $f4, %lo(D_8005202C)($at)
  lui   $at, %hi(D_80052030)
  mul.s $f10, $f14, $f6
  lwc1  $f6, %lo(D_80052030)($at)
  mul.s $f8, $f12, $f4
  swc1  $f10, 0xa0($sp)
  mul.s $f10, $f14, $f6
  swc1  $f8, 0x9c($sp)
  jal   set_or_unset_GUARDdata_flag
   swc1  $f10, 0x98($sp)
  jal   sub_GAME_7F0B1CC4
   nop   
  lw    $t7, 0xc0($sp)
  lwc1  $f4, 0xa0($sp)
  lwc1  $f6, 0xa4($sp)
  sw    $t7, 0xb4($sp)
  lwc1  $f2, 8($s0)
  lwc1  $f0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  sub.s $f10, $f2, $f6
  mtc1  $zero, $f6
  lw    $t8, 0xd8($sp)
  add.s $f8, $f0, $f4
  swc1  $f10, 0x10($sp)
  mtc1  $at, $f10
  lwc1  $f4, 0x4c($sp)
  mfc1  $a3, $f8
  lwc1  $f8, 0x48($sp)
  mfc1  $a2, $f2
  mfc1  $a1, $f0
  addiu $a0, $sp, 0xb4
  sw    $t8, 0x14($sp)
  swc1  $f6, 0x20($sp)
  swc1  $f4, 0x18($sp)
  swc1  $f10, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f8, 0x1c($sp)
  beqz  $v0, .L7F030FAC
   addiu $a0, $sp, 0xb4
  lw    $v0, 0xc4($sp)
  lwc1  $f18, 0xd0($sp)
  lwc1  $f16, ($s0)
  lwc1  $f14, 0xa0($sp)
  lwc1  $f12, 8($s0)
  lwc1  $f10, 0xa4($sp)
  add.s $f14, $f16, $f14
  lwc1  $f16, 0xa8($sp)
  lwc1  $f8, ($v0)
  sub.s $f10, $f12, $f10
  mul.s $f16, $f16, $f18
  lwc1  $f12, 0x98($sp)
  lwc1  $f6, 0xb0($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f2, 0x9c($sp)
  mul.s $f18, $f6, $f18
  add.s $f12, $f8, $f12
  mfc1  $a1, $f14
  mfc1  $a2, $f10
  lw    $t9, 0xd8($sp)
  sub.s $f2, $f4, $f2
  lwc1  $f4, 0x4c($sp)
  lwc1  $f10, 0x48($sp)
  add.s $f12, $f16, $f12
  mtc1  $zero, $f16
  li    $at, 0x3F800000 # 1.000000
  add.s $f2, $f18, $f2
  mfc1  $a3, $f12
  mtc1  $at, $f12
  swc1  $f4, 0x18($sp)
  swc1  $f2, 0x10($sp)
  sw    $t9, 0x14($sp)
  swc1  $f10, 0x1c($sp)
  swc1  $f16, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f12, 0x24($sp)
  bnez  $v0, .L7F030FDC
.L7F030FAC:
   li    $t0, 1
  sw    $t0, 0x90($sp)
  addiu $a0, $sp, 0x80
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x74
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x74
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa8
  lui   $at, %hi(flt_CODE_bss_8007BA00)
  lwc1  $f10, %lo(flt_CODE_bss_8007BA00)($at)
  swc1  $f10, 0x54($sp)
.L7F030FDC:
  lw    $t1, 0xc0($sp)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f6, 0xa4($sp)
  sw    $t1, 0xb4($sp)
  lwc1  $f2, 8($s0)
  lwc1  $f0, ($s0)
  li    $at, 0x3F800000 # 1.000000
  add.s $f10, $f2, $f6
  mtc1  $zero, $f6
  lw    $t2, 0xd8($sp)
  sub.s $f4, $f0, $f8
  swc1  $f10, 0x10($sp)
  mtc1  $at, $f10
  lwc1  $f8, 0x4c($sp)
  mfc1  $a3, $f4
  lwc1  $f4, 0x48($sp)
  mfc1  $a2, $f2
  mfc1  $a1, $f0
  addiu $a0, $sp, 0xb4
  sw    $t2, 0x14($sp)
  swc1  $f6, 0x20($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f10, 0x24($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x1c($sp)
  beqz  $v0, .L7F0310DC
   addiu $a0, $sp, 0xb4
  lw    $v0, 0xc4($sp)
  lwc1  $f18, 8($s0)
  lwc1  $f16, 0xa4($sp)
  lwc1  $f14, 0xa8($sp)
  lwc1  $f12, 0xd0($sp)
  add.s $f16, $f18, $f16
  lwc1  $f18, ($v0)
  mul.s $f14, $f14, $f12
  lwc1  $f10, ($s0)
  lwc1  $f8, 0xa0($sp)
  lwc1  $f6, 0x98($sp)
  lwc1  $f4, 0xb0($sp)
  sub.s $f8, $f10, $f8
  lwc1  $f10, 8($v0)
  lwc1  $f2, 0x9c($sp)
  sub.s $f6, $f18, $f6
  mul.s $f12, $f4, $f12
  mfc1  $a1, $f8
  add.s $f2, $f10, $f2
  mfc1  $a2, $f16
  lw    $t3, 0xd8($sp)
  add.s $f6, $f14, $f6
  lwc1  $f14, 0x4c($sp)
  lwc1  $f16, 0x48($sp)
  add.s $f2, $f12, $f2
  mfc1  $a3, $f6
  mtc1  $zero, $f6
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  swc1  $f2, 0x10($sp)
  swc1  $f14, 0x18($sp)
  sw    $t3, 0x14($sp)
  swc1  $f16, 0x1c($sp)
  swc1  $f6, 0x20($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f12, 0x24($sp)
  bnez  $v0, .L7F03110C
.L7F0310DC:
   li    $t4, 1
  sw    $t4, 0x8c($sp)
  addiu $a0, $sp, 0x68
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x5c
  addiu $a0, $sp, 0x68
  addiu $a1, $sp, 0x5c
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa8
  lui   $at, %hi(flt_CODE_bss_8007BA00)
  lwc1  $f8, %lo(flt_CODE_bss_8007BA00)($at)
  swc1  $f8, 0x50($sp)
.L7F03110C:
  lw    $t5, 0x90($sp)
  lw    $t6, 0x8c($sp)
  lw    $t7, 0x90($sp)
  beqz  $t5, .L7F0311B0
   nop   
  beqz  $t6, .L7F0311B0
   lwc1  $f4, 0x54($sp)
  lwc1  $f10, 0x50($sp)
  lwc1  $f6, 0x80($sp)
  lw    $a0, 0xc8($sp)
  c.lt.s $f4, $f10
  lwc1  $f4, 0x68($sp)
  bc1fl .L7F031180
   lw    $a1, 0xcc($sp)
  lw    $a0, 0xc8($sp)
  lw    $a1, 0xcc($sp)
  swc1  $f6, ($a0)
  lwc1  $f8, 0x84($sp)
  swc1  $f8, 4($a0)
  lwc1  $f4, 0x88($sp)
  swc1  $f4, 8($a0)
  lwc1  $f10, 0x74($sp)
  swc1  $f10, ($a1)
  lwc1  $f6, 0x78($sp)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x7c($sp)
  b     .L7F0312E8
   swc1  $f8, 8($a1)
  lw    $a1, 0xcc($sp)
.L7F031180:
  swc1  $f4, ($a0)
  lwc1  $f10, 0x6c($sp)
  swc1  $f10, 4($a0)
  lwc1  $f6, 0x70($sp)
  swc1  $f6, 8($a0)
  lwc1  $f8, 0x5c($sp)
  swc1  $f8, ($a1)
  lwc1  $f4, 0x60($sp)
  swc1  $f4, 4($a1)
  lwc1  $f10, 0x64($sp)
  b     .L7F0312E8
   swc1  $f10, 8($a1)
.L7F0311B0:
  beqz  $t7, .L7F0311F4
   lw    $t8, 0x8c($sp)
  lw    $a0, 0xc8($sp)
  lwc1  $f6, 0x80($sp)
  lw    $a1, 0xcc($sp)
  swc1  $f6, ($a0)
  lwc1  $f8, 0x84($sp)
  swc1  $f8, 4($a0)
  lwc1  $f4, 0x88($sp)
  swc1  $f4, 8($a0)
  lwc1  $f10, 0x74($sp)
  swc1  $f10, ($a1)
  lwc1  $f6, 0x78($sp)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x7c($sp)
  b     .L7F0312E8
   swc1  $f8, 8($a1)
.L7F0311F4:
  beqz  $t8, .L7F031238
   lw    $v0, 0xc4($sp)
  lw    $a0, 0xc8($sp)
  lwc1  $f4, 0x68($sp)
  lw    $a1, 0xcc($sp)
  swc1  $f4, ($a0)
  lwc1  $f10, 0x6c($sp)
  swc1  $f10, 4($a0)
  lwc1  $f6, 0x70($sp)
  swc1  $f6, 8($a0)
  lwc1  $f8, 0x5c($sp)
  swc1  $f8, ($a1)
  lwc1  $f4, 0x60($sp)
  swc1  $f4, 4($a1)
  lwc1  $f10, 0x64($sp)
  b     .L7F0312E8
   swc1  $f10, 8($a1)
.L7F031238:
  lw    $t9, 0xc0($sp)
  li    $at, 0x3F800000 # 1.000000
  lw    $t0, 0xd8($sp)
  sw    $t9, 0xb4($sp)
  lwc1  $f6, 8($v0)
  lw    $a3, ($v0)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  swc1  $f6, 0x10($sp)
  mtc1  $at, $f6
  lwc1  $f8, 0x4c($sp)
  lwc1  $f4, 0x48($sp)
  mtc1  $zero, $f10
  addiu $a0, $sp, 0xb4
  sw    $t0, 0x14($sp)
  swc1  $f8, 0x18($sp)
  swc1  $f6, 0x24($sp)
  swc1  $f4, 0x1c($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f10, 0x20($sp)
  beqz  $v0, .L7F0312CC
   addiu $a0, $sp, 0xb4
  lw    $t1, 0xc4($sp)
  lw    $t2, 0xd8($sp)
  lwc1  $f8, 0x4c($sp)
  lwc1  $f4, 0x48($sp)
  lw    $a1, ($t1)
  lw    $a2, 8($t1)
  lw    $a3, 0xd4($sp)
  sw    $t2, 0x10($sp)
  swc1  $f8, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f4, 0x18($sp)
  bgez  $v0, .L7F0312CC
   li    $t3, 1
  b     .L7F0312E8
   sw    $t3, 0x58($sp)
.L7F0312CC:
  lw    $a0, 0xc8($sp)
  jal   sub_GAME_7F0B28B0
   lw    $a1, 0xcc($sp)
  lw    $a0, 0xc8($sp)
  lw    $a1, 0xcc($sp)
  jal   sub_GAME_7F03074C
   addiu $a2, $sp, 0xa8
.L7F0312E8:
  lw    $a0, 0xb8($sp)
  jal   set_or_unset_GUARDdata_flag
   li    $a1, 1
  lw    $v0, 0x58($sp)
.L7F0312F8:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0xb8
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80052034
.word 0x3f490fdb /*0.78539819*/
glabel D_80052038
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F03130C
  addiu $sp, $sp, -0x80
  sw    $ra, 0x34($sp)
  sw    $s0, 0x30($sp)
  sw    $a0, 0x80($sp)
  sw    $a2, 0x88($sp)
  move  $s0, $a1
  beqz  $a2, .L7F031338
   lw    $v0, 0x18($a0)
  sw    $a1, 0x4c($sp)
  b     .L7F031340
   sw    $a3, 0x48($sp)
.L7F031338:
  sw    $a3, 0x4c($sp)
  sw    $s0, 0x48($sp)
.L7F031340:
  lwc1  $f4, ($s0)
  lwc1  $f6, 8($v0)
  mtc1  $zero, $f10
  sub.s $f8, $f4, $f6
  swc1  $f10, 0x74($sp)
  swc1  $f8, 0x70($sp)
  lwc1  $f6, 0x10($v0)
  lwc1  $f4, 8($s0)
  sw    $v0, 0x7c($sp)
  sub.s $f8, $f4, $f6
  lwc1  $f6, 0x70($sp)
  swc1  $f8, 0x78($sp)
  lwc1  $f10, 0x78($sp)
  mul.s $f4, $f10, $f10
  nop   
  mul.s $f8, $f6, $f6
  jal   sqrtf
   add.s $f12, $f4, $f8
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f18, 0x90($sp)
  lwc1  $f10, 0x70($sp)
  div.s $f14, $f16, $f0
  lwc1  $f4, 0x78($sp)
  lui   $at, %hi(D_80052034)
  mul.s $f2, $f18, $f14
  nop   
  mul.s $f6, $f10, $f2
  c.lt.s $f16, $f2
  mul.s $f8, $f4, $f2
  swc1  $f6, 0x70($sp)
  bc1f  .L7F0313CC
   swc1  $f8, 0x78($sp)
  b     .L7F0313DC
   lwc1  $f12, %lo(D_80052034)($at)
.L7F0313CC:
  mul.s $f12, $f18, $f14
  jal   sub_GAME_7F05ACB0
   nop   
  mov.s $f12, $f0
.L7F0313DC:
  lw    $t8, 0x88($sp)
  bnez  $t8, .L7F031408
   nop   
  mtc1  $zero, $f10
  lui   $at, %hi(D_80052038)
  c.eq.s $f12, $f10
  nop   
  bc1t  .L7F031408
   nop   
  lwc1  $f6, %lo(D_80052038)($at)
  sub.s $f12, $f6, $f12
.L7F031408:
  jal   cosf
   swc1  $f12, 0x5c($sp)
  lwc1  $f12, 0x5c($sp)
  jal   sinf
   swc1  $f0, 0x40($sp)
  lwc1  $f4, 0x40($sp)
  lwc1  $f10, 0x70($sp)
  lwc1  $f12, 0x5c($sp)
  neg.s $f8, $f4
  lwc1  $f4, 0x78($sp)
  mul.s $f6, $f8, $f10
  nop   
  mul.s $f8, $f4, $f0
  mtc1  $zero, $f4
  nop   
  swc1  $f4, 0x54($sp)
  add.s $f10, $f8, $f6
  jal   sinf
   swc1  $f10, 0x50($sp)
  lwc1  $f12, 0x5c($sp)
  jal   cosf
   swc1  $f0, 0x40($sp)
  lwc1  $f8, 0x40($sp)
  lwc1  $f10, 0x70($sp)
  lw    $v0, 0x7c($sp)
  neg.s $f6, $f8
  lwc1  $f8, 0x78($sp)
  mul.s $f4, $f6, $f10
  lw    $t9, 0x4c($sp)
  lw    $t0, 0x48($sp)
  mul.s $f6, $f8, $f0
  lwc1  $f8, 0x50($sp)
  lw    $a0, 0x80($sp)
  lw    $t1, 0xa4($sp)
  addiu $a1, $v0, 8
  addiu $a3, $sp, 0x64
  sub.s $f10, $f4, $f6
  swc1  $f10, 0x58($sp)
  lwc1  $f4, ($s0)
  add.s $f6, $f8, $f4
  swc1  $f6, 0x64($sp)
  lwc1  $f8, 4($s0)
  swc1  $f8, 0x68($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f8, 0xa0($sp)
  add.s $f6, $f10, $f4
  swc1  $f6, 0x6c($sp)
  lw    $a2, 0x14($v0)
  sw    $t9, 0x10($sp)
  sw    $t0, 0x14($sp)
  swc1  $f8, 0x18($sp)
  lwc1  $f10, 0x24($a0)
  sw    $a1, 0x3c($sp)
  sw    $t1, 0x20($sp)
  jal   sub_GAME_7F03081C
   swc1  $f10, 0x1c($sp)
  beqz  $v0, .L7F03158C
   lw    $a1, 0x3c($sp)
  lw    $t2, 0x94($sp)
  lw    $a0, 0x80($sp)
  lw    $t3, 0x7c($sp)
  beqz  $t2, .L7F031528
   addiu $a3, $sp, 0x64
  lw    $t4, 0x98($sp)
  lw    $t5, 0xa4($sp)
  lw    $a2, 0x14($t3)
  sw    $zero, 0x14($sp)
  sw    $t4, 0x10($sp)
  jal   sub_GAME_7F0304AC
   sw    $t5, 0x18($sp)
  beql  $v0, $zero, .L7F031590
   move  $v0, $zero
.L7F031528:
  lw    $t6, 0xa8($sp)
  lw    $v0, 0x9c($sp)
  li    $t8, 1
  beql  $t6, $zero, .L7F03156C
   sb    $t8, 2($v0)
  lw    $v0, 0x9c($sp)
  li    $t7, 1
  sb    $t7, 3($v0)
  lwc1  $f4, 0x64($sp)
  swc1  $f4, 0x2c($v0)
  lwc1  $f6, 0x68($sp)
  swc1  $f6, 0x30($v0)
  lwc1  $f8, 0x6c($sp)
  swc1  $f8, 0x34($v0)
  b     .L7F031590
   li    $v0, 1
  sb    $t8, 2($v0)
.L7F03156C:
  lwc1  $f10, 0x64($sp)
  swc1  $f10, 4($v0)
  lwc1  $f4, 0x68($sp)
  swc1  $f4, 8($v0)
  lwc1  $f6, 0x6c($sp)
  swc1  $f6, 0xc($v0)
  b     .L7F031590
   li    $v0, 1
.L7F03158C:
  move  $v0, $zero
.L7F031590:
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8005203C
.word 0x40490fdb /*3.1415927*/
glabel D_80052040
.word 0x40c90fdb /*6.2831855*/
glabel D_80052044
.word 0x3f99999a /*1.2*/
glabel D_80052048
.word 0x3f866666 /*1.05*/
glabel D_8005204C
.word 0x3f99999a /*1.2*/
glabel D_80052050
.word 0x3f866666 /*1.05*/
glabel D_80052054
.word 0x3f99999a /*1.2*/
glabel D_80052058
.word 0x3f866666 /*1.05*/
glabel D_8005205C
.word 0x3f8ccccd /*1.1*/
glabel D_80052060
.word 0x3f8ccccd /*1.1*/
glabel D_80052064
.word 0x471c4000 /*40000.0*/
.text
glabel sub_GAME_7F0315A4
  addiu $sp, $sp, -0x110
  sw    $ra, 0x84($sp)
  sw    $s7, 0x80($sp)
  sw    $s6, 0x7c($sp)
  sw    $s5, 0x78($sp)
  sw    $s4, 0x74($sp)
  sw    $s3, 0x70($sp)
  sw    $s2, 0x6c($sp)
  sw    $s1, 0x68($sp)
  sw    $s0, 0x64($sp)
  sdc1  $f30, 0x58($sp)
  sdc1  $f28, 0x50($sp)
  sdc1  $f26, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  sw    $a2, 0x118($sp)
  lhu   $t6, 0x12($a0)
  move  $s0, $a3
  move  $s2, $a0
  andi  $t7, $t6, 0x10
  move  $s4, $a1
  lw    $s1, 0x18($a0)
  beqz  $t7, .L7F03160C
   li    $s6, 32797
  li    $s6, 31
.L7F03160C:
  lui   $at, %hi(D_8005203C)
  lwc1  $f30, %lo(D_8005203C)($at)
  lui   $at, %hi(D_80052040)
  mtc1  $zero, $f28
  lwc1  $f26, %lo(D_80052040)($at)
  sw    $zero, 0xf0($sp)
  li    $s7, 1
  li    $s5, 4
  addiu $s3, $sp, 0xf4
.L7F031630:
  lb    $v0, ($s0)
  li    $at, 2
  beql  $v0, $zero, .L7F03164C
   lwc1  $f4, ($s4)
  bne   $v0, $at, .L7F0316F8
   nop   
  lwc1  $f4, ($s4)
.L7F03164C:
  addiu $t8, $s0, 0x10
  addiu $t9, $s0, 0x1c
  swc1  $f4, 0x100($sp)
  lwc1  $f6, 4($s4)
  li    $t0, 16
  move  $a0, $s2
  swc1  $f6, 0x104($sp)
  lwc1  $f8, 8($s4)
  addiu $a1, $s1, 8
  addiu $a3, $sp, 0x100
  swc1  $f8, 0x108($sp)
  lw    $a2, 0x14($s1)
  sw    $t9, 0x14($sp)
  sw    $t8, 0x10($sp)
  lwc1  $f0, 0x24($s2)
  sw    $t0, 0x20($sp)
  neg.s $f10, $f0
  swc1  $f0, 0x1c($sp)
  jal   sub_GAME_7F03081C
   swc1  $f10, 0x18($sp)
  beql  $v0, $zero, .L7F0316CC
   lb    $v0, ($s0)
  sb    $s7, 2($s0)
  lwc1  $f18, 0x100($sp)
  swc1  $f18, 4($s0)
  lwc1  $f4, 0x104($sp)
  swc1  $f4, 8($s0)
  lwc1  $f6, 0x108($sp)
  sb    $s5, ($s0)
  b     .L7F031D30
   swc1  $f6, 0xc($s0)
  lb    $v0, ($s0)
.L7F0316CC:
  li    $at, 2
  bnez  $v0, .L7F0316E4
   nop   
  sb    $s7, ($s0)
  b     .L7F031D30
   sb    $zero, 1($s0)
.L7F0316E4:
  bne   $v0, $at, .L7F031D30
   li    $t1, 3
  sb    $t1, ($s0)
  b     .L7F031D30
   sb    $zero, 1($s0)
.L7F0316F8:
  bne   $s7, $v0, .L7F0317D0
   li    $at, 3
  lui   $at, %hi(D_80052044)
  lwc1  $f10, %lo(D_80052044)($at)
  lwc1  $f8, 0x24($s2)
  lui   $at, %hi(D_80052048)
  lwc1  $f4, %lo(D_80052048)($at)
  mul.s $f18, $f8, $f10
  li    $t2, 16
  sw    $t2, 0x24($sp)
  sw    $zero, 0x28($sp)
  swc1  $f28, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $s4, 0x18($sp)
  mul.s $f0, $f18, $f4
  sw    $s7, 0x14($sp)
  move  $a0, $s2
  addiu $a1, $s0, 0x10
  move  $a2, $s7
  move  $a3, $s3
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F03130C
   swc1  $f0, 0xe8($sp)
  beqz  $v0, .L7F031764
   lwc1  $f0, 0xe8($sp)
  b     .L7F031D30
   sb    $s5, ($s0)
.L7F031764:
  li    $t3, 16
  sw    $t3, 0x24($sp)
  move  $a0, $s2
  addiu $a1, $s0, 0x1c
  move  $a2, $zero
  move  $a3, $s3
  swc1  $f0, 0x10($sp)
  sw    $s7, 0x14($sp)
  sw    $s4, 0x18($sp)
  sw    $s0, 0x1c($sp)
  swc1  $f28, 0x20($sp)
  jal   sub_GAME_7F03130C
   sw    $zero, 0x28($sp)
  beql  $v0, $zero, .L7F0317AC
   lb    $t4, 1($s0)
  b     .L7F031D30
   sb    $s5, ($s0)
  lb    $t4, 1($s0)
.L7F0317AC:
  li    $t7, 2
  addiu $t5, $t4, 1
  sb    $t5, 1($s0)
  lb    $t6, 1($s0)
  slti  $at, $t6, 6
  bnezl $at, .L7F031D34
   lw    $t0, 0xf0($sp)
  b     .L7F031D30
   sb    $t7, ($s0)
.L7F0317D0:
  bne   $v0, $at, .L7F0318D0
   lui   $at, %hi(D_8005204C)
  lwc1  $f8, %lo(D_8005204C)($at)
  lwc1  $f6, 0x24($s2)
  lui   $at, %hi(D_80052050)
  lwc1  $f18, %lo(D_80052050)($at)
  mul.s $f10, $f6, $f8
  li    $t8, 16
  sw    $t8, 0x24($sp)
  sw    $zero, 0x28($sp)
  swc1  $f28, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $zero, 0x18($sp)
  mul.s $f0, $f10, $f18
  sw    $zero, 0x14($sp)
  move  $a0, $s2
  addiu $a1, $s0, 0x10
  move  $a2, $s7
  move  $a3, $s3
  swc1  $f0, 0x10($sp)
  jal   sub_GAME_7F03130C
   swc1  $f0, 0xe4($sp)
  beqz  $v0, .L7F031838
   lwc1  $f0, 0xe4($sp)
  b     .L7F031D30
   sb    $s5, ($s0)
.L7F031838:
  li    $t9, 16
  sw    $t9, 0x24($sp)
  move  $a0, $s2
  addiu $a1, $s0, 0x1c
  move  $a2, $zero
  move  $a3, $s3
  swc1  $f0, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $s0, 0x1c($sp)
  swc1  $f28, 0x20($sp)
  jal   sub_GAME_7F03130C
   sw    $zero, 0x28($sp)
  beql  $v0, $zero, .L7F031880
   lb    $t0, 1($s0)
  b     .L7F031D30
   sb    $s5, ($s0)
  lb    $t0, 1($s0)
.L7F031880:
  addiu $t1, $t0, 1
  sb    $t1, 1($s0)
  lb    $t2, 1($s0)
  slti  $at, $t2, 6
  bnezl $at, .L7F031D34
   lw    $t0, 0xf0($sp)
  sb    $zero, 2($s0)
  lb    $t3, 2($s0)
  sb    $t3, 3($s0)
  lwc1  $f0, ($s4)
  swc1  $f0, 4($s0)
  swc1  $f0, 0x2c($s0)
  lwc1  $f0, 4($s4)
  swc1  $f0, 8($s0)
  swc1  $f0, 0x30($s0)
  lwc1  $f0, 8($s4)
  sb    $zero, ($s0)
  swc1  $f0, 0xc($s0)
  b     .L7F031D30
   swc1  $f0, 0x34($s0)
.L7F0318D0:
  bne   $s5, $v0, .L7F031948
   li    $at, 5
  lw    $a2, 0x14($s1)
  addiu $t4, $s0, 0x10
  addiu $t5, $s0, 0x1c
  sw    $t5, 0x14($sp)
  sw    $t4, 0x10($sp)
  lwc1  $f0, 0x24($s2)
  sw    $s6, 0x20($sp)
  move  $a0, $s2
  neg.s $f4, $f0
  addiu $a1, $s1, 8
  swc1  $f4, 0x18($sp)
  addiu $a3, $s0, 4
  jal   sub_GAME_7F030D70
   swc1  $f0, 0x1c($sp)
  beqz  $v0, .L7F03193C
   li    $t6, 5
  lwc1  $f6, 4($s0)
  lwc1  $f8, 8($s0)
  lwc1  $f10, 0xc($s0)
  sb    $s7, 3($s0)
  sb    $zero, ($s0)
  swc1  $f6, 0x2c($s0)
  swc1  $f8, 0x30($s0)
  b     .L7F031D30
   swc1  $f10, 0x34($s0)
.L7F03193C:
  sb    $t6, ($s0)
  b     .L7F031D30
   sb    $zero, 1($s0)
.L7F031948:
  bne   $v0, $at, .L7F031D30
   lui   $at, %hi(D_80052054)
  lwc1  $f4, %lo(D_80052054)($at)
  lwc1  $f18, 0x24($s2)
  lui   $at, %hi(D_80052058)
  lwc1  $f8, %lo(D_80052058)($at)
  mul.s $f6, $f18, $f4
  lwc1  $f4, 0xc($s0)
  lwc1  $f18, 8($s1)
  lwc1  $f10, 4($s0)
  sub.s $f12, $f10, $f18
  mul.s $f24, $f6, $f8
  lwc1  $f6, 0x10($s1)
  jal   convert_angle_using_inverse
   sub.s $f14, $f4, $f6
  lwc1  $f22, 0x10($s0)
  lwc1  $f18, 8($s1)
  lwc1  $f16, 0x18($s0)
  lwc1  $f10, 0x10($s1)
  sub.s $f12, $f22, $f18
  mov.s $f20, $f0
  jal   convert_angle_using_inverse
   sub.s $f14, $f16, $f10
  sub.s $f22, $f20, $f0
  lwc1  $f18, 0x1c($s0)
  lwc1  $f16, 8($s1)
  lwc1  $f10, 0x24($s0)
  lwc1  $f8, 0x10($s1)
  sub.s $f12, $f18, $f16
  swc1  $f22, 0xd4($sp)
  jal   convert_angle_using_inverse
   sub.s $f14, $f10, $f8
  lwc1  $f16, 0xd4($sp)
  sub.s $f12, $f20, $f0
  move  $a3, $s3
  move  $a0, $s2
  c.lt.s $f16, $f28
  mov.s $f2, $f12
  addiu $a1, $s0, 0x1c
  move  $a2, $zero
  bc1f  .L7F0319F4
   lui   $at, %hi(D_80052060)
  add.s $f16, $f16, $f26
.L7F0319F4:
  c.le.s $f30, $f16
  nop   
  bc1fl .L7F031A0C
   c.lt.s $f16, $f28
  sub.s $f16, $f16, $f26
  c.lt.s $f16, $f28
.L7F031A0C:
  nop   
  bc1fl .L7F031A20
   c.lt.s $f12, $f28
  neg.s $f16, $f16
  c.lt.s $f12, $f28
.L7F031A20:
  nop   
  bc1fl .L7F031A34
   c.le.s $f30, $f2
  add.s $f2, $f12, $f26
  c.le.s $f30, $f2
.L7F031A34:
  nop   
  bc1fl .L7F031A48
   c.lt.s $f2, $f28
  sub.s $f2, $f2, $f26
  c.lt.s $f2, $f28
.L7F031A48:
  nop   
  bc1fl .L7F031A5C
   c.lt.s $f16, $f2
  neg.s $f2, $f2
  c.lt.s $f16, $f2
.L7F031A5C:
  nop   
  bc1f  .L7F031BC0
   nop   
  lui   $at, %hi(D_80052060)
  lwc1  $f4, %lo(D_8005205C)($at)
  move  $a0, $s2
  addiu $a1, $s0, 0x10
  mul.s $f22, $f24, $f4
  move  $a2, $s7
  swc1  $f24, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $s6, 0x24($sp)
  swc1  $f22, 0x20($sp)
  jal   sub_GAME_7F03130C
   sw    $s7, 0x28($sp)
  beql  $v0, $zero, .L7F031AB4
   lwc1  $f6, 0x10($s0)
  b     .L7F031D40
   sb    $zero, ($s0)
  lwc1  $f6, 0x10($s0)
.L7F031AB4:
  lwc1  $f8, 8($s1)
  lwc1  $f10, 0x18($s0)
  lwc1  $f18, 0x10($s1)
  sub.s $f12, $f6, $f8
  jal   convert_angle_using_inverse
   sub.s $f14, $f10, $f18
  sub.s $f18, $f20, $f0
  lwc1  $f16, 0xf4($sp)
  lwc1  $f10, 8($s1)
  lwc1  $f8, 0xfc($sp)
  lwc1  $f6, 0x10($s1)
  sub.s $f12, $f16, $f10
  swc1  $f18, 0xc4($sp)
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f6
  lwc1  $f16, 0xc4($sp)
  sub.s $f12, $f20, $f0
  move  $a0, $s2
  move  $a1, $s3
  c.lt.s $f16, $f28
  mov.s $f2, $f12
  move  $a2, $zero
  move  $a3, $s3
  bc1fl .L7F031B20
   c.le.s $f30, $f16
  add.s $f16, $f16, $f26
  c.le.s $f30, $f16
.L7F031B20:
  nop   
  bc1fl .L7F031B34
   c.lt.s $f16, $f28
  sub.s $f16, $f16, $f26
  c.lt.s $f16, $f28
.L7F031B34:
  nop   
  bc1fl .L7F031B48
   c.lt.s $f12, $f28
  neg.s $f16, $f16
  c.lt.s $f12, $f28
.L7F031B48:
  nop   
  bc1fl .L7F031B5C
   c.le.s $f30, $f2
  add.s $f2, $f12, $f26
  c.le.s $f30, $f2
.L7F031B5C:
  nop   
  bc1fl .L7F031B70
   c.lt.s $f2, $f28
  sub.s $f2, $f2, $f26
  c.lt.s $f2, $f28
.L7F031B70:
  nop   
  bc1fl .L7F031B84
   c.lt.s $f2, $f16
  neg.s $f2, $f2
  c.lt.s $f2, $f16
.L7F031B84:
  nop   
  bc1fl .L7F031D10
   lb    $t7, 1($s0)
  swc1  $f24, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $s0, 0x1c($sp)
  swc1  $f22, 0x20($sp)
  sw    $s6, 0x24($sp)
  jal   sub_GAME_7F03130C
   sw    $s7, 0x28($sp)
  beql  $v0, $zero, .L7F031D10
   lb    $t7, 1($s0)
  b     .L7F031D40
   sb    $zero, ($s0)
.L7F031BC0:
  lwc1  $f18, %lo(D_80052060)($at)
  move  $a3, $s3
  swc1  $f24, 0x10($sp)
  mul.s $f22, $f24, $f18
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $s0, 0x1c($sp)
  sw    $s6, 0x24($sp)
  sw    $s7, 0x28($sp)
  jal   sub_GAME_7F03130C
   swc1  $f22, 0x20($sp)
  beql  $v0, $zero, .L7F031C00
   lwc1  $f4, 0x1c($s0)
  b     .L7F031D40
   sb    $zero, ($s0)
  lwc1  $f4, 0x1c($s0)
.L7F031C00:
  lwc1  $f6, 8($s1)
  lwc1  $f8, 0x24($s0)
  lwc1  $f10, 0x10($s1)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  sub.s $f18, $f20, $f0
  lwc1  $f16, 0xf4($sp)
  lwc1  $f10, 8($s1)
  lwc1  $f8, 0xfc($sp)
  lwc1  $f6, 0x10($s1)
  sub.s $f12, $f16, $f10
  swc1  $f18, 0xb4($sp)
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f6
  lwc1  $f16, 0xb4($sp)
  sub.s $f12, $f20, $f0
  move  $a0, $s2
  move  $a1, $s3
  c.lt.s $f16, $f28
  mov.s $f2, $f12
  move  $a2, $s7
  move  $a3, $s3
  bc1fl .L7F031C6C
   c.le.s $f30, $f16
  add.s $f16, $f16, $f26
  c.le.s $f30, $f16
.L7F031C6C:
  nop   
  bc1fl .L7F031C80
   c.lt.s $f16, $f28
  sub.s $f16, $f16, $f26
  c.lt.s $f16, $f28
.L7F031C80:
  nop   
  bc1fl .L7F031C94
   c.lt.s $f12, $f28
  neg.s $f16, $f16
  c.lt.s $f12, $f28
.L7F031C94:
  nop   
  bc1fl .L7F031CA8
   c.le.s $f30, $f2
  add.s $f2, $f12, $f26
  c.le.s $f30, $f2
.L7F031CA8:
  nop   
  bc1fl .L7F031CBC
   c.lt.s $f2, $f28
  sub.s $f2, $f2, $f26
  c.lt.s $f2, $f28
.L7F031CBC:
  nop   
  bc1fl .L7F031CD0
   c.lt.s $f2, $f16
  neg.s $f2, $f2
  c.lt.s $f2, $f16
.L7F031CD0:
  nop   
  bc1fl .L7F031D10
   lb    $t7, 1($s0)
  swc1  $f24, 0x10($sp)
  sw    $zero, 0x14($sp)
  sw    $zero, 0x18($sp)
  sw    $s0, 0x1c($sp)
  swc1  $f22, 0x20($sp)
  sw    $s6, 0x24($sp)
  jal   sub_GAME_7F03130C
   sw    $s7, 0x28($sp)
  beql  $v0, $zero, .L7F031D10
   lb    $t7, 1($s0)
  b     .L7F031D40
   sb    $zero, ($s0)
  lb    $t7, 1($s0)
.L7F031D10:
  addiu $t8, $t7, 1
  sb    $t8, 1($s0)
  lb    $t9, 1($s0)
  slti  $at, $t9, 6
  bnezl $at, .L7F031D34
   lw    $t0, 0xf0($sp)
  sb    $zero, 3($s0)
  sb    $zero, ($s0)
.L7F031D30:
  lw    $t0, 0xf0($sp)
.L7F031D34:
  addiu $t1, $t0, 1
  bne   $t1, $s7, .L7F031630
   sw    $t1, 0xf0($sp)
.L7F031D40:
  lb    $t2, 3($s0)
  li    $t5, 20480
  bnezl $t2, .L7F031D6C
   lw    $t3, 0x28($s0)
  lwc1  $f10, 4($s0)
  lwc1  $f18, 8($s0)
  lwc1  $f4, 0xc($s0)
  swc1  $f10, 0x2c($s0)
  swc1  $f18, 0x30($s0)
  swc1  $f4, 0x34($s0)
  lw    $t3, 0x28($s0)
.L7F031D6C:
  li    $at, 10
  div   $zero, $t3, $at
  mfhi  $t4
  bnezl $t4, .L7F031F44
   lb    $t6, 7($s2)
  lwc1  $f6, 0x34($s0)
  lw    $a0, 0x14($s1)
  lw    $a1, 8($s1)
  lw    $a2, 0x10($s1)
  lw    $a3, 0x2c($s0)
  sw    $t5, 0x14($sp)
  jal   sub_GAME_7F0B1410
   swc1  $f6, 0x10($sp)
  beqz  $v0, .L7F031EAC
   move  $s3, $v0
  lw    $v1, 4($v0)
  lw    $t6, 0xc($v1)
  sll   $t7, $t6, 2
  bltzl $t7, .L7F031EAC
   move  $s3, $zero
  lwc1  $f8, 8($v0)
  lwc1  $f10, 8($s1)
  lwc1  $f18, 0xc($v0)
  lwc1  $f4, 0xc($s1)
  sub.s $f0, $f8, $f10
  lwc1  $f8, 0x10($s1)
  lwc1  $f6, 0x10($v0)
  sub.s $f2, $f18, $f4
  mul.s $f10, $f0, $f0
  lui   $at, %hi(D_80052064)
  sub.s $f12, $f6, $f8
  mul.s $f18, $f2, $f2
  move  $a0, $s2
  mul.s $f6, $f12, $f12
  add.s $f4, $f10, $f18
  lwc1  $f10, %lo(D_80052064)($at)
  add.s $f8, $f4, $f6
  c.lt.s $f8, $f10
  nop   
  bc1f  .L7F031EA0
   nop   
  jal   sub_GAME_7F0281F4
   nop   
  move  $a0, $s1
  jal   sub_GAME_7F055B78
   lw    $a1, 4($s3)
  lw    $a0, 4($s3)
  jal   set_door_state
   move  $a1, $s7
  lhu   $t8, 0x12($s2)
  andi  $t9, $t8, 0x10
  bnez  $t9, .L7F031EAC
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s2)
  lui   $t0, %hi(ptr_animation_table) 
  lw    $t0, %lo(ptr_animation_table)($t0)
  lui   $t1, %hi(0x00008194) # $t1, 1
  addiu $t1, %lo(0x00008194) # addiu $t1, $t1, -0x7e6c
  addu  $t2, $t0, $t1
  beq   $v0, $t2, .L7F031EAC
   nop   
  jal   sub_GAME_7F06F5AC
   lw    $a0, 0x1c($s2)
  lui   $t3, %hi(ptr_animation_table) 
  lw    $t3, %lo(ptr_animation_table)($t3)
  lui   $t4, %hi(0x0000001C) # $t4, 0
  addiu $t4, %lo(0x0000001C) # addiu $t4, $t4, 0x1c
  addu  $t5, $t3, $t4
  beq   $v0, $t5, .L7F031EAC
   move  $a0, $s2
  jal   sub_GAME_7F023948
   lui   $a1, 0x4180
  lui   $t6, %hi(global_timer) 
  lw    $t6, %lo(global_timer)($t6)
  b     .L7F031EAC
   sw    $t6, 0xcc($s2)
.L7F031EA0:
  b     .L7F031EAC
   move  $s3, $zero
  move  $s3, $zero
.L7F031EAC:
  beqz  $s3, .L7F031EC4
   lui   $s1, %hi(0x00008194) # $s1, 1
  lhu   $t7, 0x12($s2)
  andi  $t8, $t7, 0x10
  beql  $t8, $zero, .L7F031F44
   lb    $t6, 7($s2)
.L7F031EC4:
  lw    $a0, 0x1c($s2)
  jal   sub_GAME_7F06F5AC
   addiu $s1, %lo(0x00008194) # addiu $s1, $s1, -0x7e6c
  lui   $t9, %hi(ptr_animation_table) 
  lw    $t9, %lo(ptr_animation_table)($t9)
  addu  $t0, $s1, $t9
  beq   $v0, $t0, .L7F031F04
   lui   $s1, %hi(0x0000001C) # $s1, 0
  lw    $a0, 0x1c($s2)
  jal   sub_GAME_7F06F5AC
   addiu $s1, %lo(0x0000001C) # addiu $s1, $s1, 0x1c
  lui   $t1, %hi(ptr_animation_table) 
  lw    $t1, %lo(ptr_animation_table)($t1)
  addu  $t2, $s1, $t1
  bne   $v0, $t2, .L7F031F2C
   nop   
.L7F031F04:
  lb    $t3, 7($s2)
  li    $at, 14
  bne   $t3, $at, .L7F031F24
   nop   
  jal   sub_GAME_7F028FAC
   move  $a0, $s2
  b     .L7F031F2C
   nop   
.L7F031F24:
  jal   play_hit_soundeffect_and_proper_volume
   move  $a0, $s2
.L7F031F2C:
  bnezl $s3, .L7F031F44
   lb    $t6, 7($s2)
  lhu   $t4, 0x12($s2)
  andi  $t5, $t4, 0xffef
  sh    $t5, 0x12($s2)
  lb    $t6, 7($s2)
.L7F031F44:
  li    $at, 14
  move  $a0, $s2
  bne   $t6, $at, .L7F031F70
   addiu $a1, $s0, 0x2c
  move  $a0, $s2
  addiu $a1, $s0, 0x2c
  move  $a2, $zero
  jal   sub_GAME_7F02F690
   addiu $a3, $s2, 0x7c
  b     .L7F032048
   lw    $ra, 0x84($sp)
.L7F031F70:
  lbu   $a2, 0x59($s2)
  jal   sub_GAME_7F02F690
   addiu $a3, $s2, 0xa0
  lbu   $v1, 0x59($s2)
  li    $at, 2
  bne   $v1, $at, .L7F031FFC
   nop   
  lwc1  $f18, 0xa0($s2)
  lui   $a1, 0x3e80
  c.eq.s $f28, $f18
  nop   
  bc1tl .L7F031FBC
   lw    $t7, 0x14($s2)
  mfc1  $a2, $f28
  jal   sub_GAME_7F06FE4C
   lw    $a0, 0x1c($s2)
  b     .L7F032048
   lw    $ra, 0x84($sp)
  lw    $t7, 0x14($s2)
.L7F031FBC:
  lui   $a1, 0x3f00
  sll   $t8, $t7, 0xc
  bgezl $t8, .L7F031FEC
   mfc1  $a2, $f28
  lui   $a1, (0x3F266666 >> 16) # lui $a1, 0x3f26
  mfc1  $a2, $f28
  ori   $a1, (0x3F266666 & 0xFFFF) # ori $a1, $a1, 0x6666
  jal   sub_GAME_7F06FE4C
   lw    $a0, 0x1c($s2)
  b     .L7F032048
   lw    $ra, 0x84($sp)
  mfc1  $a2, $f28
.L7F031FEC:
  jal   sub_GAME_7F06FE4C
   lw    $a0, 0x1c($s2)
  b     .L7F032048
   lw    $ra, 0x84($sp)
.L7F031FFC:
  bnel  $s7, $v1, .L7F032048
   lw    $ra, 0x84($sp)
  lwc1  $f4, 0xa0($s2)
  lui   $a1, 0x3f00
  c.eq.s $f28, $f4
  nop   
  bc1tl .L7F03203C
   mfc1  $a2, $f28
  lui   $a1, (0x3ECCCCCD >> 16) # lui $a1, 0x3ecc
  mfc1  $a2, $f28
  ori   $a1, (0x3ECCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   sub_GAME_7F06FE4C
   lw    $a0, 0x1c($s2)
  b     .L7F032048
   lw    $ra, 0x84($sp)
  mfc1  $a2, $f28
.L7F03203C:
  jal   sub_GAME_7F06FE4C
   lw    $a0, 0x1c($s2)
  lw    $ra, 0x84($sp)
.L7F032048:
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  ldc1  $f28, 0x50($sp)
  ldc1  $f30, 0x58($sp)
  lw    $s0, 0x64($sp)
  lw    $s1, 0x68($sp)
  lw    $s2, 0x6c($sp)
  lw    $s3, 0x70($sp)
  lw    $s4, 0x74($sp)
  lw    $s5, 0x78($sp)
  lw    $s6, 0x7c($sp)
  lw    $s7, 0x80($sp)
  jr    $ra
   addiu $sp, $sp, 0x110
");

asm(R"
.late_rodata
glabel D_80052068
.word 0x3f99999a /*1.2*/
glabel D_8005206C
.word 0x3f99999a /*1.2*/
.text
glabel sub_GAME_7F032088
  addiu $sp, $sp, -0x88
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  lw    $t6, 0x18($a0)
  sw    $zero, 0x74($sp)
  lui   $t9, %hi(global_timer) 
  sw    $t6, 0x78($sp)
  lw    $t7, 0x84($a0)
  lui   $t1, %hi(global_timer) 
  lw    $t0, 0xcc($a0)
  addiu $t8, $t7, 1
  sw    $t8, 0x84($a0)
  lw    $t9, %lo(global_timer)($t9)
  move  $s0, $a0
  addiu $a1, $s0, 0x2c
  sw    $t9, 0xc8($a0)
  lw    $t1, %lo(global_timer)($t1)
  addiu $t2, $t1, -0x3c
  slt   $at, $t0, $t2
  beqz  $at, .L7F0320E8
   nop   
  lw    $a2, 0x38($s0)
  jal   plot_course_for_actor
   lbu   $a3, 0x59($s0)
.L7F0320E8:
  jal   sub_GAME_7F0281FC
   move  $a0, $s0
  lb    $t3, 0x5c($s0)
  li    $at, 6
  lui   $t4, %hi(global_timer) 
  beq   $t3, $at, .L7F032154
   nop   
  lw    $t5, 0x9c($s0)
  lw    $t4, %lo(global_timer)($t4)
  move  $a0, $s0
  addiu $t6, $t5, 0xb4
  slt   $at, $t6, $t4
  beqz  $at, .L7F032154
   addiu $a1, $sp, 0x68
  jal   sub_GAME_7F027F20
   addiu $a2, $sp, 0x64
  move  $a0, $s0
  addiu $a1, $sp, 0x68
  jal   sub_GAME_7F027DB0
   lw    $a2, 0x64($sp)
  beqz  $v0, .L7F032154
   li    $t7, 1
  sw    $t7, 0x74($sp)
  move  $a0, $s0
  addiu $a1, $s0, 0x5c
  jal   sub_GAME_7F027E90
   addiu $a2, $sp, 0x68
.L7F032154:
  lui   $t8, %hi(setting_007_5) 
  lw    $t8, %lo(setting_007_5)($t8)
  slti  $at, $t8, 0xa
  bnezl $at, .L7F03217C
   lb    $t9, 0x5c($s0)
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F032538
   lw    $ra, 0x24($sp)
  lb    $t9, 0x5c($s0)
.L7F03217C:
  li    $at, 6
  move  $a0, $s0
  bne   $t9, $at, .L7F032218
   addiu $a1, $sp, 0x58
  jal   sub_GAME_7F027F20
   addiu $a2, $sp, 0x54
  lw    $t1, 0x74($sp)
  lw    $t0, 0x78($sp)
  bnezl $t1, .L7F0321E8
   addiu $t4, $s0, 0x5c
  lbu   $t2, 1($t0)
  move  $a0, $s0
  addiu $a1, $sp, 0x58
  andi  $t3, $t2, 2
  bnez  $t3, .L7F0321CC
   nop   
  jal   sub_GAME_7F027DB0
   lw    $a2, 0x54($sp)
  bnezl $v0, .L7F0321E8
   addiu $t4, $s0, 0x5c
.L7F0321CC:
  jal   sub_GAME_7F02828C
   move  $a0, $s0
  lui   $t5, %hi(global_timer) 
  lw    $t5, %lo(global_timer)($t5)
  b     .L7F032534
   sw    $t5, 0x9c($s0)
  addiu $t4, $s0, 0x5c
.L7F0321E8:
  sw    $t4, 0x34($sp)
  jal   sub_GAME_7F027FA8
   move  $a0, $s0
  lw    $t6, 0x54($sp)
  mfc1  $a2, $f0
  move  $a0, $s0
  lw    $a1, 0x34($sp)
  addiu $a3, $sp, 0x58
  jal   sub_GAME_7F028600
   sw    $t6, 0x10($sp)
  b     .L7F032538
   lw    $ra, 0x24($sp)
.L7F032218:
  lbu   $t7, 0x58($s0)
  lw    $a1, 0x78($sp)
  move  $v1, $zero
  sll   $t8, $t7, 2
  addu  $t9, $s0, $t8
  lw    $v0, 0x40($t9)
  addiu $a0, $s0, 0xbc
  addiu $a2, $s0, 0x2c
  beqz  $v0, .L7F032290
   addiu $a1, $a1, 8
  lw    $t1, ($v0)
  lw    $a1, 0x78($sp)
  lui   $t2, %hi(ptr_0xxxpresets) 
  sll   $t0, $t1, 2
  subu  $t0, $t0, $t1
  sll   $t0, $t0, 2
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  subu  $t0, $t0, $t1
  sll   $t0, $t0, 2
  addiu $a1, $a1, 8
  sw    $a1, 0x2c($sp)
  sw    $zero, 0x4c($sp)
  addiu $a0, $s0, 0xbc
  lui   $a3, 0x41f0
  jal   sub_GAME_7F02FD50
   addu  $a2, $t0, $t2
  beqz  $v0, .L7F0322B8
   lw    $v1, 0x4c($sp)
  b     .L7F0322B8
   li    $v1, 1
.L7F032290:
  lui   $a3, 0x41f0
  sw    $v1, 0x4c($sp)
  jal   sub_GAME_7F02FD50
   sw    $a1, 0x2c($sp)
  beqz  $v0, .L7F0322B8
   lw    $v1, 0x4c($sp)
  jal   sub_GAME_7F023E48
   move  $a0, $s0
  b     .L7F032538
   lw    $ra, 0x24($sp)
.L7F0322B8:
  addiu $t3, $s0, 0x5c
  beqz  $v1, .L7F0322CC
   sw    $t3, 0x34($sp)
  jal   sub_GAME_7F0282E0
   move  $a0, $s0
.L7F0322CC:
  lw    $t5, 0x84($s0)
  li    $at, 10
  div   $zero, $t5, $at
  mfhi  $t4
  li    $at, 5
  bnel  $t4, $at, .L7F0323E0
   lw    $t9, 0x84($s0)
  lbu   $v1, 0x58($s0)
  sll   $t6, $v1, 2
  addu  $t7, $s0, $t6
  lw    $v0, 0x40($t7)
  sll   $t8, $v1, 2
  addu  $a0, $s0, $t8
  beql  $v0, $zero, .L7F0323E0
   lw    $t9, 0x84($s0)
  lw    $v0, 0x44($a0)
  li    $t6, 16
  beql  $v0, $zero, .L7F0323E0
   lw    $t9, 0x84($s0)
  lw    $v0, 0x48($a0)
  addiu $t3, $s0, 0x2c
  move  $a0, $s0
  beql  $v0, $zero, .L7F032364
   sw    $t3, 0x80($sp)
  lw    $t9, ($v0)
  lui   $t0, %hi(ptr_0xxxpresets) 
  lw    $t0, %lo(ptr_0xxxpresets)($t0)
  sll   $t1, $t9, 2
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  subu  $t1, $t1, $t9
  sll   $t1, $t1, 2
  addu  $v1, $t1, $t0
  sw    $v1, 0x80($sp)
  lw    $t2, 0x28($v1)
  b     .L7F03236C
   sw    $t2, 0x7c($sp)
  sw    $t3, 0x80($sp)
.L7F032364:
  lw    $a2, 0x38($s0)
  sw    $a2, 0x7c($sp)
.L7F03236C:
  lw    $t5, 0x78($sp)
  lw    $t4, 0x7c($sp)
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x14($t5)
  sw    $t6, 0x14($sp)
  lw    $a3, 0x80($sp)
  jal   sub_GAME_7F030128
   sw    $t4, 0x10($sp)
  beqz  $v0, .L7F0323DC
   lui   $at, %hi(D_80052068)
  lwc1  $f4, 0x24($s0)
  lwc1  $f6, %lo(D_80052068)($at)
  lw    $t7, 0x78($sp)
  li    $t8, 16
  mul.s $f8, $f4, $f6
  lw    $a2, 0x14($t7)
  sw    $t8, 0x14($sp)
  move  $a0, $s0
  lw    $a1, 0x2c($sp)
  lw    $a3, 0x80($sp)
  jal   sub_GAME_7F0301FC
   swc1  $f8, 0x10($sp)
  beql  $v0, $zero, .L7F0323E0
   lw    $t9, 0x84($s0)
  jal   sub_GAME_7F0282E0
   move  $a0, $s0
  jal   sub_GAME_7F0282E0
   move  $a0, $s0
.L7F0323DC:
  lw    $t9, 0x84($s0)
.L7F0323E0:
  li    $at, 10
  div   $zero, $t9, $at
  mfhi  $t1
  bnezl $t1, .L7F0324D4
   lbu   $t4, 0x58($s0)
  lbu   $v1, 0x58($s0)
  move  $a0, $s0
  sll   $t0, $v1, 2
  addu  $t2, $s0, $t0
  lw    $v0, 0x40($t2)
  sll   $t3, $v1, 2
  addu  $t5, $s0, $t3
  beqz  $v0, .L7F0324D0
   li    $t2, 16
  lw    $v0, 0x44($t5)
  addiu $t9, $s0, 0x2c
  beql  $v0, $zero, .L7F032460
   sw    $t9, 0x80($sp)
  lw    $t4, ($v0)
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  sll   $t6, $t4, 2
  subu  $t6, $t6, $t4
  sll   $t6, $t6, 2
  subu  $t6, $t6, $t4
  sll   $t6, $t6, 2
  addu  $v1, $t6, $t7
  sw    $v1, 0x80($sp)
  lw    $t8, 0x28($v1)
  b     .L7F032468
   sw    $t8, 0x7c($sp)
  sw    $t9, 0x80($sp)
.L7F032460:
  lw    $a2, 0x38($s0)
  sw    $a2, 0x7c($sp)
.L7F032468:
  lw    $t1, 0x78($sp)
  lw    $t0, 0x7c($sp)
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x14($t1)
  sw    $t2, 0x14($sp)
  lw    $a3, 0x80($sp)
  jal   sub_GAME_7F030128
   sw    $t0, 0x10($sp)
  beqz  $v0, .L7F0324D0
   lui   $at, %hi(D_8005206C)
  lwc1  $f10, 0x24($s0)
  lwc1  $f16, %lo(D_8005206C)($at)
  lw    $t3, 0x78($sp)
  li    $t5, 16
  mul.s $f18, $f10, $f16
  lw    $a2, 0x14($t3)
  sw    $t5, 0x14($sp)
  move  $a0, $s0
  lw    $a1, 0x2c($sp)
  lw    $a3, 0x80($sp)
  jal   sub_GAME_7F0301FC
   swc1  $f18, 0x10($sp)
  beql  $v0, $zero, .L7F0324D4
   lbu   $t4, 0x58($s0)
  jal   sub_GAME_7F0282E0
   move  $a0, $s0
.L7F0324D0:
  lbu   $t4, 0x58($s0)
.L7F0324D4:
  addiu $t0, $s0, 0x2c
  move  $a0, $s0
  sll   $t6, $t4, 2
  addu  $t7, $s0, $t6
  lw    $v0, 0x40($t7)
  beql  $v0, $zero, .L7F032524
   sw    $t0, 0x80($sp)
  lw    $t8, ($v0)
  lui   $t1, %hi(ptr_0xxxpresets) 
  lw    $t1, %lo(ptr_0xxxpresets)($t1)
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $v1, $t9, $t1
  sw    $v1, 0x80($sp)
  b     .L7F032528
   lw    $a2, 0x28($v1)
  sw    $t0, 0x80($sp)
.L7F032524:
  lw    $a2, 0x38($s0)
.L7F032528:
  lw    $a1, 0x80($sp)
  jal   sub_GAME_7F0315A4
   lw    $a3, 0x34($sp)
.L7F032534:
  lw    $ra, 0x24($sp)
.L7F032538:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x88
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032548
  addiu $sp, $sp, -0x40
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  lw    $t6, 0x18($a0)
  move  $s0, $a0
  jal   sub_GAME_7F028474
   sw    $t6, 0x3c($sp)
  sw    $zero, 0x34($sp)
  lw    $t7, 0x60($s0)
  lb    $t0, 0x38($s0)
  lui   $t9, %hi(global_timer) 
  addiu $t8, $t7, 1
  sw    $t8, 0x60($s0)
  lw    $t9, %lo(global_timer)($t9)
  li    $at, 6
  move  $s1, $v0
  beq   $t0, $at, .L7F0325D8
   sw    $t9, 0xc8($s0)
  lw    $t2, 0x78($s0)
  lui   $t1, %hi(global_timer) 
  lw    $t1, %lo(global_timer)($t1)
  addiu $t3, $t2, 0xb4
  move  $a0, $s0
  slt   $at, $t3, $t1
  beql  $at, $zero, .L7F0325DC
   lb    $t5, 0x38($s0)
  jal   sub_GAME_7F027E70
   move  $a1, $v0
  beqz  $v0, .L7F0325D8
   li    $t4, 1
  sw    $t4, 0x34($sp)
  move  $a0, $s0
  addiu $a1, $s0, 0x38
  jal   sub_GAME_7F027E90
   move  $a2, $s1
.L7F0325D8:
  lb    $t5, 0x38($s0)
.L7F0325DC:
  li    $at, 6
  addiu $t1, $s0, 0x38
  bne   $t5, $at, .L7F032660
   addiu $a0, $s0, 0xbc
  lw    $t6, 0x34($sp)
  lw    $t7, 0x3c($sp)
  bnezl $t6, .L7F03263C
   lw    $t2, 0x28($s1)
  lbu   $t8, 1($t7)
  move  $a0, $s0
  andi  $t9, $t8, 2
  bnez  $t9, .L7F03261C
   nop   
  jal   sub_GAME_7F027E70
   move  $a1, $s1
  bnez  $v0, .L7F032638
.L7F03261C:
   lui   $t0, %hi(global_timer) 
  lw    $t0, %lo(global_timer)($t0)
  move  $a0, $s0
  jal   sub_GAME_7F028494
   sw    $t0, 0x78($s0)
  b     .L7F0326AC
   lw    $ra, 0x24($sp)
.L7F032638:
  lw    $t2, 0x28($s1)
.L7F03263C:
  lui   $a2, %hi(D_80030984)
  lw    $a2, %lo(D_80030984)($a2)
  move  $a0, $s0
  addiu $a1, $s0, 0x38
  move  $a3, $s1
  jal   sub_GAME_7F028600
   sw    $t2, 0x10($sp)
  b     .L7F0326AC
   lw    $ra, 0x24($sp)
.L7F032660:
  lw    $a1, 0x3c($sp)
  sw    $t1, 0x2c($sp)
  move  $a2, $s1
  lui   $a3, 0x41f0
  jal   sub_GAME_7F02FD50
   addiu $a1, $a1, 8
  beql  $v0, $zero, .L7F032698
   move  $a0, $s0
  jal   sub_GAME_7F0284DC
   move  $a0, $s0
  jal   sub_GAME_7F028474
   move  $a0, $s0
  move  $s1, $v0
  move  $a0, $s0
.L7F032698:
  move  $a1, $s1
  lw    $a2, 0x28($s1)
  jal   sub_GAME_7F0315A4
   lw    $a3, 0x2c($sp)
  lw    $ra, 0x24($sp)
.L7F0326AC:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x40
");

asm(R"
.late_rodata
glabel jpt_80052070
 .word .L7F032788
 .word .L7F032798
 .word .L7F0327A8
 .word .L7F0327B8
 .word .L7F032808
 .word .L7F0327C8
 .word .L7F0327D8
 .word .L7F032818
 .word .L7F032828
 .word .L7F032838
 .word .L7F0327E8
 .word .L7F0327F8
 .word .L7F032848
 .word .L7F032858
 .word .L7F032868
 .word .L7F032878
 .word def_7F032780
 .word .L7F032898
 .word .L7F0328A8
 .word .L7F0328B8
 .word def_7F032780
 .word .L7F032888
 .word .L7F0328C8
 .word .L7F0328D8
.text
glabel manage_actions
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  blez  $v0, .L7F032908
   sw    $ra, 0x1c($sp)
  lb    $t6, 7($a0)
  bnezl $t6, .L7F032708
   lhu   $t9, 0x12($s0)
  lw    $t7, 0x14($a0)
  li    $a1, 0
  ori   $t8, $t7, 1
  jal   sub_GAME_7F023A94
   sw    $t8, 0x14($a0)
  sb    $zero, 8($s0)
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lhu   $t9, 0x12($s0)
.L7F032708:
  move  $a0, $s0
  li    $a1, 3
  andi  $t0, $t9, 0x40
  beql  $t0, $zero, .L7F032734
   lb    $t3, 8($s0)
  lw    $t1, 0x110($s0)
  addu  $t2, $t1, $v0
  sw    $t2, 0x110($s0)
  lui   $v0, %hi(clock_timer)
  lw    $v0, %lo(clock_timer)($v0)
  lb    $t3, 8($s0)
.L7F032734:
  subu  $t4, $t3, $v0
  sb    $t4, 8($s0)
  lb    $t5, 8($s0)
  bltz  $t5, .L7F032758
   nop   
  lw    $t6, 0x14($s0)
  sll   $t7, $t6, 0xd
  bgezl $t7, .L7F03290C
   lw    $ra, 0x1c($sp)
.L7F032758:
  jal   parse_handle_actionblocks
   sb    $zero, 8($s0)
  lb    $t8, 7($s0)
  addiu $t9, $t8, -1
  sltiu $at, $t9, 0x18
  beqz  $at, .L7F0328E0
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80052070)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80052070)($at)
  jr    $t9
   nop   
.L7F032788:
  jal   sub_GAME_7F02AD98
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032798:
  jal   actor_reset_sleep
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327A8:
  jal   sub_GAME_7F02B4E8
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327B8:
  jal   guard_body_hit_sfx
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327C8:
  jal   sub_GAME_7F02BC80
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327D8:
  jal   sub_GAME_7F02BD20
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327E8:
  jal   sub_GAME_7F02BDA4
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0327F8:
  jal   sub_GAME_7F02BE00
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032808:
  jal   manage_guard_fade
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032818:
  jal   sub_GAME_7F02EBFC
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032828:
  jal   sub_GAME_7F02F888
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032838:
  jal   sub_GAME_7F02EEE0
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032848:
  jal   sub_GAME_7F02FE78
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032858:
  jal   sub_GAME_7F032548
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032868:
  jal   sub_GAME_7F032088
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032878:
  jal   sub_GAME_7F02B638
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032888:
  jal   sub_GAME_7F02BE58
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F032898:
  jal   sub_GAME_7F02BF24
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0328A8:
  jal   sub_GAME_7F02BEA8
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0328B8:
  jal   sub_GAME_7F02F3F8
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0328C8:
  jal   sub_GAME_7F02F5A4
   move  $a0, $s0
  b     .L7F0328E4
   lw    $t0, 0x14($s0)
.L7F0328D8:
  jal   sub_GAME_7F02F688
   move  $a0, $s0
def_7F032780:
.L7F0328E0:
  lw    $t0, 0x14($s0)
.L7F0328E4:
  lhu   $t2, 0x12($s0)
  li    $v0, -1
  li    $at, -5
  and   $t1, $t0, $at
  andi  $t3, $t2, 0xfdfd
  sw    $t1, 0x14($s0)
  sh    $t3, 0x12($s0)
  sh    $v0, 0x118($s0)
  sh    $v0, 0x11a($s0)
.L7F032908:
  lw    $ra, 0x1c($sp)
.L7F03290C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F03291C
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  jal   get_numguards
   sw    $s0, 0x18($sp)
  lui   $t6, %hi(objectiveregisters3) 
  lw    $t6, %lo(objectiveregisters3)($t6)
  move  $t3, $v0
  move  $v1, $zero
  blez  $t6, .L7F032980
   move  $s0, $zero
.L7F032944:
  lui   $t7, %hi(objectiveregisters2) 
  lw    $t7, %lo(objectiveregisters2)($t7)
  sw    $v1, 0x24($sp)
  sw    $t3, 0x20($sp)
  jal   manage_actions
   addu  $a0, $s0, $t7
  lw    $v1, 0x24($sp)
  lui   $t8, %hi(objectiveregisters3) 
  lw    $t8, %lo(objectiveregisters3)($t8)
  addiu $v1, $v1, 1
  addiu $s0, $s0, 0x1dc
  slt   $at, $v1, $t8
  bnez  $at, .L7F032944
   lw    $t3, 0x20($sp)
  move  $v1, $zero
.L7F032980:
  lui   $a0, %hi(setting_007_5)
  addiu $a0, %lo(setting_007_5) # addiu $a0, $a0, -0x31b0
  blez  $t3, .L7F032B54
   sw    $zero, ($a0)
  andi  $v0, $t3, 3
  beqz  $v0, .L7F032A0C
   move  $a3, $v0
  sll   $t9, $v1, 4
  subu  $t9, $t9, $v1
  lui   $t4, %hi(ptr_guard_data) 
  lw    $t4, %lo(ptr_guard_data)($t4)
  sll   $t9, $t9, 3
  subu  $t9, $t9, $v1
  sll   $t9, $t9, 2
  lui   $a2, %hi(global_timer)
  addiu $a2, %lo(global_timer) # addiu $a2, $a2, -0x7c84
  addu  $a1, $t9, $t4
.L7F0329C4:
  lw    $t5, 0x1c($a1)
  addiu $v1, $v1, 1
  beqz  $t5, .L7F032A00
   nop   
  lw    $v0, 0xd4($a1)
  blez  $v0, .L7F032A00
   nop   
  lw    $t6, ($a2)
  subu  $t7, $t6, $v0
  slti  $at, $t7, 0x78
  beqz  $at, .L7F032A00
   nop   
  lw    $t8, ($a0)
  addiu $t9, $t8, 1
  sw    $t9, ($a0)
.L7F032A00:
  bne   $a3, $v1, .L7F0329C4
   addiu $a1, $a1, 0x1dc
  beq   $v1, $t3, .L7F032B54
.L7F032A0C:
   sll   $s0, $v1, 4
  subu  $s0, $s0, $v1
  lui   $t4, %hi(ptr_guard_data) 
  lw    $t4, %lo(ptr_guard_data)($t4)
  sll   $s0, $s0, 3
  subu  $s0, $s0, $v1
  sll   $s0, $s0, 2
  sll   $t2, $t3, 4
  subu  $t2, $t2, $t3
  addu  $a1, $s0, $t4
  sll   $t2, $t2, 3
  subu  $t2, $t2, $t3
  lui   $a2, %hi(global_timer)
  addiu $a2, %lo(global_timer) # addiu $a2, $a2, -0x7c84
  sll   $t2, $t2, 2
  addiu $a3, $a1, 0x1dc
  addiu $t0, $a1, 0x3b8
  addiu $t1, $a1, 0x594
.L7F032A54:
  lw    $t5, 0x1c($a1)
  addiu $s0, $s0, 0x770
  beql  $t5, $zero, .L7F032A94
   lw    $t4, 0x1c($a3)
  lw    $v0, 0xd4($a1)
  blezl $v0, .L7F032A94
   lw    $t4, 0x1c($a3)
  lw    $t6, ($a2)
  subu  $t7, $t6, $v0
  slti  $at, $t7, 0x78
  beql  $at, $zero, .L7F032A94
   lw    $t4, 0x1c($a3)
  lw    $t8, ($a0)
  addiu $t9, $t8, 1
  sw    $t9, ($a0)
  lw    $t4, 0x1c($a3)
.L7F032A94:
  move  $v0, $a3
  addiu $a3, $a3, 0x770
  beqz  $t4, .L7F032AD0
   addiu $a1, $a1, 0x770
  lw    $v1, 0xd4($v0)
  blezl $v1, .L7F032AD4
   lw    $t9, 0x1c($t0)
  lw    $t5, ($a2)
  subu  $t6, $t5, $v1
  slti  $at, $t6, 0x78
  beql  $at, $zero, .L7F032AD4
   lw    $t9, 0x1c($t0)
  lw    $t7, ($a0)
  addiu $t8, $t7, 1
  sw    $t8, ($a0)
.L7F032AD0:
  lw    $t9, 0x1c($t0)
.L7F032AD4:
  move  $v0, $t0
  addiu $t0, $t0, 0x770
  beql  $t9, $zero, .L7F032B14
   lw    $t8, 0x1c($t1)
  lw    $v1, 0xd4($v0)
  blezl $v1, .L7F032B14
   lw    $t8, 0x1c($t1)
  lw    $t4, ($a2)
  subu  $t5, $t4, $v1
  slti  $at, $t5, 0x78
  beql  $at, $zero, .L7F032B14
   lw    $t8, 0x1c($t1)
  lw    $t6, ($a0)
  addiu $t7, $t6, 1
  sw    $t7, ($a0)
  lw    $t8, 0x1c($t1)
.L7F032B14:
  move  $v0, $t1
  beqz  $t8, .L7F032B4C
   nop   
  lw    $v1, 0xd4($v0)
  blez  $v1, .L7F032B4C
   nop   
  lw    $t9, ($a2)
  subu  $t4, $t9, $v1
  slti  $at, $t4, 0x78
  beqz  $at, .L7F032B4C
   nop   
  lw    $t5, ($a0)
  addiu $t6, $t5, 1
  sw    $t6, ($a0)
.L7F032B4C:
  bne   $s0, $t2, .L7F032A54
   addiu $t1, $t1, 0x770
.L7F032B54:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032B68
  lw    $v0, 0xd4($a0)
  lui   $t6, %hi(global_timer) 
  blezl $v0, .L7F032B98
   move  $v0, $zero
  lw    $t6, %lo(global_timer)($t6)
  subu  $t7, $t6, $v0
  slti  $at, $t7, 0x258
  beql  $at, $zero, .L7F032B98
   move  $v0, $zero
  jr    $ra
   li    $v0, 1

  move  $v0, $zero
.L7F032B98:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032BA0
  lw    $v0, 0xf0($a0)
  lui   $t6, %hi(global_timer) 
  blezl $v0, .L7F032BD0
   move  $v0, $zero
  lw    $t6, %lo(global_timer)($t6)
  subu  $t7, $t6, $v0
  slti  $at, $t7, 0x258
  beql  $at, $zero, .L7F032BD0
   move  $v0, $zero
  jr    $ra
   li    $v0, 1

  move  $v0, $zero
.L7F032BD0:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800520D0
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_distance_actor_to_position
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  jal   getsubroty
   lw    $a0, 0x1c($a0)
  lw    $t7, 0x20($sp)
  lw    $v1, 0x24($sp)
  lw    $v0, 0x18($t7)
  lwc1  $f4, ($v1)
  lwc1  $f8, 8($v1)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  swc1  $f0, 0x18($sp)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f2, 0x18($sp)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_800520D0)
  c.lt.s $f0, $f2
  addiu $sp, $sp, 0x20
  sub.s $f14, $f0, $f2
  bc1f  .L7F032C44
   mov.s $f12, $f14
  lwc1  $f16, %lo(D_800520D0)($at)
  add.s $f12, $f14, $f16
.L7F032C44:
  jr    $ra
   mov.s $f0, $f12
");

asm(R"
glabel sub_GAME_7F032C4C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  jal   get_distance_actor_to_position
   addiu $a1, $v0, 8
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032C78
  addiu $sp, $sp, -0x18
  andi  $t6, $a1, 4
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F032CD0
   sw    $a3, 0x24($sp)
  move  $a1, $a2
  jal   get_handle_for_guard_id
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  beqz  $v0, .L7F032CB0
   move  $v1, $v0
  lw    $t7, 0x18($v0)
  bnezl $t7, .L7F032CB8
   lw    $t8, 0x18($a0)
.L7F032CB0:
  move  $v1, $a0
  lw    $t8, 0x18($a0)
.L7F032CB8:
  lw    $t0, 0x24($sp)
  lw    $t9, 0x14($t8)
  sw    $t9, ($t0)
  lw    $v0, 0x18($v1)
  b     .L7F032D60
   addiu $v0, $v0, 8
.L7F032CD0:
  andi  $t1, $a1, 8
  beqz  $t1, .L7F032D48
   nop   
  jal   sub_GAME_7F032F94
   move  $a1, $a2
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F032D14
   lw    $t7, 0x24($sp)
  sll   $t2, $v0, 2
  subu  $t2, $t2, $v0
  sll   $t2, $t2, 2
  lui   $t3, %hi(ptr_0xxxpresets) 
  lw    $t3, %lo(ptr_0xxxpresets)($t3)
  subu  $t2, $t2, $v0
  sll   $t2, $t2, 2
  b     .L7F032D38
   addu  $v1, $t2, $t3
.L7F032D14:
  lui   $t5, %hi(ptr_2xxxpresets) 
  lw    $t5, %lo(ptr_2xxxpresets)($t5)
  sll   $t4, $v0, 4
  addu  $t4, $t4, $v0
  sll   $t4, $t4, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t4, $t5
  addu  $v1, $v1, $at
.L7F032D38:
  lw    $t6, 0x28($v1)
  move  $v0, $v1
  b     .L7F032D60
   sw    $t6, ($t7)
.L7F032D48:
  jal   get_curplayer_positiondata
   nop   
  lw    $t8, 0x14($v0)
  lw    $t9, 0x24($sp)
  addiu $v0, $v0, 8
  sw    $t8, ($t9)
.L7F032D60:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800520D4
.word 0x40c90fdb /*6.2831855*/
.text
glabel get_angle_between_actor_cur_player
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   get_curplay_horizontal_rotation_in_degrees
   sw    $a0, 0x20($sp)
  lw    $t6, 0x20($sp)
  swc1  $f0, 0x1c($sp)
  lw    $v1, 0x18($t6)
  jal   get_curplayer_positiondata
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f10, 0x10($v0)
  lwc1  $f4, 8($v1)
  lwc1  $f8, 0x10($v1)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f14, 0x1c($sp)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(D_800520D4)
  c.lt.s $f0, $f14
  addiu $sp, $sp, 0x20
  sub.s $f12, $f0, $f14
  bc1f  .L7F032DDC
   mov.s $f2, $f12
  lwc1  $f16, %lo(D_800520D4)($at)
  add.s $f2, $f12, $f16
.L7F032DDC:
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F032DE4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v1, 0x18($a0)
  jal   get_curplayer_positiondata
   sw    $v1, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0xc($v1)
  lwc1  $f16, 0x10($v0)
  sub.s $f0, $f4, $f6
  lwc1  $f18, 0x10($v1)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032E48
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $a2, 0x18($a0)
  jal   sub_GAME_7F032F94
   sw    $a2, 0x1c($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F032E8C
   lw    $a2, 0x1c($sp)
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F032EB0
   addu  $v1, $t6, $t7
.L7F032E8C:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  sll   $t8, $v0, 4
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t8, $t9
  addu  $v1, $v1, $at
.L7F032EB0:
  lwc1  $f4, ($v1)
  lwc1  $f6, 8($a2)
  lwc1  $f8, 4($v1)
  lwc1  $f10, 0xc($a2)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($v1)
  lwc1  $f18, 0x10($a2)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel check_if_room_for_preset_loaded
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F032F94
   nop   
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F032F3C
   sll   $t8, $v0, 4
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F032F5C
   addu  $v1, $t6, $t7
.L7F032F3C:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t8, $t9
  addu  $v1, $v1, $at
.L7F032F5C:
  lw    $a0, 0x28($v1)
  move  $v0, $zero
  beqz  $a0, .L7F032F84
   nop   
  jal   sub_GAME_7F0B2FD8
   nop   
  jal   sub_GAME_7F0B5E50
   move  $a0, $v0
  b     .L7F032F88
   lw    $ra, 0x14($sp)
.L7F032F84:
  lw    $ra, 0x14($sp)
.L7F032F88:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F032F94
  li    $at, 9000
  bne   $a1, $at, .L7F032FA4
   nop   
  lh    $a1, 0x114($a0)
.L7F032FA4:
  jr    $ra
   move  $v0, $a1
");

asm(R"
glabel sub_GAME_7F032FAC
  li    $at, 250
  bnel  $a1, $at, .L7F032FC4
   li    $at, 251
  jr    $ra
   lh    $v0, 0x118($a0)

  li    $at, 251
.L7F032FC4:
  bnel  $a1, $at, .L7F032FD8
   li    $at, 252
  jr    $ra
   lh    $v0, 0x11a($a0)

  li    $at, 252
.L7F032FD8:
  bnel  $a1, $at, .L7F032FEC
   li    $at, 253
  jr    $ra
   lh    $v0, 0x116($a0)

  li    $at, 253
.L7F032FEC:
  bnel  $a1, $at, .L7F033000
   li    $at, 249
  jr    $ra
   lh    $v0, ($a0)

  li    $at, 249
.L7F033000:
  bnel  $a1, $at, .L7F033018
   li    $at, 248
  lh    $a1, ($a0)
  jr    $ra
   addiu $v0, $a1, 0x2710

  li    $at, 248
.L7F033018:
  bne   $a1, $at, .L7F033038
   lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  lw    $t7, 0xa8($t6)
  lw    $v0, 4($t7)
  beqz  $v0, .L7F033038
   nop   
  lh    $a1, ($v0)
.L7F033038:
  jr    $ra
   move  $v0, $a1
");

asm(R"
glabel get_handle_for_guard_id
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F032FAC
   nop   
  move  $a0, $v0
  jal   check_if_guardnum_loaded_get_ptr_GUARDdata
   sw    $v0, 0x1c($sp)
  lw    $a2, 0x1c($sp)
  bnez  $v0, .L7F0330B0
   move  $t0, $v0
  lui   $a1, %hi(objectiveregisters3)
  lw    $a1, %lo(objectiveregisters3)($a1)
  move  $v0, $zero
  lui   $a3, %hi(objectiveregisters2)
  blezl $a1, .L7F0330B4
   lw    $ra, 0x14($sp)
  lw    $a3, %lo(objectiveregisters2)($a3)
  move  $a0, $zero
  move  $v1, $a3
.L7F03308C:
  lh    $t6, ($v1)
  addiu $v0, $v0, 1
  slt   $at, $v0, $a1
  bne   $a2, $t6, .L7F0330A8
   addiu $v1, $v1, 0x1dc
  b     .L7F0330B0
   addu  $t0, $a0, $a3
.L7F0330A8:
  bnez  $at, .L7F03308C
   addiu $a0, $a0, 0x1dc
.L7F0330B0:
  lw    $ra, 0x14($sp)
.L7F0330B4:
  addiu $sp, $sp, 0x18
  move  $v0, $t0
  jr    $ra
   nop   
");

asm(R"
glabel get_distance_between_actor_and_actorID
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $v1, 0x18($a0)
  jal   get_handle_for_guard_id
   sw    $v1, 0x1c($sp)
  mtc1  $zero, $f2
  beqz  $v0, .L7F033140
   lw    $v1, 0x1c($sp)
  lw    $t6, 0x1c($v0)
  beql  $t6, $zero, .L7F033144
   lw    $ra, 0x14($sp)
  lw    $t7, 0x18($v0)
  beql  $t7, $zero, .L7F033144
   lw    $ra, 0x14($sp)
  lw    $v0, 0x18($v0)
  lwc1  $f6, 8($v1)
  lwc1  $f10, 0xc($v1)
  lwc1  $f4, 8($v0)
  lwc1  $f8, 0xc($v0)
  lwc1  $f18, 0x10($v1)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 0x10($v0)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  mov.s $f2, $f0
.L7F033140:
  lw    $ra, 0x14($sp)
.L7F033144:
  addiu $sp, $sp, 0x20
  mov.s $f0, $f2
  jr    $ra
   nop   
");

asm(R"
glabel get_distance_between_actor_and_preset
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_curplayer_positiondata
   sw    $a1, 0x24($sp)
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  jal   sub_GAME_7F032F94
   sw    $v0, 0x1c($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F0331A8
   lw    $a2, 0x1c($sp)
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F0331CC
   addu  $v1, $t6, $t7
.L7F0331A8:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  sll   $t8, $v0, 4
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t8, $t9
  addu  $v1, $v1, $at
.L7F0331CC:
  lwc1  $f4, ($v1)
  lwc1  $f6, 8($a2)
  lwc1  $f8, 4($v1)
  lwc1  $f10, 0xc($a2)
  sub.s $f0, $f4, $f6
  lwc1  $f16, 8($v1)
  lwc1  $f18, 0x10($a2)
  sub.s $f2, $f8, $f10
  mul.s $f4, $f0, $f0
  sub.s $f14, $f16, $f18
  mul.s $f6, $f2, $f2
  add.s $f8, $f4, $f6
  mul.s $f10, $f14, $f14
  jal   sqrtf
   add.s $f12, $f8, $f10
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033218
  sw    $a1, 4($sp)
  lbu   $t7, 0x10e($a0)
  or    $t8, $t7, $a1
  jr    $ra
   sb    $t8, 0x10e($a0)
");

asm(R"
glabel sub_GAME_7F03322C
  sw    $a1, 4($sp)
  lbu   $t7, 0x10e($a0)
  not   $t8, $a1
  and   $t9, $t7, $t8
  jr    $ra
   sb    $t9, 0x10e($a0)
");

asm(R"
glabel sub_GAME_7F033244
  sw    $a1, 4($sp)
  lbu   $t7, 0x10e($a0)
  andi  $t6, $a1, 0xff
  and   $v0, $t7, $t6
  sltu  $t8, $zero, $v0
  jr    $ra
   move  $v0, $t8
");

asm(R"
glabel sub_GAME_7F033260
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F033280
   move  $a0, $v0
  jal   sub_GAME_7F033218
   lbu   $a1, 0x23($sp)
.L7F033280:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033290
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F0332B0
   move  $a0, $v0
  jal   sub_GAME_7F03322C
   lbu   $a1, 0x23($sp)
.L7F0332B0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0332C0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F0332E8
   move  $a0, $v0
  jal   sub_GAME_7F033244
   lbu   $a1, 0x23($sp)
  b     .L7F0332F0
   lw    $ra, 0x14($sp)
.L7F0332E8:
  move  $v0, $zero
  lw    $ra, 0x14($sp)
.L7F0332F0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel toggle_objective_bitflags
  lui   $v0, %hi(objectiveregisters1)
  addiu $v0, %lo(objectiveregisters1) # addiu $v0, $v0, 0x978
  lw    $t6, ($v0)
  sw    $a0, ($sp)
  or    $t7, $t6, $a1
  jr    $ra
   sw    $t7, ($v0)
");

asm(R"
glabel untoggle_objective_bitflags
  lui   $v0, %hi(objectiveregisters1)
  addiu $v0, %lo(objectiveregisters1) # addiu $v0, $v0, 0x978
  lw    $t7, ($v0)
  not   $t6, $a1
  sw    $a0, ($sp)
  and   $t8, $t6, $t7
  jr    $ra
   sw    $t8, ($v0)
");

asm(R"
glabel check_if_objective_bitflags_set
  lui   $t6, %hi(objectiveregisters1) 
  lw    $t6, %lo(objectiveregisters1)($t6)
  sw    $a0, ($sp)
  and   $v0, $t6, $a1
  sltu  $t7, $zero, $v0
  jr    $ra
   move  $v0, $t7
");

asm(R"
glabel check_if_actor_02_flag_set
  lhu   $v0, 0x12($a0)
  andi  $t6, $v0, 2
  jr    $ra
   sltu  $v0, $zero, $t6
");

asm(R"
glabel check_if_able_to_then_surrender
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F033390
   move  $v0, $zero
  jal   actor_throw_weapon_surrender
   lw    $a0, 0x18($sp)
  b     .L7F033390
   li    $v0, 1
  move  $v0, $zero
.L7F033390:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0333A0
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   actor_fade_away
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  li    $v0, 1
  jr    $ra
   nop   
");

asm(R"
glabel reset_and_start_loop_counter
  lhu   $t6, 0x12($a0)
  sw    $zero, 0x110($a0)
  ori   $t7, $t6, 0x40
  jr    $ra
   sh    $t7, 0x12($a0)
");

asm(R"
glabel get_loop_counter_time_in_seconds
  lw    $t6, 0x110($a0)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f8
  mtc1  $t6, $f4
  nop   
  cvt.s.w $f6, $f4
  jr    $ra
   div.s $f0, $f6, $f8
");

asm(R"
.late_rodata
glabel D_800520D8
.word 0x3f4ccccd /*0.80000001*/
.text
glabel sub_GAME_7F0333F8
  addiu $sp, $sp, -0x48
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F029760
   sw    $a0, 0x48($sp)
  beqz  $v0, .L7F03347C
   lw    $t6, 0x48($sp)
  lw    $a0, 0x1c($t6)
  jal   getinstsize
   sw    $a0, 0x44($sp)
  lui   $at, %hi(D_800520D8)
  lwc1  $f4, %lo(D_800520D8)($at)
  addiu $a0, $sp, 0x38
  addiu $a1, $sp, 0x2c
  mul.s $f6, $f0, $f4
  jal   sub_GAME_7F068190
   swc1  $f6, 0x1c($sp)
  lw    $a0, 0x44($sp)
  jal   getsuboffset
   addiu $a1, $sp, 0x20
  jal   get_BONDdata_field_10CC
   nop   
  move  $a0, $v0
  jal   sub_GAME_7F058474
   addiu $a1, $sp, 0x20
  addiu $a0, $sp, 0x38
  addiu $a1, $sp, 0x2c
  addiu $a2, $sp, 0x20
  jal   sub_GAME_7F041074
   lw    $a3, 0x1c($sp)
  beql  $v0, $zero, .L7F033480
   move  $v0, $zero
  b     .L7F033480
   li    $v0, 1
.L7F03347C:
  move  $v0, $zero
.L7F033480:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel check_if_actor_invisible
  lw    $v0, 0x14($a0)
  andi  $t6, $v0, 4
  jr    $ra
   sltu  $v0, $zero, $t6
");

asm(R"
glabel actor_move_to_curplayer_at_speed
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L7F0334F8
   lui   $t6, %hi(setting_007_5) 
  lw    $t6, %lo(setting_007_5)($t6)
  slti  $at, $t6, 0xa
  beql  $at, $zero, .L7F0334FC
   move  $v0, $zero
  jal   get_curplayer_positiondata
   nop   
  lw    $a0, 0x18($sp)
  addiu $a1, $v0, 8
  lw    $a2, 0x14($v0)
  jal   plot_course_for_actor
   lw    $a3, 0x1c($sp)
  beql  $v0, $zero, .L7F0334FC
   move  $v0, $zero
  b     .L7F0334FC
   li    $v0, 1
.L7F0334F8:
  move  $v0, $zero
.L7F0334FC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel actor_move_to_actorID_at_speed
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a2, 0x20($sp)
  beqz  $v0, .L7F033590
   lui   $t6, %hi(setting_007_5) 
  lw    $t6, %lo(setting_007_5)($t6)
  lw    $a0, 0x18($sp)
  slti  $at, $t6, 0xa
  beql  $at, $zero, .L7F033594
   move  $v0, $zero
  jal   get_handle_for_guard_id
   lw    $a1, 0x1c($sp)
  beql  $v0, $zero, .L7F033594
   move  $v0, $zero
  lw    $t7, 0x1c($v0)
  beql  $t7, $zero, .L7F033594
   move  $v0, $zero
  lw    $t8, 0x18($v0)
  beql  $t8, $zero, .L7F033594
   move  $v0, $zero
  lw    $v0, 0x18($v0)
  lw    $a0, 0x18($sp)
  lw    $a3, 0x20($sp)
  addiu $a1, $v0, 8
  jal   plot_course_for_actor
   lw    $a2, 0x14($v0)
  beql  $v0, $zero, .L7F033594
   move  $v0, $zero
  b     .L7F033594
   li    $v0, 1
.L7F033590:
  move  $v0, $zero
.L7F033594:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel get_times_actor_shot
  jr    $ra
   lb    $v0, 0xb($a0)
");

asm(R"
glabel get_num_shots_near_actor
  jr    $ra
   lb    $v0, 0xa($a0)
");

asm(R"
glabel check_if_actor_FA_target_set
  lh    $v0, 0x118($a0)
  slti  $t6, $v0, 0
  jr    $ra
   xori  $v0, $t6, 1
");

asm(R"
glabel check_if_actor_FB_target_set
  lh    $v0, 0x11a($a0)
  slti  $t6, $v0, 0
  jr    $ra
   xori  $v0, $t6, 1
");

asm(R"
glabel sub_GAME_7F0335D4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F033600
   move  $v0, $zero
  jal   sub_GAME_7F023E48
   lw    $a0, 0x18($sp)
  b     .L7F033600
   li    $v0, 1
  move  $v0, $zero
.L7F033600:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_able_to_then_shuffle_feet
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F03363C
   move  $v0, $zero
  jal   actor_shuffle_feet
   lw    $a0, 0x18($sp)
  b     .L7F03363C
   li    $v0, 1
  move  $v0, $zero
.L7F03363C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_able_to_then_fawn_on_shoulder
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F033678
   move  $v0, $zero
  jal   actor_fawn_on_shoulder
   lw    $a0, 0x18($sp)
  b     .L7F033678
   li    $v0, 1
  move  $v0, $zero
.L7F033678:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_able_to_then_look_flustered
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F0336B4
   move  $v0, $zero
  jal   actor_look_flustered
   lw    $a0, 0x18($sp)
  b     .L7F0336B4
   li    $v0, 1
  move  $v0, $zero
.L7F0336B4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_able_to_then_kneel
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F0336F0
   move  $v0, $zero
  jal   actor_kneel
   lw    $a0, 0x18($sp)
  b     .L7F0336F0
   li    $v0, 1
  move  $v0, $zero
.L7F0336F0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel check_if_able_to_then_perform_animation
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  jal   true_if_actor_dying_fading_limping_shot
   sw    $a3, 0x2c($sp)
  beqz  $v0, .L7F03374C
   lw    $a0, 0x20($sp)
  lbu   $t6, 0x33($sp)
  lw    $t7, 0x34($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  sw    $t6, 0x10($sp)
  jal   perform_animation_for_actor
   sw    $t7, 0x14($sp)
  b     .L7F033750
   li    $v0, 1
.L7F03374C:
  move  $v0, $zero
.L7F033750:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel alarm_timer_related
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   is_alarm_on
   sw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800520DC
.word 0x40c90fdb /*6.2831855*/
glabel D_800520E0
.word 0x3fc90fdb /*1.5707964*/
glabel D_800520E4
.word 0x4096cbe4 /*4.712389*/
.text
glabel sub_GAME_7F033780
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a2, 0x20($sp)
  lw    $t6, ($a0)
  lui   $t8, %hi(ptr_0xxxpresets) 
  lw    $t8, %lo(ptr_0xxxpresets)($t8)
  sll   $t7, $t6, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 2
  addu  $v0, $t7, $t8
  lwc1  $f4, ($v0)
  lwc1  $f6, ($a1)
  lwc1  $f8, 8($v0)
  lwc1  $f10, 8($a1)
  sub.s $f12, $f4, $f6
  jal   convert_angle_using_inverse
   sub.s $f14, $f8, $f10
  lwc1  $f14, 0x20($sp)
  lui   $at, %hi(D_800520DC)
  lw    $ra, 0x14($sp)
  c.lt.s $f14, $f0
  sub.s $f12, $f14, $f0
  bc1f  .L7F0337F0
   mov.s $f2, $f12
  lwc1  $f16, %lo(D_800520DC)($at)
  add.s $f2, $f12, $f16
.L7F0337F0:
  lui   $at, %hi(D_800520E0)
  lwc1  $f18, %lo(D_800520E0)($at)
  lui   $at, %hi(D_800520E4)
  c.lt.s $f2, $f18
  nop   
  bc1t  .L7F033824
   nop   
  lwc1  $f4, %lo(D_800520E4)($at)
  move  $v0, $zero
  c.lt.s $f4, $f2
  nop   
  bc1f  .L7F03382C
   nop   
.L7F033824:
  b     .L7F03382C
   li    $v0, 1
.L7F03382C:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
.late_rodata
glabel D_800520E8
.word 0x40490fdb /*3.1415927*/
glabel D_800520EC
.word 0x3fc90fdb /*1.5707964*/
glabel D_800520F0
.word 0x4096cbe4 /*4.712389*/
glabel D_800520F4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F033834
  addiu $sp, $sp, -0x38
  sdc1  $f20, 0x18($sp)
  mtc1  $a2, $f20
  sw    $ra, 0x34($sp)
  sw    $s4, 0x30($sp)
  sw    $s0, 0x20($sp)
  andi  $s0, $a3, 0xff
  move  $s4, $a0
  sw    $s3, 0x2c($sp)
  sw    $s2, 0x28($sp)
  sw    $s1, 0x24($sp)
  jal   sub_GAME_7F027CD4
   sw    $a3, 0x44($sp)
  beqz  $v0, .L7F033970
   move  $s3, $v0
  li    $at, 1
  beq   $s0, $at, .L7F0338A0
   move  $a0, $s3
  li    $at, 2
  beq   $s0, $at, .L7F0338B0
   li    $at, 4
  beq   $s0, $at, .L7F0338C0
   li    $at, 8
  beq   $s0, $at, .L7F0338CC
   nop   
  b     .L7F0338CC
   nop   
.L7F0338A0:
  lui   $at, %hi(D_800520E8)
  lwc1  $f4, %lo(D_800520E8)($at)
  b     .L7F0338CC
   add.s $f20, $f20, $f4
.L7F0338B0:
  lui   $at, %hi(D_800520EC)
  lwc1  $f6, %lo(D_800520EC)($at)
  b     .L7F0338CC
   add.s $f20, $f20, $f6
.L7F0338C0:
  lui   $at, %hi(D_800520F0)
  lwc1  $f8, %lo(D_800520F0)($at)
  add.s $f20, $f20, $f8
.L7F0338CC:
  lui   $at, %hi(D_800520F4)
  lwc1  $f0, %lo(D_800520F4)($at)
  c.le.s $f0, $f20
  nop   
  bc1fl .L7F0338EC
   mfc1  $a2, $f20
  sub.s $f20, $f20, $f0
  mfc1  $a2, $f20
.L7F0338EC:
  jal   sub_GAME_7F033780
   move  $a1, $s4
  beql  $v0, $zero, .L7F033908
   lw    $t6, 4($s3)
  b     .L7F033974
   lw    $v0, ($s3)
  lw    $t6, 4($s3)
.L7F033908:
  lui   $s2, %hi(ptr_setup_path_tbl)
  addiu $s2, %lo(ptr_setup_path_tbl) # addiu $s2, $s2, 0x5d00
  lw    $s1, ($t6)
  move  $s0, $zero
  bltzl $s1, .L7F033974
   li    $v0, -1
  lw    $t8, ($s2)
.L7F033924:
  sll   $t7, $s1, 4
  mfc1  $a2, $f20
  move  $a1, $s4
  jal   sub_GAME_7F033780
   addu  $a0, $t7, $t8
  beql  $v0, $zero, .L7F033958
   lw    $t2, 4($s3)
  lw    $t9, ($s2)
  sll   $t0, $s1, 4
  addu  $t1, $t9, $t0
  b     .L7F033974
   lw    $v0, ($t1)
  lw    $t2, 4($s3)
.L7F033958:
  addiu $s0, $s0, 1
  sll   $t3, $s0, 2
  addu  $t4, $t2, $t3
  lw    $s1, ($t4)
  bgezl $s1, .L7F033924
   lw    $t8, ($s2)
.L7F033970:
  li    $v0, -1
.L7F033974:
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  lw    $s3, 0x2c($sp)
  lw    $s4, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel check_2328_preset_set_with_method
  addiu $sp, $sp, -0x48
  sw    $s0, 0x14($sp)
  andi  $s0, $a1, 0xff
  sw    $s1, 0x18($sp)
  li    $at, 16
  move  $s1, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x4c($sp)
  beq   $s0, $at, .L7F0339CC
   move  $a2, $s0
  li    $at, 32
  bne   $s0, $at, .L7F033A60
   nop   
.L7F0339CC:
  lw    $s0, 0x18($s1)
  jal   get_curplayer_positiondata
   sw    $a2, 0x20($sp)
  lw    $a1, 0x14($s0)
  sw    $v0, 0x40($sp)
  jal   sub_GAME_7F027CD4
   addiu $a0, $s0, 8
  lw    $v1, 0x40($sp)
  move  $s0, $v0
  addiu $a0, $v1, 8
  jal   sub_GAME_7F027CD4
   lw    $a1, 0x14($v1)
  lw    $a2, 0x20($sp)
  beqz  $s0, .L7F033A94
   move  $a1, $v0
  beqz  $v0, .L7F033A94
   li    $at, 16
  bne   $a2, $at, .L7F033A40
   move  $a0, $s0
  addiu $a2, $sp, 0x2c
  jal   sub_GAME_7F08F4F0
   li    $a3, 3
  slti  $at, $v0, 3
  bnez  $at, .L7F033A94
   lw    $t6, 0x30($sp)
  lw    $t7, ($t6)
  li    $v0, 1
  b     .L7F033A98
   sh    $t7, 0x114($s1)
.L7F033A40:
  jal   sub_GAME_7F08FB90
   move  $a0, $s0
  beql  $v0, $zero, .L7F033A98
   move  $v0, $zero
  lw    $t8, ($v0)
  li    $v0, 1
  b     .L7F033A98
   sh    $t8, 0x114($s1)
.L7F033A60:
  jal   getsubroty
   lw    $a0, 0x1c($s1)
  lw    $v0, 0x18($s1)
  mfc1  $a2, $f0
  andi  $a3, $s0, 0xff
  addiu $a0, $v0, 8
  jal   sub_GAME_7F033834
   lw    $a1, 0x14($v0)
  bltzl $v0, .L7F033A98
   move  $v0, $zero
  sh    $v0, 0x114($s1)
  b     .L7F033A98
   li    $v0, 1
.L7F033A94:
  move  $v0, $zero
.L7F033A98:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F033AAC
  addiu $sp, $sp, -0x20
  andi  $a3, $a1, 0xff
  li    $at, 16
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  beq   $a3, $at, .L7F033AD8
   move  $v0, $a3
  li    $at, 32
  bne   $v0, $at, .L7F033AEC
   nop   
.L7F033AD8:
  lw    $a0, 0x20($sp)
  jal   check_2328_preset_set_with_method
   andi  $a1, $a3, 0xff
  b     .L7F033B2C
   lw    $ra, 0x14($sp)
.L7F033AEC:
  jal   get_curplay_horizontal_rotation_in_degrees
   sb    $a3, 0x27($sp)
  jal   get_curplayer_positiondata
   swc1  $f0, 0x1c($sp)
  lbu   $a3, 0x27($sp)
  addiu $a0, $v0, 8
  lw    $a1, 0x14($v0)
  jal   sub_GAME_7F033834
   lw    $a2, 0x1c($sp)
  bltz  $v0, .L7F033B24
   lw    $t6, 0x20($sp)
  sh    $v0, 0x114($t6)
  b     .L7F033B28
   li    $v0, 1
.L7F033B24:
  move  $v0, $zero
.L7F033B28:
  lw    $ra, 0x14($sp)
.L7F033B2C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033B38
  addiu $sp, $sp, -0x68
  mtc1  $a1, $f12
  sw    $ra, 0x64($sp)
  sw    $s5, 0x5c($sp)
  move  $s5, $a0
  sw    $s6, 0x60($sp)
  sw    $s4, 0x58($sp)
  sw    $s3, 0x54($sp)
  sw    $s2, 0x50($sp)
  sw    $s1, 0x4c($sp)
  sw    $s0, 0x48($sp)
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  jal   get_numguards
   swc1  $f12, 0x6c($sp)
  lw    $v1, 0x18($s5)
  lwc1  $f12, 0x6c($sp)
  move  $s4, $v0
  lwc1  $f0, 8($v1)
  lwc1  $f2, 0xc($v1)
  lwc1  $f14, 0x10($v1)
  lw    $t6, 0x14($v1)
  move  $s1, $zero
  sub.s $f20, $f0, $f12
  lbu   $s3, 3($t6)
  add.s $f22, $f0, $f12
  sub.s $f24, $f2, $f12
  add.s $f26, $f2, $f12
  sub.s $f28, $f14, $f12
  blez  $v0, .L7F033CB0
   add.s $f30, $f14, $f12
  lui   $s6, %hi(ptr_guard_data)
  addiu $s6, %lo(ptr_guard_data) # addiu $s6, $s6, -0x339c
  move  $s2, $zero
.L7F033BD0:
  lw    $t7, ($s6)
  addu  $s0, $s2, $t7
  beql  $s0, $s5, .L7F033CA4
   addiu $s1, $s1, 1
  lw    $t8, 0x1c($s0)
  beql  $t8, $zero, .L7F033CA4
   addiu $s1, $s1, 1
  jal   true_if_actor_dying_fading
   move  $a0, $s0
  bnezl $v0, .L7F033CA4
   addiu $s1, $s1, 1
  lw    $v1, 0x18($s0)
  addiu $v0, $v1, 8
  lwc1  $f0, ($v0)
  c.le.s $f20, $f0
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  c.le.s $f0, $f22
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  lwc1  $f0, 4($v0)
  c.le.s $f24, $f0
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  c.le.s $f0, $f26
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  lwc1  $f0, 8($v0)
  c.le.s $f28, $f0
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  c.le.s $f0, $f30
  nop   
  bc1fl .L7F033CA4
   addiu $s1, $s1, 1
  lw    $t9, 0x14($v1)
  lbu   $a1, 3($t9)
  beql  $s3, $a1, .L7F033C94
   lh    $t0, ($s0)
  jal   sub_GAME_7F0B8FD0
   move  $a0, $s3
  beql  $v0, $zero, .L7F033CA4
   addiu $s1, $s1, 1
  lh    $t0, ($s0)
.L7F033C94:
  li    $v0, 1
  b     .L7F033CB4
   sh    $t0, 0x116($s5)
  addiu $s1, $s1, 1
.L7F033CA4:
  slt   $at, $s1, $s4
  bnez  $at, .L7F033BD0
   addiu $s2, $s2, 0x1dc
.L7F033CB0:
  move  $v0, $zero
.L7F033CB4:
  lw    $ra, 0x64($sp)
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f30, 0x40($sp)
  lw    $s0, 0x48($sp)
  lw    $s1, 0x4c($sp)
  lw    $s2, 0x50($sp)
  lw    $s3, 0x54($sp)
  lw    $s4, 0x58($sp)
  lw    $s5, 0x5c($sp)
  lw    $s6, 0x60($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

asm(R"
glabel sub_GAME_7F033CF4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F032FAC
   sw    $a0, 0x18($sp)
  lw    $t6, 0x18($sp)
  sh    $v0, 0x116($t6)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033D1C
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x28($sp)
  beqz  $v0, .L7F033D4C
   lw    $a0, 0x20($sp)
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F032FAC
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  sh    $v0, 0x116($v1)
.L7F033D4C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033D5C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F032F94
   sw    $a0, 0x18($sp)
  lw    $t6, 0x18($sp)
  sh    $v0, 0x114($t6)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033D84
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x28($sp)
  beqz  $v0, .L7F033DB4
   lw    $a0, 0x20($sp)
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F032F94
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  sh    $v0, 0x114($v1)
.L7F033DB4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F033DC4
  addiu $sp, $sp, -0x60
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  jal   get_curplayer_positiondata
   sw    $a0, 0x60($sp)
  lw    $t6, 0x60($sp)
  move  $s1, $v0
  lw    $s0, 0x18($t6)
  lw    $t7, 0x14($s0)
  jal   sub_GAME_7F0B1CC4
   sw    $t7, 0x54($sp)
  lwc1  $f4, 0x10($s1)
  lw    $a1, 8($s0)
  lw    $a2, 0x10($s0)
  lw    $a3, 8($s1)
  addiu $a0, $sp, 0x54
  jal   sub_GAME_7F0B0BE4
   swc1  $f4, 0x10($sp)
  beqz  $v0, .L7F033E20
   addiu $a0, $sp, 0x48
  b     .L7F033E98
   move  $v0, $zero
.L7F033E20:
  jal   sub_GAME_7F0B28B0
   addiu $a1, $sp, 0x3c
  lw    $a2, 0x14($s0)
  addiu $v1, $s1, 8
  sw    $v1, 0x10($sp)
  lw    $t8, 0x14($s1)
  addiu $a1, $s0, 8
  sw    $a1, 0x38($sp)
  sw    $v1, 0x34($sp)
  sw    $zero, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a3, $sp, 0x48
  jal   sub_GAME_7F0304AC
   sw    $t8, 0x14($sp)
  lw    $v1, 0x34($sp)
  bnez  $v0, .L7F033E8C
   lw    $a1, 0x38($sp)
  lw    $a2, 0x14($s0)
  sw    $v1, 0x10($sp)
  lw    $t9, 0x14($s1)
  sw    $zero, 0x18($sp)
  lw    $a0, 0x60($sp)
  addiu $a3, $sp, 0x3c
  jal   sub_GAME_7F0304AC
   sw    $t9, 0x14($sp)
  beql  $v0, $zero, .L7F033E98
   move  $v0, $zero
.L7F033E8C:
  b     .L7F033E98
   li    $v0, 1
  move  $v0, $zero
.L7F033E98:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F033EAC
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a0, 0x30($sp)
  li    $t6, 1
  sw    $a1, 0x34($sp)
  sw    $t6, 0x2c($sp)
  jal   sub_GAME_7F0B2FD8
   move  $a0, $a1
  jal   sub_GAME_7F0B5E50
   move  $a0, $v0
  beqz  $v0, .L7F033F34
   lw    $a0, 0x30($sp)
  jal   sub_GAME_7F0BB2C8
   li    $a1, 0
  beql  $v0, $zero, .L7F033F38
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0B2FD8
   lw    $a0, 0x34($sp)
  move  $a0, $v0
  jal   sub_GAME_7F0B3C0C
   addiu $a1, $sp, 0x1c
  beqz  $v0, .L7F033F24
   lw    $a0, 0x30($sp)
  lw    $a0, 0x30($sp)
  lui   $a1, 0x4348
  jal   sub_GAME_7F078BF4
   addiu $a2, $sp, 0x1c
  sltiu $t7, $v0, 1
  b     .L7F033F34
   sw    $t7, 0x2c($sp)
.L7F033F24:
  jal   sub_GAME_7F078A58
   lui   $a1, 0x4348
  sltiu $t8, $v0, 1
  sw    $t8, 0x2c($sp)
.L7F033F34:
  lw    $ra, 0x14($sp)
.L7F033F38:
  lw    $v0, 0x2c($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_800520F8
.word 0x3f490fdb /*0.78539819*/
glabel D_800520FC
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F033F48
  addiu $sp, $sp, -0x98
  sw    $ra, 0x7c($sp)
  sw    $s6, 0x78($sp)
  sw    $s5, 0x74($sp)
  sw    $s4, 0x70($sp)
  sw    $s3, 0x6c($sp)
  sw    $s2, 0x68($sp)
  sw    $s1, 0x64($sp)
  sw    $s0, 0x60($sp)
  sdc1  $f30, 0x58($sp)
  sdc1  $f28, 0x50($sp)
  sdc1  $f26, 0x48($sp)
  sdc1  $f24, 0x40($sp)
  sdc1  $f22, 0x38($sp)
  sdc1  $f20, 0x30($sp)
  lw    $t6, ($a1)
  move  $s0, $a0
  mtc1  $a2, $f20
  sw    $t6, 0x88($sp)
  move  $s5, $a1
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f24
  mtc1  $zero, $f22
  lw    $a1, ($s0)
  lw    $a2, 8($s0)
  addiu $s2, $sp, 0x88
  move  $s6, $a3
  li    $t7, 31
  sw    $t7, 0x10($sp)
  lui   $a3, 0x41a0
  move  $a0, $s2
  swc1  $f24, 0x18($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f22, 0x14($sp)
  bgez  $v0, .L7F033FF8
   nop   
  bnez  $s6, .L7F033FF0
   move  $a0, $s0
  jal   sub_GAME_7F033EAC
   lw    $a1, ($s5)
  beqz  $v0, .L7F033FF8
   nop   
.L7F033FF0:
  b     .L7F03411C
   li    $v0, 1
.L7F033FF8:
  lui   $at, %hi(D_800520F8)
  lwc1  $f30, %lo(D_800520F8)($at)
  lui   $at, %hi(D_800520FC)
  lwc1  $f28, %lo(D_800520FC)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f26
  move  $s1, $zero
  li    $s4, 8
  addiu $s3, $sp, 0x8c
.L7F03401C:
  jal   sinf
   mov.s $f12, $f20
  mul.s $f4, $f0, $f26
  lwc1  $f6, ($s0)
  mov.s $f12, $f20
  add.s $f8, $f4, $f6
  swc1  $f8, 0x8c($sp)
  lwc1  $f10, 4($s0)
  jal   cosf
   swc1  $f10, 0x90($sp)
  mul.s $f16, $f0, $f26
  lwc1  $f18, 8($s0)
  li    $t9, 19
  move  $a0, $s2
  lw    $a3, 0x8c($sp)
  add.s $f4, $f16, $f18
  swc1  $f4, 0x94($sp)
  lw    $t8, ($s5)
  sw    $t8, 0x88($sp)
  lw    $a2, 8($s0)
  lw    $a1, ($s0)
  swc1  $f24, 0x24($sp)
  swc1  $f22, 0x20($sp)
  swc1  $f24, 0x1c($sp)
  swc1  $f22, 0x18($sp)
  sw    $t9, 0x14($sp)
  jal   sub_GAME_7F0B0E24
   swc1  $f4, 0x10($sp)
  beqz  $v0, .L7F0340F4
   move  $a0, $s2
  li    $t0, 31
  sw    $t0, 0x10($sp)
  lw    $a1, 0x8c($sp)
  lw    $a2, 0x94($sp)
  lui   $a3, 0x41a0
  swc1  $f22, 0x14($sp)
  jal   sub_GAME_7F0B18B8
   swc1  $f24, 0x18($sp)
  bgez  $v0, .L7F0340F4
   move  $a0, $s3
  bnezl $s6, .L7F0340D8
   lw    $t1, 0x88($sp)
  jal   sub_GAME_7F033EAC
   lw    $a1, 0x88($sp)
  beql  $v0, $zero, .L7F0340F8
   add.s $f20, $f20, $f30
  lw    $t1, 0x88($sp)
.L7F0340D8:
  li    $v0, 1
  sw    $t1, ($s5)
  lwc1  $f6, 0x8c($sp)
  swc1  $f6, ($s0)
  lwc1  $f8, 0x94($sp)
  b     .L7F03411C
   swc1  $f8, 8($s0)
.L7F0340F4:
  add.s $f20, $f20, $f30
.L7F0340F8:
  addiu $s1, $s1, 1
  c.le.s $f28, $f20
  nop   
  bc1f  .L7F034110
   nop   
  sub.s $f20, $f20, $f28
.L7F034110:
  bne   $s1, $s4, .L7F03401C
   nop   
  move  $v0, $zero
.L7F03411C:
  lw    $ra, 0x7c($sp)
  ldc1  $f20, 0x30($sp)
  ldc1  $f22, 0x38($sp)
  ldc1  $f24, 0x40($sp)
  ldc1  $f26, 0x48($sp)
  ldc1  $f28, 0x50($sp)
  ldc1  $f30, 0x58($sp)
  lw    $s0, 0x60($sp)
  lw    $s1, 0x64($sp)
  lw    $s2, 0x68($sp)
  lw    $s3, 0x6c($sp)
  lw    $s4, 0x70($sp)
  lw    $s5, 0x74($sp)
  lw    $s6, 0x78($sp)
  jr    $ra
   addiu $sp, $sp, 0x98
");

asm(R"
glabel actionblock_guard_constructor_BDBE
  addiu $sp, $sp, -0x40
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x40($sp)
  sw    $a1, 0x44($sp)
  sw    $a2, 0x48($sp)
  jal   get_next_available_guardID
   sw    $a3, 0x4c($sp)
  slti  $at, $v0, 3
  bnez  $at, .L7F034244
   lw    $v1, 0x48($sp)
  lw    $t6, 0x44($sp)
  bgezl $t6, .L7F0341A4
   lwc1  $f4, ($v1)
  jal   select_psuedorandom_heads
   lw    $a0, 0x40($sp)
  lw    $v1, 0x48($sp)
  sw    $v0, 0x44($sp)
  lwc1  $f4, ($v1)
.L7F0341A4:
  lw    $a3, 0x58($sp)
  lw    $t7, 0x4c($sp)
  swc1  $f4, 0x30($sp)
  lwc1  $f6, 4($v1)
  andi  $t8, $a3, 0x10
  sltu  $a3, $zero, $t8
  swc1  $f6, 0x34($sp)
  lwc1  $f8, 8($v1)
  addiu $a0, $sp, 0x30
  addiu $a1, $sp, 0x28
  lw    $a2, 0x50($sp)
  sw    $t7, 0x28($sp)
  jal   sub_GAME_7F033F48
   swc1  $f8, 0x38($sp)
  beqz  $v0, .L7F034244
   lw    $a0, 0x40($sp)
  lw    $a1, 0x44($sp)
  jal   retrieve_header_for_body_and_head
   lw    $a2, 0x58($sp)
  beqz  $v0, .L7F034244
   move  $a0, $v0
  lw    $t0, 0x54($sp)
  addiu $a1, $sp, 0x30
  lw    $a2, 0x50($sp)
  lw    $a3, 0x28($sp)
  jal   replace_GUARDdata_with_actual_values
   sw    $t0, 0x10($sp)
  beqz  $v0, .L7F034244
   move  $a0, $v0
  jal   sub_GAME_7F03A4F0
   sw    $v0, 0x3c($sp)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0x3c($sp)
  lw    $v0, 0x3c($sp)
  lw    $t1, 0x44($sp)
  lw    $v1, 4($v0)
  sb    $t1, 6($v1)
  lw    $t2, 0x40($sp)
  b     .L7F034248
   sb    $t2, 0xf($v1)
.L7F034244:
  move  $v0, $zero
.L7F034248:
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

asm(R"
glabel guard_constructor_BD
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  jal   sub_GAME_7F032F94
   move  $a1, $a3
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F0342A0
   sll   $t8, $v0, 4
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F0342C0
   addu  $a2, $t6, $t7
.L7F0342A0:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $a2, $t8, $t9
  addu  $a2, $a2, $at
.L7F0342C0:
  lwc1  $f12, 0x18($a2)
  lwc1  $f14, 0x20($a2)
  jal   convert_angle_using_inverse
   sw    $a2, 0x2c($sp)
  lw    $a2, 0x2c($sp)
  lw    $t0, 0x40($sp)
  lw    $t1, 0x44($sp)
  lw    $a3, 0x28($a2)
  swc1  $f0, 0x10($sp)
  lw    $a0, 0x34($sp)
  lw    $a1, 0x38($sp)
  sw    $t0, 0x14($sp)
  jal   actionblock_guard_constructor_BDBE
   sw    $t1, 0x18($sp)
  lw    $ra, 0x24($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel guard_constructor_BE
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  jal   get_handle_for_guard_id
   move  $a1, $a3
  lw    $t6, 0x14($v0)
  andi  $t7, $t6, 8
  bnezl $t7, .L7F034378
   move  $v0, $zero
  lw    $a0, 0x1c($v0)
  jal   getsubroty
   sw    $v0, 0x2c($sp)
  lw    $v1, 0x2c($sp)
  lw    $t8, 0x40($sp)
  lw    $t9, 0x44($sp)
  lw    $v0, 0x18($v1)
  lw    $a0, 0x34($sp)
  lw    $a1, 0x38($sp)
  lw    $a3, 0x14($v0)
  swc1  $f0, 0x10($sp)
  sw    $t8, 0x14($sp)
  sw    $t9, 0x18($sp)
  jal   actionblock_guard_constructor_BDBE
   addiu $a2, $v0, 8
  b     .L7F03437C
   lw    $ra, 0x24($sp)
  move  $v0, $zero
.L7F034378:
  lw    $ra, 0x24($sp)
.L7F03437C:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel check_if_actorID_is_at_preset
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_handle_for_guard_id
   sw    $a2, 0x28($sp)
  lw    $a0, 0x20($sp)
  lw    $a1, 0x28($sp)
  jal   sub_GAME_7F032F94
   sw    $v0, 0x18($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F0343DC
   lw    $a2, 0x18($sp)
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F034400
   addu  $v1, $t6, $t7
.L7F0343DC:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  sll   $t8, $v0, 4
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t8, $t9
  addu  $v1, $v1, $at
.L7F034400:
  lw    $v0, 0x28($v1)
  lw    $ra, 0x14($sp)
  beql  $v0, $zero, .L7F034444
   move  $v0, $zero
  beql  $a2, $zero, .L7F034444
   move  $v0, $zero
  lw    $v1, 0x18($a2)
  beql  $v1, $zero, .L7F034444
   move  $v0, $zero
  lw    $t0, 0x14($v1)
  lbu   $t2, 3($v0)
  lbu   $t1, 3($t0)
  bnel  $t1, $t2, .L7F034444
   move  $v0, $zero
  b     .L7F034444
   li    $v0, 1
  move  $v0, $zero
.L7F034444:
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel check_if_actor_is_at_preset
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   get_curplayer_positiondata
   sw    $a1, 0x24($sp)
  sw    $v0, 0x1c($sp)
  lw    $a0, 0x20($sp)
  jal   sub_GAME_7F032F94
   lw    $a1, 0x24($sp)
  slti  $at, $v0, 0x2710
  beqz  $at, .L7F0344A0
   lw    $ra, 0x14($sp)
  sll   $t6, $v0, 2
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  lui   $t7, %hi(ptr_0xxxpresets) 
  lw    $t7, %lo(ptr_0xxxpresets)($t7)
  subu  $t6, $t6, $v0
  sll   $t6, $t6, 2
  b     .L7F0344C4
   addu  $v1, $t6, $t7
.L7F0344A0:
  lui   $t9, %hi(ptr_2xxxpresets) 
  lw    $t9, %lo(ptr_2xxxpresets)($t9)
  sll   $t8, $v0, 4
  addu  $t8, $t8, $v0
  sll   $t8, $t8, 2
  lui   $at, (0xFFF59FC0 >> 16) # lui $at, 0xfff5
  ori   $at, (0xFFF59FC0 & 0xFFFF) # ori $at, $at, 0x9fc0
  addu  $v1, $t8, $t9
  addu  $v1, $v1, $at
.L7F0344C4:
  lw    $v0, 0x28($v1)
  lw    $t0, 0x1c($sp)
  beql  $v0, $zero, .L7F0344F4
   move  $v0, $zero
  lw    $t1, 0x14($t0)
  lbu   $t3, 3($v0)
  lbu   $t2, 3($t1)
  bnel  $t2, $t3, .L7F0344F4
   move  $v0, $zero
  b     .L7F0344F4
   li    $v0, 1
  move  $v0, $zero
.L7F0344F4:
  jr    $ra
   addiu $sp, $sp, 0x20
");

int removed_animation_routine_27(int a0) { return 0; }

int removed_animation_routine_2B(int a0) { return 0; }

asm(R"
glabel sub_GAME_7F034514
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F032F94
   sw    $a0, 0x18($sp)
  sw    $v0, 0x1c($sp)
  jal   true_if_actor_dying_fading_limping_shot
   lw    $a0, 0x18($sp)
  beql  $v0, $zero, .L7F03456C
   move  $v0, $zero
  jal   scan_position_data_table_for_normal_object_at_preset
   lw    $a0, 0x1c($sp)
  beqz  $v0, .L7F034568
   move  $a0, $v0
  jal   check_if_object_has_not_been_destroyed
   nop   
  beql  $v0, $zero, .L7F03456C
   move  $v0, $zero
  jal   sub_GAME_7F024150
   lw    $a0, 0x18($sp)
  b     .L7F03456C
   li    $v0, 1
.L7F034568:
  move  $v0, $zero
.L7F03456C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel actor_draws_throws_grenade_at_player_if_possible
  addiu $sp, $sp, -0x28
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  jal   get_random_value
   move  $s0, $a0
  li    $at, 255
  divu  $zero, $v0, $at
  lbu   $t7, 0x10($s0)
  mfhi  $t6
  sltu  $at, $t6, $t7
  bnez  $at, .L7F0345B4
   nop   
  b     .L7F0346E8
   move  $v0, $zero
.L7F0345B4:
  jal   sub_GAME_7F032DE4
   move  $a0, $s0
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  nop   
  c.lt.s $f0, $f4
  nop   
  bc1f  .L7F0345E0
   nop   
  b     .L7F0346E8
   move  $v0, $zero
.L7F0345E0:
  jal   true_if_actor_dying_fading_limping_shot
   move  $a0, $s0
  beqz  $v0, .L7F0346E4
   move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   li    $a1, 1
  sw    $v0, 0x24($sp)
  move  $a0, $s0
  jal   something_with_weaponpos_of_guarddata_hand
   move  $a1, $zero
  lw    $a1, 0x24($sp)
  beqz  $v0, .L7F034644
   sw    $v0, 0x20($sp)
  lw    $v1, 4($v0)
  li    $at, 26
  move  $a0, $s0
  lb    $t8, 0x80($v1)
  move  $a2, $zero
  move  $a3, $zero
  bne   $t8, $at, .L7F034644
   nop   
  jal   throw_weapon_in_guard_hand
   move  $a1, $v0
  b     .L7F0346E8
   li    $v0, 1
.L7F034644:
  beqz  $a1, .L7F034678
   nop   
  lw    $v1, 4($a1)
  li    $at, 26
  move  $a0, $s0
  lb    $t9, 0x80($v1)
  li    $a2, 1
  bne   $t9, $at, .L7F034678
   nop   
  jal   throw_weapon_in_guard_hand
   move  $a3, $zero
  b     .L7F0346E8
   li    $v0, 1
.L7F034678:
  beqz  $a1, .L7F034688
   move  $a0, $s0
  bnezl $v0, .L7F0346E8
   move  $v0, $zero
.L7F034688:
  beqz  $v0, .L7F034694
   move  $a3, $zero
  lui   $a3, 0x1000
.L7F034694:
  li    $a1, 196
  jal   actor_draws_weapon_with_model
   li    $a2, 26
  beqz  $v0, .L7F0346E4
   move  $a1, $v0
  lw    $v1, 4($v0)
  move  $a0, $s0
  li    $a2, 1
  lw    $t0, 0x64($v1)
  ori   $t1, $t0, 0x800
  sw    $t1, 0x64($v1)
  lw    $t2, 0x20($sp)
  bnez  $t2, .L7F0346D4
   nop   
  b     .L7F0346D4
   move  $a2, $zero
.L7F0346D4:
  jal   throw_weapon_in_guard_hand
   li    $a3, 1
  b     .L7F0346E8
   li    $v0, 1
.L7F0346E4:
  move  $v0, $zero
.L7F0346E8:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel actor_drops_itemtype_setting_timer
  addiu $sp, $sp, -0x20
  sw    $a0, 0x20($sp)
  sw    $ra, 0x14($sp)
  andi  $t6, $a2, 0xff
  move  $a0, $a1
  sw    $a2, 0x28($sp)
  jal   create_new_item_instance_of_model
   move  $a1, $t6
  beql  $v0, $zero, .L7F034788
   move  $v0, $zero
  lw    $t7, 0x10($v0)
  beql  $t7, $zero, .L7F034788
   move  $v0, $zero
  lw    $a0, 0x14($v0)
  lw    $a1, 0x14($a0)
  jal   set_obj_instance_controller_scale
   sw    $v0, 0x1c($sp)
  lw    $v1, 0x1c($sp)
  lw    $t8, 0x20($sp)
  lw    $a0, 0x10($v1)
  jal   sub_GAME_7F03A5A4
   lw    $a1, 0x18($t8)
  lw    $v1, 0x1c($sp)
  li    $t9, 180
  li    $a1, 1
  sh    $t9, 0x82($v1)
  jal   sub_GAME_7F04BFD0
   lw    $a0, 0x10($v1)
  lw    $t0, 0x20($sp)
  li    $v0, 1
  lhu   $t1, 0x12($t0)
  ori   $t2, $t1, 1
  b     .L7F034788
   sh    $t2, 0x12($t0)
  move  $v0, $zero
.L7F034788:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
