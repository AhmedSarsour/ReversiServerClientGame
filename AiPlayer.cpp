/*
 * HumanPlayer.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: Ahmed sarsour.
 *      Student ID: 315397059.
 */
#include <iostream>
#include "AiPlayer.h"
#include "PointsList.h"
#include <string>

#include "Point.h"
#include "BasicRules.h"

/**
 * HumanPlayer constructor.
 * @param pName.
 * function: build the player and saves his name.
 */
AiPlayer::AiPlayer(string pName) {
	this->name = pName;
}
/**
 * getName function.
 * @return string.
 * function: returns the name of the player.
 */
string AiPlayer::getName() const {
	return this->name;
}

void AiPlayer::setBoardRowNCol(int rowsSize, int colsSize) {
	this->boardRows = rowsSize;
	this->boardCols = colsSize;
}

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
Point AiPlayer::playTurn(int** reversi, PointsList* choices,
		int playersDivide) {
	int computer = 2;
	//checkHuman.. == scores when computer played(Each move)
	//counter = the spot of the score with minimum points for human(in humanPSCores)(3 lines below this).
	//, min = min score for human.
	int checkHumanPlayerScore = 0, counter = 0, min = 0;
	//counters help determine the HumanPlayerScore.
	int countXs = 0, countOs = 0;
	int i = 0, j = 0;
	//list of scores for the human for each move the computer makes.
	list<int> humanPScores;
	//iterator for humanPScores list.
	list<int>::iterator scIter;
	//copying the board.
	int ** cpyBoard = this->copyBoard(reversi);
	//building rules, in order to use checkPoints.[WE should make A "GetRules function" from Board or something].
	BasicRules rules(this->boardRows, this->boardCols);
	list<Point>::iterator iter;

	//running of the list of moves.
	for (iter = choices->getMyList().begin();
			iter != choices->getMyList().end(); iter++) {
		//getting the currentMove (from the choices).
		Point currentMove = *(choices->getMyList().begin());
		//converting the piece according to the choice the computer pick.
		cpyBoard[currentMove.getX() - 1][currentMove.getY() - 1] = computer;
		//converting the pieces on cpyBoard.
		rules.convertPieces(cpyBoard, computer, currentMove.getX(),
				currentMove.getY());
		//making the score 0 for counting.
		checkHumanPlayerScore = 0;
		//counting the score of the human player.
		for (i = 0; i < this->boardRows; i++) {
			for (j = 0; j < this->boardCols; j++) {
				if (cpyBoard[i][j] == 1) {
					countXs++;
				}
				if (cpyBoard[i][j] == 2) {
					countOs++;
				}
			}
		}
		checkHumanPlayerScore = countXs - countOs;
		//adding the score to the scores list.
		humanPScores.push_back(checkHumanPlayerScore);
	}
	//getting the first score in the scores list.
	min = *(humanPScores.begin());
	counter = -1;
	//running on the scores list in order to know the spot(mekkooom) of the score the computer pick.
	for (scIter = humanPScores.begin(); scIter != humanPScores.end();
			scIter++) {
		//comparing the scores.
		if (min < *scIter) {
			min = *scIter;
		}
		//determining the spot of the score.
		counter++;
	}
	//putting an iterator on the beginning of the scores list.
	iter = choices->getMyList().begin();
	//running on the iterator by "counter steps".
	for (i = 0; i < counter; i++, iter++) {
	}
	//picking the BEST Point with the minimum human score.
	Point pcMove = *(iter);
	//converting the pieces of the computer choice on the MAIN reversi board.
	reversi[pcMove.getX() - 1][pcMove.getY() - 1] = computer;
	//deleting the CpyBoard!.
	this->deleteCopyBoard(cpyBoard);
	//returning the move the computer pick.
	return pcMove;
}

int ** AiPlayer::copyBoard(int **board) {
	//Creating dinamic matrix- a little help from stack overflow
	int ** cpyBoard = new int *[this->boardRows];
	for (int i = 0; i < this->boardRows; i++) {
		//Each row is a dinamic array.
		cpyBoard[i] = new int[this->boardCols];
	}
	for (int i = 0; i < this->boardRows; i++) {
		for (int j = 0; j < this->boardCols; j++) {
			cpyBoard[i][j] = board[i][j];
		}
	}
	return cpyBoard;
}

void AiPlayer::deleteCopyBoard(int** board) {
	int i;
	// releasing the memory we used for the game's ConsoleBoard.
	for (i = 0; i < this->boardRows; i++) {
		delete[] board[i];
	}
	delete[] board;
}
