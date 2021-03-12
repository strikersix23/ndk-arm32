cmake_minimum_required(VERSION 3.14.2)

project(liblog)

set(LIBLOG_SRC_FILES
    log_event_list.cpp    
    log_event_write.cpp    
    logger_name.cpp    
    logger_read.cpp    
    logger_write.cpp    
    logprint.cpp    
    properties.cpp    
    event_tag_map.cpp    
    log_time.cpp    
    pmsg_reader.cpp    
    pmsg_writer.cpp    
    logd_reader.cpp    
    logd_writer.cpp    
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -std=c++17 \
    -Wno-c99-designator \
    -DLIBLOG_LOG_TAG=1006 \
    -DSNET_EVENT_LOG_TAG=1397638484 \
    ")


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include_vndk
    )

add_library(log STATIC ${LIBLOG_SRC_FILES})
target_link_libraries(log)
