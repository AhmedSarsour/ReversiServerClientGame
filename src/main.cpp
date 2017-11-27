/*
 * main.cpp
 *  Created on: Oct 24, 2017.
 *      Author: ahmed sarsour.
 *      student ID:315397059
 */
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "BasicRules.h"
#include "ConsoleBoard.h"
using namespace std;

int main() {
	int row,col;
	row = 8;
	col = 8;
	Player* firstPlayer = new HumanPlayer("X");
	Player* secondPlayer = new AiPlayer("O");
    secondPlayer->setBoardRowNCol(row, col);
	BasicRules* rules = new BasicRules(row,col);
	//	//creating the board.
	Board* theGameBoard = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
	theGameBoard->buildTheBoard(rules);
    theGameBoard->printBoard();
	theGameBoard->playGame();
	theGameBoard->deleteBoard();
	delete theGameBoard;
	delete firstPlayer;
	delete secondPlayer;
	delete rules;



	return 0;
}
