#include "bondconstants.h"
#include <stddef.h>
#include <types.h>

int ptr_text;
int table_text_pointers;
char dword_CODE_bss_8008C648[0x90];
int dword_CODE_bss_8008C6D8;
int dword_CODE_bss_8008C6DC;
int dword_CODE_bss_8008C6E0;
int dword_CODE_bss_8008C6E4;
int dword_CODE_bss_8008C6E8;
int dword_CODE_bss_8008C6EC;
int dword_CODE_bss_8008C6F0;
int ptr_j_char_data_buf;
int ptr_j_char_registry;

#ifdef VERSION_JP
int j_text_trigger = 1;
#else
int j_text_trigger = 0;
#endif

void *LnameX_lookuptable[] = {
    NULL,          NULL,          /* Null (unused) */
    "LameE",       "LameJ",       /* Library (multi) */
    "LarchE",      "LarchJ",      /* Archives */
    "LarkE",       "LarkJ",       /* Facility */
    "LashE",       "LashJ",       /* Stack (multi) */
    "LaztE",       "LaztJ",       /* Aztec */
    "LcatE",       "LcatJ",       /* Citadel (multi) */
    "LcaveE",      "LcaveJ",      /* Caverns */
    "LarecE",      "LarecJ",      /* Control */
    "LcradE",      "LcradJ",      /* Cradle */
    "LcrypE",      "LcrypJ",      /* Egypt */
    "LdamE",       "LdamJ",       /* Dam */
    "LdepoE",      "LdepoJ",      /* Depot */
    "LdestE",      "LdestJ",      /* Frigate */
    "LdishE",      "LdishJ",      /* Temple (multi) */
    "LearE",       "LearJ",       /* Ear (unused) */
    "LeldE",       "LeldJ",       /* Eld (unused) */
    "LimpE",       "LimpJ",       /* Basement (multi) */
    "LjunE",       "LjunJ",       /* Jungle */
    "LleeE",       "LleeJ",       /* Lee (unused) */
    "LlenE",       "LlenJ",       /* Cuba */
    "LlipE",       "LlipJ",       /* Lip (unused) */
    "LlueE",       "LlueJ",       /* Lue (unused) */
    "LoatE",       "LoatJ",       /* Cave (multi) */
    "LpamE",       "LpamJ",       /* Pam (unused) */
    "LpeteE",      "LpeteJ",      /* Streets */
    "LrefE",       "LrefJ",       /* Complex (multi) */
    "LritE",       "LritJ",       /* Rit (unused) */
    "LrunE",       "LrunJ",       /* Runway */
    "LsevbE",      "LsevbJ",      /* Bunker 2 */
    "LsevE",       "LsevJ",       /* Bunker 1 */
    "LsevxE",      "LsevxJ",      /* Surface 1 */
    "LsevxbE",     "LsevxbJ",     /* Surface 2 */
    "LshoE",       "LshoJ",       /* Sho (unused) */
    "LsiloE",      "LsiloJ",      /* Silo */
    "LstatE",      "LstatJ",      /* Statue */
    "LtraE",       "LtraJ",       /* Train */
    "LwaxE",       "LwaxJ",       /* Wax (unused) */
    "LgunE",       "LgunJ",       /* Guns */
    "LtitleE",     "LtitleJ",     /* Stage and menu titles */
    "LmpmenuE",    "LmpmenuJ",    /* Multi menus */
    "LpropobjE",   "LpropobjJ",   /* In-game pickups */
    "LmpweaponsE", "LmpweaponsJ", /* Multi weapon select */
    "LoptionsE",   "LoptionsJ",   /* Solo in-game menus */
    "LmiscE",      "LmiscJ",      /* Cheat options */
};

