#ifndef TURTLE_H
#define TURTLE_H

#include <string>

using namespace std;

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
bool applyCommand(string command, string* orientation, bool& penDown, char** grid, int gridSize, int& turtlex, int& turtley);

#endif