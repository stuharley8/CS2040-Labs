/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Container.h"
#include "Item.h"
#include "Key.h"
#include "Exit.h"
#include "Teleporter.h"
#include "Treasure.h"

#include <string>
#include <algorithm>

Container::Container(int maxItems)
    :maxItems(maxItems), numItems(0)
{
    this -> items = new Item*[maxItems];
    for(int i = 0; i < maxItems; i++) {
        items[i] = new Item();
    }
}

Container::~Container()
{
    for(int i = 0; i < maxItems; i++) {
        delete items[i];
    }
    delete [] items;
}

bool Container::addItem(Item* const item) {
    bool added = false;
    for(int i = 0; i < maxItems; i++) {
        if(items[i]->getName() == "") {
            delete items[i];
            items[i] = item;
            added = true;
            numItems++;
            break;
        }
    }
    return added;
}

Item* Container::removeItem(const std::string itemName) {
    Item* removed;
    for(int i = 0; i < maxItems; i++) {
        std::string name = items[i]->getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == itemName) {
            if(items[i]->getType() == "key") {
                removed = new Key(*items[i]);
            } else if(items[i]->getType() == "exit") {
                removed = new Exit(*items[i]);
            } else if(items[i]->getType() == "teleporter") {
                removed = new Teleporter(*items[i]);
            } else if(items[i]->getType() == "treasure") {
                removed = new Treasure(*items[i]);
            } else {
                removed = new Item(*items[i]);
            }
            delete items[i];
            items[i] = new Item();
            numItems--;
            break;
        }
    }
    return removed;
}

bool Container::contains(std::string itemName) const {
    bool contains = false;
    for(int i = 0; i < maxItems; i++) {
        std::string name = items[i]->getName();
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == itemName) {
            contains = true;
            break;
        }
    }
    return contains;
}

bool Container::isFull() const {
    if(numItems == maxItems) {
        return true;
    } else {
        return false;
    }
}