


.section .text, "ax" 
glabel alHeapInit
  li    $v1, 16
  andi  $t6, $a1, 0xf
  subu  $v0, $v1, $t6
  beq   $v1, $v0, .L70010D4C
   addu  $t7, $a1, $v0
  b     .L70010D50
   sw    $t7, ($a0)
.L70010D4C:
  sw    $a1, ($a0)
.L70010D50:
  lw    $t8, ($a0)
  sw    $a2, 8($a0)
  sw    $zero, 0xc($a0)
  jr    $ra
   sw    $t8, 4($a0)
