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

/* --------------------------------------------------------------
   Start Screen
   -------------------------------------------------------------- */
void displayStartScreen() {

#ifdef _WIN32
    system("Color 0A");
#endif

    cout << "==========================================" << endl;
    cout << "           FARKLE DICE GAME\n";
    cout << "                  v2.0\n";
    cout << "------------------------------------------" << endl;
    cout << "   A console Farkle game\n";
    cout << "   with improved scoring and rules.\n";
    cout << "==========================================" << endl << endl;

    cout << "(Use the menu below to continue...)" << endl;
}

/* --------------------------------------------------------------
   Menu Options
   -------------------------------------------------------------- */
int displayMenu() {
    int choice;

    cout << "\n1. Start Game" << endl;
    cout << "2. View Rules" << endl;
    cout << "3. Exit" << endl;
    cout << "\nSelect an option: ";

    // Validate input
    while (!(cin >> choice) || choice < 1 || choice > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Please enter 1, 2, or 3: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    return choice;
}

/* --------------------------------------------------------------
   Clear Screen
   -------------------------------------------------------------- */
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* --------------------------------------------------------------
   Program Entry
   -------------------------------------------------------------- */
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Show intro screen
    displayStartScreen();

    // Menu loop
    while (true) {
        
        int choice = displayMenu();

        if (choice == 1) {
            // Start the actual game
            clearScreen();
            Game farkleGame;
            farkleGame.start();
            break;  // exit menu loop
        }

        else if (choice == 2) {
            // View rules
            clearScreen();
            displayRules("farkle_rules.txt");

            cout << "\n(Press Enter to return to the menu...)";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            clearScreen();
            displayStartScreen();
        }

        else if (choice == 3) {
            cout << "\nExiting game. Goodbye!\n";
            return 0;
        }
    }

    return 0;
}
