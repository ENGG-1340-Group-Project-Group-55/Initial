#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "MainEngine.h" // Include the new header file
#include <ncurses.h>

using namespace std;

VectorWrapper Maps::Map_Loader() {
    ifstream inputline;
    string nextline;
    inputline.open("15-15_map.txt");
    if (inputline.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    VectorWrapper Converter = MapToArray(inputline);
    return Converter;
}

void Maps::Map_printer(VectorWrapper Converter, int y, int x, int screen_height, int screen_width)
{
    for (int i=y;i<y+screen_height-2;i++){
        for(int j=x;j<x+screen_width-2;j++){
            if (j==x+screen_width-3){
                mvaddch(i + 1, (j * 2) + 2, Converter.TDVEC[i][j]);
            }
            else{
                mvaddch(i + 1, (j * 2) + 2, Converter.TDVEC[i][j]);
            }
        }
    }
}
