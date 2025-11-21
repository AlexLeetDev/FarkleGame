/*
 ============================================================================
 File        : Player.cpp
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Implementation of the Player class methods for
               managing name, score, and entry into the game.
 ============================================================================
*/

#include "Player.h"

// ------------------------------------------------------------
// Constructor
// ------------------------------------------------------------
Player::Player(const std::string& playerName)
    : name(playerName), score(0), entered(false) {
}

// ------------------------------------------------------------
// Getters
// ------------------------------------------------------------
std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

bool Player::hasEntered() const {
    return entered;
}

// ------------------------------------------------------------
// Setters / Modifiers
// ------------------------------------------------------------
void Player::addScore(int amount) {
    score += amount;
}

void Player::setEntered(bool status) {
    entered = status;
}