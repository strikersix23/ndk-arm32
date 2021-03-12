cmake_minimum_required(VERSION 3.14.2)

project(adb)

add_subdirectory(libadb_protos)
add_subdirectory(libadb_crypto)
add_subdirectory(libadb_pairing_auth)
add_subdirectory(libadb_pairing_connection)
add_subdirectory(libadb_tls_connection)
add_subdirectory(libadb_sysdeps)
add_subdirectory(libfastdeploy_host)
add_subdirectory(deployagent)

set(ADB ${AOSP}/packages/modules/adb)

set(LIBADB_SRC_FILES
    ${ADB}/adb.cpp
    ${ADB}/adb_io.cpp
    ${ADB}/adb_listeners.cpp
    ${ADB}/adb_trace.cpp
    ${ADB}/adb_unique_fd.cpp
    ${ADB}/adb_utils.cpp
    ${ADB}/fdevent/fdevent.cpp
    ${ADB}/services.cpp
    ${ADB}/sockets.cpp
    ${ADB}/socket_spec.cpp
    ${ADB}/sysdeps/errno.cpp
    ${ADB}/transport.cpp
    ${ADB}/transport_fd.cpp
    ${ADB}/types.cpp
    )

set(LIBADB_LINUX_SRC_FILES
    ${ADB}/fdevent/fdevent_epoll.cpp
    )

set(LIBADB_POSIX_SRC_FILES
    ${ADB}/sysdeps_unix.cpp
    ${ADB}/sysdeps/posix/network.cpp
    )

set(LIBADB_HOST_SRC_FILES
    ${LIBADB_SRC_FILES}
    ${LIBADB_LINUX_SRC_FILES}
    ${LIBADB_POSIX_SRC_FILES}
    ${ADB}/client/usb_linux.cpp
    ${ADB}/client/auth.cpp
    ${ADB}/client/adb_wifi.cpp
    ${ADB}/client/usb_libusb.cpp
    ${ADB}/client/usb_dispatch.cpp
    ${ADB}/client/transport_local.cpp
    ${ADB}/client/transport_mdns.cpp
    ${ADB}/client/mdns_utils.cpp
    ${ADB}/client/transport_usb.cpp
    ${ADB}/client/pairing/pairing_client.cpp
    )

set(ADB_SRC_FILES
    ${ADB}/client/adb_client.cpp
    ${ADB}/client/bugreport.cpp
    ${ADB}/client/commandline.cpp
    ${ADB}/client/file_sync_client.cpp
    ${ADB}/client/main.cpp
    ${ADB}/client/console.cpp
    ${ADB}/client/adb_install.cpp
    ${ADB}/client/line_printer.cpp
    ${ADB}/client/fastdeploy.cpp
    ${ADB}/client/fastdeploycallbacks.cpp
    ${ADB}/client/incremental.cpp
    ${ADB}/client/incremental_server.cpp
    ${ADB}/client/incremental_utils.cpp
    ${ADB}/shell_service_protocol.cpp
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -std=c++2a \
    -Wall \
    -Wextra \
    -Werror \
    -Wexit-time-destructors \
    -Wno-thread-safety-attributes \
    -Wno-unused-parameter \
    -Wno-missing-field-initializers \
    -Wno-thread-safety \
    -Wno-invalid-constexpr \
    -Wvla \
    -DADB_HOST=1 \
    -DALLOW_ADBD_ROOT=1 \
    -DANDROID_BASE_UNIQUE_FD_DISABLE_IMPLICIT_CONVERSION=1 \
    ")

include_directories(
    ${adb_headers}
    ${libbase_headers}
    ${libcutils_headers}
    ${boringssl_headers}
    ${libbuildversion_headers}
    ${libusb_headers}
    ${protobuf_headers}
    ${mdnsresponder_headers}
    ${libcrypto_utils_headers}
    ${libdiagnose_usb_headers}
    ${libbrotli_headers}
    ${liblz4_headers}
    ${libziparchive_headers}
    ${libutils_headers}
    ${liblog_headers}
    ${libsystem_headers}
    ${gtest_headers}
    ${androidfw_headers}
    ${zstd_headers}
    ${incfs_headers}
    ${fmtlib_headers}
    ${ADB}
    ${ADB}/fastdeploy/proto
    ${ADB}/fastdeploy/proto/packages/modules/adb
    )

link_directories(
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/lib/boringssl/build/crypto
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/lib/boringssl/build/ssl
    )

set(CMAKE_EXE_LINKER_FLAGS "-static")

# system/core/adb/adb.cpp
# comment platform_tools_version.h
add_definitions(-DPLATFORM_TOOLS_VERSION="30.0.3")

add_library(adb_host STATIC ${LIBADB_HOST_SRC_FILES})
target_link_libraries(adb_host)

add_executable(adb ${ADB_SRC_FILES})
target_link_libraries(adb 
    adb_host
    adb_pairing_server
    adb_pairing_connection
    adb_tls_connection
    adb_pairing_auth 
    adb_crypto
    adb_protos
    adb_sysdeps
    androidfw
    incfs_utils
    incfs
    fmt
    selinux
    pcre2
    sepol
    packagelistparser
    crypto
    ssl
    brotli
    crypto_utils
    fastdeploy_host
    diagnose_usb
    lz4
    mdnssd
    protobuf-cpp-full
    usb
    ssl
    crypto
    ziparchive
    base
    utils
    cutils
    cutils_sockets
    buildversion
    log
    zstd
    z
    c++
    c++abi
    dl
    )
