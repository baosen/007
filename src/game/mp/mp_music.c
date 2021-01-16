int dword_CODE_bss_8008C600;
int dword_CODE_bss_8008C604;

int *music_slot_active_0;
int *music_slot_active_1;
int *music_slot_active_2;
int *music_slot_active_3;
int *music_slot_minutes_0;
int *music_slot_minutes_1;
int *music_slot_minutes_2;
int *music_slot_minutes_3;
int *music_slot_seconds_0;
int *music_slot_seconds_1;
int *music_slot_seconds_2;
int *music_slot_seconds_3;

int mission_state = 0;

void sub_GAME_7F0C0C10(void) { call_sfx_c_700091C8(); }

int get_mission_state(void) { return mission_state; }

#ifdef VERSION_US
asm(R"
.late_rodata
/*D:8005B790*/
glabel jpt_8005B790
.word .L7F0C0C74
.word .L7F0C0D28
.word .L7F0C0E18
.word .L7F0C0EB0
.word .L7F0C0FE8
.word .L7F0C10B4
.word .L7F0C115C

/*D:8005B7AC*/
glabel jpt_8005B7AC
.word .L7F0C11EC
.word .L7F0C0C94
.word .L7F0C0D28
.word .L7F0C0D28
.word .L7F0C0CC8
.word .L7F0C0D28
.word .L7F0C0D28

/*D:8005B7C8*/
glabel jpt_8005B7C8
.word .L7F0C0D48
.word .L7F0C0E18
.word .L7F0C0D68
.word .L7F0C0DAC
.word .L7F0C0E18
.word .L7F0C0E18
.word .L7F0C0DE4

glabel music_rate_8005B7E4
.word 0x3ca3d70a /*0.02*/

/*D:8005B7E8*/
glabel jpt_8005B7E8
.word .L7F0C0E38
.word .L7F0C0E58
.word .L7F0C11EC
.word .L7F0C0E88
.word .L7F0C0EB0
.word .L7F0C0EB0
.word .L7F0C0EB0

/*D:8005B804*/
glabel jpt_8005B804
.word .L7F0C0ED0
.word .L7F0C0EF0
.word .L7F0C0F20
.word .L7F0C0FE8
.word .L7F0C0F54
.word .L7F0C0F9C
.word .L7F0C0FE8

/*D:8005B820*/
glabel jpt_8005B820
.word .L7F0C1008
.word .L7F0C10B4
.word .L7F0C10B4
.word .L7F0C1028
.word .L7F0C10B4
.word .L7F0C1070
.word .L7F0C10B4

/*D:8005B83C*/
glabel jpt_8005B83C
.word .L7F0C10D4
.word .L7F0C115C
.word .L7F0C115C
.word .L7F0C10F4
.word .L7F0C112C
.word .L7F0C115C
.word .L7F0C115C

/*D:8005B858*/
glabel jpt_8005B858
.word .L7F0C117C
.word .L7F0C119C
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11E4
.word .L7F0C11CC


.text
glabel set_missionstate
/* 0F576C set_missionstate 3C038005 */  lui   $v1, %hi(mission_state)
  addiu $v1, %lo(mission_state) # addiu $v1, $v1, -0x7b40
  lw    $v0, ($v1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sltiu $at, $v0, 7
  beqz  $at, .L7F0C11E4
   sw    $a0, ($v1)
  sll   $t6, $v0, 2
  lui   $at, %hi(jpt_8005B790)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005B790)($at)
  jr    $t6
   nop   
.L7F0C0C74:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C0D28
   sll   $t7, $a0, 2
  lui   $at, %hi(jpt_8005B7AC)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_8005B7AC)($at)
  jr    $t7
   nop   
.L7F0C0C94:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music1_playing)($at)
  jal   getmusictrack_or_randomtrack
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack1Play
   move  $a0, $v0
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0CC8:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music1_playing)($at)
  jal   getmusictrack_or_randomtrack
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack1Play
   move  $a0, $v0
  jal   sub_GAME_7F0C0C10
   nop   
  jal   musicTrack3Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music3_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music3_playing)($at)
  jal   sub_GAME_7F0D2848
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   music_related_3rd_block
   move  $a0, $v0
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0D28:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C0E18
   sll   $t8, $a0, 2
  lui   $at, %hi(jpt_8005B7C8)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8005B7C8)($at)
  jr    $t8
   nop   
