cmake_minimum_required(VERSION 3.24)
project(Initial)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Map_loading Map.Objects/Map_loading.cpp CharactersDesign_Mechanism/MainEngine.h)
add_executable(Map_loading_save Map_Objects/Map_loading_save.cpp)
add_executable(MAIN Main_directory/MAIN.cpp CharactersDesign_Mechanism/doorcoordinate.cpp /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.h CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
add_executable(Enginev1 CharactersDesign_Mechanism/Enginev1.cpp)
add_executable(Enginev2 CharactersDesign_Mechanism/Enginev2.cpp)
add_executable(MainEngine CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)