#include <ncurses.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
#include "/workspaces/Initial/CharactersDesign_Mechanism/MapLoader.h"

//compile using: g++ -pedantic-errors -std=c++11 CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp -o game -lncurses

int VISION_RADIUS;
int point;
int VISION_RADIUS_INCREASE = 0;

int restflag = 0;
int teacherflag = 0;
int musicflag = 0;
int diningflag = 0;
int clubflag = 0;

// Function to update the timer and VISION_RADIUS
int updateTimerAndVisionRadius(int countdown_duration) {
    time_t current_time = time(NULL);
    time_t start_time;

    // Read start_time from the text file
    std::ifstream in_file("start_time.txt");
    if (in_file) {
        in_file >> start_time;
        in_file.close();
    } else {
        return -1;
    }

    int remaining_time = countdown_duration - static_cast<int>(difftime(current_time, start_time));
    VISION_RADIUS = 20 - (100 * (1 - static_cast<double>(remaining_time) / countdown_duration));

    // Increase the VISION_RADIUS by the global variable value
    VISION_RADIUS += VISION_RADIUS_INCREASE;

    if (VISION_RADIUS < 5) {
        VISION_RADIUS = 5;
    }
    return remaining_time;
}

// Function to create a centered window with a box border
WINDOW* CreateWindow(int screen_height, int screen_width) {
    int startY = (LINES - screen_height) / 2;
    int startX = (COLS - screen_width) / 2;
    WINDOW* win = newwin(screen_height, screen_width, startY, startX);
    refresh();
    wrefresh(win);
    return win;
}

void printInventory(vector<string> inventory);
vector<string> loadInventoryFromFile();

void printChatboxIntro(vector<string> chatboxintro);
vector<string> loadChatboxIntroFromFile();

void printHelicopter();
vector<string> loadHelicopterFromFile();

void ToInventory(string object);

void printMenu(vector<string> menu, int remaining_time);

