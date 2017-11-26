/*
 * Board.h
 *  Created on: Nov 11, 2017
 *  ID: 315397059.
 *      Author: ahmed sarsour
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Rules.h"
#include "Player.h"
using namespace std;

class Board {
public:
	virtual void printBoard() const = 0;
	virtual int getCols() const= 0;
	virtual int** getReversi()= 0;
	virtual int getRows() const= 0;
	virtual void deleteBoard()= 0;
	virtual void playGame() = 0;
	virtual Player* getFirstPlayer() const = 0;
	virtual Player* getSecondPlayer() const = 0;
	virtual Player* getCurrentTurnPlayer(int playersDivide) const = 0;
	virtual void buildTheBoard(Rules* rules) = 0;
	virtual ~Board() {}
private:
	int row, col;
	int** reversi;
	Player* firstPlayer;
	Player* secondPlayer;
};

#endif /* BOARD_H_ */
