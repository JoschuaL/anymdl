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
include src/base/data/attr/CMakeFiles/base-data-attr.dir/depend.make

# Include the progress variables for this target.
include src/base/data/attr/CMakeFiles/base-data-attr.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.o: ../src/base/data/attr/attr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr.cpp > CMakeFiles/base-data-attr.dir/attr.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr.cpp -o CMakeFiles/base-data-attr.dir/attr.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o: ../src/base/data/attr/attr_attribute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_attribute.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute.cpp > CMakeFiles/base-data-attr.dir/attr_attribute.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_attribute.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute.cpp -o CMakeFiles/base-data-attr.dir/attr_attribute.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o: ../src/base/data/attr/attr_attribute_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute_list.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute_list.cpp > CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attribute_list.cpp -o CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o: ../src/base/data/attr/attr_attrset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attrset.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_attrset.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attrset.cpp > CMakeFiles/base-data-attr.dir/attr_attrset.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_attrset.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_attrset.cpp -o CMakeFiles/base-data-attr.dir/attr_attrset.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.o: ../src/base/data/attr/attr_module.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_module.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_module.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_module.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_module.cpp > CMakeFiles/base-data-attr.dir/attr_module.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_module.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_module.cpp -o CMakeFiles/base-data-attr.dir/attr_module.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.o: ../src/base/data/attr/attr_registry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_registry.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_registry.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_registry.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_registry.cpp > CMakeFiles/base-data-attr.dir/attr_registry.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_registry.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_registry.cpp -o CMakeFiles/base-data-attr.dir/attr_registry.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.o: ../src/base/data/attr/attr_type.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_type.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_type.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type.cpp > CMakeFiles/base-data-attr.dir/attr_type.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_type.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type.cpp -o CMakeFiles/base-data-attr.dir/attr_type.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o: ../src/base/data/attr/attr_type_value_iterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type_value_iterator.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type_value_iterator.cpp > CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_type_value_iterator.cpp -o CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.s

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o: src/base/data/attr/CMakeFiles/base-data-attr.dir/flags.make
src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o: ../src/base/data/attr/attr_utilities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_utilities.cpp

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-data-attr.dir/attr_utilities.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_utilities.cpp > CMakeFiles/base-data-attr.dir/attr_utilities.cpp.i

src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-data-attr.dir/attr_utilities.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr/attr_utilities.cpp -o CMakeFiles/base-data-attr.dir/attr_utilities.cpp.s

# Object files for target base-data-attr
base__data__attr_OBJECTS = \
"CMakeFiles/base-data-attr.dir/attr.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_module.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_registry.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_type.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o" \
"CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o"

# External object files for target base-data-attr
base__data__attr_EXTERNAL_OBJECTS =

src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attribute_list.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_attrset.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_module.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_registry.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_type_value_iterator.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/attr_utilities.cpp.o
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/build.make
src/base/data/attr/libbase-data-attr.a: src/base/data/attr/CMakeFiles/base-data-attr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libbase-data-attr.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && $(CMAKE_COMMAND) -P CMakeFiles/base-data-attr.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base-data-attr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/data/attr/CMakeFiles/base-data-attr.dir/build: src/base/data/attr/libbase-data-attr.a

.PHONY : src/base/data/attr/CMakeFiles/base-data-attr.dir/build

src/base/data/attr/CMakeFiles/base-data-attr.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr && $(CMAKE_COMMAND) -P CMakeFiles/base-data-attr.dir/cmake_clean.cmake
.PHONY : src/base/data/attr/CMakeFiles/base-data-attr.dir/clean

src/base/data/attr/CMakeFiles/base-data-attr.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/data/attr /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/data/attr/CMakeFiles/base-data-attr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/data/attr/CMakeFiles/base-data-attr.dir/depend
