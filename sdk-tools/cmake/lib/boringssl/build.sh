#!/bin/bash

# check git
if [ ! -x "$(command -v git)" ]; then
  echo 'Warnning: git is not installed.' 
  pkg install git 1>&1
fi

# check ninja
if [ ! -x "$(command -v ninja)" ]; then
  echo 'Warnning: ninja is not installed.'
  pkg install ninja 1>&1
fi

# check perl
if [ ! -x "$(command -v perl)" ]; then
  echo 'Warnning: perl is not installed.'
  pkg install perl 1>&1
fi

# check go
if [ ! -x "$(command -v go)" ]; then
  echo 'Warnning: golang is not installed.'
  pkg install golang 1>&1
fi

# check boringssl
if [ ! -f "boringssl/CMakeLists.txt" ];then
  git clone https://github.com/google/boringssl 1>&1
fi

# check build directory
if [ ! -d "build" ];then
  mkdir build && cd build
else
  cd build
fi

# set ndk toolchain
# /path/to/android-ndk-r21d/toolchains/llvm/prebuilt/linux-aarch64
TOOLCHAIN=$HOME/android/android-ndk-r22/toolchains/llvm/prebuilt/linux-aarch64

# check toolchain
if [ ! -d "$TOOLCHAIN" ];then
  echo "The toolchain cannot be found, please set the toolchain path correctly."
  exit 1
fi

cmake -G 'Ninja' \
    -DCMAKE_C_COMPILER=$TOOLCHAIN/bin/aarch64-linux-android30-clang \
    -DCMAKE_CXX_COMPILER=$TOOLCHAIN/bin/aarch64-linux-android30-clang++ \
    -DCMAKE_SYSROOT=$TOOLCHAIN/sysroot \
    -DCMAKE_BUILD_TYPE=Release \
    ../boringssl 1>&1
    
ninja -j16 1>&1

