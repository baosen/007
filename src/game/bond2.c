#include "bondconstants.h"
#include "unk_093880.h"
#include <stddef.h>
#include <types.h>

typedef enum INV_ITEM_TYPE {
  INV_ITEM_WEAPON = 1,
  INV_ITEM_PROP,
  INV_ITEM_DUAL
} INV_ITEM_TYPE;

void reinit_BONDdata_inventory(void) {
  int i;
  for (i = 0; i < pPlayer->equipmaxitems; i++) {
    pPlayer->p_itemcur[i].type = -1;
  }
  pPlayer->ptr_inventory_first_in_cycle = NULL;
  pPlayer->textoverrides = NULL;
  pPlayer->equipcuritem = 0;
}

asm(R"
glabel sub_GAME_7F08C054
  addiu $sp, $sp, -8
  sw    $s0, 4($sp)
  lw    $a1, ($a0)
  li    $t3, 1
  li    $v0, -1
  bne   $t3, $a1, .L7F08C080
   li    $v1, -1
  lw    $v0, 4($a0)
  li    $s0, 2
  b     .L7F08C0A8
   li    $t5, 3
.L7F08C080:
  li    $t5, 3
  bne   $t5, $a1, .L7F08C09C
   li    $s0, 2
  lw    $v0, 4($a0)
  lw    $v1, 8($a0)
  b     .L7F08C0A8
   li    $s0, 2
.L7F08C09C:
  bne   $s0, $a1, .L7F08C0A8
   nop   
  li    $v0, 2000
.L7F08C0A8:
  lui   $t4, %hi(pPlayer) 
  addiu $t4, %lo(pPlayer) # addiu $t4, $t4, -0x5f50
  lw    $a3, ($t4)
  lw    $a2, 0xc($a0)
  lw    $t6, 0x11e0($a3)
  move  $a1, $a2
  beql  $a2, $t6, .L7F08C18C
   lw    $s0, 4($sp)
.L7F08C0C8:
  lw    $t2, ($a2)
  li    $t0, -1
  li    $t1, -1
  bne   $t3, $t2, .L7F08C0E4
   nop   
  b     .L7F08C104
   lw    $t0, 4($a2)
.L7F08C0E4:
  bne   $t5, $t2, .L7F08C0F8
   nop   
  lw    $t0, 4($a2)
  b     .L7F08C104
   lw    $t1, 8($a2)
.L7F08C0F8:
  bnel  $s0, $t2, .L7F08C108
   slt   $at, $t0, $v0
  li    $t0, 1000
.L7F08C104:
  slt   $at, $t0, $v0
.L7F08C108:
  bnezl $at, .L7F08C124
   lw    $a2, 0xc($a1)
  bne   $v0, $t0, .L7F08C188
   slt   $at, $t1, $v1
  beql  $at, $zero, .L7F08C18C
   lw    $s0, 4($sp)
  lw    $a2, 0xc($a1)
.L7F08C124:
  bnel  $a0, $a2, .L7F08C140
   lw    $t7, 0x10($a0)
  sw    $a1, 0x11e0($a3)
  lw    $a3, ($t4)
  b     .L7F08C17C
   lw    $t0, 0x11e0($a3)
  lw    $t7, 0x10($a0)
.L7F08C140:
  sw    $a2, 0xc($a0)
  sw    $t7, 0x10($a1)
  sw    $a1, 0x10($a0)
  sw    $a0, 0xc($a1)
  lw    $t8, 0xc($a0)
  sw    $a0, 0x10($t8)
  lw    $t9, 0x10($a1)
  sw    $a1, 0xc($t9)
  lw    $a3, ($t4)
  lw    $t0, 0x11e0($a3)
  bnel  $a0, $t0, .L7F08C180
   lw    $a2, 0xc($a0)
  sw    $a1, 0x11e0($a3)
  lw    $a3, ($t4)
  lw    $t0, 0x11e0($a3)
.L7F08C17C:
  lw    $a2, 0xc($a0)
.L7F08C180:
  bne   $a2, $t0, .L7F08C0C8
   move  $a1, $a2
.L7F08C188:
  lw    $s0, 4($sp)
.L7F08C18C:
  jr    $ra
   addiu $sp, $sp, 8
");

void add_additional_weapon_slot_to_player_inventory_guess(InvItem *item) {
  if (pPlayer->ptr_inventory_first_in_cycle) {
    item->next = pPlayer->ptr_inventory_first_in_cycle;
    item->prev = pPlayer->ptr_inventory_first_in_cycle->prev;
    item->next->prev = item;
    item->prev->next = item;
  } else {
    item->next = item;
    item->prev = item;
  }
  pPlayer->ptr_inventory_first_in_cycle = item;
  sub_GAME_7F08C054(item);
}

void reorder_inventory_ptrs_based_on_id_code(InvItem *item) {
  InvItem *prev, *next;

  next = item->next;
  prev = item->prev;

  if (item == pPlayer->ptr_inventory_first_in_cycle) {
    if (item == item->next) {
      pPlayer->ptr_inventory_first_in_cycle = NULL;
    } else {
      pPlayer->ptr_inventory_first_in_cycle = item->next;
    }
  }
  next->prev = prev;
  prev->next = next;
  item->type = -1;
}

InvItem *get_ptr_next_available_weapon(void) {
  int i;

  for (i = 0; i < pPlayer->equipmaxitems; i++) {
    if (pPlayer->p_itemcur[i].type == -1) {
      return &pPlayer->p_itemcur[i];
    }
  }

  return NULL;
}

void set_BONDdata_allguns_flag(int param_1) { pPlayer->equipallguns = param_1; }

int get_BONDdata_allguns_flag(void) { return pPlayer->equipallguns; }

InvItem *get_ptr_inventory_item(ITEM_IDS weapon) {
  InvItem *first = pPlayer->ptr_inventory_first_in_cycle;
  InvItem *item = first;

  while (item) {
    if (item->type == INV_ITEM_WEAPON &&
        item->type_inv_item.type_weap.weapon == weapon) {
      return item;
    }
    item = item->next;
    if (item == first) {
      break;
    }
  }

  return NULL;
}

/**
 * Is item in inventory
 * @param item: enum Item ID eg: ITEM_KNIFE
 * @return TRUE/FALSE
 */
int is_weapon_in_inv(ITEM_IDS item) {
  return get_ptr_inventory_item(item) != 0;
}

InvItem *get_ptr_inventory_for_item_in_hand(ITEM_IDS right, ITEM_IDS left) {

  InvItem *first = pPlayer->ptr_inventory_first_in_cycle;
  InvItem *item = first;

  while (item) {

    if (item->type == INV_ITEM_DUAL &&
        item->type_inv_item.type_dual.weapon_right == right &&
        item->type_inv_item.type_dual.weapon_left == left) {
      return item;
    }

    item = item->next;

    if (item == first) {
      break;
    }
  }

  return NULL;
}

/**
 * Is item for hand in inventory
 * @param item: enum Item ID eg: ITEM_KNIFE
 * @param hand: enum Hand ID eg: HAND_LEFT
 * @return TRUE/FALSE
 */
int is_item_for_hand_in_inventory(ITEM_IDS item, int hand) {
  return get_ptr_inventory_for_item_in_hand(item, hand) != 0;
}

int check_if_item_available(ITEM_IDS weaponid) {
  if (((pPlayer->equipallguns) && (weaponid != ITEM_UNARMED) &&
       (weaponid < ITEM_BOMBCASE))) {
#ifdef VERSION_JP
    if ((!j_text_trigger || (weaponid != ITEM_KNIFE))) {
      return 1;
    }
#else
    return 1;
#endif
  }
  return is_weapon_in_inv(weaponid);
}

#ifdef VERSION_US
asm(R"
glabel check_if_item_for_hand_available
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  sw    $a1, 0x1c($sp)
  lw    $t7, 0x11ec($t6)
  slti  $at, $a0, 0x21
  beqz  $t7, .L7F08C470
   nop   
  beqz  $at, .L7F08C470
   nop   
  bne   $a0, $a1, .L7F08C470
   nop   
  jal   getPlayerCount
   sw    $a0, 0x18($sp)
  li    $at, 1
  bne   $v0, $at, .L7F08C470
   lw    $a0, 0x18($sp)
  lui   $a1, 0x10
  jal   check_special_attributes
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F08C470
   lw    $a0, 0x18($sp)
  b     .L7F08C478
   li    $v0, 1
.L7F08C470:
  jal   is_item_for_hand_in_inventory
   lw    $a1, 0x1c($sp)
.L7F08C478:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel check_if_item_for_hand_available
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  bnez  $a1, .Ljp7F08CCCC
   move  $a2, $a1
  b     .Ljp7F08CD58
   li    $v0, 1
.Ljp7F08CCCC:
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  slti  $at, $a0, 0x21
  lw    $t7, 0x11ec($t6)
  beqz  $t7, .Ljp7F08CD50
   nop   
  beqz  $at, .Ljp7F08CD50
   nop   
  bne   $a0, $a2, .Ljp7F08CD50
   nop   
  sw    $a0, 0x18($sp)
  jal   getPlayerCount
   sw    $a2, 0x1c($sp)
  li    $at, 1
  lw    $a0, 0x18($sp)
  bne   $v0, $at, .Ljp7F08CD50
   lw    $a2, 0x1c($sp)
  lui   $a1, 0x10
  sw    $a0, 0x18($sp)
  jal   check_special_attributes
   sw    $a2, 0x1c($sp)
  lw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08CD50
   lw    $a2, 0x1c($sp)
  lui   $t8, %hi(j_text_trigger) # $t8, 0x8005
  lw    $t8, %lo(j_text_trigger)($t8)
  li    $at, 2
  beqz  $t8, .Ljp7F08CD48
   nop   
  beq   $a0, $at, .Ljp7F08CD50
   nop   
.Ljp7F08CD48:
  b     .Ljp7F08CD58
   li    $v0, 1
.Ljp7F08CD50:
  jal   is_item_for_hand_in_inventory
   move  $a1, $a2
.Ljp7F08CD58:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop    
");
#endif

int add_item_to_inventory(ITEM_IDS item) {
  InvItem *nextItem;

  if (is_weapon_in_inv(item) == 0) {
    nextItem = get_ptr_next_available_weapon();
    if (nextItem) {
      nextItem->type = INV_ITEM_WEAPON;
      nextItem->type_inv_item.type_weap.weapon = item;
      add_additional_weapon_slot_to_player_inventory_guess(nextItem);
    }

    if ((pPlayer->equipallguns) && (item < ITEM_BOMBCASE)) {
#ifdef VERSION_JP
      if ((!j_text_trigger || (item != ITEM_KNIFE))) {
        return false;
      }
#else
      return false;
#endif
    }
    return true;
  }
  return false;
}

int add_doubles_item_to_inventory(int right, int left) {
  InvItem *item;

  if (is_item_for_hand_in_inventory(right, left) == 0) {
    item = get_ptr_next_available_weapon();
    if (item) {
      item->type = INV_ITEM_DUAL;
      item->type_inv_item.type_dual.weapon_right = right;
      item->type_inv_item.type_dual.weapon_left = left;
      add_additional_weapon_slot_to_player_inventory_guess(item);
    }
    return true;
  }
  return false;
}

asm(R"
glabel sub_GAME_7F08C570
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -0x38
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $a2, 0x11e0($t6)
  move  $s0, $a0
  li    $t2, 8
  beqz  $a2, .L7F08C604
   li    $t1, 4
  lw    $a0, 0xc($a2)
  li    $t0, 2
.L7F08C5A0:
  lw    $t7, ($a0)
  lw    $a3, 0xc($a0)
  bne   $t0, $t7, .L7F08C5EC
   nop   
  lw    $v1, 4($a0)
  lbu   $t8, ($v1)
  bne   $t1, $t8, .L7F08C5EC
   nop   
  lw    $a1, 4($v1)
  lbu   $t9, 3($a1)
  bne   $t2, $t9, .L7F08C5EC
   nop   
  lb    $t3, 0x80($a1)
  bne   $s0, $t3, .L7F08C5EC
   nop   
  jal   reorder_inventory_ptrs_based_on_id_code
   sw    $a1, 0x24($sp)
  b     .L7F08C608
   lw    $v0, 0x24($sp)
.L7F08C5EC:
  beql  $a0, $a2, .L7F08C608
   move  $v0, $zero
  beql  $a2, $zero, .L7F08C608
   move  $v0, $zero
  b     .L7F08C5A0
   move  $a0, $a3
.L7F08C604:
  move  $v0, $zero
.L7F08C608:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x38
  jr    $ra
   nop   
");

asm(R"
glabel sub_GAME_7F08C61C
  addiu $sp, $sp, -0x38
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  sw    $ra, 0x34($sp)
  sw    $s6, 0x30($sp)
  sw    $s5, 0x2c($sp)
  sw    $s4, 0x28($sp)
  sw    $s3, 0x24($sp)
  sw    $s2, 0x20($sp)
  sw    $s1, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lw    $a1, 0x11e0($t6)
  move  $s2, $a0
  li    $s5, 8
  beqz  $a1, .L7F08C6FC
   li    $s6, 1
  lw    $s0, 0xc($a1)
  li    $s4, 4
  li    $s3, 2
.L7F08C668:
  lw    $v0, ($s0)
  lw    $s1, 0xc($s0)
  bne   $s3, $v0, .L7F08C6BC
   nop   
  lw    $v1, 4($s0)
  lbu   $t7, ($v1)
  bne   $s4, $t7, .L7F08C6E4
   nop   
  lw    $a0, 4($v1)
  lbu   $t8, 3($a0)
  bne   $s5, $t8, .L7F08C6E4
   nop   
  lb    $t9, 0x80($a0)
  bne   $s2, $t9, .L7F08C6E4
   nop   
  jal   reorder_inventory_ptrs_based_on_id_code
   move  $a0, $s0
  lui   $t0, %hi(pPlayer) 
  lw    $t0, %lo(pPlayer)($t0)
  b     .L7F08C6E4
   lw    $a1, 0x11e0($t0)
.L7F08C6BC:
  bne   $s6, $v0, .L7F08C6E4
   nop   
  lw    $t1, 4($s0)
  bne   $s2, $t1, .L7F08C6E4
   nop   
  jal   reorder_inventory_ptrs_based_on_id_code
   move  $a0, $s0
  lui   $t2, %hi(pPlayer) 
  lw    $t2, %lo(pPlayer)($t2)
  lw    $a1, 0x11e0($t2)
.L7F08C6E4:
  beql  $s0, $a1, .L7F08C700
   lw    $ra, 0x34($sp)
  beql  $a1, $zero, .L7F08C700
   lw    $ra, 0x34($sp)
  b     .L7F08C668
   move  $s0, $s1
.L7F08C6FC:
  lw    $ra, 0x34($sp)
.L7F08C700:
  lw    $s0, 0x18($sp)
  lw    $s1, 0x1c($sp)
  lw    $s2, 0x20($sp)
  lw    $s3, 0x24($sp)
  lw    $s4, 0x28($sp)
  lw    $s5, 0x2c($sp)
  lw    $s6, 0x30($sp)
  jr    $ra
   addiu $sp, $sp, 0x38
");

int add_prop_to_inventory(PropRecord *prop) {
  InvItem *item = get_ptr_next_available_weapon();
  if (item) {
    item->type = INV_ITEM_PROP;
    item->type_inv_item.type_prop.prop = prop;
    add_additional_weapon_slot_to_player_inventory_guess(item);
  }
  return true;
}

asm(R"
glabel sub_GAME_7F08C764
  addiu $sp, $sp, -0x30
  sw    $ra, 0x1c($sp)
  sw    $s0, 0x18($sp)
  lbu   $t6, ($a0)
  li    $at, 4
  move  $a1, $zero
  bnel  $t6, $at, .L7F08C85C
   lw    $ra, 0x1c($sp)
  lw    $a2, 4($a0)
  li    $at, 8
  lbu   $t7, 3($a2)
  bnel  $t7, $at, .L7F08C85C
   lw    $ra, 0x1c($sp)
  lb    $s0, 0x80($a2)
  sw    $a2, 0x24($sp)
  jal   add_item_to_inventory
   move  $a0, $s0
  lw    $v1, 0x24($sp)
  move  $a1, $v0
  lw    $a2, 0x84($v1)
  beql  $a2, $zero, .L7F08C81C
   lb    $a2, 0x81($v1)
  lw    $t8, 8($v1)
  move  $a1, $s0
  move  $a0, $s0
  sll   $t9, $t8, 3
  bgezl $t9, .L7F08C7F0
   lb    $a1, 0x80($a2)
  lb    $a0, 0x80($a2)
  jal   is_item_for_hand_in_inventory
   sw    $v1, 0x24($sp)
  lw    $v1, 0x24($sp)
  b     .L7F08C800
   sltiu $a1, $v0, 1
  lb    $a1, 0x80($a2)
.L7F08C7F0:
  jal   is_item_for_hand_in_inventory
   sw    $v1, 0x24($sp)
  lw    $v1, 0x24($sp)
  sltiu $a1, $v0, 1
.L7F08C800:
  lw    $t0, 0x84($v1)
  sb    $s0, 0x81($t0)
  lw    $t1, 0x84($v1)
  sw    $zero, 0x84($t1)
  b     .L7F08C858
   sw    $zero, 0x84($v1)
  lb    $a2, 0x81($v1)
.L7F08C81C:
  bltzl $a2, .L7F08C85C
   lw    $ra, 0x1c($sp)
  lw    $t2, 8($v1)
  move  $a1, $s0
  move  $a0, $s0
  sll   $t3, $t2, 3
  bgez  $t3, .L7F08C84C
   nop   
  jal   add_doubles_item_to_inventory
   move  $a0, $a2
  b     .L7F08C858
   move  $a1, $v0
.L7F08C84C:
  jal   add_doubles_item_to_inventory
   move  $a1, $a2
  move  $a1, $v0
.L7F08C858:
  lw    $ra, 0x1c($sp)
.L7F08C85C:
  lw    $s0, 0x18($sp)
  addiu $sp, $sp, 0x30
  jr    $ra
   move  $v0, $a1
");

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08C86C
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $s0, 0x11e0($v1)
  move  $s2, $a2
  lw    $s1, ($a0)
  beqz  $s0, .L7F08C998
   lw    $s3, ($a1)
  lw    $v0, ($s0)
.L7F08C8AC:
  li    $at, 1
  bnel  $v0, $at, .L7F08C900
   li    $at, 3
  lw    $a0, 4($s0)
  slti  $at, $a0, 0x21
  beqz  $at, .L7F08C968
   slt   $at, $s1, $a0
  beqz  $at, .L7F08C968
   nop   
  beql  $s2, $zero, .L7F08C8F4
   move  $s1, $a0
  jal   check_if_have_ammo_for_item
   nop   
  beqz  $v0, .L7F08C968
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a0, 4($s0)
  move  $s1, $a0
.L7F08C8F4:
  b     .L7F08C998
   move  $s3, $zero
  li    $at, 3
.L7F08C900:
  bne   $v0, $at, .L7F08C968
   nop   
  lw    $a0, 4($s0)
  slt   $at, $s1, $a0
  bnez  $at, .L7F08C930
   nop   
  bne   $s1, $a0, .L7F08C968
   nop   
  lw    $t8, 8($s0)
  slt   $at, $s3, $t8
  beqz  $at, .L7F08C968
   nop   
.L7F08C930:
  beqz  $s2, .L7F08C954
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  bnez  $v0, .L7F08C954
   nop   
  jal   check_if_have_ammo_for_item
   lw    $a0, 8($s0)
  beqz  $v0, .L7F08C968
.L7F08C954:
   lui   $v1, %hi(pPlayer)
  lw    $s1, 4($s0)
  lw    $s3, 8($s0)
  b     .L7F08C998
   lw    $v1, %lo(pPlayer)($v1)
.L7F08C968:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $s0, 0xc($s0)
  lw    $t9, 0x11e0($v1)
  bne   $s0, $t9, .L7F08C990
   nop   
  bnezl $s2, .L7F08C99C
   lw    $t0, 0x11ec($v1)
  li    $s1, -1
  li    $s3, -1
.L7F08C990:
  bnezl $s0, .L7F08C8AC
   lw    $v0, ($s0)
.L7F08C998:
  lw    $t0, 0x11ec($v1)
.L7F08C99C:
  lw    $t1, 0x28($sp)
  beql  $t0, $zero, .L7F08CAE8
   lw    $t3, 0x28($sp)
  jal   getPlayerCount
   lw    $s0, ($t1)
  li    $at, 1
  bnel  $v0, $at, .L7F08CA30
   lw    $t7, 0x28($sp)
  lw    $t2, 0x28($sp)
  lui   $a1, 0x10
  jal   check_special_attributes
   lw    $a0, ($t2)
  beql  $v0, $zero, .L7F08CA30
   lw    $t7, 0x28($sp)
  lw    $t3, 0x28($sp)
  lw    $t4, 0x2c($sp)
  lw    $a0, ($t3)
  lw    $t5, ($t4)
  slt   $at, $t5, $a0
  beql  $at, $zero, .L7F08CA30
   lw    $t7, 0x28($sp)
  beqz  $s2, .L7F08CA10
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  beql  $v0, $zero, .L7F08CA30
   lw    $t7, 0x28($sp)
  lw    $t6, 0x28($sp)
  lw    $a0, ($t6)
.L7F08CA10:
  bne   $s1, $a0, .L7F08CA20
   slt   $at, $a0, $s3
  beql  $at, $zero, .L7F08CA30
   lw    $t7, 0x28($sp)
.L7F08CA20:
  move  $s1, $a0
  b     .L7F08CAE4
   move  $s3, $a0
  lw    $t7, 0x28($sp)
.L7F08CA30:
  li    $v1, 33
  lw    $t8, ($t7)
  bne   $s1, $t8, .L7F08CA50
   nop   
  lw    $t9, 0x2c($sp)
  lw    $t0, ($t9)
  bnel  $s3, $t0, .L7F08CAE8
   lw    $t3, 0x28($sp)
.L7F08CA50:
  addiu $t1, $s0, 1
.L7F08CA54:
  div   $zero, $t1, $v1
  mfhi  $s0
  addiu $t2, $s0, 1
  bnez  $v1, .L7F08CA6C
   nop   
  break 7
.L7F08CA6C:
  li    $at, -1
  bne   $v1, $at, .L7F08CA84
   lui   $at, 0x8000
  bne   $t1, $at, .L7F08CA84
   nop   
  break 6
.L7F08CA84:
  bnez  $s0, .L7F08CAB8
   nop   
  div   $zero, $t2, $v1
  mfhi  $s0
  bnez  $v1, .L7F08CAA0
   nop   
  break 7
.L7F08CAA0:
  li    $at, -1
  bne   $v1, $at, .L7F08CAB8
   lui   $at, 0x8000
  bne   $t2, $at, .L7F08CAB8
   nop   
  break 6
.L7F08CAB8:
  beql  $s2, $zero, .L7F08CAD4
   move  $s1, $s0
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beqz  $v0, .L7F08CADC
   li    $v1, 33
  move  $s1, $s0
.L7F08CAD4:
  b     .L7F08CAE4
   move  $s3, $zero
.L7F08CADC:
  bnel  $s0, $s1, .L7F08CA54
   addiu $t1, $s0, 1
.L7F08CAE4:
  lw    $t3, 0x28($sp)
.L7F08CAE8:
  sw    $s1, ($t3)
  lw    $t4, 0x2c($sp)
  sw    $s3, ($t4)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08C86C
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $s0, 0x11e0($v1)
  move  $s2, $a2
  lw    $s1, ($a0)
  beqz  $s0, .Ljp7F08D290
   lw    $s3, ($a1)
  lw    $v0, ($s0)
.Ljp7F08D1A4:
  li    $at, 1
  bnel  $v0, $at, .Ljp7F08D1F8
   li    $at, 3
  lw    $a0, 4($s0)
  slti  $at, $a0, 0x21
  beqz  $at, .Ljp7F08D260
   slt   $at, $s1, $a0
  beqz  $at, .Ljp7F08D260
   nop   
  beql  $s2, $zero, .Ljp7F08D1EC
   move  $s1, $a0
  jal   check_if_have_ammo_for_item
   nop   
  beqz  $v0, .Ljp7F08D260
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a0, 4($s0)
  move  $s1, $a0
.Ljp7F08D1EC:
  b     .Ljp7F08D290
   move  $s3, $zero
  li    $at, 3
.Ljp7F08D1F8:
  bne   $v0, $at, .Ljp7F08D260
   nop   
  lw    $a0, 4($s0)
  slt   $at, $s1, $a0
  bnez  $at, .Ljp7F08D228
   nop   
  bne   $s1, $a0, .Ljp7F08D260
   nop   
  lw    $t8, 8($s0)
  slt   $at, $s3, $t8
  beqz  $at, .Ljp7F08D260
   nop   
.Ljp7F08D228:
  beqz  $s2, .Ljp7F08D24C
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  bnez  $v0, .Ljp7F08D24C
   nop   
  jal   check_if_have_ammo_for_item
   lw    $a0, 8($s0)
  beqz  $v0, .Ljp7F08D260
.Ljp7F08D24C:
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $s1, 4($s0)
  lw    $s3, 8($s0)
  b     .Ljp7F08D290
   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F08D260:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $s0, 0xc($s0)
  lw    $t9, 0x11e0($v1)
  bne   $s0, $t9, .Ljp7F08D288
   nop   
  bnezl $s2, .Ljp7F08D294
   lw    $t0, 0x11ec($v1)
  li    $s1, -1
  li    $s3, -1
.Ljp7F08D288:
  bnezl $s0, .Ljp7F08D1A4
   lw    $v0, ($s0)
.Ljp7F08D290:
  lw    $t0, 0x11ec($v1)
.Ljp7F08D294:
  lw    $t1, 0x28($sp)
  beql  $t0, $zero, .Ljp7F08D414
   lw    $t5, 0x28($sp)
  jal   getPlayerCount
   lw    $s0, ($t1)
  li    $at, 1
  bne   $v0, $at, .Ljp7F08D33C
   lw    $t2, 0x28($sp)
  lw    $a0, ($t2)
  jal   check_special_attributes
   lui   $a1, 0x10
  beql  $v0, $zero, .Ljp7F08D340
   lw    $t8, 0x28($sp)
  lw    $t3, 0x28($sp)
  lw    $t4, 0x2c($sp)
  lw    $a0, ($t3)
  lw    $t5, ($t4)
  slt   $at, $t5, $a0
  beql  $at, $zero, .Ljp7F08D340
   lw    $t8, 0x28($sp)
  beqz  $s2, .Ljp7F08D304
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  beql  $v0, $zero, .Ljp7F08D340
   lw    $t8, 0x28($sp)
  lw    $t6, 0x28($sp)
  lw    $a0, ($t6)
.Ljp7F08D304:
  bne   $s1, $a0, .Ljp7F08D314
   slt   $at, $a0, $s3
  beql  $at, $zero, .Ljp7F08D340
   lw    $t8, 0x28($sp)
.Ljp7F08D314:
  lui   $t7, %hi(j_text_trigger) # $t7, 0x8005
  lw    $t7, %lo(j_text_trigger)($t7)
  li    $at, 2
  beql  $t7, $zero, .Ljp7F08D334
   move  $s1, $a0
  beql  $a0, $at, .Ljp7F08D340
   lw    $t8, 0x28($sp)
  move  $s1, $a0
.Ljp7F08D334:
  b     .Ljp7F08D410
   move  $s3, $a0
.Ljp7F08D33C:
  lw    $t8, 0x28($sp)
.Ljp7F08D340:
  li    $v1, 33
  lw    $t9, ($t8)
  bne   $s1, $t9, .Ljp7F08D360
   nop   
  lw    $t0, 0x2c($sp)
  lw    $t1, ($t0)
  bnel  $s3, $t1, .Ljp7F08D414
   lw    $t5, 0x28($sp)
.Ljp7F08D360:
  addiu $t2, $s0, 1
.Ljp7F08D364:
  div   $zero, $t2, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D378
   nop   
  break 7
.Ljp7F08D378:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D390
   lui   $at, 0x8000
  bne   $t2, $at, .Ljp7F08D390
   nop   
  break 6
.Ljp7F08D390:
  bnez  $s0, .Ljp7F08D3C8
   nop   
  addiu $t3, $s0, 1
  div   $zero, $t3, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D3B0
   nop   
  break 7
.Ljp7F08D3B0:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D3C8
   lui   $at, 0x8000
  bne   $t3, $at, .Ljp7F08D3C8
   nop   
  break 6
.Ljp7F08D3C8:
  beqz  $s2, .Ljp7F08D3E0
   nop   
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beqz  $v0, .Ljp7F08D408
   li    $v1, 33
.Ljp7F08D3E0:
  lui   $t4, %hi(j_text_trigger) # $t4, 0x8005
  lw    $t4, %lo(j_text_trigger)($t4)
  li    $at, 2
  beql  $t4, $zero, .Ljp7F08D400
   move  $s1, $s0
  beq   $s0, $at, .Ljp7F08D408
   nop   
  move  $s1, $s0
.Ljp7F08D400:
  b     .Ljp7F08D410
   move  $s3, $zero
.Ljp7F08D408:
  bnel  $s0, $s1, .Ljp7F08D364
   addiu $t2, $s0, 1
.Ljp7F08D410:
  lw    $t5, 0x28($sp)
.Ljp7F08D414:
  sw    $s1, ($t5)
  lw    $t6, 0x2c($sp)
  sw    $s3, ($t6)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x28 
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08CB10
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $v0, 0x11e0($v1)
  move  $s2, $a2
  lw    $s1, ($a0)
  move  $t6, $a0
  lw    $s3, ($a1)
  beqz  $v0, .L7F08CC58
   move  $t7, $a1
  lw    $s0, 0x10($v0)
.L7F08CB58:
  lw    $v0, ($s0)
  li    $at, 1
  bnel  $v0, $at, .L7F08CBC4
   li    $at, 3
  lw    $a0, 4($s0)
  slti  $at, $a0, 0x21
  beqz  $at, .L7F08CC2C
   nop   
  slt   $at, $a0, $s1
  bnez  $at, .L7F08CB94
   nop   
  bne   $s1, $a0, .L7F08CC2C
   nop   
  blez  $s3, .L7F08CC2C
   nop   
.L7F08CB94:
  beql  $s2, $zero, .L7F08CBB8
   move  $s1, $a0
  jal   check_if_have_ammo_for_item
   nop   
  beqz  $v0, .L7F08CC2C
   lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a0, 4($s0)
  move  $s1, $a0
.L7F08CBB8:
  b     .L7F08CC58
   move  $s3, $zero
  li    $at, 3
.L7F08CBC4:
  bne   $v0, $at, .L7F08CC2C
   nop   
  lw    $a0, 4($s0)
  slt   $at, $a0, $s1
  bnez  $at, .L7F08CBF4
   nop   
  bne   $s1, $a0, .L7F08CC2C
   nop   
  lw    $t8, 8($s0)
  slt   $at, $t8, $s3
  beqz  $at, .L7F08CC2C
   nop   
.L7F08CBF4:
  beqz  $s2, .L7F08CC18
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  bnez  $v0, .L7F08CC18
   nop   
  jal   check_if_have_ammo_for_item
   lw    $a0, 8($s0)
  beqz  $v0, .L7F08CC2C
.L7F08CC18:
   lui   $v1, %hi(pPlayer)
  lw    $s1, 4($s0)
  lw    $s3, 8($s0)
  b     .L7F08CC58
   lw    $v1, %lo(pPlayer)($v1)
.L7F08CC2C:
  lui   $v1, %hi(pPlayer)
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t9, 0x11e0($v1)
  bne   $s0, $t9, .L7F08CC50
   nop   
  bnezl $s2, .L7F08CC5C
   lw    $t0, 0x11ec($v1)
  li    $s1, 1000
  li    $s3, 1000
.L7F08CC50:
  b     .L7F08CB58
   lw    $s0, 0x10($s0)
.L7F08CC58:
  lw    $t0, 0x11ec($v1)
.L7F08CC5C:
  lw    $t2, 0x2c($sp)
  beql  $t0, $zero, .L7F08CE48
   lw    $t6, 0x28($sp)
  lw    $t3, ($t2)
  lw    $t1, 0x28($sp)
  li    $v1, 33
  bnez  $t3, .L7F08CCE4
   lw    $s0, ($t1)
  addiu $t4, $s0, 0x20
  div   $zero, $t4, $v1
  mfhi  $s0
  addiu $t5, $s0, 0x20
  bnez  $v1, .L7F08CC98
   nop   
  break 7
.L7F08CC98:
  li    $at, -1
  bne   $v1, $at, .L7F08CCB0
   lui   $at, 0x8000
  bne   $t4, $at, .L7F08CCB0
   nop   
  break 6
.L7F08CCB0:
  bnez  $s0, .L7F08CCE4
   nop   
  div   $zero, $t5, $v1
  mfhi  $s0
  bnez  $v1, .L7F08CCCC
   nop   
  break 7
.L7F08CCCC:
  li    $at, -1
  bne   $v1, $at, .L7F08CCE4
   lui   $at, 0x8000
  bne   $t5, $at, .L7F08CCE4
   nop   
  break 6
.L7F08CCE4:
  bne   $s0, $s1, .L7F08CD60
   nop   
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F08CE44
   move  $a0, $s0
  jal   check_special_attributes
   lui   $a1, 0x10
  beql  $v0, $zero, .L7F08CE48
   lw    $t6, 0x28($sp)
  beql  $s2, $zero, .L7F08CD2C
   lw    $t6, 0x28($sp)
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beql  $v0, $zero, .L7F08CE48
   lw    $t6, 0x28($sp)
  lw    $t6, 0x28($sp)
.L7F08CD2C:
  lw    $t8, 0x2c($sp)
  lw    $t7, ($t6)
  bnel  $s0, $t7, .L7F08CD4C
   slt   $at, $s3, $s0
  lw    $t9, ($t8)
  slt   $at, $s0, $t9
  beqz  $at, .L7F08CE44
   slt   $at, $s3, $s0
.L7F08CD4C:
  beql  $at, $zero, .L7F08CE48
   lw    $t6, 0x28($sp)
  move  $s1, $s0
  b     .L7F08CE44
   move  $s3, $s0
.L7F08CD60:
  beqz  $s2, .L7F08CD78
   nop   
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beqz  $v0, .L7F08CDD4
   li    $v1, 33
.L7F08CD78:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .L7F08CDC8
   move  $a0, $s0
  jal   check_special_attributes
   lui   $a1, 0x10
  beqz  $v0, .L7F08CDC8
   lw    $t0, 0x28($sp)
  lw    $t1, ($t0)
  lw    $t2, 0x2c($sp)
  move  $s1, $s0
  bne   $s0, $t1, .L7F08CDC0
   nop   
  lw    $t3, ($t2)
  slt   $at, $s0, $t3
  beql  $at, $zero, .L7F08CDCC
   move  $s1, $s0
.L7F08CDC0:
  b     .L7F08CE44
   move  $s3, $s0
.L7F08CDC8:
  move  $s1, $s0
.L7F08CDCC:
  b     .L7F08CE44
   move  $s3, $zero
.L7F08CDD4:
  addiu $t4, $s0, 0x20
  div   $zero, $t4, $v1
  mfhi  $s0
  bnez  $v1, .L7F08CDEC
   nop   
  break 7
.L7F08CDEC:
  li    $at, -1
  bne   $v1, $at, .L7F08CE04
   lui   $at, 0x8000
  bne   $t4, $at, .L7F08CE04
   nop   
  break 6
.L7F08CE04:
  bnez  $s0, .L7F08CCE4
   nop   
  addiu $t5, $s0, 0x20
  div   $zero, $t5, $v1
  mfhi  $s0
  bnez  $v1, .L7F08CE24
   nop   
  break 7
.L7F08CE24:
  li    $at, -1
  bne   $v1, $at, .L7F08CE3C
   lui   $at, 0x8000
  bne   $t5, $at, .L7F08CE3C
   nop   
  break 6
.L7F08CE3C:
  b     .L7F08CCE4
   nop   
.L7F08CE44:
  lw    $t6, 0x28($sp)
.L7F08CE48:
  sw    $s1, ($t6)
  lw    $t7, 0x2c($sp)
  sw    $s3, ($t7)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08CB10
  addiu $sp, $sp, -0x28
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  sw    $ra, 0x24($sp)
  sw    $s3, 0x20($sp)
  sw    $s2, 0x1c($sp)
  sw    $s1, 0x18($sp)
  sw    $s0, 0x14($sp)
  sw    $a0, 0x28($sp)
  sw    $a1, 0x2c($sp)
  lw    $v0, 0x11e0($v1)
  move  $s2, $a2
  lw    $s1, ($a0)
  move  $t6, $a0
  lw    $s3, ($a1)
  beqz  $v0, .Ljp7F08D584
   move  $t7, $a1
  lw    $s0, 0x10($v0)
.Ljp7F08D484:
  lw    $v0, ($s0)
  li    $at, 1
  bnel  $v0, $at, .Ljp7F08D4F0
   li    $at, 3
  lw    $a0, 4($s0)
  slti  $at, $a0, 0x21
  beqz  $at, .Ljp7F08D558
   nop   
  slt   $at, $a0, $s1
  bnez  $at, .Ljp7F08D4C0
   nop   
  bne   $s1, $a0, .Ljp7F08D558
   nop   
  blez  $s3, .Ljp7F08D558
   nop   
.Ljp7F08D4C0:
  beql  $s2, $zero, .Ljp7F08D4E4
   move  $s1, $a0
  jal   check_if_have_ammo_for_item
   nop   
  beqz  $v0, .Ljp7F08D558
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $a0, 4($s0)
  move  $s1, $a0
.Ljp7F08D4E4:
  b     .Ljp7F08D584
   move  $s3, $zero
  li    $at, 3
.Ljp7F08D4F0:
  bne   $v0, $at, .Ljp7F08D558
   nop   
  lw    $a0, 4($s0)
  slt   $at, $a0, $s1
  bnez  $at, .Ljp7F08D520
   nop   
  bne   $s1, $a0, .Ljp7F08D558
   nop   
  lw    $t8, 8($s0)
  slt   $at, $t8, $s3
  beqz  $at, .Ljp7F08D558
   nop   
.Ljp7F08D520:
  beqz  $s2, .Ljp7F08D544
   nop   
  jal   check_if_have_ammo_for_item
   nop   
  bnez  $v0, .Ljp7F08D544
   nop   
  jal   check_if_have_ammo_for_item
   lw    $a0, 8($s0)
  beqz  $v0, .Ljp7F08D558
.Ljp7F08D544:
   lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $s1, 4($s0)
  lw    $s3, 8($s0)
  b     .Ljp7F08D584
   lw    $v1, %lo(pPlayer)($v1)
.Ljp7F08D558:
  lui   $v1, %hi(pPlayer) # $v1, 0x8008
  lw    $v1, %lo(pPlayer)($v1)
  lw    $t9, 0x11e0($v1)
  bne   $s0, $t9, .Ljp7F08D57C
   nop   
  bnezl $s2, .Ljp7F08D588
   lw    $t0, 0x11ec($v1)
  li    $s1, 1000
  li    $s3, 1000
.Ljp7F08D57C:
  b     .Ljp7F08D484
   lw    $s0, 0x10($s0)
.Ljp7F08D584:
  lw    $t0, 0x11ec($v1)
.Ljp7F08D588:
  lw    $t2, 0x2c($sp)
  beql  $t0, $zero, .Ljp7F08D7AC
   lw    $t8, 0x28($sp)
  lw    $t3, ($t2)
  lw    $t1, 0x28($sp)
  li    $v1, 33
  bnez  $t3, .Ljp7F08D610
   lw    $s0, ($t1)
  addiu $t4, $s0, 0x20
  div   $zero, $t4, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D5C0
   nop   
  break 7
.Ljp7F08D5C0:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D5D8
   lui   $at, 0x8000
  bne   $t4, $at, .Ljp7F08D5D8
   nop   
  break 6
.Ljp7F08D5D8:
  bnezl $s0, .Ljp7F08D614
   li    $v1, 33
  addiu $t5, $s0, 0x20
  div   $zero, $t5, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D5F8
   nop   
  break 7
.Ljp7F08D5F8:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D610
   lui   $at, 0x8000
  bne   $t5, $at, .Ljp7F08D610
   nop   
  break 6
.Ljp7F08D610:
  li    $v1, 33
.Ljp7F08D614:
  bne   $s0, $s1, .Ljp7F08D6A8
   nop   
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F08D7A8
   move  $a0, $s0
  jal   check_special_attributes
   lui   $a1, 0x10
  beql  $v0, $zero, .Ljp7F08D7AC
   lw    $t8, 0x28($sp)
  beql  $s2, $zero, .Ljp7F08D65C
   lw    $t6, 0x28($sp)
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beql  $v0, $zero, .Ljp7F08D7AC
   lw    $t8, 0x28($sp)
  lw    $t6, 0x28($sp)
.Ljp7F08D65C:
  lw    $t8, 0x2c($sp)
  lw    $t7, ($t6)
  bnel  $s0, $t7, .Ljp7F08D67C
   slt   $at, $s3, $s0
  lw    $t9, ($t8)
  slt   $at, $s0, $t9
  beqz  $at, .Ljp7F08D7A8
   slt   $at, $s3, $s0
.Ljp7F08D67C:
  beqz  $at, .Ljp7F08D7A8
   lui   $t0, %hi(j_text_trigger) # $t0, 0x8005
  lw    $t0, %lo(j_text_trigger)($t0)
  li    $at, 2
  beql  $t0, $zero, .Ljp7F08D6A0
   move  $s1, $s0
  beql  $s0, $at, .Ljp7F08D7AC
   lw    $t8, 0x28($sp)
  move  $s1, $s0
.Ljp7F08D6A0:
  b     .Ljp7F08D7A8
   move  $s3, $s0
.Ljp7F08D6A8:
  beqz  $s2, .Ljp7F08D6C0
   nop   
  jal   check_if_have_ammo_for_item
   move  $a0, $s0
  beqz  $v0, .Ljp7F08D738
   li    $v1, 33
.Ljp7F08D6C0:
  lui   $t1, %hi(j_text_trigger) # $t1, 0x8005
  lw    $t1, %lo(j_text_trigger)($t1)
  li    $at, 2
  beqz  $t1, .Ljp7F08D6DC
   nop   
  beql  $s0, $at, .Ljp7F08D73C
   addiu $t6, $s0, 0x20
.Ljp7F08D6DC:
  jal   getPlayerCount
   nop   
  li    $at, 1
  bne   $v0, $at, .Ljp7F08D72C
   move  $a0, $s0
  jal   check_special_attributes
   lui   $a1, 0x10
  beqz  $v0, .Ljp7F08D72C
   lw    $t2, 0x28($sp)
  lw    $t3, ($t2)
  lw    $t4, 0x2c($sp)
  move  $s1, $s0
  bne   $s0, $t3, .Ljp7F08D724
   nop   
  lw    $t5, ($t4)
  slt   $at, $s0, $t5
  beql  $at, $zero, .Ljp7F08D730
   move  $s1, $s0
.Ljp7F08D724:
  b     .Ljp7F08D7A8
   move  $s3, $s0
.Ljp7F08D72C:
  move  $s1, $s0
.Ljp7F08D730:
  b     .Ljp7F08D7A8
   move  $s3, $zero
.Ljp7F08D738:
  addiu $t6, $s0, 0x20
.Ljp7F08D73C:
  div   $zero, $t6, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D750
   nop   
  break 7
.Ljp7F08D750:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D768
   lui   $at, 0x8000
  bne   $t6, $at, .Ljp7F08D768
   nop   
  break 6
.Ljp7F08D768:
  bnez  $s0, .Ljp7F08D614
   nop   
  addiu $t7, $s0, 0x20
  div   $zero, $t7, $v1
  mfhi  $s0
  bnez  $v1, .Ljp7F08D788
   nop   
  break 7
.Ljp7F08D788:
  li    $at, -1
  bne   $v1, $at, .Ljp7F08D7A0
   lui   $at, 0x8000
  bne   $t7, $at, .Ljp7F08D7A0
   nop   
  break 6
.Ljp7F08D7A0:
  b     .Ljp7F08D614
   nop   
.Ljp7F08D7A8:
  lw    $t8, 0x28($sp)
.Ljp7F08D7AC:
  sw    $s1, ($t8)
  lw    $t9, 0x2c($sp)
  sw    $s3, ($t9)
  lw    $ra, 0x24($sp)
  lw    $s3, 0x20($sp)
  lw    $s2, 0x1c($sp)
  lw    $s1, 0x18($sp)
  lw    $s0, 0x14($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");
#endif

asm(R"
glabel sub_GAME_7F08CE70
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  addiu $sp, $sp, -8
  sw    $s0, 4($sp)
  lw    $a1, 0x11e0($t6)
  move  $s0, $a0
  move  $v0, $zero
  beqz  $a1, .L7F08CEFC
   move  $v1, $a1
  li    $t2, 4
  li    $t1, 1
  li    $t0, 2
  lw    $t7, ($v1)
.L7F08CEA4:
  bnel  $t0, $t7, .L7F08CEEC
   lw    $v1, 0xc($v1)
  lw    $a0, 4($v1)
  lbu   $t8, ($a0)
  bnel  $t1, $t8, .L7F08CEEC
   lw    $v1, 0xc($v1)
  lw    $a3, 4($a0)
  lbu   $t9, 3($a3)
  bnel  $t2, $t9, .L7F08CEEC
   lw    $v1, 0xc($v1)
  lw    $t3, 0x80($a3)
  or    $v0, $v0, $t3
  and   $t4, $s0, $v0
  bnel  $s0, $t4, .L7F08CEEC
   lw    $v1, 0xc($v1)
  b     .L7F08CF00
   li    $v0, 1
  lw    $v1, 0xc($v1)
.L7F08CEEC:
  beql  $v1, $a1, .L7F08CF00
   move  $v0, $zero
  bnezl $v1, .L7F08CEA4
   lw    $t7, ($v1)
.L7F08CEFC:
  move  $v0, $zero
.L7F08CF00:
  lw    $s0, 4($sp)
  jr    $ra
   addiu $sp, $sp, 8
");

asm(R"
glabel sub_GAME_7F08CF0C
  lui   $t6, %hi(pPlayer) 
  lw    $t6, %lo(pPlayer)($t6)
  li    $t0, 248
  li    $a3, 4
  lw    $v1, 0x11e0($t6)
  li    $a2, 2
  beqz  $v1, .L7F08CF74
   move  $v0, $v1
  lw    $t7, ($v0)
.L7F08CF30:
  bnel  $a2, $t7, .L7F08CF64
   lw    $v0, 0xc($v0)
  lw    $a0, 4($v0)
  lbu   $t8, ($a0)
  bnel  $a3, $t8, .L7F08CF64
   lw    $v0, 0xc($v0)
  lw    $a1, 4($a0)
  lh    $t9, 4($a1)
  bnel  $t0, $t9, .L7F08CF64
   lw    $v0, 0xc($v0)
  jr    $ra
   li    $v0, 1

  lw    $v0, 0xc($v0)
.L7F08CF64:
  beql  $v0, $v1, .L7F08CF78
   move  $v0, $zero
  bnezl $v0, .L7F08CF30
   lw    $t7, ($v0)
.L7F08CF74:
  move  $v0, $zero
.L7F08CF78:
  jr    $ra
   nop   
");

/**
 * Is the player alive with flag tag token in inventory
 * @return TRUE/FALSE
 */
int bondinvIsAliveWithFlag(void) {
  if (!pPlayer->bonddead) {
    return is_weapon_in_inv(ITEM_TOKEN);
  }
  return 0;
}

/**
 * Is the Golden Gun in inventory
 * @return TRUE/FALSE
 */
int checkforgoldengun(void) { return is_weapon_in_inv(ITEM_GOLDENGUN); }

int sub_GAME_7F08CFE0(PropRecord *prop) {
  InvItem *item = pPlayer->ptr_inventory_first_in_cycle;
  while (item) {
    if (item->type == INV_ITEM_PROP &&
        item->type_inv_item.type_prop.prop == prop)
      return true;
    item = item->next;
    if (item == pPlayer->ptr_inventory_first_in_cycle)
      break;
  }
  return false;
}

#ifdef VERSION_US
asm(R"
glabel count_total_items_in_inventory
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  move  $v1, $zero
  lui   $t3, 4
  lw    $a0, 0x11ec($v0)
  li    $t2, 1
  li    $t1, 4
  beqz  $a0, .L7F08D060
   li    $t0, 2
  li    $v1, 32
.L7F08D060:
  lw    $a2, 0x11e0($v0)
  beqz  $a2, .L7F08D100
   move  $a1, $a2
  lw    $v0, ($a1)
.L7F08D070:
  bne   $t0, $v0, .L7F08D0C8
   nop   
  lw    $v0, 4($a1)
  lbu   $a3, ($v0)
  bne   $t1, $a3, .L7F08D0A4
   nop   
  lw    $a3, 4($v0)
  lw    $t6, 0x64($a3)
  andi  $t7, $t6, 0x400
  beql  $t7, $zero, .L7F08D0F0
   lw    $a1, 0xc($a1)
  b     .L7F08D0EC
   addiu $v1, $v1, 1
.L7F08D0A4:
  bnel  $t2, $a3, .L7F08D0F0
   lw    $a1, 0xc($a1)
  lw    $t8, 4($v0)
  lw    $t9, 0xc($t8)
  and   $t4, $t9, $t3
  bnezl $t4, .L7F08D0F0
   lw    $a1, 0xc($a1)
  b     .L7F08D0EC
   addiu $v1, $v1, 1
.L7F08D0C8:
  bnel  $t2, $v0, .L7F08D0F0
   lw    $a1, 0xc($a1)
  beql  $a0, $zero, .L7F08D0EC
   addiu $v1, $v1, 1
  lw    $t5, 4($a1)
  slti  $at, $t5, 0x21
  bnezl $at, .L7F08D0F0
   lw    $a1, 0xc($a1)
  addiu $v1, $v1, 1
.L7F08D0EC:
  lw    $a1, 0xc($a1)
.L7F08D0F0:
  beq   $a1, $a2, .L7F08D100
   nop   
  bnezl $a1, .L7F08D070
   lw    $v0, ($a1)
.L7F08D100:
  jr    $ra
   move  $v0, $v1
");
#endif

#ifdef VERSION_JP
asm(R"
glabel count_total_items_in_inventory
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  move  $v1, $zero
  lui   $t6, %hi(j_text_trigger) # $t6, 0x8005
  lw    $a0, 0x11ec($v0)
  lui   $t3, 4
  li    $t2, 1
  beqz  $a0, .Ljp7F08D9D8
   li    $t1, 4
  lw    $t6, %lo(j_text_trigger)($t6)
  li    $v1, 32
  beqz  $t6, .Ljp7F08D9D8
   nop   
  b     .Ljp7F08D9D8
   li    $v1, 31
.Ljp7F08D9D8:
  lw    $a2, 0x11e0($v0)
  li    $t0, 2
  beqz  $a2, .Ljp7F08DA7C
   move  $a1, $a2
  lw    $v0, ($a1)
.Ljp7F08D9EC:
  bne   $t0, $v0, .Ljp7F08DA44
   nop   
  lw    $v0, 4($a1)
  lbu   $a3, ($v0)
  bne   $t1, $a3, .Ljp7F08DA20
   nop   
  lw    $a3, 4($v0)
  lw    $t7, 0x64($a3)
  andi  $t8, $t7, 0x400
  beql  $t8, $zero, .Ljp7F08DA6C
   lw    $a1, 0xc($a1)
  b     .Ljp7F08DA68
   addiu $v1, $v1, 1
.Ljp7F08DA20:
  bnel  $t2, $a3, .Ljp7F08DA6C
   lw    $a1, 0xc($a1)
  lw    $t9, 4($v0)
  lw    $t4, 0xc($t9)
  and   $t5, $t4, $t3
  bnezl $t5, .Ljp7F08DA6C
   lw    $a1, 0xc($a1)
  b     .Ljp7F08DA68
   addiu $v1, $v1, 1
.Ljp7F08DA44:
  bnel  $t2, $v0, .Ljp7F08DA6C
   lw    $a1, 0xc($a1)
  beql  $a0, $zero, .Ljp7F08DA68
   addiu $v1, $v1, 1
  lw    $t6, 4($a1)
  slti  $at, $t6, 0x21
  bnezl $at, .Ljp7F08DA6C
   lw    $a1, 0xc($a1)
  addiu $v1, $v1, 1
.Ljp7F08DA68:
  lw    $a1, 0xc($a1)
.Ljp7F08DA6C:
  beq   $a1, $a2, .Ljp7F08DA7C
   nop   
  bnezl $a1, .Ljp7F08D9EC
   lw    $v0, ($a1)
.Ljp7F08DA7C:
  jr    $ra
   move  $v0, $v1
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08D108
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  slti  $at, $a0, 0x20
  lw    $v1, 0x11ec($v0)
  beql  $v1, $zero, .L7F08D134
   lw    $a2, 0x11e0($v0)
  beqz  $at, .L7F08D130
   addiu $a0, $a0, -0x20
  jr    $ra
   move  $v0, $zero

.L7F08D130:
  lw    $a2, 0x11e0($v0)
.L7F08D134:
  lui   $t3, 4
  li    $t2, 1
  beqz  $a2, .L7F08D210
   move  $a1, $a2
  li    $t1, 4
  li    $t0, 2
  lw    $v0, ($a1)
.L7F08D150:
  bne   $t0, $v0, .L7F08D1C8
   nop   
  lw    $v0, 4($a1)
  lbu   $a3, ($v0)
  bne   $t1, $a3, .L7F08D194
   nop   
  lw    $a3, 4($v0)
  lw    $t6, 0x64($a3)
  andi  $t7, $t6, 0x400
  beql  $t7, $zero, .L7F08D200
   lw    $a1, 0xc($a1)
  bnez  $a0, .L7F08D18C
   nop   
  jr    $ra
   move  $v0, $a1

.L7F08D18C:
  b     .L7F08D1FC
   addiu $a0, $a0, -1
.L7F08D194:
  bnel  $t2, $a3, .L7F08D200
   lw    $a1, 0xc($a1)
  lw    $t8, 4($v0)
  lw    $t9, 0xc($t8)
  and   $t4, $t9, $t3
  bnezl $t4, .L7F08D200
   lw    $a1, 0xc($a1)
  bnez  $a0, .L7F08D1C0
   nop   
  jr    $ra
   move  $v0, $a1

.L7F08D1C0:
  b     .L7F08D1FC
   addiu $a0, $a0, -1
.L7F08D1C8:
  bnel  $t2, $v0, .L7F08D200
   lw    $a1, 0xc($a1)
  beqz  $v1, .L7F08D1E8
   nop   
  lw    $t5, 4($a1)
  slti  $at, $t5, 0x21
  bnezl $at, .L7F08D200
   lw    $a1, 0xc($a1)
.L7F08D1E8:
  bnezl $a0, .L7F08D1FC
   addiu $a0, $a0, -1
  jr    $ra
   move  $v0, $a1

  addiu $a0, $a0, -1
.L7F08D1FC:
  lw    $a1, 0xc($a1)
.L7F08D200:
  beql  $a1, $a2, .L7F08D214
   move  $v0, $zero
  bnezl $a1, .L7F08D150
   lw    $v0, ($a1)
.L7F08D210:
  move  $v0, $zero
.L7F08D214:
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08D108
  lui   $v0, %hi(pPlayer) # $v0, 0x8008
  lw    $v0, %lo(pPlayer)($v0)
  move  $a2, $a0
  lui   $a0, %hi(j_text_trigger) # $a0, 0x8005
  lw    $v1, 0x11ec($v0)
  beql  $v1, $zero, .Ljp7F08DAE4
   lw    $a1, 0x11e0($v0)
  lw    $a0, %lo(j_text_trigger)($a0)
  li    $a1, 32
  beqz  $a0, .Ljp7F08DAB8
   nop   
  b     .Ljp7F08DAB8
   li    $a1, 31
.Ljp7F08DAB8:
  slt   $at, $a2, $a1
  beqz  $at, .Ljp7F08DACC
   nop   
  jr    $ra
   move  $v0, $zero

.Ljp7F08DACC:
  beqz  $a0, .Ljp7F08DADC
   li    $a1, 32
  b     .Ljp7F08DADC
   li    $a1, 31
.Ljp7F08DADC:
  subu  $a2, $a2, $a1
  lw    $a1, 0x11e0($v0)
.Ljp7F08DAE4:
  lui   $t3, 4
  li    $t2, 1
  beqz  $a1, .Ljp7F08DBC0
   move  $a0, $a1
  li    $t1, 4
  li    $t0, 2
  lw    $v0, ($a0)
.Ljp7F08DB00:
  bne   $t0, $v0, .Ljp7F08DB78
   nop   
  lw    $v0, 4($a0)
  lbu   $a3, ($v0)
  bne   $t1, $a3, .Ljp7F08DB44
   nop   
  lw    $a3, 4($v0)
  lw    $t6, 0x64($a3)
  andi  $t7, $t6, 0x400
  beql  $t7, $zero, .Ljp7F08DBB0
   lw    $a0, 0xc($a0)
  bnez  $a2, .Ljp7F08DB3C
   nop   
  jr    $ra
   move  $v0, $a0

.Ljp7F08DB3C:
  b     .Ljp7F08DBAC
   addiu $a2, $a2, -1
.Ljp7F08DB44:
  bnel  $t2, $a3, .Ljp7F08DBB0
   lw    $a0, 0xc($a0)
  lw    $t8, 4($v0)
  lw    $t9, 0xc($t8)
  and   $t4, $t9, $t3
  bnezl $t4, .Ljp7F08DBB0
   lw    $a0, 0xc($a0)
  bnez  $a2, .Ljp7F08DB70
   nop   
  jr    $ra
   move  $v0, $a0

.Ljp7F08DB70:
  b     .Ljp7F08DBAC
   addiu $a2, $a2, -1
.Ljp7F08DB78:
  bnel  $t2, $v0, .Ljp7F08DBB0
   lw    $a0, 0xc($a0)
  beqz  $v1, .Ljp7F08DB98
   nop   
  lw    $t5, 4($a0)
  slti  $at, $t5, 0x21
  bnezl $at, .Ljp7F08DBB0
   lw    $a0, 0xc($a0)
.Ljp7F08DB98:
  bnezl $a2, .Ljp7F08DBAC
   addiu $a2, $a2, -1
  jr    $ra
   move  $v0, $a0

  addiu $a2, $a2, -1
.Ljp7F08DBAC:
  lw    $a0, 0xc($a0)
.Ljp7F08DBB0:
  beql  $a0, $a1, .Ljp7F08DBC4
   move  $v0, $zero
  bnezl $a0, .Ljp7F08DB00
   lw    $v0, ($a0)
.Ljp7F08DBC0:
  move  $v0, $zero
.Ljp7F08DBC4:
  jr    $ra
   nop   
");
#endif

textoverride *get_textoverride_by_obj(ObjectRecord *obj) {

  textoverride *override = pPlayer->textoverrides;

  while (override) {

    if (override->obj == obj) {
      return override;
    }

    override = override->next;
  }

  return NULL;
}

textoverride *get_textoverride_by_weaponum(ITEM_IDS weaponnum) {

  textoverride *override = pPlayer->textoverrides;

  while (override) {

    if ((override->objoffset == 0) && (override->weapon == weaponnum)) {
      return override;
    }

    override = override->next;
  }

  return NULL;
}

#ifdef VERSION_US
int get_weaponnum_by_inv_index(int index) {

  textoverride *override;
  InvItem *inv_item;

  inv_item = sub_GAME_7F08D108(index);

  if (inv_item) {

    if (inv_item->type == INV_ITEM_PROP) {

      PropRecord *prop = inv_item->type_inv_item.type_prop.prop;

      override = get_textoverride_by_obj(prop->Entityp.obj);

      if (override) {
        return override->weapon;
      }

    } else if (inv_item->type == INV_ITEM_WEAPON) {
      return inv_item->type_inv_item.type_weap.weapon;
    }

  } else if ((pPlayer->equipallguns) && (index < ITEM_TANKSHELLS)) {
    return index + 1;
  }

  return 0;
}
#endif

#ifdef VERSION_JP
asm(R"
glabel get_weaponnum_by_inv_index
  addiu $sp, $sp, -0x18
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x18($sp)
  lw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08DCB4
   move  $v1, $v0
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .Ljp7F08DCA4
   li    $at, 1
  lw    $v0, 4($v0)
  jal   get_textoverride_by_obj
   lw    $a0, 4($v0)
  beql  $v0, $zero, .Ljp7F08DD18
   move  $v0, $zero
  b     .Ljp7F08DD18
   lw    $v0, 8($v0)
  li    $at, 1
.Ljp7F08DCA4:
  bnel  $a0, $at, .Ljp7F08DD18
   move  $v0, $zero
  b     .Ljp7F08DD18
   lw    $v0, 4($v1)
.Ljp7F08DCB4:
  lui   $t6, %hi(pPlayer) # $t6, 0x8008
  lw    $t6, %lo(pPlayer)($t6)
  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
  lw    $t7, 0x11ec($t6)
  beql  $t7, $zero, .Ljp7F08DD18
   move  $v0, $zero
  lw    $v0, %lo(j_text_trigger)($v0)
  li    $v1, 32
  beqz  $v0, .Ljp7F08DCE4
   nop   
  b     .Ljp7F08DCE4
   li    $v1, 31
.Ljp7F08DCE4:
  slt   $at, $a0, $v1
  beql  $at, $zero, .Ljp7F08DD18
   move  $v0, $zero
  beqz  $v0, .Ljp7F08DD0C
   addiu $t8, $a0, 1
  slti  $at, $t8, 2
  bnez  $at, .Ljp7F08DD0C
   nop   
  b     .Ljp7F08DD18
   addiu $v0, $a0, 2
.Ljp7F08DD0C:
  b     .Ljp7F08DD18
   addiu $v0, $a0, 1
  move  $v0, $zero
.Ljp7F08DD18:
  lw    $ra, 0x14($sp)
  addiu $sp, $sp, 0x18
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08D340
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .L7F08D3EC
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .L7F08D3B4
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .L7F08D41C
   move  $v1, $v0
  lw    $t6, 0x14($v0)
  beqz  $t6, .L7F08D3A8
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x14($v1)
  b     .L7F08D428
   lw    $ra, 0x14($sp)
.L7F08D3A8:
  b     .L7F08D41C
   lw    $a2, 8($v0)
  li    $at, 1
.L7F08D3B4:
  bne   $a0, $at, .L7F08D41C
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F08D41C
   lw    $a2, 0x18($sp)
  lw    $t7, 0x14($v0)
  beqz  $t7, .L7F08D41C
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x14($v0)
  b     .L7F08D428
   lw    $ra, 0x14($sp)
.L7F08D3EC:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  slti  $at, $a1, 0x20
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .L7F08D41C
   nop   
  beqz  $at, .L7F08D41C
   nop   
  jal   get_ptr_short_watch_text_for_item
   addiu $a0, $a1, 1
  b     .L7F08D428
   lw    $ra, 0x14($sp)
.L7F08D41C:
  jal   get_ptr_short_watch_text_for_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.L7F08D428:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08D340
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .Ljp7F08DDD4
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .Ljp7F08DD9C
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .Ljp7F08DE44
   move  $v1, $v0
  lw    $t6, 0x14($v0)
  beqz  $t6, .Ljp7F08DD90
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x14($v1)
  b     .Ljp7F08DE50
   lw    $ra, 0x14($sp)
.Ljp7F08DD90:
  b     .Ljp7F08DE44
   lw    $a2, 8($v0)
  li    $at, 1
.Ljp7F08DD9C:
  bne   $a0, $at, .Ljp7F08DE44
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08DE44
   lw    $a2, 0x18($sp)
  lw    $t7, 0x14($v0)
  beqz  $t7, .Ljp7F08DE44
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x14($v0)
  b     .Ljp7F08DE50
   lw    $ra, 0x14($sp)
.Ljp7F08DDD4:
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .Ljp7F08DE44
   nop   
  lw    $v0, %lo(j_text_trigger)($v0)
  li    $v1, 32
  beqz  $v0, .Ljp7F08DE04
   nop   
  b     .Ljp7F08DE04
   li    $v1, 31
.Ljp7F08DE04:
  slt   $at, $a1, $v1
  beqz  $at, .Ljp7F08DE44
   nop   
  beqz  $v0, .Ljp7F08DE34
   addiu $t0, $a1, 1
  slti  $at, $t0, 2
  bnez  $at, .Ljp7F08DE34
   nop   
  jal   get_ptr_short_watch_text_for_item
   addiu $a0, $a1, 2
  b     .Ljp7F08DE50
   lw    $ra, 0x14($sp)
.Ljp7F08DE34:
  jal   get_ptr_short_watch_text_for_item
   addiu $a0, $a1, 1
  b     .Ljp7F08DE50
   lw    $ra, 0x14($sp)
.Ljp7F08DE44:
  jal   get_ptr_short_watch_text_for_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.Ljp7F08DE50:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop     
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08D434
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .L7F08D4E0
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .L7F08D4A8
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .L7F08D510
   move  $v1, $v0
  lw    $t6, 0x18($v0)
  beqz  $t6, .L7F08D49C
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x18($v1)
  b     .L7F08D51C
   lw    $ra, 0x14($sp)
.L7F08D49C:
  b     .L7F08D510
   lw    $a2, 8($v0)
  li    $at, 1
.L7F08D4A8:
  bne   $a0, $at, .L7F08D510
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F08D510
   lw    $a2, 0x18($sp)
  lw    $t7, 0x18($v0)
  beqz  $t7, .L7F08D510
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x18($v0)
  b     .L7F08D51C
   lw    $ra, 0x14($sp)
.L7F08D4E0:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  slti  $at, $a1, 0x20
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .L7F08D510
   nop   
  beqz  $at, .L7F08D510
   nop   
  jal   get_ptr_long_watch_text_for_item
   addiu $a0, $a1, 1
  b     .L7F08D51C
   lw    $ra, 0x14($sp)
.L7F08D510:
  jal   get_ptr_long_watch_text_for_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.L7F08D51C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08D434
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .Ljp7F08DF08
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .Ljp7F08DED0
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .Ljp7F08DF78
   move  $v1, $v0
  lw    $t6, 0x18($v0)
  beqz  $t6, .Ljp7F08DEC4
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x18($v1)
  b     .Ljp7F08DF84
   lw    $ra, 0x14($sp)
.Ljp7F08DEC4:
  b     .Ljp7F08DF78
   lw    $a2, 8($v0)
  li    $at, 1
.Ljp7F08DED0:
  bne   $a0, $at, .Ljp7F08DF78
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08DF78
   lw    $a2, 0x18($sp)
  lw    $t7, 0x18($v0)
  beqz  $t7, .Ljp7F08DF78
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x18($v0)
  b     .Ljp7F08DF84
   lw    $ra, 0x14($sp)
.Ljp7F08DF08:
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .Ljp7F08DF78
   nop   
  lw    $v0, %lo(j_text_trigger)($v0)
  li    $v1, 32
  beqz  $v0, .Ljp7F08DF38
   nop   
  b     .Ljp7F08DF38
   li    $v1, 31
.Ljp7F08DF38:
  slt   $at, $a1, $v1
  beqz  $at, .Ljp7F08DF78
   nop   
  beqz  $v0, .Ljp7F08DF68
   addiu $t0, $a1, 1
  slti  $at, $t0, 2
  bnez  $at, .Ljp7F08DF68
   nop   
  jal   get_ptr_long_watch_text_for_item
   addiu $a0, $a1, 2
  b     .Ljp7F08DF84
   lw    $ra, 0x14($sp)
.Ljp7F08DF68:
  jal   get_ptr_long_watch_text_for_item
   addiu $a0, $a1, 1
  b     .Ljp7F08DF84
   lw    $ra, 0x14($sp)
.Ljp7F08DF78:
  jal   get_ptr_long_watch_text_for_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.Ljp7F08DF84:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop       
");
#endif

int sub_GAME_7F08D528(int index) {
  return get_45_degree_angle_0(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D550(int index) {
  return get_horizontal_offset_on_solo_watch_menu_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D578(int index) {
  return get_vertical_offset_on_solo_watch_menu_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D5A0(int index) {
  return get_depth_offset_solo_watch_menu_inventory_page_for_item(
      get_weaponnum_by_inv_index(index));
}

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08D5C8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .L7F08D674
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .L7F08D63C
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .L7F08D6A4
   move  $v1, $v0
  lw    $t6, 0xc($v0)
  beqz  $t6, .L7F08D630
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0xc($v1)
  b     .L7F08D6B0
   lw    $ra, 0x14($sp)
.L7F08D630:
  b     .L7F08D6A4
   lw    $a2, 8($v0)
  li    $at, 1
.L7F08D63C:
  bne   $a0, $at, .L7F08D6A4
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F08D6A4
   lw    $a2, 0x18($sp)
  lw    $t7, 0xc($v0)
  beqz  $t7, .L7F08D6A4
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0xc($v0)
  b     .L7F08D6B0
   lw    $ra, 0x14($sp)
.L7F08D674:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  slti  $at, $a1, 0x20
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .L7F08D6A4
   nop   
  beqz  $at, .L7F08D6A4
   nop   
  jal   get_ptr_first_title_line_item
   addiu $a0, $a1, 1
  b     .L7F08D6B0
   lw    $ra, 0x14($sp)
.L7F08D6A4:
  jal   get_ptr_first_title_line_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.L7F08D6B0:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08D5C8
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .Ljp7F08E0DC
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .Ljp7F08E0A4
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .Ljp7F08E14C
   move  $v1, $v0
  lw    $t6, 0xc($v0)
  beqz  $t6, .Ljp7F08E098
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0xc($v1)
  b     .Ljp7F08E158
   lw    $ra, 0x14($sp)
.Ljp7F08E098:
  b     .Ljp7F08E14C
   lw    $a2, 8($v0)
  li    $at, 1
.Ljp7F08E0A4:
  bne   $a0, $at, .Ljp7F08E14C
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08E14C
   lw    $a2, 0x18($sp)
  lw    $t7, 0xc($v0)
  beqz  $t7, .Ljp7F08E14C
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0xc($v0)
  b     .Ljp7F08E158
   lw    $ra, 0x14($sp)
.Ljp7F08E0DC:
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .Ljp7F08E14C
   nop   
  lw    $v0, %lo(j_text_trigger)($v0)
  li    $v1, 32
  beqz  $v0, .Ljp7F08E10C
   nop   
  b     .Ljp7F08E10C
   li    $v1, 31
.Ljp7F08E10C:
  slt   $at, $a1, $v1
  beqz  $at, .Ljp7F08E14C
   nop   
  beqz  $v0, .Ljp7F08E13C
   addiu $t0, $a1, 1
  slti  $at, $t0, 2
  bnez  $at, .Ljp7F08E13C
   nop   
  jal   get_ptr_first_title_line_item
   addiu $a0, $a1, 2
  b     .Ljp7F08E158
   lw    $ra, 0x14($sp)
.Ljp7F08E13C:
  jal   get_ptr_first_title_line_item
   addiu $a0, $a1, 1
  b     .Ljp7F08E158
   lw    $ra, 0x14($sp)
.Ljp7F08E14C:
  jal   get_ptr_first_title_line_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.Ljp7F08E158:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop       
");
#endif

#ifdef VERSION_US
asm(R"
glabel sub_GAME_7F08D6BC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .L7F08D768
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .L7F08D730
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .L7F08D798
   move  $v1, $v0
  lw    $t6, 0x10($v0)
  beqz  $t6, .L7F08D724
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x10($v1)
  b     .L7F08D7A4
   lw    $ra, 0x14($sp)
.L7F08D724:
  b     .L7F08D798
   lw    $a2, 8($v0)
  li    $at, 1
.L7F08D730:
  bne   $a0, $at, .L7F08D798
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .L7F08D798
   lw    $a2, 0x18($sp)
  lw    $t7, 0x10($v0)
  beqz  $t7, .L7F08D798
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x10($v0)
  b     .L7F08D7A4
   lw    $ra, 0x14($sp)
.L7F08D768:
  lui   $t8, %hi(pPlayer) 
  lw    $t8, %lo(pPlayer)($t8)
  slti  $at, $a1, 0x20
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .L7F08D798
   nop   
  beqz  $at, .L7F08D798
   nop   
  jal   get_ptr_second_title_line_item
   addiu $a0, $a1, 1
  b     .L7F08D7A4
   lw    $ra, 0x14($sp)
.L7F08D798:
  jal   get_ptr_second_title_line_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.L7F08D7A4:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop   
");
#endif

#ifdef VERSION_JP
asm(R"
glabel sub_GAME_7F08D6BC
  addiu $sp, $sp, -0x20
  sw    $ra, 0x14($sp)
  jal   sub_GAME_7F08D108
   sw    $a0, 0x20($sp)
  lw    $a1, 0x20($sp)
  move  $v1, $v0
  beqz  $v0, .Ljp7F08E210
   move  $a2, $zero
  lw    $a0, ($v0)
  li    $at, 2
  bnel  $a0, $at, .Ljp7F08E1D8
   li    $at, 1
  lw    $v0, 4($v0)
  lw    $a0, 4($v0)
  jal   get_textoverride_by_obj
   sw    $zero, 0x18($sp)
  lw    $a2, 0x18($sp)
  beqz  $v0, .Ljp7F08E280
   move  $v1, $v0
  lw    $t6, 0x10($v0)
  beqz  $t6, .Ljp7F08E1CC
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x10($v1)
  b     .Ljp7F08E28C
   lw    $ra, 0x14($sp)
.Ljp7F08E1CC:
  b     .Ljp7F08E280
   lw    $a2, 8($v0)
  li    $at, 1
.Ljp7F08E1D8:
  bne   $a0, $at, .Ljp7F08E280
   nop   
  lw    $a0, 4($v1)
  jal   get_textoverride_by_weaponum
   sw    $a0, 0x18($sp)
  beqz  $v0, .Ljp7F08E280
   lw    $a2, 0x18($sp)
  lw    $t7, 0x10($v0)
  beqz  $t7, .Ljp7F08E280
   nop   
  jal   get_textptr_for_textID
   lw    $a0, 0x10($v0)
  b     .Ljp7F08E28C
   lw    $ra, 0x14($sp)
.Ljp7F08E210:
  lui   $t8, %hi(pPlayer) # $t8, 0x8008
  lw    $t8, %lo(pPlayer)($t8)
  lui   $v0, %hi(j_text_trigger) # $v0, 0x8005
  lw    $t9, 0x11ec($t8)
  beqz  $t9, .Ljp7F08E280
   nop   
  lw    $v0, %lo(j_text_trigger)($v0)
  li    $v1, 32
  beqz  $v0, .Ljp7F08E240
   nop   
  b     .Ljp7F08E240
   li    $v1, 31
.Ljp7F08E240:
  slt   $at, $a1, $v1
  beqz  $at, .Ljp7F08E280
   nop   
  beqz  $v0, .Ljp7F08E270
   addiu $t0, $a1, 1
  slti  $at, $t0, 2
  bnez  $at, .Ljp7F08E270
   nop   
  jal   get_ptr_second_title_line_item
   addiu $a0, $a1, 2
  b     .Ljp7F08E28C
   lw    $ra, 0x14($sp)
.Ljp7F08E270:
  jal   get_ptr_second_title_line_item
   addiu $a0, $a1, 1
  b     .Ljp7F08E28C
   lw    $ra, 0x14($sp)
.Ljp7F08E280:
  jal   get_ptr_second_title_line_item
   move  $a0, $a2
  lw    $ra, 0x14($sp)
.Ljp7F08E28C:
  addiu $sp, $sp, 0x20
  jr    $ra
   nop      
");
#endif

int sub_GAME_7F08D7B0(int index) {
  return get_45_degree_angle(get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D7D8(int index) {
  return get_vertical_position_solo_watch_menu_main_page_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D800(int index) {
  return get_lateral_position_solo_watch_menu_main_page_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D828(int index) {
  return get_depth_on_solo_watch_menu_page_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D850(int index) {
  return get_xrotation_solo_watch_menu_for_item(
      get_weaponnum_by_inv_index(index));
}

int sub_GAME_7F08D878(int index) {
  return get_yrotation_solo_watch_menu_for_item(
      get_weaponnum_by_inv_index(index));
}

void sub_GAME_7F08D8A0(textoverride *override) {
  override->next = pPlayer->textoverrides;
  pPlayer->textoverrides = override;
}

int get_BONDdata_equipcuritem(void) { return pPlayer->equipcuritem; }

void set_BONDdata_equipcuritem(int current_item) {
  pPlayer->equipcuritem = current_item;
}

void calculate_equip_cur_item(void) {
  int current_weapon, i;
  current_weapon = get_item_in_hand(RIGHT_HAND);
  pPlayer->equipcuritem = 0;
  for (i = 0; i < count_total_items_in_inventory(); i++) {
    if (get_weaponnum_by_inv_index(i) == current_weapon) {
      pPlayer->equipcuritem = i;
      return;
    }
  }
}

char *obj_get_activated_text(ObjectRecord *obj) {
  textoverride *override = get_textoverride_by_obj(obj);
  if (override && override->unk8)
    return get_textptr_for_textID(override->unk8);
  return NULL;
}

char *weapon_get_activated_text(ITEM_IDS weaponnum) {
  textoverride *override = get_textoverride_by_weaponum(weaponnum);
  if (override && override->unk8)
    return get_textptr_for_textID(override->unk8);
  return NULL;
}

asm(R"
glabel sub_GAME_7F08D9EC
  addiu $sp, $sp, -0x28
  sw    $s0, 0x14($sp)
  move  $s0, $a1
  sw    $ra, 0x1c($sp)
  sw    $s1, 0x18($sp)
  move  $s1, $a0
  jal   check_special_attributes
   lui   $a1, 2
  beqz  $v0, .L7F08DAF4
   lui   $a2, (0x7FFFFFFF >> 16) # lui $a2, 0x7fff
  ori   $a2, (0x7FFFFFFF & 0xFFFF) # ori $a2, $a2, 0xffff
  sw    $a2, 0x24($sp)
  move  $a0, $s0
  lui   $a1, 2
  jal   check_special_attributes
   sw    $zero, 0x20($sp)
  lw    $a2, 0x24($sp)
  bnez  $v0, .L7F08DA3C
   lw    $a3, 0x20($sp)
  move  $s0, $zero
.L7F08DA3C:
  lui   $v0, %hi(pPlayer)
  lw    $v0, %lo(pPlayer)($v0)
  move  $a0, $zero
.L7F08DA48:
  lw    $v1, 0x1200($v0)
  bltz  $v1, .L7F08DA90
   slt   $at, $v1, $a2
  lw    $t6, 0x11f8($v0)
  bne   $s1, $t6, .L7F08DA7C
   nop   
  lw    $t7, 0x11fc($v0)
  bne   $s0, $t7, .L7F08DA7C
   lui   $t8, %hi(clock_timer) 
  lw    $t8, %lo(clock_timer)($t8)
  addu  $t9, $v1, $t8
  b     .L7F08DAAC
   sw    $t9, 0x1200($v0)
.L7F08DA7C:
  beql  $at, $zero, .L7F08DAA0
   addiu $a0, $a0, 1
  move  $a2, $v1
  b     .L7F08DA9C
   move  $a3, $a0
.L7F08DA90:
  move  $a3, $a0
  b     .L7F08DAAC
   li    $a0, 10
.L7F08DA9C:
  addiu $a0, $a0, 1
.L7F08DAA0:
  slti  $at, $a0, 0xa
  bnez  $at, .L7F08DA48
   addiu $v0, $v0, 0xc
.L7F08DAAC:
  li    $at, 10
  bne   $a0, $at, .L7F08DAF4
   lui   $v1, %hi(pPlayer)
  addiu $v1, %lo(pPlayer) # addiu $v1, $v1, -0x5f50
  lw    $t1, ($v1)
  sll   $v0, $a3, 2
  lui   $t0, %hi(clock_timer) 
  lw    $t0, %lo(clock_timer)($t0)
  subu  $v0, $v0, $a3
  sll   $v0, $v0, 2
  addu  $t2, $t1, $v0
  sw    $t0, 0x1200($t2)
  lw    $t3, ($v1)
  addu  $t4, $t3, $v0
  sw    $s1, 0x11f8($t4)
  lw    $t5, ($v1)
  addu  $t6, $t5, $v0
  sw    $s0, 0x11fc($t6)
.L7F08DAF4:
  lw    $ra, 0x1c($sp)
  lw    $s0, 0x14($sp)
  lw    $s1, 0x18($sp)
  jr    $ra
   addiu $sp, $sp, 0x28
");

asm(R"
glabel sub_GAME_7F08DB08
  sw    $zero, ($a0)
  lui   $t0, %hi(pPlayer) 
  li    $v0, -1
  sw    $zero, ($a1)
  addiu $t0, %lo(pPlayer) # addiu $t0, $t0, -0x5f50
  move  $a2, $zero
  li    $t1, 120
  lw    $t6, ($t0)
.L7F08DB28:
  addu  $v1, $t6, $a2
  lw    $a3, 0x1200($v1)
  bltz  $a3, .L7F08DB64
   slt   $at, $v0, $a3
  beql  $at, $zero, .L7F08DB68
   lw    $a3, 0x120c($v1)
  lw    $t7, 0x11f8($v1)
  move  $v0, $a3
  sw    $t7, ($a0)
  lw    $t8, ($t0)
  addu  $t9, $t8, $a2
  lw    $t2, 0x11fc($t9)
  sw    $t2, ($a1)
  lw    $t3, ($t0)
  addu  $v1, $t3, $a2
.L7F08DB64:
  lw    $a3, 0x120c($v1)
.L7F08DB68:
  bltz  $a3, .L7F08DB94
   slt   $at, $v0, $a3
  beql  $at, $zero, .L7F08DB98
   addiu $a2, $a2, 0x18
  lw    $t4, 0x1204($v1)
  move  $v0, $a3
  sw    $t4, ($a0)
  lw    $t5, ($t0)
  addu  $t6, $t5, $a2
  lw    $t7, 0x1208($t6)
  sw    $t7, ($a1)
.L7F08DB94:
  addiu $a2, $a2, 0x18
.L7F08DB98:
  bnel  $a2, $t1, .L7F08DB28
   lw    $t6, ($t0)
  jr    $ra
   nop   
");
