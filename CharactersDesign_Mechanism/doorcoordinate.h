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

void initialize();
void clears();

extern map<string,coordinates> Corridor;
extern map<string,coordinates> Stairs;

extern coordinates Classroom;
extern coordinates Clubroom;
extern coordinates Musicroom;
extern coordinates TeachersOffice;
extern coordinates RoofTopStairs;
extern coordinates ToCorridor;
extern coordinates RoofTop;

#endif //INITIAL_DOORCOORDINATE_H
