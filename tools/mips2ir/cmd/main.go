package main

import (
	"io/ioutil"
	"mips2ir/opcodes"
	"os"
	"text/template"
)

func main() {
	file, err := os.Open(os.Args[1])
	if err != nil {
		panic(err)
	}
	s, err := ioutil.ReadAll(file)
	if err != nil {
		panic(err)
	}
	lexer, err := template.New("opcodes").Parse(string(s))
	if err != nil {
		panic(err)
	}
	_opcodes := struct {
		Opcodes string
	}{
		Opcodes: opcodes.GetOpcodeRegex(),
	}
	if err := lexer.Execute(os.Stdout, _opcodes); err != nil {
		panic(err)
	}
}
