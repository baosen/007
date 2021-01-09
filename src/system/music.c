// This file contains code to handle music.
extern signed char bootswitch_sound;

int music_unused = 0;

int music1_track_num = 0;
unsigned short music1len = 0x7FFF;

int music2_track_num = 0;
unsigned short music2len = 0x7FFF;

int music3_track_num = 0;
unsigned short music3len = 0x7FFF;

int music1_playing = 0, music2_playing = 0, music3_playing = 0;

short music_tempo_array[] = {
    0x6665, 0x7332, 0x7332, 0x7998, 0x7332, 0x5998, 0x6665, 0x6665, 0x6665,
    0x6665, 0x7332, 0x6665, 0x7332, 0x6665, 0x6665, 0x7332, 0x7332, 0x6665,
    0x3FFF, 0x6665, 0x6665, 0x3FFF, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665,
    0x7998, 0x6665, 0x5998, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665,
    0x6665, 0x5998, 0x6665, 0x3332, 0x6665, 0x7332, 0x7332, 0x5998, 0x7332,
    0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x6CCB, 0x6665,
    0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x6665, 0x7332, 0x6665, 0x7332,
    0x7998, 0xFFFF};

unsigned int hp[4]; // maybe heap?
unsigned int *ptr_sfx_buf;
int D_80063724;

int seqp_1, seqp_2, seqp_3;

void *ptr_musicdatatable;

char D_80063738[0x80];
char D_800637B8[0x7E];
short D_80063836;
int D_80063838;
int D_8006383C;
int D_80063840;
short musicTrack1_length;
short D_80063846;
short D_80063848;
short music1_length, music2_length, music3_length;
int music1_rate, music2_rate, music3_rate;
int D_8006385C;
char D_80063860[0xF8];
char D_80063958[0xF8];
char D_80063A50[0x100];
char D_80063B50[0x54];
int D_80063BA4;
int D_80063BA8;

