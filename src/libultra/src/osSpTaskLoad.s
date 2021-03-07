

.section .text
.section .bss

glabel tp # type.
.word 0
glabel flags
.word 0
glabel t_ucode_boot
.word 0
glabel t_ucode_boot_size
.word 0
glabel t_ucode
.word 0
glabel t_ucode_size
.word 0
glabel t_ucode_data
.word 0
glabel t_ucode_data_size
.word 0
glabel t_dram_stack
.word 0
glabel t_dram_stack_size
.word 0
glabel t_output_buff
.word 0
glabel t_output_buff_size
.word 0
glabel t_data_ptr
.word 0
glabel t_data_size
.word 0
glabel t_yield_data_ptr
.word 0
glabel t_yield_data_size
.word 0

.section .text
glabel _VirtualToPhysicalTask
  addiu $sp, $sp, -0x20
  lui   $t6, %hi(tp) 
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  addiu $t6, %lo(tp) # addiu $t6, $t6, 0x6a90
  sw    $t6, 0x1c($sp)
  move  $a1, $t6
  lw    $a0, 0x20($sp)
  jal   _bcopy
   li    $a2, 64
  lw    $t7, 0x1c($sp)
  lw    $t8, 0x10($t7)
  beqz  $t8, .L7000E538
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t8
  lw    $t9, 0x1c($sp)
  sw    $v0, 0x10($t9)
.L7000E538:
  lw    $t0, 0x1c($sp)
  lw    $t1, 0x18($t0)
  beqz  $t1, .L7000E558
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t1
  lw    $t2, 0x1c($sp)
  sw    $v0, 0x18($t2)
.L7000E558:
  lw    $t3, 0x1c($sp)
  lw    $t4, 0x20($t3)
  beqz  $t4, .L7000E578
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t4
  lw    $t5, 0x1c($sp)
  sw    $v0, 0x20($t5)
.L7000E578:
  lw    $t6, 0x1c($sp)
  lw    $t7, 0x28($t6)
  beqz  $t7, .L7000E598
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t7
  lw    $t8, 0x1c($sp)
  sw    $v0, 0x28($t8)
.L7000E598:
  lw    $t9, 0x1c($sp)
  lw    $t0, 0x2c($t9)
  beqz  $t0, .L7000E5B8
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t0
  lw    $t1, 0x1c($sp)
  sw    $v0, 0x2c($t1)
.L7000E5B8:
  lw    $t2, 0x1c($sp)
  lw    $t3, 0x30($t2)
  beqz  $t3, .L7000E5D8
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t3
  lw    $t4, 0x1c($sp)
  sw    $v0, 0x30($t4)
.L7000E5D8:
  lw    $t5, 0x1c($sp)
  lw    $t6, 0x38($t5)
  beqz  $t6, .L7000E5F8
   nop   
  jal   osVirtualToPhysical
   move  $a0, $t6
  lw    $t7, 0x1c($sp)
  sw    $v0, 0x38($t7)
.L7000E5F8:
  lw    $ra, 0x14($sp)
  lw    $v0, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel osSpTaskLoad
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a0, 0x20($sp)
  jal   _VirtualToPhysicalTask
   lw    $a0, 0x20($sp)
  sw    $v0, 0x1c($sp)
  lw    $t6, 0x1c($sp)
  lw    $t7, 4($t6)
  andi  $t8, $t7, 1
  beqz  $t8, .L7000E660
   nop   
  lw    $t9, 0x38($t6)
  li    $at, -2
  sw    $t9, 0x18($t6)
  lw    $t0, 0x1c($sp)
  lw    $t1, 0x3c($t0)
  sw    $t1, 0x1c($t0)
  lw    $t2, 0x20($sp)
  lw    $t3, 4($t2)
  and   $t4, $t3, $at
  sw    $t4, 4($t2)
.L7000E660:
  lw    $a0, 0x1c($sp)
  jal   osWritebackDCache
   li    $a1, 64
  jal   __osSpSetStatus
   li    $a0, 11008
  lui   $a0, (0x04001000 >> 16) # lui $a0, 0x400
  jal   __osSpSetPc
   ori   $a0, (0x04001000 & 0xFFFF) # ori $a0, $a0, 0x1000
  li    $at, -1
  bne   $v0, $at, .L7000E6A4
   nop   
.L7000E68C:
  lui   $a0, (0x04001000 >> 16) # lui $a0, 0x400
  jal   __osSpSetPc
   ori   $a0, (0x04001000 & 0xFFFF) # ori $a0, $a0, 0x1000
  li    $at, -1
  beq   $v0, $at, .L7000E68C
   nop   
.L7000E6A4:
  lui   $a1, (0x04000FC0 >> 16) # lui $a1, 0x400
  ori   $a1, (0x04000FC0 & 0xFFFF) # ori $a1, $a1, 0xfc0
  li    $a0, 1
  lw    $a2, 0x1c($sp)
  jal   __osSpRawStartDma
   li    $a3, 64
  li    $at, -1
  bne   $v0, $at, .L7000E6EC
   nop   
.L7000E6C8:
  lui   $a1, (0x04000FC0 >> 16) # lui $a1, 0x400
  ori   $a1, (0x04000FC0 & 0xFFFF) # ori $a1, $a1, 0xfc0
  li    $a0, 1
  lw    $a2, 0x1c($sp)
  jal   __osSpRawStartDma
   li    $a3, 64
  li    $at, -1
  beq   $v0, $at, .L7000E6C8
   nop   
.L7000E6EC:
  jal   __osSpDeviceBusy
   nop   
  beqz  $v0, .L7000E70C
   nop   
.L7000E6FC:
  jal   __osSpDeviceBusy
   nop   
  bnez  $v0, .L7000E6FC
   nop   
.L7000E70C:
  lw    $t5, 0x1c($sp)
  lui   $a1, (0x04001000 >> 16) # lui $a1, 0x400
  ori   $a1, (0x04001000 & 0xFFFF) # ori $a1, $a1, 0x1000
  li    $a0, 1
  lw    $a2, 8($t5)
  jal   __osSpRawStartDma
   lw    $a3, 0xc($t5)
  li    $at, -1
  bne   $v0, $at, .L7000E75C
   nop   
.L7000E734:
  lw    $t7, 0x1c($sp)
  lui   $a1, (0x04001000 >> 16) # lui $a1, 0x400
  ori   $a1, (0x04001000 & 0xFFFF) # ori $a1, $a1, 0x1000
  li    $a0, 1
  lw    $a2, 8($t7)
  jal   __osSpRawStartDma
   lw    $a3, 0xc($t7)
  li    $at, -1
  beq   $v0, $at, .L7000E734
   nop   
.L7000E75C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   

glabel osSpTaskStartGo
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   __osSpDeviceBusy
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7000E794
   nop   
.L7000E784:
  jal   __osSpDeviceBusy
   nop   
  bnez  $v0, .L7000E784
   nop   
.L7000E794:
  jal   __osSpSetStatus
   li    $a0, 293
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
