/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef KEY_H
#define KEY_H

#include "Item.h"

#include <string>

class Key : public Item
{
public:
    Key(std::string itemName);
    Key(const Item& other);
    ~Key() override { };
    std::string getType() const override { return "key"; };
};

#endif