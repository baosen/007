#include "bondtypes.h"
#include <types.h>

int dword_CODE_bss_80069550;
int dword_CODE_bss_80069554;
int matrix_buffer_rarelogo_0;
int matrix_buffer_gunbarrel_0;
int matrix_buffer_rarelogo_1;
int matrix_buffer_rarelogo_2;
int matrix_buffer_gunbarrel_1;
int matrix_buffer_intro_backdrop;
int matrix_buffer_intro_bond;
int x, y;
int dword_CODE_bss_8006957C;
int dword_CODE_bss_80069580;
int word_CODE_bss_80069584;
int dword_CODE_bss_80069588;
int dword_CODE_bss_8006958C;
int virtualaddress;
int dword_CODE_bss_80069594;

unsigned int D_8002A7D0 = 0;
unsigned int D_8002A7D4 = 0x3000000;
unsigned int D_8002A7D8 = 0;
unsigned int D_8002A7DC = 0;
unsigned int D_8002A7E0 = 0;
unsigned int D_8002A7E4 = 0;

unsigned int D_8002A7E8 = 0xFF;
unsigned int D_8002A7EC = 0xFF;
unsigned int D_8002A7F0 = 0xFF;
unsigned int D_8002A7F4 = 0;
unsigned int D_8002A7F8 = 0;
unsigned int D_8002A7FC = 0;

unsigned int D_8002A800 = 1;
unsigned int D_8002A804 = 3;
unsigned int D_8002A808 = 0;
unsigned int D_8002A80C = 0;
unsigned int D_8002A810 = 0;
unsigned int D_8002A814 = 0;
unsigned int D_8002A818 = 0;
unsigned int D_8002A81C = 0;
unsigned int D_8002A820 = 0;
unsigned int D_8002A824 = 0;
unsigned int D_8002A828 = 0;
unsigned int D_8002A82C = 0;
unsigned int D_8002A830 = 0;
unsigned int D_8002A834 = 0;
unsigned int D_8002A838 = 0;
float D_8002A83C = 1758.2957f;
float D_8002A840 = 220.0f;
float D_8002A844 = 684.28143f;
float D_8002A848 = -0.97f;
unsigned int D_8002A84C = 0;
float D_8002A850 = 0.24f;
unsigned int D_8002A854 = 0;
float D_8002A858 = 1.0f;
unsigned int D_8002A85C = 0x80000000;
struct color D_8002A860 = {0xDC, 0xDC, 0xDC, 0};
struct color D_8002A864 = {0xDC, 0xDC, 0xDC, 0};
struct color D_8002A868 = {0xFF, 0xFF, 0xFF, 0};
struct color D_8002A86C = {0xFF, 0xFF, 0xFF, 0};
struct color D_8002A870 = {0x00, 0x7F, 0x00, 0};
unsigned int D_8002A874 = 0;

unsigned int D_8002A878 = 0;
unsigned int D_8002A87C = 0;
float D_8002A880 = 4883.0f;
unsigned int D_8002A884 = 0;
unsigned int D_8002A888 = 0;
float D_8002A88C = -1.0f;
unsigned int D_8002A890 = 0;
float D_8002A894 = 1.0f;
unsigned int D_8002A898 = 0;

float D_8002A89C = 0.0f;
unsigned int intro_eye_counter = 0;
unsigned int intro_state_blood_animation = 0;
unsigned int D_8002A8A8 = 0;
unsigned int D_8002A8AC = 0;
unsigned int D_8002A8B0 = 0;

