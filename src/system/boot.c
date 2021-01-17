// This file sets up initial TLB mapping then jumps to boot1.

// This is where _start jumps to.
asm(R"
glabel boot
  li    $v0, 1
  li    $v1, 0
  li    $a0, 0
  lui   $a1, 0x7000
  li    $a2, 31
  li    $a3, 1
  lui   $t0, (0x007FE000 >> 16) # lui $t0, 0x7f
  ori   $t0, (0x007FE000 & 0xFFFF) # ori $t0, $t0, 0xe000
  mtc0  $v0, $0
  srl   $v1, $v1, 0xc
  sll   $v1, $v1, 6
  addu  $v1, $v1, $a2
  mtc0  $v1, $2
  srl   $a0, $a0, 0xc
  sll   $a0, $a0, 6
  addu  $a0, $a0, $a3
  mtc0  $a0, $3
  srl   $a0, $a1, 0xd
  sll   $a0, $a0, 0xd
  mtc0  $a0, $10
  mtc0  $t0, $5
  nop
  tlbwi 
  lui   $t2, %hi(init) # $t2, 0x7000
  addiu $t2, %lo(init) # addiu $t2, $t2, 0x510
  jr    $t2
  nop
");

extern void *_compressedSegmentStart;
extern void *_cdataRomSegmentStart;
extern void *_cdataRomSegmentEnd;
extern void *_inflateRomSegmentStart;
extern void *_inflateRomSegmentEnd;

/*
 * Due to alignments the following functions are included here
 * these could have been assembly originally, or more likely part
 * of the code inserted by the custom makerom rare created
 */

// Returns the start memory address of the compressed .text segment (USA).
void *get_csegmentSegmentStart(void) { return &_compressedSegmentStart; }

// Returns the start memory address of the compressed .data segment (USA).
void *get_cdataRomSegmentStart(void) { return &_cdataRomSegmentStart; }

// Returns the end memory address of the compressed .data segment (USA).
void *get_cdataRomSegmentEnd(void) { return &_cdataRomSegmentEnd; }

// Returns the start memory address of the DEFLATE compression functions.
void *get_inflateRomSegmentStart(void) { return &_inflateRomSegmentStart; }

// Returns the end memory address of the DEFLATE compression functions.
void *get_inflateRomSegmentEnd(void) { return &_inflateRomSegmentEnd; }

/*
 * Redirects to decompression routine.
 *
 * Accepts: A0=p->source, A1=p->target, A2=p->buffer sets A3=7020141C, then
 * jumps to address.
 */
asm(R"
glabel jump_decompressfile
  lui   $a3, %hi(decompress_entry) # $a3, 0x7020
  addiu $a3, %lo(decompress_entry) # addiu $a3, $a3, 0x141c
  jr    $a3
  nop
");
