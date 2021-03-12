cmake_minimum_required(VERSION 3.14.2)

project(libext2_e2p)

set(E2P ${AOSP}/external/e2fsprogs/lib/e2p)

set(LIBEXT2_E2P_SRC_FILES
    ${E2P}/encoding.c
    ${E2P}/feature.c
    ${E2P}/fgetflags.c
    ${E2P}/fsetflags.c
    ${E2P}/fgetproject.c
    ${E2P}/fsetproject.c
    ${E2P}/fgetversion.c
    ${E2P}/fsetversion.c
    ${E2P}/getflags.c
    ${E2P}/getversion.c
    ${E2P}/hashstr.c
    ${E2P}/iod.c
    ${E2P}/ljs.c
    ${E2P}/ls.c
    ${E2P}/mntopts.c
    ${E2P}/parse_num.c
    ${E2P}/pe.c
    ${E2P}/pf.c
    ${E2P}/ps.c
    ${E2P}/setflags.c
    ${E2P}/setversion.c
    ${E2P}/uuid.c
    ${E2P}/ostype.c
    ${E2P}/percent.c
    )

include_directories(${E2P}/../)

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -Wno-error=attributes -Wno-unused-parameter")

add_library(ext2_e2p STATIC ${LIBEXT2_E2P_SRC_FILES})
target_link_libraries(ext2_e2p)
