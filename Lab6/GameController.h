/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Maze.h"

class GameController
{
private:
    Maze* maze;
    void move();
    void take();
    void drop();
    void teleport();
    void help() const;
    bool unlock();
public:
    GameController(Maze* maze);
    void printStatus() const;
    bool performAction();
};

#endif