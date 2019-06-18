/***************************************************************************************************
** Author: Kurt Kaiser
** Date: 06.10.2019
** Course: CS 162 400 S2019
** Description:  Final Project - design and implement a one-player, text-based game
** where the player can move through spaces to get items and accomplish goals.
****************************************************************************************************/

#ifndef CAVE_HPP
#define CAVE_HPP
#include "space.hpp"
#include <string>
using std::string;

// Defining the interface for the class
class Cave : public Space
{
private:
	// Declaring private variables

public:
	// Class Default Constructor
	Cave();
	~Cave();

	// Declaring public methods
	// Override functions
	int battle(int, string);
	int pillage();
};

#endif