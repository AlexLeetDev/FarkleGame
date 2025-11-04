/*
 ============================================================================
 File        : main.cpp
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : Entry point for the Farkle dice game.
               Displays rules and starts the game.
 ============================================================================
*/

#include <iostream>
#include <ctime>
#include "rules_reader.h"  // Declaration for displayRules()
#include "Game.h"          // Declaration for Game class

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Display the game rules from the text file
    displayRules("farkle_rules.txt");

    // Wait for the user to read the rules before starting
    cout << "\n(Press Enter to continue...)";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

// Clear the screen for a clean start
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Start the Farkle game
    Game farkleGame;
    farkleGame.start();

    return 0;
}
