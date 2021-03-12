cmake_minimum_required(VERSION 3.14.2)

project(libext2_blkid)

set(BLKID ${AOSP}/external/e2fsprogs/lib/blkid)

set(LIBEXT2_BLKID_SRC_FILES
    ${BLKID}/cache.c
    ${BLKID}/dev.c
    ${BLKID}/devname.c
    ${BLKID}/devno.c
    ${BLKID}/getsize.c
    ${BLKID}/llseek.c
    ${BLKID}/probe.c
    ${BLKID}/read.c
    ${BLKID}/resolve.c
    ${BLKID}/save.c
    ${BLKID}/tag.c
    ${BLKID}/version.c
    )
    
set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -Wno-error=attributes \
    -Wno-error=pointer-sign \
    -Wno-unused-parameter \
    -fno-strict-aliasing \
    ")

include_directories(${BLKID}/../)

add_library(ext2_blkid STATIC ${LIBEXT2_BLKID_SRC_FILES})
target_link_libraries(ext2_blkid)
