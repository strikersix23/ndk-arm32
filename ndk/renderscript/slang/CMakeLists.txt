cmake_minimum_required(VERSION 3.14.2)

project(slang)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -O0 \
    -Wno-deprecated-declarations \
    -Wno-inconsistent-missing-override \
    -Wno-sign-compare \
    -DRS_VERSION=24 \
    -D__DISABLE_ASSERTS \
    -D__ENABLE_INTERNAL_OPTIONS \
    -UTARGET_BUILD_VARIANT \
    -DTARGET_BUILD_VARIANT=eng \
    ")

set(LIBSLANG_SRC_FILES 
	slang.cpp 
	slang_bitcode_gen.cpp
	slang_backend.cpp 
	slang_diagnostic_buffer.cpp
	)

# llvm-rs-as
set(LLVM_RS_AS_SRC_FILES llvm-rs-as.cpp)

# llvm-rs-cc 
set(LLVM_RS_CC_SRC_FILES 
	llvm-rs-cc.cpp 
	rs_cc_options.cpp 
	slang_rs_foreach_lowering.cpp 
	slang_rs_ast_replace.cpp 
	slang_rs_check_ast.cpp 
	slang_rs_context.cpp 
	slang_rs_pragma_handler.cpp 
	slang_rs_exportable.cpp 
	slang_rs_export_type.cpp 
	slang_rs_export_element.cpp 
	slang_rs_export_var.cpp 
	slang_rs_export_func.cpp 
	slang_rs_export_foreach.cpp 
	slang_rs_export_reduce.cpp 
	slang_rs_object_ref_count.cpp 
	slang_rs_reflection.cpp 
	slang_rs_reflection_cpp.cpp 
	slang_rs_reflection_state.cpp 
	slang_rs_reflect_utils.cpp 
	slang_rs_special_func.cpp 
	slang_rs_special_kernel_param.cpp 
	)

# set(LLD_SRC_FILES lld_main.cpp)

include_directories(${CMAKE_SOURCE_DIR}/llvm/include)
include_directories(${CMAKE_SOURCE_DIR}/libbcc/bcinfo/include)

link_directories(${CMAKE_SOURCE_DIR}/llvm/lib)

add_subdirectory(BitWriter_2_9)
add_subdirectory(BitWriter_2_9_func)
add_subdirectory(BitWriter_3_2)
add_subdirectory(StripUnkAttr)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(slang STATIC ${LIBSLANG_SRC_FILES})
target_link_libraries(slang LLVMBitWriter_2_9 LLVMBitWriter_2_9_func LLVMBitWriter_3_2 StripUnkAttr)

add_executable(llvm-rs-as ${LLVM_RS_AS_SRC_FILES})
target_link_libraries(llvm-rs-as slang LLVM_static -ldl -lz -lm)

add_executable(llvm-rs-cc ${LLVM_RS_CC_SRC_FILES})
target_link_libraries(llvm-rs-cc slang clang_static LLVM_static -ldl -lz -lm)




