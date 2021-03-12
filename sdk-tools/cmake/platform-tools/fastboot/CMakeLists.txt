cmake_minimum_required(VERSION 3.14.2)

project(fastboot)

set(FASTBOOT ${AOSP}/system/core/fastboot)

set(LIBFASTBOOT_SRC_FILES
    ${FASTBOOT}/bootimg_utils.cpp
    ${FASTBOOT}/fastboot.cpp
    ${FASTBOOT}/fs.cpp
    ${FASTBOOT}/socket.cpp
    ${FASTBOOT}/tcp.cpp
    ${FASTBOOT}/udp.cpp
    ${FASTBOOT}/util.cpp
    ${FASTBOOT}/fastboot_driver.cpp
    ${FASTBOOT}/usb_linux.cpp
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra -Wunreachable-code")
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(
    ${libbase_headers}
    ${libcutils_headers}
    ${libsparse_headers}
    ${liblp_headers}
    ${libbuildversion_headers}
    ${libziparchive_headers}
    ${libdiagnose_usb_headers}
    ${gtest_headers}
    ${libavb_headers}
    ${AOSP}/system/tools/mkbootimg/include/bootimg
    )

link_directories(                                   
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/lib/boringssl/build/crypto
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/lib/boringssl/build/ssl                                      
    )

# system/core/fastboot/fastboot.cpp
# comment platform_tools_version.h
add_definitions(-DPLATFORM_TOOLS_VERSION="30.0.3")

add_library(fastboot_host STATIC ${LIBFASTBOOT_SRC_FILES})
target_link_libraries(fastboot_host)

add_executable(fastboot ${FASTBOOT}/main.cpp)
target_link_libraries(fastboot 
    fastboot_host
    ziparchive
    buildversion
    lp
    sparse
    crypto_utils
    ext4_utils
    utils
    log
    diagnose_usb
    base
    cutils
    cutils_sockets
    gtest
    crypto
    z
    c++
    c++abi
    dl
    )
