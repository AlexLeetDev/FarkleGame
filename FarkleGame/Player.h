/*
 ============================================================================
 File        : Player.h
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Declaration of the Player class used to store
			   and manage player names, scores, and game entry status.
 ============================================================================
*/

#pragma once
#include <string>

class Player {
private:
	std::string name;		// Player's name
	int score;				// Current score
	bool enteredGame;		// True if player has reached 1000+ points in one turn

public:
	Player(std::string playerName);		// Constructor that sets player name

	std::string getName() const;		// Returns the player's name
	int getScore() const;				// Returns the player's score
	void addScore(int points);			// Adds points to the player's total score
	bool hasEntered() const;			// Checks if player has entered the game
	void enterGame();					// Marks the player as having entered the game
};
