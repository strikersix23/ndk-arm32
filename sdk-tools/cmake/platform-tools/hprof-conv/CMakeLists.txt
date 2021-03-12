cmake_minimum_required(VERSION 3.14.2)

project(hprof-conv)

set(HPROF-CONV ${AOSP}/dalvik/tools/hprof-conv)

set(HPROF-CONV_SRC_FILES
    ${HPROF-CONV}/HprofConv.c
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(hprof-conv ${HPROF-CONV_SRC_FILES})
target_link_libraries(hprof-conv)
