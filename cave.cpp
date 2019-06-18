/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include <string>
#include "space.hpp"
#include "cave.hpp"
using std::cout;
using std::string;
using std::endl;
using std::cin;

// Constructor for the House class
Cave::Cave() {
	// Defing private variables
	Space::setSquare('o');
	Space::setDefaultSquare('o');
	Space::setEnemyName("bear");
}

Cave::~Cave() {
	// Deconstructor
}
// Declaring public methods
// Methods to simulate space combat
int Cave::battle(int health, string weapon) {
	int playerHealth = health;
	int enemyHealth = 15;
	int playerStrength = 1;
	int choice = 0;
	int damage = 0;
	int randomEvent;
	int enemyStrength = 5;
	if (weapon == "sword") {
		playerStrength = 2;
	}
	int num1 = Space::rollDice();
	int num2 = Space::rollDice();
	int num3 = Space::rollDice();
	int puzzleNum1 = num1 * num2 - num3;
	int puzzleNum2 = puzzleNum1 * num2 - num3;
	int puzzleNum3 = puzzleNum2 * num2 - num3;
	int answer = puzzleNum3 * num2 - num3;
	int guess = 0;
	cout << "This is no ordinary cave. A desert mystic resides here." << endl;
	// Player takes immediate damage 1/3 of the time
	
	cout << " ~ I have what you seek, I do, I do. ~" << endl;
	cout << " ~ The tool is cheap, and new, and new. ~" << endl;
	cout << " ~ Six pieces provided, true, and true. ~" << endl;
	cout << " ~ Now solve my puzzle, or shoo, and shoo. ~" << endl;
	cout << "_.~'~._.~'~._.~'~._.~'~.__.~'~._.~'~._.~'~._.~'~._" << endl;
	cout << "ANSWER For grading: " << answer << endl;
	/// Print out puzzle
	cout << puzzleNum1 << ", " << puzzleNum2 << ", " << puzzleNum3 << ", _____" << endl;
	cout << "What should be the next number in the sequence? ";
	cin >> guess;
	if (guess == answer) {
		cout << "You solved it, I know, I know.\n";
		cout << "Reward, reward I don't lie, true, true." << endl;
		Space::setItemName("pickaxe");
		playerHealth = playerHealth + 10;
	}
	else {
		cout << "You fool. You fool. You wasted my time.\n";
		cout << "Enjoy facing the beast.Bye, bye." << endl;
		randomEvent = Space::rollDice();
		if (randomEvent < 2) {
			cout << "BITE! Ouch!!" << endl;
			playerHealth = playerHealth - 5;
		}
		cout << "<>>>>>:>~ A  bear lunges at you. ~<:<<<<<>" << endl;
		while (choice != 1 && choice != 2) {
			cout << "Enter 1 to fight, 2 to run." << endl;
			cin >> choice;
			cout << choice << endl;
		}

		while (enemyHealth > 0 && playerHealth > 0) {
			if (choice == 2) {
				if (Space::rollDice() > 2) {
					enemyHealth = 0;
					cout << "You escaped." << endl;
				}
				else {
					cout << "Ouch! You can't get away fast enough." << endl;
					playerHealth = playerHealth - enemyStrength;
					choice = 0;
					while (choice != 1 && choice != 2) {
						cout << "Enter 1 to fight, 2 to run." << endl;
						cin >> choice;
					}
				}
			}
			else {
				cout << "You attack with your " << weapon << "." << endl;
				damage = Space::rollDice();
				if (damage == 6) {
					cout << "Your attack missed." << endl;
				}
				else {
					enemyHealth = enemyHealth - damage * playerStrength;
					cout << "Your attack's strength: " << damage << endl;
					if (enemyHealth < 0) {
						enemyHealth = 0;
					}
					cout << "Solid hit. Enemy Health: " << enemyHealth << endl;
				}
				if (enemyHealth > 0) {
					damage = Space::rollDice()* enemyStrength;
					playerHealth = playerHealth - damage;
					cout << "OUCH! You are attacked! Damage: " << damage;
					if (playerHealth < 0) {
						playerHealth = 0;
					}
					cout << ", Health: " << playerHealth << endl;
				}
				if (enemyHealth < 1) {
					cout << "You won!" << endl;
					Space::setItemName("");
				}
				else if (playerHealth < 1) {
					cout << "You died." << endl;
				}
				else {
					choice = 0;
					while (choice != 1 && choice != 2) {
						cout << "Enter 1 to fight, 2 to run." << endl;
						cin >> choice;
					}
				}
			}
		}
	}
	return playerHealth;
}

int Cave::pillage() {
	return 0;
}
