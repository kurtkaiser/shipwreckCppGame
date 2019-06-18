/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/
#include <iostream>
#include <string>
#include "board.hpp"
#include "space.hpp"
#include "house.hpp"
#include "cave.hpp"
#include "empty.hpp"
#include "player.hpp"
#include <time.h>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

// Constructor for the Board class
Board::Board() {
	// Defing private variables
	head = NULL;
	playerTile = NULL;
}

Board::~Board() {
	// Deconstructor
	while (head != NULL)
		removeFront();
}

// Defining public member functions 
bool Board::isEmpty() {
	bool empty = false;
	if (head == NULL)
		empty = true;
	return empty;
}

// Add integer to back of list
void Board::addBack(Space* val) {
	// Check if list is empty
	if (isEmpty()) {
		// If empty, define value for head
		head = new BoardNode;
		head->val = val;
		head->right = NULL;
		head->left = NULL;
		head->up = NULL;
		head->down = NULL;
	}
	else {
		// Adding newData to list, reassigning needed pointers
		BoardNode* newData = new BoardNode;
		newData->val = val;
		newData->left = head->left;
		newData->right = head;
		head->left->right = newData;
		if (head->right == head)
			head->right = newData;
		head->left = newData;
	}
}

// Define all the pointer values for the board
void Board::connectBoard() {
	int count = 0;
	struct BoardNode* above = head;
	struct BoardNode* below = head;
	struct BoardNode* tempBelow = head;
	while (tempBelow->down != NULL) {
		below = above->down;
		tempBelow = below->down;
		while (above->right != NULL) {
			above = above->right;
			below = below->right;
			// Define pointers
			above->down = below;
			below->up = above;
		}
		count++;
		tempBelow = head;
		for (int i = 0; i < count; i++) {
			tempBelow = tempBelow->down;
		}
		above = tempBelow;
	}
}

// Create the entire board game
void Board::createBoard(int rows, int columns) {
	srand((unsigned)time(NULL));
	struct BoardNode* traverse;
	// Check if list is empty
	BoardNode* newData;
	// Get random location for cave
	int caveColumn1 = columns - 1;
	int caveColumn2 = columns - 2;
	int caveRow1 = (rand() % (rows-1)) + 1;
	int caveRow2 = (rand() % (rows - 1)) + 1;
	// Get random location for cave
	int houseColumn1;
	int houseColumn2;
	int houseColumn3;
	int playerRow = (rand() % (rows - 1)) + 0;
	// If empty, define value for head
	head = new BoardNode;
	head->val = new Empty;
	head->right = NULL;
	head->left = NULL;
	head->up = NULL;
	head->down = NULL;
	traverse = head;
	// Create rows and columns of board
	while (-3 < caveRow1 - caveRow2 && caveRow1 - caveRow2 < 3) {
		caveRow2 = (rand() % (rows - 1)) + 1;
	}
	for (int r = 0; r < rows; r++) {
		houseColumn1 = (rand() % columns) + 1;
		houseColumn2 = (rand() % columns) + 1;
		houseColumn3 = (rand() % columns) + 1;
		while (houseColumn1 == houseColumn2) {
			houseColumn2 = (rand() % columns) + 1;
		}
		while (houseColumn1 == houseColumn3 || houseColumn1 == houseColumn3) {
			houseColumn3 = (rand() % columns) + 1;
		}
		// Place player, store location of ship
		if (playerRow == r) {
			traverse->val->setSquare('P');
			traverse->val->setDefaultSquare('S');
			playerTile = traverse;
		}
		// Place houses
		for (int c = 1; c < columns; c++) {
			newData = new BoardNode;
			newData->val = new Empty;
			if (c == houseColumn1)
			{
				newData->val = new House;

			} 
			else if (c == houseColumn2)
			{
				newData->val = new House;

			} 
			else if (c == houseColumn3)
			{
				newData->val = new House;

			}
			// Place caves
			if (c == caveColumn1 && r == caveRow1) {
				newData->val = new Cave;
			} else if (c == caveColumn2 && r == caveRow2) {
				newData->val = new Cave;
			}
			traverse->right = newData;
			newData->left = traverse;
			newData->right = NULL;
			newData->down = NULL;
			traverse = traverse->right;
		}
		traverse = head;
		while (traverse->down != NULL) {
			traverse = traverse->down;
		}
		/// if last set to null
		if (r + 1 != rows) {
			newData = new BoardNode;
			newData->val = new Empty;
			traverse->down = newData;
			newData->left = NULL;
			newData->up = traverse;
			newData->right = NULL;
			newData->down = NULL;
			traverse = traverse->down;
		}
	}
	// connect the board, set up the pointers
	connectBoard();
}

// Print out front of list to the console
Space* Board::getFront() {
	return head->val;
}

// Move based on user input
BoardNode* Board::moveRight(BoardNode* tile) {
	tile->val->setToDefault();
	if (tile->right != NULL) {
		tile = tile->right;
	}
	return tile;
}

// Move based on user input
BoardNode* Board::moveLeft(BoardNode* tile) {
	tile->val->setToDefault();
	if (tile->left != NULL) {
		tile = tile->left;
	}
	return tile;
}

// Move based on user input
BoardNode* Board::moveUp(BoardNode* tile) {
	tile->val->setToDefault();
	if (tile->up != NULL) {
		tile = tile->up;
	}
	return tile;
}

// Move based on user input
BoardNode* Board::moveDown(BoardNode* tile) {
	tile->val->setToDefault();
	if (tile->down != NULL) {
		tile = tile->down;
	}
	return tile;
}


// Remove front value of the list
void Board::removeFront() {
	BoardNode* tranverse = head;
	BoardNode *oldHeadNode;
	// If list is empty define head as null
	// If not empty, reassign pointers
	while (head != NULL) {
		tranverse = head;
		head = head->down;
		cout << endl;
		while (tranverse->right != NULL) {
			cout << "D" << endl;
			cout << tranverse->val->getSquare();
			oldHeadNode = tranverse;
			tranverse->right->left = NULL;
			tranverse = tranverse->right;
			tranverse->left->right = tranverse;
			delete oldHeadNode;
		}
	}
	free(head);
}

// Output the board
void Board::printBoard() {
	struct BoardNode* goDown;
	struct BoardNode* goRight;
	goDown = head;
	if (!isEmpty()) {
		while (goDown != NULL) {
			goRight = goDown;
			while (goRight != NULL)
			{
				cout << goRight->val->getSquare();
				goRight = goRight->right;
			}
			cout << endl;
			goDown = goDown->down;
		}
	}
}

// Return player tile
BoardNode* Board::getPlayerTile() {
	return playerTile;
}
