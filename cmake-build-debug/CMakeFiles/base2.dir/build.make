# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/M1/Documents/GitHub/Initial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/M1/Documents/GitHub/Initial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/base2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/base2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/base2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/base2.dir/flags.make

CMakeFiles/base2.dir/UI/base2.cpp.o: CMakeFiles/base2.dir/flags.make
CMakeFiles/base2.dir/UI/base2.cpp.o: /Users/M1/Documents/GitHub/Initial/UI/base2.cpp
CMakeFiles/base2.dir/UI/base2.cpp.o: CMakeFiles/base2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/base2.dir/UI/base2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/base2.dir/UI/base2.cpp.o -MF CMakeFiles/base2.dir/UI/base2.cpp.o.d -o CMakeFiles/base2.dir/UI/base2.cpp.o -c /Users/M1/Documents/GitHub/Initial/UI/base2.cpp

CMakeFiles/base2.dir/UI/base2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base2.dir/UI/base2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/M1/Documents/GitHub/Initial/UI/base2.cpp > CMakeFiles/base2.dir/UI/base2.cpp.i

CMakeFiles/base2.dir/UI/base2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base2.dir/UI/base2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/M1/Documents/GitHub/Initial/UI/base2.cpp -o CMakeFiles/base2.dir/UI/base2.cpp.s

# Object files for target base2
base2_OBJECTS = \
"CMakeFiles/base2.dir/UI/base2.cpp.o"

# External object files for target base2
base2_EXTERNAL_OBJECTS =

base2: CMakeFiles/base2.dir/UI/base2.cpp.o
base2: CMakeFiles/base2.dir/build.make
base2: CMakeFiles/base2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable base2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/base2.dir/build: base2
.PHONY : CMakeFiles/base2.dir/build

CMakeFiles/base2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/base2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/base2.dir/clean

CMakeFiles/base2.dir/depend:
	cd /Users/M1/Documents/GitHub/Initial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/M1/Documents/GitHub/Initial /Users/M1/Documents/GitHub/Initial /Users/M1/Documents/GitHub/Initial/cmake-build-debug /Users/M1/Documents/GitHub/Initial/cmake-build-debug /Users/M1/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles/base2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/base2.dir/depend

