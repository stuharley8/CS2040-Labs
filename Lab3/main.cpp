#include <iostream>
#include <string>
#include <fstream>

#include "turtle.h"
#include "screen.h"

using namespace std;

char** runFile(ifstream* fin, string* orientation, bool& penDown, int& gridSize, int& turtlex, int& turtley);

int main()
{
    int turtlex;
    int turtley;
    string orientation = "up";
    string* orientationptr = &orientation;
    bool penDown = true;
    int gridSize = getUserDimension(); // not const because the grid size can change when loading new files
    if(gridSize < 1 || gridSize > 99) {
        cout << "Invalid dimension. Goodbye." << endl;
        return 1;
    }
    getUserStartingPoint(turtlex, turtley);
    if(turtlex < 0 || turtlex >= gridSize || turtley < 0 || turtley >= gridSize) {
        cout << "Invalid starting location. Goodbye." << endl;
        return 1;
    }
    char** grid = initializeGrid(gridSize, turtlex, turtley);
    printGrid(grid, gridSize);
    cout << "Enter a command:" << endl;
    string command;
    cin >> command;
    while(cin) {
        if(command == "LD") {
            cout << "Enter a file to load (include the file extenion):" << endl;
            string filename;
            cin >> filename;
            ifstream fin;
            fin.open(filename);
            ifstream* finptr = &fin;
            if(!fin.good()) {
                cout << "Unable to load file" << endl;
            } else {
                delete grid;
                grid = runFile(finptr, orientationptr, penDown, gridSize, turtlex, turtley);
            }
        } else {
            while(!applyCommand(command, orientationptr, penDown, grid, gridSize, turtlex, turtley)) {
                cout << "Invalid command. Try Again:" << endl;
                cin >> command;
            }
        }
        printGrid(grid, gridSize);
        cout << "Enter a command:" << endl;
        cin >> command;
    }
    return 0;
}

/**
 * @brief Runs the commands specified in a succesfully loaded file
 * @param fin
 * @param orientation
 * @param penDown
 * @param gridSize
 * @param turtlex
 * @param turtley
 * @return the new grid created by the file
 */
char** runFile(ifstream* fin, string* orientation, bool& penDown, int& gridSize, int& turtlex, int& turtley) {
    *orientation = "up";
    penDown = true;
    *fin >> gridSize;
    *fin >> turtlex;
    *fin >> turtley;
    char** grid = initializeGrid(gridSize, turtlex, turtley);
    string command;
    *fin >> command;
    while(*fin) {
        applyCommand(command, orientation, penDown, grid, gridSize, turtlex, turtley);
        *fin >> command;
    }
    return grid;
}
