cmake_minimum_required(VERSION 3.14.2)

project(libusb)

set(LIBUSB ${AOSP}/external/libusb)

set(LIBUSB_SRC_FILES
    ${LIBUSB}/libusb/core.c
    ${LIBUSB}/libusb/descriptor.c
    ${LIBUSB}/libusb/hotplug.c
    ${LIBUSB}/libusb/io.c
    ${LIBUSB}/libusb/sync.c
    ${LIBUSB}/libusb/strerror.c
    ${LIBUSB}/libusb/os/linux_usbfs.c
    ${LIBUSB}/libusb/os/events_posix.c
    ${LIBUSB}/libusb/os/threads_posix.c
    ${LIBUSB}/libusb/os/linux_netlink.c
    )

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -Wall \
    -Wno-error=sign-compare \
    -Wno-error=switch \
    -Wno-error=unused-function \
    -Wno-unused-parameter \
    -Wno-unused-function \
    ")

include_directories(
    ${libusb_headers}
    ${LIBUSB}/libusb
    ${LIBUSB}/libusb/os
    ${LIBUSB}/linux
    )

add_library(usb STATIC ${LIBUSB_SRC_FILES})
target_link_libraries(usb)
