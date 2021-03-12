cmake_minimum_required(VERSION 3.14.2)

project(libext2_uuid)

set(EXT2UUID ${AOSP}/external/e2fsprogs/lib/uuid)

set(LIBEXT2_UUID_SRC_FILES
    ${EXT2UUID}/clear.c
    ${EXT2UUID}/compare.c
    ${EXT2UUID}/copy.c
    ${EXT2UUID}/gen_uuid.c
    ${EXT2UUID}/isnull.c
    ${EXT2UUID}/pack.c
    ${EXT2UUID}/parse.c
    ${EXT2UUID}/unpack.c
    ${EXT2UUID}/unparse.c
    ${EXT2UUID}/uuid_time.c
    )

include_directories(${EXT2UUID}/../)

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -Wno-unused-function -Wno-unused-parameter")

add_library(ext2_uuid STATIC ${LIBEXT2_UUID_SRC_FILES})
target_link_libraries(ext2_uuid)
