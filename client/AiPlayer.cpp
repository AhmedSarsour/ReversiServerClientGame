/*
 * HumanPlayer.cpp
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include <iostream>
#include "AiPlayer.h"
#include "PointsList.h"
#include <string>
#include "Point.h"
#include "BasicRules.h"

/**
 * AiPlayer constructor.
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
	// Here we don't print its your move because the computer knows it his move.
	int computer = 2;
	//checkHuman.. == scores when computer played(Each move)
	//counter = the spot of the score with minimum points for the enemy.
	//min == minimum score for human.
	int checkHumanPlayerScore = 0, counter = 0, min = 0;
	int i = 0, j = 0;
	//counters help determine the HumanPlayerScore.
	int countXs = 0, countOs = 0;
	//list of scores for the human for each move the computer makes.
	list<int> humanPScores;
	//iterator for humanPScores list.
	list<int>::iterator scIter;

	list<list<int> > humanDeepScores;
	//copying the board.
	int** cpyBoard = this->copyBoard(reversi);
	//copying the copy board after making a pc move.
	int** deepCopy = this->copyBoard(reversi);
	//copying the board after Humanplayer played a move after pc pick move.
	int** deeperCopy = this->copyBoard(reversi);
	//building rules, in order to use checkPoints
	BasicRules rules(this->boardRows, this->boardCols);
	//list of moves(choices) for the computer.
	list<Point> moves = rules.checkPoints(reversi, computer);
	list<Point>::iterator iter;
	//adding the points to choice("PointsList")
	for (iter = moves.begin(); iter != moves.end(); iter++) {
		//we don't add the same point twice.
		if (choices->checkifContains(*iter) == false) {
			choices->addPoint(*iter);
		}
	}
	//running of the list of moves.
	for (iter = choices->getMyList().begin();
		 iter != choices->getMyList().end(); iter++) {
		//getting the currentMove (from the choices).
		Point currentMove = *(iter);
		//copying the main board status.
		this->copyValues(cpyBoard, reversi);
		//converting the piece according to the choice the computer pick.
		cpyBoard[currentMove.getX() - 1][currentMove.getY() - 1] = computer;
		//converting the pieces on cpyBoard.
		rules.convertPieces(cpyBoard, computer, currentMove.getX(),
							currentMove.getY());
		//copying the board after the computer pick a choice.
		this->copyValues(deepCopy, cpyBoard);
		//list of choices for the human player.
		PointsList humanChoicesList;
		//getting list of choices.
		list<Point> humanMoves = rules.checkPoints(deepCopy, 1);
		//iterator for the human moves list.
		list<Point>::iterator iter2;
		for (iter2 = humanMoves.begin(); iter2 != humanMoves.end(); iter2++) {
			//we don't add the same point twice.
			if (humanChoicesList.checkifContains(*iter2) == false) {
				humanChoicesList.addPoint(*iter2);
			}
		}
		//list of scores each time a player picks a move.
		list<int> humanScores;
		//running on the choices of the human player.
		for (iter2 = humanChoicesList.getMyList().begin();
			 iter2 != humanChoicesList.getMyList().end(); iter2++) {
			//trying all the moves.
			Point curHumanMove = *(iter2);
			//copying the status of the board before the player picks a move.
			this->copyValues(deeperCopy, deepCopy);
			//1 == X == the value of x in the int dynamic array.
			deeperCopy[curHumanMove.getX() - 1][curHumanMove.getY() - 1] = 1;
			//converting the pieces according to the pick choice.
			rules.convertPieces(deeperCopy, 1, curHumanMove.getX(),
								curHumanMove.getY());
			//making the score 0 for counting.
			checkHumanPlayerScore = 0;
			countXs = 0, countOs = 0;
			//counting the score of the human player.
			for (i = 0; i < this->boardRows; i++) {
				for (j = 0; j < this->boardCols; j++) {
					if (deeperCopy[i][j] == 1) {
						countXs++;
					}
					if (deeperCopy[i][j] == 2) {
						countOs++;
					}
				}
			}
			//calculating the score.
			checkHumanPlayerScore = countXs - countOs;
			//adding the score to the scores list.
			humanScores.push_back(checkHumanPlayerScore);
		}
		//adding the list of scores into the list of lists.
		humanDeepScores.push_back(humanScores);
	}
	/*maxInList saves the highest score of the choices he has
	 according to the computer moves.*/
	int maxInList = 0;
	//making a list of the best choices.
	list<int> bestChoices;
	//making a list of lists iterator.
	list<list<int> >::iterator humanScIter;
	//making an iterator for an int list.
	list<int>::iterator runOnScores;
	//now filling the list of best choices.
	for (humanScIter = humanDeepScores.begin();
		 humanScIter != humanDeepScores.end(); humanScIter++) {
		//getting the first score of each list.
		maxInList = *(*humanScIter).begin();
		//running on the scores on the list.
		for (runOnScores = (*humanScIter).begin();
			 runOnScores != (*humanScIter).end(); runOnScores++) {
			//comparing the scores.
			if (maxInList < *runOnScores) {
				maxInList = *runOnScores;
			}
		}
		//adding the maximum score (best choice for human player).
		bestChoices.push_back(maxInList);
		cout << endl;
	}
	//setting min to be the first score in the bestchoices list.
	min = *(bestChoices.begin());
	for (runOnScores = bestChoices.begin(); runOnScores != bestChoices.end();
		 runOnScores++) {
		//finding the minimum score of the best choices' scores.
		if (min > *runOnScores) {
			min = *runOnScores;
		}
	}
	//countMin for finding the spot of the score in the list.
	int countMin = 0;
	for (runOnScores = bestChoices.begin(); runOnScores != bestChoices.end();
		 runOnScores++) {
		/*
		 * looking for the min spot in the list in order to
		 * determine the number of steps we need to make
		 * in the computer choices list in order to get the
		 * choice that leads to the min score.
		 */
		if (min == *runOnScores) {
			min = *runOnScores;
			break;
		}
		//counting steps.
		countMin++;
	}
	//putting an iterator on the beginning of the computer choices list.
	iter = choices->getMyList().begin();
	//running on choices' iterator by "countMin steps".
	for (i = 0; i < countMin; i++) {
		iter++;
	}
	//picking the BEST choice (point) with the minimum score of best choices for human.
	Point pcMove = *(iter);
	//converting the pieces of the computer choice on the MAIN reversi board.
	reversi[pcMove.getX() - 1][pcMove.getY() - 1] = computer;
	//deleting the boards we allocated previously.
	this->deleteCopyBoard(deeperCopy);
	this->deleteCopyBoard(deepCopy);
	this->deleteCopyBoard(cpyBoard);
	//returning the move the computer pick.
	return pcMove;
}

