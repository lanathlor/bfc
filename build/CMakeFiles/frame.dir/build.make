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
include CMakeFiles/frame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/frame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/frame.dir/flags.make

CMakeFiles/frame.dir/src/actorRep.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/actorRep.cpp.o: ../src/actorRep.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/frame.dir/src/actorRep.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/actorRep.cpp.o -c /home/lanath/repo/bfc/src/actorRep.cpp

CMakeFiles/frame.dir/src/actorRep.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/actorRep.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/actorRep.cpp > CMakeFiles/frame.dir/src/actorRep.cpp.i

CMakeFiles/frame.dir/src/actorRep.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/actorRep.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/actorRep.cpp -o CMakeFiles/frame.dir/src/actorRep.cpp.s

CMakeFiles/frame.dir/src/bfcmain.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/bfcmain.cpp.o: ../src/bfcmain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/frame.dir/src/bfcmain.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/bfcmain.cpp.o -c /home/lanath/repo/bfc/src/bfcmain.cpp

CMakeFiles/frame.dir/src/bfcmain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/bfcmain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/bfcmain.cpp > CMakeFiles/frame.dir/src/bfcmain.cpp.i

CMakeFiles/frame.dir/src/bfcmain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/bfcmain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/bfcmain.cpp -o CMakeFiles/frame.dir/src/bfcmain.cpp.s

CMakeFiles/frame.dir/src/exit.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/exit.cpp.o: ../src/exit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/frame.dir/src/exit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/exit.cpp.o -c /home/lanath/repo/bfc/src/exit.cpp

CMakeFiles/frame.dir/src/exit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/exit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/exit.cpp > CMakeFiles/frame.dir/src/exit.cpp.i

CMakeFiles/frame.dir/src/exit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/exit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/exit.cpp -o CMakeFiles/frame.dir/src/exit.cpp.s

CMakeFiles/frame.dir/src/flag.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/flag.cpp.o: ../src/flag.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/frame.dir/src/flag.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/flag.cpp.o -c /home/lanath/repo/bfc/src/flag.cpp

CMakeFiles/frame.dir/src/flag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/flag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/flag.cpp > CMakeFiles/frame.dir/src/flag.cpp.i

CMakeFiles/frame.dir/src/flag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/flag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/flag.cpp -o CMakeFiles/frame.dir/src/flag.cpp.s

CMakeFiles/frame.dir/src/masterThread.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/masterThread.cpp.o: ../src/masterThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/frame.dir/src/masterThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/masterThread.cpp.o -c /home/lanath/repo/bfc/src/masterThread.cpp

CMakeFiles/frame.dir/src/masterThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/masterThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/masterThread.cpp > CMakeFiles/frame.dir/src/masterThread.cpp.i

CMakeFiles/frame.dir/src/masterThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/masterThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/masterThread.cpp -o CMakeFiles/frame.dir/src/masterThread.cpp.s

CMakeFiles/frame.dir/src/usage.cpp.o: CMakeFiles/frame.dir/flags.make
CMakeFiles/frame.dir/src/usage.cpp.o: ../src/usage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/frame.dir/src/usage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/frame.dir/src/usage.cpp.o -c /home/lanath/repo/bfc/src/usage.cpp

CMakeFiles/frame.dir/src/usage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/frame.dir/src/usage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lanath/repo/bfc/src/usage.cpp > CMakeFiles/frame.dir/src/usage.cpp.i

CMakeFiles/frame.dir/src/usage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/frame.dir/src/usage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lanath/repo/bfc/src/usage.cpp -o CMakeFiles/frame.dir/src/usage.cpp.s

# Object files for target frame
frame_OBJECTS = \
"CMakeFiles/frame.dir/src/actorRep.cpp.o" \
"CMakeFiles/frame.dir/src/bfcmain.cpp.o" \
"CMakeFiles/frame.dir/src/exit.cpp.o" \
"CMakeFiles/frame.dir/src/flag.cpp.o" \
"CMakeFiles/frame.dir/src/masterThread.cpp.o" \
"CMakeFiles/frame.dir/src/usage.cpp.o"

# External object files for target frame
frame_EXTERNAL_OBJECTS =

libframe.a: CMakeFiles/frame.dir/src/actorRep.cpp.o
libframe.a: CMakeFiles/frame.dir/src/bfcmain.cpp.o
libframe.a: CMakeFiles/frame.dir/src/exit.cpp.o
libframe.a: CMakeFiles/frame.dir/src/flag.cpp.o
libframe.a: CMakeFiles/frame.dir/src/masterThread.cpp.o
libframe.a: CMakeFiles/frame.dir/src/usage.cpp.o
libframe.a: CMakeFiles/frame.dir/build.make
libframe.a: CMakeFiles/frame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lanath/repo/bfc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libframe.a"
	$(CMAKE_COMMAND) -P CMakeFiles/frame.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/frame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/frame.dir/build: libframe.a

.PHONY : CMakeFiles/frame.dir/build

CMakeFiles/frame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/frame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/frame.dir/clean

CMakeFiles/frame.dir/depend:
	cd /home/lanath/repo/bfc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lanath/repo/bfc /home/lanath/repo/bfc /home/lanath/repo/bfc/build /home/lanath/repo/bfc/build /home/lanath/repo/bfc/build/CMakeFiles/frame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/frame.dir/depend
