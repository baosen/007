.section .text 
glabel __osDequeueThread
  move  $a2, $a0
  lw    $a3, ($a2)
  addiu $sp, $sp, -8
  beqz  $a3, .L70010AC8
   nop   
.L70010AA4:
  bne   $a3, $a1, .L70010AB8
   nop   
  lw    $t6, ($a1)
  b     .L70010AC8
   sw    $t6, ($a2)
.L70010AB8:
  move  $a2, $a3
  lw    $a3, ($a2)
  bnez  $a3, .L70010AA4
   nop   
.L70010AC8:
  jr    $ra
   addiu $sp, $sp, 8

.section .data
glabel __osThreadTail
.word 0, 0xFFFFFFFF
glabel __osRunQueue
 .word __osThreadTail
glabel __osActiveQueue
.word __osThreadTail
glabel __osRunningThread
.word 0
glabel __osFaultedThread
.word 0
