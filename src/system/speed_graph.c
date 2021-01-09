// This file contains code to draw speed graph.
#include <gbi.h>

/*   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    | Snippet of building glist buffers   |
    |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|

== H file ==
#define	GLIST_LEN	2048 // GE seems to be 266

/*
 * Layout of dynamic data.
 *
 * This structure holds the things which change per frame. It is advantageous
 * to keep dynamic data together so that we may selectively write back dirty
 * data cache lines to DRAM prior to processing by the RCP.
 *
 * /
typedef struct {
        Mtx	projection;
        Mtx	modeling;
        Mtx	modeling2;
        Mtx	viewing;
        LookAt	lookat;
        Hilite	hilite;
        Lightsn	light;          //Oh interesting, since we found this and
LookAt, it seems dynamic gfx should astart right after. Gfx
glist[GLIST_LEN]; } Dynamic;

extern Dynamic	dynamic;

== H file End ==

/*
 * global variables
 *
Gfx		*glistp;	/* RSP display list pointer * /
//Dynamic		dynamic;	/* dynamic data * /
/ *
 * Double-buffered dynamic segments
 * /
Dynamic	dynamic[2];
...

// some function()
{
    ...
    int		current = 0;
    dynamicp = &dynamic[current];
    glistp = dynamicp->glist;
    //example gfx build
    gSPSegment(glistp++, 0, 0x0); // glist++ ready for next instruction (held in
dynamic 1 or 2)
}
*/

/* tempory types confirm me */
int dword_CODE_bss_8005F3F0[4]; // Gfx Tiles_Setup? oh... unless thats what the
                                // next 2 are... the first command I recognised
                                // did start at 8005f400...
// dynamic glist, though it lacks the format above...
Gfx displaylist_0[266];
Gfx displaylist_1[266];
int displaylist_bank; // 0 or 1? current?
int dword_CODE_bss_800604A4;
unsigned int dword_CODE_bss_800604A8;
unsigned int dword_CODE_bss_800604AC;
int dword_CODE_bss_800604B0[0xC0];
int dword_CODE_bss_800607B0;
int dword_CODE_bss_800607B4;
int dword_CODE_bss_800607B8;
int dword_CODE_bss_800607BC;
int dword_CODE_bss_800607C0;
int dword_CODE_bss_800607C4;
int dword_CODE_bss_800607C8;
int dword_CODE_bss_800607CC;
int dword_CODE_bss_800607D0;
int dword_CODE_bss_800607D4;
int dword_CODE_bss_800607D8;
int dword_CODE_bss_800607DC;

int D_800231D0 = 0;
int D_800231D4[] = {0, 0,          2,          0,          1, 0,         2,
                    0, 2,          0xFF000000, 2,          0, 3,         0x9200,
                    4, 0xFFFFFFFF, 4,          0xDB000000, 4, 0xFFFFFFFF};

int D_80023224 = 0;
int D_80023228 = 0;
int D_8002322C = 0;
int counterforframes = 0;
int D_80023234 = 1;

const char aUtz2_0f[] = "utz %2.0f%%\n";
const char aRsp2_0f[] = "rsp %2.0f%%\n";
const char aTex2_0f[] = "tex %2.0f%%";
const char a2dHz[] = "%2d hz";
const char a2dFrames[] = "%2d frames";
const char a2d[] = " [%2d]";
const char asc_D_80028468[] = "     ";
const char aIL0[] = "I=l0";

