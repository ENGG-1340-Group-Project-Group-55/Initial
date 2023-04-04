#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 10;

int main()
{
    // Initialize inventory
    string inventory[MAX_ITEMS] = {"key", "letter", "scheduler", "book", "a bundle of hair"};
    string art[MAX_ITEMS] = {
            " ╔═════════════════╗\n"
            "  ║  /o \\_____      ║\n"
            "  ║  \\__/-=\"=\"`     ║\n"
            "  ║                 ║\n"
            "  ╚═════════════════╝\n",
            " ╔════════════════╗\n"
            "  ║  /@@@@@@@&@@&& ║ \n"
            "  ║ &@@@@@&@@&&@@  ║\n"
            "  ║ @@@@@&&&@@@@@  ║\n"
            "  ║ &@@&&&&&@@@&&  ║\n"
            "  ║                ║\n"
            "  ╚════════════════╝\n",
            " ╔════╗\n"
            "  ║    ║\n"
            "  ║    ║\n"
            "  ╚════╝\n",
            " ╔═════════════════════════╗\n"
            "  ║     &&&&&    &&&&&&     ║\n"
            "  ║,&& ...... &  ......&&   ║\n"
            "  ║&&& ...    &  ......&&   ║\n"
            "  ║&&  ...... &  ..... &&/  ║\n"
            "  ║&&  .....  &  ....  &&   ║\n"
            "  ║  *&&&&&@# ##&&&&&&#     ║\n"
            "  ╚═════════════════════════╝\n",
            " ╔═════════════════════╗\n"
            "  ║          *          ║\n"
            "  ║    *///&%@,%(/      ║\n"
            "  ║     &##/,(,(&@**    ║\n"
            "  ║  ..&/*#%&%%##*(*    ║\n"
            "  ║ , /# &#(&(&%&&%, *  ║\n"
            "  ║    /(&###%*(%@* .   ║\n"
            "  ║    ,,,*(%/,#((      ║\n"
            "  ║        *. *         ║\n"
            "  ╚═════════════════════╝\n"
    };
    int numItems = 5;

    // Display inventory header
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║               INVENTORY                ║" << endl;
    cout << "╟────────────────────────────────────────╢" << endl;

    // Display inventory items
    for (int i = 0; i < numItems; i++) {
        cout << "║" << art[i] << " " << inventory[i] << " ";
        for (int j = inventory[i].size(); j < 10; j++) {
            cout << " ";
        }
        cout << "║" << endl;
    }

    // Display inventory footer
    cout << "╚════════════════════════════════════════╝" << endl;

    return 0;
}
