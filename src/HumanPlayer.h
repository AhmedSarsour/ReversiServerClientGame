/*
 * HumanPlayer.h
 *  Created on: Nov 11, 2017
 *      Author: Ahmed sarsour.
 *      Student ID: 315397059.
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include <string>
#include "Player.h"
#include "Point.h"
#include "PointsList.h"
using namespace std;

class HumanPlayer: public Player {
public:
	HumanPlayer(string pName);
	void setBoardRowNCol(int rowsSize, int colsSize) {
		this->boardRows = rowsSize;
		this->boardCols = colsSize;
	}
	string getName() const;
	Point playTurn(int** reversi, PointsList* choicesList,
			int playersDivide) ;
	~HumanPlayer() {
	}
private:
	string name;
	int boardRows, boardCols;
};

#endif /* HUMANPLAYER_H_ */
