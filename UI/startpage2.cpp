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
    printw("|   **      **     **     **     ** ****     ** ********** ******** *******                               |\n");
    printw("|  /**     /**    ****   /**    /**/**/**   /**/////**/// /**///// /**////**                              |\n");
    printw("|  /**     /**   **//**  /**    /**/**//**  /**    /**    /**      /**    /**                             |\n");
    printw("|  /**********  **  //** /**    /**/** //** /**    /**    /******* /**    /**                             |\n");
    printw("|  /**//////** **********/**    /**/**  //**/**    /**    /**////  /**    /**                             |\n");
    printw("|  /**     /**/**//////**/**    /**/**   //****    /**    /**      /**    **                              |\n");
    printw("|  /**     /**/**     /**//******* /**    //***    /**    /********/*******                               |\n");
    printw("|  //      // //      //  ///////  //      ///     //     //////// ///////                                |\n");
    printw("|                                                                                                         |\n");
    printw("|                       ****     **** ******** ****     ****   *******   *******   ** ********  ********  |\n");
    printw("|                      /**/**   **/**/**///// /**/**   **/**  **/////** /**////** /**/**/////  **//////   |\n");
    printw("|                      /**//** ** /**/**      /**//** ** /** **     //**/**   /** /**/**      /**         |\n");
    printw("|                      /** //***  /**/******* /** //***  /**/**      /**/*******  /**/******* /*********  |\n");
    printw("|                      /**  //*   /**/**////  /**  //*   /**/**      /**/**///**  /**/**////  ////////**  |\n");
    printw("|                      /**   /    /**/**      /**   /    /**//**     ** /**  //** /**/**             /**  |\n");
    printw("|                      /**        /**/********/**        /** //*******  /**   //**/**/******** ********   |\n");
    printw("|                      //         // //////// //         //   ///////   //     // // //////// ////////    |\n");
    printw("|                                                                                                         |\n");
    printw("|                           Please enter the corresponding number to your choice:                         |\n");
    printw("|                                                                                                         |\n");
    printw("|                                        ___    ______           __                                       |\n");
    printw("|                                       <  /   / __/ /____ _____/ /_                                      |\n");
    printw("|                                       / /   _\\ \\/ __/ _ `/ __/ __/                                    |\n");
    printw("|                                      /_(_) /___/\\__/\\_,_/_/  \\__/                                    |\n");
    printw("|                                                                                                         |\n");
    printw("|                             ___      ____        __               __  _                                 |\n");
    printw("|                            |_  |    /  _/__  ___/ /_______ ______/ /_(_)__  ___                         |\n");
    printw("|                           / __/_   _/ // _ \\(_-< __/ __/ // / __/ __/ / _ \\/ _ \\                     |\n");
    printw("|                          /____(_) /___/_//_/___|__/_/  \\_,_/\\__/\\__/_/\\___/_//_/                    |\n");
    printw("|                                                                                                         |\n");
    printw("|---------------------------------------------------------------------------------------------------------|\n");
    printw("\n");
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
