cmake_minimum_required(VERSION 3.14.2)

project(libadb_sysdeps)

set(SYSDEPS ${AOSP}/packages/modules/adb/sysdeps)

set(LIBADB_SYSDEPS_SRC_FILES ${SYSDEPS}/env.cpp)

include_directories(
    ${adb_headers}
    ${libbase_headers}
    ${liblog_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wthread-safety")

add_library(adb_sysdeps STATIC ${LIBADB_SYSDEPS_SRC_FILES})
target_link_libraries(adb_sysdeps)
