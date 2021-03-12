cmake_minimum_required(VERSION 3.14.2)

project(libartpalette)

set(LIBARTPALETTE ${AOSP}/art/libartpalette)

set(LIBARTPALETTE_SRC_FILES
    ${LIBARTPALETTE}/apex/palette.cc
    ${LIBARTPALETTE}/system/palette_fake.cc
    )

include_directories(
    ${libartpalette_headers}
    ${libbase_headers}
    ${liblog_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")

add_library(artpalette STATIC ${LIBARTPALETTE_SRC_FILES})
target_link_libraries(artpalette)
