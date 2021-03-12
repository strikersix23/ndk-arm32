/*
 * Copyright 2014, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>

#include <getopt.h>
#include <string.h>

#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/Driver/Options.h"
#include "clang/Frontend/Utils.h"

#include "llvm/Option/Arg.h"
#include "llvm/Option/ArgList.h"
#include "llvm/Option/Option.h"
#include "llvm/Option/OptTable.h"
#include "llvm/Support/CommandLine.h"

#include "rs_cc_options.h"
#include "slang.h"
#include "slang_assert.h"


namespace slang {

static struct option long_options[] = {
	{"target-api", required_argument, NULL, 't'},
	{"include-path", required_argument, NULL, 'I'},
    {"emit-asm", no_argument, NULL, 'S'},
    {"emit-llvm", no_argument, NULL, 0},
    {"emit-bc", no_argument, NULL, 0},
    {"emit-nothing", no_argument, NULL, 0},
    {"m32", no_argument, NULL, 0},
    {"m64", no_argument, NULL, 0},
    {"allow-rs-prefix", no_argument, NULL, 0},
    {"java-reflection-path-base", required_argument, NULL, 'p'},
    {"java-reflection-package-name", no_argument, NULL, 'j'},
    {"bitcode-storage", required_argument, NULL, 's'},
    {"rs-package-name", required_argument, NULL, 0},
    {"MD", no_argument, NULL, 0},
    {"MP", no_argument, NULL, 0},
    {"emit-dep", required_argument, NULL, 'M'},
    {"output-dep-dir", required_argument, NULL, 'd'},
    {"additional-dep-target", no_argument, NULL, 'a'},
    {"reflect-c++", no_argument, NULL, 0},
    {"ast-print", no_argument, NULL, 0},
    {"print-after-all", no_argument, NULL, 0},
    {"print-before-all", no_argument, NULL, 0},
    {"debug", no_argument, NULL, 'g'},
    {"verbose", no_argument, NULL, 'v'},
    {"version",  no_argument, NULL, '0'},
    {"help", no_argument, NULL, 'h'},
};


void PrintHelper() {
    std::stringstream ss;
    ss << "Renderscript source compiler\n\n"
    << "llvm-rs-cc [option] input_file\n\n"
    << "  -t  <num>   --target-api\t\tSpecify target API level (e.g. 16)\n"
    << "  -o  <directory>\t\t\tSpecify output directory\n"
    << "  -O  <optimization-level> \t\t<optimization-level> can be one of '0' or '3' (default)\n"
    << "  -I  <directory>   --include-path\t\tAdd directory to include search path\n"
    << "  -S  --emit-asm\t\t\tEmit target assembly files\n"
    << "  -p  <directory>   --java-reflection-path-base\t Base directory for output reflected Java files\n"
    << "  -j  --java-reflection-package-name\tSpecify the package name that reflected Java files belong to\n"
    << "  -s  <value>   --bitcode-storage\t<value> should be 'ar' or 'jc'\n"
    << "  -M   --emit-dep\temit dependency\n"
    << "  -d   <directory>   --output-dep-dir\tSpecify output directory for dependencies output\n"
    << "  -a   --additional-dep-target\t\tAdditional targets to show up in dependencies output\n"
    << "  -w  \t\t\tSuppress all warnings\n"
    << "  -W  \t\t\tEnable the specified warning\n"
    << "  -g   --debug\t\tEnable debug output\n"
    << "  -v   --verbose\tDisplay verbose information during the compilation\n"
    << "  -h   --help\t\tPrint this help text\n"
    << "  --m32\t\t\tEmit 32-bit code (only for C++, unless eng build)\n"
    << "  --m64\t\t\tEmit 64-bit code (only for C++, unless eng build)\n"
    << "  --MD\t\t\tEmit .d dependency files\n"
    << "  --MP\t\t\tAlso emit phony target for dependency files\n"
    << "  --reflect-c++\t\tReflect C++ classes\n"
    << "  --emit-llvm\t\tBuild ASTs then convert to LLVM, emit .ll file\n"
    << "  --emit-bc\t\tBuild ASTs then convert to LLVM, emit .bc file\n"
    << "  --emit-nothing\tBuild ASTs then convert to LLVM, but emit nothing\n"
    << "  --allow-rs-prefix\tAllow user-defined function prefixed with 'rs\n'"
    << "  --rs-package-name <package_name>\tpackage name for referencing RS classes\n"
    << "  --ast-print\t\tPrint clang AST prior to llvm IR generation\n"
    << "  --print-before-all\tPrint llvm IR before each pass\n"
    << "  --print-after-all\tPrint llvm IR after each pass\n"
    << "  --version\t\tPrint the assembler version\n"
    << "  --no-link\t\tCompatible with old slang"
    << std::endl;
    
    std::cout << ss.str();
    ss.clear();
}

std::vector<std::string> split(char *str, const char *delim) {
    std::vector<std::string> ret;
    if(strcmp(str, "") == 0 || str == nullptr) return ret;
    
    char *ptr = strtok(str, delim);
    while(ptr) {
        ret.push_back(ptr);
        ptr = strtok(nullptr, delim);
    }
    return ret;
}


void ParseLongParams(RSCCOptions &Opts, clang::DiagnosticsEngine &DiagEngine
    , int index, int &delegate_options) {
    if(strcmp(long_options[index].name, "emit-llvm") == 0) {
        Opts.mOutputType = Slang::OT_LLVMAssembly;
    } 
    else if(strcmp(long_options[index].name, "emit-bc") == 0){
        Opts.mOutputType = Slang::OT_Bitcode;
    } 
    else if(strcmp(long_options[index].name, "emit-nothing") == 0){
        Opts.mOutputType = Slang::OT_Nothing;
    } 
    else if(strcmp(long_options[index].name, "m32") == 0){
        // Check for bitwidth arguments.
        Opts.mBitWidth = 32;
        // -m32/-m64 are forbidden for non-C++ reflection paths for non-eng builds
        // (they would make it too easy for a developer to accidentally create and
        // release an APK that has 32-bit or 64-bit bitcode but not both).
#ifdef __ENABLE_INTERNAL_OPTIONS
        Opts.mEmit3264 = false;
#else
        DiagEngine.Report(DiagEngine.getCustomDiagID(clang::DiagnosticsEngine::Error,
                                     "cannot use -m32/-m64 without specifying "
                                     "C++ reflection (-reflect-c++)"));
#endif

    } 
    else if(strcmp(long_options[index].name, "m64") == 0){
        // Check for bitwidth arguments.
        Opts.mBitWidth = 64;
#ifdef __ENABLE_INTERNAL_OPTIONS
        Opts.mEmit3264 = false;
#else
        DiagEngine.Report(DiagEngine.getCustomDiagID(clang::DiagnosticsEngine::Error,
                                     "cannot use -m32/-m64 without specifying "
                                     "C++ reflection (-reflect-c++)"));
#endif
    } 
    else if(strcmp(long_options[index].name, "allow-rs-prefix") == 0){
        Opts.mAllowRSPrefix = true;
    } 
    else if(strcmp(long_options[index].name, "rs-package-name") == 0){
        
    } 
    else if(strcmp(long_options[index].name, "MD") == 0){
        Opts.mEmitDependency = true;
        Opts.mOutputType = Slang::OT_Bitcode;
    } 
    else if(strcmp(long_options[index].name, "MP") == 0){
        Opts.mEmitDependency = true;
        Opts.mOutputType = Slang::OT_Bitcode;
        Opts.mEmitPhonyDependency = true;
    } 
    else if(strcmp(long_options[index].name, "reflect-c++") == 0){
        Opts.mBitcodeStorage = BCST_CPP_CODE;
        // mJavaReflectionPathBase can be set for C++ reflected builds.
        // Set it to the standard mBitcodeOutputDir (via -o) by default.
        if (Opts.mJavaReflectionPathBase.empty()) {
            Opts.mJavaReflectionPathBase = Opts.mBitcodeOutputDir;
        }
    } 
    else if(strcmp(long_options[index].name, "ast-print") == 0){
        Opts.mASTPrint = true;
    } 
    else if(strcmp(long_options[index].name, "print-after-all") == 0){
        delegate_options = index;
    } 
    else if(strcmp(long_options[index].name, "print-before-all") == 0){
        delegate_options = index;
    } 
    else if(strcmp(long_options[index].name, "version") == 0){
        Opts.mShowVersion = true;
    } 
    else if(strcmp(long_options[index].name, "no-link") == 0){
        // nothing to do
    } 
    else {
        DiagEngine.Report(clang::diag::err_drv_argument_not_allowed_with);
    } 
}


bool ParseArguments(int argc, char **argv, 
                    llvm::SmallVectorImpl<const char *> &Inputs,
                    RSCCOptions &Opts, clang::DiagnosticOptions &DiagOpts,
                    llvm::StringSaver &StringSaver) {
    
    // We use a different diagnostic engine for argument parsing from the rest of
    // the work.  This mimics what's done in clang.  I believe it is so the
    // argument parsing errors are well formatted while the full errors can be
    // influenced by command line arguments.
    llvm::IntrusiveRefCntPtr<clang::DiagnosticOptions> ArgumentParseDiagOpts(
        new clang::DiagnosticOptions());
    llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs> DiagIDs(
        new clang::DiagnosticIDs());
    DiagnosticBuffer DiagsBuffer;
    clang::DiagnosticsEngine DiagEngine(DiagIDs, &*ArgumentParseDiagOpts,
                                      &DiagsBuffer, false);
    
    llvm::StringRef BitcodeStorageValue;
    
    std::vector<std::string> warn_vector ;
    std::vector<std::string> inc_paths_vector ;
    std::vector<std::string> addi_target_vector ;
    
    int delegate_options = 0;
    int option_index = 0;
    int opt = 0;
	const char *optstring = "t:o:O:I:s:p:M:d:javwghSW";

	while((opt = getopt_long_only(argc, argv, optstring, long_options, &option_index)) != -1) {
        switch(opt) {
        case 't':
            Opts.mTargetAPI = atoi(optarg);
            break;
        case 'o': // output file 
            Opts.mBitcodeOutputDir = optarg;
            break;
        case 'O':
            {
                size_t OptLevel = atoi(optarg);
                Opts.mOptimizationLevel = OptLevel == 0 ? llvm::CodeGenOpt::None : llvm::CodeGenOpt::Aggressive;
            }
            break;
        case 'w':
            DiagOpts.IgnoreWarnings = false;
            break;
        case 'W':
            warn_vector.push_back(optarg);
            break;
        case 'I':
            inc_paths_vector.push_back(optarg);
            break;
        case 'P':
            Opts.mJavaReflectionPathBase = optarg;
            break;
        case 's':
            BitcodeStorageValue = optarg;
            break;
        case 'S':
            Opts.mOutputType = Slang::OT_Assembly;
            break;
        case 'j':
            Opts.mJavaReflectionPackageName = optarg;
            break;
        case 'M':
            Opts.mEmitDependency = true;
            Opts.mOutputType = Slang::OT_Dependency;
            break;
        case 'd':
            Opts.mDependencyOutputDir = Opts.mBitcodeOutputDir;
            break;
        case 'a':
            addi_target_vector.push_back(optarg);
            break;
        case 'g':
            Opts.mDebugEmission = true;
            delegate_options = option_index;
            break;
        case 'v':
            Opts.mVerbose = true;
            break;
        case 'h':
            Opts.mShowHelp = true;
            break;
        default:
            ParseLongParams(Opts, DiagEngine, option_index, delegate_options);
            break;
        }
	}

    DiagOpts.Warnings = warn_vector;
    Opts.mIncludePaths = inc_paths_vector;
    Opts.mAdditionalDepTargets =addi_target_vector;

    // Always turn off warnings for empty initializers, since we really want to
    // employ/encourage this extension for zero-initialization of structures.
    DiagOpts.Warnings.push_back("no-gnu-empty-initializer");
  
  
    if (Opts.mEmitDependency && ((Opts.mOutputType != Slang::OT_Bitcode) &&
                               (Opts.mOutputType != Slang::OT_Dependency)))
    DiagEngine.Report(clang::diag::err_drv_argument_not_allowed_with)
        << "emit dependency" << "emit output type";
    
        
    if (BitcodeStorageValue == "ar")
        Opts.mBitcodeStorage = BCST_APK_RESOURCE;
    else if (BitcodeStorageValue == "jc")
        Opts.mBitcodeStorage = BCST_JAVA_CODE;
    else if (!BitcodeStorageValue.empty())
        DiagEngine.Report(clang::diag::err_drv_invalid_value)
        << "bitcode-storage" << BitcodeStorageValue;
    
        
    // Delegate options
    std::vector<std::string> DelegatedStrings;
    if(delegate_options != 0) {
        // TODO: Don't assume that the option begins with "-"; determine this programmatically instead.
        DelegatedStrings.push_back(std::string("-") + std::string(long_options[delegate_options].name));
        slangAssert(OptParser->getOptionKind(Opt) == llvm::opt::Option::FlagClass);
    }
    
    if (DelegatedStrings.size()) {
        std::vector<const char *> DelegatedCStrs;
        DelegatedCStrs.push_back(argv[0]); // program name
        std::for_each(DelegatedStrings.cbegin(), DelegatedStrings.cend(),
                  [&DelegatedCStrs](const std::string &String) { DelegatedCStrs.push_back(String.c_str()); });
        llvm::cl::ParseCommandLineOptions(DelegatedCStrs.size(), DelegatedCStrs.data());
    }
     
    // If we are emitting both 32-bit and 64-bit bitcode, we must embed it.
    if (Opts.mTargetAPI == 0) {
        Opts.mTargetAPI = UINT_MAX;
    } else if (Opts.mTargetAPI == SLANG_N_MR1_TARGET_API ||
             Opts.mTargetAPI == SLANG_O_TARGET_API ||
             Opts.mTargetAPI == SLANG_O_MR1_TARGET_API ||
             Opts.mTargetAPI == SLANG_P_TARGET_API) {
        // Bug: http://b/35767071
        // No new APIs for N_MR1, O, O_MR1 and P, convert to N.
        Opts.mTargetAPI = SLANG_N_TARGET_API;
    }

    if ((Opts.mTargetAPI < 21) || (Opts.mBitcodeStorage == BCST_CPP_CODE))
        Opts.mEmit3264 = false;
    if (Opts.mEmit3264)
        Opts.mBitcodeStorage = BCST_JAVA_CODE;

    if (DiagEngine.hasErrorOccurred()) {
        llvm::errs() << DiagsBuffer.str();
        return false;
    }
	return true;
}

} // namespace slang


