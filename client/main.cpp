/*
 * main.cpp
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include<iostream>
#include "Player.h"
#include "Board.h"
#include "BasicRules.h"
#include "ConsoleBoard.h"
#include <stdlib.h>
#include "Client.h"
using namespace std;

int main() {
    int row,col;
	row = 8;
	col = 8;
	Player* firstPlayer = new HumanPlayer("X");
    Player* secondPlayer = new HumanPlayer("O");
    Client client("127.0.0.1", 8000);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }
    int num1, num2;
    char op;
    secondPlayer->setBoardRowNCol(row, col);
    BasicRules *rules = new BasicRules(row, col);
    //creating the board.
    Board *theGameBoard = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
    theGameBoard->buildTheBoard(rules);
    int index = 1;
    int playerXorO = 1;
    int looper = 0;
    while (true) {
        // Wait until connection or move of the other player.
        if (index != 2) {
            cout << "Waiting for the other player" << endl;
        }
        int x = client.wait();

        if (x == 1) {
            cout << "You are the first player X" << endl;
            playerXorO = 1;
        }

        if (x == 2){
            playerXorO = 2;
            cout << "You are the second player player O" << endl;
            cout << "Waiting for the other player" << endl;
        }
        if((index >= 3 && playerXorO == 1) || (index >= 2 && playerXorO == 2)) {
            Point move = client.getMove();
            if (playerxorO == 1) {
                cout << "O played " << move;
            } else {
                cout << "X player " << move;
            }
            theGameBoard->getReversi()[move.getX() - 1][move.getY() - 1] = 3 - playerXorO;
            rules->convertPieces(theGameBoard->getReversi(), 3 - playerXorO, move.getX(), move.getY());
        }

        if (index != 1) {
            theGameBoard->printBoard();
            list<Point> moves = rules->checkPoints(theGameBoard->getReversi(), playerXorO);
            PointsList choicesList;
            list<Point>::iterator iter;
            //adding the points to choice("PointsList")
            for (iter = moves.begin(); iter != moves.end(); iter++) {
                //we don't add the same point twice.
                if (choicesList.checkifContains(*iter) == false) {
                    choicesList.addPoint(*iter);
                }
            }
            do {
                cout << "your choices are: ";
                //printing the list of availabe choices.
                choicesList.runOnElms();
                cout << endl << endl;
                cout << "Please enter your move row,col: ";
                cin >> num1 >> num2;
                looper = 0;
                //in case the player entered something beside int.
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    looper = 1;
                }
                //in case the player didn't pick an available choice.
                if (!choicesList.checkifContains(Point(num1, num2))) {
                    cout << "invalid input, choose again.";
                    looper = 1;
                }
                cout << endl;
            }while (looper == 1);
            theGameBoard->getReversi()[num1 - 1][num2 - 1] = playerXorO;
            rules->convertPieces(theGameBoard->getReversi(), playerXorO, num1 , num2);
            try {
                Point result = client.sendMove(num1, num2);
                cout << result << endl;
            } catch (const char *msg) {
                cout << "Failed to send exercise toserver. Reason: " << msg << endl;
            }
        }

        index++;
    }
    //Deletes the memmory we just allocated.
    theGameBoard->deleteBoard();
    delete theGameBoard;
    delete firstPlayer;
    delete secondPlayer;
    delete rules;

}
//
//
//int main() {
//	int row,col;
//	row = 8;
//	col = 8;
//	Player* firstPlayer;
//    Player* secondPlayer;
//    int option;//Option of the game type 1- against human 2 - against computer.
//    cout << "Hi Welcome to Reversi please select your kind of game to play:" << endl;
//    cout << endl;
//    cout << "Press 1 to play against other player." << endl;
//    cout << endl;
//    cout << "Press 2 to play against the computer." << endl;
//    cin >>option;
////Human player.
//    if (option == 1) {
//        cout << "You selected to play against other player" << endl;
//        firstPlayer= new HumanPlayer("X");
//
//        secondPlayer = new HumanPlayer("O");
//    }
//    //Computer player.
//    if (option == 2) {
//        cout << "You selected to play against the computer" << endl;
//        firstPlayer= new HumanPlayer("X");
//
//        secondPlayer = new AiPlayer("O");
//    }
//    //We selected option from the menu.
//    if (option == 1 || option ==2) {
//        secondPlayer->setBoardRowNCol(row, col);
//        BasicRules *rules = new BasicRules(row, col);
//        //	//creating the board.
//        Board *theGameBoard = new ConsoleBoard(row, col, firstPlayer, secondPlayer);
//        theGameBoard->buildTheBoard(rules);
//        theGameBoard->printBoard();
//        theGameBoard->playGame();
//        //Deletes the memmory we just allocated.
//        theGameBoard->deleteBoard();
//        delete theGameBoard;
//        delete firstPlayer;
//        delete secondPlayer;
//        delete rules;
//
//
//    }
//	return 0;
//}
