#include <ncurses.h>
#include <iostream>
#include <string>
#include <fstream>
#include "MapLoader.h"

//compile using: g++ CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp -o Game -lncurses

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor

    // Set up initial variables
    int x = 0, y = 0;
    int key_input;
    string file_path = "/Users/M1/Documents/GitHub/Initial/Map_Objects/Map_resources/activity_room.txt";
    // Set up screen size
    int screen_height=0;
    int screen_width=0;
    char ch;
    bool flag = TRUE;

    ifstream inputline;
    string nextline;
    inputline.open(file_path);
    if (inputline.fail()) {
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
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

    ifstream charline("/Users/M1/Documents/GitHub/Initial/CharactersDesign_Mechanism/character2.txt");
    if (charline.fail()) {
        cout<<"no file!"<<endl;
        exit(1);
    }
    int charsize = 5;
    int *cptr = &charsize;
    string char_left[*cptr], char_right[*cptr], char_down[*cptr], char_up[*cptr];
    string line;
    int i = 0;
    while (getline(charline, line)) {
        if (i < *cptr) {
            char_left[i] = line;
        } else if (i < *cptr*2) {
            char_right[i%*cptr] = line;
        } else if (i < *cptr*3) {
            char_down[i%*cptr] = line;
        } else {
            char_up[i%*cptr] = line;
        }
        i++;
    }
    charline.close();
    string *current_character = char_right;

    // Main loop
    while ((key_input = getch()) != 27) { // Exit on ESC key press
        clear(); //clear screen
        Maps gameMap(screen_height, screen_width);
        VectorWrapper mapData = gameMap.Map_Loader(file_path);

        // Draw the map
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width);

        switch(key_input) {
            case 'w':
                y--;
                current_character = char_up;
                break;
            case 's':
                y++;
                current_character = char_down;
                break;
            case 'a':
                x-=2;
                current_character = char_left;
                break;
            case 'd':
                x+=2;
                current_character = char_right;
                break;
        }

        // Keep character within screen boundaries
        if (x < 1) {
            x = 1;
        } if (y < 3) {
            y = 2;
        } if (x >= screen_width - 1) {
            x = screen_width - 2;
        } if (y >= screen_height - 1) {
            y = screen_height - 2;
        }
        //for later: add coordinates of objects for each map, so that character can't pass

        for (int i = 0; i < *cptr; i++) {
            for (int j = 0; j < current_character[i].length(); j++) {
                if (current_character[i][j] != '~') {
                    mvaddch(y+i, x+j, current_character[i][j]);
                }
            }
        }
        //mvaddch(y, x, 'O');

        // Refresh screen
        refresh();

    }
    // Clean up ncurses
    endwin();
    return 0;
}