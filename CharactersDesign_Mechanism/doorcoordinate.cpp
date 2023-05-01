#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;

coordinates Classroom = {20,13};
coordinates Clubroom = {75,13};
coordinates Musicroom = {24,27};
coordinates TeachersOffice = {13,104};
coordinates RoofTopStairs = {22,105};
coordinates ToCorridor = {48,30};
coordinates RoofTop = {48,14};

void initialize(){
    Corridor.insert({"Classroom",Classroom});
    Corridor.insert({"Clubroom",Clubroom});
    Corridor.insert({"Musicroom",Musicroom});
    Corridor.insert({"TeachersOffice",TeachersOffice});
    Corridor.insert({"RoofTopStairs",RoofTopStairs});

    Stairs.insert({"ToCorridor",ToCorridor});
    Stairs.insert({"RoofTop",RoofTop});
}

void clears()
{
    Corridor.clear();
    Stairs.clear();
}
