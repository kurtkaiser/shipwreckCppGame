/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include <string>
#include <limits.h>
#include "menu.hpp"
using std::cout;
using std::string;
using std::endl;
using std::cin;

// Constructor for the Menu class
Menu::Menu(string option1) {
	// Declaring private member variables and arrays of variables
  length = 1;
  options = new string[length];
  options[0] = option1;
  start = 1;
}

// Defining methods to access and set class variables
void Menu::addOption(std::string optionIn) {
  string *tempOptions = new string[length + 1];
  for (int i = 0; i < length; i++){
	tempOptions[i] = options[i];
  }
  tempOptions[length] = optionIn;
  delete [] options;
  options = tempOptions;
  length++;
}

// Setter for start value, used for choice validation
void Menu::setStart(int startIn) {
	start = startIn;
}

void Menu::editOption(int index, string change) {
	options[index] = change;
}

// Output the options with numbers for selection
// Prompt user for input, validate input and return it
int Menu::getUserChoice() {
	int choice = 0;
  	for (int i = 0; i < length; i++){
    cout << (i + 1) << ": ";
    cout << options[i] << endl;
  }
	while (true) {
		// if input is an int and in the acceptable range break
		if (cin >> choice) {
			if (choice > (start - 1) && choice < (length + 1)) {
				break;
			}
		}
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Please enter a number from " << start << " to " << length << "." << endl;
	}
	// Return acceptable user input
	return choice;
}

void Menu::deleteMenu() {
	delete[] options;
}
