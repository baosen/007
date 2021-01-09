#ifdef VERSION_US
asm(R"
glabel something_with_stage_objectives
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_stage_num
   nop   
  li    $at, 90
  beq   $v0, $at, .L7F004F1C
   li    $t6, -1
  lui   $at, %hi(num_objective_ptrs)
  sw    $t6, %lo(num_objective_ptrs)($at)
  lui   $at, %hi(dword_CODE_bss_80075D58)
  sw    $zero, %lo(dword_CODE_bss_80075D58)($at)
  lui   $at, %hi(dword_CODE_bss_80075D5C)
  lui   $v0, %hi(dword_CODE_bss_80075D60)
  lui   $v1, %hi(ptr_last_tag_entry_type16)
  addiu $v1, %lo(ptr_last_tag_entry_type16) # addiu $v1, $v1, 0x5d80
  addiu $v0, %lo(dword_CODE_bss_80075D60) # addiu $v0, $v0, 0x5d60
  sw    $zero, %lo(dword_CODE_bss_80075D5C)($at)
.L7F004F04:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F004F04
   sw    $zero, -0x10($v0)
.L7F004F1C:
  lui   $at, %hi(objective_ptrs)
  sw    $zero, %lo(objective_ptrs)($at)
  lui   $at, %hi(objective_ptrs+4)
  lui   $v0, %hi(objective_ptrs+8)
  lui   $v1, %hi(dword_CODE_bss_80075D58)
  addiu $v1, %lo(dword_CODE_bss_80075D58) # addiu $v1, $v1, 0x5d58
  addiu $v0, %lo(objective_ptrs+8) # addiu $v0, $v0, 0x5d38
  sw    $zero, %lo(objective_ptrs+4)($at)
.L7F004F3C:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F004F3C
   sw    $zero, -0x10($v0)
  lui   $at, %hi(ptr_last_tag_entry_type16)
  sw    $zero, %lo(ptr_last_tag_entry_type16)($at)
  lui   $at, %hi(ptr_last_briefing_setup_entry_type23)
  sw    $zero, %lo(ptr_last_briefing_setup_entry_type23)($at)
  lui   $at, %hi(ptr_last_enter_room_subobject_entry_type20)
  sw    $zero, %lo(ptr_last_enter_room_subobject_entry_type20)($at)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
  sw    $zero, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($at)
  lui   $at, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
  sw    $zero, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");
#endif

#ifdef VERSION_JP
asm(R"
glabel something_with_stage_objectives
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_stage_num
   nop   
  li    $at, 90
  beq   $v0, $at, .L7F004F2C
   li    $t6, -1
  lui   $at, %hi(num_objective_ptrs) # $at, 0x8003
  sw    $t6, %lo(num_objective_ptrs)($at)
  lui   $at, %hi(dword_CODE_bss_80075D58) # $at, 0x8007
  sw    $zero, %lo(dword_CODE_bss_80075D58)($at)
  lui   $at, %hi(dword_CODE_bss_80075D5C) # $at, 0x8007
  lui   $v0, %hi(dword_CODE_bss_80075D60) # $v0, 0x8007
  lui   $v1, %hi(ptr_last_tag_entry_type16) # $v1, 0x8007
  addiu $v1, %lo(ptr_last_tag_entry_type16) # addiu $v1, $v1, 0x5dc0
  addiu $v0, %lo(dword_CODE_bss_80075D60) # addiu $v0, $v0, 0x5da0
  sw    $zero, %lo(dword_CODE_bss_80075D5C)($at)
.L7F004F14:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F004F14
   sw    $zero, -0x10($v0)
.L7F004F2C:
  lui   $at, %hi(num_objective_ptrs+4) # $at, 0x8003
  sw    $zero, %lo(num_objective_ptrs+4)($at)
  lui   $at, %hi(objective_ptrs) # $at, 0x8007
  sw    $zero, %lo(objective_ptrs)($at)
  lui   $at, %hi(objective_ptrs+4) # $at, 0x8007
  lui   $v0, %hi(objective_ptrs+8) # $v0, 0x8007
  lui   $v1, %hi(dword_CODE_bss_80075D58) # $v1, 0x8007
  addiu $v1, %lo(dword_CODE_bss_80075D58) # addiu $v1, $v1, 0x5d98
  addiu $v0, %lo(objective_ptrs+8) # addiu $v0, $v0, 0x5d78
  sw    $zero, %lo(objective_ptrs+4)($at)
.L7F004F54:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F004F54
   sw    $zero, -0x10($v0)
  lui   $at, %hi(ptr_last_tag_entry_type16) # $at, 0x8007
  sw    $zero, %lo(ptr_last_tag_entry_type16)($at)
  lui   $at, %hi(ptr_last_briefing_setup_entry_type23) # $at, 0x8007
  sw    $zero, %lo(ptr_last_briefing_setup_entry_type23)($at)
  lui   $at, %hi(ptr_last_enter_room_subobject_entry_type20) # $at, 0x8007
  sw    $zero, %lo(ptr_last_enter_room_subobject_entry_type20)($at)
  lw    $ra, 0x14($sp)
  lui   $at, %hi(ptr_last_deposit_in_room_subobject_entry_type21) # $at, 0x8007
  sw    $zero, %lo(ptr_last_deposit_in_room_subobject_entry_type21)($at)
  lui   $at, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E) # $at, 0x8007
  sw    $zero, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");
#endif

asm(R"
glabel set_parent_cur_tag_entry
  lui   $v0, %hi(ptr_last_tag_entry_type16)
  addiu $v0, %lo(ptr_last_tag_entry_type16) # addiu $v0, $v0, 0x5d80
  lw    $t6, ($v0)
  sw    $t6, 8($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel setup_briefing_text_entry_parent
  lui   $v0, %hi(ptr_last_briefing_setup_entry_type23)
  addiu $v0, %lo(ptr_last_briefing_setup_entry_type23) # addiu $v0, $v0, 0x5d84
  lw    $t6, ($v0)
  sw    $t6, 0xc($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel add_ptr_to_objective
  lw    $t6, 4($a0)
  lui   $at, %hi(objective_ptrs)
  lui   $v1, %hi(num_objective_ptrs)
  sll   $t7, $t6, 2
  addu  $at, $at, $t7
  sw    $a0, %lo(objective_ptrs)($at)
  addiu $v1, %lo(num_objective_ptrs) # addiu $v1, $v1, 0x22f0
  lw    $t8, ($v1)
  lw    $v0, 4($a0)
  slt   $at, $t8, $v0
  beqz  $at, .L7F004FEC
   nop   
  sw    $v0, ($v1)
.L7F004FEC:
  jr    $ra
   nop   
");

asm(R"
glabel set_parent_cur_obj_enter_room
  lui   $v0, %hi(ptr_last_enter_room_subobject_entry_type20)
  addiu $v0, %lo(ptr_last_enter_room_subobject_entry_type20) # addiu $v0, $v0, 0x5d88
  lw    $t6, ($v0)
  sw    $t6, 0xc($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel set_parent_cur_obj_deposited_in_room
  lui   $v0, %hi(ptr_last_deposit_in_room_subobject_entry_type21)
  addiu $v0, %lo(ptr_last_deposit_in_room_subobject_entry_type21) # addiu $v0, $v0, 0x5d8c
  lw    $t6, ($v0)
  sw    $t6, 0x10($a0)
  jr    $ra
   sw    $a0, ($v0)
");

asm(R"
glabel set_parent_cur_obj_photograph
  lui   $v0, %hi(ptr_last_photo_obj_in_room_subobject_entry_type1E)
  addiu $v0, %lo(ptr_last_photo_obj_in_room_subobject_entry_type1E) # addiu $v0, $v0, 0x5d90
  lw    $t6, ($v0)
  sw    $t6, 0xc($a0)
  jr    $ra
   sw    $a0, ($v0)
");
