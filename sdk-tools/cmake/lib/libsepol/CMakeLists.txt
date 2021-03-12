cmake_minimum_required(VERSION 3.14.2)

project(libsepol)

set(LIBSEPOL ${AOSP}/external/selinux/libsepol)

set(LIBSEPOL_SRC_FILES
     ${LIBSEPOL}/src/assertion.c
     ${LIBSEPOL}/src/avrule_block.c
     ${LIBSEPOL}/src/avtab.c
     ${LIBSEPOL}/src/boolean_record.c
     ${LIBSEPOL}/src/booleans.c
     ${LIBSEPOL}/src/conditional.c
     ${LIBSEPOL}/src/constraint.c
     ${LIBSEPOL}/src/context.c
     ${LIBSEPOL}/src/context_record.c
     ${LIBSEPOL}/src/debug.c
     ${LIBSEPOL}/src/ebitmap.c
     ${LIBSEPOL}/src/expand.c
     ${LIBSEPOL}/src/handle.c
     ${LIBSEPOL}/src/hashtab.c
     ${LIBSEPOL}/src/hierarchy.c
     ${LIBSEPOL}/src/iface_record.c
     ${LIBSEPOL}/src/interfaces.c
     ${LIBSEPOL}/src/kernel_to_cil.c
     ${LIBSEPOL}/src/kernel_to_common.c
     ${LIBSEPOL}/src/kernel_to_conf.c
     ${LIBSEPOL}/src/link.c
     ${LIBSEPOL}/src/mls.c
     ${LIBSEPOL}/src/module.c
     ${LIBSEPOL}/src/module_to_cil.c
     ${LIBSEPOL}/src/node_record.c
     ${LIBSEPOL}/src/nodes.c
     ${LIBSEPOL}/src/optimize.c
     ${LIBSEPOL}/src/polcaps.c
     ${LIBSEPOL}/src/policydb.c
     ${LIBSEPOL}/src/policydb_convert.c
     ${LIBSEPOL}/src/policydb_public.c
     ${LIBSEPOL}/src/port_record.c
     ${LIBSEPOL}/src/ports.c
     ${LIBSEPOL}/src/roles.c
     ${LIBSEPOL}/src/services.c
     ${LIBSEPOL}/src/sidtab.c
     ${LIBSEPOL}/src/symtab.c
     ${LIBSEPOL}/src/user_record.c
     ${LIBSEPOL}/src/users.c
     ${LIBSEPOL}/src/util.c
     ${LIBSEPOL}/src/write.c
     ${LIBSEPOL}/cil/src/android.c
     ${LIBSEPOL}/cil/src/cil_binary.c
     ${LIBSEPOL}/cil/src/cil_build_ast.c
     ${LIBSEPOL}/cil/src/cil.c
     ${LIBSEPOL}/cil/src/cil_copy_ast.c
     ${LIBSEPOL}/cil/src/cil_find.c
     ${LIBSEPOL}/cil/src/cil_fqn.c
     ${LIBSEPOL}/cil/src/cil_lexer.l
     ${LIBSEPOL}/cil/src/cil_list.c
     ${LIBSEPOL}/cil/src/cil_log.c
     ${LIBSEPOL}/cil/src/cil_mem.c
     ${LIBSEPOL}/cil/src/cil_parser.c
     ${LIBSEPOL}/cil/src/cil_policy.c
     ${LIBSEPOL}/cil/src/cil_post.c
     ${LIBSEPOL}/cil/src/cil_reset_ast.c
     ${LIBSEPOL}/cil/src/cil_resolve_ast.c
     ${LIBSEPOL}/cil/src/cil_stack.c
     ${LIBSEPOL}/cil/src/cil_strpool.c
     ${LIBSEPOL}/cil/src/cil_symtab.c
     ${LIBSEPOL}/cil/src/cil_tree.c
     ${LIBSEPOL}/cil/src/cil_verify.c
     ${LIBSEPOL}/cil/src/cil_write_ast.c
    )

set(CMAKE_C_FLAGS " \
    -D_GNU_SOURCE \
    -Wall \
    -Werror \
    -Wno-void-pointer-to-enum-cast \
    -Wundef \
    -Wshadow \
    -Wno-error=missing-noreturn \
    -Wmissing-format-attribute \
    ")

include_directories(
    ${libsepol_headers}
    ${LIBSEPOL}/src
    ${LIBSEPOL}/cil/src
    )

add_library(sepol STATIC ${LIBSEPOL_SRC_FILES})
target_link_libraries(sepol)
