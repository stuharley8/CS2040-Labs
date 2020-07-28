/* 
 * Course: CS 2040-041
 * Spring 2020
 * BattleBouy Exercise
 * Author: Stuart Harley
 * Created: 3/22/2020
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void randomizeBouys(int grid[10][10]);
int printGrid(int grid[10][10], int guesses[10][10]);
void userGuess(int grid[10][10], int guesses[10][10]);

int main() {
    std::cout << "Welcome to Battlebouy" << std::endl;
    int grid[10][10];
    int guesses[10][10];
    for(int i = 0; i < 10; i++) {
       for(int j = 0; j < 10; j++) {
           guesses[i][j] = 0;
       } 
    }
    randomizeBouys(grid);
    printGrid(grid, guesses);
    int guess_count = 0;
    int correct = 0;
    while(correct != 5) {
        userGuess(grid, guesses);
        correct = printGrid(grid, guesses);
        guess_count++;
    }
    std::cout << "Congratulations, you hit all the bouys. ";
    std::cout << "It took you " << guess_count << " guesses." << std::endl;
    return 0;
}

/**
 * @brief Randomizes 5 bouys into the grid
 * @param grid will contain the locations of the bouys
 */
void randomizeBouys(int grid[10][10]) {
    // Initialize all grid elements to 0 (empty locations)
    for(int i = 0; i < 10; i++) {
       for(int j = 0; j < 10; j++) {
           grid[i][j] = 0;
       } 
    }
    // Initialize the first 5 elements of the grid to 1 (buoys)
    for(int i = 0; i < 5; i++) {
        grid[i][0] = 1;
    }
    // Seed the random number generator based on the current time
    srand(time(0));
    // Randomly shuffle the grid
    std::random_shuffle(std::begin(grid[0]), std::end(grid[9]));
}

/**
 * @brief Prints the grid
 * @param grid contains the locations of the bouys
 * @param guesses contains the locations of valid guesses
 * @return the number of correct guesses in guesses
 */
int printGrid(int grid[10][10], int guesses[10][10]) {
    int correct_count = 0;
    std::cout << std::endl;
    std::cout << "   0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "  ---------------------" << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << i << " |";
        for(int j = 0; j < 10; j++) {
            if(guesses[i][j] == 1 && grid[i][j] == 0) {
                std::cout << "O ";
            } else if(guesses[i][j] == 1 && grid[i][j] == 1) {
                std::cout << "X ";
                correct_count++;
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "  ---------------------\n" << std::endl;
    return correct_count;
}

/**
 * @brief Method processes a user guess
 * @param guesses contains the locations of valid guesses
 */
void userGuess(int grid[10][10], int guesses[10][10]) {
    std::cout << "Enter a target:" << std::endl;
    int x;
    int y;
    std::cin >> y;
    std::cin >> x;
    if(x < 0 || x > 9 || y < 0 || y > 9) {
        std::cout << "Target not valid!" << std::endl;
    } else {
        if(guesses[x][y] == 1) {
            std::cout << "You already guessed that target!" << std::endl;
        } else {
            guesses[x][y] = 1;
            if(grid[x][y] == guesses[x][y]) {
                std::cout << "Hit!" << std::endl;
            } else {
                std::cout << "Miss!" << std::endl;
            }
        }
    }
}
