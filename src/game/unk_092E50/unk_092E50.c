float flt_CODE_bss_80079E80, flt_CODE_bss_80079E84, flt_CODE_bss_80079E88;

// Gfx MipMap2C_Something_Setup[]={};
unsigned long long MipMap2C_Something_Setup[] = {
    0xF580080000018060, 0xF580080001018060, 0xF200200200000000,
    0xF200200201000000, 0xFA00000FFFFFFFFF, 0xBA00110200000000,
    0xBA000C0200002000, 0xFC272C041F1093FF, 0xB900031D0C192078,
    0xBA00100100000000, 0xBA00140200100000, 0xB700000000002000,
    0xB800000000000000};

// Gfx MipMap2C_Something2_Setup[]={};
unsigned long long MipMap2C_Something2_Setup[] = {
    0xF548040000014050, 0xF548040001014050, 0xF200200200000000,
    0xF200200201000000, 0xFA00000FFFFFFFFF, 0xBA00110200000000,
    0xBA000C0200002000, 0xFC272C041F1093FF, 0xB900031D0C192078,
    0xBA00100100000000, 0xBA00140200100000, 0xB700000000002000,
    0xB800000000000000};

// End Dl means this gfx list cannot go any further. perhaps below is a vtx
// array?

unsigned int D_8003FD90 = 0;
float D_8003FD94[3] = {0};
unsigned int D_8003FDA0 = 0;
unsigned int D_8003FDA4 = 0xFFFFFFFF;
unsigned long long D_8003FDA8[] = {0x100,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0x3F800000,
                                   0,
                                   0,
                                   0x3F80000000000000,
                                   0,
                                   0x3F800000,
                                   0,
                                   0,
                                   0x3F80000000000000,
                                   0,
                                   0,
                                   0xBF800000,
                                   0x3F800000,
                                   0,
                                   0,
                                   0,
                                   0xC19FFFFE00000000,
                                   0x419FFFFE00000000,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0xBF80000000000000,
                                   0xBF800000,
                                   0,
                                   0xBF80000000000000,
                                   0xBF800000,
                                   0x3F800000,
                                   0,
                                   0x3F80000000000000,
                                   0x3F800000,
                                   0,
                                   0x3F80000000000000,
                                   0,
                                   0x3F8000003F800000,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0x447A000000000000,
                                   0,
                                   0xFF000000,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0,
                                   0};

