cmake_minimum_required(VERSION 3.14.2)

project(libdiagnose_usb)

set(DIAGNOSE_USB ${AOSP}/system/core/diagnose_usb)

set(CMAKE_CXX_FLAGS "${GLOBAL_CXX_FLAGS} -Wextra")

include_directories(
    ${libdiagnose_usb_headers}
    ${libbase_headers}
    )

add_library(diagnose_usb STATIC ${DIAGNOSE_USB}/diagnose_usb.cpp)
target_link_libraries(diagnose_usb)
