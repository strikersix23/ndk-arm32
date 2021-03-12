cmake_minimum_required(VERSION 3.14.2)

project(libbcinfo)

set(LIBBCINFO_SRC_FILES
	BitcodeTranslator.cpp 
	BitcodeWrapper.cpp 
	MetadataExtractor.cpp 
	)


add_subdirectory(BitReader_2_7)
add_subdirectory(BitReader_3_0)
add_subdirectory(Wrap)
add_subdirectory(tools)


add_library(bcinfo_static STATIC ${LIBBCINFO_SRC_FILES})

target_link_libraries(bcinfo_static LLVMWrap LLVMBitReader_2_7 LLVMBitReader_3_0 LLVMBitWriter_3_2 StripUnkAttr LLVMBitReader LLVMCore LLVMSupport log)





