#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;
//coordinates for exiting to map {x, y} point on head
coordinates ClassRoom = {18,8};
coordinates ClubRoom = {74,8};
coordinates MusicRoom = {23,17};
coordinates TeachersOffice = {100,8};
coordinates RoofTopStairs = {105,19};
coordinates ToCorridor = {44,23};
coordinates RoofTop = {47,9};
coordinates ToRoofTop = {49,15};
coordinates DiningRoom = {40,17};///
coordinates RestRoom = {34,8};///

void initialize(){
    Corridor.insert({"ClassRoom",ClassRoom});
    Corridor.insert({"ClubRoom",ClubRoom});
    Corridor.insert({"MusicRoom",MusicRoom});
    Corridor.insert({"TeachersOffice",TeachersOffice});
    Corridor.insert({"RoofTopStairs",RoofTopStairs});
    Corridor.insert({"DiningRoom",DiningRoom});
    Corridor.insert({"RestRoom",RestRoom});

    Stairs.insert({"ToCorridor",ToCorridor});
    Stairs.insert({"ToRoofTop",ToRoofTop});
    Stairs.insert({"RoofTop",RoofTop});
}

void clears()
{
    Corridor.clear();
    Stairs.clear();
}
