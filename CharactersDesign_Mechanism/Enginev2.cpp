#include <ncurses.h>

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

    // Main loop
    while ((ch = getch()) != 27) { // Exit on ESC key press
        // Clear screen
        clear();

        // Draw border
        for (int i = 0; i < screen_height; i++) {
            for (int j = 0; j < screen_width; j++) {
                if (i == 0 || i == screen_height-1 || j == 0 || j == screen_width-1) {
                    mvaddch(i, j, '#');
                }
            }
        }

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
