#include <string>

#include "screen.h"

using namespace std;

static char previous = ' '; // stores what was previously in the space the turtle is moving too (needed when pen is up)

/**
 * @brief Moves the turtle up
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveUp(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '|';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex--;
    if(turtlex < 0) {
        turtlex = gridSize - 1;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle up right
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveUpR(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '/';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex--;
    turtley++;
    if(turtlex < 0) {
        turtlex = gridSize - 1;
    }
    if(turtley >= gridSize) {
        turtley = 0;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle right
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveR(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '-';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtley++;
    if(turtley >= gridSize) {
        turtley = 0;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle down right
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveDownR(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '\\';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex++;
    turtley++;
    if(turtlex >= gridSize) {
        turtlex = 0;
    }
    if(turtley >= gridSize) {
        turtley = 0;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle down
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveDown(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '|';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex++;
    if(turtlex >= gridSize) {
        turtlex = 0;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle down left
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveDownL(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '/';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex++;
    turtley--;
    if(turtlex >= gridSize) {
        turtlex = 0;
    }
    if(turtley < 0) {
        turtley = gridSize - 1;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle left
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveL(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '-';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtley--;
    if(turtley < 0) {
        turtley = gridSize - 1;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle up left
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void moveUpL(bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(penDown) {
        grid[turtlex][turtley] = '\\';
    } else {
        grid[turtlex][turtley] = previous;
    }
    turtlex--;
    turtley--;
    if(turtlex < 0) {
        turtlex = gridSize - 1;
    }
    if(turtley < 0) {
        turtley = gridSize - 1;
    }
    previous = grid[turtlex][turtley];
    grid[turtlex][turtley] = 'X';
}

/**
 * @brief Moves the turtle forward
 * @param orientation
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void forward(string* orientation, bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(*orientation == "up") {
        moveUp(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "upR") {
        moveUpR(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "right") {
        moveR(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "downR") {
        moveDownR(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "down") {
        moveDown(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "downL") {
        moveDownL(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "left") {
        moveL(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "upL") {
        moveUpL(penDown, grid, gridSize, turtlex, turtley);
    }
}

/**
 * @brief Moves the turtle backward
 * @param orientation
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 */
void backward(string* orientation, bool penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(*orientation == "up") {
        moveDown(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "upR") {
        moveDownL(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "right") {
        moveL(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "downR") {
        moveUpL(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "down") {
        moveUp(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "downL") {
        moveUpR(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "left") {
        moveR(penDown, grid, gridSize, turtlex, turtley);
    } else if(*orientation == "upL") {
        moveDownR(penDown, grid, gridSize, turtlex, turtley);
    }
}

/**
 * @brief Rotates the turtle right 45 degrees
 * @param orientation
 */
void rotateRight(string* orientation) {
    if(*orientation == "up") {
        *orientation = "upR";
    } else if(*orientation == "upR") {
        *orientation = "right";
    } else if(*orientation == "right") {
        *orientation = "downR";
    } else if(*orientation == "downR") {
        *orientation = "down";
    } else if(*orientation == "down") {
        *orientation = "downL";
    } else if(*orientation == "downL") {
        *orientation = "left";
    } else if(*orientation == "left") {
        *orientation = "upL";
    } else if(*orientation == "upL") {
        *orientation = "up";
    }
}

/**
 * @brief Rotates the turtle left 45 degrees
 * @param orientation
 */
void rotateLeft(string* orientation) {
    if(*orientation == "up") {
        *orientation = "upL";
    } else if(*orientation == "upR") {
        *orientation = "up";
    } else if(*orientation == "right") {
        *orientation = "upR";
    } else if(*orientation == "downR") {
        *orientation = "right";
    } else if(*orientation == "down") {
        *orientation = "downR";
    } else if(*orientation == "downL") {
        *orientation = "down";
    } else if(*orientation == "left") {
        *orientation = "downL";
    } else if(*orientation == "upL") {
        *orientation = "left";
    }
}

/**
 * @brief Exectutes a user command
 * @param command
 * @param orientation
 * @param penDown
 * @param grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 * @return true if successful, false if not
 */
bool applyCommand(string command, string* orientation, bool& penDown, char** grid, int gridSize, int& turtlex, int& turtley) {
    if(command == "FD") {
        forward(orientation, penDown, grid, gridSize, turtlex, turtley);
    } else if(command == "BK") {
        backward(orientation, penDown, grid, gridSize, turtlex, turtley);
    } else if(command == "RT") {
        rotateRight(orientation);
    } else if(command == "LT") {
        rotateLeft(orientation);
    } else if(command == "PU") {
        penDown = false;
    } else if(command == "PD") {
        penDown = true;
    } else {
        return false;
    }
    return true;
}