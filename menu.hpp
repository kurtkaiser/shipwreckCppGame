/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
using std::string;

class Menu
{
private:
	// Declaring private member variables
	string *options;
  int length;
	int start;

public:
	// Declaring constructor for the class
	Menu(string);
	int getUserChoice();
	void addOption(string);
	void setStart(int);
	void editOption(int, string);
	void deleteMenu();
};
#endif
