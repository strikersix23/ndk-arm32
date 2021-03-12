cmake_minimum_required(VERSION 3.14.2)

project(libext4_utils)

set(EXT4_UTILS ${AOSP}/system/extras/ext4_utils)

set(LIBEXT4_UTILS_SRC_FILES
    ${EXT4_UTILS}/ext4_utils.cpp
    ${EXT4_UTILS}/wipe.cpp
    ${EXT4_UTILS}/ext4_sb.cpp
    )

include_directories(
    ${libext4_utils_headers}
    ${libbase_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -fno-strict-aliasing -DREAL_UUID")

add_library(ext4_utils STATIC ${LIBEXT4_UTILS_SRC_FILES})
target_link_libraries(ext4_utils)
