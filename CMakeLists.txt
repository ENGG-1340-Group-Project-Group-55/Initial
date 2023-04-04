cmake_minimum_required(VERSION 3.24)
project(Initial)

set(CMAKE_CXX_STANDARD 17)

add_executable(Map_loading Map&Objects/Map_loading.cpp)
add_executable(inventory UI/inventory.cpp)
add_executable(inventory2 UI/inventory2.cpp)
add_executable(base UI/base.cpp)
add_executable(base2 UI/base2.cpp)
add_executable(Enginev1 Characters_Design&Mechanism/Enginev1.cpp)
add_executable(Enginev2 Characters_Design&Mechanism/Enginev2.cpp)

target_link_libraries(Enginev2 ncurses)