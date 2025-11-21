/*
 ============================================================================
 File        : Dice.cpp
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Implementation of the Dice class that rolls
               a specified number of six-sided dice.
 ============================================================================
*/

#include "Dice.h"
#include <cstdlib>
#include <ctime>

// ------------------------------------------------------------
// Roll a single die (1–6)
// ------------------------------------------------------------
int Dice::roll() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    return (rand() % 6) + 1;
}

// ------------------------------------------------------------
// Roll multiple dice and return the results
// ------------------------------------------------------------
std::vector<int> Dice::rollMultiple(int count) {
    std::vector<int> result;
    result.reserve(count);

    for (int i = 0; i < count; i++) {
        result.push_back(roll());
    }

    return result;
}