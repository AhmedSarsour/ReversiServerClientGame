/*
 * BasicRules.h
 *  Created on: Nov 9, 2017.
 *  ID: 315397059.
 *      Author: ahmed sarsour.
 */
#ifndef BASICRULES_H_
#define BASICRULES_H_

#include <list>
#include "Point.h"
#include "Rules.h"


class BasicRules: public Rules {
public:
	BasicRules(int rows, int cols);
	void buildBoard(int** reversi);
	list<Point> checkPoints(int** reversi, int playerXorO);
	//Take my choices and swaps everything.

	void convertPieces(int** reversi, int playerXorO, int choiceRow, int choiceCol);
	int getCol() const {
		return col;
	}

	int getRow() const {
		return row;
	}
private:
	int row,col;
};

#endif /* BASICRULES_H_ */