.L7F0C0D48:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0D68:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0DAC:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0DE4:
  lui   $at, %hi(music_rate_8005B7E4)
  jal   music_related_1
   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 58
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0E18:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C0EB0
   sll   $t9, $a0, 2
  lui   $at, %hi(jpt_8005B7E8)
  addu  $at, $at, $t9
  lw    $t9, %lo(jpt_8005B7E8)($at)
  jr    $t9
   nop   
.L7F0C0E38:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0E58:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0E88:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0EB0:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C0FE8
   sll   $t0, $a0, 2
  lui   $at, %hi(jpt_8005B804)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_8005B804)($at)
  jr    $t0
   nop   
.L7F0C0ED0:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0EF0:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0F20:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0F54:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  jal   sub_GAME_7F0C0C10
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_13
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0F9C:
  jal   sub_GAME_7F0C0C10
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_13
   andi  $a1, $v0, 0xffff
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C0FE8:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C10B4
   sll   $t1, $a0, 2
  lui   $at, %hi(jpt_8005B820)
  addu  $at, $at, $t1
  lw    $t1, %lo(jpt_8005B820)($at)
  jr    $t1
   nop   
.L7F0C1008:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C1028:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_11
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C1070:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  lui   $a0, %hi(dword_CODE_bss_8008C600)
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C10B4:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C115C
   sll   $t2, $a0, 2
  lui   $at, %hi(jpt_8005B83C)
  addu  $at, $at, $t2
  lw    $t2, %lo(jpt_8005B83C)($at)
  jr    $t2
   nop   
.L7F0C10D4:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C10F4:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_11
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C112C:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C115C:
  sltiu $at, $a0, 7
  beqz  $at, .L7F0C11E4
   sll   $t3, $a0, 2
  lui   $at, %hi(jpt_8005B858)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_8005B858)($at)
  jr    $t3
   nop   
.L7F0C117C:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C119C:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C11CC:
  lui   $at, %hi(music2_playing)
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 58
  b     .L7F0C11F0
   lw    $ra, 0x14($sp)
.L7F0C11E4:
  b     .L7F0C11E4
   nop   
.L7F0C11EC:
  lw    $ra, 0x14($sp)
.L7F0C11F0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
    .late_rodata
/*D:8005B790*/
glabel jpt_8005B790
.word .Ljp7F0C1904
.word .Ljp7F0C19D8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1B60
.word .Ljp7F0C1C98
.word .Ljp7F0C1D64
.word .Ljp7F0C1E0C

/*D:8005B7AC*/
glabel jpt_8005B7AC
.word .Ljp7F0C1924
.word .Ljp7F0C1944
.word .Ljp7F0C19D8
.word .Ljp7F0C19D8
.word .Ljp7F0C1978
.word .Ljp7F0C19D8
.word .Ljp7F0C19D8


/*D:8005B7C8*/
glabel jpt_8005B7C8
.word .Ljp7F0C19F8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1A18
.word .Ljp7F0C1A5C
.word .Ljp7F0C1AC8
.word .Ljp7F0C1AC8
.word .Ljp7F0C1A94

glabel music_rate_8005B7E4
.word 0x3ca3d70a /*0.02*/

/*D:8005B7E8*/
glabel jpt_8005B7E8
.word .Ljp7F0C1AE8
.word .Ljp7F0C1B08
.word .Ljp7F0C1E9C
.word .Ljp7F0C1B38
.word .Ljp7F0C1B60
.word .Ljp7F0C1B60
.word .Ljp7F0C1B60

/*D:8005B804*/
glabel jpt_8005B804
.word .Ljp7F0C1B80
.word .Ljp7F0C1BA0
.word .Ljp7F0C1BD0
.word .Ljp7F0C1C98
.word .Ljp7F0C1C04
.word .Ljp7F0C1C4C
.word .Ljp7F0C1C98

/*D:8005B820*/
glabel jpt_8005B820
.word .Ljp7F0C1CB8
.word .Ljp7F0C1D64
.word .Ljp7F0C1D64
.word .Ljp7F0C1CD8
.word .Ljp7F0C1D64
.word .Ljp7F0C1D20
.word .Ljp7F0C1D64

/*D:8005B83C*/
glabel jpt_8005B83C
.word .Ljp7F0C1D84
.word .Ljp7F0C1E0C
.word .Ljp7F0C1E0C
.word .Ljp7F0C1DA4
.word .Ljp7F0C1DDC
.word .Ljp7F0C1E0C
.word .Ljp7F0C1E0C

/*D:8005B858*/
glabel jpt_8005B858
.word .Ljp7F0C1E2C
.word .Ljp7F0C1E4C
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E94
.word .Ljp7F0C1E7C

