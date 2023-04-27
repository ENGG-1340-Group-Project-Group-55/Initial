//g++ -o startpage2 startpage2.cpp -lncurses

#include <ncurses.h>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
void show_start_page();
void display_instructions();

int main() {
    srand(time(0)); // Seed the random number generator

    initscr(); // Initialize ncurses
    raw(); // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys
    noecho(); // Don't echo user input

    start_color(); // Enable colors

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK); // Pair 1: Red text on a black background
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // Pair 2: Green text on a black background
    init_pair(3, COLOR_BLUE, COLOR_BLACK); // Pair 3: Blue text on a black background
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Pair 4: Yellow text on a black background

    // Check if the terminal supports custom colors
    if (can_change_color()) {
        // Define a custom bright blue color
        init_color(COLOR_BLUE + 1, 0, 0, 1000);

        // Use the custom color in the color pair
        init_pair(3, COLOR_BLUE + 1, COLOR_BLACK);
    }

    show_start_page();

    // Your game code here

    endwin(); // End ncurses mode

    return 0;
}


void show_start_page() {
    string input;

    // Clear the screen
    clear();

    // Display the title and options
    printw("|---------------------------------------------------------------------------------------------------------|\n");
    printw("|   ");
    attron(COLOR_PAIR(1));
    printw("**      **     **     **     ** ****     ** ********** ******** *******                               ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**     /**    ****   /**    /**/**/**   /**/////**/// /**///// /**////**                              ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**     /**   **//**  /**    /**/**//**  /**    /**    /**      /**    /**                             ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**********  **  //** /**    /**/** //** /**    /**    /******* /**    /**                             ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**//////** **********/**    /**/**  //**/**    /**    /**////  /**    /**                             ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**     /**/**//////**/**    /**/**   //****    /**    /**      /**    **                              ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("/**     /**/**     /**//******* /**    //***    /**    /********/*******                               ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|  ");
    attron(COLOR_PAIR(1));
    printw("//      // //      //  ///////  //      ///     //     //////// ///////                                ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                                                                                                         |\n");
    printw("|                       ");
    attron(COLOR_PAIR(1));
    printw("****     **** ******** ****     ****   *******   *******   ** ********  ********  ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("/**/**   **/**/**///// /**/**   **/**  **/////** /**////** /**/**/////  **//////   ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("/** //***  /**/******* /** //***  /**/**      /**/*******  /**/******* /*********  ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("/**  //*   /**/**////  /**  //*   /**/**      /**/**///**  /**/**////  ////////**  ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("/**   /    /**/**      /**   /    /**//**     ** /**  //** /**/**             /**  ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("/**        /**/********/**        /** //*******  /**   //**/**/******** ********   ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                      ");
    attron(COLOR_PAIR(1));
    printw("//         // //////// //         //   ///////   //     // // //////// ////////    ");
    attroff(COLOR_PAIR(1));
    printw("|\n");
    printw("|                                                                                                         |\n");
    printw("|                           ");
    attron(COLOR_PAIR(3));
    printw("Please enter the corresponding number to your choice:                         ");
    attroff(COLOR_PAIR(3));
    printw("|\n");
    printw("|                                                                                                         |\n");
    printw("|                                        ");
    attron(COLOR_PAIR(2));
    printw("___    ______           __                                       ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                                       ");
    attron(COLOR_PAIR(2));
    printw("<  /   / __/ /____ _____/ /_                                      ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                                       ");
    attron(COLOR_PAIR(2));
    printw("/ /   _\\ \\/ __/ _ `/ __/ __/                                      ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                                      ");
    attron(COLOR_PAIR(2));
    printw("/_(_) /___/\\__/\\_,_/_/  \\__/                                       ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                                                                                                         |\n");
    printw("|                             ");
    attron(COLOR_PAIR(2));
    printw("___      ____        __               __  _                                 ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                            ");
    attron(COLOR_PAIR(2));
    printw("|_  |    /  _/__  ___/ /_______ ______/ /_(_)__  ___                         ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                           ");
    attron(COLOR_PAIR(2));
    printw("/ __/_   _/ // _ \\(_-< __/ __/ // / __/ __/ / _ \\/ _ \\                        ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                          ");
    attron(COLOR_PAIR(2));
    printw("/____(_) /___/_//_/___|__/_/  \\_,_/\\__/\\__/_/\\___/_//_/                        ");
    attroff(COLOR_PAIR(2));
    printw("|\n");
    printw("|                                                                                                         |\n");
    printw("|---------------------------------------------------------------------------------------------------------|\n");
    printw("\n");

    // Refresh the screen to show the changes
    refresh();

    // Wait for the user to enter 1 or 2
    int ch;
    do {
        ch = getch();
    } while (ch != '1' && ch != '2');

    if (ch == '1') {
        // Proceed to the game
    } else if (ch == '2') {
        display_instructions();
    }
}



void display_instructions() {
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
    printw("4. You can move your character by using ‘W’, ‘A’, ’S’, and ‘D’ in your keyboard to move to another place. (‘W’ = up, ’S’ = down, ‘A’ = left, ‘D’ = right)\n");
    printw("\n");
    printw("5. You can press ‘E’ to open your inventory and press ‘F’ to grab items while playing the game.\n");
    printw("\n");
    printw("\nPress Enter to return to the start page.");
    attroff(COLOR_PAIR(4));

    refresh();

    // Wait for the user to press Enter
    int ch;
    do {
        ch = getch();
    } while (ch != '\n' && ch != '\r');

    show_start_page();
}
