cmake_minimum_required(VERSION 3.14.2)

project(dmtracedump)

set(DMTRACEDUMP ${AOSP}/art/tools/dmtracedump)

set(DMTRACEDUMP_SRC_FILES
    ${DMTRACEDUMP}/tracedump.cc
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(dmtracedump ${DMTRACEDUMP_SRC_FILES})
target_link_libraries(dmtracedump c++ c++abi)
