/*
 ============================================================================
 File        : Game.h
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Declaration of the Game class for handling
               Farkle game setup, turn logic, and end conditions.
 ============================================================================
*/

#pragma once
#include "Player.h"
#include <vector>

class Game {
private:
    std::vector<Player> players;     // All players in the game
    Player* leadingPlayer;           // Points to the player with the highest score
    bool gameOver;                   // True when the game ends

    void setup();                    // Get number of players and their names
    void play();                     // Main game loop
    void playerTurn(Player& player); // Handles one player's turn
    void endGame();                  // Shows the winner and ends the game

    // Calculates total score and identifies which dice are scoring
    int calculateScore(const std::vector<int>& dice, std::vector<int>& scoringDice);

public:
    void start();                    // Starts the full game process
};