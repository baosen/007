unsigned long long game_random_seed = 0xAB8D9F7781280783;

asm(R"
glabel get_rand_val
  lui   $a0, %hi(game_random_seed)
  ld    $a0, %lo(game_random_seed)($a0)
  lui   $at, %hi(game_random_seed)
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
  sd    $a0, %lo(game_random_seed)($at)
  jr    $ra
  dsra32 $v0, $v0, 0
");

asm(R"
glabel set_rand_val
  daddiu $a0, $a0, 1
  lui   $at, %hi(game_random_seed)
  sd    $a0, %lo(game_random_seed)($at)
  jr    $ra
  li    $a0, 0
");