.text
glabel set_missionstate
  lui   $v1, %hi(mission_state) # $v1, 0x8005
  addiu $v1, %lo(mission_state) # addiu $v1, $v1, -0x7b10
  lw    $v0, ($v1)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sltiu $at, $v0, 7
  beqz  $at, .Ljp7F0C1E94
   sw    $a0, ($v1)
  sll   $t6, $v0, 2
  lui   $at, %hi(jpt_8005B790)
  addu  $at, $at, $t6
  lw    $t6, %lo(jpt_8005B790)($at)
  jr    $t6
   nop   
.Ljp7F0C1904:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C19D8
   sll   $t7, $a0, 2
  lui   $at, %hi(jpt_8005B7AC)
  addu  $at, $at, $t7
  lw    $t7, %lo(jpt_8005B7AC)($at)
  jr    $t7
   nop   
.Ljp7F0C1924:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1944:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music1_playing)($at)
  jal   getmusictrack_or_randomtrack
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack1Play
   move  $a0, $v0
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1978:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack1Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music1_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music1_playing)($at)
  jal   getmusictrack_or_randomtrack
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack1Play
   move  $a0, $v0
  jal   sub_GAME_7F0C0C10
   nop   
  jal   musicTrack3Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music3_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music3_playing)($at)
  jal   sub_GAME_7F0D2848
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   music_related_3rd_block
   move  $a0, $v0
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C19D8:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1AC8
   sll   $t8, $a0, 2
  lui   $at, %hi(jpt_8005B7C8)
  addu  $at, $at, $t8
  lw    $t8, %lo(jpt_8005B7C8)($at)
  jr    $t8
   nop   
.Ljp7F0C19F8:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1A18:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1A5C:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1A94:
  lui   $at, %hi(music_rate_8005B7E4) # $at, 0x8006
  jal   music_related_1
   lwc1  $f12, %lo(music_rate_8005B7E4)($at)
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 58
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1AC8:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1B60
   sll   $t9, $a0, 2
  lui   $at, 0x8006
  addu  $at, $at, $t9
  lw    $t9, -0x47d8($at)
  jr    $t9
   nop   
.Ljp7F0C1AE8:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1B08:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1B38:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1B60:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1C98
   sll   $t0, $a0, 2
  lui   $at, %hi(jpt_8005B804)
  addu  $at, $at, $t0
  lw    $t0, %lo(jpt_8005B804)($at)
  jr    $t0
   nop   
.Ljp7F0C1B80:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1BA0:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1BD0:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1C04:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  jal   sub_GAME_7F0C0C10
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_13
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1C4C:
  jal   sub_GAME_7F0C0C10
   nop   
  li    $at, 0x3F800000 # 1.000000
  mtc1  $at, $f12
  jal   music_related_13
   andi  $a1, $v0, 0xffff
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1C98:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1D64
   sll   $t1, $a0, 2
  lui   $at, 0x8006
  addu  $at, $at, $t1
  lw    $t1, -0x47a0($at)
  jr    $t1
   nop   
.Ljp7F0C1CB8:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1CD8:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_11
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1D20:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  lui   $a0, %hi(dword_CODE_bss_8008C600) # $a0, 0x8009
  sw    $zero, %lo(music2_playing)($at)
  jal   sub_GAME_7F0D2890
   lw    $a0, %lo(dword_CODE_bss_8008C600)($a0)
  jal   musicTrack2Play
   move  $a0, $v0
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_1
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1D64:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1E0C
   sll   $t2, $a0, 2
  lui   $at, %hi(jpt_8005B83C)
  addu  $at, $at, $t2
  lw    $t2, %lo(jpt_8005B83C)($at)
  jr    $t2
   nop   
.Ljp7F0C1D84:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1DA4:
  jal   sub_GAME_7F0C0BF0
   nop   
  jal   musicTrack2Vol
   andi  $a0, $v0, 0xffff
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 24
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_11
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1DDC:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x3F000000 # 0.500000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1E0C:
  sltiu $at, $a0, 7
  beqz  $at, .Ljp7F0C1E94
   sll   $t3, $a0, 2
  lui   $at, %hi(jpt_8005B858)
  addu  $at, $at, $t3
  lw    $t3, %lo(jpt_8005B858)($at)
  jr    $t3
   nop   
