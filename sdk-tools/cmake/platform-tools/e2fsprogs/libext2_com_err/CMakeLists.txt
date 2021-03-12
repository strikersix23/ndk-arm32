cmake_minimum_required(VERSION 3.14.2)

project(libext2_com_err)

set(ET ${AOSP}/external/e2fsprogs/lib/et)

set(LIBEXT2_COM_ERR_SRC_FILES
    ${ET}/error_message.c
    ${ET}/et_name.c
    ${ET}/init_et.c
    ${ET}/com_err.c
    ${ET}/com_right.c
    )

include_directories(${ET}/../)

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")

add_library(ext2_com_err STATIC ${LIBEXT2_COM_ERR_SRC_FILES})
target_link_libraries(ext2_com_err)
