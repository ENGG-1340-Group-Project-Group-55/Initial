#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    // Define the filenames and select one at random
    string filenames[] = {"Dining Room 1.txt", "Dining Room 2.txt", "Dining Room 3.txt", "Dining Room 4.txt", "Dining Room 5.txt", "Dining Room 6.txt"};
    srand(time(nullptr));
    int index = rand() % 6;
    string filename = filenames[index];

    // Open the file in input mode and display it on the screen
    ifstream fin(filename);
    string line;
    while (getline(fin, line)) {
        printw("%s\n", line.c_str());
    }

    // Close the file and wait for user input before exiting
    fin.close();
    getch();

    // End ncurses mode
    endwin();

    return 0;
}
