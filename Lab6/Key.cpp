/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Key.h"

#include <string>

Key::Key(std::string itemName)
    :Item(itemName)
{
}

Key::Key(const Item& other)
    :Item(other)
{
}