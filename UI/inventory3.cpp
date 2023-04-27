#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

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
    inventory.push_back(item);
    cout << "Added " << item << " to the inventory." << endl;
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