LEVELID get_textbank_number_for_stagenum(LEVELID level) {
  LEVELID return_id;

  switch (level) {
  case LEVELID_DAM:
    return_id = LDAM;
    break;
  case LEVELID_FACILITY:
    return_id = LARK;
    break;
  case LEVELID_RUNWAY:
    return_id = LRUN;
    break;
  case LEVELID_SURFACE:
    return_id = LSEVX;
    break;
  case LEVELID_BUNKER1:
    return_id = LSEV;
    break;
  case LEVELID_SILO:
    return_id = LSILO;
    break;
  case LEVELID_FRIGATE:
    return_id = LDEST;
    break;
  case LEVELID_SURFACE2:
    return_id = LSEVXB;
    break;
  case LEVELID_BUNKER2:
    return_id = LSEVB;
    break;
  case LEVELID_STATUE:
    return_id = LSTAT;
    break;
  case LEVELID_ARCHIVES:
    return_id = LARCH;
    break;
  case LEVELID_STREETS:
    return_id = LPETE;
    break;
  case LEVELID_DEPOT:
    return_id = LDEPO;
    break;
  case LEVELID_TRAIN:
    return_id = LTRA;
    break;
  case LEVELID_JUNGLE:
    return_id = LJUN;
    break;
  case LEVELID_CONTROL:
    return_id = LAREC;
    break;
  case LEVELID_CAVERNS:
    return_id = LCAVE;
    break;
  case LEVELID_CRADLE:
    return_id = LCRAD;
    break;
  case LEVELID_AZTEC:
    return_id = LAZT;
    break;
  case LEVELID_EGYPT:
    return_id = LCRYP;
    break;
  case LEVELID_TEMPLE:
    return_id = LDISH;
    break;
  case LEVELID_COMPLEX:
    return_id = LREF;
    break;
  case LEVELID_LIBRARY:
    return_id = LAME;
    break;
  case LEVELID_BASEMENT:
    return_id = LIMP;
    break;
  case LEVELID_STACK:
    return_id = LASH;
    break;
  case LEVELID_CAVES:
    return_id = LOAT;
    break;
  case LEVELID_CUBA:
    return_id = LLEN;
    break;
  default: {
    /* infinite loop on invalid text bank */
    for (;;) {
    };
  }
  }

  return return_id;
}

