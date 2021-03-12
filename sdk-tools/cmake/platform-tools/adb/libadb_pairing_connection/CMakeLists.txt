cmake_minimum_required(VERSION 3.14.2)

project(libadb_pairing_connection)

set(PAIRING_CONNECTION ${AOSP}/packages/modules/adb/pairing_connection)

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wthread-safety")

include_directories(
    ${boringssl_headers}
    ${libbase_headers}
    ${libcutils_headers}
    ${protobuf_headers}
    ${adb_headers}
    ${PAIRING_CONNECTION}/internal
    )

add_library(adb_pairing_connection STATIC ${PAIRING_CONNECTION}/pairing_connection.cpp)
target_link_libraries(adb_pairing_connection)

add_library(adb_pairing_server STATIC ${PAIRING_CONNECTION}/pairing_server.cpp)
target_link_libraries(adb_pairing_server)
