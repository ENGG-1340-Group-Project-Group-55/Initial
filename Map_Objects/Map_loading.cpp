#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "/Users/M1/Documents/GitHub/Initial/CharactersDesign_Mechanism/MapLoader.h"
#include <ncurses.h>

using namespace std;

Maps::Maps(int a,int b){
    Map_height = a;
    Map_width = b;
    map_height = Map_height;
    map_width = Map_width;
}

VectorWrapper Maps::Map_Loader() {
    ifstream inputline;
    string nextline;
    inputline.open("/Users/M1/Documents/GitHub/Initial/Map_Objects/Map_resources/15-15_Testing.txt");
    if (inputline.fail()){
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }
    VectorWrapper Converter = MapToArray(inputline);
    return Converter;
}

VectorWrapper Maps::MapToArray(ifstream& inputline)
{
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

void Maps::Map_printer(VectorWrapper Converter, int y, int x, int screen_height, int screen_width)
{
    for (int i=y;i<y+screen_height;i++){
        for(int j=x;j<x+screen_width;j++){
//            if (j==x+screen_width-3){
            mvaddch(i + 1, j, Converter.TDVEC[i][j]);
//            }
//            else{
//                mvaddch(i + 1, (j * 2) + 2, Converter.TDVEC[i][j]);
        }
    }
}

