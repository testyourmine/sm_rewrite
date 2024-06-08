# Requirements
  * cmake (and also ninja, for better compiling speed)
  * A Super Metroid rom (Make sure to rename it to `sm.smc`) which **must be in
    the same folder as `sm`/`sm.exe`**
  * libsdl2-dev
  * Super Metroid repo `git clone --recursive https://github.com/testyourmine/sm_rewrite.git`

 For Linux/MacOS you must install these for your desired OS:
 * Ubuntu/Debian: `sudo apt install libsdl2-dev cmake ninja-build`
 * Fedora Linux: `sudo dnf in sdl2-devel cmake ninja-build`
 * Arch Linux: `sudo pacman -S sdl2 cmake ninja`
 * macOS: `brew install sdl2 cmake ninja`

# Windows
## Building with MSYS2
First, install [MSYS2](https://www.msys2.org/). After following the instructions,
install the following packages.

Note: *Make sure you're using MINGW64 and you're in `sm` folder in the terminal.*

```sh
pacman -S mingw-w64-x86_64-{gcc,cmake,SDL2,ninja}
```

Once installed, building can be done with:
```sh
cmake -B build -G Ninja && cmake --build build
```
`sm.exe` will be at `./build/sm.exe`.

## Building with Visual Studio
Dependencies and requirements:
 * The `libsdl2-dev` library, which is automatically installed with vcpkg
 * [Visual Studio Community 2022](https://visualstudio.microsoft.com)

Download VS installer. On installer prompt, make sure you're on "Workloads"
and check `Desktop Development with C++`, `C++ CMake Tools for Windows` **and**
`vcpkg package manager`. You **must** have all three for building and developing.


Visual Studio should automatically detect the CMake project and let you configure and build it. If not,
follow the [general instructions](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
from Microsoft.

### CMake Presets
There are two cmake presets for Windows that will automatically be detected by cmake and visual
studio and should be used when building:

1. `windows-relwithdebinfo`: release mode (with debug info)
2. `windows-debug`: debug mode

Each of them also sets up the proper `vcpkg` path so that the dependency libraries are
automatically downloaded and installed.

## Building with Tiny C Compiler
 Dependencies and requirements:
 * You'll need [TCC](https://github.com/FitzRoyX/tinycc/releases/download/tcc_20221020/tcc_20221020.zip) and
   [SDL2](https://github.com/libsdl-org/SDL/releases/download/release-2.24.1/SDL2-devel-2.24.1-VC.zip) in order to compile using TCC.

1. Unzip both TCC and SDL and place them in `third_party` folder.
2. Double click `run_with_tcc.bat`
3. Wait for it to compile and the game will automatically boot-up.

Note: TCC compiles without any optimizations or hardware features, which *may* cause `sm` to
run slowly. It's recommended to use the other methods.

# Linux/MacOS
CD to your SM root folder and open the terminal and type:
```sh
cmake -G Ninja -B build && cmake --build build --parallel
```

The resulting binary will be `build/sm`.

# Nintendo Switch
## Getting Dependencies
You will need:
  * [DevKitPro](https://github.com/devkitPro/installer)
  * [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere)

First, follow the [installation instructions on devkitPro's website](https://devkitpro.org/wiki/Getting_Started).

Second, once you have pacman set up and synced, do:
```shell
pacman -S switch-dev switch-tools switch-sdl2
```

## Building
In the top level directory, you can use the cmake preset for running a build for the switch:
```shell
cmake --preset nintendo-switch
cmake --build build-switch --parallel
```

## Getting SM on to your Switch
First, make sure you've installed [Atmosphere](https://github.com/Atmosphere-NX/Atmosphere) on your Switch.
Next, go into the `build-switch` directory and copy `sm.ini`, `sm.nro`, and `sm.ncap` and the sm rom
file to your Switch.
