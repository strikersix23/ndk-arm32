cmake_minimum_required(VERSION 3.14.2)

project(liblog)

set(LOG ${AOSP}/system/logging/liblog)

# liblog src files
set(LIBLOG_SRC_FILES
    ${LOG}/log_event_list.cpp
    ${LOG}/log_event_write.cpp
    ${LOG}/logger_name.cpp
    ${LOG}/logger_read.cpp
    ${LOG}/logger_write.cpp
    ${LOG}/logprint.cpp
    ${LOG}/event_tag_map.cpp
    ${LOG}/log_time.cpp
    ${LOG}/properties.cpp
    ${LOG}/pmsg_reader.cpp
    ${LOG}/pmsg_writer.cpp
    ${LOG}/logd_reader.cpp
    ${LOG}/logd_writer.cpp
    )

include_directories(
    ${liblog_headers}
    ${libbase_headers}
    ${libutils_headers}
    ${libcutils_headers}
    ${libsystem_headers}
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Wall \
    -Werror \
    -Wextra \
    -Wno-c99-designator \
    -DLIBLOG_LOG_TAG=1006 \
    -DSNET_EVENT_LOG_TAG=1397638484 \
    ")

add_library(log STATIC ${LIBLOG_SRC_FILES})

target_link_libraries(log)

