#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif

using namespace std;

// Define the size of the playing field
const int FIELD_WIDTH = 20;
const int FIELD_HEIGHT = 10;

// Define the player's starting position
int playerX = FIELD_WIDTH / 2;
int playerY = FIELD_HEIGHT / 2;

#ifdef _WIN32
void disableRawMode() {
    _setmode(_fileno(stdin), _O_TEXT);
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hstdin, &mode);
    mode |= ENABLE_ECHO_INPUT;
    SetConsoleMode(hstdin, mode);
}

void enableRawMode() {
    _setmode(_fileno(stdin), _O_BINARY);
    HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hstdin, &mode);
    mode &= ~ENABLE_ECHO_INPUT;
    SetConsoleMode(hstdin, mode);
}
#else
// Define the keyboard input settings
struct termios orig_tio;
int orig_flags;

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_tio);
    fcntl(STDIN_FILENO, F_SETFL, orig_flags);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_tio);
    atexit(disableRawMode);

    struct termios raw = orig_tio;
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    orig_flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, orig_flags | O_NONBLOCK);
}
#endif

// Function to draw the playing field
void drawField() {
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            if (x == 0 || x == FIELD_WIDTH - 1 || y == 0 || y == FIELD_HEIGHT - 1) {
                cout << "#";
            } else if (x == playerX && y == playerY) {
                cout << "X";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
#ifdef _WIN32
    // Enable raw keyboard input mode on Windows
    enableRawMode();
#else
    // Enable raw keyboard input mode on macOS/Linux
    enableRawMode();
#endif

    // Clear the screen
    cout << "\033[2J\033[1;1H";

    // Draw the playing field
    drawField();

    // Loop to handle keyboard input
    while (true) {
        // Read the keyboard input
#ifdef _WIN32
        if (_kbhit()) {
            char c = _getch();
#else
        char c;
        if (read(STDIN_FILENO, &c, 1) == 1) {
#endif
// Move the player based on the keyboard input
            switch (c) {
                case 'w':
                    if (playerY > 1) {
                        playerY -= 1;
                    }
                    break;
                case 'a':
                    if (playerX > 2) {
                        playerX -= 2;
                    }
                    break;
                case 's':
                    if (playerY < FIELD_HEIGHT - 2) {
                        playerY += 1;
                    }
                    break;
                case 'd':
                    if (playerX < FIELD_WIDTH - 3) {
                        playerX += 2;
                    }
                    break;
            }

// Clear the screen
#ifdef _WIN32
            system("cls");
#else
            cout << "\033[2J\033[1;1H";
#endif

// Draw the playing field
            drawField();

        }
    }
}