// Display list generator.
asm(R"
glabel displaylist_related
  lui   $a0, %hi(displaylist_0)
  addiu $a0, %lo(displaylist_0) # addiu $a0, $a0, -0xc00
  lui   $a2, 0xb800
  sw    $a2, ($a0)
  sw    $zero, 4($a0)
  sw    $a2, 0x850($a0)
  sw    $zero, 0x854($a0)
  addiu $sp, $sp, -0x18
  lui   $at, %hi(displaylist_bank)
  lui   $v1, %hi(dword_CODE_bss_800607B0)
  lui   $v0, %hi(dword_CODE_bss_800607D0)
  lui   $a1, %hi(dword_CODE_bss_800607DC)
  sw    $ra, 0x14($sp)
  sw    $zero, %lo(displaylist_bank)($at)
  addiu $a1, %lo(dword_CODE_bss_800607DC) # addiu $a1, $a1, 0x7dc
  addiu $v0, %lo(dword_CODE_bss_800607D0) # addiu $v0, $v0, 0x7d0
  addiu $v1, %lo(dword_CODE_bss_800607B0) # addiu $v1, $v1, 0x7b0
  li    $a0, 1
.L70002778:
  addiu $v0, $v0, 4
  addiu $v1, $v1, 4
  sw    $zero, -4($v1)
  bne   $v0, $a1, .L70002778
   sw    $a0, -4($v0)
  jal   video_related_2
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel video_related_1
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   osGetCount
   nop   
  lui   $at, %hi(dword_CODE_bss_800604A8)
  sw    $v0, %lo(dword_CODE_bss_800604A8)($at)
  lui   $v0, %hi(dword_CODE_bss_800607DC)
  lui   $a0, %hi(dword_CODE_bss_800607C0)
  lui   $v1, %hi(dword_CODE_bss_800607D0)
  addiu $v1, %lo(dword_CODE_bss_800607D0) # addiu $v1, $v1, 0x7d0
  addiu $a0, %lo(dword_CODE_bss_800607C0) # addiu $a0, $a0, 0x7c0
  addiu $v0, %lo(dword_CODE_bss_800607DC) # addiu $v0, $v0, 0x7dc
.L700027D4:
  lw    $t6, ($v1)
  addiu $v1, $v1, 4
  addiu $a0, $a0, 4
  addiu $t7, $t6, 0x1f
  bgez  $t7, .L700027F8
   andi  $t8, $t7, 0x1f
  beqz  $t8, .L700027F8
   nop   
  addiu $t8, $t8, -0x20
.L700027F8:
  bne   $v1, $v0, .L700027D4
   sw    $t8, -4($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel video_related_2
  lui   $t6, %hi(dword_CODE_bss_800604A8) 
  lw    $t6, %lo(dword_CODE_bss_800604A8)($t6)
  lui   $at, %hi(dword_CODE_bss_800604A4)
  lui   $v1, %hi(dword_CODE_bss_800607B0)
  lui   $a0, %hi(dword_CODE_bss_800607C0)
  lui   $v0, %hi(dword_CODE_bss_800607CC)
  addiu $v0, %lo(dword_CODE_bss_800607CC) # addiu $v0, $v0, 0x7cc
  addiu $a0, %lo(dword_CODE_bss_800607C0) # addiu $a0, $a0, 0x7c0
  addiu $v1, %lo(dword_CODE_bss_800607B0) # addiu $v1, $v1, 0x7b0
  sw    $t6, %lo(dword_CODE_bss_800604A4)($at)
.L70002838:
  lw    $t7, ($a0)
  addiu $a0, $a0, 4
  addiu $v1, $v1, 4
  bne   $a0, $v0, .L70002838
   sw    $t7, -4($v1)
  jr    $ra
   nop   
");

asm(R"
glabel video_related_3
  addiu $sp, $sp, -0x40
  sw    $ra, 0x14($sp)
  sw    $a0, 0x40($sp)
  jal   osSetIntMask
   li    $a0, 1
  lw    $t1, 0x40($sp)
  lui   $t6, %hi(dword_CODE_bss_800607D0) 
  addiu $t6, %lo(dword_CODE_bss_800607D0) # addiu $t6, $t6, 0x7d0
  andi  $a3, $t1, 0xffff
  sll   $v1, $a3, 2
  addu  $t0, $v1, $t6
  li    $at, 3
  sra   $a0, $t1, 0x10
  sw    $v0, 0x34($sp)
  move  $a2, $a0
  bne   $a0, $at, .L700028B0
   lw    $a1, ($t0)
  lui   $a2, %hi(dword_CODE_bss_8005F3F0)
  addu  $a2, $a2, $v1
  lw    $a2, %lo(dword_CODE_bss_8005F3F0)($a2)
  ori   $t7, $a2, 0x8000
  b     .L700028D0
   move  $a2, $t7
.L700028B0:
  li    $at, 6
  bnel  $a0, $at, .L700028D4
   sll   $t9, $a3, 8
  lui   $a2, %hi(dword_CODE_bss_8005F3F0)
  addu  $a2, $a2, $v1
  lw    $a2, %lo(dword_CODE_bss_8005F3F0)($a2)
  andi  $t8, $a2, 0x7fff
  move  $a2, $t8
.L700028D0:
  sll   $t9, $a3, 8
.L700028D4:
  sll   $t2, $a1, 3
  lui   $t4, %hi(dword_CODE_bss_800604B0) 
  lui   $t5, %hi(dword_CODE_bss_8005F3F0) 
  addiu $t4, %lo(dword_CODE_bss_800604B0) # addiu $t4, $t4, 0x4b0
  addu  $t3, $t9, $t2
  addiu $t5, %lo(dword_CODE_bss_8005F3F0) # addiu $t5, $t5, -0xc10
  addu  $v0, $t3, $t4
  addu  $t6, $v1, $t5
  sw    $v0, 0x2c($sp)
  sw    $a2, ($v0)
  sw    $t6, 0x24($sp)
  sw    $a1, 0x30($sp)
  sw    $a2, 0x38($sp)
  jal   osGetCount
   sw    $t0, 0x1c($sp)
  lw    $t7, 0x2c($sp)
  lw    $a1, 0x30($sp)
  lw    $a2, 0x38($sp)
  lw    $t0, 0x1c($sp)
  sw    $v0, 4($t7)
  lw    $t8, 0x24($sp)
  addiu $a1, $a1, 1
  slti  $at, $a1, 0x20
  bnez  $at, .L7000293C
   sw    $a2, ($t8)
  move  $a1, $zero
.L7000293C:
  sw    $a1, ($t0)
  jal   osSetIntMask
   lw    $a0, 0x34($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x40
  jr    $ra
   nop   
");

// Draw "display speed" display.
// Accepts: A0=p->display list.
asm(R"
glabel display_speed_graph
  lui   $v1, %hi(D_80048498)
  lui   $t6, %hi(D_80023228) 
  lw    $v1, %lo(D_80048498)($v1)
  lw    $t6, %lo(D_80023228)($t6)
  lui   $v0, %hi(D_80023224)
  lw    $v0, %lo(D_80023224)($v0)
  addiu $sp, $sp, -0x48
  slt   $at, $t6, $v1
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  beqz  $at, .L70002990
   addu  $v0, $v0, $v1
  lui   $at, %hi(D_80023228)
  sw    $v1, %lo(D_80023228)($at)
.L70002990:
  lui   $at, %hi(D_80023224)
  sw    $v0, %lo(D_80023224)($at)
  sltiu $at, $v0, 0x15
  bnez  $at, .L70002C8C
   lui   $at, %hi(D_80023224)
  sw    $v0, %lo(D_80023224)($at)
  sltiu $at, $v0, 0x15
  bnez  $at, .L700029C8
   addiu $v0, $v0, -0x14
.L700029B4:
  sltiu $at, $v0, 0x15
  beql  $at, $zero, .L700029B4
   addiu $v0, $v0, -0x14
  lui   $at, %hi(D_80023224)
  sw    $v0, %lo(D_80023224)($at)
.L700029C8:
  jal   get_counters
   sw    $a0, 0x48($sp)
  sw    $v0, 0x44($sp)
  li    $a0, 255
  li    $a1, 255
  li    $a2, 255
  jal   set_debug_text_color
   li    $a3, 255
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $zero
  jal   set_color_speedgraph
   li    $a3, 255
  li    $a0, 8
  jal   set_final_debug_text_positions
   li    $a1, 5
  lw    $v0, 0x44($sp)
  addiu $s0, $sp, 0x30
  lui   $a1, %hi(aUtz2_0f)
  lw    $t7, 4($v0)
  lw    $t8, 0xc($v0)
  addiu $a1, %lo(aUtz2_0f) # addiu $a1, $a1, -0x7be0
  move  $a0, $s0
  subu  $t9, $t7, $t8
  mtc1  $t9, $f4
  bgez  $t9, .L70002A44
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L70002A44:
  lw    $t0, ($v0)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f10
  mtc1  $t0, $f18
  mul.s $f16, $f6, $f10
  bgez  $t0, .L70002A70
   cvt.s.w $f4, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f4, $f4, $f8
.L70002A70:
  div.s $f6, $f16, $f4
  cvt.d.s $f10, $f6
  mfc1  $a3, $f10
  mfc1  $a2, $f11
  jal   sprintf
   nop   
  jal   write_string_stdout
   move  $a0, $s0
  li    $a0, 8
  jal   set_final_debug_text_positions
   li    $a1, 6
  lw    $v1, 0x44($sp)
  lui   $a1, %hi(aRsp2_0f)
  addiu $a1, %lo(aRsp2_0f) # addiu $a1, $a1, -0x7bd0
  lw    $v0, ($v1)
  lw    $t1, 4($v1)
  move  $a0, $s0
  mtc1  $v0, $f10
  subu  $t2, $v0, $t1
  mtc1  $t2, $f18
  bgez  $t2, .L70002AD8
   cvt.s.w $f8, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f8, $f8, $f16
.L70002AD8:
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f4
  cvt.s.w $f18, $f10
  mul.s $f6, $f8, $f4
  bgez  $v0, .L70002AFC
   li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f16
  nop   
  add.s $f18, $f18, $f16
.L70002AFC:
  div.s $f8, $f6, $f18
  cvt.d.s $f4, $f8
  mfc1  $a3, $f4
  mfc1  $a2, $f5
  jal   sprintf
   nop   
  jal   write_string_stdout
   move  $a0, $s0
  li    $a0, 8
  jal   set_final_debug_text_positions
   li    $a1, 7
  lw    $t3, 0x44($sp)
  lui   $a1, %hi(aTex2_0f)
  addiu $a1, %lo(aTex2_0f) # addiu $a1, $a1, -0x7bc0
  lw    $t4, 0xc($t3)
  move  $a0, $s0
  mtc1  $t4, $f10
  bgez  $t4, .L70002B58
   cvt.s.w $f16, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f16, $f16, $f6
.L70002B58:
  lw    $t5, ($t3)
  li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f18
  mtc1  $t5, $f4
  mul.s $f8, $f16, $f18
  bgez  $t5, .L70002B84
   cvt.s.w $f10, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f6
  nop   
  add.s $f10, $f10, $f6
.L70002B84:
  div.s $f16, $f8, $f10
  cvt.d.s $f18, $f16
  mfc1  $a3, $f18
  mfc1  $a2, $f19
  jal   sprintf
   nop   
  jal   write_string_stdout
   move  $a0, $s0
  li    $a0, 28
  jal   set_final_debug_text_positions
   li    $a1, 5
  lui   $v1, %hi(D_80048498)
  lw    $v1, %lo(D_80048498)($v1)
  move  $a0, $s0
  lui   $a1, %hi(a2dHz)
  bnez  $v1, .L70002BD0
   li    $t6, 60
  b     .L70002BFC
   move  $a2, $zero
.L70002BD0:
  div   $zero, $t6, $v1
  mflo  $a2
  bnez  $v1, .L70002BE4
   nop   
  break 7
.L70002BE4:
  li    $at, -1
  bne   $v1, $at, .L70002BFC
   lui   $at, 0x8000
  bne   $t6, $at, .L70002BFC
   nop   
  break 6
.L70002BFC:
  jal   sprintf
   addiu $a1, %lo(a2dHz) # addiu $a1, $a1, -0x7bb4
  jal   write_string_stdout
   move  $a0, $s0
  li    $a0, 28
  jal   set_final_debug_text_positions
   li    $a1, 6
  lui   $a1, %hi(a2dFrames)
  lui   $a2, %hi(D_80048498)
  lw    $a2, %lo(D_80048498)($a2)
  addiu $a1, %lo(a2dFrames) # addiu $a1, $a1, -0x7bac
  jal   sprintf
   move  $a0, $s0
  jal   write_string_stdout
   move  $a0, $s0
  lui   $t7, %hi(D_80023228) 
  lui   $t8, %hi(D_80048498) 
  lw    $t8, %lo(D_80048498)($t8)
  lw    $t7, %lo(D_80023228)($t7)
  move  $a0, $s0
  lui   $a1, %hi(asc_D_80028468)
  beq   $t7, $t8, .L70002C70
   move  $a2, $t7
  lui   $a1, %hi(a2d)
  addiu $a1, %lo(a2d) # addiu $a1, $a1, -0x7ba0
  jal   sprintf
   move  $a0, $s0
  b     .L70002C78
   nop   
.L70002C70:
  jal   sprintf
   addiu $a1, $a1, %lo(asc_D_80028468)
.L70002C78:
  jal   write_string_stdout
   move  $a0, $s0
  lui   $at, %hi(D_80023228)
  sw    $zero, %lo(D_80023228)($at)
  lw    $a0, 0x48($sp)
.L70002C8C:
  lui   $t9, 0x600
  sw    $t9, ($a0)
  lui   $t0, %hi(displaylist_bank) 
  lw    $t0, %lo(displaylist_bank)($t0)
  lui   $t4, %hi(displaylist_0) 
  addiu $t4, %lo(displaylist_0) # addiu $t4, $t4, -0xc00
  xori  $t1, $t0, 1
  sll   $t2, $t1, 5
  addu  $t2, $t2, $t1
  sll   $t2, $t2, 2
  addu  $t2, $t2, $t1
  sll   $t2, $t2, 4
  addu  $t3, $t2, $t4
  sw    $t3, 4($a0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $v0, $a0, 8
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel video_DL_related_4
  addiu $sp, $sp, -0xd0
  lui   $v0, %hi(counterforframes)
  lui   $t6, %hi(D_80048498) 
  lw    $v0, %lo(counterforframes)($v0)
  lw    $t6, %lo(D_80048498)($t6)
  lui   $at, %hi(counterforframes)
  sw    $ra, 0x5c($sp)
  addu  $v0, $v0, $t6
  sw    $v0, %lo(counterforframes)($at)
  sltiu $at, $v0, 0xc9
  sw    $fp, 0x58($sp)
  sw    $s7, 0x54($sp)
  sw    $s6, 0x50($sp)
  sw    $s5, 0x4c($sp)
  sw    $s4, 0x48($sp)
  sw    $s3, 0x44($sp)
  sw    $s2, 0x40($sp)
  sw    $s1, 0x3c($sp)
  sw    $s0, 0x38($sp)
  sdc1  $f22, 0x30($sp)
  bnez  $at, .L70002D50
   sdc1  $f20, 0x28($sp)
  lui   $t7, %hi(D_80023234) 
  lw    $t7, %lo(D_80023234)($t7)
  lui   $at, %hi(D_80023234)
  addiu $v0, $v0, -0xc8
  xori  $t8, $t7, 1
  sw    $t8, %lo(D_80023234)($at)
  lui   $at, %hi(counterforframes)
  sw    $v0, %lo(counterforframes)($at)
.L70002D50:
  lui   $v1, %hi(D_8002322C)
  lw    $v1, %lo(D_8002322C)($v1)
  lui   $t9, %hi(D_80023234) 
  lw    $t9, %lo(D_80023234)($t9)
  andi  $t1, $v1, 1
  lui   $at, %hi(D_8002322C)
  addiu $v1, $v1, 1
  beq   $t9, $t1, .L70003024
   sw    $v1, %lo(D_8002322C)($at)
  lui   $t2, %hi(displaylist_bank) 
  lw    $t2, %lo(displaylist_bank)($t2)
  lui   $t4, %hi(displaylist_0) 
  addiu $t4, %lo(displaylist_0) # addiu $t4, $t4, -0xc00
  sll   $t3, $t2, 5
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 2
  addu  $t3, $t3, $t2
  sll   $t3, $t3, 4
  jal   sub_GAME_7F0D1AC0
   addu  $a0, $t3, $t4
  move  $s3, $v0
  addiu $v0, $sp, 0xb8
  addiu $s4, $sp, 0xac
.L70002DAC:
  addiu $s4, $s4, 4
  sltu  $at, $s4, $v0
  bnez  $at, .L70002DAC
   sw    $zero, -4($s4)
  lui   $a0, %hi(dword_CODE_bss_800604A4)
  lw    $a0, %lo(dword_CODE_bss_800604A4)($a0)
  addiu $s5, $sp, 0xa0
  addiu $v0, $sp, 0xac
.L70002DCC:
  addiu $s5, $s5, 4
  sltu  $at, $s5, $v0
  bnez  $at, .L70002DCC
   sw    $a0, -4($s5)
  lui   $t5, %hi(dword_CODE_bss_800607B0) 
  addiu $t5, %lo(dword_CODE_bss_800607B0) # addiu $t5, $t5, 0x7b0
  lui   $fp, %hi(dword_CODE_bss_800607D0) 
  lui   $at, %hi(aIL0)
  lwc1  $f22, %lo(aIL0)($at)
  addiu $fp, %lo(dword_CODE_bss_800607D0) # addiu $fp, $fp, 0x7d0
  sw    $t5, 0x70($sp)
  sw    $zero, 0xc8($sp)
  sw    $zero, 0x80($sp)
  li    $s6, 1
.L70002E04:
  lw    $t6, 0x70($sp)
  lw    $a1, ($fp)
  lw    $t7, 0x80($sp)
  lw    $s1, ($t6)
  mtc1  $zero, $f20
  addiu $t8, $sp, 0xac
  beq   $s1, $a1, .L70002F9C
   addu  $s4, $t7, $t8
  lw    $t1, 0xc8($sp)
  lui   $t3, %hi(dword_CODE_bss_800604B0) 
  addiu $t3, %lo(dword_CODE_bss_800604B0) # addiu $t3, $t3, 0x4b0
  addiu $t9, $sp, 0xa0
  sll   $t2, $t1, 8
  addu  $s7, $t2, $t3
  addu  $s5, $t7, $t9
.L70002E40:
  sll   $t4, $s1, 3
  addu  $v0, $s7, $t4
  lw    $s2, ($v0)
  lui   $a0, %hi(dword_CODE_bss_800604A4)
  lw    $a0, %lo(dword_CODE_bss_800604A4)($a0)
  andi  $t5, $s2, 0x8000
  beql  $t5, $zero, .L70002E68
   lw    $v1, ($s5)
  li    $s2, 3
  lw    $v1, ($s5)
.L70002E68:
  lw    $s0, 4($v0)
  sltu  $at, $v1, $a0
  beql  $at, $zero, .L70002E80
   sltu  $at, $s0, $a0
  move  $v1, $a0
  sltu  $at, $s0, $a0
.L70002E80:
  bnez  $at, .L70002F74
   sltu  $at, $s0, $v1
  bnez  $at, .L70002F74
   lui   $t9, %hi(D_800231D4) 
  lw    $v0, ($s4)
  addiu $t9, %lo(D_800231D4) # addiu $t9, $t9, 0x31d4
  subu  $t1, $s0, $v1
  beq   $s6, $v0, .L70002EDC
   sll   $t7, $v0, 4
  li    $at, 3
  beq   $v0, $at, .L70002EDC
   andi  $t6, $v0, 0x8000
  bnez  $t6, .L70002EDC
   subu  $t8, $s0, $v1
  mtc1  $t8, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t8, .L70002ED4
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L70002ED4:
  div.s $f10, $f6, $f22
  add.s $f20, $f20, $f10
.L70002EDC:
  mtc1  $t1, $f16
  addu  $t0, $t7, $t9
  bgez  $t1, .L70002EFC
   cvt.s.w $f18, $f16
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f4
  nop   
  add.s $f18, $f18, $f4
.L70002EFC:
  bne   $s6, $v0, .L70002F14
   div.s $f12, $f18, $f22
  jal   sub_GAME_7F0D1DCC
   nop   
  b     .L70002F60
   move  $v0, $s3
.L70002F14:
  lw    $v0, 4($t0)
  mfc1  $a1, $f12
  move  $a0, $s3
  sra   $t4, $v0, 8
  andi  $t5, $t4, 0xff
  sw    $t5, 0x10($sp)
  lw    $t6, 8($t0)
  sra   $a2, $v0, 0x18
  sra   $a3, $v0, 0x10
  sw    $t6, 0x14($sp)
  lw    $t8, 0xc($t0)
  andi  $t3, $a3, 0xff
  andi  $t2, $a2, 0xff
  move  $a2, $t2
  move  $a3, $t3
  jal   sub_GAME_7F0D1BD0
   sw    $t8, 0x18($sp)
  move  $s3, $v0
  move  $v0, $s3
.L70002F60:
  lui   $t7, 0xe700
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  addiu $s3, $s3, 8
  lw    $a1, ($fp)
.L70002F74:
  addiu $s1, $s1, 1
  sw    $s2, ($s4)
  sw    $s0, ($s5)
  bgez  $s1, .L70002F94
   andi  $t9, $s1, 0x1f
  beqz  $t9, .L70002F94
   nop   
  addiu $t9, $t9, -0x20
.L70002F94:
  bne   $t9, $a1, .L70002E40
   move  $s1, $t9
.L70002F9C:
  lw    $t1, 0xc8($sp)
  slti  $at, $t1, 2
  beql  $at, $zero, .L70002FB8
   lw    $t2, 0xc8($sp)
  jal   sub_GAME_7F0D2320
   nop   
  lw    $t2, 0xc8($sp)
.L70002FB8:
  lw    $t4, 0x80($sp)
  lw    $t6, 0x70($sp)
  li    $at, 3
  addiu $t3, $t2, 1
  addiu $t5, $t4, 4
  addiu $t8, $t6, 4
  sw    $t8, 0x70($sp)
  sw    $t5, 0x80($sp)
  sw    $t3, 0xc8($sp)
  bne   $t3, $at, .L70002E04
   addiu $fp, $fp, 4
  move  $a0, $s3
  move  $a1, $zero
  move  $a2, $zero
  jal   sub_GAME_7F0D1E98
   move  $a3, $zero
  lui   $v1, %hi(displaylist_bank)
  lui   $t7, 0xe700
  lui   $t9, 0xb800
  addiu $v1, %lo(displaylist_bank) # addiu $v1, $v1, 0x4a0
  sw    $t7, ($v0)
  sw    $zero, 4($v0)
  sw    $t9, 8($v0)
  sw    $zero, 0xc($v0)
  lw    $t1, ($v1)
  xori  $t2, $t1, 1
  sw    $t2, ($v1)
.L70003024:
  lw    $ra, 0x5c($sp)
  ldc1  $f20, 0x28($sp)
  ldc1  $f22, 0x30($sp)
  lw    $s0, 0x38($sp)
  lw    $s1, 0x3c($sp)
  lw    $s2, 0x40($sp)
  lw    $s3, 0x44($sp)
  lw    $s4, 0x48($sp)
  lw    $s5, 0x4c($sp)
  lw    $s6, 0x50($sp)
  lw    $s7, 0x54($sp)
  lw    $fp, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");
