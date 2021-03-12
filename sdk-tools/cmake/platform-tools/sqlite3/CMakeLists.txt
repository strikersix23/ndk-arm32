cmake_minimum_required(VERSION 3.14.2)

project(sqlite3)

add_subdirectory(libandroidicu)
add_subdirectory(libandroidicuinit)
add_subdirectory(libicuuc)
add_subdirectory(libicui18n)
add_subdirectory(libicudata)


set(SQLITE ${AOSP}/external/sqlite)

# libsqlite3_android
set(LIBSQLITE3_ANDROID_SRC_FILES
    ${SQLITE}/android/PhoneNumberUtils.cpp
    ${SQLITE}/android/OldPhoneNumberUtils.cpp
    ${SQLITE}/android/sqlite3_android.cpp
    )


set(CMAKE_CXX_FLAGS " \
    ${GLOBAL_CXX_FLAGS} \
    -Wno-unused-function \
    -Wno-unused-variable \
    -DSQLITE_ENABLE_ICU \
    -DPIC \
    -fPIC \
    ")

set(CMAKE_C_FLAGS " \
    ${GLOBAL_C_FLAGS} \
    -DSQLITE_ENABLE_ICU \
    -DNDEBUG=1 \
    -DHAVE_USLEEP=1 \
    -DSQLITE_HAVE_ISNAN \
    -DSQLITE_DEFAULT_JOURNAL_SIZE_LIMIT=1048576 \
    -DSQLITE_THREADSAFE=2 \
    -DSQLITE_TEMP_STORE=3 \
    -DSQLITE_POWERSAFE_OVERWRITE=1 \
    -DSQLITE_DEFAULT_FILE_FORMAT=4 \
    -DSQLITE_DEFAULT_AUTOVACUUM=1 \
    -DSQLITE_ENABLE_MEMORY_MANAGEMENT=1 \
    -DSQLITE_ENABLE_FTS3 \
    -DSQLITE_ENABLE_FTS3_BACKWARDS \
    -DSQLITE_ENABLE_FTS4 \
    -DSQLITE_OMIT_BUILTIN_TEST \
    -DSQLITE_OMIT_COMPILEOPTION_DIAGS \
    -DSQLITE_OMIT_LOAD_EXTENSION \
    -DSQLITE_DEFAULT_FILE_PERMISSIONS=0600 \
    -DSQLITE_SECURE_DELETE \
    -DSQLITE_ENABLE_BATCH_ATOMIC_WRITE \
    -DBIONIC_IOCTL_NO_SIGNEDNESS_OVERLOAD \
    -Wno-unused-parameter \
    -DUSE_PREAD64 \
    -Dfdatasync=fdatasync \
    -DHAVE_MALLOC_H=1 \
    -DHAVE_MALLOC_USABLE_SIZE \
    -DPIC \
    -fPIC \
    ")

include_directories(
    ${sqlite_headers}
    ${icu_headers}
    ${liblog_headers}
    )

link_directories(
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/sqlite3/libicuuc
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/sqlite3/libicudata
    ${CMAKE_SOURCE_DIR}/cmake/platform-tools/sqlite3/libicui18n
    )

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(sqlite3_android STATIC ${LIBSQLITE3_ANDROID_SRC_FILES})
target_link_libraries(sqlite3_android)

add_library(sqlite STATIC ${SQLITE}/dist/sqlite3.c)
target_link_libraries(sqlite)

add_executable(sqlite3 ${SQLITE}/dist/shell.c)
target_link_libraries(sqlite3 
    sqlite 
    sqlite3_android 
    androidicu 
    androidicuinit 
    icui18n 
    icuuc 
    icudata 
    base 
    log 
    utils 
    c++ 
    c++abi 
    -ldl
    )

