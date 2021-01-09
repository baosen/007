package statements

import (
	"mips2ir/reassembler"
)

var function string
var opcode string
var operands []string
var constant string

func reset() {
	function = ""
	opcode = ""
	operands = []string{}
	constant = ""
}

func BuildInstruction() {
	if len(opcode) <= 0 {
		panic("opcode is of length 0")
	}

	switch len(operands) {
	case 0:
		reassembler.ReassembleInstruction0(opcode)
	case 1:
		if constant != "" {
			reassembler.ReassembleInstruction2Constant(opcode, operands[0], constant)
		} else {
			reassembler.ReassembleInstruction1(opcode, operands[0])
		}
	case 2:
		reassembler.ReassembleInstruction2(opcode, operands[0], operands[1])
	case 3:
		reassembler.ReassembleInstruction3(opcode, operands[0], operands[1], operands[2])
	default:
		panic("too many operands in instruction")
	}
	reset()
}

func BuildFunction(name string) {
	reassembler.ReassembleFunction(function)
	BuildInstruction()
}

func BuildInstruction0(op string) {
	opcode = op
}

func BuildInstruction1(op, firstOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
}

func BuildInstruction1Constant(op, firstOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
}

func BuildInstruction2(op, firstOperand, secondOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
	operands = append(operands, secondOperand)
}

func BuildInstructionHi(op, firstOperand, secondOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
	operands = append(operands, secondOperand)
}

func BuildInstructionLo(op, firstOperand, secondOperand, thirdOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
	operands = append(operands, secondOperand)
	operands = append(operands, thirdOperand)
}

func BuildInstruction3(op, firstOperand, secondOperand, thirdOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
	operands = append(operands, secondOperand)
	operands = append(operands, thirdOperand)
}

func BuildInstruction2Constant(op, firstOperand, secondOperand string) {
	opcode = op
	operands = append(operands, firstOperand)
	constant = secondOperand
}

func BuildLabelInstruction(instruction string) {}
