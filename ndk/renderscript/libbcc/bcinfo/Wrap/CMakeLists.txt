cmake_minimum_required(VERSION 3.14.2)

project(Wrap)

set(Wrap_SRC_FILES
	bitcode_wrapperer.cpp
    file_wrapper_input.cpp
    file_wrapper_output.cpp
    in_memory_wrapper_input.cpp
    wrapper_output.cpp
	)

add_library(LLVMWrap STATIC ${Wrap_SRC_FILES})

target_link_libraries(LLVMWrap)


