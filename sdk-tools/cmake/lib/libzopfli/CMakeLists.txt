cmake_minimum_required(VERSION 3.14.2)

project(libzopfli)

set(LIBZOPFLI ${AOSP}/external/zopfli)

set(LIBZOPFLI_SRC_FILES
    ${LIBZOPFLI}/src/zopfli/blocksplitter.c
    ${LIBZOPFLI}/src/zopfli/cache.c
    ${LIBZOPFLI}/src/zopfli/deflate.c
    ${LIBZOPFLI}/src/zopfli/gzip_container.c
    ${LIBZOPFLI}/src/zopfli/hash.c
    ${LIBZOPFLI}/src/zopfli/katajainen.c
    ${LIBZOPFLI}/src/zopfli/lz77.c
    ${LIBZOPFLI}/src/zopfli/squeeze.c
    ${LIBZOPFLI}/src/zopfli/tree.c
    ${LIBZOPFLI}/src/zopfli/util.c
    ${LIBZOPFLI}/src/zopfli/zlib_container.c
    ${LIBZOPFLI}/src/zopfli/zopfli_lib.c
    )

set(ZOPFLIPNG_SRC_FILES
    ${LIBZOPFLI}/src/zopflipng/lodepng/lodepng.cpp
    ${LIBZOPFLI}/src/zopflipng/lodepng/lodepng_util.cpp
    ${LIBZOPFLI}/src/zopflipng/zopflipng_lib.cc
    ${LIBZOPFLI}/src/zopflipng/zopflipng_bin.cc
    )

include_directories(
    ${libzopfli_headers}
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -O2 -Werror -Wno-unused-parameter")

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -O2 -Werror -Wno-unused-parameter")

add_library(zopfli STATIC ${LIBZOPFLI_SRC_FILES})
target_link_libraries(zopfli)

add_library(zopflipng STATIC ${ZOPFLIPNG_SRC_FILES})
target_link_libraries(zopflipng)



