#include "doorcoordinate.h"
#include <iostream>

using namespace std;

map<string,coordinates> Corridor;
map<string,coordinates> Stairs;

coordinates ClassRoom = {20,13};
coordinates ClubRoom = {75,13};
coordinates MusicRoom = {24,27};
coordinates TeachersOffice = {13,104};
coordinates RoofTopStairs = {22,105};
coordinates ToCorridor = {48,30};
coordinates RoofTop = {48,14};
coordinates DiningRoom = {1,2};
coordinates RestRoom = {3,4};

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
