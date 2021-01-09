def _compress_impl(ctx):
    map_file = [file for file in ctx.files.srcs if file.path.endswith(".map")][0]
    raw_file = [file for file in ctx.files.srcs if file.path.endswith(".seg")][0]

    output_file = ctx.actions.declare_file("usa.bin")
    ctx.actions.run(
        inputs = ctx.files._deps + [map_file] + [raw_file],
        outputs = [output_file],
        arguments = [raw_file.path] + [map_file.path] + [output_file.path],
        executable = ctx.executable._compression_tool,
    )
    return [DefaultInfo(files = depset([output_file]))]

compress = rule(
    implementation = _compress_impl,
    attrs = {
        "srcs": attr.label_list(
            mandatory = True,
        ),
        "_compression_tool": attr.label(
            default = Label("//tools/compress:data_compress.sh"),
            allow_single_file = True,
            executable = True,
            cfg = "exec",
        ),
        "_deps": attr.label_list(
            default = ["//tools/rz/deflate:deflate_tool_files"],
        ),
    },
)
