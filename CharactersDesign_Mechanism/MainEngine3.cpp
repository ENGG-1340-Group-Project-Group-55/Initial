#include <ncurses.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "MapLoader.h"

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

void printMenu(vector<string> menu);
void printStartpage(VectorWrapper StartData);
void display_instructions(VectorWrapper StartData);

//compile using: g++ -pedantic-errors -std=c++11 MainEngine2.cpp Map_loading.cpp -o Game -lncurses

int main() {
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


    //Set up initial variables
    int x = 87, y = 24;
    string file_path = "/Users/minchankim/CLionProjects/1340GP/Classroom.txt";
    char ch;
    bool flag = TRUE;

    //count dimensions of a map
    int screen_height=0;
    int screen_width=0;
    ifstream inputline;
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

    WINDOW *game_window = CreateWindow(screen_height, screen_width);

    //store character into arrays
    ifstream charline("character3.txt");
    if (charline.fail()) {
        cout<<"no file!"<<endl;
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



    //startpapge
    string startpath = "/Users/minchankim/CLionProjects/1340GP/startpage.txt";
    Maps Start(28, 104);
    VectorWrapper StartData = Start.Map_Loader(startpath);



// Main loop
    int key_input;
    while ((key_input = wgetch(game_window)) != 'q') { // Exit on ESC key press
        // Clear window
        werase(game_window);
        bool flag1 = FALSE;
        bool flag2 = FALSE;
        bool flag3 = FALSE;


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

            case 27:
                flag2 = TRUE;
                break;

            case '0':
                flag3 = TRUE;
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

        if (flag2 == TRUE) {
            vector<string> menu;
            printMenu(menu);
        }
        if (flag3 == TRUE) {
            printStartpage(StartData);
        }
    }

// End ncurses mode
    endwin();

    return 0;
}

vector<string> loadInventoryFromFile() {
    vector<string> inventory;
    ifstream inputFile("/Users/minchankim/CLionProjects/1340GP/UI/inventory.txt"); // Open the file for reading
    string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            inventory.push_back(line); // Read and store the items from the file
        }
        inputFile.close(); // Close the file
    } else {
        cout << "Unable to open file for reading." << endl;
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
        if (ch == 'q') {
            break;
        }
    }

    delwin(inventoryWin);
}

void printMenu(vector<string> menu) {
    int menu_height = 15;
    int menu_width = 30;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* menuWin = CreateWindow(menu_height, menu_width);
    box(menuWin, 0, 0);
    mvwprintw(menuWin, 1, 1, "Menu:");
    for (int i = 0; i < menu.size(); i++) {
        mvwprintw(menuWin, i + 2, 1, "%d. %s", i + 1, menu[i].c_str());
    }
    wrefresh(menuWin);

    //screen displayed until 'q' is pressed
    while (true) {              // consider while ((key_input = getch()) != 27) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    delwin(menuWin);
}


void printStartpage(VectorWrapper StartData) {
    clear();

    int start_height = 28;
    int start_width = 104;

    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* startWin = CreateWindow(start_height, start_width);

    // Draw the start page with colors
    for (int i = 0; i < StartData.TDVEC.size(); i++) {
        for (int j = 0; j < StartData.TDVEC[i].size(); j++) {
            if (StartData.TDVEC[i][j] == '.') {
                continue; // Skip '.' characters
            }
            if (i < 17) {
                wattron(startWin, COLOR_PAIR(1));
                mvwaddch(startWin, i, j, StartData.TDVEC[i][j]);
                wattroff(startWin, COLOR_PAIR(1));
            } else if (i < 19) {
                wattron(startWin, COLOR_PAIR(3));
                mvwaddch(startWin, i, j, StartData.TDVEC[i][j]);
                wattroff(startWin, COLOR_PAIR(3));
            } else {
                wattron(startWin, COLOR_PAIR(2));
                mvwaddch(startWin, i, j, StartData.TDVEC[i][j]);
                wattroff(startWin, COLOR_PAIR(2));
            }
        }
    }

    wrefresh(startWin);

    // Screen displayed until 'q' is pressed
    while (true) {
        int ch = getch();
        if (ch == '1') {
            cout << "Starting Game";
        }
        else if (ch == '2') {
            display_instructions(StartData);
        }
        if (ch == 'q') {
            break;
        }
    }

    delwin(startWin);
    wrefresh(startWin);
}

void display_instructions(VectorWrapper StartData) {
    clear();
    attron(COLOR_PAIR(1));
    printw("\n");
    printw("  ___ _  _ ___ _____ ___ _   _  ___ _____ ___ ___  _  _ \n");
    printw(" |_ _| \\| / __|_   _| _ \\ | | |/ __|_   _|_ _/ _ \\| \\| |\n");
    printw("  | || .` \\__ \\ | | |   / |_| | (__  | |  | | (_) | .` |\n");
    printw(" |___|_|\\_|___/ |_| |_|_\\\\___/ \\___| |_| |___\\___/|_|\\_|\n");
    printw("                                                        ");
    printw("\n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    printw("1. Welcome to horror school escape game!\n");
    printw("\n");
    printw("2. While playing the game, you will be guided to choose an action from several options while playing the game. To make a choice, enter the corresponding number and press Enter.\n");
    printw("\n");
    printw("3. Please choose wisely, as you cannot change your choice and the storyline changes by your decisions.\n");
    printw("\n");
    printw("4. You can move your character by using W, A, S, and D in your keyboard to move to another place. (W = up, S = down, A = left, D = right)\n");
    printw("\n");
    printw("5. You can press E to open your inventory and press F to grab items while playing the game.\n");
    printw("\n");
    printw("\nPress Enter to return to the start page.");
    attroff(COLOR_PAIR(4));

    refresh();

    // Wait for the user to press Enter
    int ch;
    do {
        ch = getch();
    } while (ch != '\n' && ch != '\r');

    printStartpage(StartData);
}