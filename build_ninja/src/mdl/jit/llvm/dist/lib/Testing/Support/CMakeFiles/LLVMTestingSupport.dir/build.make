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
include src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/depend.make

# Include the progress variables for this target.
include src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/progress.make

# Include the compile flags for this target's objects.
include src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/flags.make

src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o: src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/flags.make
src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o: ../src/mdl/jit/llvm/dist/lib/Testing/Support/Error.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Testing/Support/Error.cpp

src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMTestingSupport.dir/Error.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Testing/Support/Error.cpp > CMakeFiles/LLVMTestingSupport.dir/Error.cpp.i

src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMTestingSupport.dir/Error.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Testing/Support/Error.cpp -o CMakeFiles/LLVMTestingSupport.dir/Error.cpp.s

# Object files for target LLVMTestingSupport
LLVMTestingSupport_OBJECTS = \
"CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o"

# External object files for target LLVMTestingSupport
LLVMTestingSupport_EXTERNAL_OBJECTS =

src/mdl/jit/llvm/dist/lib/libLLVMTestingSupport.a: src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/Error.cpp.o
src/mdl/jit/llvm/dist/lib/libLLVMTestingSupport.a: src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/build.make
src/mdl/jit/llvm/dist/lib/libLLVMTestingSupport.a: src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../libLLVMTestingSupport.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && $(CMAKE_COMMAND) -P CMakeFiles/LLVMTestingSupport.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMTestingSupport.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/build: src/mdl/jit/llvm/dist/lib/libLLVMTestingSupport.a

.PHONY : src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/build

src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support && $(CMAKE_COMMAND) -P CMakeFiles/LLVMTestingSupport.dir/cmake_clean.cmake
.PHONY : src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/clean

src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/Testing/Support /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mdl/jit/llvm/dist/lib/Testing/Support/CMakeFiles/LLVMTestingSupport.dir/depend

