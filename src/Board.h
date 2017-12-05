/*
 * Board.h
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Rules.h"
#include "Player.h"
using namespace std;
/**
 * Board.
 * Interface of board because all the functions are virtual.
 */
class Board {
public:
	/**
 * function name: PrintBoard.
 * the Input: void.
 * the output: void.
 * the function operation: this function prints the game's Board.
 */
	virtual void printBoard() const = 0;
/**
 * getCols
 * @return how many columns the board has.
 */
	virtual int getCols() const= 0;
    /**
 * getReversi function.
 * @return int**.
 * function: returns pointer to the board's array.
 */
	virtual int** getReversi()= 0;
/**
 * getRows
 * @return how many rows the board has.
 */
	virtual int getRows() const= 0;
/**
 * function name: DeleteBoard.
 * the Input: void.
 * the output: void.
 * the function operation: it deallocates all the memory space
 * that was allocated for the game's Board.
 */
	virtual void deleteBoard()= 0;
/**
	 * playGame.
	 * Doing the game process. By the players type we chose.
	 */
	virtual void playGame() = 0;
    /**
 * getFirstPlayer function.
 * @return Player*.
 * function: returns a pointer to the first player.
 */
	virtual Player* getFirstPlayer() const = 0;
    /**
     * getSecondPlayer function.
     * @return Player*.
     * function: returns a pointer to the second player.
     */
    virtual Player* getSecondPlayer() const = 0;
    /**
     * getCurrentTurnPlayer function.
     * @return Player*.
     * function: returns a pointer to the player who's turn is now.
     */
    virtual Player* getCurrentTurnPlayer(int playersDivide) const = 0;
    /**
     * function name: BuildTheBoard.
     * the Input: void.
     * the output: void.
     * the function operation: this function builds the game
     * starting Board which is 8x8(on ex1) and the middle spots
     * in it are occupied in order to prepare the game for play.
     */
    virtual void buildTheBoard(Rules* rules) = 0;
	virtual ~Board() {}
private:
	int row, col; //ROws and cols to the reversi.
	int** reversi; //The reversi array.
	Player* firstPlayer; //The first player.
	Player* secondPlayer; //The second player.
};

#endif /* BOARD_H_ */
