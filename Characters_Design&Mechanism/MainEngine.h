#ifndef MAINENGINE_H
#define MAINENGINE_H

#include <vector>
#include <fstream>

using namespace std;

struct VectorWrapper{
    vector<vector<char>> TDVEC;
};

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
    void Map_printer(VectorWrapper, int, int, int, int);
};

#endif