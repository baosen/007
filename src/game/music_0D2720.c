typedef struct {
  short stage_id, main_music, bg_sound, xtrack;
} music_setup;

music_setup music_setup_entries[] = {
    {9, 0xF, 0xFFFF, 0x29},       {0x14, 0xC, 0xFFFF, 0x26},
    {0x16, 0x11, 0xFFFF, 0x3D},   {0x17, 8, 0xFFFF, 0x12},
    {0x18, 0xB, 0xFFFF, 0x25},    {0x19, 3, 0xFFFF, 0x1D},
    {0x1A, 0xA, 0xFFFF, 0x3E},    {0x1B, 0x10, 0xFFFF, 0x2A},
    {0x1C, 0x19, 0xFFFF, 0x2E},   {0x1D, 0xE, 0xFFFF, 0x28},
    {0x1E, 4, 0xFFFF, 0x20},      {0x20, 0x16, 0xFFFF, 0x2F},
    {0x21, 9, 0xFFFF, 0x35},      {0x22, 7, 0xFFFF, 0x1F},
    {0x23, 0x32, 0xFFFF, 0x33},   {0x24, 0x39, 0xFFFF, 0x35},
    {0x25, 0x37, 0xFFFF, 0x2B},   {0x27, 0x1A, 0xFFFF, 0x15},
    {0x28, 6, 0xFFFF, 0xFFFF},    {0x29, 0x13, 0xFFFF, 0x30},
    {0x2A, 0x1C, 0xFFFF, 0xFFFF}, {0x2B, 0x1C, 0x35, 0x3C},
    {0x36, 0x31, 0xFFFF, 0xFFFF}, {0}};

short random_tracks[] = {3,    4,    5,    6,    7,    8,    9,    0xA,  0xB,
                         0xC,  0xD,  0xE,  0xF,  0x10, 0x11, 0x12, 0x13, 0x15,
                         0x16, 0x19, 0x1A, 0x1C, 0x1D, 0x1F, 0x20, 0x21, 0x22,
                         0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B, 0x2D,
                         0x2E, 0x2F, 0x30, 0x32, 0x34, 0x38, 0x39, 0};

asm(R"
glabel getmusictrack_or_randomtrack
  lui   $t6, %hi(music_setup_entries) 
  lh    $t6, %lo(music_setup_entries)($t6)
  addiu $sp, $sp, -0x28
  sw    $ra, 0x14($sp)
  beqz  $t6, .L7F0D27DC
   lui   $t2, %hi(random_tracks) 
  lui   $t7, %hi(music_setup_entries)
  addiu $v0, $t7, %lo(music_setup_entries)
  lh    $v1, ($v0)
.L7F0D2744:
  bnel  $a0, $v1, .L7F0D27D0
   lh    $v1, 8($v0)
  lh    $v1, 2($v0)
  li    $at, -1
  lui   $t8, %hi(random_tracks) 
  bne   $v1, $at, .L7F0D27C4
   nop   
  lh    $t8, %lo(random_tracks)($t8)
  lui   $v0, %hi(random_tracks)
  move  $v1, $zero
  beqz  $t8, .L7F0D2788
   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
  lh    $t9, 2($v0)
.L7F0D2778:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 2
  bnezl $t9, .L7F0D2778
   lh    $t9, 2($v0)
.L7F0D2788:
  jal   get_random_value
   sw    $v1, 0x20($sp)
  lw    $v1, 0x20($sp)
  lui   $a0, %hi(random_tracks)
  divu  $zero, $v0, $v1
  mfhi  $t0
  sll   $t1, $t0, 1
  addu  $a0, $a0, $t1
  lh    $a0, %lo(random_tracks)($a0)
  bnez  $v1, .L7F0D27B8
   nop   
  break 7
.L7F0D27B8:
  move  $v0, $a0
  b     .L7F0D283C
   lw    $ra, 0x14($sp)
.L7F0D27C4:
  b     .L7F0D2838
   move  $v0, $v1
  lh    $v1, 8($v0)
.L7F0D27D0:
  addiu $v0, $v0, 8
  bnez  $v1, .L7F0D2744
   nop   
.L7F0D27DC:
  lh    $t2, %lo(random_tracks)($t2)
  lui   $v0, %hi(random_tracks)
  move  $v1, $zero
  beqz  $t2, .L7F0D2804
   addiu $v0, %lo(random_tracks) # addiu $v0, $v0, -0x1430
  lh    $t3, 2($v0)
.L7F0D27F4:
  addiu $v1, $v1, 1
  addiu $v0, $v0, 2
  bnezl $t3, .L7F0D27F4
   lh    $t3, 2($v0)
.L7F0D2804:
  jal   get_random_value
   sw    $v1, 0x18($sp)
  lw    $v1, 0x18($sp)
  lui   $a0, %hi(random_tracks)
  divu  $zero, $v0, $v1
  mfhi  $t4
  sll   $t5, $t4, 1
  addu  $a0, $a0, $t5
  lh    $a0, %lo(random_tracks)($a0)
  bnez  $v1, .L7F0D2834
   nop   
  break 7
.L7F0D2834:
  move  $v0, $a0
.L7F0D2838:
  lw    $ra, 0x14($sp)
.L7F0D283C:
  addiu $sp, $sp, 0x28
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D2848
  lui   $t6, %hi(music_setup_entries) 
  lh    $t6, %lo(music_setup_entries)($t6)
  lui   $t7, %hi(music_setup_entries)
  addiu $v1, $t7, %lo(music_setup_entries)
  beql  $t6, $zero, .L7F0D2888
   li    $v0, -1
  lh    $v0, ($v1)
.L7F0D2864:
  bnel  $a0, $v0, .L7F0D2878
   lh    $v0, 8($v1)
  jr    $ra
   lh    $v0, 4($v1)

  lh    $v0, 8($v1)
.L7F0D2878:
  addiu $v1, $v1, 8
  bnez  $v0, .L7F0D2864
   nop   
  li    $v0, -1
.L7F0D2888:
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F0D2890
  lui   $t6, %hi(music_setup_entries) 
  lh    $t6, %lo(music_setup_entries)($t6)
  lui   $t7, %hi(music_setup_entries)
  addiu $v1, $t7, %lo(music_setup_entries)
  beql  $t6, $zero, .L7F0D28D0
   li    $v0, -1
  lh    $v0, ($v1)
.L7F0D28AC:
  bnel  $a0, $v0, .L7F0D28C0
   lh    $v0, 8($v1)
  jr    $ra
   lh    $v0, 6($v1)

  lh    $v0, 8($v1)
.L7F0D28C0:
  addiu $v1, $v1, 8
  bnez  $v0, .L7F0D28AC
   nop   
  li    $v0, -1
.L7F0D28D0:
  jr    $ra
   nop   
");
