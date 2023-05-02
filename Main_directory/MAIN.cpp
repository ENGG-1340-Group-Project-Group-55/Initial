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


// Seed the random number generator with the current time
mt19937 rng(time(nullptr));

// Define an array of letters to choose from
char letters[] = {'M', 'T', 'D', 'C', 'R'};

// Get the size of the array
int numLetters = sizeof(letters) / sizeof(letters[0]);

// Generate a random index into the array
uniform_int_distribution<int> indexDist(0, numLetters - 1);
int randIndex = indexDist(rng);

// Get the random room from the array
char randroom = letters[randIndex];

// seed the random number generator
random_device rd;
mt19937 gen(rd());

// define the range of values
uniform_int_distribution<int> valueDist(1, 6);

// generate a random number
<<<<<<< HEAD
int randnum = dist(gen);
std::string str_randnum = std::to_string(randnum);
=======
int randnum = valueDist(gen);

>>>>>>> 140fdb5 (random room)


int main()
{
    initialize();
    int a;
    int b;
    int *x = &a;
    int *y = &b;
    int counter = 0;
    string exitto;
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
            previous = "ToRoofTop";
            entered = "RoofTopStairs";
        }
        else if (entered == "RoofTopStairs")
        {
            *x = Stairs[previous].x_coordinates;
            *y = Stairs[previous].y_coordinates;
            exitto = RM.RoofTopStairs(*x,*y);
            if (exitto == "NONE")
            {
                *x = Corridor["RoofTopStairs"].x_coordinates;
                *y = Corridor["RoofTopStairs"].y_coordinates;
                entered = "SchoolMap";
            }
            else if (exitto == "RoofTop")
            {
                *x = Stairs["RoofTop"].x_coordinates;
                *y = Stairs["RoofTop"].y_coordinates;
                entered = exitto;
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
    int x_door = 87;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
}
void rooms::ClubRoom()
{   
    string file_path;
    if (randroom != 'C') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt";
    }

    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);
    int x_door = 20;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
}

 void rooms::MusicRoom()
 {  
    string file_path;
    if (randroom != 'M') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt"; 
    }
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);
    int x_door = 79;
    int y_door = 5;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RoofTop()
 {
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Rooftop.txt";
    int x_door = 44;
    int y_door = 20;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::TeachersOffice()
 {
<<<<<<< HEAD
<<<<<<< HEAD
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);

    string file_path;
    if (randroom != 'T') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt"; 
    }
=======
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);
>>>>>>> 7c34aae (auto random map)
>>>>>>> parent of b3a3cd9 (ver)
=======
    string file_path;
    if (randroom != 'T') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt"; 
    }
=======
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);
>>>>>>> 7c34aae (auto random map)
>>>>>>> 2f2a186 (ver)
    
    int x_door = 86;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);
 }

 void rooms::RestRoom()
 {
<<<<<<< HEAD
    string file_path;
    if (randroom != 'R') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt"; 
    }
=======
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7c34aae (auto random map)
>>>>>>> parent of b3a3cd9 (ver)
=======
>>>>>>> 7c34aae (auto random map)
>>>>>>> 2f2a186 (ver)
    
    int x_door = 86;
    int y_door = 29;
    main_engine(file_path,x_door,y_door);

 }

void rooms::DiningRoom()
 {
<<<<<<< HEAD
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
>>>>>>> 2f2a186 (ver)
    string file_path;
    if (randroom != 'D') {
        
        if (randnum == 1) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 1.txt"; 
        }

        else if (randnum == 2) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 2.txt"; 
        }

        else if (randnum == 3) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 3.txt"; 
        }

        else if (randnum == 4) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 4.txt"; 
        }

        else if (randnum == 5) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 5.txt"; 
        }

        else if (randnum == 6) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 6.txt"; 
        }
    }
    else {
        file_path = "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt"; 
    }
    
=======
<<<<<<< HEAD
>>>>>>> parent of b3a3cd9 (ver)
=======
>>>>>>> 2f2a186 (ver)
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Dining Room .txt";
    int file_length = file_path.length();
    file_path.insert(file_length - 4, str_randnum);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 7c34aae (auto random map)
>>>>>>> parent of b3a3cd9 (ver)
=======
>>>>>>> 7c34aae (auto random map)
>>>>>>> 2f2a186 (ver)
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
        return "RoofTop";
        break;
    case 8:
        return "RoofTopStairs";
        break;
    default:
        return "NONE";
        break;
    }
}
