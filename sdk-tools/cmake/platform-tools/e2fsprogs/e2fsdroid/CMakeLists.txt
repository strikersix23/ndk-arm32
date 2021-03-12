cmake_minimum_required(VERSION 3.14.2)

project(e2fsdroid)

set(E2FSDROID ${AOSP}/external/e2fsprogs/contrib/android)

set(E2FSDROID_SRC_FILES
    ${E2FSDROID}/e2fsdroid.c
    ${E2FSDROID}/block_range.c
    ${E2FSDROID}/fsmap.c
    ${E2FSDROID}/block_list.c
    ${E2FSDROID}/base_fs.c
    ${E2FSDROID}/perms.c
    ${E2FSDROID}/basefs_allocator.c
    )

include_directories(
    ${libselinux_headers}
    ${libcutils_headers}
    ${E2FSDROID}/../../lib
    ${E2FSDROID}/../../lib/ext2fs
    ${E2FSDROID}/../../misc
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(e2fsdroid ${E2FSDROID_SRC_FILES})
target_link_libraries(e2fsdroid 
    ext2_misc 
    ext2fs 
    ext2_com_err 
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
    -ldl
    )
