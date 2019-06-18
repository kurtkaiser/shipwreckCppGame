/***************************************************************************************************
** Author: Kurt Kaiser
** Date: 06.10.2019
** Course: CS 162 400 S2019
** Description:  Final Project - design and implement a one-player, text-based game
** where the player can move through spaces to get items and accomplish goals.
****************************************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "space.hpp"
#include <string>
using std::string;
// Abstract Class with pure virtual functions
// Defines the interface of the player class

class Player
{
private:
	private:
	// Declaring private variables
  string name;
  int health;
  string *pack;
  int itemCount;
  int packLimit;
  string weapon;
  int weaponPower;
  int weaponHealth;
  bool hasPickaxe;
  bool hasOil;
  bool hasHide;


public:
	// Defining public variables and methods
	Player();
	

	void setName(string);
	void addToPack(string);
	int getPackLimit();
	int getItemCount();
	void removeFromPack(string);
	void setHealth(int);
	int getHealth();
	
	void printPack();
	string getWeapon();
	int getWeaponPower();
	int getWeaponHealth();
	void setWeaponPower(int);
	void setWeaponHealth(int);
	bool getHasPickaxe();
	bool getHasOil();
	bool getHasHide();
	

};

#endif