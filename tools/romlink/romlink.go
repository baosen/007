package main

import (
	"romlink/rom"
)

func compileRomlinkInput(inputString string) {
	printHeader()
	rom.Parse(inputString)
	printEnd()
}
