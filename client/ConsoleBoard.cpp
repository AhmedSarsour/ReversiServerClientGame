/*
 * ConsoleBoard.cpp.
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include <iostream>
#include "PointsList.h"
#include "BasicRules.h"
#include "ConsoleBoard.h"
#include "HumanPlayer.h"
#include "Player.h"
#include "Point.h"
#include "Rules.h"
#include "AiPlayer.h"
using namespace std;
/**
 * ConsoleBoard constructor.
 * @param rows.
 * @param cols.
 * function: creating the humanPlayers and allocating sufficient
 * memory space for the board.
 */
ConsoleBoard::ConsoleBoard(int rows, int cols, Player* player1, Player* player2) {
	this->firstPlayer = player1;
	this->secondPlayer = player2;
	this->row = rows;
	this->col = cols;
	//allocating sufficient memory-space for the game's ConsoleBoard.
	this->reversi = new int*[rows];
	for (int i = 0; i < rows; i++) {
		this->reversi[i] = new int[cols];
	}
}
/**
 * getRows function.
 * @return int.
 * function: returns the rows size of the board.
 */
int ConsoleBoard::getRows() const {
	return row;
}

/**
 * getCols function.
 * @return int.
 * function: returns the cols size of the board.
 */int ConsoleBoard::getCols() const {
	return col;
}
/**
 * getFirstPlayer function.
 * @return Player*.
 * function: returns a pointer to the first player.
 */
Player* ConsoleBoard::getFirstPlayer() const {
	return this->firstPlayer;
}
/**
 * getSecondPlayer function.
 * @return Player*.
 * function: returns a pointer to the second player.
 */
Player* ConsoleBoard::getSecondPlayer() const {
	return this->secondPlayer;
}
/**
 * getCurrentTurnPlayer function.
 * @return Player*.
 * function: returns a pointer to the player who's turn is now.
 */
Player* ConsoleBoard::getCurrentTurnPlayer(int playersDivide) const {
	if ((playersDivide % 2) + 1 == 1) {
		return ConsoleBoard::getFirstPlayer();
	}
	return ConsoleBoard::getSecondPlayer();
}
/**
 * getReversi function.
 * @return int**.
 * function: returns pointer to the board's array.
 */
int** ConsoleBoard::getReversi() {
	return this->reversi;
}
/**
 * buildTheBoard.
 * @param rules.
 * function: calls the buildBoard function according the given rules.
 */
void ConsoleBoard::buildTheBoard(Rules* rules) {
	rules->buildBoard(this->getReversi());
}
/**
 * printBoard function.
 * function: it prints the game's board on the console.
 */
void ConsoleBoard::printBoard() const {
	cout << "Current Board:" << endl << endl;
	//drawing the borders of the Board.
	int i = 0, j = 0;
//	char p1 = 'X', p2 = 'O';

	cout << " |";
	for (i = 0; i < this->col; i++) {
		cout << " " << i + 1;
		cout << " |";
	}
	cout << endl;
	cout << "--";
	for (int k = 0; k < this->col; k++) {
		cout << "----";
	}
	cout << endl;
	//drawing the Board's state.
	for (i = 0; i < this->row; i++) {
		cout << i + 1 << "|";
		for (j = 0; j < this->col; j++) {
			if (this->reversi[i][j] == 1) {
				cout << " " << ConsoleBoard::getFirstPlayer()->getName();
				cout << " |";
			} else if (this->reversi[i][j] == 2) {
				cout << " " << ConsoleBoard::getSecondPlayer()->getName();
				cout << " |";
			} else {
				cout << "  ";
				cout << " |";
			}
		}
		cout << endl;
		cout << "--";
		for (int k = 0; k < this->col; k++) {
			cout << "----";
		}
		cout << endl;
	}
}

/**
 * playGame function.
 * function: it begins the flow of the game, each player has a list of
 * choices, the player picks a choice, convert the pieces ...etc.
 */
