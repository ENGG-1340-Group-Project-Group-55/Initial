cmake_minimum_required(VERSION 3.24)
project(Initial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(MAIN Main_directory/MAIN.cpp CharactersDesign_Mechanism/doorcoordinate.cpp CharactersDesign_Mechanism/doorcoordinate.h CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
add_executable(MainEngine CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h Main_directory/MAIN.cpp CharactersDesign_Mechanism/doorcoordinate.cpp CharactersDesign_Mechanism/doorcoordinate.h)
