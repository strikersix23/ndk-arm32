cmake_minimum_required(VERSION 3.14.2)

project(libdexfile)

set(LIBDEXFILE ${AOSP}/art/libdexfile)

set(LIBDEXFILE_SRC_FILES
    ${LIBDEXFILE}/dex/art_dex_file_loader.cc
    ${LIBDEXFILE}/dex/compact_dex_file.cc
    ${LIBDEXFILE}/dex/compact_offset_table.cc
    ${LIBDEXFILE}/dex/descriptors_names.cc
    ${LIBDEXFILE}/dex/dex_file.cc
    ${LIBDEXFILE}/dex/dex_file_exception_helpers.cc
    ${LIBDEXFILE}/dex/dex_file_layout.cc
    ${LIBDEXFILE}/dex/dex_file_loader.cc
    ${LIBDEXFILE}/dex/dex_file_tracking_registrar.cc
    ${LIBDEXFILE}/dex/dex_file_verifier.cc
    ${LIBDEXFILE}/dex/dex_instruction.cc
    ${LIBDEXFILE}/dex/modifiers.cc
    ${LIBDEXFILE}/dex/primitive.cc
    ${LIBDEXFILE}/dex/signature.cc
    ${LIBDEXFILE}/dex/standard_dex_file.cc
    ${LIBDEXFILE}/dex/type_lookup_table.cc
    ${LIBDEXFILE}/dex/utf.cc
    )

include_directories(
    ${libbase_headers}
    ${liblog_headers}
    ${libartbase_headers}
    ${libdexfile_headers}
    ${libartpalette_headers}
    ${libziparchive_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS}")

add_library(dexfile STATIC ${LIBDEXFILE_SRC_FILES})
target_link_libraries(dexfile)
