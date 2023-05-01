#include <iostream>
#include <string>
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
    void RoofTop();
    void TeachersOffice();
    string SchoolMap(int,int);
    string RoofTopStairs(int,int);
    string roomchooser(int);
};

int main()
{
    initialize();
    int *x = new int;
    int *y = new int;
    int counter = 0;
    string exitfrom;
    string entered;
    rooms RM;
    bool flag = true;
          
     while (flag)
    {
        if (counter == 0)
        {
            *x = 20, *y = 20;
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt";
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
            RM.Clubroom();
            exitfrom = "Clubroom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "Music_Room")
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

    delete x;
    delete y;
} 

void rooms::Classroom()
{
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
    int x_door = 87;
    int y_door = 24;
    main_engine(file_path,x_door,y_door);
}
void rooms::Clubroom()
{
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt";
    int x_door = 28;
    int y_door = 28;
    main_engine(file_path,x_door,y_door);
}
 void rooms::MusicRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt";
    int x_door = 82;
    int y_door = 10;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt";
    int x_door = 79;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RestRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

void rooms::DiningRoom()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt";
    int x_door = 0;
    int y_door = 0;
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
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/School map.txt";
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
        return "MusicRoom";
        break;
    case 4:
        return "TeachersOffice";
        break;
    case 5:      
        return "RoofTop";
        break;
    case 6:
        return "DiningRoom";
        break;
    case 7:
        return "RestRoom";
        break;
    case 8:
        return "RoofTopStairs";
        break;
    case 9:
        return "ToCorridor";
        break;   
    default:
        return "NONE";
        break;
    }
}
