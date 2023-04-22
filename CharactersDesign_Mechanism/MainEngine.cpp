#include <ncurses.h>
#include <iostream>
#include <string>
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
    string file_path = "/Users/M1/Documents/GitHub/Initial/Map_Objects/Map_resources/wholemap.txt";
    // Set up screen size
    int screen_height;
    int screen_width;
    char ch;

    ifstream inputline;
    string nextline;
    inputline.open(file_path);
    if (inputline.fail()) {
        cout<<"파일이 없다잖아 병신아!!!"<<endl;
        exit(1);
    }

    while (inputline >> noskipws >> ch)
    {
        if (ch != '\n')
        {
            screen_width++;
        }
        else
        {
            screen_height++;
        }
    }

    inputline.close();

    string character_right[8] = {
            ".._...",
            "// }..",
            "//,\\..",
            "_/`-.",
            "( ,).",
            "|/...",
            "/|...",
            "`...."
    };
    string character_left[8] = {
            "..._.",
            "..{ \\",
            "..,/\\",
            "-`\\_.",
            ".(, )",
            "...\\|",
            "...|\\",
            "....`"
    };
    string character_up[8] = {
            "   UP  ",
            " U   P ",
            " U   P ",
            "  U  P  ",
            "  U P ",
            "  UP  .......",
            "  UP   ",
            "   UP  "
    };
    string character_down[8] = {
            ".  DOW N   ",
            ".  DO WN  ",
            "   DOW N  ",
            "  DOWN/  ",
            ".  DOWN  ",
            "  DO WN   ",
            "  D O W N  ................",
            "   DOWN   "
    };

    string *current_character = character_right;

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
                current_character = character_up;
                break;
            case 's':
                y++;
                current_character = character_down;
                break;
            case 'a':
                x-=2;
                current_character = character_left;
                break;
            case 'd':
                x+=2;
                current_character = character_right;
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

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < current_character[i].length(); j++) {
                if (current_character[i][j] != '.') {   //change . to smth used less
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