/**
 *copyBoard function:
 *@param: board
 *@return int**
 *function: it gets a reversi board, creates a dynamic array
 * and copies the values of the given reversi board.
 */
int ** AiPlayer::copyBoard(int **board) {
	//Creating dinamic matrix- a little help from stack overflow
	int ** cpyBoard = new int *[this->boardRows];
	for (int i = 0; i < this->boardRows; i++) {
		//Each row is a dinamic array.
		cpyBoard[i] = new int[this->boardCols];
	}
	this->copyValues(cpyBoard, board);
	return cpyBoard;
}
/**
 * copyValues function.
 * @param int** cpy.
 * @param int** mainReversi.
 * copyValues: it copies the valuse from the main reversi into the cpy.
 */
void AiPlayer::copyValues(int** cpy, int** mainReversi) {
	for (int i = 0; i < this->boardRows; i++) {
		for (int j = 0; j < this->boardCols; j++) {
			cpy[i][j] = mainReversi[i][j];
		}
	}
}

/**
 * deleteCopyBoard.
 * @param int** board.
 * function: it gets a board and deallocates it, it mainly frees the memory.
 */
void AiPlayer::deleteCopyBoard(int** board) {
	int i;
	// releasing the memory we used for the game's ConsoleBoard.
	for (i = 0; i < this->boardRows; i++) {
		delete[] board[i];
	}
	delete[] board;
}
