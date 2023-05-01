#include <iostream>
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    // Set window size
    int row = 30;
    int col = 100;
    int start_row = 0;
    int start_col = 0;

    // Load map from file
    string filename = "Music Room.txt";
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // Draw map
    for (int i = 0; i < row && i < lines.size(); i++) {
        for (int j = 0; j < col && j < lines[i].size(); j++) {
            mvaddch(start_row + i, start_col + j, lines[i][j]);
        }
    }

    // Set random seed
    srand(time(NULL));

    // Spawn "*"
    int coords[6][2] = {{13, 18}, {16, 20}, {19, 45}, {19, 16}, {22, 23}, {27, 82}};
    int index = rand() % 6;
    int x = coords[index][0];
    int y = coords[index][1];
    mvaddch(start_row + x, start_col + y, '*');

    // Refresh screen
    refresh();

    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}
