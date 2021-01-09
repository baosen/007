.section .font

.global _fonttablectlsmall1
_fonttablectlsmall1:
    .incbin "first_font_table_controller_small.bin"
    .incbin "second_font_table_controller_small.bin"

.global _fonttablectllarge1
_fonttablectllarge1:
    .incbin "first_font_table_controller_large.bin"
    .incbin "second_font_table_controller_large.bin"
