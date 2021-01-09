unsigned long long randseed = 0xAB8D9F7781280783;

asm(R"
glabel get_random_value
  lui   $a0, %hi(randseed)
  ld    $a0, %lo(randseed)($a0)
  lui   $at, %hi(randseed)
  dsll32 $a2, $a0, 0x1f
  dsll  $a1, $a0, 0x1f
  dsrl  $a2, $a2, 0x1f
  dsrl32 $a1, $a1, 0
  dsll32 $a0, $a0, 0xc
  or    $a2, $a2, $a1
  dsrl32 $a0, $a0, 0
  xor   $a2, $a2, $a0
  dsrl  $a0, $a2, 0x14
  andi  $a0, $a0, 0xfff
  xor   $a0, $a0, $a2
  dsll32 $v0, $a0, 0
  sd    $a0, %lo(randseed)($at)
  jr    $ra
  dsra32 $v0, $v0, 0
");

asm(R"
glabel increment_random_num
  daddiu $a0, $a0, 1
  lui   $at, %hi(randseed)
  sd    $a0, %lo(randseed)($at)
  jr    $ra
  li    $a0, 0
");

asm(R"
glabel lotsa_shifting_randomizer_related
  ld    $a3, ($a0)
  dsll32 $a2, $a3, 0x1f
  dsll  $a1, $a3, 0x1f
  dsrl  $a2, $a2, 0x1f
  dsrl32 $a1, $a1, 0
  dsll32 $a3, $a3, 0xc
  or    $a2, $a2, $a1
  dsrl32 $a3, $a3, 0
  xor   $a2, $a2, $a3
  dsrl  $a3, $a2, 0x14
  andi  $a3, $a3, 0xfff
  xor   $a3, $a3, $a2
  dsll32 $v0, $a3, 0
  sd    $a3, ($a0)
  jr    $ra
  dsra32 $v0, $v0, 0
");
