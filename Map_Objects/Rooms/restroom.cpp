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
    string filenames[] = {"Restroom 1.txt", "Restroom 2.txt", "Restroom 3.txt", "Restroom 4.txt", "Restroom 5.txt", "Restroom 6.txt"};
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
