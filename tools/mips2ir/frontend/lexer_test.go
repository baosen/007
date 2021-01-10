package frontend

import (
	"fmt"
	"mips2ir/opcodes"
	"testing"
)

func Lex(s string) int {
	m := mipsLexer{input: s}
	return m.Lex(&yySymType{})
}

func TestMipsRegisters(t *testing.T) {
	for _, register := range getMipsRegisters() {
		if Lex(register) != REGISTER {
			t.FailNow()
		}
	}
}

func TestGlobalLabel(t *testing.T) {
	if Lex("glabel sub_GAME_7F0B39BC") != GLABEL {
		t.FailNow()
	}
}

func TestLabel(t *testing.T) {
	if Lex(".L7F0B38D4:") != LABEL {
		t.FailNow()
	}
}

func TestOpcodes(t *testing.T) {
	for _, opcode := range opcodes.GetOpcodes() {
		if Lex(fmt.Sprintf("%s\n", opcode)) != OPCODE {
			t.FailNow()
		}
	}
}
