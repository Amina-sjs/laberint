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
        cout << '\n';
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