/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Treasure.h"

#include <string>

Treasure::Treasure(std::string itemName)
    :Item(itemName)
{    
}

Treasure::Treasure(const Item& other)
    :Item(other)
{
}