# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/noisyedge/Projects/mdl-source/MDL-SDK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja

# Utility rule file for AttributeCompatFuncTableGen.

# Include the progress variables for this target.
include src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/progress.make

src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen: src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc


src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc: src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Updating AttributesCompatFunc.inc..."
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR && /usr/local/Cellar/cmake/3.15.0/bin/cmake -E copy_if_different /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc

src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: src/mdl/jit/llvm/dist/bin/llvm-tblgen
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: src/mdl/jit/llvm/dist/bin/llvm-tblgen
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/CodeGen/SDNodeProperties.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/CodeGen/ValueTypes.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/Attributes.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/Intrinsics.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsAArch64.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsAMDGPU.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsARM.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsBPF.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsHexagon.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsMips.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsNVVM.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsPowerPC.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsSystemZ.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsWebAssembly.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsX86.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/IR/IntrinsicsXCore.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Option/OptParser.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/TableGen/SearchableTable.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/GenericOpcodes.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/GlobalISel/RegisterBank.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/GlobalISel/SelectionDAGCompat.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/GlobalISel/Target.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/Target.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/TargetCallingConv.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/TargetInstrPredicate.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/TargetItinerary.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/TargetSchedule.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/include/llvm/Target/TargetSelectionDAG.td
src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp: ../src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.td
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building AttributesCompatFunc.inc..."
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR && ../../bin/llvm-tblgen -gen-attrs -I /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/IR -I /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/include /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.td -o /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp

AttributeCompatFuncTableGen: src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen
AttributeCompatFuncTableGen: src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc
AttributeCompatFuncTableGen: src/mdl/jit/llvm/dist/lib/IR/AttributesCompatFunc.inc.tmp
AttributeCompatFuncTableGen: src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/build.make

.PHONY : AttributeCompatFuncTableGen

# Rule to build all files generated by this target.
src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/build: AttributeCompatFuncTableGen

.PHONY : src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/build

src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR && $(CMAKE_COMMAND) -P CMakeFiles/AttributeCompatFuncTableGen.dir/cmake_clean.cmake
.PHONY : src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/clean

src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/IR /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mdl/jit/llvm/dist/lib/IR/CMakeFiles/AttributeCompatFuncTableGen.dir/depend

