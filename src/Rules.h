/*
 * Rules.h
 *       student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#ifndef RULES_H_
#define RULES_H_
#include <iostream>
#include "Player.h"


class Rules {
public:
	/**
	 * buildBoard function.
	 * @param: reversi.
	 * function: it builds the initial board according the rules
	 * of the game.
	 */
	virtual void buildBoard(int** reversi) = 0;

	/**
	 * checkPoints function.
	 * @param reversi.
	 * @param playerXorO.
	 * @param choiceList.
	 * @return list<Point>.
	 * function: it returns a list of a playable choices, list of Points.
	 */
	virtual list<Point> checkPoints(int** reversi, int playerXorO) = 0;
	/**
	 * convertPieces function.
	 * @param reversi.
	 * @param playerXorO.
	 * @param choiceRow.
	 * @param ChoiceCol.
	 * function: it gets the Point that the player chose, and then converts
	 * the nearby pieces of the game according the basic rules of the game.
	 */
	virtual void convertPieces(int** reversi, int playerXorO, int choiceRow,
			int choiceCol) = 0;
	//default destructor.
	virtual ~Rules() {}
	//virtual bool isPlayerWin(Player* player, Board* board);
};

#endif /* RULES_H_ */