.Ljp7F0C1E2C:
  jal   musicTrack1Stop
   nop   
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1E4C:
  jal   sub_GAME_7F0C0BF0
   nop   
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f12
  jal   music_related_3
   andi  $a1, $v0, 0xffff
  li    $at, 0x40000000 # 2.000000
  mtc1  $at, $f12
  jal   music_related_6
   nop   
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1E7C:
  lui   $at, %hi(music2_playing) # $at, 0x8002
  sw    $zero, %lo(music2_playing)($at)
  jal   musicTrack2Play
   li    $a0, 58
  b     .Ljp7F0C1EA0
   lw    $ra, 0x14($sp)
.Ljp7F0C1E94:
  b     .Ljp7F0C1E94
   nop   
.Ljp7F0C1E9C:
  lw    $ra, 0x14($sp)
.Ljp7F0C1EA0:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

asm(R"
glabel sub_GAME_7F0C11FC
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   musicTrack1Stop
   sw    $a0, 0x18($sp)
  jal   musicTrack2Stop
   nop   
  jal   musicTrack3Stop
   nop   
  lw    $a0, 0x18($sp)
  lui   $v0, %hi(dword_CODE_bss_8008C600)
  lui   $at, %hi(mission_state)
  addiu $v0, %lo(dword_CODE_bss_8008C600) # addiu $v0, $v0, -0x3a00
  sw    $zero, %lo(mission_state)($at)
  jal   sub_GAME_7F0D2848
   sw    $a0, ($v0)
  bgez  $v0, .L7F0C1250
   nop   
  jal   set_missionstate
   li    $a0, 1
  b     .L7F0C125C
   lw    $ra, 0x14($sp)
.L7F0C1250:
  jal   set_missionstate
   li    $a0, 4
  lw    $ra, 0x14($sp)
.L7F0C125C:
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");

void sub_GAME_7F0C1268(void) { set_missionstate(0); }

void sub_GAME_7F0C1288(void) {
  if (sub_GAME_7F0D2848(dword_CODE_bss_8008C600) < 0)
    set_missionstate(2);
  else
    set_missionstate(5);
}

void sub_GAME_7F0C12CC(void) {
  if (sub_GAME_7F0D2848(dword_CODE_bss_8008C600) < 0)
    set_missionstate(1);
  else
    set_missionstate(4);
}

void sub_GAME_7F0C1310(void) {
  dword_CODE_bss_8008C604 = mission_state;
  set_missionstate(3);
}

void sub_GAME_7F0C1340(void) { set_missionstate(dword_CODE_bss_8008C604); }

void sub_GAME_7F0C1364(void) {
  music_slot_active_0 = 0;
  music_slot_minutes_0 = 0;
  music_slot_seconds_0 = 0;
  music_slot_active_1 = 0;
  music_slot_minutes_1 = 0;
  music_slot_seconds_1 = 0;
  music_slot_active_2 = 0;
  music_slot_minutes_2 = 0;
  music_slot_seconds_2 = 0;
  music_slot_active_3 = 0;
  music_slot_minutes_3 = 0;
  music_slot_seconds_3 = 0;
}

asm(R"
glabel reset_all_music_slots
  addiu $sp, $sp, -0x20
  lui   $a3, %hi(music_slot_active_0)
  lui   $a0, %hi(music_slot_minutes_0)
  lui   $a2, %hi(clock_timer)
  lui   $t1, %hi(music_slot_seconds_0) 
  sw    $ra, 0x14($sp)
  move  $t2, $zero
  addiu $t1, %lo(music_slot_seconds_0) # addiu $t1, $t1, -0x39d8
  lw    $a2, %lo(clock_timer)($a2)
  addiu $a0, %lo(music_slot_minutes_0) # addiu $a0, $a0, -0x39e8
  addiu $a3, %lo(music_slot_active_0) # addiu $a3, $a3, -0x39f8
  move  $t0, $zero
.L7F0C13F8:
  lw    $a1, ($a3)
  bnezl $a1, .L7F0C1414
   lw    $v0, ($a0)
  lw    $t6, ($a0)
  blezl $t6, .L7F0C1488
   addiu $a0, $a0, 4
  lw    $v0, ($a0)
.L7F0C1414:
  lui   $t7, %hi(music_slot_seconds_0) 
  addiu $t7, %lo(music_slot_seconds_0) # addiu $t7, $t7, -0x39d8
  slt   $at, $v0, $a2
  bnez  $at, .L7F0C1434
   addu  $v1, $t0, $t7
  subu  $t8, $v0, $a2
  b     .L7F0C1438
   sw    $t8, ($a0)
.L7F0C1434:
  sw    $zero, ($a0)
.L7F0C1438:
  lw    $v0, ($v1)
  beqz  $v0, .L7F0C1484
   slt   $at, $v0, $a2
  bnez  $at, .L7F0C1454
   subu  $t9, $v0, $a2
  b     .L7F0C1458
   sw    $t9, ($v1)
.L7F0C1454:
  sw    $zero, ($v1)
.L7F0C1458:
  lw    $t3, ($v1)
  beql  $t3, $zero, .L7F0C1484
   sw    $zero, ($a3)
  bnez  $a1, .L7F0C1478
   nop   
  lw    $t4, ($a0)
  beql  $t4, $zero, .L7F0C1488
   addiu $a0, $a0, 4
.L7F0C1478:
  b     .L7F0C1484
   li    $t2, 1
  sw    $zero, ($a3)
.L7F0C1484:
  addiu $a0, $a0, 4
.L7F0C1488:
  addiu $t0, $t0, 4
  bne   $a0, $t1, .L7F0C13F8
   addiu $a3, $a3, 4
  beql  $a2, $zero, .L7F0C14F0
   lw    $ra, 0x14($sp)
  jal   get_mission_state
   sw    $t2, 0x18($sp)
  li    $at, 2
  beq   $v0, $at, .L7F0C14C4
   lw    $t2, 0x18($sp)
  jal   get_mission_state
   sw    $t2, 0x18($sp)
  li    $at, 5
  bne   $v0, $at, .L7F0C14DC
   lw    $t2, 0x18($sp)
.L7F0C14C4:
  bnezl $t2, .L7F0C14F0
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0C12CC
   nop   
  b     .L7F0C14F0
   lw    $ra, 0x14($sp)
.L7F0C14DC:
  beql  $t2, $zero, .L7F0C14F0
   lw    $ra, 0x14($sp)
  jal   sub_GAME_7F0C1288
   nop   
  lw    $ra, 0x14($sp)
.L7F0C14F0:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");

asm(R"
glabel set_musicslot_time
  lui   $t6, %hi(music_slot_active_0) 
  addiu $t6, %lo(music_slot_active_0) # addiu $t6, $t6, -0x39f8
  sll   $v0, $a0, 2
  addu  $v1, $v0, $t6
  lw    $t7, ($v1)
  li    $a0, 60
  bnez  $t7, .L7F0C1550
   nop   
  multu $a1, $a0
  li    $t8, 1
  lui   $at, %hi(music_slot_minutes_0)
  sw    $t8, ($v1)
  addu  $at, $at, $v0
  mflo  $t9
  sw    $t9, %lo(music_slot_minutes_0)($at)
  lui   $at, %hi(music_slot_seconds_0)
  multu $a2, $a0
  addu  $at, $at, $v0
  mflo  $t0
  sw    $t0, %lo(music_slot_seconds_0)($at)
  nop   
.L7F0C1550:
  jr    $ra
   nop   
");

asm(R"
glabel reset_music_in_slot
  bltz  $a0, .L7F0C1574
   lui   $at, %hi(music_slot_active_0)
  sll   $t6, $a0, 2
  lui   $at, %hi(music_slot_active_0)
  addu  $at, $at, $t6
  jr    $ra
   sw    $zero, %lo(music_slot_active_0)($at)

.L7F0C1574:
  sw    $zero, %lo(music_slot_active_0)($at)
  lui   $at, %hi(music_slot_minutes_0)
  sw    $zero, %lo(music_slot_minutes_0)($at)
  lui   $at, %hi(music_slot_seconds_0)
  sw    $zero, %lo(music_slot_seconds_0)($at)
  lui   $at, %hi(music_slot_active_1)
  sw    $zero, %lo(music_slot_active_1)($at)
  lui   $at, %hi(music_slot_minutes_1)
  sw    $zero, %lo(music_slot_minutes_1)($at)
  lui   $at, %hi(music_slot_seconds_1)
  sw    $zero, %lo(music_slot_seconds_1)($at)
  lui   $at, %hi(music_slot_active_2)
  sw    $zero, %lo(music_slot_active_2)($at)
  lui   $at, %hi(music_slot_minutes_2)
  sw    $zero, %lo(music_slot_minutes_2)($at)
  lui   $at, %hi(music_slot_seconds_2)
  sw    $zero, %lo(music_slot_seconds_2)($at)
  lui   $at, %hi(music_slot_active_3)
  sw    $zero, %lo(music_slot_active_3)($at)
  lui   $at, %hi(music_slot_minutes_3)
  sw    $zero, %lo(music_slot_minutes_3)($at)
  lui   $at, %hi(music_slot_seconds_3)
  sw    $zero, %lo(music_slot_seconds_3)($at)
  jr    $ra
   nop   
");
