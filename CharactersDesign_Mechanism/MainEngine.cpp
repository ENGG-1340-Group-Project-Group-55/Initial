#include <ncurses.h>
#include <iostream> 
#include <string>
#include <fstream>
#include "/workspaces/Initial/CharactersDesign_Mechanism/MapLoader.h"

//compile using: g++ -pedantic-errors -std=c++11 CharactersDesign_Mechanism/MainEngine.cpp Map_Objects/Map_loading.cpp -o game -lncurses

// Function to create a centered window with a box border
WINDOW* CreateWindow(int screen_height, int screen_width) {
    int startY = (LINES - screen_height) / 2 ;
    int startX = (COLS - screen_width) / 2 ;
    WINDOW* win = newwin(screen_height, screen_width, startY, startX);
    refresh();
    wrefresh(win);
    return win;
}

void printInventory(vector<string> inventory);
vector<string> loadInventoryFromFile();


int main_engine(string file_path, int&x, int& y) {
// Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor

    //Set up initial variables
    char ch;
    bool flag = TRUE;

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

// Main loop
    int key_input;
    while ((key_input = wgetch(game_window)) != 27) { // Exit on ESC key press
        // Clear window
        werase(game_window);
        bool flag1 = FALSE;

        // Draw the map
        Maps gameMap(screen_height, screen_width);
        VectorWrapper mapData = gameMap.Map_Loader(file_path);
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width, game_window);

        switch(key_input) {
            case 'w':
                y--;
                current_character = char_up;
                if (mapData.TDVEC[y+4][x+1] != ' ' || mapData.TDVEC[y+4][x+2] != ' ' || mapData.TDVEC[y+4][x+3] != ' ' || mapData.TDVEC[y+4][x+4] != ' ') {
                    y++;
                    break;
                }
                break;

            case 's':
                y++;
                current_character = char_down;
                if (mapData.TDVEC[y+4][x+1] != ' ' || mapData.TDVEC[y+4][x+2] != ' ' || mapData.TDVEC[y+4][x+3] != ' ' || mapData.TDVEC[y+4][x+4] != ' ') {
                    y--;
                    break;
                }
                break;

            case 'a':
                x-=2;
                current_character = char_left;
                if (mapData.TDVEC[y+4][x+1] != ' '|| mapData.TDVEC[y+4][x+2] != ' ') {
                    x+=2;
                    break;
                }
                break;

            case 'd':
                x+=2;
                current_character = char_right;
                if (mapData.TDVEC[y+4][x+4] != ' ' || mapData.TDVEC[y+4][x+3] != ' ') {
                    x-=2;
                    break;
                }
                break;

            case 'i':
                flag1 = TRUE;
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

        // Refresh the window
        wrefresh(game_window);
        if (flag1 == TRUE) {
            vector<string> inventory = loadInventoryFromFile();
            printInventory(inventory);
        }
    }

// End ncurses mode
    endwin();

    return 0;
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
    } else {
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

int main() {
    int x = 87,y = 24;
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
    main_engine(file_path, x, y);
}