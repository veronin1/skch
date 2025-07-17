#!/bin/sh

mkdir -p build-release
cd build-release || exit 1

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
cd ..

./build-release/bin/skch
