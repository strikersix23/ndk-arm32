cmake_minimum_required(VERSION 3.14.2)

project(BitReader_2_7)

set(BitReader_2_7_SRC_FILES
	BitcodeReader.cpp 
	)

add_library(LLVMBitReader_2_7 STATIC ${BitReader_2_7_SRC_FILES})

target_link_libraries(LLVMBitReader_2_7)


