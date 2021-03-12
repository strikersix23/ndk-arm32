cmake_minimum_required(VERSION 3.14.2)

project(libandroidicuinit)

set(ICU ${AOSP}/external/icu)

include_directories(
    ${icu_headers}
    ${libbase_headers}
    ${liblog_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -DANDROID_LINK_SHARED_ICU4C")

add_library(androidicuinit STATIC ${ICU}/libandroidicuinit/IcuRegistration.cpp)
target_link_libraries(androidicuinit)


