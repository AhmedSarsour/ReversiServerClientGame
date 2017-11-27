/*
 * Player.h interface.
 *  Created on: Nov 12, 2017
 *      Author: Ahmed sarsour.
 *      Student ID: 315397059.
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

#include "Point.h"
#include "PointsList.h"

class Player{
public:
	virtual void setBoardRowNCol(int rowsSize, int colsSize) = 0;
	virtual Point playTurn(int** reversi, PointsList* choicesList, int playersDivide)  = 0;
	/**
	 * getName function.
	 * @return string.
	 * function: returns the name of the player.
	 */
	virtual string getName() const = 0;
	void setName(const string& name) {
		this->name = name;
	}
	virtual ~Player(){}

private:
	string name;
	int boardRows, boardCols;
};

#endif /* PLAYER_H_ */
