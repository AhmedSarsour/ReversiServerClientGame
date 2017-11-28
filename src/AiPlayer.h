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
    /**
 * Computer player constructor.
 * @param pName.
 * function: build the player and saves his name.
 */
    AiPlayer(string pName);
/**
 * setBoardRowCol
 * Setting the board row and cols.
 * @param rowsSize how many rows we want to have.
 * @param colsSize how many cols we want to have.
 */
	void setBoardRowNCol(int rowsSize, int colsSize);
    /**
 * getName function.
 * @return string.
 * function: returns the name of the player.
 */
	string getName() const;
/**
 * playTurn function.
 * @param: reversi.
 * @param: choices.
 * @param: playersDivide.
 * @return: int.
 * function: the human player gets to play his turn, he gets a list of
 * avaiable choices, picks one, and the function converts the piece of
 * pick choice, and then returns the choice he pick.
 */
	Point playTurn(int** reversi, PointsList* choicesList,
			int playersDivide) ;
	~AiPlayer() {
	}
private:
	string name;
	int boardRows, boardCols;
    /**
     * copyBoard
     * @param board a board.
     * @return copy of this board.
     */
    int** copyBoard(int **board);
/**
 * deleteCopyBoard.
 * Deletes the board that we allocated.
 * @param board the board we allocated.
 */
    void deleteCopyBoard(int** board);


};
#endif // AIPLAYER_H_
