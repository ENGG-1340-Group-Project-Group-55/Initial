#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

// Function declarations
void show_start_page();
void display_instructions();

int main() {
    srand(time(0)); // Seed the random number generator

    show_start_page();

    // Your game code here

    return 0;
}

void show_start_page() {
    std::string input;

    std::cout << R"(

▄▄▄█████▓ ██░ ██  ▄▄▄       ██▀███   ██░ ██  ▄▄▄█████▓
▓  ██▒ ▓▒▓██░ ██▒▒████▄    ▓██ ▒ ██▒▓██░ ██▒▓  ██▒ ▓▒
▒ ▓██░ ▒░▒██▀▀██░▒██  ▀█▄  ▓██ ░▄█ ▒▒██▀▀██░▒ ▓██░ ▒░
░ ▓██▓ ░ ░▓█ ░██ ░██▄▄▄▄██ ▒██▀▀█▄  ░▓█ ░██ ░ ▓██▓ ░
  ▒██▒ ░ ░▓█▒░██▓ ▓█   ▓██▒░██▓ ▒██▒░▓█▒░██▓  ▒██▒ ░
  ▒ ░░    ▒ ░░▒░▒ ▒▒   ▓▒█░░ ▒▓ ░▒▓░ ▒ ░░▒░▒  ▒ ░░
    ░     ▒ ░▒░ ░  ▒   ▒▒ ░  ░▒ ░ ▒░ ▒ ░▒░ ░    ░
  ░       ░  ░░ ░  ░   ▒     ░░   ░  ░  ░░ ░  ░
          ░  ░  ░      ░  ░   ░      ░  ░  ░



@@@  @@@   @@@@@@   @@@  @@@  @@@  @@@  @@@@@@@  @@@@@@@@  @@@@@@@     @@@@@@@@@@   @@@@@@@@  @@@@@@@@@@    @@@@@@   @@@@@@@   @@@  @@@@@@@@   @@@@@@
@@@  @@@  @@@@@@@@  @@@  @@@  @@@@ @@@  @@@@@@@  @@@@@@@@  @@@@@@@@    @@@@@@@@@@@  @@@@@@@@  @@@@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@  @@@@@@@@  @@@@@@@
@@!  @@@  @@!  @@@  @@!  @@@  @@!@!@@@    @@!    @@!       @@!  @@@    @@! @@! @@!  @@!       @@! @@! @@!  @@!  @@@  @@!  @@@  @@!  @@!       !@@
!@!  @!@  !@!  @!@  !@!  @!@  !@!!@!@!    !@!    !@!       !@!  @!@    !@! !@! !@!  !@!       !@! !@! !@!  !@!  @!@  !@!  @!@  !@!  !@!       !@!
@!@!@!@!  @!@!@!@!  @!@  !@!  @!@ !!@!    @!!    @!!!:!    @!@  !@!    @!! !!@ @!@  @!!!:!    @!! !!@ @!@  @!@  !@!  @!@!!@!   !!@  @!!!:!    !!@@!!
!!!@!!!!  !!!@!!!!  !@!  !!!  !@!  !!!    !!!    !!!!!:    !@!  !!!    !@!   ! !@!  !!!!!:    !@!   ! !@!  !@!  !!!  !!@!@!    !!!  !!!!!:     !!@!!!
!!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!    !!:    !!:       !!:  !!!    !!:     !!:  !!:       !!:     !!:  !!:  !!!  !!: :!!   !!:  !!:            !:!
:!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!    :!:    :!:       :!:  !:!    :!:     :!:  :!:       :!:     :!:  :!:  !:!  :!:  !:!  :!:  :!:           !:!
::   :::  ::   :::  ::::: ::   ::   ::     ::     :: ::::   :::: ::    :::     ::    :: ::::  :::     ::   ::::: ::  ::   :::   ::   :: ::::  :::: ::
 :   : :   :   : :   : :  :   ::    :      :     : :: ::   :: :  :      :      :    : :: ::    :      :     : :  :    :   : :  :    : :: ::   :: : : 

1. Start Game
2. Instructions

Enter the corresponding number to choose an option: )";
    std::cin >> input;

    while (input != "1" && input != "2") {
        std::cout << "Invalid input. Please enter 1 or 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> input;
    }

    if (input == "1") {
        // Proceed to the game
    } else if (input == "2") {
        display_instructions();
    }
}

void display_instructions() {
    std::cout << "\nINSTRUCTIONS:\n";
    std::cout << "1. The game is a text-based adventure set in a haunted school.\n";
    std::cout << "2. You will be prompted with choices throughout the game.\n";
    std::cout << "3. Choose wisely, as your decisions will impact the story.\n";
    std::cout << "4. To make a choice, enter the corresponding number and press Enter.\n";
    std::cout << "\nPress Enter to return to the start page.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    show_start_page();
}
