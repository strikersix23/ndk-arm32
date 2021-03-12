cmake_minimum_required(VERSION 3.14.2)

project(mdnsresponder)

set(MDNSRESPONDER ${AOSP}/external/mdnsresponder)

set(LIBMDNSSD_SRC_FILES
    ${MDNSRESPONDER}/mDNSShared/dnssd_clientlib.c
    ${MDNSRESPONDER}/mDNSShared/dnssd_clientstub.c
    ${MDNSRESPONDER}/mDNSShared/dnssd_ipc.c
    )

set(CMAKE_C_FLAGS " \
    -O2 \
    -g \
    -fno-strict-aliasing \
    -fwrapv \
    -D_GNU_SOURCE \
    -DHAVE_IPV6 \
    -DNOT_HAVE_SA_LEN \
    -DPLATFORM_NO_RLIMIT \
    -W \
    -Wall \
    -Wextra \
    -Wno-address-of-packed-member \
    -Wno-array-bounds \
    -Wno-pointer-sign \
    -Wno-unused \
    -Wno-unused-const-variable \
    -Wno-unused-parameter \
    -Werror=implicit-function-declaration \
    -DTARGET_OS_LINUX \
    -DHAVE_LINUX \
    -DUSES_NETLINK \
    -Werror \
    ")

add_definitions(-DMDNS_UDS_SERVERPATH="/dev/socket/mdnsd")
add_definitions(-DMDNS_USERNAME="mdnsr")
add_definitions(-DMDNS_DEBUGMSGS=0)

add_library(mdnssd STATIC ${LIBMDNSSD_SRC_FILES})
target_link_libraries(mdnssd)
