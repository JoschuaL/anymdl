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
include src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/depend.make

# Include the progress variables for this target.
include src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/progress.make

# Include the compile flags for this target's objects.
include src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/flags.make

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/flags.make
src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o: ../src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Execution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Execution.cpp

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMInterpreter.dir/Execution.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Execution.cpp > CMakeFiles/LLVMInterpreter.dir/Execution.cpp.i

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMInterpreter.dir/Execution.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Execution.cpp -o CMakeFiles/LLVMInterpreter.dir/Execution.cpp.s

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/flags.make
src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o: ../src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/ExternalFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/ExternalFunctions.cpp

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/ExternalFunctions.cpp > CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.i

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/ExternalFunctions.cpp -o CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.s

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/flags.make
src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o: ../src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Interpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Interpreter.cpp

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Interpreter.cpp > CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.i

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/Interpreter.cpp -o CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.s

# Object files for target LLVMInterpreter
LLVMInterpreter_OBJECTS = \
"CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o" \
"CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o" \
"CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o"

# External object files for target LLVMInterpreter
LLVMInterpreter_EXTERNAL_OBJECTS =

src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Execution.cpp.o
src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/ExternalFunctions.cpp.o
src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/Interpreter.cpp.o
src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/build.make
src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a: src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../libLLVMInterpreter.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && $(CMAKE_COMMAND) -P CMakeFiles/LLVMInterpreter.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LLVMInterpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/build: src/mdl/jit/llvm/dist/lib/libLLVMInterpreter.a

.PHONY : src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/build

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter && $(CMAKE_COMMAND) -P CMakeFiles/LLVMInterpreter.dir/cmake_clean.cmake
.PHONY : src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/clean

src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/mdl/jit/llvm/dist/lib/ExecutionEngine/Interpreter/CMakeFiles/LLVMInterpreter.dir/depend
