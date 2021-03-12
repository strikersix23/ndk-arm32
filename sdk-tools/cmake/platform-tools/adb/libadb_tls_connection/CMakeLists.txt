cmake_minimum_required(VERSION 3.14.2)

project(libadb_tls_connection)

set(TLS ${AOSP}/packages/modules/adb/tls)

set(LIBADB_TLS_CONNECTION_SRC_FILES
    ${TLS}/adb_ca_list.cpp
    ${TLS}/tls_connection.cpp
    )

include_directories(
    ${boringssl_headers}
    ${adb_headers}
    ${libbase_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wthread-safety")

add_library(adb_tls_connection STATIC ${LIBADB_TLS_CONNECTION_SRC_FILES})
target_link_libraries(adb_tls_connection)
