/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef ITEM_H
#define ITEM_H

#include <string>
 
class Item
{
private:
    std::string name;
public:
    Item();
    Item(std::string name);
    Item(const Item& other);
    virtual ~Item() { };
    std::string getName() const { return name; };
    virtual std::string getType() const { return "item"; };
};
 
#endif