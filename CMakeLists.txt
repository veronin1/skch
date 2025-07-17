cmake_minimum_required(VERSION 3.10)
project(skch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(skch
    src/main.cpp
    src/canvas.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(skch PRIVATE raylib)

target_compile_options(skch PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wformat=2
    -Wconversion
    -Wnull-dereference
    -Wdouble-promotion
)

# Different flags for Debug vs Release:
target_compile_options(skch PRIVATE
  $<$<CONFIG:Debug>:-g -fsanitize=address -DDEBUG>
  $<$<CONFIG:Release>:-O3 -DNDEBUG>
)

target_link_options(skch PRIVATE
  $<$<CONFIG:Debug>:-fsanitize=address>
)

set_target_properties(skch PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
