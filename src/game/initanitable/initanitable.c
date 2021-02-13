#include <message.h>
#include <stddef.h>
#include <thread.h>

char dword_CODE_bss_80069170[0x2D0];
OSMesgQueue animMsgQ;
char dword_CODE_bss_80069458[0xC0];
OSMesg animMesg[8];
int *ptr_animation_table;

void *D_80029D60[] = {NULL, &dword_CODE_bss_80069170, &dword_CODE_bss_80069170};

int animation_table_ptrs1[] = {
    0x1C,   0x144,  0x214,  0x318,  0x3C4,  0x610,  0x814,  0x990,  0xB84,
    0xDB4,  0x1028, 0x1334, 0x1578, 0x17B4, 0x186C, 0x1984, 0x1A6C, 0x1B54,
    0x1C9C, 0x1E40, 0x1F84, 0x2134, 0x282C, 0x299C, 0x2E64, 0x2F94, 0x30B8,
    0x31DC, 0x32C8, 0x33AC, 0x34D4, 0x35C8, 0x36D8, 0x384C, 0x39C0, 0x3AF0,
    0x3C10, 0x3D04, 0x3D9C, 0x3FA0, 0x4018, 0x4070, 0x40D4, 0x4144, 0x4298,
    0x42C8, 0x4384, 0x4504, 0x4574, 0x45CC, 1,      1,      0x47BC, 0x4A40,
    0x4CE0, 0x4F14, 0x51C4, 0x540C, 0x54A0, 0x5554, 0x5684, 0x5744, 0x5964,
    0x5D10, 0x5EF0, 0x60D4, 0x6254, 0x637C, 0x6484, 0x6554, 0x6644, 0x6738,
    0x6808, 0x694C, 0x6A18, 0x6C18, 0x6D50, 0x6F08, 0x700C, 0x71D0, 0x7304,
    0x7430, 0x74A4, 0x7514, 0x7588, 0x75EC, 0x7650, 0x76B8, 0x7714, 0x777C,
    0x77D4, 1,      1,      1,      1,      1,      1,      0x78C8, 0x7AA8,
    0x7C4C, 0x7D04, 0x7DD8, 0x7F0C, 0x7FB4, 0x8080, 0x8164, 0x8194, 0x8204,
    0x8274, 0x82E0, 0x8340, 0x83A4, 0x8404, 0x845C, 0x84C4, 0x8520, 0x8698,
    0x8800, 0x8978, 0x8AAC, 0x8BF0, 0x8D28, 0x8E1C, 0x8F2C, 0x9084, 0x9194,
    0x92EC, 0x9444, 0x95FC, 0x97BC, 0x98C8, 0x9A2C, 0x9B48, 0x9C4C, 0x9D5C,
    0x9E44, 0x9F48, 0xA094, 0xA1B8, 0xA2F8, 0xA424, 0xA538, 0xA650, 1,
    1,      1,      1,      0xA6B0, 0xA704, 0xA8BC, 0xA94C, 0xA9DC, 0xACAC,
    0xB174, 0xB2AC, 0xB528, 0xB6B0, 0xB7C8, 0xB854, 0xB9A8, 0xBC40, 0xBF80,
    0xC224, 0xC410, 0xC544, 0xC838, 0xCB78, 0xCE6C, 0xD0A8, 1,      0xD348,
    0xD54C, 0xD5E4, 0xD668, 0xD6F8, 0xD728, 0xD89C, 0xDBE4, 0xDD20, 0xE05C,
    0xE08C, 0xE0BC, 0xE18C, 0};

int animation_table_ptrs2[] = {0xE470, 0xE5F4, 0xE7C0, 0};

