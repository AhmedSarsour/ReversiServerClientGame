/*
 * AiPlayer.h
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
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
    void copyValues(int** cpy, int** mainReversi);
	void deleteCopyBoard(int** board);
	bool playerKind(){
		return false;
	}
	~AiPlayer() {
	}
private:
	string name;
	int boardRows, boardCols;
    int** copyBoard(int **board);

};
#endif // AIPLAYER_H_
