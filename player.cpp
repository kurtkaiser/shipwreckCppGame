/***************************************************************************************************
** Author: Kurt Kaiser
** Date: 06.10.2019
** Course: CS 162 400 S2019
** Description:  Final Project - design and implement a one-player, text-based game
** where the player can move through spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include "player.hpp"
#include <string>
#include <array>
#include <stdlib.h>    
#include <time.h>     
#include <cstdlib>
//#include <limits.h>
using std::string;
using std::cout;
using std::endl;

// Constructor for the Player class
Player::Player() {
	name = "player";
	health = 40;
	// index 0 is food count
	itemCount = 6;
	packLimit = 10;
	// Starting item pack
	pack = new string [itemCount]{"meat", "meat", "meat", "meat", "meat", "meat"};
	weapon = "fists";
	weaponPower = 1;
	weaponHealth = 100;
	hasPickaxe = false;
	hasOil = false;
	hasHide = false;
}

// Declaring public methods
// Setters to define private variables
void Player::setName(string nameIn) {
	name = nameIn;
}

// Add items to the players pack to collect goods and food
void Player::addToPack(string itemIn) {
	if (itemIn == "sword" && weapon == "sword") {
		cout << "Too much weight. You can't carry two swords." << endl;
	}
	else {
		// check if winning had been picked up
		if (itemIn == "sword") {
			weapon = "sword";
			weaponPower = 2;
		}
		else if (itemIn == "pickaxe") {
			hasPickaxe = true;
		}
		else if (itemIn == "oil") {
			hasOil = true;
		}
		else if (itemIn == "hide") {
			hasHide = true;
		}
		// keep item count up to date and resize array
		if (itemCount < packLimit) {
			string *tempPack = new string[itemCount + 1];
			for (int i = 0; i < itemCount; i++) {
				tempPack[i] = pack[i];
			}
			itemCount++;
			delete[] pack;
			pack = tempPack;
			pack[itemCount - 1] = itemIn;
		}
		else {
			cout << "-- Your pack is full. --" << endl;
			printPack();
		}
	}
	
}

// output the contents of the pack
void Player::printPack() {
	cout << "---- Pack ----" << endl;
		for (int i = 0; i < itemCount; i++) {
			cout <<"| "<< i + 1 << ": " <<  pack[i] << endl;
		}
		cout << "------------" << endl;
}

// Remove items from the pack and resize the array
void Player::removeFromPack(string itemOut) {
	string deleteItem = itemOut;
	int index = 0;
	bool found = false;
	if (itemOut == "sword") {
		weapon = "fists";
		weaponPower = 1;
	}
	if (itemCount == 1){
		if (pack[0] == deleteItem) {
			pack[0] = "";
			itemCount = 0;
		}
	} else if (itemCount > 0) {
		string *tempPack = new string[itemCount - 1];
			for (int i = 0; i < itemCount; i++) {
				if (pack[i] == deleteItem) {
					deleteItem = "false item here";
					found = true;
				}
				else {
					tempPack[index] = pack[i];
					index++;
				}
			}
			// if found delete pack and set it to temp array
			if (found) {
				itemCount--;
				delete[] pack;
				pack = tempPack;
				printPack();
			}
			// Output if nothing in pack
			else {
				cout << "The item is not in your pack." << endl;
			}
	}
	else {
		cout << "You have nothing in your pack." << endl;
	}
}

// Setters and Getters
void Player::setHealth(int healthIn) {
	health = healthIn;
}

int Player::getHealth() {
	return health;
}

int Player::getPackLimit() {
	return packLimit;
}

int Player::getItemCount() {
	return itemCount;
}

string Player::getWeapon() {
	return weapon;
}

bool Player::getHasPickaxe() {
	return hasPickaxe;
}

bool Player::getHasOil() {
	return hasOil;
}

bool Player::getHasHide() {
	return hasHide;
}

int Player::getWeaponPower() {
	return weaponPower;
}

int Player::getWeaponHealth() {
	return weaponHealth;
}

void Player::setWeaponPower(int weaponPowerIn) {
	weaponPower = weaponPowerIn;
}

void Player::setWeaponHealth(int weaponHealthIn) {
	weaponHealth = weaponHealthIn;
}