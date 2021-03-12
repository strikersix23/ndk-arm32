cmake_minimum_required(VERSION 3.14.2)

project(libbcc)

set(LIBBCC_SRC_FILES 
    BCCContext.cpp
    BCCContextImpl.cpp
    Compiler.cpp
    CompilerConfig.cpp
    FileBase.cpp
    Initialization.cpp
    RSAddDebugInfoPass.cpp
    RSCompilerDriver.cpp
    RSEmbedInfo.cpp
    RSGlobalInfoPass.cpp
    RSInvariant.cpp
    RSInvokeHelperPass.cpp
    RSIsThreadablePass.cpp
    RSKernelExpand.cpp
    RSScreenFunctionsPass.cpp
    RSScriptGroupFusion.cpp
    RSFunctionsList.cpp
    RSX86CallConvPass.cpp
    RSX86TranslateGEPPass.cpp
    Script.cpp
    Source.cpp
	)

add_library(bcc STATIC ${LIBBCC_SRC_FILES})
target_link_libraries(bcc)





