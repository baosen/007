asm(R"
glabel init_menus_or_reset
  li    $v0, -1
  lui   $at, %hi(current_menu)
  sw    $v0, %lo(current_menu)($at)
  lui   $at, %hi(maybe_prev_menu)
  sw    $v0, %lo(maybe_prev_menu)($at)
  lui   $at, %hi(screen_size)
  sw    $zero, %lo(screen_size)($at)
  li    $v1, 1
  lui   $at, %hi(spectrum_related_flag)
  sw    $v1, %lo(spectrum_related_flag)($at)
  lui   $at, %hi(is_emulating_spectrum)
  sw    $zero, %lo(is_emulating_spectrum)($at)
  lui   $at, %hi(folder_selection_screen_option_icon)
  sw    $zero, %lo(folder_selection_screen_option_icon)($at)
  lui   $at, %hi(folder_selected_for_deletion)
  sw    $v0, %lo(folder_selected_for_deletion)($at)
  lui   $at, %hi(folder_selected_for_deletion_choice)
  sw    $v1, %lo(folder_selected_for_deletion_choice)($at)
  lui   $at, %hi(tab_1_highlight)
  sw    $zero, %lo(tab_1_highlight)($at)
  lui   $at, %hi(tab_2_highlight)
  sw    $zero, %lo(tab_2_highlight)($at)
  lui   $t6, %hi(prev_keypresses) 
  lw    $t6, %lo(prev_keypresses)($t6)
  lui   $at, %hi(tab_3_highlight)
  sw    $zero, %lo(tab_3_highlight)($at)
  addiu $sp, $sp, -0x18
  lui   $at, %hi(maybe_is_in_menu)
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F000DAC
   sw    $v1, %lo(maybe_is_in_menu)($at)
  lui   $v0, %hi(menu_update)
  addiu $v0, %lo(menu_update) # addiu $v0, $v0, -0x573c
  li    $t7, 5
  sw    $t7, ($v0)
.L7F000DAC:
  lui   $v0, %hi(menu_update)
  addiu $v0, %lo(menu_update) # addiu $v0, $v0, -0x573c
  lw    $t8, ($v0)
  lui   $a0, (0x00078000 >> 16) # lui $a0, 7
  li    $t9, 5
  bgez  $t8, .L7F000DCC
   ori   $a0, (0x00078000 & 0xFFFF) # ori $a0, $a0, 0x8000
  sw    $t9, ($v0)
.L7F000DCC:
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $at, %hi(ptr_logo_and_walletbond_DL)
  lui   $a0, (0x0004B040 >> 16) # lui $a0, 4
  sw    $v0, %lo(ptr_logo_and_walletbond_DL)($at)
  ori   $a0, (0x0004B040 & 0xFFFF) # ori $a0, $a0, 0xb040
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $v1, %hi(ptr_menu_videobuffer)
  addiu $t1, $v0, 0x3f
  li    $at, -64
  addiu $v1, %lo(ptr_menu_videobuffer) # addiu $v1, $v1, -0x56ac
  and   $t2, $t1, $at
  sw    $v0, ($v1)
  sw    $t2, ($v1)
  lui   $at, %hi(ptr_folder_object_instance)
  sw    $zero, %lo(ptr_folder_object_instance)($at)
  lui   $at, %hi(set0_never_used)
  sw    $zero, %lo(set0_never_used)($at)
  lui   $at, %hi(set0_never_used_0)
  sw    $zero, %lo(set0_never_used_0)($at)
  lui   $at, %hi(D_8002A968)
  jal   alloc_intro_matrices
   sw    $zero, %lo(D_8002A968)($at)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
