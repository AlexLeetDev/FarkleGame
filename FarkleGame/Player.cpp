/*
 ============================================================================
 File        : Player.cpp
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Implementation of the Player class methods for
               managing name, score, and entry into the game.
 ============================================================================
*/

#include "Player.h"

// Constructor: initializes name, score to 0, and entry status to false
Player::Player(std::string playerName) : name(playerName), score(0), enteredGame(false) {}

// Returns the player's name
std::string Player::getName() const { return name; }

// Returns the player's current score
int Player::getScore() const { return score; }

// Adds points to the player's score
void Player::addScore(int points) { score += points; }

// Checks whether the player has officially entered the game
bool Player::hasEntered() const { return enteredGame; }

// Marks the player as having entered the game (after scoring 1000+ in one turn)
void Player::enterGame() { enteredGame = true; }