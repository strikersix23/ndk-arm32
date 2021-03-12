cmake_minimum_required(VERSION 3.14.2)

project(libpackagelistparser)

set(LIBPACKAGELISTPARSER ${AOSP}/system/core/libpackagelistparser)

set(LIBPACKAGELISTPARSER_SRC_FILES
    ${LIBPACKAGELISTPARSER}/packagelistparser.cpp
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")

include_directories(
    ${libbase_headers}
    ${liblog_headers}
    ${libpackagelistparser_headers}
    )

add_library(packagelistparser STATIC ${LIBPACKAGELISTPARSER_SRC_FILES})
target_link_libraries(packagelistparser)


