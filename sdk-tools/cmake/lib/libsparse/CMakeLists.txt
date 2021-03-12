cmake_minimum_required(VERSION 3.14.2)

project(libsparse)

set(LIBSPARSE ${AOSP}/system/core/libsparse)

set(LIBSPARSE_SRC_FILES
    ${LIBSPARSE}/backed_block.cpp
    ${LIBSPARSE}/output_file.cpp
    ${LIBSPARSE}/sparse.cpp
    ${LIBSPARSE}/sparse_crc32.cpp
    ${LIBSPARSE}/sparse_err.cpp
    ${LIBSPARSE}/sparse_read.cpp
    )

include_directories(
    ${libsparse_headers}
    ${libbase_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")

add_library(sparse STATIC ${LIBSPARSE_SRC_FILES})
target_link_libraries(sparse)
