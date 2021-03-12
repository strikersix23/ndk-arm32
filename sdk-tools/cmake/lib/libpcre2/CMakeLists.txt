cmake_minimum_required(VERSION 3.14.2)

project(libpcre2)

set(PCRE ${AOSP}/external/pcre)

set(LIBPCRE2_SRC_FILES
    ${PCRE}/dist2/src/pcre2_auto_possess.c
    ${PCRE}/dist2/src/pcre2_compile.c
    ${PCRE}/dist2/src/pcre2_config.c
    ${PCRE}/dist2/src/pcre2_context.c
    ${PCRE}/dist2/src/pcre2_convert.c
    ${PCRE}/dist2/src/pcre2_dfa_match.c
    ${PCRE}/dist2/src/pcre2_error.c
    ${PCRE}/dist2/src/pcre2_extuni.c
    ${PCRE}/dist2/src/pcre2_find_bracket.c
    ${PCRE}/dist2/src/pcre2_maketables.c
    ${PCRE}/dist2/src/pcre2_match.c
    ${PCRE}/dist2/src/pcre2_match_data.c
    ${PCRE}/dist2/src/pcre2_jit_compile.c
    ${PCRE}/dist2/src/pcre2_newline.c
    ${PCRE}/dist2/src/pcre2_ord2utf.c
    ${PCRE}/dist2/src/pcre2_pattern_info.c
    ${PCRE}/dist2/src/pcre2_script_run.c
    ${PCRE}/dist2/src/pcre2_serialize.c
    ${PCRE}/dist2/src/pcre2_string_utils.c
    ${PCRE}/dist2/src/pcre2_study.c
    ${PCRE}/dist2/src/pcre2_substitute.c
    ${PCRE}/dist2/src/pcre2_substring.c
    ${PCRE}/dist2/src/pcre2_tables.c
    ${PCRE}/dist2/src/pcre2_ucd.c
    ${PCRE}/dist2/src/pcre2_valid_utf.c
    ${PCRE}/dist2/src/pcre2_xclass.c
    ${PCRE}/dist2/src/pcre2_chartables.c
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -DHAVE_CONFIG_H")

include_directories(
    ${libpcre2_headers}
    ${PCRE}/include_internal
    )

add_library(pcre2 STATIC ${LIBPCRE2_SRC_FILES})
target_link_libraries(pcre2)
