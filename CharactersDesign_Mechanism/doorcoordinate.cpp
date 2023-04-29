#include "doorcoordinate.h"
#include <iostream>

using namespace std;


void initialize(){
    Corridor.insert({"Classroom",Classroom});
    Corridor.insert({"Clubroom",Clubroom});
    Corridor.insert({"Musicroom",Musicroom});
    Corridor.insert({"TeachersOffice",TeachersOffice});
    Corridor.insert({"RoofTopStairs",RoofTopStairs});

    Stairs.insert({"ToCorridor",ToCorridor});
    Stairs.insert({"RoofTop",RoofTop});
}

void clear()
{
    Corridor.clear();
    Stairs.clear();
}
