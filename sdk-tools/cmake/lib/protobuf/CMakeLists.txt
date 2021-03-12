cmake_minimum_required(VERSION 3.14.2)

project(protobuf)

set(PROTOBUF ${AOSP}/external/protobuf)

set(LIBPROTOBUF_CPP_LITE_SRC_FILES
    ${PROTOBUF}/src/google/protobuf/any_lite.cc
    ${PROTOBUF}/src/google/protobuf/arena.cc
    ${PROTOBUF}/src/google/protobuf/extension_set.cc
    ${PROTOBUF}/src/google/protobuf/generated_enum_util.cc
    ${PROTOBUF}/src/google/protobuf/generated_message_table_driven_lite.cc
    ${PROTOBUF}/src/google/protobuf/generated_message_util.cc
    ${PROTOBUF}/src/google/protobuf/implicit_weak_message.cc
    ${PROTOBUF}/src/google/protobuf/io/coded_stream.cc
    ${PROTOBUF}/src/google/protobuf/io/io_win32.cc
    ${PROTOBUF}/src/google/protobuf/io/strtod.cc
    ${PROTOBUF}/src/google/protobuf/io/zero_copy_stream.cc
    ${PROTOBUF}/src/google/protobuf/io/zero_copy_stream_impl.cc
    ${PROTOBUF}/src/google/protobuf/io/zero_copy_stream_impl_lite.cc
    ${PROTOBUF}/src/google/protobuf/message_lite.cc
    ${PROTOBUF}/src/google/protobuf/parse_context.cc
    ${PROTOBUF}/src/google/protobuf/repeated_field.cc
    ${PROTOBUF}/src/google/protobuf/stubs/bytestream.cc
    ${PROTOBUF}/src/google/protobuf/stubs/common.cc
    ${PROTOBUF}/src/google/protobuf/stubs/int128.cc
    ${PROTOBUF}/src/google/protobuf/stubs/status.cc
    ${PROTOBUF}/src/google/protobuf/stubs/statusor.cc
    ${PROTOBUF}/src/google/protobuf/stubs/stringpiece.cc
    ${PROTOBUF}/src/google/protobuf/stubs/stringprintf.cc
    ${PROTOBUF}/src/google/protobuf/stubs/structurally_valid.cc
    ${PROTOBUF}/src/google/protobuf/stubs/strutil.cc
    ${PROTOBUF}/src/google/protobuf/stubs/time.cc
    ${PROTOBUF}/src/google/protobuf/wire_format_lite.cc
    )


set(LIBPROTOBUF_CPP_FULL_SRC_FILES
    ${LIBPROTOBUF_CPP_LITE_SRC_FILES}
    ${PROTOBUF}/src/google/protobuf/any.cc
    ${PROTOBUF}/src/google/protobuf/any.pb.cc
    ${PROTOBUF}/src/google/protobuf/api.pb.cc
    ${PROTOBUF}/src/google/protobuf/compiler/importer.cc
    ${PROTOBUF}/src/google/protobuf/compiler/parser.cc
    ${PROTOBUF}/src/google/protobuf/descriptor.cc
    ${PROTOBUF}/src/google/protobuf/descriptor.pb.cc
    ${PROTOBUF}/src/google/protobuf/descriptor_database.cc
    ${PROTOBUF}/src/google/protobuf/duration.pb.cc
    ${PROTOBUF}/src/google/protobuf/dynamic_message.cc
    ${PROTOBUF}/src/google/protobuf/empty.pb.cc
    ${PROTOBUF}/src/google/protobuf/extension_set_heavy.cc
    ${PROTOBUF}/src/google/protobuf/field_mask.pb.cc
    ${PROTOBUF}/src/google/protobuf/generated_message_reflection.cc
    ${PROTOBUF}/src/google/protobuf/generated_message_table_driven.cc
    ${PROTOBUF}/src/google/protobuf/io/gzip_stream.cc
    ${PROTOBUF}/src/google/protobuf/io/printer.cc
    ${PROTOBUF}/src/google/protobuf/io/tokenizer.cc
    ${PROTOBUF}/src/google/protobuf/map_field.cc
    ${PROTOBUF}/src/google/protobuf/message.cc
    ${PROTOBUF}/src/google/protobuf/reflection_ops.cc
    ${PROTOBUF}/src/google/protobuf/service.cc
    ${PROTOBUF}/src/google/protobuf/source_context.pb.cc
    ${PROTOBUF}/src/google/protobuf/struct.pb.cc
    ${PROTOBUF}/src/google/protobuf/stubs/mathlimits.cc
    ${PROTOBUF}/src/google/protobuf/stubs/substitute.cc
    ${PROTOBUF}/src/google/protobuf/text_format.cc
    ${PROTOBUF}/src/google/protobuf/timestamp.pb.cc
    ${PROTOBUF}/src/google/protobuf/type.pb.cc
    ${PROTOBUF}/src/google/protobuf/unknown_field_set.cc
    ${PROTOBUF}/src/google/protobuf/util/delimited_message_util.cc
    ${PROTOBUF}/src/google/protobuf/util/field_comparator.cc
    ${PROTOBUF}/src/google/protobuf/util/field_mask_util.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/datapiece.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/default_value_objectwriter.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/error_listener.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/field_mask_utility.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/json_escaping.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/json_objectwriter.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/json_stream_parser.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/object_writer.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/proto_writer.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/protostream_objectsource.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/protostream_objectwriter.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/type_info.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/type_info_test_helper.cc
    ${PROTOBUF}/src/google/protobuf/util/internal/utility.cc
    ${PROTOBUF}/src/google/protobuf/util/json_util.cc
    ${PROTOBUF}/src/google/protobuf/util/message_differencer.cc
    ${PROTOBUF}/src/google/protobuf/util/time_util.cc
    ${PROTOBUF}/src/google/protobuf/util/type_resolver_util.cc
    ${PROTOBUF}/src/google/protobuf/wire_format.cc
    ${PROTOBUF}/src/google/protobuf/wrappers.pb.cc
    )


