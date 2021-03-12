cmake_minimum_required(VERSION 3.14.2)

project(mke2fs)

set(MISC ${AOSP}/external/e2fsprogs/misc)

set(MKE2FS_SRC_FILES
    ${MISC}/mke2fs.c
    ${MISC}/util.c
    ${MISC}/mk_hugefiles.c
    ${MISC}/default_profile.c
    )

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -Wno-error=format-extra-args \
    -Wno-error=format \
    -Wno-error=type-limits \
    -Wno-format-extra-args \
    ")

include_directories(${MISC}/../lib)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(ext2_misc STATIC ${MISC}/create_inode.c)
target_link_libraries(ext2_misc)

add_executable(mke2fs ${MKE2FS_SRC_FILES})
target_link_libraries(mke2fs 
    ext2_misc 
    ext2_blkid 
    ext2fs 
    ext2_uuid  
    ext2_e2p 
    ext2_com_err 
    ext2_quota 
    sparse 
    base 
    z 
    c++ 
    c++abi 
    -ldl
    )
