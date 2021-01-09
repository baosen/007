.PHONY: all

all: romlink

run: romlink
	@./$<

clean:
	@rm -f romlink rom/lex.yy.go rom/rom_parser.go

test: romlink
	@go test

rom/lex.yy.go: rom/rom_lexer.l
	@golex -o $@ $<

rom/rom_parser.go: rom/rom_parser.y
	@goyacc -o $@ $<

segment/lex.yy.go: segment/segment_lexer.l
	@golex -o $@ $<

segment/segment_parser.go: segment/segment_parser.y
	@goyacc -o $@ $<

romlink: segment/lex.yy.go segment/segment_parser.go rom/lex.yy.go rom/rom_parser.go $(wildcard *.go)
	@go build .

