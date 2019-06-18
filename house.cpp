/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include <string>
#include "space.hpp"
#include "house.hpp"
using std::cout;
using std::string;
using std::endl;
using std::cin;

// Constructor for the House class
House::House() {
	// Defing private variables
	Space::setSquare('#');
	Space::setDefaultSquare('#');
  //Space::setItemName("sword");
  Space::setEnemyName("outlaw");
 // Space::setItemName(houseItemName);
}

House::~House(){
  // Deconstructor
}
// Declaring public methods
// Methods to simulate space combat
int House::battle(int health, string weapon) {
	int playerHealth = health;
	int enemyHealth = 5;
	int playerStrength = 1;
	int choice = 0;
	int damage = 0;
	int randomEvent;
	int enemyStrength = 2;
	if (weapon == "sword") {
		playerStrength = 2;
	}
	// Player takes immediate damage 1/3 of the time
	randomEvent = Space::rollDice();
	if (randomEvent < 2) {
		cout << "Shot! Ouch!!" << endl;
		playerHealth  = playerHealth - 3;
	}
	else if (randomEvent == 4)
	{
		Space::setEnemyName("outlaw");
		enemyHealth = 10;
		enemyStrength = 4;
	}
	cout << "o=[::::::::> An outlaw lunges at you." << endl;
	while (choice != 1 && choice != 2) {
		cout << "Enter 1 to fight, 2 to run." << endl;
		cin >> choice;
		cout << choice << endl;
	}
	while (enemyHealth > 0 && playerHealth > 0) {
		if (choice == 2) {
			if (Space::rollDice() > 3) {
				enemyHealth = 0;
				cout << "You escape." << endl;
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
				cout << " Health: " << playerHealth << endl;
			}
			if (enemyHealth < 1) {
				randomEvent = Space::rollDice();
				cout << "You won!" << endl;
				if (randomEvent > 4) {
					Space::setItemName("sword");
				}
				else if (randomEvent == 3) {
					Space::setItemName("oil");
				}
				else {
					Space::setItemName("meat");
				}
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
	Space::setEnemyName("");
	return playerHealth;
}
int House::pillage() {
 return 0;
}