void ConsoleBoard::playGame() {
	int playersDivide = 0, i = 0, j = 0;
	//building the game's rules.
	BasicRules playRules(this->row, this->col);
	this->firstPlayer->setBoardRowNCol(this->row, this->col);
	this->secondPlayer->setBoardRowNCol(this->row, this->col);
		PointsList choices;
	list<Point> emptyList;
	list<Point> choicesList;
	list<Point>::iterator iter;
	bool gameOver = false;
	bool p1EmptyChoices = false;
	bool p2EmptyChoices = false;
	//counter for the player's scores, to determine the winner.
	int countOs = 0, countXs = 0;
	bool listEmpty = false;
	while (1) {
		//getting a list of playable choices(points) for the players.
		choicesList = playRules.checkPoints(this->reversi,
				(playersDivide % 2) + 1);
//		cout << ConsoleBoard::getCurrentTurnPlayer(playersDivide)->getName()
//				<< ": it's your move." << endl;
		//printing the avaiable choices.
		for (iter = choicesList.begin(); iter != choicesList.end(); iter++) {
			if (choices.checkifContains(*iter) == false) {
				choices.addPoint(*iter);
			}
		}
		int choiceRow = 0, choiceCol = 0;
		Point pick(0, 0);
		//checking if list is empty or not and saving it in listEmpty var.
		listEmpty = choices.getMyList().empty();
		if (!listEmpty) {
			if ((playersDivide % 2) + 1 == 1) {
				p1EmptyChoices = false;
			} else {
				p2EmptyChoices = false;
			}
			// getting the choice(point) that the player pick.
			pick = (ConsoleBoard::getCurrentTurnPlayer(playersDivide))->playTurn(ConsoleBoard::getReversi(), &choices,
							playersDivide);
			choiceRow = pick.getX();
			choiceCol = pick.getY();
			//converting the pieces.
			playRules.convertPieces(this->reversi, (playersDivide % 2) + 1,
					choiceRow, choiceCol);
		} else {
			cout << "No possible moves. Play passes back to the other player.";
			if ((playersDivide % 2) + 1 == 1) {
				p1EmptyChoices = true;
			} else {
				p2EmptyChoices = true;
			}
			do {
				cout << "Press any key to continue." << endl;
			} while (cin.get() != '\n');
			cout << endl;
		}
		//printing the board.
		this->printBoard();
		if (!listEmpty) {
			cout << ConsoleBoard::getCurrentTurnPlayer(playersDivide)->getName()
					<< " played (" << choiceRow << "," << choiceCol << ")"
					<< endl << endl;
		}
		gameOver = true;
		countXs = 0;
		countOs = 0;
		//checking if there is more available spots to play.
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				if (this->reversi[i][j] == 0) {
					gameOver = false;
				}
				if (this->reversi[i][j] == 1) {
					countXs++;
				}
				if (this->reversi[i][j] == 2) {
					countOs++;
				}
			}
		}
		//if both players don't have any playable choices, game over.
		if (p1EmptyChoices && p2EmptyChoices) {
			gameOver = true;
			cout << "No more available choices for both players!." << endl;
		}
		/*
		 in case gameOver = true, no more playable choices and
		 the board is full.
		 */
		if (gameOver) {
			if (countXs > countOs) {
				cout << "Game over. The winner is: "
						<< ConsoleBoard::getFirstPlayer()->getName();
			} else if (countOs > countXs) {
				cout << "Game over. The winner is: "
						<< ConsoleBoard::getSecondPlayer()->getName();
			} else {
				cout << "Game over. Its a Draw!.";
			}
			cout << endl;
			break;
		}
		//clearing the lists of the points we had.
		choicesList.clear();
		choices.clearList();
		playersDivide++;
	}
}



void ConsoleBoard::deleteBoard() {
	int i;
	// releasing the memory we used for the game's ConsoleBoard.
	for (i = 0; i < this->row; i++) {
		delete[] this->reversi[i];
	}
	delete[] this->reversi;
}
