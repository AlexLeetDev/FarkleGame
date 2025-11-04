/*
 ============================================================================
 File        : rules_reader.cpp
 Author      : Alex Leet
 Course      : IT-312 - Software Development with C++
 Date        : April 20, 2025
 Description : This file includes a function that reads and displays the
			   rules for the Farkle game from a text file. 
 ============================================================================
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to display rules from the file
void displayRules(const string& filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Error: Could not open " << filename << endl;
		return;
	}

	cout << "=== Welcome to Farkle ===\n" << endl;

	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}

	file.close();
}