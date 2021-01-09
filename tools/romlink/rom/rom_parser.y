%{
package rom

var subalign bool
var compressed bool

%}

%union{
	val string
}
%type <val> segment address path sign
%token <val> SIGN HEX WHITESPACE PATH

%%

segments: /* zero token */
| segment segments
;

segment: address WHITESPACE path
{
	printSegment($1, $3, subalign, compressed)
	subalign = false
	compressed = false
}
;

path: PATH WHITESPACE
| PATH WHITESPACE path
{
	if $3 == "subalign" {
		subalign = true
	}
	if $3 == "compressed" {
		compressed = true
	}
	$$ = $1
}
;

address: HEX
{
	setPreviousAddress($1)
	$$ = "0x" + $1
}
| sign HEX
{
	$$ = computeMemoryAddress($1, $2)
}
| sign PATH
{
	$$ = "_" + $2 + "RomSegmentStart"
}
| sign
{
	$$ = computeStartMemoryAddress()
}
;

sign: SIGN
{
	$$ = $1
}
;

%%
