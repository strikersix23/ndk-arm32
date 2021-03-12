cmake_minimum_required(VERSION 3.14.2)

project(e2fsprogs)

add_subdirectory(libext2_blkid)
add_subdirectory(libext2_e2p)
add_subdirectory(libext2_com_err)
add_subdirectory(libext2fs)
add_subdirectory(libext2_quota)
add_subdirectory(libext2_uuid)
add_subdirectory(mke2fs)
add_subdirectory(e2fsdroid)