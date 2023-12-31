#include <stdio.h>

// Enum to represent different states in the maze
enum State {
    EMPTY = 0,
    WALL,
    BOX,
    PLAYER,
    ENDPOINT
};

void printMaze(int n, char maze[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int hasWon(int n, char maze[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == BOX) {
                return 0;
            }
        }
    }
    return 1;
}

void movePlayer(int n, char maze[][n], int x, int y, int dx, int dy) {
    int new_x = x + dx;
    int new_y = y + dy;

    // Check if the new position is within bounds
    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
        // Check the state of the new position
        char newPos = maze[new_x][new_y];

        if (newPos == EMPTY || newPos == ENDPOINT) {
            // Move the player to the new position
            maze[x][y] = (maze[x][y] == PLAYER) ? EMPTY : ENDPOINT;
            maze[new_x][new_y] = PLAYER;
        } else if (newPos == BOX) {
            // Check if the box can be pushed
            int newBox_x = new_x + dx;
            int newBox_y = new_y + dy;

            if (newBox_x >= 0 && newBox_x < n && newBox_y >= 0 && newBox_y < n) {
                char newBoxPos = maze[newBox_x][newBox_y];

                if (newBoxPos == EMPTY || newBoxPos == ENDPOINT) {
                    // Move the player and push the box
                    maze[x][y] = (maze[x][y] == PLAYER) ? EMPTY : ENDPOINT;
                    maze[new_x][new_y] = PLAYER;
                    maze[newBox_x][newBox_y] = BOX;
                }
            }
        }
    }
}

int main() {
    // Read maze size from the file
    char directory[255] = "C:\\Users\\Admin\\CLionProjects\\c2023-challenge\\level1\\maze.txt";
    //gets(directory);
    FILE *file = fopen(directory, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    char maze[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, " %c", &maze[i][j]);
        }
    }

    fclose(file);

    int player_x, player_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == PLAYER) {
                player_x = i;
                player_y = j;
                break;
            }
        }
    }

    while (!hasWon(n, maze)) {
        printMaze(n, maze);

        char move;
        printf("Enter move (W/A/S/D): ");
        scanf(" %c", &move);

        switch (move) {
            case 'W':
                movePlayer(n, maze, player_x, player_y, -1, 0);
                break;
            case 'A':
                movePlayer(n, maze, player_x, player_y, 0, -1);
                break;
            case 'S':
                movePlayer(n, maze, player_x, player_y, 1, 0);
                break;
            case 'D':
                movePlayer(n, maze, player_x, player_y, 0, 1);
                break;
            default:
                printf("Invalid move. Please enter W/A/S/D.\n");
                break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maze[i][j] == PLAYER) {
                    player_x = i;
                    player_y = j;
                    break;
                }
            }
        }
    }

    printf("Congratulations! You have won!\n");

    return 0;
}
