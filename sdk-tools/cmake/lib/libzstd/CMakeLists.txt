cmake_minimum_required(VERSION 3.14.2)

project(libzstd)

set(ZSTD ${AOSP}/external/zstd)

file(GLOB_RECURSE LIBZSTD_SRC_FILES ${ZSTD}/lib/*.c)

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \                           -Wall \
    -Werror \
    -Wextra \
    ")

include_directories(
    ${libzstd_headers}
    ${ZSTD}/lib/common
    )

add_library(zstd STATIC ${LIBZSTD_SRC_FILES})
target_link_libraries(zstd)
