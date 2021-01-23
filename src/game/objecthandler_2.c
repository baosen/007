const char aGetsubmatrixNoObjinst[] = "getsubmatrix: no objinst!\n";
const char aGetsubmatrixObjinstHasNoObject[] =
    "getsubmatrix: objinst has no object!\n";
const char aGetpartoffsetNoObjinst[] = "getpartoffset: no objinst!";
const char aGetpartoffsetNoPartdesc[] = "getpartoffset: no partdesc!";
const char aSetpartoffsetNoObjinst[] = "setpartoffset: no objinst!";
const char aSetpartoffsetNoPartdesc[] = "setpartoffset: no partdesc!";
const char aGetsuboffsetNoObjinst[] = "getsuboffset: no objinst!";
const char aGetsuboffsetObjinstHasNoObject[] =
    "getsuboffset: objinst has no object!";
const char aSetsuboffsetNoObjinst[] = "setsuboffset: no objinst!";
const char aSetsuboffsetObjinstHasNoObject[] =
    "setsuboffset: objinst has no object!";
const char aGetsubrotyNoObjinst[] = "getsubroty: no objinst!";
const char aGetsubrotyObjinstHasNoObject[] =
    "getsubroty: objinst has no object!";
const char aGetsubrotyObjinstHasNoRootPart[] =
    "getsubroty: objinst has no root part!";
const char aSetsubrotyNoObjinst[] = "setsubroty: no objinst!";
const char aSetsubrotyObjinstHasNoObject[] =
    "setsubroty: objinst has no object!";
const char aSetsubrotyObjinstHasNoRootPart[] =
    "setsubroty: objinst has no root part!";
const char aGetjointsizeNoObjinst[] = "getjointsize: no objinst!\n";
const char aGetinstsizeNoObjinst[] = "getinstsize: no objinst!\n";
const char aGetinstsizeNoObjdesc[] = "getinstsize: no objdesc!\n";
const char aSubcalcposNoObjanim[] = "subcalcpos: no objanim!\n";
const char aSubcalcposNoObjdesc[] = "subcalcpos: no objdesc!\n";
const char aInstcalcmatricesNoObjinst[] = "instcalcmatrices: no objinst!\n";
const char aInstcalcmatricesNoBasemtx[] = "instcalcmatrices: no basemtx!\n";
const char aInstcalcmatricesNoMtxlist[] = "instcalcmatrices: no mtxlist!\n";
const char aSubcalcmatricesNoObjanim[] = "subcalcmatrices: no objanim!\n";
const char aSubcalcmatricesNoBasemtx[] = "subcalcmatrices: no basemtx!\n";
const char aSubcalcmatricesNoMtxlist[] = "subcalcmatrices: no mtxlist!\n";
const char aSubcalcmatricesNoAttachForObjinst[] =
    "subcalcmatrices: no attach for objinst!\n";
const char aSubcalcmatricesFrameaOutOfRange[] =
    "subcalcmatrices: framea out of range!\n";
const char aSubcalcmatricesFramebOutOfRange[] =
    "subcalcmatrices: frameb out of range!\n";
const char aSubcalcmatricesNoAnim2[] = "subcalcmatrices: no anim2!\n";
const char aSubcalcmatricesFrame2aOutOfRange[] =
    "subcalcmatrices: frame2a out of range!\n";
const char aSubcalcmatricesFrame2bOutOfRange[] =
    "subcalcmatrices: frame2b out of range!\n";
const char aDorottexNoVtxAllocator[] = "dorottex: no vtx allocator!\n";
const char aDotubeNoVtxAllocator[] = "dotube: no vtx allocator!\n";
const char aDogfnegxNoVtxAllocator[] = "dogfnegx: no vtx allocator!\n";
const char aDoshadowNoVtxAllocator[] = "doshadow: no vtx allocator!\n";
const char aSubdrawNoGfxlist[] = "subdraw: no gfxlist!\n";
const char aSubdrawObjectNotInitialised0xX[] =
    "subdraw: object not initialised! (0x%X)\n";

asm(R"
glabel getsubmatrix
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06C6C4
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(aGetsubmatrixNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetsubmatrixNoObjinst) # addiu $a0, $a0, 0x4600
  jal   return_null
   nop   
.L7F06C6C4:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aGetsubmatrixObjinstHasNoObject)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06C6F4
   lw    $a0, 0x18($sp)
  jal   osSyncPrintf
   addiu $a0, $a0, %lo(aGetsubmatrixObjinstHasNoObject)
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $a0, 0x18($sp)
.L7F06C6F4:
  lw    $a1, ($v0)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06C710
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getsubmatrix
   sw    $a1, 0x1c($sp)
  beqz  $v0, .L7F06C744
   lw    $a1, 0x1c($sp)
  lwc1  $f4, 0x30($v0)
  swc1  $f4, ($a1)
  lwc1  $f6, 0x34($v0)
  swc1  $f6, 4($a1)
  lwc1  $f8, 0x38($v0)
  b     .L7F06C758
   swc1  $f8, 8($a1)
.L7F06C744:
  mtc1  $zero, $f0
  nop   
  swc1  $f0, ($a1)
  swc1  $f0, 4($a1)
  swc1  $f0, 8($a1)
.L7F06C758:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06C768
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   getsubmatrix
   nop   
  beqz  $v0, .L7F06C78C
   lw    $ra, 0x14($sp)
  lwc1  $f0, 0x38($v0)
  b     .L7F06C794
   neg.s $f0, $f0
.L7F06C78C:
  mtc1  $zero, $f0
  nop   
.L7F06C794:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
.late_rodata
/*D:80054AF8*/
glabel jpt_obj_struct_microcode_id
.word .L7F06C7D8
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C7F0
.word .L7F06C7FC
.word .L7F06C814
.word .L7F06C840
.word .L7F06C820
.word .L7F06C82C
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C840
.word .L7F06C808
.word .L7F06C840
.word .L7F06C840
/*.word .L7F06C840*/
/*.word .L7F06C840*/
/*.word .L7F06C838*/
/*.word .L7F06C7E4*/

.text
glabel extract_id_from_object_structure_microcode
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lhu   $t6, ($a1)
  move  $a2, $zero
  lw    $a3, 0x10($a0)
  andi  $t7, $t6, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x18
  beqz  $at, .L7F06C840
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_obj_struct_microcode_id)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_obj_struct_microcode_id)($at)
.L7F06C7D0:
  jr    $t8
   nop   
.L7F06C7D8:
  lw    $t9, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0xc($t9)
.L7F06C7E4:
  lw    $t0, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0x1a($t0)
.L7F06C7F0:
  lw    $t1, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0x1aa($t1)
.L7F06C7FC:
  lw    $t2, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0xc($t2)
.L7F06C808:
  lw    $t3, 4($a1)
  b     .L7F06C840
   lhu   $a2, 4($t3)
.L7F06C814:
  lw    $t4, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0x22($t4)
.L7F06C820:
  lw    $t5, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0x44($t5)
.L7F06C82C:
  lw    $t6, 4($a1)
  b     .L7F06C840
   lhu   $a2, 0x20($t6)
.L7F06C838:
  lw    $t7, 4($a1)
  lhu   $a2, ($t7)
def_7F06C7D0:
.L7F06C840:
  lw    $v0, 8($a1)
  li    $v1, 23
  beql  $v0, $zero, .L7F06C888
   lw    $ra, 0x14($sp)
  lhu   $t8, ($v0)
.L7F06C854:
  move  $a1, $v0
  andi  $t9, $t8, 0xff
  bnel  $v1, $t9, .L7F06C87C
   lw    $v0, 8($a1)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x1c($sp)
  lw    $a2, 0x1c($sp)
  b     .L7F06C884
   lw    $a3, 4($v0)
  lw    $v0, 8($a1)
.L7F06C87C:
  bnezl $v0, .L7F06C854
   lhu   $t8, ($v0)
.L7F06C884:
  lw    $ra, 0x14($sp)
.L7F06C888:
  sll   $t0, $a2, 2
  addu  $v0, $t0, $a3
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
/*HACKY, above jtable too big*/
.word .L7F06C840
.word .L7F06C840
.word .L7F06C838
.word .L7F06C7E4

.text
glabel getpartoffset
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06C8CC
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(aGetpartoffsetNoObjinst)
  addiu $a0, %lo(aGetpartoffsetNoObjinst) # addiu $a0, $a0, 0x4644
  sw    $a1, 0x1c($sp)
  jal   osSyncPrintf
   sw    $a2, 0x20($sp)
  jal   return_null
   nop   
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x20($sp)
.L7F06C8CC:
  bnez  $a1, .L7F06C8F4
   lui   $a0, %hi(aGetpartoffsetNoPartdesc)
  addiu $a0, %lo(aGetpartoffsetNoPartdesc) # addiu $a0, $a0, 0x4660
  sw    $a1, 0x1c($sp)
  jal   osSyncPrintf
   sw    $a2, 0x20($sp)
  jal   return_null
   nop   
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x20($sp)
.L7F06C8F4:
  lhu   $v0, ($a1)
  li    $at, 1
  lw    $a0, 0x18($sp)
  andi  $t7, $v0, 0xff
  beq   $t7, $at, .L7F06C93C
   li    $at, 2
  beq   $t7, $at, .L7F06C964
   li    $at, 3
  beq   $t7, $at, .L7F06C984
   li    $at, 21
  beql  $t7, $at, .L7F06C9A8
   lw    $v0, 4($a1)
  mtc1  $zero, $f0
  nop   
  swc1  $f0, ($a2)
  swc1  $f0, 4($a2)
  b     .L7F06C9C0
   swc1  $f0, 8($a2)
.L7F06C93C:
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x20($sp)
  lw    $a2, 0x20($sp)
  lwc1  $f4, 8($v0)
  swc1  $f4, ($a2)
  lwc1  $f6, 0xc($v0)
  swc1  $f6, 4($a2)
  lwc1  $f8, 0x10($v0)
  b     .L7F06C9C0
   swc1  $f8, 8($a2)
.L7F06C964:
  lw    $v0, 4($a1)
  lwc1  $f10, ($v0)
  swc1  $f10, ($a2)
  lwc1  $f16, 4($v0)
  swc1  $f16, 4($a2)
  lwc1  $f18, 8($v0)
  b     .L7F06C9C0
   swc1  $f18, 8($a2)
.L7F06C984:
  lw    $v0, 4($a1)
  lwc1  $f4, ($v0)
  swc1  $f4, ($a2)
  lwc1  $f6, 4($v0)
  swc1  $f6, 4($a2)
  lwc1  $f8, 8($v0)
  b     .L7F06C9C0
   swc1  $f8, 8($a2)
  lw    $v0, 4($a1)
.L7F06C9A8:
  lwc1  $f10, ($v0)
  swc1  $f10, ($a2)
  lwc1  $f16, 4($v0)
  swc1  $f16, 4($a2)
  lwc1  $f18, 8($v0)
  swc1  $f18, 8($a2)
.L7F06C9C0:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel setpartoffset
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06CA04
   sw    $a0, 0x28($sp)
  lui   $a0, %hi(aSetpartoffsetNoObjinst)
  addiu $a0, %lo(aSetpartoffsetNoObjinst) # addiu $a0, $a0, 0x467c
  sw    $a1, 0x2c($sp)
  jal   osSyncPrintf
   sw    $a2, 0x30($sp)
  jal   return_null
   nop   
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x30($sp)
.L7F06CA04:
  bnez  $a1, .L7F06CA2C
   lui   $a0, %hi(aSetpartoffsetNoPartdesc)
  addiu $a0, %lo(aSetpartoffsetNoPartdesc) # addiu $a0, $a0, 0x4698
  sw    $a1, 0x2c($sp)
  jal   osSyncPrintf
   sw    $a2, 0x30($sp)
  jal   return_null
   nop   
  lw    $a1, 0x2c($sp)
  lw    $a2, 0x30($sp)
.L7F06CA2C:
  lhu   $v0, ($a1)
  li    $at, 1
  lw    $a0, 0x28($sp)
  andi  $t7, $v0, 0xff
  beq   $t7, $at, .L7F06CA64
   li    $at, 2
  beq   $t7, $at, .L7F06CB2C
   li    $at, 3
  beq   $t7, $at, .L7F06CB4C
   li    $at, 21
  beql  $t7, $at, .L7F06CB70
   lw    $v0, 4($a1)
  b     .L7F06CB8C
   lw    $ra, 0x14($sp)
.L7F06CA64:
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x30($sp)
  lw    $a2, 0x30($sp)
  lwc1  $f6, 8($v0)
  lwc1  $f4, ($a2)
  sub.s $f8, $f4, $f6
  swc1  $f8, 0x18($sp)
  lwc1  $f16, 0x10($v0)
  lwc1  $f10, 8($a2)
  sub.s $f18, $f10, $f16
  swc1  $f18, 0x20($sp)
  lwc1  $f4, ($a2)
  lwc1  $f10, 0x24($v0)
  swc1  $f4, 8($v0)
  lwc1  $f6, 4($a2)
  lwc1  $f4, 0x2c($v0)
  swc1  $f6, 0xc($v0)
  lwc1  $f8, 8($a2)
  swc1  $f8, 0x10($v0)
  lwc1  $f16, 0x18($sp)
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x34($v0)
  swc1  $f18, 0x24($v0)
  lwc1  $f6, 0x20($sp)
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x3c($v0)
  swc1  $f8, 0x2c($v0)
  lwc1  $f16, 0x18($sp)
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x40($v0)
  swc1  $f18, 0x34($v0)
  lwc1  $f6, 0x20($sp)
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x48($v0)
  swc1  $f8, 0x3c($v0)
  lwc1  $f16, 0x18($sp)
  add.s $f18, $f10, $f16
  lwc1  $f10, 0x4c($v0)
  swc1  $f18, 0x40($v0)
  lwc1  $f6, 0x20($sp)
  add.s $f8, $f4, $f6
  lwc1  $f4, 0x54($v0)
  swc1  $f8, 0x48($v0)
  lwc1  $f16, 0x18($sp)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x4c($v0)
  lwc1  $f6, 0x20($sp)
  add.s $f8, $f4, $f6
  b     .L7F06CB88
   swc1  $f8, 0x54($v0)
.L7F06CB2C:
  lw    $v0, 4($a1)
  lwc1  $f10, ($a2)
  swc1  $f10, ($v0)
  lwc1  $f16, 4($a2)
  swc1  $f16, 4($v0)
  lwc1  $f18, 8($a2)
  b     .L7F06CB88
   swc1  $f18, 8($v0)
.L7F06CB4C:
  lw    $v0, 4($a1)
  lwc1  $f4, ($a2)
  swc1  $f4, ($v0)
  lwc1  $f6, 4($a2)
  swc1  $f6, 4($v0)
  lwc1  $f8, 8($a2)
  b     .L7F06CB88
   swc1  $f8, 8($v0)
  lw    $v0, 4($a1)
.L7F06CB70:
  lwc1  $f10, ($a2)
  swc1  $f10, ($v0)
  lwc1  $f16, 4($a2)
  swc1  $f16, 4($v0)
  lwc1  $f18, 8($a2)
  swc1  $f18, 8($v0)
.L7F06CB88:
  lw    $ra, 0x14($sp)
.L7F06CB8C:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel getsuboffset
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  bnez  $a0, .L7F06CBC0
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(aGetsuboffsetNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetsuboffsetNoObjinst) # addiu $a0, $a0, 0x46b4
  jal   return_null
   nop   
.L7F06CBC0:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aGetsuboffsetObjinstHasNoObject)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06CBF0
   lw    $a0, 0x18($sp)
  jal   osSyncPrintf
   addiu $a0, $a0, %lo(aGetsuboffsetObjinstHasNoObject)
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $a0, 0x18($sp)
.L7F06CBF0:
  lw    $a1, ($v0)
  jal   getpartoffset
   lw    $a2, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel setsuboffset
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  bnez  $a0, .L7F06CC34
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(aSetsuboffsetNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aSetsuboffsetNoObjinst) # addiu $a0, $a0, 0x46f8
  jal   return_null
   nop   
.L7F06CC34:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aSetsuboffsetObjinstHasNoObject)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06CC64
   lw    $a0, 0x18($sp)
  jal   osSyncPrintf
   addiu $a0, $a0, %lo(aSetsuboffsetObjinstHasNoObject)
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $a0, 0x18($sp)
.L7F06CC64:
  lw    $a1, ($v0)
  jal   setpartoffset
   lw    $a2, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel getsubroty
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06CCA4
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(aGetsubrotyNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetsubrotyNoObjinst) # addiu $a0, $a0, 0x473c
  jal   return_null
   nop   
.L7F06CCA4:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aGetsubrotyObjinstHasNoObject)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06CCD4
   lw    $v1, ($v0)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetsubrotyObjinstHasNoObject) # addiu $a0, $a0, 0x4754
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $v1, ($v0)
.L7F06CCD4:
  lui   $a0, %hi(aGetsubrotyObjinstHasNoRootPart)
  bnezl $v1, .L7F06CD00
   lhu   $t1, ($v1)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetsubrotyObjinstHasNoRootPart) # addiu $a0, $a0, 0x4778
  jal   return_null
   nop   
  lw    $t9, 0x18($sp)
  lw    $t0, 8($t9)
  lw    $v1, ($t0)
  lhu   $t1, ($v1)
.L7F06CD00:
  li    $at, 1
  move  $a1, $v1
  andi  $t2, $t1, 0xff
  bnel  $t2, $at, .L7F06CD28
   mtc1  $zero, $f0
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x18($sp)
  b     .L7F06CD2C
   lwc1  $f0, 0x14($v0)
  mtc1  $zero, $f0
.L7F06CD28:
  nop   
.L7F06CD2C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054B58
.word 0x40c90fdb /*6.2831855*/
glabel D_80054B5C
.word 0x40c90fdb /*6.2831855*/
.text
glabel setsubroty
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  bnez  $a0, .L7F06CD64
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(aSetsubrotyNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aSetsubrotyNoObjinst) # addiu $a0, $a0, 0x47a0
  jal   return_null
   nop   
.L7F06CD64:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aSetsubrotyObjinstHasNoObject)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06CD94
   lw    $v1, ($v0)
  jal   osSyncPrintf
   addiu $a0, %lo(aSetsubrotyObjinstHasNoObject) # addiu $a0, $a0, 0x47b8
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $v1, ($v0)
.L7F06CD94:
  lui   $a0, %hi(aSetsubrotyObjinstHasNoRootPart)
  bnezl $v1, .L7F06CDC0
   lhu   $t1, ($v1)
  jal   osSyncPrintf
   addiu $a0, %lo(aSetsubrotyObjinstHasNoRootPart) # addiu $a0, $a0, 0x47dc
  jal   return_null
   nop   
  lw    $t9, 0x18($sp)
  lw    $t0, 8($t9)
  lw    $v1, ($t0)
  lhu   $t1, ($v1)
.L7F06CDC0:
  li    $at, 1
  move  $a1, $v1
  andi  $t2, $t1, 0xff
  bnel  $t2, $at, .L7F06CE6C
   lw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a0, 0x18($sp)
  lwc1  $f4, 0x1c($sp)
  lwc1  $f6, 0x14($v0)
  mtc1  $zero, $f8
  lui   $at, %hi(D_80054B58)
  sub.s $f0, $f4, $f6
  c.lt.s $f0, $f8
  nop   
  bc1fl .L7F06CE0C
   lwc1  $f10, 0x30($v0)
  lwc1  $f12, %lo(D_80054B58)($at)
  add.s $f0, $f0, $f12
  lwc1  $f10, 0x30($v0)
.L7F06CE0C:
  lui   $at, %hi(D_80054B5C)
  lwc1  $f12, %lo(D_80054B5C)($at)
  add.s $f16, $f10, $f0
  swc1  $f16, 0x30($v0)
  lwc1  $f2, 0x30($v0)
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F06CE3C
   lwc1  $f4, 0x20($v0)
  sub.s $f18, $f2, $f12
  swc1  $f18, 0x30($v0)
  lwc1  $f4, 0x20($v0)
.L7F06CE3C:
  add.s $f6, $f4, $f0
  swc1  $f6, 0x20($v0)
  lwc1  $f2, 0x20($v0)
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F06CE64
   lwc1  $f10, 0x1c($sp)
  sub.s $f8, $f2, $f12
  swc1  $f8, 0x20($v0)
  lwc1  $f10, 0x1c($sp)
.L7F06CE64:
  swc1  $f10, 0x14($v0)
  lw    $ra, 0x14($sp)
.L7F06CE6C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel set_obj_instance_controller_scale
  mtc1  $a1, $f12
  jr    $ra
   swc1  $f12, 0x14($a0)
");

asm(R"
glabel sub_GAME_7F06CE84
  mtc1  $a1, $f12
  jr    $ra
   swc1  $f12, 0xb8($a0)
");

asm(R"
.late_rodata
/*D:80054B60*/
glabel jpt_getjointsize
.word .L7F06CEF8
.word .L7F06CF10
.word .L7F06CF28
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CF58
.word .L7F06CF70
.word .L7F06CF88
.word .L7F06CFA0
.word .L7F06CFB8
.word .L7F06CFD0
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CFE8
.word .L7F06CF40

.text
glabel getjointsize
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06CEC4
   move  $a2, $a0
  lui   $a0, %hi(aGetjointsizeNoObjinst)
  addiu $a0, %lo(aGetjointsizeNoObjinst) # addiu $a0, $a0, 0x4804
  sw    $a1, 0x1c($sp)
  jal   osSyncPrintf
   sw    $a2, 0x18($sp)
  jal   return_null
   nop   
  lw    $a1, 0x1c($sp)
  lw    $a2, 0x18($sp)
.L7F06CEC4:
  beql  $a1, $zero, .L7F06CFF8
   mtc1  $zero, $f0
  lhu   $t6, ($a1)
.L7F06CED0:
  andi  $t7, $t6, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x15
  beqz  $at, .L7F06CFE8
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_getjointsize)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_getjointsize)($at)
.L7F06CEF0:
  jr    $t8
   nop   
.L7F06CEF8:
  lw    $v0, 4($a1)
  lwc1  $f6, 0x14($a2)
  lwc1  $f4, 8($v0)
  mul.s $f0, $f4, $f6
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF10:
  lw    $v0, 4($a1)
  lwc1  $f10, 0x14($a2)
  lwc1  $f8, 0x18($v0)
  mul.s $f0, $f8, $f10
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF28:
  lw    $v0, 4($a1)
  lwc1  $f18, 0x14($a2)
  lwc1  $f16, 0x18($v0)
  mul.s $f0, $f16, $f18
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF40:
  lw    $v0, 4($a1)
  lwc1  $f6, 0x14($a2)
  lwc1  $f4, 0x10($v0)
  mul.s $f0, $f4, $f6
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF58:
  lw    $v0, 4($a1)
  lwc1  $f10, 0x14($a2)
  lwc1  $f8, 0x40($v0)
  mul.s $f0, $f8, $f10
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF70:
  lw    $v0, 4($a1)
  lwc1  $f18, 0x14($a2)
  lwc1  $f16, 0x1c($v0)
  mul.s $f0, $f16, $f18
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CF88:
  lw    $v0, 4($a1)
  lwc1  $f6, 0x14($a2)
  lwc1  $f4, 0x18($v0)
  mul.s $f0, $f4, $f6
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CFA0:
  lw    $v0, 4($a1)
  lwc1  $f10, 0x14($a2)
  lwc1  $f8, 0xc($v0)
  mul.s $f0, $f8, $f10
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CFB8:
  lw    $v0, 4($a1)
  lwc1  $f18, 0x14($a2)
  lwc1  $f16, 0x18($v0)
  mul.s $f0, $f16, $f18
  b     .L7F06D000
   lw    $ra, 0x14($sp)
.L7F06CFD0:
  lw    $v0, 4($a1)
  lwc1  $f6, 0x14($a2)
  lwc1  $f4, 0x14($v0)
  mul.s $f0, $f4, $f6
  b     .L7F06D000
   lw    $ra, 0x14($sp)
def_7F06CEF0:
.L7F06CFE8:
  lw    $a1, 8($a1)
  bnezl $a1, .L7F06CED0
   lhu   $t6, ($a1)
  mtc1  $zero, $f0
.L7F06CFF8:
  nop   
  lw    $ra, 0x14($sp)
.L7F06D000:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel getinstsize
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06D030
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(aGetinstsizeNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetinstsizeNoObjinst) # addiu $a0, $a0, 0x4820
  jal   return_null
   nop   
.L7F06D030:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aGetinstsizeNoObjdesc)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06D060
   lw    $t9, 0x18($sp)
  jal   osSyncPrintf
   addiu $a0, %lo(aGetinstsizeNoObjdesc) # addiu $a0, $a0, 0x483c
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $t9, 0x18($sp)
.L7F06D060:
  lwc1  $f4, 0x10($v0)
  lw    $ra, 0x14($sp)
  lwc1  $f6, 0x14($t9)
  addiu $sp, $sp, 0x18
  mul.s $f0, $f4, $f6
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06D07C
  lwc1  $f0, ($a0)
  lwc1  $f4, ($a1)
  mtc1  $a2, $f12
  lwc1  $f2, 4($a0)
  sub.s $f6, $f4, $f0
  lwc1  $f14, 8($a0)
  mul.s $f8, $f6, $f12
  add.s $f10, $f0, $f8
  swc1  $f10, ($a0)
  lwc1  $f16, 4($a1)
  sub.s $f18, $f16, $f2
  mul.s $f4, $f18, $f12
  add.s $f6, $f2, $f4
  swc1  $f6, 4($a0)
  lwc1  $f8, 8($a1)
  sub.s $f10, $f8, $f14
  mul.s $f16, $f10, $f12
  add.s $f18, $f14, $f16
  jr    $ra
   swc1  $f18, 8($a0)
");

asm(R"
.late_rodata
glabel D_80054BB4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BB8
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BBC
.word 0x40490fdb /*3.1415927*/
.text
glabel sub_GAME_7F06D0CC
  c.lt.s $f14, $f12
  sw    $a2, 8($sp)
  sub.s $f2, $f14, $f12
  lui   $at, %hi(D_80054BB4)
  lwc1  $f6, 8($sp)
  bc1f  .L7F06D0F0
   mov.s $f0, $f2
  lwc1  $f14, %lo(D_80054BB4)($at)
  add.s $f0, $f2, $f14
.L7F06D0F0:
  lui   $at, %hi(D_80054BB8)
  lwc1  $f14, %lo(D_80054BB8)($at)
  lui   $at, %hi(D_80054BBC)
  lwc1  $f4, %lo(D_80054BBC)($at)
  c.lt.s $f0, $f4
  nop   
  bc1fl .L7F06D134
   sub.s $f10, $f14, $f0
  mul.s $f8, $f0, $f6
  add.s $f12, $f12, $f8
  c.le.s $f14, $f12
  nop   
  bc1f  .L7F06D158
   nop   
  jr    $ra
   sub.s $f0, $f12, $f14

  sub.s $f10, $f14, $f0
.L7F06D134:
  lwc1  $f16, 8($sp)
  mtc1  $zero, $f4
  mul.s $f18, $f10, $f16
  sub.s $f12, $f12, $f18
  c.lt.s $f12, $f4
  nop   
  bc1f  .L7F06D158
   nop   
  add.s $f12, $f12, $f14
.L7F06D158:
  jr    $ra
   mov.s $f0, $f12
");

asm(R"
glabel sub_GAME_7F06D160
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  move  $s0, $a0
  lwc1  $f14, ($a1)
  jal   sub_GAME_7F06D0CC
   lwc1  $f12, ($a0)
  swc1  $f0, ($s0)
  lw    $t7, 0x24($sp)
  lw    $a2, 0x28($sp)
  lwc1  $f12, 4($s0)
  jal   sub_GAME_7F06D0CC
   lwc1  $f14, 4($t7)
  swc1  $f0, 4($s0)
  lw    $t8, 0x24($sp)
  lw    $a2, 0x28($sp)
  lwc1  $f12, 8($s0)
  jal   sub_GAME_7F06D0CC
   lwc1  $f14, 8($t8)
  swc1  $f0, 8($s0)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06D1CC
  lw    $t6, 8($a0)
  sll   $t7, $a1, 2
  subu  $t7, $t7, $a1
  sll   $t7, $t7, 1
  addu  $a3, $t6, $t7
  lbu   $t0, 2($a3)
  move  $v1, $zero
  move  $t1, $t0
  blezl $t1, .L7F06D2D8
   lhu   $t8, 4($a3)
  lhu   $t8, ($a3)
  li    $t6, 8
  lw    $t5, 0x10($a0)
  addu  $v0, $t8, $a2
  andi  $t9, $v0, 7
  subu  $t4, $t6, $t9
  andi  $t7, $t4, 0xff
  srl   $a1, $v0, 3
  slt   $at, $t1, $t7
  andi  $t3, $t4, 0xff
  bnez  $at, .L7F06D260
   addu  $t2, $t5, $a1
.L7F06D224:
  lbu   $t9, ($t2)
  li    $t5, 1
  sllv  $t6, $t5, $t3
  subu  $v0, $t1, $t3
  addiu $t7, $t6, -1
  andi  $t1, $v0, 0xff
  and   $t8, $t9, $t7
  sllv  $t5, $t8, $t1
  or    $v1, $v1, $t5
  andi  $t6, $v1, 0xffff
  slti  $at, $t1, 8
  move  $v1, $t6
  addiu $t2, $t2, 1
  beqz  $at, .L7F06D224
   li    $t3, 8
.L7F06D260:
  blez  $t1, .L7F06D28C
   subu  $t7, $t3, $t1
  lbu   $t9, ($t2)
  li    $t5, 1
  sllv  $t6, $t5, $t1
  srav  $t8, $t9, $t7
  addiu $t9, $t6, -1
  and   $t7, $t8, $t9
  or    $v1, $v1, $t7
  andi  $t5, $v1, 0xffff
  move  $v1, $t5
.L7F06D28C:
  andi  $t1, $t0, 0xff
  slti  $at, $t1, 0x10
  beqz  $at, .L7F06D2D4
   addiu $t6, $t1, 0x1f
  li    $t8, 1
  sllv  $t9, $t8, $t6
  and   $t7, $v1, $t9
  beqz  $t7, .L7F06D2D4
   move  $v0, $v1
  li    $t5, 16
  subu  $t8, $t5, $t1
  li    $t6, 1
  sllv  $t9, $t6, $t8
  addiu $t7, $t9, -1
  sllv  $t5, $t7, $t1
  or    $v1, $v0, $t5
  andi  $t6, $v1, 0xffff
  move  $v1, $t6
.L7F06D2D4:
  lhu   $t8, 4($a3)
.L7F06D2D8:
  addu  $v1, $v1, $t8
  jr    $ra
   andi  $v0, $v1, 0xffff
");

asm(R"
glabel sub_GAME_7F06D2E4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  lhu   $t6, 0xc($a3)
  lw    $t7, 0x38($sp)
  move  $s2, $a3
  sll   $t0, $a0, 2
  multu $t6, $t7
  sll   $t3, $a0, 2
  mflo  $s1
  beql  $a1, $zero, .L7F06D33C
   lw    $t2, 4($a2)
  lw    $t9, 4($a2)
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 1
  addu  $t1, $t9, $t0
  b     .L7F06D34C
   lhu   $s0, 4($t1)
  lw    $t2, 4($a2)
.L7F06D33C:
  subu  $t3, $t3, $a0
  sll   $t3, $t3, 1
  addu  $t4, $t2, $t3
  lhu   $s0, 2($t4)
.L7F06D34C:
  move  $a0, $s2
  move  $a1, $s0
  jal   sub_GAME_7F06D1CC
   move  $a2, $s1
  lw    $t5, 0x3c($sp)
  move  $a0, $s2
  addiu $a1, $s0, 1
  move  $a2, $s1
  jal   sub_GAME_7F06D1CC
   sh    $v0, ($t5)
  lw    $t6, 0x3c($sp)
  move  $a0, $s2
  addiu $a1, $s0, 2
  move  $a2, $s1
  jal   sub_GAME_7F06D1CC
   sh    $v0, 2($t6)
  lw    $t7, 0x3c($sp)
  move  $a0, $s2
  addiu $a1, $s0, 3
  move  $a2, $s1
  jal   sub_GAME_7F06D1CC
   sh    $v0, 4($t7)
  lw    $t8, 0x2c($sp)
  lw    $a1, 0x3c($sp)
  andi  $v1, $v0, 0xffff
  beql  $t8, $zero, .L7F06D3DC
   lw    $ra, 0x24($sp)
  lh    $t9, ($a1)
  lui   $t1, 1
  negu  $t0, $t9
  beqz  $v0, .L7F06D3D8
   sh    $t0, ($a1)
  subu  $v1, $t1, $v0
  andi  $t2, $v1, 0xffff
  move  $v1, $t2
.L7F06D3D8:
  lw    $ra, 0x24($sp)
.L7F06D3DC:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  addiu $sp, $sp, 0x28
  jr    $ra
   move  $v0, $v1
");

asm(R"
.late_rodata
glabel D_80054BC0
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06D3F4
  addiu $sp, $sp, -0x30
  lw    $t6, 0x40($sp)
  sw    $ra, 0x1c($sp)
  addiu $t7, $sp, 0x28
  sw    $t7, 0x14($sp)
  jal   sub_GAME_7F06D2E4
   sw    $t6, 0x10($sp)
  lh    $t8, 0x28($sp)
  lw    $v1, 0x44($sp)
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $t8, $f4
  nop   
  cvt.s.w $f6, $f4
  mtc1  $v0, $f4
  swc1  $f6, ($v1)
  lh    $t9, 0x2a($sp)
  cvt.s.w $f6, $f4
  mtc1  $t9, $f8
  nop   
  cvt.s.w $f10, $f8
  swc1  $f10, 4($v1)
  lh    $t0, 0x2c($sp)
  mtc1  $t0, $f16
  nop   
  cvt.s.w $f18, $f16
  bgez  $v0, .L7F06D46C
   swc1  $f18, 8($v1)
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F06D46C:
  lui   $at, %hi(D_80054BC0)
  lwc1  $f10, %lo(D_80054BC0)($at)
  lw    $ra, 0x1c($sp)
  li    $at, 0x47800000 # 65536.000000
  mul.s $f16, $f6, $f10
  mtc1  $at, $f18
  addiu $sp, $sp, 0x30
  jr    $ra
   div.s $f0, $f16, $f18
");

asm(R"
glabel sub_GAME_7F06D490
  addiu $sp, $sp, -0x48
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  jal   extract_id_from_object_structure_microcode
   sw    $s0, 0x14($sp)
  lb    $t6, ($v0)
  move  $s0, $v0
  bnezl $t6, .L7F06D6A0
   lw    $ra, 0x1c($sp)
  lwc1  $f4, 0x34($v0)
  mtc1  $zero, $f14
  swc1  $f4, 0x38($sp)
  lwc1  $f6, 0x38($v0)
  swc1  $f6, 0x3c($sp)
  lwc1  $f8, 0x3c($v0)
  swc1  $f8, 0x40($sp)
  lwc1  $f10, 0x30($v0)
  swc1  $f10, 0x14($v0)
  lwc1  $f0, 0x2c($s1)
  c.eq.s $f14, $f0
  nop   
  bc1tl .L7F06D528
   lw    $t8, 0x54($s1)
  lb    $t7, 1($v0)
  addiu $a0, $sp, 0x38
  beql  $t7, $zero, .L7F06D528
   lw    $t8, 0x54($s1)
  mfc1  $a2, $f0
  jal   sub_GAME_7F06D07C
   addiu $a1, $v0, 0x24
  lwc1  $f12, 0x30($s0)
  lwc1  $f14, 0x20($s0)
  jal   sub_GAME_7F06D0CC
   lw    $a2, 0x2c($s1)
  mtc1  $zero, $f14
  swc1  $f0, 0x14($s0)
  lw    $t8, 0x54($s1)
.L7F06D528:
  move  $a0, $s1
  addiu $a1, $s0, 8
  bnez  $t8, .L7F06D54C
   addiu $a2, $sp, 0x2c
  lwc1  $f16, 0x84($s1)
  c.eq.s $f14, $f16
  nop   
  bc1tl .L7F06D59C
   lwc1  $f4, 0x38($sp)
.L7F06D54C:
  lb    $t9, 2($s0)
  lwc1  $f8, 0x3c($sp)
  beql  $t9, $zero, .L7F06D59C
   lwc1  $f4, 0x38($sp)
  lwc1  $f2, 0x5c($s1)
  lwc1  $f0, 0x50($s0)
  lwc1  $f12, 0x84($s1)
  c.eq.s $f14, $f2
  nop   
  bc1tl .L7F06D58C
   sub.s $f10, $f0, $f8
  lwc1  $f18, 0x44($s0)
  sub.s $f4, $f18, $f0
  mul.s $f6, $f4, $f2
  add.s $f0, $f0, $f6
  sub.s $f10, $f0, $f8
.L7F06D58C:
  mul.s $f16, $f10, $f12
  add.s $f18, $f8, $f16
  swc1  $f18, 0x3c($sp)
  lwc1  $f4, 0x38($sp)
.L7F06D59C:
  lwc1  $f6, 0x3c($sp)
  lwc1  $f10, 0x40($sp)
  swc1  $f4, 0x2c($sp)
  swc1  $f6, 0x30($sp)
  swc1  $f10, 0x34($sp)
  lw    $v0, 0xa0($s1)
  beql  $v0, $zero, .L7F06D5D0
   lwc1  $f8, 0x2c($sp)
  jalr  $v0
  addiu $a3, $s0, 4
  beql  $v0, $zero, .L7F06D6A0
   lw    $ra, 0x1c($sp)
  lwc1  $f8, 0x2c($sp)
.L7F06D5D0:
  lwc1  $f16, 0x38($sp)
  lwc1  $f4, 0x34($sp)
  lwc1  $f6, 0x40($sp)
  sub.s $f18, $f8, $f16
  sub.s $f10, $f4, $f6
  swc1  $f18, 0x38($sp)
  swc1  $f10, 0x40($sp)
  swc1  $f8, 8($s0)
  lwc1  $f16, 0x30($sp)
  lwc1  $f18, 4($s0)
  lwc1  $f10, 0x34($s0)
  lb    $t0, 1($s0)
  add.s $f4, $f16, $f18
  lwc1  $f18, 0x3c($s0)
  swc1  $f4, 0xc($s0)
  lwc1  $f6, 0x34($sp)
  swc1  $f6, 0x10($s0)
  lwc1  $f8, 0x38($sp)
  add.s $f16, $f10, $f8
  swc1  $f16, 0x34($s0)
  lwc1  $f4, 0x40($sp)
  add.s $f6, $f18, $f4
  beqz  $t0, .L7F06D650
   swc1  $f6, 0x3c($s0)
  lwc1  $f10, 0x24($s0)
  lwc1  $f8, 0x38($sp)
  lwc1  $f18, 0x2c($s0)
  add.s $f16, $f10, $f8
  swc1  $f16, 0x24($s0)
  lwc1  $f4, 0x40($sp)
  add.s $f6, $f18, $f4
  swc1  $f6, 0x2c($s0)
.L7F06D650:
  lb    $t1, 2($s0)
  lwc1  $f8, 0x38($sp)
  beql  $t1, $zero, .L7F06D6A0
   lw    $ra, 0x1c($sp)
  lwc1  $f10, 0x4c($s0)
  lwc1  $f18, 0x54($s0)
  add.s $f16, $f10, $f8
  lwc1  $f10, 0x40($s0)
  swc1  $f16, 0x4c($s0)
  lwc1  $f4, 0x40($sp)
  add.s $f6, $f18, $f4
  lwc1  $f18, 0x48($s0)
  swc1  $f6, 0x54($s0)
  lwc1  $f8, 0x38($sp)
  add.s $f16, $f10, $f8
  swc1  $f16, 0x40($s0)
  lwc1  $f4, 0x40($sp)
  add.s $f6, $f18, $f4
  swc1  $f6, 0x48($s0)
  lw    $ra, 0x1c($sp)
.L7F06D6A0:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel subcalcpos
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a0, .L7F06D6D4
   sw    $a0, 0x18($sp)
  lui   $a0, %hi(aSubcalcposNoObjanim)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcposNoObjanim) # addiu $a0, $a0, 0x4858
  jal   return_null
   nop   
.L7F06D6D4:
  lw    $t7, 0x18($sp)
  lui   $a0, %hi(aSubcalcposNoObjdesc)
  lw    $v0, 8($t7)
  bnezl $v0, .L7F06D704
   lw    $a1, ($v0)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcposNoObjdesc) # addiu $a0, $a0, 0x4874
  jal   return_null
   nop   
  lw    $t8, 0x18($sp)
  lw    $v0, 8($t8)
  lw    $a1, ($v0)
.L7F06D704:
  beql  $a1, $zero, .L7F06D72C
   lw    $ra, 0x14($sp)
  lhu   $t9, ($a1)
  li    $at, 1
  andi  $t0, $t9, 0xff
  bnel  $t0, $at, .L7F06D72C
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F06D490
   lw    $a0, 0x18($sp)
  lw    $ra, 0x14($sp)
.L7F06D72C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel process_01_group_heading
  addiu $sp, $sp, -0x80
  sw    $ra, 0x14($sp)
  sw    $a0, 0x80($sp)
  lw    $t6, 4($a2)
  move  $a3, $a1
  move  $a0, $a1
  move  $a1, $a2
  sw    $a3, 0x84($sp)
  sw    $a2, 0x88($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0x7c($sp)
  lw    $a3, 0x84($sp)
  lw    $t8, 0x7c($sp)
  addiu $t7, $v0, 8
  lwc1  $f4, 0x14($a3)
  sw    $t7, 0x70($sp)
  lw    $a2, 0x88($sp)
  swc1  $f4, 0x74($sp)
  lh    $v1, 2($t8)
  lw    $t9, 0xc($a3)
  lwc1  $f12, 0x14($v0)
  sll   $t1, $v1, 6
  addu  $t2, $t9, $t1
  sw    $t2, 0x60($sp)
  lw    $a1, 8($a2)
  move  $t0, $v0
  lw    $t3, 0x80($sp)
  beqz  $a1, .L7F06D7CC
   move  $a0, $a3
  move  $a2, $zero
  sw    $v0, 0x78($sp)
  jal   sub_GAME_7F06C660
   swc1  $f12, 0x6c($sp)
  lw    $t0, 0x78($sp)
  lwc1  $f12, 0x6c($sp)
  b     .L7F06D7D0
   move  $a3, $v0
.L7F06D7CC:
  lw    $a3, ($t3)
.L7F06D7D0:
  lwc1  $f0, 0x18($t0)
  mtc1  $zero, $f6
  nop   
  c.eq.s $f6, $f0
  nop   
  bc1t  .L7F06D804
   nop   
  lwc1  $f14, 0x1c($t0)
  mfc1  $a2, $f0
  jal   sub_GAME_7F06D0CC
   sw    $a3, 0x68($sp)
  lw    $a3, 0x68($sp)
  mov.s $f12, $f0
.L7F06D804:
  beqz  $a3, .L7F06D86C
   lw    $a0, 0x70($sp)
  mfc1  $a1, $f12
  lw    $a0, 0x70($sp)
  addiu $a2, $sp, 0x20
  jal   sub_GAME_7F0584D0
   sw    $a3, 0x68($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f10
  lwc1  $f8, 0x74($sp)
  lw    $a3, 0x68($sp)
  addiu $a1, $sp, 0x20
  c.eq.s $f8, $f10
  nop   
  bc1tl .L7F06D858
   move  $a0, $a3
  mov.s $f12, $f8
  jal   sub_GAME_7F058B10
   sw    $a3, 0x68($sp)
  lw    $a3, 0x68($sp)
  move  $a0, $a3
.L7F06D858:
  addiu $a1, $sp, 0x20
  jal   sub_GAME_7F05818C
   lw    $a2, 0x60($sp)
  b     .L7F06D8A4
   lw    $ra, 0x14($sp)
.L7F06D86C:
  mfc1  $a1, $f12
  jal   sub_GAME_7F0584D0
   lw    $a2, 0x60($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f18
  lwc1  $f16, 0x74($sp)
  lw    $a1, 0x60($sp)
  c.eq.s $f16, $f18
  nop   
  bc1tl .L7F06D8A4
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F058B10
   mov.s $f12, $f16
  lw    $ra, 0x14($sp)
.L7F06D8A4:
  addiu $sp, $sp, 0x80
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054BC4
.word 0x40490fdb /*3.1415927*/
glabel D_80054BC8
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BCC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BD0
.word 0x40490fdb /*3.1415927*/
glabel D_80054BD4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BD8
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06D8B0
  addiu $sp, $sp, -0xb8
  sw    $ra, 0x14($sp)
  sw    $a1, 0xbc($sp)
  sw    $a3, 0xc4($sp)
  lhu   $t6, ($a2)
  sw    $t6, 0xb4($sp)
  lw    $t7, 4($a2)
  sw    $t7, 0xb0($sp)
  lh    $t9, 0xe($t7)
  sw    $t9, 0x64($sp)
  lh    $t0, 0x10($t7)
  sw    $t0, 0x60($sp)
  lh    $t1, 0x12($t7)
  sw    $t1, 0x5c($sp)
  lw    $t3, 0xc($a1)
  sw    $t3, 0x58($sp)
  lw    $t4, 8($a2)
  move  $a2, $zero
  beqz  $t4, .L7F06D914
   sw    $t4, 0x1c($sp)
  move  $a0, $a1
  jal   sub_GAME_7F06C660
   move  $a1, $t4
  b     .L7F06D91C
   sw    $v0, 0xac($sp)
.L7F06D914:
  lw    $t6, ($a0)
  sw    $t6, 0xac($sp)
.L7F06D91C:
  lw    $t7, 0xac($sp)
  lw    $t1, 0x64($sp)
  lw    $a0, 0xb0($sp)
  beqz  $t7, .L7F06D988
   sll   $t3, $t1, 6
  lw    $a0, 0xb0($sp)
  lw    $a1, 0xc4($sp)
  jal   sub_GAME_7F05892C
   addiu $a2, $sp, 0x68
  lw    $t9, 0x64($sp)
  lw    $t8, 0x58($sp)
  lw    $a0, 0xac($sp)
  sll   $t0, $t9, 6
  addu  $a2, $t0, $t8
  sw    $a2, 0x1c($sp)
  jal   sub_GAME_7F05818C
   addiu $a1, $sp, 0x68
  lui   $v0, %hi(D_80036090)
  lw    $v0, %lo(D_80036090)($v0)
  lw    $a2, 0x1c($sp)
  lw    $a0, 0x64($sp)
  beql  $v0, $zero, .L7F06D99C
   lw    $t2, 0xb4($sp)
  jalr  $v0
  move  $a1, $a2
  b     .L7F06D99C
   lw    $t2, 0xb4($sp)
.L7F06D988:
  lw    $t4, 0x58($sp)
  lw    $a1, 0xc4($sp)
  jal   sub_GAME_7F05892C
   addu  $a2, $t3, $t4
  lw    $t2, 0xb4($sp)
.L7F06D99C:
  lw    $a0, 0xc4($sp)
  andi  $t5, $t2, 0x100
  beql  $t5, $zero, .L7F06DA1C
   lw    $t4, 0xb4($sp)
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x3c
  addiu $a0, $sp, 0x3c
  lui   $a1, 0x3f00
  jal   sub_GAME_7F05BC68
   addiu $a2, $sp, 0x2c
  lw    $t6, 0xac($sp)
  lw    $t8, 0x60($sp)
  addiu $a1, $sp, 0x2c
  beqz  $t6, .L7F06DA08
   sll   $t1, $t8, 6
  lw    $a0, 0xb0($sp)
  jal   sub_GAME_7F05B9B4
   addiu $a2, $sp, 0x68
  lw    $t7, 0x60($sp)
  lw    $t0, 0x58($sp)
  lw    $a0, 0xac($sp)
  sll   $t9, $t7, 6
  addiu $a1, $sp, 0x68
  jal   sub_GAME_7F05818C
   addu  $a2, $t9, $t0
  b     .L7F06DA1C
   lw    $t4, 0xb4($sp)
.L7F06DA08:
  lw    $t3, 0x58($sp)
  lw    $a0, 0xb0($sp)
  jal   sub_GAME_7F05B9B4
   addu  $a2, $t1, $t3
  lw    $t4, 0xb4($sp)
.L7F06DA1C:
  lw    $t5, 0xac($sp)
  andi  $t2, $t4, 0x200
  beql  $t2, $zero, .L7F06DB50
   lw    $ra, 0x14($sp)
  beqz  $t5, .L7F06DA40
   lw    $t7, 0x5c($sp)
  addiu $t6, $sp, 0x68
  b     .L7F06DA50
   sw    $t6, 0x28($sp)
.L7F06DA40:
  lw    $t0, 0x58($sp)
  sll   $t9, $t7, 6
  addu  $t8, $t9, $t0
  sw    $t8, 0x28($sp)
.L7F06DA50:
  lw    $t1, 0xc4($sp)
  lui   $at, %hi(D_80054BC4)
  lwc1  $f4, %lo(D_80054BC4)($at)
  lwc1  $f12, 4($t1)
  lui   $at, %hi(D_80054BC8)
  lw    $a1, 0x28($sp)
  c.lt.s $f12, $f4
  nop   
  bc1f  .L7F06DA90
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  mul.s $f12, $f12, $f6
  b     .L7F06DAB0
   nop   
.L7F06DA90:
  lwc1  $f8, %lo(D_80054BC8)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  sub.s $f10, $f8, $f12
  lui   $at, %hi(D_80054BCC)
  lwc1  $f4, %lo(D_80054BCC)($at)
  mul.s $f18, $f10, $f16
  sub.s $f12, $f4, $f18
.L7F06DAB0:
  jal   sub_GAME_7F0585FC
   swc1  $f12, 0x24($sp)
  lui   $at, %hi(D_80054BD0)
  lwc1  $f12, 0x24($sp)
  lwc1  $f6, %lo(D_80054BD0)($at)
  lui   $at, %hi(D_80054BD4)
  c.le.s $f6, $f12
  nop   
  bc1f  .L7F06DAE0
   nop   
  lwc1  $f8, %lo(D_80054BD4)($at)
  sub.s $f12, $f8, $f12
.L7F06DAE0:
  lui    $at, %hi(D_80054BD8)
  lwc1  $f10, %lo(D_80054BD8)($at)
  li    $at, 0x3FC00000 # 1.500000
  c.lt.s $f12, $f10
  nop   
  bc1fl .L7F06DB10
   mtc1  $at, $f12
  jal   sqrt_tan_angle_plus_one
   nop   
  b     .L7F06DB14
   mov.s $f12, $f0
  mtc1  $at, $f12
.L7F06DB10:
  nop   
.L7F06DB14:
  jal   sub_GAME_7F058A4C
   lw    $a1, 0x28($sp)
  lw    $a0, 0xb0($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x28($sp)
  lw    $t3, 0xac($sp)
  lw    $t4, 0x5c($sp)
  lw    $t5, 0x58($sp)
  beqz  $t3, .L7F06DB4C
   move  $a0, $t3
  sll   $t2, $t4, 6
  addu  $a2, $t2, $t5
  jal   sub_GAME_7F05818C
   lw    $a1, 0x28($sp)
.L7F06DB4C:
  lw    $ra, 0x14($sp)
.L7F06DB50:
  addiu $sp, $sp, 0xb8
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054BDC
.word 0x40490fdb /*3.1415927*/
glabel D_80054BE0
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BE4
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BE8
.word 0x40490fdb /*3.1415927*/
glabel D_80054BEC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054BF0
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06DB5C
  addiu $sp, $sp, -0xa8
  sw    $ra, 0x14($sp)
  sw    $a1, 0xac($sp)
  sw    $a3, 0xb4($sp)
  lhu   $t6, ($a2)
  sw    $t6, 0xa4($sp)
  lw    $t7, 4($a2)
  sw    $t7, 0xa0($sp)
  lh    $t9, 0xe($t7)
  sw    $t9, 0x54($sp)
  lh    $t0, 0x10($t7)
  sw    $t0, 0x50($sp)
  lh    $t1, 0x12($t7)
  sw    $t1, 0x4c($sp)
  lw    $t3, 0xc($a1)
  sw    $t3, 0x48($sp)
  lw    $t4, 8($a2)
  move  $a2, $zero
  beqz  $t4, .L7F06DBC0
   sw    $t4, 0x1c($sp)
  move  $a0, $a1
  jal   sub_GAME_7F06C660
   move  $a1, $t4
  b     .L7F06DBC8
   sw    $v0, 0x9c($sp)
.L7F06DBC0:
  lw    $t6, ($a0)
  sw    $t6, 0x9c($sp)
.L7F06DBC8:
  lw    $t7, 0x9c($sp)
  lw    $t1, 0x54($sp)
  lw    $a0, 0xa0($sp)
  beqz  $t7, .L7F06DC34
   sll   $t3, $t1, 6
  lw    $a0, 0xa0($sp)
  lw    $a1, 0xb4($sp)
  jal   sub_GAME_7F05B9B4
   addiu $a2, $sp, 0x58
  lw    $t9, 0x54($sp)
  lw    $t8, 0x48($sp)
  lw    $a0, 0x9c($sp)
  sll   $t0, $t9, 6
  addu  $a2, $t0, $t8
  sw    $a2, 0x1c($sp)
  jal   sub_GAME_7F05818C
   addiu $a1, $sp, 0x58
  lui   $v0, %hi(D_80036090)
  lw    $v0, %lo(D_80036090)($v0)
  lw    $a2, 0x1c($sp)
  lw    $a0, 0x54($sp)
  beql  $v0, $zero, .L7F06DC48
   lw    $t2, 0xa4($sp)
  jalr  $v0
  move  $a1, $a2
  b     .L7F06DC48
   lw    $t2, 0xa4($sp)
.L7F06DC34:
  lw    $t4, 0x48($sp)
  lw    $a1, 0xb4($sp)
  jal   sub_GAME_7F05B9B4
   addu  $a2, $t3, $t4
  lw    $t2, 0xa4($sp)
.L7F06DC48:
  lw    $a0, 0xb4($sp)
  lui   $a1, 0x3f00
  andi  $t5, $t2, 0x100
  beql  $t5, $zero, .L7F06DCBC
   lw    $t4, 0xa4($sp)
  jal   sub_GAME_7F05BC68
   addiu $a2, $sp, 0x2c
  lw    $t6, 0x9c($sp)
  lw    $t8, 0x50($sp)
  addiu $a1, $sp, 0x2c
  beqz  $t6, .L7F06DCA8
   sll   $t1, $t8, 6
  lw    $a0, 0xa0($sp)
  jal   sub_GAME_7F05B9B4
   addiu $a2, $sp, 0x58
  lw    $t7, 0x50($sp)
  lw    $t0, 0x48($sp)
  lw    $a0, 0x9c($sp)
  sll   $t9, $t7, 6
  addiu $a1, $sp, 0x58
  jal   sub_GAME_7F05818C
   addu  $a2, $t9, $t0
  b     .L7F06DCBC
   lw    $t4, 0xa4($sp)
.L7F06DCA8:
  lw    $t3, 0x48($sp)
  lw    $a0, 0xa0($sp)
  jal   sub_GAME_7F05B9B4
   addu  $a2, $t1, $t3
  lw    $t4, 0xa4($sp)
.L7F06DCBC:
  lw    $t5, 0x9c($sp)
  andi  $t2, $t4, 0x200
  beql  $t2, $zero, .L7F06DDF8
   lw    $ra, 0x14($sp)
  beqz  $t5, .L7F06DCE0
   lw    $t7, 0x4c($sp)
  addiu $t6, $sp, 0x58
  b     .L7F06DCF0
   sw    $t6, 0x28($sp)
.L7F06DCE0:
  lw    $t0, 0x48($sp)
  sll   $t9, $t7, 6
  addu  $t8, $t9, $t0
  sw    $t8, 0x28($sp)
.L7F06DCF0:
  lw    $t1, 0xb4($sp)
  jal   sub_GAME_7F05ACB0
   lwc1  $f12, ($t1)
  add.s $f2, $f0, $f0
  lui   $at, %hi(D_80054BDC)
  lwc1  $f4, %lo(D_80054BDC)($at)
  lui   $at, %hi(D_80054BE0)
  lw    $a1, 0x28($sp)
  c.lt.s $f2, $f4
  nop   
  bc1f  .L7F06DD38
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  mul.s $f12, $f2, $f6
  b     .L7F06DD58
   nop   
.L7F06DD38:
  lwc1  $f8, %lo(D_80054BE0)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  sub.s $f10, $f8, $f2
  lui   $at, %hi(D_80054BE4)
  lwc1  $f4, %lo(D_80054BE4)($at)
  mul.s $f18, $f10, $f16
  sub.s $f12, $f4, $f18
.L7F06DD58:
  jal   sub_GAME_7F0585FC
   swc1  $f12, 0x24($sp)
  lui   $at, %hi(D_80054BE8)
  lwc1  $f12, 0x24($sp)
  lwc1  $f6, %lo(D_80054BE8)($at)
  lui   $at, %hi(D_80054BEC)
  c.le.s $f6, $f12
  nop   
  bc1f  .L7F06DD88
   nop   
  lwc1  $f8, %lo(D_80054BEC)($at)
  sub.s $f12, $f8, $f12
.L7F06DD88:
  lui    $at, %hi(D_80054BF0)
  lwc1  $f10, %lo(D_80054BF0)($at)
  li    $at, 0x3FC00000 # 1.500000
  c.lt.s $f12, $f10
  nop   
  bc1fl .L7F06DDB8
   mtc1  $at, $f12
  jal   sqrt_tan_angle_plus_one
   nop   
  b     .L7F06DDBC
   mov.s $f12, $f0
  mtc1  $at, $f12
.L7F06DDB8:
  nop   
.L7F06DDBC:
  jal   sub_GAME_7F058A4C
   lw    $a1, 0x28($sp)
  lw    $a0, 0xa0($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x28($sp)
  lw    $t3, 0x9c($sp)
  lw    $t4, 0x4c($sp)
  lw    $t5, 0x48($sp)
  beqz  $t3, .L7F06DDF4
   move  $a0, $t3
  sll   $t2, $t4, 6
  addu  $a2, $t2, $t5
  jal   sub_GAME_7F05818C
   lw    $a1, 0x28($sp)
.L7F06DDF4:
  lw    $ra, 0x14($sp)
.L7F06DDF8:
  addiu $sp, $sp, 0xa8
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06DE04
  andi  $t7, $a2, 7
  li    $t8, 8
  subu  $t1, $t8, $t7
  andi  $t2, $a1, 0xff
  andi  $t9, $t1, 0xff
  srl   $a3, $a2, 3
  slt   $at, $t2, $t9
  sw    $a1, 4($sp)
  move  $v1, $zero
  andi  $v0, $t2, 0xff
  addu  $a0, $a0, $a3
  bnez  $at, .L7F06DE80
   andi  $t0, $t1, 0xff
  move  $a1, $v0
.L7F06DE3C:
  lbu   $t4, ($a0)
  li    $t5, 1
  sllv  $t6, $t5, $t0
  addiu $t7, $t6, -1
  subu  $v0, $a1, $t0
  and   $t8, $t4, $t7
  andi  $a1, $v0, 0xff
  andi  $t9, $t8, 0xffff
  sllv  $t3, $t9, $a1
  or    $v1, $v1, $t3
  andi  $t5, $v1, 0xffff
  slti  $at, $a1, 8
  move  $v0, $a1
  move  $v1, $t5
  addiu $a0, $a0, 1
  beqz  $at, .L7F06DE3C
   li    $t0, 8
.L7F06DE80:
  blez  $v0, .L7F06DEAC
   subu  $t4, $t0, $v0
  lbu   $t6, ($a0)
  li    $t8, 1
  sllv  $t9, $t8, $v0
  addiu $t3, $t9, -1
  srav  $t7, $t6, $t4
  and   $t5, $t7, $t3
  or    $v1, $v1, $t5
  andi  $t6, $v1, 0xffff
  move  $v1, $t6
.L7F06DEAC:
  li    $t4, 16
  subu  $t8, $t4, $t2
  sllv  $v1, $v1, $t8
  jr    $ra
   andi  $v0, $v1, 0xffff
");

asm(R"
.late_rodata
glabel D_80054BF4
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06DEC0
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  beqz  $a1, .L7F06DF04
   lbu   $s0, 6($a3)
  lw    $t8, 4($a2)
  sll   $t9, $a0, 2
  subu  $t9, $t9, $a0
  sll   $t9, $t9, 1
  addu  $t0, $t8, $t9
  lhu   $t1, 4($t0)
  multu $t1, $s0
  mflo  $a2
  b     .L7F06DF34
   lw    $a0, 0x40($sp)
.L7F06DF04:
  lw    $t2, 0x38($sp)
  sll   $t4, $a0, 2
  subu  $t4, $t4, $a0
  lw    $t3, 4($t2)
  sll   $t4, $t4, 1
  addu  $t5, $t3, $t4
  lhu   $t6, 2($t5)
  multu $t6, $s0
  mflo  $a2
  nop   
  nop   
  lw    $a0, 0x40($sp)
.L7F06DF34:
  andi  $a1, $s0, 0xff
  jal   sub_GAME_7F06DE04
   sw    $a2, 0x2c($sp)
  lw    $a2, 0x2c($sp)
  sh    $v0, 0x24($sp)
  lw    $a0, 0x40($sp)
  addu  $a2, $a2, $s0
  sw    $a2, 0x2c($sp)
  jal   sub_GAME_7F06DE04
   andi  $a1, $s0, 0xff
  lw    $a2, 0x2c($sp)
  sh    $v0, 0x26($sp)
  lw    $a0, 0x40($sp)
  andi  $a1, $s0, 0xff
  jal   sub_GAME_7F06DE04
   addu  $a2, $a2, $s0
  lhu   $t7, 0x24($sp)
  lui   $at, %hi(D_80054BF4)
  lwc1  $f0, %lo(D_80054BF4)($at)
  mtc1  $t7, $f4
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f2
  lw    $v1, 0x44($sp)
  sh    $v0, 0x28($sp)
  bgez  $t7, .L7F06DFAC
   cvt.s.w $f6, $f4
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F06DFAC:
  mul.s $f10, $f6, $f0
  div.s $f16, $f10, $f2
  swc1  $f16, ($v1)
  lw    $t8, 0x34($sp)
  lhu   $v0, 0x26($sp)
  lhu   $t3, 0x26($sp)
  beql  $t8, $zero, .L7F06E03C
   mtc1  $t3, $f10
  beqz  $v0, .L7F06DFF4
   lui   $t9, 1
  subu  $t0, $t9, $v0
  mtc1  $t0, $f18
  nop   
  cvt.s.w $f4, $f18
  mul.s $f8, $f4, $f0
  div.s $f6, $f8, $f2
  b     .L7F06E000
   swc1  $f6, 4($v1)
.L7F06DFF4:
  mtc1  $zero, $f10
  nop   
  swc1  $f10, 4($v1)
.L7F06E000:
  lhu   $v0, 0x28($sp)
  lui   $t1, 1
  beqz  $v0, .L7F06E02C
   subu  $t2, $t1, $v0
  mtc1  $t2, $f16
  nop   
  cvt.s.w $f18, $f16
  mul.s $f4, $f18, $f0
  div.s $f8, $f4, $f2
  b     .L7F06E08C
   swc1  $f8, 8($v1)
.L7F06E02C:
  mtc1  $zero, $f6
  b     .L7F06E08C
   swc1  $f6, 8($v1)
  mtc1  $t3, $f10
.L7F06E03C:
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $t3, .L7F06E054
   cvt.s.w $f16, $f10
  mtc1  $at, $f18
  nop   
  add.s $f16, $f16, $f18
.L7F06E054:
  mul.s $f4, $f16, $f0
  li    $at, 0x4F800000 # 4294967296.000000
  div.s $f8, $f4, $f2
  swc1  $f8, 4($v1)
  lhu   $t4, 0x28($sp)
  mtc1  $t4, $f6
  bgez  $t4, .L7F06E080
   cvt.s.w $f10, $f6
  mtc1  $at, $f18
  nop   
  add.s $f10, $f10, $f18
.L7F06E080:
  mul.s $f16, $f10, $f0
  div.s $f4, $f16, $f2
  swc1  $f4, 8($v1)
.L7F06E08C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel process_02_position
  addiu $sp, $sp, -0x98
  sw    $ra, 0x24($sp)
  sw    $s0, 0x20($sp)
  sw    $a0, 0x98($sp)
  sw    $a2, 0xa0($sp)
  lui   $t8, %hi(D_80036094) 
  lw    $v0, 4($a2)
  lw    $t7, 8($a1)
  addiu $t8, %lo(D_80036094) # addiu $t8, $t8, 0x6094
  lw    $at, ($t8)
  lhu   $a0, 0xc($v0)
  lw    $a2, 4($t7)
  addiu $v1, $sp, 0x80
  sw    $at, ($v1)
  lw    $t1, 4($t8)
  move  $s0, $a1
  sw    $t1, 4($v1)
  lw    $at, 8($t8)
  sw    $at, 8($v1)
  lw    $t2, 0x34($s0)
  lw    $a3, 0x20($s0)
  lb    $a1, 0x24($a1)
  sw    $v1, 0x14($sp)
  sw    $a0, 0x90($sp)
  sw    $a2, 0x8c($sp)
  jal   sub_GAME_7F06DEC0
   sw    $t2, 0x10($sp)
  mtc1  $zero, $f4
  lwc1  $f6, 0x2c($s0)
  lui   $t3, %hi(D_800360A0) 
  addiu $t3, %lo(D_800360A0) # addiu $t3, $t3, 0x60a0
  c.eq.s $f4, $f6
  nop   
  bc1tl .L7F06E17C
   mtc1  $zero, $f8
  lw    $at, ($t3)
  addiu $v0, $sp, 0x74
  sw    $at, ($v0)
  lw    $t5, 4($t3)
  sw    $t5, 4($v0)
  lw    $at, 8($t3)
  sw    $at, 8($v0)
  lw    $t6, 0x38($s0)
  lw    $a3, 0x20($s0)
  lb    $a1, 0x24($s0)
  sw    $v0, 0x14($sp)
  lw    $a2, 0x8c($sp)
  lw    $a0, 0x90($sp)
  jal   sub_GAME_7F06DEC0
   sw    $t6, 0x10($sp)
  addiu $a0, $sp, 0x80
  addiu $a1, $sp, 0x74
  jal   sub_GAME_7F06D160
   lw    $a2, 0x2c($s0)
  mtc1  $zero, $f8
.L7F06E17C:
  lwc1  $f10, 0x84($s0)
  lui   $t7, %hi(D_800360AC) 
  addiu $t7, %lo(D_800360AC) # addiu $t7, $t7, 0x60ac
  c.eq.s $f8, $f10
  lw    $a0, 0x98($sp)
  move  $a1, $s0
  lw    $a2, 0xa0($sp)
  bc1t  .L7F06E29C
   nop   
  lw    $at, ($t7)
  addiu $v0, $sp, 0x68
  sw    $at, ($v0)
  lw    $t9, 4($t7)
  sw    $t9, 4($v0)
  lw    $at, 8($t7)
  sw    $at, 8($v0)
  lw    $t8, 0x64($s0)
  lw    $a3, 0x54($s0)
  lb    $a1, 0x25($s0)
  sw    $v0, 0x14($sp)
  lw    $a2, 0x8c($sp)
  lw    $a0, 0x90($sp)
  jal   sub_GAME_7F06DEC0
   sw    $t8, 0x10($sp)
  mtc1  $zero, $f16
  lwc1  $f18, 0x5c($s0)
  lui   $t1, %hi(D_800360B8) 
  addiu $t1, %lo(D_800360B8) # addiu $t1, $t1, 0x60b8
  c.eq.s $f16, $f18
  nop   
  bc1tl .L7F06E24C
   addiu $a0, $sp, 0x80
  lw    $at, ($t1)
  addiu $v0, $sp, 0x2c
  sw    $at, ($v0)
  lw    $t4, 4($t1)
  sw    $t4, 4($v0)
  lw    $at, 8($t1)
  sw    $at, 8($v0)
  lw    $t3, 0x68($s0)
  lw    $a3, 0x54($s0)
  lb    $a1, 0x25($s0)
  sw    $v0, 0x14($sp)
  lw    $a2, 0x8c($sp)
  lw    $a0, 0x90($sp)
  jal   sub_GAME_7F06DEC0
   sw    $t3, 0x10($sp)
  addiu $a0, $sp, 0x68
  addiu $a1, $sp, 0x2c
  jal   sub_GAME_7F06D160
   lw    $a2, 0x5c($s0)
  addiu $a0, $sp, 0x80
.L7F06E24C:
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x58
  addiu $a0, $sp, 0x68
  jal   sub_GAME_7F05B3F4
   addiu $a1, $sp, 0x48
  addiu $a0, $sp, 0x58
  jal   sub_GAME_7F05BE10
   addiu $a1, $sp, 0x48
  addiu $a0, $sp, 0x58
  addiu $a1, $sp, 0x48
  lw    $a2, 0x84($s0)
  jal   sub_GAME_7F05BA08
   addiu $a3, $sp, 0x38
  lw    $a0, 0x98($sp)
  move  $a1, $s0
  lw    $a2, 0xa0($sp)
  jal   sub_GAME_7F06DB5C
   addiu $a3, $sp, 0x38
  b     .L7F06E2A8
   lw    $ra, 0x24($sp)
.L7F06E29C:
  jal   sub_GAME_7F06D8B0
   addiu $a3, $sp, 0x80
  lw    $ra, 0x24($sp)
.L7F06E2A8:
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0x98
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054BF8
.word 0x40490fdb /*3.1415927*/
glabel D_80054BFC
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C00
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C04
.word 0x40490fdb /*3.1415927*/
glabel D_80054C08
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C0C
.word 0x3f63dec6 /*0.890118*/
.text
glabel sub_GAME_7F06E2B8
  addiu $sp, $sp, -0xa0
  sw    $ra, 0x1c($sp)
  sdc1  $f20, 0x10($sp)
  sw    $a1, 0xa4($sp)
  lhu   $t6, ($a2)
  mtc1  $a3, $f20
  sw    $t6, 0x9c($sp)
  lw    $t7, 4($a2)
  sw    $t7, 0x98($sp)
  lh    $t9, 0x10($t7)
  lh    $v1, 0xe($t7)
  sw    $t9, 0x48($sp)
  lh    $t0, 0x12($t7)
  sw    $t0, 0x44($sp)
  lw    $t2, 0xc($a1)
  sw    $t2, 0x40($sp)
  lw    $a3, 8($a2)
  move  $a2, $zero
  beql  $a3, $zero, .L7F06E328
   lw    $t3, ($a0)
  move  $a0, $a1
  move  $a1, $a3
  jal   sub_GAME_7F06C660
   sw    $v1, 0x4c($sp)
  lw    $v1, 0x4c($sp)
  b     .L7F06E32C
   sw    $v0, 0x94($sp)
  lw    $t3, ($a0)
.L7F06E328:
  sw    $t3, 0x94($sp)
.L7F06E32C:
  lw    $t4, 0x94($sp)
  lw    $a0, 0x98($sp)
  sll   $t7, $v1, 6
  beqz  $t4, .L7F06E378
   lw    $t9, 0x40($sp)
  mfc1  $a1, $f20
  lw    $a0, 0x98($sp)
  addiu $a2, $sp, 0x50
  jal   sub_GAME_7F0584D0
   sw    $v1, 0x4c($sp)
  lw    $v1, 0x4c($sp)
  lw    $t6, 0x40($sp)
  lw    $a0, 0x94($sp)
  sll   $t5, $v1, 6
  addiu $a1, $sp, 0x50
  jal   sub_GAME_7F05818C
   addu  $a2, $t5, $t6
  b     .L7F06E388
   lw    $t8, 0x9c($sp)
.L7F06E378:
  mfc1  $a1, $f20
  jal   sub_GAME_7F0584D0
   addu  $a2, $t7, $t9
  lw    $t8, 0x9c($sp)
.L7F06E388:
  lui   $at, %hi(D_80054BF8)
  lw    $t2, 0x94($sp)
  andi  $v0, $t8, 0x100
  bnez  $v0, .L7F06E3A4
   andi  $v1, $t8, 0x200
  beqz  $v1, .L7F06E3FC
   nop   
.L7F06E3A4:
  lwc1  $f4, %lo(D_80054BF8)($at)
  lw    $v1, 0x9c($sp)
  lui   $at, %hi(D_80054BFC)
  c.lt.s $f20, $f4
  andi  $t0, $v1, 0x200
  move  $v1, $t0
  bc1f  .L7F06E3DC
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f6
  nop   
  mul.s $f20, $f20, $f6
  b     .L7F06E3FC
   nop   
.L7F06E3DC:
  lwc1  $f8, %lo(D_80054BFC)($at)
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f16
  sub.s $f10, $f8, $f20
  lui   $at, %hi(D_80054C00)
  lwc1  $f4, %lo(D_80054C00)($at)
  mul.s $f18, $f10, $f16
  sub.s $f20, $f4, $f18
.L7F06E3FC:
  beqz  $v0, .L7F06E464
   nop   
  beqz  $t2, .L7F06E444
   lw    $a0, 0x98($sp)
  mfc1  $a1, $f20
  lw    $a0, 0x98($sp)
  addiu $a2, $sp, 0x50
  jal   sub_GAME_7F0584D0
   sw    $v1, 0x24($sp)
  lw    $t1, 0x48($sp)
  lw    $t4, 0x40($sp)
  lw    $a0, 0x94($sp)
  sll   $t3, $t1, 6
  addiu $a1, $sp, 0x50
  jal   sub_GAME_7F05818C
   addu  $a2, $t3, $t4
  b     .L7F06E464
   lw    $v1, 0x24($sp)
.L7F06E444:
  lw    $t5, 0x48($sp)
  lw    $t7, 0x40($sp)
  mfc1  $a1, $f20
  sll   $t6, $t5, 6
  sw    $v1, 0x24($sp)
  jal   sub_GAME_7F0584D0
   addu  $a2, $t6, $t7
  lw    $v1, 0x24($sp)
.L7F06E464:
  beqz  $v1, .L7F06E52C
   lw    $t9, 0x94($sp)
  beqz  $t9, .L7F06E480
   mov.s $f12, $f20
  addiu $t8, $sp, 0x50
  b     .L7F06E494
   sw    $t8, 0x30($sp)
.L7F06E480:
  lw    $t0, 0x44($sp)
  lw    $t1, 0x40($sp)
  sll   $t2, $t0, 6
  addu  $t3, $t2, $t1
  sw    $t3, 0x30($sp)
.L7F06E494:
  jal   sub_GAME_7F0585FC
   lw    $a1, 0x30($sp)
  lui   $at, %hi(D_80054C04)
  lwc1  $f6, %lo(D_80054C04)($at)
  lui   $at, %hi(D_80054C08)
  c.le.s $f6, $f20
  nop   
  bc1f  .L7F06E4C0
   nop   
  lwc1  $f8, %lo(D_80054C08)($at)
  sub.s $f20, $f8, $f20
.L7F06E4C0:
  lui    $at, %hi(D_80054C0C)
  lwc1  $f10, %lo(D_80054C0C)($at)
  li    $at, 0x3FC00000 # 1.500000
  c.lt.s $f20, $f10
  nop   
  bc1fl .L7F06E4F0
   mtc1  $at, $f12
  jal   sqrt_tan_angle_plus_one
   mov.s $f12, $f20
  b     .L7F06E4F4
   mov.s $f12, $f0
  mtc1  $at, $f12
.L7F06E4F0:
  nop   
.L7F06E4F4:
  jal   sub_GAME_7F058A4C
   lw    $a1, 0x30($sp)
  lw    $a0, 0x98($sp)
  jal   copies_first_3_floats_from_a0_to_a1_plus_0x30
   lw    $a1, 0x30($sp)
  lw    $t4, 0x94($sp)
  lw    $t5, 0x44($sp)
  lw    $t7, 0x40($sp)
  beqz  $t4, .L7F06E52C
   move  $a0, $t4
  sll   $t6, $t5, 6
  addu  $a2, $t6, $t7
  jal   sub_GAME_7F05818C
   lw    $a1, 0x30($sp)
.L7F06E52C:
  lw    $ra, 0x1c($sp)
  ldc1  $f20, 0x10($sp)
  addiu $sp, $sp, 0xa0
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054C10
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C14
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06E540
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  sw    $a1, 0x2c($sp)
  sw    $a2, 0x30($sp)
  lbu   $t6, 6($a3)
  mtc1  $zero, $f2
  beqz  $a1, .L7F06E58C
   sb    $t6, 0x1f($sp)
  lw    $t9, 4($a2)
  sll   $t0, $a0, 2
  subu  $t0, $t0, $a0
  sll   $t0, $t0, 1
  addu  $t1, $t9, $t0
  lhu   $t2, 4($t1)
  andi  $t3, $t6, 0xff
  multu $t2, $t3
  mflo  $a2
  b     .L7F06E5C0
   lw    $a0, 0x38($sp)
.L7F06E58C:
  lw    $t4, 0x30($sp)
  sll   $t6, $a0, 2
  subu  $t6, $t6, $a0
  lw    $t5, 4($t4)
  sll   $t6, $t6, 1
  lbu   $t9, 0x1f($sp)
  addu  $t7, $t5, $t6
  lhu   $t8, 2($t7)
  multu $t8, $t9
  mflo  $a2
  nop   
  nop   
  lw    $a0, 0x38($sp)
.L7F06E5C0:
  lbu   $a1, 0x1f($sp)
  jal   sub_GAME_7F06DE04
   swc1  $f2, 0x18($sp)
  lw    $t0, 0x2c($sp)
  lwc1  $f2, 0x18($sp)
  lw    $ra, 0x14($sp)
  beqz  $t0, .L7F06E610
   addiu $sp, $sp, 0x28
  beqz  $v0, .L7F06E644
   lui   $t1, 1
  subu  $t2, $t1, $v0
  mtc1  $t2, $f4
  lui   $at, %hi(D_80054C10)
  lwc1  $f8, %lo(D_80054C10)($at)
  cvt.s.w $f6, $f4
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f16
  mul.s $f10, $f6, $f8
  b     .L7F06E644
   div.s $f2, $f10, $f16
.L7F06E610:
  mtc1  $v0, $f18
  li    $at, 0x4F800000 # 4294967296.000000
  bgez  $v0, .L7F06E62C
   cvt.s.w $f4, $f18
  mtc1  $at, $f6
  nop   
  add.s $f4, $f4, $f6
.L7F06E62C:
  lui   $at, %hi(D_80054C14)
  lwc1  $f8, %lo(D_80054C14)($at)
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f16
  mul.s $f10, $f4, $f8
  div.s $f2, $f10, $f16
.L7F06E644:
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel process_03_unknown
  addiu $sp, $sp, -0x50
  sw    $s0, 0x28($sp)
  sw    $ra, 0x34($sp)
  sw    $s2, 0x30($sp)
  sw    $s1, 0x2c($sp)
  sdc1  $f20, 0x20($sp)
  sw    $a0, 0x50($sp)
  sw    $a2, 0x58($sp)
  lw    $v0, 4($a2)
  lw    $t7, 8($a1)
  move  $s0, $a1
  lw    $t8, 0x34($s0)
  lhu   $s1, 0xc($v0)
  lw    $s2, 4($t7)
  lw    $a3, 0x20($s0)
  lb    $a1, 0x24($a1)
  sw    $t8, 0x10($sp)
  move  $a0, $s1
  jal   sub_GAME_7F06E540
   move  $a2, $s2
  mtc1  $zero, $f4
  lwc1  $f6, 0x2c($s0)
  mov.s $f20, $f0
  move  $a0, $s1
  c.eq.s $f4, $f6
  move  $a2, $s2
  bc1tl .L7F06E6E8
   mtc1  $zero, $f8
  lw    $t9, 0x38($s0)
  lb    $a1, 0x24($s0)
  lw    $a3, 0x20($s0)
  jal   sub_GAME_7F06E540
   sw    $t9, 0x10($sp)
  mov.s $f12, $f20
  mov.s $f14, $f0
  jal   sub_GAME_7F06D0CC
   lw    $a2, 0x2c($s0)
  mov.s $f20, $f0
  mtc1  $zero, $f8
.L7F06E6E8:
  lwc1  $f10, 0x84($s0)
  move  $a0, $s1
  move  $a2, $s2
  c.eq.s $f8, $f10
  nop   
  bc1tl .L7F06E77C
   mfc1  $a3, $f20
  lw    $t0, 0x64($s0)
  lb    $a1, 0x25($s0)
  lw    $a3, 0x54($s0)
  jal   sub_GAME_7F06E540
   sw    $t0, 0x10($sp)
  swc1  $f0, 0x38($sp)
  lwc1  $f18, 0x5c($s0)
  mtc1  $zero, $f16
  move  $a0, $s1
  move  $a2, $s2
  c.eq.s $f16, $f18
  nop   
  bc1tl .L7F06E768
   mov.s $f12, $f20
  lw    $t1, 0x68($s0)
  lb    $a1, 0x25($s0)
  lw    $a3, 0x54($s0)
  jal   sub_GAME_7F06E540
   sw    $t1, 0x10($sp)
  lwc1  $f12, 0x38($sp)
  mov.s $f14, $f0
  jal   sub_GAME_7F06D0CC
   lw    $a2, 0x5c($s0)
  swc1  $f0, 0x38($sp)
  mov.s $f12, $f20
.L7F06E768:
  lwc1  $f14, 0x38($sp)
  jal   sub_GAME_7F06D0CC
   lw    $a2, 0x84($s0)
  mov.s $f20, $f0
  mfc1  $a3, $f20
.L7F06E77C:
  lw    $a0, 0x50($sp)
  move  $a1, $s0
  jal   sub_GAME_7F06E2B8
   lw    $a2, 0x58($sp)
  lw    $ra, 0x34($sp)
  ldc1  $f20, 0x20($sp)
  lw    $s0, 0x28($sp)
  lw    $s1, 0x2c($sp)
  lw    $s2, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x50
");

asm(R"
glabel process_15_subposition
  addiu $sp, $sp, -0x70
  sw    $ra, 0x14($sp)
  sw    $a1, 0x74($sp)
  lw    $t6, 4($a2)
  sw    $t6, 0x6c($sp)
  lw    $a3, 8($a2)
  lw    $t0, 0xc($a1)
  move  $a2, $zero
  beqz  $a3, .L7F06E7F4
   lh    $v1, 0xc($t6)
  move  $a0, $a1
  move  $a1, $a3
  sw    $v1, 0x24($sp)
  jal   sub_GAME_7F06C660
   sw    $t0, 0x20($sp)
  lw    $v1, 0x24($sp)
  lw    $t0, 0x20($sp)
  b     .L7F06E7F8
   move  $a3, $v0
.L7F06E7F4:
  lw    $a3, ($a0)
.L7F06E7F8:
  beqz  $a3, .L7F06E83C
   lw    $a0, 0x6c($sp)
  lw    $a0, 0x6c($sp)
  addiu $a1, $sp, 0x28
  sw    $v1, 0x24($sp)
  sw    $a3, 0x68($sp)
  jal   init_something_copy_posdata_to_it
   sw    $t0, 0x20($sp)
  lw    $v1, 0x24($sp)
  lw    $t0, 0x20($sp)
  lw    $a0, 0x68($sp)
  sll   $t9, $v1, 6
  addiu $a1, $sp, 0x28
  jal   sub_GAME_7F05818C
   addu  $a2, $t9, $t0
  b     .L7F06E84C
   lw    $ra, 0x14($sp)
.L7F06E83C:
  sll   $t1, $v1, 6
  jal   init_something_copy_posdata_to_it
   addu  $a1, $t1, $t0
  lw    $ra, 0x14($sp)
.L7F06E84C:
  addiu $sp, $sp, 0x70
  jr    $ra
   nop   
");

asm(R"
glabel process_08_distance_triggers
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x30($sp)
  lw    $t6, 4($a1)
  move  $s0, $a1
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0x2c($sp)
  sw    $v0, 0x28($sp)
  lw    $a0, 0x30($sp)
  move  $a1, $s0
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lui   $t7, %hi(D_80036084) 
  lw    $t7, %lo(D_80036084)($t7)
  move  $v1, $v0
  beqz  $t7, .L7F06E8AC
   nop   
  mtc1  $zero, $f2
  b     .L7F06E8EC
   lw    $v0, 0x2c($sp)
.L7F06E8AC:
  jal   getPlayer_c_lodscalez
   sw    $v1, 0x24($sp)
  lui   $at, %hi(D_80036088)
  lw    $v1, 0x24($sp)
  lwc1  $f12, %lo(D_80036088)($at)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f4, 0x38($v1)
  c.eq.s $f8, $f12
  neg.s $f6, $f4
  mul.s $f2, $f0, $f6
  bc1tl .L7F06E8EC
   lw    $v0, 0x2c($sp)
  mul.s $f2, $f2, $f12
  nop   
  lw    $v0, 0x2c($sp)
.L7F06E8EC:
  lw    $t8, 0x30($sp)
  lwc1  $f0, ($v0)
  lwc1  $f12, 0x14($t8)
  mul.s $f10, $f0, $f12
  c.lt.s $f10, $f2
  nop   
  bc1tl .L7F06E928
   lwc1  $f18, 4($v0)
  mtc1  $zero, $f16
  nop   
  c.eq.s $f16, $f0
  nop   
  bc1fl .L7F06E954
   lw    $t2, 0x28($sp)
  lwc1  $f18, 4($v0)
.L7F06E928:
  lw    $t0, 0x28($sp)
  mul.s $f4, $f18, $f12
  c.le.s $f2, $f4
  nop   
  bc1f  .L7F06E950
   li    $t9, 1
  sw    $t9, ($t0)
  lw    $t1, 8($v0)
  b     .L7F06E95C
   sw    $t1, 0x14($s0)
.L7F06E950:
  lw    $t2, 0x28($sp)
.L7F06E954:
  sw    $zero, ($t2)
  sw    $zero, 0x14($s0)
.L7F06E95C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06E970
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t6, 4($a1)
  sw    $a1, 0x24($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0x1c($sp)
  lw    $t7, ($v0)
  lw    $a1, 0x24($sp)
  lw    $t8, 0x1c($sp)
  beql  $t7, $zero, .L7F06E9AC
   sw    $zero, 0x14($a1)
  lw    $t9, 8($t8)
  b     .L7F06E9AC
   sw    $t9, 0x14($a1)
  sw    $zero, 0x14($a1)
.L7F06E9AC:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel process_12_handle_switch
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  lw    $t6, 4($a1)
  sw    $a1, 0x24($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0x1c($sp)
  lw    $t7, ($v0)
  lw    $a1, 0x24($sp)
  lw    $t8, 0x1c($sp)
  beql  $t7, $zero, .L7F06E9F8
   sw    $zero, 0x14($a1)
  lw    $t9, ($t8)
  b     .L7F06E9F8
   sw    $t9, 0x14($a1)
  sw    $zero, 0x14($a1)
.L7F06E9F8:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel process_17_pointer_to_head
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a1, 0x1c($sp)
  lw    $a0, ($v0)
  lw    $a1, 0x1c($sp)
  beql  $a0, $zero, .L7F06EA48
   lw    $ra, 0x14($sp)
  lw    $v1, ($a0)
  beqz  $v1, .L7F06EA44
   sw    $v1, 0x14($a1)
  sw    $a1, 8($v1)
.L7F06EA38:
  lw    $v1, 0xc($v1)
  bnezl $v1, .L7F06EA38
   sw    $a1, 8($v1)
.L7F06EA44:
  lw    $ra, 0x14($sp)
.L7F06EA48:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06EA54
  beqz  $a1, .L7F06EA68
   lw    $v0, 4($a0)
  lw    $v1, 0x18($v0)
  b     .L7F06EA70
   lw    $a1, 0x1c($v0)
.L7F06EA68:
  lw    $v1, 0x1c($v0)
  lw    $a1, 0x18($v0)
.L7F06EA70:
  beqz  $v1, .L7F06EAFC
   nop   
  sw    $v1, 0x14($a0)
  lw    $a2, 0xc($v1)
  sw    $zero, 0x10($v1)
  move  $v0, $v1
  beqz  $a2, .L7F06EAB4
   nop   
  beq   $a1, $a2, .L7F06EAB4
   nop   
  lw    $a0, 0xc($v0)
  move  $v0, $a0
.L7F06EAA0:
  lw    $a0, 0xc($a0)
  beqz  $a0, .L7F06EAB4
   nop   
  bnel  $a1, $a0, .L7F06EAA0
   move  $v0, $a0
.L7F06EAB4:
  beqz  $a1, .L7F06EB08
   sw    $a1, 0xc($v0)
  lw    $a0, 0xc($a1)
  sw    $v0, 0x10($a1)
  move  $v0, $a1
  beqz  $a0, .L7F06EAF4
   nop   
  beq   $v1, $a0, .L7F06EAF4
   nop   
  lw    $a0, 0xc($a1)
  move  $v0, $a0
.L7F06EAE0:
  lw    $a0, 0xc($a0)
  beqz  $a0, .L7F06EAF4
   nop   
  bnel  $v1, $a0, .L7F06EAE0
   move  $v0, $a0
.L7F06EAF4:
  jr    $ra
   sw    $zero, 0xc($v0)

.L7F06EAFC:
  beqz  $a1, .L7F06EB08
   sw    $a1, 0x14($a0)
  sw    $zero, 0x10($a1)
.L7F06EB08:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06EB10
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a1, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  jal   sub_GAME_7F06EA54
   lw    $a1, ($v0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel process_09_head_hat_placement_interlink
  addiu $sp, $sp, -0x50
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x50($sp)
  lw    $s0, 4($a1)
  jal   extract_id_from_object_structure_microcode
   sw    $a1, 0x54($sp)
  sw    $v0, 0x48($sp)
  lw    $a0, 0x50($sp)
  lw    $a1, 0x54($sp)
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  lh    $v1, 0x20($s0)
  move  $a0, $v0
  li    $at, 2
  bnez  $v1, .L7F06EBAC
   nop   
  lwc1  $f4, 0xc($s0)
  addiu $a1, $sp, 0x38
  swc1  $f4, 0x38($sp)
  lwc1  $f6, 0x10($s0)
  swc1  $f6, 0x3c($sp)
  lwc1  $f8, 0x14($s0)
  sw    $a0, 0x44($sp)
  jal   sub_GAME_7F0583D8
   swc1  $f8, 0x40($sp)
  b     .L7F06EC64
   lw    $a0, 0x44($sp)
.L7F06EBAC:
  bnel  $v1, $at, .L7F06EBEC
   li    $at, 3
  lwc1  $f10, 0x10($s0)
  lwc1  $f16, 0x10($v0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x38($sp)
  lwc1  $f4, 0x10($s0)
  lwc1  $f6, 0x14($v0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x3c($sp)
  lwc1  $f16, 0x18($v0)
  lwc1  $f10, 0x10($s0)
  mul.s $f18, $f10, $f16
  b     .L7F06EC64
   swc1  $f18, 0x40($sp)
  li    $at, 3
.L7F06EBEC:
  bnel  $v1, $at, .L7F06EC2C
   li    $at, 1
  lwc1  $f4, 0x14($s0)
  lwc1  $f6, 0x20($v0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x38($sp)
  lwc1  $f10, 0x14($s0)
  lwc1  $f16, 0x24($v0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x3c($sp)
  lwc1  $f6, 0x28($v0)
  lwc1  $f4, 0x14($s0)
  mul.s $f8, $f4, $f6
  b     .L7F06EC64
   swc1  $f8, 0x40($sp)
  li    $at, 1
.L7F06EC2C:
  bnel  $v1, $at, .L7F06EC68
   lwc1  $f4, ($s0)
  lwc1  $f10, 0xc($s0)
  lwc1  $f16, ($v0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x38($sp)
  lwc1  $f4, 0xc($s0)
  lwc1  $f6, 4($v0)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0x3c($sp)
  lwc1  $f16, 8($v0)
  lwc1  $f10, 0xc($s0)
  mul.s $f18, $f10, $f16
  swc1  $f18, 0x40($sp)
.L7F06EC64:
  lwc1  $f4, ($s0)
.L7F06EC68:
  addiu $a1, $sp, 0x2c
  swc1  $f4, 0x2c($sp)
  lwc1  $f6, 4($s0)
  swc1  $f6, 0x30($sp)
  lwc1  $f8, 8($s0)
  jal   sub_GAME_7F058474
   swc1  $f8, 0x34($sp)
  lwc1  $f10, 0x38($sp)
  lwc1  $f16, 0x2c($sp)
  lwc1  $f4, 0x3c($sp)
  lwc1  $f6, 0x30($sp)
  mul.s $f18, $f10, $f16
  lwc1  $f16, 0x34($sp)
  lw    $t7, 0x48($sp)
  mul.s $f8, $f4, $f6
  lwc1  $f4, 0x40($sp)
  lw    $t8, 0x48($sp)
  mul.s $f6, $f16, $f4
  add.s $f10, $f18, $f8
  mtc1  $zero, $f18
  add.s $f0, $f6, $f10
  c.lt.s $f0, $f18
  nop   
  bc1f  .L7F06ECD4
   li    $t6, 1
  b     .L7F06ECD8
   sw    $t6, ($t7)
.L7F06ECD4:
  sw    $zero, ($t8)
.L7F06ECD8:
  lw    $a0, 0x50($sp)
  jal   sub_GAME_7F06EB10
   lw    $a1, 0x54($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x50
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054C18
.word 0x40c90fdb /*6.2831855*/
glabel D_80054C1C
.word 0x40c90fdb /*6.2831855*/
.text
glabel process_07_unknown
  addiu $sp, $sp, -0x58
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0x58($sp)
  lw    $t6, 4($a1)
  move  $s0, $a1
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0x54($sp)
  sw    $v0, 0x50($sp)
  lw    $a0, 0x58($sp)
  move  $a1, $s0
  jal   sub_GAME_7F06C660
   move  $a2, $zero
  move  $s0, $v0
  lw    $a0, 0x58($sp)
  jal   sub_GAME_7F06C550
   addiu $a1, $sp, 0x38
  lwc1  $f4, 0x38($sp)
  lwc1  $f6, 0x10($s0)
  lwc1  $f10, 0x3c($sp)
  lwc1  $f16, 0x14($s0)
  mul.s $f8, $f4, $f6
  lwc1  $f6, 0x18($s0)
  mul.s $f18, $f10, $f16
  lwc1  $f10, 0x40($sp)
  mul.s $f16, $f6, $f10
  add.s $f4, $f8, $f18
  jal   sub_GAME_7F05ACB0
   add.s $f12, $f16, $f4
  swc1  $f0, 0x30($sp)
  jal   sinf
   mov.s $f12, $f0
  lwc1  $f8, 0x38($sp)
  lwc1  $f18, 0x20($s0)
  lwc1  $f10, 0x3c($sp)
  lwc1  $f16, 0x24($s0)
  mul.s $f6, $f8, $f18
  lwc1  $f18, 0x40($sp)
  mul.s $f4, $f10, $f16
  lwc1  $f10, 0x28($s0)
  mul.s $f16, $f18, $f10
  add.s $f8, $f6, $f4
  add.s $f6, $f8, $f16
  jal   sub_GAME_7F05ACB0
   div.s $f12, $f6, $f0
  lwc1  $f4, 0x38($sp)
  lwc1  $f18, ($s0)
  lwc1  $f8, 0x3c($sp)
  lwc1  $f16, 4($s0)
  mul.s $f10, $f4, $f18
  lwc1  $f18, 8($s0)
  mtc1  $zero, $f14
  mul.s $f6, $f8, $f16
  lwc1  $f8, 0x40($sp)
  mov.s $f12, $f0
  mul.s $f16, $f18, $f8
  add.s $f4, $f10, $f6
  lwc1  $f10, 0x30($sp)
  add.s $f2, $f16, $f4
  c.lt.s $f2, $f14
  nop   
  bc1f  .L7F06EE0C
   nop   
  c.lt.s $f14, $f0
  lui   $at, %hi(D_80054C18)
  bc1f  .L7F06EE0C
   nop   
  lwc1  $f2, %lo(D_80054C18)($at)
  sub.s $f12, $f2, $f0
.L7F06EE0C:
  lui   $at, %hi(D_80054C1C)
  lwc1  $f2, %lo(D_80054C1C)($at)
  li    $at, 0x42800000 # 64.000000
  mtc1  $at, $f6
  li    $at, 0x47800000 # 65536.000000
  mtc1  $at, $f4
  mul.s $f18, $f10, $f6
  lui   $t0, %hi(D_800360C4) 
  addiu $t0, %lo(D_800360C4) # addiu $t0, $t0, 0x60c4
  mul.s $f10, $f12, $f4
  lw    $t6, 0x54($sp)
  div.s $f8, $f18, $f2
  div.s $f6, $f10, $f2
  trunc.w.s $f16, $f8
  mfc1  $t8, $f16
  nop   
  sll   $t9, $t8, 2
  subu  $t9, $t9, $t8
  sll   $t9, $t9, 2
  addu  $v1, $t9, $t0
  lw    $t3, 4($v1)
  lw    $t4, 8($v1)
  lw    $t5, ($v1)
  lw    $t9, 0x50($sp)
  trunc.w.s $f18, $f6
  mfc1  $t2, $f18
  nop   
  addu  $v0, $t2, $t3
  srav  $v0, $v0, $t4
  addu  $a0, $t5, $v0
  addu  $t7, $t6, $a0
  lbu   $t8, 0x18($t7)
  sw    $t8, ($t9)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x58
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80054C20*/
glabel jpt_80054C20
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF2C
.word .L7F06EF04
.word .L7F06EF18
.word .L7F06EF4C
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EF4C
.word .L7F06EEFC
.word .L7F06EF4C
.word .L7F06EF40
/*.word .L7F06EF4C*/

.text
glabel sub_GAME_7F06EEA4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x2c($sp)
  lw    $s0, 0x14($a1)
  move  $s2, $a0
  beql  $s0, $zero, .L7F06EFB0
   lw    $ra, 0x24($sp)
  lhu   $v0, ($s0)
.L7F06EED0:
  li    $s1, 1
  andi  $t7, $v0, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x18
  beqz  $at, .L7F06EF4C
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80054C20)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80054C20)($at)
.L7F06EEF4:
  jr    $t8
   nop   
.L7F06EEFC:
  b     .L7F06EF4C
   move  $s1, $zero
.L7F06EF04:
  move  $a0, $s2
  jal   process_08_distance_triggers
   move  $a1, $s0
  b     .L7F06EF4C
   nop   
.L7F06EF18:
  move  $a0, $s2
  jal   process_09_head_hat_placement_interlink
   move  $a1, $s0
  b     .L7F06EF4C
   nop   
.L7F06EF2C:
  move  $a0, $s2
  jal   process_07_unknown
   move  $a1, $s0
  b     .L7F06EF4C
   nop   
.L7F06EF40:
  move  $a0, $s2
  jal   process_17_pointer_to_head
   move  $a1, $s0
def_7F06EEF4:
.L7F06EF4C:
  beqz  $s1, .L7F06EF68
   nop   
  lw    $v0, 0x14($s0)
  beqz  $v0, .L7F06EF68
   nop   
  b     .L7F06EFA4
   move  $s0, $v0
.L7F06EF68:
  beqz  $s0, .L7F06EFA4
   lw    $t9, 0x2c($sp)
  lw    $v1, 8($t9)
.L7F06EF74:
  bnel  $s0, $v1, .L7F06EF88
   lw    $v0, 0xc($s0)
  b     .L7F06EFA4
   move  $s0, $zero
  lw    $v0, 0xc($s0)
.L7F06EF88:
  beql  $v0, $zero, .L7F06EF9C
   lw    $s0, 8($s0)
  b     .L7F06EFA4
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F06EF9C:
  bnez  $s0, .L7F06EF74
   nop   
.L7F06EFA4:
  bnezl $s0, .L7F06EED0
   lhu   $v0, ($s0)
  lw    $ra, 0x24($sp)
.L7F06EFB0:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
.late_rodata
/*hack for above jtbl being too big*/
.word .L7F06EF4C

/*D:80054C80*/
glabel jpt_80054C80
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F03C
.word .L7F06F014
.word .L7F06F028
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
.word .L7F06F050
.word .L7F06F078
.word .L7F06F078
.word .L7F06F078
/*.word .L7F06F078*/
/*.word .L7F06F064*/
/*.word .L7F06F078*/

.text
glabel sub_GAME_7F06EFC4
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 8($a0)
  move  $s1, $a0
  lw    $s0, ($t6)
  beql  $s0, $zero, .L7F06F0C0
   lw    $ra, 0x1c($sp)
  lhu   $v0, ($s0)
.L7F06EFEC:
  andi  $t7, $v0, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x18
  beqz  $at, .L7F06F078
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80054C80)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80054C80)($at)
.L7F06F00C:
  jr    $t8
   nop   
.L7F06F014:
  move  $a0, $s1
  jal   process_08_distance_triggers
   move  $a1, $s0
  b     .L7F06F07C
   lw    $v0, 0x14($s0)
.L7F06F028:
  move  $a0, $s1
  jal   process_09_head_hat_placement_interlink
   move  $a1, $s0
  b     .L7F06F07C
   lw    $v0, 0x14($s0)
.L7F06F03C:
  move  $a0, $s1
  jal   process_07_unknown
   move  $a1, $s0
  b     .L7F06F07C
   lw    $v0, 0x14($s0)
.L7F06F050:
  move  $a0, $s1
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F06F07C
   lw    $v0, 0x14($s0)
.L7F06F064:
  move  $a0, $s1
  jal   process_17_pointer_to_head
   move  $a1, $s0
  b     .L7F06F07C
   lw    $v0, 0x14($s0)
def_7F06F00C:
.L7F06F078:
  lw    $v0, 0x14($s0)
.L7F06F07C:
  beqz  $v0, .L7F06F08C
   nop   
  b     .L7F06F0B4
   move  $s0, $v0
.L7F06F08C:
  beqz  $s0, .L7F06F0B4
   nop   
  lw    $v0, 0xc($s0)
.L7F06F098:
  beql  $v0, $zero, .L7F06F0AC
   lw    $s0, 8($s0)
  b     .L7F06F0B4
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F06F0AC:
  bnezl $s0, .L7F06F098
   lw    $v0, 0xc($s0)
.L7F06F0B4:
  bnezl $s0, .L7F06EFEC
   lhu   $v0, ($s0)
  lw    $ra, 0x1c($sp)
.L7F06F0C0:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
.late_rodata
/*hack for above jtbl*/
.word .L7F06F078
.word .L7F06F064
.word .L7F06F078

/*D:80054CE0*/
glabel jpt_80054CE0
.word .L7F06F128
.word .L7F06F140
.word .L7F06F158
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1B0
.word .L7F06F188
.word .L7F06F19C
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F1C4
.word .L7F06F1EC
.word .L7F06F1EC
.word .L7F06F170
.word .L7F06F1EC
.word .L7F06F1D8
.word .L7F06F1EC

.text
glabel sub_GAME_7F06F0D0
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 8($a1)
  move  $s1, $a1
  move  $s2, $a0
  lw    $s0, ($t6)
  beql  $s0, $zero, .L7F06F234
   lw    $ra, 0x24($sp)
  lhu   $v0, ($s0)
.L7F06F100:
  andi  $t7, $v0, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x18
  beqz  $at, .L7F06F1EC
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80054CE0)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80054CE0)($at)
.L7F06F120:
  jr    $t8
   nop   
.L7F06F128:
  move  $a0, $s2
  move  $a1, $s1
  jal   process_01_group_heading
   move  $a2, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F140:
  move  $a0, $s2
  move  $a1, $s1
  jal   process_02_position
   move  $a2, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F158:
  move  $a0, $s2
  move  $a1, $s1
  jal   process_03_unknown
   move  $a2, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F170:
  move  $a0, $s2
  move  $a1, $s1
  jal   process_15_subposition
   move  $a2, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F188:
  move  $a0, $s1
  jal   process_08_distance_triggers
   move  $a1, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F19C:
  move  $a0, $s1
  jal   process_09_head_hat_placement_interlink
   move  $a1, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F1B0:
  move  $a0, $s1
  jal   process_07_unknown
   move  $a1, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F1C4:
  move  $a0, $s1
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
.L7F06F1D8:
  move  $a0, $s1
  jal   process_17_pointer_to_head
   move  $a1, $s0
  b     .L7F06F1F0
   lw    $v0, 0x14($s0)
def_7F06F120:
.L7F06F1EC:
  lw    $v0, 0x14($s0)
.L7F06F1F0:
  beqz  $v0, .L7F06F200
   nop   
  b     .L7F06F228
   move  $s0, $v0
.L7F06F200:
  beqz  $s0, .L7F06F228
   nop   
  lw    $v0, 0xc($s0)
.L7F06F20C:
  beql  $v0, $zero, .L7F06F220
   lw    $s0, 8($s0)
  b     .L7F06F228
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F06F220:
  bnezl $s0, .L7F06F20C
   lw    $v0, 0xc($s0)
.L7F06F228:
  bnezl $s0, .L7F06F100
   lhu   $v0, ($s0)
  lw    $ra, 0x24($sp)
.L7F06F234:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel instcalcmatrices
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  bnez  $a1, .L7F06F274
   sw    $a1, 0x24($sp)
  lui   $a0, %hi(aInstcalcmatricesNoObjinst)
  jal   osSyncPrintf
   addiu $a0, %lo(aInstcalcmatricesNoObjinst) # addiu $a0, $a0, 0x4890
  jal   return_null
   nop   
.L7F06F274:
  lw    $t7, ($s0)
  lui   $a0, %hi(aInstcalcmatricesNoBasemtx)
  bnezl $t7, .L7F06F298
   lw    $v0, 0x10($s0)
  jal   osSyncPrintf
   addiu $a0, %lo(aInstcalcmatricesNoBasemtx) # addiu $a0, $a0, 0x48b0
  jal   return_null
   nop   
  lw    $v0, 0x10($s0)
.L7F06F298:
  lui   $a0, %hi(aInstcalcmatricesNoMtxlist)
  bnezl $v0, .L7F06F2BC
   lw    $t8, 0x24($sp)
  jal   osSyncPrintf
   addiu $a0, %lo(aInstcalcmatricesNoMtxlist) # addiu $a0, $a0, 0x48d0
  jal   return_null
   nop   
  lw    $v0, 0x10($s0)
  lw    $t8, 0x24($sp)
.L7F06F2BC:
  move  $a0, $s0
  lw    $t0, 8($t8)
  sw    $v0, 0xc($t8)
  lw    $t9, 0x10($s0)
  lh    $t1, 0xe($t0)
  sll   $t2, $t1, 6
  addu  $t3, $t9, $t2
  sw    $t3, 0x10($s0)
  jal   sub_GAME_7F06F0D0
   lw    $a1, 0x24($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel subcalcmatrices
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  bnez  $a1, .L7F06F324
   sw    $a0, 0x20($sp)
  lui   $a0, %hi(aSubcalcmatricesNoObjanim)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesNoObjanim) # addiu $a0, $a0, 0x48f0
  jal   return_null
   nop   
.L7F06F324:
  lw    $t6, 0x20($sp)
  lui   $a0, %hi(aSubcalcmatricesNoBasemtx)
  lw    $t7, ($t6)
  bnezl $t7, .L7F06F34C
   lw    $t8, 0x20($sp)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesNoBasemtx) # addiu $a0, $a0, 0x4910
  jal   return_null
   nop   
  lw    $t8, 0x20($sp)
.L7F06F34C:
  lui   $a0, %hi(aSubcalcmatricesNoMtxlist)
  lw    $t9, 0x10($t8)
  bnezl $t9, .L7F06F370
   lw    $t0, 0x20($s0)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesNoMtxlist) # addiu $a0, $a0, 0x4930
  jal   return_null
   nop   
  lw    $t0, 0x20($s0)
.L7F06F370:
  beql  $t0, $zero, .L7F06F590
   lw    $a0, 0x20($sp)
  lw    $t1, 0x18($s0)
  beql  $t1, $zero, .L7F06F3A8
   lh    $a1, 0x30($s0)
  lw    $t2, 0x1c($s0)
  lui   $a0, %hi(aSubcalcmatricesNoAttachForObjinst)
  bnezl $t2, .L7F06F3A8
   lh    $a1, 0x30($s0)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesNoAttachForObjinst) # addiu $a0, $a0, 0x4950
  jal   return_null
   nop   
  lh    $a1, 0x30($s0)
.L7F06F3A8:
  lui   $a0, %hi(aSubcalcmatricesFrameaOutOfRange)
  bltz  $a1, .L7F06F3C8
   nop   
  lw    $t3, 0x20($s0)
  lhu   $t4, 4($t3)
  slt   $at, $a1, $t4
  bnezl $at, .L7F06F3DC
   lh    $v0, 0x32($s0)
.L7F06F3C8:
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesFrameaOutOfRange) # addiu $a0, $a0, 0x497c
  jal   return_null
   nop   
  lh    $v0, 0x32($s0)
.L7F06F3DC:
  lui   $a0, %hi(aSubcalcmatricesFramebOutOfRange)
  bltz  $v0, .L7F06F3FC
   nop   
  lw    $t5, 0x20($s0)
  lhu   $t6, 4($t5)
  slt   $at, $v0, $t6
  bnezl $at, .L7F06F410
   mtc1  $zero, $f2
.L7F06F3FC:
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesFramebOutOfRange) # addiu $a0, $a0, 0x49a4
  jal   return_null
   nop   
  mtc1  $zero, $f2
.L7F06F410:
  lwc1  $f0, 0x84($s0)
  c.eq.s $f2, $f0
  nop   
  bc1t  .L7F06F440
   nop   
  c.eq.s $f2, $f0
  lui   $a0, %hi(aSubcalcmatricesNoAnim2)
  bc1t  .L7F06F448
   nop   
  lw    $t7, 0x54($s0)
  beqz  $t7, .L7F06F448
   nop   
.L7F06F440:
  b     .L7F06F45C
   lw    $a0, 0x54($s0)
.L7F06F448:
  jal   osSyncPrintf
   addiu $a0, $a0, %lo(aSubcalcmatricesNoAnim2)
  jal   return_null
   nop   
  lw    $a0, 0x54($s0)
.L7F06F45C:
  beqz  $a0, .L7F06F4A0
   nop   
  beqz  $a0, .L7F06F488
   nop   
  lh    $v0, 0x60($s0)
  bltz  $v0, .L7F06F488
   nop   
  lhu   $t8, 4($a0)
  slt   $at, $v0, $t8
  bnez  $at, .L7F06F4A0
   nop   
.L7F06F488:
  lui   $a0, %hi(aSubcalcmatricesFrame2aOutOfRange)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesFrame2aOutOfRange) # addiu $a0, $a0, 0x49e8
  jal   return_null
   nop   
  lw    $a0, 0x54($s0)
.L7F06F4A0:
  beql  $a0, $zero, .L7F06F4D0
   lw    $a0, 0x20($s0)
  beqz  $a0, .L7F06F4D8
   nop   
  lh    $v0, 0x62($s0)
  bltz  $v0, .L7F06F4D8
   nop   
  lhu   $t9, 4($a0)
  slt   $at, $v0, $t9
  beqz  $at, .L7F06F4D8
   nop   
  lw    $a0, 0x20($s0)
.L7F06F4D0:
  b     .L7F06F4F4
   lh    $a1, 0x30($s0)
.L7F06F4D8:
  lui   $a0, %hi(aSubcalcmatricesFrame2bOutOfRange)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubcalcmatricesFrame2bOutOfRange) # addiu $a0, $a0, 0x4a10
  jal   return_null
   nop   
  lw    $a0, 0x20($s0)
  lh    $a1, 0x30($s0)
.L7F06F4F4:
  lw    $t0, 8($s0)
  jal   sub_GAME_7F0754BC
   lw    $a2, 4($t0)
  mtc1  $zero, $f4
  lwc1  $f6, 0x2c($s0)
  sw    $v0, 0x34($s0)
  c.eq.s $f4, $f6
  nop   
  bc1tl .L7F06F538
   lw    $a0, 0x54($s0)
  lw    $t1, 8($s0)
  lw    $a0, 0x20($s0)
  lh    $a1, 0x32($s0)
  jal   sub_GAME_7F0754BC
   lw    $a2, 4($t1)
  sw    $v0, 0x38($s0)
  lw    $a0, 0x54($s0)
.L7F06F538:
  beqz  $a0, .L7F06F584
   nop   
  lw    $t2, 8($s0)
  lh    $a1, 0x60($s0)
  jal   sub_GAME_7F0754BC
   lw    $a2, 4($t2)
  mtc1  $zero, $f8
  lwc1  $f10, 0x5c($s0)
  sw    $v0, 0x64($s0)
  c.eq.s $f8, $f10
  nop   
  bc1t  .L7F06F584
   nop   
  lw    $t3, 8($s0)
  lw    $a0, 0x54($s0)
  lh    $a1, 0x62($s0)
  jal   sub_GAME_7F0754BC
   lw    $a2, 4($t3)
  sw    $v0, 0x68($s0)
.L7F06F584:
  jal   sub_GAME_7F0755B0
   nop   
  lw    $a0, 0x20($sp)
.L7F06F590:
  jal   instcalcmatrices
   move  $a1, $s0
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06F5AC
  jr    $ra
   lw    $v0, 0x20($a0)
");

asm(R"
glabel sub_GAME_7F06F5B4
  jr    $ra
   lb    $v0, 0x24($a0)
");

asm(R"
glabel sub_GAME_7F06F5BC
  jr    $ra
   lwc1  $f0, 0x28($a0)
");

asm(R"
glabel sub_GAME_7F06F5C4
  mtc1  $zero, $f12
  lwc1  $f2, 0x3c($a0)
  c.le.s $f12, $f2
  nop   
  bc1fl .L7F06F5E8
   lw    $v0, 0x20($a0)
  jr    $ra
   mov.s $f0, $f2

  lw    $v0, 0x20($a0)
.L7F06F5E8:
  beql  $v0, $zero, .L7F06F608
   mov.s $f0, $f12
  lhu   $t6, 4($v0)
  addiu $t7, $t6, -1
  mtc1  $t7, $f4
  jr    $ra
   cvt.s.w $f0, $f4

  mov.s $f0, $f12
.L7F06F608:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06F610
  jr    $ra
   lwc1  $f0, 0x40($a0)
");

asm(R"
glabel sub_GAME_7F06F618
  lwc1  $f2, 0x40($a0)
  mtc1  $zero, $f4
  nop   
  c.lt.s $f2, $f4
  nop   
  bc1f  .L7F06F638
   nop   
  neg.s $f2, $f2
.L7F06F638:
  jr    $ra
   mov.s $f0, $f2
");

asm(R"
glabel sub_GAME_7F06F640
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F06F610
   sw    $a0, 0x18($sp)
  lw    $t6, 0x18($sp)
  lw    $ra, 0x14($sp)
  lwc1  $f4, 0xa4($t6)
  addiu $sp, $sp, 0x18
  mul.s $f0, $f0, $f4
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06F66C
  addiu $sp, $sp, -0x18
  mtc1  $a2, $f12
  bgez  $a0, .L7F06F6D4
   sw    $ra, 0x14($sp)
  lbu   $t6, 7($a1)
  andi  $t7, $t6, 1
  beqz  $t7, .L7F06F6CC
   nop   
  lhu   $v0, 4($a1)
  negu  $t8, $a0
  div   $zero, $t8, $v0
  mfhi  $t9
  subu  $a0, $v0, $t9
  bnez  $v0, .L7F06F6AC
   nop   
  break 7
.L7F06F6AC:
  li    $at, -1
  bne   $v0, $at, .L7F06F6C4
   lui   $at, 0x8000
  bne   $t8, $at, .L7F06F6C4
   nop   
  break 6
.L7F06F6C4:
  b     .L7F06F770
   lw    $ra, 0x14($sp)
.L7F06F6CC:
  b     .L7F06F76C
   move  $a0, $zero
.L7F06F6D4:
  mtc1  $zero, $f4
  nop   
  c.le.s $f4, $f12
  nop   
  bc1fl .L7F06F718
   lhu   $v0, 4($a1)
  trunc.w.s $f6, $f12
  mfc1  $t1, $f6
  nop   
  slt   $at, $t1, $a0
  beql  $at, $zero, .L7F06F718
   lhu   $v0, 4($a1)
  jal   sub_GAME_7F05C4B8
   nop   
  b     .L7F06F76C
   move  $a0, $v0
  lhu   $v0, 4($a1)
.L7F06F718:
  slt   $at, $a0, $v0
  bnezl $at, .L7F06F770
   lw    $ra, 0x14($sp)
  lbu   $t2, 7($a1)
  andi  $t3, $t2, 1
  beql  $t3, $zero, .L7F06F76C
   addiu $a0, $v0, -1
  div   $zero, $a0, $v0
  bnez  $v0, .L7F06F744
   nop   
  break 7
.L7F06F744:
  li    $at, -1
  bne   $v0, $at, .L7F06F75C
   lui   $at, 0x8000
  bne   $a0, $at, .L7F06F75C
   nop   
  break 6
.L7F06F75C:
  mfhi  $a0
  b     .L7F06F770
   lw    $ra, 0x14($sp)
  addiu $a0, $v0, -1
.L7F06F76C:
  lw    $ra, 0x14($sp)
.L7F06F770:
  addiu $sp, $sp, 0x18
  move  $v0, $a0
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06F780
  mtc1  $a1, $f12
  mtc1  $zero, $f4
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  c.lt.s $f4, $f12
  nop   
  bc1fl .L7F06F868
   sw    $zero, 0x54($a0)
  lw    $v0, 0x20($a0)
  li    $at, 1
  beql  $v0, $zero, .L7F06F868
   sw    $zero, 0x54($a0)
  lw    $t6, 8($a0)
  lwc1  $f6, 0x28($a0)
  lwc1  $f8, 0x2c($a0)
  lw    $a1, ($t6)
  lb    $t8, 0x24($a0)
  lh    $t9, 0x30($a0)
  lhu   $v1, ($a1)
  swc1  $f6, 0x58($a0)
  swc1  $f8, 0x5c($a0)
  lh    $t0, 0x32($a0)
  lwc1  $f10, 0x40($a0)
  lwc1  $f16, 0x44($a0)
  lwc1  $f18, 0x48($a0)
  lwc1  $f4, 0x4c($a0)
  lwc1  $f6, 0x50($a0)
  lwc1  $f8, 0x3c($a0)
  andi  $t7, $v1, 0xff
  sw    $v0, 0x54($a0)
  sb    $t8, 0x25($a0)
  sh    $t9, 0x60($a0)
  sh    $t0, 0x62($a0)
  swc1  $f10, 0x70($a0)
  swc1  $f16, 0x74($a0)
  swc1  $f18, 0x78($a0)
  swc1  $f4, 0x7c($a0)
  swc1  $f6, 0x80($a0)
  bne   $t7, $at, .L7F06F868
   swc1  $f8, 0x6c($a0)
  jal   extract_id_from_object_structure_microcode
   nop   
  lwc1  $f10, 0x34($v0)
  lwc1  $f16, 0x38($v0)
  lwc1  $f18, 0x3c($v0)
  lwc1  $f4, 0x24($v0)
  lwc1  $f6, 0x28($v0)
  lwc1  $f8, 0x2c($v0)
  li    $t1, 1
  sb    $t1, 2($v0)
  swc1  $f10, 0x4c($v0)
  swc1  $f16, 0x50($v0)
  swc1  $f18, 0x54($v0)
  swc1  $f4, 0x40($v0)
  swc1  $f6, 0x44($v0)
  b     .L7F06F868
   swc1  $f8, 0x48($v0)
  sw    $zero, 0x54($a0)
.L7F06F868:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
glabel D_80054D40
.word 0x40c90fdb /*6.2831855*/
glabel D_80054D44
.word 0x40c90fdb /*6.2831855*/
glabel D_80054D48
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F06F878
  addiu $sp, $sp, -0x90
  sw    $ra, 0x24($sp)
  sw    $s1, 0x20($sp)
  sw    $s0, 0x1c($sp)
  sw    $a1, 0x94($sp)
  lw    $t6, 0x20($a0)
  mtc1  $a3, $f12
  move  $a3, $a1
  sltiu $t7, $t6, 1
  sw    $t7, 0x2c($sp)
  lw    $t8, 0x54($a0)
  mfc1  $a1, $f12
  move  $s1, $a0
  beqz  $t8, .L7F06F8D0
   lwc1  $f4, 0xa4($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $zero, $f6
  mtc1  $at, $f8
  swc1  $f4, 0x88($a0)
  swc1  $f6, 0x8c($a0)
  b     .L7F06F8E0
   swc1  $f8, 0x84($a0)
.L7F06F8D0:
  mtc1  $zero, $f10
  mtc1  $zero, $f4
  swc1  $f10, 0x88($s1)
  swc1  $f4, 0x84($s1)
.L7F06F8E0:
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f6
  sw    $a3, 0x20($s1)
  sb    $a2, 0x24($s1)
  swc1  $f6, 0x3c($s1)
  lwc1  $f8, 0xa0($sp)
  mtc1  $zero, $f10
  move  $a0, $s1
  swc1  $f8, 0x40($s1)
  jal   sub_GAME_7F06FF64
   swc1  $f10, 0x4c($s1)
  lw    $t9, 8($s1)
  sb    $zero, 0x26($s1)
  li    $at, 1
  lw    $a1, ($t9)
  lhu   $v0, ($a1)
  andi  $t0, $v0, 0xff
  bnel  $t0, $at, .L7F06FC3C
   lw    $ra, 0x24($sp)
  lw    $t1, 4($a1)
  move  $a0, $s1
  jal   extract_id_from_object_structure_microcode
   sw    $t1, 0x80($sp)
  lui   $t4, %hi(D_80036244) 
  lw    $t2, 0x80($sp)
  lw    $t3, 8($s1)
  addiu $t4, %lo(D_80036244) # addiu $t4, $t4, 0x6244
  lw    $at, ($t4)
  lwc1  $f4, 0x14($s1)
  lwc1  $f6, 0xb8($s1)
  addiu $v1, $sp, 0x5c
  lhu   $a0, ($t2)
  lw    $a2, 4($t3)
  sw    $at, ($v1)
  lw    $t7, 4($t4)
  mul.s $f2, $f4, $f6
  move  $s0, $v0
  sw    $t7, 4($v1)
  lw    $at, 8($t4)
  sw    $at, 8($v1)
  lh    $t8, 0x32($s1)
  lw    $a3, 0x20($s1)
  lb    $a1, 0x24($s1)
  swc1  $f2, 0x70($sp)
  sw    $v1, 0x14($sp)
  jal   sub_GAME_7F06D3F4
   sw    $t8, 0x10($sp)
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f2, 0x70($sp)
  mtc1  $at, $f8
  swc1  $f0, 0x58($sp)
  lwc1  $f10, 0x5c($sp)
  c.eq.s $f2, $f8
  nop   
  bc1t  .L7F06F9E0
   nop   
  mul.s $f4, $f10, $f2
  lwc1  $f6, 0x60($sp)
  lwc1  $f10, 0x64($sp)
  mul.s $f8, $f6, $f2
  swc1  $f4, 0x5c($sp)
  mul.s $f4, $f10, $f2
  swc1  $f8, 0x60($sp)
  swc1  $f4, 0x64($sp)
.L7F06F9E0:
  jal   cosf
   lwc1  $f12, 0x14($s0)
  lwc1  $f12, 0x14($s0)
  jal   sinf
   swc1  $f0, 0x6c($sp)
  lwc1  $f2, 0x2c($s1)
  mtc1  $zero, $f6
  lwc1  $f18, 0x6c($sp)
  li    $t9, 1
  c.eq.s $f6, $f2
  lwc1  $f6, 0x64($sp)
  lwc1  $f10, 0x5c($sp)
  bc1f  .L7F06FADC
   nop   
  lwc1  $f8, 0xc($s0)
  lwc1  $f10, 4($s0)
  lwc1  $f2, 8($s0)
  lwc1  $f6, 0x10($s0)
  sub.s $f4, $f8, $f10
  lwc1  $f8, 0x14($s0)
  swc1  $f2, 0x34($s0)
  swc1  $f6, 0x3c($s0)
  swc1  $f4, 0x38($s0)
  swc1  $f8, 0x30($s0)
  lwc1  $f10, 0x64($sp)
  lwc1  $f6, 0x5c($sp)
  mul.s $f4, $f10, $f0
  nop   
  mul.s $f8, $f6, $f18
  add.s $f8, $f2, $f8
  mul.s $f6, $f6, $f0
  add.s $f4, $f4, $f8
  lwc1  $f8, 0x60($sp)
  swc1  $f4, 0x4c($sp)
  swc1  $f8, 0x50($sp)
  lwc1  $f8, 0x3c($s0)
  sub.s $f8, $f8, $f6
  mul.s $f6, $f10, $f18
  add.s $f10, $f6, $f8
  swc1  $f10, 0x54($sp)
  swc1  $f4, 0x24($s0)
  lwc1  $f4, 0x18($s0)
  mtc1  $zero, $f10
  lwc1  $f6, 0x50($sp)
  c.eq.s $f10, $f4
  swc1  $f6, 0x28($s0)
  lwc1  $f8, 0x54($sp)
  bc1f  .L7F06FAD4
   swc1  $f8, 0x2c($s0)
  lwc1  $f6, 0x30($s0)
  lwc1  $f8, 0x58($sp)
  lui    $at, %hi(D_80054D40)
  lwc1  $f2, %lo(D_80054D40)($at)
  add.s $f0, $f6, $f8
  c.le.s $f2, $f0
  swc1  $f0, 0x20($s0)
  bc1f  .L7F06FAD4
   nop   
  lwc1  $f10, 0x20($s0)
  sub.s $f4, $f10, $f2
  swc1  $f4, 0x20($s0)
.L7F06FAD4:
  b     .L7F06FC24
   sb    $t9, 1($s0)
.L7F06FADC:
  mul.s $f8, $f6, $f0
  li    $at, 0x3F800000 # 1.000000
  lwc1  $f16, 0x60($sp)
  mul.s $f4, $f10, $f18
  add.s $f14, $f8, $f4
  mul.s $f8, $f6, $f18
  neg.s $f4, $f10
  mul.s $f6, $f4, $f0
  add.s $f10, $f8, $f6
  mtc1  $at, $f8
  nop   
  sub.s $f6, $f8, $f2
  swc1  $f10, 0x30($sp)
  lwc1  $f4, 8($s0)
  swc1  $f16, 0x44($sp)
  mul.s $f8, $f14, $f6
  add.s $f6, $f4, $f8
  mtc1  $at, $f4
  swc1  $f6, 0x40($sp)
  lwc1  $f8, 0x2c($s1)
  sub.s $f6, $f4, $f8
  lwc1  $f8, 0x10($s0)
  mul.s $f4, $f10, $f6
  lwc1  $f6, 0x40($sp)
  add.s $f10, $f8, $f4
  swc1  $f10, 0x48($sp)
  swc1  $f6, 0x24($s0)
  lwc1  $f8, 0x44($sp)
  lwc1  $f10, 0x24($s0)
  swc1  $f8, 0x28($s0)
  lwc1  $f4, 0x48($sp)
  lwc1  $f8, 0xc($s0)
  sub.s $f6, $f10, $f14
  swc1  $f4, 0x2c($s0)
  lwc1  $f4, 4($s0)
  swc1  $f6, 0x34($s0)
  sub.s $f12, $f8, $f4
  lwc1  $f2, 0x2c($s1)
  mtc1  $at, $f8
  lui   $at, %hi(D_80054D44)
  sub.s $f10, $f16, $f12
  sub.s $f4, $f8, $f2
  mul.s $f6, $f10, $f2
  div.s $f10, $f6, $f4
  lwc1  $f6, 0x2c($s0)
  sub.s $f8, $f12, $f10
  lwc1  $f12, 0x14($s0)
  swc1  $f8, 0x38($s0)
  lwc1  $f4, 0x30($sp)
  sub.s $f10, $f6, $f4
  mtc1  $zero, $f6
  swc1  $f10, 0x3c($s0)
  lwc1  $f8, 0x58($sp)
  sub.s $f14, $f12, $f8
  c.lt.s $f14, $f6
  nop   
  bc1f  .L7F06FBCC
   nop   
  lwc1  $f4, %lo(D_80054D44)($at)
  add.s $f14, $f14, $f4
.L7F06FBCC:
  jal   sub_GAME_7F06D0CC
   lw    $a2, 0x2c($s1)
  mtc1  $zero, $f10
  lwc1  $f8, 0x18($s0)
  lui   $at, %hi(D_80054D48)
  lwc1  $f2, %lo(D_80054D48)($at)
  c.eq.s $f10, $f8
  swc1  $f0, 0x30($s0)
  lwc1  $f4, 0x58($sp)
  li    $t0, 1
  bc1fl .L7F06FC24
   sb    $t0, 1($s0)
  lwc1  $f6, 0x30($s0)
  add.s $f0, $f6, $f4
  c.le.s $f2, $f0
  swc1  $f0, 0x20($s0)
  bc1fl .L7F06FC24
   sb    $t0, 1($s0)
  lwc1  $f10, 0x20($s0)
  sub.s $f8, $f10, $f2
  swc1  $f8, 0x20($s0)
  sb    $t0, 1($s0)
.L7F06FC24:
  lw    $t1, 0x2c($sp)
  beql  $t1, $zero, .L7F06FC3C
   lw    $ra, 0x24($sp)
  lwc1  $f6, 0x28($s0)
  swc1  $f6, 0x38($s0)
  lw    $ra, 0x24($sp)
.L7F06FC3C:
  lw    $s0, 0x1c($sp)
  lw    $s1, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x90
");

asm(R"
glabel sub_GAME_7F06FC4C
  addiu $sp, $sp, -0x20
  lw    $t6, 0x38($sp)
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  sw    $a1, 0x24($sp)
  sw    $a2, 0x28($sp)
  beqz  $t6, .L7F06FC74
   sw    $a3, 0x2c($sp)
  jal   sub_GAME_7F06F780
   lw    $a1, 0x34($sp)
.L7F06FC74:
  lwc1  $f4, 0x30($sp)
  lwc1  $f6, 0x34($sp)
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F06F878
   swc1  $f6, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FCA8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  sw    $a0, 0x20($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  jal   sub_GAME_7F06F780
   lw    $a1, 0x34($sp)
  lwc1  $f4, 0x30($sp)
  lwc1  $f6, 0x34($sp)
  lw    $a0, 0x20($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  lw    $a3, 0x2c($sp)
  swc1  $f4, 0x10($sp)
  jal   sub_GAME_7F06F878
   swc1  $f6, 0x14($sp)
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FCFC
  lw    $at, ($a1)
  addiu $sp, $sp, -0x20
  addiu $v0, $sp, 0
  sw    $at, ($v0)
  lw    $t8, 4($a1)
  move  $t2, $a0
  move  $t3, $a1
  sw    $t8, 4($v0)
  lw    $at, 8($a1)
  addiu $t1, $a0, 0xb4
  sw    $at, 8($v0)
  lw    $t8, 0xc($a1)
  sw    $t8, 0xc($v0)
  lw    $at, 0x10($a1)
  sw    $at, 0x10($v0)
  lw    $t8, 0x14($a1)
  sw    $t8, 0x14($v0)
  lw    $at, 0x18($a1)
  sw    $at, 0x18($v0)
  lw    $t8, 0x1c($a1)
  sw    $t8, 0x1c($v0)
.L7F06FD50:
  lw    $at, ($t2)
  addiu $t2, $t2, 0xc
  addiu $t3, $t3, 0xc
  sw    $at, -0xc($t3)
  lw    $at, -8($t2)
  sw    $at, -8($t3)
  lw    $at, -4($t2)
  bne   $t2, $t1, .L7F06FD50
   sw    $at, -4($t3)
  lw    $at, ($t2)
  sw    $at, ($t3)
  lw    $t1, 4($t2)
  sw    $t1, 4($t3)
  lw    $at, ($v0)
  sw    $at, ($a1)
  lw    $t7, 4($v0)
  sw    $t7, 4($a1)
  lw    $at, 8($v0)
  sw    $at, 8($a1)
  lw    $t7, 0xc($v0)
  sw    $t7, 0xc($a1)
  lw    $at, 0x10($v0)
  sw    $at, 0x10($a1)
  lw    $t7, 0x14($v0)
  sw    $t7, 0x14($a1)
  lw    $at, 0x18($v0)
  sw    $at, 0x18($a1)
  lw    $t7, 0x1c($v0)
  addiu $sp, $sp, 0x20
  jr    $ra
   sw    $t7, 0x1c($a1)
");

asm(R"
glabel sub_GAME_7F06FDCC
  mtc1  $a1, $f12
  mtc1  $a2, $f14
  li    $t6, 1
  sb    $t6, 0x26($a0)
  swc1  $f12, 0x90($a0)
  jr    $ra
   swc1  $f14, 0x94($a0)
");

asm(R"
glabel sub_GAME_7F06FDE8
  lw    $v0, 0x20($a0)
  mtc1  $a1, $f12
  li    $at, 0xBF800000 # -1.000000
  beql  $v0, $zero, .L7F06FE2C
   mtc1  $at, $f8
  lhu   $t6, 4($v0)
  addiu $t7, $t6, -1
  mtc1  $t7, $f4
  nop   
  cvt.s.w $f6, $f4
  c.lt.s $f12, $f6
  nop   
  bc1fl .L7F06FE2C
   mtc1  $at, $f8
  jr    $ra
   swc1  $f12, 0x3c($a0)

  mtc1  $at, $f8
.L7F06FE2C:
  nop   
  swc1  $f8, 0x3c($a0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FE3C
  jr    $ra
   sw    $a1, 0x98($a0)
");

asm(R"
glabel sub_GAME_7F06FE44
  jr    $ra
   sw    $a1, 0x9c($a0)
");

asm(R"
glabel sub_GAME_7F06FE4C
  mtc1  $a2, $f12
  mtc1  $zero, $f0
  mtc1  $a1, $f14
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F06FE84
   swc1  $f14, 0x40($a0)
  lwc1  $f4, 0x40($a0)
  swc1  $f12, 0x4c($a0)
  swc1  $f14, 0x44($a0)
  swc1  $f0, 0x50($a0)
  jr    $ra
   swc1  $f4, 0x48($a0)

  swc1  $f14, 0x40($a0)
.L7F06FE84:
  swc1  $f0, 0x4c($a0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FE90
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  mtc1  $a1, $f12
  lwc1  $f0, 0x28($a0)
  mtc1  $a2, $f14
  c.le.s $f0, $f12
  nop   
  bc1fl .L7F06FEC0
   lw    $t6, 0x20($a0)
  b     .L7F06FEE8
   sub.s $f2, $f12, $f0
  lw    $t6, 0x20($a0)
.L7F06FEC0:
  li    $at, 0x4F800000 # 4294967296.000000
  lhu   $t7, 4($t6)
  mtc1  $t7, $f4
  bgez  $t7, .L7F06FEE0
   cvt.s.w $f6, $f4
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F06FEE0:
  sub.s $f10, $f6, $f0
  add.s $f2, $f10, $f12
.L7F06FEE8:
  add.s $f18, $f2, $f2
  lwc1  $f16, 0x40($a0)
  mfc1  $a2, $f14
  div.s $f4, $f18, $f14
  add.s $f0, $f16, $f4
  mfc1  $a1, $f0
  jal   sub_GAME_7F06FE4C
   nop   
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FF18
  mtc1  $a2, $f12
  mtc1  $zero, $f0
  mtc1  $a1, $f14
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F06FF50
   swc1  $f14, 0xa4($a0)
  lwc1  $f4, 0xa4($a0)
  swc1  $f12, 0xb0($a0)
  swc1  $f14, 0xa8($a0)
  swc1  $f0, 0xb4($a0)
  jr    $ra
   swc1  $f4, 0xac($a0)

  swc1  $f14, 0xa4($a0)
.L7F06FF50:
  swc1  $f0, 0xb0($a0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F06FF5C
  jr    $ra
   sw    $a1, 0xa0($a0)
");

asm(R"
glabel sub_GAME_7F06FF64
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x34($sp)
  move  $s0, $a0
  jal   sub_GAME_7F05C3D8
   lwc1  $f12, 0x34($sp)
  lwc1  $f4, 0x40($s0)
  mtc1  $zero, $f6
  move  $a0, $v0
  move  $t0, $zero
  c.le.s $f6, $f4
  addiu $a3, $v0, -1
  bc1f  .L7F06FFA4
   nop   
  li    $t0, 1
.L7F06FFA4:
  beqz  $t0, .L7F06FFB4
   nop   
  b     .L7F06FFB4
   addiu $a3, $v0, 1
.L7F06FFB4:
  lw    $a1, 0x20($s0)
  lw    $a2, 0x3c($s0)
  sw    $t0, 0x24($sp)
  sw    $a3, 0x28($sp)
  jal   sub_GAME_7F06F66C
   sw    $a0, 0x2c($sp)
  lw    $a0, 0x28($sp)
  sh    $v0, 0x30($s0)
  lw    $a1, 0x20($s0)
  jal   sub_GAME_7F06F66C
   lw    $a2, 0x3c($s0)
  lw    $a3, 0x28($sp)
  lw    $t0, 0x24($sp)
  sh    $v0, 0x32($s0)
  lh    $a0, 0x32($s0)
  lh    $v1, 0x30($s0)
  bne   $a0, $v1, .L7F070014
   nop   
  mtc1  $v1, $f10
  mtc1  $zero, $f8
  cvt.s.w $f16, $f10
  swc1  $f8, 0x2c($s0)
  b     .L7F07007C
   swc1  $f16, 0x28($s0)
.L7F070014:
  beqz  $t0, .L7F070044
   lw    $t6, 0x2c($sp)
  mtc1  $t6, $f4
  mtc1  $v1, $f8
  lwc1  $f18, 0x34($sp)
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  sub.s $f0, $f18, $f6
  add.s $f16, $f10, $f0
  swc1  $f0, 0x2c($s0)
  b     .L7F07007C
   swc1  $f16, 0x28($s0)
.L7F070044:
  mtc1  $a3, $f18
  lwc1  $f4, 0x34($sp)
  li    $at, 0x3F800000 # 1.000000
  cvt.s.w $f6, $f18
  mtc1  $at, $f2
  mtc1  $a0, $f10
  nop   
  cvt.s.w $f16, $f10
  sub.s $f8, $f4, $f6
  sub.s $f0, $f2, $f8
  sub.s $f18, $f2, $f0
  swc1  $f0, 0x2c($s0)
  add.s $f4, $f16, $f18
  swc1  $f4, 0x28($s0)
.L7F07007C:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F070090
  mtc1  $a1, $f12
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  mfc1  $a1, $f12
  move  $s0, $a0
  jal   sub_GAME_7F06FF64
   sw    $a2, 0x38($sp)
  lw    $t6, 0x54($s0)
  beql  $t6, $zero, .L7F0701C4
   lw    $ra, 0x1c($sp)
  jal   sub_GAME_7F05C3D8
   lwc1  $f12, 0x38($sp)
  lwc1  $f4, 0x70($s0)
  mtc1  $zero, $f6
  move  $a0, $v0
  move  $t0, $zero
  c.le.s $f6, $f4
  addiu $a3, $v0, -1
  bc1f  .L7F0700E8
   nop   
  li    $t0, 1
.L7F0700E8:
  beqz  $t0, .L7F0700F8
   nop   
  b     .L7F0700F8
   addiu $a3, $v0, 1
.L7F0700F8:
  lw    $a1, 0x54($s0)
  lw    $a2, 0x6c($s0)
  sw    $t0, 0x24($sp)
  sw    $a3, 0x28($sp)
  jal   sub_GAME_7F06F66C
   sw    $a0, 0x2c($sp)
  lw    $a0, 0x28($sp)
  sh    $v0, 0x60($s0)
  lw    $a1, 0x54($s0)
  jal   sub_GAME_7F06F66C
   lw    $a2, 0x6c($s0)
  lw    $a3, 0x28($sp)
  lw    $t0, 0x24($sp)
  sh    $v0, 0x62($s0)
  lh    $a0, 0x62($s0)
  lh    $v1, 0x60($s0)
  bne   $a0, $v1, .L7F070158
   nop   
  mtc1  $v1, $f10
  mtc1  $zero, $f8
  cvt.s.w $f16, $f10
  swc1  $f8, 0x5c($s0)
  b     .L7F0701C0
   swc1  $f16, 0x58($s0)
.L7F070158:
  beqz  $t0, .L7F070188
   lw    $t7, 0x2c($sp)
  mtc1  $t7, $f4
  mtc1  $v1, $f8
  lwc1  $f18, 0x38($sp)
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  sub.s $f0, $f18, $f6
  add.s $f16, $f10, $f0
  swc1  $f0, 0x5c($s0)
  b     .L7F0701C0
   swc1  $f16, 0x58($s0)
.L7F070188:
  mtc1  $a3, $f18
  lwc1  $f4, 0x38($sp)
  li    $at, 0x3F800000 # 1.000000
  cvt.s.w $f6, $f18
  mtc1  $at, $f2
  mtc1  $a0, $f10
  nop   
  cvt.s.w $f16, $f10
  sub.s $f8, $f4, $f6
  sub.s $f0, $f2, $f8
  sub.s $f18, $f2, $f0
  swc1  $f0, 0x5c($s0)
  add.s $f4, $f16, $f18
  swc1  $f4, 0x58($s0)
.L7F0701C0:
  lw    $ra, 0x1c($sp)
.L7F0701C4:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   nop   
");

extern int D_80036250;
void sub_GAME_7F0701D4(int arg0) { D_80036250 = arg0; }

int sub_GAME_7F0701E0(void) { return D_80036250; }

asm(R"
.late_rodata
glabel D_80054D4C
.word 0x40c90fdb /*6.2831855*/
.text
glabel sub_GAME_7F0701EC
  addiu $sp, $sp, -0xf8
  sw    $ra, 0x5c($sp)
  sw    $s3, 0x58($sp)
  sw    $s2, 0x54($sp)
  sw    $s1, 0x50($sp)
  sw    $s0, 0x4c($sp)
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x100($sp)
  sw    $a3, 0x104($sp)
  lw    $t6, 8($a0)
  mtc1  $a1, $f20
  li    $at, 1
  lw    $a1, ($t6)
  move  $s1, $a0
  lhu   $v0, ($a1)
  andi  $t7, $v0, 0xff
  bnel  $t7, $at, .L7F070AA4
   lwc1  $f20, 0x108($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $s2, 4($a1)
  lb    $t8, ($v0)
  move  $s0, $v0
  bnezl $t8, .L7F070A84
   lwc1  $f20, 0x108($sp)
  lhu   $t9, ($s2)
  lui   $t3, %hi(D_80036254) 
  addiu $t3, %lo(D_80036254) # addiu $t3, $t3, 0x6254
  sw    $t9, 0xe4($sp)
  lw    $t0, 8($s1)
  addiu $t2, $sp, 0xc8
  mtc1  $zero, $f24
  lw    $t1, 4($t0)
  sw    $t1, 0xe0($sp)
  lwc1  $f6, 0xb8($s1)
  lwc1  $f4, 0x14($s1)
  mul.s $f8, $f4, $f6
  swc1  $f8, 0xdc($sp)
  lw    $at, ($t3)
  lw    $t6, 4($t3)
  sw    $at, ($t2)
  lw    $at, 8($t3)
  sw    $t6, 4($t2)
  sw    $at, 8($t2)
  lwc1  $f10, 0x34($v0)
  swc1  $f10, 0xac($sp)
  lwc1  $f16, 0x38($v0)
  swc1  $f16, 0xb0($sp)
  lwc1  $f18, 0x3c($v0)
  lwc1  $f16, 0x100($sp)
  swc1  $f18, 0xb4($sp)
  lwc1  $f4, 0x24($v0)
  lwc1  $f28, 0x30($v0)
  swc1  $f4, 0x9c($sp)
  lwc1  $f6, 0x28($v0)
  swc1  $f6, 0xa0($sp)
  lwc1  $f8, 0x2c($v0)
  swc1  $f8, 0xa4($sp)
  lwc1  $f10, 0x20($v0)
  swc1  $f10, 0x98($sp)
  lb    $t7, 1($v0)
  sw    $t7, 0x94($sp)
  lwc1  $f30, 0x40($s1)
  c.lt.s $f30, $f24
  nop   
  bc1fl .L7F070310
   lwc1  $f0, 0x70($s1)
  neg.s $f30, $f30
  lwc1  $f0, 0x70($s1)
.L7F070310:
  c.lt.s $f0, $f24
  nop   
  bc1fl .L7F070328
   c.le.s $f20, $f16
  neg.s $f0, $f0
  c.le.s $f20, $f16
.L7F070328:
  move  $s3, $zero
  bc1f  .L7F070338
   nop   
  li    $s3, 1
.L7F070338:
  beql  $s3, $zero, .L7F070364
   mov.s $f12, $f20
  mov.s $f12, $f20
  jal   sub_GAME_7F05C3D8
   swc1  $f0, 0x88($sp)
  addiu $s2, $v0, 1
  jal   sub_GAME_7F05C3D8
   lwc1  $f12, 0x100($sp)
  b     .L7F07037C
   sw    $v0, 0xb8($sp)
  mov.s $f12, $f20
.L7F070364:
  jal   sub_GAME_7F05C4B8
   swc1  $f0, 0x88($sp)
  addiu $s2, $v0, -1
  jal   sub_GAME_7F05C4B8
   lwc1  $f12, 0x100($sp)
  sw    $v0, 0xb8($sp)
.L7F07037C:
  lui   $at, %hi(D_80054D4C)
  lw    $a3, 0xb8($sp)
  lwc1  $f26, %lo(D_80054D4C)($at)
.L7F070388:
  beqz  $s3, .L7F0703A4
   slt   $at, $s2, $a3
  slt   $at, $a3, $s2
  beql  $at, $zero, .L7F0703B0
   lw    $a1, 0x20($s1)
  b     .L7F070860
   lwc1  $f6, 0xac($sp)
.L7F0703A4:
  bnezl $at, .L7F070860
   lwc1  $f6, 0xac($sp)
  lw    $a1, 0x20($s1)
.L7F0703B0:
  lw    $a2, 0x3c($s1)
  sw    $a3, 0xb8($sp)
  jal   sub_GAME_7F06F66C
   move  $a0, $s2
  sh    $v0, 0x30($s1)
  lw    $t8, 0x94($sp)
  move  $v1, $v0
  lw    $a2, 0xe0($sp)
  beqz  $t8, .L7F07040C
   lw    $a0, 0xe4($sp)
  lwc1  $f18, 0x9c($sp)
  lwc1  $f4, 0xa0($sp)
  lwc1  $f6, 0xa4($sp)
  swc1  $f18, 0xac($sp)
  swc1  $f4, 0xb0($sp)
  swc1  $f6, 0xb4($sp)
  lwc1  $f8, 0x18($s0)
  c.eq.s $f24, $f8
  nop   
  bc1f  .L7F070518
   nop   
  b     .L7F070518
   lwc1  $f28, 0x98($sp)
.L7F07040C:
  lb    $a1, 0x24($s1)
  lw    $a3, 0x20($s1)
  addiu $t9, $sp, 0xc8
  sw    $t9, 0x14($sp)
  jal   sub_GAME_7F06D3F4
   sw    $v1, 0x10($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f16
  lwc1  $f10, 0xdc($sp)
  mov.s $f22, $f0
  lwc1  $f2, 0xc8($sp)
  c.eq.s $f10, $f16
  lwc1  $f18, 0xcc($sp)
  bc1tl .L7F07046C
   lwc1  $f2, 0xc8($sp)
  mul.s $f2, $f2, $f10
  lwc1  $f12, 0xd0($sp)
  mul.s $f4, $f18, $f10
  nop   
  mul.s $f12, $f12, $f10
  swc1  $f2, 0xc8($sp)
  swc1  $f4, 0xcc($sp)
  swc1  $f12, 0xd0($sp)
  lwc1  $f2, 0xc8($sp)
.L7F07046C:
  bnez  $s3, .L7F070490
   lwc1  $f12, 0xd0($sp)
  c.lt.s $f24, $f0
  neg.s $f2, $f2
  neg.s $f12, $f12
  swc1  $f2, 0xc8($sp)
  bc1f  .L7F070490
   swc1  $f12, 0xd0($sp)
  sub.s $f22, $f26, $f0
.L7F070490:
  jal   cosf
   lwc1  $f12, 0x14($s0)
  mov.s $f20, $f0
  jal   sinf
   lwc1  $f12, 0x14($s0)
  lwc1  $f6, 0xc8($sp)
  lwc1  $f16, 0xd0($sp)
  lwc1  $f10, 0xac($sp)
  mul.s $f8, $f6, $f20
  nop   
  mul.s $f18, $f16, $f0
  add.s $f4, $f8, $f18
  lwc1  $f18, 0xcc($sp)
  add.s $f8, $f10, $f4
  swc1  $f18, 0xb0($sp)
  neg.s $f10, $f6
  swc1  $f8, 0xac($sp)
  mul.s $f4, $f10, $f0
  lwc1  $f6, 0xb4($sp)
  mul.s $f8, $f16, $f20
  add.s $f18, $f4, $f8
  add.s $f10, $f6, $f18
  swc1  $f10, 0xb4($sp)
  lwc1  $f16, 0x18($s0)
  c.eq.s $f24, $f16
  nop   
  bc1f  .L7F070518
   nop   
  add.s $f28, $f28, $f22
  c.le.s $f26, $f28
  nop   
  bc1f  .L7F070518
   nop   
  sub.s $f28, $f28, $f26
.L7F070518:
  beql  $s3, $zero, .L7F07052C
   addiu $s2, $s2, -1
  b     .L7F07052C
   addiu $s2, $s2, 1
  addiu $s2, $s2, -1
.L7F07052C:
  move  $a0, $s2
  lw    $a1, 0x20($s1)
  jal   sub_GAME_7F06F66C
   lw    $a2, 0x3c($s1)
  sh    $v0, 0x32($s1)
  lh    $t1, 0x32($s1)
  lh    $t0, 0x30($s1)
  lw    $a2, 0xe0($sp)
  lw    $a0, 0xe4($sp)
  beq   $t0, $t1, .L7F070854
   addiu $t5, $sp, 0xc8
  lb    $a1, 0x24($s1)
  lw    $a3, 0x20($s1)
  li    $t4, 1
  sw    $t4, 0x94($sp)
  sw    $t5, 0x14($sp)
  jal   sub_GAME_7F06D3F4
   sw    $v0, 0x10($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f8
  lwc1  $f4, 0xdc($sp)
  mov.s $f22, $f0
  lwc1  $f2, 0xc8($sp)
  c.eq.s $f4, $f8
  lwc1  $f6, 0xcc($sp)
  bc1tl .L7F0705BC
   lwc1  $f2, 0xc8($sp)
  mul.s $f2, $f2, $f4
  lwc1  $f12, 0xd0($sp)
  mul.s $f18, $f6, $f4
  nop   
  mul.s $f12, $f12, $f4
  swc1  $f2, 0xc8($sp)
  swc1  $f18, 0xcc($sp)
  swc1  $f12, 0xd0($sp)
  lwc1  $f2, 0xc8($sp)
.L7F0705BC:
  bnez  $s3, .L7F0705E0
   lwc1  $f12, 0xd0($sp)
  c.lt.s $f24, $f0
  neg.s $f2, $f2
  neg.s $f12, $f12
  swc1  $f2, 0xc8($sp)
  bc1f  .L7F0705E0
   swc1  $f12, 0xd0($sp)
  sub.s $f22, $f26, $f0
.L7F0705E0:
  jal   cosf
   lwc1  $f12, 0x30($s0)
  mov.s $f20, $f0
  jal   sinf
   lwc1  $f12, 0x30($s0)
  lui   $t2, %hi(D_80036250) 
  lw    $t2, %lo(D_80036250)($t2)
  lwc1  $f2, 0xc8($sp)
  lwc1  $f12, 0xd0($sp)
  beqz  $t2, .L7F070760
   nop   
  lw    $t3, 0x54($s1)
  beqz  $t3, .L7F070760
   nop   
  lwc1  $f12, 0xd0($sp)
  lwc1  $f2, 0xc8($sp)
  c.lt.s $f24, $f30
  mul.s $f10, $f12, $f0
  neg.s $f6, $f2
  li    $at, 0x3F000000 # 0.500000
  mul.s $f16, $f2, $f20
  nop   
  mul.s $f4, $f12, $f20
  nop   
  mul.s $f18, $f6, $f0
  add.s $f8, $f10, $f16
  swc1  $f8, 0x9c($sp)
  add.s $f10, $f4, $f18
  bc1f  .L7F0706F4
   swc1  $f10, 0xa4($sp)
  lwc1  $f8, 0x88($s1)
  lwc1  $f16, 0xa4($s1)
  lwc1  $f2, 0x84($s1)
  mul.s $f6, $f30, $f8
  div.s $f4, $f16, $f6
  sub.s $f0, $f2, $f4
  c.lt.s $f0, $f24
  nop   
  bc1fl .L7F070688
   add.s $f18, $f2, $f0
  mov.s $f0, $f24
  add.s $f18, $f2, $f0
.L7F070688:
  lwc1  $f8, 0x40($s0)
  lwc1  $f16, 0x4c($s0)
  mtc1  $at, $f10
  lwc1  $f4, 0x88($sp)
  sub.s $f6, $f8, $f16
  mul.s $f0, $f18, $f10
  nop   
  mul.s $f18, $f6, $f4
  div.s $f10, $f18, $f30
  swc1  $f10, 0x7c($sp)
  lwc1  $f16, 0x54($s0)
  lwc1  $f8, 0x48($s0)
  sub.s $f6, $f8, $f16
  lwc1  $f16, 0x9c($sp)
  mul.s $f18, $f6, $f4
  sub.s $f6, $f10, $f16
  lwc1  $f10, 0xa4($sp)
  mul.s $f4, $f6, $f0
  div.s $f8, $f18, $f30
  add.s $f18, $f16, $f4
  swc1  $f18, 0x9c($sp)
  sub.s $f6, $f8, $f10
  swc1  $f8, 0x84($sp)
  mul.s $f16, $f6, $f0
  add.s $f4, $f10, $f16
  b     .L7F070734
   swc1  $f4, 0xa4($sp)
.L7F0706F4:
  lwc1  $f18, 0x40($s0)
  lwc1  $f8, 0x4c($s0)
  lwc1  $f10, 0x84($s1)
  lwc1  $f4, 0x9c($sp)
  sub.s $f6, $f18, $f8
  mul.s $f16, $f6, $f10
  add.s $f18, $f4, $f16
  swc1  $f18, 0x9c($sp)
  lwc1  $f6, 0x54($s0)
  lwc1  $f8, 0x48($s0)
  lwc1  $f4, 0x84($s1)
  lwc1  $f18, 0xa4($sp)
  sub.s $f10, $f8, $f6
  mul.s $f16, $f10, $f4
  add.s $f8, $f18, $f16
  swc1  $f8, 0xa4($sp)
.L7F070734:
  lwc1  $f6, 0x9c($sp)
  lwc1  $f10, 0xac($sp)
  lwc1  $f18, 0xa4($sp)
  lwc1  $f16, 0xb4($sp)
  add.s $f4, $f6, $f10
  lwc1  $f6, 0xcc($sp)
  add.s $f8, $f18, $f16
  swc1  $f4, 0x9c($sp)
  swc1  $f6, 0xa0($sp)
  b     .L7F070798
   swc1  $f8, 0xa4($sp)
.L7F070760:
  mul.s $f4, $f2, $f20
  lwc1  $f10, 0xac($sp)
  lwc1  $f6, 0xcc($sp)
  mul.s $f16, $f12, $f0
  swc1  $f6, 0xa0($sp)
  add.s $f18, $f10, $f4
  mul.s $f4, $f2, $f0
  lwc1  $f10, 0xb4($sp)
  add.s $f8, $f16, $f18
  mul.s $f18, $f12, $f20
  sub.s $f16, $f10, $f4
  swc1  $f8, 0x9c($sp)
  add.s $f8, $f18, $f16
  swc1  $f8, 0xa4($sp)
.L7F070798:
  lwc1  $f0, 0x5c($s0)
  c.lt.s $f24, $f0
  nop   
  bc1fl .L7F070828
   lwc1  $f16, 0x18($s0)
  c.lt.s $f24, $f30
  li    $at, 0x3F800000 # 1.000000
  bc1fl .L7F070828
   lwc1  $f16, 0x18($s0)
  mtc1  $at, $f6
  nop   
  div.s $f2, $f6, $f30
  c.lt.s $f0, $f2
  mov.s $f12, $f2
  bc1fl .L7F0707E8
   sub.s $f10, $f0, $f2
  mov.s $f12, $f0
  b     .L7F0707EC
   swc1  $f24, 0x5c($s0)
  sub.s $f10, $f0, $f2
.L7F0707E8:
  swc1  $f10, 0x5c($s0)
.L7F0707EC:
  lwc1  $f4, 0x58($s0)
  mul.s $f18, $f4, $f12
  add.s $f22, $f22, $f18
  c.lt.s $f22, $f24
  nop   
  bc1fl .L7F070814
   c.le.s $f26, $f22
  b     .L7F070824
   add.s $f22, $f22, $f26
  c.le.s $f26, $f22
.L7F070814:
  nop   
  bc1fl .L7F070828
   lwc1  $f16, 0x18($s0)
  sub.s $f22, $f22, $f26
.L7F070824:
  lwc1  $f16, 0x18($s0)
.L7F070828:
  c.eq.s $f24, $f16
  nop   
  bc1f  .L7F070854
   nop   
  add.s $f0, $f28, $f22
  c.le.s $f26, $f0
  swc1  $f0, 0x98($sp)
  bc1f  .L7F070854
   nop   
  sub.s $f8, $f0, $f26
  swc1  $f8, 0x98($sp)
.L7F070854:
  b     .L7F070388
   lw    $a3, 0xb8($sp)
  lwc1  $f6, 0xac($sp)
.L7F070860:
  swc1  $f6, 0x34($s0)
  lwc1  $f10, 0xb0($sp)
  swc1  $f10, 0x38($s0)
  lwc1  $f4, 0xb4($sp)
  swc1  $f28, 0x30($s0)
  swc1  $f4, 0x3c($s0)
  lwc1  $f18, 0x9c($sp)
  swc1  $f18, 0x24($s0)
  lwc1  $f16, 0xa0($sp)
  swc1  $f16, 0x28($s0)
  lwc1  $f8, 0xa4($sp)
  swc1  $f8, 0x2c($s0)
  lwc1  $f6, 0x98($sp)
  swc1  $f6, 0x20($s0)
  lh    $v0, 0x30($s1)
  lh    $v1, 0x32($s1)
  bne   $v1, $v0, .L7F0708BC
   nop   
  mtc1  $v0, $f10
  swc1  $f24, 0x2c($s1)
  cvt.s.w $f4, $f10
  b     .L7F07091C
   swc1  $f4, 0x28($s1)
.L7F0708BC:
  beql  $s3, $zero, .L7F0708F0
   mtc1  $a3, $f16
  mtc1  $a3, $f16
  mtc1  $v0, $f6
  lwc1  $f18, 0x100($sp)
  cvt.s.w $f8, $f16
  cvt.s.w $f10, $f6
  sub.s $f0, $f18, $f8
  add.s $f4, $f10, $f0
  swc1  $f0, 0x2c($s1)
  b     .L7F07091C
   swc1  $f4, 0x28($s1)
  mtc1  $a3, $f16
.L7F0708F0:
  lwc1  $f8, 0x100($sp)
  mtc1  $v1, $f6
  cvt.s.w $f18, $f16
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  cvt.s.w $f10, $f6
  sub.s $f0, $f18, $f8
  sub.s $f16, $f4, $f0
  swc1  $f0, 0x2c($s1)
  add.s $f18, $f10, $f16
  swc1  $f18, 0x28($s1)
.L7F07091C:
  lw    $t6, 0x54($s1)
  beqz  $t6, .L7F070A78
   nop   
  jal   sub_GAME_7F05C3D8
   lwc1  $f12, 0x104($sp)
  lwc1  $f20, 0x108($sp)
  move  $s2, $v0
  jal   sub_GAME_7F05C3D8
   mov.s $f12, $f20
  beqz  $s3, .L7F070954
   sw    $v0, 0x6c($sp)
  slt   $at, $s2, $v0
  bnezl $at, .L7F070968
   lb    $t7, 2($s0)
.L7F070954:
  bnez  $s3, .L7F070A08
   slt   $at, $v0, $s2
  beql  $at, $zero, .L7F070A0C
   lui   $at, 0x3f80
  lb    $t7, 2($s0)
.L7F070968:
  beql  $t7, $zero, .L7F070980
   lwc1  $f6, 0x38($s0)
  lwc1  $f8, 0x44($s0)
  b     .L7F070984
   swc1  $f8, 0x50($s0)
  lwc1  $f6, 0x38($s0)
.L7F070980:
  swc1  $f6, 0x50($s0)
.L7F070984:
  lw    $a0, 0x6c($sp)
  lw    $a1, 0x54($s1)
  jal   sub_GAME_7F06F66C
   lw    $a2, 0x6c($s1)
  sh    $v0, 0x60($s1)
  lw    $a0, 0x6c($sp)
  lw    $a1, 0x54($s1)
  lw    $a2, 0x6c($s1)
  jal   sub_GAME_7F06F66C
   addiu $a0, $a0, 1
  sh    $v0, 0x62($s1)
  lb    $a1, 0x25($s1)
  lw    $a3, 0x54($s1)
  addiu $t8, $sp, 0xc8
  sw    $t8, 0x14($sp)
  sw    $v0, 0x10($sp)
  lw    $a2, 0xe0($sp)
  jal   sub_GAME_7F06D3F4
   lw    $a0, 0xe4($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  lwc1  $f12, 0xdc($sp)
  lwc1  $f4, 0xcc($sp)
  c.eq.s $f12, $f2
  nop   
  bc1tl .L7F0709FC
   lwc1  $f16, 0xcc($sp)
  mul.s $f10, $f4, $f12
  swc1  $f10, 0xcc($sp)
  lwc1  $f16, 0xcc($sp)
.L7F0709FC:
  li    $t9, 1
  sb    $t9, 2($s0)
  swc1  $f16, 0x44($s0)
.L7F070A08:
  li    $at, 0x3F800000 # 1.000000
.L7F070A0C:
  mtc1  $at, $f2
  beqz  $s3, .L7F070A44
   lw    $t5, 0x6c($sp)
  lw    $t0, 0x6c($sp)
  lh    $t1, 0x60($s1)
  mtc1  $t0, $f18
  mtc1  $t1, $f6
  cvt.s.w $f8, $f18
  cvt.s.w $f4, $f6
  sub.s $f0, $f20, $f8
  add.s $f10, $f4, $f0
  swc1  $f0, 0x5c($s1)
  b     .L7F070AB8
   swc1  $f10, 0x58($s1)
.L7F070A44:
  mtc1  $t5, $f16
  lh    $t4, 0x62($s1)
  cvt.s.w $f18, $f16
  mtc1  $t4, $f6
  nop   
  cvt.s.w $f4, $f6
  sub.s $f8, $f20, $f18
  sub.s $f0, $f2, $f8
  sub.s $f10, $f2, $f0
  swc1  $f0, 0x5c($s1)
  add.s $f16, $f4, $f10
  b     .L7F070AB8
   swc1  $f16, 0x58($s1)
.L7F070A78:
  b     .L7F070AB8
   sb    $zero, 2($s0)
  lwc1  $f20, 0x108($sp)
.L7F070A84:
  move  $a0, $s1
  lw    $a1, 0x100($sp)
  mfc1  $a2, $f20
  jal   sub_GAME_7F070090
   nop   
  b     .L7F070ABC
   lw    $ra, 0x5c($sp)
  lwc1  $f20, 0x108($sp)
.L7F070AA4:
  move  $a0, $s1
  lw    $a1, 0x100($sp)
  mfc1  $a2, $f20
  jal   sub_GAME_7F070090
   nop   
.L7F070AB8:
  lw    $ra, 0x5c($sp)
.L7F070ABC:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f30, 0x40($sp)
  lw    $s0, 0x4c($sp)
  lw    $s1, 0x50($sp)
  lw    $s2, 0x54($sp)
  lw    $s3, 0x58($sp)
  jr    $ra
   addiu $sp, $sp, 0xf8
");

asm(R"
glabel sub_GAME_7F070AEC
  addiu $sp, $sp, -0x88
  sw    $ra, 0x54($sp)
  sw    $s1, 0x50($sp)
  sw    $s0, 0x4c($sp)
  sdc1  $f30, 0x40($sp)
  sdc1  $f28, 0x38($sp)
  sdc1  $f26, 0x30($sp)
  sdc1  $f24, 0x28($sp)
  sdc1  $f22, 0x20($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a2, 0x90($sp)
  lwc1  $f4, 0x58($a0)
  lwc1  $f18, 0x28($a0)
  move  $s0, $a0
  move  $s1, $a1
  blez  $a1, .L7F070F54
   swc1  $f4, 0x80($sp)
  blezl $a1, .L7F070ECC
   lw    $t3, 0x90($sp)
  mtc1  $zero, $f24
  nop   
  lwc1  $f2, 0xb0($s0)
.L7F070B44:
  li    $at, 0x3F800000 # 1.000000
  c.lt.s $f24, $f2
  nop   
  bc1fl .L7F070BB0
   lwc1  $f8, 0x88($s0)
  lwc1  $f6, 0xb4($s0)
  mtc1  $at, $f8
  nop   
  add.s $f10, $f6, $f8
  swc1  $f10, 0xb4($s0)
  lwc1  $f12, 0xb4($s0)
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F070BA4
   lwc1  $f6, 0xa8($s0)
  lwc1  $f0, 0xac($s0)
  lwc1  $f4, 0xa8($s0)
  sub.s $f6, $f4, $f0
  mul.s $f8, $f6, $f12
  div.s $f10, $f8, $f2
  add.s $f4, $f0, $f10
  b     .L7F070BAC
   swc1  $f4, 0xa4($s0)
  lwc1  $f6, 0xa8($s0)
.L7F070BA4:
  swc1  $f24, 0xb0($s0)
  swc1  $f6, 0xa4($s0)
.L7F070BAC:
  lwc1  $f8, 0x88($s0)
.L7F070BB0:
  lwc1  $f2, 0xa4($s0)
  c.lt.s $f24, $f8
  nop   
  bc1fl .L7F070C34
   lwc1  $f12, 0x4c($s0)
  lwc1  $f10, 0x8c($s0)
  li    $at, 0x3F800000 # 1.000000
  add.s $f4, $f10, $f2
  swc1  $f4, 0x8c($s0)
  lwc1  $f12, 0x8c($s0)
  c.eq.s $f24, $f12
  nop   
  bc1fl .L7F070BFC
   lwc1  $f0, 0x88($s0)
  mtc1  $at, $f6
  lwc1  $f2, 0xa4($s0)
  b     .L7F070C30
   swc1  $f6, 0x84($s0)
  lwc1  $f0, 0x88($s0)
.L7F070BFC:
  c.lt.s $f12, $f0
  nop   
  bc1fl .L7F070C24
   swc1  $f24, 0x88($s0)
  sub.s $f8, $f0, $f12
  lwc1  $f2, 0xa4($s0)
  div.s $f10, $f8, $f0
  b     .L7F070C30
   swc1  $f10, 0x84($s0)
  swc1  $f24, 0x88($s0)
.L7F070C24:
  swc1  $f24, 0x84($s0)
  sw    $zero, 0x54($s0)
  lwc1  $f2, 0xa4($s0)
.L7F070C30:
  lwc1  $f12, 0x4c($s0)
.L7F070C34:
  c.lt.s $f24, $f12
  nop   
  bc1fl .L7F070C9C
   lwc1  $f16, 0x40($s0)
  lwc1  $f4, 0x50($s0)
  add.s $f6, $f4, $f2
  swc1  $f6, 0x50($s0)
  lwc1  $f14, 0x50($s0)
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F070C8C
   lwc1  $f10, 0x44($s0)
  lwc1  $f0, 0x48($s0)
  lwc1  $f8, 0x44($s0)
  lwc1  $f2, 0xa4($s0)
  sub.s $f10, $f8, $f0
  mul.s $f4, $f10, $f14
  div.s $f6, $f4, $f12
  add.s $f8, $f0, $f6
  b     .L7F070C98
   swc1  $f8, 0x40($s0)
  lwc1  $f10, 0x44($s0)
.L7F070C8C:
  swc1  $f24, 0x4c($s0)
  lwc1  $f2, 0xa4($s0)
  swc1  $f10, 0x40($s0)
.L7F070C98:
  lwc1  $f16, 0x40($s0)
.L7F070C9C:
  lw    $t6, 0x54($s0)
  mul.s $f4, $f2, $f16
  beqz  $t6, .L7F070D28
   add.s $f18, $f18, $f4
  lwc1  $f12, 0x7c($s0)
  c.lt.s $f24, $f12
  nop   
  bc1fl .L7F070D18
   lwc1  $f0, 0x70($s0)
  lwc1  $f6, 0x80($s0)
  add.s $f8, $f6, $f2
  swc1  $f8, 0x80($s0)
  lwc1  $f14, 0x80($s0)
  c.lt.s $f14, $f12
  nop   
  bc1fl .L7F070D08
   lwc1  $f4, 0x74($s0)
  lwc1  $f0, 0x78($s0)
  lwc1  $f10, 0x74($s0)
  lwc1  $f2, 0xa4($s0)
  sub.s $f4, $f10, $f0
  mul.s $f6, $f4, $f14
  div.s $f8, $f6, $f12
  add.s $f10, $f0, $f8
  b     .L7F070D14
   swc1  $f10, 0x70($s0)
  lwc1  $f4, 0x74($s0)
.L7F070D08:
  swc1  $f24, 0x7c($s0)
  lwc1  $f2, 0xa4($s0)
  swc1  $f4, 0x70($s0)
.L7F070D14:
  lwc1  $f0, 0x70($s0)
.L7F070D18:
  lwc1  $f6, 0x80($sp)
  mul.s $f8, $f2, $f0
  add.s $f10, $f6, $f8
  swc1  $f10, 0x80($sp)
.L7F070D28:
  lb    $t7, 0x26($s0)
  beql  $t7, $zero, .L7F070EC0
   addiu $s1, $s1, -1
  lw    $t8, 0x20($s0)
  c.le.s $f24, $f16
  lwc1  $f22, 0x3c($s0)
  lhu   $t9, 4($t8)
  lwc1  $f2, 0x90($s0)
  addiu $t0, $t9, -1
  mtc1  $t0, $f4
  bc1f  .L7F070D84
   cvt.s.w $f0, $f4
  c.le.s $f24, $f22
  mov.s $f20, $f0
  mov.s $f26, $f2
  bc1fl .L7F070DB0
   c.le.s $f24, $f16
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F070DB0
   c.le.s $f24, $f16
  b     .L7F070DAC
   mov.s $f20, $f22
.L7F070D84:
  c.le.s $f24, $f22
  mov.s $f20, $f2
  mov.s $f26, $f0
  bc1fl .L7F070DB0
   c.le.s $f24, $f16
  c.lt.s $f22, $f0
  nop   
  bc1fl .L7F070DB0
   c.le.s $f24, $f16
  mov.s $f26, $f22
.L7F070DAC:
  c.le.s $f24, $f16
.L7F070DB0:
  nop   
  bc1fl .L7F070DD0
   c.lt.s $f16, $f24
  c.le.s $f20, $f18
  nop   
  bc1tl .L7F070DF0
   lwc1  $f6, 0x4c($s0)
  c.lt.s $f16, $f24
.L7F070DD0:
  nop   
  bc1fl .L7F070EC0
   addiu $s1, $s1, -1
  c.le.s $f18, $f20
  nop   
  bc1fl .L7F070EC0
   addiu $s1, $s1, -1
  lwc1  $f6, 0x4c($s0)
.L7F070DF0:
  lwc1  $f28, 0x44($s0)
  lwc1  $f30, 0x48($s0)
  lw    $t1, 0x90($sp)
  swc1  $f6, 0x60($sp)
  lwc1  $f8, 0x50($s0)
  move  $a0, $s0
  beqz  $t1, .L7F070E34
   swc1  $f8, 0x5c($sp)
  lw    $a1, 0x28($s0)
  mfc1  $a2, $f20
  mfc1  $a3, $f24
  swc1  $f18, 0x84($sp)
  swc1  $f24, 0x10($sp)
  jal   sub_GAME_7F0701EC
   move  $a0, $s0
  b     .L7F070E48
   lwc1  $f18, 0x84($sp)
.L7F070E34:
  mfc1  $a1, $f20
  mfc1  $a2, $f24
  jal   sub_GAME_7F070090
   swc1  $f18, 0x84($sp)
  lwc1  $f18, 0x84($sp)
.L7F070E48:
  lwc1  $f10, 0x40($s0)
  lw    $a1, 0x20($s0)
  lb    $a2, 0x24($s0)
  swc1  $f10, 0x10($sp)
  lwc1  $f4, 0x94($s0)
  mfc1  $a3, $f26
  swc1  $f18, 0x84($sp)
  move  $a0, $s0
  jal   sub_GAME_7F06FCA8
   swc1  $f4, 0x14($sp)
  lwc1  $f18, 0x84($sp)
  li    $t2, 1
  sb    $t2, 0x26($s0)
  swc1  $f22, 0x3c($s0)
  swc1  $f28, 0x44($s0)
  swc1  $f30, 0x48($s0)
  lwc1  $f6, 0x60($sp)
  add.s $f10, $f26, $f18
  swc1  $f6, 0x4c($s0)
  lwc1  $f8, 0x5c($sp)
  swc1  $f8, 0x50($s0)
  swc1  $f18, 0x80($sp)
  lw    $v0, 0x98($s0)
  sub.s $f18, $f10, $f20
  beql  $v0, $zero, .L7F070EC0
   addiu $s1, $s1, -1
  jalr  $v0
  swc1  $f18, 0x84($sp)
  lwc1  $f18, 0x84($sp)
  addiu $s1, $s1, -1
.L7F070EC0:
  bgtzl $s1, .L7F070B44
   lwc1  $f2, 0xb0($s0)
  lw    $t3, 0x90($sp)
.L7F070ECC:
  mtc1  $zero, $f24
  lw    $v0, 0x54($s0)
  beqz  $t3, .L7F070F28
   nop   
  beqz  $v0, .L7F070F08
   lwc1  $f0, 0x28($s0)
  lwc1  $f4, 0x80($sp)
  mfc1  $a1, $f0
  mfc1  $a2, $f18
  lw    $a3, 0x58($s0)
  move  $a0, $s0
  jal   sub_GAME_7F0701EC
   swc1  $f4, 0x10($sp)
  b     .L7F070F58
   lw    $ra, 0x54($sp)
.L7F070F08:
  mfc1  $a1, $f0
  mfc1  $a2, $f18
  mfc1  $a3, $f24
  move  $a0, $s0
  jal   sub_GAME_7F0701EC
   swc1  $f24, 0x10($sp)
  b     .L7F070F58
   lw    $ra, 0x54($sp)
.L7F070F28:
  beqz  $v0, .L7F070F44
   move  $a0, $s0
  mfc1  $a1, $f18
  jal   sub_GAME_7F070090
   lw    $a2, 0x80($sp)
  b     .L7F070F58
   lw    $ra, 0x54($sp)
.L7F070F44:
  mfc1  $a1, $f18
  mfc1  $a2, $f24
  jal   sub_GAME_7F070090
   move  $a0, $s0
.L7F070F54:
  lw    $ra, 0x54($sp)
.L7F070F58:
  ldc1  $f20, 0x18($sp)
  ldc1  $f22, 0x20($sp)
  ldc1  $f24, 0x28($sp)
  ldc1  $f26, 0x30($sp)
  ldc1  $f28, 0x38($sp)
  ldc1  $f30, 0x40($sp)
  lw    $s0, 0x4c($sp)
  lw    $s1, 0x50($sp)
  jr    $ra
   addiu $sp, $sp, 0x88
");

asm(R"
glabel sub_GAME_7F070F80
  lw    $v1, 0xc($a0)
  lui   $t7, 0xe700
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  addiu $t6, $v1, 8
  sw    $t6, 0xc($a0)
  sw    $zero, 4($v1)
  sw    $t7, ($v1)
  lw    $v1, 0xc($a0)
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  addiu $t8, $v1, 8
  sw    $t8, 0xc($a0)
  sw    $zero, 4($v1)
  sw    $t9, ($v1)
  lw    $t0, 4($a0)
  lui   $t8, (0xFC121824 >> 16) # lui $t8, 0xfc12
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  beqz  $t0, .L7F070FF4
   ori   $t8, (0xFC121824 & 0xFFFF) # ori $t8, $t8, 0x1824
  lw    $v1, 0xc($a0)
  lui   $t2, (0xB900031D >> 16) # lui $t2, 0xb900
  lui   $t3, (0x00552078 >> 16) # lui $t3, 0x55
  addiu $t1, $v1, 8
  sw    $t1, 0xc($a0)
  ori   $t3, (0x00552078 & 0xFFFF) # ori $t3, $t3, 0x2078
  ori   $t2, (0xB900031D & 0xFFFF) # ori $t2, $t2, 0x31d
  sw    $t2, ($v1)
  b     .L7F071010
   sw    $t3, 4($v1)
.L7F070FF4:
  lw    $v1, 0xc($a0)
  lui   $t6, (0x00552048 >> 16) # lui $t6, 0x55
  ori   $t6, (0x00552048 & 0xFFFF) # ori $t6, $t6, 0x2048
  addiu $t4, $v1, 8
  sw    $t4, 0xc($a0)
  sw    $t6, 4($v1)
  sw    $t5, ($v1)
.L7F071010:
  lw    $v1, 0xc($a0)
  lui   $t9, (0xFF33FFFF >> 16) # lui $t9, 0xff33
  ori   $t9, (0xFF33FFFF & 0xFFFF) # ori $t9, $t9, 0xffff
  addiu $t7, $v1, 8
  sw    $t7, 0xc($a0)
  sw    $t9, 4($v1)
  jr    $ra
   sw    $t8, ($v1)
");

asm(R"
glabel sub_GAME_7F071030 /*DisplayListSetup(obj)*/
  lw    $v0, 0x30($a0)    /*a0=obj?*/
  li    $at, 7
  bnel  $v0, $at, .L7F0711EC      /*obj.ModelType <= 7? */
   li    $at, 8
  beql  $a1, $zero, .L7F071194    /*a1 = */
   lw    $t9, 4($a0)
  lw    $v0, 0xc($a0)
  lui   $t7, 0xe700
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t7, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402 /*2Cycle*/
  lui   $t4, 0x10
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t4, 4($v0)
  sw    $t9, ($v0)
  lw    $t2, 0x38($a0)
  lw    $v0, 0xc($a0)
  lui   $t7, 0xf800
  srl   $t0, $t2, 0x10
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  andi  $t4, $t0, 0xff
  srl   $t8, $t2, 0x18
  sll   $t9, $t8, 0x18
  sll   $t5, $t4, 0x10
  srl   $t1, $t2, 8
  sw    $t7, ($v0)
  andi  $t7, $t1, 0xff
  or    $t6, $t9, $t5
  sll   $t8, $t7, 8
  or    $t4, $t6, $t8
  andi  $t9, $t2, 0xff
  or    $t5, $t4, $t9
  sw    $t5, 4($v0)
  lw    $v1, 0x34($a0)
  lw    $v0, 0xc($a0)
  lui   $t6, 0xfb00
  srl   $t0, $v1, 0x10
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  andi  $t9, $t0, 0xff
  srl   $a3, $v1, 0x18
  srl   $t1, $v1, 8
  sw    $t6, ($v0)
  andi  $t6, $t1, 0xff
  sll   $t4, $a3, 0x18
  sll   $t5, $t9, 0x10
  or    $t7, $t4, $t5
  sll   $t8, $t6, 8
  or    $t9, $t7, $t8
  ori   $t4, $t9, 0xff
  sw    $t4, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t7, (0x5FFEDBF8 >> 16) # lui $t7, 0x5ffe    /*fulldl guard */
  lui   $t6, (0xFC159804 >> 16) # lui $t6, 0xfc15
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t6, (0xFC159804 & 0xFFFF) # ori $t6, $t6, 0x9804
  ori   $t7, (0x5FFEDBF8 & 0xFFFF) # ori $t7, $t7, 0xdbf8
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  lw    $t8, 4($a0)
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  beqz  $t8, .L7F071170
   ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC4112078 >> 16) # lui $t5, 0xc411
  ori   $t5, (0xC4112078 & 0xFFFF) # ori $t5, $t5, 0x2078
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  sw    $t4, ($v0)
  jr    $ra
   sw    $t5, 4($v0)

.L7F071170:
  lw    $v0, 0xc($a0)
  lui   $t8, (0xC4112048 >> 16) # lui $t8, 0xc411
  ori   $t8, (0xC4112048 & 0xFFFF) # ori $t8, $t8, 0x2048
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t8, 4($v0)
  jr    $ra
   sw    $t7, ($v0)

  lw    $t9, 4($a0)
.L7F071194: /*UseZ - Transparent Gun Rendermode*/
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  beqz  $t9, .L7F0711C8
   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC41049D8 >> 16) # lui $t6, 0xc410
  ori   $t6, (0xC41049D8 & 0xFFFF) # ori $t6, $t6, 0x49d8
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  sw    $t5, ($v0)
  jr    $ra
   sw    $t6, 4($v0)

.L7F0711C8: /*not UseZ - Opaque Gun Rendermode*/
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
  ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t9, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

  li    $at, 8
.L7F0711EC:
  bnel  $v0, $at, .L7F07134C
   li    $at, 9
  beqz  $a1, .L7F071B3C
   nop   
  lw    $v0, 0xc($a0)
  lui   $t5, 0xe700
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t5, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  lui   $t8, 0x10
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t8, 4($v0)       /*add to t7 = */
  sw    $t7, ($v0)        /*0xBA00140200000010 2cycle*/
  lw    $t2, 0x38($a0)
  lw    $v0, 0xc($a0)
  lui   $t5, 0xf800       /*fogcolour*/
  srl   $t0, $t2, 0x10
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  andi  $t8, $t0, 0xff
  srl   $t6, $t2, 0x18
  sll   $t7, $t6, 0x18
  sll   $t9, $t8, 0x10
  srl   $t1, $t2, 8
  sw    $t5, ($v0)        /*black*/
  andi  $t5, $t1, 0xff
  or    $t4, $t7, $t9
  sll   $t6, $t5, 8
  or    $t8, $t4, $t6
  andi  $t7, $t2, 0xff
  or    $t9, $t8, $t7
  sw    $t9, 4($v0)
  lw    $t2, 0x34($a0)
  lw    $v0, 0xc($a0)
  lui   $t6, 0xfb00       /*envcolour*/
  srl   $t0, $t2, 0x10
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  andi  $t9, $t0, 0xff
  srl   $t8, $t2, 0x18
  sll   $t7, $t8, 0x18
  sll   $t5, $t9, 0x10
  srl   $t1, $t2, 8
  sw    $t6, ($v0)        /*black*/
  andi  $t6, $t1, 0xff
  or    $t4, $t7, $t5
  sll   $t8, $t6, 8
  or    $t9, $t4, $t8
  andi  $t7, $t2, 0xff
  or    $t5, $t9, $t7
  sw    $t5, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t8, (0x5FFEFFF8 >> 16) # lui $t8, 0x5ffe
  lui   $t4, (0xFC159A04 >> 16) # lui $t4, 0xfc15
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t4, (0xFC159A04 & 0xFFFF) # ori $t4, $t4, 0x9a04
  ori   $t8, (0x5FFEFFF8 & 0xFFFF) # ori $t8, $t8, 0xfff8
  sw    $t8, 4($v0)
  sw    $t4, ($v0)
  lw    $t9, 4($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  beqz  $t9, .L7F071328
   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC41049D8 >> 16) # lui $t6, 0xc410
  ori   $t6, (0xC41049D8 & 0xFFFF) # ori $t6, $t6, 0x49d8
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d  /*Transparent Gun Rendermode Z*/
  sw    $t5, ($v0)
  jr    $ra
   sw    $t6, 4($v0)

.L7F071328:
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
  ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8 /*transparent Gun rendermode NoZ*/
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t9, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

  li    $at, 9
.L7F07134C:
  bnel  $v0, $at, .L7F0716C8
   li    $at, 4
  lw    $t7, 0x34($a0)
  andi  $t5, $t7, 0xff
  bnez  $t5, .L7F071500
   nop   
  beqz  $a1, .L7F0714A8
   lui   $t8, 0xe700
  lw    $v0, 0xc($a0)
  lw    $t0, 0x38($a0)
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  lui   $t5, 0x10
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t5, 4($v0)       /*add to t4 =*/
  sw    $t7, ($v0)        /*2cycle*/
  lw    $v0, 0xc($a0)
  srl   $a2, $t0, 0x10
  andi  $t7, $a2, 0xff
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  lui   $t4, 0xf800       /*fogcolour*/
  srl   $a1, $t0, 0x18
  sll   $t9, $a1, 0x18
  sll   $t5, $t7, 0x10
  srl   $a3, $t0, 8
  sw    $t4, ($v0)        /*black*/
  andi  $t4, $a3, 0xff
  or    $t6, $t9, $t5
  sll   $t8, $t4, 8
  or    $t7, $t6, $t8
  andi  $t9, $t0, 0xff
  or    $t5, $t7, $t9
  sw    $t5, 4($v0)
  lw    $v0, 0xc($a0)
  li    $t8, -1
  lui   $t6, 0xfb00       /*envcolour*/
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t8, 4($v0)
  sw    $t6, ($v0)        /*black*/
  lw    $v0, 0xc($a0)
  lui   $t9, 0xfa00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t9, ($v0)
  lw    $t5, 0x34($a0)
  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
  ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004     /*prop combiner*/
  srl   $t6, $t5, 8
  andi  $t8, $t6, 0xff
  sw    $t8, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t5, (0x1F1093FB >> 16) # lui $t5, 0x1f10
  ori   $t5, (0x1F1093FB & 0xFFFF) # ori $t5, $t5, 0x93fb
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t9, ($v0)
  lw    $t4, 4($a0)
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  beqz  $t4, .L7F071488
   ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t7, (0xC4112078 >> 16) # lui $t7, 0xc411
  ori   $t7, (0xC4112078 & 0xFFFF) # ori $t7, $t7, 0x2078     /*primary prop useZ rendermode*/
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  sw    $t8, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F071488: /*Not UseZ*/
  lw    $v0, 0xc($a0)
  lui   $t4, (0xC4112048 >> 16) # lui $t4, 0xc411
  ori   $t4, (0xC4112048 & 0xFFFF) # ori $t4, $t4, 0x2048 /*primary prop noz rendermode*/
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t4, 4($v0)
  jr    $ra
   sw    $t5, ($v0)

.L7F0714A8: /*sec UseZ*/
  lw    $t6, 4($a0)
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F0714E0
   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC41049D8 >> 16) # lui $t9, 0xc410
  ori   $t9, (0xC41049D8 & 0xFFFF) # ori $t9, $t9, 0x49d8
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t9, 4($v0)

.L7F0714E0: /*Sec Not UseZ*/
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
  ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t4, ($v0)

.L7F071500:
  beqz  $a1, .L7F071624
   lui   $t9, 0xe700
  lw    $v0, 0xc($a0)
  lw    $t0, 0x38($a0)
  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t9, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
  lui   $t6, 0x10     /*add to t4 = */
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t6, 4($v0)
  sw    $t4, ($v0)       /*2cycle*/
  lw    $v0, 0xc($a0)
  srl   $a2, $t0, 0x10
  andi  $t4, $a2, 0xff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  lui   $t7, 0xf800
  srl   $a1, $t0, 0x18
  sll   $t5, $a1, 0x18
  sll   $t6, $t4, 0x10
  srl   $a3, $t0, 8
  sw    $t7, ($v0)
  andi  $t7, $a3, 0xff
  or    $t8, $t5, $t6
  sll   $t9, $t7, 8
  or    $t4, $t8, $t9
  andi  $t5, $t0, 0xff
  or    $t6, $t4, $t5
  sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t8, 0xfb00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t8, ($v0)
  lw    $t4, 0x34($a0)
  lui   $t8, (0x1FFCFBF8 >> 16) # lui $t8, 0x1ffc
  lui   $t7, (0xFC26E804 >> 16) # lui $t7, 0xfc26
  andi  $t5, $t4, 0xff
  sw    $t5, 4($v0)
  lw    $v0, 0xc($a0)
  ori   $t7, (0xFC26E804 & 0xFFFF) # ori $t7, $t7, 0xe804
  ori   $t8, (0x1FFCFBF8 & 0xFFFF) # ori $t8, $t8, 0xfbf8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t8, 4($v0)
  sw    $t7, ($v0)
  lw    $t9, 4($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  beqz  $t9, .L7F071604
   ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC4113078 >> 16) # lui $t6, 0xc411
  ori   $t6, (0xC4113078 & 0xFFFF) # ori $t6, $t6, 0x3078
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  sw    $t5, ($v0)
  jr    $ra
   sw    $t6, 4($v0)

.L7F071604:
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC4113048 >> 16) # lui $t9, 0xc411
  ori   $t9, (0xC4113048 & 0xFFFF) # ori $t9, $t9, 0x3048
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t9, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

.L7F071624:
  lw    $v0, 0xc($a0)
  lui   $t5, 0xfa00
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t5, ($v0)
  lw    $t6, 0x34($a0)
  lui   $t5, (0xFC26C204 >> 16) # lui $t5, 0xfc26
  ori   $t5, (0xFC26C204 & 0xFFFF) # ori $t5, $t5, 0xc204
  srl   $t8, $t6, 8
  andi  $t9, $t8, 0xff
  sw    $t9, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t6, (0x1FCCDFF8 >> 16) # lui $t6, 0x1fcc
  ori   $t6, (0x1FCCDFF8 & 0xFFFF) # ori $t6, $t6, 0xdff8
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t6, 4($v0)
  sw    $t5, ($v0)
  lw    $t7, 4($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  beqz  $t7, .L7F0716A4
   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t4, (0xC4113078 >> 16) # lui $t4, 0xc411
  ori   $t4, (0xC4113078 & 0xFFFF) # ori $t4, $t4, 0x3078
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  jr    $ra
   sw    $t4, 4($v0)

.L7F0716A4:
  lw    $v0, 0xc($a0)
  lui   $t7, (0xC4113048 >> 16) # lui $t7, 0xc411
  ori   $t7, (0xC4113048 & 0xFFFF) # ori $t7, $t7, 0x3048
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t7, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

  li    $at, 4
.L7F0716C8:
  bnel  $v0, $at, .L7F071830
   li    $at, 5
  beqz  $a1, .L7F0717D4
   lui   $t4, 0xe700
  lw    $v0, 0xc($a0)
  lw    $t0, 0x34($a0)
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t4, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  lui   $t7, 0x10
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t7, 4($v0)
  sw    $t6, ($v0)
  lw    $v0, 0xc($a0)
  srl   $a2, $t0, 0x10
  andi  $t6, $a2, 0xff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  lui   $t9, 0xf800
  srl   $a1, $t0, 0x18
  sll   $t5, $a1, 0x18
  sll   $t7, $t6, 0x10
  srl   $a3, $t0, 8
  sw    $t9, ($v0)
  andi  $t9, $a3, 0xff
  or    $t8, $t5, $t7
  sll   $t4, $t9, 8
  or    $t6, $t8, $t4
  andi  $t5, $t0, 0xff
  or    $t7, $t6, $t5
  sw    $t7, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t4, (0x1F1093FF >> 16) # lui $t4, 0x1f10
  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
  ori   $t4, (0x1F1093FF & 0xFFFF) # ori $t4, $t4, 0x93ff
  sw    $t4, 4($v0)
  sw    $t8, ($v0)
  lw    $t6, 4($a0)
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F0717B4
   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC4112078 >> 16) # lui $t9, 0xc411
  ori   $t9, (0xC4112078 & 0xFFFF) # ori $t9, $t9, 0x2078
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t9, 4($v0)

.L7F0717B4:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC4112048 >> 16) # lui $t6, 0xc411
  ori   $t6, (0xC4112048 & 0xFFFF) # ori $t6, $t6, 0x2048
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t4, ($v0)

.L7F0717D4:
  lw    $t5, 4($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  beqz  $t5, .L7F07180C
   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  jr    $ra
   sw    $t8, 4($v0)

.L7F07180C:
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
  ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t5, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

  li    $at, 5
.L7F071830:
  bne   $v0, $at, .L7F071A30
   nop   
  beql  $a1, $zero, .L7F0719D4
   lw    $t9, 0x34($a0)
  lw    $v0, 0xc($a0)
  lui   $t9, 0xe700
  lui   $t4, (0xBA001402 >> 16) # lui $t4, 0xba00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t9, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t4, (0xBA001402 & 0xFFFF) # ori $t4, $t4, 0x1402
  lui   $t6, 0x10
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t6, 4($v0)
  sw    $t4, ($v0)
  lw    $t2, 0x38($a0)
  lw    $v0, 0xc($a0)
  lui   $t9, 0xf800
  srl   $t0, $t2, 0x10
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  andi  $t6, $t0, 0xff
  srl   $t8, $t2, 0x18
  sll   $t4, $t8, 0x18
  sll   $t5, $t6, 0x10
  srl   $t1, $t2, 8
  sw    $t9, ($v0)
  andi  $t9, $t1, 0xff
  or    $t7, $t4, $t5
  sll   $t8, $t9, 8
  or    $t6, $t7, $t8
  andi  $t4, $t2, 0xff
  or    $t5, $t6, $t4
  sw    $t5, 4($v0)
  lw    $t9, 0x34($a0)
  lui   $t6, (0xFC26A004 >> 16) # lui $t6, 0xfc26
  ori   $t6, (0xFC26A004 & 0xFFFF) # ori $t6, $t6, 0xa004
  andi  $t7, $t9, 0xff
  slti  $at, $t7, 0xff
  beqz  $at, .L7F07195C
   andi  $t4, $t7, 0xff
  lw    $v0, 0xc($a0)
  li    $at, -256
  or    $t5, $t4, $at
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  lui   $t6, 0xfb00
  sw    $t6, ($v0)
  sw    $t5, 4($v0)
  lw    $t9, 0x34($a0)
  lui   $t6, (0xFC26EA04 >> 16) # lui $t6, 0xfc26
  ori   $t6, (0xFC26EA04 & 0xFFFF) # ori $t6, $t6, 0xea04
  andi  $t7, $t9, 0xff00
  beqz  $t7, .L7F071938
   lui   $t9, (0xFC26EA04 >> 16) # lui $t9, 0xfc26
  lw    $v0, 0xc($a0)
  lui   $t4, (0x1F10CFFF >> 16) # lui $t4, 0x1f10
  ori   $t4, (0x1F10CFFF & 0xFFFF) # ori $t4, $t4, 0xcfff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t4, 4($v0)
  b     .L7F071978
   sw    $t6, ($v0)
.L7F071938:
  lw    $v0, 0xc($a0)
  lui   $t7, (0x1F10FFFF >> 16) # lui $t7, 0x1f10
  ori   $t7, (0x1F10FFFF & 0xFFFF) # ori $t7, $t7, 0xffff
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t9, (0xFC26EA04 & 0xFFFF) # ori $t9, $t9, 0xea04
  sw    $t9, ($v0)
  b     .L7F071978
   sw    $t7, 4($v0)
.L7F07195C:
  lw    $v0, 0xc($a0)
  lui   $t4, (0x1F1093FF >> 16) # lui $t4, 0x1f10
  ori   $t4, (0x1F1093FF & 0xFFFF) # ori $t4, $t4, 0x93ff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t4, 4($v0)
  sw    $t6, ($v0)
.L7F071978:
  lw    $t5, 4($a0)
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t5, .L7F0719B0
   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t8, 4($v0)

.L7F0719B0:
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
  ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t5, 4($v0)
  jr    $ra
   sw    $t4, ($v0)

  lw    $t9, 0x34($a0)
.L7F0719D4:
  lui   $t6, (0xFC269A04 >> 16) # lui $t6, 0xfc26
  ori   $t6, (0xFC269A04 & 0xFFFF) # ori $t6, $t6, 0x9a04
  andi  $t7, $t9, 0xff
  slti  $at, $t7, 0xff
  beqz  $at, .L7F071A0C
   lui   $t9, 0xfc26
  lw    $v0, 0xc($a0)
  lui   $t4, (0x1F10FFFF >> 16) # lui $t4, 0x1f10
  ori   $t4, (0x1F10FFFF & 0xFFFF) # ori $t4, $t4, 0xffff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t4, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

.L7F071A0C:
  lw    $v0, 0xc($a0)
  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t9, $t9, 0xa004
  sw    $t9, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F071A30:
  beqz  $a1, .L7F071AE8
   lui   $t6, 0xe700
  lw    $v0, 0xc($a0)
  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t6, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t9, 0x10
  lui   $t6, (0x1F1093FF >> 16) # lui $t6, 0x1f10
  addiu $t4, $v0, 8
  sw    $t4, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t5, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  ori   $t6, (0x1F1093FF & 0xFFFF) # ori $t6, $t6, 0x93ff
  sw    $t6, 4($v0)
  sw    $t8, ($v0)
  lw    $t4, 4($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  beqz  $t4, .L7F071AC8
   ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t7, (0x0C192078 >> 16) # lui $t7, 0xc19
  ori   $t7, (0x0C192078 & 0xFFFF) # ori $t7, $t7, 0x2078
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F071AC8:
  lw    $v0, 0xc($a0)
  lui   $t4, (0x0C192048 >> 16) # lui $t4, 0xc19
  ori   $t4, (0x0C192048 & 0xFFFF) # ori $t4, $t4, 0x2048
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t4, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

.L7F071AE8:
  lw    $t5, 4($a0)
  lui   $t4, (0xB900031D >> 16) # lui $t4, 0xb900
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t5, .L7F071B20
   ori   $t4, (0xB900031D & 0xFFFF) # ori $t4, $t4, 0x31d
  lw    $v0, 0xc($a0)
  lui   $t8, (0x0C1849D8 >> 16) # lui $t8, 0xc18
  ori   $t8, (0x0C1849D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t8, 4($v0)

.L7F071B20:
  lw    $v0, 0xc($a0)
  lui   $t5, (0x0C1841C8 >> 16) # lui $t5, 0xc18
  ori   $t5, (0x0C1841C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t4, ($v0)
.L7F071B3C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F071B44
  lw    $v0, 0x30($a0)
  li    $at, 7
  bnel  $v0, $at, .L7F071CFC
   li    $at, 8
  lw    $v0, 0xc($a0)
  lui   $t7, 0xe700
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t7, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  lui   $t5, 0x10
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t9, ($v0)
  lw    $v0, 0xc($a0)
  lw    $t3, 0x38($a0)
  lui   $t9, 0xf800
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  srl   $t1, $t3, 0x10
  andi  $t7, $t1, 0xff
  srl   $t0, $t3, 0x18
  sll   $t6, $t0, 0x18
  sll   $t8, $t7, 0x10
  sw    $t9, ($v0)
  srl   $t2, $t3, 8
  andi  $t5, $t2, 0xff
  or    $t9, $t6, $t8
  sll   $t7, $t5, 8
  or    $t6, $t9, $t7
  andi  $t8, $t3, 0xff
  or    $t5, $t6, $t8
  sw    $t5, 4($v0)
  lw    $v1, 0x34($a0)
  lw    $v0, 0xc($a0)
  lui   $t6, 0xfb00
  srl   $t1, $v1, 0x10
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  andi  $t9, $t1, 0xff
  srl   $t8, $v1, 0x18
  sll   $t5, $t8, 0x18
  sll   $t7, $t9, 0x10
  srl   $t2, $v1, 8
  andi  $t8, $t2, 0xff
  sw    $t6, ($v0)
  or    $t6, $t5, $t7
  sll   $t9, $t8, 8
  or    $t5, $t6, $t9
  ori   $t7, $t5, 0xff
  sw    $t7, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t9, (0x5FFEDBF8 >> 16) # lui $t9, 0x5ffe
  lui   $t6, (0xFC159804 >> 16) # lui $t6, 0xfc15
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t6, (0xFC159804 & 0xFFFF) # ori $t6, $t6, 0x9804
  ori   $t9, (0x5FFEDBF8 & 0xFFFF) # ori $t9, $t9, 0xdbf8
  sw    $t9, 4($v0)
  beqz  $a1, .L7F071CA0
   sw    $t6, ($v0)
  lw    $t5, 4($a0)
  lui   $t7, (0xC4112048 >> 16) # lui $t7, 0xc411
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  beqz  $t5, .L7F071C80
   ori   $t7, (0xC4112048 & 0xFFFF) # ori $t7, $t7, 0x2048
  lw    $v0, 0xc($a0)
  lui   $t6, (0xC4112078 >> 16) # lui $t6, 0xc411
  ori   $t6, (0xC4112078 & 0xFFFF) # ori $t6, $t6, 0x2078
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  sw    $t8, ($v0)
  jr    $ra
   sw    $t6, 4($v0)

.L7F071C80:
  lw    $v0, 0xc($a0)
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t7, 4($v0)
  jr    $ra
   sw    $t5, ($v0)

.L7F071CA0:
  lw    $t8, 4($a0)
  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  beqz  $t8, .L7F071CD8
   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC41049D8 >> 16) # lui $t5, 0xc410
  ori   $t5, (0xC41049D8 & 0xFFFF) # ori $t5, $t5, 0x49d8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  sw    $t9, ($v0)
  jr    $ra
   sw    $t5, 4($v0)

.L7F071CD8:
  lw    $v0, 0xc($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

  li    $at, 8
.L7F071CFC:
  bnel  $v0, $at, .L7F071E54
   li    $at, 9
  lw    $v0, 0xc($a0)
  lui   $t5, 0xe700
  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t5, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
  lui   $t6, 0x10
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t6, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  lw    $t2, 0x38($a0)
  lui   $t8, 0xf800
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  srl   $t0, $t2, 0x10
  andi  $t5, $t0, 0xff
  srl   $a3, $t2, 0x18
  sll   $t9, $a3, 0x18
  sll   $t7, $t5, 0x10
  sw    $t8, ($v0)
  srl   $t1, $t2, 8
  andi  $t6, $t1, 0xff
  or    $t8, $t9, $t7
  sll   $t5, $t6, 8
  or    $t9, $t8, $t5
  andi  $t7, $t2, 0xff
  or    $t6, $t9, $t7
  sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lw    $t2, 0x34($a0)
  lui   $t7, 0xfb00
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  srl   $t0, $t2, 0x10
  andi  $t5, $t0, 0xff
  srl   $a3, $t2, 0x18
  sll   $t8, $a3, 0x18
  sll   $t9, $t5, 0x10
  sw    $t7, ($v0)
  srl   $t1, $t2, 8
  andi  $t6, $t1, 0xff
  or    $t7, $t8, $t9
  sll   $t5, $t6, 8
  or    $t8, $t7, $t5
  andi  $t9, $t2, 0xff
  or    $t6, $t8, $t9
  sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t8, (0x5FFEFFF8 >> 16) # lui $t8, 0x5ffe
  lui   $t5, (0xFC159A04 >> 16) # lui $t5, 0xfc15
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  ori   $t5, (0xFC159A04 & 0xFFFF) # ori $t5, $t5, 0x9a04
  ori   $t8, (0x5FFEFFF8 & 0xFFFF) # ori $t8, $t8, 0xfff8
  sw    $t8, 4($v0)
  sw    $t5, ($v0)
  lw    $t9, 4($a0)
  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t9, .L7F071E30
   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC41049D8 >> 16) # lui $t5, 0xc410
  ori   $t5, (0xC41049D8 & 0xFFFF) # ori $t5, $t5, 0x49d8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t5, 4($v0)

.L7F071E30:
  lw    $v0, 0xc($a0)
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t9, ($v0)

  li    $at, 9
.L7F071E54:
  bnel  $v0, $at, .L7F0721F0
   li    $at, 4
  lw    $t7, 0x34($a0)
  lui   $t9, 0x10
  lui   $t8, 0xe700
  andi  $t5, $t7, 0xff
  bnez  $t5, .L7F072030
   lui   $t7, 0x10
  lw    $v0, 0xc($a0)
  lw    $t1, 0x38($a0)
  lui   $t7, 0xe700
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t7, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t8, (0xBA001402 >> 16) # lui $t8, 0xba00
  ori   $t8, (0xBA001402 & 0xFFFF) # ori $t8, $t8, 0x1402
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  srl   $a3, $t1, 0x10
  andi  $t9, $a3, 0xff
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  lui   $t7, 0xf800
  srl   $a2, $t1, 0x18
  sll   $t8, $a2, 0x18
  sll   $t6, $t9, 0x10
  srl   $t0, $t1, 8
  sw    $t7, ($v0)
  or    $t7, $t8, $t6
  andi  $t5, $t0, 0xff
  sll   $t9, $t5, 8
  or    $t8, $t7, $t9
  andi  $t6, $t1, 0xff
  or    $t5, $t8, $t6
  sw    $t5, 4($v0)
  lw    $v0, 0xc($a0)
  li    $t8, -1
  lui   $t9, 0xfb00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t8, 4($v0)
  sw    $t9, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t5, 0xfa00
  lui   $t9, (0x1F1093FB >> 16) # lui $t9, 0x1f10
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t5, ($v0)
  lw    $t7, 0x34($a0)
  ori   $t9, (0x1F1093FB & 0xFFFF) # ori $t9, $t9, 0x93fb
  srl   $t8, $t7, 8
  andi  $t6, $t8, 0xff
  beqz  $a1, .L7F071FBC
   sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
  lui   $t9, (0x1F1093FB >> 16) # lui $t9, 0x1f10
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t9, (0x1F1093FB & 0xFFFF) # ori $t9, $t9, 0x93fb
  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
  sw    $t7, ($v0)
  sw    $t9, 4($v0)
  lw    $t8, 4($a0)
  lui   $t6, (0xC4112048 >> 16) # lui $t6, 0xc411
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  beqz  $t8, .L7F071F9C
   ori   $t6, (0xC4112048 & 0xFFFF) # ori $t6, $t6, 0x2048
  lw    $v0, 0xc($a0)
  lui   $t7, (0xC4112078 >> 16) # lui $t7, 0xc411
  ori   $t7, (0xC4112078 & 0xFFFF) # ori $t7, $t7, 0x2078
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  sw    $t5, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F071F9C:
  lw    $v0, 0xc($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

.L7F071FBC:
  lw    $v0, 0xc($a0)
  lui   $t7, (0xFC26A004 >> 16) # lui $t7, 0xfc26
  ori   $t7, (0xFC26A004 & 0xFFFF) # ori $t7, $t7, 0xa004
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t7, ($v0)
  lw    $t8, 4($a0)
  lui   $t6, (0xC41041C8 >> 16) # lui $t6, 0xc410
  lui   $t5, (0xB900031D >> 16) # lui $t5, 0xb900
  beqz  $t8, .L7F072010
   ori   $t6, (0xC41041C8 & 0xFFFF) # ori $t6, $t6, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t7, (0xC41049D8 >> 16) # lui $t7, 0xc410
  ori   $t7, (0xC41049D8 & 0xFFFF) # ori $t7, $t7, 0x49d8
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t5, (0xB900031D & 0xFFFF) # ori $t5, $t5, 0x31d
  sw    $t5, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F072010:
  lw    $v0, 0xc($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

.L7F072030:
  lw    $v0, 0xc($a0)
  lw    $t1, 0x38($a0)
  lui   $t5, (0xBA001402 >> 16) # lui $t5, 0xba00
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t5, (0xBA001402 & 0xFFFF) # ori $t5, $t5, 0x1402
  srl   $a3, $t1, 0x10
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  sw    $t7, 4($v0)
  sw    $t5, ($v0)
  lw    $v0, 0xc($a0)
  andi  $t7, $a3, 0xff
  lui   $t8, 0xf800
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  srl   $a2, $t1, 0x18
  sll   $t5, $a2, 0x18
  sll   $t9, $t7, 0x10
  srl   $t0, $t1, 8
  sw    $t8, ($v0)
  or    $t8, $t5, $t9
  andi  $t6, $t0, 0xff
  sll   $t7, $t6, 8
  or    $t5, $t8, $t7
  andi  $t9, $t1, 0xff
  or    $t6, $t5, $t9
  sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t7, 0xfb00
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t7, ($v0)
  lw    $t9, 0x34($a0)
  lui   $t7, (0xFC26E804 >> 16) # lui $t7, 0xfc26
  ori   $t7, (0xFC26E804 & 0xFFFF) # ori $t7, $t7, 0xe804
  andi  $t6, $t9, 0xff
  beqz  $a1, .L7F07214C
   sw    $t6, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t5, (0x1FFCFBF8 >> 16) # lui $t5, 0x1ffc
  ori   $t5, (0x1FFCFBF8 & 0xFFFF) # ori $t5, $t5, 0xfbf8
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t7, ($v0)
  lw    $t9, 4($a0)
  lui   $t6, (0xC4113048 >> 16) # lui $t6, 0xc411
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  beqz  $t9, .L7F07212C
   ori   $t6, (0xC4113048 & 0xFFFF) # ori $t6, $t6, 0x3048
  lw    $v0, 0xc($a0)
  lui   $t7, (0xC4113078 >> 16) # lui $t7, 0xc411
  ori   $t7, (0xC4113078 & 0xFFFF) # ori $t7, $t7, 0x3078
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  sw    $t8, ($v0)
  jr    $ra
   sw    $t7, 4($v0)

.L7F07212C:
  lw    $v0, 0xc($a0)
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t6, 4($v0)
  jr    $ra
   sw    $t9, ($v0)

.L7F07214C:
  lw    $v0, 0xc($a0)
  lui   $t7, 0xfa00
  lui   $t9, (0x1FCCDFF8 >> 16) # lui $t9, 0x1fcc
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t7, ($v0)
  lw    $t5, 0x34($a0)
  ori   $t9, (0x1FCCDFF8 & 0xFFFF) # ori $t9, $t9, 0xdff8
  srl   $t6, $t5, 8
  andi  $t8, $t6, 0xff
  sw    $t8, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t5, (0xFC26C204 >> 16) # lui $t5, 0xfc26
  ori   $t5, (0xFC26C204 & 0xFFFF) # ori $t5, $t5, 0xc204
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t5, ($v0)
  lw    $t6, 4($a0)
  lui   $t8, (0xC4113048 >> 16) # lui $t8, 0xc411
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F0721CC
   ori   $t8, (0xC4113048 & 0xFFFF) # ori $t8, $t8, 0x3048
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC4113078 >> 16) # lui $t5, 0xc411
  ori   $t5, (0xC4113078 & 0xFFFF) # ori $t5, $t5, 0x3078
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t5, 4($v0)

.L7F0721CC:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t8, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

  li    $at, 4
.L7F0721F0:
  bne   $v0, $at, .L7F072350
   lui   $t6, 0xe700
  lw    $v0, 0xc($a0)
  lw    $t1, 0x34($a0)
  lui   $t7, (0xBA001402 >> 16) # lui $t7, 0xba00
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t6, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t7, (0xBA001402 & 0xFFFF) # ori $t7, $t7, 0x1402
  lui   $t5, 0x10
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t7, ($v0)
  lw    $v0, 0xc($a0)
  srl   $a3, $t1, 0x10
  andi  $t5, $a3, 0xff
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  lui   $t6, 0xf800
  srl   $a2, $t1, 0x18
  sll   $t7, $a2, 0x18
  sll   $t9, $t5, 0x10
  srl   $t0, $t1, 8
  sw    $t6, ($v0)
  or    $t6, $t7, $t9
  andi  $t8, $t0, 0xff
  sll   $t5, $t8, 8
  or    $t7, $t6, $t5
  andi  $t9, $t1, 0xff
  or    $t8, $t7, $t9
  sw    $t8, 4($v0)
  lw    $v0, 0xc($a0)
  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
  lui   $t5, (0xFC26A004 >> 16) # lui $t5, 0xfc26
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t5, (0xFC26A004 & 0xFFFF) # ori $t5, $t5, 0xa004
  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
  sw    $t7, 4($v0)
  beqz  $a1, .L7F0722F8
   sw    $t5, ($v0)
  lw    $t9, 4($a0)
  lui   $t8, (0xC4112048 >> 16) # lui $t8, 0xc411
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  beqz  $t9, .L7F0722D8
   ori   $t8, (0xC4112048 & 0xFFFF) # ori $t8, $t8, 0x2048
  lw    $v0, 0xc($a0)
  lui   $t5, (0xC4112078 >> 16) # lui $t5, 0xc411
  ori   $t5, (0xC4112078 & 0xFFFF) # ori $t5, $t5, 0x2078
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  sw    $t6, ($v0)
  jr    $ra
   sw    $t5, 4($v0)

.L7F0722D8:
  lw    $v0, 0xc($a0)
  lui   $t9, (0xB900031D >> 16) # lui $t9, 0xb900
  ori   $t9, (0xB900031D & 0xFFFF) # ori $t9, $t9, 0x31d
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t8, 4($v0)
  jr    $ra
   sw    $t9, ($v0)

.L7F0722F8:
  lw    $t6, 4($a0)
  lui   $t5, (0xC41041C8 >> 16) # lui $t5, 0xc410
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F072330
   ori   $t5, (0xC41041C8 & 0xFFFF) # ori $t5, $t5, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC41049D8 >> 16) # lui $t9, 0xc410
  ori   $t9, (0xC41049D8 & 0xFFFF) # ori $t9, $t9, 0x49d8
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t9, 4($v0)

.L7F072330:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t5, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

.L7F072350:
  li    $at, 5
  bne   $v0, $at, .L7F072518
   lui   $t8, 0xe700
  lw    $v0, 0xc($a0)
  lui   $t9, 0xe700
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t9, ($v0)
  lw    $v0, 0xc($a0)
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  lui   $t5, 0x10
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t6, ($v0)
  lw    $v0, 0xc($a0)
  lw    $t3, 0x38($a0)
  lui   $t6, 0xf800
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  srl   $t1, $t3, 0x10
  andi  $t9, $t1, 0xff
  srl   $t0, $t3, 0x18
  sll   $t7, $t0, 0x18
  sll   $t8, $t9, 0x10
  sw    $t6, ($v0)
  srl   $t2, $t3, 8
  andi  $t5, $t2, 0xff
  or    $t6, $t7, $t8
  sll   $t9, $t5, 8
  or    $t7, $t6, $t9
  andi  $t8, $t3, 0xff
  or    $t5, $t7, $t8
  sw    $t5, 4($v0)
  lw    $t6, 0x34($a0)
  lui   $t8, (0xFC26A004 >> 16) # lui $t8, 0xfc26
  ori   $t8, (0xFC26A004 & 0xFFFF) # ori $t8, $t8, 0xa004
  andi  $t9, $t6, 0xff
  slti  $at, $t9, 0xff
  beqz  $at, .L7F0724A4
   andi  $t5, $t9, 0xff
  lw    $v0, 0xc($a0)
  li    $at, -256
  or    $t6, $t5, $at
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  lui   $t8, 0xfb00
  sw    $t8, ($v0)
  beqz  $a1, .L7F07247C
   sw    $t6, 4($v0)
  lw    $t9, 0x34($a0)
  lui   $t8, (0x1F10FFFF >> 16) # lui $t8, 0x1f10
  lui   $t5, (0xFC26EA04 >> 16) # lui $t5, 0xfc26
  andi  $t7, $t9, 0xff00
  beqz  $t7, .L7F07245C
   ori   $t8, (0x1F10FFFF & 0xFFFF) # ori $t8, $t8, 0xffff
  lw    $v0, 0xc($a0)
  lui   $t6, (0x1F10CFFF >> 16) # lui $t6, 0x1f10
  ori   $t6, (0x1F10CFFF & 0xFFFF) # ori $t6, $t6, 0xcfff
  addiu $t8, $v0, 8
  sw    $t8, 0xc($a0)
  ori   $t5, (0xFC26EA04 & 0xFFFF) # ori $t5, $t5, 0xea04
  sw    $t5, ($v0)
  b     .L7F0724C0
   sw    $t6, 4($v0)
.L7F07245C:
  lw    $v0, 0xc($a0)
  lui   $t7, (0xFC26EA04 >> 16) # lui $t7, 0xfc26
  ori   $t7, (0xFC26EA04 & 0xFFFF) # ori $t7, $t7, 0xea04
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  sw    $t8, 4($v0)
  b     .L7F0724C0
   sw    $t7, ($v0)
.L7F07247C:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xFC269A04 >> 16) # lui $t6, 0xfc26
  lui   $t9, (0x1F10FFFF >> 16) # lui $t9, 0x1f10
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t9, (0x1F10FFFF & 0xFFFF) # ori $t9, $t9, 0xffff
  ori   $t6, (0xFC269A04 & 0xFFFF) # ori $t6, $t6, 0x9a04
  sw    $t6, ($v0)
  b     .L7F0724C0
   sw    $t9, 4($v0)
.L7F0724A4:
  lw    $v0, 0xc($a0)
  lui   $t5, (0x1F1093FF >> 16) # lui $t5, 0x1f10
  ori   $t5, (0x1F1093FF & 0xFFFF) # ori $t5, $t5, 0x93ff
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t8, ($v0)
.L7F0724C0:
  lw    $t6, 4($a0)
  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F0724F8
   ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t8, 4($v0)

.L7F0724F8:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t9, 4($v0)
  jr    $ra
   sw    $t6, ($v0)

.L7F072518:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xBA001402 >> 16) # lui $t6, 0xba00
  ori   $t6, (0xBA001402 & 0xFFFF) # ori $t6, $t6, 0x1402
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $zero, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t9, 0x10
  lui   $t8, 0xf800
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t6, ($v0)
  lw    $v0, 0xc($a0)
  li    $t5, -256
  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t5, 4($v0)
  sw    $t8, ($v0)
  lw    $v0, 0xc($a0)
  lui   $t7, (0x1F1093FF >> 16) # lui $t7, 0x1f10
  ori   $t7, (0x1F1093FF & 0xFFFF) # ori $t7, $t7, 0x93ff
  addiu $t6, $v0, 8
  sw    $t6, 0xc($a0)
  ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004
  sw    $t9, ($v0)
  beqz  $a1, .L7F0725E8
   sw    $t7, 4($v0)
  lw    $t8, 4($a0)
  lui   $t5, (0xC4112048 >> 16) # lui $t5, 0xc411
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  beqz  $t8, .L7F0725C8
   ori   $t5, (0xC4112048 & 0xFFFF) # ori $t5, $t5, 0x2048
  lw    $v0, 0xc($a0)
  lui   $t9, (0xC4112078 >> 16) # lui $t9, 0xc411
  ori   $t9, (0xC4112078 & 0xFFFF) # ori $t9, $t9, 0x2078
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  sw    $t6, ($v0)
  jr    $ra
   sw    $t9, 4($v0)

.L7F0725C8:
  lw    $v0, 0xc($a0)
  lui   $t8, (0xB900031D >> 16) # lui $t8, 0xb900
  ori   $t8, (0xB900031D & 0xFFFF) # ori $t8, $t8, 0x31d
  addiu $t7, $v0, 8
  sw    $t7, 0xc($a0)
  sw    $t5, 4($v0)
  jr    $ra
   sw    $t8, ($v0)

.L7F0725E8:
  lw    $t6, 4($a0)
  lui   $t9, (0xC41041C8 >> 16) # lui $t9, 0xc410
  lui   $t7, (0xB900031D >> 16) # lui $t7, 0xb900
  beqz  $t6, .L7F072620
   ori   $t9, (0xC41041C8 & 0xFFFF) # ori $t9, $t9, 0x41c8
  lw    $v0, 0xc($a0)
  lui   $t8, (0xC41049D8 >> 16) # lui $t8, 0xc410
  ori   $t8, (0xC41049D8 & 0xFFFF) # ori $t8, $t8, 0x49d8
  addiu $t9, $v0, 8
  sw    $t9, 0xc($a0)
  ori   $t7, (0xB900031D & 0xFFFF) # ori $t7, $t7, 0x31d
  sw    $t7, ($v0)
  jr    $ra
   sw    $t8, 4($v0)

.L7F072620:
  lw    $v0, 0xc($a0)
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  addiu $t5, $v0, 8
  sw    $t5, 0xc($a0)
  sw    $t9, 4($v0)
  sw    $t6, ($v0)
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F072644
  lw    $v1, 0xc($a0)
  lui   $t7, 0xe700
  lui   $t9, (0xBA001402 >> 16) # lui $t9, 0xba00
  addiu $t6, $v1, 8
  sw    $t6, 0xc($a0)
  sw    $zero, 4($v1)
  sw    $t7, ($v1)
  lw    $v1, 0xc($a0)
  ori   $t9, (0xBA001402 & 0xFFFF) # ori $t9, $t9, 0x1402
  lui   $t0, 0x10
  addiu $t8, $v1, 8
  sw    $t8, 0xc($a0)
  sw    $t0, 4($v1)
  sw    $t9, ($v1)
  lw    $t1, 4($a0)
  lui   $t9, (0xFC26A004 >> 16) # lui $t9, 0xfc26
  lui   $t6, (0xB900031D >> 16) # lui $t6, 0xb900
  beqz  $t1, .L7F0726B8
   ori   $t9, (0xFC26A004 & 0xFFFF) # ori $t9, $t9, 0xa004
  lw    $v1, 0xc($a0)
  lui   $t3, (0xB900031D >> 16) # lui $t3, 0xb900
  lui   $t4, (0x0C192078 >> 16) # lui $t4, 0xc19
  addiu $t2, $v1, 8
  sw    $t2, 0xc($a0)
  ori   $t4, (0x0C192078 & 0xFFFF) # ori $t4, $t4, 0x2078
  ori   $t3, (0xB900031D & 0xFFFF) # ori $t3, $t3, 0x31d
  sw    $t3, ($v1)
  b     .L7F0726D8
   sw    $t4, 4($v1)
.L7F0726B8:
  lw    $v1, 0xc($a0)
  lui   $t7, (0x0C192048 >> 16) # lui $t7, 0xc19
  ori   $t7, (0x0C192048 & 0xFFFF) # ori $t7, $t7, 0x2048
  addiu $t5, $v1, 8
  sw    $t5, 0xc($a0)
  ori   $t6, (0xB900031D & 0xFFFF) # ori $t6, $t6, 0x31d
  sw    $t6, ($v1)
  sw    $t7, 4($v1)
.L7F0726D8:
  lw    $v1, 0xc($a0)
  lui   $t0, (0x1F1093FF >> 16) # lui $t0, 0x1f10
  ori   $t0, (0x1F1093FF & 0xFFFF) # ori $t0, $t0, 0x93ff
  addiu $t8, $v1, 8
  sw    $t8, 0xc($a0)
  sw    $t0, 4($v1)
  jr    $ra
   sw    $t9, ($v1)
");

asm(R"
glabel sub_GAME_7F0726F8
  lw    $v0, 0x3c($a0)
  li    $at, 1
  bnel  $v0, $at, .L7F07272C
   li    $at, 2
  lw    $v1, 0xc($a0)
  lui   $t7, 0xb600
  li    $t8, 12288
  addiu $t6, $v1, 8
  sw    $t6, 0xc($a0)
  sw    $t8, 4($v1)
  jr    $ra
   sw    $t7, ($v1)

  li    $at, 2
.L7F07272C:
  bnel  $v0, $at, .L7F072758
   li    $at, 3
  lw    $v1, 0xc($a0)
  lui   $t0, 0xb700
  li    $t1, 4096
  addiu $t9, $v1, 8
  sw    $t9, 0xc($a0)
  sw    $t1, 4($v1)
  jr    $ra
   sw    $t0, ($v1)

  li    $at, 3
.L7F072758:
  bne   $v0, $at, .L7F07277C
   nop   
  lw    $v1, 0xc($a0)
  lui   $t3, 0xb700
  li    $t4, 8192
  addiu $t2, $v1, 8
  sw    $t2, 0xc($a0)
  sw    $t4, 4($v1)
  sw    $t3, ($v1)
.L7F07277C:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F072784
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $t6, 0x18($a0)
  move  $s0, $a0
  lw    $s1, 4($a1)
  bnezl $t6, .L7F072974
   lw    $ra, 0x1c($sp)
  lw    $t7, 8($a0)
  andi  $t8, $t7, 1
  beql  $t8, $zero, .L7F0728D4
   lw    $t1, 8($s0)
  lw    $t9, ($s1)
  beql  $t9, $zero, .L7F0728D4
   lw    $t1, 8($s0)
  lw    $v0, 0xc($a0)
  lui   $t1, (0xBC001406 >> 16) # lui $t1, 0xbc00
  ori   $t1, (0xBC001406 & 0xFFFF) # ori $t1, $t1, 0x1406
  addiu $t0, $v0, 8
  sw    $t0, 0xc($a0)
  sw    $t1, ($v0)
  lw    $a0, 8($s1)
  jal   osVirtualToPhysical
   sw    $v0, 0x30($sp)
  lw    $v1, 0x30($sp)
  sw    $v0, 4($v1)
  lw    $t2, 0x3c($s0)
  beql  $t2, $zero, .L7F072808
   lb    $v0, 0x12($s1)
  jal   sub_GAME_7F0726F8
   move  $a0, $s0
  lb    $v0, 0x12($s1)
.L7F072808:
  li    $at, 1
  bnel  $v0, $at, .L7F072828
   li    $at, 3
  jal   sub_GAME_7F070F80
   move  $a0, $s0
  b     .L7F072874
   lw    $v0, 0xc($s0)
  li    $at, 3
.L7F072828:
  bne   $v0, $at, .L7F072840
   move  $a0, $s0
  jal   sub_GAME_7F071030
   li    $a1, 1
  b     .L7F072874
   lw    $v0, 0xc($s0)
.L7F072840:
  li    $at, 4
  bne   $v0, $at, .L7F07285C
   move  $a0, $s0
  jal   sub_GAME_7F071B44
   li    $a1, 1
  b     .L7F072874
   lw    $v0, 0xc($s0)
.L7F07285C:
  li    $at, 2
  bnel  $v0, $at, .L7F072874
   lw    $v0, 0xc($s0)
  jal   sub_GAME_7F072644
   move  $a0, $s0
  lw    $v0, 0xc($s0)
.L7F072874:
  lui   $t4, 0x600
  li    $at, 3
  addiu $t3, $v0, 8
  sw    $t3, 0xc($s0)
  sw    $t4, ($v0)
  lw    $t5, ($s1)
  sw    $t5, 4($v0)
  lb    $t6, 0x12($s1)
  bnel  $t6, $at, .L7F0728D4
   lw    $t1, 8($s0)
  lw    $t7, 4($s1)
  move  $a0, $s0
  beql  $t7, $zero, .L7F0728D4
   lw    $t1, 8($s0)
  jal   sub_GAME_7F071030
   move  $a1, $zero
  lw    $v0, 0xc($s0)
  lui   $t9, 0x600
  addiu $t8, $v0, 8
  sw    $t8, 0xc($s0)
  sw    $t9, ($v0)
  lw    $t0, 4($s1)
  sw    $t0, 4($v0)
  lw    $t1, 8($s0)
.L7F0728D4:
  andi  $t2, $t1, 2
  beql  $t2, $zero, .L7F072974
   lw    $ra, 0x1c($sp)
  lw    $t3, ($s1)
  beql  $t3, $zero, .L7F072974
   lw    $ra, 0x1c($sp)
  lb    $t4, 0x12($s1)
  li    $at, 4
  bnel  $t4, $at, .L7F072974
   lw    $ra, 0x1c($sp)
  lw    $t5, 4($s1)
  beql  $t5, $zero, .L7F072974
   lw    $ra, 0x1c($sp)
  lw    $v0, 0xc($s0)
  lui   $t7, (0xBC001406 >> 16) # lui $t7, 0xbc00
  ori   $t7, (0xBC001406 & 0xFFFF) # ori $t7, $t7, 0x1406
  addiu $t6, $v0, 8
  sw    $t6, 0xc($s0)
  sw    $t7, ($v0)
  lw    $a0, 8($s1)
  jal   osVirtualToPhysical
   sw    $v0, 0x24($sp)
  lw    $v1, 0x24($sp)
  sw    $v0, 4($v1)
  lw    $t8, 0x3c($s0)
  beql  $t8, $zero, .L7F07294C
   move  $a0, $s0
  jal   sub_GAME_7F0726F8
   move  $a0, $s0
  move  $a0, $s0
.L7F07294C:
  jal   sub_GAME_7F071B44
   move  $a1, $zero
  lw    $v0, 0xc($s0)
  lui   $t0, 0x600
  addiu $t9, $v0, 8
  sw    $t9, 0xc($s0)
  sw    $t0, ($v0)
  lw    $t1, 4($s1)
  sw    $t1, 4($v0)
  lw    $ra, 0x1c($sp)
.L7F072974:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

asm(R"
glabel sub_GAME_7F072984
  addiu $sp, $sp, -0x48
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a1, 0x4c($sp)
  sw    $a2, 0x50($sp)
  lw    $t7, 0x18($a0)
  move  $s0, $a0
  lw    $s1, 4($a2)
  bnezl $t7, .L7F072C00
   lw    $ra, 0x1c($sp)
  lw    $t8, 8($a0)
  move  $a0, $a1
  andi  $t9, $t8, 1
  beql  $t9, $zero, .L7F072B20
   lw    $t7, 8($s0)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $a2
  sw    $v0, 0x40($sp)
  lw    $t0, 4($v0)
  beql  $t0, $zero, .L7F072B20
   lw    $t7, 8($s0)
  lw    $v1, 0xc($s0)
  lui   $t2, (0xBC001406 >> 16) # lui $t2, 0xbc00
  ori   $t2, (0xBC001406 & 0xFFFF) # ori $t2, $t2, 0x1406
  addiu $t1, $v1, 8
  sw    $t1, 0xc($s0)
  sw    $t2, ($v1)
  lw    $a0, 0x1c($s1)
  jal   osVirtualToPhysical
   sw    $v1, 0x3c($sp)
  lw    $a1, 0x3c($sp)
  sw    $v0, 4($a1)
  lw    $t3, 0x3c($s0)
  beql  $t3, $zero, .L7F072A20
   lh    $v0, 0x18($s1)
  jal   sub_GAME_7F0726F8
   move  $a0, $s0
  lh    $v0, 0x18($s1)
.L7F072A20:
  li    $at, 1
  bnel  $v0, $at, .L7F072A40
   li    $at, 3
  jal   sub_GAME_7F070F80
   move  $a0, $s0
  b     .L7F072A8C
   lw    $v1, 0xc($s0)
  li    $at, 3
.L7F072A40:
  bne   $v0, $at, .L7F072A58
   move  $a0, $s0
  jal   sub_GAME_7F071030
   li    $a1, 1
  b     .L7F072A8C
   lw    $v1, 0xc($s0)
.L7F072A58:
  li    $at, 4
  bne   $v0, $at, .L7F072A74
   move  $a0, $s0
  jal   sub_GAME_7F071B44
   li    $a1, 1
  b     .L7F072A8C
   lw    $v1, 0xc($s0)
.L7F072A74:
  li    $at, 2
  bnel  $v0, $at, .L7F072A8C
   lw    $v1, 0xc($s0)
  jal   sub_GAME_7F072644
   move  $a0, $s0
  lw    $v1, 0xc($s0)
.L7F072A8C:
  lui   $t5, (0xBC001006 >> 16) # lui $t5, 0xbc00
  ori   $t5, (0xBC001006 & 0xFFFF) # ori $t5, $t5, 0x1006
  addiu $t4, $v1, 8
  sw    $t4, 0xc($s0)
  sw    $t5, ($v1)
  lw    $t7, 0x40($sp)
  lw    $a0, ($t7)
  jal   osVirtualToPhysical
   sw    $v1, 0x38($sp)
  lw    $a1, 0x38($sp)
  lui   $t9, 0x600
  li    $at, 3
  sw    $v0, 4($a1)
  lw    $v1, 0xc($s0)
  addiu $t8, $v1, 8
  sw    $t8, 0xc($s0)
  sw    $t9, ($v1)
  lw    $t6, 0x40($sp)
  lw    $t0, 4($t6)
  sw    $t0, 4($v1)
  lh    $t1, 0x18($s1)
  bnel  $t1, $at, .L7F072B20
   lw    $t7, 8($s0)
  lw    $t2, 4($s1)
  move  $a0, $s0
  beql  $t2, $zero, .L7F072B20
   lw    $t7, 8($s0)
  jal   sub_GAME_7F071030
   move  $a1, $zero
  lw    $v1, 0xc($s0)
  lui   $t4, 0x600
  addiu $t3, $v1, 8
  sw    $t3, 0xc($s0)
  sw    $t4, ($v1)
  lw    $t5, 4($s1)
  sw    $t5, 4($v1)
  lw    $t7, 8($s0)
.L7F072B20:
  lw    $a0, 0x4c($sp)
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F072C00
   lw    $ra, 0x1c($sp)
  jal   extract_id_from_object_structure_microcode
   lw    $a1, 0x50($sp)
  sw    $v0, 0x2c($sp)
  lw    $t9, 4($v0)
  beql  $t9, $zero, .L7F072C00
   lw    $ra, 0x1c($sp)
  lh    $t6, 0x18($s1)
  li    $at, 4
  bnel  $t6, $at, .L7F072C00
   lw    $ra, 0x1c($sp)
  lw    $t0, 4($s1)
  beql  $t0, $zero, .L7F072C00
   lw    $ra, 0x1c($sp)
  lw    $v1, 0xc($s0)
  lui   $t2, (0xBC001406 >> 16) # lui $t2, 0xbc00
  ori   $t2, (0xBC001406 & 0xFFFF) # ori $t2, $t2, 0x1406
  addiu $t1, $v1, 8
  sw    $t1, 0xc($s0)
  sw    $t2, ($v1)
  lw    $a0, 0x1c($s1)
  jal   osVirtualToPhysical
   sw    $v1, 0x28($sp)
  lw    $a1, 0x28($sp)
  sw    $v0, 4($a1)
  lw    $t3, 0x3c($s0)
  beql  $t3, $zero, .L7F072BA8
   lw    $v1, 0xc($s0)
  jal   sub_GAME_7F0726F8
   move  $a0, $s0
  lw    $v1, 0xc($s0)
.L7F072BA8:
  lui   $t5, (0xBC001006 >> 16) # lui $t5, 0xbc00
  ori   $t5, (0xBC001006 & 0xFFFF) # ori $t5, $t5, 0x1006
  addiu $t4, $v1, 8
  sw    $t4, 0xc($s0)
  sw    $t5, ($v1)
  lw    $t7, 0x2c($sp)
  lw    $a0, ($t7)
  jal   osVirtualToPhysical
   sw    $v1, 0x24($sp)
  lw    $a2, 0x24($sp)
  move  $a0, $s0
  move  $a1, $zero
  jal   sub_GAME_7F071B44
   sw    $v0, 4($a2)
  lw    $v1, 0xc($s0)
  lui   $t9, 0x600
  addiu $t8, $v1, 8
  sw    $t8, 0xc($s0)
  sw    $t9, ($v1)
  lw    $t6, 4($s1)
  sw    $t6, 4($v1)
  lw    $ra, 0x1c($sp)
.L7F072C00:
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F072C10
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
glabel dorottex
  addiu $sp, $sp, -0x48
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0x18($a0)
  move  $s3, $a0
  bnezl $t6, .L7F07300C
   lw    $ra, 0x3c($sp)
  lw    $t7, 8($a0)
  andi  $t8, $t7, 2
  beql  $t8, $zero, .L7F07300C
   lw    $ra, 0x3c($sp)
  lw    $v1, 4($a1)
  lui   $v0, %hi(D_8003608C)
  lw    $t9, 8($v1)
  beql  $t9, $zero, .L7F07300C
   lw    $ra, 0x3c($sp)
  lw    $v0, %lo(D_8003608C)($v0)
  lui   $a0, %hi(aDorottexNoVtxAllocator)
  lw    $s2, 4($v1)
  beqz  $v0, .L7F072C9C
   addiu $a0, %lo(aDorottexNoVtxAllocator) # addiu $a0, $a0, 0x4a38
  b     .L7F072CB4
   sw    $v1, 0x44($sp)
.L7F072C9C:
  jal   osSyncPrintf
   sw    $v1, 0x44($sp)
  jal   return_null
   nop   
  lui   $v0, %hi(D_8003608C)
  lw    $v0, %lo(D_8003608C)($v0)
.L7F072CB4:
  lw    $v1, 0x44($sp)
  lw    $a0, ($v1)
  sll   $t1, $a0, 2
  jalr  $v0
  move  $a0, $t1
  lw    $s4, 0xc($s3)
  lui   $t3, (0xBC001006 >> 16) # lui $t3, 0xbc00
  ori   $t3, (0xBC001006 & 0xFFFF) # ori $t3, $t3, 0x1006
  addiu $t2, $s4, 8
  sw    $t2, 0xc($s3)
  move  $s0, $v0
  move  $a0, $v0
  jal   osVirtualToPhysical
   sw    $t3, ($s4)
  sw    $v0, 4($s4)
  lw    $s6, 0xc($s3)
  lui   $t5, (0xBC001406 >> 16) # lui $t5, 0xbc00
  ori   $t5, (0xBC001406 & 0xFFFF) # ori $t5, $t5, 0x1406
  addiu $t4, $s6, 8
  sw    $t4, 0xc($s3)
  sw    $t5, ($s6)
  lw    $t6, 0x44($sp)
  jal   osVirtualToPhysical
   lw    $a0, 0xc($t6)
  lw    $a1, 0x44($sp)
  sw    $v0, 4($s6)
  lw    $s1, 0xc($s3)
  lui   $t8, 0xf800
  lui   $t1, 0x600
  addiu $t7, $s1, 8
  sw    $t7, 0xc($s3)
  sw    $zero, 4($s1)
  sw    $t8, ($s1)
  lw    $s1, 0xc($s3)
  li    $s6, 181
  move  $s5, $zero
  addiu $t9, $s1, 8
  sw    $t9, 0xc($s3)
  sw    $t1, ($s1)
  lw    $t2, 8($a1)
  lui   $fp, 1
  li    $s7, 512
  sw    $t2, 4($s1)
  lw    $t3, ($a1)
  blezl $t3, .L7F07300C
   lw    $ra, 0x3c($sp)
.L7F072D6C:
  jal   get_random_value
   nop   
  sll   $t4, $v0, 0xa
  andi  $s1, $t4, 0xffff
  jal   coss
   andi  $a0, $t4, 0xffff
  sll   $t5, $v0, 5
  multu $t5, $s6
  andi  $a0, $s1, 0xffff
  mflo  $s4
  sra   $t6, $s4, 0x12
  jal   sins
   move  $s4, $t6
  sll   $t7, $v0, 5
  multu $t7, $s6
  mflo  $s3
  sra   $t8, $s3, 0x12
  jal   get_random_value
   move  $s3, $t8
  jal   get_random_value
   srl   $s1, $v0, 0x1f
  lw    $at, ($s2)
  andi  $t9, $v0, 0x3fff
  subu  $a0, $fp, $t9
  sw    $at, ($s0)
  lw    $t2, 4($s2)
  subu  $t0, $s7, $s4
  subu  $a3, $s7, $s3
  sw    $t2, 4($s0)
  lw    $at, 8($s2)
  move  $v1, $a0
  addiu $a2, $s3, 0x200
  sw    $at, 8($s0)
  lw    $t2, 0xc($s2)
  addiu $s5, $s5, 1
  addiu $s0, $s0, 0x40
  sw    $t2, -0x34($s0)
  lw    $at, 0x10($s2)
  sw    $at, -0x30($s0)
  lw    $t4, 0x14($s2)
  sw    $t4, -0x2c($s0)
  lw    $at, 0x18($s2)
  sw    $at, -0x28($s0)
  lw    $t4, 0x1c($s2)
  sw    $t4, -0x24($s0)
  lw    $at, 0x20($s2)
  sw    $at, -0x20($s0)
  lw    $t6, 0x24($s2)
  sw    $t6, -0x1c($s0)
  lw    $at, 0x28($s2)
  sw    $at, -0x18($s0)
  lw    $t6, 0x2c($s2)
  sw    $t6, -0x14($s0)
  lw    $at, 0x30($s2)
  sw    $at, -0x10($s0)
  lw    $t8, 0x34($s2)
  sw    $t8, -0xc($s0)
  lw    $at, 0x38($s2)
  sw    $at, -8($s0)
  lw    $t8, 0x3c($s2)
  sh    $t0, -0x38($s0)
  sh    $a3, -0x36($s0)
  sw    $t8, -4($s0)
  bgez  $s1, .L7F072E7C
   andi  $t9, $s1, 3
  beqz  $t9, .L7F072E7C
   nop   
  addiu $t9, $t9, -4
.L7F072E7C:
  sll   $t1, $t9, 4
  addu  $a1, $s2, $t1
  lh    $t2, ($a1)
  multu $t2, $a0
  addiu $t2, $s1, 1
  mflo  $t3
  sra   $t4, $t3, 0x10
  sh    $t4, -0x40($s0)
  lh    $t5, 2($a1)
  multu $t5, $a0
  addiu $a0, $s4, 0x200
  mflo  $t6
  sra   $t7, $t6, 0x10
  sh    $t7, -0x3e($s0)
  lh    $t8, 4($a1)
  sh    $a2, -0x28($s0)
  sh    $t0, -0x26($s0)
  multu $t8, $v1
  mflo  $t9
  sra   $t1, $t9, 0x10
  sh    $t1, -0x3c($s0)
  bgez  $t2, .L7F072EE4
   andi  $t3, $t2, 3
  beqz  $t3, .L7F072EE4
   nop   
  addiu $t3, $t3, -4
.L7F072EE4:
  sll   $t4, $t3, 4
  addu  $v0, $s2, $t4
  lh    $t5, ($v0)
  multu $t5, $v1
  addiu $t5, $s1, 2
  mflo  $t6
  sra   $t7, $t6, 0x10
  sh    $t7, -0x30($s0)
  lh    $t8, 2($v0)
  multu $t8, $v1
  mflo  $t9
  sra   $t1, $t9, 0x10
  sh    $t1, -0x2e($s0)
  lh    $t2, 4($v0)
  sh    $a0, -0x18($s0)
  sh    $a2, -0x16($s0)
  multu $t2, $v1
  mflo  $t3
  sra   $t4, $t3, 0x10
  sh    $t4, -0x2c($s0)
  bgez  $t5, .L7F072F48
   andi  $t6, $t5, 3
  beqz  $t6, .L7F072F48
   nop   
  addiu $t6, $t6, -4
.L7F072F48:
  sll   $t7, $t6, 4
  addu  $v0, $s2, $t7
  lh    $t8, ($v0)
  multu $t8, $v1
  addiu $t8, $s1, 3
  mflo  $t9
  sra   $t1, $t9, 0x10
  sh    $t1, -0x20($s0)
  lh    $t2, 2($v0)
  multu $t2, $v1
  mflo  $t3
  sra   $t4, $t3, 0x10
  sh    $t4, -0x1e($s0)
  lh    $t5, 4($v0)
  sh    $a3, -8($s0)
  sh    $a0, -6($s0)
  multu $t5, $v1
  mflo  $t6
  sra   $t7, $t6, 0x10
  sh    $t7, -0x1c($s0)
  bgez  $t8, .L7F072FAC
   andi  $t9, $t8, 3
  beqz  $t9, .L7F072FAC
   nop   
  addiu $t9, $t9, -4
.L7F072FAC:
  sll   $t1, $t9, 4
  addu  $v0, $s2, $t1
  lh    $t2, ($v0)
  addiu $s2, $s2, 0x40
  multu $t2, $v1
  mflo  $t3
  sra   $t4, $t3, 0x10
  sh    $t4, -0x10($s0)
  lh    $t5, 2($v0)
  multu $t5, $v1
  mflo  $t6
  sra   $t7, $t6, 0x10
  sh    $t7, -0xe($s0)
  lh    $t8, 4($v0)
  multu $t8, $v1
  mflo  $t9
  sra   $t1, $t9, 0x10
  sh    $t1, -0xc($s0)
  lw    $t2, 0x44($sp)
  lw    $t3, ($t2)
  slt   $at, $s5, $t3
  bnez  $at, .L7F072D6C
   nop   
  lw    $ra, 0x3c($sp)
.L7F07300C:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x48
");

asm(R"
glabel sub_GAME_7F073038
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $a0, 0x20($sp)
  move  $t6, $a0
  lw    $a3, 4($t6)
  li    $t7, 2
  sw    $t7, 0x10($sp)
  jal   likely_generate_DL_for_image_declaration
   addiu $a0, $a0, 0xc
  lw    $ra, 0x1c($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F07306C
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
glabel dotube
  addiu $sp, $sp, -0xd0
  sw    $s5, 0x2c($sp)
  move  $s5, $a0
  sw    $s3, 0x24($sp)
  move  $s3, $a1
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s4, 0x28($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  move  $a0, $a1
  move  $s1, $a2
  lw    $s6, 4($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $a2
  lw    $v1, ($s6)
  move  $s2, $v0
  beql  $v1, $zero, .L7F0730E0
   lw    $a1, 4($s6)
  b     .L7F0730E0
   move  $a1, $v1
  lw    $a1, 4($s6)
.L7F0730E0:
  lw    $t6, 4($a1)
  move  $a0, $s3
  jal   extract_id_from_object_structure_microcode
   sw    $t6, 0xc0($sp)
  li    $t7, 1
  sw    $t7, 0x9c($sp)
  lw    $t8, 8($s5)
  move  $s0, $v0
  move  $a0, $s1
  andi  $t9, $t8, 1
  beql  $t9, $zero, .L7F0737C0
   lw    $ra, 0x3c($sp)
  jal   sub_GAME_7F06C570
   move  $a1, $zero
  lw    $t0, 0xc($s3)
  sll   $t1, $v0, 6
  li    $a1, 512
  addu  $t2, $t0, $t1
  sw    $t2, 0x84($sp)
  lw    $v1, ($s2)
  lw    $t5, ($s6)
  lw    $t3, 0xc($s6)
  sll   $t4, $v1, 3
  lw    $a2, ($s0)
  beqz  $t5, .L7F073164
   addu  $fp, $t3, $t4
  move  $s2, $a2
  move  $s0, $v1
  move  $a0, $s1
  jal   sub_GAME_7F06C570
   li    $a1, 512
  b     .L7F073178
   lw    $t6, 0xc($s3)
.L7F073164:
  move  $s2, $v1
  move  $s0, $a2
  jal   sub_GAME_7F06C570
   lw    $a0, 4($s6)
  lw    $t6, 0xc($s3)
.L7F073178:
  sll   $t7, $v0, 6
  subu  $t9, $s0, $s2
  addu  $t8, $t6, $t7
  sw    $t8, 0x80($sp)
  lw    $v1, 8($s6)
  addu  $t0, $t9, $v1
  div   $zero, $t0, $v1
  bnez  $v1, .L7F0731A0
   nop   
  break 7
.L7F0731A0:
  li    $at, -1
  bne   $v1, $at, .L7F0731B8
   lui   $at, 0x8000
  bne   $t0, $at, .L7F0731B8
   nop   
  break 6
.L7F0731B8:
  mfhi  $a1
  slti  $at, $a1, 2
  bnez  $at, .L7F07327C
   slti  $at, $a1, 7
  beqz  $at, .L7F07327C
   slti  $at, $a1, 4
  beql  $at, $zero, .L7F073228
   li    $t4, 8
  bgez  $a1, .L7F0731E8
   sra   $t1, $a1, 1
  addiu $at, $a1, 1
  sra   $t1, $at, 1
.L7F0731E8:
  addu  $t2, $t1, $s2
  addu  $t3, $t2, $v1
  div   $zero, $t3, $v1
  mfhi  $a1
  bnez  $v1, .L7F073204
   nop   
  break 7
.L7F073204:
  li    $at, -1
  bne   $v1, $at, .L7F07321C
   lui   $at, 0x8000
  bne   $t3, $at, .L7F07321C
   nop   
  break 6
.L7F07321C:
  b     .L7F073360
   lw    $s1, 0xc($s5)
  li    $t4, 8
.L7F073228:
  subu  $t5, $t4, $a1
  bgez  $t5, .L7F07323C
   sra   $t6, $t5, 1
  addiu $at, $t5, 1
  sra   $t6, $at, 1
.L7F07323C:
  subu  $t7, $s2, $t6
  addu  $t8, $t7, $v1
  div   $zero, $t8, $v1
  mfhi  $a1
  sw    $zero, 0x9c($sp)
  bnez  $v1, .L7F07325C
   nop   
  break 7
.L7F07325C:
  li    $at, -1
  bne   $v1, $at, .L7F073274
   lui   $at, 0x8000
  bne   $t8, $at, .L7F073274
   nop   
  break 6
.L7F073274:
  b     .L7F073360
   lw    $s1, 0xc($s5)
.L7F07327C:
  slti  $at, $a1, 0xa
  bnez  $at, .L7F073340
   slti  $at, $a1, 0xf
  beqz  $at, .L7F073340
   slti  $at, $a1, 0xd
  bnezl $at, .L7F0732F0
   addiu $t4, $a1, -8
  li    $t9, 16
  subu  $t0, $t9, $a1
  bgez  $t0, .L7F0732B0
   sra   $t1, $t0, 1
  addiu $at, $t0, 1
  sra   $t1, $at, 1
.L7F0732B0:
  subu  $t2, $s2, $t1
  addu  $t3, $t2, $v1
  div   $zero, $t3, $v1
  mfhi  $a1
  bnez  $v1, .L7F0732CC
   nop   
  break 7
.L7F0732CC:
  li    $at, -1
  bne   $v1, $at, .L7F0732E4
   lui   $at, 0x8000
  bne   $t3, $at, .L7F0732E4
   nop   
  break 6
.L7F0732E4:
  b     .L7F073360
   lw    $s1, 0xc($s5)
  addiu $t4, $a1, -8
.L7F0732F0:
  bgez  $t4, .L7F073300
   sra   $t5, $t4, 1
  addiu $at, $t4, 1
  sra   $t5, $at, 1
.L7F073300:
  addu  $t6, $t5, $s2
  addu  $t7, $t6, $v1
  div   $zero, $t7, $v1
  mfhi  $a1
  sw    $zero, 0x9c($sp)
  bnez  $v1, .L7F073320
   nop   
  break 7
.L7F073320:
  li    $at, -1
  bne   $v1, $at, .L7F073338
   lui   $at, 0x8000
  bne   $t7, $at, .L7F073338
   nop   
  break 6
.L7F073338:
  b     .L7F073360
   lw    $s1, 0xc($s5)
.L7F073340:
  slti  $at, $a1, 7
  bnez  $at, .L7F073358
   slti  $at, $a1, 0xa
  beql  $at, $zero, .L7F07335C
   move  $a1, $s2
  sw    $zero, 0x9c($sp)
.L7F073358:
  move  $a1, $s2
.L7F07335C:
  lw    $s1, 0xc($s5)
.L7F073360:
  lw    $s4, 4($fp)
  lui   $t9, (0xBC001406 >> 16) # lui $t9, 0xbc00
  addiu $t8, $s1, 8
  sw    $t8, 0xc($s5)
  ori   $t9, (0xBC001406 & 0xFFFF) # ori $t9, $t9, 0x1406
  sw    $t9, ($s1)
  lw    $a0, 0x1ac($s6)
  jal   osVirtualToPhysical
   sw    $a1, 0xb8($sp)
  sw    $v0, 4($s1)
  lbu   $s7, ($fp)
  li    $fp, 10
  li    $s3, 3
  blez  $s7, .L7F0737BC
   li    $s2, 2
  li    $s1, 1
  lbu   $a0, ($s4)
.L7F0733A4:
  lui   $v0, %hi(D_8003608C)
  lw    $s0, 0xb8($sp)
  beq   $a0, $s1, .L7F0733CC
   nop   
  beql  $a0, $s2, .L7F07370C
   lbu   $v0, 1($s4)
  beql  $a0, $s3, .L7F073758
   lw    $s0, 0xc($s5)
  b     .L7F0737B4
   addiu $s7, $s7, -1
.L7F0733CC:
  lw    $v0, %lo(D_8003608C)($v0)
  sll   $t0, $s0, 3
  move  $s0, $t0
  bnez  $v0, .L7F0733F8
   lui   $a0, %hi(aDotubeNoVtxAllocator)
  jal   osSyncPrintf
   addiu $a0, %lo(aDotubeNoVtxAllocator) # addiu $a0, $a0, 0x4a58
  jal   return_null
   nop   
  lui   $v0, %hi(D_8003608C)
  lw    $v0, %lo(D_8003608C)($v0)
.L7F0733F8:
  jalr  $v0
  move  $a0, $s2
  sw    $v0, 0x74($sp)
  lhu   $t2, 2($s4)
  lw    $t1, 0x10($s6)
  addiu $a3, $v0, 0x10
  sll   $t3, $t2, 4
  addu  $t4, $t1, $t3
  lw    $at, ($t4)
  sw    $at, ($v0)
  lw    $t7, 4($t4)
  sw    $t7, 4($v0)
  lw    $at, 8($t4)
  sw    $at, 8($v0)
  lw    $t7, 0xc($t4)
  sw    $t7, 0xc($v0)
  lhu   $t9, 2($s4)
  lw    $t8, 0x10($s6)
  sll   $t0, $t9, 4
  addu  $t2, $t8, $t0
  lw    $at, 0x10($t2)
  sw    $at, ($a3)
  lw    $t6, 0x14($t2)
  sw    $t6, 4($a3)
  lw    $at, 0x18($t2)
  sw    $at, 8($a3)
  lw    $t6, 0x1c($t2)
  sw    $t6, 0xc($a3)
  lw    $t5, 4($s6)
  lw    $t4, 0xc0($sp)
  lw    $t7, 0xc0($sp)
  beql  $t5, $zero, .L7F073530
   lw    $t9, 0xc($t4)
  lw    $t4, 0xc($s6)
  addu  $v1, $t4, $s0
  lbu   $a2, ($v1)
  lw    $a1, 4($v1)
  blezl $a2, .L7F07361C
   lw    $s0, 0xc($s5)
  lbu   $v1, ($a1)
.L7F073498:
  addiu $a2, $a2, -1
  bne   $s1, $v1, .L7F0734E8
   nop   
  lhu   $t9, 2($a1)
  lw    $t7, 0x10($s6)
  sll   $t8, $t9, 4
  addu  $v1, $t7, $t8
  lh    $t0, ($v1)
  sh    $t0, ($v0)
  lh    $t3, 2($v1)
  sh    $t3, 2($v0)
  lh    $t1, 4($v1)
  sh    $t1, 4($v0)
  lh    $t2, 0x10($v1)
  sh    $t2, ($a3)
  lh    $t6, 0x12($v1)
  sh    $t6, 2($a3)
  lh    $t5, 0x14($v1)
  b     .L7F073618
   sh    $t5, 4($a3)
.L7F0734E8:
  beq   $v1, $s1, .L7F073508
   nop   
  beq   $v1, $s2, .L7F073510
   nop   
  beql  $v1, $s3, .L7F07351C
   addiu $a1, $a1, 4
  b     .L7F07351C
   nop   
.L7F073508:
  b     .L7F07351C
   addiu $a1, $a1, 4
.L7F073510:
  b     .L7F07351C
   addiu $a1, $a1, 2
  addiu $a1, $a1, 4
.L7F07351C:
  bgtzl $a2, .L7F073498
   lbu   $v1, ($a1)
  b     .L7F07361C
   lw    $s0, 0xc($s5)
  lw    $t9, 0xc($t4)
.L7F073530:
  addu  $v1, $t9, $s0
  lbu   $a2, ($v1)
  lw    $a1, 4($v1)
  blezl $a2, .L7F07361C
   lw    $s0, 0xc($s5)
  lbu   $v1, ($a1)
.L7F073548:
  addiu $a2, $a2, -1
  bne   $s1, $v1, .L7F0735DC
   nop   
  lhu   $t0, 2($a1)
  lw    $t1, 0x9c($sp)
  lw    $t8, 0x10($t7)
  sll   $t3, $t0, 4
  beqz  $t1, .L7F0735A4
   addu  $v1, $t8, $t3
  addiu $a0, $v1, 0x10
  lh    $t2, ($a0)
  sh    $t2, ($v0)
  lh    $t6, 2($a0)
  sh    $t6, 2($v0)
  lh    $t5, 4($a0)
  sh    $t5, 4($v0)
  lh    $t4, ($v1)
  sh    $t4, ($a3)
  lh    $t9, 2($v1)
  sh    $t9, 2($a3)
  lh    $t7, 4($v1)
  b     .L7F073618
   sh    $t7, 4($a3)
.L7F0735A4:
  lh    $t0, ($v1)
  addiu $a0, $v1, 0x10
  sh    $t0, ($v0)
  lh    $t8, 2($v1)
  sh    $t8, 2($v0)
  lh    $t3, 4($v1)
  sh    $t3, 4($v0)
  lh    $t1, ($a0)
  sh    $t1, ($a3)
  lh    $t2, 2($a0)
  sh    $t2, 2($a3)
  lh    $t6, 4($a0)
  b     .L7F073618
   sh    $t6, 4($a3)
.L7F0735DC:
  beq   $v1, $s1, .L7F0735FC
   nop   
  beq   $v1, $s2, .L7F073604
   nop   
  beql  $v1, $s3, .L7F073610
   addiu $a1, $a1, 4
  b     .L7F073610
   nop   
.L7F0735FC:
  b     .L7F073610
   addiu $a1, $a1, 4
.L7F073604:
  b     .L7F073610
   addiu $a1, $a1, 2
  addiu $a1, $a1, 4
.L7F073610:
  bgtzl $a2, .L7F073548
   lbu   $v1, ($a1)
.L7F073618:
  lw    $s0, 0xc($s5)
.L7F07361C:
  lui   $t4, (0x01020040 >> 16) # lui $t4, 0x102
  ori   $t4, (0x01020040 & 0xFFFF) # ori $t4, $t4, 0x40
  addiu $t5, $s0, 8
  sw    $t5, 0xc($s5)
  sw    $t4, ($s0)
  lw    $a0, 0x80($sp)
  jal   osVirtualToPhysical
   sw    $s0, 0x4c($sp)
  lw    $v1, 0x4c($sp)
  lui   $t7, (0x04100020 >> 16) # lui $t7, 0x410
  ori   $t7, (0x04100020 & 0xFFFF) # ori $t7, $t7, 0x20
  sw    $v0, 4($v1)
  lw    $s0, 0xc($s5)
  addiu $t9, $s0, 8
  sw    $t9, 0xc($s5)
  sw    $t7, ($s0)
  lw    $a0, 0x74($sp)
  jal   osVirtualToPhysical
   sw    $s0, 0x48($sp)
  lw    $a1, 0x48($sp)
  lui   $t8, (0x01020040 >> 16) # lui $t8, 0x102
  ori   $t8, (0x01020040 & 0xFFFF) # ori $t8, $t8, 0x40
  sw    $v0, 4($a1)
  lw    $s0, 0xc($s5)
  addiu $t0, $s0, 8
  sw    $t0, 0xc($s5)
  sw    $t8, ($s0)
  lw    $a0, 0x84($sp)
  jal   osVirtualToPhysical
   sw    $s0, 0x44($sp)
  lw    $a2, 0x44($sp)
  lui   $at, 0x400
  sw    $v0, 4($a2)
  lw    $s0, 0xc($s5)
  addiu $t3, $s0, 8
  sw    $t3, 0xc($s5)
  lbu   $v1, 1($s4)
  addiu $v1, $v1, -2
  addiu $t1, $v1, -1
  sll   $t2, $t1, 4
  ori   $t6, $t2, 2
  andi  $t5, $t6, 0xff
  sll   $t4, $t5, 0x10
  sll   $t7, $v1, 4
  andi  $t0, $t7, 0xffff
  or    $t9, $t4, $at
  or    $t8, $t9, $t0
  sw    $t8, ($s0)
  lhu   $t1, 2($s4)
  lw    $t3, 0x10($s6)
  sw    $s0, 0x40($sp)
  sll   $t2, $t1, 4
  addu  $a0, $t3, $t2
  jal   osVirtualToPhysical
   addiu $a0, $a0, 0x20
  lw    $a1, 0x40($sp)
  addiu $s4, $s4, 4
  b     .L7F0737B0
   sw    $v0, 4($a1)
  lbu   $v0, 1($s4)
.L7F07370C:
  li    $at, 255
  move  $a0, $s5
  beq   $v0, $at, .L7F073744
   move  $a1, $zero
  sll   $t5, $v0, 2
  lw    $t6, 0x14($s6)
  subu  $t5, $t5, $v0
  sll   $t5, $t5, 2
  move  $a0, $s5
  move  $a2, $s1
  jal   sub_GAME_7F073038
   addu  $a1, $t6, $t5
  b     .L7F0737B0
   addiu $s4, $s4, 2
.L7F073744:
  jal   sub_GAME_7F073038
   move  $a2, $s1
  b     .L7F0737B0
   addiu $s4, $s4, 2
  lw    $s0, 0xc($s5)
.L7F073758:
  lui   $t7, 0xbf00
  addiu $s4, $s4, 4
  addiu $t4, $s0, 8
  sw    $t4, 0xc($s5)
  sw    $t7, ($s0)
  lbu   $t9, -3($s4)
  lbu   $t3, -2($s4)
  lbu   $t7, -1($s4)
  multu $t9, $fp
  mflo  $t0
  andi  $t8, $t0, 0xff
  sll   $t1, $t8, 0x10
  multu $t3, $fp
  mflo  $t2
  andi  $t6, $t2, 0xff
  sll   $t5, $t6, 8
  multu $t7, $fp
  or    $t4, $t1, $t5
  mflo  $t9
  andi  $t0, $t9, 0xff
  or    $t8, $t4, $t0
  sw    $t8, 4($s0)
.L7F0737B0:
  addiu $s7, $s7, -1
.L7F0737B4:
  bgtzl $s7, .L7F0733A4
   lbu   $a0, ($s4)
.L7F0737BC:
  lw    $ra, 0x3c($sp)
.L7F0737C0:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0xd0
");

asm(R"
glabel sub_GAME_7F0737EC
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
glabel sub_GAME_7F0737FC
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
.late_rodata
glabel D_80054D50
.word 0x40c90fdb /*6.2831855*/
.text
glabel dogfnegx
  addiu $sp, $sp, -0x100
  sw    $s2, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x24($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a1, 0x104($sp)
  move  $a0, $a1
  move  $s0, $a2
  lw    $s1, 4($a2)
  jal   extract_id_from_object_structure_microcode
   move  $a1, $a2
  lui   $t7, %hi(D_800363E0) 
  addiu $t7, %lo(D_800363E0) # addiu $t7, $t7, 0x63e0
  lw    $at, ($t7)
  lw    $t9, 4($t7)
  addiu $t6, $sp, 0x70
  sw    $at, ($t6)
  sw    $t9, 4($t6)
  lw    $t9, 0xc($t7)
  lw    $at, 8($t7)
  sw    $t9, 0xc($t6)
  sw    $at, 8($t6)
  lw    $t8, 8($s2)
  andi  $t5, $t8, 2
  beql  $t5, $zero, .L7F073FB4
   lw    $ra, 0x24($sp)
  lh    $t4, ($v0)
  move  $a0, $s0
  beql  $t4, $zero, .L7F073FB4
   lw    $ra, 0x24($sp)
  jal   sub_GAME_7F06C570
   move  $a1, $zero
  lw    $t6, 0x104($sp)
  sll   $t9, $v0, 6
  lwc1  $f8, ($s1)
  lw    $t7, 0xc($t6)
  lwc1  $f4, 4($s1)
  addu  $s0, $t7, $t9
  lwc1  $f10, ($s0)
  mul.s $f6, $f8, $f10
  lwc1  $f8, 0x10($s0)
  mul.s $f10, $f4, $f8
  lwc1  $f8, 8($s1)
  add.s $f4, $f6, $f10
  lwc1  $f6, 0x20($s0)
  mul.s $f10, $f8, $f6
  lwc1  $f6, 0x30($s0)
  add.s $f8, $f4, $f10
  add.s $f4, $f6, $f8
  neg.s $f10, $f4
  swc1  $f10, 0xd0($sp)
  lwc1  $f6, ($s1)
  lwc1  $f8, 4($s0)
  mul.s $f4, $f6, $f8
  lwc1  $f8, 0x14($s0)
  lwc1  $f6, 4($s1)
  mul.s $f6, $f6, $f8
  add.s $f8, $f4, $f6
  lwc1  $f6, 0x24($s0)
  lwc1  $f4, 8($s1)
  mul.s $f4, $f4, $f6
  add.s $f6, $f8, $f4
  lwc1  $f8, 0x34($s0)
  add.s $f4, $f8, $f6
  neg.s $f8, $f4
  swc1  $f8, 0xd4($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f6, ($s1)
  mul.s $f6, $f6, $f4
  lwc1  $f4, 4($s1)
  swc1  $f10, 0x28($sp)
  lwc1  $f10, 0x18($s0)
  mul.s $f4, $f4, $f10
  add.s $f10, $f6, $f4
  lwc1  $f4, 0x28($s0)
  lwc1  $f6, 8($s1)
  mul.s $f6, $f6, $f4
  add.s $f4, $f10, $f6
  lwc1  $f10, 0x38($s0)
  add.s $f6, $f10, $f4
  lwc1  $f4, 0x28($sp)
  neg.s $f10, $f6
  mul.s $f6, $f4, $f4
  swc1  $f10, 0xd8($sp)
  mul.s $f4, $f8, $f8
  add.s $f8, $f6, $f4
  mul.s $f10, $f10, $f10
  jal   sqrtf
   add.s $f12, $f10, $f8
  mtc1  $zero, $f14
  nop   
  c.lt.s $f14, $f0
  nop   
  bc1fl .L7F0739D0
   lw    $t5, 0x104($sp)
  lw    $t8, 0x104($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x14($t8)
  lwc1  $f8, 0xd0($sp)
  mul.s $f10, $f4, $f0
  div.s $f2, $f6, $f10
  lwc1  $f6, 0xd4($sp)
  mul.s $f4, $f8, $f2
  lwc1  $f8, 0xd8($sp)
  mul.s $f10, $f6, $f2
  swc1  $f4, 0xd0($sp)
  mul.s $f4, $f8, $f2
  swc1  $f10, 0xd4($sp)
  b     .L7F0739EC
   swc1  $f4, 0xd8($sp)
  lw    $t5, 0x104($sp)
.L7F0739D0:
  swc1  $f14, 0xd0($sp)
  swc1  $f14, 0xd4($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f6
  lwc1  $f10, 0x14($t5)
  div.s $f8, $f6, $f10
  swc1  $f8, 0xd8($sp)
.L7F0739EC:
  lwc1  $f4, 0xd0($sp)
  lwc1  $f6, 0x10($s0)
  lwc1  $f8, 0xd4($sp)
  mul.s $f10, $f4, $f6
  lwc1  $f4, 0x14($s0)
  mul.s $f6, $f8, $f4
  lwc1  $f4, 0x18($s0)
  add.s $f8, $f10, $f6
  lwc1  $f10, 0xd8($sp)
  mul.s $f6, $f4, $f10
  jal   sub_GAME_7F05ACB0
   add.s $f12, $f6, $f8
  swc1  $f0, 0xdc($sp)
  jal   sinf
   mov.s $f12, $f0
  lwc1  $f4, 0xd0($sp)
  lwc1  $f10, 0x20($s0)
  lwc1  $f8, 0xd4($sp)
  mul.s $f6, $f4, $f10
  lwc1  $f4, 0x24($s0)
  mul.s $f10, $f8, $f4
  lwc1  $f4, 0xd8($sp)
  add.s $f8, $f6, $f10
  lwc1  $f6, 0x28($s0)
  mul.s $f10, $f4, $f6
  add.s $f4, $f8, $f10
  neg.s $f6, $f4
  jal   sub_GAME_7F05ACB0
   div.s $f12, $f6, $f0
  lwc1  $f8, 0xd0($sp)
  lwc1  $f10, ($s0)
  lwc1  $f6, 0xd4($sp)
  mov.s $f12, $f0
  mul.s $f4, $f8, $f10
  lwc1  $f8, 4($s0)
  mul.s $f10, $f6, $f8
  lwc1  $f8, 8($s0)
  add.s $f6, $f4, $f10
  lwc1  $f4, 0xd8($sp)
  mul.s $f10, $f8, $f4
  mtc1  $zero, $f8
  add.s $f2, $f10, $f6
  neg.s $f2, $f2
  c.lt.s $f2, $f8
  nop   
  bc1f  .L7F073AB0
   lui   $at, %hi(D_80054D50)
  lwc1  $f4, %lo(D_80054D50)($at)
  sub.s $f12, $f4, $f0
.L7F073AB0:
  jal   cosf
   swc1  $f12, 0xe0($sp)
  lwc1  $f12, 0xe0($sp)
  jal   sinf
   swc1  $f0, 0xcc($sp)
  swc1  $f0, 0xc8($sp)
  jal   cosf
   lwc1  $f12, 0xdc($sp)
  swc1  $f0, 0xc4($sp)
  jal   sinf
   lwc1  $f12, 0xdc($sp)
  jal   get_random_value
   swc1  $f0, 0xc0($sp)
  andi  $t4, $v0, 0x7f
  mtc1  $t4, $f10
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f0
  lwc1  $f12, 0xcc($sp)
  lwc1  $f14, 0xc8($sp)
  lwc1  $f18, 0xc4($sp)
  bgez  $t4, .L7F073B18
   cvt.s.w $f6, $f10
  li    $at, 0x4F800000 # 4294967296.000000
  mtc1  $at, $f8
  nop   
  add.s $f6, $f6, $f8
.L7F073B18:
  li    $at, 0x3B800000 # 0.003906
  mtc1  $at, $f4
  li    $at, 0x3F400000 # 0.750000
  mtc1  $at, $f8
  mul.s $f10, $f6, $f4
  lwc1  $f6, 0xc($s1)
  lui   $v1, %hi(D_8003608C)
  lw    $v1, %lo(D_8003608C)($v1)
  lui   $a0, %hi(aDogfnegxNoVtxAllocator)
  addiu $a0, %lo(aDogfnegxNoVtxAllocator) # addiu $a0, $a0, 0x4a74
  add.s $f2, $f10, $f8
  mul.s $f4, $f6, $f2
  swc1  $f4, 0x8c($sp)
  lwc1  $f10, 0x10($s1)
  mul.s $f8, $f10, $f2
  lwc1  $f10, 0x8c($sp)
  swc1  $f8, 0x90($sp)
  lwc1  $f6, 0x14($s1)
  mul.s $f4, $f6, $f2
  nop   
  mul.s $f8, $f10, $f12
  swc1  $f4, 0x94($sp)
  lwc1  $f4, 0x94($sp)
  mul.s $f6, $f8, $f0
  nop   
  mul.s $f8, $f4, $f14
  swc1  $f6, 0xbc($sp)
  mul.s $f6, $f8, $f0
  lwc1  $f8, 0x90($sp)
  swc1  $f6, 0xb8($sp)
  lwc1  $f6, 0xc0($sp)
  mul.s $f8, $f8, $f6
  nop   
  mul.s $f16, $f8, $f0
  nop   
  mul.s $f6, $f10, $f18
  nop   
  mul.s $f8, $f6, $f14
  nop   
  mul.s $f6, $f8, $f0
  nop   
  mul.s $f8, $f4, $f18
  swc1  $f6, 0xb0($sp)
  mul.s $f6, $f8, $f12
  nop   
  mul.s $f4, $f6, $f0
  swc1  $f4, 0xac($sp)
  mul.s $f6, $f10, $f0
  lwc1  $f8, ($s1)
  sub.s $f4, $f8, $f6
  swc1  $f4, 0x80($sp)
  lwc1  $f10, 4($s1)
  swc1  $f10, 0x84($sp)
  lwc1  $f8, 8($s1)
  bnez  $v1, .L7F073C14
   swc1  $f8, 0x88($sp)
  jal   osSyncPrintf
   swc1  $f16, 0xb4($sp)
  jal   return_null
   nop   
  lui   $v1, %hi(D_8003608C)
  lw    $v1, %lo(D_8003608C)($v1)
  lwc1  $f16, 0xb4($sp)
.L7F073C14:
  li    $a0, 4
  jalr  $v1
  swc1  $f16, 0xb4($sp)
  addiu $v1, $sp, 0x70
  sw    $v0, 0x6c($sp)
  lw    $at, ($v1)
  lwc1  $f16, 0xb4($sp)
  sw    $at, ($v0)
  lw    $t9, 4($v1)
  sw    $t9, 4($v0)
  lw    $at, 8($v1)
  sw    $at, 8($v0)
  lw    $t9, 0xc($v1)
  sw    $t9, 0xc($v0)
  lw    $at, ($v1)
  sw    $at, 0x10($v0)
  lw    $t4, 4($v1)
  sw    $t4, 0x14($v0)
  lw    $at, 8($v1)
  sw    $at, 0x18($v0)
  lw    $t4, 0xc($v1)
  sw    $t4, 0x1c($v0)
  lw    $at, ($v1)
  sw    $at, 0x20($v0)
  lw    $t9, 4($v1)
  sw    $t9, 0x24($v0)
  lw    $at, 8($v1)
  sw    $at, 0x28($v0)
  lw    $t9, 0xc($v1)
  sw    $t9, 0x2c($v0)
  lw    $at, ($v1)
  sw    $at, 0x30($v0)
  lw    $t4, 4($v1)
  sw    $t4, 0x34($v0)
  lw    $at, 8($v1)
  sw    $at, 0x38($v0)
  lw    $t4, 0xc($v1)
  sw    $t4, 0x3c($v0)
  lwc1  $f0, 0xbc($sp)
  lwc1  $f6, 0x80($sp)
  lwc1  $f12, 0xb0($sp)
  neg.s $f0, $f0
  add.s $f4, $f6, $f0
  neg.s $f12, $f12
  add.s $f10, $f4, $f12
  trunc.w.s $f8, $f10
  mfc1  $t7, $f8
  nop   
  sh    $t7, ($v0)
  lwc1  $f6, 0x84($sp)
  sub.s $f4, $f6, $f16
  trunc.w.s $f10, $f4
  mfc1  $t8, $f10
  nop   
  sh    $t8, 2($v0)
  lwc1  $f2, 0xb8($sp)
  lwc1  $f8, 0x88($sp)
  lwc1  $f14, 0xac($sp)
  neg.s $f2, $f2
  sub.s $f6, $f8, $f2
  neg.s $f14, $f14
  add.s $f4, $f6, $f14
  trunc.w.s $f10, $f4
  mfc1  $t4, $f10
  nop   
  sh    $t4, 4($v0)
  lwc1  $f8, 0x80($sp)
  add.s $f6, $f8, $f0
  sub.s $f4, $f6, $f12
  trunc.w.s $f10, $f4
  mfc1  $t7, $f10
  nop   
  sh    $t7, 0x10($v0)
  lwc1  $f8, 0x84($sp)
  add.s $f6, $f8, $f16
  trunc.w.s $f4, $f6
  mfc1  $t8, $f4
  nop   
  sh    $t8, 0x12($v0)
  lwc1  $f10, 0x88($sp)
  sub.s $f8, $f10, $f2
  sub.s $f6, $f8, $f14
  trunc.w.s $f4, $f6
  mfc1  $t4, $f4
  nop   
  sh    $t4, 0x14($v0)
  lwc1  $f10, 0x80($sp)
  sub.s $f8, $f10, $f0
  sub.s $f6, $f8, $f12
  trunc.w.s $f4, $f6
  mfc1  $t7, $f4
  nop   
  sh    $t7, 0x20($v0)
  lwc1  $f10, 0x84($sp)
  add.s $f8, $f10, $f16
  trunc.w.s $f6, $f8
  mfc1  $t8, $f6
  nop   
  sh    $t8, 0x22($v0)
  lwc1  $f4, 0x88($sp)
  add.s $f10, $f4, $f2
  sub.s $f8, $f10, $f14
  trunc.w.s $f6, $f8
  mfc1  $t4, $f6
  nop   
  sh    $t4, 0x24($v0)
  lwc1  $f4, 0x80($sp)
  sub.s $f10, $f4, $f0
  add.s $f8, $f10, $f12
  trunc.w.s $f6, $f8
  mfc1  $t7, $f6
  nop   
  sh    $t7, 0x30($v0)
  lwc1  $f4, 0x84($sp)
  lui   $t7, (0xBC001406 >> 16) # lui $t7, 0xbc00
  ori   $t7, (0xBC001406 & 0xFFFF) # ori $t7, $t7, 0x1406
  sub.s $f10, $f4, $f16
  trunc.w.s $f8, $f10
  mfc1  $t8, $f8
  nop   
  sh    $t8, 0x32($v0)
  lwc1  $f6, 0x88($sp)
  add.s $f4, $f6, $f2
  add.s $f10, $f4, $f14
  trunc.w.s $f8, $f10
  mfc1  $t4, $f8
  nop   
  sh    $t4, 0x34($v0)
  lw    $v1, 0xc($s2)
  addiu $t6, $v1, 8
  sw    $t6, 0xc($s2)
  sw    $t7, ($v1)
  lw    $a0, 0x24($s1)
  jal   osVirtualToPhysical
   sw    $v1, 0x5c($sp)
  lw    $a1, 0x5c($sp)
  move  $a0, $s2
  sw    $v0, 4($a1)
  lw    $v1, 0x18($s1)
  move  $a1, $zero
  beqz  $v1, .L7F073F24
   nop   
  jal   get_random_value
   move  $s1, $v1
  sll   $t9, $v0, 0xa
  sh    $t9, 0x56($sp)
  jal   coss
   andi  $a0, $t9, 0xffff
  lbu   $t8, 4($s1)
  lhu   $a0, 0x56($sp)
  multu $v0, $t8
  mflo  $t1
  sll   $t5, $t1, 2
  subu  $t5, $t5, $t1
  sll   $t5, $t5, 2
  subu  $t5, $t5, $t1
  sll   $t5, $t5, 2
  addu  $t5, $t5, $t1
  sll   $t5, $t5, 2
  addu  $t5, $t5, $t1
  sra   $t4, $t5, 0x12
  jal   sins
   sw    $t4, 0x50($sp)
  lbu   $a0, 4($s1)
  lw    $t0, 0x6c($sp)
  lw    $t1, 0x50($sp)
  multu $v0, $a0
  sll   $v1, $a0, 4
  subu  $a2, $v1, $t1
  sh    $a2, 8($t0)
  sh    $a2, 0x1a($t0)
  addu  $t3, $v1, $t1
  li    $a2, 4
  move  $a0, $s2
  sh    $t3, 0x28($t0)
  sh    $t3, 0x3a($t0)
  mflo  $a1
  sll   $t6, $a1, 2
  subu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  subu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a1
  sll   $t6, $t6, 2
  addu  $t6, $t6, $a1
  sra   $t7, $t6, 0x12
  subu  $t2, $v1, $t7
  addu  $a3, $v1, $t7
  move  $a1, $s1
  sh    $t2, 0xa($t0)
  sh    $a3, 0x18($t0)
  sh    $a3, 0x2a($t0)
  jal   sub_GAME_7F073038
   sh    $t2, 0x38($t0)
  b     .L7F073F30
   lw    $v1, 0xc($s2)
.L7F073F24:
  jal   sub_GAME_7F073038
   li    $a2, 1
  lw    $v1, 0xc($s2)
.L7F073F30:
  lui   $t8, 0xb700
  li    $t5, 8192
  addiu $t9, $v1, 8
  sw    $t9, 0xc($s2)
  sw    $t5, 4($v1)
  sw    $t8, ($v1)
  lw    $s1, 0xc($s2)
  lui   $t6, (0x01020040 >> 16) # lui $t6, 0x102
  ori   $t6, (0x01020040 & 0xFFFF) # ori $t6, $t6, 0x40
  addiu $t4, $s1, 8
  sw    $t4, 0xc($s2)
  move  $a0, $s0
  jal   osVirtualToPhysical
   sw    $t6, ($s1)
  sw    $v0, 4($s1)
  lw    $s0, 0xc($s2)
  lui   $t9, (0x04300040 >> 16) # lui $t9, 0x430
  ori   $t9, (0x04300040 & 0xFFFF) # ori $t9, $t9, 0x40
  addiu $t7, $s0, 8
  sw    $t7, 0xc($s2)
  sw    $t9, ($s0)
  jal   osVirtualToPhysical
   lw    $a0, 0x6c($sp)
  sw    $v0, 4($s0)
  lw    $v1, 0xc($s2)
  lui   $t5, (0xB1000002 >> 16) # lui $t5, 0xb100    # gSP4Triangles(6,1,2,8,2,0,1,0,0,0,0,0
  ori   $t5, (0xB1000002 & 0xFFFF) # ori $t5, $t5, 2
  addiu $t8, $v1, 8
  sw    $t8, 0xc($s2)
  li    $t4, 12816
  sw    $t4, 4($v1)
  sw    $t5, ($v1)                                    # ),
  lw    $ra, 0x24($sp)
.L7F073FB4:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x100
");

asm(R"
glabel sub_GAME_7F073FC8
  lui   $at, %hi(D_800363F0)
  jr    $ra
   sw    $a0, %lo(D_800363F0)($at)
");

asm(R"
glabel doshadow
  lui   $v1, %hi(D_800363F0)
  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x63f0
  lw    $t6, ($v1)
  addiu $sp, $sp, -0x78
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a2, 0x80($sp)
  blez  $t6, .L7F074500
   move  $a3, $a1
  lui   $t9, %hi(D_800363F8) 
  addiu $t9, %lo(D_800363F8) # addiu $t9, $t9, 0x63f8
  lw    $at, ($t9)
  lw    $t1, 4($t9)
  lw    $a2, 4($a2)
  addiu $t8, $sp, 0x58
  sw    $at, ($t8)
  sw    $t1, 4($t8)
  lw    $t1, 0xc($t9)
  lw    $at, 8($t9)
  move  $a0, $a1
  sw    $t1, 0xc($t8)
  sw    $at, 8($t8)
  lw    $a1, 0x14($a2)
  sw    $a3, 0x7c($sp)
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x6c($sp)
  lw    $t2, 8($s0)
  lw    $a2, 0x6c($sp)
  lwc1  $f4, 0xc($v0)
  lwc1  $f6, 4($v0)
  lui   $v1, %hi(D_800363F0)
  andi  $t3, $t2, 2
  addiu $v1, %lo(D_800363F0) # addiu $v1, $v1, 0x63f0
  lw    $a3, 0x7c($sp)
  lwc1  $f12, 8($a2)
  lwc1  $f14, 0xc($a2)
  beqz  $t3, .L7F074500
   sub.s $f2, $f4, $f6
  lw    $v0, 0x30($s0)
  li    $at, 3
  move  $a1, $zero
  beq   $v0, $at, .L7F07408C
   li    $at, 8
  bnel  $v0, $at, .L7F0740C4
   lw    $t8, ($v1)
.L7F07408C:
  lw    $t4, 0x34($s0)
  lw    $t6, ($v1)
  li    $at, 255
  andi  $t5, $t4, 0xff
  multu $t5, $t6
  mflo  $v0
  nop   
  nop   
  divu  $zero, $v0, $at
  mflo  $t0
  sb    $t0, 0x67($sp)
  b     .L7F0740CC
   lw    $a0, 0x80($sp)
  lw    $t8, ($v1)
.L7F0740C4:
  sb    $t8, 0x67($sp)
  lw    $a0, 0x80($sp)
.L7F0740CC:
  sw    $a2, 0x6c($sp)
  sw    $a3, 0x7c($sp)
  swc1  $f2, 0x40($sp)
  swc1  $f12, 0x48($sp)
  jal   sub_GAME_7F06C570
   swc1  $f14, 0x44($sp)
  lw    $a3, 0x7c($sp)
  sll   $t1, $v0, 6
  lw    $a2, 0x6c($sp)
  lw    $t9, 0xc($a3)
  lwc1  $f2, 0x40($sp)
  lwc1  $f12, 0x48($sp)
  addu  $t2, $t9, $t1
  sw    $t2, 0x70($sp)
  lw    $t3, 4($s0)
  lwc1  $f14, 0x44($sp)
  li    $at, 0x40000000 # 2.000000
  beqz  $t3, .L7F074140
   lui   $v0, %hi(D_8003608C)
  mtc1  $at, $f8
  lwc1  $f18, 0x14($a3)
  sub.s $f10, $f8, $f2
  div.s $f4, $f10, $f18
  trunc.w.s $f6, $f4
  mfc1  $v1, $f6
  nop   
  sll   $t5, $v1, 0x10
  b     .L7F074160
   sra   $v1, $t5, 0x10
.L7F074140:
  lwc1  $f10, 0x14($a3)
  neg.s $f8, $f2
  div.s $f18, $f8, $f10
  trunc.w.s $f4, $f18
  mfc1  $v1, $f4
  nop   
  sll   $t0, $v1, 0x10
  sra   $v1, $t0, 0x10
.L7F074160:
  li    $at, 0x42480000 # 50.000000
  mtc1  $at, $f6
  lui   $a0, %hi(aDoshadowNoVtxAllocator)
  li    $at, 0x43960000 # 300.000000
  c.lt.s $f2, $f6
  addiu $a0, %lo(aDoshadowNoVtxAllocator) # addiu $a0, $a0, 0x4a94
  bc1fl .L7F0741A4
   mtc1  $at, $f16
  li    $at, 0x3FA00000 # 1.250000
  mtc1  $at, $f0
  nop   
  mul.s $f12, $f12, $f0
  nop   
  mul.s $f14, $f14, $f0
  b     .L7F0741E4
   nop   
  mtc1  $at, $f16
.L7F0741A4:
  li    $at, 0x43480000 # 200.000000
  c.lt.s $f16, $f2
  nop   
  bc1fl .L7F0741C8
   sub.s $f8, $f16, $f2
  mtc1  $zero, $f14
  b     .L7F0741E4
   mov.s $f12, $f14
  sub.s $f8, $f16, $f2
.L7F0741C8:
  mtc1  $at, $f10
  nop   
  div.s $f0, $f8, $f10
  mul.s $f12, $f12, $f0
  nop   
  mul.s $f14, $f14, $f0
  nop   
.L7F0741E4:
  lw    $v0, %lo(D_8003608C)($v0)
  bnezl $v0, .L7F074228
   li    $a0, 4
  sh    $v1, 0x52($sp)
  sw    $a2, 0x6c($sp)
  swc1  $f12, 0x48($sp)
  jal   osSyncPrintf
   swc1  $f14, 0x44($sp)
  jal   return_null
   nop   
  lui   $v0, %hi(D_8003608C)
  lw    $v0, %lo(D_8003608C)($v0)
  lh    $v1, 0x52($sp)
  lw    $a2, 0x6c($sp)
  lwc1  $f12, 0x48($sp)
  lwc1  $f14, 0x44($sp)
  li    $a0, 4
.L7F074228:
  sh    $v1, 0x52($sp)
  sw    $a2, 0x6c($sp)
  swc1  $f12, 0x48($sp)
  jalr  $v0
  swc1  $f14, 0x44($sp)
  addiu $a0, $sp, 0x58
  lw    $at, ($a0)
  lh    $v1, 0x52($sp)
  lw    $a2, 0x6c($sp)
  lwc1  $f12, 0x48($sp)
  lwc1  $f14, 0x44($sp)
  sw    $at, ($v0)
  lw    $t2, 4($a0)
  sw    $t2, 4($v0)
  lw    $at, 8($a0)
  sw    $at, 8($v0)
  lw    $t2, 0xc($a0)
  sw    $t2, 0xc($v0)
  lw    $at, ($a0)
  sw    $at, 0x10($v0)
  lw    $t5, 4($a0)
  sw    $t5, 0x14($v0)
  lw    $at, 8($a0)
  sw    $at, 0x18($v0)
  lw    $t5, 0xc($a0)
  sw    $t5, 0x1c($v0)
  lw    $at, ($a0)
  sw    $at, 0x20($v0)
  lw    $t0, 4($a0)
  sw    $t0, 0x24($v0)
  lw    $at, 8($a0)
  sw    $at, 0x28($v0)
  lw    $t0, 0xc($a0)
  sw    $t0, 0x2c($v0)
  lw    $at, ($a0)
  sw    $at, 0x30($v0)
  lw    $t9, 4($a0)
  sw    $t9, 0x34($v0)
  lw    $at, 8($a0)
  sw    $at, 0x38($v0)
  lw    $t9, 0xc($a0)
  sw    $t9, 0x3c($v0)
  lwc1  $f18, ($a2)
  sh    $v1, 2($v0)
  sub.s $f4, $f18, $f12
  trunc.w.s $f6, $f4
  mfc1  $t4, $f6
  nop   
  sh    $t4, ($v0)
  lwc1  $f8, 4($a2)
  sub.s $f10, $f8, $f14
  trunc.w.s $f18, $f10
  mfc1  $t5, $f18
  nop   
  sh    $t5, 4($v0)
  lwc1  $f4, ($a2)
  sh    $v1, 0x12($v0)
  sub.s $f6, $f4, $f12
  trunc.w.s $f8, $f6
  mfc1  $t6, $f8
  nop   
  sh    $t6, 0x10($v0)
  lwc1  $f10, 4($a2)
  add.s $f18, $f10, $f14
  trunc.w.s $f4, $f18
  mfc1  $t1, $f4
  nop   
  sh    $t1, 0x14($v0)
  lwc1  $f6, ($a2)
  sh    $v1, 0x22($v0)
  lui   $t1, (0xBC001406 >> 16) # lui $t1, 0xbc00
  add.s $f8, $f6, $f12
  ori   $t1, (0xBC001406 & 0xFFFF) # ori $t1, $t1, 0x1406
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sh    $t9, 0x20($v0)
  lwc1  $f18, 4($a2)
  add.s $f4, $f18, $f14
  trunc.w.s $f6, $f4
  mfc1  $t4, $f6
  nop   
  sh    $t4, 0x24($v0)
  lwc1  $f8, ($a2)
  sh    $v1, 0x32($v0)
  add.s $f10, $f8, $f12
  trunc.w.s $f18, $f10
  mfc1  $t5, $f18
  nop   
  sh    $t5, 0x30($v0)
  lwc1  $f4, 4($a2)
  sub.s $f6, $f4, $f14
  trunc.w.s $f8, $f6
  mfc1  $t6, $f8
  nop   
  sh    $t6, 0x34($v0)
  lw    $v1, 0xc($s0)
  addiu $t0, $v1, 8
  sw    $t0, 0xc($s0)
  sw    $t1, ($v1)
  lw    $a0, 0x1c($a2)
  sw    $v0, 0x54($sp)
  sw    $a2, 0x6c($sp)
  jal   osVirtualToPhysical
   sw    $v1, 0x38($sp)
  lw    $a1, 0x38($sp)
  lw    $a2, 0x6c($sp)
  lw    $a3, 0x54($sp)
  sw    $v0, 4($a1)
  lw    $v1, 0x10($a2)
  li    $a2, 1
  move  $a1, $zero
  beqz  $v1, .L7F07445C
   move  $a0, $s0
  sh    $zero, 8($a3)
  sh    $zero, 0xa($a3)
  lbu   $t8, 4($v1)
  sh    $zero, 0x1a($a3)
  move  $a1, $v1
  sll   $t9, $t8, 5
  addiu $t2, $t9, -1
  sh    $t2, 0x18($a3)
  lbu   $t4, 4($v1)
  move  $a0, $s0
  li    $a2, 4
  sll   $t3, $t4, 5
  addiu $t5, $t3, -1
  sh    $t5, 0x28($a3)
  lbu   $t7, 5($v1)
  sh    $zero, 0x38($a3)
  sll   $t6, $t7, 5
  addiu $t0, $t6, -1
  sh    $t0, 0x2a($a3)
  lbu   $t1, 5($v1)
  sll   $t8, $t1, 5
  addiu $t9, $t8, -1
  sh    $t9, 0x3a($a3)
  jal   sub_GAME_7F073038
   sw    $a3, 0x54($sp)
  b     .L7F074468
   lw    $a3, 0x54($sp)
.L7F07445C:
  jal   sub_GAME_7F073038
   sw    $a3, 0x54($sp)
  lw    $a3, 0x54($sp)
.L7F074468:
  lw    $v1, 0xc($s0)
  lui   $t4, 0xb700
  li    $t3, 8192
  addiu $t2, $v1, 8
  sw    $t2, 0xc($s0)
  sw    $t4, ($v1)
  sw    $t3, 4($v1)
  lw    $v1, 0xc($s0)
  lui   $t7, (0x01020040 >> 16) # lui $t7, 0x102
  ori   $t7, (0x01020040 & 0xFFFF) # ori $t7, $t7, 0x40
  addiu $t5, $v1, 8
  sw    $t5, 0xc($s0)
  sw    $t7, ($v1)
  sw    $a3, 0x54($sp)
  lw    $a0, 0x70($sp)
  jal   osVirtualToPhysical
   sw    $v1, 0x2c($sp)
  lw    $a1, 0x2c($sp)
  lw    $a0, 0x54($sp)
  lui   $t0, (0x04300040 >> 16) # lui $t0, 0x430
  sw    $v0, 4($a1)
  lw    $v1, 0xc($s0)
  ori   $t0, (0x04300040 & 0xFFFF) # ori $t0, $t0, 0x40
  addiu $t6, $v1, 8
  sw    $t6, 0xc($s0)
  sw    $t0, ($v1)
  jal   osVirtualToPhysical
   sw    $v1, 0x28($sp)
  lw    $a2, 0x28($sp)
  lui   $t8, (0xB1000002 >> 16) # lui $t8, 0xb100
  ori   $t8, (0xB1000002 & 0xFFFF) # ori $t8, $t8, 2
  sw    $v0, 4($a2)
  lw    $v1, 0xc($s0)
  li    $t9, 12816
  addiu $t1, $v1, 8
  sw    $t1, 0xc($s0)
  sw    $t9, 4($v1)
  sw    $t8, ($v1)
.L7F074500:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x78
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F074514
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
glabel sub_GAME_7F074524
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  jr    $ra
   sw    $a2, 8($sp)
");

asm(R"
.late_rodata
/*80054D54*/
glabel jpt_80054D54
.word .L7F074674
.word .L7F074674
.word .L7F074674
.word .L7F07460C
.word .L7F07464C
.word .L7F07466C
.word .L7F07465C
.word .L7F07456C
.word .L7F0745A8
.word .L7F0745EC
.word .L7F0745BC
.word .L7F0745CC
.word .L7F0745DC
.word .L7F074674
.word .L7F074674
.word .L7F074674
.word .L7F0745FC
.word .L7F074580
.word .L7F074674
.word .L7F07462C
.word .L7F074674
.word .L7F07463C
.word .L7F074594
.word .L7F07461C
.text
glabel sub_GAME_7F074534
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  lhu   $v0, ($a2)
  move  $a3, $a1
  andi  $t6, $v0, 0xff
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x18
  beqz  $at, .L7F074674
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80054D54)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80054D54)($at)
.L7F074564:
  jr    $t7
   nop   
.L7F07456C:
  move  $a0, $a3
  jal   sub_GAME_7F06E970
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F074580:
  move  $a0, $a3
  jal   process_12_handle_switch
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F074594:
  move  $a0, $a3
  jal   process_17_pointer_to_head
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745A8:
  move  $a0, $a3
  jal   sub_GAME_7F06EB10
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745BC:
  jal   sub_GAME_7F0737FC
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745CC:
  jal   dogfnegx
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745DC:
  jal   doshadow
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745EC:
  jal   sub_GAME_7F074514
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F0745FC:
  jal   sub_GAME_7F074524
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07460C:
  jal   sub_GAME_7F072784
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07461C:
  jal   sub_GAME_7F072984
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07462C:
  jal   sub_GAME_7F072C10
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07463C:
  jal   dorottex
   move  $a1, $a2
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07464C:
  jal   sub_GAME_7F07306C
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07465C:
  jal   dotube
   move  $a1, $a3
  b     .L7F074678
   lw    $ra, 0x14($sp)
.L7F07466C:
  jal   sub_GAME_7F0737EC
   move  $a1, $a3
def_7F074564:
.L7F074674:
  lw    $ra, 0x14($sp)
.L7F074678:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel subdraw
  addiu $sp, $sp, -0x30
  sw    $ra, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $t6, 0xc($a0)
  lw    $v0, 8($a1)
  move  $s1, $a0
  move  $s2, $a1
  bnez  $t6, .L7F0746C8
   lw    $s0, ($v0)
  lui   $a0, %hi(aSubdrawNoGfxlist)
  jal   osSyncPrintf
   addiu $a0, %lo(aSubdrawNoGfxlist) # addiu $a0, $a0, 0x4ab4
  jal   return_null
   nop   
  lw    $v0, 8($s2)
.L7F0746C8:
  lw    $t7, 0x1c($v0)
  lui   $a0, %hi(aSubdrawObjectNotInitialised0xX)
  addiu $a0, %lo(aSubdrawObjectNotInitialised0xX) # addiu $a0, $a0, 0x4acc
  beqz  $t7, .L7F0746E4
   nop   
  b     .L7F0746F8
   lw    $v0, 0xc($s1)
.L7F0746E4:
  jal   osSyncPrintf
   move  $a1, $v0
  jal   return_null
   nop   
  lw    $v0, 0xc($s1)
.L7F0746F8:
  addiu $t8, $v0, 8
  lui   $t9, (0xBC000C06 >> 16) # lui $t9, 0xbc00
  ori   $t9, (0xBC000C06 & 0xFFFF) # ori $t9, $t9, 0xc06
  sw    $t8, 0xc($s1)
  sw    $t9, ($v0)
  lw    $a0, 0xc($s2)
  jal   osVirtualToPhysical
   sw    $v0, 0x28($sp)
  lw    $v1, 0x28($sp)
  beqz  $s0, .L7F074778
   sw    $v0, 4($v1)
  move  $a0, $s1
.L7F074728:
  move  $a1, $s2
  jal   sub_GAME_7F074534
   move  $a2, $s0
  lw    $v0, 0x14($s0)
  beqz  $v0, .L7F074748
   nop   
  b     .L7F074770
   move  $s0, $v0
.L7F074748:
  beqz  $s0, .L7F074770
   nop   
  lw    $v0, 0xc($s0)
.L7F074754:
  beql  $v0, $zero, .L7F074768
   lw    $s0, 8($s0)
  b     .L7F074770
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F074768:
  bnezl $s0, .L7F074754
   lw    $v0, 0xc($s0)
.L7F074770:
  bnezl $s0, .L7F074728
   move  $a0, $s1
.L7F074778:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F074790
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a0, 0x18($sp)
  sw    $a1, 0x1c($sp)
  jal   subcalcpos
   move  $a0, $a1
  lw    $a0, 0x18($sp)
  jal   subcalcmatrices
   lw    $a1, 0x1c($sp)
  lw    $a0, 0x18($sp)
  jal   subdraw
   lw    $a1, 0x1c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0747D0
  lwc1  $f0, ($a1)
  lwc1  $f2, 4($a1)
  addiu $sp, $sp, -0xb8
  mul.s $f16, $f0, $f0
  nop   
  mul.s $f4, $f2, $f2
  swc1  $f4, 0xb0($sp)
  lwc1  $f12, 8($a1)
  lwc1  $f8, 0xb0($sp)
  mul.s $f6, $f12, $f12
  add.s $f10, $f16, $f8
  swc1  $f6, 0xac($sp)
  lwc1  $f4, 0xac($sp)
  lwc1  $f6, 4($a0)
  add.s $f14, $f10, $f4
  neg.s $f14, $f14
  mul.s $f8, $f14, $f6
  swc1  $f8, 0xa4($sp)
  lwc1  $f10, 8($a0)
  mul.s $f4, $f14, $f10
  swc1  $f4, 0xa0($sp)
  lwc1  $f6, 8($a3)
  swc1  $f6, 0x14($sp)
  lwc1  $f8, ($a3)
  swc1  $f8, 0x10($sp)
  lwc1  $f10, 4($a3)
  lwc1  $f4, 0x10($sp)
  swc1  $f10, 0xc($sp)
  mul.s $f6, $f0, $f4
  lwc1  $f8, 0xc($sp)
  mul.s $f10, $f2, $f8
  lwc1  $f8, 0x14($sp)
  add.s $f4, $f6, $f10
  mul.s $f6, $f8, $f12
  add.s $f10, $f6, $f4
  swc1  $f10, 0x9c($sp)
  lwc1  $f6, 0x38($a1)
  lwc1  $f8, 8($a2)
  sub.s $f4, $f8, $f6
  swc1  $f4, 8($sp)
  lwc1  $f6, 0x30($a1)
  lwc1  $f8, ($a2)
  sub.s $f4, $f8, $f6
  swc1  $f4, 4($sp)
  lwc1  $f6, 0x34($a1)
  lwc1  $f8, 4($a2)
  sub.s $f4, $f8, $f6
  lwc1  $f8, 4($sp)
  swc1  $f4, ($sp)
  mul.s $f6, $f0, $f8
  lwc1  $f4, ($sp)
  mul.s $f8, $f2, $f4
  add.s $f4, $f6, $f8
  lwc1  $f6, 8($sp)
  mul.s $f8, $f6, $f12
  mtc1  $zero, $f12
  lwc1  $f6, 0xa0($sp)
  c.lt.s $f10, $f12
  add.s $f18, $f8, $f4
  lwc1  $f8, 0xa4($sp)
  add.s $f0, $f18, $f6
  add.s $f18, $f18, $f8
  neg.s $f0, $f0
  bc1f  .L7F0748E4
   neg.s $f18, $f18
  neg.s $f4, $f10
  neg.s $f18, $f18
  swc1  $f4, 0x9c($sp)
  neg.s $f0, $f0
.L7F0748E4:
  c.lt.s $f18, $f12
  nop   
  bc1fl .L7F074910
   c.lt.s $f0, $f18
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F074910
   c.lt.s $f0, $f18
  b     .L7F074C60
   move  $v0, $zero
  c.lt.s $f0, $f18
.L7F074910:
  swc1  $f0, 0x94($sp)
  bc1fl .L7F07492C
   lwc1  $f0, 0x10($a1)
  mov.s $f2, $f18
  mov.s $f18, $f0
  swc1  $f2, 0x94($sp)
  lwc1  $f0, 0x10($a1)
.L7F07492C:
  mul.s $f6, $f0, $f0
  swc1  $f6, 0x88($sp)
  lwc1  $f2, 0x14($a1)
  lwc1  $f4, 0x88($sp)
  mul.s $f8, $f2, $f2
  swc1  $f8, 0x84($sp)
  lwc1  $f12, 0x18($a1)
  lwc1  $f6, 0x84($sp)
  mul.s $f10, $f12, $f12
  add.s $f8, $f4, $f6
  swc1  $f10, 0x80($sp)
  lwc1  $f10, 0x80($sp)
  lwc1  $f4, 0xc($a0)
  add.s $f14, $f8, $f10
  neg.s $f14, $f14
  mul.s $f6, $f14, $f4
  lwc1  $f4, 0x10($sp)
  swc1  $f6, 0x78($sp)
  lwc1  $f8, 0x10($a0)
  mul.s $f10, $f14, $f8
  lwc1  $f8, 0xc($sp)
  mul.s $f6, $f0, $f4
  swc1  $f10, 0x74($sp)
  mul.s $f10, $f2, $f8
  lwc1  $f8, 0x14($sp)
  add.s $f4, $f6, $f10
  mul.s $f6, $f8, $f12
  lwc1  $f8, 4($sp)
  add.s $f10, $f6, $f4
  mul.s $f6, $f0, $f8
  lwc1  $f4, ($sp)
  swc1  $f10, 0x70($sp)
  mul.s $f8, $f2, $f4
  mov.s $f14, $f10
  add.s $f4, $f6, $f8
  lwc1  $f6, 8($sp)
  mul.s $f8, $f6, $f12
  mtc1  $zero, $f12
  lwc1  $f6, 0x74($sp)
  c.lt.s $f10, $f12
  add.s $f16, $f8, $f4
  lwc1  $f8, 0x78($sp)
  lwc1  $f4, 0x9c($sp)
  add.s $f0, $f16, $f6
  add.s $f16, $f16, $f8
  neg.s $f0, $f0
  bc1f  .L7F0749F8
   neg.s $f16, $f16
  neg.s $f14, $f10
  neg.s $f16, $f16
  neg.s $f0, $f0
.L7F0749F8:
  c.lt.s $f16, $f12
  nop   
  bc1fl .L7F074A24
   c.lt.s $f0, $f16
  c.lt.s $f0, $f12
  nop   
  bc1fl .L7F074A24
   c.lt.s $f0, $f16
  b     .L7F074C60
   move  $v0, $zero
  c.lt.s $f0, $f16
.L7F074A24:
  lwc1  $f8, 0x94($sp)
  bc1f  .L7F074A3C
   nop   
  mov.s $f2, $f16
  mov.s $f16, $f0
  mov.s $f0, $f2
.L7F074A3C:
  mul.s $f12, $f16, $f4
  nop   
  mul.s $f2, $f18, $f14
  c.lt.s $f12, $f2
  nop   
  bc1f  .L7F074A8C
   nop   
  mul.s $f12, $f0, $f4
  c.lt.s $f12, $f2
  nop   
  bc1fl .L7F074A78
   lwc1  $f6, 0x94($sp)
  b     .L7F074C60
   move  $v0, $zero
  lwc1  $f6, 0x94($sp)
.L7F074A78:
  lwc1  $f10, 0x9c($sp)
  swc1  $f18, 0x5c($sp)
  mul.s $f2, $f6, $f14
  b     .L7F074ABC
   swc1  $f10, 0x58($sp)
.L7F074A8C:
  mul.s $f2, $f8, $f14
  c.lt.s $f2, $f12
  nop   
  bc1fl .L7F074AAC
   lwc1  $f4, 0x9c($sp)
  b     .L7F074C60
   move  $v0, $zero
  lwc1  $f4, 0x9c($sp)
.L7F074AAC:
  swc1  $f16, 0x5c($sp)
  swc1  $f14, 0x58($sp)
  mul.s $f12, $f0, $f4
  nop   
.L7F074ABC:
  c.lt.s $f2, $f12
  lwc1  $f10, 0x94($sp)
  bc1fl .L7F074AE0
   swc1  $f0, 0x54($sp)
  lwc1  $f6, 0x9c($sp)
  swc1  $f10, 0x54($sp)
  b     .L7F074AE4
   swc1  $f6, 0x50($sp)
  swc1  $f0, 0x54($sp)
.L7F074AE0:
  swc1  $f14, 0x50($sp)
.L7F074AE4:
  lwc1  $f0, 0x20($a1)
  lwc1  $f2, 0x24($a1)
  mul.s $f18, $f0, $f0
  nop   
  mul.s $f8, $f2, $f2
  swc1  $f8, 0x40($sp)
  lwc1  $f12, 0x28($a1)
  lwc1  $f10, 0x40($sp)
  mul.s $f4, $f12, $f12
  add.s $f6, $f18, $f10
  swc1  $f4, 0x3c($sp)
  lwc1  $f8, 0x3c($sp)
  lwc1  $f4, 0x14($a0)
  add.s $f16, $f6, $f8
  neg.s $f16, $f16
  mul.s $f10, $f16, $f4
  lwc1  $f4, 0x10($sp)
  swc1  $f10, 0x34($sp)
  lwc1  $f6, 0x18($a0)
  mul.s $f8, $f16, $f6
  lwc1  $f6, 0xc($sp)
  mul.s $f10, $f0, $f4
  swc1  $f8, 0x30($sp)
  mul.s $f8, $f2, $f6
  lwc1  $f6, 0x14($sp)
  add.s $f4, $f10, $f8
  mul.s $f10, $f6, $f12
  lwc1  $f6, 4($sp)
  add.s $f8, $f10, $f4
  mul.s $f10, $f0, $f6
  lwc1  $f4, ($sp)
  swc1  $f8, 0x2c($sp)
  mul.s $f6, $f2, $f4
  mtc1  $zero, $f2
  nop   
  c.lt.s $f8, $f2
  add.s $f4, $f10, $f6
  lwc1  $f10, 8($sp)
  mul.s $f6, $f10, $f12
  lwc1  $f10, 0x30($sp)
  mov.s $f12, $f8
  add.s $f14, $f6, $f4
  lwc1  $f6, 0x34($sp)
  lwc1  $f4, 0x5c($sp)
  add.s $f0, $f14, $f10
  add.s $f14, $f14, $f6
  neg.s $f0, $f0
  bc1f  .L7F074BB4
   neg.s $f14, $f14
  neg.s $f12, $f8
  neg.s $f14, $f14
  neg.s $f0, $f0
.L7F074BB4:
  c.lt.s $f14, $f2
  lwc1  $f8, 0x58($sp)
  bc1fl .L7F074BE0
   c.lt.s $f0, $f14
  c.lt.s $f0, $f2
  nop   
  bc1fl .L7F074BE0
   c.lt.s $f0, $f14
  b     .L7F074C60
   move  $v0, $zero
  c.lt.s $f0, $f14
.L7F074BE0:
  lwc1  $f6, 0x58($sp)
  bc1f  .L7F074BF8
   nop   
  mov.s $f2, $f14
  mov.s $f14, $f0
  mov.s $f0, $f2
.L7F074BF8:
  mul.s $f2, $f4, $f12
  nop   
  mul.s $f10, $f14, $f8
  c.lt.s $f2, $f10
  nop   
  bc1f  .L7F074C40
   nop   
  lwc1  $f6, 0x54($sp)
  lwc1  $f8, 0x50($sp)
  mul.s $f4, $f6, $f12
  nop   
  mul.s $f10, $f14, $f8
  c.lt.s $f4, $f10
  nop   
  bc1f  .L7F074C5C
   nop   
  b     .L7F074C60
   move  $v0, $zero
.L7F074C40:
  mul.s $f8, $f0, $f6
  c.lt.s $f8, $f2
  nop   
  bc1fl .L7F074C60
   li    $v0, 1
  b     .L7F074C60
   move  $v0, $zero
.L7F074C5C:
  li    $v0, 1
.L7F074C60:
  jr    $ra
   addiu $sp, $sp, 0xb8
");

asm(R"
glabel sub_GAME_7F074C68
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  sw    $a2, 0x28($sp)
  sw    $a3, 0x2c($sp)
  lw    $t6, 4($a1)
  move  $a2, $zero
  jal   sub_GAME_7F06C660
   sw    $t6, 0x1c($sp)
  lw    $a0, 0x1c($sp)
  move  $a1, $v0
  lw    $a2, 0x28($sp)
  jal   sub_GAME_7F0747D0
   lw    $a3, 0x2c($sp)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F074CAC
  addiu $sp, $sp, -0xb0
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a0, 0xb0($sp)
  lw    $t0, 4($a1)
  move  $s0, $a2
  move  $a2, $zero
  sw    $a3, 0xbc($sp)
  sw    $a1, 0xb4($sp)
  jal   sub_GAME_7F06C660
   sw    $t0, 0xac($sp)
  lui   $t3, %hi(D_80036408) 
  addiu $t3, %lo(D_80036408) # addiu $t3, $t3, 0x6408
  lw    $at, ($t3)
  lw    $a3, 0xbc($sp)
  lw    $t0, 0xac($sp)
  addiu $t2, $sp, 0x90
  sw    $at, ($t2)
  lw    $at, 8($t3)
  lw    $t9, 4($t3)
  move  $v1, $v0
  sw    $at, 8($t2)
  sw    $t9, 4($t2)
  lwc1  $f8, 4($t0)
  lw    $t8, 0xb4($sp)
  swc1  $f8, 0x8c($sp)
  lwc1  $f6, ($a3)
  swc1  $f6, 0x9c($sp)
  lwc1  $f10, 4($a3)
  swc1  $f10, 0xa0($sp)
  lwc1  $f4, 8($a3)
  swc1  $f4, 0xa4($sp)
  lhu   $a0, ($t8)
  andi  $t6, $a0, 0x100
  beqz  $t6, .L7F074E28
   andi  $t7, $a0, 0x200
  lwc1  $f8, 8($t0)
  swc1  $f8, 0x80($sp)
  lwc1  $f6, 0xc($t0)
  lwc1  $f4, 0x80($sp)
  swc1  $f6, 0x84($sp)
  lwc1  $f10, 0x10($t0)
  swc1  $f10, 0x88($sp)
  lwc1  $f8, ($v0)
  lwc1  $f10, 0x84($sp)
  mul.s $f6, $f4, $f8
  lwc1  $f8, 0x10($v0)
  swc1  $f4, 0x20($sp)
  lwc1  $f4, 0x20($v0)
  mul.s $f8, $f10, $f8
  add.s $f6, $f6, $f8
  lwc1  $f8, 0x88($sp)
  mul.s $f4, $f8, $f4
  add.s $f6, $f6, $f4
  lwc1  $f4, 0x30($v0)
  swc1  $f10, 0x24($sp)
  lwc1  $f10, ($s0)
  sub.s $f4, $f4, $f10
  add.s $f10, $f4, $f6
  lwc1  $f4, 0x20($sp)
  swc1  $f10, 0x90($sp)
  lwc1  $f6, 4($v0)
  mul.s $f10, $f4, $f6
  lwc1  $f6, 0x24($sp)
  swc1  $f8, 0x24($sp)
  lwc1  $f8, 0x14($v0)
  mul.s $f8, $f6, $f8
  add.s $f10, $f10, $f8
  lwc1  $f8, 0x24($sp)
  swc1  $f4, 0x24($sp)
  lwc1  $f4, 0x24($v0)
  mul.s $f4, $f8, $f4
  add.s $f10, $f10, $f4
  lwc1  $f4, 0x34($v0)
  swc1  $f6, 0x20($sp)
  lwc1  $f6, 4($s0)
  sub.s $f4, $f4, $f6
  add.s $f6, $f4, $f10
  lwc1  $f4, 0x24($sp)
  swc1  $f6, 0x94($sp)
  lwc1  $f10, 8($v0)
  mul.s $f6, $f4, $f10
  lwc1  $f10, 0x18($v0)
  lwc1  $f4, 0x20($sp)
  mul.s $f4, $f4, $f10
  add.s $f10, $f6, $f4
  lwc1  $f6, 0x28($v0)
  mul.s $f4, $f8, $f6
  lwc1  $f6, 0x38($v0)
  add.s $f8, $f10, $f4
  lwc1  $f10, 8($s0)
  sub.s $f4, $f6, $f10
  add.s $f6, $f4, $f8
  b     .L7F074F1C
   swc1  $f6, 0x98($sp)
.L7F074E28:
  beql  $t7, $zero, .L7F074EF0
   lwc1  $f6, 0x30($v0)
  lw    $a1, 0x14($t0)
  lw    $a0, 0xb0($sp)
  move  $a2, $zero
  beql  $a1, $zero, .L7F074EBC
   lwc1  $f8, 0x30($v0)
  sw    $v1, 0xa8($sp)
  jal   sub_GAME_7F06C660
   sw    $t0, 0xac($sp)
  lw    $v1, 0xa8($sp)
  lwc1  $f4, 0x30($v0)
  li    $at, 0x3F000000 # 0.500000
  lwc1  $f10, 0x30($v1)
  mtc1  $at, $f0
  lw    $t0, 0xac($sp)
  add.s $f8, $f10, $f4
  lwc1  $f10, ($s0)
  mul.s $f6, $f8, $f0
  sub.s $f4, $f6, $f10
  swc1  $f4, 0x90($sp)
  lwc1  $f6, 0x34($v0)
  lwc1  $f8, 0x34($v1)
  add.s $f10, $f8, $f6
  lwc1  $f8, 4($s0)
  mul.s $f4, $f10, $f0
  sub.s $f6, $f4, $f8
  swc1  $f6, 0x94($sp)
  lwc1  $f4, 0x38($v0)
  lwc1  $f10, 0x38($v1)
  add.s $f8, $f10, $f4
  lwc1  $f10, 8($s0)
  mul.s $f6, $f8, $f0
  sub.s $f4, $f6, $f10
  b     .L7F074F1C
   swc1  $f4, 0x98($sp)
  lwc1  $f8, 0x30($v0)
.L7F074EBC:
  lwc1  $f6, ($s0)
  sub.s $f10, $f8, $f6
  swc1  $f10, 0x90($sp)
  lwc1  $f8, 4($s0)
  lwc1  $f4, 0x34($v0)
  sub.s $f6, $f4, $f8
  swc1  $f6, 0x94($sp)
  lwc1  $f4, 8($s0)
  lwc1  $f10, 0x38($v0)
  sub.s $f8, $f10, $f4
  b     .L7F074F1C
   swc1  $f8, 0x98($sp)
  lwc1  $f6, 0x30($v0)
.L7F074EF0:
  lwc1  $f10, ($s0)
  sub.s $f4, $f6, $f10
  swc1  $f4, 0x90($sp)
  lwc1  $f6, 4($s0)
  lwc1  $f8, 0x34($v0)
  sub.s $f10, $f8, $f6
  swc1  $f10, 0x94($sp)
  lwc1  $f8, 8($s0)
  lwc1  $f4, 0x38($v0)
  sub.s $f6, $f4, $f8
  swc1  $f6, 0x98($sp)
.L7F074F1C:
  lw    $t1, 0xb4($sp)
  lwc1  $f4, 0xa4($sp)
  lwc1  $f6, 0xa0($sp)
  lhu   $a0, ($t1)
  andi  $t5, $a0, 0x400
  beqz  $t5, .L7F075104
   andi  $v0, $a0, 0x800
  lwc1  $f10, 8($v1)
  lwc1  $f12, 0x18($t0)
  lwc1  $f16, 0x1c($t0)
  mul.s $f8, $f10, $f4
  lwc1  $f10, 4($v1)
  lwc1  $f0, ($v1)
  swc1  $f4, 0x24($sp)
  mul.s $f10, $f6, $f10
  lwc1  $f4, 0x9c($sp)
  swc1  $f8, 0x20($sp)
  mul.s $f8, $f4, $f0
  add.s $f8, $f8, $f10
  lwc1  $f10, 0x20($sp)
  add.s $f10, $f10, $f8
  mul.s $f2, $f10, $f12
  nop   
  mul.s $f8, $f0, $f2
  add.s $f10, $f8, $f4
  swc1  $f10, 0x9c($sp)
  lwc1  $f8, 4($v1)
  mul.s $f4, $f8, $f2
  add.s $f8, $f4, $f6
  swc1  $f8, 0xa0($sp)
  lwc1  $f4, 8($v1)
  mul.s $f6, $f4, $f2
  lwc1  $f4, 0x24($sp)
  add.s $f6, $f6, $f4
  swc1  $f6, 0xa4($sp)
  lwc1  $f4, 8($v1)
  lwc1  $f0, ($v1)
  swc1  $f10, 0x24($sp)
  lwc1  $f10, 0x98($sp)
  swc1  $f8, 0x20($sp)
  swc1  $f6, 0x28($sp)
  mul.s $f4, $f4, $f10
  lwc1  $f6, 4($v1)
  lwc1  $f8, 0x94($sp)
  swc1  $f10, 0x2c($sp)
  lwc1  $f10, 0x90($sp)
  mul.s $f6, $f8, $f6
  swc1  $f4, 0x30($sp)
  mul.s $f4, $f10, $f0
  add.s $f4, $f4, $f6
  lwc1  $f6, 0x30($sp)
  add.s $f6, $f6, $f4
  mul.s $f14, $f6, $f12
  nop   
  mul.s $f4, $f0, $f14
  add.s $f6, $f4, $f10
  swc1  $f6, 0x90($sp)
  lwc1  $f4, 4($v1)
  mul.s $f10, $f4, $f14
  add.s $f4, $f10, $f8
  swc1  $f4, 0x94($sp)
  lwc1  $f10, 8($v1)
  mul.s $f8, $f10, $f14
  lwc1  $f10, 0x2c($sp)
  add.s $f8, $f8, $f10
  lwc1  $f10, 0x24($sp)
  swc1  $f8, 0x98($sp)
  lwc1  $f0, 0x10($v1)
  swc1  $f6, 0x30($sp)
  swc1  $f4, 0x2c($sp)
  swc1  $f8, 0x24($sp)
  mul.s $f6, $f10, $f0
  lwc1  $f8, 0x14($v1)
  lwc1  $f4, 0x20($sp)
  mul.s $f8, $f4, $f8
  add.s $f6, $f6, $f8
  lwc1  $f8, 0x28($sp)
  swc1  $f10, 0x28($sp)
  lwc1  $f10, 0x18($v1)
  mul.s $f10, $f10, $f8
  add.s $f10, $f10, $f6
  lwc1  $f6, 0x28($sp)
  mul.s $f2, $f10, $f16
  nop   
  mul.s $f10, $f0, $f2
  add.s $f10, $f10, $f6
  swc1  $f10, 0x9c($sp)
  lwc1  $f6, 0x14($v1)
  mul.s $f10, $f6, $f2
  add.s $f6, $f10, $f4
  swc1  $f6, 0xa0($sp)
  lwc1  $f10, 0x18($v1)
  mul.s $f4, $f10, $f2
  lwc1  $f10, 0x30($sp)
  add.s $f6, $f4, $f8
  lwc1  $f8, 0x2c($sp)
  swc1  $f6, 0xa4($sp)
  lwc1  $f0, 0x10($v1)
  lwc1  $f6, 0x14($v1)
  swc1  $f10, 0x30($sp)
  mul.s $f4, $f10, $f0
  lwc1  $f10, 0x18($v1)
  mul.s $f6, $f8, $f6
  add.s $f4, $f4, $f6
  lwc1  $f6, 0x24($sp)
  mul.s $f10, $f10, $f6
  add.s $f10, $f10, $f4
  lwc1  $f4, 0x30($sp)
  mul.s $f12, $f10, $f16
  nop   
  mul.s $f10, $f0, $f12
  add.s $f10, $f10, $f4
  swc1  $f10, 0x90($sp)
  lwc1  $f4, 0x14($v1)
  mul.s $f10, $f4, $f12
  add.s $f4, $f10, $f8
  swc1  $f4, 0x94($sp)
  lwc1  $f10, 0x18($v1)
  mul.s $f8, $f10, $f12
  add.s $f4, $f8, $f6
  b     .L7F07523C
   swc1  $f4, 0x98($sp)
.L7F075104:
  bnez  $v0, .L7F07511C
   andi  $t4, $a0, 0x1000
  bnez  $t4, .L7F07511C
   andi  $t2, $a0, 0x2000
  beql  $t2, $zero, .L7F075240
   lwc1  $f18, 0x9c($sp)
.L7F07511C:
  lwc1  $f10, 0x18($t0)
  andi  $t3, $a0, 0x1000
  beqz  $v0, .L7F075148
   swc1  $f10, 0x60($sp)
  lwc1  $f8, ($v1)
  swc1  $f8, 0x54($sp)
  lwc1  $f6, 4($v1)
  swc1  $f6, 0x58($sp)
  lwc1  $f4, 8($v1)
  b     .L7F07518C
   swc1  $f4, 0x5c($sp)
.L7F075148:
  beqz  $t3, .L7F07516C
   andi  $t9, $a0, 0x2000
  lwc1  $f10, 0x10($v1)
  swc1  $f10, 0x54($sp)
  lwc1  $f8, 0x14($v1)
  swc1  $f8, 0x58($sp)
  lwc1  $f6, 0x18($v1)
  b     .L7F07518C
   swc1  $f6, 0x5c($sp)
.L7F07516C:
  beql  $t9, $zero, .L7F075190
   lwc1  $f12, 0x54($sp)
  lwc1  $f4, 0x20($v1)
  swc1  $f4, 0x54($sp)
  lwc1  $f10, 0x24($v1)
  swc1  $f10, 0x58($sp)
  lwc1  $f8, 0x28($v1)
  swc1  $f8, 0x5c($sp)
.L7F07518C:
  lwc1  $f12, 0x54($sp)
.L7F075190:
  lwc1  $f18, 0x9c($sp)
  lwc1  $f14, 0x58($sp)
  lwc1  $f4, 0xa0($sp)
  mul.s $f6, $f18, $f12
  lwc1  $f16, 0x5c($sp)
  mul.s $f10, $f4, $f14
  add.s $f8, $f6, $f10
  lwc1  $f6, 0xa4($sp)
  mul.s $f10, $f16, $f6
  add.s $f10, $f10, $f8
  lwc1  $f8, 0x60($sp)
  mul.s $f0, $f10, $f8
  swc1  $f8, 0x30($sp)
  mul.s $f10, $f12, $f0
  add.s $f18, $f10, $f18
  mul.s $f10, $f14, $f0
  swc1  $f18, 0x9c($sp)
  add.s $f10, $f10, $f4
  mul.s $f4, $f16, $f0
  swc1  $f10, 0xa0($sp)
  add.s $f10, $f4, $f6
  lwc1  $f4, 0x90($sp)
  swc1  $f10, 0xa4($sp)
  mul.s $f6, $f4, $f12
  lwc1  $f10, 0x94($sp)
  swc1  $f4, 0x2c($sp)
  mul.s $f8, $f10, $f14
  add.s $f6, $f6, $f8
  lwc1  $f8, 0x98($sp)
  mul.s $f4, $f16, $f8
  add.s $f4, $f4, $f6
  lwc1  $f6, 0x30($sp)
  mul.s $f2, $f4, $f6
  lwc1  $f6, 0x2c($sp)
  mul.s $f4, $f12, $f2
  add.s $f4, $f4, $f6
  mul.s $f6, $f14, $f2
  swc1  $f4, 0x90($sp)
  add.s $f4, $f6, $f10
  mul.s $f6, $f16, $f2
  swc1  $f4, 0x94($sp)
  add.s $f10, $f6, $f8
  swc1  $f10, 0x98($sp)
.L7F07523C:
  lwc1  $f18, 0x9c($sp)
.L7F075240:
  lwc1  $f4, 0x90($sp)
  lwc1  $f14, 0xa0($sp)
  lwc1  $f8, 0x94($sp)
  mul.s $f6, $f18, $f4
  lwc1  $f16, 0xa4($sp)
  swc1  $f4, 0x30($sp)
  mul.s $f10, $f14, $f8
  lw    $ra, 0x1c($sp)
  move  $v0, $zero
  add.s $f6, $f6, $f10
  lwc1  $f10, 0x98($sp)
  mul.s $f4, $f10, $f16
  add.s $f2, $f4, $f6
  mtc1  $zero, $f4
  nop   
  c.lt.s $f4, $f2
  nop   
  bc1f  .L7F0752F0
   nop   
  mul.s $f6, $f18, $f18
  nop   
  mul.s $f4, $f14, $f14
  add.s $f6, $f6, $f4
  mul.s $f4, $f16, $f16
  add.s $f0, $f4, $f6
  lwc1  $f4, 0x30($sp)
  mul.s $f6, $f4, $f4
  nop   
  mul.s $f4, $f8, $f8
  add.s $f8, $f6, $f4
  mul.s $f6, $f10, $f10
  lwc1  $f10, 0x8c($sp)
  mul.s $f4, $f2, $f2
  add.s $f12, $f6, $f8
  sub.s $f6, $f12, $f10
  mul.s $f8, $f6, $f0
  c.le.s $f8, $f4
  nop   
  bc1f  .L7F0752E8
   nop   
  b     .L7F0752F0
   li    $v0, 1
.L7F0752E8:
  b     .L7F0752F0
   move  $v0, $zero
.L7F0752F0:
  lw    $s0, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0xb0
");

asm(R"
.late_rodata
/*D:80054DB4*/
glabel jpt_80054DB4
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F07543C
.word .L7F075470
.word .L7F0753CC
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075404
.word .L7F075450
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075470
.word .L7F075464
.word .L7F075470

.text
glabel sub_GAME_7F0752FC
  addiu $sp, $sp, -0x30
  sw    $ra, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a3, 0x3c($sp)
  lw    $v0, ($a3)
  move  $s2, $a0
  move  $s3, $a1
  move  $s4, $a2
  beqz  $v0, .L7F075340
   li    $s1, 1
  move  $s0, $v0
  b     .L7F075348
   sw    $zero, ($a3)
.L7F075340:
  lw    $t7, 8($s2)
  lw    $s0, ($t7)
.L7F075348:
  beql  $s0, $zero, .L7F07547C
   move  $v0, $zero
.L7F075350:
  beqz  $s1, .L7F07536C
   nop   
  lw    $v0, 0x14($s0)
  beqz  $v0, .L7F07536C
   nop   
  b     .L7F07539C
   move  $s0, $v0
.L7F07536C:
  beqz  $s0, .L7F075394
   nop   
  lw    $v0, 0xc($s0)
.L7F075378:
  beql  $v0, $zero, .L7F07538C
   lw    $s0, 8($s0)
  b     .L7F075394
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F07538C:
  bnezl $s0, .L7F075378
   lw    $v0, 0xc($s0)
.L7F075394:
  beql  $s0, $zero, .L7F07547C
   move  $v0, $zero
.L7F07539C:
  lhu   $v0, ($s0)
  li    $s1, 1
  andi  $t8, $v0, 0xff
  addiu $t9, $t8, -1
  sltiu $at, $t9, 0x18
  beqz  $at, .L7F075470
   sll   $t9, $t9, 2
  lui   $at, %hi(jpt_80054DB4)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_80054DB4)($at)
.L7F0753C4:
  jr    $t9
   nop   
.L7F0753CC:
  move  $a0, $s2
  move  $a1, $s0
  move  $a2, $s3
  jal   sub_GAME_7F074C68
   move  $a3, $s4
  beqz  $v0, .L7F0753FC
   nop   
  lw    $t0, 0x3c($sp)
  sw    $s0, ($t0)
  lw    $t1, 4($s0)
  b     .L7F07547C
   lw    $v0, ($t1)
.L7F0753FC:
  b     .L7F075470
   move  $s1, $zero
.L7F075404:
  move  $a0, $s2
  move  $a1, $s0
  move  $a2, $s3
  jal   sub_GAME_7F074CAC
   move  $a3, $s4
  beqz  $v0, .L7F075434
   nop   
  lw    $t2, 0x3c($sp)
  sw    $s0, ($t2)
  lw    $t3, 4($s0)
  b     .L7F07547C
   lw    $v0, ($t3)
.L7F075434:
  b     .L7F075470
   move  $s1, $zero
.L7F07543C:
  move  $a0, $s2
  jal   sub_GAME_7F06E970
   move  $a1, $s0
  b     .L7F075470
   nop   
.L7F075450:
  move  $a0, $s2
  jal   process_12_handle_switch
   move  $a1, $s0
  b     .L7F075470
   nop   
.L7F075464:
  move  $a0, $s2
  jal   process_17_pointer_to_head
   move  $a1, $s0
def_7F0753C4:
.L7F075470:
  bnez  $s0, .L7F075350
   nop   
  move  $v0, $zero
.L7F07547C:
  lw    $ra, 0x2c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F07549C
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F0752FC
   sw    $zero, ($a3)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0754BC
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  sw    $a1, 0x34($sp)
  sw    $a2, 0x38($sp)
  lhu   $v1, 0xe($a0)
  lw    $a2, ($a0)
  move  $a3, $zero
  sra   $t6, $v1, 3
  sll   $t7, $a2, 0
  bgez  $t7, .L7F0754FC
   move  $v1, $t6
  multu $a1, $t6
  mflo  $t9
  addu  $a3, $a2, $t9
  b     .L7F0755A0
   lw    $ra, 0x14($sp)
.L7F0754FC:
  lui   $t0, %hi(D_80036414) 
  addiu $t0, %lo(D_80036414) # addiu $t0, $t0, 0x6414
  lw    $v0, ($t0)
  lw    $t3, 0x34($sp)
  beql  $v0, $zero, .L7F0755A0
   lw    $ra, 0x14($sp)
  multu $t3, $v1
  lw    $a0, 8($v0)
  addiu $a0, $a0, 0xf
  srl   $t1, $a0, 4
  sll   $t2, $t1, 4
  move  $a0, $t2
  move  $a3, $t2
  mflo  $t4
  addu  $a1, $a2, $t4
  andi  $t5, $a1, 1
  beql  $t5, $zero, .L7F075554
   addiu $a2, $v1, 0xf
  addiu $a1, $a1, -1
  addiu $v1, $v1, 1
  addiu $a3, $t2, 1
  addiu $a2, $v1, 0xf
.L7F075554:
  srl   $t6, $a2, 4
  sll   $a2, $t6, 4
  sw    $a2, 0x18($sp)
  sw    $a0, 0x20($sp)
  jal   romCopy
   sw    $a3, 0x2c($sp)
  lui   $t0, %hi(D_80036414) 
  addiu $t0, %lo(D_80036414) # addiu $t0, $t0, 0x6414
  lw    $v0, ($t0)
  lw    $a0, 0x20($sp)
  lw    $a2, 0x18($sp)
  lw    $t8, ($v0)
  lw    $a3, 0x2c($sp)
  addu  $t1, $a0, $a2
  addiu $t9, $t8, 1
  sw    $t9, ($v0)
  lw    $t2, ($t0)
  sw    $t1, 8($t2)
  lw    $ra, 0x14($sp)
.L7F0755A0:
  addiu $sp, $sp, 0x30
  move  $v0, $a3
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0755B0
  lui   $v1, %hi(D_80036414)
  addiu $v1, %lo(D_80036414) # addiu $v1, $v1, 0x6414
  lw    $v0, ($v1)
  beqz  $v0, .L7F0755D4
   nop   
  lw    $t6, 4($v0)
  sw    $t6, 8($v0)
  lw    $t7, ($v1)
  sw    $zero, ($t7)
.L7F0755D4:
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80054E14*/
glabel jpt_80054E14
.word .L7F075678
.word .L7F075698
.word .L7F0756B8
.word .L7F0756D8
.word .L7F0757AC
.word .L7F0758F4
.word .L7F07583C
.word .L7F075904
.word .L7F07594C
.word .L7F075A44
.word .L7F0759A0
.word .L7F0759C4
.word .L7F0759E8
.word .L7F075A44
.word .L7F075A44
.word .L7F075A44
.word .L7F075980
.word .L7F07592C
.word .L7F075A44
.word .L7F07578C
.word .L7F075A44
.word .L7F075A20
.word .L7F075A44
.word .L7F0756FC

.text
glabel convert_obj_microcode_offset_to_rdram_addr
  beqz  $a0, .L7F075A88
   nop   
  lhu   $v0, ($a0)
.L7F0755E8:
  lw    $v1, 4($a0)
  subu  $t7, $a2, $a1
  andi  $t6, $v0, 0xff
  beqz  $v1, .L7F075604
   move  $v0, $t6
  addu  $t8, $v1, $t7
  sw    $t8, 4($a0)
.L7F075604:
  lw    $v1, 8($a0)
  subu  $t9, $a2, $a1
  subu  $t4, $a2, $a1
  beqz  $v1, .L7F07561C
   addu  $t3, $v1, $t9
  sw    $t3, 8($a0)
.L7F07561C:
  lw    $v1, 0xc($a0)
  addiu $t3, $v0, -1
  sltiu $at, $t3, 0x18
  beqz  $v1, .L7F075634
   addu  $t5, $v1, $t4
  sw    $t5, 0xc($a0)
.L7F075634:
  lw    $v1, 0x10($a0)
  subu  $t6, $a2, $a1
  subu  $t8, $a2, $a1
  beqz  $v1, .L7F07564C
   addu  $t7, $v1, $t6
  sw    $t7, 0x10($a0)
.L7F07564C:
  lw    $v1, 0x14($a0)
  sll   $t3, $t3, 2
  beqz  $v1, .L7F075660
   addu  $t9, $v1, $t8
  sw    $t9, 0x14($a0)
.L7F075660:
  beqz  $at, .L7F075A44
   lui   $at, %hi(jpt_80054E14)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_80054E14)($at)
.L7F075670:
  jr    $t3
   nop   
.L7F075678:
  lw    $v0, 4($a0)
  subu  $t4, $a2, $a1
  lw    $v1, 4($v0)
  beqz  $v1, .L7F075690
   addu  $t5, $v1, $t4
  sw    $t5, 4($v0)
.L7F075690:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F075698:
  lw    $v0, 4($a0)
  subu  $t6, $a2, $a1
  lw    $v1, 0x14($v0)
  beqz  $v1, .L7F0756B0
   addu  $t7, $v1, $t6
  sw    $t7, 0x14($v0)
.L7F0756B0:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0756B8:
  lw    $v0, 4($a0)
  subu  $t8, $a2, $a1
  lw    $v1, 0x14($v0)
  beqz  $v1, .L7F0756D0
   addu  $t9, $v1, $t8
  sw    $t9, 0x14($v0)
.L7F0756D0:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0756D8:
  lw    $v0, 4($a0)
  subu  $t3, $a2, $a1
  lw    $v1, 0xc($v0)
  beqz  $v1, .L7F0756F0
   addu  $t4, $v1, $t3
  sw    $t4, 0xc($v0)
.L7F0756F0:
  sw    $a2, 8($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0756FC:
  lw    $a3, 4($a0)
  subu  $t5, $a2, $a1
  move  $v0, $zero
  lw    $v1, 8($a3)
  subu  $t7, $a2, $a1
  subu  $t9, $a2, $a1
  beqz  $v1, .L7F075720
   addu  $t6, $v1, $t5
  sw    $t6, 8($a3)
.L7F075720:
  lw    $v1, 0x10($a3)
  move  $t0, $zero
  beqz  $v1, .L7F075734
   addu  $t8, $v1, $t7
  sw    $t8, 0x10($a3)
.L7F075734:
  lw    $v1, 0x14($a3)
  beqz  $v1, .L7F075744
   addu  $t3, $v1, $t9
  sw    $t3, 0x14($a3)
.L7F075744:
  lh    $v1, 0xe($a3)
  blezl $v1, .L7F075784
   sw    $a2, 0x1c($a3)
.L7F075750:
  lw    $t4, 0x10($a3)
  subu  $t5, $a2, $a1
  addiu $v0, $v0, 1
  addu  $t1, $t4, $t0
  lw    $t2, 8($t1)
  beqz  $t2, .L7F075774
   addu  $t6, $t2, $t5
  sw    $t6, 8($t1)
  lh    $v1, 0xe($a3)
.L7F075774:
  slt   $at, $v0, $v1
  bnez  $at, .L7F075750
   addiu $t0, $t0, 0x10
  sw    $a2, 0x1c($a3)
.L7F075784:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F07578C:
  lw    $v0, 4($a0)
  subu  $t7, $a2, $a1
  lw    $v1, 4($v0)
  beqz  $v1, .L7F0757A4
   addu  $t8, $v1, $t7
  sw    $t8, 4($v0)
.L7F0757A4:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0757AC:
  lw    $a3, 4($a0)
  subu  $t9, $a2, $a1
  move  $v0, $zero
  lw    $v1, 4($a3)
  subu  $t4, $a2, $a1
  subu  $t6, $a2, $a1
  beqz  $v1, .L7F0757D0
   addu  $t3, $v1, $t9
  sw    $t3, 4($a3)
.L7F0757D0:
  lw    $v1, 8($a3)
  move  $t0, $zero
  beqz  $v1, .L7F0757E4
   addu  $t5, $v1, $t4
  sw    $t5, 8($a3)
.L7F0757E4:
  lw    $v1, 0xc($a3)
  beqz  $v1, .L7F0757F4
   addu  $t7, $v1, $t6
  sw    $t7, 0xc($a3)
.L7F0757F4:
  lw    $v1, ($a3)
  blezl $v1, .L7F075834
   sw    $a2, 0x1a4($a3)
.L7F075800:
  lw    $t8, 4($a3)
  subu  $t9, $a2, $a1
  addiu $v0, $v0, 1
  addu  $t1, $t8, $t0
  lw    $t2, 4($t1)
  beqz  $t2, .L7F075824
   addu  $t3, $t2, $t9
  sw    $t3, 4($t1)
  lw    $v1, ($a3)
.L7F075824:
  slt   $at, $v0, $v1
  bnez  $at, .L7F075800
   addiu $t0, $t0, 8
  sw    $a2, 0x1a4($a3)
.L7F075834:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F07583C:
  lw    $a3, 4($a0)
  subu  $t4, $a2, $a1
  move  $v0, $zero
  lw    $v1, ($a3)
  subu  $t6, $a2, $a1
  subu  $t8, $a2, $a1
  beqz  $v1, .L7F075860
   addu  $t5, $v1, $t4
  sw    $t5, ($a3)
.L7F075860:
  lw    $v1, 4($a3)
  subu  $t3, $a2, $a1
  subu  $t5, $a2, $a1
  beqz  $v1, .L7F075878
   addu  $t7, $v1, $t6
  sw    $t7, 4($a3)
.L7F075878:
  lw    $v1, 0xc($a3)
  move  $t0, $zero
  beqz  $v1, .L7F07588C
   addu  $t9, $v1, $t8
  sw    $t9, 0xc($a3)
.L7F07588C:
  lw    $v1, 0x10($a3)
  beqz  $v1, .L7F07589C
   addu  $t4, $v1, $t3
  sw    $t4, 0x10($a3)
.L7F07589C:
  lw    $v1, 0x14($a3)
  beqz  $v1, .L7F0758AC
   addu  $t6, $v1, $t5
  sw    $t6, 0x14($a3)
.L7F0758AC:
  lw    $v1, 8($a3)
  blezl $v1, .L7F0758EC
   sw    $a2, 0x1ac($a3)
.L7F0758B8:
  lw    $t7, 0xc($a3)
  subu  $t8, $a2, $a1
  addiu $v0, $v0, 1
  addu  $t1, $t7, $t0
  lw    $t2, 4($t1)
  beqz  $t2, .L7F0758DC
   addu  $t9, $t2, $t8
  sw    $t9, 4($t1)
  lw    $v1, 8($a3)
.L7F0758DC:
  slt   $at, $v0, $v1
  bnez  $at, .L7F0758B8
   addiu $t0, $t0, 8
  sw    $a2, 0x1ac($a3)
.L7F0758EC:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0758F4:
  lw    $v0, 4($a0)
  sw    $a2, 0x14($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F075904:
  lw    $v0, 4($a0)
  subu  $t3, $a2, $a1
  lw    $a3, 8($v0)
  beqz  $a3, .L7F075920
   addu  $t4, $a3, $t3
  sw    $t4, 8($v0)
  move  $a3, $t4
.L7F075920:
  sw    $a3, 0x14($a0)
  b     .L7F075A48
   move  $v1, $a3
.L7F07592C:
  lw    $v0, 4($a0)
  subu  $t5, $a2, $a1
  lw    $v1, ($v0)
  beqz  $v1, .L7F075944
   addu  $t6, $v1, $t5
  sw    $t6, ($v0)
.L7F075944:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F07594C:
  lw    $v0, 4($a0)
  subu  $t7, $a2, $a1
  subu  $t9, $a2, $a1
  lw    $v1, 0x18($v0)
  beqz  $v1, .L7F075968
   addu  $t8, $v1, $t7
  sw    $t8, 0x18($v0)
.L7F075968:
  lw    $v1, 0x1c($v0)
  beqz  $v1, .L7F075978
   addu  $t3, $v1, $t9
  sw    $t3, 0x1c($v0)
.L7F075978:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F075980:
  lw    $v0, 4($a0)
  subu  $t4, $a2, $a1
  lw    $v1, 0x14($v0)
  beqz  $v1, .L7F075998
   addu  $t5, $v1, $t4
  sw    $t5, 0x14($v0)
.L7F075998:
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0759A0:
  lw    $v0, 4($a0)
  subu  $t6, $a2, $a1
  lw    $v1, 0x3c($v0)
  beqz  $v1, .L7F0759B8
   addu  $t7, $v1, $t6
  sw    $t7, 0x3c($v0)
.L7F0759B8:
  sw    $a2, 0x48($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0759C4:
  lw    $v0, 4($a0)
  subu  $t8, $a2, $a1
  lw    $v1, 0x18($v0)
  beqz  $v1, .L7F0759DC
   addu  $t9, $v1, $t8
  sw    $t9, 0x18($v0)
.L7F0759DC:
  sw    $a2, 0x24($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F0759E8:
  lw    $v0, 4($a0)
  subu  $t3, $a2, $a1
  subu  $t5, $a2, $a1
  lw    $v1, 0x10($v0)
  beqz  $v1, .L7F075A04
   addu  $t4, $v1, $t3
  sw    $t4, 0x10($v0)
.L7F075A04:
  lw    $v1, 0x14($v0)
  beqz  $v1, .L7F075A14
   addu  $t6, $v1, $t5
  sw    $t6, 0x14($v0)
.L7F075A14:
  sw    $a2, 0x1c($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
.L7F075A20:
  lw    $v0, 4($a0)
  subu  $t7, $a2, $a1
  lw    $v1, 4($v0)
  beqz  $v1, .L7F075A38
   addu  $t8, $v1, $t7
  sw    $t8, 4($v0)
.L7F075A38:
  sw    $a2, 0xc($v0)
  b     .L7F075A48
   lw    $v1, 0x14($a0)
def_7F075670:
.L7F075A44:
  lw    $v1, 0x14($a0)
.L7F075A48:
  beqz  $v1, .L7F075A58
   nop   
  b     .L7F075A80
   move  $a0, $v1
.L7F075A58:
  beqz  $a0, .L7F075A80
   nop   
  lw    $v1, 0xc($a0)
.L7F075A64:
  beql  $v1, $zero, .L7F075A78
   lw    $a0, 8($a0)
  b     .L7F075A80
   move  $a0, $v1
  lw    $a0, 8($a0)
.L7F075A78:
  bnezl $a0, .L7F075A64
   lw    $v1, 0xc($a0)
.L7F075A80:
  bnezl $a0, .L7F0755E8
   lhu   $v0, ($a0)
.L7F075A88:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F075A90
  addiu $sp, $sp, -0x20
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lh    $a3, 0xc($a0)
  move  $s0, $a0
  move  $s1, $a1
  blez  $a3, .L7F075AE8
   move  $v0, $zero
  move  $v1, $zero
.L7F075AB8:
  lw    $t6, 8($s0)
  subu  $t7, $a2, $s1
  addiu $v0, $v0, 1
  addu  $a0, $t6, $v1
  lw    $a1, ($a0)
  beqz  $a1, .L7F075ADC
   addu  $t8, $a1, $t7
  sw    $t8, ($a0)
  lh    $a3, 0xc($s0)
.L7F075ADC:
  slt   $at, $v0, $a3
  bnez  $at, .L7F075AB8
   addiu $v1, $v1, 4
.L7F075AE8:
  lw    $a0, ($s0)
  jal   convert_obj_microcode_offset_to_rdram_addr
   move  $a1, $s1
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel sub_GAME_7F075B08
  sw    $a0, ($sp)
  sw    $a1, 4($sp)
  sw    $a2, 8($sp)
  jr    $ra
   sw    $a3, 0xc($sp)
");

asm(R"
.late_rodata
/*D:80054E74*/
glabel jpt_80054E74
.word .L7F075B68
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075B84
.word .L7F075BA0
.word .L7F075C00
.word .L7F075C84
.word .L7F075C30
.word .L7F075C4C
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075BC0
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075C84
.word .L7F075BE0
.word .L7F075C68

.text
glabel set_microcode_entry_numbers
  addiu $sp, $sp, -0x20
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $ra, 0x1c($sp)
  move  $a2, $a0
  move  $s1, $zero
  beqz  $a0, .L7F075CDC
   move  $s0, $a0
  lhu   $v0, ($s0)
.L7F075B40:
  andi  $t6, $v0, 0xff
  addiu $t7, $t6, -1
  sltiu $at, $t7, 0x18
  beqz  $at, .L7F075C84
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80054E74)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80054E74)($at)
.L7F075B60:
  jr    $t7
   nop   
.L7F075B68:
  lw    $v0, 4($s0)
  sh    $s1, 0xc($v0)
  addiu $s1, $s1, 0x18
  andi  $t8, $s1, 0xffff
  move  $s1, $t8
  b     .L7F075C88
   lw    $v1, 0x14($s0)
.L7F075B84:
  lw    $v0, 4($s0)
  sh    $s1, 0x1aa($v0)
  addiu $s1, $s1, 1
  andi  $t9, $s1, 0xffff
  move  $s1, $t9
  b     .L7F075C88
   lw    $v1, 0x14($s0)
.L7F075BA0:
  lw    $v0, 4($s0)
  sh    $s1, 0xc($v0)
  lw    $v1, 8($v0)
  addiu $s1, $s1, 1
  andi  $t0, $s1, 0xffff
  move  $s1, $t0
  b     .L7F075C88
   sw    $v1, 0x14($s0)
.L7F075BC0:
  lw    $v0, 4($s0)
  sh    $s1, 4($v0)
  lw    $v1, ($v0)
  addiu $s1, $s1, 1
  andi  $t2, $s1, 0xffff
  move  $s1, $t2
  b     .L7F075C88
   sw    $v1, 0x14($s0)
.L7F075BE0:
  lw    $v0, 4($s0)
  move  $v1, $zero
  sh    $s1, ($v0)
  addiu $s1, $s1, 2
  andi  $t4, $s1, 0xffff
  move  $s1, $t4
  b     .L7F075C88
   sw    $zero, 0x14($s0)
.L7F075C00:
  lw    $v0, 4($s0)
  move  $a0, $s0
  move  $a1, $zero
  sh    $s1, 0x22($v0)
  addiu $s1, $s1, 1
  andi  $t5, $s1, 0xffff
  move  $s1, $t5
  jal   sub_GAME_7F06EA54
   sw    $a2, 0x20($sp)
  lw    $a2, 0x20($sp)
  b     .L7F075C88
   lw    $v1, 0x14($s0)
.L7F075C30:
  lw    $v0, 4($s0)
  sh    $s1, 0x44($v0)
  addiu $s1, $s1, 1
  andi  $t6, $s1, 0xffff
  move  $s1, $t6
  b     .L7F075C88
   lw    $v1, 0x14($s0)
.L7F075C4C:
  lw    $v0, 4($s0)
  sh    $s1, 0x20($v0)
  addiu $s1, $s1, 1
  andi  $t7, $s1, 0xffff
  move  $s1, $t7
  b     .L7F075C88
   lw    $v1, 0x14($s0)
.L7F075C68:
  lw    $v0, 4($s0)
  sh    $s1, 0x1a($v0)
  addiu $s1, $s1, 2
  andi  $t8, $s1, 0xffff
  move  $s1, $t8
  b     .L7F075C88
   lw    $v1, 0x14($s0)
def_7F075B60:
.L7F075C84:
  lw    $v1, 0x14($s0)
.L7F075C88:
  beqz  $v1, .L7F075C98
   nop   
  b     .L7F075CD4
   move  $s0, $v1
.L7F075C98:
  beqz  $s0, .L7F075CD4
   nop   
  lw    $v1, 8($a2)
.L7F075CA4:
  bnel  $s0, $v1, .L7F075CB8
   lw    $v0, 0xc($s0)
  b     .L7F075CD4
   move  $s0, $zero
  lw    $v0, 0xc($s0)
.L7F075CB8:
  beql  $v0, $zero, .L7F075CCC
   lw    $s0, 8($s0)
  b     .L7F075CD4
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F075CCC:
  bnez  $s0, .L7F075CA4
   nop   
.L7F075CD4:
  bnezl $s0, .L7F075B40
   lhu   $v0, ($s0)
.L7F075CDC:
  lw    $ra, 0x1c($sp)
  move  $v0, $s1
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x20
");

asm(R"
glabel set_objuse_flag_compute_grp_nums_set_obj_loaded
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $t6, 1
  move  $a1, $a0
  sw    $t6, 0x1c($a0)
  lw    $a0, ($a0)
  jal   set_microcode_entry_numbers
   sw    $a1, 0x18($sp)
  lw    $a1, 0x18($sp)
  sh    $v0, 0x14($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80054ED4*/
glabel jpt_80054ED4
.word .L7F075D88
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E00
.word .L7F075E18
.word .L7F075E78
.word .L7F075EF4
.word .L7F075E9C
.word .L7F075EB4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E38
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075EF4
.word .L7F075E5C
.word .L7F075ECC

.text
glabel unknown_object_microcode_handler
  addiu $sp, $sp, -0x30
  sw    $s2, 0x28($sp)
  sw    $s0, 0x20($sp)
  move  $s2, $a0
  sw    $ra, 0x2c($sp)
  sw    $s1, 0x24($sp)
  sdc1  $f20, 0x18($sp)
  sw    $a1, 0x34($sp)
  beqz  $a1, .L7F075F4C
   move  $s0, $a1
  mtc1  $zero, $f20
  nop   
  lhu   $v0, ($s0)
.L7F075D60:
  andi  $t7, $v0, 0xff
  addiu $t8, $t7, -1
  sltiu $at, $t8, 0x18
  beqz  $at, .L7F075EF4
   sll   $t8, $t8, 2
  lui   $at, %hi(jpt_80054ED4)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_80054ED4)($at)
.L7F075D80:
  jr    $t8
   nop   
.L7F075D88:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sb    $zero, ($v0)
  swc1  $f20, 4($v0)
  swc1  $f20, 8($v0)
  swc1  $f20, 0xc($v0)
  swc1  $f20, 0x10($v0)
  swc1  $f20, 0x14($v0)
  swc1  $f20, 0x18($v0)
  swc1  $f20, 0x1c($v0)
  sb    $zero, 1($v0)
  swc1  $f20, 0x34($v0)
  swc1  $f20, 0x38($v0)
  swc1  $f20, 0x3c($v0)
  swc1  $f20, 0x30($v0)
  swc1  $f20, 0x24($v0)
  swc1  $f20, 0x28($v0)
  swc1  $f20, 0x2c($v0)
  swc1  $f20, 0x20($v0)
  sb    $zero, 2($v0)
  swc1  $f20, 0x4c($v0)
  swc1  $f20, 0x50($v0)
  swc1  $f20, 0x54($v0)
  swc1  $f20, 0x40($v0)
  swc1  $f20, 0x44($v0)
  swc1  $f20, 0x48($v0)
  swc1  $f20, 0x5c($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075E00:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sw    $zero, ($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075E18:
  lw    $s1, 4($s0)
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sw    $zero, ($v0)
  lw    $v1, 8($s1)
  b     .L7F075EF8
   sw    $v1, 0x14($s0)
.L7F075E38:
  lw    $s1, 4($s0)
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  li    $t0, 1
  sw    $t0, ($v0)
  lw    $v1, ($s1)
  b     .L7F075EF8
   sw    $v1, 0x14($s0)
.L7F075E5C:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sw    $zero, ($v0)
  sw    $zero, 4($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075E78:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sw    $zero, ($v0)
  move  $a0, $s2
  jal   sub_GAME_7F06EB10
   move  $a1, $s0
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075E9C:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sh    $zero, ($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075EB4:
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  sh    $zero, ($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
.L7F075ECC:
  lw    $s1, 4($s0)
  move  $a0, $s2
  jal   extract_id_from_object_structure_microcode
   move  $a1, $s0
  lw    $t2, 8($s1)
  sw    $t2, ($v0)
  lw    $t3, ($s1)
  sw    $t3, 4($v0)
  b     .L7F075EF8
   lw    $v1, 0x14($s0)
def_7F075D80:
.L7F075EF4:
  lw    $v1, 0x14($s0)
.L7F075EF8:
  beqz  $v1, .L7F075F08
   nop   
  b     .L7F075F44
   move  $s0, $v1
.L7F075F08:
  beqz  $s0, .L7F075F44
   lw    $t4, 0x34($sp)
  lw    $v1, 8($t4)
.L7F075F14:
  bnel  $s0, $v1, .L7F075F28
   lw    $v0, 0xc($s0)
  b     .L7F075F44
   move  $s0, $zero
  lw    $v0, 0xc($s0)
.L7F075F28:
  beql  $v0, $zero, .L7F075F3C
   lw    $s0, 8($s0)
  b     .L7F075F44
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F075F3C:
  bnez  $s0, .L7F075F14
   nop   
.L7F075F44:
  bnezl $s0, .L7F075D60
   lhu   $v0, ($s0)
.L7F075F4C:
  lw    $ra, 0x2c($sp)
  ldc1  $f20, 0x18($sp)
  lw    $s0, 0x20($sp)
  lw    $s1, 0x24($sp)
  lw    $s2, 0x28($sp)
  jr    $ra
   addiu $sp, $sp, 0x30
");

asm(R"
glabel sub_GAME_7F075F68
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f4
  li    $t6, -1
  sw    $a1, 8($a0)
  sw    $a2, 0x10($a0)
  sh    $t6, 2($a0)
  sw    $zero, 0x18($a0)
  sw    $zero, 0x1c($a0)
  swc1  $f4, 0x14($a0)
  jal   unknown_object_microcode_handler
   lw    $a1, ($a1)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F075FAC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F075F68
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  mtc1  $zero, $f0
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f2
  li    $at, 0xBF800000 # -1.000000
  mtc1  $at, $f12
  sw    $zero, 0x20($a0)
  sw    $zero, 0x54($a0)
  sb    $zero, 0x26($a0)
  sw    $zero, 0x98($a0)
  sw    $zero, 0x9c($a0)
  sw    $zero, 0xa0($a0)
  swc1  $f0, 0x2c($a0)
  swc1  $f0, 0x4c($a0)
  swc1  $f0, 0x5c($a0)
  swc1  $f0, 0x7c($a0)
  swc1  $f0, 0x84($a0)
  swc1  $f0, 0x88($a0)
  swc1  $f0, 0xb0($a0)
  swc1  $f2, 0x40($a0)
  swc1  $f2, 0x70($a0)
  swc1  $f2, 0xa4($a0)
  swc1  $f2, 0xb8($a0)
  swc1  $f12, 0x3c($a0)
  swc1  $f12, 0x6c($a0)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F076030
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  sw    $a0, 0x18($sp)
  sw    $a3, 0x24($sp)
  move  $a1, $a2
  jal   extract_id_from_object_structure_microcode
   sw    $a2, 0x20($sp)
  lw    $a1, 0x24($sp)
  lw    $a2, 0x20($sp)
  lw    $a3, 0x1c($sp)
  sw    $a1, ($v0)
  lw    $t6, 0x18($sp)
  lh    $t8, 0x14($a3)
  lw    $t7, 0x10($t6)
  sll   $t9, $t8, 2
  addu  $t0, $t7, $t9
  sw    $t0, 4($v0)
  lw    $v1, ($a1)
  sw    $v1, 0x14($a2)
  beqz  $v1, .L7F07609C
   move  $a0, $v1
  sw    $a2, 8($v1)
.L7F07608C:
  lw    $v1, 0xc($v1)
  bnezl $v1, .L7F07608C
   sw    $a2, 8($v1)
  lw    $a0, 0x14($a2)
.L7F07609C:
  jal   set_microcode_entry_numbers
   nop   
  lw    $a3, 0x1c($sp)
  lh    $t2, 0x14($a3)
  addu  $t3, $t2, $v0
  sh    $t3, 0x14($a3)
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
.late_rodata
/*D:80054F34*/
glabel jpt_80054F34
.word .L7F076128
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761A0
.word .L7F0761C0
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761B0
.word .L7F0761CC
.word .L7F0761CC
.word .L7F0761CC
.word .L7F076188
.word .L7F0761CC
.word .L7F076158

.text
glabel sub_GAME_7F0760C4
  addiu $sp, $sp, -0x28
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  lw    $s0, ($a1)
  move  $s2, $a1
  move  $s3, $a2
  bnez  $s0, .L7F0760F4
   move  $s1, $zero
  lw    $s0, ($a0)
.L7F0760F4:
  beql  $s0, $zero, .L7F07621C
   sw    $s1, ($s3)
  lhu   $v0, ($s0)
.L7F076100:
  andi  $t6, $v0, 0xff
  addiu $t7, $t6, -4
  sltiu $at, $t7, 0x15
  beqz  $at, .L7F0761CC
   sll   $t7, $t7, 2
  lui   $at, %hi(jpt_80054F34)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_80054F34)($at)
.L7F076120:
  jr    $t7
   nop   
.L7F076128:
  lw    $t8, ($s2)
  lw    $v0, 4($s0)
  beql  $s0, $t8, .L7F076144
   lw    $v1, 4($v0)
  b     .L7F0761CC
   lw    $s1, ($v0)
  lw    $v1, 4($v0)
.L7F076144:
  lw    $t9, ($s3)
  beq   $v1, $t9, .L7F0761CC
   nop   
  b     .L7F0761CC
   move  $s1, $v1
.L7F076158:
  lw    $t0, ($s2)
  lw    $v0, 4($s0)
  beql  $s0, $t0, .L7F076174
   lw    $v1, 4($v0)
  b     .L7F0761CC
   lw    $s1, ($v0)
  lw    $v1, 4($v0)
.L7F076174:
  lw    $t1, ($s3)
  beq   $v1, $t1, .L7F0761CC
   nop   
  b     .L7F0761CC
   move  $s1, $v1
.L7F076188:
  lw    $t2, ($s2)
  lw    $v0, 4($s0)
  beq   $s0, $t2, .L7F0761CC
   nop   
  b     .L7F0761CC
   lw    $s1, 8($v0)
.L7F0761A0:
  lw    $v0, 4($s0)
  lw    $t3, 8($v0)
  b     .L7F0761CC
   sw    $t3, 0x14($s0)
.L7F0761B0:
  lw    $v0, 4($s0)
  lw    $t4, ($v0)
  b     .L7F0761CC
   sw    $t4, 0x14($s0)
.L7F0761C0:
  move  $a0, $s0
  jal   sub_GAME_7F06EA54
   li    $a1, 1
def_7F076120:
.L7F0761CC:
  bnezl $s1, .L7F07621C
   sw    $s1, ($s3)
  lw    $v0, 0x14($s0)
  beqz  $v0, .L7F0761E8
   nop   
  b     .L7F076210
   move  $s0, $v0
.L7F0761E8:
  beqz  $s0, .L7F076210
   nop   
  lw    $v0, 0xc($s0)
.L7F0761F4:
  beql  $v0, $zero, .L7F076208
   lw    $s0, 8($s0)
  b     .L7F076210
   move  $s0, $v0
  lw    $s0, 8($s0)
.L7F076208:
  bnezl $s0, .L7F0761F4
   lw    $v0, 0xc($s0)
.L7F076210:
  bnezl $s0, .L7F076100
   lhu   $v0, ($s0)
  sw    $s1, ($s3)
.L7F07621C:
  sw    $s0, ($s2)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F07623C
  sw    $a0, ($sp)
  lhu   $v0, ($a1)
  li    $at, 4
  andi  $t6, $v0, 0xff
  beq   $t6, $at, .L7F07626C
   li    $at, 22
  beq   $t6, $at, .L7F0762C4
   li    $at, 24
  beql  $t6, $at, .L7F07629C
   lw    $v0, 4($a1)
  jr    $ra
   nop   

.L7F07626C:
  lw    $v0, 4($a1)
  lw    $t7, ($v0)
  bnel  $a2, $t7, .L7F076288
   lw    $t8, 4($v0)
  jr    $ra
   sw    $a3, ($v0)

  lw    $t8, 4($v0)
.L7F076288:
  bne   $a2, $t8, .L7F0762D8
   nop   
  jr    $ra
   sw    $a3, 4($v0)

  lw    $v0, 4($a1)
.L7F07629C:
  lw    $t9, ($v0)
  bnel  $a2, $t9, .L7F0762B4
   lw    $t0, 4($v0)
  jr    $ra
   sw    $a3, ($v0)

  lw    $t0, 4($v0)
.L7F0762B4:
  bne   $a2, $t0, .L7F0762D8
   nop   
  jr    $ra
   sw    $a3, 4($v0)

.L7F0762C4:
  lw    $v0, 4($a1)
  lw    $t1, 8($v0)
  bne   $a2, $t1, .L7F0762D8
   nop   
  sw    $a3, 8($v0)
.L7F0762D8:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0762E0
  addiu $sp, $sp, -0x78
  sw    $ra, 0x3c($sp)
  sw    $fp, 0x38($sp)
  sw    $s7, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  sw    $a2, 0x80($sp)
  sw    $a3, 0x84($sp)
  lw    $t6, 8($a0)
  move  $s5, $a0
  move  $a0, $a1
  jal   get_index_num_of_named_resource
   sw    $t6, 0x54($sp)
  sw    $v0, 0x50($sp)
  jal   get_rom_remaining_buffer_for_index
   move  $a0, $v0
  move  $s0, $v0
  jal   get_pc_remaining_buffer_for_index
   lw    $a0, 0x50($sp)
  move  $fp, $v0
  sw    $zero, 0x74($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x74
  jal   sub_GAME_7F0760C4
   addiu $a2, $sp, 0x6c
  lw    $s7, 0x6c($sp)
  lui   $s6, (0x00FFFFFF >> 16) # lui $s6, 0xff
  ori   $s6, (0x00FFFFFF & 0xFFFF) # ori $s6, $s6, 0xffff
  beqz  $s7, .L7F076474
   lw    $a3, 0x54($sp)
  lw    $t7, 8($s5)
  and   $t9, $s7, $s6
  addu  $t1, $s0, $a3
  addu  $a0, $t7, $t9
  subu  $t0, $fp, $a0
  addu  $a2, $t0, $a3
  subu  $a1, $t1, $a2
  subu  $t2, $a1, $a0
  move  $s3, $s7
  jal   sub_GAME_7F0CE794
   sw    $t2, 0x58($sp)
  move  $a0, $s5
  jal   sub_GAME_7F0CBE50
   lw    $a1, 0x84($sp)
  lw    $t3, 0x74($sp)
  beql  $t3, $zero, .L7F076440
   lw    $t2, 8($s5)
  lw    $s0, 0x6c($sp)
.L7F0763B4:
  lw    $s4, 0x74($sp)
  move  $a0, $s5
  addiu $a1, $sp, 0x74
  jal   sub_GAME_7F0760C4
   addiu $a2, $sp, 0x6c
  lw    $s7, 0x6c($sp)
  move  $a0, $s5
  move  $a1, $s4
  beqz  $s7, .L7F0763E8
   move  $a2, $s0
  subu  $s2, $s7, $s0
  b     .L7F076400
   and   $s1, $s0, $s6
.L7F0763E8:
  lw    $t4, 0x54($sp)
  lw    $t6, 8($s5)
  and   $s1, $s0, $s6
  addu  $t5, $t4, $fp
  subu  $t8, $t5, $t6
  subu  $s2, $t8, $s1
.L7F076400:
  jal   sub_GAME_7F07623C
   move  $a3, $s3
  lw    $v0, 8($s5)
  lw    $t9, 0x58($sp)
  and   $t0, $s3, $s6
  addu  $t7, $v0, $s1
  move  $a1, $s2
  lw    $a3, 0x84($sp)
  addu  $a2, $v0, $t0
  jal   process_microcode_sort_display_modes_expand_image_calls
   addu  $a0, $t7, $t9
  lw    $t1, 0x74($sp)
  addu  $s3, $s3, $v0
  bnezl $t1, .L7F0763B4
   lw    $s0, 0x6c($sp)
  lw    $t2, 8($s5)
.L7F076440:
  lw    $a1, 0x54($sp)
  and   $t3, $s3, $s6
  lw    $a3, 0x80($sp)
  addu  $t4, $t2, $t3
  subu  $s2, $t4, $a1
  addiu $a2, $s2, 0xf
  li    $at, -16
  and   $t5, $a2, $at
  sltiu $t6, $a3, 1
  move  $a3, $t6
  move  $a2, $t5
  jal   sub_GAME_7F0BD138
   lw    $a0, 0x50($sp)
.L7F076474:
  lw    $ra, 0x3c($sp)
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  lw    $s7, 0x34($sp)
  lw    $fp, 0x38($sp)
  jr    $ra
   addiu $sp, $sp, 0x78
");

asm(R"
glabel load_object_fill_header
  addiu $sp, $sp, -0x20
  sw    $s0, 0x18($sp)
  move  $s0, $a0
  sw    $ra, 0x1c($sp)
  sw    $a1, 0x24($sp)
  beqz  $a2, .L7F0764D4
   sw    $a2, 0x28($sp)
  move  $a0, $a1
  jal   _load_resource_named_to_buffer
   move  $a1, $zero
  b     .L7F0764EC
   move  $a2, $v0
.L7F0764D4:
  lw    $a0, 0x24($sp)
  move  $a1, $zero
  li    $a2, 256
  jal   _load_resource_named_to_membank
   li    $a3, 4
  move  $a2, $v0
.L7F0764EC:
  lh    $t9, 0x16($s0)
  lh    $t7, 0xc($s0)
  sw    $a2, 8($s0)
  sll   $t0, $t9, 2
  subu  $t0, $t0, $t9
  sll   $t8, $t7, 2
  addu  $v0, $a2, $t8
  sll   $t0, $t0, 2
  addu  $t1, $v0, $t0
  sw    $v0, 0x18($s0)
  sw    $t1, ($s0)
  move  $a0, $s0
  jal   sub_GAME_7F075A90
   lui   $a1, 0x500
  move  $a0, $s0
  lw    $a1, 0x24($sp)
  lw    $a2, 0x28($sp)
  jal   sub_GAME_7F0762E0
   lw    $a3, 0x30($sp)
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

void load_object_into_memory(unsigned short **param_1, char *param_2) {
  load_object_fill_header(param_1, param_2, 0, 0, 0);
}

void load_object_into_memory_unused_maybe(unsigned short **param_1,
                                          char *param_2, char *param_3,
                                          int param_4) {
  load_object_fill_header(param_1, param_2, param_3, param_4, 0x0);
}
