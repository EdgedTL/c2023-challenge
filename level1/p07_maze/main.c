#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

struct Maze {
    int maze[MAX_SIZE][MAX_SIZE];
    int entranceX;
    int entranceY;
    int exitX;
    int exitY;
};

void printMaze(struct Maze *mazeData, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == mazeData->entranceX && j == mazeData->entranceY) {
                printf("E ");  // Entrance
            } else if (i == mazeData->exitX && j == mazeData->exitY) {
                printf("X ");  // Exit
            } else if (mazeData->maze[i][j] == 1) {
                printf("  ");  // Empty path
            } else {
                printf("##");  // Wall
            }
        }
        printf("\n");
    }
}

void generateMaze(struct Maze *mazeData, int n, int x, int y) {
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int temp = dx[i];
        int randIndex = rand() % 4;
        dx[i] = dx[randIndex];
        dx[randIndex] = temp;

        temp = dy[i];
        dy[i] = dy[randIndex];
        dy[randIndex] = temp;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + 2 * dx[i];
        int ny = y + 2 * dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && mazeData->maze[nx][ny] == 1) {
            mazeData->maze[nx][ny] = 0;  // Mark the cell as part of the maze
            mazeData->maze[x + dx[i]][y + dy[i]] = 0;
            generateMaze(mazeData, n, nx, ny);
        }
    }
}



int main() {
    srand(time(NULL));

    int n;

    // Input the size of the maze
    printf("Enter the size of the maze (up to %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Validate the size of the maze
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid maze size.\n");
        return 1;
    }

    struct Maze mazeData;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mazeData.maze[i][j] = 1;
        }
    }

    mazeData.entranceX = 0;
    mazeData.entranceY = rand() % n;

    mazeData.maze[mazeData.entranceX][mazeData.entranceY] = 0;

    mazeData.exitX = n - 1;
    mazeData.exitY = n - 1;

    mazeData.maze[mazeData.exitX][mazeData.exitY] = 0;

    generateMaze(&mazeData, n, mazeData.entranceX, mazeData.entranceY);

    printf("Generated Maze:\n");
    printMaze(&mazeData, n);

    return 0;
}
