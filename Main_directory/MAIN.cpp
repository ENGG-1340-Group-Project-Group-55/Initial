#include <iostream>
#include <string>
#include "CharactersDesign_Mechanism/doorcoordinate.h"
using namespace std;

class rooms
{
public:
    string Classroom();
    string Clubroom();
    string Music_Room();
    string Rooftop_Stairs();
    string Rooftop();
    string SchoolMap(string);
    string TeachersOffice();
};

int main()
{
    initialize();
    int *x = new int;
    int *y = new int;
    string entered;
    rooms RM;
    bool flag = true;
    while (flag)
    {
        if (entered == "Classroom")
        {
            RM.Classroom();
            entered = "Classroom";
            *x = Corridor[entered].x_coordinates;
            *y = Corridor[entered].y_coordinates;
        }
        else if (entered == "Clubroom")
        {
            RM.Clubroom();
            entered = "Clubroom";
            *x = Corridor[entered].x_coordinates;
            *y = Corridor[entered].y_coordinates;
        }
        else if (entered == "Music_Room")
        {
            RM.Music_Room();
            entered = "Music_Room";
            *x = Corridor[entered].x_coordinates;
            *y = Corridor[entered].y_coordinates;
        }
        else if (entered == "TeachersOffice")
        {
            RM.TeachersOffice();
            entered = "TeachersOffice";
            *x = Corridor[entered].x_coordinates;
            *y = Corridor[entered].y_coordinates;
        }
        else if (entered == "Rooftop")
        {
            RM.Rooftop();
            entered = "RoofTop";
            *x = Stairs[entered].x_coordinates;
            *y = Stairs[entered].y_coordinates;
        }
        else if (entered == "Rooftop_Stairs")
        {
            entered = RM.Rooftop_Stairs();
            *x = Stairs[entered].x_coordinates;
            *y = Stairs[entered].y_coordinates;
        }

        if (entered == "Rooftop")
    }
}
