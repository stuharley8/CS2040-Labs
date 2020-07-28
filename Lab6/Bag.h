/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef BAG_H
#define BAG_H

#include "Container.h"

#include <string>
 
class Bag : public Container
{
public:
    Bag();
    ~Bag() override { };
    void printItems() const override;
    void printTreasure() const;
    std::string getTeleporterName() const;
    bool hasKey() const;
};
 
#endif