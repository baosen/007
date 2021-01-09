%{
package frontend

import (
    "mips2ir/statements"
)
%}

%union{
    val string
}
%type <val> Statement Instruction Constant
%token <val> LABEL OPCODE REGISTER DECIMAL HEXADECIMAL GLABEL IDENTIFIER ',' '(' ')' HI LO

%%
Statements: /* zero token */
| Statement Statements
;

Statement: GLABEL IDENTIFIER Instruction
{
    statements.BuildFunction($2)
}
| Instruction
{
    statements.BuildInstruction()
}
| LABEL Instruction
{
    statements.BuildLabelInstruction($1)
}
;

Instruction: OPCODE
{
    statements.BuildInstruction0($1)
}
| OPCODE REGISTER ',' Constant
{
    statements.BuildInstruction1Constant($1, $3)
}
| OPCODE REGISTER
{
    statements.BuildInstruction1($1, $2)
}
| OPCODE REGISTER ',' REGISTER
{
    statements.BuildInstruction2($1, $2, $3)
}
| OPCODE REGISTER ',' '(' REGISTER ')'
{
    statements.BuildInstruction2($1, $2, $3)
}
| OPCODE REGISTER ',' HI '(' IDENTIFIER ')'
{
    statements.BuildInstructionHi($1, $2, $6)
}
| OPCODE REGISTER ',' LO '(' IDENTIFIER ')' '(' REGISTER ')'
{
    statements.BuildInstructionLo($1, $2, $6, $9)
}
| OPCODE REGISTER ',' REGISTER ',' REGISTER
{
    statements.BuildInstruction3($1, $2, $4, $5)
}
| OPCODE REGISTER ',' REGISTER ',' Constant
{
    statements.BuildInstruction2Constant($1, $2, $3)
}
;

Constant: DECIMAL | HEXADECIMAL
;
%%
