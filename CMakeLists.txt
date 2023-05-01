cmake_minimum_required(VERSION 3.24)
project(Initial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")

<<<<<<< HEAD
#add_executable(Map_loading Map.Objects/Map_loading.cpp CharactersDesign_Mechanism/MainEngine.h)
add_executable(MAIN Main_directory/MAIN.cpp CharactersDesign_Mechanism/doorcoordinate.cpp /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.h CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
<<<<<<< HEAD
add_executable(MainEngine /workspaces/Initial/CharactersDesign_Mechanism /workspaces/Initial/Map_Objects/Map_loading.cpp /workspaces/Initial/CharactersDesign_Mechanism/MapLoader.h)
=======
<<<<<<< HEAD
add_executable(MainEngine /workspaces/Initial/CharactersDesign_Mechanism Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
=======
add_executable(MainEngine CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
=======
add_executable(MAIN Main_directory/MAIN.cpp CharactersDesign_Mechanism/doorcoordinate.cpp /workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.h CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp CharactersDesign_Mechanism/MapLoader.h)
add_executable(MainEngine /workspaces/Initial/CharactersDesign_Mechanism/MainEngine.cpp /workspaces/Initial/Map_Objects/Map_loading.cpp /workspaces/Initial/CharactersDesign_Mechanism/MapLoader.h)

>>>>>>> 923121c (.)
>>>>>>> 94a2f56 (.)
>>>>>>> 192f210 (.)
