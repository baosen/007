# Use the MIPS GNU toolchain.
TOOLCHAIN = "mips-linux-gnu-"

def _mips_library_impl(ctx):
    # Assembly defines.
    ASMDEFS = "--defsym VERSION_US=1"

    s_files = [file for file in ctx.files.srcs if file.path.endswith(".s")]
    if len(s_files) > 1:
        fail("too many .s-files given")
    input_file = s_files[0]
    output_file = ctx.actions.declare_file("%s.o" % ctx.attr.name)

    # GNU Assembler.
    AS = TOOLCHAIN + "as"
    ASFLAGS = "-march=vr4300 -mabi=32 " + ASMDEFS

    # The assembler command.
    ASSEMBLE = "cat %s/macros.inc %s | %s %s" % (ctx.files._deps[0].dirname, input_file.path, AS, ASFLAGS)

    # Generate -I option string.
    include_directories = []
    for source_file in ctx.files.srcs:
        include_directories.append(source_file.dirname)
    include_dir_str = ""
    for dirpath in include_directories:
        include_dir_str += "-I %s " % dirpath

    ctx.actions.run_shell(
        inputs = ctx.files._deps + ctx.files.srcs,
        outputs = [output_file],
        progress_message = "Assembling %s" % input_file.short_path,
        command = "%s %s -o %s" % (ASSEMBLE, include_dir_str, output_file.path),
    )

    # Tell Bazel that the dependent files necessary to build for this target includes `output_file`.
    return [DefaultInfo(files = depset([output_file]))]

mips_library = rule(
    implementation = _mips_library_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = True,
            doc = "Assembler files to assemble to object files",
            mandatory = True,
        ),
        "_deps": attr.label_list(
            default = ["//tools/gnu:gnu_compiler_files"],
        ),
    },
    doc = "Assembles files to a MIPS object library file",
)

def _mips_libraries_impl(ctx):
    # Assembly defines.
    ASMDEFS = "--defsym VERSION_US=1"

    # GNU Assembler.
    AS = TOOLCHAIN + "as"
    ASFLAGS = "-march=vr4300 -mabi=32 " + ASMDEFS

    input_files = [file for file in ctx.files.srcs if file.path.endswith(".s")]

    # Generate -I option string.
    include_directories = []
    for source_file in ctx.files.srcs:
        include_directories.append(source_file.dirname)
    include_dir_str = ""
    for dirpath in include_directories:
        include_dir_str += "-I %s " % dirpath

    output_files = []
    for input_file in input_files:
        input_file_name = input_file.basename
        output_file = ctx.actions.declare_file(input_file_name[:len(input_file_name) - 1] + "o")
        output_files.append(output_file)

        # The assembler command.
        ASSEMBLE = "cat %s/macros.inc %s | %s %s" % (ctx.files._deps[0].dirname, input_file.path, AS, ASFLAGS)

        ctx.actions.run_shell(
            inputs = ctx.files._deps + ctx.files.srcs,
            outputs = [output_file],
            progress_message = "Assembling %s" % input_file.short_path,
            command = "%s %s -o %s" % (ASSEMBLE, include_dir_str, output_file.path),
        )

    # Tell Bazel that the dependent files necessary to build for this target includes `output_file`.
    return [DefaultInfo(files = depset(output_files))]

mips_libraries = rule(
    implementation = _mips_libraries_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = True,
            doc = "Assembler files to assemble to object files",
            mandatory = True,
        ),
        "_deps": attr.label_list(
            default = ["//tools/gnu:gnu_compiler_files"],
        ),
    },
    doc = "Assembles files to a MIPS object library file",
)

def _link_impl(ctx):
    # GNU Linker.
    LD = TOOLCHAIN + "ld"

    input_files = [file for file in ctx.files.srcs if file.path.endswith(".o")]
    ld_file = ctx.files.ld[0]

    output_files = []
    for input_file in input_files:
        output_file_name = input_file.basename[:len(input_file.basename) - 1] + "elf"
        output_file = ctx.actions.declare_file(output_file_name)
        output_files.append(output_file)
        ctx.actions.run_shell(
            inputs = [ld_file] + [input_file],
            outputs = [output_file],
            progress_message = "Linking %s" % input_file.short_path,
            command = "%s -T %s -o %s %s" % (LD, ld_file.path, output_file.path, input_file.path),
        )

    return [DefaultInfo(files = depset(output_files))]

link = rule(
    implementation = _link_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".o"],
            mandatory = True,
        ),
        "ld": attr.label(
            allow_single_file = [".ld"],
            mandatory = True,
        ),
    },
    doc = "Link .o-files using a single .ld-file to .ELF-files.",
)

def _link_elf_impl(ctx):
    # GNU Linker.
    LD = TOOLCHAIN + "ld"

    input_files = [file for file in ctx.files.srcs if file.path.endswith(".o")]
    input_files_args = ""
    for input_file in input_files:
        input_files_args += input_file.path + " "

    t_args = ""
    for ld_file in ctx.files.lds:
        t_args += "-T %s " % ld_file.path

    output_file_name = ctx.attr.name + ".elf"
    output_file = ctx.actions.declare_file(output_file_name)
    map_file = ctx.actions.declare_file("usa.map")
    ctx.actions.run_shell(
        inputs = ctx.files.lds + input_files,
        outputs = [output_file] + [map_file],
        command = "%s %s -Map %s -o %s" % (LD, t_args, map_file.path, output_file.path),
    )

    return [DefaultInfo(files = depset([output_file, map_file]))]

link_elf = rule(
    implementation = _link_elf_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".o"],
            mandatory = True,
        ),
        "lds": attr.label_list(
            allow_files = [".ld"],
            mandatory = True,
        ),
    },
)

def _objcopy_impl(ctx):
    # GNU MIPS Object copy.
    OBJCOPY = TOOLCHAIN + "objcopy"

    gapfill = ""
    if ctx.attr.gapfill != "":
        gapfill = "--gap-fill=%s" % ctx.attr.gapfill

    input_files = [file for file in ctx.files.srcs if file.path.endswith(".elf")]
    output_files = []
    for input_file in input_files:
        output_file_name = input_file.basename[:len(input_file.basename) - 3] + "seg"
        output_file = ctx.actions.declare_file(output_file_name)
        output_files.append(output_file)
        ctx.actions.run_shell(
            inputs = [input_file],
            outputs = [output_file],
            progress_message = "Object copying %s" % input_file.short_path,
            command = "%s %s %s -O binary %s" % (OBJCOPY, input_file.path, output_file.path, gapfill),
        )

    return [DefaultInfo(files = depset(output_files))]

objcopy = rule(
    implementation = _objcopy_impl,
    attrs = {
        "srcs": attr.label_list(
            allow_files = [".elf"],
            mandatory = True,
        ),
        "gapfill": attr.string(),
    },
)
