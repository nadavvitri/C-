# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "/cygdrive/c/Users/nadav vitri/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe"

# The command to remove a file.
RM = "/cygdrive/c/Users/nadav vitri/.CLion2017.2/system/cygwin_cmake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ex3_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex3_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex3_cpp.dir/flags.make

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o: CMakeFiles/ex3_cpp.dir/flags.make
CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o: ../ParallelChecker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o -c "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/ParallelChecker.cpp"

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/ParallelChecker.cpp" > CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.i

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/ParallelChecker.cpp" -o CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.s

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.requires:

.PHONY : CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.requires

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.provides: CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex3_cpp.dir/build.make CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.provides.build
.PHONY : CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.provides

CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.provides.build: CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o


CMakeFiles/ex3_cpp.dir/Complex.cpp.o: CMakeFiles/ex3_cpp.dir/flags.make
CMakeFiles/ex3_cpp.dir/Complex.cpp.o: ../Complex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex3_cpp.dir/Complex.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex3_cpp.dir/Complex.cpp.o -c "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/Complex.cpp"

CMakeFiles/ex3_cpp.dir/Complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3_cpp.dir/Complex.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/Complex.cpp" > CMakeFiles/ex3_cpp.dir/Complex.cpp.i

CMakeFiles/ex3_cpp.dir/Complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3_cpp.dir/Complex.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/Complex.cpp" -o CMakeFiles/ex3_cpp.dir/Complex.cpp.s

CMakeFiles/ex3_cpp.dir/Complex.cpp.o.requires:

.PHONY : CMakeFiles/ex3_cpp.dir/Complex.cpp.o.requires

CMakeFiles/ex3_cpp.dir/Complex.cpp.o.provides: CMakeFiles/ex3_cpp.dir/Complex.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex3_cpp.dir/build.make CMakeFiles/ex3_cpp.dir/Complex.cpp.o.provides.build
.PHONY : CMakeFiles/ex3_cpp.dir/Complex.cpp.o.provides

CMakeFiles/ex3_cpp.dir/Complex.cpp.o.provides.build: CMakeFiles/ex3_cpp.dir/Complex.cpp.o


CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o: CMakeFiles/ex3_cpp.dir/flags.make
CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o: ../timeChecker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o -c "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/timeChecker.cpp"

CMakeFiles/ex3_cpp.dir/timeChecker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex3_cpp.dir/timeChecker.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/timeChecker.cpp" > CMakeFiles/ex3_cpp.dir/timeChecker.cpp.i

CMakeFiles/ex3_cpp.dir/timeChecker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex3_cpp.dir/timeChecker.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/timeChecker.cpp" -o CMakeFiles/ex3_cpp.dir/timeChecker.cpp.s

CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.requires:

.PHONY : CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.requires

CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.provides: CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex3_cpp.dir/build.make CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.provides.build
.PHONY : CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.provides

CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.provides.build: CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o


# Object files for target ex3_cpp
ex3_cpp_OBJECTS = \
"CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o" \
"CMakeFiles/ex3_cpp.dir/Complex.cpp.o" \
"CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o"

# External object files for target ex3_cpp
ex3_cpp_EXTERNAL_OBJECTS =

ex3_cpp.exe: CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o
ex3_cpp.exe: CMakeFiles/ex3_cpp.dir/Complex.cpp.o
ex3_cpp.exe: CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o
ex3_cpp.exe: CMakeFiles/ex3_cpp.dir/build.make
ex3_cpp.exe: CMakeFiles/ex3_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ex3_cpp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex3_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex3_cpp.dir/build: ex3_cpp.exe

.PHONY : CMakeFiles/ex3_cpp.dir/build

CMakeFiles/ex3_cpp.dir/requires: CMakeFiles/ex3_cpp.dir/ParallelChecker.cpp.o.requires
CMakeFiles/ex3_cpp.dir/requires: CMakeFiles/ex3_cpp.dir/Complex.cpp.o.requires
CMakeFiles/ex3_cpp.dir/requires: CMakeFiles/ex3_cpp.dir/timeChecker.cpp.o.requires

.PHONY : CMakeFiles/ex3_cpp.dir/requires

CMakeFiles/ex3_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex3_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex3_cpp.dir/clean

CMakeFiles/ex3_cpp.dir/depend:
	cd "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp" "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp" "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug" "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug" "/cygdrive/c/Users/nadav vitri/CLionProjects/ex3_cpp/cmake-build-debug/CMakeFiles/ex3_cpp.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ex3_cpp.dir/depend
