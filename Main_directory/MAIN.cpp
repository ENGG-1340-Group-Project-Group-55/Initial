#include <iostream>
#include <string>
#include "CharactersDesign_Mechanism/doorcoordinate.h"
using namespace std;

class rooms
{
public:
    void Classroom();
    void Clubroom();
    void Music_Room();
    string Rooftop_Stairs();
    void RoofTop();
    string SchoolMap(int,int);
    void TeachersOffice();
};

int main()
{
    initialize();
    int *x = new int;
    int *y = new int;
    string exitfrom;
    string entered;
    rooms RM;
    bool flag = true;
    while (flag)
    {
        if (entered == "Classroom")
        {
            RM.Classroom();
            exitfrom = "Classroom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap"
        }
        else if (entered == "Clubroom")
        {
            RM.Clubroom();
            exitfrom = "Clubroom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap"
        }
        else if (entered == "Music_Room")
        {
            RM.Music_Room();
            exitfrom = "Music_Room";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "TeachersOffice")
        {
            RM.TeachersOffice();
            exitfrom = "TeachersOffice";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "RoofTop")
        {
            RM.Rooftop();
            exitfrom = "RoofTop";
            *x = Stairs[exitfrom].x_coordinates;
            *y = Stairs[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "Rooftop_Stairs")
        {
            exitfrom = RM.Rooftop_Stairs();
            *x = Stairs[exitfrom].x_coordinates;
            *y = Stairs[exitfrom].y_coordinates;
            if (exitfrom == "ToCorridor")
            {
                entered = "SchoolMap";
            }
            else
            {
                entered = "RoofTop";
            }
        }
        else if (entered == "SchoolMap")
        {
            entered = RM.SchoolMap(*x,*y);
        }
    }
} 

void rooms::Classroom()
{
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //main_engine(file_path,x_door,y_door);
}
void rooms::Clubroom()
{
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //main_engine(file_path,x_door,y_door);
}
 void rooms::Music_Room()
 {
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop(){
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice()
 {
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //main_engine(file_path,x_door,y_door);
 }

 string rooms::Rooftop_Stairs()
 {
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //int C_Or_R = main_engine(file_path,x_door,y_door);
    //if (C_Or_R == 1)
    {
        //return "ToCorridor"
    }
    //else
    {
        //return "RoofTop"
    }
 }

 string rooms::SchoolMap(int a,int b){
     string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    //int C_Or_R = main_engine(file_path,x_door,y_door);
    //if (C_Or_R == 1)
    {
        //return "ToCorridor"
    }
    //else
    {
        //return "RoofTop"
    }


 }
