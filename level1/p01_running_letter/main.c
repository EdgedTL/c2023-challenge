#include <stdio.h>
#include <windows.h>  // For Windows platform specific functions

void moveCursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int maxWidth, currentX;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    maxWidth = csbi.dwSize.X - 1;

    currentX = 0;

    while (1) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        maxWidth = csbi.dwSize.X - 1;
        moveCursor(currentX, 0);
        printf("X");

        for (int i = 0; i < maxWidth; ++i) {
            Sleep(10);
            moveCursor(i-1, 0);
            printf(" ");
            moveCursor(i, 0);
            printf("X");
        }

        for (int i = maxWidth; i > 0; --i) {
            Sleep(10);
            moveCursor(i+1, 0);
            printf(" ");
            moveCursor(i, 0);
            printf("X");
        }
    }

    return 0;
}
