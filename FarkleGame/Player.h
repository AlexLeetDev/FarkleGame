/*
 ============================================================================
 File        : Player.h
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Declaration of the Player class used to store
			   and manage player names, scores, and game entry status.
 ============================================================================
*/

#pragma once
#include <string>

class Player {
private:
    std::string name;   // Player name
    int score;          // Total score
    bool entered;       // Tracks whether player has reached 500 points in a turn

public:
    // Constructor
    Player(const std::string& playerName);

    // Getters
    std::string getName() const;
    int getScore() const;
    bool hasEntered() const;

    // Setters / Modifiers
    void addScore(int amount);
    void setEntered(bool status);
};
