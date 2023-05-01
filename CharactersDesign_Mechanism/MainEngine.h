#ifndef MAIN_ENGINE_H
#define MAIN_ENGINE_H

#include <ncurses.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MapLoader.h"

WINDOW* CreateWindow(int screen_height, int screen_width);
void printInventory(std::vector<std::string> inventory);
std::vector<std::string> loadInventoryFromFile();
int main_engine(std::string file_path, int x, int y);

#endif // MAIN_ENGINE_H