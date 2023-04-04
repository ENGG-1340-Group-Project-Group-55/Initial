#include <iostream>
#include <vector>
#include <cstdlib> // for exit()

using namespace std;

void printInventory(vector<string> inventory) {
    cout << "Inventory:" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i] << endl;
    }

    // Prompt the user to quit the program
    cout << "Enter 'q' to quit or any other key to continue: ";
    string input;
    getline(cin, input);
    if (input == "q") {
        exit(0); // Terminate the program
    }
}

void addItem(vector<string>& inventory, string item) {
    inventory.push_back(item);
    cout << "Added " << item << " to the inventory." << endl;
}

int main() {
    vector<string> inventory;
    string item;

    while (true) {
        // Prompt the user to enter a command or an item
        cout << "Enter a command or an item: ";
        getline(cin, item);

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

    return 0;
}
