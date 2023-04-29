#ifndef INITIAL_DOORCOORDINATE_H
#define INITIAL_DOORCOORDINATE_H

#include <map>
#include <string>
#include <iostream>
using namespace std;

struct coordinates
{
    int y_coordinates;
    int x_coordinates;
};


map<string,coordinates> Corridor;
map<string,coordinates> Stairs;

coordinates Classroom = {20,13};
coordinates Clubroom = {75,13};
coordinates Musicroom = {24,27};
coordinates TeachersOffice = {13,104};
coordinates RoofTopStairs = {22,105};

coordinates ToCorridor = {48,30};
coordinates RoofTop = {48,14};

#endif //INITIAL_DOORCOORDINATE_H
