cmake_minimum_required(VERSION 3.14.2)

project(platform-tools)

add_subdirectory(dmtracedump)
add_subdirectory(hprof-conv)
add_subdirectory(etc1tool)
add_subdirectory(sqlite3)
add_subdirectory(e2fsprogs)
add_subdirectory(f2fs-tools)
add_subdirectory(adb)
add_subdirectory(fastboot)

