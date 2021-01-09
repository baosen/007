def _link_binaries_impl(ctx):
    output_files = []
    for input_file in ctx.files.binaries:
        input_basename = input_file.basename
        if input_basename.endswith(".bin"):
            output_filename = input_basename[:len(input_basename) - 3] + "o"
            output_file = ctx.actions.declare_file(output_filename)
            ctx.actions.run_shell(
                inputs = [input_file],
                outputs = [output_file],
                progress_message = "Linking %s" % input_file.short_path,
                command = "mips-linux-gnu-ld -r -b binary %s -o %s" % (input_file.path, output_file.path),
            )
            output_files.append(output_file)
    return [DefaultInfo(files = depset(output_files))]

link_binaries = rule(
    implementation = _link_binaries_impl,
    attrs = {
        "binaries": attr.label_list(
            allow_files = [".bin"],
            mandatory = True,
        ),
    },
)
