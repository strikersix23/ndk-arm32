cmake_minimum_required(VERSION 3.14.2)

project(etc1tool)

set(ETC1TOOL ${AOSP}/development/tools/etc1tool)

set(LIBETC1 ${AOSP}/frameworks/native/opengl/libs/ETC1)

set(ETC1TOOL_SRC_FILES ${ETC1TOOL}/etc1tool.cpp)

set(LIBETC1_SRC_FILES ${LIBETC1}/etc1.cpp)


include_directories(
    ${etc1tool_headers}
    ${libpng_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(ETC1 STATIC ${LIBETC1_SRC_FILES})
target_link_libraries(ETC1)

add_executable(etc1tool ${ETC1TOOL_SRC_FILES})
target_link_libraries(etc1tool 
    expat 
    png 
    ETC1 
    z 
    c++ 
    c++abi 
    -ldl
    )
