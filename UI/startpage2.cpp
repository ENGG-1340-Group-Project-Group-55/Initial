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
    attroff(COLOR_PAIR(1)); // Turn off the color pair
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    attroff(COLOR_PAIR(4));
    printw("1. Start the game\n");
    printw("2. Instructions\n");
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
    printw("\nINSTRUCTIONS:\n");
    printw("1. The game is a text-based horror school escape game.\n");
    printw("2. You will be prompted with choices throughout the game.\n");
    printw("3. Choose wisely, as your decisions will impact the story.\n");
    printw("4. To make a choice, enter the corresponding number and press Enter.\n");
    printw("\nPress Enter to return to the start page.");
    refresh();

    // Wait for the user to press Enter
    int ch;
    do {
        ch = getch();
    } while (ch != '\n' && ch != '\r');

    show_start_page();
}
