/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Room.h"
#include "Container.h"

#include <iostream>

Room::Room()
    :Container(5), name(-1), north(-1), south(-1), east(-1), west(-1) 
{
}

void Room::printItems() const {
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getName() != "") {
            std::cout << items[i]->getName() << std::endl;
        }
    }
}

void Room::printDoors() const {
    if(north != -1) {
        std::cout << "north" << std::endl;
    }
    if(east != -1) {
        std::cout << "east" << std::endl;
    }
    if(south != -1) {
        std::cout << "south" << std::endl;
    }
    if(west != -1) {
        std::cout << "west" << std::endl;
    }
}

bool Room::hasExit() const {
    bool hasExit = false;
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getType() == "exit") {
            hasExit = true;
            break;
        }
    }
    return hasExit;
}