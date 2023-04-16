cmake_minimum_required(VERSION 3.24)
project(Initial)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Map_loading Map&Objects/Map_loading.cpp Characters_Design&Mechanism/MainEngine.h)
add_executable(Map_loading_save Map&Objects/Map_loading_save.cpp)
add_executable(inventory UI/inventory.cpp)
add_executable(inventory2 UI/inventory2.cpp)
add_executable(base UI/base.cpp)
add_executable(base2 UI/base2.cpp)
add_executable(Enginev1 Characters_Design&Mechanism/Enginev1.cpp)
add_executable(Enginev2 Characters_Design&Mechanism/Enginev2.cpp)
add_executable(Character_Design Characters_Design&Mechanism/Character_Design.cpp)

#add_executable(Game Characters_Design&Mechanism/MainEngine.cpp Map&Objects/Map_loading.cpp Characters_Design&Mechanism/MainEngine.h)

add_executable(MainEngine Characters_Design&Mechanism/MainEngine.cpp Characters_Design&Mechanism/MainEngine.h Map&Objects/Map_loading.cpp)
target_include_directories(MainEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Characters_Design&Mechanism)