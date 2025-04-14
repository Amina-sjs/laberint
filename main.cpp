#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <windows.h>  // Добавлено для кодировки UTF-8

using namespace std;

const char WALL = '#';
const char PATH = ' ';
const char VISITED_PATH = '.';

const int DEFAULT_ROWS = 21;
const int DEFAULT_COLS = 21;

int rows, cols;
vector<vector<char>> maze;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void initMaze();
void printMaze();
bool isInBounds(int x, int y);
void generateMaze(int x, int y);
bool solveMaze(int x, int y, int ex, int ey);

int main() {
    SetConsoleOutputCP(CP_UTF8); // Настроить кодировку UTF-8

    cout << "Maze Generator Project (C++)" << endl;

    cout << "Enter maze size (odd numbers, e.g., 21 21): ";
    cin >> rows >> cols;

    if (rows < 5 || cols < 5 || rows % 2 == 0 || cols % 2 == 0) {
        cout << "Size should be odd and >= 5. Using default size (21x21)." << endl;
        rows = DEFAULT_ROWS;
        cols = DEFAULT_COLS;
    }

    srand(time(0));
    initMaze();
    generateMaze(1, 1);

    maze[1][1] = PATH;
    maze[rows - 2][cols - 2] = PATH;

    cout << "\nGenerated Maze:\n";
    printMaze();

    if (solveMaze(1, 1, rows - 2, cols - 2)) {
        cout << "\nSolved Maze:\n";
        printMaze();
    } else {
        cout << "\nNo solution found.\n";
    }

    return 0;
}

void initMaze() {
    maze = vector<vector<char>>(rows, vector<char>(cols, WALL));
}

void printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j];
        }
        cout << '\n';
    }
}

bool isInBounds(int x, int y) {
    return x > 0 && y > 0 && x < rows - 1 && y < cols - 1;
}

void generateMaze(int x, int y) {
    maze[x][y] = PATH;
    vector<int> dirs = {0, 1, 2, 3};
    random_shuffle(dirs.begin(), dirs.end());

    for (int dir : dirs) {
        int nx = x + dx[dir] * 2;
        int ny = y + dy[dir] * 2;

        if (isInBounds(nx, ny) && maze[nx][ny] == WALL) {
            maze[x + dx[dir]][y + dy[dir]] = PATH;
            generateMaze(nx, ny);
        }
    }
}

bool solveMaze(int x, int y, int ex, int ey) {
    if (x == ex && y == ey) {
        maze[x][y] = VISITED_PATH;
        return true;
    }

    if (!isInBounds(x, y) || maze[x][y] != PATH)
        return false;

    maze[x][y] = VISITED_PATH;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (solveMaze(nx, ny, ex, ey))
            return true;
    }

    maze[x][y] = PATH;
    return false;
}
