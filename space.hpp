/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
using std::string;
// Abstract Class with pure virtual functions
// Defines the interface of the character class
class Space
{
private:
	private:
	// Declaring private variables
  char square;
  char defaultSquare;
  string type;
  string itemName;
  int itemCount;
  string enemyName;
  int enemyCount;
  
  public:
	// Defining public variables and methods
	Space();
	virtual ~Space();
  // Declaring public methods
  // Pure virtual functions to simulate character combat
	virtual int battle(int, string) = 0;
  virtual int pillage() = 0;
  // Setters to define private variables
  void setSquare(char);
  void setItemName(string);
  void setItemCount(int);
  void setEnemyName(string);
  void setEnemyCount(int);
  void setDefaultSquare(char);
  // Gettters to return private values
  char getSquare();
  char getDefaultSquare();
  string getItemName();
  int getItemCount();
  string getEnemyName();
  int getEnemyCount();
  // Resets spaces to default value
  int rollDice();
  void setToDefault();
 
};

#endif
