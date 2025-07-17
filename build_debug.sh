#!/bin/sh

mkdir -p build-debug
cd build-debug || exit 1

cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
cd ..

./build-debug/bin/skch
