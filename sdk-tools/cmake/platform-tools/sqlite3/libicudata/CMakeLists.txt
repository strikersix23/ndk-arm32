cmake_minimum_required(VERSION 3.14.2)

project(libicudata)

set(STUBDATA ${AOSP}/external/icu/icu4c/source/stubdata)

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -DANDROID_LINK_SHARED_ICU4C")

include_directories(
    ${STUBDATA}/../common
    ${icu_headers}
    )

add_library(icuuc_stubdata STATIC ${STUBDATA}/stubdata.cpp)
target_link_libraries(icudata)
