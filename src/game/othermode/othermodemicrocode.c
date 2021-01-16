int is_less_than_certain_power_of_2(int number) {
  if (number < 2) {
    return 0;
  }
  if (number < 3) {
    return 1;
  }
  if (number < 5) {
    return 2;
  }
  if (number < 9) {
    return 3;
  }
  if (number < 0x11) {
    return 4;
  }
  if (number < 0x21) {
    return 5;
  }
  if (number < 0x41) {
    return 6;
  }
  if (number < 0x81) {
    return 7;
  }
  return 8;
}

asm(R"
.late_rodata
glabel D_80054F90
.word 0x3f7fffef /*0.99999899*/
.text
glabel ceil8000
  li    $at, 0x47000000 # 32768.000000
  mtc1  $at, $f4
  addiu $t6, $a0, 0xf
  bgez  $t6, .L7F076664
   sra   $t7, $t6, 4
  addiu $at, $t6, 0xf
  sra   $t7, $at, 4
.L7F076664:
  sll   $t8, $t7, 4
  mtc1  $t8, $f6
  lui   $at, %hi(D_80054F90)
  cvt.s.w $f8, $f6
  div.s $f0, $f4, $f8
  lwc1  $f4, %lo(D_80054F90)($at)
  trunc.w.s $f10, $f0
  mfc1  $v1, $f10
  nop   
  mtc1  $v1, $f16
  nop   
  cvt.s.w $f18, $f16
  sub.s $f6, $f0, $f18
  add.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t1, $f10
  jr    $ra
   addu  $v0, $v1, $t1
");

asm(R"
.late_rodata
glabel D_80054F94
.word 0x3f7fffef /*0.99999899*/
.text
glabel ceil4000
  li    $at, 0x46800000 # 16384.000000
  mtc1  $at, $f4
  addiu $t6, $a0, 7
  bgez  $t6, .L7F0766C8
   sra   $t7, $t6, 3
  addiu $at, $t6, 7
  sra   $t7, $at, 3
.L7F0766C8:
  sll   $t8, $t7, 3
  mtc1  $t8, $f6
  lui   $at, %hi(D_80054F94)
  cvt.s.w $f8, $f6
  div.s $f0, $f4, $f8
  lwc1  $f4, %lo(D_80054F94)($at)
  trunc.w.s $f10, $f0
  mfc1  $v1, $f10
  nop   
  mtc1  $v1, $f16
  nop   
  cvt.s.w $f18, $f16
  sub.s $f6, $f0, $f18
  add.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t1, $f10
  jr    $ra
   addu  $v0, $v1, $t1
");

asm(R"
.late_rodata
glabel D_80054F98
.word 0x3f7fffef /*0.99999899*/
.text
glabel ceil2000
  li    $at, 0x46000000 # 8192.000000
  mtc1  $at, $f4
  addiu $t6, $a0, 3
  bgez  $t6, .L7F07672C
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7F07672C:
  sll   $t8, $t7, 2
  mtc1  $t8, $f6
  lui   $at, %hi(D_80054F98)
  cvt.s.w $f8, $f6
  div.s $f0, $f4, $f8
  lwc1  $f4, %lo(D_80054F98)($at)
  trunc.w.s $f10, $f0
  mfc1  $v1, $f10
  nop   
  mtc1  $v1, $f16
  nop   
  cvt.s.w $f18, $f16
  sub.s $f6, $f0, $f18
  add.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t1, $f10
  jr    $ra
   addu  $v0, $v1, $t1
");

asm(R"
.late_rodata
glabel D_80054F9C
.word 0x3f7fffef /*0.99999899*/
.text
glabel ceil1000
  li    $at, 0x45800000 # 4096.000000
  mtc1  $at, $f4
  addiu $t6, $a0, 3
  bgez  $t6, .L7F076790
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7F076790:
  sll   $t8, $t7, 2
  mtc1  $t8, $f6
  lui   $at, %hi(D_80054F9C)
  cvt.s.w $f8, $f6
  div.s $f0, $f4, $f8
  lwc1  $f4, %lo(D_80054F9C)($at)
  trunc.w.s $f10, $f0
  mfc1  $v1, $f10
  nop   
  mtc1  $v1, $f16
  nop   
  cvt.s.w $f18, $f16
  sub.s $f6, $f0, $f18
  add.s $f8, $f6, $f4
  trunc.w.s $f10, $f8
  mfc1  $t1, $f10
  jr    $ra
   addu  $v0, $v1, $t1
");

asm(R"
glabel sub_GAME_7F0767D8
  bgtz  $a2, .L7F0767E4
   move  $v1, $zero
  li    $a2, 1
.L7F0767E4:
  blez  $a2, .L7F076840
   addiu $t6, $a0, 0xf
.L7F0767EC:
  bgez  $t6, .L7F0767FC
   sra   $t7, $t6, 4
  addiu $at, $t6, 0xf
  sra   $t7, $at, 4
.L7F0767FC:
  sll   $t8, $t7, 2
  multu $t8, $a1
  slti  $at, $a0, 2
  addiu $a2, $a2, -1
  sra   $t0, $a0, 1
  sra   $t1, $a1, 1
  mflo  $t9
  addu  $v1, $v1, $t9
  bnezl $at, .L7F07682C
   slti  $at, $a1, 2
  move  $a0, $t0
  slti  $at, $a1, 2
.L7F07682C:
  bnez  $at, .L7F076838
   nop   
  move  $a1, $t1
.L7F076838:
  bgtzl $a2, .L7F0767EC
   addiu $t6, $a0, 0xf
.L7F076840:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F076848
  bgtz  $a2, .L7F076854
   move  $v1, $zero
  li    $a2, 1
.L7F076854:
  blez  $a2, .L7F0768B0
   addiu $t6, $a0, 7
.L7F07685C:
  bgez  $t6, .L7F07686C
   sra   $t7, $t6, 3
  addiu $at, $t6, 7
  sra   $t7, $at, 3
.L7F07686C:
  sll   $t8, $t7, 2
  multu $t8, $a1
  slti  $at, $a0, 2
  addiu $a2, $a2, -1
  sra   $t0, $a0, 1
  sra   $t1, $a1, 1
  mflo  $t9
  addu  $v1, $v1, $t9
  bnezl $at, .L7F07689C
   slti  $at, $a1, 2
  move  $a0, $t0
  slti  $at, $a1, 2
.L7F07689C:
  bnez  $at, .L7F0768A8
   nop   
  move  $a1, $t1
.L7F0768A8:
  bgtzl $a2, .L7F07685C
   addiu $t6, $a0, 7
.L7F0768B0:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F0768B8
  bgtz  $a2, .L7F0768C4
   move  $v1, $zero
  li    $a2, 1
.L7F0768C4:
  blez  $a2, .L7F076920
   addiu $t6, $a0, 3
.L7F0768CC:
  bgez  $t6, .L7F0768DC
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7F0768DC:
  sll   $t8, $t7, 2
  multu $t8, $a1
  slti  $at, $a0, 2
  addiu $a2, $a2, -1
  sra   $t0, $a0, 1
  sra   $t1, $a1, 1
  mflo  $t9
  addu  $v1, $v1, $t9
  bnezl $at, .L7F07690C
   slti  $at, $a1, 2
  move  $a0, $t0
  slti  $at, $a1, 2
.L7F07690C:
  bnez  $at, .L7F076918
   nop   
  move  $a1, $t1
.L7F076918:
  bgtzl $a2, .L7F0768CC
   addiu $t6, $a0, 3
.L7F076920:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel sub_GAME_7F076928
  bgtz  $a2, .L7F076934
   move  $v1, $zero
  li    $a2, 1
.L7F076934:
  blez  $a2, .L7F076990
   addiu $t6, $a0, 3
.L7F07693C:
  bgez  $t6, .L7F07694C
   sra   $t7, $t6, 2
  addiu $at, $t6, 3
  sra   $t7, $at, 2
.L7F07694C:
  sll   $t8, $t7, 2
  multu $t8, $a1
  slti  $at, $a0, 2
  addiu $a2, $a2, -1
  sra   $t0, $a0, 1
  sra   $t1, $a1, 1
  mflo  $t9
  addu  $v1, $v1, $t9
  bnezl $at, .L7F07697C
   slti  $at, $a1, 2
  move  $a0, $t0
  slti  $at, $a1, 2
.L7F07697C:
  bnez  $at, .L7F076988
   nop   
  move  $a1, $t1
.L7F076988:
  bgtzl $a2, .L7F07693C
   addiu $t6, $a0, 3
.L7F076990:
  jr    $ra
   move  $v0, $v1
");

asm(R"
glabel generate_microcode_for_othermode_setting
  sw    $a1, 4($sp)
  li    $t0, 1
  bne   $a2, $t0, .L7F076B84
   lw    $v0, ($a0)
  move  $v1, $v0
  addiu $v0, $v0, 8
  lui   $t6, 0xe700
  sw    $t6, ($v1)
  sw    $zero, 4($v1)
  move  $a1, $v0
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00         #BA00140200000000 
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402 #
  sw    $t7, ($a1)                                        #
  sw    $zero, 4($a1)                                     #gDPSetCycleType(G_CYC_1CYCLE)
  lw    $t8, 4($sp)
  addiu $v0, $v0, 8
  li    $at, 2
  beq   $t8, $t0, .L7F0769FC
   nop   
  beq   $t8, $at, .L7F076A74
   li    $at, 3
  beq   $t8, $at, .L7F076AEC
   li    $at, 4
  beq   $t8, $at, .L7F076B38
   nop   
.L7F0769FC:
  beqz  $a3, .L7F076A54
   move  $v1, $v0
  slti  $at, $a3, 2
  bnez  $at, .L7F076A34
   move  $v1, $v0
  move  $v1, $v0
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900         #B900031D00552D58
  lui   $t1, (0x00552D58 >> 16) # lui $t1, 0x55           #
  ori   $t1, (0x00552D58 & 0xFFFF) # ori $t1, $t1, 0x2d58 #
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d  #
  sw    $t9, ($v1)                                        #
  sw    $t1, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076A34:
  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900         #B900031D00552078
  lui   $t3, (0x00552078 >> 16) # lui $t3, 0x55           #
  ori   $t3, (0x00552078 & 0xFFFF) # ori $t3, $t3, 0x2078 #
  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d  #
  sw    $t2, ($v1)                                        #
  sw    $t3, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076A54:
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900         #B900031D 00552048
  lui   $t5, (0x00552048 >> 16) # lui $t5, 0x55           #
  ori   $t5, (0x00552048 & 0xFFFF) # ori $t5, $t5, 0x2048 #
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d  #
  sw    $t4, ($v1)                                        #
  sw    $t5, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076A74:
  beqz  $a3, .L7F076ACC
   move  $v1, $v0
  slti  $at, $a3, 2
  bnez  $at, .L7F076AAC
   move  $v1, $v0
  move  $v1, $v0
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900         #B900031D00504DD8
  lui   $t7, (0x00504DD8 >> 16) # lui $t7, 0x50           #
  ori   $t7, (0x00504DD8 & 0xFFFF) # ori $t7, $t7, 0x4dd8 #
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d  #
  sw    $t6, ($v1)                                        #
  sw    $t7, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076AAC:
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900         #B900031D005049D8
  lui   $t9, (0x005049D8 >> 16) # lui $t9, 0x50           #
  ori   $t9, (0x005049D8 & 0xFFFF) # ori $t9, $t9, 0x49d8 #
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d  #
  sw    $t8, ($v1)                                        #
  sw    $t9, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076ACC:
  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900         #
  lui   $t2, (0x005041C8 >> 16) # lui $t2, 0x50           #
  ori   $t2, (0x005041C8 & 0xFFFF) # ori $t2, $t2, 0x41c8 #
  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d  #
  sw    $t1, ($v1)                                        #
  sw    $t2, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076AEC:
  beqz  $a3, .L7F076B18
   move  $v1, $v0
  move  $v1, $v0
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900         #
  lui   $t4, (0x00553078 >> 16) # lui $t4, 0x55           #
  ori   $t4, (0x00553078 & 0xFFFF) # ori $t4, $t4, 0x3078 #
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d  #
  sw    $t3, ($v1)                                        #
  sw    $t4, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076B18:
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900         #
  lui   $t6, (0x00553048 >> 16) # lui $t6, 0x55           #
  ori   $t6, (0x00553048 & 0xFFFF) # ori $t6, $t6, 0x3048 #
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d  #
  sw    $t5, ($v1)                                        #
  sw    $t6, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076B38:
  beqz  $a3, .L7F076B64
   move  $v1, $v0
  move  $v1, $v0
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900         #
  lui   $t8, (0x00504B50 >> 16) # lui $t8, 0x50           #
  ori   $t8, (0x00504B50 & 0xFFFF) # ori $t8, $t8, 0x4b50 #
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d  #
  sw    $t7, ($v1)                                        #
  sw    $t8, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076B64:
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900         #
  lui   $t1, (0x00504340 >> 16) # lui $t1, 0x50           #
  ori   $t1, (0x00504340 & 0xFFFF) # ori $t1, $t1, 0x4340 #
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d  #
  sw    $t9, ($v1)                                        #
  sw    $t1, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076B84:
  move  $v1, $v0
  addiu $v0, $v0, 8
  lui   $t2, 0xe700                                       #e7000000000000
  sw    $t2, ($v1)                                        #gDPPipeSync()
  sw    $zero, 4($v1)
  move  $a1, $v0
  lui   $t3, (0xBA001402 >> 16) # lui $t3, 0xba00         #
  ori   $t3, (0xBA001402 & 0xFFFF) # ori $t3, $t3, 0x1402 #
  lui   $t4, 0x10                                         #2c
  sw    $t4, 4($a1)                                       #gDPSetCycleType(G_CYC_2CYCLE)
  sw    $t3, ($a1)
  lw    $t5, 4($sp)
  addiu $v0, $v0, 8
  li    $at, 2
  beq   $t5, $t0, .L7F076BDC
   nop   
  beq   $t5, $at, .L7F076C54
   li    $at, 3
  beq   $t5, $at, .L7F076CCC
   li    $at, 4
  beq   $t5, $at, .L7F076D18
   nop   
.L7F076BDC:
  beqz  $a3, .L7F076C34
   move  $v1, $v0
  slti  $at, $a3, 2
  bnez  $at, .L7F076C14
   move  $v1, $v0
  move  $v1, $v0
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900         #
  lui   $t7, (0x0C192D58 >> 16) # lui $t7, 0xc19          #
  ori   $t7, (0x0C192D58 & 0xFFFF) # ori $t7, $t7, 0x2d58 #
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d  #
  sw    $t6, ($v1)                                        #
  sw    $t7, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076C14:
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900         #
  lui   $t9, (0x0C192078 >> 16) # lui $t9, 0xc19          #
  ori   $t9, (0x0C192078 & 0xFFFF) # ori $t9, $t9, 0x2078 #
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d  #
  sw    $t8, ($v1)                                        #
  sw    $t9, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076C34:
  lui   $t1, (0xB900031D >> 16) # lui $t1, 0xb900         #
  lui   $t2, (0x0C192048 >> 16) # lui $t2, 0xc19          #
  ori   $t2, (0x0C192048 & 0xFFFF) # ori $t2, $t2, 0x2048 #
  ori   $t1, (0xB900031D & 0xFFFF) # ori $t1, $t1, 0x31d  #
  sw    $t1, ($v1)                                        #
  sw    $t2, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076C54:
  beqz  $a3, .L7F076CAC
   move  $v1, $v0
  slti  $at, $a3, 2
  bnez  $at, .L7F076C8C
   move  $v1, $v0
  move  $v1, $v0
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900         #
  lui   $t4, (0x0C184DD8 >> 16) # lui $t4, 0xc18          #
  ori   $t4, (0x0C184DD8 & 0xFFFF) # ori $t4, $t4, 0x4dd8 #
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d  #
  sw    $t3, ($v1)                                        #
  sw    $t4, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076C8C:
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900         #
  lui   $t6, (0x0C1849D8 >> 16) # lui $t6, 0xc18          #
  ori   $t6, (0x0C1849D8 & 0xFFFF) # ori $t6, $t6, 0x49d8 #
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d  #
  sw    $t5, ($v1)                                        #
  sw    $t6, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076CAC:
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900         #
  lui   $t8, (0x0C1841C8 >> 16) # lui $t8, 0xc18          #
  ori   $t8, (0x0C1841C8 & 0xFFFF) # ori $t8, $t8, 0x41c8 #
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d  #
  sw    $t7, ($v1)                                        #
  sw    $t8, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076CCC:
  beqz  $a3, .L7F076CF8
   move  $v1, $v0
  move  $v1, $v0
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900         #
  lui   $t1, (0x0C193078 >> 16) # lui $t1, 0xc19          #
  ori   $t1, (0x0C193078 & 0xFFFF) # ori $t1, $t1, 0x3078 #
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d  #
  sw    $t9, ($v1)                                        #
  sw    $t1, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076CF8:
  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900         #
  lui   $t3, (0x0C193048 >> 16) # lui $t3, 0xc19          #
  ori   $t3, (0x0C193048 & 0xFFFF) # ori $t3, $t3, 0x3048 #
  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d  #
  sw    $t2, ($v1)                                        #
  sw    $t3, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076D18:
  beqz  $a3, .L7F076D44
   move  $v1, $v0
  move  $v1, $v0
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900         #
  lui   $t5, (0x0C184B50 >> 16) # lui $t5, 0xc18          #
  ori   $t5, (0x0C184B50 & 0xFFFF) # ori $t5, $t5, 0x4b50 #
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d  #
  sw    $t4, ($v1)                                        #
  sw    $t5, 4($v1)                                       #gDPSetRenderMode(,)
  b     .L7F076D60
   addiu $v0, $v0, 8
.L7F076D44:
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900         #
  lui   $t7, (0x0C184340 >> 16) # lui $t7, 0xc18          #
  ori   $t7, (0x0C184340 & 0xFFFF) # ori $t7, $t7, 0x4340 #
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d  #
  sw    $t6, ($v1)                                        #
  sw    $t7, 4($v1)                                       #gDPSetRenderMode(,)
  addiu $v0, $v0, 8
.L7F076D60:
  jr    $ra
   sw    $v0, ($a0)
");

asm(R"
glabel likely_generate_DL_for_image_declaration
  addiu $sp, $sp, -0x170
  sw    $ra, 0x34($sp)
  sw    $s7, 0x30($sp)
  sw    $s6, 0x2c($sp)
  sw    $s5, 0x28($sp)
  sw    $s4, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x170($sp)
  sw    $a2, 0x178($sp)
  lw    $t7, ($a0)
  move  $s0, $a3
  move  $s7, $a1
  bnez  $a1, .L7F076E3C
   sw    $t7, 0x16c($sp)
  move  $a1, $a2
  li    $a2, 1
  jal   generate_microcode_for_othermode_setting
   addiu $a0, $sp, 0x16c
  slti  $at, $s0, 2
  bnez  $at, .L7F076DF8
   lw    $t7, 0x16c($sp)
  lw    $v0, 0x16c($sp)
  andi  $t6, $s0, 0xff
  sll   $t7, $t6, 0x10
  lui   $at, 0xbb00
  addiu $t9, $v0, 8
  sw    $t9, 0x16c($sp)
  or    $t8, $t7, $at
  ori   $t9, $t8, 1
  li    $t6, -1
  sw    $t6, 4($v0)
  b     .L7F076E14
   sw    $t9, ($v0)
.L7F076DF8:
  addiu $t8, $t7, 8
  sw    $t8, 0x16c($sp)
  lui   $t9, (0xBB000001 >> 16) # lui $t9, 0xbb00     #
  ori   $t9, (0xBB000001 & 0xFFFF) # ori $t9, $t9, 1  #
  li    $t6, -1
  sw    $t6, 4($t7)                                   # As with above gbi, I forgot to include *dl since I dont know where it is saving the Gfx array (*dl)
  sw    $t9, ($t7)                                    #gSPTexture(*dl, 0xFFFF, 0xFFFF, 1, 0, G_ON) #use FFFF since 1.0 cannot be represented directly
.L7F076E14:
  lw    $t7, 0x16c($sp)
  lui   $t9, (0xFCFFFFFF >> 16) # lui $t9, 0xfcff         #
  lui   $t6, (0xFFFE793C >> 16) # lui $t6, 0xfffe         #FCFFFFFFFFFE793C
  addiu $t8, $t7, 8
  sw    $t8, 0x16c($sp)
  ori   $t6, (0xFFFE793C & 0xFFFF) # ori $t6, $t6, 0x793c #
  ori   $t9, (0xFCFFFFFF & 0xFFFF) # ori $t9, $t9, 0xffff #
  sw    $t9, ($t7)                                        #
  b     .L7F077B80
   sw    $t6, 4($t7)                                      #gDPSetCombineMode()
.L7F076E3C:
  lw    $v0, ($s7)
  lbu   $s5, 4($s7)
  lbu   $s4, 5($s7)
  sltiu $at, $v0, 0xbb9
  beqz  $at, .L7F076E60
   move  $a0, $s7
  jal   load_image_to_buffer
   move  $a1, $zero
  lw    $v0, ($s7)
.L7F076E60:
  lui   $at, 0x8000
  or    $v1, $v0, $at
  lhu   $a0, -8($v1)
  jal   sub_GAME_7F0CBB0C
   move  $a1, $zero
  lbu   $v1, 6($s7)
  move  $s6, $v0
  bnezl $v1, .L7F07741C
   sw    $zero, 0xd0($sp)
  beql  $v0, $zero, .L7F076EBC
   lbu   $s1, 7($s7)
  lw    $s2, 8($v0)
  lw    $t6, 0xc($v0)
  sll   $s1, $s2, 0x1b
  srl   $t7, $s1, 0x1d
  andi  $s1, $t7, 0xff
  srl   $t7, $t6, 0x1e
  sll   $t8, $t7, 0xe
  andi  $t9, $s2, 3
  move  $s2, $t9
  b     .L7F076EC0
   sw    $t8, 0x144($sp)
  lbu   $s1, 7($s7)
.L7F076EBC:
  lbu   $s2, 8($s7)
.L7F076EC0:
  beqz  $s2, .L7F076F90
   move  $v0, $s2
  li    $at, 1
  beq   $v0, $at, .L7F076F5C
   li    $t7, 2
  li    $at, 2
  beq   $v0, $at, .L7F076F28
   li    $t8, 2
  li    $at, 3
  beq   $v0, $at, .L7F076EF4
   li    $t9, 3
  b     .L7F076FC4
   lw    $s3, 0x13c($sp)
.L7F076EF4:
  sw    $t9, 0x140($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F076928
   li    $a2, 1
  addiu $s3, $v0, -1
  jal   ceil1000
   move  $a0, $s5
  addiu $t6, $s5, 3
  sra   $t7, $t6, 2
  sw    $v0, 0x138($sp)
  b     .L7F076FC4
   sw    $t7, 0x134($sp)
.L7F076F28:
  sw    $t8, 0x140($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F0768B8
   li    $a2, 1
  addiu $s3, $v0, -1
  jal   ceil2000
   move  $a0, $s5
  addiu $t9, $s5, 3
  sra   $t6, $t9, 2
  sw    $v0, 0x138($sp)
  b     .L7F076FC4
   sw    $t6, 0x134($sp)
.L7F076F5C:
  sw    $t7, 0x140($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F076848
   li    $a2, 1
  addiu $s3, $v0, -1
  jal   ceil4000
   move  $a0, $s5
  addiu $t8, $s5, 7
  sra   $t9, $t8, 3
  sw    $v0, 0x138($sp)
  b     .L7F076FC4
   sw    $t9, 0x134($sp)
.L7F076F90:
  li    $t6, 2
  sw    $t6, 0x140($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F0767D8
   li    $a2, 1
  addiu $s3, $v0, -1
  jal   ceil8000
   move  $a0, $s5
  addiu $t7, $s5, 0xf
  sra   $t8, $t7, 4
  sw    $v0, 0x138($sp)
  sw    $t8, 0x134($sp)
.L7F076FC4:
  addiu $a0, $sp, 0x16c
  lw    $a1, 0x178($sp)
  li    $a2, 1
  jal   generate_microcode_for_othermode_setting
   move  $a3, $s0
  slti  $at, $s0, 2
  bnez  $at, .L7F077014
   move  $t1, $s1
  lw    $v0, 0x16c($sp)
  andi  $t7, $s0, 0xff
  sll   $t8, $t7, 0x10
  lui   $at, 0xbb00
  addiu $t6, $v0, 8
  sw    $t6, 0x16c($sp)
  or    $t9, $t8, $at
  ori   $t6, $t9, 1
  li    $t7, -1
  sw    $t7, 4($v0)
  b     .L7F077034
   sw    $t6, ($v0)
.L7F077014:
  lw    $t8, 0x16c($sp)
  lui   $t6, (0xBB000001 >> 16) # lui $t6, 0xbb00     #
  ori   $t6, (0xBB000001 & 0xFFFF) # ori $t6, $t6, 1  #
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  li    $t7, -1                                       #
  sw    $t7, 4($t8)                                   #
  sw    $t6, ($t8)                                    #gSPTexture(*dl, 0xFFFF, 0xFFFF, 1, 0, G_ON) #use FFFF since 1.0 cannot be represented directly
.L7F077034:
  lw    $t8, 0x16c($sp)
  lui   $t6, (0xBA001001 >> 16) # lui $t6, 0xba00         #
  ori   $t6, (0xBA001001 & 0xFFFF) # ori $t6, $t6, 0x1001 #
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  sw    $zero, 4($t8)
  beqz  $s1, .L7F077080
   sw    $t6, ($t8)                                       #gDPSetTextureLOD(G_TL_TILE)
  li    $at, 2
  beq   $t1, $at, .L7F0770EC
   lw    $t7, 0x144($sp)
  li    $at, 3
  beq   $t1, $at, .L7F0770A8
   lw    $t7, 0x16c($sp)
  li    $at, 4
  beq   $t1, $at, .L7F0770CC
   lw    $t7, 0x16c($sp)
  b     .L7F077154
   lw    $v0, 0x16c($sp)
.L7F077080:
  lw    $t7, 0x16c($sp)
  lui   $t9, (0xFC121824 >> 16) # lui $t9, 0xfc12         #
  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33         #
  addiu $t8, $t7, 8
  sw    $t8, 0x16c($sp)
  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff #
  ori   $t9, (0xFC121824 & 0xFFFF) # ori $t9, $t9, 0x1824 #
  sw    $t9, ($t7)
  b     .L7F077150
   sw    $t6, 4($t7)                                      #gDPSetCombineMode()
.L7F0770A8:
  addiu $t8, $t7, 8
  lui   $t9, (0xFC121824 >> 16) # lui $t9, 0xfc12         #
  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33         #
  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff #
  ori   $t9, (0xFC121824 & 0xFFFF) # ori $t9, $t9, 0x1824 #
  sw    $t8, 0x16c($sp)
  sw    $t6, 4($t7)
  b     .L7F077150
   sw    $t9, ($t7)                                       #gDPSetCombineMode()
.L7F0770CC:
  addiu $t8, $t7, 8
  lui   $t9, (0xFC127E24 >> 16) # lui $t9, 0xfc12         #
  ori   $t9, (0xFC127E24 & 0xFFFF) # ori $t9, $t9, 0x7e24 #
  sw    $t8, 0x16c($sp)
  li    $t6, -1540
  sw    $t6, 4($t7)
  b     .L7F077150
   sw    $t9, ($t7)                                       #gDPSetCombineMode()
.L7F0770EC:
  li    $at, 32768
  beq   $t7, $at, .L7F07710C
   lw    $t8, 0x16c($sp)
  li    $at, 49152
  beq   $t7, $at, .L7F077130
   lw    $t8, 0x16c($sp)
  b     .L7F077154
   lw    $v0, 0x16c($sp)
.L7F07710C:
  addiu $t9, $t8, 8
  lui   $t6, (0xFC121824 >> 16) # lui $t6, 0xfc12         #
  lui   $t7, (0xFF33FFFF >> 16) # lui $t7, 0xff33         #
  ori   $t7, (0xFF33FFFF & 0xFFFF) # ori $t7, $t7, 0xffff #
  ori   $t6, (0xFC121824 & 0xFFFF) # ori $t6, $t6, 0x1824 #
  sw    $t9, 0x16c($sp)
  sw    $t7, 4($t8)
  b     .L7F077150
   sw    $t6, ($t8)                                       #gDPSetCombineMode()
.L7F077130:
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  lui   $t6, (0xFC121824 >> 16) # lui $t6, 0xfc12         #
  lui   $t7, (0xFF33FFFF >> 16) # lui $t7, 0xff33         #
  ori   $t7, (0xFF33FFFF & 0xFFFF) # ori $t7, $t7, 0xffff #
  ori   $t6, (0xFC121824 & 0xFFFF) # ori $t6, $t6, 0x1824 #
  sw    $t6, ($t8)
  sw    $t7, 4($t8)                                       #gDPSetCombineMode()
.L7F077150:
  lw    $v0, 0x16c($sp)
.L7F077154:
  lw    $a0, 0x140($sp)
  andi  $v1, $s1, 7
  sll   $t6, $v1, 0x15
  addiu $t9, $v0, 8
  sw    $t9, 0x16c($sp)
  lui   $at, 0xfd00
  andi  $t7, $a0, 3
  sll   $a0, $t7, 0x13
  or    $t9, $t6, $at
  move  $v1, $t6
  or    $t6, $t9, $a0
  sw    $t6, ($v0)
  lw    $t7, ($s7)
  lui   $at, 0xf500
  or    $t3, $v1, $at
  sw    $t7, 4($v0)
  lw    $a1, 0x16c($sp)
  or    $t6, $t3, $a0
  lui   $t2, 0x700
  addiu $t9, $a1, 8
  sw    $t9, 0x16c($sp)
  sw    $t6, ($a1)
  lbu   $t7, 0xa($s7)
  lui   $t5, 0xe600
  slti  $at, $s3, 0x7ff
  andi  $t8, $t7, 3
  lbu   $t7, 9($s7)
  sll   $t9, $t8, 0x12
  or    $t6, $t9, $t2
  andi  $t8, $t7, 3
  sll   $t9, $t8, 8
  or    $t7, $t6, $t9
  sw    $t7, 4($a1)
  lw    $t8, 0x16c($sp)
  li    $a3, 2047
  addiu $t6, $t8, 8
  sw    $t6, 0x16c($sp)
  sw    $zero, 4($t8)
  sw    $t5, ($t8)
  lw    $t0, 0x16c($sp)
  lui   $t8, 0xf300
  addiu $t7, $t0, 8
  sw    $t7, 0x16c($sp)
  beqz  $at, .L7F077210
   sw    $t8, ($t0)
  b     .L7F077210
   move  $a3, $s3
.L7F077210:
  lw    $t8, 0x138($sp)
  andi  $t6, $a3, 0xfff
  sll   $t9, $t6, 0xc
  or    $t7, $t9, $t2
  andi  $t6, $t8, 0xfff
  or    $t9, $t7, $t6
  sw    $t9, 4($t0)
  lw    $t8, 0x16c($sp)
  lui   $t4, 0xe700
  li    $at, 2
  addiu $t7, $t8, 8
  sw    $t7, 0x16c($sp)
  sw    $zero, 4($t8)
  bne   $t1, $at, .L7F077328
   sw    $t4, ($t8)
  lbu   $t6, 0xa($s6)
  li    $t9, 1023
  addiu $a3, $s3, 1
  subu  $v0, $t9, $t6
  sltu  $at, $v0, $a3
  beqz  $at, .L7F077270
   lw    $t8, 0x16c($sp)
  b     .L7F077274
   move  $t0, $v0
.L7F077270:
  move  $t0, $zero
.L7F077274:
  addiu $t7, $t8, 8
  sw    $t7, 0x16c($sp)
  lui   $t9, (0xF5000100 >> 16) # lui $t9, 0xf500         #
  ori   $t9, (0xF5000100 & 0xFFFF) # ori $t9, $t9, 0x100  #gDPSetTile()
  sw    $t9, ($t8)
  sw    $t2, 4($t8)
  lw    $t6, 0x16c($sp)
  subu  $a2, $a3, $t0
  andi  $a1, $t0, 0x3ff
  addiu $t8, $t6, 8
  sw    $t8, 0x16c($sp)
  sw    $zero, 4($t6)
  sw    $t5, ($t6)
  lw    $a0, 0x16c($sp)
  andi  $t8, $a2, 0x3ff
  sll   $t7, $t8, 0xe
  addiu $t9, $a0, 8
  sw    $t9, 0x16c($sp)
  sll   $t6, $a1, 2
  lui   $at, 0xf000
  or    $t9, $t7, $at
  move  $a1, $t6
  or    $t6, $t9, $t6
  sw    $t6, ($a0)
  lbu   $t8, 0xa($s6)
  addu  $t7, $t8, $a2
  andi  $t9, $t7, 0x3ff
  sll   $t6, $t9, 0xe
  or    $t8, $t6, $t2
  or    $t7, $t8, $a1
  sw    $t7, 4($a0)
  lw    $t9, 0x16c($sp)
  addiu $t6, $t9, 8
  sw    $t6, 0x16c($sp)
  sw    $zero, 4($t9)
  sw    $t4, ($t9)
  lw    $t8, 0x16c($sp)
  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00         #
  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02  #gDPSetTextureLUT()
  addiu $t7, $t8, 8
  sw    $t7, 0x16c($sp)
  sw    $t9, ($t8)
  lw    $t6, 0x144($sp)
  b     .L7F077344
   sw    $t6, 4($t8)
.L7F077328:
  lw    $t8, 0x16c($sp)
  lui   $t9, (0xBA000E02 >> 16) # lui $t9, 0xba00         #
  ori   $t9, (0xBA000E02 & 0xFFFF) # ori $t9, $t9, 0xe02  #gDPSetTextureLUT()
  addiu $t7, $t8, 8
  sw    $t7, 0x16c($sp)
  sw    $zero, 4($t8)
  sw    $t9, ($t8)
.L7F077344:
  lw    $s0, 0x16c($sp)
  andi  $t7, $s2, 3
  sll   $t9, $t7, 0x13
  addiu $t8, $s0, 8
  sw    $t8, 0x16c($sp)
  lw    $t8, 0x134($sp)
  or    $t6, $t3, $t9
  move  $a0, $s4
  andi  $t7, $t8, 0x1ff
  sll   $t9, $t7, 9
  or    $t8, $t6, $t9
  jal   is_less_than_certain_power_of_2
   sw    $t8, ($s0)
  move  $a0, $s5
  jal   is_less_than_certain_power_of_2
   sw    $v0, 0x58($sp)
  lbu   $t9, 0xa($s7)
  andi  $t7, $v0, 0xf
  lw    $a3, 0x58($sp)
  sll   $t6, $t7, 4
  andi  $t8, $t9, 3
  sll   $t7, $t8, 0x12
  or    $t9, $t6, $t7
  andi  $t8, $a3, 0xf
  sll   $t6, $t8, 0xe
  lbu   $t8, 9($s7)
  or    $t7, $t9, $t6
  lw    $a1, 0x180($sp)
  andi  $t9, $t8, 3
  sll   $t6, $t9, 8
  or    $t8, $t7, $t6
  sw    $t8, 4($s0)
  lw    $v1, 0x16c($sp)
  andi  $a0, $a1, 0xfff
  sll   $t6, $a0, 0xc
  lui   $at, 0xf200
  addiu $t7, $v1, 8
  sw    $t7, 0x16c($sp)
  or    $t8, $t6, $at
  or    $t9, $t8, $a0
  addiu $t7, $s5, -1
  sll   $t6, $t7, 2
  addu  $t8, $t6, $a1
  sw    $t9, ($v1)
  andi  $t9, $t8, 0xfff
  addiu $t6, $s4, -1
  sll   $t8, $t6, 2
  sll   $t7, $t9, 0xc
  addu  $t9, $t8, $a1
  andi  $t6, $t9, 0xfff
  or    $t8, $t7, $t6
  b     .L7F077B80
   sw    $t8, 4($v1)
  sw    $zero, 0xd0($sp)
.L7F07741C:
  beqz  $v0, .L7F07744C
   sw    $v1, 0xcc($sp)
  lw    $v1, 8($v0)
  andi  $t6, $v1, 3
  sb    $t6, 0xca($sp)
  lw    $s2, 0xc($v0)
  sll   $s1, $v1, 0x1b
  srl   $t9, $s1, 0x1d
  srl   $t8, $s2, 0x1e
  andi  $s1, $t9, 0xff
  b     .L7F07745C
   sll   $s2, $t8, 0xe
.L7F07744C:
  lbu   $t7, 8($s7)
  lbu   $s1, 7($s7)
  lw    $s2, 0xc4($sp)
  sb    $t7, 0xca($sp)
.L7F07745C:
  beqz  $v0, .L7F07748C
   lbu   $s3, 0xca($sp)
  lw    $t6, 0xc($v0)
  move  $a0, $s6
  addiu $a1, $sp, 0xc0
  sll   $t9, $t6, 2
  bgez  $t9, .L7F07748C
   nop   
  jal   sub_GAME_7F0CC9D4
   addiu $a2, $sp, 0xbc
  b     .L7F077538
   addiu $a0, $sp, 0x16c
.L7F07748C:
  beqz  $s3, .L7F077518
   li    $t8, 2
  li    $at, 1
  beq   $s3, $at, .L7F0774F8
   li    $t7, 2
  li    $at, 2
  beq   $s3, $at, .L7F0774D8
   li    $t8, 2
  li    $at, 3
  bne   $s3, $at, .L7F077534
   li    $t7, 3
  sw    $t7, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F076928
   lw    $a2, 0xcc($sp)
  addiu $t6, $v0, -1
  b     .L7F077534
   sw    $t6, 0xbc($sp)
.L7F0774D8:
  sw    $t8, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F0768B8
   lw    $a2, 0xcc($sp)
  addiu $t9, $v0, -1
  b     .L7F077534
   sw    $t9, 0xbc($sp)
.L7F0774F8:
  sw    $t7, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F076848
   lw    $a2, 0xcc($sp)
  addiu $t6, $v0, -1
  b     .L7F077534
   sw    $t6, 0xbc($sp)
.L7F077518:
  sw    $t8, 0xc0($sp)
  move  $a0, $s5
  move  $a1, $s4
  jal   sub_GAME_7F0767D8
   lw    $a2, 0xcc($sp)
  addiu $t9, $v0, -1
  sw    $t9, 0xbc($sp)
.L7F077534:
  addiu $a0, $sp, 0x16c
.L7F077538:
  lw    $a1, 0x178($sp)
  li    $a2, 2
  jal   generate_microcode_for_othermode_setting
   move  $a3, $s0
  slti  $at, $s0, 2
  bnez  $at, .L7F077598
   move  $t0, $s1
  lw    $v0, 0x16c($sp)
  andi  $t8, $s0, 0xff
  sll   $t9, $t8, 0x10
  addiu $t6, $v0, 8
  sw    $t6, 0x16c($sp)
  lw    $t6, 0xcc($sp)
  lui   $at, 0xbb00
  or    $t7, $t9, $at
  addiu $t8, $t6, -1
  andi  $t9, $t8, 7
  sll   $t6, $t9, 0xb
  or    $t8, $t7, $t6
  ori   $t9, $t8, 1
  li    $t7, -1
  sw    $t7, 4($v0)
  b     .L7F0775CC
   sw    $t9, ($v0)
.L7F077598:
  lw    $v0, 0x16c($sp)
  lw    $t9, 0xcc($sp)
  lui   $at, 0xbb00
  addiu $t8, $v0, 8
  addiu $t7, $t9, -1
  andi  $t6, $t7, 7
  sw    $t8, 0x16c($sp)
  sll   $t8, $t6, 0xb
  or    $t9, $t8, $at
  ori   $t7, $t9, 1
  li    $t6, -1
  sw    $t6, 4($v0)
  sw    $t7, ($v0)
.L7F0775CC:
  lw    $t8, 0x16c($sp)
  lui   $t7, (0xBA001001 >> 16) # lui $t7, 0xba00         #
  ori   $t7, (0xBA001001 & 0xFFFF) # ori $t7, $t7, 0x1001 #
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  lui   $t6, 1
  sw    $t6, 4($t8)
  beqz  $s1, .L7F077618
   sw    $t7, ($t8)                                       #gDPSetTextureLOD(G_TL_LOD)
  li    $at, 2
  beq   $t0, $at, .L7F077688
   li    $at, 3
  beq   $t0, $at, .L7F077640
   lw    $t8, 0x16c($sp)
  li    $at, 4
  beq   $t0, $at, .L7F077664
   lw    $t8, 0x16c($sp)
  b     .L7F0776F0
   lw    $v0, 0x16c($sp)
.L7F077618:
  lw    $t8, 0x16c($sp)
  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26          #
  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10          #
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff #
  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004 #
  sw    $t7, ($t8)
  b     .L7F0776EC
   sw    $t6, 4($t8)                                       #gDPSetCombineMode()
.L7F077640:
  addiu $t9, $t8, 8
  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10
  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff
  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
  sw    $t9, 0x16c($sp)
  sw    $t6, 4($t8)
  b     .L7F0776EC
   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F077664:
  addiu $t9, $t8, 8
  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
  lui   $t6, (0x1FFC93FC >> 16) # lui $t6, 0x1ffc
  ori   $t6, (0x1FFC93FC & 0xFFFF) # ori $t6, $t6, 0x93fc
  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
  sw    $t9, 0x16c($sp)
  sw    $t6, 4($t8)
  b     .L7F0776EC
   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F077688:
  li    $at, 32768
  beq   $s2, $at, .L7F0776A8
   lw    $t8, 0x16c($sp)
  li    $at, 49152
  beq   $s2, $at, .L7F0776CC
   lw    $t8, 0x16c($sp)
  b     .L7F0776F0
   lw    $v0, 0x16c($sp)
.L7F0776A8:
  addiu $t9, $t8, 8
  lui   $t7, (0xFC121824 >> 16) # lui $t7, 0xfc12
  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33
  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff
  ori   $t7, (0xFC121824 & 0xFFFF) # ori $t7, $t7, 0x1824
  sw    $t9, 0x16c($sp)
  sw    $t6, 4($t8)
  b     .L7F0776EC
   sw    $t7, ($t8)                                       #gDPSetCombineMode()
.L7F0776CC:
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  lui   $t7, (0xFC121824 >> 16) # lui $t7, 0xfc12
  lui   $t6, (0xFF33FFFF >> 16) # lui $t6, 0xff33
  ori   $t6, (0xFF33FFFF & 0xFFFF) # ori $t6, $t6, 0xffff
  ori   $t7, (0xFC121824 & 0xFFFF) # ori $t7, $t7, 0x1824
  sw    $t7, ($t8)
  sw    $t6, 4($t8)                                       #gDPSetCombineMode()
.L7F0776EC:
  lw    $v0, 0x16c($sp)
.L7F0776F0:
  lw    $t8, 0xc0($sp)
  andi  $v1, $s1, 7
  sll   $t7, $v1, 0x15
  addiu $t9, $v0, 8
  sw    $t9, 0x16c($sp)
  lui   $at, 0xfd00
  or    $t6, $t7, $at
  move  $v1, $t7
  andi  $t9, $t8, 3
  sll   $t7, $t9, 0x13
  or    $t8, $t6, $t7
  sw    $t8, ($v0)
  lw    $t9, ($s7)
  lui   $at, 0xf500
  or    $t1, $v1, $at
  sw    $t9, 4($v0)
  lw    $a0, 0x16c($sp)
  lw    $t8, 0xc0($sp)
  lui   $t2, 0x700
  addiu $t7, $a0, 8
  sw    $t7, 0x16c($sp)
  andi  $t9, $t8, 3
  sll   $t6, $t9, 0x13
  or    $t7, $t1, $t6
  sw    $t7, ($a0)
  sw    $t2, 4($a0)
  lw    $t8, 0x16c($sp)
  lui   $t5, 0xe600
  li    $a3, 2047
  addiu $t9, $t8, 8
  sw    $t9, 0x16c($sp)
  sw    $zero, 4($t8)
  sw    $t5, ($t8)
  lw    $a2, 0x16c($sp)
  lui   $t8, 0xf300
  addiu $t7, $a2, 8
  sw    $t7, 0x16c($sp)
  sw    $t8, ($a2)
  lw    $t9, 0xbc($sp)
  slti  $at, $t9, 0x7ff
  beqz  $at, .L7F0777A0
   nop   
  b     .L7F0777A0
   move  $a3, $t9
.L7F0777A0:
  andi  $t6, $a3, 0xfff
  sll   $t7, $t6, 0xc
  or    $t8, $t7, $t2
  sw    $t8, 4($a2)
  lw    $t9, 0x16c($sp)
  lui   $t4, 0xe700
  li    $at, 2
  addiu $t6, $t9, 8
  sw    $t6, 0x16c($sp)
  sw    $zero, 4($t9)
  bne   $t0, $at, .L7F0778AC
   sw    $t4, ($t9)
  lw    $v1, 0xbc($sp)
  lbu   $t7, 0xa($s6)
  li    $t8, 1023
  addiu $a2, $v1, 1
  subu  $v0, $t8, $t7
  sltu  $at, $v0, $a2
  beqz  $at, .L7F0777F8
   lw    $t9, 0x16c($sp)
  b     .L7F0777FC
   move  $a3, $v0
.L7F0777F8:
  move  $a3, $zero
.L7F0777FC:
  addiu $t6, $t9, 8
  sw    $t6, 0x16c($sp)
  lui   $t8, (0xF5000100 >> 16) # lui $t8, 0xf500         #
  ori   $t8, (0xF5000100 & 0xFFFF) # ori $t8, $t8, 0x100  #gDPSetTile()
  sw    $t8, ($t9)
  sw    $t2, 4($t9)
  lw    $t7, 0x16c($sp)
  subu  $a2, $a2, $a3
  andi  $a1, $a3, 0x3ff
  addiu $t9, $t7, 8
  sw    $t9, 0x16c($sp)
  sw    $zero, 4($t7)
  sw    $t5, ($t7)
  lw    $a0, 0x16c($sp)
  andi  $t9, $a2, 0x3ff
  sll   $t6, $t9, 0xe
  addiu $t8, $a0, 8
  sw    $t8, 0x16c($sp)
  sll   $t7, $a1, 2
  lui   $at, 0xf000
  or    $t8, $t6, $at
  move  $a1, $t7
  or    $t7, $t8, $t7
  sw    $t7, ($a0)
  lbu   $t9, 0xa($s6)
  addu  $t6, $t9, $a2
  andi  $t8, $t6, 0x3ff
  sll   $t7, $t8, 0xe
  or    $t9, $t7, $t2
  or    $t6, $t9, $a1
  sw    $t6, 4($a0)
  lw    $t8, 0x16c($sp)
  addiu $t7, $t8, 8
  sw    $t7, 0x16c($sp)
  sw    $zero, 4($t8)
  sw    $t4, ($t8)
  lw    $t9, 0x16c($sp)
  lui   $t8, (0xBA000E02 >> 16) # lui $t8, 0xba00         #
  ori   $t8, (0xBA000E02 & 0xFFFF) # ori $t8, $t8, 0xe02  #gDPSetTextureLUT()
  addiu $t6, $t9, 8
  sw    $t6, 0x16c($sp)
  sw    $s2, 4($t9)
  b     .L7F0778C8
   sw    $t8, ($t9)
.L7F0778AC:
  lw    $t7, 0x16c($sp)
  lui   $t6, (0xBA000E02 >> 16) # lui $t6, 0xba00         #
  ori   $t6, (0xBA000E02 & 0xFFFF) # ori $t6, $t6, 0xe02  #gDPSetTextureLUT()
  addiu $t9, $t7, 8
  sw    $t9, 0x16c($sp)
  sw    $zero, 4($t7)
  sw    $t6, ($t7)
.L7F0778C8:
  lw    $t8, 0xcc($sp)
  lw    $a3, 0x180($sp)
  move  $s1, $zero
  blez  $t8, .L7F077B80
   andi  $a0, $a3, 0xfff
  lbu   $s3, 0xca($sp)
  sll   $t7, $a0, 0xc
  lui   $at, 0xf200
  or    $t9, $t7, $at
  or    $t6, $t9, $a0
  andi  $t7, $s3, 3
  sll   $t9, $t7, 0x13
  or    $s2, $t1, $t9
  sw    $t6, 0x50($sp)
  lw    $s0, 0x64($sp)
.L7F077904:
  blez  $s1, .L7F077968
   lw    $a3, 0x180($sp)
  beqz  $s6, .L7F07794C
   slti  $at, $s5, 2
  lw    $t6, 0xc($s6)
  move  $a0, $s6
  sll   $t7, $t6, 2
  bgez  $t7, .L7F07794C
   nop   
  jal   sub_GAME_7F0CC714
   move  $a1, $s1
  move  $s5, $v0
  move  $a0, $s6
  jal   sub_GAME_7F0CC7FC
   move  $a1, $s1
  move  $s4, $v0
  b     .L7F077968
   lw    $a3, 0x180($sp)
.L7F07794C:
  bnez  $at, .L7F077958
   sra   $t9, $s5, 1
  move  $s5, $t9
.L7F077958:
  slti  $at, $s4, 2
  bnez  $at, .L7F077968
   sra   $t6, $s4, 1
  move  $s4, $t6
.L7F077968:
  addiu $t8, $s5, -1
  sll   $t7, $t8, 2
  addu  $t9, $t7, $a3
  andi  $t6, $t9, 0xfff
  sll   $t8, $t6, 0xc
  addiu $t7, $s4, -1
  sll   $t9, $t7, 2
  addu  $t6, $t9, $a3
  sw    $t8, 0x54($sp)
  andi  $t8, $t6, 0xfff
  beqz  $s3, .L7F077A6C
   sw    $t8, 0x4c($sp)
  li    $at, 1
  beq   $s3, $at, .L7F077A38
   li    $at, 2
  beq   $s3, $at, .L7F077A04
   li    $at, 3
  beql  $s3, $at, .L7F0779D4
   addiu $s0, $s5, 3
  multu $s0, $s4
  andi  $t7, $s0, 0x1ff
  sll   $t9, $t7, 9
  or    $v0, $s2, $t9
  mflo  $a2
  b     .L7F077AA4
   lw    $v1, 0x16c($sp)
  addiu $s0, $s5, 3
.L7F0779D4:
  bgez  $s0, .L7F0779E4
   sra   $t6, $s0, 2
  addiu $at, $s0, 3
  sra   $t6, $at, 2
.L7F0779E4:
  multu $t6, $s4
  andi  $t8, $t6, 0x1ff
  sll   $t7, $t8, 9
  move  $s0, $t6
  or    $v0, $s2, $t7
  mflo  $a2
  b     .L7F077AA4
   lw    $v1, 0x16c($sp)
.L7F077A04:
  addiu $s0, $s5, 3
  bgez  $s0, .L7F077A18
   sra   $t9, $s0, 2
  addiu $at, $s0, 3
  sra   $t9, $at, 2
.L7F077A18:
  multu $t9, $s4
  andi  $t6, $t9, 0x1ff
  sll   $t8, $t6, 9
  move  $s0, $t9
  or    $v0, $s2, $t8
  mflo  $a2
  b     .L7F077AA4
   lw    $v1, 0x16c($sp)
.L7F077A38:
  addiu $s0, $s5, 7
  bgez  $s0, .L7F077A4C
   sra   $t7, $s0, 3
  addiu $at, $s0, 7
  sra   $t7, $at, 3
.L7F077A4C:
  multu $t7, $s4
  andi  $t9, $t7, 0x1ff
  sll   $t6, $t9, 9
  move  $s0, $t7
  or    $v0, $s2, $t6
  mflo  $a2
  b     .L7F077AA4
   lw    $v1, 0x16c($sp)
.L7F077A6C:
  addiu $s0, $s5, 0xf
  bgez  $s0, .L7F077A80
   sra   $t8, $s0, 4
  addiu $at, $s0, 0xf
  sra   $t8, $at, 4
.L7F077A80:
  multu $t8, $s4
  andi  $t7, $t8, 0x1ff
  sll   $t9, $t7, 9
  move  $s0, $t8
  or    $v0, $s2, $t9
  mflo  $a2
  nop   
  nop   
  lw    $v1, 0x16c($sp)
.L7F077AA4:
  lw    $t7, 0xd0($sp)
  move  $a0, $s4
  addiu $t8, $v1, 8
  andi  $t9, $t7, 0x1ff
  or    $t6, $v0, $t9
  sw    $t8, 0x16c($sp)
  sw    $t6, ($v1)
  sw    $a2, 0x3c($sp)
  jal   is_less_than_certain_power_of_2
   sw    $v1, 0x60($sp)
  move  $a0, $s5
  jal   is_less_than_certain_power_of_2
   sw    $v0, 0x58($sp)
  andi  $v1, $s1, 7
  sll   $t8, $v1, 0x18
  andi  $t7, $v0, 0xf
  sll   $t9, $t7, 4
  or    $t6, $t9, $t8
  move  $v1, $t8
  lbu   $t8, 0xa($s7)
  lw    $a3, 0x58($sp)
  andi  $a0, $s1, 0xf
  andi  $t7, $t8, 3
  sll   $t9, $t7, 0x12
  or    $t8, $t6, $t9
  andi  $t7, $a3, 0xf
  sll   $t6, $t7, 0xe
  or    $t9, $t8, $t6
  lbu   $t6, 9($s7)
  sll   $t7, $a0, 0xa
  or    $t8, $t9, $t7
  andi  $t9, $t6, 3
  sll   $t7, $t9, 8
  or    $t6, $t8, $t7
  lw    $t8, 0x60($sp)
  lw    $a2, 0x3c($sp)
  or    $t9, $t6, $a0
  sw    $t9, 4($t8)
  lw    $a1, 0x16c($sp)
  lw    $t9, 0x50($sp)
  addiu $s1, $s1, 1
  addiu $t6, $a1, 8
  sw    $t6, 0x16c($sp)
  sw    $t9, ($a1)
  lw    $t8, 0x54($sp)
  lw    $t6, 0x4c($sp)
  or    $t7, $v1, $t8
  or    $t9, $t7, $t6
  sw    $t9, 4($a1)
  lw    $t8, 0xd0($sp)
  lw    $t6, 0xcc($sp)
  addu  $t7, $t8, $a2
  bne   $s1, $t6, .L7F077904
   sw    $t7, 0xd0($sp)
  sw    $s0, 0x64($sp)
.L7F077B80:
  lw    $t9, 0x16c($sp)
  lw    $t8, 0x170($sp)
  sw    $t9, ($t8)
  lw    $ra, 0x34($sp)
  lw    $s7, 0x30($sp)
  lw    $s6, 0x2c($sp)
  lw    $s5, 0x28($sp)
  lw    $s4, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x170
");

void sub_GAME_7F077BB8(int arg0, int arg1, int arg2, int arg3) {}
