package frontend

import (
	"testing"
)

func TestParsingInstruction(t *testing.T) {
	program := `
glabel sub_GAME_800asdasd
	add $t0, $t1, $t2
`
	Parse(program)
}

func TestParsingInstructionWithLabel(t *testing.T) {
	program := `
.L1234ABCD:
	addu $t3, $t2, $t1
`
	Parse(program)
}
