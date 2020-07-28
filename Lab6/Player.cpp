/*
* Course: CS-2040-041
* Spring 2020
* Lab 6 - Room Raider
* Name: Stuart Harley
* Created: 04/29/2020
*/

#include "Player.h"
#include "Bag.h"

Player::Player(int currentRoom)
    :currentRoom(currentRoom)
{
    bag = new Bag();
}

Player::~Player() {
    delete bag;
}

void Player::move(const int newRoom) {
    this -> currentRoom = newRoom;
}