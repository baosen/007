# GoldenEye 007

This repository contains a work-in-progress decompiled source code of the game GoldenEye 007, which can be useful for modding.

## Building
To build this game, some build tools needs to be installed on your computer first. Follow the steps in the `Dockerfile` to install them.

After finishing the steps, place the original game roms in the directory `roms/` like this:

```
USA: roms/usa.z64
```

and then execute

```
bazel build //src:usa_z64_rom
```

to build the US version. The built ROM will be outputted at `bazel-bin/src/usa.z64`.

## Testing
To check if you did not break the code, execute

```
bazel test //tests:usa
```

Combining this command with [ibazel](https://github.com/bazelbuild/bazel-watcher) will let you watch for file changes and automatically rebuild and retest the code for any breakage.

## See also

https://tcrf.net/GoldenEye_007_(Nintendo_64)

https://www.reddit.com/r/n64/comments/8qo5g0/so_you_want_to_mod_your_favourite_game_andor/

## Credits

This decompilation was only made possible thanks to many awesome 00 Agents who will be revealed only if they wish, and [n64decomp](https://github.com/n64decomp/007).

