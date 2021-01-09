def _gecc_library_impl(ctx):
    input_files = [file for file in ctx.files.srcs if file.path.endswith(".c")]
    if len(input_files) > 1:
        fail("too many .c-files in srcs")

    # Get .c source code input file.
    input_file = input_files[0]

    # header files
    header_files = [file for file in ctx.files.srcs if file.path.endswith(".h")]

    include_directories = ""
    for header_file in header_files:
        include_directories += "-I " + header_file.dirname + " "

    # The output file is declared with a name based on the target's name.
    output_filename = "%s.o" % ctx.attr.name
    output_file = ctx.actions.declare_file(output_filename)

    # Run the executable named gecc.
    ctx.actions.run(
        inputs = ctx.files._deps + ctx.files.srcs,
        outputs = [output_file],
        progress_message = "Compiling %s" % input_file.short_path,
        arguments = [include_directories] + [input_file.path] + [output_file.path] + ["usa"],
        executable = ctx.executable._compiler,
    )

    # Tell Bazel that the dependent files necessary to build for this target includes `output_file`.
    return [DefaultInfo(files = depset([output_file]))]

gecc_library = rule(
    implementation = _gecc_library_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".h", ".c"],
            doc = "Source code files to compile to object files",
            mandatory = True,
        ),
        "_deps": attr.label_list(
            default = ["//tools/gecc:gecc_compiler_files"],
        ),
        "_compiler": attr.label(
            default = Label("//tools/gecc:gecc.sh"),
            allow_single_file = True,
            executable = True,
            cfg = "exec",
        ),
    },
    doc = "Compiles a C source code file using IRIX C Compiler",
)

def _gecc_libraries_impl(ctx):
    input_files = [file for file in ctx.files.srcs if file.path.endswith(".c")]

    # The output file is declared with a name based on the target's name.

    # Run the executable named gecc.
    output_files = []
    for input_file in input_files:
        input_file_basename = input_file.basename
        output_filename = input_file_basename[:len(input_file_basename) - 1] + "o"
        output_file = ctx.actions.declare_file(output_filename)
        output_files.append(output_file)
        ctx.actions.run(
            inputs = ctx.files._deps + ctx.files.srcs,
            outputs = [output_file],
            progress_message = "Compiling %s" % input_file.short_path,
            arguments = ["-I ."] + [input_file.path] + [output_file.path] + ["usa"],
            executable = ctx.executable._compiler,
        )
    return [DefaultInfo(files = depset(output_files))]

gecc_libraries = rule(
    implementation = _gecc_libraries_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".h", ".c"],
            doc = "Source code files to compile to object files",
            mandatory = True,
        ),
        "_deps": attr.label_list(
            default = ["//tools/gecc:gecc_compiler_files"],
        ),
        "_compiler": attr.label(
            default = Label("//tools/gecc:gecc.sh"),
            allow_single_file = True,
            executable = True,
            cfg = "exec",
        ),
    },
    doc = "Compiles C source code files using IRIX C Compiler",
)
