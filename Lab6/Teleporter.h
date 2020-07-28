/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "Item.h"

#include <string>

class Teleporter : public Item
{
public:
    Teleporter(std::string itemName);
    Teleporter(const Item& other);
    ~Teleporter() override { };
    std::string getType() const override { return "teleporter"; };
};

#endif