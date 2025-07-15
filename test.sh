#!/bin/sh

mkdir -p build
cd build || exit 1

cmake ..
cmake --build .

../bin/skch