int intro = 1;
int main_engine(string file_path, int&x, int& y) {
// Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK); // Pair 1: Red text on a black background
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // Pair 2: Green text on a black background
    init_pair(3, COLOR_BLUE, COLOR_BLACK); // Pair 3: Blue text on a black background
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Pair 4: Yellow text on a black background


    if (intro == 1) {
        vector<string> chatboxintro = loadChatboxIntroFromFile();
        printChatboxIntro(chatboxintro);
        intro = 0;
    }


    // Initialize the timer
    int countdown_duration = 900; // Set this to the desired countdown duration (15 minutes)


    //Set up initial variables
    char ch;
    bool flag = true;

    //count dimensions of a map
    int screen_height=0;
    int screen_width=0;
    ifstream inputline;
    inputline.open(file_path);
    if (inputline.fail()) {
        cout<<"no file for map"<<endl;
        exit(1);
    }
    while (inputline >> noskipws >> ch) {
        if (ch != '\n') {
            if (flag) {
                screen_width++;
            }
        } else {
            screen_height++;
            flag=FALSE;
        }
    }
    inputline.close();

    WINDOW *game_window = CreateWindow(screen_height, screen_width);

    //store character into arrays
    ifstream charline("/workspaces/Initial/CharactersDesign_Mechanism/Character_Ghosts.resources/character3.txt");
    if (charline.fail()) {
        cout<<"no character file!"<<endl;
        exit(1);
    }
    int const charsize = 5;
    string char_left[charsize], char_right[charsize], char_down[charsize], char_up[charsize];
    string line;
    int ii = 0;
    while (getline(charline, line)) {
        if (ii < charsize) {
            char_left[ii] = line;
        } else if (ii < charsize*2) {
            char_right[ii%charsize] = line;
        } else if (ii < charsize*3) {
            char_down[ii%charsize] = line;
        } else {
            char_up[ii%charsize] = line;
        }
        ii++;
    }
    charline.close();

    string *current_character = char_up;
    
    // Draw the map
    Maps gameMap(screen_height, screen_width);
    VectorWrapper mapData = gameMap.Map_Loader(file_path);
    //gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width, game_window);

    

// Main loop ...............................................................................
    
    int key_input;
    while ((key_input = wgetch(game_window)) != 'q') { // Exit on 'q' key press
        // Clear window
        //werase(game_window);
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;

        int restcount = 0;
        int teachercount = 0;
        int musiccount = 0;
        int diningcount = 0;
        int clubcount = 0;
        
        if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 6.txt") {
            restcount++;
        } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 6.txt") {
            teachercount++;
        } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 6.txt") {
            musiccount++;
        } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 6.txt") {
            diningcount++;
        } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 6.txt") {
            clubcount++;
        }

        if (restflag == 1 && restcount > 0) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt";
        }
        if (teacherflag == 1 && teachercount > 0) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt";
        }
        if (musicflag == 1 && musiccount > 0) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt";
        }
        if (diningcount == 1 && diningcount > 0) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt";
        }
        if (clubcount == 1 && clubcount > 0) {
            file_path = "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt";
        }
        
        int y4 = y+4;
        int x4 = x+4;

        // Darken the entire screen
        wattron(game_window, COLOR_PAIR(4)); // Set color pair 4 (yellow on black)
        for (int i = 0; i < screen_height; i++) {
            for (int j = 0; j < screen_width; j++) {
                mvwaddch(game_window, i, j, ' ');
            }
        }
        wattroff(game_window, COLOR_PAIR(4)); // Unset color pair 4

        // Render the map within the circular vision radius
        for (int i = y - VISION_RADIUS; i <= y + VISION_RADIUS; i++) {
            for (int j = x - 2 * VISION_RADIUS; j <= x + 2 * VISION_RADIUS; j++) {
                int dist_y = i - y;
                int dist_x = (j - x) / 2; // Divide by 2 to adjust for character width
                double euclidean_distance = sqrt(dist_y * dist_y + dist_x * dist_x);
                if (i >= 0 && i < screen_height && j >= 0 && j < screen_width && euclidean_distance <= VISION_RADIUS) {
                    mvwaddch(game_window, i, j, mapData.TDVEC[i][j]);
                }
            }
        }

        if (intro == 1) {
            vector<string> chatboxintro = loadChatboxIntroFromFile();
            printChatboxIntro(chatboxintro);
            intro = 0;
        }
    
        if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop6.txt") {
            
        }

        switch(key_input) {
            case 'w':
                y--;
                current_character = char_up;
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt") {
                    if (y4 == 13) {
                        if (x4 >= 19 && x4 <= 24) {
                            delwin(game_window);
                            clear();
                            return 1;
                        } else if (x4 >= 36 && x4 <= 41) {
                            delwin(game_window);
                            clear();
                            return 2;
                        } else if (x4 >= 74 && x4 <= 79) {
                            delwin(game_window);
                            clear();
                            return 4;
                        } else if (x4 >= 99 && x4 <= 112) {
                            delwin(game_window);
                            clear();
                            return 8;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Music Room 6.txt") {
                    if (y4 == 10) {
                        if (x4>=80 && x4<=85) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Diningroom.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Dining Room 6.txt") {
                    if (y4 == 10) {
                        if (x4>=65 && x4<=70) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Club Room 6.txt") {
                    if (y4 == 10) {
                        if (x4>=21 && x4<=26) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop stairs.txt") {
                    if (y4 == 12 || y4 == 11) {
                        if (x4>=44 && x4<=53) {
                            if (point != 4) {
                                int chatbox_height = 7;
                                int chatbox_width = 80;

                                initscr();
                                raw();
                                noecho();
                                curs_set(0);
                                keypad(stdscr, TRUE);

                                WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
                                box(chatboxWin, 0, 0);
                                wrefresh(chatboxWin);

                                string filePath = "/workspaces/Initial/UI/chatboxintro/chatboxneed.txt";
                                ifstream inputFile(filePath);
                                string line;

                                while (getline(inputFile, line)) {
                                    mvwprintw(chatboxWin, 3, 6, "%s", line.c_str());
                                    wrefresh(chatboxWin);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }

                                delwin(chatboxWin); // delete window after displaying the file
                                inputFile.close();}

                            else if (point == 4) {
                                    VISION_RADIUS_INCREASE += 100;
                            delwin(game_window);
                            clear();
                            vector<string> helicopter = loadHelicopterFromFile();
                            printHelicopter();
                            return 7;
                                }
                        }
                    }
                }

                for (int i=1; i<5; i++) {
                    if (mapData.TDVEC[y+4][x+i] != ' '){
                        y++;
                        break;
                    }
                }
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop stairs.txt") {
                    for (int i=1; i<5; i++) {
                        if (mapData.TDVEC[y+3][x+i] == '_') {
                            y--;
                        }
                    }
                }
                break;

            case 's':
                y++;
                current_character = char_down;
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt") {
                    if (y4 == 20) {
                        if (x4>= 26 && x4<= 31) {
                            delwin(game_window);
                            clear();
                            return 5;
                        } else if (x4 >= 43 && x4 <= 48) {
                            delwin(game_window);
                            clear();
                            return 6;
                        } else if (x4 >= 92 && x4 <= 97) {
                            delwin(game_window);
                            clear();
                            return 3;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt") {
                    if (y4 == 28) {
                        if (x4>=88 && x4<=93) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Restroom 6.txt" ) {
                    if (y4 == 28) {
                        if (x4>=87 && x4<=92) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                 } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 1.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 2.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 3.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 4.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 5.txt" || file_path == "/workspaces/Initial/Map_Objects/Map_resources/Teacher's office 6.txt") {
                    if (y4 == 28) {
                        if (x4>=87 && x4<=92) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop stairs.txt") {
                    if (y4 == 26 || y4 == 27) {
                        if (x4>=40 && x4<=60) {
                            delwin(game_window);
                            clear();
                            return 0;
                        }
                    }
                } 
                // else if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop.txt") {
                //     if (y4 == 23) {
                //         if (x4>=45 && x4<=50) {
                //             delwin(game_window);
                //             clear();
                //             return 8;
                //         }
                //     }
                // }
                for (int i=1; i<5; i++) {
                    if (mapData.TDVEC[y+4][x+i] != ' '){
                        y--;
                        break;
                    }
                }
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/Rooftop stairs.txt") {
                    for (int i=1; i<5; i++) {
                        if (mapData.TDVEC[y+5][x+i] == '_') {
                            y++;
                        }
                    }
                }
                break;

            case 'a':
                x-=2;
                current_character = char_left;
                if (mapData.TDVEC[y+4][x+1] != ' '|| mapData.TDVEC[y+4][x+2] != ' ') {
                    x+=2;
                }
                break;

            case 'd':
                x+=2;
                current_character = char_right;
                if (mapData.TDVEC[y+4][x+4] != ' ' || mapData.TDVEC[y+4][x+3] != ' ') {
                    x-=2;
                }
                break;
            
            // case 'f':
            //     for (int i = 0; i < charsize+2; i++) {
            //         for (int j = 0; j < current_character[i].length()+2; j++) {
            //             if (mapData.TDVEC[i+y][j+x] == '*') {
            //                 flag1 = true;
            //                 break;
            //             }
            //         }
            //     }
            //     break;

            case 'i':
                flag1 = true;
                break;

            case 27:
                flag2 = true;
                break;

            case '0':
                flag3 = true;
                break;

            case 'f':
                for (int i = 0; i < charsize+2; i++) {
                    for (int j = 0; j < current_character[i].length()+2; j++) {
                        if (mapData.TDVEC[i+y][j+x] == '*') {
                            point += 1;
                            if (point == 1) {
                                int chatbox_height = 7;
                                int chatbox_width = 80;
                                string object;


                                initscr();
                                raw();
                                noecho();
                                curs_set(0);
                                keypad(stdscr, TRUE);

                                WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
                                box(chatboxWin, 0, 0);
                                wrefresh(chatboxWin);

                                string filePath = "/workspaces/Initial/UI/chatboxintro/chatboxfound1.txt";
                                ifstream inputFile(filePath);
                                string line;

                                while (getline(inputFile, line)) {
                                    mvwprintw(chatboxWin, 3, 6, "%s", line.c_str());
                                    wrefresh(chatboxWin);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }

                                delwin(chatboxWin); // delete window after displaying the file
                                inputFile.close();

                                object = "Key \n";
                                ToInventory(object);}

                            if (point == 2) {
                                VISION_RADIUS_INCREASE += 10;
                                int chatbox_height = 7;
                                int chatbox_width = 80;
                                string object;


                                initscr();
                                raw();
                                noecho();
                                curs_set(0);
                                keypad(stdscr, TRUE);

                                WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
                                box(chatboxWin, 0, 0);
                                wrefresh(chatboxWin);

                                string filePath = "/workspaces/Initial/UI/chatboxintro/chatboxfound2.txt";
                                ifstream inputFile(filePath);
                                string line;

                                while (getline(inputFile, line)) {
                                    mvwprintw(chatboxWin, 3, 6, "%s", line.c_str());
                                    wrefresh(chatboxWin);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }

                                delwin(chatboxWin); // delete window after displaying the file
                                inputFile.close();
                                


                                object = "Battery \n";
                                ToInventory(object); }

                            if (point == 3) {
                                //printing out ghosts
                                int chatbox_height = 20;
                                int chatbox_width = 20;
                                string object;


                                initscr();
                                raw();
                                noecho();
                                curs_set(0);
                                keypad(stdscr, TRUE);

                                WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
                                box(chatboxWin, 0, 0);
                                wrefresh(chatboxWin);

                                string filePath = "/workspaces/Initial/CharactersDesign_Mechanism/Character_Ghosts.resources/ghostfinal.txt";
                                ifstream inputFile(filePath);
                                string line;

                                while (getline(inputFile, line)) {
                                    mvwprintw(chatboxWin, 1, 1, "%s", line.c_str());
                                    wrefresh(chatboxWin);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }
                                
                                delwin(chatboxWin); // delete window after displaying the file
                                inputFile.close();
                                
                                chatbox_height = 7;
                                chatbox_width = 80;

                                WINDOW* chatboxWin2 = CreateWindow(chatbox_height, chatbox_width); // create new window for the second chatbox
                                box(chatboxWin2, 0, 0);
                                wrefresh(chatboxWin2);

                                filePath = "/workspaces/Initial/UI/chatboxintro/chatboxfound3.txt";
                                ifstream inputFile2(filePath);
                                line;

                                while (getline(inputFile2, line)) {
                                    mvwprintw(chatboxWin2, 3, 6, "%s", line.c_str());
                                    wrefresh(chatboxWin2);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }

                                delwin(chatboxWin2); // delete window after displaying the file
                                inputFile2.close();

                                object = "Ghost Poster \n";
                                ToInventory(object); }

                            if (point == 4) {
                                int chatbox_height = 7;
                                int chatbox_width = 80;
                                string object;
                                object = "Key \n";
                                ToInventory(object);
                                std::ofstream outfile("/workspaces/Initial/UI/inventory.txt", std::ios::out | std::ios::trunc);
                                outfile.close();

                                initscr();
                                raw();
                                noecho();
                                curs_set(0);
                                keypad(stdscr, TRUE);

                                WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
                                box(chatboxWin, 0, 0);
                                wrefresh(chatboxWin);

                                string filePath = "/workspaces/Initial/UI/chatboxintro/chatboxfound1.txt";
                                ifstream inputFile(filePath);
                                string line;

                                while (getline(inputFile, line)) {
                                    mvwprintw(chatboxWin, 3, 6, "%s", line.c_str());
                                    wrefresh(chatboxWin);
                                    int ch = getch();
                                    if (ch == 10) { // Enter key
                                        break;
                                    }
                                }

                                delwin(chatboxWin); // delete window after displaying the file
                                inputFile.close();}                             

                                
                            
                            break;
                        }
                    }
                }
                break;

        }

        // Keep character within screen boundaries
        if (x < 1) {
            x = 1;
        } if (y < 3) {
            y = 2;
        } if (x >= screen_width - 5) {
            x = screen_width - 6;
        } if (y >= screen_height - 5) {
            y = screen_height - 6;
        }

        // Draw the player character
        for (int i = 0; i < charsize; i++) {
            for (int j = 0; j < current_character[i].length(); j++) {
                if (current_character[i][j] != '~') {
                    mvwaddch(game_window, y+i, x+j, current_character[i][j]);
                }
            }
        }
        //mvwaddch(game_window, y, x, 'O');

        int remaining_time = updateTimerAndVisionRadius(countdown_duration);

        if (flag1 == true) {
            vector<string> inventory = loadInventoryFromFile();
            printInventory(inventory);
            wrefresh(game_window);
        }
        if (flag2 == true) {
            vector<string> menu;
            printMenu(menu, remaining_time);
            wrefresh(game_window);
        }
        if (flag3 == true) {
            wrefresh(game_window);
        } else {
            wrefresh(game_window);
        }
    }
    //main loop end ////////////////////////////////////////////////////////////////////////////////////////////

// End ncurses mode
    delwin(game_window);
    clear();
    endwin();
    return 0;
}

vector<string> loadChatboxIntroFromFile() {
    vector<string> chatboxintro;
    string folderPath = "/workspaces/Initial/UI/chatboxintro/";

    for (string fileName : {"chatboxintro1.txt", "chatboxintro2.txt", "chatboxintro3.txt", "chatboxintro4.txt", "chatboxintro5.txt", "chatboxintro6.txt", "chatboxintro7.txt"}) {
        string filePath = folderPath + fileName;
        ifstream inputFile(filePath); // Open the file for reading
        string line;

        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                chatboxintro.push_back(line); // Read and store the lines from the file
            }
            inputFile.close(); // Close the file
        } else {
            cout << "No " << fileName << " file." << endl;
        }
    }

    return chatboxintro;
}

void printChatboxIntro(vector<string> chatboxintro) {
    int chatbox_height = 7;
    int chatbox_width = 80;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    int currentFileIndex = 1;
    while (currentFileIndex <= chatboxintro.size()) {
        WINDOW* chatboxWin = CreateWindow(chatbox_height, chatbox_width); // create window for each file
        box(chatboxWin, 0, 0);
        wrefresh(chatboxWin);

        string filePath = "/workspaces/Initial/UI/chatboxintro/chatboxintro" + to_string(currentFileIndex) + ".txt";
        ifstream inputFile(filePath);
        string line;

        while (getline(inputFile, line)) {
            for (int i = 0; i < line.length(); i++) {
                mvwprintw(chatboxWin, 3, 6+i, "%c", line[i]);
                wrefresh(chatboxWin);
                this_thread::sleep_for(chrono::milliseconds(30)); }
            int ch = getch();
            if (ch == 10) { // Enter key
                break;
            }
        }

        delwin(chatboxWin); // delete window after displaying the file
        inputFile.close();
        currentFileIndex++;

        if (currentFileIndex % chatbox_height == 0) {
            // Wait for the user to press enter before displaying the next set of messages
            while (true) {
                int ch = getch();
                if (ch == 10) { // Enter key
                    break;
                }
            }
        }
    }
    endwin();
}


vector<string> loadHelicopterFromFile() {
    vector<string> helicopter;
    string folderPath = "/workspaces/Initial/Map_Objects/Map_resources/";

    for (string fileName : {"Rooftop2.txt", "Rooftop3.txt", "Rooftop4.txt", "Rooftop5.txt", "Rooftop6.txt"}) {
        string filePath = folderPath + fileName;
        ifstream inputFile(filePath); // Open the file for reading
        string line;

        if (inputFile.is_open()) {
            while (getline(inputFile, line)) {
                helicopter.push_back(line); // Read and store the lines from the file
            }
            inputFile.close(); // Close the file
        } else {
            cout << "No " << fileName << " file." << endl;
        }
    }

    return helicopter;
}

void printHelicopter() {
    vector<string> fileNames = {"Rooftop2.txt", "Rooftop3.txt", "Rooftop4.txt", "Rooftop5.txt", "Rooftop6.txt"};
    int currentFileIndex = 0;

    Maps mp(25, 95);

    initscr();
    clear();
    refresh();
    curs_set(0);
    noecho();

    int screen_rows, screen_cols;
    getmaxyx(stdscr, screen_rows, screen_cols);

    int row_offset = (screen_rows - 25) / 2;
    int col_offset = (screen_cols - 95) / 2;

    while (currentFileIndex < fileNames.size()) {
        string fileName = fileNames[currentFileIndex];
        string filep = "/workspaces/Initial/Map_Objects/Map_resources/" + fileName;
        VectorWrapper start = mp.Map_Loader(filep);

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 95; j++) {
                mvprintw(row_offset + i, col_offset + j, "%c", start.TDVEC[i][j]);
            }
        }

        refresh();
        getch(); // Wait for user input
        currentFileIndex++;
        clear();
        refresh();
    }

    endwin();
}


