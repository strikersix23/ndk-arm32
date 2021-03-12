cmake_minimum_required(VERSION 3.14.2)

project(fmtlib)

set(FMTLIB ${AOSP}/external/fmtlib)

set(LIBFMT_SRC_FILES ${FMTLIB}/src/format.cc)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -fno-exceptions \
    -UNDEBUG \
    ")

include_directories(
    ${fmtlib_headers}
    )

add_library(fmt STATIC ${LIBFMT_SRC_FILES})
target_link_libraries(fmt)
