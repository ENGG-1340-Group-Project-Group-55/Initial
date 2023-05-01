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
    string filenames[] = {"Teacher's office 1.txt", "Teacher's office 2.txt", "Teacher's office 3.txt", "Teacher's office 4.txt", "Teacher's office 5.txt", "Teacher's office 6.txt"};
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
