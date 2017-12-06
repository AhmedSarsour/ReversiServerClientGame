/*
 * ConsoleBoard.h.
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
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
 * getRows
 * @return how many rows the board has.
 */
	int getRows() const;
/**
 * getCols
 * @return how many columns the board has.
 */
	int getCols() const;
	/**
	 * playGame.
	 * Doing the game process.
	 */
	void playGame();

    void playForOnePlayer(int player);
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
