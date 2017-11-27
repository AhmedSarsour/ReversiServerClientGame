/*
 * main.cpp
 *  Created on: Oct 24, 2017.
 *      Author: ahmed sarsour.
 *      student ID:315397059
 */
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "BasicRules.h"
#include "ConsoleBoard.h"
using namespace std;

int main() {
	int row,col;
	row = 8;
	col = 8;
	Player* firstPlayer;
    Player* secondPlayer;
    int option;//Option of the game type 1- against human 2 - against computer.
    cout << "Hi Welcome to Reversi please select your kind of game to play:" << endl;
    cout << endl;
    cout << "Press 1 to play against other player." << endl;
    cout << endl;
    cout << "Press 2 to play against the computer." << endl;
    cin >>option;

    if (option == 1) {
        cout << "You selected to play against other player" << endl;
        firstPlayer= new HumanPlayer("X");

        secondPlayer = new HumanPlayer("O");
    }
    if (option == 2) {
        cout << "You selected to play against the computer" << endl;
        firstPlayer= new HumanPlayer("X");

        secondPlayer = new AiPlayer("O");
    }


    secondPlayer->setBoardRowNCol(row, col);
	BasicRules* rules = new BasicRules(row,col);
	//	//creating the board.
	Board* theGameBoard = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
	theGameBoard->buildTheBoard(rules);
    theGameBoard->printBoard();
	theGameBoard->playGame();
	theGameBoard->deleteBoard();
	delete theGameBoard;
	delete firstPlayer;
	delete secondPlayer;
	delete rules;



	return 0;
}
