char rumble_off_player1_packet_buffer[256];
char rumble_on_player_packet_buffers[256];
char rumble_on_buffer[32];
char rumble_off_buffer[32];

asm(R"
glabel send_rumble_off_to_PIF
  addiu $sp, $sp, -0x50
  sw    $ra, 0x14($sp)
  jal   __osSiGetAccess
   sw    $a0, 0x50($sp)
  lw    $t7, 0x50($sp)
  li    $t6, 3
  lui   $at, %hi(__osContLastCmd)
  sb    $t6, %lo(__osContLastCmd)($at)
  lw    $t8, 8($t7)
  lui   $t0, %hi(rumble_off_player1_packet_buffer) 
  addiu $t0, %lo(rumble_off_player1_packet_buffer) # addiu $t0, $t0, 0x55a0
  sll   $t9, $t8, 6
  addu  $a1, $t9, $t0
  jal   __osSiRawStartDma
   li    $a0, 1
  lw    $t1, 0x50($sp)
  move  $a1, $zero
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 4($t1)
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  lw    $t2, 0x50($sp)
  move  $a1, $zero
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 4($t2)
  lw    $t3, 0x50($sp)
  lui   $v1, %hi(__osPfsPifRam)
  addiu $v1, %lo(__osPfsPifRam) # addiu $v1, $v1, 0x7d70
  lw    $a0, 8($t3)
  addiu $t4, $sp, 0x1c
  beql  $a0, $zero, .L7000CA2C
   move  $t7, $v1
  blez  $a0, .L7000CA28
   move  $v0, $zero
.L7000CA18:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  bnez  $at, .L7000CA18
   addiu $v1, $v1, 1
.L7000CA28:
  move  $t7, $v1
.L7000CA2C:
  addiu $t6, $v1, 0x24
.L7000CA30:
  lwl   $at, ($t7)
  lwr   $at, 3($t7)
  addiu $t7, $t7, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lwl   $at, -8($t7)
  lwr   $at, -5($t7)
  sw    $at, -8($t4)
  lwl   $at, -4($t7)
  lwr   $at, -1($t7)
  bne   $t7, $t6, .L7000CA30
   sw    $at, -4($t4)
  lwl   $at, ($t7)
  lwr   $at, 3($t7)
  sw    $at, ($t4)
  lbu   $v0, 0x1e($sp)
  lbu   $t0, 0x42($sp)
  andi  $t8, $v0, 0xc0
  sra   $a0, $t8, 4
  bnez  $a0, .L7000CA90
   nop   
  beqz  $t0, .L7000CA90
   nop   
  li    $a0, 4
.L7000CA90:
  jal   __osSiRelAccess
   sw    $a0, 0x48($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x48($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000CAAC
  addiu $sp, $sp, -0x50
  sw    $ra, 0x14($sp)
  jal   __osSiGetAccess
   sw    $a0, 0x50($sp)
  lw    $t7, 0x50($sp)
  li    $t6, 3
  lui   $at, %hi(__osContLastCmd)
  sb    $t6, %lo(__osContLastCmd)($at)
  lw    $t8, 8($t7)
  lui   $t0, %hi(rumble_on_player_packet_buffers) 
  addiu $t0, %lo(rumble_on_player_packet_buffers) # addiu $t0, $t0, 0x56a0
  sll   $t9, $t8, 6
  addu  $a1, $t9, $t0
  jal   __osSiRawStartDma
   li    $a0, 1
  lw    $t1, 0x50($sp)
  move  $a1, $zero
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 4($t1)
  lui   $a1, %hi(__osPfsPifRam)
  addiu $a1, %lo(__osPfsPifRam) # addiu $a1, $a1, 0x7d70
  jal   __osSiRawStartDma
   move  $a0, $zero
  lw    $t2, 0x50($sp)
  move  $a1, $zero
  li    $a2, 1
  jal   osRecvMesg
   lw    $a0, 4($t2)
  lw    $t3, 0x50($sp)
  lui   $v1, %hi(__osPfsPifRam)
  addiu $v1, %lo(__osPfsPifRam) # addiu $v1, $v1, 0x7d70
  lw    $a0, 8($t3)
  addiu $t4, $sp, 0x1c
  beql  $a0, $zero, .L7000CB58
   move  $t7, $v1
  blez  $a0, .L7000CB54
   move  $v0, $zero
.L7000CB44:
  addiu $v0, $v0, 1
  slt   $at, $v0, $a0
  bnez  $at, .L7000CB44
   addiu $v1, $v1, 1
.L7000CB54:
  move  $t7, $v1
.L7000CB58:
  addiu $t6, $v1, 0x24
.L7000CB5C:
  lwl   $at, ($t7)
  lwr   $at, 3($t7)
  addiu $t7, $t7, 0xc
  addiu $t4, $t4, 0xc
  sw    $at, -0xc($t4)
  lwl   $at, -8($t7)
  lwr   $at, -5($t7)
  sw    $at, -8($t4)
  lwl   $at, -4($t7)
  lwr   $at, -1($t7)
  bne   $t7, $t6, .L7000CB5C
   sw    $at, -4($t4)
  lwl   $at, ($t7)
  lwr   $at, 3($t7)
  sw    $at, ($t4)
  lbu   $v0, 0x1e($sp)
  lbu   $t0, 0x42($sp)
  li    $at, 235
  andi  $t8, $v0, 0xc0
  sra   $a0, $t8, 4
  bnez  $a0, .L7000CBC0
   nop   
  beq   $t0, $at, .L7000CBC0
   nop   
  li    $a0, 4
.L7000CBC0:
  jal   __osSiRelAccess
   sw    $a0, 0x48($sp)
  lw    $ra, 0x14($sp)
  lw    $v0, 0x48($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000CBDC
  addiu $sp, $sp, -0x58
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x5c($sp)
  move  $v1, $a3
  move  $t0, $zero
  move  $v0, $a3
.L7000CBFC:
  addiu $t0, $t0, 1
  slti  $at, $t0, 0xf
  addiu $v0, $v0, 4
  bnez  $at, .L7000CBFC
   sw    $zero, -4($v0)
  li    $t6, 1
  sw    $t6, 0x3c($a3)
  li    $t7, 255
  li    $t8, 35
  li    $t9, 1
  li    $t1, 3
  sb    $t7, 0x2c($sp)
  sb    $t8, 0x2d($sp)
  sb    $t9, 0x2e($sp)
  sb    $t1, 0x2f($sp)
  sw    $a2, 0x60($sp)
  sw    $v1, 0x54($sp)
  jal   __osContAddressCrc
   lhu   $a0, 0x5e($sp)
  lhu   $t2, 0x5e($sp)
  li    $t5, 255
  lw    $v1, 0x54($sp)
  sll   $t3, $t2, 5
  or    $t4, $v0, $t3
  sh    $t4, 0x30($sp)
  lw    $a2, 0x60($sp)
  sb    $t5, 0x52($sp)
  addiu $v0, $sp, 0x4c
  addiu $a0, $sp, 0x2c
.L7000CC70:
  lbu   $t6, ($a2)
  addiu $a0, $a0, 1
  sltu  $at, $a0, $v0
  addiu $a2, $a2, 1
  bnez  $at, .L7000CC70
   sb    $t6, 5($a0)
  beqz  $s0, .L7000CCD4
   addiu $t7, $sp, 0x2c
  blez  $s0, .L7000CCD4
   move  $t0, $zero
  andi  $a0, $s0, 3
  beqz  $a0, .L7000CCB8
   move  $v0, $a0
.L7000CCA4:
  addiu $t0, $t0, 1
  sb    $zero, ($v1)
  bne   $v0, $t0, .L7000CCA4
   addiu $v1, $v1, 1
  beq   $t0, $s0, .L7000CCD4
.L7000CCB8:
   addiu $t0, $t0, 4
  sb    $zero, 1($v1)
  sb    $zero, 2($v1)
  sb    $zero, 3($v1)
  addiu $v1, $v1, 4
  bne   $t0, $s0, .L7000CCB8
   sb    $zero, -4($v1)
.L7000CCD4:
  move  $t1, $v1
  addiu $t9, $t7, 0x24
.L7000CCDC:
  lw    $at, ($t7)
  addiu $t7, $t7, 0xc
  addiu $t1, $t1, 0xc
  swl   $at, -0xc($t1)
  swr   $at, -9($t1)
  lw    $at, -8($t7)
  swl   $at, -8($t1)
  swr   $at, -5($t1)
  lw    $at, -4($t7)
  swl   $at, -4($t1)
  bne   $t7, $t9, .L7000CCDC
   swr   $at, -1($t1)
  lw    $at, ($t7)
  li    $t2, 254
  addiu $v1, $v1, 0x28
  swl   $at, ($t1)
  swr   $at, 3($t1)
  sb    $t2, ($v1)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
glabel controller_7000CD38
  addiu $sp, $sp, -0x58
  sw    $s0, 0x20($sp)
  sw    $ra, 0x24($sp)
  li    $a3, 128
  move  $s0, $a2
  sw    $a0, 4($a1)
  sw    $a2, 8($a1)
  sw    $zero, ($a1)
  sb    $a3, 0x65($a1)
  addiu $v0, $sp, 0x30
  addiu $v1, $sp, 0x50
.L7000CD64:
  addiu $v0, $v0, 1
  sltu  $at, $v0, $v1
  bnez  $at, .L7000CD64
   sb    $a3, -1($v0)
  move  $a1, $s0
  li    $a2, 1024
  addiu $a3, $sp, 0x30
  sw    $zero, 0x10($sp)
  jal   __osContRamWrite
   sw    $a0, 0x58($sp)
  li    $at, 2
  bne   $v0, $at, .L7000CDB4
   move  $v1, $v0
  lw    $a0, 0x58($sp)
  move  $a1, $s0
  li    $a2, 1024
  addiu $a3, $sp, 0x30
  jal   __osContRamWrite
   sw    $zero, 0x10($sp)
  move  $v1, $v0
.L7000CDB4:
  beqz  $v0, .L7000CDC4
   lw    $a0, 0x58($sp)
  b     .L7000CE8C
   move  $v0, $v1
.L7000CDC4:
  move  $a1, $s0
  li    $a2, 1024
  jal   __osContRamRead
   addiu $a3, $sp, 0x30
  beqz  $v0, .L7000CDE4
   lbu   $t6, 0x4f($sp)
  b     .L7000CE90
   lw    $ra, 0x24($sp)
.L7000CDE4:
  li    $at, 128
  beq   $t6, $at, .L7000CDF8
   lui   $a0, %hi(rumble_off_buffer)
  b     .L7000CE8C
   li    $v0, 11
.L7000CDF8:
  lui   $v1, %hi(rumble_on_buffer)
  lui   $a1, %hi(rumble_off_buffer)
  addiu $a1, %lo(rumble_off_buffer) # addiu $a1, $a1, 0x57c0
  addiu $v1, %lo(rumble_on_buffer) # addiu $v1, $v1, 0x57a0
  addiu $a0, %lo(rumble_off_buffer) # addiu $a0, $a0, 0x57c0
  li    $v0, 1
.L7000CE10:
  addiu $v1, $v1, 4
  sb    $v0, 1($a0)
  sb    $zero, -3($v1)
  sb    $v0, 2($a0)
  sb    $zero, -2($v1)
  sb    $v0, 3($a0)
  sb    $zero, -1($v1)
  addiu $a0, $a0, 4
  sb    $v0, -4($a0)
  bne   $v1, $a1, .L7000CE10
   sb    $zero, -4($v1)
  lui   $t7, %hi(rumble_on_player_packet_buffers) 
  addiu $t7, %lo(rumble_on_player_packet_buffers) # addiu $t7, $t7, 0x56a0
  lui   $a2, %hi(rumble_off_buffer)
  sll   $v0, $s0, 6
  addu  $a3, $v0, $t7
  sw    $v0, 0x2c($sp)
  addiu $a2, %lo(rumble_off_buffer) # addiu $a2, $a2, 0x57c0
  move  $a0, $s0
  jal   controller_7000CBDC
   li    $a1, 1536
  lw    $v0, 0x2c($sp)
  lui   $t8, %hi(rumble_off_player1_packet_buffer) 
  addiu $t8, %lo(rumble_off_player1_packet_buffer) # addiu $t8, $t8, 0x55a0
  lui   $a2, %hi(rumble_on_buffer)
  addiu $a2, %lo(rumble_on_buffer) # addiu $a2, $a2, 0x57a0
  move  $a0, $s0
  li    $a1, 1536
  jal   controller_7000CBDC
   addu  $a3, $v0, $t8
  move  $v0, $zero
.L7000CE8C:
  lw    $ra, 0x24($sp)
.L7000CE90:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");
