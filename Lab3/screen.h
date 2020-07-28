#ifndef SCREEN_H
#define SCREEN_H

/**
 * @brief Gets the dimension of the screen from the user
 * @param turtlex
 * @param turtley
 * @return the dimension of the screen
 */
int getUserDimension();

/**
 * @brief Gets the starting point for the turtle from the user
 * @param turtlex
 * @param turtley
 */
void getUserStartingPoint(int& turtlex, int& turtley);

/**
 * @brief Initializes the grid
 * @param gridSize
 * @param turtlex
 * @param turtley
 * @return 
 */
char** initializeGrid(int gridSize, int turtlex, int turtley);

/**
 * @brief Prints the Screen
 * @param grid
 * @param gridSize
 */
void printGrid(char** grid, int gridSize);

#endif