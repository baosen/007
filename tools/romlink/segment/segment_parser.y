%{
package segment

import (
	"path/filepath"
	"strings"
)

var output []string

%}

%union{
	val string
}
%type <val> object
%token <val> WHITESPACE PATH OBJECT

%%

segment: /* empty */
| object segment
{
	obj := $1
	s := strings.Split(obj, " ")
	if s[0] == "import" {
		// Open, read and parse .segment-file.
		var fullpath string
		if romDirPath != "." {
			fullpath = romDirPath
			if segmentDirPath != "." {
				fullpath += "/" + segmentDirPath
			}
		} else if segmentDirPath != "." {
			fullpath += segmentDirPath
		}
		parse(readSegmentFile(GetAbsolutePath(fullpath, s[1])))
		output = append(output, getSliceOutput(filepath.Dir(s[1]))...)
	} else {
		output = append(output, $1)
	}
}
;

object: OBJECT WHITESPACE
| OBJECT

%%
