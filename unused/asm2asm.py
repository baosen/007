#!/bin/python3
import sys
import os
import re

# Print error message and exit with 1.
def die(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    exit(1)


def convert_macro_asm_to_cpp_asm(c_file):
    file = open(c_file, "r")
    contents = file.read()
    newContents = ""

    next = 0
    for asm_match in re.finditer("ASM\(", contents):
        s1, e1 = asm_match.span()
        newContents += contents[next:s1] + 'asm(R"'
        for end_paren_match in re.finditer("\n\)", contents[e1:]):
            s2, e2 = end_paren_match.span()
            newContents += contents[e1 : e1 + s2] + '\n");'
            break
        next = e1 + e2
    newContents += contents[next:]
    file.close()

    # Overwrite file.
    file = open(c_file, "w")
    file.write(newContents)
    file.close()


if __name__ == "__main__":
    # Check if user provided enough arguments.
    if len(sys.argv) <= 1:
        die("not enough arguments")

    # Get input directory to list .c-files.
    input_directory = sys.argv[1]
    if input_directory == "":  # probably does not happen.
        die("empty input directory")

    # Get all .c-files recursively inside the input directory.
    c_files = []
    for (root, _, files) in os.walk(input_directory, topdown=True):
        for file in files:
            if file.endswith(".c"):
                c_files.append("{}/{}".format(root, file))
    if len(c_files) <= 0:
        die("no .c-files found in %s" % input_directory)

    # Remove empty NONMATCHING C functions.
    for c_file in c_files:
        convert_macro_asm_to_cpp_asm(c_file)
