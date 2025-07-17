# skch

A minimalistic blackboard-style drawing app for jotting down quick notes and sketches to aid visual understanding made for myself.

## Keybinds

`space`: clear screen
`press lmb`: draw single pixel
`hold lmb`: draw line
`hold rmb`: eraser
`esc`: close window

## Requirements

-   CMake >= 3.10
-   C++17-compatible compiler (e.g. `clang++` or `g++`)
-   (Optional) `clang-tidy` for static analysis

## Build Instructions

```sh
mkdir build
cd build
cmake ..
make
```

## Run

```sh
./bin/skch
```
