#include <ncurses.h>
#include "MainEngine.h" // Include the new header file

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
    int screen_height = 22; // Add 2 for border
    int screen_width = 44;  // Add 2 for border

    // Load the map
    Maps gameMap(20, 42);
    VectorWrapper mapData = gameMap.Map_Loader();

    // Main loop
    while ((ch = getch()) != 27) { // Exit on ESC key press
        // Clear screen
        clear();

        // Draw the map
        gameMap.Map_printer(mapData, 0, 0, screen_height, screen_width);

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
        if (x < 1) x = 1;
        if (y < 1) y = 1;
        if (x >= screen_width-1) x = screen_width - 2;
        if (y >= screen_height-1) y = screen_height - 2;

        // Draw character at current position
        mvaddch(y, x, 'X');

        // Refresh screen
        refresh();
    }

    // Clean up ncurses
    endwin();
    return 0;
}
