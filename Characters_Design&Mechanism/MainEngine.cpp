#include <ncurses.h>
#include "MapLoader.h"

//use command g++ MainEngine.cpp Map_loading.cpp -o Game -lncurses

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0); // Hide cursor

    // Set up initial variables
    int x = 0, y = 0;
    int ch;

    // Set up screen size
    int screen_height = 17; // Add 2 for border
    int screen_width = 32;  // Add 2 for border

    // Load the map
//    Maps gameMap(15, 30);
//    VectorWrapper mapData = gameMap.Map_Loader();

    // Main loop
    while ((ch = getch()) != 27) { // Exit on ESC key press
        // Clear screen
        clear();
        Maps gameMap(15, 30);
        VectorWrapper mapData = gameMap.Map_Loader();

        // Draw the map
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width);
//        gameMap.Map_printer(mapData);

        // Move character based on w, a, s, d key press
        switch(ch) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x-=2;
                break;
            case 'd':
                x+=2;
                break;
        }

        // Keep character within screen boundaries
        if (x < 3) x = 3;
        if (y < 3) y = 2;
        if (x >= screen_width*2 - 3) x = screen_width*2 - 5;
        if (y >= screen_height - 2) y = screen_height - 3;

        // Draw character at current position
        mvaddch(y, x, 'X');

        // Refresh screen
        refresh();
    }

    // Clean up ncurses
    endwin();
    return 0;
}