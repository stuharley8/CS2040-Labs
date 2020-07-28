/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef ROOM_H
#define ROOM_H

#include "Container.h"
 
class Room : public Container
{
private:
    int name;
    int north;
    int south;
    int east;
    int west;
public:
    Room();
    ~Room() override { };
    void setName(const int name) { this -> name = name; }
    void setNorth(const int roomName) { this -> north = roomName; }
    void setSouth(const int roomName) { this -> south = roomName; }
    void setEast(const int roomName) { this -> east = roomName; }
    void setWest(const int roomName) {this -> west = roomName; }
    int getName() const { return name; }
    int getNorth() const { return north; }
    int getSouth() const { return south; }
    int getEast() const { return east; }
    int getWest() const { return west; }
    void printItems() const override;
    void printDoors() const;
    bool hasExit() const;
};
 
#endif