asm(R"
glabel expand_ani_table_entries
  lw    $v1, ($a0)
  lui   $a2, %hi(ptr_animation_table)
  move  $v0, $a0
  beqz  $v1, .L7F000A6C
   addiu $a2, %lo(ptr_animation_table) # addiu $a2, $a2, -0x6ac8
  lw    $v1, ($a0)
  li    $a1, 1
.L7F000A1C:
  beql  $a1, $v1, .L7F000A58
   lw    $v1, 4($v0)
  lw    $t6, ($a2)
  addu  $t7, $v1, $t6
  sw    $t7, ($v0)
  lw    $t9, ($a2)
  lw    $t8, 8($t7)
  addu  $t0, $t8, $t9
  sw    $t0, 8($t7)
  lw    $v1, ($v0)
  lw    $t2, ($a2)
  lw    $t1, 0x10($v1)
  addu  $t3, $t1, $t2
  sw    $t3, 0x10($v1)
  lw    $v1, 4($v0)
.L7F000A58:
  addiu $v0, $v0, 4
  bnez  $v1, .L7F000A1C
   nop   
  move  $v0, $a0
  lw    $v1, ($a0)
.L7F000A6C:
  beqz  $v1, .L7F000AA4
   li    $a1, 1
  lui   $a0, %hi(_animation_table) # $a0, 0x12
  addiu $a0, %lo(_animation_table) # addiu $a0, $a0, 0x4ac0
  lw    $v1, ($v0)
.L7F000A80:
  beql  $a1, $v1, .L7F000A98
   lw    $v1, 4($v0)
  lw    $t4, ($v1)
  addu  $t5, $t4, $a0
  sw    $t5, ($v1)
  lw    $v1, 4($v0)
.L7F000A98:
  addiu $v0, $v0, 4
  bnez  $v1, .L7F000A80
   nop   
.L7F000AA4:
  jr    $ra
   nop   
");

asm(R"
glabel alloc_load_expand_ani_table
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lui   $a0, %hi(animMsgQ)
  lui   $a1, %hi(animMesg)
  addiu $a1, %lo(animMesg) # addiu $a1, $a1, -0x6ae8
  addiu $a0, %lo(animMsgQ) # addiu $a0, $a0, -0x6bc0
  jal   osCreateMesgQueue
   li    $a2, 8
  lui   $a0, %hi(D_80029D60)
  lui   $a1, %hi(animMsgQ)
  lui   $a2, %hi(dword_CODE_bss_80069458)
  addiu $a2, %lo(dword_CODE_bss_80069458) # addiu $a2, $a2, -0x6ba8
  addiu $a1, %lo(animMsgQ) # addiu $a1, $a1, -0x6bc0
  jal   sub_GAME_7F0009E0
   addiu $a0, %lo(D_80029D60) # addiu $a0, $a0, -0x62a0
  lui   $t6, %hi(0x0000E7E0) # $t6, 1
  lui   $t7, 0
  addiu $t7, $t7, 0
  addiu $t6, %lo(0x0000E7E0) # addiu $t6, $t6, -0x1820
  subu  $a2, $t6, $t7
  move  $a0, $a2
  sw    $a2, 0x18($sp)
  jal   mempAllocBytesInBank
   li    $a1, 6
  lui   $v1, %hi(ptr_animation_table)
  addiu $v1, %lo(ptr_animation_table) # addiu $v1, $v1, -0x6ac8
  lui   $a1, %hi(_animation_data) # $a1, 0x29
  sw    $v0, ($v1)
  lw    $a2, 0x18($sp)
  addiu $a1, %lo(_animation_data) # addiu $a1, $a1, -0x1680
  jal   romCopy
   move  $a0, $v0
  lui   $a0, %hi(animation_table_ptrs1)
  jal   expand_ani_table_entries
   addiu $a0, %lo(animation_table_ptrs1) # addiu $a0, $a0, -0x6294
  lui   $a0, %hi(animation_table_ptrs2)
  jal   expand_ani_table_entries
   addiu $a0, %lo(animation_table_ptrs2) # addiu $a0, $a0, -0x5fb4
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
