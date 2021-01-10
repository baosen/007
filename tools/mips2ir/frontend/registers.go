package frontend

import "fmt"

func getMipsRegisters() []string {
	allRegisters := []string{
		"$zero",
		"$gp",
		"$sp",
		"$fp",
		"$ra",
		"$at",
	}
	for i := 0; i <= 1; i++ {
		allRegisters = append(allRegisters, fmt.Sprintf("$v%d", i))
	}
	for i := 0; i <= 3; i++ {
		allRegisters = append(allRegisters, fmt.Sprintf("$a%d", i))
	}
	for i := 0; i <= 9; i++ {
		allRegisters = append(allRegisters, fmt.Sprintf("$t%d", i))
	}
	for i := 0; i <= 8; i++ {
		allRegisters = append(allRegisters, fmt.Sprintf("$s%d", i))
	}
	return allRegisters
}