asm(R"
glabel audio_related
  lhu   $t6, ($a0)
  move  $v0, $zero
  move  $v1, $a0
  blez  $t6, .L70006A28
   nop   
  lw    $t7, 4($v1)
.L70006A08:
  addiu $v0, $v0, 1
  addiu $v1, $v1, 8
  addu  $t8, $t7, $a1
  sw    $t8, -4($v1)
  lhu   $t9, ($a0)
  slt   $at, $v0, $t9
  bnezl $at, .L70006A08
   lw    $t7, 4($v1)
.L70006A28:
  jr    $ra
   nop   
");

// loads sound and music banks into memory segment 6.
asm(R"
glabel setupaudio
  lui   $t6, %hi(bootswitch_sound) 
  lb    $t6, %lo(bootswitch_sound)($t6)
  addiu $sp, $sp, -0xe8
  sw    $ra, 0x24($sp)
  bnez  $t6, .L70006E68
   sw    $s0, 0x20($sp)
  lui   $a0, (0x0002E000 >> 16) # lui $a0, 2
  ori   $a0, (0x0002E000 & 0xFFFF) # ori $a0, $a0, 0xe000
  jal   mempAllocBytesInBank
   li    $a1, 6
  lui   $at, (0x0002E000 >> 16) # lui $at, 2
  ori   $at, (0x0002E000 & 0xFFFF) # ori $at, $at, 0xe000
  move  $v1, $v0
  move  $a1, $v0
  addu  $a0, $v0, $at
.L70006A6C:
  addiu $v1, $v1, 1
  sltu  $at, $v1, $a0
  bnez  $at, .L70006A6C
   sb    $zero, -1($v1)
  lui   $s0, %hi(hp)
  addiu $s0, %lo(hp) # addiu $s0, $s0, 0x3710
  lui   $a2, (0x0002E000 >> 16) # lui $a2, 2
  ori   $a2, (0x0002E000 & 0xFFFF) # ori $a2, $a2, 0xe000
  jal   alHeapInit
   move  $a0, $s0
  lui   $t7, %hi(_sfxtbl) # $t7, 0x2f
  lui   $t8, %hi(_sfxctl) # $t8, 0x2f
  addiu $t8, %lo(_sfxctl) # addiu $t8, $t8, -0x4220
  addiu $t7, %lo(_sfxtbl) # addiu $t7, $t7, 0x19a0
  subu  $v0, $t7, $t8
  sw    $v0, 0x10($sp)
  sw    $v0, 0x38($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $a1, %hi(_sfxctl) # $a1, 0x2f
  sw    $v0, 0xd4($sp)
  addiu $a1, %lo(_sfxctl) # addiu $a1, $a1, -0x4220
  move  $a0, $v0
  jal   romCopy
   lw    $a2, 0x38($sp)
  lui   $a1, %hi(_sfxtbl) # $a1, 0x2f
  addiu $a1, %lo(_sfxtbl) # addiu $a1, $a1, 0x19a0
  jal   alBnkfNew
   lw    $a0, 0xd4($sp)
  lw    $t9, 0xd4($sp)
  lui   $t1, %hi(_instrumentstbl) # $t1, 0x3c
  lui   $t2, %hi(_instrumentsctl) # $t2, 0x3b
  lw    $t0, 4($t9)
  addiu $t2, %lo(_instrumentsctl) # addiu $t2, $t2, 0x4450
  addiu $t1, %lo(_instrumentstbl) # addiu $t1, $t1, -0x7810
  lui   $at, %hi(ptr_sfx_buf)
  subu  $v0, $t1, $t2
  sw    $v0, 0x10($sp)
  sw    $v0, 0x38($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  li    $a3, 1
  jal   alHeapDBAlloc
   sw    $t0, %lo(ptr_sfx_buf)($at)
  lui   $a1, %hi(_instrumentsctl) # $a1, 0x3b
  sw    $v0, 0xcc($sp)
  addiu $a1, %lo(_instrumentsctl) # addiu $a1, $a1, 0x4450
  move  $a0, $v0
  jal   romCopy
   lw    $a2, 0x38($sp)
  lui   $a1, %hi(_instrumentstbl) # $a1, 0x3c
  addiu $a1, %lo(_instrumentstbl) # addiu $a1, $a1, -0x7810
  jal   alBnkfNew
   lw    $a0, 0xcc($sp)
  lw    $t3, 0xcc($sp)
  lui   $at, %hi(D_80063724)
  li    $t5, 16
  lw    $t4, 4($t3)
  sw    $t5, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  li    $a3, 1
  jal   alHeapDBAlloc
   sw    $t4, %lo(D_80063724)($at)
  lui   $v1, %hi(ptr_musicdatatable)
  lui   $a1, %hi(_musicsampletbl) # $a1, 0x42
  addiu $v1, %lo(ptr_musicdatatable) # addiu $v1, $v1, 0x3734
  addiu $a1, %lo(_musicsampletbl) # addiu $a1, $a1, -0x6870
  sw    $v0, ($v1)
  sw    $a1, 0x38($sp)
  move  $a0, $v0
  jal   romCopy
   li    $a2, 16
  lui   $t6, %hi(ptr_musicdatatable) 
  lw    $t6, %lo(ptr_musicdatatable)($t6)
  move  $a0, $zero
  move  $a1, $zero
  lhu   $v1, ($t6)
  move  $a2, $s0
  li    $a3, 1
  sll   $t7, $v1, 3
  addiu $v1, $t7, 4
  sw    $v1, 0x10($sp)
  jal   alHeapDBAlloc
   sw    $v1, 0x40($sp)
  lw    $v1, 0x40($sp)
  lui   $a3, %hi(ptr_musicdatatable)
  addiu $a3, %lo(ptr_musicdatatable) # addiu $a3, $a3, 0x3734
  addiu $a2, $v1, 0xf
  ori   $t8, $a2, 0xf
  sw    $v0, ($a3)
  xori  $a2, $t8, 0xf
  move  $a0, $v0
  jal   romCopy
   lw    $a1, 0x38($sp)
  lui   $a0, %hi(ptr_musicdatatable)
  lui   $a1, %hi(_musicsampletbl) # $a1, 0x42
  addiu $a1, %lo(_musicsampletbl) # addiu $a1, $a1, -0x6870
  jal   audio_related
   lw    $a0, %lo(ptr_musicdatatable)($a0)
  li    $t0, 6344
  sw    $t0, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $at, %hi(D_80063838)
  li    $t1, 6000
  sw    $v0, %lo(D_80063838)($at)
  sw    $t1, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $a3, %hi(D_8006383C)
  addiu $a3, %lo(D_8006383C) # addiu $a3, $a3, 0x383c
  sw    $v0, ($a3)
  addiu $t3, $v0, 0x7d0
  lui   $at, %hi(D_80063840)
  lui   $v1, %hi(D_80063738)
  lui   $a0, %hi(ptr_musicdatatable)
  lui   $a1, %hi(D_800637B8)
  lui   $a2, %hi(D_80063836)
  sw    $t3, %lo(D_80063840)($at)
  addiu $a2, %lo(D_80063836) # addiu $a2, $a2, 0x3836
  addiu $a1, %lo(D_800637B8) # addiu $a1, $a1, 0x37b8
  lw    $a0, %lo(ptr_musicdatatable)($a0)
  addiu $v1, %lo(D_80063738) # addiu $v1, $v1, 0x3738
.L70006C88:
  lhu   $t4, 8($a0)
  addiu $a0, $a0, 8
  addiu $a1, $a1, 2
  sh    $t4, ($v1)
  lhu   $t5, 2($a0)
  andi  $v0, $t4, 0xffff
  andi  $t6, $v0, 1
  beqz  $t6, .L70006CB4
   sh    $t5, -2($a1)
  addiu $t7, $v0, 1
  sh    $t7, ($v1)
.L70006CB4:
  bne   $a1, $a2, .L70006C88
   addiu $v1, $v1, 2
  li    $t8, 24
  li    $t9, 128
  li    $t0, 6
  sw    $zero, 0xa4($sp)
  sw    $t8, 0xa8($sp)
  sw    $t9, 0xac($sp)
  sw    $zero, 0xb4($sp)
  sb    $t0, 0xc0($sp)
  sw    $zero, 0xbc($sp)
  sw    $s0, 0xb8($sp)
  jal   amCreateAudioMgr
   addiu $a0, $sp, 0xa4
  li    $t1, 16
  li    $t2, 64
  li    $t3, 16
  li    $t4, 16
  li    $t5, 64
  li    $t6, 16
  li    $t7, 16
  li    $t8, 64
  li    $t9, 16
  li    $t0, 124
  sw    $t1, 0x88($sp)
  sw    $t2, 0x8c($sp)
  sb    $t3, 0x90($sp)
  sw    $s0, 0x94($sp)
  sw    $zero, 0x98($sp)
  sw    $zero, 0x9c($sp)
  sw    $zero, 0xa0($sp)
  sw    $t4, 0x6c($sp)
  sw    $t5, 0x70($sp)
  sb    $t6, 0x74($sp)
  sw    $s0, 0x78($sp)
  sw    $zero, 0x7c($sp)
  sw    $zero, 0x80($sp)
  sw    $zero, 0x84($sp)
  sw    $t7, 0x50($sp)
  sw    $t8, 0x54($sp)
  sb    $t9, 0x58($sp)
  sw    $s0, 0x5c($sp)
  sw    $zero, 0x60($sp)
  sw    $zero, 0x64($sp)
  sw    $zero, 0x68($sp)
  sw    $t0, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $at, %hi(seqp_1)
  li    $t1, 124
  sw    $v0, %lo(seqp_1)($at)
  sw    $t1, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $at, %hi(seqp_2)
  li    $t2, 124
  sw    $v0, %lo(seqp_2)($at)
  sw    $t2, 0x10($sp)
  move  $a0, $zero
  move  $a1, $zero
  move  $a2, $s0
  jal   alHeapDBAlloc
   li    $a3, 1
  lui   $at, %hi(seqp_3)
  lui   $a0, %hi(seqp_1)
  sw    $v0, %lo(seqp_3)($at)
  lw    $a0, %lo(seqp_1)($a0)
  jal   alCSPNew
   addiu $a1, $sp, 0x88
  lui   $a0, %hi(seqp_1)
  lui   $a1, %hi(D_80063724)
  lw    $a1, %lo(D_80063724)($a1)
  jal   alSeqpSetBank
   lw    $a0, %lo(seqp_1)($a0)
  lui   $a0, %hi(seqp_2)
  lw    $a0, %lo(seqp_2)($a0)
  jal   alCSPNew
   addiu $a1, $sp, 0x6c
  lui   $a0, %hi(seqp_2)
  lui   $a1, %hi(D_80063724)
  lw    $a1, %lo(D_80063724)($a1)
  jal   alSeqpSetBank
   lw    $a0, %lo(seqp_2)($a0)
  lui   $a0, %hi(seqp_3)
  lw    $a0, %lo(seqp_3)($a0)
  jal   alCSPNew
   addiu $a1, $sp, 0x50
  lui   $a0, %hi(seqp_3)
  lui   $a1, %hi(D_80063724)
  lw    $a1, %lo(D_80063724)($a1)
  jal   alSeqpSetBank
   lw    $a0, %lo(seqp_3)($a0)
  li    $t3, 64
  li    $t4, 64
  li    $t5, 8
  sw    $t3, 0xdc($sp)
  sw    $t4, 0xd8($sp)
  sw    $t5, 0xe0($sp)
  sw    $s0, 0xe4($sp)
  jal   sfx_c_70007B20
   addiu $a0, $sp, 0xd8
  jal   startAudioThread
   nop   
.L70006E68:
  lw    $ra, 0x24($sp)
  lw    $s0, 0x20($sp)
  addiu $sp, $sp, 0xe8
  jr    $ra
   nop   
");

// Play first music track A0.
asm(R"
glabel musicTrack1Play
  lui   $t6, %hi(bootswitch_sound) 
  lb    $t6, %lo(bootswitch_sound)($t6)
  addiu $sp, $sp, -0x2148
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  bnez  $t6, .L70006FBC
   sw    $a0, 0x2148($sp)
  lui   $t7, %hi(music1_track_num) 
  lw    $t7, %lo(music1_track_num)($t7)
  beql  $t7, $zero, .L70006EB4
   lw    $t8, 0x2148($sp)
  jal   musicTrack1Stop
   nop   
  lw    $t8, 0x2148($sp)
.L70006EB4:
  lui   $s0, %hi(seqp_1)
  lui   $at, %hi(music1_track_num)
  addiu $s0, %lo(seqp_1) # addiu $s0, $s0, 0x3728
  sw    $t8, %lo(music1_track_num)($at)
  jal   alCSPGetState
   lw    $a0, ($s0)
  beqz  $v0, .L70006EE4
   nop   
.L70006ED4:
  jal   alCSPGetState
   lw    $a0, ($s0)
  bnez  $v0, .L70006ED4
   nop   
.L70006EE4:
  lui   $a3, %hi(music1_track_num)
  lw    $a3, %lo(music1_track_num)($a3)
  lui   $t9, %hi(ptr_musicdatatable) 
  lw    $t9, %lo(ptr_musicdatatable)($t9)
  sll   $t1, $a3, 3
  lui   $at, 1
  addu  $t2, $t9, $t1
  lw    $a1, 4($t2)
  lui   $v1, %hi(D_80063738)
  sll   $v0, $a3, 1
  sltu  $at, $a1, $at
  beqz  $at, .L70006F28
   addu  $v1, $v1, $v0
  jal   musicTrack1Play
   li    $a0, 1
  b     .L70006FC0
   lw    $ra, 0x1c($sp)
.L70006F28:
  lhu   $v1, %lo(D_80063738)($v1)
  lui   $a2, %hi(D_800637B8)
  addu  $a2, $a2, $v0
  lhu   $a2, %lo(D_800637B8)($a2)
  lui   $t0, %hi(D_80063838) 
  addiu $v1, $v1, 0xf
  lw    $t0, %lo(D_80063838)($t0)
  ori   $t3, $v1, 0xf
  xori  $t4, $t3, 0xf
  addiu $a2, $a2, 0xf
  addiu $v1, $t4, 0x40
  ori   $t5, $a2, 0xf
  xori  $a2, $t5, 0xf
  addu  $t7, $t0, $v1
  subu  $a0, $t7, $a2
  sw    $a0, 0x28($sp)
  jal   romCopy
   sw    $t0, 0x2140($sp)
  lw    $a0, 0x28($sp)
  lw    $a1, 0x2140($sp)
  jal   decompressdata
   addiu $a2, $sp, 0x34
  lui   $a0, %hi(D_80063860)
  lui   $a1, %hi(D_80063838)
  lw    $a1, %lo(D_80063838)($a1)
  jal   alCSeqNew
   addiu $a0, %lo(D_80063860) # addiu $a0, $a0, 0x3860
  lui   $a1, %hi(D_80063860)
  addiu $a1, %lo(D_80063860) # addiu $a1, $a1, 0x3860
  jal   alCSPSetSeq
   lw    $a0, ($s0)
  jal   musicTrack1Length
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  jal   alCSPPlay
   lw    $a0, ($s0)
.L70006FBC:
  lw    $ra, 0x1c($sp)
.L70006FC0:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x2148
  jr    $ra
   nop   
");

// Stop playing first music track.
void musicTrack1Stop(void) {
  if (bootswitch_sound == 0) {
    music1_playing = 0;
    if (music1_track_num != 0)
      if (alCSPGetState(seqp_1) == 1)
        alCSPStop(seqp_1);
    music1_track_num = 0;
  }
}

unsigned short musicTrack1Length(void) { return music1len; }

// Sets something for currently running music track...
asm(R"
glabel musicTrack1Vol
  lui   $t6, %hi(music1_track_num) 
  lw    $t6, %lo(music1_track_num)($t6)
  lui   $t8, %hi(music_tempo_array)
  andi  $a2, $a0, 0xffff
  sll   $t7, $t6, 1
  addu  $t8, $t8, $t7
  lh    $t8, %lo(music_tempo_array)($t8)
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  multu $a2, $t8
  sw    $ra, 0x14($sp)
  lui   $at, %hi(music1len)
  lui   $a0, %hi(seqp_1)
  sh    $a2, %lo(music1len)($at)
  lw    $a0, %lo(seqp_1)($a0)
  mflo  $v0
  srl   $t9, $v0, 0xf
  sll   $a1, $t9, 0x10
  sra   $t0, $a1, 0x10
  jal   alCSPSetVol
   move  $a1, $t0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel musicTrack1Tempo
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   musicTrack1Length
   nop   
  lui   $t6, %hi(music1_track_num) 
  lw    $t6, %lo(music1_track_num)($t6)
  lui   $a0, %hi(music_tempo_array)
  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
  sll   $t7, $t6, 1
  addu  $t8, $a0, $t7
  sh    $v0, ($t8)
  lh    $t9, ($a0)
  lui   $v0, %hi(music_tempo_array)
  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
  bltz  $t9, .L700070F0
   lw    $ra, 0x14($sp)
  lh    $t0, 2($v0)
.L700070E4:
  addiu $v0, $v0, 2
  bgezl $t0, .L700070E4
   lh    $t0, 2($v0)
.L700070F0:
  jr    $ra
   addiu $sp, $sp, 0x18
");

void music_related_1(float rate) {
  if (0 <= music1_playing) {
    musicTrack1_length = musicTrack1Length();
    music1_length = 0;
    music1_rate = rate * 60.0f;
    music1_playing = -1;
  }
}

asm(R"
glabel music_related_3
  lui   $t6, %hi(music1_playing) 
  lw    $t6, %lo(music1_playing)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  bgtz  $t6, .L700071F4
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(seqp_1)
  jal   alCSPPlay
   lw    $a0, %lo(seqp_1)($a0)
  lhu   $v0, 0x1e($sp)
  li    $at, 65535
  lui   $t7, %hi(musicTrack1_length) 
  bne   $v0, $at, .L700071B4
   nop   
  lhu   $t7, %lo(musicTrack1_length)($t7)
  lui   $at, %hi(music1_length)
  b     .L700071BC
   sh    $t7, %lo(music1_length)($at)
.L700071B4:
  lui   $at, %hi(music1_length)
  sh    $v0, %lo(music1_length)($at)
.L700071BC:
  lui   $at, %hi(musicTrack1_length)
  sh    $zero, %lo(musicTrack1_length)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($sp)
  lui   $at, %hi(music1_rate)
  li    $t0, 1
  mul.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sw    $t9, %lo(music1_rate)($at)
  lui   $at, %hi(music1_playing)
  sw    $t0, %lo(music1_playing)($at)
.L700071F4:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel musicTrack2Play
  lui   $t6, %hi(bootswitch_sound) 
  lb    $t6, %lo(bootswitch_sound)($t6)
  addiu $sp, $sp, -0x2148
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  bnez  $t6, .L70007344
   sw    $a0, 0x2148($sp)
  lui   $t7, %hi(music2_track_num) 
  lw    $t7, %lo(music2_track_num)($t7)
  beql  $t7, $zero, .L7000723C
   lw    $t8, 0x2148($sp)
  jal   musicTrack2Stop
   nop   
  lw    $t8, 0x2148($sp)
.L7000723C:
  lui   $s0, %hi(seqp_2)
  lui   $at, %hi(music2_track_num)
  addiu $s0, %lo(seqp_2) # addiu $s0, $s0, 0x372c
  sw    $t8, %lo(music2_track_num)($at)
  jal   alCSPGetState
   lw    $a0, ($s0)
  beqz  $v0, .L7000726C
   nop   
.L7000725C:
  jal   alCSPGetState
   lw    $a0, ($s0)
  bnez  $v0, .L7000725C
   nop   
.L7000726C:
  lui   $a3, %hi(music2_track_num)
  lw    $a3, %lo(music2_track_num)($a3)
  lui   $t9, %hi(ptr_musicdatatable) 
  lw    $t9, %lo(ptr_musicdatatable)($t9)
  sll   $t1, $a3, 3
  lui   $at, 1
  addu  $t2, $t9, $t1
  lw    $a1, 4($t2)
  lui   $v1, %hi(D_80063738)
  sll   $v0, $a3, 1
  sltu  $at, $a1, $at
  beqz  $at, .L700072B0
   addu  $v1, $v1, $v0
  jal   musicTrack2Play
   li    $a0, 1
  b     .L70007348
   lw    $ra, 0x1c($sp)
.L700072B0:
  lhu   $v1, %lo(D_80063738)($v1)
  lui   $a2, %hi(D_800637B8)
  addu  $a2, $a2, $v0
  lhu   $a2, %lo(D_800637B8)($a2)
  lui   $t0, %hi(D_8006383C) 
  addiu $v1, $v1, 0xf
  lw    $t0, %lo(D_8006383C)($t0)
  ori   $t3, $v1, 0xf
  xori  $t4, $t3, 0xf
  addiu $a2, $a2, 0xf
  addiu $v1, $t4, 0x40
  ori   $t5, $a2, 0xf
  xori  $a2, $t5, 0xf
  addu  $t7, $t0, $v1
  subu  $a0, $t7, $a2
  sw    $a0, 0x28($sp)
  jal   romCopy
   sw    $t0, 0x2140($sp)
  lw    $a0, 0x28($sp)
  lw    $a1, 0x2140($sp)
  jal   decompressdata
   addiu $a2, $sp, 0x34
  lui   $a0, %hi(D_80063958)
  lui   $a1, %hi(D_8006383C)
  lw    $a1, %lo(D_8006383C)($a1)
  jal   alCSeqNew
   addiu $a0, %lo(D_80063958) # addiu $a0, $a0, 0x3958
  lui   $a1, %hi(D_80063958)
  addiu $a1, %lo(D_80063958) # addiu $a1, $a1, 0x3958
  jal   alCSPSetSeq
   lw    $a0, ($s0)
  jal   musicTrack2Length
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  jal   alCSPPlay
   lw    $a0, ($s0)
.L70007344:
  lw    $ra, 0x1c($sp)
.L70007348:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x2148
  jr    $ra
   nop   
");

void musicTrack2Stop(void) {
  if (bootswitch_sound == 0) {
    music2_playing = 0;
    if (music2_track_num != 0)
      if (alCSPGetState(seqp_2) == 1)
        alCSPStop(seqp_2);
    music2_track_num = 0;
  }
}

unsigned short musicTrack2Length(void) { return music2len; }

asm(R"
glabel musicTrack2Vol
  lui   $t6, %hi(music2_track_num) 
  lw    $t6, %lo(music2_track_num)($t6)
  lui   $t8, %hi(music_tempo_array)
  andi  $a2, $a0, 0xffff
  sll   $t7, $t6, 1
  addu  $t8, $t8, $t7
  lh    $t8, %lo(music_tempo_array)($t8)
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  multu $a2, $t8
  sw    $ra, 0x14($sp)
  lui   $at, %hi(music2len)
  lui   $a0, %hi(seqp_2)
  sh    $a2, %lo(music2len)($at)
  lw    $a0, %lo(seqp_2)($a0)
  mflo  $v0
  srl   $t9, $v0, 0xf
  sll   $a1, $t9, 0x10
  sra   $t0, $a1, 0x10
  jal   alCSPSetVol
   move  $a1, $t0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel musicTrack2Tempo
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   musicTrack2Length
   nop   
  lui   $t6, %hi(music2_track_num) 
  lw    $t6, %lo(music2_track_num)($t6)
  lui   $a0, %hi(music_tempo_array)
  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
  sll   $t7, $t6, 1
  addu  $t8, $a0, $t7
  sh    $v0, ($t8)
  lh    $t9, ($a0)
  lui   $v0, %hi(music_tempo_array)
  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
  bltz  $t9, .L70007478
   lw    $ra, 0x14($sp)
  lh    $t0, 2($v0)
.L7000746C:
  addiu $v0, $v0, 2
  bgezl $t0, .L7000746C
   lh    $t0, 2($v0)
.L70007478:
  jr    $ra
   addiu $sp, $sp, 0x18
");

void music_related_6(float arg0) {
  if (music2_playing >= 0) {
    D_80063846 = musicTrack2Length();
    music2_length = 0;
    music2_rate = arg0 * 60.0f;
    music2_playing = -1;
  }
}

asm(R"
glabel music_related_8
  lui   $t6, %hi(music2_playing) 
  lw    $t6, %lo(music2_playing)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  bgtz  $t6, .L7000757C
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(seqp_2)
  jal   alCSPPlay
   lw    $a0, %lo(seqp_2)($a0)
  lhu   $v0, 0x1e($sp)
  li    $at, 65535
  lui   $t7, %hi(D_80063846) 
  bne   $v0, $at, .L7000753C
   nop   
  lhu   $t7, %lo(D_80063846)($t7)
  lui   $at, %hi(music2_length)
  b     .L70007544
   sh    $t7, %lo(music2_length)($at)
.L7000753C:
  lui   $at, %hi(music2_length)
  sh    $v0, %lo(music2_length)($at)
.L70007544:
  lui   $at, %hi(D_80063846)
  sh    $zero, %lo(D_80063846)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($sp)
  lui   $at, %hi(music2_rate)
  li    $t0, 1
  mul.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sw    $t9, %lo(music2_rate)($at)
  lui   $at, %hi(music2_playing)
  sw    $t0, %lo(music2_playing)($at)
.L7000757C:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel music_related_3rd_block
  lui   $t6, %hi(bootswitch_sound) 
  lb    $t6, %lo(bootswitch_sound)($t6)
  addiu $sp, $sp, -0x2148
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  bnez  $t6, .L700076CC
   sw    $a0, 0x2148($sp)
  lui   $t7, %hi(music3_track_num) 
  lw    $t7, %lo(music3_track_num)($t7)
  beql  $t7, $zero, .L700075C4
   lw    $t8, 0x2148($sp)
  jal   musicTrack3Stop
   nop   
  lw    $t8, 0x2148($sp)
.L700075C4:
  lui   $s0, %hi(seqp_3)
  lui   $at, %hi(music3_track_num)
  addiu $s0, %lo(seqp_3) # addiu $s0, $s0, 0x3730
  sw    $t8, %lo(music3_track_num)($at)
  jal   alCSPGetState
   lw    $a0, ($s0)
  beqz  $v0, .L700075F4
   nop   
.L700075E4:
  jal   alCSPGetState
   lw    $a0, ($s0)
  bnez  $v0, .L700075E4
   nop   
.L700075F4:
  lui   $a3, %hi(music3_track_num)
  lw    $a3, %lo(music3_track_num)($a3)
  lui   $t9, %hi(ptr_musicdatatable) 
  lw    $t9, %lo(ptr_musicdatatable)($t9)
  sll   $t1, $a3, 3
  lui   $at, 1
  addu  $t2, $t9, $t1
  lw    $a1, 4($t2)
  lui   $v1, %hi(D_80063738)
  sll   $v0, $a3, 1
  sltu  $at, $a1, $at
  beqz  $at, .L70007638
   addu  $v1, $v1, $v0
  jal   music_related_3rd_block
   li    $a0, 1
  b     .L700076D0
   lw    $ra, 0x1c($sp)
.L70007638:
  lhu   $v1, %lo(D_80063738)($v1)
  lui   $a2, %hi(D_800637B8)
  addu  $a2, $a2, $v0
  lhu   $a2, %lo(D_800637B8)($a2)
  lui   $t0, %hi(D_80063840)
  addiu $v1, $v1, 0xf
  lw    $t0, %lo(D_80063840)($t0)
  ori   $t3, $v1, 0xf
  xori  $t4, $t3, 0xf
  addiu $a2, $a2, 0xf
  addiu $v1, $t4, 0x40
  ori   $t5, $a2, 0xf
  xori  $a2, $t5, 0xf
  addu  $t7, $t0, $v1
  subu  $a0, $t7, $a2
  sw    $a0, 0x28($sp)
  jal   romCopy
   sw    $t0, 0x2140($sp)
  lw    $a0, 0x28($sp)
  lw    $a1, 0x2140($sp)
  jal   decompressdata
   addiu $a2, $sp, 0x34
  lui   $a0, %hi(D_80063A50)
  lui   $a1, %hi(D_80063840)
  lw    $a1, %lo(D_80063840)($a1)
  jal   alCSeqNew
   addiu $a0, %lo(D_80063A50) # addiu $a0, $a0, 0x3a50
  lui   $a1, %hi(D_80063A50)
  addiu $a1, %lo(D_80063A50) # addiu $a1, $a1, 0x3a50
  jal   alCSPSetSeq
   lw    $a0, ($s0)
  jal   get_music3len
   nop   
  jal   musicTrack3Vol
   andi  $a0, $v0, 0xffff
  jal   alCSPPlay
   lw    $a0, ($s0)
.L700076CC:
  lw    $ra, 0x1c($sp)
.L700076D0:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x2148
  jr    $ra
   nop   
");

void musicTrack3Stop(void) {
  if (bootswitch_sound == 0) {
    music3_playing = 0;
    if (music3_track_num != 0)
      if (alCSPGetState(seqp_3) == 1)
        alCSPStop(seqp_3);
    music3_track_num = 0;
  }
}

unsigned short get_music3len(void) { return music3len; }

asm(R"
glabel musicTrack3Vol
  lui   $t6, %hi(music3_track_num) 
  lw    $t6, %lo(music3_track_num)($t6)
  lui   $t8, %hi(music_tempo_array)
  andi  $a2, $a0, 0xffff
  sll   $t7, $t6, 1
  addu  $t8, $t8, $t7
  lh    $t8, %lo(music_tempo_array)($t8)
  addiu $sp, $sp, -0x18
  sw    $a0, 0x18($sp)
  multu $a2, $t8
  sw    $ra, 0x14($sp)
  lui   $at, %hi(music3len)
  lui   $a0, %hi(seqp_3)
  sh    $a2, %lo(music3len)($at)
  lw    $a0, %lo(seqp_3)($a0)
  mflo  $v0
  srl   $t9, $v0, 0xf
  sll   $a1, $t9, 0x10
  sra   $t0, $a1, 0x10
  jal   alCSPSetVol
   move  $a1, $t0
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel music_related_10
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   get_music3len
   nop   
  lui   $t6, %hi(music3_track_num) 
  lw    $t6, %lo(music3_track_num)($t6)
  lui   $a0, %hi(music_tempo_array)
  addiu $a0, %lo(music_tempo_array) # addiu $a0, $a0, 0x4358
  sll   $t7, $t6, 1
  addu  $t8, $a0, $t7
  sh    $v0, ($t8)
  lh    $t9, ($a0)
  lui   $v0, %hi(music_tempo_array)
  addiu $v0, %lo(music_tempo_array) # addiu $v0, $v0, 0x4358
  bltz  $t9, .L70007800
   lw    $ra, 0x14($sp)
  lh    $t0, 2($v0)
.L700077F4:
  addiu $v0, $v0, 2
  bgezl $t0, .L700077F4
   lh    $t0, 2($v0)
.L70007800:
  jr    $ra
   addiu $sp, $sp, 0x18
");

asm(R"
glabel music_related_11
  lui   $t6, %hi(music3_playing) 
  lw    $t6, %lo(music3_playing)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bltz  $t6, .L70007868
   swc1  $f12, 0x18($sp)
  jal   get_music3len
   nop   
  lui   $at, %hi(D_80063848)
  sh    $v0, %lo(D_80063848)($at)
  lui   $at, %hi(music3_length)
  sh    $zero, %lo(music3_length)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($sp)
  lui   $at, %hi(music3_rate)
  li    $t9, -1
  mul.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t8, $f10
  nop   
  sw    $t8, %lo(music3_rate)($at)
  lui   $at, %hi(music3_playing)
  sw    $t9, %lo(music3_playing)($at)
.L70007868:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel music_related_13
  lui   $t6, %hi(music3_playing) 
  lw    $t6, %lo(music3_playing)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  swc1  $f12, 0x18($sp)
  bgtz  $t6, .L70007904
   sw    $a1, 0x1c($sp)
  lui   $a0, %hi(seqp_3)
  jal   alCSPPlay
   lw    $a0, %lo(seqp_3)($a0)
  lhu   $v0, 0x1e($sp)
  li    $at, 65535
  lui   $t7, %hi(D_80063848) 
  bne   $v0, $at, .L700078C4
   nop   
  lhu   $t7, %lo(D_80063848)($t7)
  lui   $at, %hi(music3_length)
  b     .L700078CC
   sh    $t7, %lo(music3_length)($at)
.L700078C4:
  lui   $at, %hi(music3_length)
  sh    $v0, %lo(music3_length)($at)
.L700078CC:
  lui   $at, %hi(D_80063848)
  sh    $zero, %lo(D_80063848)($at)
  li    $at, 0x42700000 # 60.000000
  mtc1  $at, $f6
  lwc1  $f4, 0x18($sp)
  lui   $at, %hi(music3_rate)
  li    $t0, 1
  mul.s $f8, $f4, $f6
  trunc.w.s $f10, $f8
  mfc1  $t9, $f10
  nop   
  sw    $t9, %lo(music3_rate)($at)
  lui   $at, %hi(music3_playing)
  sw    $t0, %lo(music3_playing)($at)
.L70007904:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

asm(R"
glabel music_related_15
  lui   $t6, %hi(music1_playing) 
  lw    $t6, %lo(music1_playing)($t6)
  addiu $sp, $sp, -0x30
  sw    $ra, 0x14($sp)
  beqz  $t6, .L700079C0
   nop   
  jal   musicTrack1Length
   nop   
  lui   $a2, %hi(music1_rate)
  lui   $t7, %hi(music1_length) 
  lhu   $t7, %lo(music1_length)($t7)
  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
  lw    $t8, ($a2)
  subu  $a1, $t7, $v0
  mtc1  $a1, $f4
  mtc1  $t8, $f8
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  div.s $f16, $f6, $f10
  trunc.w.s $f18, $f16
  mfc1  $t0, $f18
  nop   
  addu  $a0, $v0, $t0
  andi  $t1, $a0, 0xffff
  move  $a0, $t1
  jal   musicTrack1Vol
   sh    $t1, 0x2e($sp)
  lui   $a2, %hi(music1_rate)
  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
  lw    $t2, ($a2)
  lhu   $a0, 0x2e($sp)
  addiu $t3, $t2, -1
  bgtz  $t3, .L700079C0
   sw    $t3, ($a2)
  bnez  $a0, .L700079B4
   lui   $a0, %hi(seqp_1)
  jal   alCSPStop
   lw    $a0, %lo(seqp_1)($a0)
  lui   $a2, %hi(music1_rate)
  addiu $a2, %lo(music1_rate) # addiu $a2, $a2, 0x3850
.L700079B4:
  sw    $zero, ($a2)
  lui   $at, %hi(music1_playing)
  sw    $zero, %lo(music1_playing)($at)
.L700079C0:
  lui   $t5, %hi(music2_playing) 
  lw    $t5, %lo(music2_playing)($t5)
  beqz  $t5, .L70007A64
   nop   
  jal   musicTrack2Length
   nop   
  lui   $a2, %hi(music2_rate)
  lui   $t6, %hi(music2_length) 
  lhu   $t6, %lo(music2_length)($t6)
  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
  lw    $t7, ($a2)
  subu  $a1, $t6, $v0
  mtc1  $a1, $f4
  mtc1  $t7, $f6
  cvt.s.w $f8, $f4
  cvt.s.w $f10, $f6
  div.s $f16, $f8, $f10
  trunc.w.s $f18, $f16
  mfc1  $t9, $f18
  nop   
  addu  $a0, $v0, $t9
  andi  $t0, $a0, 0xffff
  move  $a0, $t0
  jal   musicTrack2Vol
   sh    $t0, 0x26($sp)
  lui   $a2, %hi(music2_rate)
  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
  lw    $t1, ($a2)
  lhu   $a0, 0x26($sp)
  addiu $t2, $t1, -1
  bgtz  $t2, .L70007A64
   sw    $t2, ($a2)
  bnez  $a0, .L70007A58
   lui   $a0, %hi(seqp_2)
  jal   alCSPStop
   lw    $a0, %lo(seqp_2)($a0)
  lui   $a2, %hi(music2_rate)
  addiu $a2, %lo(music2_rate) # addiu $a2, $a2, 0x3854
.L70007A58:
  sw    $zero, ($a2)
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
.L70007A64:
  lui   $t4, %hi(music3_playing) 
  lw    $t4, %lo(music3_playing)($t4)
  beql  $t4, $zero, .L70007B0C
   lw    $ra, 0x14($sp)
  jal   get_music3len
   nop   
  lui   $a2, %hi(music3_rate)
  lui   $t5, %hi(music3_length) 
  lhu   $t5, %lo(music3_length)($t5)
  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
  lw    $t6, ($a2)
  subu  $a1, $t5, $v0
  mtc1  $a1, $f4
  mtc1  $t6, $f8
  cvt.s.w $f6, $f4
  cvt.s.w $f10, $f8
  div.s $f16, $f6, $f10
  trunc.w.s $f18, $f16
  mfc1  $t8, $f18
  nop   
  addu  $a0, $v0, $t8
  andi  $t9, $a0, 0xffff
  move  $a0, $t9
  jal   musicTrack3Vol
   sh    $t9, 0x1e($sp)
  lui   $a2, %hi(music3_rate)
  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
  lw    $t0, ($a2)
  lhu   $a0, 0x1e($sp)
  addiu $t1, $t0, -1
  bgtz  $t1, .L70007B08
   sw    $t1, ($a2)
  bnez  $a0, .L70007AFC
   lui   $a0, %hi(seqp_3)
  jal   alCSPStop
   lw    $a0, %lo(seqp_3)($a0)
  lui   $a2, %hi(music3_rate)
  addiu $a2, %lo(music3_rate) # addiu $a2, $a2, 0x3858
.L70007AFC:
  sw    $zero, ($a2)
  lui   $at, %hi(music3_playing)
  sw    $zero, %lo(music3_playing)($at)
.L70007B08:
  lw    $ra, 0x14($sp)
.L70007B0C:
  addiu $sp, $sp, 0x30
  jr    $ra
   nop
");
