cmake_minimum_required(VERSION 3.14.2)

project(f2fs-tools)

set(F2FS-TOOLS ${AOSP}/external/f2fs-tools)

set(LIBF2FS_FMT_SRC_FILES
    ${F2FS-TOOLS}/lib/libf2fs.c
    ${F2FS-TOOLS}/mkfs/f2fs_format.c
    ${F2FS-TOOLS}/mkfs/f2fs_format_utils.c
    ${F2FS-TOOLS}/lib/libf2fs_zoned.c
    ${F2FS-TOOLS}/lib/nls_utf8.c
    )

set(MAKE_F2FS_SRC_FILES
    ${F2FS-TOOLS}/lib/libf2fs_io.c
    ${F2FS-TOOLS}/mkfs/f2fs_format_main.c
    )

set(FSCK_SRC_FILES
    ${F2FS-TOOLS}/fsck/dir.c
    ${F2FS-TOOLS}/fsck/dict.c
    ${F2FS-TOOLS}/fsck/compress.c
    ${F2FS-TOOLS}/fsck/mkquota.c
    ${F2FS-TOOLS}/fsck/quotaio.c
    ${F2FS-TOOLS}/fsck/quotaio_tree.c
    ${F2FS-TOOLS}/fsck/quotaio_v2.c
    ${F2FS-TOOLS}/fsck/node.c
    ${F2FS-TOOLS}/fsck/segment.c
    ${F2FS-TOOLS}/fsck/xattr.c
    ${F2FS-TOOLS}/fsck/main.c
    ${F2FS-TOOLS}/fsck/mount.c
    ${F2FS-TOOLS}/lib/libf2fs.c
    ${F2FS-TOOLS}/lib/libf2fs_io.c
    ${F2FS-TOOLS}/lib/nls_utf8.c
    ${F2FS-TOOLS}/fsck/dump.c
    )

set(F2FS_SLOAD_SRC_FILES
    ${FSCK_SRC_FILES}
    ${F2FS-TOOLS}/fsck/fsck.c
    ${F2FS-TOOLS}/fsck/sload.c
    )

set(CMAKE_C_FLAGS " \
    -DF2FS_MAJOR_VERSION=1 \
    -DF2FS_MINOR_VERSION=13 \
    -DWITH_ANDROID \
    -DWITH_BLKDISCARD \
    -DWITH_SLOAD \
    -Wall \
    -Wno-format \
    -Wno-macro-redefined \
    -Wno-missing-field-initializers \
    -Wno-pointer-arith \
    -Wno-sign-compare \
    -Wno-unused-function \
    -Wno-string-plus-int \
    ")

add_definitions(-DF2FS_TOOLS_VERSION="1.13.0")
add_definitions(-DF2FS_TOOLS_DATE="2020-06-05")

set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(
    ${f2fs_headers}
    ${e2fsprogs_headers}
    ${libsparse_headers}
    ${libselinux_headers}
    ${libcutils_headers}
    ${liblz4_headers}
    )

add_library(f2fs_fmt STATIC ${LIBF2FS_FMT_SRC_FILES})
target_link_libraries(f2fs_fmt)

add_executable(make_f2fs ${MAKE_F2FS_SRC_FILES})
target_link_libraries(make_f2fs 
    f2fs_fmt 
    ext2_uuid 
    lz4
    sparse 
    base 
    z 
    c++ 
    c++abi 
    dl
    )

add_executable(f2fs_sload ${F2FS_SLOAD_SRC_FILES})
target_link_libraries(f2fs_sload 
    ext2_uuid 
    lz4
    selinux 
    sepol 
    sparse 
    pcre2 
    packagelistparser 
    cutils 
    base 
    log 
    z 
    c++ 
    c++abi 
    dl
    )
