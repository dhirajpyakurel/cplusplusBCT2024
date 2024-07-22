# fonograf

Terminal-based music player in C++.

Uses [miniaudio](https://github.com/mackron/miniaudio) for audio decoding, and
[rogueutil](https://github.com/sakhmatd/rogueutil) for the terminal-based UI.

A college project.

# author

- Sadbhav Adhikari, BCT-B1 (ACE079BCT054)

# usage

Just invoke it on the terminal:

```bash
fonograf
```

It will list out the music files in the current directory, and start playing the
one at the top (the one which is alphabetically first). Currently, `mp3`, `wav` 
and `flac` files are supported. A few controls, specifically pause, change song
and quit are provided, run by pressing the "p", "c" and "q" keys respectively.

# building

You'll need a C++ compiler. While most compilers are likely to work, this project
is built with clang and all the build scripts are for clang, so it is recommended
to use it.

On Linux and macOS, install it with your package manager. On Windows, the easiest
way is to use [scoop](https://scoop.sh) to install LLVM by installing the `llvm` 
package which provides `clang++`.

```bash
scoop install llvm
```

Note that you'll also require the Visual Studio build tools and by extension 
Visual Studio, since LLVM doesn't provide a standard library.

Now clone this repo:

```bash
git clone https://github.com/pes18fan/fonograf.git
```

And to compile, if on Linux or macOS:

```bash
make # Build
```

If on Windows, run `build.bat`. Make sure `clang++.exe` is in your path.

Enjoy!

# known issues

- UI flickering. This is due to the UI redrawing every half second to update the remaining duration of the playing track.
- Delayed input handling. The reason is similar to above, the UI's infinite loop sleeps for half a second each iteration to avoid overloading the CPU.

The solution to both these issues is multithreading, but that's a complex task
with plenty of pitfalls and I do not wish to get into that for now.

# license

This software is in its entirity licensed under the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0).

Additionally, it uses these following libraries under the following licenses:

- [miniaudio](https://github.com/mackron/miniaudio), public domain under the [Unlicense](https://unlicense.org)
- [rogueutil](https://github.com/sakhmatd/rogueutil), under the [Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0).
