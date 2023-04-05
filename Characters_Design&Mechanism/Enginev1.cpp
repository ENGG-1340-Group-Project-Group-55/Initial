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

using namespace std;

class Game {
private:
    const int ROWS = 12;
    const int COLS = 22;
    int x;
    int y;
    char grid[12][22];

#ifdef _WIN32
    HANDLE consoleHandle;
    DWORD originalConsoleMode;
#else
    struct termios oldSettings, newSettings;
#endif

public:
    Game() {
        x = COLS / 2;
        y = ROWS / 2;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                    grid[i][j] = '#';
                } else {
                    grid[i][j] = ' ';
                }
            }
        }

#ifdef _WIN32
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleMode(consoleHandle, &originalConsoleMode);
        DWORD consoleMode = originalConsoleMode;
        consoleMode &= ~ENABLE_LINE_INPUT;
        consoleMode &= ~ENABLE_ECHO_INPUT;
        SetConsoleMode(consoleHandle, consoleMode);
#else
        tcgetattr(STDIN_FILENO, &oldSettings);
        newSettings = oldSettings;
        newSettings.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
#endif
    }

    ~Game() {
#ifdef _WIN32
        SetConsoleMode(consoleHandle, originalConsoleMode);
#else
        tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
#endif
    }

    void update() {
        while (true) {
#ifdef _WIN32
            system("cls");
#else
            cout << "\033[2J\033[1;1H";
#endif
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (i == y && j == x) {
                        cout << "X";
                    } else {
                        cout << grid[i][j];
                    }
                }
                cout << endl;
            }

#ifdef _WIN32
            int ch = _getch();
#else
            char ch = getchar();
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
    }
};

int main() {
    Game game;
    game.update();
    return 0;
}
