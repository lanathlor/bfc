# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lanath/repo/bfc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lanath/repo/bfc/build

# Include any dependencies generated for this target.
include CMakeFiles/bkcnode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bkcnode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bkcnode.dir/flags.make

CMakeFiles/bkcnode.dir/src/__dummy.cpp.o: CMakeFiles/bkcnode.dir/flags.make
CMakeFiles/bkcnode.dir/src/__dummy.cpp.o: ../src/__dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bkcnode.dir/src/__dummy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bkcnode.dir/src/__dummy.cpp.o -c /home/lanath/repo/bfc/src/__dummy.cpp

CMakeFiles/bkcnode.dir/src/__dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bkcnode.dir/src/__dummy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/__dummy.cpp > CMakeFiles/bkcnode.dir/src/__dummy.cpp.i

CMakeFiles/bkcnode.dir/src/__dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bkcnode.dir/src/__dummy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/__dummy.cpp -o CMakeFiles/bkcnode.dir/src/__dummy.cpp.s

# Object files for target bkcnode
bkcnode_OBJECTS = \
"CMakeFiles/bkcnode.dir/src/__dummy.cpp.o"

# External object files for target bkcnode
bkcnode_EXTERNAL_OBJECTS =

bkcnode: CMakeFiles/bkcnode.dir/src/__dummy.cpp.o
bkcnode: CMakeFiles/bkcnode.dir/build.make
bkcnode: /usr/local/lib/libblc.a
bkcnode: libframe.a
bkcnode: dev/libdevobj.a
bkcnode: ../dep/libtomcrypt.a
bkcnode: ../dep/libtommath.a
bkcnode: /usr/local/lib/libblc.a
bkcnode: CMakeFiles/bkcnode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bkcnode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bkcnode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bkcnode.dir/build: bkcnode

.PHONY : CMakeFiles/bkcnode.dir/build

CMakeFiles/bkcnode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bkcnode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bkcnode.dir/clean

CMakeFiles/bkcnode.dir/depend:
	cd /home/lanath/repo/bfc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lanath/repo/bfc /home/lanath/repo/bfc /home/lanath/repo/bfc/build /home/lanath/repo/bfc/build /home/lanath/repo/bfc/build/CMakeFiles/bkcnode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bkcnode.dir/depend

