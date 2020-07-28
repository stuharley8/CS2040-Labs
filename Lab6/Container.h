/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#ifndef CONTAINER_H
#define CONTAINER_H

#include "Item.h"

#include <string>

class Container
{
protected:
    int maxItems;
    int numItems;
    Item** items;
public:
    Container(int maxItems);
    virtual ~Container();
    bool addItem(Item* const item);
    Item* removeItem(const std::string itemName);
    bool contains(std::string itemName) const;
    bool isFull() const;
    virtual void printItems() const = 0;
};

#endif