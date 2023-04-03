#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string support;

void mainMenu() {
    if(support == "Help" || support == "help") {

        cout << "-------------------------------------------" << endl;
        cout << "                MAIN MENU                  " << endl;
        cout << "To quite the game, type 'quit'" << endl;
        cout << "To continue, type 'continue'. " << endl;
        cin >> support;
    }
}

void gameID() {
    string ID;
    cout << "What is your name?" << endl; //might take this out for later plot twist
    cin >> ID;
    cout << "Hello " << ID << ", Good luck on your journey" << endl;
    cin >> support;
}

void starting() {
    string userStart;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Hello, welcome to the \"Haunted Memories: The School Tragedy\"." << endl << " " << endl;
    cout << "If you need help during the game, type 'help' to go to the main menu." << endl << " " << endl;
    cout << "Type 'start' to start your adventure!" << endl;
    cin >> support;
    if (support == "Start" || support == "start") {

        gameID();
    }
}


int main() {

    starting();
    mainMenu();
}