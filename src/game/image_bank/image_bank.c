int img_curpos;
int img_curdatatable;
int img_bitcount;
int dword_CODE_bss_8008D0AC;
int globalbank_rdram_offset;
int *pGlobalimagetable;
struct sImageTableEntry *genericimage;
struct sImageTableEntry *impactimages;
struct sImageTableEntry *explosion_smokeimages;
struct sImageTableEntry *scattered_explosions;
struct sImageTableEntry *flareimage1;
struct sImageTableEntry *flareimage2;
struct sImageTableEntry *flareimage3;
struct sImageTableEntry *flareimage4;
struct sImageTableEntry *flareimage5;
struct sImageTableEntry *ammo9mmimage;
struct sImageTableEntry *rifleammoimage;
struct sImageTableEntry *shotgunammoimage;
struct sImageTableEntry *knifeammoimage;
struct sImageTableEntry *glaunchammoimage;
struct sImageTableEntry *rocketammoimage;
struct sImageTableEntry *genericmineammoimage;
struct sImageTableEntry *grenadeammoimage;
struct sImageTableEntry *magnumammoimage;
struct sImageTableEntry *goldengunammoimage;
struct sImageTableEntry *remotemineammoimage;
struct sImageTableEntry *timedmineammoimage;
struct sImageTableEntry *proxmineammoimage;
struct sImageTableEntry *tankammoimage;
struct sImageTableEntry *crosshairimage;
struct sImageTableEntry *betacrosshairimage;
struct sImageTableEntry *glassoverlayimage;
struct sImageTableEntry *monitorimages;
struct sImageTableEntry *skywaterimages;
struct sImageTableEntry *mainfolderimages;
struct sImageTableEntry *mpradarimages;
struct sImageTableEntry *mpcharselimages;
struct sImageTableEntry *mpstageselimages;

extern unsigned char *GlobalImageTable;

void makeemptyimageatpos(int pos) {
  img_curpos = pos;
  img_curdatatable = 0;
  img_bitcount = 0;
}

