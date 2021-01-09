


.section .text, "ax"  
glabel alCents2Ratio
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  bltz  $a0, .L700137DC
   lui   $at, %hi(F32_800296E4)
  lui   $at, %hi(F32_800296E0)
  b     .L700137E4
   lwc1  $f0, %lo(F32_800296E0)($at)
.L700137DC:
  lwc1  $f0, %lo(F32_800296E4)($at)
  negu  $a0, $a0
.L700137E4:
  beqz  $a0, .L70013808
.L700137E8:
   andi  $t6, $a0, 1
  beqz  $t6, .L700137FC
   sra   $t7, $a0, 1
  mul.s $f2, $f2, $f0
  nop   
.L700137FC:
  mul.s $f0, $f0, $f0
  bnez  $t7, .L700137E8
   move  $a0, $t7
.L70013808:
  jr    $ra
   mov.s $f0, $f2

.section .rodata
glabel F32_800296E0
.float 1.0005778
glabel F32_800296E4
.float 0.99942255

