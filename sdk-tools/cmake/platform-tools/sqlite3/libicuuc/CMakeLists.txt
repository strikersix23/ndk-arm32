cmake_minimum_required(VERSION 3.14.2)

project(libicuuc)

set(LIBICUUC ${AOSP}/external/icu/icu4c/source/common)

aux_source_directory(${LIBICUUC} LIBICUUC_SRC_FILES)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -D_REENTRANT \
    -DU_COMMON_IMPLEMENTATION \
    -O3 \
    -fvisibility=hidden \
    -Wall \
    -Werror \
    -Wno-unused-parameter \
    -Wno-macro-redefined \
    -Wno-missing-field-initializers \
    -Wno-sign-compare \
    -Wno-deprecated-declarations \
    -Wno-ignored-attributes \
    -DPIC \
    -fPIC \
    -frtti \
    ")

include_directories(
    ${LIBICUUC}
    ${icu_headers}
    )

add_library(icuuc STATIC ${LIBICUUC_SRC_FILES})
target_link_libraries(icuuc)
