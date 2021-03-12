cmake_minimum_required(VERSION 3.14.2)

project(boringssl)

# because ${AOSP}/external/boringssl has a link error
# so choose the official boringssl to compile

execute_process(
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )

