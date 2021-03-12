cmake_minimum_required(VERSION 3.14.2)

project(libbase)

set(LIBBASE ${AOSP}/system/libbase)

set(LIBBASE_SRC_FILES
    ${LIBBASE}/abi_compatibility.cpp
    ${LIBBASE}/chrono_utils.cpp
    ${LIBBASE}/cmsg.cpp
    ${LIBBASE}/file.cpp
    ${LIBBASE}/logging.cpp
    ${LIBBASE}/mapped_file.cpp
    ${LIBBASE}/parsebool.cpp
    ${LIBBASE}/parsenetaddress.cpp
    ${LIBBASE}/process.cpp
    ${LIBBASE}/properties.cpp
    ${LIBBASE}/stringprintf.cpp
    ${LIBBASE}/strings.cpp
    ${LIBBASE}/threads.cpp
    ${LIBBASE}/test_utils.cpp
    ${LIBBASE}/errors_unix.cpp
    )


include_directories(
    ${liblog_headers}
    ${libbase_headers}
    )

set(CMAKE_C_FLAGS  " \
    -Wall \
    -Werror \
    -Wextra \
    -D_FILE_OFFSET_BITS=64 \
    ")

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Wexit-time-destructors \
    ")

add_library(base STATIC ${LIBBASE_SRC_FILES})
target_link_libraries(base)
