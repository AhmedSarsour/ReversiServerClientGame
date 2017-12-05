/*
 * Player.h interface.
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <string>

#include "Point.h"
#include "PointsList.h"
/**
 * Player.
 * Interface of player in the game.
 */
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
