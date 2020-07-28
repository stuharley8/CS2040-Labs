/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Maze.h"
#include "Room.h"
#include "Player.h"
#include "Item.h"
#include "Key.h"
#include "Teleporter.h"
#include "Treasure.h"
#include "Exit.h"

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>

Maze::Maze(std::ifstream* fin) {
    *fin >> this -> numRooms;
    this -> rooms = new Room[numRooms];
    for(int i = 0; i < numRooms; i++) {
        rooms[i].setName(i);
    }
    int playerLocation;
    *fin >> playerLocation;
    if(playerLocation > numRooms-1 || playerLocation < 0) {
        throw std::invalid_argument("Invalid starting player location");
    }
    this -> player = new Player(playerLocation);
    setRoomConnections(fin);
    setItems(fin);
}

void Maze::clean() {
    for(int i = 0; i < numRooms; i++) {
        rooms[i].~Room();
    }
    delete rooms;
    delete player;
}

void Maze::movePlayer(const std::string direction) {
    if(direction == "north") {
        if(rooms[player->getLocation()].getNorth() != -1) {
            player->move(rooms[player->getLocation()].getNorth());
        }
    } else if(direction == "south") {
        if(rooms[player->getLocation()].getSouth() != -1) {
            player->move(rooms[player->getLocation()].getSouth());
        }
    } else if(direction == "east") {
        if(rooms[player->getLocation()].getEast() != -1) {
            player->move(rooms[player->getLocation()].getEast());
        }
    } else if(direction == "west") {
        if(rooms[player->getLocation()].getWest() != -1) {
            player->move(rooms[player->getLocation()].getWest());
        }
    }
}

void Maze::setRoomConnections(std::ifstream* fin) {
    int sourceRoom;
    int destinationRoom;
    std::string direction;
    *fin >> sourceRoom;
    while(sourceRoom != -1) {
        *fin >> destinationRoom;
        *fin >> direction;
        if(direction == "north") {
            rooms[sourceRoom].setNorth(destinationRoom);
        } else if(direction == "south") {
            rooms[sourceRoom].setSouth(destinationRoom);
        } else if(direction == "east") {
            rooms[sourceRoom].setEast(destinationRoom);
        } else {
            rooms[sourceRoom].setWest(destinationRoom);
        }
        *fin >> sourceRoom;
    }
}

void Maze::setItems(std::ifstream* fin) {
    int roomIndex;
    std::string itemType;
    std::string itemName;
    *fin >> roomIndex;
    while(roomIndex != -1) {
        *fin >> itemType;
        *fin >> itemName;
        if(itemType == "key") {
            Item* key = new Key(itemName);
            rooms[roomIndex].addItem(key);
        } else if(itemType == "treasure") {
            Item* treasure = new Treasure(itemName);
            rooms[roomIndex].addItem(treasure);
        } else if(itemType == "teleporter") {
            Item* teleporter = new Teleporter(itemName);
            rooms[roomIndex].addItem(teleporter);
        } else {
            Item* exit = new Exit(itemName);
            rooms[roomIndex].addItem(exit);
        }
        *fin >> roomIndex;
    }
}

Room& Maze::getRoom(int name) const {
    return rooms[name];
}