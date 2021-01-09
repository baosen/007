


.section .text, "ax" 

glabel osCreateMesgQueue
  lui   $t6, %hi(__osThreadTail) 
  lui   $t7, %hi(__osThreadTail) 
  addiu $t6, %lo(__osThreadTail) # addiu $t6, $t6, 0x7720
  addiu $t7, %lo(__osThreadTail) # addiu $t7, $t7, 0x7720
  sw    $t6, ($a0)
  sw    $t7, 4($a0)
  sw    $zero, 8($a0)
  sw    $zero, 0xc($a0)
  sw    $a2, 0x10($a0)
  jr    $ra
   sw    $a1, 0x14($a0)

#wtf why do these exist, figure out
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
  nop   
