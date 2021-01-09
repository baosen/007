%{
package segment

import (
    "fmt"
    "os"
)

type segmentLexer struct {
    input   string
    prev, i int
}

func (l *segmentLexer) get() byte {
    if l.i < len(l.input) {
        return l.input[l.i]
    }
    return 0
}

func (l *segmentLexer) next() {
    l.i++
}

func (l *segmentLexer) set(lval *yySymType) {
    lval.val = l.input[l.prev:l.i]
    l.prev = l.i
}

func (l *segmentLexer) Lex(lval *yySymType) int {
%}

%yyn l.next()
%yyc l.get()

%%

[ \t\n\r]+
    l.set(lval)
    return WHITESPACE

[A-Za-z0-9.()_/ ]+
    l.set(lval)
    return OBJECT

%%

// default match:
    return 0 /* zero token indicates end */
}

func (l *segmentLexer) Error(s string) {
	fmt.Fprintf(os.Stderr, "%s\n", s)
}
