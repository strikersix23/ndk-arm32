cmake_minimum_required(VERSION 3.14.2)

project(incfs)

set(INCFS ${AOSP}/system/incremental_delivery/incfs)


set(LIBINCFS_SRC_FILES
    ${INCFS}/incfs_ndk.c
    ${INCFS}/incfs.cpp
    ${INCFS}/MountRegistry.cpp
    ${INCFS}/path.cpp
    )

set(LIBINCFS_UTILS_SRC_FILES ${INCFS}/util/map_ptr.cpp)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Werror \
    -Wextra \
    -Wno-deprecated-enum-enum-conversion \
    -std=c++2a \
    ")

include_directories(
    ${incfs_headers}
    ${libbase_headers}
    ${libutils_headers}
    ${boringssl_headers}
    ${libselinux_headers}
    )

add_library(incfs STATIC ${LIBINCFS_SRC_FILES})
target_link_libraries(incfs)

add_library(incfs_utils STATIC ${LIBINCFS_UTILS_SRC_FILES})
target_link_libraries(incfs_utils)
