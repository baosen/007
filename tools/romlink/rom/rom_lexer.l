%{
package rom

import (
    "fmt"
    "os"
)

type romlinkLexer struct {
    input   string
    prev, i int
}

func (l *romlinkLexer) get() byte {
    if l.i < len(l.input) {
        return l.input[l.i]
    }
    return 0
}

func (l *romlinkLexer) next() {
    l.i++
}

func (l *romlinkLexer) set(lval *yySymType) {
    lval.val = l.input[l.prev:l.i]
    l.prev = l.i
}

func (l *romlinkLexer) Lex(lval *yySymType) int {
%}

%yyn l.next()
%yyc l.get()

hexdigit [a-fA-F0-9]
%%

[ \t\n\r]+
    l.set(lval)
    return WHITESPACE

[\+]
    l.set(lval)
    return SIGN

{hexdigit}+
    l.set(lval)
    return HEX

[A-Za-z0-9/]+
    l.set(lval)
    return PATH

%%

// default match:
    return 0 /* zero token indicates end */
}

func (l *romlinkLexer) Error(s string) {
	fmt.Fprintf(os.Stderr, "%s\n", s)
}

