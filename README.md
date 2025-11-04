# 🎲 Farkle Dice Game

This project is a C++ implementation of the classic dice game **Farkle**.  
It was originally developed for a previous course and will be **further enhanced** as part of my **CS 499 Capstone Project**.  
This project demonstrates my understanding of object-oriented programming, algorithm design, and structured code organization in C++.

---

## 🧩 Overview

Farkle is a turn-based dice game where players roll six dice and earn points for specific combinations, such as triples or certain numbers.  
The goal is to reach a target score before your opponent, but if you "Farkle" (roll no scoring dice), you lose all points for that turn.

This version of the game runs in the console and allows players to:

- Roll dice and view the results
- Choose which dice to keep for scoring
- Track scores between players
- View the official game rules from a text file (`farkle_rules.txt`)

---

## 🧠 Features

- **Object-Oriented Design:** Organized using `Game`, `Player`, and `Dice` classes.
- **Algorithmic Scoring:** Calculates points according to Farkle rules.
- **File Handling:** Reads game rules from an external text file.
- **User Input:** Lets players select which dice to keep or reroll.
- **Modular Codebase:** Source code is split into multiple files for clarity and maintainability.

---

## 🚀 Planned Enhancements

For my upcoming capstone work, I plan to build on this project by:

- Expanding the scoring logic to include new combinations (such as straights and three pairs).
- Improving input checks so the program can handle mistakes or invalid entries more smoothly.
- Making the code easier to read and update by cleaning up how the scoring logic is written
- Adding more helpful comments and documentation to explain how each part of the program works.

These updates will make the program more user-friendly, reliable, and easier to maintain.

---

## 🗂️ Project Structure

```plaintext
FarkleGame/
├── FarkleGame/
│   ├── Dice.cpp                    # Handles dice rolls and random values
│   ├── Dice.h
│   ├── Player.cpp                  # Stores player data and total scores
│   ├── Player.h
│   ├── Game.cpp                    # Main game logic and scoring calculations
│   ├── Game.h
│   ├── rules_reader.cpp            # Loads rules from a text file
│   ├── rules_reader.h
│   ├── farkle_rules.txt            # Reference file with Farkle rules
│   ├── FarkleGame.vcxproj          # Visual Studio project file
│   ├── FarkleGame.vcxproj.filters
│   ├── FarkleGame.vcxproj.user
│   └── main.cpp                    # Entry point of the program
├── FarkleGame.sln                  # Visual Studio solution file
├── .gitignore               
└── README.md                 
```

---

## 🧰 How to Run

1. **Open in Visual Studio:**  
   - Double-click `FarkleGame.sln` to open the solution.
2. **Build the project:**  
   - Select *Build → Build Solution* (or press `Ctrl+Shift+B`).
3. **Run the game:**  
   - Press `Ctrl+F5` to start without debugging.
4. Follow the on-screen prompts to play!

---

## 👨‍💻 Author

**Alex Leet**  
Computer Science Student & Developer  
📫 [GitHub: AlexLeetDev](https://github.com/AlexLeetDev)