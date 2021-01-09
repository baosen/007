package segment

// parse runs the yacc-parser on the input string.
func parse(inputString string) {
	yyParse(&segmentLexer{input: inputString})
}

// reverseOutput reverses the output slice.
func reverseOutput() {
	for left, right := 0, len(output)-1; left < right; left, right = left+1, right-1 {
		output[left], output[right] = output[right], output[left]
	}
}

// Empty and return reversed output slice.
var lastEnd int

func getSliceOutput(path string) []string {
	if path != "" && path != "." {
		for i := lastEnd; i < len(output); i++ {
			output[i] = path + "/" + output[i]
		}
		lastEnd = len(output)
	}
	s := output
	output = nil
	return s
}

func getOutput() []string {
	lastEnd = 0
	reverseOutput()
	return getSliceOutput("")
}
