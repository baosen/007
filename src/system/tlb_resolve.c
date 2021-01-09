// Loads/resolves TLB address, writing random entry.
asm(R"
glabel resolve_TLBaddress_for_InvalidHit
  mtc0  $zero, $5
  nop   
  mfc0  $k0, $4
  lui   $k1, %hi(TLB_manager_mapping_table_end) # $k1, 0x8006
  addiu $k1, %lo(TLB_manager_mapping_table_end) # addiu $k1, $k1, -0x1b5c
  lw    $k1, ($k1)
  addu  $k0, $k0, $k1
  lw    $k1, ($k0)
  mtc0  $k1, $2
  nop   
  addiu $k1, $k1, 0x40
  mtc0  $k1, $3
  nop   
  tlbwr 
  nop   
  nop   
  nop   
  nop   
  eret  
");
