/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Item.h"

#include <string>

Item::Item()
    :name("")
{
}

Item::Item(std::string name) 
    :name(name)
{
}

Item::Item(const Item& other)
    :name(other.getName())
{
}