void ToInventory(string object) {
    string fp = "/workspaces/Initial/UI/inventory.txt";
    ofstream outputFile(fp, ios::app);
    if (outputFile.is_open()) {
        outputFile << object;
        outputFile.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

vector<string> loadInventoryFromFile() {
    vector<string> inventory;
    ifstream inputFile("/workspaces/Initial/UI/inventory.txt"); // Open the file for reading
    string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            inventory.push_back(line); // Read and store the items from the file
        }
        inputFile.close(); // Close the file
    } 
    else {
        cout << "No inventory file." << endl;
    }
    return inventory;
}

void printInventory(vector<string> inventory) {
    int inv_height = 15;
    int inv_width = 30;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* inventoryWin = CreateWindow(inv_height, inv_width);
    box(inventoryWin, 0, 0);
    mvwprintw(inventoryWin, 1, 1, "Inventory:");
    for (int i = 0; i < inventory.size(); i++) {
        mvwprintw(inventoryWin, i + 2, 1, "%d. %s", i + 1, inventory[i].c_str());
    }
    wrefresh(inventoryWin);

    //screen displayed until 'q' is pressed
    while (true) {              // consider while ((key_input = getch()) != 27) {
        int ch = getch();
        if (ch == 27) {
            break;
        }
    }
    delwin(inventoryWin);
}

