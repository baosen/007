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

func TestZeroRegister(t *testing.T) {
	if Lex("$zero") != REGISTER {
		t.FailNow()
	}
}

func TestGpRegister(t *testing.T) {
	if Lex("$gp") != REGISTER {
		t.FailNow()
	}
}

func TestSpRegister(t *testing.T) {
	if Lex("$sp") != REGISTER {
		t.FailNow()
	}
}

func TestFpRegister(t *testing.T) {
	if Lex("$fp") != REGISTER {
		t.FailNow()
	}
}

func TestRaRegister(t *testing.T) {
	if Lex("$ra") != REGISTER {
		t.FailNow()
	}
}

func TestAtRegister(t *testing.T) {
	if Lex("$at") != REGISTER {
		t.FailNow()
	}
}

func TestVRegisters(t *testing.T) {
	for i := 0; i <= 1; i++ {
		if Lex(fmt.Sprintf("$v%d", i)) != REGISTER {
			t.FailNow()
		}
	}
}

func TestARegisters(t *testing.T) {
	for i := 0; i <= 3; i++ {
		if Lex(fmt.Sprintf("$a%d", i)) != REGISTER {
			t.FailNow()
		}
	}
}

func TestTRegisters(t *testing.T) {
	for i := 0; i <= 9; i++ {
		if Lex(fmt.Sprintf("$t%d", i)) != REGISTER {
			t.FailNow()
		}
	}
}

func TestSRegisters(t *testing.T) {
	for i := 0; i <= 8; i++ {
		if Lex(fmt.Sprintf("$s%d", i)) != REGISTER {
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
