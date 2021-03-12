cmake_minimum_required(VERSION 3.14.2)

project(bcc_compat)

set(BCC_COMPAT_SRC_FILES Main.cpp)

#set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(bcc_compat ${BCC_COMPAT_SRC_FILES})
target_link_libraries(bcc_compat bcc bcinfo_static LLVM_static -lz -lm -llog)
