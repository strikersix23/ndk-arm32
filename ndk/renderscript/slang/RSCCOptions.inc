------------- Classes -----------------
class Alias<Option Alias:alias = ?> {
  Option Alias = Alias:alias;
}
class AliasArgs<list<string> AliasArgs:aliasargs = ?> {
  list<string> AliasArgs = AliasArgs:aliasargs;
}
class CommaJoined<list<string> CommaJoined:prefixes = ?, string CommaJoined:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = CommaJoined:prefixes;
  string Name = CommaJoined:name;
  OptionKind Kind = KIND_COMMAJOINED;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class EnumName<string EnumName:name = ?> {
  string EnumName = EnumName:name;
}
class Flag<list<string> Flag:prefixes = ?, string Flag:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = Flag:prefixes;
  string Name = Flag:name;
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class Flags<list<OptionFlag> Flags:flags = ?> {
  list<OptionFlag> Flags = Flags:flags;
}
class Group<OptionGroup Group:group = ?> {
  OptionGroup Group = Group:group;
}
class HelpText<string HelpText:text = ?> {
  string HelpText = HelpText:text;
}
class Joined<list<string> Joined:prefixes = ?, string Joined:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = Joined:prefixes;
  string Name = Joined:name;
  OptionKind Kind = KIND_JOINED;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class JoinedAndSeparate<list<string> JoinedAndSeparate:prefixes = ?, string JoinedAndSeparate:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = JoinedAndSeparate:prefixes;
  string Name = JoinedAndSeparate:name;
  OptionKind Kind = KIND_JOINED_AND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class JoinedOrSeparate<list<string> JoinedOrSeparate:prefixes = ?, string JoinedOrSeparate:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = JoinedOrSeparate:prefixes;
  string Name = JoinedOrSeparate:name;
  OptionKind Kind = KIND_JOINED_OR_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class MetaVarName<string MetaVarName:name = ?> {
  string MetaVarName = MetaVarName:name;
}
class MultiArg<list<string> MultiArg:prefixes = ?, string MultiArg:name = ?, int MultiArg:numargs = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = MultiArg:prefixes;
  string Name = MultiArg:name;
  OptionKind Kind = KIND_MULTIARG;
  int NumArgs = MultiArg:numargs;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class Option<list<string> Option:prefixes = ?, string Option:name = ?, OptionKind Option:kind = ?> {
  string EnumName = ?;
  list<string> Prefixes = Option:prefixes;
  string Name = Option:name;
  OptionKind Kind = Option:kind;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
class OptionFlag {
}
class OptionGroup<string OptionGroup:name = ?> {
  string EnumName = ?;
  string Name = OptionGroup:name;
  string HelpText = ?;
  OptionGroup Group = ?;
  list<OptionFlag> Flags = [];
}
class OptionKind<string OptionKind:name = ?, int OptionKind:precedence = 0, bit OptionKind:sentinel = 0> {
  string Name = OptionKind:name;
  int Precedence = OptionKind:precedence;
  bit Sentinel = OptionKind:sentinel;
}
class Separate<list<string> Separate:prefixes = ?, string Separate:name = ?> {	// Option
  string EnumName = ?;
  list<string> Prefixes = Separate:prefixes;
  string Name = Separate:name;
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
------------- Defs -----------------
def HelpHidden {	// OptionFlag
}
def I {	// Option JoinedOrSeparate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "I";
  OptionKind Kind = KIND_JOINED_OR_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Add directory to include search path";
  string MetaVarName = "<directory>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def INPUT {	// Option
  string EnumName = ?;
  list<string> Prefixes = [];
  string Name = "<input>";
  OptionKind Kind = KIND_INPUT;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def KIND_COMMAJOINED {	// OptionKind
  string Name = "CommaJoined";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_FLAG {	// OptionKind
  string Name = "Flag";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_GROUP {	// OptionKind
  string Name = "Group";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_INPUT {	// OptionKind
  string Name = "Input";
  int Precedence = 1;
  bit Sentinel = 1;
}
def KIND_JOINED {	// OptionKind
  string Name = "Joined";
  int Precedence = 1;
  bit Sentinel = 0;
}
def KIND_JOINED_AND_SEPARATE {	// OptionKind
  string Name = "JoinedAndSeparate";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_JOINED_OR_SEPARATE {	// OptionKind
  string Name = "JoinedOrSeparate";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_MULTIARG {	// OptionKind
  string Name = "MultiArg";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_REMAINING_ARGS {	// OptionKind
  string Name = "RemainingArgs";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_REMAINING_ARGS_JOINED {	// OptionKind
  string Name = "RemainingArgsJoined";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_SEPARATE {	// OptionKind
  string Name = "Separate";
  int Precedence = 0;
  bit Sentinel = 0;
}
def KIND_UNKNOWN {	// OptionKind
  string Name = "Unknown";
  int Precedence = 2;
  bit Sentinel = 1;
}
def M {	// Option Flag
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "M";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = M_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def MD {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "MD";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Emit .d dependency files";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = M_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def MP {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "MP";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Also emit phony target for dependency files";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = M_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def M_Group {	// OptionGroup
  string EnumName = ?;
  string Name = "M group>";
  string HelpText = ?;
  OptionGroup Group = ?;
  list<OptionFlag> Flags = [];
}
def Output_Type_Group {	// OptionGroup
  string EnumName = ?;
  string Name = "<output type group>";
  string HelpText = ?;
  OptionGroup Group = ?;
  list<OptionFlag> Flags = [];
}
def RenderAsInput {	// OptionFlag
}
def RenderJoined {	// OptionFlag
}
def RenderSeparate {	// OptionFlag
}
def UNKNOWN {	// Option
  string EnumName = ?;
  list<string> Prefixes = [];
  string Name = "<unknown>";
  OptionKind Kind = KIND_UNKNOWN;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def W {	// Option Joined HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "W";
  OptionKind Kind = KIND_JOINED;
  int NumArgs = 0;
  string HelpText = "Enable the specified warning";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def _I {	// Option Separate MetaVarName Alias
  string EnumName = ?;
  list<string> Prefixes = ["-", "--"];
  string Name = "include-path";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = "<directory>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = I;
  list<string> AliasArgs = [];
}
def __help {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "h";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = help;
  list<string> AliasArgs = [];
}
def __verbose {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["--"];
  string Name = "verbose";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = verbose;
  list<string> AliasArgs = [];
}
def _additional_dep_target {	// Option Separate Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "a";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = additional_dep_target;
  list<string> AliasArgs = [];
}
def _bitcode_storage {	// Option Separate Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "s";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = bitcode_storage;
  list<string> AliasArgs = [];
}
def _emit_asm {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "S";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = Output_Type_Group;
  Option Alias = emit_asm;
  list<string> AliasArgs = [];
}
def _help {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["--"];
  string Name = "help";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = help;
  list<string> AliasArgs = [];
}
def _java_reflection_package_name {	// Option Separate Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "j";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = java_reflection_package_name;
  list<string> AliasArgs = [];
}
def _java_reflection_path_base {	// Option Separate Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "p";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = java_reflection_path_base;
  list<string> AliasArgs = [];
}
def _output_dep_dir {	// Option Separate Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "d";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = output_dep_dir;
  list<string> AliasArgs = [];
}
def _verbose {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "verbose";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = verbose;
  list<string> AliasArgs = [];
}
def _version {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["--"];
  string Name = "version";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = version;
  list<string> AliasArgs = [];
}
def additional_dep_target {	// Option Separate HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "additional-dep-target";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Additional targets to show up in dependencies output";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def allow_rs_prefix {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "allow-rs-prefix";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Allow user-defined function prefixed with 'rs'";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def ast_print {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "ast-print";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Print clang AST prior to llvm IR generation";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def bitcode_storage {	// Option Separate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "bitcode-storage";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "<value> should be 'ar' or 'jc'";
  string MetaVarName = "<value>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def debug {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "debug";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Enable debug output";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def emit_asm {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "emit-asm";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Emit target assembly files";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = Output_Type_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def emit_bc {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "emit-bc";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Build ASTs then convert to LLVM, emit .bc file";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = Output_Type_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def emit_dep {	// Option Flag Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "emit-dep";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = M_Group;
  Option Alias = M;
  list<string> AliasArgs = [];
}
def emit_g {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "g";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Emit LLVM Debug Metadata";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def emit_llvm {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "emit-llvm";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Build ASTs then convert to LLVM, emit .ll file";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = Output_Type_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def emit_nothing {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "emit-nothing";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Build ASTs then convert to LLVM, but emit nothing";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = Output_Type_Group;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def help {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "help";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Print this help text";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def java_reflection_package_name {	// Option Separate HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "java-reflection-package-name";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Specify the package name that reflected Java files belong to";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def java_reflection_path_base {	// Option Separate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "java-reflection-path-base";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Base directory for output reflected Java files";
  string MetaVarName = "<directory>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def m32 {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "m32";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Emit 32-bit code (only for C++, unless eng build)";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def m64 {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "m64";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Emit 64-bit code (only for C++, unless eng build)";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def no_link {	// Option Flag
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "no-link";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def o {	// Option Separate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "o";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Specify output directory";
  string MetaVarName = "<directory>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def optimization_level {	// Option JoinedOrSeparate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "O";
  OptionKind Kind = KIND_JOINED_OR_SEPARATE;
  int NumArgs = 0;
  string HelpText = "<optimization-level> can be one of '0' or '3' (default)";
  string MetaVarName = "<optimization-level>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def output_dep_dir {	// Option Separate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "output-dep-dir";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Specify output directory for dependencies output";
  string MetaVarName = "<directory>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def print_after_all {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "print-after-all";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Print llvm IR after each pass";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def print_before_all {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "print-before-all";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Print llvm IR before each pass";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def reflect_cpp {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "reflect-c++";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Reflect C++ classes";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def rs_package_name {	// Option Separate MetaVarName HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "rs-package-name";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "package name for referencing RS classes";
  string MetaVarName = "<package_name>";
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def rs_package_name_EQ {	// Option Joined Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "rs-package-name=";
  OptionKind Kind = KIND_JOINED;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = rs_package_name;
  list<string> AliasArgs = [];
}
def target_api {	// Option Separate HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "target-api";
  OptionKind Kind = KIND_SEPARATE;
  int NumArgs = 0;
  string HelpText = "Specify target API level (e.g. 14)";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def target_api_EQ {	// Option Joined Alias
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "target-api=";
  OptionKind Kind = KIND_JOINED;
  int NumArgs = 0;
  string HelpText = ?;
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = target_api;
  list<string> AliasArgs = [];
}
def verbose {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "v";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Display verbose information during the compilation";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def version {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "version";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Print the assembler version";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
def w {	// Option Flag HelpText
  string EnumName = ?;
  list<string> Prefixes = ["-"];
  string Name = "w";
  OptionKind Kind = KIND_FLAG;
  int NumArgs = 0;
  string HelpText = "Suppress all warnings";
  string MetaVarName = ?;
  list<OptionFlag> Flags = [];
  OptionGroup Group = ?;
  Option Alias = ?;
  list<string> AliasArgs = [];
}
