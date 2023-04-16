#ifndef INITIAL_MAINENGINE_H
#define INITIAL_MAINENGINE_H

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define the struct for the 2D vector
struct VectorWrapper{
    vector<vector<char>> TDVEC;
};

// Define the Maps class
class Maps
{
private:
    int Map_height;
    int Map_width;
public:
    Maps(int,int);
    int map_height;
    int map_width;
    VectorWrapper Map_Loader();
    VectorWrapper MapToArray(ifstream&);
    void Map_printer(VectorWrapper Converter);
};

// Define the move character function
void move_character(WINDOW*, int&, int&, VectorWrapper, int, int);

#endif //INITIAL_MAINENGINE_H
