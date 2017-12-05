/*
 * main.cpp
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "BasicRules.h"
#include "ConsoleBoard.h"
#include <stdlib.h>
#include "Client.h"
using namespace std;

int main() {
    Client client("127.0.0.1", 8000);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }
    int num1, num2;
    char op;
    while (true) {
        cout << "Enter an exercise (e.g., 15*19):";
        cin >> num1 >> op >> num2;
        cout << "Sending exercise: " << num1 << op
             << num2 << endl;
        try {
            int result = client.sendExercise(num1,
                                             op, num2);
            cout << "Result: " << result << endl;
        } catch (const char *msg) {
            cout << "Failed to send exercise toserver. Reason: " << msg << endl;
        }
    }
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
