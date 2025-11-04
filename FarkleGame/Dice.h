/*
 ============================================================================
 File        : Dice.h
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Declaration of the Dice class that provides
               random number generation for dice rolls.
 ============================================================================
*/

#pragma once
#include <vector>

class Dice {
public:
    // Rolls a given number of six-sided dice and returns the results as a vector
    static std::vector<int> rollDice(int numDice);
};

