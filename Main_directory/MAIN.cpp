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
    void ClassRoom(char,char,int);
    void ClubRoom(char,char,int);
    void MusicRoom(char,char,int);
    void DiningRoom(char,char,int);
    void RestRoom(char,char,int);
    void TeachersOffice(char,char,int);
    void RoofTop();
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
    
    // Seed the random number generator with the current time
    srand(time(nullptr));

    char letters[] = {'M', 'T', 'D', 'C', 'R'};

    int numLetters = sizeof(letters) / sizeof(letters[0]);

    // Generate the first random index into the array
    int randIndex1 = rand() % numLetters;

    // Get the first random letter from the array
    char randroom1 = letters[randIndex1];

    // Generate the second random index into the array
    int randIndex2;

    // Keep generating a new random index for randIndex2 until it is different from randIndex1
    do {
        randIndex2 = rand() % numLetters;
    } while (randIndex2 == randIndex1);

    // Get the second random letter from the array
    char randroom2 = letters[randIndex2];


    // seed the random number generator
    random_device rd;
    mt19937 gen(rd());

    // define the range of values
    uniform_int_distribution<int> dist(1, 6);

    // generate a random number
    int randnum = dist(gen);
          
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
            RM.ClassRoom(randroom1,randroom2,randnum);
            exitfrom = "ClassRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "ClubRoom")
        {
            RM.ClubRoom(randroom1,randroom2,randrum);
            exitfrom = "ClubRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "Music_Room")
        {
            RM.MusicRoom(randroom1,randroom2,randnum);
            exitfrom = "MusicRoom";
            *x = Corridor[exitfrom].x_coordinates;
            *y = Corridor[exitfrom].y_coordinates;
            entered = "SchoolMap";
        }
        else if (entered == "TeachersOffice")
        {
            RM.TeachersOffice(randroom1,randroom2,randnum);
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
            RM.RestRoom(randroom1,randroom2,randnum);
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
    }

    delete x;
    delete y;
}

void rooms::ClassRoom()
{
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
    int x_door = 87;
    int y_door = 24;
    main_engine(file_path,x_door,y_door);
}
void rooms::ClubRoom(char randroom1,char randroom2,int randnum)
{
    if ((randroom1 == "C") || (randroom2 == "C")) {
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
    int x_door = 28;
    int y_door = 28;
    main_engine(file_path,x_door,y_door);
}

 void rooms::MusicRoom(char randroom1,char randroom2,int randnum)
 {
    
     if ((randroom1 == "M") || (randroom2 == "M")) {
        if (randnum == 1) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 1.txt";
        }
        
        if (randnum == 2) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 2.txt";
        }

        if (randnum == 3) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 3.txt";
        }

        if (randnum == 4) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 4.txt";
        }

        if (randnum == 5) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 5.txt";
        }

        if (randnum == 6) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 6.txt";
        }

    }
     
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Rooftop.txt";
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice(char randroom1,char randroom2,int randnum)
 {
    if ((randroom1 == "T") || (randroom2 == "T")) {
        if (randnum == 1) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 1.txt";
        }
        
        if (randnum == 2) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 2.txt";
        }

        if (randnum == 3) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 3.txt";
        }

        if (randnum == 4) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 4.txt";
        }

        if (randnum == 5) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 5.txt";
        }

        if (randnum == 6) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 6.txt";
        }

    }
    int x_door = 79;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RestRoom(char randroom1, char randroom2,int randnum)
 {
    if ((randroom1 == "R") || (randroom2 == "R")) {
        if (randnum == 1) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 1.txt";
        }
        
        if (randnum == 2) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 2.txt";
        }

        if (randnum == 3) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 3.txt";
        }

        if (randnum == 4) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 4.txt";
        }

        if (randnum == 5) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 5.txt";
        }

        if (randnum == 6) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 6.txt";
        }
    }
    int x_door = 0;
    int y_door = 0;
    main_engine(file_path,x_door,y_door);
 }

void rooms::DiningRoom(char randroom1,char randroom2,int randnum)
 {
    if ((randroom1 == "R") || (randroom2 == "R")) {
        if (randnum == 1) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 1.txt";
        }
        
        if (randnum == 2) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 2.txt";
        }

        if (randnum == 3) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 3.txt";
        }

        if (randnum == 4) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 4.txt";
        }

        if (randnum == 5) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 5.txt";
        }

        if (randnum == 6) {
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 6.txt";
        }
    }
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
        return "RestRoom";
        break;
    case 3:
        return "Clubroom";
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
