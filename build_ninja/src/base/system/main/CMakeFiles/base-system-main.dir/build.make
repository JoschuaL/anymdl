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
include src/base/system/main/CMakeFiles/base-system-main.dir/depend.make

# Include the progress variables for this target.
include src/base/system/main/CMakeFiles/base-system-main.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/system/main/CMakeFiles/base-system-main.dir/flags.make

src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.o: src/base/system/main/CMakeFiles/base-system-main.dir/flags.make
src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.o: ../src/base/system/main/module.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-system-main.dir/module.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module.cpp

src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-system-main.dir/module.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module.cpp > CMakeFiles/base-system-main.dir/module.cpp.i

src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-system-main.dir/module.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module.cpp -o CMakeFiles/base-system-main.dir/module.cpp.s

src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o: src/base/system/main/CMakeFiles/base-system-main.dir/flags.make
src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o: ../src/base/system/main/module_registration_entry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module_registration_entry.cpp

src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-system-main.dir/module_registration_entry.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module_registration_entry.cpp > CMakeFiles/base-system-main.dir/module_registration_entry.cpp.i

src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-system-main.dir/module_registration_entry.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main/module_registration_entry.cpp -o CMakeFiles/base-system-main.dir/module_registration_entry.cpp.s

# Object files for target base-system-main
base__system__main_OBJECTS = \
"CMakeFiles/base-system-main.dir/module.cpp.o" \
"CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o"

# External object files for target base-system-main
base__system__main_EXTERNAL_OBJECTS =

src/base/system/main/libbase-system-main.a: src/base/system/main/CMakeFiles/base-system-main.dir/module.cpp.o
src/base/system/main/libbase-system-main.a: src/base/system/main/CMakeFiles/base-system-main.dir/module_registration_entry.cpp.o
src/base/system/main/libbase-system-main.a: src/base/system/main/CMakeFiles/base-system-main.dir/build.make
src/base/system/main/libbase-system-main.a: src/base/system/main/CMakeFiles/base-system-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libbase-system-main.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && $(CMAKE_COMMAND) -P CMakeFiles/base-system-main.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base-system-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/system/main/CMakeFiles/base-system-main.dir/build: src/base/system/main/libbase-system-main.a

.PHONY : src/base/system/main/CMakeFiles/base-system-main.dir/build

src/base/system/main/CMakeFiles/base-system-main.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main && $(CMAKE_COMMAND) -P CMakeFiles/base-system-main.dir/cmake_clean.cmake
.PHONY : src/base/system/main/CMakeFiles/base-system-main.dir/clean

src/base/system/main/CMakeFiles/base-system-main.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/system/main /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/system/main/CMakeFiles/base-system-main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/system/main/CMakeFiles/base-system-main.dir/depend
