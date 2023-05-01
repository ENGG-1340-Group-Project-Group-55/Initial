#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;
                      //{x, y}
coordinates ClassRoom = {18,8};
coordinates ClubRoom = {75,11};
coordinates MusicRoom = {23,16};
coordinates TeachersOffice = {101,11};
coordinates RoofTopStairs = {107,23};
coordinates ToCorridor = {48,30};
coordinates RoofTop = {48,14};
coordinates DiningRoom = {21,40};///
coordinates RestRoom = {38,14};///

void initialize(){
    Corridor.insert({"ClassRoom",ClassRoom});
    Corridor.insert({"ClubRoom",ClubRoom});
    Corridor.insert({"MusicRoom",MusicRoom});
    Corridor.insert({"TeachersOffice",TeachersOffice});
    Corridor.insert({"RoofTopStairs",RoofTopStairs});
    Corridor.insert({"DiningRoom",DiningRoom});
    Corridor.insert({"RestRoom",RestRoom});

    Stairs.insert({"ToCorridor",ToCorridor});
    Stairs.insert({"RoofTop",RoofTop});
}

void clears()
{
    Corridor.clear();
    Stairs.clear();
}
