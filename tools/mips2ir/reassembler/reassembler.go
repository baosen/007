package reassembler

import (
	"fmt"

	"github.com/llir/llvm/ir"
	"github.com/llir/llvm/ir/constant"
	"github.com/llir/llvm/ir/types"
	"github.com/llir/llvm/ir/value"
)

var mainModule *ir.Module
var f *ir.Func
var b *ir.Block

var registers map[string]value.Value

func initializeRegisters() {
	if registers == nil {
		registers = make(map[string]value.Value)
		registers["$v0"] = constant.NewInt(types.I32, 42)
	}
}

func initialize() {
	if mainModule == nil {
		mainModule = ir.NewModule()
	}
	initializeRegisters()
}

func Print() string {
	initialize()
	return fmt.Sprintf("%s", mainModule)
}

func ReassembleFunction(name string) {
	initialize()
	f = mainModule.NewFunc(name, types.I32)
	b = f.NewBlock(name)
}

func ReassembleInstruction0(opcode string) {
	initialize()

	switch opcode {
	case "nop":
		// just skip no op's.
	default:
		panic(fmt.Sprintf("unknown opcode with 0 operands: %v", opcode))
	}
}

func ReassembleInstruction1(opcode, operand string) {
	initialize()

	switch opcode {
	case "jr":
		if operand != "$ra" {
			panic("opcode jr needs to have register $ra as operand")
		}
		value, ok := registers["$v0"]
		if !ok {
			panic("$v0 does not exist")
		}
		b.NewRet(value)
	case "li":
	default:
		panic(fmt.Sprintf("unknown opcode with 1 operand: %v", opcode))
	}
}

func ReassembleInstruction2(opcode, firstOperand, secondOperand string) {
	initialize()

	switch opcode {
	case "lui":
	case "ld":
	case "sd":
	default:
		panic(fmt.Sprintf("unknown opcode with 2 operands: %v", opcode))
	}
}

func ReassembleInstruction3(opcode, firstOperand, secondOperand, thirdOperand string) {
	initialize()

	switch opcode {
	case "ld":
	case "sd":
	case "add":
		registers[firstOperand] = b.NewAdd(constant.NewInt(types.I32, 3), constant.NewInt(types.I32, 3))
	case "or":
	case "xor":
	case "andi":
	default:
		panic(fmt.Sprintf("unknown opcode with 3 operands: %v", opcode))
	}
}

func ReassembleInstruction2Constant(opcode, firstOperand, secondOperand string) {
	initialize()

	switch opcode {
	case "andi":
	case "dsra32":
	case "daddiu":
	case "dsrl32":
	case "dsll32":
	case "dsll":
	case "dsrl":
	default:
		panic(fmt.Sprintf("unknown opcode with 2 operands and 1 constant: %v", opcode))
	}
}
