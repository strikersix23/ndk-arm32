cmake_minimum_required(VERSION 3.14.2)

project(liblp)

set(LIBLP ${AOSP}/system/core/fs_mgr/liblp)

set(LIBLP_SRC_FILES
    ${LIBLP}/builder.cpp
    ${LIBLP}/images.cpp
    ${LIBLP}/partition_opener.cpp
    ${LIBLP}/property_fetcher.cpp
    ${LIBLP}/reader.cpp
    ${LIBLP}/utility.cpp
    ${LIBLP}/writer.cpp
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -D_FILE_OFFSET_BITS=64")

include_directories(
    ${liblp_headers}
    ${libbase_headers}
    ${libsparse_headers}
    ${libext4_utils_headers}
    ${libcutils_headers}
    ${boringssl_headers}
    )

add_library(lp STATIC ${LIBLP_SRC_FILES})
target_link_libraries(lp)