asm(R"
glabel something_with_gunbarrel_and_rareware_logo_matrix_manip
  lui   $t6, %hi(D_8002A7D0) 
  lw    $t6, %lo(D_8002A7D0)($t6)
  addiu $sp, $sp, -0x38
  lui   $t8, %hi(matrix_buffer_rarelogo_2) 
  lw    $t8, %lo(matrix_buffer_rarelogo_2)($t8)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  lui   $a1, %hi(x)
  lui   $a2, %hi(y)
  sll   $t7, $t6, 6
  lw    $a2, %lo(y)($a2)
  lw    $a1, %lo(x)($a1)
  lui   $a3, 0xc0a0
  jal   guTranslate
   addu  $a0, $t7, $t8
  lui   $t9, %hi(D_8002A7D0) 
  lw    $t9, %lo(D_8002A7D0)($t9)
  lui   $t1, %hi(matrix_buffer_gunbarrel_1) 
  lw    $t1, %lo(matrix_buffer_gunbarrel_1)($t1)
  lui   $a1, %hi(dword_CODE_bss_8006957C)
  lui   $a2, %hi(dword_CODE_bss_80069580)
  sll   $t0, $t9, 6
  lw    $a2, %lo(dword_CODE_bss_80069580)($a2)
  lw    $a1, %lo(dword_CODE_bss_8006957C)($a1)
  lui   $a3, 0xc0a0
  jal   guTranslate
   addu  $a0, $t0, $t1
  lui   $t3, 0x100
  addiu $t3, $t3, 0
  move  $v0, $s0
  lui   $t2, 0x600
  sw    $t2, ($v0)
  sw    $t3, 4($v0)
  jal   insert_imageDL
   addiu $a0, $s0, 8
  jal   sub_GAME_7F01C1A4
   move  $a0, $v0
  lui   $t4, (0xFCFFFFFF >> 16) # lui $t4, 0xfcff
  lui   $t5, (0xFFFDF6FB >> 16) # lui $t5, 0xfffd
  lui   $t7, (0xE6E6E600 >> 16) # lui $t7, 0xe6e6
  ori   $t5, (0xFFFDF6FB & 0xFFFF) # ori $t5, $t5, 0xf6fb
  ori   $t4, (0xFCFFFFFF & 0xFFFF) # ori $t4, $t4, 0xffff
  ori   $t7, (0xE6E6E600 & 0xFFFF) # ori $t7, $t7, 0xe600
  lui   $t6, 0xfa00
  lui   $t8, 0x600
  sw    $t4, ($v0)
  sw    $t5, 4($v0)
  sw    $t6, 8($v0)
  sw    $t7, 0xc($v0)
  sw    $t8, 0x10($v0)
  lui   $t9, %hi(dword_CODE_bss_80069554) 
  lw    $t9, %lo(dword_CODE_bss_80069554)($t9)
  lui   $at, 0x8000
  addiu $t1, $v0, 0x18
  addu  $t0, $t9, $at
  sw    $t0, 0x14($v0)
  lui   $t2, (0x01020040 >> 16) # lui $t2, 0x102
  ori   $t2, (0x01020040 & 0xFFFF) # ori $t2, $t2, 0x40
  sw    $t1, 0x24($sp)
  sw    $t2, 0x18($v0)
  lui   $t3, %hi(D_8002A7D0) 
  lw    $t3, %lo(D_8002A7D0)($t3)
  lui   $t5, %hi(matrix_buffer_gunbarrel_1) 
  lw    $t5, %lo(matrix_buffer_gunbarrel_1)($t5)
  sll   $t4, $t3, 6
  addiu $s0, $v0, 0x20
  jal   osVirtualToPhysical
   addu  $a0, $t4, $t5
  lw    $t6, 0x24($sp)
  move  $v1, $s0
  lui   $t7, 0x600
  sw    $v0, 4($t6)
  sw    $t7, ($v1)
  lui   $t8, %hi(dword_CODE_bss_80069554) 
  lw    $t8, %lo(dword_CODE_bss_80069554)($t8)
  lui   $at, 0x8000
  addiu $v0, $s0, 8
  addu  $t9, $t8, $at
  sw    $t9, 4($v1)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel insert_sight_backdrop_eye_intro
  lui   $at, %hi(x)
  lwc1  $f4, %lo(x)($at)
  li    $at, 0x44400000 # 768.000000
  mtc1  $at, $f6
  lui   $at, %hi(y)
  lwc1  $f10, %lo(y)($at)
  li    $at, 0x42200000 # 40.000000
  mtc1  $at, $f16
  add.s $f8, $f4, $f6
  lui   $t6, %hi(D_8002A7D0) 
  lw    $t6, %lo(D_8002A7D0)($t6)
  sub.s $f18, $f10, $f16
  addiu $sp, $sp, -0x30
  lui   $t8, %hi(matrix_buffer_rarelogo_2) 
  lw    $t8, %lo(matrix_buffer_rarelogo_2)($t8)
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  mfc1  $a2, $f18
  mfc1  $a1, $f8
  sll   $t7, $t6, 6
  lui   $a3, 0xc0a0
  jal   guTranslate
   addu  $a0, $t7, $t8
  lui   $t9, %hi(D_8002A7D0) 
  lw    $t9, %lo(D_8002A7D0)($t9)
  lui   $t1, %hi(matrix_buffer_gunbarrel_1) 
  lw    $t1, %lo(matrix_buffer_gunbarrel_1)($t1)
  lui   $a1, (0x402CCCCD >> 16) # lui $a1, 0x402c
  lui   $a2, (0x40247AE1 >> 16) # lui $a2, 0x4024
  sll   $t0, $t9, 6
  ori   $a2, (0x40247AE1 & 0xFFFF) # ori $a2, $a2, 0x7ae1
  ori   $a1, (0x402CCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  lui   $a3, 0x3f80
  jal   guScale
   addu  $a0, $t0, $t1
  move  $v0, $s0
  lui   $t2, 0x100
  lui   $a1, 0x600
  addiu $t2, $t2, 0
  addiu $v1, $s0, 8
  lui   $t3, 0x100
  sw    $t2, 4($v0)
  sw    $a1, ($v0)
  addiu $t3, $t3, 0x40
  sw    $t3, 4($v1)
  sw    $a1, ($v1)
  jal   sub_GAME_7F01C1A4
   addiu $a0, $v1, 8
  lui   $t4, (0x01000040 >> 16) # lui $t4, 0x100
  ori   $t4, (0x01000040 & 0xFFFF) # ori $t4, $t4, 0x40
  sw    $v0, 0x24($sp)
  sw    $t4, ($v0)
  lui   $t5, %hi(D_8002A7D0) 
  lw    $t5, %lo(D_8002A7D0)($t5)
  lui   $t7, %hi(matrix_buffer_gunbarrel_1) 
  lw    $t7, %lo(matrix_buffer_gunbarrel_1)($t7)
  sll   $t6, $t5, 6
  addiu $s0, $v0, 8
  jal   osVirtualToPhysical
   addu  $a0, $t6, $t7
  lw    $t8, 0x24($sp)
  move  $v1, $s0
  lui   $t9, 0x600
  sw    $v0, 4($t8)
  sw    $t9, ($v1)
  lui   $t0, %hi(dword_CODE_bss_80069554) 
  lw    $t0, %lo(dword_CODE_bss_80069554)($t0)
  lui   $at, 0x8000
  addiu $v0, $s0, 8
  addu  $t1, $t0, $at
  sw    $t1, 4($v1)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F007CC8
  addiu $sp, $sp, -0x20
  move  $v0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  addiu $a0, $a0, 8
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x0F0A4000 >> 16) # lui $t7, 0xf0a
  ori   $t7, (0x0F0A4000 & 0xFFFF) # ori $t7, $t7, 0x4000
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  move  $v1, $a0
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  addiu $a0, $a0, 8
  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
  move  $t0, $a0
  sw    $t8, ($v1)
  sw    $zero, 4($v1)
  addiu $a0, $a0, 8
  lui   $t9, (0xBA001301 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001301 & 0xFFFF) # ori $t9, $t9, 0x1301
  move  $t1, $a0
  sw    $t9, ($t0)
  sw    $zero, 4($t0)
  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
  addiu $a0, $a0, 8
  sw    $t3, ($t1)
  sw    $zero, 4($t1)
  move  $t2, $a0
  lui   $t4, 0xe700
  sw    $t4, ($t2)
  sw    $zero, 4($t2)
  lui   $a1, %hi(dword_CODE_bss_8006958C)
  lw    $a1, %lo(dword_CODE_bss_8006958C)($a1)
  lw    $t5, 0x2c($sp)
  lui   $at, 0x8000
  addiu $a0, $a0, 8
  lw    $a3, 0x28($sp)
  lw    $a2, 0x24($sp)
  addu  $a1, $a1, $at
  jal   sub_GAME_7F01B240
   sw    $t5, 0x10($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel insert_sniper_sight_eye_intro
  addiu $sp, $sp, -0x48
  lui   $t7, %hi(D_8002A7DC) 
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  addiu $t7, %lo(D_8002A7DC) # addiu $t7, $t7, -0x5824
  lw    $at, ($t7)
  addiu $t6, $sp, 0x3c
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  lui   $t2, %hi(D_8002A7E8) 
  addiu $t2, %lo(D_8002A7E8) # addiu $t2, $t2, -0x5818
  sw    $t0, 4($t6)
  sw    $at, 8($t6)
  lw    $at, ($t2)
  addiu $t1, $sp, 0x30
  lw    $t5, 4($t2)
  sw    $at, ($t1)
  lw    $at, 8($t2)
  lui   $t8, 0x100
  sw    $t5, 4($t1)
  sw    $at, 8($t1)
  addiu $t8, $t8, 0
  lui   $t9, 0x600
  sw    $t9, ($a0)
  sw    $t8, 4($a0)
  addiu $s0, $a0, 8
  jal   insert_imageDL
   move  $a0, $s0
  lui   $t6, (0xFC11FE23 >> 16) # lui $t6, 0xfc11
  ori   $t6, (0xFC11FE23 & 0xFFFF) # ori $t6, $t6, 0xfe23
  li    $t7, -2053
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  jal   get_video2_settings_txtClipW
   addiu $s0, $v0, 8
  mtc1  $v0, $f4
  lui   $at, %hi(x)
  lwc1  $f8, %lo(x)($at)
  cvt.s.w $f6, $f4
  li    $at, 0x44A00000 # 1280.000000
  mtc1  $at, $f16
  mul.s $f10, $f6, $f8
  jal   truncf
   div.s $f12, $f10, $f16
  trunc.w.s $f18, $f0
  move  $a0, $s0
  addiu $a2, $sp, 0x3c
  addiu $a3, $sp, 0x30
  mfc1  $a1, $f18
  jal   sub_GAME_7F007CC8
   nop   
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x48
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F007E70
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F01C1A4
   sw    $a1, 0x34($sp)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t7, (0x00504340 >> 16) # lui $t7, 0x50
  lui   $t8, (0xFCFFFFFF >> 16) # lui $t8, 0xfcff
  lui   $t9, (0xFFFDF6FB >> 16) # lui $t9, 0xfffd
  ori   $t7, (0x00504340 & 0xFFFF) # ori $t7, $t7, 0x4340
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t9, (0xFFFDF6FB & 0xFFFF) # ori $t9, $t9, 0xf6fb
  ori   $t8, (0xFCFFFFFF & 0xFFFF) # ori $t8, $t8, 0xffff
  lui   $t0, 0xfa00
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  sw    $t8, 8($v0)
  sw    $t9, 0xc($v0)
  sw    $t0, 0x10($v0)
  lw    $t1, 0x34($sp)
  lui   $t3, (0xBA000602 >> 16) # lui $t3, 0xba00
  ori   $t3, (0xBA000602 & 0xFFFF) # ori $t3, $t3, 0x602
  andi  $t2, $t1, 0xff
  sw    $t2, 0x14($v0)
  sw    $t3, 0x18($v0)
  sw    $zero, 0x1c($v0)
  addiu $t4, $v0, 0x20
  addiu $t5, $v0, 0x28
  sw    $t5, 0x30($sp)
  jal   get_video2_settings_txtClipW
   sw    $t4, 0x1c($sp)
  jal   get_video2_settings_txtClipH
   sh    $v0, 0x1a($sp)
  lh    $t9, 0x1a($sp)
  lw    $v1, 0x1c($sp)
  andi  $t6, $v0, 0x3ff
  sll   $t7, $t6, 2
  lui   $at, 0xf600
  andi  $t0, $t9, 0x3ff
  sll   $t1, $t0, 0xe
  or    $t8, $t7, $at
  or    $t2, $t8, $t1
  sw    $t2, ($v1)
  sw    $zero, 4($v1)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x30($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_8004F2D0
.word 0x3f68f5c3
glabel D_8004F2D4
.word 0x461c4000
glabel D_8004F2D8
.word 0x459c4000
glabel D_8004F2DC
.word 0x3f68f5c3
.text
glabel sub_GAME_7F007F30
  addiu $sp, $sp, -0x120
  lui   $t7, %hi(D_8002A7FC) 
  addiu $t7, %lo(D_8002A7FC) # addiu $t7, $t7, -0x5804
  sw    $ra, 0x34($sp)
  sw    $s5, 0x30($sp)
  sw    $s4, 0x2c($sp)
  sw    $s3, 0x28($sp)
  sw    $s2, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a0, 0x120($sp)
  sw    $a1, 0x124($sp)
  sw    $a2, 0x128($sp)
  addiu $t0, $t7, 0x3c
  addiu $t6, $sp, 0xdc
.L7F007F6C:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t0, .L7F007F6C
   sw    $at, -4($t6)
  lw    $at, ($t7)
  move  $s5, $zero
  move  $s2, $zero
  sw    $at, ($t6)
  lw    $t1, 0x124($sp)
  blez  $t1, .L7F008078
   lui   $s4, 0
  lui   $s3, %hi(D_8002A7F4)
  lui   $s0, %hi(dword_CODE_bss_80069594)
  addiu $s0, %lo(dword_CODE_bss_80069594) # addiu $s0, $s0, -0x6a6c
  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
  addiu $s4, $s4, 0x4298
  li    $s1, 137
  lw    $v0, ($s0)
.L7F007FC8:
  bltz  $v0, .L7F008030
   addiu $t2, $v0, 1
  sw    $t2, ($s0)
  bne   $s1, $t2, .L7F008014
   move  $v0, $t2
  lui   $at, %hi(D_8004F2D0)
  lwc1  $f4, %lo(D_8004F2D0)($at)
  li    $at, 0x41800000 # 16.000000
  lui   $t3, %hi(ptr_animation_table) 
  lw    $t3, %lo(ptr_animation_table)($t3)
  mtc1  $at, $f6
  lw    $a0, ($s3)
  move  $a2, $zero
  lui   $a3, 0x4000
  swc1  $f4, 0x10($sp)
  addu  $a1, $s4, $t3
  jal   sub_GAME_7F06FCA8
   swc1  $f6, 0x14($sp)
  lw    $v0, ($s0)
.L7F008014:
  li    $at, 212
  bne   $v0, $at, .L7F008030
   lui   $a1, (0x3FCCCCCD >> 16) # lui $a1, 0x3fcc
  lw    $a0, ($s3)
  ori   $a1, (0x3FCCCCCD & 0xFFFF) # ori $a1, $a1, 0xcccd
  jal   sub_GAME_7F06FE4C
   lui   $a2, 0x4100
.L7F008030:
  lw    $a0, ($s3)
  li    $a1, 1
  jal   sub_GAME_7F070AEC
   li    $a2, 1
  lw    $t4, ($s0)
  li    $at, 230
  lui   $a0, %hi(ptr_sfx_buf)
  bne   $t4, $at, .L7F008064
   li    $a1, 111
  lw    $a0, %lo(ptr_sfx_buf)($a0)
  move  $a2, $zero
  jal   play_sfx_a1
   li    $s5, 1
.L7F008064:
  lw    $t5, 0x124($sp)
  addiu $s2, $s2, 1
  bnel  $s2, $t5, .L7F007FC8
   lw    $v0, ($s0)
  move  $s2, $zero
.L7F008078:
  lui   $s3, %hi(D_8002A7F4)
  addiu $s3, %lo(D_8002A7F4) # addiu $s3, $s3, -0x580c
  jal   set_80036084
   li    $a0, 1
  jal   sub_GAME_7F073FC8
   li    $a0, 80
  jal   subcalcpos
   lw    $a0, ($s3)
  lui   $s4, %hi(D_8002A7F8)
  addiu $s4, %lo(D_8002A7F8) # addiu $s4, $s4, -0x5808
  lw    $a2, ($s4)
  lw    $t9, 8($a2)
  lw    $v1, 8($t9)
  lw    $a1, ($v1)
  beql  $a1, $zero, .L7F0080D4
   lw    $a1, 8($v1)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a2
  sh    $s5, ($v0)
  lw    $a2, ($s4)
  lw    $t8, 8($a2)
  lw    $v1, 8($t8)
  lw    $a1, 8($v1)
.L7F0080D4:
  beql  $a1, $zero, .L7F0080EC
   lw    $t0, 0x128($sp)
  jal   extract_id_from_object_structure_microcode
   move  $a0, $a2
  sw    $s5, ($v0)
  lw    $t0, 0x128($sp)
.L7F0080EC:
  lw    $t7, ($s3)
  sw    $t0, 0xdc($sp)
  lw    $t6, 8($t7)
  lh    $a0, 0xe($t6)
  sll   $t1, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t1
  sw    $v0, 0xec($sp)
  addiu $a0, $sp, 0xdc
  jal   subcalcmatrices
   lw    $a1, ($s3)
  lw    $t2, ($s4)
  lw    $a0, ($s3)
  move  $a2, $zero
  jal   sub_GAME_7F06C660
   lw    $a1, 0x1c($t2)
  lw    $t3, ($s4)
  sw    $v0, 0xdc($sp)
  lw    $t4, 8($t3)
  lh    $a0, 0xe($t4)
  sll   $t5, $a0, 6
  jal   sub_GAME_7F0BD714
   move  $a0, $t5
  sw    $v0, 0xec($sp)
  addiu $a0, $sp, 0xdc
  jal   instcalcmatrices
   lw    $a1, ($s4)
  move  $a0, $zero
  jal   sub_GAME_7F06B120
   lw    $a1, ($s3)
  move  $a0, $v0
  jal   sub_GAME_7F06B120
   lw    $a1, ($s4)
  move  $s0, $v0
  jal   sub_GAME_7F06B29C
   move  $a0, $v0
  jal   sub_GAME_7F06BB28
   move  $a0, $s0
  lw    $t8, 0x120($sp)
  li    $t9, 7
  li    $t0, 1
  move  $s0, $v0
  sw    $t9, 0x10c($sp)
  sw    $zero, 0xe0($sp)
  sw    $t0, 0xe4($sp)
  addiu $a0, $sp, 0xdc
  move  $a1, $v0
  jal   drawjointlist
   sw    $t8, 0xe8($sp)
  li    $t7, 2
  sw    $t7, 0xe4($sp)
  addiu $a0, $sp, 0xdc
  jal   drawjointlist
   move  $a1, $s0
  jal   set_80036084
   move  $a0, $zero
  jal   sub_GAME_7F06B248
   move  $a0, $s0
  lw    $v0, ($s3)
  move  $s0, $zero
  addiu $s1, $sp, 0x88
  lw    $t6, 8($v0)
  lh    $t1, 0xe($t6)
  blezl $t1, .L7F008240
   lw    $a2, ($s4)
  lw    $t2, 0xc($v0)
.L7F0081F4:
  move  $a1, $s1
  jal   matrix_4x4_copy
   addu  $a0, $t2, $s0
  lw    $t3, ($s3)
  sll   $t5, $s2, 6
  move  $a0, $s1
  lw    $t4, 0xc($t3)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t4, $t5
  lw    $v0, ($s3)
  addiu $s2, $s2, 1
  addiu $s0, $s0, 0x40
  lw    $t9, 8($v0)
  lh    $t8, 0xe($t9)
  slt   $at, $s2, $t8
  bnezl $at, .L7F0081F4
   lw    $t2, 0xc($v0)
  move  $s2, $zero
  lw    $a2, ($s4)
.L7F008240:
  move  $s0, $zero
  addiu $s1, $sp, 0x48
  lw    $t0, 8($a2)
  lh    $t7, 0xe($t0)
  blezl $t7, .L7F0082A4
   lw    $ra, 0x34($sp)
  lw    $t6, 0xc($a2)
.L7F00825C:
  move  $a1, $s1
  jal   matrix_4x4_copy
   addu  $a0, $t6, $s0
  lw    $t1, ($s4)
  sll   $t3, $s2, 6
  move  $a0, $s1
  lw    $t2, 0xc($t1)
  jal   sub_GAME_7F058C9C
   addu  $a1, $t2, $t3
  lw    $a2, ($s4)
  addiu $s2, $s2, 1
  addiu $s0, $s0, 0x40
  lw    $t4, 8($a2)
  lh    $t5, 0xe($t4)
  slt   $at, $s2, $t5
  bnezl $at, .L7F00825C
   lw    $t6, 0xc($a2)
  lw    $ra, 0x34($sp)
.L7F0082A4:
  lw    $v0, 0xe8($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  lw    $s4, 0x2c($sp)
  lw    $s5, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x120
");

asm(R"
glabel insert_bond_eye_intro
  mtc1  $zero, $f0
  lui   $t6, %hi(D_8002A7D0) 
  lw    $t6, %lo(D_8002A7D0)($t6)
  addiu $sp, $sp, -0xa0
  lui   $t8, %hi(matrix_buffer_intro_backdrop) 
  lw    $t8, %lo(matrix_buffer_intro_backdrop)($t8)
  sw    $s0, 0x30($sp)
  move  $s0, $a0
  sw    $ra, 0x34($sp)
  mfc1  $a1, $f0
  mfc1  $a2, $f0
  mfc1  $a3, $f0
  sll   $t7, $t6, 6
  jal   guTranslate
   addu  $a0, $t7, $t8
  li    $at, 0x41200000 # 10.000000
  mtc1  $at, $f4
  lui   $at, %hi(D_8004F2D4)
  lui   $t9, %hi(D_8002A7D0) 
  lw    $t9, %lo(D_8002A7D0)($t9)
  lwc1  $f6, %lo(D_8004F2D4)($at)
  li    $at, 0x3F800000 # 1.000000
  lui   $t4, %hi(matrix_buffer_intro_bond) 
  lw    $t4, %lo(matrix_buffer_intro_bond)($t4)
  mtc1  $at, $f8
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  sll   $t3, $t9, 6
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  addiu $a1, $sp, 0x5e
  lui   $a2, 0x4238
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  addu  $a0, $t3, $t4
  jal   guPerspective
   swc1  $f8, 0x18($sp)
  lui   $t5, (0xBC00000E >> 16) # lui $t5, 0xbc00
  ori   $t5, (0xBC00000E & 0xFFFF) # ori $t5, $t5, 0xe
  move  $v0, $s0
  sw    $t5, ($v0)
  lhu   $t6, 0x5e($sp)
  addiu $s0, $s0, 8
  move  $v1, $s0
  addiu $s0, $s0, 8
  lui   $t7, (0xFCFFFFFF >> 16) # lui $t7, 0xfcff
  lui   $t8, (0xFFFE793C >> 16) # lui $t8, 0xfffe
  sw    $t6, 4($v0)
  ori   $t8, (0xFFFE793C & 0xFFFF) # ori $t8, $t8, 0x793c
  ori   $t7, (0xFCFFFFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  move  $a1, $s0
  sw    $t7, ($v1)
  sw    $t8, 4($v1)
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  lui   $t3, (0x00552048 >> 16) # lui $t3, 0x55
  ori   $t3, (0x00552048 & 0xFFFF) # ori $t3, $t3, 0x2048
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  addiu $s0, $s0, 8
  lui   $t4, (0x01030040 >> 16) # lui $t4, 0x103
  sw    $t9, ($a1)
  sw    $t3, 4($a1)
  ori   $t4, (0x01030040 & 0xFFFF) # ori $t4, $t4, 0x40
  move  $a2, $s0
  sw    $t4, ($a2)
  lui   $t5, %hi(D_8002A7D0) 
  lw    $t5, %lo(D_8002A7D0)($t5)
  lui   $t7, %hi(matrix_buffer_intro_bond) 
  lw    $t7, %lo(matrix_buffer_intro_bond)($t7)
  sll   $t6, $t5, 6
  sw    $a2, 0x4c($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   addu  $a0, $t6, $t7
  lw    $a2, 0x4c($sp)
  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $t2, $s0
  sw    $v0, 4($a2)
  sw    $t8, ($t2)
  lui   $t9, %hi(D_8002A7D0) 
  lw    $t9, %lo(D_8002A7D0)($t9)
  lui   $t4, %hi(matrix_buffer_intro_backdrop) 
  lw    $t4, %lo(matrix_buffer_intro_backdrop)($t4)
  sll   $t3, $t9, 6
  sw    $t2, 0x48($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   addu  $a0, $t3, $t4
  lw    $t2, 0x48($sp)
  lui   $v1, %hi(D_8002A83C)
  lui   $t0, %hi(D_8002A848) 
  sw    $v0, 4($t2)
  addiu $t0, %lo(D_8002A848) # addiu $t0, $t0, -0x57b8
  addiu $v1, %lo(D_8002A83C) # addiu $v1, $v1, -0x57c4
  lwc1  $f0, ($v1)
  lwc1  $f10, ($t0)
  lwc1  $f2, 4($v1)
  lwc1  $f18, 4($t0)
  add.s $f16, $f10, $f0
  lwc1  $f12, 8($v1)
  lwc1  $f6, 8($t0)
  lui   $t1, %hi(D_8002A854) 
  addiu $t1, %lo(D_8002A854) # addiu $t1, $t1, -0x57ac
  add.s $f4, $f18, $f2
  swc1  $f16, 0x10($sp)
  lwc1  $f16, 4($t1)
  add.s $f8, $f6, $f12
  lwc1  $f18, 8($t1)
  lwc1  $f10, ($t1)
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  mfc1  $a3, $f12
  swc1  $f8, 0x18($sp)
  swc1  $f4, 0x14($sp)
  addiu $a0, $sp, 0x60
  swc1  $f16, 0x20($sp)
  swc1  $f18, 0x24($sp)
  jal   sub_GAME_7F059694
   swc1  $f10, 0x1c($sp)
  move  $a0, $s0
  li    $a1, 2
  jal   sub_GAME_7F007F30
   addiu $a2, $sp, 0x60
  lw    $ra, 0x34($sp)
  lw    $s0, 0x30($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

asm(R"
glabel load_display_rare_logo
  mtc1  $a3, $f4
  addiu $sp, $sp, -0xe8
  sw    $s0, 0x2c($sp)
  cvt.s.w $f6, $f4
  lui   $at, %hi(D_8002A880)
  sw    $ra, 0x34($sp)
  sw    $s1, 0x30($sp)
  sw    $a1, 0xec($sp)
  sw    $a2, 0xf0($sp)
  swc1  $f6, %lo(D_8002A880)($at)
  lui   $t7, 0x100
  addiu $t7, $t7, 0
  lui   $t6, 0x600
  sw    $t6, ($a0)
  sw    $t7, 4($a0)
  addiu $s0, $a0, 8
  jal   insert_imageDL
   move  $a0, $s0
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f8
  lui   $s1, %hi(D_8002A7D0)
  addiu $s1, %lo(D_8002A7D0) # addiu $s1, $s1, -0x5830
  lui   $at, %hi(D_8004F2D8)
  lwc1  $f10, %lo(D_8004F2D8)($at)
  lw    $t8, ($s1)
  li    $at, 0x3F800000 # 1.000000
  lui   $t6, %hi(matrix_buffer_rarelogo_0) 
  lw    $t6, %lo(matrix_buffer_rarelogo_0)($t6)
  mtc1  $at, $f16
  lui   $a3, (0x3FAAAAAB >> 16) # lui $a3, 0x3faa
  sll   $t9, $t8, 6
  move  $s0, $v0
  ori   $a3, (0x3FAAAAAB & 0xFFFF) # ori $a3, $a3, 0xaaab
  addiu $a1, $sp, 0xe2
  lui   $a2, 0x4270
  swc1  $f8, 0x10($sp)
  swc1  $f10, 0x14($sp)
  addu  $a0, $t9, $t6
  jal   guPerspective
   swc1  $f16, 0x18($sp)
  lui   $t7, (0xBC00000E >> 16) # lui $t7, 0xbc00
  ori   $t7, (0xBC00000E & 0xFFFF) # ori $t7, $t7, 0xe
  move  $v0, $s0
  sw    $t7, ($v0)
  lhu   $t8, 0xe2($sp)
  addiu $s0, $s0, 8
  lui   $t9, (0x01030040 >> 16) # lui $t9, 0x103
  ori   $t9, (0x01030040 & 0xFFFF) # ori $t9, $t9, 0x40
  move  $t3, $s0
  sw    $t8, 4($v0)
  sw    $t9, ($t3)
  lw    $t6, ($s1)
  lui   $t8, %hi(matrix_buffer_rarelogo_0) 
  lw    $t8, %lo(matrix_buffer_rarelogo_0)($t8)
  sll   $t7, $t6, 6
  sw    $t3, 0xd8($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   addu  $a0, $t7, $t8
  lw    $t3, 0xd8($sp)
  move  $v1, $s0
  li    $t6, -1
  sw    $v0, 4($t3)
  sw    $t6, 4($v1)
  addiu $s0, $s0, 8
  lui   $t9, 0xb600
  sw    $t9, ($v1)
  move  $t0, $s0
  lui   $t7, 0xb700
  lui   $t8, (0x00062204 >> 16) # lui $t8, 6
  ori   $t8, (0x00062204 & 0xFFFF) # ori $t8, $t8, 0x2204
  sw    $t7, ($t0)
  sw    $t8, 4($t0)
  lui   $t1, %hi(D_8002A884) 
  lui   $t4, %hi(D_8002A878) 
  addiu $t4, %lo(D_8002A878) # addiu $t4, $t4, -0x5788
  addiu $t1, %lo(D_8002A884) # addiu $t1, $t1, -0x577c
  lwc1  $f18, ($t1)
  lwc1  $f0, ($t4)
  lwc1  $f6, 4($t1)
  lwc1  $f2, 4($t4)
  add.s $f4, $f18, $f0
  lwc1  $f10, 8($t1)
  lwc1  $f12, 8($t4)
  lui   $t2, %hi(D_8002A890) 
  addiu $t2, %lo(D_8002A890) # addiu $t2, $t2, -0x5770
  add.s $f8, $f6, $f2
  lw    $t9, ($s1)
  swc1  $f4, 0x10($sp)
  add.s $f16, $f10, $f12
  lui   $t7, %hi(matrix_buffer_rarelogo_1) 
  lw    $t7, %lo(matrix_buffer_rarelogo_1)($t7)
  lwc1  $f4, 4($t2)
  lwc1  $f6, 8($t2)
  lwc1  $f18, ($t2)
  mfc1  $a1, $f0
  mfc1  $a2, $f2
  mfc1  $a3, $f12
  sll   $t6, $t9, 6
  addiu $s0, $s0, 8
  swc1  $f16, 0x18($sp)
  swc1  $f8, 0x14($sp)
  addu  $a0, $t6, $t7
  swc1  $f4, 0x20($sp)
  swc1  $f6, 0x24($sp)
  jal   guLookAt
   swc1  $f18, 0x1c($sp)
  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $v1, $s0
  sw    $t8, ($v1)
  lw    $t9, ($s1)
  lui   $t7, %hi(matrix_buffer_rarelogo_1) 
  lw    $t7, %lo(matrix_buffer_rarelogo_1)($t7)
  sll   $t6, $t9, 6
  sw    $v1, 0xcc($sp)
  addiu $s0, $s0, 8
  jal   osVirtualToPhysical
   addu  $a0, $t6, $t7
  lw    $v1, 0xcc($sp)
  mtc1  $zero, $f0
  lui   $t6, %hi(matrix_buffer_rarelogo_2) 
  sw    $v0, 4($v1)
  lw    $t8, ($s1)
  lw    $t6, %lo(matrix_buffer_rarelogo_2)($t6)
  lui   $a1, %hi(D_8002A89C)
  mfc1  $a2, $f0
  sll   $t9, $t8, 6
  lw    $a1, %lo(D_8002A89C)($a1)
  lui   $a3, %hi(0x3F800004) # $a3, 0x3f80
  swc1  $f0, 0x10($sp)
  jal   guRotate
   addu  $a0, $t9, $t6
  lui   $v0, %hi(D_8002A89C)
  addiu $v0, %lo(D_8002A89C) # addiu $v0, $v0, -0x5764
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f10
  lwc1  $f8, ($v0)
  lui   $t7, (0x01000040 >> 16) # lui $t7, 0x100
  ori   $t7, (0x01000040 & 0xFFFF) # ori $t7, $t7, 0x40
  add.s $f16, $f8, $f10
  move  $t2, $s0
  lui   $t6, %hi(matrix_buffer_rarelogo_2) 
  addiu $s0, $s0, 8
  swc1  $f16, ($v0)
  sw    $t7, ($t2)
  lw    $t8, ($s1)
  lw    $t6, %lo(matrix_buffer_rarelogo_2)($t6)
  sw    $t2, 0xc8($sp)
  sll   $t9, $t8, 6
  jal   osVirtualToPhysical
   addu  $a0, $t9, $t6
  lw    $t0, 0xf8($sp)
  lw    $t2, 0xc8($sp)
  move  $a0, $s0
  lui   $t7, (0xBC000002 >> 16) # lui $t7, 0xbc00
  ori   $t7, (0xBC000002 & 0xFFFF) # ori $t7, $t7, 2
  addiu $s0, $s0, 8
  lui   $t8, (0x80000040 >> 16) # lui $t8, 0x8000
  sw    $v0, 4($t2)
  sw    $t7, ($a0)
  ori   $t8, (0x80000040 & 0xFFFF) # ori $t8, $t8, 0x40
  move  $a1, $s0
  sw    $t8, 4($a0)
  lui   $t9, (0x03860010 >> 16) # lui $t9, 0x386
  lui   $t6, %hi(D_8002A868) 
  addiu $t6, %lo(D_8002A868) # addiu $t6, $t6, -0x5798
  ori   $t9, (0x03860010 & 0xFFFF) # ori $t9, $t9, 0x10
  addiu $s0, $s0, 8
  lui   $v1, %hi(D_8002A860)
  move  $a2, $s0
  sw    $t9, ($a1)
  sw    $t6, 4($a1)
  lui   $t7, (0x03880010 >> 16) # lui $t7, 0x388
  addiu $v1, %lo(D_8002A860) # addiu $v1, $v1, -0x57a0
  ori   $t7, (0x03880010 & 0xFFFF) # ori $t7, $t7, 0x10
  sw    $t7, ($a2)
  sw    $v1, 4($a2)
  addiu $s0, $s0, 8
  move  $a3, $s0
  sb    $t0, ($v1)
  sb    $t0, 1($v1)
  sb    $t0, 2($v1)
  sb    $t0, 4($v1)
  sb    $t0, 5($v1)
  sb    $t0, 6($v1)
  addiu $s0, $s0, 8
  lui   $t1, 0xe700
  move  $t3, $s0
  sw    $t1, ($a3)
  sw    $zero, %lo(0x3F800004)($a3)
  addiu $s0, $s0, 8
  move  $v0, $s0
  sw    $zero, 4($t3)
  sw    $t1, ($t3)
  addiu $s0, $s0, 8
  lui   $t8, (0xFC127E24 >> 16) # lui $t8, 0xfc12
  ori   $t8, (0xFC127E24 & 0xFFFF) # ori $t8, $t8, 0x7e24
  li    $t9, -1540
  move  $v1, $s0
  sw    $t9, 4($v0)
  sw    $t8, ($v0)
  lui   $t6, (0xBA001301 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001301 & 0xFFFF) # ori $t6, $t6, 0x1301
  lui   $t7, 8
  sw    $t7, 4($v1)
  sw    $t6, ($v1)
  addiu $s0, $s0, 8
  move  $a0, $s0
  lui   $t8, (0xBA001102 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001102 & 0xFFFF) # ori $t8, $t8, 0x1102
  addiu $s0, $s0, 8
  sw    $t8, ($a0)
  move  $a1, $s0
  lui   $t9, (0xBA001001 >> 16) # lui $t9, 0xba00
  sw    $zero, 4($a0)
  ori   $t9, (0xBA001001 & 0xFFFF) # ori $t9, $t9, 0x1001
  addiu $s0, $s0, 8
  sw    $t9, ($a1)
  move  $a2, $s0
  sw    $zero, 4($a1)
  addiu $s0, $s0, 8
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02
  move  $v0, $s0
  sw    $t6, ($a2)
  sw    $zero, 4($a2)
  lui   $t7, (0xBA000C02 >> 16) # lui $t7, 0xba00
  ori   $t7, (0xBA000C02 & 0xFFFF) # ori $t7, $t7, 0xc02
  addiu $s0, $s0, 8
  li    $t8, 8192
  sw    $t8, 4($v0)
  sw    $t7, ($v0)
  move  $v1, $s0
  lui   $t9, (0xBA000903 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA000903 & 0xFFFF) # ori $t9, $t9, 0x903
  addiu $s0, $s0, 8
  sw    $t9, ($v1)
  li    $t6, 3072
  move  $a0, $s0
  sw    $t6, 4($v1)
  addiu $s0, $s0, 8
  move  $a1, $s0
  sw    $zero, 4($a0)
  sw    $t1, ($a0)
  addiu $s0, $s0, 8
  sw    $zero, 4($a1)
  sw    $t1, ($a1)
  move  $a3, $s0
  addiu $s0, $s0, 8
  lui   $t7, (0xBB000001 >> 16) # lui $t7, 0xbb00
  lui   $t8, (0x08000800 >> 16) # lui $t8, 0x800
  ori   $t8, (0x08000800 & 0xFFFF) # ori $t8, $t8, 0x800
  ori   $t7, (0xBB000001 & 0xFFFF) # ori $t7, $t7, 1
  move  $v0, $s0
  sw    $t7, ($a3)
  sw    $t8, %lo(0x3F800004)($a3)
  addiu $s0, $s0, 8
  lui   $t9, %hi(0x02004FE8) # $t9, 0x200
  lui   $t3, 0xfd10
  addiu $t9, %lo(0x02004FE8) # addiu $t9, $t9, 0x4fe8
  move  $v1, $s0
  lui   $t5, (0x07014050 >> 16) # lui $t5, 0x701
  addiu $s0, $s0, 8
  sw    $t9, 4($v0)
  sw    $t3, ($v0)
  ori   $t5, (0x07014050 & 0xFFFF) # ori $t5, $t5, 0x4050
  lui   $t4, 0xf510
  move  $a0, $s0
  sw    $t4, ($v1)
  sw    $t5, 4($v1)
  lui   $ra, 0xe600
  addiu $s0, $s0, 8
  move  $a1, $s0
  sw    $ra, ($a0)
  sw    $zero, 4($a0)
  lui   $t6, (0x073FF100 >> 16) # lui $t6, 0x73f
  ori   $t6, (0x073FF100 & 0xFFFF) # ori $t6, $t6, 0xf100
  addiu $s0, $s0, 8
  lui   $s1, 0xf300
  move  $a2, $s0
  sw    $t6, 4($a1)
  addiu $s0, $s0, 8
  sw    $s1, ($a1)
  move  $v1, $s0
  sw    $zero, 4($a2)
  sw    $t1, ($a2)
  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
  lui   $t7, (0xF5101000 >> 16) # lui $t7, 0xf510
  ori   $t7, (0xF5101000 & 0xFFFF) # ori $t7, $t7, 0x1000
  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
  addiu $s0, $s0, 8
  move  $a0, $s0
  sw    $t8, 4($v1)
  sw    $t7, ($v1)
  lui   $t6, (0x0007C07C >> 16) # lui $t6, 7
  lui   $t9, 0xf200
  sw    $t9, ($a0)
  ori   $t6, (0x0007C07C & 0xFFFF) # ori $t6, $t6, 0xc07c
  addiu $s0, $s0, 8
  andi  $v0, $t0, 0xff
  sw    $t6, 4($a0)
  move  $a1, $s0
  lui   $t7, 0xfa00
  sw    $t7, ($a1)
  sll   $t8, $v0, 0x18
  sll   $t9, $v0, 0x10
  or    $t6, $t8, $t9
  sll   $t7, $v0, 8
  or    $t8, $t6, $t7
  addiu $s0, $s0, 8
  ori   $t9, $t8, 0xff
  move  $a3, $s0
  sw    $t9, 4($a1)
  addiu $s0, $s0, 8
  lui   $t6, %hi(0x020043E8) # $t6, 0x200
  addiu $t6, %lo(0x020043E8) # addiu $t6, $t6, 0x43e8
  lui   $a2, 0x600
  move  $v0, $s0
  sw    $a2, ($a3)
  sw    $t6, 4($a3)
  addiu $s0, $s0, 8
  lui   $t7, %hi(0x020044B0) # $t7, 0x200
  addiu $t7, %lo(0x020044B0) # addiu $t7, $t7, 0x44b0
  move  $v1, $s0
  sw    $t7, 4($v0)
  sw    $a2, ($v0)
  lui   $t8, %hi(0x02005FF0) # $t8, 0x200
  addiu $t8, %lo(0x02005FF0) # addiu $t8, $t8, 0x5ff0
  addiu $s0, $s0, 8
  move  $a0, $s0
  sw    $t8, 4($v1)
  sw    $t3, ($v1)
  addiu $s0, $s0, 8
  move  $a1, $s0
  addiu $s0, $s0, 8
  sw    $t5, 4($a0)
  sw    $t4, ($a0)
  move  $t2, $s0
  addiu $s0, $s0, 8
  sw    $zero, 4($a1)
  sw    $ra, ($a1)
  lui   $t9, (0x073FF100 >> 16) # lui $t9, 0x73f
  ori   $t9, (0x073FF100 & 0xFFFF) # ori $t9, $t9, 0xf100
  move  $v0, $s0
  li    $a3, 255
  sw    $t9, 4($t2)
  sw    $s1, ($t2)
  addiu $s0, $s0, 8
  lui   $t7, (0x00014050 >> 16) # lui $t7, 1
  ori   $t7, (0x00014050 & 0xFFFF) # ori $t7, $t7, 0x4050
  move  $v1, $s0
  sw    $zero, 4($v0)
  sw    $t1, ($v0)
  sw    $t7, 4($v1)
  sll   $t7, $t0, 4
  subu  $t7, $t7, $t0
  sll   $t7, $t7, 4
  div   $zero, $t7, $a3
  lui   $t6, (0xF5101000 >> 16) # lui $t6, 0xf510
  ori   $t6, (0xF5101000 & 0xFFFF) # ori $t6, $t6, 0x1000
  addiu $s0, $s0, 8
  move  $a0, $s0
  sw    $t6, ($v1)
  lui   $t9, (0x0007C07C >> 16) # lui $t9, 7
  ori   $t9, (0x0007C07C & 0xFFFF) # ori $t9, $t9, 0xc07c
  addiu $s0, $s0, 8
  lui   $t8, 0xf200
  sw    $t8, ($a0)
  sw    $t9, 4($a0)
  move  $a1, $s0
  lui   $t6, 0xfa00
  sw    $t6, ($a1)
  sll   $t6, $t0, 2
  subu  $t6, $t6, $t0
  sll   $t6, $t6, 2
  addu  $t6, $t6, $t0
  sll   $t6, $t6, 4
  mflo  $a2
  andi  $t8, $a2, 0xff
  move  $a2, $t8
  div   $zero, $t6, $a3
  sll   $t9, $t8, 0x18
  addiu $s0, $s0, 8
  bnez  $a3, .L7F008ACC
   nop   
  break 7
.L7F008ACC:
  li    $at, -1
  bne   $a3, $at, .L7F008AE4
   lui   $at, 0x8000
  bne   $t7, $at, .L7F008AE4
   nop   
  break 6
.L7F008AE4:
  mflo  $t7
  andi  $t8, $t7, 0xff
  bnez  $a3, .L7F008AF8
   nop   
  break 7
.L7F008AF8:
  li    $at, -1
  bne   $a3, $at, .L7F008B10
   lui   $at, 0x8000
  bne   $t6, $at, .L7F008B10
   nop   
  break 6
.L7F008B10:
  sll   $t6, $t8, 0x10
  or    $t7, $t9, $t6
  sll   $t8, $a2, 8
  or    $t9, $t7, $t8
  ori   $t6, $t9, 0xff
  sw    $t6, 4($a1)
  lui   $t8, %hi(0x02004758) # $t8, 0x200
  move  $v1, $s0
  addiu $t8, %lo(0x02004758) # addiu $t8, $t8, 0x4758
  lui   $t7, 0x600
  sw    $t7, ($v1)
  sw    $t8, 4($v1)
  lw    $ra, 0x34($sp)
  addiu $v0, $s0, 8
  lw    $s0, 0x2c($sp)
  lw    $s1, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0xe8
");

asm(R"
glabel sub_GAME_7F008B58
  lui   $at, %hi(D_8002A7D4)
  sb    $zero, %lo(D_8002A7D4)($at)
  li    $at, 0x445C0000 # 880.000000
  mtc1  $at, $f4
  lui   $at, %hi(x)
  lui   $t6, %hi(0x020067F0) # $t6, 0x200
  swc1  $f4, %lo(x)($at)
  li    $at, 0xC2200000 # -40.000000
  mtc1  $at, $f6
  lui   $t7, 0x200
  lui   $at, %hi(D_8002A89C)
  addiu $t7, $t7, 0
  addiu $t6, %lo(0x020067F0) # addiu $t6, $t6, 0x67f0
  addiu $sp, $sp, -0x18
  subu  $a2, $t6, $t7
  swc1  $f6, %lo(D_8002A89C)($at)
  sw    $a1, 0x1c($sp)
  lui   $v0, %hi(virtualaddress)
  lui   $at, %hi(intro_eye_counter)
  addiu $a2, $a2, 0x3f
  addiu $v0, %lo(virtualaddress) # addiu $v0, $v0, -0x6a70
  sw    $ra, 0x14($sp)
  sw    $zero, %lo(intro_eye_counter)($at)
  ori   $t8, $a2, 0x3f
  lui   $a1, %hi(_Globalimagetablecmdblk) # $a1, 0x2a
  sw    $a0, ($v0)
  addiu $a1, %lo(_Globalimagetablecmdblk) # addiu $a1, $a1, -0x1aa0
  jal   romCopy
   xori  $a2, $t8, 0x3f
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel retrieve_display_rareware_logo
  lui   $v0, %hi(D_8002A7D0)
  addiu $v0, %lo(D_8002A7D0) # addiu $v0, $v0, -0x5830
  lw    $t6, ($v0)
  addiu $sp, $sp, -0x30
  li    $t7, 1
  sw    $s0, 0x20($sp)
  lui   $t9, (0xBC000806 >> 16) # lui $t9, 0xbc00
  subu  $t8, $t7, $t6
  sw    $ra, 0x24($sp)
  sw    $t8, ($v0)
  ori   $t9, (0xBC000806 & 0xFFFF) # ori $t9, $t9, 0x806
  sw    $t9, ($a0)
  addiu $s0, $a0, 8
  move  $v1, $a0
  lui   $a0, %hi(virtualaddress)
  lw    $a0, %lo(virtualaddress)($a0)
  jal   osVirtualToPhysical
   sw    $v1, 0x2c($sp)
  lw    $v1, 0x2c($sp)
  lui   $t1, %hi(D_8002A7D4) 
  addiu $t1, %lo(D_8002A7D4) # addiu $t1, $t1, -0x582c
  sw    $v0, 4($v1)
  lbu   $a0, ($t1)
  lui   $t0, %hi(intro_eye_counter) 
  addiu $t0, %lo(intro_eye_counter) # addiu $t0, $t0, -0x5760
  beql  $a0, $zero, .L7F008C58
   lw    $t3, ($t0)
  li    $at, 1
  bnel  $a0, $at, .L7F008DC0
   lw    $ra, 0x24($sp)
  lw    $t3, ($t0)
.L7F008C58:
  li    $t2, 255
  li    $a1, 70
  multu $t3, $t2
  mflo  $a0
  nop   
  nop   
  div   $zero, $a0, $a1
  bnez  $a1, .L7F008C80
   nop   
  break 7
.L7F008C80:
  li    $at, -1
  bne   $a1, $at, .L7F008C98
   lui   $at, 0x8000
  bne   $a0, $at, .L7F008C98
   nop   
  break 6
.L7F008C98:
  mflo  $v1
  slti  $at, $v1, 0x100
  bnez  $at, .L7F008CAC
   nop   
  move  $v1, $t2
.L7F008CAC:
  bgez  $v1, .L7F008CB8
   lui   $at, (0xFFFF60A0 >> 16) # lui $at, 0xffff
  move  $v1, $zero
.L7F008CB8:
  ori   $at, (0xFFFF60A0 & 0xFFFF) # ori $at, $at, 0x60a0
  addu  $t4, $a0, $at
  div   $zero, $t4, $a1
  bnez  $a1, .L7F008CD0
   nop   
  break 7
.L7F008CD0:
  li    $at, -1
  bne   $a1, $at, .L7F008CE8
   lui   $at, 0x8000
  bne   $t4, $at, .L7F008CE8
   nop   
  break 6
.L7F008CE8:
  mflo  $t5
  subu  $v0, $t2, $t5
  slti  $at, $v0, 0x100
  bnez  $at, .L7F008D00
   nop   
  move  $v0, $t2
.L7F008D00:
  bgez  $v0, .L7F008D0C
   nop   
  move  $v0, $zero
.L7F008D0C:
  multu $v1, $v0
  lui   $at, %hi(x)
  lwc1  $f4, %lo(x)($at)
  move  $a0, $s0
  li    $a1, 403
  trunc.w.s $f6, $f4
  li    $a2, 488
  mfc1  $a3, $f6
  mflo  $t6
  nop   
  nop   
  div   $zero, $t6, $t2
  mflo  $t8
  sw    $t8, 0x10($sp)
  bnez  $t2, .L7F008D50
   nop   
  break 7
.L7F008D50:
  li    $at, -1
  bne   $t2, $at, .L7F008D68
   lui   $at, 0x8000
  bne   $t6, $at, .L7F008D68
   nop   
  break 6
.L7F008D68:
  jal   load_display_rare_logo
   nop   
  lui   $t0, %hi(intro_eye_counter) 
  addiu $t0, %lo(intro_eye_counter) # addiu $t0, $t0, -0x5760
  lw    $v1, ($t0)
  lui   $t1, %hi(D_8002A7D4) 
  addiu $t1, %lo(D_8002A7D4) # addiu $t1, $t1, -0x582c
  slti  $a0, $v1, 0x104
  addiu $t9, $v1, 1
  move  $s0, $v0
  bnez  $a0, .L7F008DBC
   sw    $t9, ($t0)
  slti  $at, $t9, 0x122
  bnezl $at, .L7F008DC0
   lw    $ra, 0x24($sp)
  lbu   $t4, ($t1)
  sw    $zero, ($t0)
  addiu $t7, $t4, 1
  sb    $t7, ($t1)
  addiu $t6, $t7, 1
  sb    $t6, ($t1)
.L7F008DBC:
  lw    $ra, 0x24($sp)
.L7F008DC0:
  move  $v0, $s0
  lw    $s0, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F008DD0
  lui   $v0, %hi(D_8002A7D4)
  lbu   $v0, %lo(D_8002A7D4)($v0)
  xori  $t6, $v0, 2
  jr    $ra
   sltiu $v0, $t6, 1
");

asm(R"
glabel sub_GAME_7F008DE4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  lw    $t6, ($a0)
  lui   $at, %hi(dword_CODE_bss_8006958C)
  lui   $v1, %hi(unknown2) # $v1, 0x2a
  sw    $t6, %lo(dword_CODE_bss_8006958C)($at)
  lw    $t8, ($a1)
  lui   $at, (0xFFFBFC00 >> 16) # lui $at, 0xfffb
  ori   $at, (0xFFFBFC00 & 0xFFFF) # ori $at, $at, 0xfc00
  addu  $t9, $t8, $at
  sw    $t9, ($a1)
  lw    $t0, ($a0)
  lui   $t3, %hi(ramrom_Dam_1) # $t3, 0x2c
  addiu $v1, %lo(unknown2) # addiu $v1, $v1, 0x4d50
  lui   $at, (0x00040400 >> 16) # lui $at, 4
  addiu $t3, %lo(ramrom_Dam_1) # addiu $t3, $t3, -0xd30
  ori   $at, (0x00040400 & 0xFFFF) # ori $at, $at, 0x400
  subu  $a2, $t3, $v1
  lui   $v0, %hi(dword_CODE_bss_80069588)
  addiu $a2, $a2, 0x3f
  addu  $t1, $t0, $at
  addiu $v0, %lo(dword_CODE_bss_80069588) # addiu $v0, $v0, -0x6a78
  sw    $t1, ($a0)
  ori   $t4, $a2, 0x3f
  sw    $t1, ($v0)
  xori  $a2, $t4, 0x3f
  move  $a0, $t1
  jal   romCopy
   move  $a1, $v1
  lui   $a0, %hi(dword_CODE_bss_80069588)
  lui   $a1, %hi(dword_CODE_bss_8006958C)
  lw    $a1, %lo(dword_CODE_bss_8006958C)($a1)
  jal   sub_GAME_7F01B0E0
   lw    $a0, %lo(dword_CODE_bss_80069588)($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F008E80
  li    $t6, 2
  lui   $at, %hi(D_8002A7D4)
  sb    $t6, %lo(D_8002A7D4)($at)
  li    $at, 0x44700000 # 960.000000
  mtc1  $at, $f4
  addiu $sp, $sp, -0x60
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  mtc1  $zero, $f0
  li    $at, 0x41000000 # 8.000000
  mtc1  $at, $f8
  li    $at, 0x43800000 # 256.000000
  mtc1  $at, $f10
  sw    $a0, 0x60($sp)
  sw    $a1, 0x64($sp)
  sw    $ra, 0x2c($sp)
  lui   $a0, %hi(matrix_buffer_gunbarrel_0)
  mfc1  $a1, $f0
  mfc1  $a3, $f0
  sw    $s1, 0x28($sp)
  sw    $s0, 0x24($sp)
  lw    $a0, %lo(matrix_buffer_gunbarrel_0)($a0)
  lui   $a2, 0x44a0
  swc1  $f4, 0x10($sp)
  swc1  $f6, 0x14($sp)
  swc1  $f8, 0x18($sp)
  jal   guOrtho
   swc1  $f10, 0x1c($sp)
  li    $at, 0x43F10000 # 482.000000
  mtc1  $at, $f0
  li    $at, 0xC1F00000 # -30.000000
  mtc1  $at, $f16
  lui   $at, %hi(x)
  lw    $v0, 0x60($sp)
  swc1  $f16, %lo(x)($at)
  lui   $at, %hi(y)
  swc1  $f0, %lo(y)($at)
  li    $at, 0xC2C80000 # -100.000000
  mtc1  $at, $f18
  lui   $at, %hi(dword_CODE_bss_8006957C)
  lw    $t8, 0x64($sp)
  swc1  $f18, %lo(dword_CODE_bss_8006957C)($at)
  lui   $at, %hi(dword_CODE_bss_80069580)
  swc1  $f0, %lo(dword_CODE_bss_80069580)($at)
  lui   $s0, %hi(dword_CODE_bss_80069550)
  lui   $at, %hi(word_CODE_bss_80069584)
  li    $t7, 66
  addiu $s0, %lo(dword_CODE_bss_80069550) # addiu $s0, $s0, -0x6ab0
  sh    $t7, %lo(word_CODE_bss_80069584)($at)
  sw    $v0, ($s0)
  addiu $v0, $v0, 0x200
  addiu $t9, $t8, -0x200
  sw    $t9, 0x64($sp)
  sw    $v0, 0x60($sp)
  lw    $a0, ($s0)
  jal   sub_GAME_7F01BAE0
   li    $a1, 30
  lw    $v1, 0x60($sp)
  lw    $t0, 0x64($sp)
  lui   $v0, %hi(dword_CODE_bss_80069554)
  addiu $v0, %lo(dword_CODE_bss_80069554) # addiu $v0, $v0, -0x6aac
  lw    $a1, ($s0)
  sw    $v1, ($v0)
  lui   $at, 0x8000
  addiu $v1, $v1, 0x100
  addiu $t1, $t0, -0x100
  sw    $t1, 0x64($sp)
  sw    $v1, 0x60($sp)
  lw    $a0, ($v0)
  li    $a2, 30
  jal   sub_GAME_7F01BFF8
   addu  $a1, $a1, $at
  addiu $a0, $sp, 0x60
  jal   sub_GAME_7F008DE4
   addiu $a1, $sp, 0x64
  lui   $t3, %hi(D_8002A8A8) 
  addiu $t3, %lo(D_8002A8A8) # addiu $t3, $t3, -0x5758
  lw    $at, ($t3)
  addiu $t2, $sp, 0x50
  lw    $t6, 4($t3)
  sw    $at, ($t2)
  lw    $at, 8($t3)
  lui   $s1, (0x00012C00 >> 16) # lui $s1, 1
  ori   $s1, (0x00012C00 & 0xFFFF) # ori $s1, $s1, 0x2c00
  sw    $t6, 4($t2)
  sw    $at, 8($t2)
  lw    $a1, 0x60($sp)
  move  $a2, $s1
  jal   sub_GAME_7F0CBAF4
   addiu $a0, $sp, 0x40
  lw    $a2, 0x60($sp)
  lw    $a3, 0x64($sp)
  lui   $s0, %hi(c_item_entries)
  addiu $s0, %lo(c_item_entries) # addiu $s0, $s0, -0x21f0
  addiu $t7, $sp, 0x40
  addu  $a2, $a2, $s1
  subu  $a3, $a3, $s1
  sw    $a3, 0x64($sp)
  sw    $a2, 0x60($sp)
  sw    $t7, 0x10($sp)
  lw    $a0, 0x64($s0)
  jal   load_object_fill_header
   lw    $a1, 0x68($s0)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 0x68($s0)
  addiu $v1, $v0, 0x3f
  lw    $a2, 0x60($sp)
  lw    $a3, 0x64($sp)
  ori   $t8, $v1, 0x3f
  xori  $t9, $t8, 0x3f
  addiu $t0, $sp, 0x40
  addu  $a2, $a2, $t9
  subu  $a3, $a3, $t9
  sw    $a3, 0x64($sp)
  sw    $a2, 0x60($sp)
  sw    $t0, 0x10($sp)
  lw    $a0, 0x618($s0)
  jal   load_object_fill_header
   lw    $a1, 0x61c($s0)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 0x61c($s0)
  addiu $v1, $v0, 0x3f
  lw    $t4, 0x64($sp)
  lw    $t3, 0x60($sp)
  ori   $t1, $v1, 0x3f
  xori  $t5, $t1, 0x3f
  subu  $t2, $t4, $t5
  addu  $t6, $t3, $t5
  sw    $t2, 0x64($sp)
  sw    $t6, 0x60($sp)
  li    $a0, 5
  li    $a1, 78
  lw    $a2, 0x64($s0)
  lw    $a3, 0x618($s0)
  jal   sub_GAME_7F0234A8
   sw    $zero, 0x10($sp)
  lui   $s1, %hi(D_8002A7F4)
  addiu $s1, %lo(D_8002A7F4) # addiu $s1, $s1, -0x580c
  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
  sw    $v0, ($s1)
  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
  jal   set_obj_instance_controller_scale
   move  $a0, $v0
  lw    $a0, ($s1)
  jal   sub_GAME_7F06CE84
   lui   $a1, 0x3f80
  lw    $a0, ($s1)
  jal   setsuboffset
   addiu $a1, $sp, 0x50
  lw    $a0, ($s1)
  jal   setsubroty
   li    $a1, 0
  lw    $a0, ($s1)
  lui   $a1, 0x3f00
  jal   sub_GAME_7F06FF18
   li    $a2, 0
  lui   $t7, %hi(ptr_animation_table) 
  lw    $t7, %lo(ptr_animation_table)($t7)
  lui   $t8, 0
  addiu $t8, $t8, 0x4144
  addu  $a1, $t7, $t8
  lhu   $v1, 4($a1)
  addiu $v0, $v1, -0x44
  bgezl $v0, .L7F009124
   mtc1  $v0, $f4
  addu  $v0, $v0, $v1
.L7F009118:
  bltzl $v0, .L7F009118
   addu  $v0, $v0, $v1
  mtc1  $v0, $f4
.L7F009124:
  lui   $at, %hi(D_8004F2DC)
  lwc1  $f6, %lo(D_8004F2DC)($at)
  cvt.s.w $f4, $f4
  mtc1  $zero, $f8
  lw    $a0, ($s1)
  move  $a2, $zero
  swc1  $f6, 0x10($sp)
  swc1  $f8, 0x14($sp)
  mfc1  $a3, $f4
  jal   sub_GAME_7F06FCA8
   nop   
  lui   $s0, %hi(PitemZ_entries)
  addiu $s0, %lo(PitemZ_entries) # addiu $s0, $s0, -0x5dd8
  addiu $t9, $sp, 0x40
  sw    $t9, 0x10($sp)
  lw    $a0, 0x8f4($s0)
  lw    $a1, 0x8f8($s0)
  lw    $a2, 0x60($sp)
  jal   load_object_fill_header
   lw    $a3, 0x64($sp)
  jal   get_pc_buffer_remaining_value
   lw    $a0, 0x8f8($s0)
  addiu $v1, $v0, 0x3f
  lw    $t5, 0x64($sp)
  lw    $t2, 0x60($sp)
  ori   $t0, $v1, 0x3f
  xori  $t1, $t0, 0x3f
  subu  $t4, $t5, $t1
  addu  $t3, $t2, $t1
  sw    $t4, 0x64($sp)
  sw    $t3, 0x60($sp)
  jal   set_objuse_flag_compute_grp_nums_set_obj_loaded
   lw    $a0, 0x8f4($s0)
  jal   get_obj_instance_controller_for_header
   lw    $a0, 0x8f4($s0)
  lui   $s0, %hi(D_8002A7F8)
  addiu $s0, %lo(D_8002A7F8) # addiu $s0, $s0, -0x5808
  lui   $a1, (0x3E404CEC >> 16) # lui $a1, 0x3e40
  sw    $v0, ($s0)
  ori   $a1, (0x3E404CEC & 0xFFFF) # ori $a1, $a1, 0x4cec
  jal   set_obj_instance_controller_scale
   move  $a0, $v0
  lw    $t6, ($s1)
  lw    $t7, ($s0)
  lui   $at, %hi(dword_CODE_bss_80069594)
  sw    $t6, 0x18($t7)
  lw    $t8, ($s1)
  lw    $t5, ($s0)
  lw    $t9, 8($t8)
  lw    $t0, 8($t9)
  lw    $t1, 0xc($t0)
  sw    $t1, 0x1c($t5)
  lw    $ra, 0x2c($sp)
  lw    $s1, 0x28($sp)
  lw    $s0, 0x24($sp)
  sw    $zero, %lo(dword_CODE_bss_80069594)($at)
  jr    $ra
   addiu $sp, $sp, 0x60
");

asm(R"
glabel sub_GAME_7F00920C
  lui   $a0, %hi(D_8002A7F4)
  lw    $a0, %lo(D_8002A7F4)($a0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $a0, .L7F00922C
   nop   
  jal   set_aircraft_obj_inst_scale_to_zero
   nop   
.L7F00922C:
  lui   $a0, %hi(D_8002A7F8)
  lw    $a0, %lo(D_8002A7F8)($a0)
  beql  $a0, $zero, .L7F009248
   lw    $ra, 0x14($sp)
  jal   set_obj_instance_scale_to_zero
   nop   
  lw    $ra, 0x14($sp)
.L7F009248:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel jpt_8004F2E0
    .word .L7F0092A4
    .word .L7F009344
    .word .L7F009428
    .word .L7F00949C
    .word .L7F009550
    .word .L7F009610
    .word .L7F0096D8
glabel D_8004F2FC
.word 0x44adc000
glabel D_8004F300
.word 0x449f8000
glabel D_8004F304
.word 0x40ba2fbd
.text
glabel sub_GAME_7F009254
  lui   $v0, %hi(D_8002A7D0)
  addiu $v0, %lo(D_8002A7D0) # addiu $v0, $v0, -0x5830
  lw    $t6, ($v0)
  li    $t7, 1
  lui   $t9, %hi(D_8002A7D4) 
  subu  $t8, $t7, $t6
  sw    $t8, ($v0)
  lbu   $t9, %lo(D_8002A7D4)($t9)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  addiu $t0, $t9, -2
  sltiu $at, $t0, 7
  beqz  $at, .L7F009730
   move  $a1, $a0
  sll   $t0, $t0, 2
  lui   $at, %hi(jpt_8004F2E0)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_8004F2E0)($at)
  jr    $t0
   nop   
.L7F0092A4:
  jal   something_with_gunbarrel_and_rareware_logo_matrix_manip
   move  $a0, $a1
  lui   $a3, %hi(x)
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  li    $at, 0x40C00000 # 6.000000
  mtc1  $at, $f6
  lwc1  $f4, ($a3)
  lui   $v1, %hi(word_CODE_bss_80069584)
  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
  add.s $f8, $f4, $f6
  lh    $a0, ($v1)
  move  $a1, $v0
  bgez  $a0, .L7F009300
   swc1  $f8, ($a3)
  li    $at, 0x41400000 # 12.000000
  mtc1  $at, $f10
  lwc1  $f0, ($a3)
  li    $t1, 200
  sh    $t1, ($v1)
  sub.s $f16, $f0, $f10
  lui   $at, %hi(dword_CODE_bss_8006957C)
  b     .L7F00930C
   swc1  $f16, %lo(dword_CODE_bss_8006957C)($at)
.L7F009300:
  addiu $t2, $a0, -6
  sh    $t2, ($v1)
  lwc1  $f0, ($a3)
.L7F00930C:
  lui   $at, %hi(D_8004F2FC)
  lwc1  $f18, %lo(D_8004F2FC)($at)
  c.lt.s $f18, $f0
  nop   
  bc1f  .L7F009730
   lui   $t3, %hi(D_8002A7D4) 
  lbu   $t3, %lo(D_8002A7D4)($t3)
  lui   $at, %hi(D_8002A7D4)
  addiu $t4, $t3, 1
  sb    $t4, %lo(D_8002A7D4)($at)
  lui   $at, %hi(D_8004F300)
  lwc1  $f4, %lo(D_8004F300)($at)
  b     .L7F009730
   swc1  $f4, ($a3)
.L7F009344:
  lui   $t7, 0x100
  addiu $t7, $t7, 0
  move  $v0, $a1
  lui   $t5, 0x600
  sw    $t5, ($v0)
  sw    $t7, 4($v0)
  jal   insert_imageDL
   addiu $a0, $a1, 8
  jal   insert_imageDL
   move  $a0, $v0
  jal   insert_imageDL
   move  $a0, $v0
  jal   insert_imageDL
   move  $a0, $v0
  jal   insert_imageDL
   move  $a0, $v0
  jal   insert_sniper_sight_eye_intro
   move  $a0, $v0
  jal   insert_sight_backdrop_eye_intro
   move  $a0, $v0
  lui   $a3, %hi(x)
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  li    $at, 0x44160000 # 600.000000
  mtc1  $at, $f6
  lwc1  $f0, ($a3)
  move  $a1, $v0
  c.lt.s $f0, $f6
  nop   
  bc1f  .L7F0093D4
   nop   
  jal   insert_bond_eye_intro
   move  $a0, $v0
  lui   $a3, %hi(x)
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  lwc1  $f0, ($a3)
  move  $a1, $v0
.L7F0093D4:
  lui   $at, %hi(D_8004F304)
  lwc1  $f8, %lo(D_8004F304)($at)
  li    $at, 0xC2A00000 # -80.000000
  mtc1  $at, $f16
  sub.s $f10, $f0, $f8
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lui   $t6, %hi(D_8002A7D4) 
  swc1  $f10, ($a3)
  lwc1  $f18, ($a3)
  c.le.s $f18, $f16
  nop   
  bc1fl .L7F009734
   lw    $ra, 0x14($sp)
  lbu   $t6, %lo(D_8002A7D4)($t6)
  lui   $at, %hi(D_8002A7D4)
  li    $t9, 20
  addiu $t8, $t6, 1
  sb    $t8, %lo(D_8002A7D4)($at)
  b     .L7F009730
   sw    $t9, ($a2)
.L7F009428:
  jal   insert_sniper_sight_eye_intro
   move  $a0, $a1
  jal   insert_sight_backdrop_eye_intro
   move  $a0, $v0
  jal   insert_bond_eye_intro
   move  $a0, $v0
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $t0, ($a2)
  move  $a1, $v0
  lui   $t3, %hi(D_8002A7D4) 
  addiu $t1, $t0, -1
  bgez  $t1, .L7F009730
   sw    $t1, ($a2)
  lbu   $t3, %lo(D_8002A7D4)($t3)
  lui   $at, %hi(D_8002A7D4)
  move  $a0, $zero
  addiu $t4, $t3, 1
  sb    $t4, %lo(D_8002A7D4)($at)
  jal   die_blood_image_routine
   sw    $v0, 0x18($sp)
  lui   $a2, %hi(intro_eye_counter)
  lui   $at, %hi(intro_state_blood_animation)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  sw    $zero, %lo(intro_state_blood_animation)($at)
  li    $t5, 1
  lw    $a1, 0x18($sp)
  b     .L7F009730
   sw    $t5, ($a2)
.L7F00949C:
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $t7, ($a2)
  li    $a0, 1
  addiu $t6, $t7, -1
  bnez  $t6, .L7F0094DC
   sw    $t6, ($a2)
  jal   die_blood_image_routine
   sw    $a1, 0x18($sp)
  lui   $a2, %hi(intro_eye_counter)
  lui   $at, %hi(intro_state_blood_animation)
  sw    $v0, %lo(intro_state_blood_animation)($at)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  li    $t9, 2
  lw    $a1, 0x18($sp)
  sw    $t9, ($a2)
.L7F0094DC:
  jal   insert_sniper_sight_eye_intro
   move  $a0, $a1
  jal   insert_sight_backdrop_eye_intro
   move  $a0, $v0
  jal   insert_bond_eye_intro
   move  $a0, $v0
  jal   sub_GAME_7F01C400
   move  $a0, $v0
  lui   $t0, %hi(intro_state_blood_animation) 
  lw    $t0, %lo(intro_state_blood_animation)($t0)
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  beqz  $t0, .L7F009730
   move  $a1, $v0
  lui   $t1, %hi(D_8002A7D4) 
  lbu   $t1, %lo(D_8002A7D4)($t1)
  lui   $a3, %hi(x)
  lui   $at, %hi(D_8002A7D4)
  addiu $t2, $t1, 1
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  sb    $t2, %lo(D_8002A7D4)($at)
  lwc1  $f4, ($a3)
  lui   $v1, %hi(word_CODE_bss_80069584)
  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
  sh    $zero, ($v1)
  lui   $at, %hi(dword_CODE_bss_8006957C)
  swc1  $f4, %lo(dword_CODE_bss_8006957C)($at)
  b     .L7F009730
   sw    $zero, ($a2)
.L7F009550:
  lui   $v1, %hi(word_CODE_bss_80069584)
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
  lh    $t3, ($v1)
  lw    $t5, ($a2)
  sw    $a1, 0x18($sp)
  addiu $t4, $t3, 0x38e
  addiu $t7, $t5, 1
  sh    $t4, ($v1)
  sw    $t7, ($a2)
  jal   sins
   andi  $a0, $t4, 0xffff
  mtc1  $v0, $f6
  li    $at, 0x42800000 # 64.000000
  mtc1  $at, $f10
  cvt.s.w $f8, $f6
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f18
  lui   $at, %hi(dword_CODE_bss_8006957C)
  lwc1  $f6, %lo(dword_CODE_bss_8006957C)($at)
  lui   $a3, %hi(x)
  mul.s $f16, $f8, $f10
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  lw    $a0, 0x18($sp)
  div.s $f4, $f16, $f18
  add.s $f8, $f4, $f6
  jal   insert_sniper_sight_eye_intro
   swc1  $f8, ($a3)
  jal   insert_sight_backdrop_eye_intro
   move  $a0, $v0
  jal   insert_bond_eye_intro
   move  $a0, $v0
  jal   sub_GAME_7F01CA18
   move  $a0, $v0
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $t6, ($a2)
  move  $a1, $v0
  lui   $v0, %hi(D_8002A7D4)
  slti  $at, $t6, 0x6c
  bnez  $at, .L7F009730
   addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
  lbu   $t8, ($v0)
  sw    $zero, ($a2)
  addiu $t9, $t8, 1
  b     .L7F009730
   sb    $t9, ($v0)
.L7F009610:
  lui   $v1, %hi(word_CODE_bss_80069584)
  addiu $v1, %lo(word_CODE_bss_80069584) # addiu $v1, $v1, -0x6a7c
  lh    $t0, ($v1)
  sw    $a1, 0x18($sp)
  addiu $t1, $t0, 0x38e
  sh    $t1, ($v1)
  jal   sins
   andi  $a0, $t1, 0xffff
  mtc1  $v0, $f10
  li    $at, 0x42800000 # 64.000000
  mtc1  $at, $f18
  cvt.s.w $f16, $f10
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f6
  lui   $at, %hi(dword_CODE_bss_8006957C)
  lwc1  $f10, %lo(dword_CODE_bss_8006957C)($at)
  lui   $a3, %hi(x)
  mul.s $f4, $f16, $f18
  addiu $a3, %lo(x) # addiu $a3, $a3, -0x6a8c
  lw    $a0, 0x18($sp)
  div.s $f8, $f4, $f6
  add.s $f16, $f8, $f10
  jal   insert_sniper_sight_eye_intro
   swc1  $f16, ($a3)
  jal   insert_sight_backdrop_eye_intro
   move  $a0, $v0
  jal   insert_bond_eye_intro
   move  $a0, $v0
  jal   sub_GAME_7F01CA18
   move  $a0, $v0
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $t2, ($a2)
  move  $a0, $v0
  addiu $a1, $t2, 8
  jal   sub_GAME_7F007E70
   sw    $a1, ($a2)
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $t4, ($a2)
  move  $a1, $v0
  lui   $v0, %hi(D_8002A7D4)
  slti  $at, $t4, 0xf7
  bnez  $at, .L7F009730
   addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
  lbu   $t5, ($v0)
  sw    $zero, ($a2)
  addiu $t7, $t5, 1
  b     .L7F009730
   sb    $t7, ($v0)
.L7F0096D8:
  lui   $t8, 0x100
  addiu $t8, $t8, 0
  move  $v0, $a1
  lui   $t6, 0x600
  sw    $t6, ($v0)
  sw    $t8, 4($v0)
  jal   insert_imageDL
   addiu $a0, $a1, 8
  lui   $a2, %hi(intro_eye_counter)
  addiu $a2, %lo(intro_eye_counter) # addiu $a2, $a2, -0x5760
  lw    $v1, ($a2)
  move  $a1, $v0
  lui   $v0, %hi(D_8002A7D4)
  slti  $a0, $v1, 0x1e
  addiu $t9, $v1, 1
  bnez  $a0, .L7F009730
   sw    $t9, ($a2)
  addiu $v0, %lo(D_8002A7D4) # addiu $v0, $v0, -0x582c
  lbu   $t0, ($v0)
  sw    $zero, ($a2)
  addiu $t1, $t0, 1
  sb    $t1, ($v0)
def_7F00929C:
.L7F009730:
  lw    $ra, 0x14($sp)
.L7F009734:
  addiu $sp, $sp, 0x18
  move  $v0, $a1
  jr    $ra
   nop   
");

bool sub_GAME_7F009744(void) {
  return (*(unsigned char *)&D_8002A7D4 ^ 9) < (unsigned int)1;
}
