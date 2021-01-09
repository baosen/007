


.section .text, "ax"   

glabel osDpGetCounters
  lui   $t6, %hi(DPC_CLOCK_REG) # $t6, 0xa410
  lw    $t7, %lo(DPC_CLOCK_REG)($t6)
  lui   $t8, %hi(DPC_BUFBUSY_REG) # $t8, 0xa410
  lui   $t0, %hi(DPC_PIPEBUSY_REG) # $t0, 0xa410
  sw    $t7, ($a0)
  lw    $t9, %lo(DPC_BUFBUSY_REG)($t8)
  addiu $a0, $a0, 4
  lui   $t2, %hi(DPC_TMEM_REG) # $t2, 0xa410
  sw    $t9, ($a0)
  lw    $t1, %lo(DPC_PIPEBUSY_REG)($t0)
  addiu $a0, $a0, 4
  addiu $a0, $a0, 4
  sw    $t1, -4($a0)
  lw    $t3, %lo(DPC_TMEM_REG)($t2)
  addiu $a0, $a0, 4
  jr    $ra
   sw    $t3, -4($a0)

