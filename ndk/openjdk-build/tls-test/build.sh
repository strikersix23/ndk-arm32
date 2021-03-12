#!/bin/bash

NDK_TOOLCHAIN=$HOME/android/android-ndk-r22/toolchains/llvm/prebuilt/linux-aarch64

#CC=$NDK_TOOLCHAIN/bin/aarch64-linux-android30-clang

#CXX=$NDK_TOOLCHAIN/bin/aarch64-linux-android30-clang++

CC=clang
CXX=clang++

cmake -G 'Unix Makefiles' \
    -DCMAKE_C_COMPILER=$CC \
    -DCMAKE_CXX_COMPILER=$CXX \
    .

make -j4
