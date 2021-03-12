cmake_minimum_required(VERSION 3.14.2)

project(libcrypto_utils)

set(LIBCRYPTO_UTILS ${AOSP}/system/core/libcrypto_utils)

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wall -Werror -Wextra")

include_directories(
    ${libcrypto_utils_headers}
    ${boringssl_headers}
    )

add_library(crypto_utils STATIC ${LIBCRYPTO_UTILS}/android_pubkey.cpp)
target_link_libraries(crypto_utils)
