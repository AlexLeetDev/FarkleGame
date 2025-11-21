/*
 ============================================================================
 File        : Dice.h
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Declaration of the Dice class that provides
               random number generation for dice rolls.
 ============================================================================
*/

#pragma once
#include <vector>

class Dice {
public:
    // Roll a single die (1–6)
    int roll();

    // Roll multiple dice based on count
    std::vector<int> rollMultiple(int count);
};

