/***************************************************************************************************
** Author: Kurt Kaiser
** Date: 06.10.2019
** Course: CS 162 400 S2019
** Description:  Final Project - design and implement a one-player, text-based game
** where the player can move through spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include <string>
#include "space.hpp"
#include "empty.hpp"
using std::cout;
using std::string;
using std::endl;
using std::cin;

// Constructor for the House class
Empty::Empty() {
	// Defing private variables
  Space::setSquare('*');
  Space::setDefaultSquare('*');
  Space::setEnemyName("rattlesnake");
}
Empty::~Empty(){
  // Deconstructor
}

// Declaring public methods
// Methods to simulate space combat
int Empty::battle(int health, string weapon) {
	int playerHealth = health;
	int enemyHealth = 3;
	int choice = 0;
	int damage = 0;
	int randomEvent;
	int playerStrength = 1;
	int enemyStrength = 1;
	if (weapon == "sword"){
		playerStrength = 2;
	}
	// Player takes immediate damage 1/3 of the time
	randomEvent = Space::rollDice();
	if (randomEvent < 2) {
		cout << "BITE! Ouch!!" << endl;
		playerHealth--;
	}
	else if (randomEvent == 4)
	{
		Space::setEnemyName("desert bighorn sheep");
		enemyHealth = 8;
		enemyStrength = 1;
	}
	else if (randomEvent == 6) {
		Space::setEnemyName("armadillo");
		enemyHealth = 8;
		enemyStrength = 1.5;
	}
	cout << "<>>>>>:>~ A  " << Space::getEnemyName() << " lunges at you. ~<:<<<<<>" << endl;
	while (choice != 1 && choice != 2) {
		cout << "Enter 1 to fight, 2 to run." << endl;
		cin >> choice;
		cout << choice << endl;
	}

	while (enemyHealth > 0 && playerHealth > 0) {
		if (choice == 2) {
			if (Space::rollDice() > 3) {
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
				cout << "Animals health: " << enemyHealth << endl;
			}
			if (enemyHealth > 0) {
				damage = Space::rollDice()* enemyStrength;
				playerHealth = playerHealth - damage;
				cout << "OUCH! You are attacked! Damage: " << damage;
				cout << ", Health: " << playerHealth << endl;
			}
			if (enemyHealth < 1) {
				cout << "You won!" << endl;
				if (Space::getEnemyName() == "desert bighorn sheep") {
					Space::setItemName("hide");
				}
				else {
					Space::setItemName("meat");
				}
				Space::setEnemyName("");

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
  return playerHealth;
} 

int Empty::pillage() {
 return 0;
}
