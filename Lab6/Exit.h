/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef EXIT_H
#define EXIT_H

#include "Item.h"

#include <string>

class Exit : public Item
{
public:
    Exit(std::string itemName);
    Exit(const Item& other);
    ~Exit() override { };
    std::string getType() const override { return "exit"; };
};

#endif