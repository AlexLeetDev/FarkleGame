/*
 ============================================================================
 File        : main.cpp
 Author      : Alex Leet
 Original    : April 20, 2025 (Version 1.0)
 Updated     : November 2025 (Version 2.0 - Enhanced Hybrid Scoring System)
 Description : Entry point for the Farkle dice game.
               Displays rules and starts the game.
 ============================================================================
*/

#include <iostream>
#include <ctime>
#include <limits>
#include "rules_reader.h"
#include "Game.h"

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Display the rules from the text file
    displayRules("farkle_rules.txt");

    // Pause to let the user read the rules
    cout << "\n(Press Enter to continue...)";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    // Clear the screen
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Start the enhanced Farkle game
    Game farkleGame;
    farkleGame.start();

    return 0;
}
