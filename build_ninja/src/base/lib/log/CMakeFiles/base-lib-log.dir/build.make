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
include src/base/lib/log/CMakeFiles/base-lib-log.dir/depend.make

# Include the progress variables for this target.
include src/base/lib/log/CMakeFiles/base-lib-log.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/lib/log/CMakeFiles/base-lib-log.dir/flags.make

src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.o: src/base/lib/log/CMakeFiles/base-lib-log.dir/flags.make
src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.o: src/base/lib/log/generated/empty.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-lib-log.dir/generated/empty.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log/generated/empty.cpp

src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-lib-log.dir/generated/empty.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log/generated/empty.cpp > CMakeFiles/base-lib-log.dir/generated/empty.cpp.i

src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-lib-log.dir/generated/empty.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log/generated/empty.cpp -o CMakeFiles/base-lib-log.dir/generated/empty.cpp.s

# Object files for target base-lib-log
base__lib__log_OBJECTS = \
"CMakeFiles/base-lib-log.dir/generated/empty.cpp.o"

# External object files for target base-lib-log
base__lib__log_EXTERNAL_OBJECTS =

src/base/lib/log/libbase-lib-log.a: src/base/lib/log/CMakeFiles/base-lib-log.dir/generated/empty.cpp.o
src/base/lib/log/libbase-lib-log.a: src/base/lib/log/CMakeFiles/base-lib-log.dir/build.make
src/base/lib/log/libbase-lib-log.a: src/base/lib/log/CMakeFiles/base-lib-log.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbase-lib-log.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && $(CMAKE_COMMAND) -P CMakeFiles/base-lib-log.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base-lib-log.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/lib/log/CMakeFiles/base-lib-log.dir/build: src/base/lib/log/libbase-lib-log.a

.PHONY : src/base/lib/log/CMakeFiles/base-lib-log.dir/build

src/base/lib/log/CMakeFiles/base-lib-log.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log && $(CMAKE_COMMAND) -P CMakeFiles/base-lib-log.dir/cmake_clean.cmake
.PHONY : src/base/lib/log/CMakeFiles/base-lib-log.dir/clean

src/base/lib/log/CMakeFiles/base-lib-log.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/lib/log /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/lib/log/CMakeFiles/base-lib-log.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/lib/log/CMakeFiles/base-lib-log.dir/depend
