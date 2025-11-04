/*
 ============================================================================
 File        : Game.cpp
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Contains the Game class implementation for Farkle.
 ============================================================================
*/

#include "Game.h"
#include "Dice.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

// Calculates score from the specific dice the player chose to keep
int calculateKeptScore(const vector<int>& kept) {
    int counts[7] = { 0 };  // counts[1] to counts[6]
    for (int die : kept) {
        if (die >= 1 && die <= 6)
            counts[die]++;
    }

    int score = 0;

    // Triples
    for (int i = 1; i <= 6; ++i) {
        if (counts[i] >= 3) {
            score += (i == 1) ? 1000 : i * 100;
            counts[i] -= 3;
        }
    }

    // Extra 1s and 5s after triples
    score += counts[1] * 100;
    score += counts[5] * 50;

    return score;
}

// Checks if the dice the player wants to keep are valid scoring dice
bool isValidSelection(const vector<int>& scoringDice, const vector<int>& keptDice) {
    vector<int> temp = scoringDice;
    for (int val : keptDice) {
        auto it = find(temp.begin(), temp.end(), val);
        if (it == temp.end()) return false;
        temp.erase(it);
    }
    return !keptDice.empty(); // Must keep at least one die
}

// Calculates which dice are scoring and returns the total score
int Game::calculateScore(const vector<int>& dice, vector<int>& scoringDice) {
    int counts[7] = { 0 };
    for (int die : dice) counts[die]++;

    int score = 0;
    for (int i = 1; i <= 6; ++i) {
        if (counts[i] >= 3) {
            score += (i == 1) ? 1000 : i * 100;
            counts[i] -= 3;
            scoringDice.insert(scoringDice.end(), 3, i);
        }
    }

    score += counts[1] * 100;
    score += counts[5] * 50;

    for (int i = 1; i <= 6; ++i) {
        if (i == 1 || i == 5) {
            for (int j = 0; j < counts[i]; ++j) {
                scoringDice.push_back(i);
            }
        }
    }

    return score;
}

// Starts the game by calling setup and play
void Game::start() {
    setup();
    play();
    endGame();
}

// Setup: get number of players and their names
void Game::setup() {
    int numPlayers;
    cout << "\nHow many players? ";
    cin >> numPlayers;

    while (numPlayers < 2) {
        cout << "Need at least 2 players. Try again: ";
        cin >> numPlayers;
    }

    for (int i = 0; i < numPlayers; ++i) {
        string name;
        cout << "Enter name for Player " << (i + 1) << ": ";
        cin >> name;
        players.push_back(Player(name));
    }

    gameOver = false;
    leadingPlayer = nullptr;
}

// Main gameplay loop
void Game::play() {
    while (!gameOver) {
        for (auto& player : players) {
            cout << "\n--- " << player.getName() << "'s Turn ---\n";
            playerTurn(player);

            if (player.getScore() >= 10000 && player.hasEntered()) {
                gameOver = true;
                leadingPlayer = &player;
                cout << "\n" << player.getName() << " has reached 10,000 points!\n";
                break;
            }
        }
    }

    // Final round for the rest of the players
    cout << "\n--- Final Round for Remaining Players ---\n";
    for (auto& player : players) {
        if (&player != leadingPlayer) {
            cout << "\n--- " << player.getName() << "'s Final Turn ---\n";
            playerTurn(player);
            if (player.getScore() > leadingPlayer->getScore()) {
                leadingPlayer = &player;
            }
        }
    }
}

// Handles one player's turn
void Game::playerTurn(Player& player) {
    int turnScore = 0;
    bool enteredGame = player.hasEntered();
    bool continueRolling = true;
    int diceToRoll = 6;
    bool mustReroll = false;

    while (continueRolling) {
        // Roll the dice
        vector<int> roll = Dice::rollDice(diceToRoll);
        cout << "Rolled: ";
        for (int die : roll) cout << die << " ";
        cout << endl;

        // Show scoring dice
        vector<int> scoringDice;
        int score = calculateScore(roll, scoringDice);

        if (score == 0) {
            cout << "Farkle! No scoring dice.\n";
            turnScore = 0;
            break;
        }

        cout << "Scoring dice: ";
        for (int die : scoringDice) cout << die << " ";
        cout << "\nEnter the dice you want to keep (e.g., 1 5): ";

        // Get player's selection
        vector<int> keptDice;
        string line;
        cin.ignore();
        getline(cin, line);
        stringstream ss(line);
        int dieChoice;
        while (ss >> dieChoice) keptDice.push_back(dieChoice);

        // Validate selection
        if (!isValidSelection(scoringDice, keptDice)) {
            cout << "Invalid selection. You must choose only from the scoring dice and keep at least one.\n";
            continue;
        }

        // Calculate score from kept dice
        int keptScore = calculateKeptScore(keptDice);
        turnScore += keptScore;

        // Show player's current turn score and entry status
        if (!enteredGame) {
            cout << player.getName() << "'s current turn score: " << turnScore << "\n";
            cout << "(Not entered yet. Reach 1000 points in one turn to start scoring.)\n";
        }
        else {
            cout << player.getName() << "'s current turn score: " << turnScore << "\n";
            cout << "Your total score (if you stop now) would be: " << player.getScore() + turnScore << "\n";
        }

        // Check if player qualifies to enter the game
        if (!enteredGame && turnScore >= 1000) {
            enteredGame = true;
            player.enterGame();
            cout << player.getName() << " has entered the game!\n";
        }

        // Determine how many dice are left to roll
        diceToRoll -= static_cast<int>(keptDice.size());
        if (diceToRoll == 0) {
            cout << "All dice scored! You must roll all six again.\n";
            diceToRoll = 6;
        }

        // Ask player if they want to continue
        string choice;
        cout << "Turn score: " << turnScore << ". Roll again? (y/n or q to quit): ";
        cin >> choice;

        if (choice == "q" || choice == "Q") {
            cout << "\nGame exited by player.\n";
            exit(0);
        }
        else if (choice != "y" && choice != "Y") {
            player.addScore(turnScore);
            cout << player.getName() << "'s total score: " << player.getScore() << "\n";
            continueRolling = false;
        }
        // Otherwise, loop continues
    }
}

// Display winner
void Game::endGame() {
    cout << "\n========================\n";
    cout << "Game Over!\n";
    cout << "Winner: " << leadingPlayer->getName()
        << " with " << leadingPlayer->getScore() << " points!\n";
    cout << "========================\n";
}