package rom

func Parse(inputString string) {
	yyParse(&romlinkLexer{input: inputString})
}
