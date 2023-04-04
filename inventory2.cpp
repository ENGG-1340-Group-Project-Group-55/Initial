#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Define items and their corresponding ASCII graphics
    vector<string> items = {"key", "book", "letter", "bundle of hair"};
    vector<string> graphics = {
            "/o \\_____",
            "\\__/-=\"=\"`",
            " /@@@@@\n&@@@@\n@@@@@",
            " *       \n    *///&%@,%(/     \n     &##/,(,(&@**   \n  ..&/*#%&%%##*(*  \n , /# &#(&(&%&&%, * \n    /(&###%*(%@* .  \n    ,,,*(%/,#((     \n        *."
    };

    // Print the inventory
    cout << " _____   _____   _____   _____\n";
    cout << "|     | |     | |     | |     |\n";
    cout << "|  ";
    if (items.size() > 0) {
        cout << items[0] << "  ";
    } else {
        cout << "     ";
    }
    cout << "| |  ";
    if (items.size() > 1) {
        cout << items[1] << "  ";
    } else {
        cout << "     ";
    }
    cout << "| |  ";
    if (items.size() > 2) {
        cout << items[2] << "  ";
    } else {
        cout << "     ";
    }
    cout << "| |  ";
    if (items.size() > 3) {
        cout << items[3] << "  ";
    } else {
        cout << "     ";
    }
    cout << "|\n";
    cout << "|_____| |_____| |_____| |_____|\n";
    for (int i = 0; i < 5; i++) {
        cout << "|     | |     | |     | |     |\n";
        for (int j = 0; j < items.size(); j++) {
            cout << "|  ";
            if (i < graphics[j].size()) {
                cout << graphics[j][i];
            } else {
                cout << " ";
            }
            cout << "  ";
        }
        cout << "|\n";
    }
    cout << "|_____| |_____| |_____| |_____|\n";

    return 0;
}


  &&&&   &&&&
&& ... &  ...&&
&& ... &  ...&&/
  *&&& & @###&