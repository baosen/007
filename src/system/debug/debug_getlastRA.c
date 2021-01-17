/*
 * Get last return address on stack.
 *
 * V0=value of RA previously saved to the stack or -1 if impossible to retrieve.
 * Searches backward from caller for last instance of RA saved to stack.
 */
asm(R"
glabel return_last_RA_saved_to_stack
  move  $a0, $ra
  li    $v0, -1
glabel .L70005B18
  lw    $t0, ($a0)
  li    $t2, 10173
  srl   $t1, $t0, 0x10
  beq   $t1, $t2, .L70005B50
   nop   
  li    $t2, 44991
  beql  $t1, $t2, .L70005B44
   sll   $t2, $t0, 0x10
  j     .L70005B18
   addiu $a0, $a0, -4
  sll   $t2, $t0, 0x10
.L70005B44:
  sra   $t2, $t2, 0x10
  add   $t2, $t2, $sp
  lw    $v0, ($t2)
.L70005B50:
  jr    $ra
   nop   
");
