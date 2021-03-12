cmake_minimum_required(VERSION 3.14.2)

project(libadb_pairing_auth)

set(PAIRING_AUTH ${AOSP}/packages/modules/adb/pairing_auth)

set(LIBADB_PAIRING_AUTH_SRC_FILES
    ${PAIRING_AUTH}/aes_128_gcm.cpp
    ${PAIRING_AUTH}/pairing_auth.cpp
    )

include_directories(
    ${boringssl_headers}
    ${libbase_headers}
    ${adb_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wthread-safety")

add_library(adb_pairing_auth STATIC ${LIBADB_PAIRING_AUTH_SRC_FILES})
target_link_libraries(adb_pairing_auth)
