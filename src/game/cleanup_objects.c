asm(R"
.rdata
glabel jpt_8004F210
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F00755C
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550
    .word .L7F00755C
    .word .L7F007550

.text
glabel cleanupObjects
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  lui   $s0, %hi(ptr_setup_objects)
  lw    $s0, %lo(ptr_setup_objects)($s0)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  beql  $s0, $zero, .L7F007580
   lw    $ra, 0x1c($sp)
  lbu   $v1, 3($s0)
  li    $at, 48
  beq   $v1, $at, .L7F00757C
   addiu $t6, $v1, -1
   
.L7F007530:
  sltiu $at, $t6, 0x2f
  beqz  $at, .L7F00755C
   sll   $t6, $t6, 2
  lui   $at, %hi(jpt_8004F210)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8004F210)($at)
  jr    $t6
   nop 

.L7F007550:
  move  $a0, $s0
  jal   sub_GAME_7F041024
   li    $a1, 1

.L7F00755C:
  jal   get_size_of_setup_object_type
   move  $a0, $s0
  sll   $t7, $v0, 2
  addu  $s0, $t7, $s0
  lbu   $v1, 3($s0)
  li    $at, 48
  bnel  $v1, $at, .L7F007530
   addiu $t6, $v1, -1

.L7F00757C:
  lw    $ra, 0x1c($sp)

.L7F007580:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
