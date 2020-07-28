#include <iostream>

using namespace std;

/**
 * @brief Gets the dimension of the screen from the user
 * @param turtlex
 * @param turtley
 * @return the dimension of the screen
 */
int getUserDimension() {
    cout << "Enter the dimensions of the screen:" << endl;
    int size;
    cin >> size;
    return size;
}

/**
 * @brief Gets the starting point for the turtle from the user
 * @param turtlex
 * @param turtley
 */
void getUserStartingPoint(int& turtlex, int& turtley) {
    cout << "Enter the turtle's starting location:" << endl;
    cin >> turtlex;
    cin >> turtley;
}

/**
 * @brief Initializes the grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 * @return 
 */
char** initializeGrid(int gridSize, int turtlex, int turtley) {
    char** grid = new char*[gridSize];
    for(int i = 0; i < gridSize; i++) {
        grid[i] = new char[gridSize];
        for(int j = 0; j < gridSize; j++) {
            grid[i][j] = ' ';
        }
    }
    grid[turtlex][turtley] = 'X';
    return grid;
}

/**
 * @brief Prints the Screen
 * @param grid
 * @param gridSize
 */
void printGrid(char** grid, int gridSize) {
    cout << endl;
    for(int i = 0; i < gridSize+2; i++) {
        cout << "*";
    }
    cout << endl;
    for(int i = 0; i < gridSize; i++) {
        cout << "*";
        for(int j = 0; j < gridSize; j++) {
            cout << grid[i][j];
        }
        cout << "*" << endl;
    }
    for(int i = 0; i < gridSize+2; i++) {
        cout << "*";
    }
    cout << endl;
    cout << endl;
}