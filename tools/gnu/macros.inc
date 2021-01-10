# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64
.macro glabel label
    .global \label
    \label:
.endm
