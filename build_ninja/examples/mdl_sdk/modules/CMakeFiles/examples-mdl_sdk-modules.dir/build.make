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
include examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/depend.make

# Include the progress variables for this target.
include examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/progress.make

# Include the compile flags for this target's objects.
include examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/flags.make

examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o: examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/flags.make
examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o: ../examples/mdl_sdk/modules/example_modules.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/modules/example_modules.cpp

examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/modules/example_modules.cpp > CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.i

examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/modules/example_modules.cpp -o CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.s

# Object files for target examples-mdl_sdk-modules
examples__mdl_sdk__modules_OBJECTS = \
"CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o"

# External object files for target examples-mdl_sdk-modules
examples__mdl_sdk__modules_EXTERNAL_OBJECTS =

examples/mdl_sdk/modules/modules: examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/example_modules.cpp.o
examples/mdl_sdk/modules/modules: examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/build.make
examples/mdl_sdk/modules/modules: examples/mdl_sdk/shared/libshared.a
examples/mdl_sdk/modules/modules: examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable modules"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/examples-mdl_sdk-modules.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/build: examples/mdl_sdk/modules/modules

.PHONY : examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/build

examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules && $(CMAKE_COMMAND) -P CMakeFiles/examples-mdl_sdk-modules.dir/cmake_clean.cmake
.PHONY : examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/clean

examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/modules /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/mdl_sdk/modules/CMakeFiles/examples-mdl_sdk-modules.dir/depend
