package frontend

func Parse(program string) int {
	return yyParse(&mipsLexer{input: program})
}
