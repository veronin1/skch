cmake_minimum_required(VERSION 3.10)
project(skch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(skch
    src/main.cpp
    src/canvas.cpp
)

target_compile_options(skch PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wformat=2
    -Wconversion
    -Wnull-dereference
    -Wdouble-promotion
    -Werror
    -fstack-protector-strong
    -D_FORTIFY_SOURCE=2
    -fsanitize=address
    -O2
)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

set_target_properties(skch PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(raylib REQUIRED)
target_link_libraries(skch PRIVATE raylib)
