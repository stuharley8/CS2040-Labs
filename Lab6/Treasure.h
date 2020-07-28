/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef TREASURE_H
#define TREASURE_H

#include "Item.h"

#include <string>

class Treasure : public Item
{
public:
    Treasure(std::string itemName);
    Treasure(const Item& other);
    ~Treasure() override { };
    std::string getType() const override { return "treasure"; };
};

#endif