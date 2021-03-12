cmake_minimum_required(VERSION 3.14.2)

project(libicui18n)

set(I18N ${AOSP}/external/icu/icu4c/source/i18n)

aux_source_directory(${I18N} LIBICUI18N_SRC_FILES)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -D_REENTRANT \
    -DU_I18N_IMPLEMENTATION \
    -O3 \
    -fvisibility=hidden \
    -Wall \
    -Werror \
    -Wno-unused-parameter \
    -Wno-unused-const-variable \
    -Wno-implicit-int-float-conversion \
    -Wno-unneeded-internal-declaration \
    -Wno-unreachable-code-loop-increment \
    -DANDROID_LINK_SHARED_ICU4C \
    -DPIC \
    -fPIC \
    -frtti \
    ")

include_directories(
    ${I18N}
    ${I18N}/../common
    ${icu_headers}
    )

add_library(icui18n STATIC ${LIBICUI18N_SRC_FILES})
target_link_libraries(icui18n)
