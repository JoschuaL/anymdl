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
include src/base/hal/disk/CMakeFiles/base-hal-disk.dir/depend.make

# Include the progress variables for this target.
include src/base/hal/disk/CMakeFiles/base-hal-disk.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.o: ../src/base/hal/disk/disk.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/disk.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/disk.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk.cpp > CMakeFiles/base-hal-disk.dir/disk.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/disk.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk.cpp -o CMakeFiles/base-hal-disk.dir/disk.cpp.s

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o: ../src/base/hal/disk/diskdirectory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskdirectory.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskdirectory.cpp > CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskdirectory.cpp -o CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.s

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.o: ../src/base/hal/disk/diskfile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/diskfile.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskfile.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/diskfile.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskfile.cpp > CMakeFiles/base-hal-disk.dir/diskfile.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/diskfile.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/diskfile.cpp -o CMakeFiles/base-hal-disk.dir/diskfile.cpp.s

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o: ../src/base/hal/disk/disk_file_reader_writer_impl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_file_reader_writer_impl.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_file_reader_writer_impl.cpp > CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_file_reader_writer_impl.cpp -o CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.s

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o: ../src/base/hal/disk/disk_memory_reader_writer_impl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_memory_reader_writer_impl.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_memory_reader_writer_impl.cpp > CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_memory_reader_writer_impl.cpp -o CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.s

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/flags.make
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o: ../src/base/hal/disk/disk_zip_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o -c /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_zip_file.cpp

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.i"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_zip_file.cpp > CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.i

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.s"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && /usr/local/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk/disk_zip_file.cpp -o CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.s

# Object files for target base-hal-disk
base__hal__disk_OBJECTS = \
"CMakeFiles/base-hal-disk.dir/disk.cpp.o" \
"CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o" \
"CMakeFiles/base-hal-disk.dir/diskfile.cpp.o" \
"CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o" \
"CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o" \
"CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o"

# External object files for target base-hal-disk
base__hal__disk_EXTERNAL_OBJECTS =

src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskdirectory.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/diskfile.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_file_reader_writer_impl.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_memory_reader_writer_impl.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/disk_zip_file.cpp.o
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/build.make
src/base/hal/disk/libbase-hal-disk.a: src/base/hal/disk/CMakeFiles/base-hal-disk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libbase-hal-disk.a"
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && $(CMAKE_COMMAND) -P CMakeFiles/base-hal-disk.dir/cmake_clean_target.cmake
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base-hal-disk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/hal/disk/CMakeFiles/base-hal-disk.dir/build: src/base/hal/disk/libbase-hal-disk.a

.PHONY : src/base/hal/disk/CMakeFiles/base-hal-disk.dir/build

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/clean:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk && $(CMAKE_COMMAND) -P CMakeFiles/base-hal-disk.dir/cmake_clean.cmake
.PHONY : src/base/hal/disk/CMakeFiles/base-hal-disk.dir/clean

src/base/hal/disk/CMakeFiles/base-hal-disk.dir/depend:
	cd /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noisyedge/Projects/mdl-source/MDL-SDK /Users/noisyedge/Projects/mdl-source/MDL-SDK/src/base/hal/disk /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk /Users/noisyedge/Projects/mdl-source/MDL-SDK/build_ninja/src/base/hal/disk/CMakeFiles/base-hal-disk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/hal/disk/CMakeFiles/base-hal-disk.dir/depend

