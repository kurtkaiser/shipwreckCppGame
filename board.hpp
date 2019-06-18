/***************************************************************************************************
** Author:  Kurt Kaiser
** Website: kurtkaiser.us
** Info:    Designed a one-player, text-based game, the player can move through 
**     	    spaces to get items and accomplish goals.
****************************************************************************************************/

#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "space.hpp"
#include "house.hpp"
#include "empty.hpp"
#include "player.hpp"

struct BoardNode
{
	Space* val;
	BoardNode *right;
	BoardNode *left;
	BoardNode *up;
	BoardNode *down;
};

// Defining the interface for the class
class Board
{
private:
	// Declaring private variables
	struct BoardNode* head;
	struct BoardNode* playerTile;
	Player player;
public:
	// Class Default Constructor
	Board();
	~Board();
	// Declaring public member functions

	bool isEmpty();
	void addBack(Space*);
	Space* getFront();
	BoardNode* getPlayerTile();
	void removeFront();
	void createBoard(int, int);
	void connectBoard();
	void printBoard();
	BoardNode* moveRight(BoardNode*);
	BoardNode* moveLeft(BoardNode*);
	BoardNode* moveDown(BoardNode*);
	BoardNode* moveUp(BoardNode*);
};

#endif
