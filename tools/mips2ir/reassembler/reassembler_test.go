package reassembler_test

import (
	"mips2ir/frontend"
	"testing"
)

func TestReassembleAdd(t *testing.T) {
	program :=
		`
glabel sub_GAME_800asdasd
	add $t3, $t2, $t1
	add $t3, $t2, $t1
`
	frontend.Parse(program)
}
