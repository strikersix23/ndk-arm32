cmake_minimum_required(VERSION 3.14.2)

project(liblz4)

set(LZ4 ${AOSP}/external/lz4/lib)

set(LIBLZ4_SRC_FILES
    ${LZ4}/lz4.c
    ${LZ4}/lz4hc.c
    ${LZ4}/lz4frame.c
    ${LZ4}/xxhash.c
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")

add_library(lz4 STATIC ${LIBLZ4_SRC_FILES})
target_link_libraries(lz4)
