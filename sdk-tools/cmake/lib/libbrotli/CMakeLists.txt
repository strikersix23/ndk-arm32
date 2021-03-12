cmake_minimum_required(VERSION 3.14.2)

project(libbrotli)

set(BROTLI ${AOSP}/external/brotli)

aux_source_directory(${BROTLI}/c/common LIBBROTLI_SRC_FILES)

aux_source_directory(${BROTLI}/c/dec LIBBROTLI_SRC_FILES)

aux_source_directory(${BROTLI}/c/enc LIBBROTLI_SRC_FILES)

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")

include_directories(${libbrotli_headers})

add_library(brotli STATIC ${LIBBROTLI_SRC_FILES})
target_link_libraries(brotli)
