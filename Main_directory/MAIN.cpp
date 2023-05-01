#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "/workspaces/Initial/CharactersDesign_Mechanism/doorcoordinate.h"
#include "/workspaces/Initial/CharactersDesign_Mechanism/MainEngine.h"
using namespace std;

class rooms
{
public:
    void ClassRoom();
    void ClubRoom();
    void MusicRoom();
    void DiningRoom();
    void RestRoom();
    void TeachersOffice();
    void RoofTop();
    string SchoolMap(int,int);
    string RoofTopStairs(int,int);
    string roomchooser(int);
};

int main()
{
    initialize();
    int a;
    int b;
    int *x = &a;
    int *y = &b;
    int counter = 0;
    string previous;
    string exitfrom;
    string entered;
    rooms RM;
    bool flag = true;
     while (flag)
    {
        if (counter == 0)
        {
            *x = 43, *y = 14;
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
            main_engine(file_path,*x,*y);
            entered="SchoolMap";
            *x = Corridor["ClassRoom"].x_coordinates;
            *y = Corridor["ClassRoom"].y_coordinates;
            counter++;
        }

        if (entered == "ClassRoom")
        {
            RM.ClassRoom();
            exitfrom = "ClassRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "ClubRoom")
        {
            RM.ClubRoom();
            exitfrom = "ClubRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "MusicRoom")
        {
            RM.MusicRoom();
            exitfrom = "MusicRoom";
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
        else if (entered == "DiningRoom")
        {
            RM.DiningRoom();
            exitfrom = "DiningRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
         else if (entered == "RestRoom")
        {
            RM.RestRoom();
            exitfrom = "RestRoom";
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
            previous = "ToRoofTop";
            entered = "RoofTopStairs";
        }
        else if (entered == "RoofTopStairs")
        {
            *x = Stairs[previous].x_coordinates;
            *y = Stairs[previous].y_coordinates;
            exitfrom = RM.RoofTopStairs(*x,*y);
            *x = Stairs[exitfrom].x_coordinates;
            *y = Stairs[exitfrom].y_coordinates;
            if (exitfrom == "ToCorridor")
            {
                entered = "SchoolMap";
            }
            else if (exitfrom == "ToRoofTop")
            {
                entered = "RoofTop";
            }
        }
        else if (entered == "SchoolMap")
        {
            previous = "ToCorridor";
            entered = RM.SchoolMap(*x,*y);
        }
    }

}
//coordinates inside each room (point on feet)
void rooms::ClassRoom()
{
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
    int x_door = 88;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
}
void rooms::ClubRoom()
{   
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt"; 
    int x_door = 86;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
}

 void rooms::MusicRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt";
    int x_door = 79;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Rooftop.txt";
    int x_door = 49;
    int y_door = 23;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt";
    int x_door = 86;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RestRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt";
    int x_door = 86;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);

 }

void rooms::DiningRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt";
    int x_door = 64;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
 }

 string rooms::RoofTopStairs(int a,int b)
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Rooftop stairs.txt";
    int x_door = a;
    int y_door = b;
    int C_Or_R = main_engine(file_path,x_door,y_door);
    return roomchooser(C_Or_R);
 }

 string rooms::SchoolMap(int a,int b)
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt";
    int x_door = a;
    int y_door = b;
    int roomdecider = main_engine(file_path,x_door,y_door);
    return roomchooser(roomdecider);
 }

 string rooms::roomchooser(int roomdecider){
    switch (roomdecider)
    {
    case 1:
        return "ClassRoom";
        break;
    case 2:
        return "RestRoom";
        break;
    case 3:
        return "ClubRoom";
        break;
    case 4:
        return "TeachersOffice";
        break;
    case 5:      
        return "MusicRoom";
        break;
    case 6:
        return "DiningRoom";
        break;
    case 7:
        return "RoofTopStairs";
        break;
    case 8:
        return "RoofTop";
        break;
    case 9:
        return "ToCorridor";
        break;
    case 10:
        return "ToRoofTop";       
    default:
        return "NONE";
        break;
    }
}
