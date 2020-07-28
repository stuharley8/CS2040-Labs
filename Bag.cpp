/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Bag.h"

#include <iostream>
#include <string>

Bag::Bag()
    :Container(10)
{
}

void Bag::printItems() const {
    std::cout << "\nYour bag contains the following items:" << std::endl;
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getName() != "") {
            std::cout << items[i]->getName() << " - " << items[i]->getType() << std::endl;
        }
    }
}

void Bag::printTreasure() const {
    std::cout << "\nYou escaped with the following treasure:" << std::endl;
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getType() == "treasure") {
            std::cout << items[i]->getName() << std::endl;
        }
    }
    std::cout << std::endl;
}

std::string Bag::getTeleporterName() const {
    std::string teleporterName = "";
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getType() == "teleporter") {
            teleporterName = items[i]->getName();
            break;
        }
    }
    return teleporterName;
}

bool Bag::hasKey() const {
    bool hasKey = false;
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getType() == "key") {
            hasKey = true;
            break;
        }
    }
    return hasKey;
}