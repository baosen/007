// This file contains video handling code.
#include <message.h>
#include <stddef.h>
#include <thread.h>
#include <types.h>

extern OSMesg vi_c_debug_MSG[0x8];
extern OSMesgQueue vi_c_debug_MQ;

extern unsigned int enddl_80024518[];

unsigned int D_80023240 = 0;

typedef struct {
  int mode;
  short txtClipW;
  short txtClipH;
  float far;
  float scale;
  float aspect;
  float anonymous_6;
  short somethingW;
  short somethingH;
  short width;
  short height;
  short ulx;
  short uly;
  int anonymous_12;
  unsigned char *framebuffer;
} video_settings;

video_settings video1_settings = {0,     320,      240, 60.0f, 1.3333334f,
                                  30.0f, 10000.0f, 320, 240,   320,
                                  240,   0,        0,   1,     NULL};
video_settings video2_settings = {0,     320,      240, 60.0f, 1.3333334f,
                                  30.0f, 10000.0f, 320, 240,   320,
                                  240,   0,        0,   1,     NULL};

int D_8002329C = 0;
int D_800232A0 = 0;

video_settings *ptr_video_settings1 = &video1_settings;
video_settings *ptr_video_settings2 = &video1_settings;

typedef enum COLORMODE { MODE_32BIT = 0, MODE_16BIT = 1 } COLORMODE;

COLORMODE coloroutputmode = MODE_16BIT;

int D_800232B0 = 1;
int D_800232B4 = 0;
int D_800232B8 = 0;
int D_800232BC = 3;
int D_800232C0 = 0;
int jpg_16bit_grabnum = 1;
int jpg_32bit_grabnum = 1;
int rgb_16bit_grabnum = 1;
int rgb_32bit_grabnum = 1;

const unsigned short widths_80028480[] = {320, 320, 640};
const unsigned short heights_80028488[] = {
    240, 240, 480}; // is this not 16bit and a list of 320x240 and 640x480 - 3
                    // widths, 3 heights
const char aGrab_D_jpeg_1[] = "grab.%d.jpeg";
const char aGrab_D_temp_uix[] = "grab.%d.temp.uix";
const char aUix2pixGrab_D_temp_uix[] = "uix2pix grab.%d.temp.uix";
const char aFromaliasGrab_D_temp_pixGrab_D_tem[] =
    "fromalias grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgcopyFjfifGrab_D_temp_rgbGrab_D_[] =
    "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg";
const char aRmGrab_D_temp_uixGrab_D_temp_pixGr[] =
    "rm grab.%d.temp.uix grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgviewGrab_D_jpeg[] = "imgview grab.%d.jpeg";
const char aGrab_D_jpeg[] = "grab.%d.jpeg";
const char aGrab_D_temp_uix_0[] = "grab.%d.temp.Uix";
const char aUix2pixXsDGrab_D_temp_uix[] = "Uix2pix -xs%d grab.%d.temp.Uix";
const char aFromaliasGrab_D_temp_pixGrab_D_t_0[] =
    "fromalias grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgcopyFjfifGrab_D_temp_rgbGrab__0[] =
    "imgcopy -fjfif grab.%d.temp.rgb grab.%d.jpeg";
const char aRmGrab_D_temp_uixGrab_D_temp_pix_0[] =
    "rm grab.%d.temp.Uix grab.%d.temp.pix grab.%d.temp.rgb";
const char aImgviewGrab_D_jpeg_0[] = "imgview grab.%d.jpeg";
const char aGrab_D_rgb[] = "grab.%d.rgb";
const char aGrab_D_temp_uix_1[] = "grab.%d.temp.uix";
const char aUix2pixGrab_D_temp_uix_0[] = "uix2pix grab.%d.temp.uix";
const char aFromaliasGrab_D_temp_pixGrab_D_rgb[] =
    "fromalias grab.%d.temp.pix grab.%d.rgb";
const char aRmGrab_D_temp_uixGrab_D_temp_pix[] =
    "rm grab.%d.temp.uix grab.%d.temp.pix";
const char aImgviewGrab_D_rgb[] = "imgview grab.%d.rgb";
const char aGrab_D_rgb_0[] = "grab.%d.rgb";
const char aGrab_D_temp_uix_2[] = "grab.%d.temp.Uix";
const char aUix2pixXsDGrab_D_temp_uix_0[] = "Uix2pix -xs%d grab.%d.temp.Uix";
const char aFromaliasGrab_D_temp_pixGrab_D_r_0[] =
    "fromalias grab.%d.temp.pix grab.%d.rgb";
const char aRmGrab_D_temp_uixGrab_D_temp_pix_1[] =
    "rm grab.%d.temp.Uix grab.%d.temp.pix";
const char aImgviewGrab_D_rgb_0[] = "imgview grab.%d.rgb";

char dword_CODE_bss_800607E0[0x40];
Mtx *m;
unsigned short word_CODE_bss_80060824;
char dword_CODE_bss_80060828[0x50];
unsigned char off_CODE_bss_80060878;
unsigned char off_CODE_bss_80060879;
int viMode;
int dword_CODE_bss_80060880;
int dword_CODE_bss_80060884;
int dword_CODE_bss_80060888;
int dword_CODE_bss_8006088C;
char dword_CODE_bss_80060890[0x400]; // CC[0x3C4];
                                     // 90[0x400];