asm(R"
glabel init_LnameX
  addiu $sp, $sp, -0x28
  sw    $s2, 0x20($sp)
  lui   $s2, %hi(j_text_trigger)
  addiu $s2, %lo(j_text_trigger) # addiu $s2, $s2, -0x7b30
  lw    $t0, ($s2)
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  beqz  $t0, .L7F0C17F0
   sw    $s0, 0x18($sp)
  li    $a0, 11904
  jal   mempAllocBytesInBank
   li    $a1, 6
  lui   $at, %hi(ptr_j_char_data_buf)
  sw    $v0, %lo(ptr_j_char_data_buf)($at)
  li    $a0, 256
  jal   mempAllocBytesInBank
   li    $a1, 6
  lui   $a0, %hi(ptr_j_char_registry)
  addiu $a0, %lo(ptr_j_char_registry) # addiu $a0, $a0, -0x3908
  sw    $v0, ($a0)
  move  $v1, $zero
  li    $a1, 248
.L7F0C1744:
  lw    $t6, ($a0)
  addu  $v0, $t6, $v1
  lbu   $t7, ($v0)
  andi  $t8, $t7, 0xff3f
  sb    $t8, ($v0)
  lw    $t9, ($a0)
  addu  $v0, $t9, $v1
  lhu   $t2, ($v0)
  ori   $t3, $t2, 0x3fff
  sh    $t3, ($v0)
  lw    $t4, ($a0)
  addu  $v0, $t4, $v1
  lbu   $t5, 2($v0)
  andi  $t6, $t5, 0xff3f
  sb    $t6, 2($v0)
  lw    $t7, ($a0)
  addu  $v0, $t7, $v1
  lhu   $t9, 2($v0)
  ori   $t1, $t9, 0x3fff
  sh    $t1, 2($v0)
  lw    $t2, ($a0)
  addu  $v0, $t2, $v1
  lbu   $t3, 4($v0)
  andi  $t4, $t3, 0xff3f
  sb    $t4, 4($v0)
  lw    $t5, ($a0)
  addu  $v0, $t5, $v1
  lhu   $t7, 4($v0)
  ori   $t8, $t7, 0x3fff
  sh    $t8, 4($v0)
  lw    $t9, ($a0)
  addu  $v0, $t9, $v1
  lbu   $t1, 6($v0)
  andi  $t2, $t1, 0xff3f
  sb    $t2, 6($v0)
  lw    $t3, ($a0)
  addu  $v0, $t3, $v1
  lhu   $t5, 6($v0)
  addiu $v1, $v1, 8
  ori   $t6, $t5, 0x3fff
  bne   $v1, $a1, .L7F0C1744
   sh    $t6, 6($v0)
  lw    $t0, ($s2)
.L7F0C17F0:
  lui   $at, %hi(ptr_text)
  lui   $v0, %hi(table_text_pointers)
  lui   $v1, %hi(ptr_j_char_data_buf)
  addiu $v1, %lo(ptr_j_char_data_buf) # addiu $v1, $v1, -0x390c
  addiu $v0, %lo(table_text_pointers) # addiu $v0, $v0, -0x39bc
  sw    $zero, %lo(ptr_text)($at)
.L7F0C1808:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F0C1808
   sw    $zero, -0x10($v0)
  lui   $s0, %hi(LnameX_lookuptable)
  addiu $s0, %lo(LnameX_lookuptable) # addiu $s0, $s0, -0x7b2c
  sll   $t7, $t0, 2
  addu  $t8, $s0, $t7
  lw    $a0, 0x130($t8)
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t9, ($s2)
  lui   $s1, %hi(ptr_text)
  addiu $s1, %lo(ptr_text) # addiu $s1, $s1, -0x39c0
  sll   $t1, $t9, 2
  addu  $t2, $s0, $t1
  sw    $v0, 0x98($s1)
  lw    $a0, 0x138($t2)
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t3, ($s2)
  sw    $v0, 0x9c($s1)
  li    $a1, 1
  sll   $t4, $t3, 2
  addu  $t5, $s0, $t4
  lw    $a0, 0x140($t5)
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t6, ($s2)
  sw    $v0, 0xa0($s1)
  li    $a1, 1
  sll   $t7, $t6, 2
  addu  $t8, $s0, $t7
  lw    $a0, 0x148($t8)
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t9, ($s2)
  sw    $v0, 0xa4($s1)
  li    $a1, 1
  sll   $t1, $t9, 2
  addu  $t2, $s0, $t1
  lw    $a0, 0x150($t2)
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t3, ($s2)
  sw    $v0, 0xa8($s1)
  li    $a1, 1
  sll   $t4, $t3, 2
  addu  $t5, $s0, $t4
  lw    $a0, 0x158($t5)
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $t6, ($s2)
  sw    $v0, 0xac($s1)
  li    $a1, 1
  sll   $t7, $t6, 2
  addu  $t8, $s0, $t7
  lw    $a0, 0x160($t8)
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 6
  lw    $ra, 0x24($sp)
  sw    $v0, 0xb0($s1)
  lw    $s1, 0x1c($sp)
  lw    $s0, 0x18($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel something_with_LnameJ
  lui   $t6, %hi(j_text_trigger) 
  lw    $t6, %lo(j_text_trigger)($t6)
  move  $v1, $zero
  li    $a2, 248
  beqz  $t6, .L7F0C1A28
   lui   $a1, %hi(ptr_j_char_registry)
  addiu $a1, %lo(ptr_j_char_registry) # addiu $a1, $a1, -0x3908
  lw    $t7, ($a1)
.L7F0C1960:
  addu  $v0, $t7, $v1
  lhu   $a0, ($v0)
  srl   $t8, $a0, 0xe
  beql  $t8, $zero, .L7F0C1998
   lhu   $a0, 2($v0)
  lbu   $t2, ($v0)
  addiu $t9, $t8, -1
  sll   $t1, $t9, 6
  andi  $t3, $t2, 0xff3f
  or    $t4, $t1, $t3
  sb    $t4, ($v0)
  lw    $t5, ($a1)
  addu  $v0, $t5, $v1
  lhu   $a0, 2($v0)
.L7F0C1998:
  srl   $t6, $a0, 0xe
  beql  $t6, $zero, .L7F0C19C8
   lhu   $a0, 4($v0)
  lbu   $t0, 2($v0)
  addiu $t7, $t6, -1
  sll   $t9, $t7, 6
  andi  $t2, $t0, 0xff3f
  or    $t1, $t9, $t2
  sb    $t1, 2($v0)
  lw    $t3, ($a1)
  addu  $v0, $t3, $v1
  lhu   $a0, 4($v0)
.L7F0C19C8:
  srl   $t4, $a0, 0xe
  beql  $t4, $zero, .L7F0C19F8
   lhu   $a0, 6($v0)
  lbu   $t8, 4($v0)
  addiu $t5, $t4, -1
  sll   $t7, $t5, 6
  andi  $t0, $t8, 0xff3f
  or    $t9, $t7, $t0
  sb    $t9, 4($v0)
  lw    $t2, ($a1)
  addu  $v0, $t2, $v1
  lhu   $a0, 6($v0)
.L7F0C19F8:
  addiu $v1, $v1, 8
  srl   $t1, $a0, 0xe
  beqz  $t1, .L7F0C1A20
   nop   
  lbu   $t6, 6($v0)
  addiu $t3, $t1, -1
  sll   $t5, $t3, 6
  andi  $t8, $t6, 0xff3f
  or    $t7, $t5, $t8
  sb    $t7, 6($v0)
.L7F0C1A20:
  bnel  $v1, $a2, .L7F0C1960
   lw    $t7, ($a1)
.L7F0C1A28:
  jr    $ra
   nop   
");

asm(R"
glabel something_with_LnameX
  addiu $sp, $sp, -0x38
  sw    $s0, 0x18($sp)
  andi  $t6, $a0, 0x2000
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  li    $t2, -1
  li    $t3, -1
  beqz  $t6, .L7F0C1A58
   move  $t0, $zero
  li    $t0, 1
.L7F0C1A58:
  lui   $t4, %hi(ptr_j_char_registry) 
  lw    $t4, %lo(ptr_j_char_registry)($t4)
  move  $a1, $zero
  move  $a3, $zero
  li    $t1, 124
  move  $a0, $t4
.L7F0C1A70:
  bnez  $t0, .L7F0C1A8C
   nop   
  lhu   $t8, ($a0)
  sra   $t7, $s0, 1
  andi  $t9, $t8, 0x3fff
  beql  $t7, $t9, .L7F0C1B04
   slti  $at, $a1, 0x7c
.L7F0C1A8C:
  beqz  $t0, .L7F0C1ABC
   lhu   $v1, ($a0)
  addiu $t6, $a1, 1
  slti  $at, $t6, 0x7c
  beqz  $at, .L7F0C1ABC
   sra   $v0, $s0, 1
  andi  $t8, $v1, 0x3fff
  bnel  $v0, $t8, .L7F0C1AC0
   srl   $v0, $v1, 0xe
  lhu   $t7, 2($a0)
  andi  $t9, $t7, 0x3fff
  beq   $v0, $t9, .L7F0C1B00
.L7F0C1ABC:
   srl   $v0, $v1, 0xe
.L7F0C1AC0:
  bnez  $v0, .L7F0C1ACC
   addiu $a2, $a1, 1
  move  $t2, $a1
.L7F0C1ACC:
  bnez  $v0, .L7F0C1AF4
   addiu $a3, $a3, 2
  lhu   $t6, 2($a0)
  slti  $at, $a2, 0x7c
  srl   $t8, $t6, 0xe
  bnezl $t8, .L7F0C1AF8
   move  $a1, $a2
  beql  $at, $zero, .L7F0C1AF8
   move  $a1, $a2
  move  $t3, $a1
.L7F0C1AF4:
  move  $a1, $a2
.L7F0C1AF8:
  bne   $a2, $t1, .L7F0C1A70
   addiu $a0, $a0, 2
.L7F0C1B00:
  slti  $at, $a1, 0x7c
.L7F0C1B04:
  beqz  $at, .L7F0C1B8C
   nop   
  bnez  $t0, .L7F0C1B40
   li    $t5, 96
  multu $a1, $t5
  lbu   $t7, ($a0)
  andi  $t9, $t7, 0xff3f
  ori   $t6, $t9, 0x80
  sb    $t6, ($a0)
  lui   $t7, %hi(ptr_j_char_data_buf) 
  lw    $t7, %lo(ptr_j_char_data_buf)($t7)
  mflo  $t8
  addu  $v0, $t8, $t7
  b     .L7F0C1CF8
   lw    $ra, 0x1c($sp)
.L7F0C1B40:
  lbu   $t9, ($a0)
  lui   $t1, %hi(ptr_j_char_registry) 
  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
  andi  $t6, $t9, 0xff3f
  ori   $t8, $t6, 0x80
  sb    $t8, ($a0)
  lw    $t7, ($t1)
  li    $t5, 96
  multu $a1, $t5
  addu  $a0, $t7, $a3
  lbu   $t9, 2($a0)
  andi  $t6, $t9, 0xff3f
  ori   $t8, $t6, 0x80
  sb    $t8, 2($a0)
  lui   $t9, %hi(ptr_j_char_data_buf) 
  lw    $t9, %lo(ptr_j_char_data_buf)($t9)
  mflo  $t7
  b     .L7F0C1CF4
   addu  $v0, $t7, $t9
.L7F0C1B8C:
  bnez  $t0, .L7F0C1C24
   nop   
  bltz  $t2, .L7F0C1C24
   li    $t5, 96
  multu $t2, $t5
  sll   $a3, $t2, 1
  addu  $v1, $t4, $a3
  lbu   $t6, ($v1)
  lui   $t1, %hi(ptr_j_char_registry) 
  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
  andi  $t8, $t6, 0xff3f
  ori   $t7, $t8, 0x80
  sb    $t7, ($v1)
  lw    $t9, ($t1)
  mflo  $t0
  sra   $v0, $s0, 1
  addu  $v1, $t9, $a3
  multu $v0, $t5
  lhu   $t7, ($v1)
  andi  $t8, $v0, 0x3fff
  li    $a2, 96
  andi  $t9, $t7, 0xc000
  or    $t6, $t8, $t9
  sh    $t6, ($v1)
  lui   $t7, %hi(ptr_j_char_data_buf) 
  lw    $t7, %lo(ptr_j_char_data_buf)($t7)
  lui   $t9, %hi(_jfontcharSegmentStart) # $t9, 0x11
  addiu $t9, %lo(_jfontcharSegmentStart) # addiu $t9, $t9, 0x7940
  mflo  $t8
  addu  $a1, $t8, $t9
  sw    $t0, 0x24($sp)
  jal   romCopy
   addu  $a0, $t0, $t7
  lui   $t6, %hi(ptr_j_char_data_buf) 
  lw    $t0, 0x24($sp)
  lw    $t6, %lo(ptr_j_char_data_buf)($t6)
  b     .L7F0C1CF4
   addu  $v0, $t0, $t6
.L7F0C1C24:
  beqz  $t0, .L7F0C1CF0
   lui   $v0, %hi(ptr_j_char_data_buf)
  bltz  $t3, .L7F0C1CF0
   sll   $v1, $t3, 1
  addu  $v0, $t4, $v1
  lbu   $t7, ($v0)
  lui   $t1, %hi(ptr_j_char_registry) 
  addiu $t1, %lo(ptr_j_char_registry) # addiu $t1, $t1, -0x3908
  andi  $t8, $t7, 0xff3f
  ori   $t9, $t8, 0x80
  sb    $t9, ($v0)
  lw    $t6, ($t1)
  li    $t5, 96
  multu $t3, $t5
  addu  $v0, $t6, $v1
  lbu   $t7, 2($v0)
  li    $a2, 128
  andi  $t8, $t7, 0xff3f
  ori   $t9, $t8, 0x80
  sb    $t9, 2($v0)
  lw    $t6, ($t1)
  sra   $t7, $s0, 1
  andi  $a3, $t7, 0x3fff
  addu  $v0, $t6, $v1
  lhu   $t9, ($v0)
  mflo  $t0
  andi  $t6, $t9, 0xc000
  or    $t7, $a3, $t6
  sh    $t7, ($v0)
  lw    $t8, ($t1)
  addu  $v0, $t8, $v1
  lhu   $t9, 2($v0)
  lui   $t8, %hi(ptr_j_char_data_buf) 
  andi  $t6, $t9, 0xc000
  or    $t7, $a3, $t6
  sh    $t7, 2($v0)
  lw    $t8, %lo(ptr_j_char_data_buf)($t8)
  andi  $t9, $s0, 0x1fff
  sra   $t6, $t9, 1
  addu  $a0, $t0, $t8
  lui   $t8, %hi(_efontchar) # $t8, 0x12
  addiu $t8, %lo(_efontchar) # addiu $t8, $t8, 0x3040
  sll   $t7, $t6, 7
  addu  $a1, $t7, $t8
  jal   romCopy
   sw    $t0, 0x24($sp)
  lui   $t9, %hi(ptr_j_char_data_buf) 
  lw    $t0, 0x24($sp)
  lw    $t9, %lo(ptr_j_char_data_buf)($t9)
  b     .L7F0C1CF4
   addu  $v0, $t0, $t9
.L7F0C1CF0:
  lw    $v0, %lo(ptr_j_char_data_buf)($v0)
.L7F0C1CF4:
  lw    $ra, 0x1c($sp)
.L7F0C1CF8:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel load_mission_text_bank
  lui   $t8, %hi(j_text_trigger) 
  lw    $t8, %lo(j_text_trigger)($t8)
  addiu $sp, $sp, -0x18
  sll   $t7, $a0, 3
  sw    $a0, 0x18($sp)
  sll   $t9, $t8, 2
  addu  $t0, $t7, $t9
  lui   $a0, %hi(LnameX_lookuptable)
  sw    $ra, 0x14($sp)
  addu  $a0, $a0, $t0
  lw    $a0, %lo(LnameX_lookuptable)($a0)
  li    $a1, 1
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  lw    $t1, 0x18($sp)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(ptr_text)
  sll   $t2, $t1, 2
  addu  $at, $at, $t2
  sw    $v0, %lo(ptr_text)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel load_briefing_text_bank
  lui   $t8, %hi(j_text_trigger) 
  lw    $t8, %lo(j_text_trigger)($t8)
  addiu $sp, $sp, -0x18
  sll   $t7, $a0, 3
  sw    $a0, 0x18($sp)
  sll   $t9, $t8, 2
  move  $a3, $a2
  addu  $t0, $t7, $t9
  lui   $a0, %hi(LnameX_lookuptable)
  move  $a2, $a1
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  addu  $a0, $a0, $t0
  lw    $a0, %lo(LnameX_lookuptable)($a0)
  jal   _load_resource_named_to_buffer
   li    $a1, 1
  lw    $t1, 0x18($sp)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(ptr_text)
  sll   $t2, $t1, 2
  addu  $at, $at, $t2
  sw    $v0, %lo(ptr_text)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

void blank_text_bank(int textBank) { (&ptr_text)[textBank] = 0; }

unsigned char *get_textptr_for_textID(int slotID) {
  unsigned int textbank_ptr =
      (&ptr_text)[slotID >>
                  10]; /* get the text file bank ID index the text ptr table */
  unsigned int textslot_offset =
      ((unsigned int *)
           textbank_ptr)[slotID & 0x03FF]; /* load the textbank ptr table then
                                              get the slot's offset */

  /* add the text slot offset to the base ptr to get the ptr to text file's slot
   * (output slot) */
  return textslot_offset ? (unsigned char *)(textslot_offset + textbank_ptr)
                         : NULL;
}
