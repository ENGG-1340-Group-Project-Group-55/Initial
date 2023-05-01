#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;
            //to corridor{x, y}
coordinates ClassRoom = {18,8};
coordinates ClubRoom = {75,11};
coordinates MusicRoom = {23,16};
coordinates TeachersOffice = {103,10};
coordinates RoofTopStairs = {105,19};
coordinates ToCorridor = {46,25};
coordinates RoofTop = {47,9};
coordinates DiningRoom = {40,17};///
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
