#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Maze Generator Project (C++)" << endl;
    srand(time(0));
    initMaze();
    printMaze();
    generateMaze(1, 1);
    printMaze();
    solveMaze(1, 1, rows - 2, cols - 2);
    return 0;
}

const char WALL = '#';
const char PATH = ' ';
const int DEFAULT_ROWS = 21;
const int DEFAULT_COLS = 21;

int rows = DEFAULT_ROWS, cols = DEFAULT_COLS;
vector<vector<char>> maze;

void initMaze() {
    maze = vector<vector<char>>(rows, vector<char>(cols, WALL));
}

void printMaze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze[i][j];
        }
        cout << 'Done!\n';
    }
}


int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

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

maze[1][1] = PATH;  // Старт
maze[rows - 2][cols - 2] = PATH;  // Выход

const char VISITED_PATH = '.';

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
        if (solveMaze(nx, ny, ex, ey)) return true;
    }

    maze[x][y] = PATH;
    return false;
}

