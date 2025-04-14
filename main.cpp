#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Maze Generator Project (C++)" << endl;
    srand(time(0));
    initMaze();
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
