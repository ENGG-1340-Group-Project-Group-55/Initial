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
CMAKE_COMMAND = /Users/lucas/Desktop/programming/C++/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/lucas/Desktop/programming/C++/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lucas/Documents/GitHub/Initial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lucas/Documents/GitHub/Initial/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Character_Design.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Character_Design.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Character_Design.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Character_Design.dir/flags.make

CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o: CMakeFiles/Character_Design.dir/flags.make
CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o: /Users/lucas/Documents/GitHub/Initial/CharactersDesign_Mechanism/Character_Design.cpp
CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o: CMakeFiles/Character_Design.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lucas/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o -MF CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o.d -o CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o -c /Users/lucas/Documents/GitHub/Initial/CharactersDesign_Mechanism/Character_Design.cpp

CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lucas/Documents/GitHub/Initial/CharactersDesign_Mechanism/Character_Design.cpp > CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.i

CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lucas/Documents/GitHub/Initial/CharactersDesign_Mechanism/Character_Design.cpp -o CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.s

# Object files for target Character_Design
Character_Design_OBJECTS = \
"CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o"

# External object files for target Character_Design
Character_Design_EXTERNAL_OBJECTS =

Character_Design: CMakeFiles/Character_Design.dir/CharactersDesign_Mechanism/Character_Design.cpp.o
Character_Design: CMakeFiles/Character_Design.dir/build.make
Character_Design: CMakeFiles/Character_Design.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lucas/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Character_Design"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Character_Design.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Character_Design.dir/build: Character_Design
.PHONY : CMakeFiles/Character_Design.dir/build

CMakeFiles/Character_Design.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Character_Design.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Character_Design.dir/clean

CMakeFiles/Character_Design.dir/depend:
	cd /Users/lucas/Documents/GitHub/Initial/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lucas/Documents/GitHub/Initial /Users/lucas/Documents/GitHub/Initial /Users/lucas/Documents/GitHub/Initial/cmake-build-debug /Users/lucas/Documents/GitHub/Initial/cmake-build-debug /Users/lucas/Documents/GitHub/Initial/cmake-build-debug/CMakeFiles/Character_Design.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Character_Design.dir/depend

