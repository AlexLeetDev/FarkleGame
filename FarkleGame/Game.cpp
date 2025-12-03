/*
 ============================================================================
 File        : Game.cpp
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Contains the Game class implementation for Farkle.
 ============================================================================
*/

#include "Game.h"
#include "Dice.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

// ------------------------------------------------------------
// Starts the game
// ------------------------------------------------------------
void Game::start() {
    gameOver = false;
    leadingPlayer = nullptr;

    setup();
    play();
    endGame();
}

// ------------------------------------------------------------
// Setup: number of players and their names
// ------------------------------------------------------------
void Game::setup() {
    int numPlayers = 0;

    cout << "How many players? ";
    cin >> numPlayers;

    while (numPlayers < 2) {
        cout << "Need at least 2 players. Try again: ";
        cin >> numPlayers;
    }

    players.clear();
    players.reserve(numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        string name;
        cout << "Enter name for Player " << (i + 1) << ": ";
        cin >> name;
        players.emplace_back(name);
    }

    cout << "\nGame starting with " << numPlayers << " players...\n\n";
}

// ------------------------------------------------------------
// Main game loop
// ------------------------------------------------------------
void Game::play() {
    const int WINNING_SCORE = 10000;

    while (!gameOver) {
        for (auto& player : players) {
            playerTurn(player);

            if (player.getScore() >= WINNING_SCORE) {
                leadingPlayer = &player;
                gameOver = true;
                break;
            }
        }
    }
}

// ------------------------------------------------------------
// Handles a single player's turn
// ------------------------------------------------------------
void Game::playerTurn(Player& player) {
    cout << "\n--- " << player.getName() << "'s Turn ---\n";

    Dice dice;
    int turnScore = 0;
    int diceToRoll = 6;
    bool continueTurn = true;

    while (continueTurn) {
        vector<int> roll = dice.rollMultiple(diceToRoll);

        cout << "Rolled: ";
        for (int d : roll) cout << d << " ";
        cout << "\n";

        vector<int> scoringDice;
        int score = calculateScore(roll, scoringDice);

        if (score == 0) {
            cout << "Farkle! No scoring dice.\n";
            turnScore = 0;
            return;  // Turn ends immediately, no banking
        }

        cout << "Scoring dice: ";
        for (int d : scoringDice) cout << d << " ";
        cout << "\n";

        // Ask player which dice to keep
        cout << "Enter the dice you want to keep (e.g., 1 5 5): ";
        vector<int> keptDice;
        int value;

        cin.clear();
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);

        while (ss >> value) {
            keptDice.push_back(value);
        }

        // Validate selection
        while (!isValidSelection(scoringDice, keptDice)) {
            cout << "Invalid selection. Choose only from scoring dice.\n";
            cout << "Enter the dice you want to keep: ";

            keptDice.clear();
            getline(cin >> ws, line);
            stringstream ss2(line);
            while (ss2 >> value) keptDice.push_back(value);
        }

        // Add points for kept dice
        int keptScore = calculateKeptScore(keptDice);
        turnScore += keptScore;

        cout << player.getName() << "'s current turn score: " << turnScore << "\n";

        // ------------------------------------------------------------
        // AUTO-ENTER LOGIC
        // ------------------------------------------------------------
        if (!player.hasEntered() && turnScore >= 500) {
            player.setEntered(true);
            cout << player.getName() << " has now entered the game!\n";
        }

        // Set up next roll
        diceToRoll -= static_cast<int>(keptDice.size());
        if (diceToRoll == 0) {
            cout << "Hot dice! You get all six dice again.\n";
            diceToRoll = 6;
        }

        // Continue?
        cout << "Roll again? (y/n/q): ";
        char choice;
        cin >> choice;

        if (choice == 'q' || choice == 'Q') {
            cout << "\nPlayer chose to quit the game.\n";
            exit(0);
        }

        if (choice == 'n' || choice == 'N') {
            continueTurn = false;
        }
    }

    // ------------------------------------------------------------
    // BANK SCORE — only if the player has entered the game
    // ------------------------------------------------------------
    if (player.hasEntered()) {
        player.addScore(turnScore);
        cout << player.getName() << " banks " << turnScore << " points.\n";
        cout << player.getName() << "'s total score: " << player.getScore() << "\n";
    }
    else {
        cout << player.getName()
            << " has not entered yet. Points do not count until scoring 500 in one turn.\n";
    }
}

// ------------------------------------------------------------
// Ends the game
// ------------------------------------------------------------
void Game::endGame() {
    cout << "\n===== GAME OVER =====\n";
    cout << "Winner: " << leadingPlayer->getName()
        << " with " << leadingPlayer->getScore() << " points!\n";
}

// ------------------------------------------------------------
// Enhanced Scoring Calculation (Hybrid System)
// ------------------------------------------------------------
int Game::calculateScore(const vector<int>& roll, vector<int>& scoringDice) {
    int counts[7] = { 0 };
    for (int d : roll) counts[d]++;

    // Detect straight (1–6)
    if (isStraight(counts)) {
        scoringDice = roll;
        return 1500;
    }

    // Detect three pairs
    if (isThreePairs(counts)) {
        scoringDice = roll;
        return 1500;
    }

    int total = 0;
    vector<int> temp;

    bool usedInSet[7] = { false };

    // Sets (3–6 of a kind)
    for (int value = 1; value <= 6; value++) {
        int count = counts[value];

        if (count >= 3) {
            int base = (value == 1) ? 1000 : value * 100;
            int multiplier = count - 2;
            int setScore = base * multiplier;

            total += setScore;
            usedInSet[value] = true;

            for (int i = 0; i < count; i++) {
                temp.push_back(value);
            }
        }
    }

    // Singles
    for (int d : roll) {
        if (!usedInSet[d]) {
            if (d == 1 || d == 5) {
                total += (d == 1) ? 100 : 50;
                temp.push_back(d);
            }
        }
    }

    scoringDice = temp;
    return total;
}

// ------------------------------------------------------------
// Scores the kept dice only
// ------------------------------------------------------------
int Game::calculateKeptScore(const vector<int>& keptDice) {
    vector<int> dummy;
    return calculateScore(keptDice, dummy);
}

// ------------------------------------------------------------
// Validates kept dice
// ------------------------------------------------------------
bool Game::isValidSelection(const vector<int>& scoringDice,
    const vector<int>& keptDice) {
    int scoringCounts[7] = { 0 };
    int keptCounts[7] = { 0 };

    for (int d : scoringDice) scoringCounts[d]++;
    for (int d : keptDice)   keptCounts[d]++;

    for (int value = 1; value <= 6; value++) {
        if (keptCounts[value] > scoringCounts[value]) return false;
    }

    return !keptDice.empty();
}

// ------------------------------------------------------------
// Detect straight (1–6)
// ------------------------------------------------------------
bool Game::isStraight(const int counts[7]) {
    for (int value = 1; value <= 6; value++) {
        if (counts[value] != 1) return false;
    }
    return true;
}

// ------------------------------------------------------------
// Detect three pairs
// ------------------------------------------------------------
bool Game::isThreePairs(const int counts[7]) {
    int pairs = 0;
    for (int value = 1; value <= 6; value++) {
        if (counts[value] == 2) pairs++;
    }
    return pairs == 3;
}
