package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"

	"mips2ir/frontend"
	"mips2ir/reassembler"
)

// die prints an error to standard error and exit with error number.
func die(err error) {
	fmt.Fprintf(os.Stderr, "error: %v\n", err)
	os.Exit(1)
}

// compile compiles LLVM IR to your computers native assembly.
func compile(llvmir string) string {
	cmd := exec.Command("sh", "-c", "llvm-as-11 | llc")
	stdin, err := cmd.StdinPipe()
	if err != nil {
		die(err)
	}
	go func() {
		defer stdin.Close()
		io.WriteString(stdin, llvmir)
	}()
	out, err := cmd.Output()
	if err != nil {
		die(err)
	}
	return string(out)
}

// reassembleAndPrint translates MIPS assembler to LLVM IR and prints it out.
func reassembleAndPrint(assemblys []string) {
	fmt.Println("asm(R\"(")
	for _, assembly := range assemblys {
		if frontend.Parse(assembly) != 0 {
			die(fmt.Errorf("failed to parse program"))
		}
	}
	fmt.Print(compile(reassembler.Print()))
	fmt.Println(")\");")
}

// mips2ir translates MIPS assembly to LLVM IR.
func main() {
	// Check if any arguments was provided.
	if len(os.Args) <= 1 {
		die(fmt.Errorf("no arguments provided\n"))
	}

	// Open .c-file.
	inputFile, err := os.Open(os.Args[1])
	if err != nil {
		die(err)
	}

	// Read .c-file.
	programInBytes, err := ioutil.ReadAll(inputFile)
	if err != nil {
		die(err)
	}

	// Process program line by line.
	var statements []string
	scanner := bufio.NewScanner(strings.NewReader(string(programInBytes)))
	for scanner.Scan() {
		line := scanner.Text()

		// Did I hit an asm-statement?
		if line == "asm(R\"" {
			// Process it!
			hitEndOfAsmStatement := false
			statement := ""
			for scanner.Scan() {
				line = scanner.Text()
				if line == "\");" {
					hitEndOfAsmStatement = true
					break
				}
				statement += line + "\n"
			}
			if hitEndOfAsmStatement {
				statements = append(statements, statement)
				continue
			}
			die(fmt.Errorf("missing the end of the asm-statement"))
		}
		fmt.Println(line)
	}
	reassembleAndPrint(statements)
}
