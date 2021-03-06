package opcodes

var opcodes = []string{
	"add",
	"addu",
	"and",
	"andi",
	"b",
	"beq",
	"beql",
	"beqz",
	"bgez",
	"bgezl",
	"bgtz",
	"bgtzl",
	"blez",
	"blezl",
	"bltz",
	"bltzl",
	"bne",
	"bnel",
	"bnez",
	"bnezl",
	"break",
	"cfc1",
	"ctc1",
	"daddiu",
	//"daddu",
	//"ddiv",
	//"ddivu",
	"div",
	"divu",
	"dmfc1",
	"dmtc1",
	//"dmultu",
	"dsll",
	//"dsllv",
	"dsll32",
	"dsra32",
	"dsrl",
	//"dsrlv",
	"dsrl32",
	//"eret",
	"j",
	"jr",
	"jal",
	"jalr",
	"lb",
	"lbu",
	"ld",
	"lh",
	"lhu",
	"li",
	"lui",
	"lw",
	"lwc1",
	"lwl",
	"lwr",
	//"mfc0",
	"mfc1",
	"mfhi",
	"mflo",
	"move",
	//"mtc0",
	"mtc1",
	//"mthi",
	//"mtlo",
	//"mul",
	"multu",
	"neg",
	"negu",
	"nop",
	"nor",
	"not",
	"or",
	"ori",
	"sb",
	"sd",
	"sdc1",
	"sh",
	"sll",
	"sllv",
	"slt",
	"slti",
	"sltiu",
	"sltu",
	"sra",
	"srav",
	"srl",
	"srlv",
	"sub",
	"subu",
	"sw",
	"swc1",
	"swl",
	"swr",
	"xor",
	"xori",
	"ldc1",
	//"mov.s",
	//"mul.s",
	//"neg.s",
	//"round.w.s",
	//"sqrt.s",
	//"sub.s",
	//"trunc.l.d",
	//"trunc.l.s",
	//"add.s",
	//"c.eq.s",
	//"c.le.s",
	//"c.lt.s",
	//"cvt.d.l",
	//"cvt.d.s",
	//"cvt.d.w",
	//"cvt.l.d",
	//"cvt.l.s",
	//"cvt.s.d",
	//"cvt.s.l",
	//"cvt.s.w",
	//"cvt.w.d",
	//"cvt.w.s",
	//"div.s",
}

func GetOpcodes() []string {
	return opcodes
}

func GetOpcodeRegex() string {
	s := "("
	for i, opcode := range opcodes {
		if i == len(opcodes)-1 {
			s += opcode + ")"
			break
		}
		s += opcode + "|"
	}
	return s
}
