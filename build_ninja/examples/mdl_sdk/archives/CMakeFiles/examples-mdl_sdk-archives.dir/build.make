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
include examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/depend.make

# Include the progress variables for this target.
include examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/progress.make

# Include the compile flags for this target's objects.
include examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/flags.make

examples/mdl_sdk/archives/content.d: ../examples/mdl_sdk/archives/main.mdl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating content.d"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/Cellar/cmake/3.15.0/bin/cmake -E copy_if_different /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/archives/main.mdl /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives/main.mdl
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/Cellar/cmake/3.15.0/bin/cmake -E echo update\ content\ file:\ main.mdl
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/Cellar/cmake/3.15.0/bin/cmake -E echo touching:\  /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives/content.d
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/Cellar/cmake/3.15.0/bin/cmake -E touch /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives/content.d

examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o: examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/flags.make
examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o: ../examples/mdl_sdk/archives/example_archives.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/archives/example_archives.cpp

examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/archives/example_archives.cpp > CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.i

examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/archives/example_archives.cpp -o CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.s

# Object files for target examples-mdl_sdk-archives
examples__mdl_sdk__archives_OBJECTS = \
"CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o"

# External object files for target examples-mdl_sdk-archives
examples__mdl_sdk__archives_EXTERNAL_OBJECTS =

examples/mdl_sdk/archives/archives: examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/example_archives.cpp.o
examples/mdl_sdk/archives/archives: examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/build.make
examples/mdl_sdk/archives/archives: examples/mdl_sdk/shared/libshared.a
examples/mdl_sdk/archives/archives: examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable archives"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/examples-mdl_sdk-archives.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/build: examples/mdl_sdk/archives/archives

.PHONY : examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/build

examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives && $(CMAKE_COMMAND) -P CMakeFiles/examples-mdl_sdk-archives.dir/cmake_clean.cmake
.PHONY : examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/clean

examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/depend: examples/mdl_sdk/archives/content.d
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/examples/mdl_sdk/archives /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/mdl_sdk/archives/CMakeFiles/examples-mdl_sdk-archives.dir/depend

