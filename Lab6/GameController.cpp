/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "GameController.h"
#include "Key.h"

#include <iostream>
#include <string>
#include <algorithm>

GameController::GameController(Maze* maze)
    :maze(maze)
{
}

void GameController::printStatus() const {
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    std::cout << "\nYou are in one of the maze rooms. A sign on the wall says, ";
    int currentRoom = maze->getPlayer()->getLocation();
    std::cout << "'Welcome to room " << currentRoom << "'." << std::endl;
    std::cout << "Looking around you see the following items:" << std::endl;
    maze->getRoom(currentRoom).printItems();
    std::cout << "The room has doors in the following directions:" << std::endl;
    maze->getRoom(currentRoom).printDoors();
}

bool GameController::performAction() {
    bool gameOver = false;
    std::cout << "\nWhat would you like to do?" << std::endl;
    std::string action;
    std::cin >> action;
    transform(action.begin(), action.end(), action.begin(), ::tolower);
    if(action == "move") {
        move();
    } else if(action == "take") {
        take();
    } else if(action == "drop") {
        drop();
    } else if(action == "showbag") {
        maze->getPlayer()->getBag()->printItems();
    } else if(action == "teleport") {
        teleport();
    } else if(action == "help") {
        help();
    } else if(action == "unlock") {
        gameOver = unlock();
        if(gameOver) { maze->getPlayer()->getBag()->printTreasure(); }
    } else if(action == "exit") {
        std::cout << "\nYou lost :(" << std::endl;
        gameOver = true;
    } else {
        std::cout << "\nI don't know how to " << action << "." << std::endl;
    }
    return gameOver;
}

void GameController::move() {
    int currentRoom = maze->getPlayer()->getLocation();
    std::string direction;
    std::cin >> direction;
    transform(direction.begin(), direction.end(), direction.begin(), ::tolower);
    if(direction == "north") {
        if(maze->getRoom(currentRoom).getNorth() != -1) {
            maze->movePlayer("north");
        } else {
            std::cout << "\nYou can't move in that direction!" << std::endl;
        }
    } else if(direction == "east") {
        if(maze->getRoom(currentRoom).getEast() != -1) {
            maze->movePlayer("east");
        } else {
            std::cout << "\nYou can't move in that direction!" << std::endl;
        }
    } else if(direction == "south") {
        if(maze->getRoom(currentRoom).getSouth() != -1) {
            maze->movePlayer("south");
        } else {
            std::cout << "nYou can't move in that direction!" << std::endl;
        }
    } else if(direction == "west") {
        if(maze->getRoom(currentRoom).getWest() != -1) {
            maze->movePlayer("west");
        } else {
            std::cout << "\nYou can't move in that direction!" << std::endl;
        }
    } else {
        std::cout << "\nThat is not a valid direction!" << std::endl;
    }
}

void GameController::take() {
    std::string itemName;
    std::cin >> itemName;
    std::string lowerItemName = itemName;
    transform(lowerItemName.begin(), lowerItemName.end(), lowerItemName.begin(), ::tolower);
    if(maze->getRoom(maze->getPlayer()->getLocation()).contains(lowerItemName)) {
        if(maze->getPlayer()->getBag()->isFull()) {
            std::cout << "\nYour bag is already full!" << std::endl;
        } else {
            Item* item = maze->getRoom(maze->getPlayer()->getLocation()).removeItem(lowerItemName);
            if(item->getType() != "exit") {
                maze->getPlayer()->getBag()->addItem(item);
                std::cout << "\n" << itemName << " picked up and added to your bag." << std::endl;
            } else {
                maze->getRoom(maze->getPlayer()->getLocation()).addItem(item);
                std::cout << "\nYou can't pick up an exit!" << std::endl;
            }
        }
    } else {
        std::cout << "\nYou dont see a " << itemName << " to take!" << std::endl;
    }
}

void GameController::drop() {
    std::string itemName;
    std::cin >> itemName;
    std::string lowerItemName = itemName;
    transform(lowerItemName.begin(), lowerItemName.end(), lowerItemName.begin(), ::tolower);
    if(maze->getPlayer()->getBag()->contains(lowerItemName)) {
        if(maze->getRoom(maze->getPlayer()->getLocation()).isFull()) {
            std::cout << "\nThe room cannot contain any more items!" << std::endl;
        } else {
            Item* item = maze->getPlayer()->getBag()->removeItem(lowerItemName);
            maze->getRoom(maze->getPlayer()->getLocation()).addItem(item);
            std::cout << "\n" << itemName << " dropped." << std::endl;
        }
    }
}

void GameController::teleport() {
    int roomNumber;
    std::cin >> roomNumber;
    std::string teleporterName = maze->getPlayer()->getBag()->getTeleporterName();
    transform(teleporterName.begin(), teleporterName.end(), teleporterName.begin(), ::tolower);
    if(teleporterName != "") {
        maze->getPlayer()->move(roomNumber);
        maze->getPlayer()->getBag()->removeItem(teleporterName);
        std::cout << "\nAs if by magic you are transported to room " << roomNumber << std::endl;
    } else {
        std::cout << "\nYou can't teleport without a teleporter!" << std::endl;
    }
}

void GameController::help() const {
    std::cout << "\nCommands:" << std::endl;
    std::cout << "move <direction> - move the player in the given direction" << std::endl;
    std::cout << "take <item> - pickup an item, by name, from the room into your bag" << std::endl;
    std::cout << "drop <item> - drop an item, by name, from your bag into the room" << std::endl;
    std::cout << "showbag - prints the contents of the bag" << std::endl;
    std::cout << "teleport <room> - teleports you to the given room (if you have a teleporter)" << std::endl;
    std::cout << "help - prints out a list of commands and a short description of each" << std::endl;
    std::cout << "unlock - unlocks the exit to the maze, if you have the key, and are in the room with the exit (you win)" << std::endl;
    std::cout << "exit - exits the game (you lose)" << std::endl;
}

bool GameController::unlock() {
    bool hasExit = maze->getRoom(maze->getPlayer()->getLocation()).hasExit();
    bool hasKey = maze->getPlayer()->getBag()->hasKey();
    bool successfulUnlock = false;
    if(hasExit && hasKey) {
        std::cout << "\nCongratulations! You escaped the maze!" << std::endl;
        successfulUnlock = true;
    } else if(!hasExit && hasKey) {
        std::cout << "\nYou are not in the room with the exit!" << std::endl;
    } else if(hasExit && !hasKey) {
        std::cout << "\nYou do not have the key to open the exit!" << std::endl;
    } else {
        std::cout << "\nYou are not in the room with the exit and you do not have the key!" << std::endl;
    }
    return successfulUnlock;
}