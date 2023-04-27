//g++ -o inventory3 inventory3.cpp -lncurses

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <fstream>
#include <ostream>
#include <istream>

using namespace std;

WINDOW* createInventoryWindow(int height, int width) {
    int startY = (LINES - height) / 2;
    int startX = (COLS - width) / 2;

    WINDOW* win = newwin(height, width, startY, startX);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    return win;
}

void printInventory(vector<string> inventory) {
    int height = 20;
    int width = 40;

    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    WINDOW* inventoryWin = createInventoryWindow(height, width);

    mvwprintw(inventoryWin, 1, 1, "Inventory:");
    for (int i = 0; i < inventory.size(); i++) {
        mvwprintw(inventoryWin, i + 2, 1, "%d. %s", i + 1, inventory[i].c_str());
    }
    wrefresh(inventoryWin);

    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }

    delwin(inventoryWin);
    endwin();
}

void addItem(vector<string>& inventory, string item) {
    ofstream outputFile("inventory.txt", ios::app); // Open the file in append mode
    if (outputFile.is_open()) {
        inventory.push_back(item);
        outputFile << item << endl; // Write the item to the file
        outputFile.close(); // Close the file
        cout << "Added " << item << " to the inventory." << endl;
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

vector<string> loadInventoryFromFile() {
    vector<string> inventory;
    ifstream inputFile("inventory.txt"); // Open the file for reading
    string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            inventory.push_back(line); // Read and store the items from the file
        }
        inputFile.close(); // Close the file
    } else {
        cout << "Unable to open file for reading." << endl;
    }

    return inventory;
}

int main() {
    vector<string> inventory;
    string item;

    while (true) {
        cout << "Enter a command or an item: ";
        getline(cin, item);

        if (item == "q") {
            break;
        }

        if (item == "e") {
            printInventory(inventory);
            continue;
        }

        addItem(inventory, item);
    }

    return 0;
}
