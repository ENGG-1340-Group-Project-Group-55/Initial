# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/codespace/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/Initial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Initial/build

# Include any dependencies generated for this target.
include CMakeFiles/MainEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MainEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainEngine.dir/flags.make

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o: CMakeFiles/MainEngine.dir/flags.make
CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o: /workspaces/Initial/CharactersDesign_Mechanism/MainEngine.cpp
CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o: CMakeFiles/MainEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Initial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o -MF CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o.d -o CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o -c /workspaces/Initial/CharactersDesign_Mechanism/MainEngine.cpp

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Initial/CharactersDesign_Mechanism/MainEngine.cpp > CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.i

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Initial/CharactersDesign_Mechanism/MainEngine.cpp -o CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.s

CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o: CMakeFiles/MainEngine.dir/flags.make
CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o: /workspaces/Initial/Map_Objects/Map_loading.cpp
CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o: CMakeFiles/MainEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Initial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o -MF CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o.d -o CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o -c /workspaces/Initial/Map_Objects/Map_loading.cpp

CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Initial/Map_Objects/Map_loading.cpp > CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.i

CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Initial/Map_Objects/Map_loading.cpp -o CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.s

CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o: CMakeFiles/MainEngine.dir/flags.make
CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o: /workspaces/Initial/Main_directory/MAIN.cpp
CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o: CMakeFiles/MainEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Initial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o -MF CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o.d -o CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o -c /workspaces/Initial/Main_directory/MAIN.cpp

CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Initial/Main_directory/MAIN.cpp > CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.i

CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Initial/Main_directory/MAIN.cpp -o CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.s

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o: CMakeFiles/MainEngine.dir/flags.make
CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o: /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.cpp
CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o: CMakeFiles/MainEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/Initial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o -MF CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o.d -o CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o -c /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.cpp

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.cpp > CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.i

CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.cpp -o CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.s

# Object files for target MainEngine
MainEngine_OBJECTS = \
"CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o" \
"CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o" \
"CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o" \
"CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o"

# External object files for target MainEngine
MainEngine_EXTERNAL_OBJECTS =

MainEngine: CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/MainEngine.cpp.o
MainEngine: CMakeFiles/MainEngine.dir/Map_Objects/Map_loading.cpp.o
MainEngine: CMakeFiles/MainEngine.dir/Main_directory/MAIN.cpp.o
MainEngine: CMakeFiles/MainEngine.dir/CharactersDesign_Mechanism/doorcoordinate.cpp.o
MainEngine: CMakeFiles/MainEngine.dir/build.make
MainEngine: CMakeFiles/MainEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/Initial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable MainEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainEngine.dir/build: MainEngine
.PHONY : CMakeFiles/MainEngine.dir/build

CMakeFiles/MainEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainEngine.dir/clean

CMakeFiles/MainEngine.dir/depend:
	cd /workspaces/Initial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Initial /workspaces/Initial /workspaces/Initial/build /workspaces/Initial/build /workspaces/Initial/build/CMakeFiles/MainEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MainEngine.dir/depend

