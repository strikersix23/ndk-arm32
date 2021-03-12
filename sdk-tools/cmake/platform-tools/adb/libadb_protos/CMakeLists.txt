cmake_minimum_required(VERSION 3.14.2)

project(libadb_protos)

set(PROTO ${AOSP}/packages/modules/adb/proto)

set(LIBADB_PROTOS_SRC_FILES "")

# check key_type.pb.cc
if (EXISTS ${PROTO}/packages/modules/adb/proto/key_type.pb.cc)
    list(APPEND LIBADB_PROTOS_SRC_FILES ${PROTO}/packages/modules/adb/proto/key_type.pb.cc)
else ()                                             
    # generate key_type.pb.h and key_type.pb.cc
    execute_process(
        COMMAND ${CMAKE_BINARY_DIR}/cmake/lib/protobuf/aprotoc 
        packages/modules/adb/proto/key_type.proto
        --cpp_out=packages/modules/adb/proto
        WORKING_DIRECTORY ${AOSP}
        )
endif ()

# check adb_known_hosts.pb.cc
if (EXISTS ${PROTO}/packages/modules/adb/proto/adb_known_hosts.pb.cc)
    list(APPEND LIBADB_PROTOS_SRC_FILES ${PROTO}/packages/modules/adb/proto/adb_known_hosts.pb.cc)
else ()                                             
    # generate adb_known_hosts.pb.h and adb_known_hosts.pb.cc
    execute_process(
        COMMAND ${CMAKE_BINARY_DIR}/cmake/lib/protobuf/aprotoc 
        packages/modules/adb/proto/adb_known_hosts.proto
        --cpp_out=packages/modules/adb/proto
        WORKING_DIRECTORY ${AOSP}
        )
endif ()

# check app_processes.pb.cc
if (EXISTS ${PROTO}/packages/modules/adb/proto/app_processes.pb.cc)
    list(APPEND LIBADB_PROTOS_SRC_FILES ${PROTO}/packages/modules/adb/proto/app_processes.pb.cc)
else ()                                             
    # generate app_processes.pb.h and app_processes.pb.cc
    execute_process(
        COMMAND ${CMAKE_BINARY_DIR}/cmake/lib/protobuf/aprotoc 
        packages/modules/adb/proto/app_processes.proto
        --cpp_out=packages/modules/adb/proto
        WORKING_DIRECTORY ${AOSP}
        )
endif ()

# check pairing.pb.cc
if (EXISTS ${PROTO}/packages/modules/adb/proto/pairing.pb.cc)
    list(APPEND LIBADB_PROTOS_SRC_FILES ${PROTO}/packages/modules/adb/proto/pairing.pb.cc)
else ()                                             
    # generate pairing.pb.h and pairing.pb.cc
    execute_process(
        COMMAND ${CMAKE_BINARY_DIR}/cmake/lib/protobuf/aprotoc 
        packages/modules/adb/proto/pairing.proto
        --cpp_out=packages/modules/adb/proto
        WORKING_DIRECTORY ${AOSP}
        )
endif ()

include_directories(
    ${PROTO}
    ${protobuf_headers}
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Wall \
    -Werror \
    -Wextra \
    -Wthread-safety \
    ")

add_library(adb_protos STATIC ${LIBADB_PROTOS_SRC_FILES})
target_link_libraries(adb_protos)
