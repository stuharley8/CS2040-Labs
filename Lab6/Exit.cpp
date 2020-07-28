/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Exit.h"

Exit::Exit(std::string itemName)
    :Item(itemName)
{
}

Exit::Exit(const Item& other)
    :Item(other)
{
}