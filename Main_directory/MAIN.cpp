#include <iostream>
#include <string>
#include "/workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.h"
#include "/workspaces/Initial/CharactersDesign_Mechanism/MainEngine.h"
using namespace std;

class rooms
{
public:
    void Classroom();
    void Clubroom();
    void Music_Room();
    string Rooftop_Stairs(int,int);
    void RoofTop();
    string SchoolMap(int,int);
    void TeachersOffice();
    string roomchooser(int);
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


    *x = 87, *y = 24;
    string file_path = "/Map_Objects/Map_resources/Classroom.txt";
    main_engine(file_path,*x,*y);

    
    while (flag)
    {
        if (entered == "Classroom")
        {
            RM.Classroom();
            exitfrom = "Classroom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "Clubroom")
        {
            RM.Clubroom();
            exitfrom = "Clubroom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
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
            RM.RoofTop();
            exitfrom = "RoofTop";
            *x = Stairs[exitfrom].x_coordinates;
            *y = Stairs[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "Rooftop_Stairs")
        {
            exitfrom = RM.Rooftop_Stairs(*x,*y);
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
    main_engine(file_path,x_door,y_door);
}
void rooms::Clubroom()
{
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
}
 void rooms::Music_Room()
 {
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop(){
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice()
 {
    string file_path = "..";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 string rooms::Rooftop_Stairs(int a,int b)
 {
    string file_path = "..";
    int x_door = a;
    int y_door = b;
    int C_Or_R = main_engine(file_path,x_door,y_door);
    return roomchooser(C_Or_R);
   
 }

 string rooms::SchoolMap(int a,int b)
 {
    string file_path = "..";
    int x_door = a;
    int y_door = b;
    int roomdecider = main_engine(file_path,x_door,y_door);
    return roomchooser(roomdecider);
 }

 string rooms::roomchooser(int roomdecider){
    switch (roomdecider)
    {
    case 1:
        return "Classroom";
        break;
    case 2:
        return "Clubroom";
        break;
    case 3:
        return "Music_room";
        break;
    case 4:
        return "TeachersOffice";
        break;
    case 5:      
        return "RoofTop";
        break;
    case 6:
        return "Rooftop_Stairs";
        break;
    case 7:
        return "ToCorridor";
        break;   
    default:
        break;
    }
 }
