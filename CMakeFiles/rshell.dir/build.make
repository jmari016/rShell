# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /class/classes/ewhit004/assignments/assignment-rshell

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /class/classes/ewhit004/assignments/assignment-rshell

# Include any dependencies generated for this target.
include CMakeFiles/rshell.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rshell.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rshell.dir/flags.make

CMakeFiles/rshell.dir/src/main.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rshell.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/main.cpp.o -c /class/classes/ewhit004/assignments/assignment-rshell/src/main.cpp

CMakeFiles/rshell.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/ewhit004/assignments/assignment-rshell/src/main.cpp > CMakeFiles/rshell.dir/src/main.cpp.i

CMakeFiles/rshell.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/ewhit004/assignments/assignment-rshell/src/main.cpp -o CMakeFiles/rshell.dir/src/main.cpp.s

CMakeFiles/rshell.dir/src/Execute.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/Execute.cpp.o: src/Execute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rshell.dir/src/Execute.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/Execute.cpp.o -c /class/classes/ewhit004/assignments/assignment-rshell/src/Execute.cpp

CMakeFiles/rshell.dir/src/Execute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/Execute.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/ewhit004/assignments/assignment-rshell/src/Execute.cpp > CMakeFiles/rshell.dir/src/Execute.cpp.i

CMakeFiles/rshell.dir/src/Execute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/Execute.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/ewhit004/assignments/assignment-rshell/src/Execute.cpp -o CMakeFiles/rshell.dir/src/Execute.cpp.s

CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o: src/ExecuteOR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o -c /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteOR.cpp

CMakeFiles/rshell.dir/src/ExecuteOR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/ExecuteOR.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteOR.cpp > CMakeFiles/rshell.dir/src/ExecuteOR.cpp.i

CMakeFiles/rshell.dir/src/ExecuteOR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/ExecuteOR.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteOR.cpp -o CMakeFiles/rshell.dir/src/ExecuteOR.cpp.s

CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o: src/ExecuteAND.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o -c /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteAND.cpp

CMakeFiles/rshell.dir/src/ExecuteAND.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/ExecuteAND.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteAND.cpp > CMakeFiles/rshell.dir/src/ExecuteAND.cpp.i

CMakeFiles/rshell.dir/src/ExecuteAND.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/ExecuteAND.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteAND.cpp -o CMakeFiles/rshell.dir/src/ExecuteAND.cpp.s

CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o: CMakeFiles/rshell.dir/flags.make
CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o: src/ExecuteSEMI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o -c /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteSEMI.cpp

CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteSEMI.cpp > CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.i

CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /class/classes/ewhit004/assignments/assignment-rshell/src/ExecuteSEMI.cpp -o CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.s

# Object files for target rshell
rshell_OBJECTS = \
"CMakeFiles/rshell.dir/src/main.cpp.o" \
"CMakeFiles/rshell.dir/src/Execute.cpp.o" \
"CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o" \
"CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o" \
"CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o"

# External object files for target rshell
rshell_EXTERNAL_OBJECTS =

rshell: CMakeFiles/rshell.dir/src/main.cpp.o
rshell: CMakeFiles/rshell.dir/src/Execute.cpp.o
rshell: CMakeFiles/rshell.dir/src/ExecuteOR.cpp.o
rshell: CMakeFiles/rshell.dir/src/ExecuteAND.cpp.o
rshell: CMakeFiles/rshell.dir/src/ExecuteSEMI.cpp.o
rshell: CMakeFiles/rshell.dir/build.make
rshell: CMakeFiles/rshell.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable rshell"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rshell.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rshell.dir/build: rshell

.PHONY : CMakeFiles/rshell.dir/build

CMakeFiles/rshell.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rshell.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rshell.dir/clean

CMakeFiles/rshell.dir/depend:
	cd /class/classes/ewhit004/assignments/assignment-rshell && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /class/classes/ewhit004/assignments/assignment-rshell /class/classes/ewhit004/assignments/assignment-rshell /class/classes/ewhit004/assignments/assignment-rshell /class/classes/ewhit004/assignments/assignment-rshell /class/classes/ewhit004/assignments/assignment-rshell/CMakeFiles/rshell.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rshell.dir/depend

