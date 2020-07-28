/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/
 
#ifndef MAZE_H
#define MAZE_H

#include "Room.h"
#include "Player.h"

#include <fstream>
 
class Maze
{
private:
    int numRooms;
    Room* rooms;
    Player* player;
    void setRoomConnections(std::ifstream* fin);
    void setItems(std::ifstream* fin);
public:
    Maze(std::ifstream* fin);
    void clean();
    void movePlayer(const std::string direction);
    Player* getPlayer() const { return player; }
    Room& getRoom(int name) const;
};

#endif