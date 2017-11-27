/*
 * ConsoleBoard.h.
 *  Created on: Oct 24, 2017
 *      Author: ahmed sarsour.
 *      Student ID: 315397059.
 */
#ifndef CONSOLEBOARD_H_
#define CONSOLEBOARD_H_

#include <iostream>
#include <list>
#include "Board.h"
#include "Rules.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "Point.h"


class ConsoleBoard: public Board {
public:
	/**
	 * the Console Board's constructor.
	 * the Input: void.
	 * the output: void.
	 * the function operation: it gets the size of the game's Board and allocates
	 * sufficient memory space for the Board.
	 */
	ConsoleBoard(int row, int col, Player* player1, Player* player2);
	/**
	 * function name: BuildTheBoard.
	 * the Input: void.
	 * the output: void.
	 * the function operation: this function builds the game
	 * starting Board which is 8x8(on ex1) and the middle spots
	 * in it are occupied in order to prepare the game for play.
	 */
	void buildTheBoard(Rules* rules);
	/**
	 * function name: DeleteBoard.
	 * the Input: void.
	 * the output: void.
	 * the function operation: it deallocates all the memory space
	 * that was allocated for the game's Board.
	 */
	void deleteBoard();
	/**
	 * function name: PrintBoard.
	 * the Input: void.
	 * the output: void.
	 * the function operation: this function prints the game's Board.
	 */
	void printBoard() const;
	/**
	 * function name: getBoardSize.
	 * the Input: void.
	 * the output: int.
	 * the function operation: it returns the size of the game's Board.
	 */
	int getRows() const;
	/**
	 * function name: setBoardRows.
	 * the Input: int.
	 * the output: void.
	 * the function operation: it sets a new rows size of the game's Board.
	 */
	int getCols() const;
	/**
	 * function name: SetBoardCols.
	 * the Input: int.
	 * the output: void.
	 * the function operation: it sets new size of the game's Board columns.
	 */
	void playGame();

	/**
	 * getReversi function.
	 * @return int**.
	 * function: returns pointer to the board's array.
	 */
	int** getReversi();

	/**
	 * getFirstPlayer function.
	 * @return Player*.
	 * function: returns a pointer to the first player.
	 */
	Player* getFirstPlayer() const;

	/**
	 * getSecondPlayer function.
	 * @return Player*.
	 * function: returns a pointer to the second player.
	 */
	Player* getSecondPlayer() const;

	/**
	 * getCurrentTurnPlayer function.
	 * @return Player*.
	 * function: returns a pointer to the player who's turn is now.
	 */
	Player* getCurrentTurnPlayer(int playersDivide) const;
private:
	int row, col;
	Player* firstPlayer;
	Player* secondPlayer;
	int **reversi;
};
#endif /* ConsoleBoard_H_ */