asm(R"
glabel sub_GAME_7F0CBF2C
  lui   $a1, %hi(img_bitcount)
  addiu $a1, %lo(img_bitcount) # addiu $a1, $a1, -0x2f58
  lw    $v1, ($a1)
  lui   $a3, %hi(img_curpos)
  addiu $a3, %lo(img_curpos) # addiu $a3, $a3, -0x2f60
  slt   $at, $v1, $a0
  beqz  $at, .L7F0CBF84
   lui   $a2, %hi(img_curdatatable)
  addiu $a2, %lo(img_curdatatable) # addiu $a2, $a2, -0x2f5c
.L7F0CBF50:
  lw    $v0, ($a3)
  lw    $t7, ($a2)
  addiu $t1, $v1, 8
  lbu   $t6, ($v0)
  sll   $t8, $t7, 8
  slt   $at, $t1, $a0
  addiu $t0, $v0, 1
  or    $t9, $t6, $t8
  sw    $t9, ($a2)
  sw    $t0, ($a3)
  sw    $t1, ($a1)
  bnez  $at, .L7F0CBF50
   move  $v1, $t1
.L7F0CBF84:
  lui   $a2, %hi(img_curdatatable)
  addiu $a2, %lo(img_curdatatable) # addiu $a2, $a2, -0x2f5c
  lw    $t3, ($a2)
  li    $t7, 1
  subu  $t2, $v1, $a0
  sllv  $t6, $t7, $a0
  addiu $t8, $t6, -1
  srlv  $t5, $t3, $t2
  sw    $t2, ($a1)
  jr    $ra
   and   $v0, $t5, $t8
");

asm(R"
glabel load_prepare_global_image_bank
  addiu $sp, $sp, -0x28
  lui   $t6, %hi(0x02001400) # $t6, 0x200
  lui   $t7, 0x200
  sw    $s0, 0x14($sp)
  addiu $t7, $t7, 0
  addiu $t6, %lo(0x02001400) # addiu $t6, $t6, 0x1400
  sw    $ra, 0x24($sp)
  subu  $s0, $t6, $t7
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  addiu $a0, $s0, 0x1000
  jal   mempAllocBytesInBank
   li    $a1, 4
  lui   $s1, %hi(pGlobalimagetable)
  addiu $s1, %lo(pGlobalimagetable) # addiu $s1, $s1, -0x2f4c
  addiu $t9, $v0, 0xfff
  li    $at, -4096
  sw    $v0, ($s1)
  and   $a0, $t9, $at
  lui   $a1, %hi(GlobalImageTable) # $a1, 0x2a
  sw    $a0, ($s1)
  addiu $a1, %lo(GlobalImageTable) # addiu $a1, $a1, -0x2ea0
  jal   romCopy
   move  $a2, $s0
  lw    $t1, ($s1)
  lui   $at, 0xfe00
  lui   $s0, %hi(globalbank_rdram_offset)
  addu  $v0, $t1, $at
  lui   $t3, %hi(0x02000AC8) # $t3, 0x200
  addiu $s0, %lo(globalbank_rdram_offset) # addiu $s0, $s0, -0x2f50
  addiu $t3, %lo(0x02000AC8) # addiu $t3, $t3, 0xac8
  sw    $v0, ($s0)
  addu  $t4, $v0, $t3
  lui   $at, %hi(genericimage)
  lui   $t5, %hi(0x02000AD4) # $t5, 0x200
  sw    $t4, %lo(genericimage)($at)
  addiu $t5, %lo(0x02000AD4) # addiu $t5, $t5, 0xad4
  addu  $t6, $v0, $t5
  lui   $at, %hi(impactimages)
  sw    $t6, %lo(impactimages)($at)
  lui   $t7, %hi(0x02000BC4) # $t7, 0x200
  lui   $t9, %hi(0x02000C0C) # $t9, 0x200
  lui   $s2, %hi(explosion_smokeimages)
  lui   $s3, %hi(scattered_explosions)
  addiu $t7, %lo(0x02000BC4) # addiu $t7, $t7, 0xbc4
  addiu $t9, %lo(0x02000C0C) # addiu $t9, $t9, 0xc0c
  lui   $t1, %hi(0x02000C48) # $t1, 0x200
  addiu $s3, %lo(scattered_explosions) # addiu $s3, $s3, -0x2f3c
  addiu $s2, %lo(explosion_smokeimages) # addiu $s2, $s2, -0x2f40
  addu  $t8, $v0, $t7
  addu  $t0, $v0, $t9
  addiu $t1, %lo(0x02000C48) # addiu $t1, $t1, 0xc48
  sw    $t8, ($s2)
  sw    $t0, ($s3)
  addu  $t2, $v0, $t1
  lui   $at, %hi(flareimage1)
  lui   $t3, %hi(0x02000C54) # $t3, 0x200
  sw    $t2, %lo(flareimage1)($at)
  addiu $t3, %lo(0x02000C54) # addiu $t3, $t3, 0xc54
  addu  $t4, $v0, $t3
  lui   $at, %hi(flareimage2)
  lui   $t5, %hi(0x02000C60) # $t5, 0x200
  sw    $t4, %lo(flareimage2)($at)
  addiu $t5, %lo(0x02000C60) # addiu $t5, $t5, 0xc60
  addu  $t6, $v0, $t5
  lui   $at, %hi(flareimage3)
  lui   $t7, %hi(0x02000C6C) # $t7, 0x200
  sw    $t6, %lo(flareimage3)($at)
  addiu $t7, %lo(0x02000C6C) # addiu $t7, $t7, 0xc6c
  addu  $t8, $v0, $t7
  lui   $at, %hi(flareimage4)
  lui   $t9, %hi(0x02000C78) # $t9, 0x200
  sw    $t8, %lo(flareimage4)($at)
  addiu $t9, %lo(0x02000C78) # addiu $t9, $t9, 0xc78
  addu  $t0, $v0, $t9
  lui   $at, %hi(flareimage5)
  lui   $t1, %hi(0x02000C84) # $t1, 0x200
  sw    $t0, %lo(flareimage5)($at)
  addiu $t1, %lo(0x02000C84) # addiu $t1, $t1, 0xc84
  addu  $t2, $v0, $t1
  lui   $at, %hi(ammo9mmimage)
  lui   $t3, %hi(0x02000C90) # $t3, 0x200
  sw    $t2, %lo(ammo9mmimage)($at)
  addiu $t3, %lo(0x02000C90) # addiu $t3, $t3, 0xc90
  addu  $t4, $v0, $t3
  lui   $at, %hi(rifleammoimage)
  lui   $t5, %hi(0x02000C9C) # $t5, 0x200
  sw    $t4, %lo(rifleammoimage)($at)
  addiu $t5, %lo(0x02000C9C) # addiu $t5, $t5, 0xc9c
  addu  $t6, $v0, $t5
  lui   $at, %hi(shotgunammoimage)
  lui   $t7, %hi(0x02000CA8) # $t7, 0x200
  sw    $t6, %lo(shotgunammoimage)($at)
  addiu $t7, %lo(0x02000CA8) # addiu $t7, $t7, 0xca8
  addu  $t8, $v0, $t7
  lui   $at, %hi(knifeammoimage)
  lui   $t9, %hi(0x02000CB4) # $t9, 0x200
  sw    $t8, %lo(knifeammoimage)($at)
  addiu $t9, %lo(0x02000CB4) # addiu $t9, $t9, 0xcb4
  addu  $t0, $v0, $t9
  lui   $at, %hi(glaunchammoimage)
  lui   $t1, %hi(0x02000CC0) # $t1, 0x200
  sw    $t0, %lo(glaunchammoimage)($at)
  addiu $t1, %lo(0x02000CC0) # addiu $t1, $t1, 0xcc0
  addu  $t2, $v0, $t1
  lui   $at, %hi(rocketammoimage)
  lui   $t3, %hi(0x02000CCC) # $t3, 0x200
  sw    $t2, %lo(rocketammoimage)($at)
  addiu $t3, %lo(0x02000CCC) # addiu $t3, $t3, 0xccc
  addu  $t4, $v0, $t3
  lui   $at, %hi(genericmineammoimage)
  lui   $t5, %hi(0x02000CD8) # $t5, 0x200
  sw    $t4, %lo(genericmineammoimage)($at)
  addiu $t5, %lo(0x02000CD8) # addiu $t5, $t5, 0xcd8
  addu  $t6, $v0, $t5
  lui   $at, %hi(grenadeammoimage)
  lui   $t7, %hi(0x02000CE4) # $t7, 0x200
  sw    $t6, %lo(grenadeammoimage)($at)
  addiu $t7, %lo(0x02000CE4) # addiu $t7, $t7, 0xce4
  addu  $t8, $v0, $t7
  lui   $at, %hi(magnumammoimage)
  lui   $t9, %hi(0x02000CF0) # $t9, 0x200
  sw    $t8, %lo(magnumammoimage)($at)
  addiu $t9, %lo(0x02000CF0) # addiu $t9, $t9, 0xcf0
  addu  $t0, $v0, $t9
  lui   $at, %hi(goldengunammoimage)
  lui   $t1, %hi(0x02000CFC) # $t1, 0x200
  sw    $t0, %lo(goldengunammoimage)($at)
  addiu $t1, %lo(0x02000CFC) # addiu $t1, $t1, 0xcfc
  addu  $t2, $v0, $t1
  lui   $at, %hi(remotemineammoimage)
  lui   $t3, %hi(0x02000D08) # $t3, 0x200
  sw    $t2, %lo(remotemineammoimage)($at)
  addiu $t3, %lo(0x02000D08) # addiu $t3, $t3, 0xd08
  addu  $t4, $v0, $t3
  lui   $at, %hi(timedmineammoimage)
  lui   $t5, %hi(0x02000D14) # $t5, 0x200
  sw    $t4, %lo(timedmineammoimage)($at)
  addiu $t5, %lo(0x02000D14) # addiu $t5, $t5, 0xd14
  addu  $t6, $v0, $t5
  lui   $at, %hi(proxmineammoimage)
  lui   $t7, %hi(0x02000D20) # $t7, 0x200
  sw    $t6, %lo(proxmineammoimage)($at)
  addiu $t7, %lo(0x02000D20) # addiu $t7, $t7, 0xd20
  addu  $t8, $v0, $t7
  lui   $at, %hi(tankammoimage)
  lui   $t9, %hi(0x02000D2C) # $t9, 0x200
  sw    $t8, %lo(tankammoimage)($at)
  addiu $t9, %lo(0x02000D2C) # addiu $t9, $t9, 0xd2c
  addu  $t0, $v0, $t9
  lui   $at, %hi(crosshairimage)
  lui   $t1, %hi(0x02000D38) # $t1, 0x200
  sw    $t0, %lo(crosshairimage)($at)
  addiu $t1, %lo(0x02000D38) # addiu $t1, $t1, 0xd38
  addu  $t2, $v0, $t1
  lui   $at, %hi(betacrosshairimage)
  lui   $t3, %hi(0x02000D44) # $t3, 0x200
  sw    $t2, %lo(betacrosshairimage)($at)
  addiu $t3, %lo(0x02000D44) # addiu $t3, $t3, 0xd44
  addu  $t4, $v0, $t3
  lui   $at, %hi(glassoverlayimage)
  lui   $t5, %hi(0x02000D5C) # $t5, 0x200
  sw    $t4, %lo(glassoverlayimage)($at)
  addiu $t5, %lo(0x02000D5C) # addiu $t5, $t5, 0xd5c
  addu  $t6, $v0, $t5
  lui   $at, %hi(monitorimages)
  lui   $t7, %hi(0x02000FB4) # $t7, 0x200
  sw    $t6, %lo(monitorimages)($at)
  addiu $t7, %lo(0x02000FB4) # addiu $t7, $t7, 0xfb4
  addu  $t8, $v0, $t7
  lui   $at, %hi(skywaterimages)
  lui   $t9, %hi(0x02000FD8) # $t9, 0x200
  sw    $t8, %lo(skywaterimages)($at)
  addiu $t9, %lo(0x02000FD8) # addiu $t9, $t9, 0xfd8
  addu  $t0, $v0, $t9
  lui   $at, %hi(mainfolderimages)
  lui   $t1, %hi(0x02001020) # $t1, 0x200
  sw    $t0, %lo(mainfolderimages)($at)
  addiu $t1, %lo(0x02001020) # addiu $t1, $t1, 0x1020
  addu  $t2, $v0, $t1
  lui   $at, %hi(mpradarimages)
  lui   $t3, %hi(0x0200102C) # $t3, 0x200
  sw    $t2, %lo(mpradarimages)($at)
  addiu $t3, %lo(0x0200102C) # addiu $t3, $t3, 0x102c
  addu  $t4, $v0, $t3
  lui   $at, %hi(mpcharselimages)
  lui   $t5, %hi(0x0200132C) # $t5, 0x200
  sw    $t4, %lo(mpcharselimages)($at)
  addiu $t5, %lo(0x0200132C) # addiu $t5, $t5, 0x132c
  lui   $t7, 0x200
  addu  $t6, $v0, $t5
  lui   $at, %hi(mpstageselimages)
  addiu $t7, $t7, 0
  sw    $t6, %lo(mpstageselimages)($at)
  addu  $a0, $v0, $t7
  jal   check_load_image_to_buffer
   move  $a1, $zero
  lw    $t8, ($s0)
  lui   $t9, %hi(0x02000078) # $t9, 0x200
  addiu $t9, %lo(0x02000078) # addiu $t9, $t9, 0x78
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t8, $t9
  lw    $t0, ($s0)
  lui   $t1, %hi(0x02000120) # $t1, 0x200
  addiu $t1, %lo(0x02000120) # addiu $t1, $t1, 0x120
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t0, $t1
  lw    $t2, ($s0)
  lui   $t3, %hi(0x020001C8) # $t3, 0x200
  addiu $t3, %lo(0x020001C8) # addiu $t3, $t3, 0x1c8
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t2, $t3
  lw    $t4, ($s0)
  lui   $t5, %hi(0x02000270) # $t5, 0x200
  addiu $t5, %lo(0x02000270) # addiu $t5, $t5, 0x270
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t4, $t5
  lw    $t6, ($s0)
  lui   $t7, %hi(0x02000318) # $t7, 0x200
  addiu $t7, %lo(0x02000318) # addiu $t7, $t7, 0x318
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t6, $t7
  lw    $t8, ($s0)
  lui   $t9, %hi(0x020003C0) # $t9, 0x200
  addiu $t9, %lo(0x020003C0) # addiu $t9, $t9, 0x3c0
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t8, $t9
  lw    $t0, ($s0)
  lui   $t1, %hi(0x02000468) # $t1, 0x200
  addiu $t1, %lo(0x02000468) # addiu $t1, $t1, 0x468
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t0, $t1
  lw    $t2, ($s0)
  lui   $t3, %hi(0x02000510) # $t3, 0x200
  addiu $t3, %lo(0x02000510) # addiu $t3, $t3, 0x510
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t2, $t3
  lw    $t4, ($s0)
  lui   $t5, %hi(0x020005B8) # $t5, 0x200
  addiu $t5, %lo(0x020005B8) # addiu $t5, $t5, 0x5b8
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t4, $t5
  lw    $t6, ($s0)
  lui   $t7, %hi(0x02000660) # $t7, 0x200
  addiu $t7, %lo(0x02000660) # addiu $t7, $t7, 0x660
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t6, $t7
  lw    $t8, ($s0)
  lui   $t9, %hi(0x02000708) # $t9, 0x200
  addiu $t9, %lo(0x02000708) # addiu $t9, $t9, 0x708
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t8, $t9
  lw    $t0, ($s0)
  lui   $t1, %hi(0x020007B0) # $t1, 0x200
  addiu $t1, %lo(0x020007B0) # addiu $t1, $t1, 0x7b0
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t0, $t1
  lw    $t2, ($s0)
  lui   $t3, %hi(0x02000858) # $t3, 0x200
  addiu $t3, %lo(0x02000858) # addiu $t3, $t3, 0x858
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t2, $t3
  lw    $t4, ($s0)
  lui   $t5, %hi(0x02000900) # $t5, 0x200
  addiu $t5, %lo(0x02000900) # addiu $t5, $t5, 0x900
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t4, $t5
  lw    $t6, ($s0)
  lui   $t7, %hi(0x020009A8) # $t7, 0x200
  addiu $t7, %lo(0x020009A8) # addiu $t7, $t7, 0x9a8
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t6, $t7
  lw    $t8, ($s0)
  lui   $t9, %hi(0x02000A50) # $t9, 0x200
  addiu $t9, %lo(0x02000A50) # addiu $t9, $t9, 0xa50
  move  $a1, $zero
  jal   check_load_image_to_buffer
   addu  $a0, $t8, $t9
  lui   $a0, %hi(genericimage)
  lw    $a0, %lo(genericimage)($a0)
  jal   load_image_to_buffer
   move  $a1, $zero
  move  $s0, $zero
  lw    $t0, ($s2)
.L7F0CC460:
  move  $a1, $zero
  jal   load_image_to_buffer
   addu  $a0, $s0, $t0
  addiu $s0, $s0, 0xc
  slti  $at, $s0, 0x48
  bnezl $at, .L7F0CC460
   lw    $t0, ($s2)
  move  $s0, $zero
  li    $s1, 60
  lw    $t1, ($s3)
.L7F0CC488:
  move  $a1, $zero
  jal   load_image_to_buffer
   addu  $a0, $s0, $t1
  addiu $s0, $s0, 0xc
  bnel  $s0, $s1, .L7F0CC488
   lw    $t1, ($s3)
  lw    $ra, 0x24($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  lw    $s2, 0x1c($sp)
  lw    $s3, 0x20($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
