
.section .text, "ax"

# The entry-point. Blanks 8005D2E0-8008E360, sets SP->803AB410, JR to 80000450.
glabel _start
  lui   $t0, %hi(_bssSegmentStart) 
  lui   $t1, %hi(_bssSegmentSize) # lui $t1, 3
  addiu $t0, %lo(_bssSegmentStart) # addiu $t0, $t0, -0x2d20
  ori   $t1, %lo(_bssSegmentSize) # ori $t1, $t1, 0x1080

.L80000410:
  addi  $t1, $t1, -8
  sw    $zero, ($t0)
  sw    $zero, 4($t0)
  bnez  $t1, .L80000410
  addi  $t0, $t0, 8
  lui   $t2, %hi(_boot_function) 
  lui   $sp, %hi(sp_rmon) # $sp, 0x803b
  addiu $t2, %lo(_boot_function) # addiu $t2, $t2, 0x450
  jr    $t2
  addiu $sp, %lo(sp_rmon) # addiu $sp, $sp, -0x4bf0
  nop   
  nop   
  nop   
  nop   
  nop   
  nop 

_boot_function: # hack to fill and get us to first function of file boot0 using vaddr of 0x80000450.
.section .data
.section .rodata
.section .bss
