unsigned int D_8002A780 = 0;
unsigned int D_8002A784 = 0;
unsigned int D_8002A788 = 0;

asm(R"
glabel set_weapon_model_generated_thrown_object
  addiu $t6, $a0, -3
  addiu $sp, $sp, -0x18
  sltiu $at, $t6, 0x2e
  sw    $ra, 0x14($sp)
  beqz  $at, .L7F00579C
  li    $a1, -1
  sll   $t6, $t6, 2
  lui   $at, %hi(projectile_ptr_table)
  addu  $at, $at, $t6
  lw    $t6, %lo(projectile_ptr_table)($at)
  jr    $t6
  nop
throwingknife:
  b     .L7F00579C
  li    $a1, 186
grenade_launch_round:
  b     .L7F00579C
  li    $a1, 203
rocket:
  b     .L7F00579C
  li    $a1, 202
grenade:
  b     .L7F00579C
  li    $a1, 196
timed_mine:
  b     .L7F00579C
  li    $a1, 201
prox_mine:
  b     .L7F00579C
  li    $a1, 200
remote_mine:
  b     .L7F00579C
  li    $a1, 199
rocket_0:
  b     .L7F00579C
  li    $a1, 202
bombcase:
  b     .L7F00579C
  li    $a1, 226
plastique:
  b     .L7F00579C
  li    $a1, 273
bug:
  b     .L7F00579C
  li    $a1, 245
microcamera:
  li    $a1, 246
default:
.L7F00579C:
  bltz  $a1, .L7F0057B4
  move  $v0, $zero
  jal   load_model
  move  $a0, $a1
  b     .L7F0057B8
  lw    $ra, 0x14($sp)
.L7F0057B4:
  lw    $ra, 0x14($sp)
.L7F0057B8:
  addiu $sp, $sp, 0x18
  jr    $ra
  nop
");

#ifdef VERSION_US
asm(R"
.late_rodata
glabel projectile_ptr_table
.word throwingknife
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word grenade_launch_round
.word rocket
.word grenade
.word timed_mine
.word prox_mine
.word remote_mine
.word default
.word default
.word rocket_0
.word bombcase
.word plastique
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word bug
.word microcamera

glabel default_zoom_speed
.word 0x3f68ba2e

glabel jpt_8004F1AC
    .word spawn_point
    .word weapon
    .word ammo
    .word swirling_intro_cam
    .word intro_ani
    .word cuff_char
    .word fixed_cam
    .word watch_time
    .word credits

glabel D_8004F1D0
.word 0xb8d1b717
glabel D_8004F1D4
.word 0x40c90fdb
glabel D_8004F1D8
.word 0x40c90fdb
glabel D_8004F1DC
.word 0x3e2e147c
glabel D_8004F1E0
.word 0x3dccccd0

.text
glabel load_camera_intro_type_values
  addiu $sp, $sp, -0x98
  lui   $t7, %hi(D_8002A780) 
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sw    $s0, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  addiu $t7, %lo(D_8002A780) # addiu $t7, $t7, -0x5880
  lw    $at, ($t7)
  addiu $t6, $sp, 0x8c
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t0, 4($t6)
  lui   $s1, %hi(resolution)
  sw    $at, 8($t6)
  lui   $at, %hi(mission_kia_flag)
  sw    $zero, %lo(mission_kia_flag)($at)
  lui   $at, %hi(camera_80036424)
  lui   $s0, %hi(ptr_setup_intro)
  sw    $zero, %lo(camera_80036424)($at)
  addiu $s1, %lo(resolution) # addiu $s1, $s1, 0x6428
  lw    $s0, %lo(ptr_setup_intro)($s0)
  sw    $zero, ($s1)
  lui   $at, %hi(camera_8003642C)
  lui   $s2, %hi(camera_80036430)
  sw    $zero, %lo(camera_8003642C)($at)
  mtc1  $zero, $f4
  addiu $s2, %lo(camera_80036430) # addiu $s2, $s2, 0x6430
  sw    $zero, ($s2)
  lui   $at, %hi(camera_80036434)
  sw    $zero, 0x7c($sp)
  sw    $zero, %lo(camera_80036434)($at)
  jal   get_stage_num
   swc1  $f4, 0x88($sp)
  li    $at, 54
  bne   $v0, $at, .L7F005888
   lui   $a0, (0x00046EA0 >> 16) # lui $a0, 4
  ori   $a0, (0x00046EA0 & 0xFFFF) # ori $a0, $a0, 0x6ea0
  jal   mempAllocBytesInBank
   li    $a1, 4
  addiu $t2, $v0, 0x3f
  li    $at, -64
  sw    $v0, ($s1)
  and   $t3, $t2, $at
  li    $t4, 1
  sw    $t3, ($s1)
  sw    $t4, ($s2)
.L7F005888:
  lui   $at, %hi(camera_80036438)
  sw    $zero, %lo(camera_80036438)($at)
  lui   $at, %hi(D_8003643C)
  sw    $zero, %lo(D_8003643C)($at)
  lui   $at, %hi(D_80036440)
  lui   $v0, %hi(flt_CODE_bss_80079990)
  sw    $zero, %lo(D_80036440)($at)
  mtc1  $zero, $f6
  mtc1  $zero, $f8
  mtc1  $zero, $f10
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6670
  lui   $at, %hi(D_80036444)
  swc1  $f6, ($v0)
  swc1  $f8, 4($v0)
  swc1  $f10, 8($v0)
  sw    $zero, %lo(D_80036444)($at)
  lui   $at, %hi(dword_CODE_bss_80079C68)
  sw    $zero, %lo(dword_CODE_bss_80079C68)($at)
  lui   $at, %hi(in_tank_flag)
  sw    $zero, %lo(in_tank_flag)($at)
  lui   $at, %hi(D_8003644C)
  sw    $zero, %lo(D_8003644C)($at)
  mtc1  $zero, $f16
  lui   $at, %hi(ptr_playerstank)
  sw    $zero, %lo(ptr_playerstank)($at)
  lui   $at, %hi(D_80036454)
  lui   $v1, %hi(SFX_80036458)
  swc1  $f16, %lo(D_80036454)($at)
  mtc1  $zero, $f18
  addiu $v1, %lo(SFX_80036458) # addiu $v1, $v1, 0x6458
  mtc1  $zero, $f4
  sw    $zero, ($v1)
  sw    $zero, 4($v1)
  lui   $at, %hi(D_80036460)
  swc1  $f18, %lo(D_80036460)($at)
  mtc1  $zero, $f6
  lui   $at, %hi(D_80036464)
  swc1  $f4, %lo(D_80036464)($at)
  mtc1  $zero, $f8
  lui   $at, %hi(D_80036468)
  swc1  $f6, %lo(D_80036468)($at)
  mtc1  $zero, $f10
  lui   $at, %hi(D_8003646C)
  swc1  $f8, %lo(D_8003646C)($at)
  mtc1  $zero, $f16
  lui   $at, %hi(D_80036470)
  swc1  $f10, %lo(D_80036470)($at)
  mtc1  $zero, $f18
  lui   $at, %hi(D_80036474)
  swc1  $f16, %lo(D_80036474)($at)
  mtc1  $zero, $f4
  lui   $at, %hi(D_80036478)
  swc1  $f18, %lo(D_80036478)($at)
  lui   $at, %hi(D_8003647C)
  swc1  $f4, %lo(D_8003647C)($at)
  mtc1  $zero, $f6
  lui   $at, %hi(D_80036480)
  sw    $zero, %lo(D_80036480)($at)
  mtc1  $zero, $f8
  lui   $at, %hi(D_80036484)
  swc1  $f6, %lo(D_80036484)($at)
  lui   $at, %hi(D_80036488)
  swc1  $f8, %lo(D_80036488)($at)
  lui   $at, %hi(D_8003648C)
  sw    $zero, %lo(D_8003648C)($at)
  lui   $at, %hi(D_800364B0)
  li    $t5, 1
  sw    $t5, %lo(D_800364B0)($at)
  lui   $at, %hi(disable_player_pickups_flag)
  sw    $zero, %lo(disable_player_pickups_flag)($at)
  lui   $at, %hi(cameramode)
  sw    $zero, %lo(cameramode)($at)
  lui   $at, %hi(enable_move_after_cinema)
  sw    $zero, %lo(enable_move_after_cinema)($at)
  lui   $at, %hi(D_8003649C)
  sw    $zero, %lo(D_8003649C)($at)
  mtc1  $zero, $f10
  lui   $at, %hi(stop_time_flag)
  sw    $zero, %lo(stop_time_flag)($at)
  lui   $at, %hi(D_800364A4)
  swc1  $f10, %lo(D_800364A4)($at)
  lui   $at, %hi(D_800364A8)
  li    $t9, 1
  sw    $t9, %lo(D_800364A8)($at)
  lui   $at, %hi(D_800364AC)
  sw    $zero, %lo(D_800364AC)($at)
  lui   $at, %hi(ptr_random06cam_entry)
  sw    $zero, %lo(ptr_random06cam_entry)($at)
  lui   $at, %hi(D_800364B8)
  sw    $zero, %lo(D_800364B8)($at)
  lui   $at, %hi(D_800364BC)
  sw    $zero, %lo(D_800364BC)($at)
  lui   $at, %hi(mission_timer)
  lui   $s1, %hi(watch_time_0)
  sw    $zero, %lo(mission_timer)($at)
  addiu $s1, %lo(watch_time_0) # addiu $s1, $s1, -0x65dc
  sw    $zero, ($s1)
  lui   $at, %hi(D_80036514)
  sw    $zero, %lo(D_80036514)($at)
  lui   $at, %hi(default_zoom_speed)
  lwc1  $f16, %lo(default_zoom_speed)($at)
  lui   $at, %hi(watch_transition_time)
  swc1  $f16, %lo(watch_transition_time)($at)
  lui   $at, %hi(starting_left_weapon)
  sw    $zero, %lo(starting_left_weapon)($at)
  lui   $at, %hi(starting_right_weapon)
  beqz  $s0, .L7F005DF4
   sw    $zero, %lo(starting_right_weapon)($at)
  lw    $v0, ($s0)
  li    $at, 9
  lui   $s2, %hi(pPlayer)
  beq   $v0, $at, .L7F005DF4
   li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f22
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f20
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5f50
  sltiu $at, $v0, 9
.L7F005A60:
  beqz  $at, .L7F005DE0
   sll   $t8, $v0, 2
  lui   $at, %hi(jpt_8004F1AC)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8004F1AC)($at)
  jr    $t8
   nop   
spawn_point:
  lui   $t6, %hi(ptr_0xxxpresets) 
  lw    $t6, %lo(ptr_0xxxpresets)($t6)
  beqz  $t6, .L7F005AE8
   nop   
  jal   check_ramrom_flags
   nop   
  lw    $t7, 8($s0)
  lui   $t2, %hi(ptr_0xxxpresets) 
  lui   $at, %hi(dword_CODE_bss_80079C28)
  bne   $v0, $t7, .L7F005AE8
   nop   
  lw    $t0, 4($s0)
  lui   $v0, %hi(dword_CODE_bss_80079C68)
  lw    $v0, %lo(dword_CODE_bss_80079C68)($v0)
  sll   $t1, $t0, 2
  subu  $t1, $t1, $t0
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  sll   $t1, $t1, 2
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  sll   $t4, $v0, 2
  addu  $at, $at, $t4
  addu  $t3, $t1, $t2
  sw    $t3, %lo(dword_CODE_bss_80079C28)($at)
  lui   $at, %hi(dword_CODE_bss_80079C68)
  addiu $t5, $v0, 1
  sw    $t5, %lo(dword_CODE_bss_80079C68)($at)
.L7F005AE8:
  b     .L7F005DE4
   addiu $s0, $s0, 0xc
weapon:
  jal   check_ramrom_flags
   nop   
  lw    $t9, 0xc($s0)
  bne   $v0, $t9, .L7F005B70
   nop   
  jal   set_weapon_model_generated_thrown_object
   lw    $a0, 4($s0)
  lw    $a0, 8($s0)
  bltz  $a0, .L7F005B34
   nop   
  jal   set_weapon_model_generated_thrown_object
   nop   
  lw    $a0, 4($s0)
  jal   add_doubles_item_to_inventory
   lw    $a1, 8($s0)
  b     .L7F005B40
   lw    $t8, 0x7c($sp)
.L7F005B34:
  jal   add_item_to_inventory
   lw    $a0, 4($s0)
  lw    $t8, 0x7c($sp)
.L7F005B40:
  bnez  $t8, .L7F005B70
   nop   
  lw    $t6, 4($s0)
  lui   $at, %hi(starting_right_weapon)
  li    $t7, 1
  sw    $t6, %lo(starting_right_weapon)($at)
  lw    $a0, 8($s0)
  sw    $t7, 0x7c($sp)
  lui   $at, %hi(starting_left_weapon)
  bltz  $a0, .L7F005B70
   nop   
  sw    $a0, %lo(starting_left_weapon)($at)
.L7F005B70:
  b     .L7F005DE4
   addiu $s0, $s0, 0x10
ammo:
  jal   check_ramrom_flags
   nop   
  lw    $t0, 0xc($s0)
  bne   $v0, $t0, .L7F005B98
   nop   
  lw    $a0, 4($s0)
  jal   give_cur_player_ammo
   lw    $a1, 8($s0)
.L7F005B98:
  b     .L7F005DE4
   addiu $s0, $s0, 0x10
swirling_intro_cam:
  lui   $t1, %hi(D_800364AC) 
  lw    $t1, %lo(D_800364AC)($t1)
  move  $v0, $s0
  lui   $at, %hi(D_800364AC)
  bnezl $t1, .L7F005BC0
   lw    $t2, 8($v0)
  sw    $s0, %lo(D_800364AC)($at)
  lw    $t2, 8($v0)
.L7F005BC0:
  lw    $t3, 0xc($v0)
  lw    $t4, 0x10($v0)
  mtc1  $t2, $f18
  mtc1  $t3, $f8
  lw    $t5, 0x14($v0)
  cvt.s.w $f4, $f18
  mtc1  $t4, $f18
  lw    $t9, 0x18($v0)
  addiu $s0, $s0, 0x20
  cvt.s.w $f10, $f8
  mtc1  $t5, $f8
  div.s $f6, $f4, $f20
  cvt.s.w $f4, $f18
  mtc1  $t9, $f18
  div.s $f16, $f10, $f20
  swc1  $f6, 8($v0)
  cvt.s.w $f10, $f8
  div.s $f6, $f4, $f20
  swc1  $f16, 0xc($v0)
  cvt.s.w $f4, $f18
  div.s $f16, $f10, $f20
  swc1  $f6, 0x10($v0)
  div.s $f6, $f4, $f20
  swc1  $f16, 0x14($v0)
  b     .L7F005DE4
   swc1  $f6, 0x18($v0)
intro_ani:
  lw    $t8, 4($s0)
  lui   $at, %hi(D_80036514)
  addiu $s0, $s0, 8
  b     .L7F005DE4
   sw    $t8, %lo(D_80036514)($at)
cuff_char:
  lw    $t6, 4($s0)
  lw    $t7, ($s2)
  addiu $s0, $s0, 8
  b     .L7F005DE4
   sw    $t6, 0x41c($t7)
fixed_cam:
  jal   get_cur_playernum
   nop   
  bnez  $v0, .L7F005D0C
   lui   $t0, %hi(D_800364B8) 
  lw    $t0, %lo(D_800364B8)($t0)
  lui   $t1, %hi(D_800364BC) 
  lui   $at, %hi(D_800364B8)
  sw    $t0, 0x24($s0)
  lw    $t1, %lo(D_800364BC)($t1)
  sw    $s0, %lo(D_800364B8)($at)
  lui   $at, %hi(D_800364BC)
  addiu $t2, $t1, 1
  sw    $t2, %lo(D_800364BC)($at)
  lw    $t3, 4($s0)
  lw    $t4, 8($s0)
  lw    $t5, 0xc($s0)
  mtc1  $t3, $f8
  mtc1  $t4, $f18
  lw    $t9, 0x10($s0)
  cvt.s.w $f10, $f8
  mtc1  $t5, $f8
  lw    $t8, 0x14($s0)
  lhu   $a0, 0x1e($s0)
  cvt.s.w $f4, $f18
  mtc1  $t9, $f18
  div.s $f16, $f10, $f22
  cvt.s.w $f10, $f8
  mtc1  $t8, $f8
  div.s $f6, $f4, $f22
  swc1  $f16, 4($s0)
  cvt.s.w $f4, $f18
  div.s $f16, $f10, $f22
  swc1  $f6, 8($s0)
  cvt.s.w $f10, $f8
  div.s $f6, $f4, $f20
  swc1  $f16, 0xc($s0)
  div.s $f16, $f10, $f20
  swc1  $f6, 0x10($s0)
  jal   get_textptr_for_textID
   swc1  $f16, 0x14($s0)
  lw    $v1, 0x20($s0)
  sw    $v0, 0x1c($s0)
  beqz  $v1, .L7F005D0C
   nop   
  jal   get_textptr_for_textID
   andi  $a0, $v1, 0xffff
  sw    $v0, 0x20($s0)
.L7F005D0C:
  b     .L7F005DE4
   addiu $s0, $s0, 0x28
watch_time:
  sw    $zero, ($s1)
  lw    $a0, 8($s0)
  li    $at, 60
  blezl $a0, .L7F005D50
   lw    $v0, 4($s0)
  div   $zero, $a0, $at
  mfhi  $t7
  sll   $t0, $t7, 3
  subu  $t0, $t0, $t7
  sll   $t0, $t0, 5
  addu  $t0, $t0, $t7
  sll   $t0, $t0, 4
  lui   $at, %hi(watch_time_0)
  sw    $t0, %lo(watch_time_0)($at)
  lw    $v0, 4($s0)
.L7F005D50:
  li    $at, 12
  blez  $v0, .L7F005D84
   nop   
  div   $zero, $v0, $at
  mfhi  $t3
  lui   $at, (0x00034BC0 >> 16) # lui $at, 3
  ori   $at, (0x00034BC0 & 0xFFFF) # ori $at, $at, 0x4bc0
  multu $t3, $at
  lw    $t2, ($s1)
  lui   $at, %hi(watch_time_0)
  mflo  $t4
  addu  $t5, $t2, $t4
  sw    $t5, %lo(watch_time_0)($at)
.L7F005D84:
  b     .L7F005DE4
   addiu $s0, $s0, 0xc
credits:
  lui   $t9, %hi(dword_CODE_bss_80075D28) 
  lw    $t9, %lo(dword_CODE_bss_80075D28)($t9)
  lw    $t8, 4($s0)
  lui   $at, %hi(D_80036440)
  addu  $v0, $t9, $t8
  sw    $v0, %lo(D_80036440)($at)
  lhu   $t7, ($v0)
  bnezl $t7, .L7F005DC0
   lhu   $t0, 0xc($v0)
  lhu   $t6, 2($v0)
  beqz  $t6, .L7F005DD8
   nop   
  lhu   $t0, 0xc($v0)
.L7F005DC0:
  addiu $v0, $v0, 0xc
  bnezl $t0, .L7F005DC0
   lhu   $t0, 0xc($v0)
  lhu   $t1, 2($v0)
  bnezl $t1, .L7F005DC0
   lhu   $t0, 0xc($v0)
.L7F005DD8:
  b     .L7F005DE4
   addiu $s0, $s0, 8
def_7F005A74:
.L7F005DE0:
  addiu $s0, $s0, 4
.L7F005DE4:
  lw    $v0, ($s0)
  li    $at, 9
  bnel  $v0, $at, .L7F005A60
   sltiu $at, $v0, 9
.L7F005DF4:
  lui   $v0, %hi(D_800364B8)
  lw    $v0, %lo(D_800364B8)($v0)
  lui   $s2, %hi(pPlayer)
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5f50
  beqz  $v0, .L7F005E50
   lui   $at, %hi(ptr_random06cam_entry)
  jal   get_random_value
   sw    $v0, %lo(ptr_random06cam_entry)($at)
  lui   $t3, %hi(D_800364BC) 
  lw    $t3, %lo(D_800364BC)($t3)
  divu  $zero, $v0, $t3
  mfhi  $v1
  bnez  $t3, .L7F005E30
   nop   
  break 7
.L7F005E30:
  blez  $v1, .L7F005E50
.L7F005E34:
   lui   $t2, %hi(ptr_random06cam_entry) 
  lw    $t2, %lo(ptr_random06cam_entry)($t2)
  addiu $v1, $v1, -1
  lui   $at, %hi(ptr_random06cam_entry)
  lw    $t4, 0x24($t2)
  bgtz  $v1, .L7F005E34
   sw    $t4, %lo(ptr_random06cam_entry)($at)
.L7F005E50:
  jal   add_item_to_inventory
   li    $a0, 1
  lw    $t5, 0x7c($sp)
  mtc1  $zero, $f18
  bnez  $t5, .L7F005E70
   li    $t9, 1
  lui   $at, %hi(starting_right_weapon)
  sw    $t9, %lo(starting_right_weapon)($at)
.L7F005E70:
  lw    $t8, ($s2)
  lui   $at, %hi(D_8004F1D0)
  mtc1  $zero, $f6
  swc1  $f18, 0x78($t8)
  lw    $t7, ($s2)
  lwc1  $f4, %lo(D_8004F1D0)($at)
  lui   $t0, %hi(dword_CODE_bss_80079C68) 
  swc1  $f4, 0x7c($t7)
  lw    $t6, ($s2)
  swc1  $f6, 0x80($t6)
  lw    $t0, %lo(dword_CODE_bss_80079C68)($t0)
  blezl $t0, .L7F005F50
   addiu $a0, $sp, 0x8c
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F005ED4
   lui   $t1, %hi(dword_CODE_bss_80079C68) 
  lw    $t1, %lo(dword_CODE_bss_80079C68)($t1)
  blezl $t1, .L7F005ED8
   move  $v1, $zero
  jal   sub_GAME_7F0790F0
   nop   
  b     .L7F005ED8
   move  $v1, $v0
.L7F005ED4:
  move  $v1, $zero
.L7F005ED8:
  lui   $t2, %hi(dword_CODE_bss_80079C28) 
  addiu $t2, %lo(dword_CODE_bss_80079C28) # addiu $t2, $t2, -0x63d8
  sll   $t3, $v1, 2
  addu  $s1, $t3, $t2
  lw    $s0, ($s1)
  lwc1  $f8, ($s0)
  swc1  $f8, 0x8c($sp)
  lwc1  $f10, 8($s0)
  lw    $a1, 0x8c($sp)
  swc1  $f10, 0x94($sp)
  lw    $a0, 0x28($s0)
  lw    $a2, 0x94($sp)
  jal   sub_GAME_7F080D60
   sw    $a0, 0x84($sp)
  lw    $v0, ($s2)
  mov.s $f20, $f0
  lwc1  $f16, 0x29bc($v0)
  add.s $f18, $f16, $f0
  swc1  $f18, 0x90($sp)
  swc1  $f0, 0x70($v0)
  lw    $s0, ($s1)
  lwc1  $f12, 0x18($s0)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x20($s0)
  lui   $at, %hi(D_8004F1D4)
  lwc1  $f4, %lo(D_8004F1D4)($at)
  sub.s $f6, $f4, $f0
  b     .L7F005F8C
   swc1  $f6, 0x88($sp)
  addiu $a0, $sp, 0x8c
.L7F005F50:
  addiu $a1, $sp, 0x90
  addiu $a2, $sp, 0x94
  jal   sub_GAME_7F0AFB78
   lui   $a3, 0x41f0
  sw    $v0, 0x84($sp)
  move  $a0, $v0
  lw    $a1, 0x8c($sp)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x94($sp)
  lw    $v0, ($s2)
  mov.s $f20, $f0
  lwc1  $f8, 0x29bc($v0)
  add.s $f10, $f8, $f0
  swc1  $f10, 0x90($sp)
  swc1  $f0, 0x70($v0)
.L7F005F8C:
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f18
  lwc1  $f16, 0x88($sp)
  lui   $at, %hi(D_8004F1D8)
  lwc1  $f6, %lo(D_8004F1D8)($at)
  mul.s $f4, $f16, $f18
  lw    $t4, ($s2)
  lui   $at, %hi(D_8004F1DC)
  addiu $a1, $sp, 0x8c
  div.s $f8, $f4, $f6
  swc1  $f8, 0x148($t4)
  lw    $t5, ($s2)
  swc1  $f20, 0x74($t5)
  lwc1  $f10, %lo(D_8004F1DC)($at)
  lw    $t9, ($s2)
  div.s $f16, $f20, $f10
  swc1  $f16, 0x6c($t9)
  lw    $a0, ($s2)
  lw    $a2, 0x84($sp)
  jal   change_player_pos_to_target
   addiu $a0, $a0, 0x488
  jal   sinf
   lwc1  $f12, 0x88($sp)
  lw    $t8, ($s2)
  neg.s $f18, $f0
  mtc1  $zero, $f4
  swc1  $f18, 0x498($t8)
  lw    $t7, ($s2)
  swc1  $f4, 0x49c($t7)
  jal   cosf
   lwc1  $f12, 0x88($sp)
  lw    $t6, ($s2)
  lui   $at, %hi(D_800364D0)
  swc1  $f0, 0x4a0($t6)
  jal   sub_GAME_7F089718
   lwc1  $f12, %lo(D_800364D0)($at)
  lui   $at, %hi(dword_CODE_bss_80079DA0)
  sw    $zero, %lo(dword_CODE_bss_80079DA0)($at)
  lui   $at, %hi(dword_CODE_bss_80079DA4)
  lui   $v0, %hi(dword_CODE_bss_80079DA8)
  lui   $v1, %hi(dword_CODE_bss_80079DC8)
  addiu $v1, %lo(dword_CODE_bss_80079DC8) # addiu $v1, $v1, -0x6238
  addiu $v0, %lo(dword_CODE_bss_80079DA8) # addiu $v0, $v0, -0x6258
  sw    $zero, %lo(dword_CODE_bss_80079DA4)($at)
.L7F00603C:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F00603C
   sw    $zero, -0x10($v0)
  jal   reset_intro_camera_message_dialogs_for_BONDdata
   nop   
  jal   sub_GAME_7F08A900
   nop   
  jal   remove_last_obj_pos_data_entry
   nop   
  lw    $t0, ($s2)
  li    $t2, 6
  sw    $v0, 0xa8($t0)
  lw    $t1, ($s2)
  lw    $t3, 0xa8($t1)
  sw    $zero, 4($t3)
  lw    $t4, ($s2)
  lw    $t5, 0xa8($t4)
  sb    $t2, ($t5)
  lw    $t9, ($s2)
  lwc1  $f0, 0x8c($sp)
  swc1  $f0, 0x408($t9)
  lw    $t8, ($s2)
  lw    $t7, 0xa8($t8)
  swc1  $f0, 8($t7)
  lw    $t6, ($s2)
  lwc1  $f0, 0x90($sp)
  swc1  $f0, 0x40c($t6)
  lw    $t0, ($s2)
  lw    $t1, 0xa8($t0)
  swc1  $f0, 0xc($t1)
  lw    $t3, ($s2)
  lwc1  $f0, 0x94($sp)
  swc1  $f0, 0x410($t3)
  lw    $t4, ($s2)
  lw    $t2, 0xa8($t4)
  swc1  $f0, 0x10($t2)
  lw    $t9, ($s2)
  lw    $t5, 0x84($sp)
  lw    $t8, 0xa8($t9)
  sw    $t5, 0x14($t8)
  lw    $t7, ($s2)
  jal   set_current_objposdata_plus_0x28
   lw    $a0, 0xa8($t7)
  lw    $t6, ($s2)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0xa8($t6)
  lw    $v0, ($s2)
  lui   $at, %hi(D_8004F1E0)
  lwc1  $f0, %lo(D_8004F1E0)($at)
  lwc1  $f6, 0x4b4($v0)
  div.s $f8, $f6, $f0
  swc1  $f8, 0x3b8($v0)
  lw    $v0, ($s2)
  lwc1  $f10, 0x4b8($v0)
  div.s $f16, $f10, $f0
  swc1  $f16, 0x3bc($v0)
  lw    $v0, ($s2)
  lwc1  $f18, 0x4bc($v0)
  div.s $f4, $f18, $f0
  jal   getPlayerCount
   swc1  $f4, 0x3c0($v0)
  li    $at, 1
  bne   $v0, $at, .L7F006158
   nop   
  jal   set_camera_mode
   li    $a0, 1
  b     .L7F006160
   nop   
.L7F006158:
  jal   set_camera_mode
   li    $a0, 9
.L7F006160:
  lui   $a0, %hi(D_800364D8)
  addiu $a0, %lo(D_800364D8) # addiu $a0, $a0, 0x64d8
  sll   $t0, $zero, 2
  addu  $t1, $a0, $t0
  lw    $t3, ($t1)
  lui   $v1, %hi(D_8003650C)
  addiu $v1, %lo(D_8003650C) # addiu $v1, $v1, 0x650c
  sw    $zero, ($v1)
  beqz  $t3, .L7F0061A8
   move  $v0, $zero
  addiu $t4, $v0, 1
.L7F00618C:
  sll   $t2, $t4, 2
  addu  $t9, $a0, $t2
  lw    $t5, ($t9)
  sw    $t4, ($v1)
  move  $v0, $t4
  bnezl $t5, .L7F00618C
   addiu $t4, $v0, 1
.L7F0061A8:
  lw    $t7, ($s2)
  li    $t8, 1
  lui   $at, %hi(D_80036510)
  sw    $t8, 0x420($t7)
  lw    $t6, ($s2)
  sw    $zero, 0x424($t6)
  lw    $t0, ($s2)
  sw    $zero, 0x428($t0)
  lw    $ra, 0x34($sp)
  lw    $s2, 0x30($sp)
  lw    $s1, 0x2c($sp)
  lw    $s0, 0x28($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  sw    $zero, %lo(D_80036510)($at)
  jr    $ra
   addiu $sp, $sp, 0x98
");
#endif

#ifdef VERSION_JP
asm(R"
.late_rodata
glabel projectile_ptr_table
.word throwingknife
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word grenade_launch_round
.word rocket
.word grenade
.word timed_mine
.word prox_mine
.word remote_mine
.word default
.word default
.word rocket_0
.word bombcase
.word plastique
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word default
.word bug
.word microcamera


/*8004f1a8*/
glabel default_zoom_speed
.word 0x3f68ba2e

glabel jpt_8004F1AC
    .word spawn_point
    .word weapon
    .word ammo
    .word swirling_intro_cam
    .word intro_ani
    .word cuff_char
    .word fixed_cam
    .word watch_time
    .word credits

glabel D_8004F1D0
.word 0xb8d1b717
glabel D_8004F1D4
.word 0x40c90fdb
glabel D_8004F1D8
.word 0x40c90fdb
glabel D_8004F1DC
.word 0x3e2e147c
glabel D_8004F1E0
.word 0x3dccccd0
.text
glabel load_camera_intro_type_values
  addiu $sp, $sp, -0xa0
  lui   $t7, %hi(D_8002A780) # $t7, 0x8003
  sw    $ra, 0x3c($sp)
  sw    $s2, 0x38($sp)
  sw    $s1, 0x34($sp)
  sw    $s0, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  addiu $t7, %lo(D_8002A780) # addiu $t7, $t7, -0x5840
  lw    $at, ($t7)
  addiu $t6, $sp, 0x94
  lw    $t0, 4($t7)
  sw    $at, ($t6)
  lw    $at, 8($t7)
  sw    $t0, 4($t6)
  lui   $s1, %hi(resolution) # $s1, 0x8003
  sw    $at, 8($t6)
  lui   $at, %hi(mission_kia_flag) # $at, 0x8003
  sw    $zero, %lo(mission_kia_flag)($at)
  lui   $at, %hi(camera_80036424) # $at, 0x8003
  lui   $s0, %hi(ptr_setup_intro) # $s0, 0x8007
  sw    $zero, %lo(camera_80036424)($at)
  addiu $s1, %lo(resolution) # addiu $s1, $s1, 0x6468
  lw    $s0, %lo(ptr_setup_intro)($s0)
  sw    $zero, ($s1)
  lui   $at, %hi(camera_8003642C) # $at, 0x8003
  lui   $s2, %hi(camera_80036430) # $s2, 0x8003
  sw    $zero, %lo(camera_8003642C)($at)
  mtc1  $zero, $f24
  addiu $s2, %lo(camera_80036430) # addiu $s2, $s2, 0x6470
  sw    $zero, ($s2)
  lui   $at, %hi(camera_80036434) # $at, 0x8003
  sw    $zero, 0x84($sp)
  sw    $zero, %lo(camera_80036434)($at)
  jal   get_stage_num
   swc1  $f24, 0x90($sp)
  li    $at, 54
  bne   $v0, $at, .L7F0058AC
   lui   $a0, (0x00046EA0 >> 16) # lui $a0, 4
  ori   $a0, (0x00046EA0 & 0xFFFF) # ori $a0, $a0, 0x6ea0
  jal   mempAllocBytesInBank
   li    $a1, 4
  addiu $t2, $v0, 0x3f
  li    $at, -64
  sw    $v0, ($s1)
  and   $t3, $t2, $at
  li    $t4, 1
  sw    $t3, ($s1)
  sw    $t4, ($s2)
.L7F0058AC:
  lui   $at, %hi(camera_80036438) # $at, 0x8003
  sw    $zero, %lo(camera_80036438)($at)
  lui   $at, %hi(D_8003643C) # $at, 0x8003
  sw    $zero, %lo(D_8003643C)($at)
  lui   $at, %hi(D_80036440) # $at, 0x8003
  lui   $v0, %hi(flt_CODE_bss_80079990) # $v0, 0x8008
  sw    $zero, %lo(D_80036440)($at)
  addiu $v0, %lo(flt_CODE_bss_80079990) # addiu $v0, $v0, -0x6630
  swc1  $f24, ($v0)
  swc1  $f24, 4($v0)
  swc1  $f24, 8($v0)
  lui   $at, %hi(D_80036444) # $at, 0x8003
  sw    $zero, %lo(D_80036444)($at)
  lui   $at, %hi(dword_CODE_bss_80079C68) # $at, 0x8008
  sw    $zero, %lo(dword_CODE_bss_80079C68)($at)
  lui   $at, %hi(in_tank_flag) # $at, 0x8003
  sw    $zero, %lo(in_tank_flag)($at)
  lui   $at, %hi(D_8003644C) # $at, 0x8003
  sw    $zero, %lo(D_8003644C)($at)
  lui   $at, %hi(ptr_playerstank) # $at, 0x8003
  sw    $zero, %lo(ptr_playerstank)($at)
  lui   $at, %hi(D_80036454) # $at, 0x8003
  lui   $v1, %hi(SFX_80036458) # $v1, 0x8003
  swc1  $f24, %lo(D_80036454)($at)
  addiu $v1, %lo(SFX_80036458) # addiu $v1, $v1, 0x6498
  sw    $zero, ($v1)
  sw    $zero, 4($v1)
  lui   $at, %hi(D_80036460) # $at, 0x8003
  swc1  $f24, %lo(D_80036460)($at)
  lui   $at, %hi(D_80036464) # $at, 0x8003
  swc1  $f24, %lo(D_80036464)($at)
  lui   $at, %hi(D_80036468) # $at, 0x8003
  swc1  $f24, %lo(D_80036468)($at)
  lui   $at, %hi(D_8003646C) # $at, 0x8003
  swc1  $f24, %lo(D_8003646C)($at)
  lui   $at, %hi(D_80036470) # $at, 0x8003
  swc1  $f24, %lo(D_80036470)($at)
  lui   $at, %hi(D_80036474) # $at, 0x8003
  swc1  $f24, %lo(D_80036474)($at)
  lui   $at, %hi(D_80036478) # $at, 0x8003
  swc1  $f24, %lo(D_80036478)($at)
  lui   $at, %hi(D_8003647C) # $at, 0x8003
  swc1  $f24, %lo(D_8003647C)($at)
  lui   $at, %hi(D_80036480) # $at, 0x8003
  sw    $zero, %lo(D_80036480)($at)
  lui   $at, %hi(D_80036484) # $at, 0x8003
  swc1  $f24, %lo(D_80036484)($at)
  lui   $at, %hi(D_80036488) # $at, 0x8003
  swc1  $f24, %lo(D_80036488)($at)
  lui   $at, %hi(D_8003648C) # $at, 0x8003
  sw    $zero, %lo(D_8003648C)($at)
  lui   $at, %hi(D_800364B0) # $at, 0x8003
  li    $t5, 1
  sw    $t5, %lo(D_800364B0)($at)
  lui   $at, %hi(disable_player_pickups_flag) # $at, 0x8003
  sw    $zero, %lo(disable_player_pickups_flag)($at)
  lui   $at, %hi(cameramode) # $at, 0x8003
  sw    $zero, %lo(cameramode)($at)
  lui   $at, %hi(enable_move_after_cinema) # $at, 0x8003
  sw    $zero, %lo(enable_move_after_cinema)($at)
  lui   $at, %hi(D_8003649C) # $at, 0x8003
  sw    $zero, %lo(D_8003649C)($at)
  lui   $at, %hi(stop_time_flag) # $at, 0x8003
  sw    $zero, %lo(stop_time_flag)($at)
  lui   $at, %hi(D_800364A4) # $at, 0x8003
  swc1  $f24, %lo(D_800364A4)($at)
  lui   $at, %hi(D_800364A8) # $at, 0x8003
  li    $t9, 1
  sw    $t9, %lo(D_800364A8)($at)
  lui   $at, %hi(D_800364AC) # $at, 0x8003
  sw    $zero, %lo(D_800364AC)($at)
  lui   $at, %hi(ptr_random06cam_entry) # $at, 0x8003
  sw    $zero, %lo(ptr_random06cam_entry)($at)
  lui   $at, %hi(D_800364B8) # $at, 0x8003
  sw    $zero, %lo(D_800364B8)($at)
  lui   $at, %hi(D_800364BC) # $at, 0x8003
  sw    $zero, %lo(D_800364BC)($at)
  lui   $at, %hi(mission_timer) # $at, 0x8008
  lui   $s1, %hi(watch_time_0) # $s1, 0x8008
  sw    $zero, %lo(mission_timer)($at)
  addiu $s1, %lo(watch_time_0) # addiu $s1, $s1, -0x659c
  swc1  $f24, ($s1)
  lui   $at, %hi(D_80036514) # $at, 0x8003
  sw    $zero, %lo(D_80036514)($at)
  lui   $at, %hi(default_zoom_speed) # $at, 0x8005
  lwc1  $f4, %lo(default_zoom_speed)($at)
  lui   $at, %hi(watch_transition_time) # $at, 0x8003
  swc1  $f4, %lo(watch_transition_time)($at)
  lui   $at, %hi(starting_left_weapon) # $at, 0x8008
  sw    $zero, %lo(starting_left_weapon)($at)
  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
  beqz  $s0, .L7F005DF8
   sw    $zero, %lo(starting_right_weapon)($at)
  lw    $v0, ($s0)
  li    $at, 9
  lui   $s2, %hi(pPlayer) # $s2, 0x8008
  beq   $v0, $at, .L7F005DF8
   li    $at, 0x42C80000 # 100.000000
  mtc1  $at, $f22
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f20
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5ee0
  sltiu $at, $v0, 9
.L7F005A48:
  beqz  $at, .L7F005DE4
   sll   $t8, $v0, 2
  lui   $at, %hi(jpt_8004F1AC)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8004F1AC)($at)
  jr    $t8
   nop   
spawn_point:
  lui   $t6, %hi(ptr_0xxxpresets) # $t6, 0x8007
  lw    $t6, %lo(ptr_0xxxpresets)($t6)
  beqz  $t6, .L7F005AD0
   nop   
  jal   check_ramrom_flags
   nop   
  lw    $t7, 8($s0)
  lui   $t2, %hi(ptr_0xxxpresets) # $t2, 0x8007
  lui   $at, %hi(dword_CODE_bss_80079C28)
  bne   $v0, $t7, .L7F005AD0
   nop   
  lw    $t0, 4($s0)
  lui   $v0, %hi(dword_CODE_bss_80079C68) # $v0, 0x8008
  lw    $v0, %lo(dword_CODE_bss_80079C68)($v0)
  sll   $t1, $t0, 2
  subu  $t1, $t1, $t0
  lw    $t2, %lo(ptr_0xxxpresets)($t2)
  sll   $t1, $t1, 2
  subu  $t1, $t1, $t0
  sll   $t1, $t1, 2
  sll   $t4, $v0, 2
  addu  $at, $at, $t4
  addu  $t3, $t1, $t2
  sw    $t3, %lo(dword_CODE_bss_80079C28)($at)
  lui   $at, %hi(dword_CODE_bss_80079C68) # $at, 0x8008
  addiu $t5, $v0, 1
  sw    $t5, %lo(dword_CODE_bss_80079C68)($at)
.L7F005AD0:
  b     .L7F005DE8
   addiu $s0, $s0, 0xc
weapon:
  jal   check_ramrom_flags
   nop   
  lw    $t9, 0xc($s0)
  bne   $v0, $t9, .L7F005B58
   nop   
  jal   set_weapon_model_generated_thrown_object
   lw    $a0, 4($s0)
  lw    $a0, 8($s0)
  bltz  $a0, .L7F005B1C
   nop   
  jal   set_weapon_model_generated_thrown_object
   nop   
  lw    $a0, 4($s0)
  jal   add_doubles_item_to_inventory
   lw    $a1, 8($s0)
  b     .L7F005B28
   lw    $t8, 0x84($sp)
.L7F005B1C:
  jal   add_item_to_inventory
   lw    $a0, 4($s0)
  lw    $t8, 0x84($sp)
.L7F005B28:
  bnez  $t8, .L7F005B58
   nop   
  lw    $t6, 4($s0)
  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
  li    $t7, 1
  sw    $t6, %lo(starting_right_weapon)($at)
  lw    $a0, 8($s0)
  sw    $t7, 0x84($sp)
  lui   $at, %hi(starting_left_weapon) # $at, 0x8008
  bltz  $a0, .L7F005B58
   nop   
  sw    $a0, %lo(starting_left_weapon)($at)
.L7F005B58:
  b     .L7F005DE8
   addiu $s0, $s0, 0x10
ammo:
  jal   check_ramrom_flags
   nop   
  lw    $t0, 0xc($s0)
  bne   $v0, $t0, .L7F005B80
   nop   
  lw    $a0, 4($s0)
  jal   give_cur_player_ammo
   lw    $a1, 8($s0)
.L7F005B80:
  b     .L7F005DE8
   addiu $s0, $s0, 0x10
swirling_intro_cam:
  lui   $t1, %hi(D_800364AC) # $t1, 0x8003
  lw    $t1, %lo(D_800364AC)($t1)
  move  $v0, $s0
  lui   $at, %hi(D_800364AC) # $at, 0x8003
  bnezl $t1, .L7F005BA8
   lw    $t2, 8($v0)
  sw    $s0, %lo(D_800364AC)($at)
  lw    $t2, 8($v0)
.L7F005BA8:
  lw    $t3, 0xc($v0)
  lw    $t4, 0x10($v0)
  mtc1  $t2, $f6
  mtc1  $t3, $f16
  lw    $t5, 0x14($v0)
  cvt.s.w $f8, $f6
  mtc1  $t4, $f6
  lw    $t9, 0x18($v0)
  addiu $s0, $s0, 0x20
  cvt.s.w $f18, $f16
  mtc1  $t5, $f16
  div.s $f10, $f8, $f20
  cvt.s.w $f8, $f6
  mtc1  $t9, $f6
  div.s $f4, $f18, $f20
  swc1  $f10, 8($v0)
  cvt.s.w $f18, $f16
  div.s $f10, $f8, $f20
  swc1  $f4, 0xc($v0)
  cvt.s.w $f8, $f6
  div.s $f4, $f18, $f20
  swc1  $f10, 0x10($v0)
  div.s $f10, $f8, $f20
  swc1  $f4, 0x14($v0)
  b     .L7F005DE8
   swc1  $f10, 0x18($v0)
intro_ani:
  lw    $t8, 4($s0)
  lui   $at, %hi(D_80036514) # $at, 0x8003
  addiu $s0, $s0, 8
  b     .L7F005DE8
   sw    $t8, %lo(D_80036514)($at)
cuff_char:
  lw    $t6, 4($s0)
  lw    $t7, ($s2)
  addiu $s0, $s0, 8
  b     .L7F005DE8
   sw    $t6, 0x41c($t7)
fixed_cam:
  jal   get_cur_playernum
   nop   
  bnez  $v0, .L7F005CF4
   lui   $t0, %hi(D_800364B8) # $t0, 0x8003
  lw    $t0, %lo(D_800364B8)($t0)
  lui   $t1, %hi(D_800364BC) # $t1, 0x8003
  lui   $at, %hi(D_800364B8) # $at, 0x8003
  sw    $t0, 0x24($s0)
  lw    $t1, %lo(D_800364BC)($t1)
  sw    $s0, %lo(D_800364B8)($at)
  lui   $at, %hi(D_800364BC) # $at, 0x8003
  addiu $t2, $t1, 1
  sw    $t2, %lo(D_800364BC)($at)
  lw    $t3, 4($s0)
  lw    $t4, 8($s0)
  lw    $t5, 0xc($s0)
  mtc1  $t3, $f16
  mtc1  $t4, $f6
  lw    $t9, 0x10($s0)
  cvt.s.w $f18, $f16
  mtc1  $t5, $f16
  lw    $t8, 0x14($s0)
  lhu   $a0, 0x1e($s0)
  cvt.s.w $f8, $f6
  mtc1  $t9, $f6
  div.s $f4, $f18, $f22
  cvt.s.w $f18, $f16
  mtc1  $t8, $f16
  div.s $f10, $f8, $f22
  swc1  $f4, 4($s0)
  cvt.s.w $f8, $f6
  div.s $f4, $f18, $f22
  swc1  $f10, 8($s0)
  cvt.s.w $f18, $f16
  div.s $f10, $f8, $f20
  swc1  $f4, 0xc($s0)
  div.s $f4, $f18, $f20
  swc1  $f10, 0x10($s0)
  jal   get_textptr_for_textID
   swc1  $f4, 0x14($s0)
  lw    $v1, 0x20($s0)
  sw    $v0, 0x1c($s0)
  beqz  $v1, .L7F005CF4
   nop   
  jal   get_textptr_for_textID
   andi  $a0, $v1, 0xffff
  sw    $v0, 0x20($s0)
.L7F005CF4:
  b     .L7F005DE8
   addiu $s0, $s0, 0x28
watch_time:
  swc1  $f24, ($s1)
  lw    $a0, 8($s0)
  li    $at, 60
  blezl $a0, .L7F005D48
   lw    $v0, 4($s0)
  div   $zero, $a0, $at
  mfhi  $t6
  sll   $t7, $t6, 3
  subu  $t7, $t7, $t6
  sll   $t7, $t7, 5
  addu  $t7, $t7, $t6
  sll   $t7, $t7, 4
  mtc1  $t7, $f8
  lwc1  $f6, ($s1)
  lui   $at, %hi(watch_time_0) # $at, 0x8008
  cvt.s.w $f10, $f8
  add.s $f16, $f6, $f10
  swc1  $f16, %lo(watch_time_0)($at)
  lw    $v0, 4($s0)
.L7F005D48:
  li    $at, 12
  blez  $v0, .L7F005D88
   nop   
  div   $zero, $v0, $at
  mfhi  $t0
  lui   $at, (0x00034BC0 >> 16) # lui $at, 3
  ori   $at, (0x00034BC0 & 0xFFFF) # ori $at, $at, 0x4bc0
  multu $t0, $at
  lwc1  $f18, ($s1)
  lui   $at, %hi(watch_time_0) # $at, 0x8008
  mflo  $t1
  mtc1  $t1, $f4
  nop   
  cvt.s.w $f8, $f4
  add.s $f6, $f18, $f8
  swc1  $f6, %lo(watch_time_0)($at)
.L7F005D88:
  b     .L7F005DE8
   addiu $s0, $s0, 0xc
credits:
  lui   $t2, %hi(dword_CODE_bss_80075D28) # $t2, 0x8007
  lw    $t2, %lo(dword_CODE_bss_80075D28)($t2)
  lw    $t3, 4($s0)
  lui   $at, %hi(D_80036440) # $at, 0x8003
  addu  $v0, $t2, $t3
  sw    $v0, %lo(D_80036440)($at)
  lhu   $t4, ($v0)
  bnezl $t4, .L7F005DC4
   lhu   $t9, 0xc($v0)
  lhu   $t5, 2($v0)
  beqz  $t5, .L7F005DDC
   nop   
  lhu   $t9, 0xc($v0)
.L7F005DC4:
  addiu $v0, $v0, 0xc
  bnezl $t9, .L7F005DC4
   lhu   $t9, 0xc($v0)
  lhu   $t8, 2($v0)
  bnezl $t8, .L7F005DC4
   lhu   $t9, 0xc($v0)
.L7F005DDC:
  b     .L7F005DE8
   addiu $s0, $s0, 8
def_7F005A74:
.L7F005DE4:
  addiu $s0, $s0, 4
.L7F005DE8:
  lw    $v0, ($s0)
  li    $at, 9
  bnel  $v0, $at, .L7F005A48
   sltiu $at, $v0, 9
.L7F005DF8:
  lui   $v0, %hi(D_800364B8) # $v0, 0x8003
  lw    $v0, %lo(D_800364B8)($v0)
  lui   $s2, %hi(pPlayer) # $s2, 0x8008
  addiu $s2, %lo(pPlayer) # addiu $s2, $s2, -0x5ee0
  beqz  $v0, .L7F005E54
   lui   $at, %hi(ptr_random06cam_entry) # $at, 0x8003
  jal   get_random_value
   sw    $v0, %lo(ptr_random06cam_entry)($at)
  lui   $t6, %hi(D_800364BC) # $t6, 0x8003
  lw    $t6, %lo(D_800364BC)($t6)
  divu  $zero, $v0, $t6
  mfhi  $v1
  bnez  $t6, .L7F005E34
   nop   
  break 7
.L7F005E34:
  blez  $v1, .L7F005E54
.L7F005E38:
   lui   $t7, %hi(ptr_random06cam_entry) # $t7, 0x8003
  lw    $t7, %lo(ptr_random06cam_entry)($t7)
  addiu $v1, $v1, -1
  lui   $at, %hi(ptr_random06cam_entry) # $at, 0x8003
  lw    $t0, 0x24($t7)
  bgtz  $v1, .L7F005E38
   sw    $t0, %lo(ptr_random06cam_entry)($at)
.L7F005E54:
  jal   add_item_to_inventory
   li    $a0, 1
  lw    $t1, 0x84($sp)
  bnez  $t1, .L7F005E70
   li    $t2, 1
  lui   $at, %hi(starting_right_weapon) # $at, 0x8008
  sw    $t2, %lo(starting_right_weapon)($at)
.L7F005E70:
  lw    $t3, ($s2)
  lui   $at, %hi(D_8004F1D0) # $at, 0x8005
  lui   $t9, %hi(dword_CODE_bss_80079C68) # $t9, 0x8008
  swc1  $f24, 0x78($t3)
  lw    $t4, ($s2)
  lwc1  $f10, %lo(D_8004F1D0)($at)
  swc1  $f10, 0x7c($t4)
  lw    $t5, ($s2)
  swc1  $f24, 0x80($t5)
  lw    $t9, %lo(dword_CODE_bss_80079C68)($t9)
  blezl $t9, .L7F005F4C
   addiu $a0, $sp, 0x94
  jal   getPlayerCount
   nop   
  slti  $at, $v0, 2
  bnez  $at, .L7F005ED0
   lui   $t8, %hi(dword_CODE_bss_80079C68) # $t8, 0x8008
  lw    $t8, %lo(dword_CODE_bss_80079C68)($t8)
  blezl $t8, .L7F005ED4
   move  $v1, $zero
  jal   sub_GAME_7F0790F0
   nop   
  b     .L7F005ED4
   move  $v1, $v0
.L7F005ED0:
  move  $v1, $zero
.L7F005ED4:
  lui   $t7, %hi(dword_CODE_bss_80079C28) # $t7, 0x8008
  addiu $t7, %lo(dword_CODE_bss_80079C28) # addiu $t7, $t7, -0x6368
  sll   $t6, $v1, 2
  addu  $s1, $t6, $t7
  lw    $s0, ($s1)
  lwc1  $f16, ($s0)
  swc1  $f16, 0x94($sp)
  lwc1  $f4, 8($s0)
  lw    $a1, 0x94($sp)
  swc1  $f4, 0x9c($sp)
  lw    $a0, 0x28($s0)
  lw    $a2, 0x9c($sp)
  jal   sub_GAME_7F080D60
   sw    $a0, 0x8c($sp)
  lw    $v0, ($s2)
  mov.s $f20, $f0
  lwc1  $f18, 0x29bc($v0)
  add.s $f8, $f18, $f0
  swc1  $f8, 0x98($sp)
  swc1  $f0, 0x70($v0)
  lw    $s0, ($s1)
  lwc1  $f12, 0x18($s0)
  jal   convert_angle_using_inverse
   lwc1  $f14, 0x20($s0)
  lui   $at, %hi(D_8004F1D4) # $at, 0x8005
  lwc1  $f6, %lo(D_8004F1D4)($at)
  sub.s $f10, $f6, $f0
  b     .L7F005F88
   swc1  $f10, 0x90($sp)
  addiu $a0, $sp, 0x94
.L7F005F4C:
  addiu $a1, $sp, 0x98
  addiu $a2, $sp, 0x9c
  jal   sub_GAME_7F0AFB78
   lui   $a3, 0x41f0
  sw    $v0, 0x8c($sp)
  move  $a0, $v0
  lw    $a1, 0x94($sp)
  jal   sub_GAME_7F080D60
   lw    $a2, 0x9c($sp)
  lw    $v0, ($s2)
  mov.s $f20, $f0
  lwc1  $f16, 0x29bc($v0)
  add.s $f4, $f16, $f0
  swc1  $f4, 0x98($sp)
  swc1  $f0, 0x70($v0)
.L7F005F88:
  li    $at, 0x43B40000 # 360.000000
  mtc1  $at, $f8
  lwc1  $f18, 0x90($sp)
  lui   $at, %hi(D_8004F1D8) # $at, 0x8005
  lwc1  $f10, %lo(D_8004F1D8)($at)
  mul.s $f6, $f18, $f8
  lw    $t0, ($s2)
  lui   $at, %hi(D_8004F1DC) # $at, 0x8005
  addiu $a1, $sp, 0x94
  div.s $f16, $f6, $f10
  swc1  $f16, 0x148($t0)
  lw    $t1, ($s2)
  swc1  $f20, 0x74($t1)
  lwc1  $f4, %lo(D_8004F1DC)($at)
  lw    $t2, ($s2)
  div.s $f18, $f20, $f4
  swc1  $f18, 0x6c($t2)
  lw    $a0, ($s2)
  lw    $a2, 0x8c($sp)
  jal   change_player_pos_to_target
   addiu $a0, $a0, 0x488
  jal   sinf
   lwc1  $f12, 0x90($sp)
  lw    $t3, ($s2)
  neg.s $f8, $f0
  swc1  $f8, 0x498($t3)
  lw    $t4, ($s2)
  swc1  $f24, 0x49c($t4)
  jal   cosf
   lwc1  $f12, 0x90($sp)
  lw    $t5, ($s2)
  lui   $at, %hi(D_800364D0) # $at, 0x8003
  swc1  $f0, 0x4a0($t5)
  jal   sub_GAME_7F089718
   lwc1  $f12, %lo(D_800364D0)($at)
  lui   $at, %hi(dword_CODE_bss_80079DA0) # $at, 0x8008
  sw    $zero, %lo(dword_CODE_bss_80079DA0)($at)
  lui   $at, %hi(dword_CODE_bss_80079DA4) # $at, 0x8008
  lui   $v0, %hi(dword_CODE_bss_80079DA8) # $v0, 0x8008
  lui   $v1, %hi(dword_CODE_bss_80079DC8) # $v1, 0x8008
  addiu $v1, %lo(dword_CODE_bss_80079DC8) # addiu $v1, $v1, -0x61c8
  addiu $v0, %lo(dword_CODE_bss_80079DA8) # addiu $v0, $v0, -0x61e8
  sw    $zero, %lo(dword_CODE_bss_80079DA4)($at)
.L7F006034:
  addiu $v0, $v0, 0x10
  sw    $zero, -0xc($v0)
  sw    $zero, -8($v0)
  sw    $zero, -4($v0)
  bne   $v0, $v1, .L7F006034
   sw    $zero, -0x10($v0)
  jal   reset_intro_camera_message_dialogs_for_BONDdata
   nop   
  jal   sub_GAME_7F08A900
   nop   
  jal   remove_last_obj_pos_data_entry
   nop   
  lw    $t9, ($s2)
  li    $t7, 6
  sw    $v0, 0xa8($t9)
  lw    $t8, ($s2)
  lw    $t6, 0xa8($t8)
  sw    $zero, 4($t6)
  lw    $t0, ($s2)
  lw    $t1, 0xa8($t0)
  sb    $t7, ($t1)
  lw    $t2, ($s2)
  lwc1  $f0, 0x94($sp)
  swc1  $f0, 0x408($t2)
  lw    $t3, ($s2)
  lw    $t4, 0xa8($t3)
  swc1  $f0, 8($t4)
  lw    $t5, ($s2)
  lwc1  $f0, 0x98($sp)
  swc1  $f0, 0x40c($t5)
  lw    $t9, ($s2)
  lw    $t8, 0xa8($t9)
  swc1  $f0, 0xc($t8)
  lw    $t6, ($s2)
  lwc1  $f0, 0x9c($sp)
  swc1  $f0, 0x410($t6)
  lw    $t0, ($s2)
  lw    $t7, 0xa8($t0)
  swc1  $f0, 0x10($t7)
  lw    $t2, ($s2)
  lw    $t1, 0x8c($sp)
  lw    $t3, 0xa8($t2)
  sw    $t1, 0x14($t3)
  lw    $t4, ($s2)
  jal   set_current_objposdata_plus_0x28
   lw    $a0, 0xa8($t4)
  lw    $t5, ($s2)
  jal   set_stateflag_0x04_for_posdata
   lw    $a0, 0xa8($t5)
  lw    $v0, ($s2)
  lui   $at, %hi(D_8004F1E0) # $at, 0x8005
  lwc1  $f0, %lo(D_8004F1E0)($at)
  lwc1  $f6, 0x4b4($v0)
  div.s $f10, $f6, $f0
  swc1  $f10, 0x3b8($v0)
  lw    $v0, ($s2)
  lwc1  $f16, 0x4b8($v0)
  div.s $f4, $f16, $f0
  swc1  $f4, 0x3bc($v0)
  lw    $v0, ($s2)
  lwc1  $f18, 0x4bc($v0)
  div.s $f8, $f18, $f0
  jal   getPlayerCount
   swc1  $f8, 0x3c0($v0)
  li    $at, 1
  bne   $v0, $at, .L7F006150
   nop   
  jal   set_camera_mode
   li    $a0, 1
  b     .L7F006158
   nop   
.L7F006150:
  jal   set_camera_mode
   li    $a0, 9
.L7F006158:
  lui   $a0, %hi(D_800364D8) # $a0, 0x8003
  addiu $a0, %lo(D_800364D8) # addiu $a0, $a0, 0x6518
  sll   $t9, $zero, 2
  addu  $t8, $a0, $t9
  lw    $t6, ($t8)
  lui   $v1, %hi(D_8003650C) # $v1, 0x8003
  addiu $v1, %lo(D_8003650C) # addiu $v1, $v1, 0x654c
  sw    $zero, ($v1)
  beqz  $t6, .L7F0061A0
   move  $v0, $zero
  addiu $t0, $v0, 1
.L7F006184:
  sll   $t7, $t0, 2
  addu  $t2, $a0, $t7
  lw    $t1, ($t2)
  sw    $t0, ($v1)
  move  $v0, $t0
  bnezl $t1, .L7F006184
   addiu $t0, $v0, 1
.L7F0061A0:
  lw    $t4, ($s2)
  li    $t3, 1
  lui   $at, %hi(D_80036510) # $at, 0x8003
  sw    $t3, 0x420($t4)
  lw    $t5, ($s2)
  sw    $zero, 0x424($t5)
  lw    $t9, ($s2)
  sw    $zero, 0x428($t9)
  lw    $ra, 0x3c($sp)
  lw    $s2, 0x38($sp)
  lw    $s1, 0x34($sp)
  lw    $s0, 0x30($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f20, 0x18($sp)
  sw    $zero, %lo(D_80036510)($at)
  jr    $ra
   addiu $sp, $sp, 0xa0

");
#endif
