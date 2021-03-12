cmake_minimum_required(VERSION 3.14.2)

project(libext2_quota)

set(SUPPORT ${AOSP}/external/e2fsprogs/lib/support)

set(LIBEXT2_QUOTA_SRC_FILES
    ${SUPPORT}/dict.c
    ${SUPPORT}/mkquota.c
    ${SUPPORT}/parse_qtype.c
    ${SUPPORT}/plausible.c
    ${SUPPORT}/profile.c
    ${SUPPORT}/profile_helpers.c
    ${SUPPORT}/prof_err.c
    ${SUPPORT}/quotaio.c
    ${SUPPORT}/quotaio_tree.c
    ${SUPPORT}/quotaio_v2.c
    )

include_directories(${SUPPORT}/../)

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS}")

add_library(ext2_quota STATIC ${LIBEXT2_QUOTA_SRC_FILES})
target_link_libraries(ext2_quota)
