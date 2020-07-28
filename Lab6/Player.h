/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef PLAYER_H
#define PLAYER_H

#include "Bag.h"

#include <string>

class Player
{
private:
    int currentRoom;
    Bag* bag;
public:
    Player(int currentRoom);
    ~Player();
    int getLocation() const { return currentRoom; }
    Bag* getBag() const { return bag; }
    void move(const int newRoom);
};

#endif