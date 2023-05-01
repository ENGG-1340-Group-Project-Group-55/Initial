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

void printMenu(vector<string> menu);
void printStartpage(VectorWrapper StartData);
void display_instructions(VectorWrapper StartData);

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

    string startpath = "/workspaces/Initial/CharactersDesign_Mechanism/startpage.txt";
    Maps Start(28, 104);
    VectorWrapper StartData = Start.Map_Loader(startpath);

// Main loop
    int key_input;
    int enterflag = 0;

    while ((key_input = wgetch(game_window)) != 'q' && (enterflag < 1)) { // Exit on 'q' key press
        // Clear window
        werase(game_window);
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;

        // Draw the map
        Maps gameMap(screen_height, screen_width);

        VectorWrapper mapData = gameMap.Map_Loader(file_path);
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width, game_window);
        int y4 = y+4;
        int x4 = x+4;

        switch(key_input) {
            case 'w':
                y--;
                current_character = char_up;
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt"){
                    if (y4 == 13) {
                        if (x4 >= 19 && x4 <= 24) {
                            enterflag++;
                            return enterflag;
                        } else if (x4 >= 36 && x4 <= 41) {
                            enterflag += 2;
                            return enterflag;
                        } else if (x4 >= 74 && x4 <= 79) {
                            enterflag += 3;
                            return enterflag;
                        } else if (x4 >= 102 && x4 <= 107) {
                            enterflag += 4;
                            return enterflag;
                        }
                    }
                }
                for (int i=1; i<5; i++) {
                    if (mapData.TDVEC[y+4][x+i] != ' '){
                        y++;
                        break;
                    }
                }
                break;

            case 's':
                y++;
                current_character = char_down;
                if (file_path == "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt"){
                    if (y4 == 20) {
                        if (x4>= 26 && x4<= 31) {
                            enterflag += 5;
                            return enterflag;
                        } else if (x4 >= 43 && x4 <= 48) {
                            enterflag += 6;
                            return enterflag;
                        }
                    } if (y4 == 22) {
                        if (x4 >= 100 && x4 <= 111) {
                            enterflag += 7;
                            return enterflag;
                        }
                    }
                }
                for (int i=1; i<5; i++) {
                    if (mapData.TDVEC[y+4][x+i] != ' '){
                        y--;
                        break;
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

            case 'i':
                flag1 = true;
                break;

            case 27:
                flag2 = true;
                break;

            case '0':
                flag3 = true;
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
        if (flag1 == true) {
            vector<string> inventory = loadInventoryFromFile();
            printInventory(inventory);
        }
        if (flag2 == true) {
            vector<string> menu;
            printMenu(menu);
        }
        if (flag3 == true) {
            printStartpage(StartData);
        }
    }

// End ncurses mode
    endwin();
    return enterflag;
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
        if (ch == 27) {
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

    // Screen displayed until 'esc' is pressed
    while (true) {
        int ch = getch();
        if (ch == '1') {
            clear();
            int x = 87, y = 24;
            string file_path = "/workspaces/Initial/Map_Objects/Map_resources/Classroom.txt";
            main_engine(file_path,x,y);
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
    printw("4. You can move your character by using W, A, S, D in your keyboard to move to another place. (W = up, S = down, A = left, D = right)\n");
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

int main(){
    int x = 87, y = 24;
    string file_path = "/workspaces/Initial/Map_Objects/Map_resources/schoolmap.txt";
    main_engine(file_path,x,y);
    endwin();
}

