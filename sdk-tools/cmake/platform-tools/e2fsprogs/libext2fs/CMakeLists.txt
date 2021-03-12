cmake_minimum_required(VERSION 3.14.2)

project(libext2fs)

set(EXT2FS ${AOSP}/external/e2fsprogs/lib/ext2fs)

set(LIBEXT2FS_SRC_FILES
    ${EXT2FS}/ext2_err.c
    ${EXT2FS}/alloc.c
    ${EXT2FS}/alloc_sb.c
    ${EXT2FS}/alloc_stats.c
    ${EXT2FS}/alloc_tables.c
    ${EXT2FS}/atexit.c
    ${EXT2FS}/badblocks.c
    ${EXT2FS}/bb_inode.c
    ${EXT2FS}/bitmaps.c
    ${EXT2FS}/bitops.c
    ${EXT2FS}/blkmap64_ba.c
    ${EXT2FS}/blkmap64_rb.c
    ${EXT2FS}/blknum.c
    ${EXT2FS}/block.c
    ${EXT2FS}/bmap.c
    ${EXT2FS}/check_desc.c
    ${EXT2FS}/crc16.c
    ${EXT2FS}/crc32c.c
    ${EXT2FS}/csum.c
    ${EXT2FS}/closefs.c
    ${EXT2FS}/dblist.c
    ${EXT2FS}/dblist_dir.c
    ${EXT2FS}/digest_encode.c
    ${EXT2FS}/dirblock.c
    ${EXT2FS}/dirhash.c
    ${EXT2FS}/dir_iterate.c
    ${EXT2FS}/dupfs.c
    ${EXT2FS}/expanddir.c
    ${EXT2FS}/ext_attr.c
    ${EXT2FS}/extent.c
    ${EXT2FS}/fallocate.c
    ${EXT2FS}/fileio.c
    ${EXT2FS}/finddev.c
    ${EXT2FS}/flushb.c
    ${EXT2FS}/freefs.c
    ${EXT2FS}/gen_bitmap.c
    ${EXT2FS}/gen_bitmap64.c
    ${EXT2FS}/get_num_dirs.c
    ${EXT2FS}/get_pathname.c
    ${EXT2FS}/getsize.c
    ${EXT2FS}/getsectsize.c
    ${EXT2FS}/hashmap.c
    ${EXT2FS}/i_block.c
    ${EXT2FS}/icount.c
    ${EXT2FS}/imager.c
    ${EXT2FS}/ind_block.c
    ${EXT2FS}/initialize.c
    ${EXT2FS}/inline.c
    ${EXT2FS}/inline_data.c
    ${EXT2FS}/inode.c
    ${EXT2FS}/io_manager.c
    ${EXT2FS}/ismounted.c
    ${EXT2FS}/link.c
    ${EXT2FS}/llseek.c
    ${EXT2FS}/lookup.c
    ${EXT2FS}/mmp.c
    ${EXT2FS}/mkdir.c
    ${EXT2FS}/mkjournal.c
    ${EXT2FS}/namei.c
    ${EXT2FS}/native.c
    ${EXT2FS}/newdir.c
    ${EXT2FS}/nls_utf8.c
    ${EXT2FS}/openfs.c
    ${EXT2FS}/progress.c
    ${EXT2FS}/punch.c
    ${EXT2FS}/qcow2.c
    ${EXT2FS}/rbtree.c
    ${EXT2FS}/read_bb.c
    ${EXT2FS}/read_bb_file.c
    ${EXT2FS}/res_gdt.c
    ${EXT2FS}/rw_bitmaps.c
    ${EXT2FS}/sha256.c
    ${EXT2FS}/sha512.c
    ${EXT2FS}/swapfs.c
    ${EXT2FS}/symlink.c
    ${EXT2FS}/undo_io.c
    ${EXT2FS}/unix_io.c
    ${EXT2FS}/sparse_io.c
    ${EXT2FS}/unlink.c
    ${EXT2FS}/valid_blk.c
    ${EXT2FS}/version.c
    ${EXT2FS}/test_io.c
    )

include_directories(
    ${EXT2FS}/../
    ${libsparse_headers}
    )

set(CMAKE_C_FLAGS "${GLOBAL_C_FLAGS} -Wno-unused-parameter")

add_library(ext2fs STATIC ${LIBEXT2FS_SRC_FILES})
target_link_libraries(ext2fs)
