cmake_minimum_required(VERSION 3.14.2)

project(tls-test)

enable_language(ASM)

set(LIBTHREAD_SRC_FILES 
    thread.cpp
    threadLS_linux_aarch64.s
    )

set(CMAKE_C_FLAGS "-fPIC -fno-emulated-tls")
# -fno-emulated-tls
set(CMAKE_CXX_FLAGS "-fPIC -fno-emulated-tls")

set(CMAKE_SHARED_LINKER_FLAGS "-fuse-ld=lld")
set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=lld")

add_library(jvm SHARED ${LIBTHREAD_SRC_FILES})
target_link_libraries(jvm)

add_executable(test main.cpp)
target_link_libraries(test jvm)