set(LIBPROTOC_SRC_FILES
    ${PROTOBUF}/src/google/protobuf/compiler/code_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/command_line_interface.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_enum.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_enum_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_extension.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_file.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_helpers.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_map_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_message.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_message_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_padding_optimizer.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_primitive_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_service.cc
    ${PROTOBUF}/src/google/protobuf/compiler/cpp/cpp_string_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_doc_comment.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_enum.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_enum_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_field_base.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_helpers.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_map_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_message.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_message_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_primitive_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_reflection_class.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_repeated_enum_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_repeated_message_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_repeated_primitive_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_source_generator_base.cc
    ${PROTOBUF}/src/google/protobuf/compiler/csharp/csharp_wrapper_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_context.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_doc_comment.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_enum.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_enum_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_enum_field_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_enum_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_extension.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_extension_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_file.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_generator_factory.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_helpers.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_map_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_map_field_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message_builder.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message_builder_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message_field_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_message_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_name_resolver.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_primitive_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_primitive_field_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_service.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_shared_code_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_string_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/java/java_string_field_lite.cc
    ${PROTOBUF}/src/google/protobuf/compiler/js/js_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/js/well_known_types_embed.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_enum.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_enum_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_extension.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_file.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_helpers.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_map_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_message.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_message_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_oneof.cc
    ${PROTOBUF}/src/google/protobuf/compiler/objectivec/objectivec_primitive_field.cc
    ${PROTOBUF}/src/google/protobuf/compiler/php/php_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/plugin.cc
    ${PROTOBUF}/src/google/protobuf/compiler/plugin.pb.cc
    ${PROTOBUF}/src/google/protobuf/compiler/python/python_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/ruby/ruby_generator.cc
    ${PROTOBUF}/src/google/protobuf/compiler/subprocess.cc
    ${PROTOBUF}/src/google/protobuf/compiler/zip_writer.cc
    )


include_directories(
    ${protobuf_headers}
    )

set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -frtti \
    -Wall \
    -Werror \
    -Wno-sign-compare \
    -Wno-sign-promo \
    -Wno-unused-function \
    -Wno-inconsistent-missing-override \
    -DHAVE_ZLIB=1 \
    ")

add_library(protobuf-cpp-lite STATIC ${LIBPROTOBUF_CPP_LITE_SRC_FILES})
target_link_libraries(protobuf-cpp-lite)

add_library(protobuf-cpp-full STATIC ${LIBPROTOBUF_CPP_FULL_SRC_FILES})
target_link_libraries(protobuf-cpp-full)

add_library(protoc STATIC ${LIBPROTOC_SRC_FILES})
target_link_libraries(protoc)

add_executable(aprotoc ${PROTOBUF}/src/google/protobuf/compiler/main.cc)
target_link_libraries(aprotoc protoc protobuf-cpp-full log z c++ c++abi)
