cmake_minimum_required(VERSION 3.14.2)

project(deployagent)

find_package(Java REQUIRED)

include(UseJava)

set(DEPLOYAGENT ${AOSP}/packages/modules/adb/fastdeploy/deployagent)

set(DEPLOYAGENT_SRC_FILES
    ${DEPLOYAGENT}/src/com/android/fastdeploy/ApkArchive.java
    ${DEPLOYAGENT}/src/com/android/fastdeploy/DeployAgent.java
    ${DEPLOYAGENT}/src/com/android/fastdeploy/PatchFormatException.java
    ${DEPLOYAGENT}/src/com/android/fastdeploy/PatchUtils.java
    ${AOSP}/external/protobuf/java/core/src/main/java/com/google/protobuf/ByteOutput.java
    )

set(CMAKE_JAVA_COMPILER_FLAGS " \
    -encoding UTF-8 \
    -source 1.8 \
    -taeget 1.8 \
    -classpath 
    ")

add_jar(deployagent ${DEPLOYAGENT_SRC_FILES})

get_target_property(jarFile deployagent JAR_FILE)
get_target_property(classDir deployagent CLASSDIR)

message(STATUS "Jar file ${jarFile}")
message(STATUS "Class compiled to ${classDir}")

add_test(NAME TestDeployagent COMMAND ${Java_JAVA_EXECUTABLE} -cp ${jarFile} deployagent)

