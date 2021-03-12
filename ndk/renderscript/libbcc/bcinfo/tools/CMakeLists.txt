cmake_minimum_required(VERSION 3.14.2)

project(bcinfo)

set(BCINFO_SRC_FILES
	main.cpp
	)

#set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(bcinfo  ${BCINFO_SRC_FILES})
target_link_libraries(bcinfo bcinfo_static clang_static LLVM_static -lm -llog)