void printMenu(vector<string> menu, int remaining_time) {
    // ...
    int menu_height = 20;
    int menu_width = 50;


    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* menuWin = CreateWindow(menu_height, menu_width);
    box(menuWin, 0, 0);
    mvwprintw(menuWin, 1, 1, "    .___  ___.  _______ .__   __.  __    __ ");
    mvwprintw(menuWin, 2, 1, "    |   \\/   | |   ____||  \\ |  | |  |  |  |");
    mvwprintw(menuWin, 3, 1, "    |  \\  /  | |  |__   |   \\|  | |  |  |  |");
    mvwprintw(menuWin, 4, 1, "    |  |\\/|  | |   __|  |  . `  | |  |  |  |");
    mvwprintw(menuWin, 5, 1, "    |  |  |  | |  |____ |  |\\   | |  `--'  |");
    mvwprintw(menuWin, 6, 1, "    |__|  |__| |_______||__| \\__|  \\______/");
    mvwprintw(menuWin, 7, 1, "    ");
    mvwprintw(menuWin, 8, 1, "    ");
    mvwprintw(menuWin, 9, 1, "              _     ___           ");
    mvwprintw(menuWin, 10, 1, "            / |   / __| __ ___ _____");
    mvwprintw(menuWin, 11, 1, "            | |_  \\__ \\/ _` \\ V / -_)");
    mvwprintw(menuWin, 12, 1, "            |_(_) |___/\\__,_|\\_/\\___|");
    mvwprintw(menuWin, 13, 1, "    ");
    mvwprintw(menuWin, 14, 1, "       ___     ___        _            _  ");
    mvwprintw(menuWin, 15, 1, "      |_  )   | _ \\___ __| |_ __ _ _ _| |");
    mvwprintw(menuWin, 16, 1, "       / / _  |   / -_|_-<  _/ _` | '_|  _|");
    mvwprintw(menuWin, 17, 1, "      /___(_) |_|_\\___/__/\\__\\__,_|_|  \\__|");



    nodelay(menuWin, TRUE);
    // Display the remaining time
    time_t current_time = time(NULL);
    int remaining_minutes = remaining_time / 60;
    int remaining_seconds = remaining_time % 60;
    mvwprintw(menuWin, 18, 1, "Time remaining: %02d:%02d", remaining_minutes, remaining_seconds);
    wrefresh(menuWin);

    //screen displayed until 'q' is pressed
    while (true) {              // consider while ((key_input = getch()) != 27) {
        int ch = getch();
        if (ch == '1') {
            //Save character's current location to a file
            ofstream outFile("saved_location.txt");
            if (outFile.is_open()) {
                outFile << "Character X: " << "x좌표" << endl;
                outFile << "Character Y: " << "y좌표" << endl;
                
                outFile.close();
                cout << "Saving Game";
            } else {
                cout << "Unable to save";
            }
        }
        else if (ch == '2') {
            delwin(menuWin);
            clear();

        }
        else if (ch == 'q') {
            break;
        }

    }

    delwin(menuWin);
}


// int main(){
//     int x = 64, y = 20;
//     string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Restroom.txt";
//     main_engine(file_path,x,y);
//     endwin();
// }
