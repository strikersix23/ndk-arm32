cmake_minimum_required(VERSION 3.14.2)

project(sdk-tools)

# android source code 
set(AOSP ${CMAKE_SOURCE_DIR}/android-11)


# headers files
set(native_headers
    ${AOSP}/frameworks/native/include
    ${AOSP}/frameworks/native/libs/binder/include
    )
        
set(safe_iop_headers
    ${AOSP}/external/safe-iop/include
    )
        
set(libbacktrace_headers
    ${AOSP}/system/unwinding/libbacktrace
    ${AOSP}/system/unwinding/libbacktrace/include
    )
                
set(libsystem_headers
    ${AOSP}/system/core/libsystem/include
    )

set(androidfw_headers
    ${AOSP}/frameworks/base/libs/androidfw/include
    )
        
set(expat_headers
    ${AOSP}/external/expat
    ${AOSP}/external/expat/lib
    )
         
set(libpng_headers
    ${AOSP}/external/libpng
    )
                
set(protobuf_headers
    ${AOSP}/external/protobuf/android
    ${AOSP}/external/protobuf/src
    )
                
set(zlib_headers
    ${AOSP}/external/zlib
    ${AOSP}/external/zlib/src
    )

set(libcxx_headers
    ${AOSP}/external/libcxx/include
    )

set(libcxxabi_headers
    ${AOSP}/external/libcxxabi/include
    )

set(compiler-rt_headers
    ${AOSP}/external/compiler-rt/include
    )

set(libbase_headers
    ${AOSP}/system/libbase/include
    )
        
set(libcutils_headers
    ${AOSP}/system/core/libcutils
    ${AOSP}/system/core/libcutils/include
    )
        
set(liblog_headers
    ${AOSP}/system/logging/liblog
    ${AOSP}/system/logging/liblog/include
    )
        
set(libutils_headers
    ${AOSP}/system/core/libutils
    ${AOSP}/system/core/libutils/include
    )
        
set(libziparchive_headers
    ${AOSP}/system/libziparchive
    ${AOSP}/system/libziparchive/include
    )
        
set(libnativehelper_headers
    ${AOSP}/libnativehelper/include_jni
    )
        
set(aapt_headers
    ${AOSP}/frameworks/base/tools/aapt
    )
                
set(aapt2_headers
    ${AOSP}/frameworks/base/tools/aapt2
    ${AOSP}/frameworks/base/tools/aapt2/frameworks/base/tools/aapt2
    )
        
set(aidl_headers
    ${AOSP}/system/tools/aidl
    )

set(libzopfli_headers
    ${AOSP}/external/zopfli/src
    )

set(zipalign_headers
    ${AOSP}/build/tools/zipalign
    )

set(libprocessgroup_headers
    ${AOSP}/system/core/libprocessgroup
    ${AOSP}/system/core/libprocessgroup/include
    ${AOSP}/system/core/libprocessgroup/cgrouprc/include
    ${AOSP}/system/core/libprocessgroup/cgrouprc_format/include
    )

set(libvndksupport_headers
    ${AOSP}/system/core/libvndksupport/include
    ${AOSP}/system/core/libvndksupport/include/vndksupport
    )

set(libjsoncpp_headers
    ${AOSP}/external/jsoncpp/include
    )
	
set(libbuildversion_headers
    ${AOSP}/build/soong/cc/libbuildversion/include
    )

set(gtest_headers                         
    ${AOSP}/external/googletest/googletest/include           
    ${AOSP}/external/googletest/googlemock/include                   
    )
	
set(cpu_features_headers                         
    ${AOSP}/external/cpu_features/include                              
    )
	
set(libartpalette_headers                        
    ${AOSP}/art/libartpalette/include                              
    )

set(libartbase_headers                        
    ${AOSP}/art/libartbase                     
    )
	
set(libdexfile_headers                        
    ${AOSP}/art/libdexfile       
    )
	
set(slang_headers                        
    ${AOSP}/frameworks/compile/slang       
    )

set(libbcc_headers                        
    ${AOSP}/frameworks/compile/libbcc       
    )	
	
set(llvm_headers                        
    ${AOSP}/external/llvm/include       
    )
	
set(clang_headers                        
    ${AOSP}/external/clang/include       
    )
    
set(etc1tool_headers                        
    ${AOSP}/frameworks/native/opengl/include       
    )
    
set(sqlite_headers                        
    ${AOSP}/external/sqlite/android
    ${AOSP}/external/sqlite/dist
    )
    
set(icu_headers     
    ${AOSP}/external/icu/icu4c/source/common                   
    ${AOSP}/external/icu/libandroidicu/include
    ${AOSP}/external/icu/libandroidicuinit/include
    
    )
	
set(libsparse_headers                        
    ${AOSP}/system/core/libsparse/include
    )
    
set(libsepol_headers                        
    ${AOSP}/external/selinux/libsepol/include
    ${AOSP}/external/selinux/libsepol/cil/include
    )
    
set(libselinux_headers                        
    ${AOSP}/external/selinux/libselinux/include
    )
    
set(libpcre2_headers                        
    ${AOSP}/external/pcre/include
    )
    
set(libpackagelistparser_headers                        
    ${AOSP}/system/core/libpackagelistparser/include
    )
    
set(e2fsprogs_headers                        
    ${AOSP}/external/e2fsprogs/lib
    ${AOSP}/external/e2fsprogs/lib/uuid
    )
    
set(f2fs_headers                        
    ${AOSP}/external/f2fs-tools/include
    )
    
set(boringssl_headers                        
    ${AOSP}/external/boringssl/src/include
    )
    
set(libcrypto_utils_headers                        
    ${AOSP}/system/core/libcrypto_utils/include
    )
    
set(adb_headers
    ${AOSP}/packages/modules/adb
    ${AOSP}/packages/modules/adb/crypto/include
    ${AOSP}/packages/modules/adb/tls/include
    ${AOSP}/packages/modules/adb/pairing_auth/include
    ${AOSP}/packages/modules/adb/pairing_connection/include
    ${AOSP}/packages/modules/adb/proto/packages/modules/adb/proto
    )

set(libdiagnose_usb_headers                        
    ${AOSP}/system/core/diagnose_usb/include
    )
    
set(libcrypto_utils_headers                        
    ${AOSP}/system/core/libcrypto_utils/include
    )
    
set(libusb_headers                        
    ${AOSP}/external/libusb/include
    )
    
set(libbrotli_headers                        
    ${AOSP}/external/brotli/c/include
    )
    
set(mdnsresponder_headers                        
    ${AOSP}/external/mdnsresponder/mDNSShared
    )

set(liblz4_headers                        
    ${AOSP}/external/lz4/lib
    )
    
set(libext4_utils_headers                        
    ${AOSP}/system/extras/ext4_utils/include
    )

set(liblp_headers                        
    ${AOSP}/system/core/fs_mgr/liblp/include
    )
    
set(fmtlib_headers                        
    ${AOSP}/external/fmtlib/include
    )
    
set(libidmap2_policies_headers                        
    ${AOSP}/frameworks/base/cmds/idmap2/libidmap2_policies/include
    )
    
set(libavb_headers                        
    ${AOSP}/external/avb
    )
   
set(zstd_headers                        
    ${AOSP}/external/zstd/lib
    )

set(incfs_headers
    ${AOSP}/system/incremental_delivery/incfs/include
    ${AOSP}/system/incremental_delivery/incfs/util/include
    )

set(fmtlib_headers                        
    ${AOSP}/external/fmtlib/include
    )
    
add_subdirectory(cmake)
