.section .romfiles, "a"

.global _Globalimagetablecmdblk
_Globalimagetablecmdblk:
    .incbin "Globalimagetable_commandblock.bin"

.global unknown2
unknown2:
    .incbin "2A4D50.usedby7F008DE4.bin"
