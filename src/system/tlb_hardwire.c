// Sets #hardwired TLB entries to 2.
asm(R"
glabel set_hardwire_TLB_to_2
  li    $t0, 2
  mtc0  $t0, $6
  li    $t0, 0
  mtc0  $t0, $4
  jr    $ra
  nop  
");
