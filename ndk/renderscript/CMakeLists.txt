cmake_minimum_required(VERSION 3.14.2)

project(renderscript)

set(GLOBAL_CXX_FLAGS " \
    -Wall \
    -Werror \
    -Wextra \
    -fno-rtti \
    -fno-exceptions \
    -fPIC \
    -std=c++11 \
    -Wno-unused-parameter \
    ")

add_subdirectory(liblog)
add_subdirectory(slang)
add_subdirectory(libbcc)
