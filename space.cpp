/***************************************************************************************************
** Author: Kurt Kaiser
** Date: 06.10.2019
** Course: CS 162 400 S2019
** Description:  Final Project - design and implement a one-player, text-based game
** where the player can move through spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include "space.hpp"
#include <string>
#include <array>
using std::string;
using std::cout;
using std::endl;

// Constructor for the Space class
Space::Space() {
	square = '.';
	defaultSquare = 'e';
	type = "Space";
}

Space::~Space() {
	// Deconstructor
}


// Declaring public methods

// Setters to define private variables
void Space::setSquare(char squareIn) {
	square = squareIn;
}


void Space::setDefaultSquare(char defaultSquareIn) {
	defaultSquare = defaultSquareIn;
}

void Space::setToDefault() {
	square = defaultSquare;
}


void Space::setItemName(string itemNameIn) {
	itemName = itemNameIn;
}

void Space::setItemCount(int itemCountIn) {
	itemCount = itemCountIn;
}

void Space::setEnemyName(string enemyNameIn) {
	enemyName = enemyNameIn;
}

void Space::setEnemyCount(int enemyCountIn) {
	enemyCount = enemyCountIn;
}

  char Space::getSquare() {
	  return square;
  }

  char Space::getDefaultSquare() {
	  return defaultSquare;
  }

  string Space::getItemName(){
    return itemName;
  }

  int Space::getItemCount(){
    return itemCount;
  }
  string Space::getEnemyName(){
    return enemyName;
  }

  int Space::getEnemyCount(){
    return enemyCount;
  }

  int Space::rollDice() {
	  int randomNum = (rand() % 6) + 1;
	  return randomNum;
  }