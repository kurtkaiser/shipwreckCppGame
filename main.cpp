/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "board.hpp"
#include "space.hpp"
#include "house.hpp"
#include "empty.hpp"
#include <cstring>
#include <time.h>
#include <stdio.h>
using std::string;
using std::cout;
using std::endl;
using std::cin;

// Early game info, establishes a narrative for the game
void outputStart(int difficulty) {
	int choice = 0;
	string tasks = "";
	cout << endl;
	cout << "Where? Why? What?" << endl;
	cout << "  O  O   " << endl;
	cout << "      O   " << endl;
	cout << "       |_  " << endl;
	cout << "       ||___ " << endl;
	cout << "       ||  | " << endl;
	cout << "  ------------ " << endl;
	cout << "   \\        /  " << endl;
	cout << " ~~~~~~~~~~~~~~~" << endl;
	cout << " ~~~~~~~~~~~~~~~~" << endl;
		cout << "A shipwreck? A ship?" << endl;
	cout << "My ship!! MY SHIP?!\n" << endl;
	if (difficulty > 1) {
		tasks = "\n I also need an animal hide to use as a vent air filter.";
		if (difficulty == 3) {
			tasks = tasks +
				"\n Oil too, I should look in houses. Engine needs new oil.";
		}
	}
	// Options for what to do at the start
	while (choice != 1 && choice != 2) {
		cout << "Enter 1 or 2" << endl;
		cout << "1. Explore the boat." << endl;
		cout << "2. Who am I?" << endl;
		cin >> choice;
		if (choice == 2) {
			// Ouptput additional character info if player requests it
			cout << "*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-*" << endl;
			cout << " Sand? Ocean? The storm! Oh no, where is the boat?" << endl;
			cout << " Mostly desert, looks like I am still in Texas. Good." << endl;
			cout << " Oh, ship washed up behind me. Hope the cargo is fine." << endl << endl;
			cout << "*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-*" << endl;
			choice = 0;
		}
		// output main mission of the game
		else {
			cout << "*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-*" << endl;
			cout << " The cargo, cannons, Sam Houston is expecting these." << endl;
			cout << " Cargo looks good, the steam engine, does not! The exhaust" << endl;
			cout << " vent is blown out. Okay. I have a spare. But how to open" << endl;
			cout << " the engine? Nothing on the ship can pry the back off. I" << endl;
			cout << " need to find a tool and fix it, maybe a hammer or pickaxe." << tasks << endl;
			cout << " Then I can come back and fix this ship and get on my way." << endl;
			cout << "*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-**-~-*-~-*-~-*-~-*-~-*" << endl << endl;
			cout << "  The Desert " << endl;
		}
	}
}

// Ask user to chose a direction to move in
BoardNode* movePlayer(Board* gameBoard, Menu* moveMenu, BoardNode* tile) {
	BoardNode* newTile;
	newTile = tile;
	int choice = moveMenu->getUserChoice();
	// Use switch to evaluate user choice
		switch (choice) {
		case 1:
			newTile = gameBoard->moveUp(tile);
			break;
		case 2:
			newTile = gameBoard->moveDown(tile);
			break;
		case 3:
			newTile = gameBoard->moveLeft(tile);
			break;
		case 4:
			newTile = gameBoard->moveRight(tile);
			break;
		default:
			break;
		}
	// if same tile returned, that means player move in null direction
	if (newTile == tile) {
		cout << "--> There is nothing that direction." << endl;
		tile->val->setSquare('P');
	}
	else {
		newTile->val->setSquare('P');
	}
	return newTile;
}

// Check for item in the space, offer it to the player
void tileItem(Player* player, BoardNode* tile) {
	int choice = 0;
	string name = tile->val->getItemName();
	// if item name is empty, to user nothing here
	if (name != "") {
		cout << "Would you like to pick up a " << name << "?\n";
		while (choice != 1 && choice != 2) {
			cout << "Enter 1 to pick it up, 2 to leave it." << endl;
			cin >> choice;
		}
		if (choice == 1) {
			player->addToPack(name);
		}
	}
	else {
		cout << "There is nothing here." << endl;
	}
}

// Options for the player if they reached a cave
bool caveEnterance(Player* player) {
	bool paid = false;
	int choice = 0;
	cout << "A mytic resides here. His sign reads:\n";
	cout << " ~ Leave six meat for sky god, do, and do. ~\n";
	cout << " ~ Enter my cave without, you die, and die. ~\n";
	cout << "_.~'~._.~'~._.~'~._.~'~.__.~'~._.~'~._.~'~._." << endl;
	while (choice != 1 && choice != 2) {
		cout << "Enter 1 to pay and go into the cave, 2 to leave." << endl;
		cin >> choice;
	}
	// If user enters 1, take six meat from the player
	if (choice == 1) {
		int count = 0;
		player->removeFromPack("meat");
		while (player->getItemCount() > 0 && count < 6) {
			player->removeFromPack("meat");
			count++;
		}
		if (count == 5) {
			paid = true;
		}
		else {
			// If player runs out of food, they lose it and do not get in
			cout << "You are out of food. Leave." << endl;
		}
	}
	return paid;
}

