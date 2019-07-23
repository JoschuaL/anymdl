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

# Include any dependencies generated for this target.
include src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/depend.make

# Include the progress variables for this target.
include src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/progress.make

# Include the compile flags for this target's objects.
include src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/flags.make

src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.o: src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/flags.make
src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.o: ../src/mdl/jit/llvm/dist/utils/FileCheck/FileCheck.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FileCheck.dir/FileCheck.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/FileCheck/FileCheck.cpp

src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FileCheck.dir/FileCheck.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/FileCheck/FileCheck.cpp > CMakeFiles/FileCheck.dir/FileCheck.cpp.i

src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FileCheck.dir/FileCheck.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/FileCheck/FileCheck.cpp -o CMakeFiles/FileCheck.dir/FileCheck.cpp.s

# Object files for target FileCheck
FileCheck_OBJECTS = \
"CMakeFiles/FileCheck.dir/FileCheck.cpp.o"

# External object files for target FileCheck
FileCheck_EXTERNAL_OBJECTS =

src/mdl/jit/llvm/dist/bin/FileCheck: src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/FileCheck.cpp.o
src/mdl/jit/llvm/dist/bin/FileCheck: src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/build.make
src/mdl/jit/llvm/dist/bin/FileCheck: src/mdl/jit/llvm/dist/lib/libLLVMSupport.a
src/mdl/jit/llvm/dist/bin/FileCheck: src/mdl/jit/llvm/dist/lib/libLLVMDemangle.a
src/mdl/jit/llvm/dist/bin/FileCheck: src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/FileCheck"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileCheck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/build: src/mdl/jit/llvm/dist/bin/FileCheck

.PHONY : src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/build

src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck && $(CMAKE_COMMAND) -P CMakeFiles/FileCheck.dir/cmake_clean.cmake
.PHONY : src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/clean

src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/utils/FileCheck /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mdl/jit/llvm/dist/utils/FileCheck/CMakeFiles/FileCheck.dir/depend

