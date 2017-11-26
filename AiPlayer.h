/*
 * HumanPlayer.h
 *  Created on: Nov 11, 2017
 *      Author: Ahmed sarsour.
 *      Student ID: 315397059.
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_
#include <string>
#include "Player.h"
#include "Point.h"
#include "PointsList.h"

class AiPlayer: public Player {
public:
    AiPlayer(string pName);
	void setBoardRowNCol(int rowsSize, int colsSize);
	string getName() const;
	Point playTurn(int** reversi, PointsList* choicesList,
			int playersDivide) ;
	void deleteCopyBoard(int** board);
	~AiPlayer() {
	}
private:
	string name;
	int boardRows, boardCols;
    int** copyBoard(int **board);

};
#endif // AIPLAYER_H_
