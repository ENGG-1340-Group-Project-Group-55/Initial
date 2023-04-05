#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

int main() {
#ifdef _WIN32
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD originalConsoleMode;
    GetConsoleMode(consoleHandle, &originalConsoleMode);
    DWORD consoleMode = originalConsoleMode;
    consoleMode &= ~ENABLE_LINE_INPUT;
    consoleMode &= ~ENABLE_ECHO_INPUT;
    SetConsoleMode(consoleHandle, consoleMode);
#else
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
#endif

    const int ROWS = 12;
    const int COLS = 22;
    int x = COLS / 2;
    int y = ROWS / 2;

    char grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                grid[i][j] = '#';
            } else {
                grid[i][j] = ' ';
            }
        }
    }

    while (true) {
#ifdef _WIN32
        system("cls");
#else
        std::cout << "\033[2J\033[1;1H";
#endif
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == y && j == x) {
                    std::cout << "X";
                } else {
                    std::cout << grid[i][j];
                }
            }
            std::cout << std::endl;
        }

#ifdef _WIN32
        int ch = _getch();
#else
        char ch = std::getchar();
#endif

        if (ch == 'w' && y > 1) {
            y--;
        } else if (ch == 'a' && x > 2) {
            x-=2;
        } else if (ch == 's' && y < ROWS - 2) {
            y++;
        } else if (ch == 'd' && x < COLS - 3) {
            x+=2;
        }
    }

#ifdef _WIN32
    SetConsoleMode(consoleHandle, originalConsoleMode);
#else
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
#endif

    return 0;
}
