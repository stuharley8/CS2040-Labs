/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Maze.h"
#include "GameController.h"
#include "Key.h"
#include "Item.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main()
{
    try {
        std::cout << "Welcome to Room Raider\n" << std::endl;
        std::cout << "Please enter the path to your game configuration file:" << std::endl;
        std::string filename;
        std::cin >> filename;
        std::ifstream fin;
        fin.open(filename);
        if(!fin.good()) {
            std::cout << "Unable to load file" << std::endl;
            return 1;
        }
        std::ifstream* finptr = &fin;
        Maze maze = Maze(finptr);
        GameController gc = GameController(&maze);
        bool gameOver = false;
        while(!gameOver) {
            gc.printStatus();
            gameOver = gc.performAction();
        }
        maze.clean();
        return 0;
    } catch(std::exception e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
