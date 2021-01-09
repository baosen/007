package segment

type segment struct {
	Address             string
	Name                string
	Objects             string
	PreviousSegmentName string
	Subalign            bool
	Compressed          bool
}

const segmentBlock = `
    {{if .Compressed}}__csegtempPos = 0xC00000;{{end}}
    .{{.Name}} {{.Address}} : AT({{if .Compressed}}__csegtempPos){{else}}_{{.Name}}RomSegmentStart){{end}} {{if .Subalign}}SUBALIGN(16){{end}} {
{{.Objects}}
    }
    _{{.Name}}SegmentStart    = ADDR(.{{.Name}});
    _{{.Name}}SegmentSize     = SIZEOF(.{{.Name}});
    _{{.Name}}SegmentEnd      = _{{.Name}}SegmentStart + _{{.Name}}SegmentSize;
    _{{.Name}}RomSegmentStart = _{{.PreviousSegmentName}}RomSegmentEnd;
    {{if .Compressed}}_{{.Name}}RomSegmentEnd   = __csegtempPos + _{{.Name}}SegmentSize;{{else}}_{{.Name}}RomSegmentEnd   = _{{.Name}}RomSegmentStart + _{{.Name}}SegmentSize;{{end}}
`
