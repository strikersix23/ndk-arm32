cmake_minimum_required(VERSION 3.14.2)

project(libselinux)

set(LIBSELINUX ${AOSP}/external/selinux/libselinux)

set(LIBSELINUX_SRC_FILES
    ${LIBSELINUX}/src/booleans.c    
    ${LIBSELINUX}/src/callbacks.c    
    ${LIBSELINUX}/src/freecon.c    
    ${LIBSELINUX}/src/label_backends_android.c    
    ${LIBSELINUX}/src/label.c    
    ${LIBSELINUX}/src/label_support.c    
    ${LIBSELINUX}/src/matchpathcon.c    
    ${LIBSELINUX}/src/setrans_client.c    
    ${LIBSELINUX}/src/sha1.c    
    ${LIBSELINUX}/src/android/android.c    
    ${LIBSELINUX}/src/avc.c    
    ${LIBSELINUX}/src/avc_internal.c    
    ${LIBSELINUX}/src/avc_sidtab.c    
    ${LIBSELINUX}/src/canonicalize_context.c    
    ${LIBSELINUX}/src/checkAccess.c    
    ${LIBSELINUX}/src/check_context.c    
    ${LIBSELINUX}/src/compute_av.c    
    ${LIBSELINUX}/src/compute_create.c    
    ${LIBSELINUX}/src/compute_member.c    
    ${LIBSELINUX}/src/context.c    
    ${LIBSELINUX}/src/deny_unknown.c    
    ${LIBSELINUX}/src/disable.c    
    ${LIBSELINUX}/src/enabled.c    
    ${LIBSELINUX}/src/fgetfilecon.c    
    ${LIBSELINUX}/src/fsetfilecon.c    
    ${LIBSELINUX}/src/getenforce.c    
    ${LIBSELINUX}/src/getfilecon.c    
    ${LIBSELINUX}/src/get_initial_context.c    
    ${LIBSELINUX}/src/getpeercon.c    
    ${LIBSELINUX}/src/init.c    
    ${LIBSELINUX}/src/lgetfilecon.c    
    ${LIBSELINUX}/src/load_policy.c    
    ${LIBSELINUX}/src/lsetfilecon.c    
    ${LIBSELINUX}/src/mapping.c    
    ${LIBSELINUX}/src/policyvers.c    
    ${LIBSELINUX}/src/procattr.c    
    ${LIBSELINUX}/src/reject_unknown.c    
    ${LIBSELINUX}/src/sestatus.c    
    ${LIBSELINUX}/src/setenforce.c    
    ${LIBSELINUX}/src/setfilecon.c    
    ${LIBSELINUX}/src/stringrep.c 
    ${LIBSELINUX}/src/label_file.c
    ${LIBSELINUX}/src/regex.c
    ${LIBSELINUX}/src/selinux_config.c
    ${LIBSELINUX}/src/seusers.c
    ${LIBSELINUX}/src/android/android_platform.c
    )

set(CMAKE_C_FLAGS " \
    -DNO_PERSISTENTLY_STORED_PATTERNS \
    -DDISABLE_SETRANS \
    -DDISABLE_BOOL \
    -D_GNU_SOURCE \
    -DNO_MEDIA_BACKEND \
    -DNO_X_BACKEND \
    -DNO_DB_BACKEND \
    -Wall \
    -Werror \
    -Wno-error=missing-noreturn \
    -Wno-error=unused-function \
    -Wno-error=unused-variable \
    -DAUDITD_LOG_TAG=1003 \
    -DUSE_PCRE2 \
    ")

include_directories(
    ${libselinux_headers}
    ${libsepol_headers}
    ${libpcre2_headers}
    ${liblog_headers}
    ${libcutils_headers}
    ${libpackagelistparser_headers}
    ${LIBSELINUX}/src
    ${AOSP}/system/core/include
    )

add_library(selinux STATIC ${LIBSELINUX_SRC_FILES})
target_link_libraries(selinux)
