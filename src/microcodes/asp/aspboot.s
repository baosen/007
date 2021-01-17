.section .text

glabel aspMainTextStart
.incbin "aspboot.text.bin"

glabel unknown_init_val
.word 2

glabel cart_hw_address
.word 0x10000000

glabel debug_handler_table 
.word sp_boot, aBoot
.word sp_rmon, aRmon
.word sp_idle, aIdle
.word sp_shed, aShed
.word sp_main, aMain
.word sp_audi, aAudi
.word 0, 0
.word 0, 0

.section .rodata
glabel aBoot
.word 0x626F6F74, 0x00000000

glabel aRmon
.word 0x726D6F6E, 0x00000000

glabel aIdle
.word 0x69646C65, 0x00000000

glabel aShed
.word 0x73686564, 0x00000000

glabel aMain
.word 0x6D61696E, 0x00000000

glabel aAudi
.word 0x61756469, 0x00000000

.section .data

glabel aspMainDataStart
.incbin "aspboot.data.bin"

.section .rodata
.section .bss
