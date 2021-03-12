### How to use termux-ndk to build android app

* Download the build-essential toolchain, android-ndk android-sdk openjdk from [release](https://github.com/Lzhiyong/termux-ndk/releases) and [gradle](https://gradle.org) 

* Add a local.properties file to the root of the project as below
   ```bash
   # modify the local.properties file
   # please note ndk.dir has been deprecated, but it still works
   sdk.dir=/path/to/android-sdk
   ndk.dir=/path/to/android-ndk
   cmake.dir=/path/to/cmake
   # for example:
   sdk.dir=/data/data/com.termux/files/home/android/android-sdk
   ndk.dir=/data/data/com.termux/files/home/android/android-ndk-r22
   cmake.dir=/data/data/com.termux/files/home/android/android-sdk/cmake
   ```
* Modify the project/build.gradle file
   ```bash
   # setting gradle plugin version 
   # com.android.tools.build:gradle:3.5.1
   # com.android.tools.build:gradle:3.6.3
   # com.android.tools.build:gradle:4.0.1
   # com.android.tools.build:gradle:4.1.1
   # com.android.tools.build:gradle:4.1.2
   # ......
   dependencies {
       classpath 'com.android.tools.build:gradle:4.1.2'
   }
   ```
* Modify the project app/build.gradle
   ```bash
   # setting build tools version
   # 28.0.3 or 29.0.3 or 30.0.3
   android {
       ......
       buildToolsVersion "30.0.3"
       ndkVersion "22.0.7026061"
       defaultConfig {
           externalNativeBuild {
                cmake {
                   arguments "-DANDROID_APP_PLATFORM=android-30", "-DANDROID_STL=c++_static"
                   abiFilters 'armeabi-v7a', 'arm64-v8a', 'x86', 'x86_64'
               }
           }
       }
       ......
   }
   ```

* Execute the `gradle build` command to start building the android app, the below error will occur, this is because the gradle plugin will download a corresponding version of aapt2-4.1.1-6503028-linux.jar, we need to replace it.
<a href="./screenshot/aapt2_xxx_linux_error.jpg"><img src="./screenshot/aapt2_xxx_linux_error.jpg" width="100%" /></a>

* Replace the aapt2-4.1.1-6503028-linux.jar with [gradle-plugin](https://github.com/Lzhiyong/termux-ndk/tree/master/build-app/gradle-plugin)
   ```bash
   # aapt2 is inside the jar file(aapt2-4.1.1-6503028-linux.jar)
   # because the aapt2 is x86_64 architecture not aarch64, so we need to replace it
   # execute the find command to search aapt-xxx-linux.jar, then replace it
   cd ~/.gradle
   find . -type f -name aapt2-*-linux.jar
   cp /path/to/aapt2-4.1.1-6503028-linux.jar ./caches/modules-2/files-2.1/com.android.tools.build/aapt2/4.1.1-6503028/eb7d8e65025222eff8e09cb86740914a28f1417/aapt2-4.1.1-6503028-linux.jar
   ```
   <a href="./screenshot/copy_aapt2.jpg"><img src="./screenshot/copy_aapt2.jpg" width="100%" /></a>
   
* If an error occurs during the build app, this may be a network problem, please execute the `gradle build` again or execute the `gradle build --info` for more information.

**** 
### Building termux-app with termux
```bash
git clone https://github.com/termux/termux-app

# add local.properties file to termux-app
sdk.dir=/path/to/android-sdk 
ndk.dir=/path/to/android-ndk 
cmake.dir=/path/to/cmake

# modify gradle.properties file 
# add buildToolsVersion
minSdkVersion=24
targetSdkVersion=28
ndkVersion=22.0.7026061
compileSdkVersion=28
buildToolsVersion=30.0.3

# modify app/build.gradle terminal-emulator/build.gradle and terminal-view/build.gradle
# add buildToolsVersion
android {
    ......
    compileSdkVersion project.properties.compileSdkVersion.toInteger()
    buildToolsVersion project.properties.buildToolsVersion
    ......
}

# ok start building termux-app
gradle build

```
<div align="left">
    <img src="./screenshot/build_termux_app_01.jpg" width="50%" /><img src="./screenshot/build_termux_app_02.jpg" width="50%" />
</div>

**** 
### Building example
```bash
# File Manager
cd example/FileManager

# cmake-example
cd example/cmake-example

# hello-jni-kotlinApp
cd example/hello-jni-kotlinApp

gradle build
```
<div align="left">
    <img src="./screenshot/build_example_01.jpg" width="50%" /><img src="./screenshot/build_example_02.jpg" width="50%" />
</div>

**** 

### Issues
Using proot or chroot linux is not recommended, this may have some problems, the building speed is much slower than the native Termux.
