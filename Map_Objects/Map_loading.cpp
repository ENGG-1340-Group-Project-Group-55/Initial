#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CharactersDesign_Mechanism/MapLoader.h"
#include <ncurses.h>

using namespace std;

Maps::Maps(int a,int b){
    Map_height = a;
    Map_width = b;
    map_height = Map_height;
    map_width = Map_width;
}

VectorWrapper Maps::Map_Loader(string &file_path) {
    ifstream inputline;
    inputline.open(file_path);
    if (inputline.fail()) {
        cout<<"No map file"<<endl;
        exit(1);
    }
    VectorWrapper Converter = MapToArray(inputline);
    inputline.close();
    return Converter;
}

VectorWrapper Maps::MapToArray(ifstream& inputline) {
    VectorWrapper Converter;
    char ch;
    int height_tracker = 0;
    int width_tracker = 0;
    Converter.TDVEC.resize(map_height);
    while (inputline >> noskipws >> ch)
    {
        if (ch != '\n')
        {
            Converter.TDVEC[height_tracker].push_back(ch);
            if (width_tracker==map_width-1)
            {
                height_tracker++;
                if (height_tracker==map_height)
                {
                    inputline.close();
                    break;
                }
                width_tracker = -1;
            }
            width_tracker++;
        }
    }
    return Converter;
}

void Maps::Map_printer(VectorWrapper Converter, int y, int x, int screen_height, int screen_width, WINDOW* win) {
    for (int i=y;i<y+screen_height;i++){
        for(int j=x;j<x+screen_width;j++){
            mvwaddch(win, i-y, j-x, Converter.TDVEC[i][j]);
        }
    }
    wrefresh(win);
}