char dword_CODE_bss_8008D370[0x400];
char dword_CODE_bss_8008D770[0xBA0];

int D_8004E9E0 = 0, D_8004E9E4 = 0, D_8004E9E8 = 0, D_8004E9EC = 0;

unsigned int fast3d_related_0[] = {
    0,     0, 0, 0, 1, 2, 0, 0, 0, 0x1000, 0, 0x800, dword_CODE_bss_8008D370,
    0x400, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0}; // make me a struct

unsigned int fast3d_related_1[] = {
    0,     0, 0, 0, 1, 2, 0, 0, 0, 0x1000, 0, 0x800, dword_CODE_bss_8008D370,
    0x400, 0, 0, 0, 0, 0, 0, 0, 0, 0,      0}; // im another instance of above
                                               // struct

unsigned int *fast3d_related_array = &fast3d_related_0;

void something_with_rsp_c_debug(void) {
  set_debug_notice_list_entry(&D_8004E9E0, "rsp_c_debug");
}

asm(R"
glabel initialize_rsp_buffers
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $a0, 40960
  jal   mempAllocBytesInBank
   li    $a1, 6
  lw    $ra, 0x14($sp)
  lui   $v1, %hi(D_8004E9E8)
  li    $at, 40960
  addiu $v1, %lo(D_8004E9E8) # addiu $v1, $v1, -0x1618
  addu  $t7, $v0, $at
  sw    $v0, ($v1)
  lui   $at, %hi(D_8004E9E4)
  sw    $t7, %lo(D_8004E9E4)($at)
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel load_rsp_microcode
  addiu $sp, $sp, -0x20
  lui   $v1, %hi(fast3d_related_array)
  addiu $v1, %lo(fast3d_related_array) # addiu $v1, $v1, -0x1550
  sw    $s0, 0x18($sp)
  lw    $s0, ($v1)
  lui   $v0, %hi(rspbootTextStart)
  lui   $t6, %hi(gsp3DTextStart) 
  addiu $v0, %lo(rspbootTextStart) # addiu $v0, $v0, 0xd90
  addiu $t6, %lo(gsp3DTextStart) # addiu $t6, $t6, 0xe60
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x28($sp)
  subu  $t7, $t6, $v0
  sw    $v0, 0x18($s0)
  lui   $t8, %hi(gsp3DTextStart) 
  lui   $t9, %hi(gsp3DDataStart) 
  sw    $t7, 0x1c($s0)
  addiu $v0, $s0, 0x10
  addiu $t8, %lo(gsp3DTextStart) # addiu $t8, $t8, 0xe60
  addiu $t9, %lo(gsp3DDataStart) # addiu $t9, $t9, -0x37e0
  sw    $t8, 0x10($v0)
  sw    $t9, 0x18($v0)
  lui   $t0, %hi(D_8004E9E8) 
  lw    $t0, %lo(D_8004E9E8)($t0)
  lui   $t1, %hi(D_8004E9E4) 
  subu  $t2, $a1, $a0
  sw    $t0, 0x28($v0)
  lw    $t1, %lo(D_8004E9E4)($t1)
  sra   $t3, $t2, 3
  lui   $t5, %hi(dword_CODE_bss_8008D770) 
  sll   $t4, $t3, 3
  addiu $t5, %lo(dword_CODE_bss_8008D770) # addiu $t5, $t5, -0x2890
  li    $t6, 2976
  sw    $a0, 0x30($v0)
  sw    $t4, 0x34($v0)
  sw    $t5, 0x38($v0)
  sw    $t6, 0x3c($v0)
  sw    $t1, 0x2c($v0)
  lui   $t8, %hi(gfxFrameMsgQ) 
  li    $t7, 99
  addiu $t8, %lo(gfxFrameMsgQ) # addiu $t8, $t8, -0x2660
  sw    $zero, ($s0)
  sw    $t7, 8($s0)
  sw    $t8, 0x50($s0)
  sw    $a3, 0x54($s0)
  lw    $t9, ($v1)
  lw    $t0, 0x58($t9)
  jal   osWritebackDCacheAll
   sw    $t0, 0xc($s0)
  lui   $a0, %hi(sched_cmdQ)
  lw    $a0, %lo(sched_cmdQ)($a0)
  move  $a1, $s0
  jal   osSendMesg
   li    $a2, 1
  lui   $v0, %hi(fast3d_related_array)
  addiu $v0, %lo(fast3d_related_array) # addiu $v0, $v0, -0x1550
  lw    $t1, ($v0)
  lui   $t2, %hi(fast3d_related_0) 
  lw    $ra, 0x1c($sp)
  addiu $t2, %lo(fast3d_related_0) # addiu $t2, $t2, -0x1610
  lui   $t4, %hi(fast3d_related_1) 
  addiu $t4, %lo(fast3d_related_1) # addiu $t4, $t4, -0x15b0
  xor   $t3, $t1, $t2
  xor   $t5, $t3, $t4
  lw    $s0, 0x18($sp)
  sw    $t5, ($v0)
  jr    $ra
   addiu $sp, $sp, 0x20
");
