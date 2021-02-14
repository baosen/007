asm(R"
glabel sub_GAME_7F0061F0
  lui   $a0, %hi(pPlayer)
  addiu $a0, %lo(pPlayer) # addiu $a0, $a0, -0x5f50
  lw    $t6, ($a0)
  li    $a1, -1
  li    $v1, 24
  sw    $zero, 0x11ec($t6)
  lw    $t7, ($a0)
  li    $v0, 120
  sw    $a1, 0x1200($t7)
  lw    $t8, ($a0)
  sw    $a1, 0x120c($t8)
.L7F00621C:
  lw    $t9, ($a0)
  addu  $t0, $t9, $v1
  sw    $a1, 0x1200($t0)
  lw    $t1, ($a0)
  addu  $t2, $t1, $v1
  sw    $a1, 0x120c($t2)
  lw    $t3, ($a0)
  addu  $t4, $t3, $v1
  sw    $a1, 0x1218($t4)
  lw    $t5, ($a0)
  addu  $t6, $t5, $v1
  addiu $v1, $v1, 0x30
  bne   $v1, $v0, .L7F00621C
   sw    $a1, 0x1224($t6)
  jr    $ra
   nop   
");

asm(R"
glabel alloc_additional_item_slots
  lui   $v0, %hi(pPlayer)
  addiu $v0, %lo(pPlayer) # addiu $v0, $v0, -0x5f50
  lw    $t7, ($v0)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  addiu $t6, $a0, 0x1e
  sw    $t6, 0x11e8($t7)
  lw    $t8, ($v0)
  li    $a1, 4
  lw    $a0, 0x11e8($t8)
  sll   $t9, $a0, 2
  addu  $t9, $t9, $a0
  sll   $t9, $t9, 2
  addiu $a0, $t9, 0xf
  ori   $t0, $a0, 0xf
  jal   mempAllocBytesInBank
   xori  $a0, $t0, 0xf
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  jal   reinit_player_inventory
   sw    $v0, 0x11e4($t2)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop
");