asm(R"
.late_rodata
glabel D_80057510
.word 0x3dcccccd /*0.1*/
glabel D_80057514
.word 0x40c90fd0 /*6.2831802*/
glabel D_80057518
.word 0x3d23d70a /*0.039999999*/
.text
glabel sub_GAME_7F092E50
  lui   $t6, %hi(clock_timer) 
  lw    $t6, %lo(clock_timer)($t6)
  li    $at, 0x43800000 # 256.000000
  mtc1  $at, $f0
  mtc1  $t6, $f4
  li    $at, 0x3E800000 # 0.250000
  mtc1  $at, $f8
  cvt.s.w $f16, $f4
  lui   $t0, %hi(flt_CODE_bss_80079E80) 
  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x6180
  lwc1  $f6, ($t0)
  addiu $sp, $sp, -0x18
  mtc1  $zero, $f18
  mul.s $f10, $f16, $f8
  sw    $ra, 0x14($sp)
  lui   $at, %hi(D_80057510)
  li    $t8, 1
  add.s $f4, $f6, $f10
  swc1  $f4, ($t0)
  lwc1  $f14, ($t0)
  c.le.s $f0, $f14
  nop   
  bc1fl .L7F092EC0
   c.lt.s $f14, $f18
  sub.s $f8, $f14, $f0
  swc1  $f8, ($t0)
  lwc1  $f14, ($t0)
  c.lt.s $f14, $f18
.L7F092EC0:
  nop   
  bc1f  .L7F092ED8
   nop   
  add.s $f6, $f14, $f0
  swc1  $f6, ($t0)
  lwc1  $f14, ($t0)
.L7F092ED8:
  lwc1  $f4, %lo(D_80057510)($at)
  lui   $a3, %hi(flt_CODE_bss_80079E84)
  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x617c
  mul.s $f8, $f16, $f4
  lwc1  $f10, ($a3)
  lui   $at, %hi(D_80057514)
  add.s $f6, $f10, $f8
  swc1  $f6, ($a3)
  lwc1  $f2, ($a3)
  c.le.s $f0, $f2
  nop   
  bc1fl .L7F092F1C
   c.lt.s $f2, $f18
  sub.s $f4, $f2, $f0
  swc1  $f4, ($a3)
  lwc1  $f2, ($a3)
  c.lt.s $f2, $f18
.L7F092F1C:
  nop   
  bc1f  .L7F092F34
   nop   
  add.s $f10, $f2, $f0
  swc1  $f10, ($a3)
  lwc1  $f2, ($a3)
.L7F092F34:
  lwc1  $f0, %lo(D_80057514)($at)
  lui   $at, %hi(D_80057518)
  lwc1  $f6, %lo(D_80057518)($at)
  lui   $a2, %hi(flt_CODE_bss_80079E88)
  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x6178
  mul.s $f4, $f16, $f6
  lwc1  $f8, ($a2)
  add.s $f10, $f8, $f4
  swc1  $f10, ($a2)
  lwc1  $f12, ($a2)
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F092F7C
   c.lt.s $f12, $f18
  sub.s $f6, $f12, $f0
  swc1  $f6, ($a2)
  lwc1  $f12, ($a2)
  c.lt.s $f12, $f18
.L7F092F7C:
  nop   
  bc1fl .L7F092F98
   cfc1  $t7, $31
  add.s $f8, $f12, $f0
  swc1  $f8, ($a2)
  lwc1  $f12, ($a2)
  cfc1  $t7, $31
.L7F092F98:
  ctc1  $t8, $31
  lui   $v0, %hi(MipMap2C_Something_Setup)
  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
  cvt.w.s $f4, $f14
  lw    $v1, 0x10($v0)
  li    $at, 0x4F000000 # 2147483648.000000
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  beql  $t8, $zero, .L7F09300C
   mfc1  $t8, $f4
  mtc1  $at, $f4
  li    $t8, 1
  sub.s $f4, $f14, $f4
  ctc1  $t8, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t8, $31
  nop   
  andi  $t8, $t8, 0x78
  bnez  $t8, .L7F093000
   nop   
  mfc1  $t8, $f4
  lui   $at, 0x8000
  b     .L7F093018
   or    $t8, $t8, $at
.L7F093000:
  b     .L7F093018
   li    $t8, -1
  mfc1  $t8, $f4
.L7F09300C:
  nop   
  bltz  $t8, .L7F093000
   nop   
.L7F093018:
  ctc1  $t7, $31
  li    $t7, 1
  srl   $t1, $v1, 0xc
  xor   $t2, $t8, $t1
  cfc1  $t6, $31
  ctc1  $t7, $31
  sll   $t3, $t2, 0x14
  srl   $t4, $t3, 8
  cvt.w.s $f10, $f2
  xor   $t5, $t4, $v1
  sw    $t5, 0x10($v0)
  li    $at, 0x4F000000 # 2147483648.000000
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  beql  $t7, $zero, .L7F0930A4
   mfc1  $t7, $f10
  mtc1  $at, $f10
  li    $t7, 1
  sub.s $f10, $f2, $f10
  ctc1  $t7, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t7, $31
  nop   
  andi  $t7, $t7, 0x78
  bnez  $t7, .L7F093098
   nop   
  mfc1  $t7, $f10
  lui   $at, 0x8000
  b     .L7F0930B0
   or    $t7, $t7, $at
.L7F093098:
  b     .L7F0930B0
   li    $t7, -1
  mfc1  $t7, $f10
.L7F0930A4:
  nop   
  bltz  $t7, .L7F093098
   nop   
.L7F0930B0:
  ctc1  $t6, $31
  lhu   $t1, 0x12($v0)
  lw    $a0, 0x18($v0)
  trunc.w.s $f6, $f14
  andi  $t9, $t7, 0xfff
  andi  $t2, $t1, 0xf000
  or    $t3, $t9, $t2
  mfc1  $t5, $f6
  srl   $t1, $a0, 0xc
  trunc.w.s $f8, $f2
  addiu $t6, $t5, 0x5a
  andi  $t8, $t6, 0xff
  xor   $t9, $t8, $t1
  sh    $t3, 0x12($v0)
  sll   $t2, $t9, 0x14
  srl   $t3, $t2, 8
  xor   $t4, $t3, $a0
  mfc1  $t6, $f8
  sw    $t4, 0x18($v0)
  lhu   $t2, 0x1a($v0)
  addiu $t1, $t6, 0x96
  andi  $t9, $t1, 0xff
  andi  $t3, $t2, 0xf000
  or    $t4, $t9, $t3
  jal   sinf
   sh    $t4, 0x1a($v0)
  li    $at, 0x42FE0000 # 127.000000
  mtc1  $at, $f4
  li    $at, 0x43000000 # 128.000000
  mtc1  $at, $f6
  mul.s $f10, $f0, $f4
  li    $t6, 1
  lui   $v0, %hi(MipMap2C_Something_Setup)
  lui   $v1, %hi(MipMap2C_Something2_Setup)
  lui   $a2, %hi(flt_CODE_bss_80079E88)
  lui   $a3, %hi(flt_CODE_bss_80079E84)
  lui   $t0, %hi(flt_CODE_bss_80079E80) 
  add.s $f8, $f10, $f6
  addiu $t0, %lo(flt_CODE_bss_80079E80) # addiu $t0, $t0, -0x6180
  addiu $a3, %lo(flt_CODE_bss_80079E84) # addiu $a3, $a3, -0x617c
  addiu $a2, %lo(flt_CODE_bss_80079E88) # addiu $a2, $a2, -0x6178
  cfc1  $t5, $31
  ctc1  $t6, $31
  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x2d8
  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
  cvt.w.s $f4, $f8
  li    $at, 0x4F000000 # 2147483648.000000
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  beql  $t6, $zero, .L7F0931C8
   mfc1  $t6, $f4
  mtc1  $at, $f4
  li    $t6, 1
  sub.s $f4, $f8, $f4
  ctc1  $t6, $31
  nop   
  cvt.w.s $f4, $f4
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F0931BC
   nop   
  mfc1  $t6, $f4
  lui   $at, 0x8000
  b     .L7F0931D4
   or    $t6, $t6, $at
.L7F0931BC:
  b     .L7F0931D4
   li    $t6, -1
  mfc1  $t6, $f4
.L7F0931C8:
  nop   
  bltz  $t6, .L7F0931BC
   nop   
.L7F0931D4:
  ctc1  $t5, $31
  li    $t9, 1
  lwc1  $f14, ($t0)
  lw    $t7, 0x20($v0)
  cfc1  $t2, $31
  ctc1  $t9, $31
  li    $at, -256
  and   $t8, $t7, $at
  cvt.w.s $f10, $f14
  or    $t1, $t6, $t8
  sw    $t1, 0x20($v0)
  li    $at, 0x4F000000 # 2147483648.000000
  cfc1  $t9, $31
  lw    $a0, 0x10($v1)
  andi  $t9, $t9, 0x78
  beql  $t9, $zero, .L7F093260
   mfc1  $t9, $f10
  mtc1  $at, $f10
  li    $t9, 1
  sub.s $f10, $f14, $f10
  ctc1  $t9, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t9, $31
  nop   
  andi  $t9, $t9, 0x78
  bnez  $t9, .L7F093254
   nop   
  mfc1  $t9, $f10
  lui   $at, 0x8000
  b     .L7F09326C
   or    $t9, $t9, $at
.L7F093254:
  b     .L7F09326C
   li    $t9, -1
  mfc1  $t9, $f10
.L7F093260:
  nop   
  bltz  $t9, .L7F093254
   nop   
.L7F09326C:
  ctc1  $t2, $31
  li    $t2, 1
  lwc1  $f2, ($a3)
  srl   $t4, $a0, 0xc
  cfc1  $t1, $31
  ctc1  $t2, $31
  xor   $t5, $t9, $t4
  sll   $t7, $t5, 0x14
  cvt.w.s $f6, $f2
  srl   $t6, $t7, 8
  xor   $t8, $t6, $a0
  sw    $t8, 0x10($v1)
  cfc1  $t2, $31
  li    $at, 0x4F000000 # 2147483648.000000
  andi  $t2, $t2, 0x78
  beql  $t2, $zero, .L7F0932F8
   mfc1  $t2, $f6
  mtc1  $at, $f6
  li    $t2, 1
  sub.s $f6, $f2, $f6
  ctc1  $t2, $31
  nop   
  cvt.w.s $f6, $f6
  cfc1  $t2, $31
  nop   
  andi  $t2, $t2, 0x78
  bnez  $t2, .L7F0932EC
   nop   
  mfc1  $t2, $f6
  lui   $at, 0x8000
  b     .L7F093304
   or    $t2, $t2, $at
.L7F0932EC:
  b     .L7F093304
   li    $t2, -1
  mfc1  $t2, $f6
.L7F0932F8:
  nop   
  bltz  $t2, .L7F0932EC
   nop   
.L7F093304:
  ctc1  $t1, $31
  lhu   $t4, 0x12($v1)
  lw    $a1, 0x18($v1)
  trunc.w.s $f8, $f14
  andi  $t3, $t2, 0xfff
  andi  $t5, $t4, 0xf000
  or    $t7, $t3, $t5
  mfc1  $t8, $f8
  srl   $t4, $a1, 0xc
  trunc.w.s $f4, $f2
  addiu $t1, $t8, 0x5a
  andi  $t9, $t1, 0xff
  xor   $t3, $t9, $t4
  sh    $t7, 0x12($v1)
  sll   $t5, $t3, 0x14
  srl   $t7, $t5, 8
  xor   $t6, $t7, $a1
  mfc1  $t1, $f4
  sw    $t6, 0x18($v1)
  lhu   $t5, 0x1a($v1)
  addiu $t4, $t1, 0x96
  andi  $t3, $t4, 0xff
  andi  $t7, $t5, 0xf000
  or    $t6, $t3, $t7
  sh    $t6, 0x1a($v1)
  jal   sinf
   lwc1  $f12, ($a2)
  li    $at, 0x42FE0000 # 127.000000
  mtc1  $at, $f10
  li    $at, 0x43000000 # 128.000000
  mtc1  $at, $f8
  mul.s $f6, $f0, $f10
  li    $t1, 1
  lui   $v0, %hi(MipMap2C_Something_Setup)
  lui   $v1, %hi(MipMap2C_Something2_Setup)
  addiu $v1, %lo(MipMap2C_Something2_Setup) # addiu $v1, $v1, -0x2d8
  addiu $v0, %lo(MipMap2C_Something_Setup) # addiu $v0, $v0, -0x340
  li    $at, 0x4F000000 # 2147483648.000000
  add.s $f4, $f6, $f8
  cfc1  $t8, $31
  ctc1  $t1, $31
  nop   
  cvt.w.s $f10, $f4
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  beql  $t1, $zero, .L7F09340C
   mfc1  $t1, $f10
  mtc1  $at, $f10
  li    $t1, 1
  sub.s $f10, $f4, $f10
  ctc1  $t1, $31
  nop   
  cvt.w.s $f10, $f10
  cfc1  $t1, $31
  nop   
  andi  $t1, $t1, 0x78
  bnez  $t1, .L7F093400
   nop   
  mfc1  $t1, $f10
  lui   $at, 0x8000
  b     .L7F093418
   or    $t1, $t1, $at
.L7F093400:
  b     .L7F093418
   li    $t1, -1
  mfc1  $t1, $f10
.L7F09340C:
  nop   
  bltz  $t1, .L7F093400
   nop   
.L7F093418:
  lw    $t2, 0x20($v0)
  lw    $ra, 0x14($sp)
  li    $at, -256
  and   $t9, $t2, $at
  or    $t4, $t1, $t9
  ctc1  $t8, $31
  sw    $t4, 0x20($v1)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel sub_GAME_7F09343C
  addiu $sp, $sp, -0x30
  beqz  $a1, .L7F093468
   sw    $ra, 0x14($sp)
  move  $v0, $a0
  lui   $t7, %hi(MipMap2C_Something_Setup) 
  addiu $t7, %lo(MipMap2C_Something_Setup) # addiu $t7, $t7, -0x340
  lui   $t6, 0x600
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  b     .L7F093648
   addiu $a0, $a0, 8
.L7F093468:
  lui   $t0, %hi(0xF5100004) # $t0, 0xf510
  move  $v0, $a0
  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
  ori   $t0, (0xF5100800 & 0xFFFF) # ori $t0, $t0, 0x800
  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
  addiu $v1, $a0, 8
  sw    $t8, 4($v0)
  sw    $t0, ($v0)
  lui   $t9, (0x01014050 >> 16) # lui $t9, 0x101
  ori   $t9, (0x01014050 & 0xFFFF) # ori $t9, $t9, 0x4050
  addiu $a1, $v1, 8
  sw    $t9, 4($v1)
  sw    $t0, ($v1)
  addiu $a2, $a1, 8
  lui   $t2, 0xf200
  sw    $t2, ($a1)
  sw    $zero, 4($a1)
  lui   $t3, (0xF205A096 >> 16) # lui $t3, 0xf205
  ori   $t3, (0xF205A096 & 0xFFFF) # ori $t3, $t3, 0xa096
  lui   $t4, 0x100
  sw    $t4, 4($a2)
  sw    $t3, ($a2)
  addiu $a3, $a2, 8
  addiu $a0, $a3, 8
  lui   $at, %hi(flt_CODE_bss_80079E88)
  lwc1  $f12, %lo(flt_CODE_bss_80079E88)($at)
  sw    $a0, 0x30($sp)
  jal   sinf
   sw    $a3, 0x18($sp)
  li    $at, 0x42FE0000 # 127.000000
  mtc1  $at, $f4
  li    $at, 0x43000000 # 128.000000
  mtc1  $at, $f8
  mul.s $f6, $f0, $f4
  li    $t6, 1
  lw    $a0, 0x30($sp)
  lui   $t2, (0xBA001102 >> 16) # lui $t2, 0xba00
  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
  move  $v0, $a0
  addiu $a0, $a0, 8
  add.s $f10, $f6, $f8
  move  $v1, $a0
  addiu $a0, $a0, 8
  move  $a1, $a0
  cfc1  $t5, $31
  ctc1  $t6, $31
  lui   $t4, (0xFC272C04 >> 16) # lui $t4, 0xfc27
  lw    $a3, 0x18($sp)
  cvt.w.s $f16, $f10
  li    $t1, 8192
  li    $t9, -1
  ori   $t2, (0xBA001102 & 0xFFFF) # ori $t2, $t2, 0x1102
  cfc1  $t6, $31
  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
  ori   $t4, (0xFC272C04 & 0xFFFF) # ori $t4, $t4, 0x2c04
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F093598
   addiu $a0, $a0, 8
  li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f16
  li    $t6, 1
  sub.s $f16, $f10, $f16
  ctc1  $t6, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F093590
   nop   
  mfc1  $t6, $f16
  lui   $at, 0x8000
  b     .L7F0935A8
   or    $t6, $t6, $at
.L7F093590:
  b     .L7F0935A8
   li    $t6, -1
.L7F093598:
  mfc1  $t6, $f16
  nop   
  bltz  $t6, .L7F093590
   nop   
.L7F0935A8:
  andi  $t7, $t6, 0xff
  lui   $at, 0xfa00
  or    $t8, $t7, $at
  sw    $t8, ($a3)
  sw    $t9, 4($a3)
  sw    $zero, 4($v0)
  sw    $t2, ($v0)
  ctc1  $t5, $31
  sw    $t1, 4($v1)
  sw    $t3, ($v1)
  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
  move  $a2, $a0
  sw    $t5, 4($a1)
  sw    $t4, ($a1)
  addiu $a0, $a0, 8
  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
  move  $t0, $a0
  sw    $t7, 4($a2)
  sw    $t6, ($a2)
  addiu $a0, $a0, 8
  lui   $t8, (0xBA001001 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001001 & 0xFFFF) # ori $t8, $t8, 0x1001
  move  $v0, $a0
  sw    $t8, ($t0)
  sw    $zero, %lo(0xF5100004)($t0)
  addiu $a0, $a0, 8
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  lui   $t2, 0x10
  move  $v1, $a0
  sw    $t2, 4($v0)
  sw    $t9, ($v0)
  lui   $t3, 0xb700
  sw    $t3, ($v1)
  sw    $t1, 4($v1)
  addiu $a0, $a0, 8
.L7F093648:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F09365C
  addiu $sp, $sp, -0x30
  beqz  $a1, .L7F093688
   sw    $ra, 0x14($sp)
  move  $v0, $a0
  lui   $t7, %hi(MipMap2C_Something2_Setup) 
  addiu $t7, %lo(MipMap2C_Something2_Setup) # addiu $t7, $t7, -0x2d8
  lui   $t6, 0x600
  sw    $t6, ($v0)
  sw    $t7, 4($v0)
  b     .L7F093868
   addiu $a0, $a0, 8
.L7F093688:
  lui   $t0, %hi(0xF5480004) # $t0, 0xf548
  move  $v0, $a0
  lui   $t8, (0x00014050 >> 16) # lui $t8, 1
  ori   $t0, (0xF5480400 & 0xFFFF) # ori $t0, $t0, 0x400
  ori   $t8, (0x00014050 & 0xFFFF) # ori $t8, $t8, 0x4050
  addiu $v1, $a0, 8
  sw    $t8, 4($v0)
  sw    $t0, ($v0)
  lui   $t9, (0x01014050 >> 16) # lui $t9, 0x101
  ori   $t9, (0x01014050 & 0xFFFF) # ori $t9, $t9, 0x4050
  addiu $a1, $v1, 8
  sw    $t9, 4($v1)
  sw    $t0, ($v1)
  addiu $a2, $a1, 8
  lui   $t2, 0xf200
  sw    $t2, ($a1)
  sw    $zero, 4($a1)
  lui   $t3, (0xF205A096 >> 16) # lui $t3, 0xf205
  ori   $t3, (0xF205A096 & 0xFFFF) # ori $t3, $t3, 0xa096
  lui   $t4, 0x100
  sw    $t4, 4($a2)
  sw    $t3, ($a2)
  addiu $a3, $a2, 8
  addiu $a0, $a3, 8
  lui   $at, %hi(flt_CODE_bss_80079E88)
  lwc1  $f12, %lo(flt_CODE_bss_80079E88)($at)
  sw    $a0, 0x30($sp)
  jal   sinf
   sw    $a3, 0x18($sp)
  li    $at, 0x42FE0000 # 127.000000
  mtc1  $at, $f4
  li    $at, 0x43000000 # 128.000000
  mtc1  $at, $f8
  mul.s $f6, $f0, $f4
  li    $t6, 1
  lw    $a0, 0x30($sp)
  lui   $t2, (0xBA001102 >> 16) # lui $t2, 0xba00
  lui   $t3, (0xBA000C02 >> 16) # lui $t3, 0xba00
  move  $v0, $a0
  addiu $a0, $a0, 8
  add.s $f10, $f6, $f8
  move  $v1, $a0
  addiu $a0, $a0, 8
  move  $a1, $a0
  cfc1  $t5, $31
  ctc1  $t6, $31
  lui   $t4, (0xFC272C04 >> 16) # lui $t4, 0xfc27
  lw    $a3, 0x18($sp)
  cvt.w.s $f16, $f10
  li    $t1, 8192
  li    $t9, -1
  ori   $t2, (0xBA001102 & 0xFFFF) # ori $t2, $t2, 0x1102
  cfc1  $t6, $31
  ori   $t3, (0xBA000C02 & 0xFFFF) # ori $t3, $t3, 0xc02
  ori   $t4, (0xFC272C04 & 0xFFFF) # ori $t4, $t4, 0x2c04
  andi  $t6, $t6, 0x78
  beqz  $t6, .L7F0937B8
   addiu $a0, $a0, 8
  li    $at, 0x4F000000 # 2147483648.000000
  mtc1  $at, $f16
  li    $t6, 1
  sub.s $f16, $f10, $f16
  ctc1  $t6, $31
  nop   
  cvt.w.s $f16, $f16
  cfc1  $t6, $31
  nop   
  andi  $t6, $t6, 0x78
  bnez  $t6, .L7F0937B0
   nop   
  mfc1  $t6, $f16
  lui   $at, 0x8000
  b     .L7F0937C8
   or    $t6, $t6, $at
.L7F0937B0:
  b     .L7F0937C8
   li    $t6, -1
.L7F0937B8:
  mfc1  $t6, $f16
  nop   
  bltz  $t6, .L7F0937B0
   nop   
.L7F0937C8:
  andi  $t7, $t6, 0xff
  lui   $at, 0xfa00
  or    $t8, $t7, $at
  sw    $t8, ($a3)
  sw    $t9, 4($a3)
  sw    $zero, 4($v0)
  sw    $t2, ($v0)
  ctc1  $t5, $31
  sw    $t1, 4($v1)
  sw    $t3, ($v1)
  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
  move  $a2, $a0
  sw    $t5, 4($a1)
  sw    $t4, ($a1)
  addiu $a0, $a0, 8
  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
  move  $t0, $a0
  sw    $t7, 4($a2)
  sw    $t6, ($a2)
  addiu $a0, $a0, 8
  lui   $t8, (0xBA001001 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001001 & 0xFFFF) # ori $t8, $t8, 0x1001
  move  $v0, $a0
  sw    $t8, ($t0)
  sw    $zero, %lo(0xF5480004)($t0)
  addiu $a0, $a0, 8
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  lui   $t2, 0x10
  move  $v1, $a0
  sw    $t2, 4($v0)
  sw    $t9, ($v0)
  lui   $t3, 0xb700
  sw    $t3, ($v1)
  sw    $t1, 4($v1)
  addiu $a0, $a0, 8
.L7F093868:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x30
  move  $v0, $a0
  jr    $ra
   nop   
");
