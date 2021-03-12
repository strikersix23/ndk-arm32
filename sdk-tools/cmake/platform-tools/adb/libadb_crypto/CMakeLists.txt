cmake_minimum_required(VERSION 3.14.2)

project(libadb_crypto)

set(CRYPTO ${AOSP}/packages/modules/adb/crypto)

set(LIBADB_CRYPTO_SRC_FILES
    ${CRYPTO}/key.cpp
    ${CRYPTO}/rsa_2048_key.cpp
    ${CRYPTO}/x509_generator.cpp
    )

include_directories(
    ${boringssl_headers}
    ${libbase_headers}
    ${protobuf_headers}
    ${libcrypto_utils_headers}
    ${adb_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wthread-safety")

add_library(adb_crypto STATIC ${LIBADB_CRYPTO_SRC_FILES})
target_link_libraries(adb_crypto)
