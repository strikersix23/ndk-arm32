cmake_minimum_required(VERSION 3.14.2)

project(libartbase)

set(LIBARTBASE ${AOSP}/art/libartbase)

set(LIBARTBASE_SRC_FILES
    ${LIBARTBASE}/arch/instruction_set.cc
    ${LIBARTBASE}/base/allocator.cc
    ${LIBARTBASE}/base/arena_allocator.cc
    ${LIBARTBASE}/base/arena_bit_vector.cc
    ${LIBARTBASE}/base/bit_vector.cc
    ${LIBARTBASE}/base/enums.cc
    ${LIBARTBASE}/base/file_magic.cc
    ${LIBARTBASE}/base/file_utils.cc
    ${LIBARTBASE}/base/hex_dump.cc
    ${LIBARTBASE}/base/hiddenapi_flags.cc
    ${LIBARTBASE}/base/logging.cc
    ${LIBARTBASE}/base/malloc_arena_pool.cc
    ${LIBARTBASE}/base/membarrier.cc
    ${LIBARTBASE}/base/memfd.cc
    ${LIBARTBASE}/base/memory_region.cc
    ${LIBARTBASE}/base/mem_map.cc
    ${LIBARTBASE}/base/os_linux.cc
    ${LIBARTBASE}/base/runtime_debug.cc
    ${LIBARTBASE}/base/safe_copy.cc
    ${LIBARTBASE}/base/scoped_arena_allocator.cc
    ${LIBARTBASE}/base/scoped_flock.cc
    ${LIBARTBASE}/base/socket_peer_is_trusted.cc
    ${LIBARTBASE}/base/time_utils.cc
    ${LIBARTBASE}/base/unix_file/fd_file.cc
    ${LIBARTBASE}/base/unix_file/random_access_file_utils.cc
    ${LIBARTBASE}/base/utils.cc
    ${LIBARTBASE}/base/zip_archive.cc
    ${LIBARTBASE}/base/mem_map_unix.cc
    ${LIBARTBASE}/base/globals_unix.cc
    )

# put in target when fuchsia supported by soong
# ${LIBARTBASE}/base/mem_map_fuchsia.cc

include_directories(
    ${libartbase_headers}
    ${libbase_headers}
    ${liblog_headers}
    ${libziparchive_headers}
    )

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -DBUILDING_LIBART=1")

add_library(artbase STATIC ${LIBARTBASE_SRC_FILES})
target_link_libraries(artbase)
