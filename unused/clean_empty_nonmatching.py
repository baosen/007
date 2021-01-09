#!/bin/python3
import sys
import os
import re


# Print error message and exit with 1.
def die(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    exit(1)


# Remove empty NONMATCHING C functions in c-file.
def remove_empty_nonmatching_function(c_file):
    file = open(c_file, "r")
    contents = file.read()
    newContents = ""

    next = 0
    for match_ifdef in re.finditer("#ifdef NONMATCHING", contents):
        start_ifdef, end_ifdef = match_ifdef.span()
        for match_else in re.finditer("#else", contents[end_ifdef:]):
            start_else, end_else = match_else.span()
            if re.search("{\s*}\s#", contents[end_ifdef : end_ifdef + start_else + 1]):
                start_endif = None
                for match_endif in re.finditer("#endif", contents[end_ifdef:]):
                    start_endif, end_endif = match_endif.span()
                    break
                if start_endif:
                    newContents += (
                        contents[next:start_ifdef]
                        + contents[end_ifdef + end_else : end_ifdef + start_endif]
                    )
                    next = end_ifdef + end_endif + 1
            break
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
        remove_empty_nonmatching_function(c_file)