// Output this text if user has completed requirements
void wonGame() {
	cout << " *-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*-~-*" << endl;
	cout << " YES! I DID IT!! I GOT THE ENGINE REPAIRED. I CAN GET THESE" << endl;
	cout << " CANNONS TO SAME HOUSTON IN NO TIME. WE SHALL WIN AFTERALL. " << endl;
	cout << " REMEMBER THE ALAMO!" << endl;
	cout << " *-~-*-~-*-~-*-~CONGRADULATIONS, YOU WIN!!!!~-*-~-*-~-*-~-*" << endl;
}

int main() {
	// Used to randomize dice function in player
	srand((unsigned)time(NULL));
	// Use to set game level difficulty
	int difficulty = 1;
	// Declare needed variables
	// Creates the game board, I could randomize the size
	Board board;
	Board* gameBoard = &board;
	gameBoard->createBoard(8, 16);
	BoardNode* tile = gameBoard->getPlayerTile();
	// Player object creation
	Player gamePlayer;
	Player* player = &gamePlayer;
	int health = player->getHealth();
	// Define the needed menues
	Menu startMenu("Easy ---> 1: Find a pickaxe to fix your ship and win.");
	startMenu.addOption("Medium -> 2: Find oil and a pickaxe to fix your ship and win.");
	startMenu.addOption("Hard ---> 3: Find a sheep hide, oil and a pickaxe to win.");
	startMenu.addOption("Exit");
	Menu menu("Move Spaces");
	menu.addOption("Hunt");
	menu.addOption("Check Pack");
	menu.addOption("Eat and Heal");
	menu.addOption("Quit");
	Menu movementMenu("Up");
	Menu *moveMenu = &movementMenu;
	moveMenu->addOption("Down");
	moveMenu->addOption("Left");
	moveMenu->addOption("Right");
	// Use for menu choice
	int choice = 0;
	cout << "    *-~-*-~-*-~-*-~-*-~-* A LONE STAR SHIPWRECK *-~-*-~-*-~-*-~-*-~-*" << endl;
	cout << "    *-~-*-Find item(s) to fix your ship, get back to it and win!-*-~-*" << endl << endl;
	char tileChar;
	// Get difficulty selection
	difficulty = startMenu.getUserChoice();
	startMenu.editOption(0, "Play Again");
	if (difficulty > 0 && difficulty < 4) {
		outputStart(difficulty);
		// Run the game while the player is alive
		gameBoard->printBoard();
		// While the player has health, run the game
		while (player->getHealth() > 0) {
			// Get choice from menu
			choice = menu.getUserChoice();
			if (choice == 1) {
				// Player selected to move
				tile = movePlayer(gameBoard, moveMenu, tile);
				tileChar = tile->val->getDefaultSquare();
				// Randomize stepping on a cactus
				if ((rand() % 6) + 1 == 3){
					cout << " - Stepped on a darn cactus! Owwwww! - " << endl;
					health = health - 1;
				}
				if (tileChar == '#') {
					// Edit menu to fit for abandoned house
					cout << "-- Abandoned House --" << endl;
					menu.editOption(1, "Search Inside");
				}
				else if (tileChar == '*') {
					// Change menu as needed
					menu.editOption(1, "Hunt");
					choice = (rand() % 3) + 1;
					if (choice == 2) {
						cout << "Health:" << health;
						cout << " Pack:" << player->getItemCount() << endl;
						gameBoard->printBoard();
					}
					else {
						choice = 1;
					}
				}
				else if (tileChar == 'o') {
					cout << "-- Cave --" << endl;
					menu.editOption(1, "Search Inside");
				}
				else if (tileChar == 'S' && player->getHasPickaxe()) {
					// Check if back at ship and then check for a win
					if (difficulty != 2 || (difficulty == 2 && player->getHasOil())) {
						if (difficulty != 3 || 
							(player->getHasOil() && player->getHasHide())) {
							wonGame();
							break;
						}
					}
					
				}
			}
			if (choice == 2) {
				// If hunting or getting attacked fight
				if (tile->val->getEnemyName() != "") {
					if (tile->val->getDefaultSquare() != 'o' || caveEnterance(player)) {
						health = tile->val->battle(health, player->getWeapon());
						if (health < 0) {
							health = 0;
						}
						// Update players health
						player->setHealth(health);
						tileItem(player, tile);
					}
				}
				else {
					cout << "Nothing here." << endl;
				}
			}
			else if (choice == 3) {
				// output pack contents
				player->printPack();
			}
			else if (choice == 4) {
				// If remove item, find item
				int count = player->getItemCount();
				player->removeFromPack("meat");
				// Update players health
				if (count > player->getItemCount()) {
					health = health + 2;
					player->setHealth(health);
				}
				else {
					cout << "You have no food." << endl;
				}

			}
			else if (choice == 5) {
				// Update health to end game
				player->setHealth(0);
			}
			// Output health and pack item count before printing board
			cout << "Health:" << health;
			cout << " Pack:" << player->getItemCount() << endl;
			gameBoard->printBoard();
		}
		cout << "\n   *-~-*-~-*-~-*-~-*-~-* A LONE STAR SHIPWRECK *-~-*-~-*-~-*-~-*-~-*" << endl << endl;
	}
}