asm(R"
glabel init_video_settings
  li    $t0, 44
  andi  $v0, $zero, 0xff
  multu $v0, $t0
  sll   $t9, $v0, 2
  addu  $t9, $t9, $v0
  sll   $t9, $t9, 2
  subu  $t9, $t9, $v0
  lui   $a3, %hi(video1_settings)
  sll   $t9, $t9, 2
  addiu $a3, %lo(video1_settings) # addiu $a3, $a3, 0x3244
  lui   $a0, %hi(off_CODE_bss_80060878)
  lui   $a1, %hi(off_CODE_bss_80060879)
  mflo  $t7
  lui   $a2, %hi(ptr_video_settings1)
  lui   $t1, %hi(cfb_16_a) # $t1, 0x803b
  subu  $t9, $t9, $v0
  addiu $t1, %lo(cfb_16_a) # addiu $t1, $t1, 0x5000
  addiu $a2, %lo(ptr_video_settings1) # addiu $a2, $a2, 0x32a4
  addiu $a1, %lo(off_CODE_bss_80060879) # addiu $a1, $a1, 0x879
  addiu $a0, %lo(off_CODE_bss_80060878) # addiu $a0, $a0, 0x878
  li    $t6, 1
  addu  $t8, $a3, $t7
  sll   $t9, $t9, 0xb
  sb    $zero, ($a0)
  sb    $t6, ($a1)
  sw    $t8, ($a2)
  addu  $t3, $t1, $t9
  sw    $t3, 0x28($t8)
  lbu   $v1, ($a1)
  lui   $t2, %hi(ptr_video_settings2) 
  addiu $t2, %lo(ptr_video_settings2) # addiu $t2, $t2, 0x32a8
  multu $v1, $t0
  sll   $t7, $v1, 2
  addu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 2
  subu  $t7, $t7, $v1
  sll   $t7, $t7, 0xb
  addu  $t8, $t1, $t7
  lui   $at, %hi(D_8002329C)
  mflo  $t5
  addu  $t6, $a3, $t5
  sw    $t6, ($t2)
  sw    $t8, 0x28($t6)
  sw    $zero, %lo(D_8002329C)($at)
  lui   $at, %hi(D_800232A0)
  jr    $ra
   sw    $zero, %lo(D_800232A0)($at)
");

asm(R"
glabel init_both_video_buffers
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   zbufDeallocate
   nop   
  lui   $a3, (0x00025800 >> 16) # lui $a3, 2
  lui   $a2, %hi(cfb_16_b) # $a2, 0x803e
  lui   $a1, %hi(cfb_16_a) # $a1, 0x803b
  addiu $a1, %lo(cfb_16_a) # addiu $a1, $a1, 0x5000
  addiu $a2, %lo(cfb_16_b) # addiu $a2, $a2, -0x5800
  ori   $a3, (0x00025800 & 0xFFFF) # ori $a3, $a3, 0x5800
  move  $a0, $zero
.L70003150:
  addu  $v0, $a1, $a0
  sb    $zero, ($v0)
  addu  $v1, $a2, $a0
  sb    $zero, ($v1)
  sb    $zero, 1($v0)
  sb    $zero, 1($v1)
  sb    $zero, 2($v0)
  sb    $zero, 2($v1)
  sb    $zero, 3($v0)
  addiu $a0, $a0, 4
  bne   $a0, $a3, .L70003150
   sb    $zero, 3($v1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void video_related_6(unsigned int arg0) {
  arg0 += 2;
  D_800232BC = arg0;
}

asm(R"
glabel video_related_7
  lui   $v1, %hi(D_800232B8)
  addiu $v1, %lo(D_800232B8) # addiu $v1, $v1, 0x32b8
  lw    $v0, ($v1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  beqz  $v0, .L700031D0
   lui   $t8, %hi(D_800232B0) 
  addiu $t6, $v0, -1
  bnez  $t6, .L700031D0
   sw    $t6, ($v1)
  lui   $at, %hi(D_800232B4)
  sw    $zero, %lo(D_800232B4)($at)
.L700031D0:
  lui   $t9, %hi(D_800232B4) 
  lw    $t9, %lo(D_800232B4)($t9)
  lw    $t8, %lo(D_800232B0)($t8)
  lui   $v0, %hi(viMode+0x8)
  lw    $t5, %lo(viMode+0x8)($v0)
  multu $t8, $t9
  lui   $a1, %hi(viMode)
  addiu $a1, %lo(viMode) # addiu $a1, $a1, 0x87c
  sra   $t1, $t5, 0x10
  lw    $t9, ($a1)
  lui   $v0, %hi(viMode+0xC)
  mflo  $v1
  addu  $t3, $t1, $v1
  addu  $t6, $t5, $v1
  andi  $t7, $t6, 0xffff
  sll   $t4, $t3, 0x10
  or    $t8, $t4, $t7
  sw    $t8, 0x30($t9)
  lw    $t6, %lo(viMode+0xC)($v0)
  lw    $t9, ($a1)
  sra   $t1, $t6, 0x10
  addu  $t3, $t1, $v1
  addu  $t4, $t6, $v1
  andi  $t7, $t4, 0xffff
  sll   $t5, $t3, 0x10
  or    $t8, $t5, $t7
  sw    $t8, 0x44($t9)
  jal   osViSetMode
   lw    $a0, ($a1)
  lui   $a0, %hi(D_800232BC + 3)
  jal   osViBlack
   lbu   $a0, %lo(D_800232BC + 3)($a0)
  lui   $v1, %hi(D_800232BC)
  addiu $v1, %lo(D_800232BC) # addiu $v1, $v1, 0x32bc
  lw    $v0, ($v1)
  beqz  $v0, .L70003270
   slti  $at, $v0, 3
  beqz  $at, .L70003270
   addiu $t0, $v0, -1
  sw    $t0, ($v1)
.L70003270:
  jal   osViSetSpecialFeatures
   li    $a0, 66
  lui   $v0, %hi(D_800232B0)
  addiu $v0, %lo(D_800232B0) # addiu $v0, $v0, 0x32b0
  lw    $t1, ($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  negu  $t2, $t1
  jr    $ra
   sw    $t2, ($v0)
");

asm(R"
glabel video_related_8
  lui   $t5, %hi(ptr_video_settings2) 
  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
  lui   $t6, %hi(ptr_video_settings1) 
  lw    $t6, %lo(ptr_video_settings1)($t6)
  lw    $t0, ($t5)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lbu   $t7, ($t6)
  lbu   $v0, ($t0)
  beql  $v0, $t7, .L7000352C
   lh    $t7, 4($t0)
  beqz  $v0, .L700032EC
   li    $at, 0x3F800000 # 1.000000
  li    $at, 1
  beq   $v0, $at, .L70003308
   lui   $t8, %hi(coloroutputmode) 
  li    $at, 2
  beq   $v0, $at, .L700034A4
   lui   $t9, 0x8000
  b     .L7000350C
   nop   
.L700032EC:
  mtc1  $at, $f12
  jal   osViSetYScale
   nop   
  jal   osViBlack
   li    $a0, 1
  b     .L7000350C
   nop   
.L70003308:
  lw    $t8, %lo(coloroutputmode)($t8)
  lui   $v1, %hi(viMode)
  lui   $t7, 0x8000
  beqz  $t8, .L700033C4
   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
  lui   $t9, %hi(osTvType) 
  lw    $t9, %lo(osTvType)($t9)
  li    $at, 2
  lui   $t8, %hi(dword_CODE_bss_80060828) 
  bne   $t9, $at, .L70003380
   addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
  lui   $t7, %hi(osViModeTable_osViModeMpalLan1) 
  addiu $t7, %lo(osViModeTable_osViModeMpalLan1) # addiu $t7, $t7, 0x7320
  lui   $t6, %hi(dword_CODE_bss_80060828) 
  addiu $t6, %lo(dword_CODE_bss_80060828) # addiu $t6, $t6, 0x828
  addiu $t9, $t7, 0x48
.L70003348:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t7)
  sw    $at, -8($t6)
  lw    $at, -4($t7)
  bne   $t7, $t9, .L70003348
   sw    $at, -4($t6)
  lw    $at, ($t7)
  lw    $t9, 4($t7)
  sw    $at, ($t6)
  b     .L70003464
   sw    $t9, 4($t6)
.L70003380:
  lui   $t9, %hi(osViModeTable_osViModeNtscLan1) 
  addiu $t9, %lo(osViModeTable_osViModeNtscLan1) # addiu $t9, $t9, 0x6a60
  addiu $t6, $t9, 0x48
.L7000338C:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t9)
  sw    $at, -8($t8)
  lw    $at, -4($t9)
  bne   $t9, $t6, .L7000338C
   sw    $at, -4($t8)
  lw    $at, ($t9)
  lw    $t6, 4($t9)
  sw    $at, ($t8)
  b     .L70003464
   sw    $t6, 4($t8)
.L700033C4:
  lw    $t7, 0x300($t7)
  li    $at, 2
  lui   $t8, %hi(dword_CODE_bss_80060828) 
  bne   $t7, $at, .L70003424
   addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
  lui   $t9, %hi(osViModeTable_osViModeMpalLan2) 
  addiu $t9, %lo(osViModeTable_osViModeMpalLan2) # addiu $t9, $t9, 0x7460
  lui   $t6, %hi(dword_CODE_bss_80060828) 
  addiu $t6, %lo(dword_CODE_bss_80060828) # addiu $t6, $t6, 0x828
  addiu $t7, $t9, 0x48
.L700033EC:
  lw    $at, ($t9)
  addiu $t9, $t9, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t9)
  sw    $at, -8($t6)
  lw    $at, -4($t9)
  bne   $t9, $t7, .L700033EC
   sw    $at, -4($t6)
  lw    $at, ($t9)
  lw    $t7, 4($t9)
  sw    $at, ($t6)
  b     .L70003464
   sw    $t7, 4($t6)
.L70003424:
  lui   $t7, %hi(osViModeTable_osViModeNtscLan2) 
  addiu $t7, %lo(osViModeTable_osViModeNtscLan2) # addiu $t7, $t7, 0x6ba0
  addiu $t6, $t7, 0x48
.L70003430:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t7)
  sw    $at, -8($t8)
  lw    $at, -4($t7)
  bne   $t7, $t6, .L70003430
   sw    $at, -4($t8)
  lw    $at, ($t7)
  lw    $t6, 4($t7)
  sw    $at, ($t8)
  sw    $t6, 4($t8)
.L70003464:
  lui   $t9, %hi(dword_CODE_bss_80060828) 
  addiu $t9, %lo(dword_CODE_bss_80060828) # addiu $t9, $t9, 0x828
  sw    $t9, ($v1)
  lw    $t6, 0x1c($t9)
  lui   $at, %hi(viMode+0x4)
  move  $a0, $zero
  sw    $t6, %lo(viMode+0x4)($at)
  lw    $t7, 0x30($t9)
  lui   $at, %hi(viMode+0x8)
  sw    $t7, %lo(viMode+0x8)($at)
  lw    $t8, 0x44($t9)
  lui   $at, %hi(viMode+0xC)
  jal   video_related_6
   sw    $t8, %lo(viMode+0xC)($at)
  b     .L7000350C
   nop   
.L700034A4:
  lw    $t9, 0x300($t9)
  li    $at, 2
  lui   $v1, %hi(viMode)
  bne   $t9, $at, .L700034D0
   addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
  lui   $v1, %hi(viMode)
  lui   $t6, %hi(osViModeTable_osViModeMpalHaf1) 
  addiu $v1, %lo(viMode) # addiu $v1, $v1, 0x87c
  addiu $t6, %lo(osViModeTable_osViModeMpalHaf1) # addiu $t6, $t6, 0x75f0
  b     .L700034DC
   sw    $t6, ($v1)
.L700034D0:
  lui   $t7, %hi(osViModeTable_osViModeNtscHaf1) 
  addiu $t7, %lo(osViModeTable_osViModeNtscHaf1) # addiu $t7, $t7, 0x6d30
  sw    $t7, ($v1)
.L700034DC:
  lw    $v0, ($v1)
  lui   $at, %hi(viMode+0x4)
  move  $a0, $zero
  lw    $t8, 0x1c($v0)
  sw    $t8, %lo(viMode+0x4)($at)
  lw    $t9, 0x30($v0)
  lui   $at, %hi(viMode+0x8)
  sw    $t9, %lo(viMode+0x8)($at)
  lw    $t6, 0x44($v0)
  lui   $at, %hi(viMode+0xC)
  jal   osViBlack
   sw    $t6, %lo(viMode+0xC)($at)
.L7000350C:
  jal   osViSetSpecialFeatures
   li    $a0, 66
  lui   $t0, %hi(ptr_video_settings2) 
  lw    $t0, %lo(ptr_video_settings2)($t0)
  lui   $t5, %hi(ptr_video_settings2) 
  addiu $t5, %lo(ptr_video_settings2) # addiu $t5, $t5, 0x32a8
  lbu   $v0, ($t0)
  lh    $t7, 4($t0)
.L7000352C:
  lh    $t8, 0x18($t0)
  lh    $t9, 6($t0)
  mtc1  $t7, $f4
  lh    $t6, 0x1a($t0)
  mtc1  $t8, $f8
  cvt.s.w $f6, $f4
  mtc1  $t9, $f16
  mtc1  $t6, $f4
  lui   $t8, %hi(dword_CODE_bss_80060828) 
  lui   $t2, %hi(D_800232C0) 
  cvt.s.w $f10, $f8
  li    $at, 0x3F800000 # 1.000000
  addiu $t8, %lo(dword_CODE_bss_80060828) # addiu $t8, $t8, 0x828
  lui   $t3, %hi(coloroutputmode) 
  cvt.s.w $f18, $f16
  cvt.s.w $f8, $f4
  div.s $f2, $f6, $f10
  bnez  $v0, .L70003580
   div.s $f0, $f18, $f8
  mtc1  $at, $f0
  nop   
.L70003580:
  lw    $t2, %lo(D_800232C0)($t2)
  lui   $at, %hi(something_with_osVI_4)
  sll   $t1, $t2, 2
  addu  $at, $at, $t1
  swc1  $f2, %lo(something_with_osVI_4)($at)
  lui   $at, %hi(something_with_osVI_C)
  addu  $at, $at, $t1
  swc1  $f0, %lo(something_with_osVI_C)($at)
  lbu   $t7, ($t0)
  li    $at, 1
  bne   $t7, $at, .L700039C0
   nop   
  lw    $t3, %lo(coloroutputmode)($t3)
  lui   $at, %hi(dword_CODE_bss_8005DB40+0xA0)
  addu  $at, $at, $t1
  beqz  $t3, .L70003694
   sw    $t8, %lo(dword_CODE_bss_8005DB40+0xA0)($at)
  lui   $t9, %hi(osTvType) 
  lw    $t9, %lo(osTvType)($t9)
  li    $at, 2
  lui   $t6, %hi(dword_CODE_bss_8005DB40) 
  bne   $t9, $at, .L7000363C
   addiu $t6, %lo(dword_CODE_bss_8005DB40) # addiu $t6, $t6, -0x24c0
  sll   $t6, $t2, 2
  addu  $t6, $t6, $t2
  lui   $t7, %hi(dword_CODE_bss_8005DB40) 
  addiu $t7, %lo(dword_CODE_bss_8005DB40) # addiu $t7, $t7, -0x24c0
  sll   $t6, $t6, 4
  addu  $v1, $t6, $t7
  lui   $t8, %hi(osViModeTable_osViModeMpalLan1) 
  addiu $t8, %lo(osViModeTable_osViModeMpalLan1) # addiu $t8, $t8, 0x7320
  addiu $t6, $t8, 0x48
  move  $t7, $v1
.L70003604:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t7, $t7, 0xc
  sw    $at, -0xc($t7)
  lw    $at, -8($t8)
  sw    $at, -8($t7)
  lw    $at, -4($t8)
  bne   $t8, $t6, .L70003604
   sw    $at, -4($t7)
  lw    $at, ($t8)
  sw    $at, ($t7)
  lw    $t6, 4($t8)
  b     .L70003760
   sw    $t6, 4($t7)
.L7000363C:
  sll   $t9, $t2, 2
  addu  $t9, $t9, $t2
  sll   $t9, $t9, 4
  addu  $v1, $t9, $t6
  lui   $t8, %hi(osViModeTable_osViModeNtscLan1) 
  addiu $t8, %lo(osViModeTable_osViModeNtscLan1) # addiu $t8, $t8, 0x6a60
  addiu $t9, $t8, 0x48
  move  $t6, $v1
.L7000365C:
  lw    $at, ($t8)
  addiu $t8, $t8, 0xc
  addiu $t6, $t6, 0xc
  sw    $at, -0xc($t6)
  lw    $at, -8($t8)
  sw    $at, -8($t6)
  lw    $at, -4($t8)
  bne   $t8, $t9, .L7000365C
   sw    $at, -4($t6)
  lw    $at, ($t8)
  sw    $at, ($t6)
  lw    $t9, 4($t8)
  b     .L70003760
   sw    $t9, 4($t6)
.L70003694:
  lui   $t7, %hi(osTvType) 
  lw    $t7, %lo(osTvType)($t7)
  li    $at, 2
  bne   $t7, $at, .L70003704
   sll   $t9, $t2, 2
  addu  $t9, $t9, $t2
  lui   $t8, %hi(dword_CODE_bss_8005DB40) 
  addiu $t8, %lo(dword_CODE_bss_8005DB40) # addiu $t8, $t8, -0x24c0
  sll   $t9, $t9, 4
  addu  $v1, $t9, $t8
  lui   $t6, %hi(osViModeTable_osViModeMpalLan2) 
  addiu $t6, %lo(osViModeTable_osViModeMpalLan2) # addiu $t6, $t6, 0x7460
  addiu $t9, $t6, 0x48
  move  $t8, $v1
.L700036CC:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t8, $t8, 0xc
  sw    $at, -0xc($t8)
  lw    $at, -8($t6)
  sw    $at, -8($t8)
  lw    $at, -4($t6)
  bne   $t6, $t9, .L700036CC
   sw    $at, -4($t8)
  lw    $at, ($t6)
  sw    $at, ($t8)
  lw    $t9, 4($t6)
  b     .L70003760
   sw    $t9, 4($t8)
.L70003704:
  sll   $t7, $t2, 2
  addu  $t7, $t7, $t2
  lui   $t9, %hi(dword_CODE_bss_8005DB40) 
  addiu $t9, %lo(dword_CODE_bss_8005DB40) # addiu $t9, $t9, -0x24c0
  sll   $t7, $t7, 4
  addu  $v1, $t7, $t9
  lui   $t6, %hi(osViModeTable_osViModeNtscLan2) 
  addiu $t6, %lo(osViModeTable_osViModeNtscLan2) # addiu $t6, $t6, 0x6ba0
  addiu $t7, $t6, 0x48
  move  $t9, $v1
.L7000372C:
  lw    $at, ($t6)
  addiu $t6, $t6, 0xc
  addiu $t9, $t9, 0xc
  sw    $at, -0xc($t9)
  lw    $at, -8($t6)
  sw    $at, -8($t9)
  lw    $at, -4($t6)
  bne   $t6, $t7, .L7000372C
   sw    $at, -4($t9)
  lw    $at, ($t6)
  sw    $at, ($t9)
  lw    $t7, 4($t6)
  sw    $t7, 4($t9)
.L70003760:
  lh    $t8, 0x18($t0)
  li    $at, 640
  li    $t4, 480
  sw    $t8, 8($v1)
  lh    $t7, 0x18($t0)
  lw    $v0, 0x1c($v1)
  lui   $a3, %hi(D_8002329C)
  sll   $t6, $t7, 0xa
  div   $zero, $t6, $at
  mflo  $t9
  sw    $t9, 0x20($v1)
  lh    $t8, 0x1a($t0)
  li    $a2, 65535
  lui   $a1, %hi(D_800232A0)
  sll   $t7, $t8, 0xb
  div   $zero, $t7, $t4
  mflo  $t6
  sw    $t6, 0x2c($v1)
  lh    $t9, 0x1a($t0)
  bnez  $t4, .L700037B8
   nop   
  break 7
.L700037B8:
  li    $at, -1
  bne   $t4, $at, .L700037D0
   lui   $at, 0x8000
  bne   $t7, $at, .L700037D0
   nop   
  break 6
.L700037D0:
  sll   $t8, $t9, 0xb
  div   $zero, $t8, $t4
  mflo  $t7
  sw    $t7, 0x40($v1)
  lh    $t6, 0x18($t0)
  bnez  $t4, .L700037F0
   nop   
  break 7
.L700037F0:
  li    $at, -1
  bne   $t4, $at, .L70003808
   lui   $at, 0x8000
  bne   $t8, $at, .L70003808
   nop   
  break 6
.L70003808:
  sll   $t9, $t6, 1
  sw    $t9, 0x28($v1)
  lh    $t8, 0x18($t0)
  sra   $t6, $v0, 0x10
  andi  $t9, $t6, 0xffff
  sll   $t7, $t8, 1
  sw    $t7, 0x3c($v1)
  lw    $a3, %lo(D_8002329C)($a3)
  addu  $t8, $t9, $a3
  div   $zero, $t8, $a2
  bnez  $a2, .L7000383C
   nop   
  break 7
.L7000383C:
  li    $at, -1
  bne   $a2, $at, .L70003854
   lui   $at, 0x8000
  bne   $t8, $at, .L70003854
   nop   
  break 6
.L70003854:
  andi  $t9, $v0, 0xffff
  mfhi  $t7
  addu  $t8, $t9, $a3
  sll   $t6, $t7, 0x10
  div   $zero, $t8, $a2
  bnez  $a2, .L70003874
   nop   
  break 7
.L70003874:
  li    $at, -1
  bne   $a2, $at, .L7000388C
   lui   $at, 0x8000
  bne   $t8, $at, .L7000388C
   nop   
  break 6
.L7000388C:
  mfhi  $t7
  or    $a0, $t6, $t7
  sw    $a0, 0x1c($v1)
  lui   $at, %hi(viMode+0x4)
  sw    $a0, %lo(viMode+0x4)($at)
  lw    $v0, 0x30($v1)
  lw    $a1, %lo(D_800232A0)($a1)
  sra   $t9, $v0, 0x10
  andi  $t8, $t9, 0xffff
  addu  $t6, $t8, $a1
  div   $zero, $t6, $a2
  bnez  $a2, .L700038C4
   nop   
  break 7
.L700038C4:
  li    $at, -1
  bne   $a2, $at, .L700038DC
   lui   $at, 0x8000
  bne   $t6, $at, .L700038DC
   nop   
  break 6
.L700038DC:
  andi  $t8, $v0, 0xffff
  mfhi  $t7
  addu  $t6, $t8, $a1
  sll   $t9, $t7, 0x10
  div   $zero, $t6, $a2
  bnez  $a2, .L700038FC
   nop   
  break 7
.L700038FC:
  li    $at, -1
  bne   $a2, $at, .L70003914
   lui   $at, 0x8000
  bne   $t6, $at, .L70003914
   nop   
  break 6
.L70003914:
  mfhi  $t7
  or    $a0, $t9, $t7
  sw    $a0, 0x30($v1)
  lui   $at, %hi(viMode+0x8)
  sw    $a0, %lo(viMode+0x8)($at)
  lw    $v0, 0x44($v1)
  sra   $t8, $v0, 0x10
  andi  $t6, $t8, 0xffff
  addu  $t9, $t6, $a1
  div   $zero, $t9, $a2
  bnez  $a2, .L70003948
   nop   
  break 7
.L70003948:
  li    $at, -1
  bne   $a2, $at, .L70003960
   lui   $at, 0x8000
  bne   $t9, $at, .L70003960
   nop   
  break 6
.L70003960:
  andi  $t6, $v0, 0xffff
  addu  $t9, $t6, $a1
  mfhi  $t7
  sll   $t8, $t7, 0x10
  li    $t6, 1
  div   $zero, $t9, $a2
  bnez  $a2, .L70003984
   nop   
  break 7
.L70003984:
  li    $at, -1
  bne   $a2, $at, .L7000399C
   lui   $at, 0x8000
  bne   $t9, $at, .L7000399C
   nop   
  break 6
.L7000399C:
  mfhi  $t7
  or    $a0, $t8, $t7
  sw    $a0, 0x44($v1)
  lui   $at, %hi(viMode+0xC)
  sw    $a0, %lo(viMode+0xC)($at)
  lui   $at, %hi(something_with_osVI_14)
  addu  $at, $at, $t1
  b     .L700039D4
   sw    $t6, %lo(something_with_osVI_14)($at)
.L700039C0:
  lui   $at, %hi(something_with_osVI_14)
  addu  $at, $at, $t1
  lui   $t3, %hi(coloroutputmode) 
  lw    $t3, %lo(coloroutputmode)($t3)
  sw    $zero, %lo(something_with_osVI_14)($at)
.L700039D4:
  addiu $t2, $t2, 1
  bgez  $t2, .L700039EC
   andi  $t9, $t2, 1
  beqz  $t9, .L700039EC
   nop   
  addiu $t9, $t9, -2
.L700039EC:
  lui   $at, %hi(D_800232C0)
  beqz  $t3, .L70003A0C
   sw    $t9, %lo(D_800232C0)($at)
  lui   $t7, %hi(fast3d_related_array) 
  lw    $t7, %lo(fast3d_related_array)($t7)
  lw    $t8, 0x28($t0)
  b     .L70003A20
   sw    $t8, 0x58($t7)
.L70003A0C:
  lui   $t9, %hi(fast3d_related_array) 
  lw    $t9, %lo(fast3d_related_array)($t9)
  lui   $t6, %hi(cfb_16_a) # $t6, 0x803b
  addiu $t6, %lo(cfb_16_a) # addiu $t6, $t6, 0x5000
  sw    $t6, 0x58($t9)
.L70003A20:
  lui   $v0, %hi(off_CODE_bss_80060878)
  addiu $v0, %lo(off_CODE_bss_80060878) # addiu $v0, $v0, 0x878
  lbu   $t8, ($v0)
  lui   $v1, %hi(off_CODE_bss_80060879)
  li    $t0, 44
  addiu $t7, $t8, 1
  addiu $v1, %lo(off_CODE_bss_80060879) # addiu $v1, $v1, 0x879
  lbu   $t9, ($v1)
  lui   $a3, %hi(video1_settings)
  addiu $a3, %lo(video1_settings) # addiu $a3, $a3, 0x3244
  addiu $t8, $t9, 1
  lw    $a0, ($t5)
  bgez  $t7, .L70003A64
   andi  $t6, $t7, 1
  beqz  $t6, .L70003A64
   nop   
  addiu $t6, $t6, -2
.L70003A64:
  sb    $t6, ($v0)
  lbu   $t6, ($v0)
  bgez  $t8, .L70003A80
   andi  $t7, $t8, 1
  beqz  $t7, .L70003A80
   nop   
  addiu $t7, $t7, -2
.L70003A80:
  multu $t6, $t0
  sb    $t7, ($v1)
  lui   $at, %hi(ptr_video_settings1)
  li    $a2, 44
  mflo  $t9
  addu  $t8, $a3, $t9
  sw    $t8, %lo(ptr_video_settings1)($at)
  lbu   $t7, ($v1)
  multu $t7, $t0
  mflo  $t6
  addu  $a1, $a3, $t6
  jal   _bcopy
   sw    $a1, ($t5)
  lui   $v1, %hi(off_CODE_bss_80060879)
  addiu $v1, %lo(off_CODE_bss_80060879) # addiu $v1, $v1, 0x879
  lbu   $t8, ($v1)
  lui   $t6, %hi(cfb_16_a) # $t6, 0x803b
  addiu $t6, %lo(cfb_16_a) # addiu $t6, $t6, 0x5000
  sll   $t7, $t8, 2
  addu  $t7, $t7, $t8
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t8
  sll   $t7, $t7, 2
  subu  $t7, $t7, $t8
  lui   $t8, %hi(ptr_video_settings2) 
  lw    $t8, %lo(ptr_video_settings2)($t8)
  sll   $t7, $t7, 0xb
  addu  $t9, $t7, $t6
  sw    $t9, 0x28($t8)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel video_related_9
  li    $at, 0x41600000 # 14.000000
  mtc1  $at, $f0
  nop   
  c.lt.s $f0, $f12
  nop   
  bc1fl .L70003B28
   mtc1  $zero, $f0
  mov.s $f12, $f0
  mtc1  $zero, $f0
.L70003B28:
  nop   
  c.lt.s $f12, $f0
  nop   
  bc1fl .L70003B44
   trunc.w.s $f4, $f12
  mov.s $f12, $f0
  trunc.w.s $f4, $f12
.L70003B44:
  lui   $at, %hi(D_800232B4)
  li    $t8, 10
  mfc1  $t7, $f4
  nop   
  sw    $t7, %lo(D_800232B4)($at)
  lui   $at, %hi(D_800232B8)
  jr    $ra
   sw    $t8, %lo(D_800232B8)($at)
");

void receive_vi_c_msgs(int msgcount) {
  do {
    osRecvMesg(&vi_c_debug_MQ, NULL, 1);
    msgcount += -1;
  } while (0 < msgcount);
}

asm(R"
glabel setVideoWidthHeightToMode
  lui   $a1, %hi(ptr_video_settings2)
  addiu $a1, %lo(ptr_video_settings2) # addiu $a1, $a1, 0x32a8
  lw    $t6, ($a1)
  sll   $v1, $a0, 1
  lui   $v0, %hi(widths_80028480)
  sb    $a0, ($t6)
  addu  $v0, $v0, $v1
  lh    $v0, %lo(widths_80028480)($v0)
  lw    $t7, ($a1)
  sh    $v0, 0x18($t7)
  lw    $t8, ($a1)
  sh    $v0, 4($t8)
  lui   $v0, %hi(heights_80028488)
  addu  $v0, $v0, $v1
  lh    $v0, %lo(heights_80028488)($v0)
  lw    $t9, ($a1)
  sh    $v0, 0x1a($t9)
  lw    $t0, ($a1)
  jr    $ra
   sh    $v0, 6($t0)
");

// sets colour output mode to 16bit.
void set_coloroutputmode_16bit(void) { coloroutputmode = MODE_16BIT; }

// sets colour output mode to 32bit.
void set_coloroutputmode_32bit(void) { coloroutputmode = MODE_32BIT; }

unsigned char *get_video_settings2_frameb(void) {
  return ptr_video_settings2->framebuffer;
}

unsigned char *get_video_settings1_frameb(void) {
  return ptr_video_settings1->framebuffer;
}

void set_video2buf_frameb(unsigned char *arg0) {
  ptr_video_settings2->framebuffer = arg0;
}

unsigned short get_80060824(void) { return word_CODE_bss_80060824; }

asm(R"
glabel video_related_F
  lui   $a1, %hi(pPlayer)
  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
  lw    $v0, ($a1)
  addiu $sp, $sp, -0x30
  sw    $s0, 0x24($sp)
  move  $s0, $a0
  sw    $ra, 0x2c($sp)
  beqz  $v0, .L70003D20
   sw    $s1, 0x28($sp)
  lui   $s1, %hi(ptr_video_settings2)
  addiu $s1, %lo(ptr_video_settings2) # addiu $s1, $s1, 0x32a8
  lw    $t6, ($s1)
  lui   $a0, %hi(off_CODE_bss_80060879)
  addiu $a0, %lo(off_CODE_bss_80060879) # addiu $a0, $a0, 0x879
  lbu   $t9, ($a0)
  lh    $t7, 0x1c($t6)
  sll   $t0, $t9, 4
  addu  $t1, $v0, $t0
  sll   $t8, $t7, 1
  sh    $t8, 0x7d0($t1)
  lw    $v1, ($s1)
  lbu   $t9, ($a0)
  lw    $t7, ($a1)
  lh    $t2, 0x1c($v1)
  lh    $t4, 0x20($v1)
  sll   $t0, $t9, 4
  sll   $t3, $t2, 1
  sll   $t5, $t4, 2
  addu  $t6, $t3, $t5
  addu  $t8, $t7, $t0
  sh    $t6, 0x7d8($t8)
  lw    $t1, ($s1)
  lbu   $t5, ($a0)
  lw    $t3, ($a1)
  lh    $t2, 0x1e($t1)
  sll   $t9, $t5, 4
  addu  $t7, $t3, $t9
  sll   $t4, $t2, 1
  sh    $t4, 0x7d2($t7)
  lw    $v1, ($s1)
  lbu   $t3, ($a0)
  lw    $t5, ($a1)
  lh    $t0, 0x1e($v1)
  lh    $t8, 0x22($v1)
  sll   $t9, $t3, 4
  sll   $t6, $t0, 1
  sll   $t1, $t8, 2
  addu  $t2, $t6, $t1
  addu  $t4, $t5, $t9
  sh    $t2, 0x7da($t4)
.L70003D20:
  lui   $t7, (0x03800010 >> 16) # lui $t7, 0x380
  lui   $a0, %hi(off_CODE_bss_80060879)
  ori   $t7, (0x03800010 & 0xFFFF) # ori $t7, $t7, 0x10
  move  $v0, $s0
  addiu $a0, %lo(off_CODE_bss_80060879) # addiu $a0, $a0, 0x879
  sw    $t7, ($v0)
  lbu   $t8, ($a0)
  lw    $t0, ($a1)
  lui   $at, (0x800007D0 >> 16) 
  sll   $t6, $t8, 4
  ori   $at, (0x800007D0 & 0xFFFF) # ori $at, $at, 0x7d0
  addu  $t1, $t0, $t6
  lui   $s1, %hi(ptr_video_settings2)
  addu  $t3, $t1, $at
  addiu $s1, %lo(ptr_video_settings2) # addiu $s1, $s1, 0x32a8
  sw    $t3, 4($v0)
  jal   sub_GAME_7F0BD6E0
   addiu $s0, $s0, 8
  lui   $at, %hi(m)
  sw    $v0, %lo(m)($at)
  lw    $v1, ($s1)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f4, 0x10($v1)
  lw    $a2, 8($v1)
  lw    $a3, 0xc($v1)
  swc1  $f4, 0x10($sp)
  lwc1  $f6, 0x14($v1)
  lui   $a0, %hi(dword_CODE_bss_800607E0)
  lui   $a1, %hi(word_CODE_bss_80060824)
  addiu $a1, %lo(word_CODE_bss_80060824) # addiu $a1, $a1, 0x824
  addiu $a0, %lo(dword_CODE_bss_800607E0) # addiu $a0, $a0, 0x7e0
  swc1  $f8, 0x18($sp)
  jal   guPerspectiveF
   swc1  $f6, 0x14($sp)
  lui   $a0, %hi(dword_CODE_bss_800607E0)
  lui   $a1, %hi(m)
  lw    $a1, %lo(m)($a1)
  jal   guMtxF2L
   addiu $a0, %lo(dword_CODE_bss_800607E0) # addiu $a0, $a0, 0x7e0
  lui   $t5, (0x01030040 >> 16) # lui $t5, 0x103
  lui   $a1, %hi(m)
  ori   $t5, (0x01030040 & 0xFFFF) # ori $t5, $t5, 0x40
  move  $v0, $s0
  addiu $a1, %lo(m) # addiu $a1, $a1, 0x820
  sw    $t5, ($v0)
  lw    $t9, ($a1)
  lui   $at, 0x8000
  addiu $s0, $s0, 8
  lui   $t4, (0xBC00000E >> 16) # lui $t4, 0xbc00
  addu  $t2, $t9, $at
  sw    $t2, 4($v0)
  ori   $t4, (0xBC00000E & 0xFFFF) # ori $t4, $t4, 0xe
  move  $v1, $s0
  sw    $t4, ($v1)
  lui   $t7, %hi(word_CODE_bss_80060824) 
  lhu   $t7, %lo(word_CODE_bss_80060824)($t7)
  addiu $s0, $s0, 8
  sw    $t7, 4($v1)
  jal   set_BONDdata_field_10D8
   lw    $a0, ($a1)
  lui   $a0, %hi(dword_CODE_bss_800607E0)
  jal   set_BONDdata_field_10DC
   addiu $a0, %lo(dword_CODE_bss_800607E0) # addiu $a0, $a0, 0x7e0
  lui   $t8, %hi(coloroutputmode) 
  lw    $t8, %lo(coloroutputmode)($t8)
  move  $v0, $s0
  lui   $at, 0xff18
  beql  $t8, $zero, .L70003E78
   lw    $t7, ($s1)
  lw    $t0, ($s1)
  lui   $at, 0xff10
  move  $v0, $s0
  lh    $t6, 0x18($t0)
  addiu $s0, $s0, 8
  addiu $t1, $t6, -1
  andi  $t3, $t1, 0xfff
  or    $t5, $t3, $at
  sw    $t5, ($v0)
  lw    $t9, ($s1)
  lui   $at, 0x8000
  lw    $t2, 0x28($t9)
  addu  $t4, $t2, $at
  b     .L70003E9C
   sw    $t4, 4($v0)
  lw    $t7, ($s1)
.L70003E78:
  lui   $t3, %hi(0x003B5000) # $t3, 0x3b
  addiu $t3, %lo(0x003B5000) # addiu $t3, $t3, 0x5000
  lh    $t8, 0x18($t7)
  sw    $t3, 4($v0)
  addiu $s0, $s0, 8
  addiu $t0, $t8, -1
  andi  $t6, $t0, 0xfff
  or    $t1, $t6, $at
  sw    $t1, ($v0)
.L70003E9C:
  lw    $ra, 0x2c($sp)
  move  $v0, $s0
  lw    $s0, 0x24($sp)
  lw    $s1, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel video_related_10
  lui   $t6, %hi(ptr_video_settings2) 
  lw    $t6, %lo(ptr_video_settings2)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lw    $t7, 0x24($t6)
  beql  $t7, $zero, .L70003EE8
   lw    $ra, 0x14($sp)
  jal   zbufInit
   nop   
  jal   zbufClearCurrentPlayer
   move  $a0, $v0
  move  $a0, $v0
  lw    $ra, 0x14($sp)
.L70003EE8:
  addiu $sp, $sp, 0x18
  move  $v0, $a0
  jr    $ra
   nop   
");

/**
 * generate a generic fillrect; fries: AT,A1,A2,A3,T0,T1,T2,T3,T4,T5,T6,T7,T8,T9
 *     V0=new display list address
 *     accepts: A0=p->display list
 */
asm(R"
glabel insert_generic_fillrect
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00				#gsDPSetCycleType
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  lui   $t7, 0x30												#G_CYC_1CYCLE
  sw    $t7, 4($a0)
  sw    $t6, ($a0)
  lui   $a2, %hi(ptr_video_settings2)
  lw    $a2, %lo(ptr_video_settings2)($a2)
  addiu $a1, $a0, 8
  lui   $at, 0xf600
  lh    $t8, 0x18($a2)
  lh    $t3, 0x1a($a2)
  addiu $a3, $a1, 8
  addiu $t9, $t8, -1
  andi  $t0, $t9, 0x3ff
  addiu $t4, $t3, -1
  andi  $t5, $t4, 0x3ff
  sll   $t1, $t0, 0xe
  or    $t2, $t1, $at
  sll   $t6, $t5, 2
  or    $t7, $t2, $t6
  sw    $t7, ($a1)
  sw    $zero, 4($a1)
  lui   $t8, 0xe700
  sw    $t8, ($a3)
  sw    $zero, 4($a3)
  jr    $ra
   addiu $v0, $a3, 8
");

// accepts: A0=p->display list
asm(R"
glabel setupscreensfornumplayers
  addiu $sp, $sp, -0x68
  sw    $s0, 0x14($sp)
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  addiu $s0, $a0, 8
  lui   $t7, 0x30
  sw    $t7, 4($a0)
  sw    $t6, ($a0)
  move  $v1, $s0
  lui   $t8, 0xed00
  sw    $t8, ($v1)
  sw    $v1, 0x60($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t9, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t9
  mtc1  $v0, $f4
  mtc1  $s1, $f16
  li    $at, 0x40800000 # 4.000000
  cvt.s.w $f6, $f4
  mtc1  $at, $f0
  lw    $t8, 0x60($sp)
  move  $v1, $s0
  lui   $t0, (0x00010001 >> 16) # lui $t0, 1
  cvt.s.w $f18, $f16
  mul.s $f8, $f6, $f0
  ori   $t0, (0x00010001 & 0xFFFF) # ori $t0, $t0, 1
  lui   $t9, 0xf700
  addiu $s0, $s0, 8
  mul.s $f4, $f18, $f0
  trunc.w.s $f10, $f8
  trunc.w.s $f6, $f4
  mfc1  $t1, $f10
  mfc1  $t4, $f6
  andi  $t2, $t1, 0xfff
  andi  $t5, $t4, 0xfff
  sll   $t6, $t5, 0xc
  or    $t7, $t2, $t6
  sw    $t7, 4($t8)
  sw    $t0, 4($v1)
  jal   get_video2_settings_uly
   sw    $t9, ($v1)
  blez  $v0, .L7000409C
   nop   
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnez  $v0, .L7000409C
   nop   
  sw    $s0, 0x58($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t1, $s1, 0x10
  jal   get_video2_settings_uly
   move  $s1, $t1
  addiu $t3, $v0, -1
  lw    $a0, 0x58($sp)
  andi  $t4, $t3, 0x3ff
  addiu $t6, $s1, -1
  andi  $t7, $t6, 0x3ff
  sll   $t5, $t4, 2
  lui   $at, 0xf600
  or    $t2, $t5, $at
  sll   $t8, $t7, 0xe
  or    $t9, $t2, $t8
  move  $v1, $s0
  sw    $t9, ($a0)
  sw    $zero, 4($a0)
  lui   $t0, 0xe700
  sw    $t0, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
.L7000409C:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7000416C
   nop   
  jal   get_video2_settings_height
   nop   
  jal   get_video2_settings_uly
   sh    $v0, 0x22($sp)
  sll   $s1, $v0, 0x10
  sra   $t1, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t1
  lh    $t3, 0x22($sp)
  addu  $t4, $s1, $t3
  slt   $at, $t4, $v0
  beql  $at, $zero, .L70004370
   lw    $ra, 0x1c($sp)
  sw    $s0, 0x50($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t5, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t5
  addiu $t6, $v0, -1
  andi  $t7, $t6, 0x3ff
  addiu $t9, $s1, -1
  andi  $t0, $t9, 0x3ff
  sll   $t2, $t7, 2
  lui   $at, 0xf600
  lw    $t4, 0x50($sp)
  or    $t8, $t2, $at
  sll   $t1, $t0, 0xe
  or    $t3, $t8, $t1
  jal   get_video2_settings_uly
   sw    $t3, ($t4)
  sll   $s1, $v0, 0x10
  sra   $t5, $s1, 0x10
  jal   get_video2_settings_height
   move  $s1, $t5
  lw    $t9, 0x50($sp)
  addu  $t6, $v0, $s1
  andi  $t7, $t6, 0x3ff
  sll   $t2, $t7, 2
  move  $v1, $s0
  lui   $t0, 0xe700
  sw    $t2, 4($t9)
  sw    $zero, 4($v1)
  sw    $t0, ($v1)
  b     .L7000436C
   addiu $s0, $s0, 8
.L7000416C:
  jal   get_cur_playernum
   nop   
  jal   sub_GAME_7F09B4D8
   move  $a0, $v0
  bnezl $v0, .L70004370
   lw    $ra, 0x1c($sp)
  jal   get_video2_settings_height
   nop   
  jal   get_video2_settings_height
   sh    $v0, 0x20($sp)
  jal   get_video2_settings_uly
   sh    $v0, 0x22($sp)
  sll   $s1, $v0, 0x10
  sra   $t8, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t8
  lh    $t1, 0x22($sp)
  lh    $t4, 0x20($sp)
  addu  $t3, $s1, $t1
  addu  $t5, $t3, $t4
  slt   $at, $t5, $v0
  beql  $at, $zero, .L70004260
   move  $s1, $s0
  sw    $s0, 0x48($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t6
  addiu $t7, $v0, -1
  andi  $t2, $t7, 0x3ff
  addiu $t8, $s1, -1
  andi  $t1, $t8, 0x3ff
  sll   $t9, $t2, 2
  lui   $at, 0xf600
  lw    $t5, 0x48($sp)
  or    $t0, $t9, $at
  sll   $t3, $t1, 0xe
  or    $t4, $t0, $t3
  jal   get_video2_settings_height
   sw    $t4, ($t5)
  jal   get_video2_settings_uly
   sh    $v0, 0x22($sp)
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_height
   move  $s1, $t6
  lh    $t2, 0x22($sp)
  addu  $t7, $v0, $s1
  lw    $t0, 0x48($sp)
  addu  $t9, $t7, $t2
  andi  $t8, $t9, 0x3ff
  sll   $t1, $t8, 2
  move  $v1, $s0
  sw    $t1, 4($t0)
  lui   $t3, 0xe700
  sw    $t3, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
  move  $s1, $s0
.L70004260:
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  addiu $t4, $v0, -1
  andi  $t5, $t4, 0x3ff
  sll   $t6, $t5, 0xe
  lui   $at, 0xf600
  or    $t7, $t6, $at
  ori   $t2, $t7, 0x1e0
  li    $t9, 476
  move  $v1, $s0
  sw    $t9, 4($s1)
  sw    $t2, ($s1)
  lui   $t8, 0xe700
  sw    $t8, ($v1)
  sw    $zero, 4($v1)
  jal   getPlayerCount
   addiu $s0, $s0, 8
  slti  $at, $v0, 3
  bnez  $at, .L700042F0
   move  $s1, $s0
  jal   get_video2_settings_txtClipH
   addiu $s0, $s0, 8
  addiu $t1, $v0, -1
  andi  $t0, $t1, 0x3ff
  sll   $t3, $t0, 2
  lui   $at, 0xf628
  lui   $t5, (0x0027C000 >> 16) # lui $t5, 0x27
  ori   $t5, (0x0027C000 & 0xFFFF) # ori $t5, $t5, 0xc000
  or    $t4, $t3, $at
  move  $v1, $s0
  sw    $t4, ($s1)
  sw    $t5, 4($s1)
  lui   $t6, 0xe700
  sw    $t6, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
.L700042F0:
  jal   getPlayerCount
   nop   
  li    $at, 3
  bnel  $v0, $at, .L70004370
   lw    $ra, 0x1c($sp)
  sw    $s0, 0x30($sp)
  jal   get_video2_settings_txtClipW
   addiu $s0, $s0, 8
  sll   $s1, $v0, 0x10
  sra   $t7, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t7
  addiu $t2, $v0, -1
  lw    $a0, 0x30($sp)
  andi  $t9, $t2, 0x3ff
  addiu $t0, $s1, -1
  andi  $t3, $t0, 0x3ff
  sll   $t8, $t9, 2
  lui   $at, 0xf600
  or    $t1, $t8, $at
  sll   $t4, $t3, 0xe
  lui   $t6, (0x002841E4 >> 16) # lui $t6, 0x28
  ori   $t6, (0x002841E4 & 0xFFFF) # ori $t6, $t6, 0x41e4
  or    $t5, $t1, $t4
  move  $v1, $s0
  sw    $t5, ($a0)
  sw    $t6, 4($a0)
  lui   $t7, 0xe700
  sw    $t7, ($v1)
  sw    $zero, 4($v1)
  addiu $s0, $s0, 8
.L7000436C:
  lw    $ra, 0x1c($sp)
.L70004370:
  move  $v0, $s0
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x68
");

void set_D_800232A0(int arg0) { D_800232A0 = arg0; }

int get_D_800232A0(void) { return D_800232A0; }

void set_D_8002329C(int arg0) { D_8002329C = arg0; }

int get_D_8002329C(void) { return D_8002329C; }

void set_video2_settings_offset_18_1A(short arg0, short arg1) {
  ptr_video_settings2->somethingW = arg0;
  ptr_video_settings2->somethingH = arg1;
}

short get_video2_settings_offset_18(void) {
  return ptr_video_settings2->somethingW;
}

short get_video2_settings_offset_1A(void) {
  return ptr_video_settings2->somethingH;
}

// set video2 text clip width and height.
void set_video2_text_clip_size(short txtClipW, short txtClipH) {
  ptr_video_settings2->txtClipW = txtClipW;
  ptr_video_settings2->txtClipH = txtClipH;
}

// video2 text clip width.
short get_video2_settings_txtClipW(void) {
  return ptr_video_settings2->txtClipW;
}

// video2 text clip height.
short get_video2_settings_txtClipH(void) {
  return ptr_video_settings2->txtClipH;
}

// set video2 width and height.
asm(R"
glabel set_video2_width_height
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  addiu $sp, $sp, -0x18
  lw    $t0, ($v1)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  sh    $a0, 0x1c($t0)
  lw    $t1, ($v1)
  sh    $a1, 0x1e($t1)
  lw    $v0, ($v1)
  lh    $t2, 0x1c($v0)
  lh    $t3, 0x1e($v0)
  mtc1  $t2, $f4
  mtc1  $t3, $f6
  cvt.s.w $f12, $f4
  jal   set_BONDdata_screensize
   cvt.s.w $f14, $f6
  jal   sub_GAME_7F077C5C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

short get_video2_settings_width(void) { return ptr_video_settings2->width; }

short get_video2_settings_height(void) { return ptr_video_settings2->height; }

// set video2 ulx and uly.
asm(R"
glabel set_video2_ulx_uly
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  addiu $sp, $sp, -0x18
  lw    $t0, ($v1)
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  sh    $a0, 0x20($t0)
  lw    $t1, ($v1)
  sh    $a1, 0x22($t1)
  lw    $v0, ($v1)
  lh    $t2, 0x20($v0)
  lh    $t3, 0x22($v0)
  mtc1  $t2, $f4
  mtc1  $t3, $f6
  cvt.s.w $f12, $f4
  jal   set_ulx_uly
   cvt.s.w $f14, $f6
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

short get_video2_settings_ulx(void) { return ptr_video_settings2->ulx; }

short get_video2_settings_uly(void) { return ptr_video_settings2->uly; }

void set_video2_settings_offset_24(int param_1) {
  ptr_video_settings2->anonymous_12 = param_1;
}

asm(R"
glabel setvideo_far
  addiu $sp, $sp, -0x18
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  swc1  $f12, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  lw    $t6, ($v1)
  sw    $ra, 0x14($sp)
  swc1  $f4, 8($t6)
  lw    $v0, ($v1)
  lwc1  $f12, 0x10($v0)
  lwc1  $f14, 8($v0)
  jal   sub_GAME_7F077C30
   lw    $a2, 0xc($v0)
  jal   sub_GAME_7F077C5C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

/**
 *     F12->video2 page width [p@800232A8+C] and something else...
 */
asm(R"
glabel video_related_21
  addiu $sp, $sp, -0x18
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  swc1  $f12, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  lw    $t6, ($v1)
  sw    $ra, 0x14($sp)
  swc1  $f4, 0xc($t6)
  lw    $v0, ($v1)
  lwc1  $f12, 0x10($v0)
  lwc1  $f14, 8($v0)
  jal   sub_GAME_7F077C30
   lw    $a2, 0xc($v0)
  jal   sub_GAME_7F077C5C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

float video_related_23(void) { return ptr_video_settings2->far; }

asm(R"
glabel video_related_24
  addiu $sp, $sp, -0x18
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  swc1  $f14, 0x1c($sp)
  lwc1  $f4, 0x1c($sp)
  lw    $t6, ($v1)
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  swc1  $f4, 8($t6)
  lwc1  $f8, 0x1c($sp)
  lwc1  $f6, 0x18($sp)
  lw    $t7, ($v1)
  div.s $f10, $f6, $f8
  swc1  $f10, 0xc($t7)
  lw    $v0, ($v1)
  lwc1  $f12, 0x10($v0)
  lwc1  $f14, 8($v0)
  jal   sub_GAME_7F077C30
   lw    $a2, 0xc($v0)
  jal   sub_GAME_7F077C5C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_page_height
  addiu $sp, $sp, -0x18
  lui   $v1, %hi(ptr_video_settings2)
  addiu $v1, %lo(ptr_video_settings2) # addiu $v1, $v1, 0x32a8
  swc1  $f12, 0x18($sp)
  lwc1  $f4, 0x18($sp)
  lw    $t6, ($v1)
  sw    $ra, 0x14($sp)
  swc1  $f14, 0x1c($sp)
  swc1  $f4, 0x10($t6)
  lw    $t7, ($v1)
  lwc1  $f6, 0x1c($sp)
  swc1  $f6, 0x14($t7)
  lw    $v0, ($v1)
  lwc1  $f12, 0x10($v0)
  lwc1  $f14, 8($v0)
  jal   sub_GAME_7F077C30
   lw    $a2, 0xc($v0)
  jal   sub_GAME_7F077C5C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel video_related_27
  lui   $v0, %hi(ptr_video_settings2)
  addiu $v0, %lo(ptr_video_settings2) # addiu $v0, $v0, 0x32a8
  lw    $t6, ($v0)
  lwc1  $f4, 0x10($t6)
  swc1  $f4, ($a0)
  lw    $t7, ($v0)
  lwc1  $f6, 0x14($t7)
  jr    $ra
   swc1  $f6, 4($a0)
");

/**
 *     setfillcolour(&A0,A1,A2,A3); generates a setfillcolour op
 *     mode determined by flag at 800232AC: 0=32bit, 1=16bit
 *     accepts: A0=p->display list target, A1=red, A2=green, A3=blue
 *     returns: V0=updated display list target (A0 also updated)
 *     fries: V1,A0,T0,T1,T2,T3,T4,T5,T6,T7,T8,T9
 */
asm(R"
glabel set_setfillcolor
  lui   $t6, %hi(coloroutputmode) 
  lw    $t6, %lo(coloroutputmode)($t6)
  move  $v0, $a0
  lui   $t8, 0xf700
  beqz  $t6, .L70004730
   sll   $t0, $a1, 0x18
  sll   $t8, $a1, 8
  sll   $t0, $a2, 3
  andi  $t1, $t0, 0x7c0
  andi  $t9, $t8, 0xf800
  sra   $t3, $a3, 2
  andi  $t4, $t3, 0x3e
  or    $t2, $t9, $t1
  or    $v1, $t2, $t4
  ori   $t5, $v1, 1
  move  $v0, $a0
  lui   $t7, 0xf700
  sw    $t7, ($v0)
  sll   $t6, $t5, 0x10
  or    $t7, $t6, $t5
  sw    $t7, 4($v0)
  addiu $a0, $a0, 8
  jr    $ra
   move  $v0, $a0

.L70004730:
  sll   $t9, $a2, 0x10
  or    $t1, $t0, $t9
  sll   $t3, $a3, 8
  or    $t2, $t1, $t3
  ori   $t4, $t2, 0xff
  sw    $t4, 4($v0)
  addiu $a0, $a0, 8
  sw    $t8, ($v0)
  jr    $ra
   move  $v0, $a0
");

// image capture routine, jpeg 16bit colour
asm(R"
glabel indy_grab_jpg_16bit
  addiu $sp, $sp, -0x138
  sw    $s1, 0x24($sp)
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  lui   $s1, %hi(aGrab_D_jpeg_1)
  sw    $ra, 0x2c($sp)
  addiu $s1, %lo(aGrab_D_jpeg_1) # addiu $s1, $s1, -0x7b70
  addiu $s0, $sp, 0x38
  addiu $s2, $sp, 0x34
.L7000477C:
  lui   $a2, %hi(jpg_16bit_grabnum)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  move  $a0, $s0
  jal   sprintf
   move  $a1, $s1
  move  $a0, $s0
  jal   check_file_found_on_indy
   move  $a1, $s2
  beqz  $v0, .L700047B8
   lui   $a2, %hi(jpg_16bit_grabnum)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  lui   $at, %hi(jpg_16bit_grabnum)
  addiu $a2, $a2, 1
  b     .L7000477C
   sw    $a2, %lo(jpg_16bit_grabnum)($at)
.L700047B8:
  lui   $a2, %hi(jpg_16bit_grabnum)
  lui   $a1, %hi(aGrab_D_temp_uix)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  addiu $a1, %lo(aGrab_D_temp_uix) # addiu $a1, $a1, -0x7b60
  jal   sprintf
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t6
  multu $v0, $s1
  lui   $t7, %hi(ptr_video_settings2) 
  lw    $t7, %lo(ptr_video_settings2)($t7)
  move  $a0, $s0
  lw    $a1, 0x28($t7)
  mflo  $a2
  sll   $t8, $a2, 1
  jal   indy_send_capture_data
   move  $a2, $t8
  lui   $a2, %hi(jpg_16bit_grabnum)
  lui   $a1, %hi(aUix2pixGrab_D_temp_uix)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  addiu $a1, %lo(aUix2pixGrab_D_temp_uix) # addiu $a1, $a1, -0x7b4c
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(jpg_16bit_grabnum)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_tem)
  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_tem) # addiu $a1, $a1, -0x7b30
  move  $a0, $s0
  jal   sprintf
   move  $a3, $a2
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(jpg_16bit_grabnum)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  lui   $a1, %hi(aImgcopyFjfifGrab_D_temp_rgbGrab_D_)
  addiu $a1, %lo(aImgcopyFjfifGrab_D_temp_rgbGrab_D_) # addiu $a1, $a1, -0x7b04
  move  $a0, $s0
  jal   sprintf
   move  $a3, $a2
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(jpg_16bit_grabnum)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pixGr)
  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pixGr) # addiu $a1, $a1, -0x7ad4
  move  $a0, $s0
  move  $a3, $a2
  jal   sprintf
   sw    $a2, 0x10($sp)
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(jpg_16bit_grabnum)
  lui   $a1, %hi(aImgviewGrab_D_jpeg)
  lw    $a2, %lo(jpg_16bit_grabnum)($a2)
  addiu $a1, %lo(aImgviewGrab_D_jpeg) # addiu $a1, $a1, -0x7a9c
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x138
");

// image capture routine, jpeg 32bit colour
asm(R"
glabel indy_grab_jpg_32bit
  addiu $sp, $sp, -0x138
  sw    $s1, 0x20($sp)
  sw    $s2, 0x24($sp)
  sw    $s0, 0x1c($sp)
  lui   $s1, %hi(aGrab_D_jpeg)
  sw    $ra, 0x2c($sp)
  sw    $s3, 0x28($sp)
  addiu $s1, %lo(aGrab_D_jpeg) # addiu $s1, $s1, -0x7a84
  addiu $s0, $sp, 0x38
  addiu $s2, $sp, 0x34
.L700048FC:
  lui   $s3, %hi(jpg_32bit_grabnum)
  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
  move  $a0, $s0
  jal   sprintf
   move  $a1, $s1
  move  $a0, $s0
  jal   check_file_found_on_indy
   move  $a1, $s2
  beqz  $v0, .L70004938
   lui   $s3, %hi(jpg_32bit_grabnum)
  lw    $s3, %lo(jpg_32bit_grabnum)($s3)
  lui   $at, %hi(jpg_32bit_grabnum)
  addiu $s3, $s3, 1
  b     .L700048FC
   sw    $s3, %lo(jpg_32bit_grabnum)($at)
.L70004938:
  lui   $s3, %hi(jpg_32bit_grabnum)
  lui   $a1, %hi(aGrab_D_temp_uix_0)
  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
  addiu $a1, %lo(aGrab_D_temp_uix_0) # addiu $a1, $a1, -0x7a74
  jal   sprintf
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t6
  multu $v0, $s1
  lui   $a1, %hi(cfb_16_a) # $a1, 0x803b
  addiu $a1, %lo(cfb_16_a) # addiu $a1, $a1, 0x5000
  move  $a0, $s0
  mflo  $a2
  sll   $t7, $a2, 2
  jal   indy_send_capture_data
   move  $a2, $t7
  jal   get_video2_settings_txtClipW
   nop   
  lui   $s3, %hi(jpg_32bit_grabnum)
  lui   $a1, %hi(aUix2pixXsDGrab_D_temp_uix)
  addiu $a1, %lo(aUix2pixXsDGrab_D_temp_uix) # addiu $a1, $a1, -0x7a60
  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
  move  $a0, $s0
  jal   sprintf
   move  $a2, $v0
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(jpg_32bit_grabnum)
  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_t_0)
  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_t_0) # addiu $a1, $a1, -0x7a40
  move  $a0, $s0
  jal   sprintf
   move  $a2, $a3
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(jpg_32bit_grabnum)
  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
  lui   $a1, %hi(aImgcopyFjfifGrab_D_temp_rgbGrab__0)
  addiu $a1, %lo(aImgcopyFjfifGrab_D_temp_rgbGrab__0) # addiu $a1, $a1, -0x7a14
  move  $a0, $s0
  jal   sprintf
   move  $a2, $a3
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(jpg_32bit_grabnum)
  lw    $a3, %lo(jpg_32bit_grabnum)($s3)
  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix_0)
  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix_0) # addiu $a1, $a1, -0x79e4
  move  $a0, $s0
  move  $a2, $a3
  jal   sprintf
   sw    $a3, 0x10($sp)
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(jpg_32bit_grabnum)
  lui   $a1, %hi(aImgviewGrab_D_jpeg_0)
  lw    $a2, %lo(jpg_32bit_grabnum)($s3)
  addiu $a1, %lo(aImgviewGrab_D_jpeg_0) # addiu $a1, $a1, -0x79ac
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  lw    $s2, 0x24($sp)
  lw    $s3, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x138
");

// image capture routine, rgb 16bit colour.
asm(R"
glabel indy_grab_rgb_16bit
  addiu $sp, $sp, -0x130
  sw    $s1, 0x1c($sp)
  sw    $s2, 0x20($sp)
  sw    $s0, 0x18($sp)
  lui   $s1, %hi(aGrab_D_rgb)
  sw    $ra, 0x24($sp)
  addiu $s1, %lo(aGrab_D_rgb) # addiu $s1, $s1, -0x7994
  addiu $s0, $sp, 0x30
  addiu $s2, $sp, 0x2c
.L70004A84:
  lui   $a2, %hi(rgb_16bit_grabnum)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  move  $a0, $s0
  jal   sprintf
   move  $a1, $s1
  move  $a0, $s0
  jal   check_file_found_on_indy
   move  $a1, $s2
  beqz  $v0, .L70004AC0
   lui   $a2, %hi(rgb_16bit_grabnum)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  lui   $at, %hi(rgb_16bit_grabnum)
  addiu $a2, $a2, 1
  b     .L70004A84
   sw    $a2, %lo(rgb_16bit_grabnum)($at)
.L70004AC0:
  lui   $a2, %hi(rgb_16bit_grabnum)
  lui   $a1, %hi(aGrab_D_temp_uix_1)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  addiu $a1, %lo(aGrab_D_temp_uix_1) # addiu $a1, $a1, -0x7988
  jal   sprintf
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t6
  multu $v0, $s1
  lui   $t7, %hi(ptr_video_settings2) 
  lw    $t7, %lo(ptr_video_settings2)($t7)
  move  $a0, $s0
  lw    $a1, 0x28($t7)
  mflo  $a2
  sll   $t8, $a2, 1
  jal   indy_send_capture_data
   move  $a2, $t8
  lui   $a2, %hi(rgb_16bit_grabnum)
  lui   $a1, %hi(aUix2pixGrab_D_temp_uix_0)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  addiu $a1, %lo(aUix2pixGrab_D_temp_uix_0) # addiu $a1, $a1, -0x7974
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(rgb_16bit_grabnum)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_rgb)
  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_rgb) # addiu $a1, $a1, -0x7958
  move  $a0, $s0
  jal   sprintf
   move  $a3, $a2
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(rgb_16bit_grabnum)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix)
  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix) # addiu $a1, $a1, -0x7930
  move  $a0, $s0
  jal   sprintf
   move  $a3, $a2
  jal   response_from_command_string
   move  $a0, $s0
  lui   $a2, %hi(rgb_16bit_grabnum)
  lui   $a1, %hi(aImgviewGrab_D_rgb)
  lw    $a2, %lo(rgb_16bit_grabnum)($a2)
  addiu $a1, %lo(aImgviewGrab_D_rgb) # addiu $a1, $a1, -0x7908
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x130
");

// image capture routine, rgb 32bit colour.
asm(R"
glabel indy_grab_rgb_32bit
  addiu $sp, $sp, -0x130
  sw    $s1, 0x18($sp)
  sw    $s2, 0x1c($sp)
  sw    $s0, 0x14($sp)
  lui   $s1, %hi(aGrab_D_rgb_0)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  addiu $s1, %lo(aGrab_D_rgb_0) # addiu $s1, $s1, -0x78f4
  addiu $s0, $sp, 0x30
  addiu $s2, $sp, 0x2c
.L70004BDC:
  lui   $s3, %hi(rgb_32bit_grabnum)
  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
  move  $a0, $s0
  jal   sprintf
   move  $a1, $s1
  move  $a0, $s0
  jal   check_file_found_on_indy
   move  $a1, $s2
  beqz  $v0, .L70004C18
   lui   $s3, %hi(rgb_32bit_grabnum)
  lw    $s3, %lo(rgb_32bit_grabnum)($s3)
  lui   $at, %hi(rgb_32bit_grabnum)
  addiu $s3, $s3, 1
  b     .L70004BDC
   sw    $s3, %lo(rgb_32bit_grabnum)($at)
.L70004C18:
  lui   $s3, %hi(rgb_32bit_grabnum)
  lui   $a1, %hi(aGrab_D_temp_uix_2)
  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
  addiu $a1, %lo(aGrab_D_temp_uix_2) # addiu $a1, $a1, -0x78e8
  jal   sprintf
   move  $a0, $s0
  jal   get_video2_settings_txtClipW
   nop   
  sll   $s1, $v0, 0x10
  sra   $t6, $s1, 0x10
  jal   get_video2_settings_txtClipH
   move  $s1, $t6
  multu $v0, $s1
  lui   $a1, %hi(cfb_16_a) # $a1, 0x803b
  addiu $a1, %lo(cfb_16_a) # addiu $a1, $a1, 0x5000
  move  $a0, $s0
  mflo  $a2
  sll   $t7, $a2, 2
  jal   indy_send_capture_data
   move  $a2, $t7
  jal   get_video2_settings_txtClipW
   nop   
  lui   $s3, %hi(rgb_32bit_grabnum)
  lui   $a1, %hi(aUix2pixXsDGrab_D_temp_uix_0)
  addiu $a1, %lo(aUix2pixXsDGrab_D_temp_uix_0) # addiu $a1, $a1, -0x78d4
  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
  move  $a0, $s0
  jal   sprintf
   move  $a2, $v0
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(rgb_32bit_grabnum)
  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
  lui   $a1, %hi(aFromaliasGrab_D_temp_pixGrab_D_r_0)
  addiu $a1, %lo(aFromaliasGrab_D_temp_pixGrab_D_r_0) # addiu $a1, $a1, -0x78b4
  move  $a0, $s0
  jal   sprintf
   move  $a2, $a3
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(rgb_32bit_grabnum)
  lw    $a3, %lo(rgb_32bit_grabnum)($s3)
  lui   $a1, %hi(aRmGrab_D_temp_uixGrab_D_temp_pix_1)
  addiu $a1, %lo(aRmGrab_D_temp_uixGrab_D_temp_pix_1) # addiu $a1, $a1, -0x788c
  move  $a0, $s0
  jal   sprintf
   move  $a2, $a3
  jal   response_from_command_string
   move  $a0, $s0
  lui   $s3, %hi(rgb_32bit_grabnum)
  lui   $a1, %hi(aImgviewGrab_D_rgb_0)
  lw    $a2, %lo(rgb_32bit_grabnum)($s3)
  addiu $a1, %lo(aImgviewGrab_D_rgb_0) # addiu $a1, $a1, -0x7864
  jal   sprintf
   move  $a0, $s0
  jal   response_from_command_string
   move  $a0, $s0
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x130
");
