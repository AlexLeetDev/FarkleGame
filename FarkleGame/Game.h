/*
 ============================================================================
 File        : Game.h
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Declaration of the Game class for handling
               Farkle game setup, turn logic, and end conditions.
 ============================================================================
*/

#pragma once
#include "Player.h"
#include <vector>

class Game {
private:
    // --- Core Game State ---
    std::vector<Player> players;     // All players in the game
    Player* leadingPlayer;           // Tracks player with the highest score
    bool gameOver;                   // True when the game ends

    // --- Game Flow ---
    void setup();                    // Get player count and names
    void play();                     // Main game loop
    void playerTurn(Player& player); // Handles a single player's turn
    void endGame();                  // Shows the winner and ends the game

    // --- Scoring & Validation (Hybrid Scoring System) ---
    int calculateScore(const std::vector<int>& roll,
                       std::vector<int>& scoringDice);

    bool isValidSelection(const std::vector<int>& scoringDice,
                       const std::vector<int>& keptDice);

    int calculateKeptScore(const std::vector<int>& keptDice);

    // --- Special Combination Helpers ---
    bool isStraight(const int counts[7]);     // Detects 1–6 straight
    bool isThreePairs(const int counts[7]);   // Detects three pairs

public:
    void start();                    // Starts the game
};