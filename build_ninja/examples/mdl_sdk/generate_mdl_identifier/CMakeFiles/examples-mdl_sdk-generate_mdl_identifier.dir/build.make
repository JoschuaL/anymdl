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
include examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/depend.make

# Include the progress variables for this target.
include examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/progress.make

# Include the compile flags for this target's objects.
include examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/flags.make

examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o: examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/flags.make
examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o: ../examples/mdl_sdk/generate_mdl_identifier/example_generate_mdl_identifier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/generate_mdl_identifier/example_generate_mdl_identifier.cpp

examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/generate_mdl_identifier/example_generate_mdl_identifier.cpp > CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.i

examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/generate_mdl_identifier/example_generate_mdl_identifier.cpp -o CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.s

# Object files for target examples-mdl_sdk-generate_mdl_identifier
examples__mdl_sdk__generate_mdl_identifier_OBJECTS = \
"CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o"

# External object files for target examples-mdl_sdk-generate_mdl_identifier
examples__mdl_sdk__generate_mdl_identifier_EXTERNAL_OBJECTS =

examples/mdl_sdk/generate_mdl_identifier/generate_mdl_identifier: examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/example_generate_mdl_identifier.cpp.o
examples/mdl_sdk/generate_mdl_identifier/generate_mdl_identifier: examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/build.make
examples/mdl_sdk/generate_mdl_identifier/generate_mdl_identifier: examples/mdl_sdk/shared/libshared.a
examples/mdl_sdk/generate_mdl_identifier/generate_mdl_identifier: examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable generate_mdl_identifier"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/build: examples/mdl_sdk/generate_mdl_identifier/generate_mdl_identifier

.PHONY : examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/build

examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier && $(CMAKE_COMMAND) -P CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/cmake_clean.cmake
.PHONY : examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/clean

examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/generate_mdl_identifier /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/mdl_sdk/generate_mdl_identifier/CMakeFiles/examples-mdl_sdk-generate_mdl_identifier.dir/depend
