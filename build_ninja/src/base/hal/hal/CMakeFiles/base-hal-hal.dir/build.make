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
include src/base/hal/hal/CMakeFiles/base-hal-hal.dir/depend.make

# Include the progress variables for this target.
include src/base/hal/hal/CMakeFiles/base-hal-hal.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/hal/hal/CMakeFiles/base-hal-hal.dir/flags.make

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.o: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/flags.make
src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.o: ../src/base/hal/hal/hal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-hal.dir/hal.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal.cpp

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-hal.dir/hal.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal.cpp > CMakeFiles/base-hal-hal.dir/hal.cpp.i

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-hal.dir/hal.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal.cpp -o CMakeFiles/base-hal-hal.dir/hal.cpp.s

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.o: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/flags.make
src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.o: ../src/base/hal/hal/hal_color.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-hal.dir/hal_color.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_color.cpp

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-hal.dir/hal_color.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_color.cpp > CMakeFiles/base-hal-hal.dir/hal_color.cpp.i

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-hal.dir/hal_color.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_color.cpp -o CMakeFiles/base-hal-hal.dir/hal_color.cpp.s

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/flags.make
src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o: ../src/base/hal/hal/hal_ospath.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_ospath.cpp

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_ospath.cpp > CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.i

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal/hal_ospath.cpp -o CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.s

# Object files for target base-hal-hal
base__hal__hal_OBJECTS = \
"CMakeFiles/base-hal-hal.dir/hal.cpp.o" \
"CMakeFiles/base-hal-hal.dir/hal_color.cpp.o" \
"CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o"

# External object files for target base-hal-hal
base__hal__hal_EXTERNAL_OBJECTS =

src/base/hal/hal/libbase-hal-hal.a: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal.cpp.o
src/base/hal/hal/libbase-hal-hal.a: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_color.cpp.o
src/base/hal/hal/libbase-hal-hal.a: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/hal_ospath.cpp.o
src/base/hal/hal/libbase-hal-hal.a: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/build.make
src/base/hal/hal/libbase-hal-hal.a: src/base/hal/hal/CMakeFiles/base-hal-hal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libbase-hal-hal.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && $(CMAKE_COMMAND) -P CMakeFiles/base-hal-hal.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base-hal-hal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/hal/hal/CMakeFiles/base-hal-hal.dir/build: src/base/hal/hal/libbase-hal-hal.a

.PHONY : src/base/hal/hal/CMakeFiles/base-hal-hal.dir/build

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal && $(CMAKE_COMMAND) -P CMakeFiles/base-hal-hal.dir/cmake_clean.cmake
.PHONY : src/base/hal/hal/CMakeFiles/base-hal-hal.dir/clean

src/base/hal/hal/CMakeFiles/base-hal-hal.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/hal /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/hal/CMakeFiles/base-hal-hal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/hal/hal/CMakeFiles/base-hal-hal.dir/depend

