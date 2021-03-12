cmake_minimum_required(VERSION 3.14.2)

project(libandroidicu)

set(ICU ${AOSP}/external/icu)

include_directories(
    ${icu_headers}
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -DANDROID_LINK_SHARED_ICU4C \
    -DU_SHOW_CPLUSPLUS_API=0 \
    ")

add_library(androidicu STATIC ${ICU}/libandroidicu/static_shim/shim.cpp)
target_link_libraries(androidicu)


