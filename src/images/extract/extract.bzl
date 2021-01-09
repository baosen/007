def _extract_impl(ctx):
    output_files = []
    for i in range(1, ctx.attr.total):
        output_files.append(ctx.actions.declare_file("%s.bin" % i))
    output_files.append(ctx.actions.declare_file("image_externs.h"))
    output_files.append(ctx.actions.declare_file("images.segment"))

    rom_file_path = ctx.files.rom[0].path
    json_file_path = ctx.files.json[0].path
    ctx.actions.run(
        inputs = ctx.files.rom + ctx.files.json,
        outputs = output_files,
        arguments = [rom_file_path] + [output_files[0].dirname] + [json_file_path],
        executable = ctx.executable._extractor,
    )
    return [DefaultInfo(files = depset(output_files))]

extract = rule(
    implementation = _extract_impl,
    attrs = {
        "rom": attr.label(
            allow_single_file = [".z64"],
            mandatory = True,
        ),
        "json": attr.label(
            allow_single_file = [".json"],
            mandatory = True,
        ),
        "total": attr.int(
            mandatory = True,
        ),
        "_extractor": attr.label(
            default = Label("//src/images/extract"),
            allow_single_file = True,
            executable = True,
            cfg = "exec",
        ),
    },
)
