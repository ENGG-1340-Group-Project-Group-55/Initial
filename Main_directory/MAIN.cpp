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
    int *x = new int;
    int *y = new int;
    int counter = 0;
    string exitfrom;
    string entered;
    rooms RM;
    bool flag = true;   
    
     while (flag)
    {
        initialize();
        if (counter == 0)
        {
            *x = 20, *y = 20;
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
            main_engine(file_path,*x,*y);
            entered="SchoolMap";
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
            entered = "SchoolMap";
        }
        else if (entered == "RoofTopStairs")
        {
            exitfrom = RM.RoofTopStairs(*x,*y);
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
        clears();
    }

    delete x;
    delete y;
}

void rooms::ClassRoom()
{
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
    int x_door = 91;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
}
void rooms::ClubRoom()
{   
<<<<<<< HEAD
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt"; }
=======
    string file_path;
    char randroom1 = 'C';
    char randroom2 = 'C';
    int randnum = 1;
    if (randroom1 == 'C' || randroom2 == 'C') {
        if (randnum == 1) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 1.txt";
        }
        
        if (randnum == 2) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 2.txt";
        }

        if (randnum == 3) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 3.txt";
        }

        if (randnum == 4) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 4.txt";
        }

        if (randnum == 5) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 5.txt";
        }

        if (randnum == 6) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 6.txt";
        }
    }
    else {
        string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt"; }
>>>>>>> 883a9f2 (.)
    int x_door = 90;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
}

 void rooms::MusicRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt";
    int x_door = 83;
    int y_door = 12;
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
    int x_door = 89;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RestRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt";
    int x_door = 90;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);

 }

void rooms::DiningRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt";
    int x_door = 68;
    int y_door = 12;
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
    default:
        return "NONE";
        break;
    }
}
