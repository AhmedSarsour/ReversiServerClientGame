/*
 * BasicRules.h
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#ifndef BASICRULES_H_
#define BASICRULES_H_

#include <list>
#include "Point.h"
#include "Rules.h"


class BasicRules: public Rules {
public:
	/**
 * BasicRules constructior.
 * @param: rows;
 * @param: cols
 */
	BasicRules(int rows, int cols);
/**
 * buildBoard function.
 * @param: reversi.
 * function: it builds the initial board according the basic rules
 * of the game.
 */
	void buildBoard(int** reversi);
/**
 * checkPoints function.
 * @param reversi the game board.
 * @param playerXorO who is the player.
 * @return list<Point>.
 * function: it returns a list of a playable choices, list of Points.
 */
	list<Point> checkPoints(int** reversi, int playerXorO);
	//Take my choices and swaps everything.
/**
 * convertPieces function.
 * @param reversi the game board.
 * @param playerXorO who is the player.
 * @param choiceRow the row we just chose.
 * @param ChoiceCol the column we just chose.
 * function: it gets the Point that the player chose, and then converts
 * the nearby pieces of the game according the basic rules of the game.
 */
	void convertPieces(int** reversi, int playerXorO, int choiceRow, int choiceCol);

private:
	int row,col;
};

#endif /* BASICRULES_H_ */
