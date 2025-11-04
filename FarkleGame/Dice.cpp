/*
 ============================================================================
 File        : Dice.cpp
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Implementation of the Dice class that rolls
               a specified number of six-sided dice.
 ============================================================================
*/

#include "Dice.h"
#include <cstdlib>
#include <ctime>

// Rolls numDice six-sided dice and returns the results in a vector
std::vector<int> Dice::rollDice(int numDice) {
    std::vector<int> rolls;
    for (int i = 0; i < numDice; ++i) {
        // Generate a random number between 1 and 6
        rolls.push_back(rand() % 6 + 1);
    }
    return rolls;
}