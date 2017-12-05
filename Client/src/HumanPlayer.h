/*
 * HumanPlayer.h
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
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
	/**
 * HumanPlayer constructor.
 * @param pName.
 * function: build the player and saves his name.
 */
	HumanPlayer(string pName);
    /**
     * setBoardRowNCOl.
     * @param rowsSize how many rows we want the board will have.
     * @param colsSize how many columns we want the board will have.
     */
	void setBoardRowNCol(int rowsSize, int colsSize) {
		this->boardRows = rowsSize;
		this->boardCols = colsSize;
	}
/**
 * getName function.
 * @return string.
 * function: returns the name of the player.
 */
	string getName() const;
/**
 * playTurn function.
 * @param: reversi.
 * @param: choices pointslist of choises the player had.
 * @param: playersDivide which player had the choices.
 * @return: int.
 * function: the human player gets to play his turn, he gets a list of
 * avaiable choices, picks one, and the function converts the piece of
 * pick choice, and then returns the choice he pick.
 */
	Point playTurn(int** reversi, PointsList* choicesList,
			int playersDivide) ;
	~HumanPlayer() {
	}
private:
	string name;//The name of the player (for example x on console board).
	int boardRows, boardCols;//The rows and columns number.
};

#endif /* HUMANPLAYER_H_ */
