def _deflate_impl(ctx):
    output_files = []
    for input_file in ctx.files.srcs:
        output_file_name = input_file.basename[:len(input_file.basename) - 3] + "rz"
        output_file = ctx.actions.declare_file(output_file_name)
        output_files.append(output_file)
        tool = ctx.executable._compression_tool
        ctx.actions.run_shell(
            inputs = ctx.files._deps + [tool] + [input_file],
            outputs = [output_file],
            command = "./%s < %s > %s" % (tool.path, input_file.path, output_file.path),
        )

    # Tell Bazel that the dependent files necessary to build for this target includes `output_file`.
    return [DefaultInfo(files = depset(output_files))]

deflate = rule(
    implementation = _deflate_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".bin", ".seg"],
            doc = "Files to deflate using Rare's compression algorithm.",
            mandatory = True,
        ),
        "_deps": attr.label_list(
            default = ["//tools/rz/deflate:deflate_tool_files"],
        ),
        "_compression_tool": attr.label(
            default = Label("//tools/rz/deflate:1172compress.sh"),
            allow_single_file = True,
            executable = True,
            cfg = "exec",
        ),
    },
    doc = "Deflate using Rare's compression algorithm informally known as RareZip.",
)
