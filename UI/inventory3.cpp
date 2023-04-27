#include <iostream>
#include <vector>
#include <cstdlib> // for exit()
#include <ncurses.h> // for ncurses
#include <string>

using namespace std;

void printInventory(vector<string> inventory) {
    clear(); // Clear the screen
    printw("Inventory:\n");
    for (int i = 0; i < inventory.size(); i++) {
        printw("%d. %s\n", i + 1, inventory[i].c_str());
    }

    // Prompt the user to quit the program
    printw("Enter 'q' to quit or any other key to continue: ");
    refresh(); // Refresh the screen
    int input = getch();
    if (input == 'q') {
        endwin(); // End ncurses mode
        exit(0); // Terminate the program
    }
}

void addItem(vector<string>& inventory, string item) {
    inventory.push_back(item);
    printw("Added %s to the inventory.\n", item.c_str());
    refresh(); // Refresh the screen
}

int main() {
    initscr(); // Initialize ncurses mode
    raw(); // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys
    noecho(); // Don't echo user input

    vector<string> inventory;
    string item;

    while (true) {
        // Prompt the user to enter a command or an item
        printw("Enter a command or an item: ");
        refresh(); // Refresh the screen

        char buf[256];
        getnstr(buf, 255);
        item = string(buf);

        // Trim leading and trailing whitespace
        item.erase(0, item.find_first_not_of(" \t\n\v\f\r"));
        item.erase(item.find_last_not_of(" \t\n\v\f\r") + 1);

        // Check if the user entered an empty string
        if (item.empty()) {
            continue;
        }

        // Check if the user wants to quit
        if (item == "q") {
            break;
        }

        // Check if the user wants to display the inventory
        if (item == "e") {
            printInventory(inventory);
            continue;
        }

        // Add the item to the inventory
        addItem(inventory, item);
    }

    endwin(); // End ncurses mode
    return 0;
}

