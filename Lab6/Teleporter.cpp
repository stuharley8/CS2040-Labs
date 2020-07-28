/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Teleporter.h"

#include <string>

Teleporter::Teleporter(std::string itemName)
    :Item(itemName)
{        
}

Teleporter::Teleporter(const Item& other)
    :Item(other)
{
}