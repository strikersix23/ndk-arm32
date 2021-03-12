cmake_minimum_required(VERSION 3.14.2)

project(libbcc)

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Wno-deprecated-declarations \
    -Wno-inconsistent-missing-override \
    -DRS_VERSION=24 \
    -D__DISABLE_ASSERTS \
    -DFORCE_ARM64_CODEGEN \
    -DARCH_ARM_HAVE_NEON \
    -DARCH_ARM_HAVE_VFP \
    -DARCH_ARM_HAVE_VFP_D32 \
    -DDISABLE_CLCORE_NEON \
    ")

include_directories(
    ${CMAKE_SOURCE_DIR}/llvm/include
    ${CMAKE_SOURCE_DIR}/slang
    ${CMAKE_SOURCE_DIR}/rs
    ${CMAKE_SOURCE_DIR}/liblog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/bcinfo/include
    )
                   
link_directories(${CMAKE_SOURCE_DIR}/llvm/lib)

add_subdirectory(bcinfo)
add_subdirectory(lib)
add_subdirectory(tools)


