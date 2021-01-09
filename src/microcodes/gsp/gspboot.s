
.section .text, "ax"
glabel gsp3DTextStart
.incbin "gspboot.text.bin"

.section .data
glabel gsp3DDataStart
.incbin "gspboot.data.bin"

.section .rodata
.section .bss
