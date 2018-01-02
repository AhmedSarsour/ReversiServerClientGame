/*
 * HumanPlayer.cpp
 *
 *      student 1: ahmed sarsour. 315397059
 *      student 2: Eliad Arzuan 206482622
 */
#include <iostream>
#include "RemotePlayer.h"
#include "PointsList.h"
#include <string>

#include "Point.h"
using namespace std;

// Constructor.
RemotePlayer::RemotePlayer(string pName, int playerXorY, Client &client): client(client) {
    this->name = pName;
    this->playerXorY = playerXorY;
}
/**
 * getName function.
 * @return string.
 * function: returns the name of the player.
 */
string RemotePlayer::getName() const {
    return this->name;
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
Point RemotePlayer::playTurn(int** reversi, PointsList* choices, int playersDivide)  {
    int choiceRow, choiceCol;
    //This client is this player.
    int player = playersDivide % 2 + 1;
    bool listEmpty = choices->getMyList().empty();
    if (player == this->playerXorY) {
        if(!listEmpty) {
            if (player == 1) {
                cout << "X: it's your move." << endl;
            }

            if (player == 2) {
                cout << "O: it's your move." << endl;
            }

            choices->sortList();
            int looper = 1;
            do {
                cout << "your choices are: ";
                //printing the list of availabe choices.
                choices->runOnElms();
                cout << endl << endl;
                cout << "Please enter your move row,col: ";
                char comma;
                cin >> choiceRow >> comma >> choiceCol;
                looper = 0;

                if (comma != ',') {
                    cout << "You forgot to put comma" << endl;
                    looper = 1;
                }
                //in case the player entered something beside int.
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    looper = 1;
                }
                //in case the player didn't pick an available choice.
                if (!choices->checkifContains(Point(choiceRow, choiceCol))) {
                    cout << "invalid input, choose again.";
                    looper = 1;
                }
                cout << endl;
            } while (looper == 1);
            //converting the piece according to the player choice.
            if ((playersDivide % 2) + 1 == 1) {
                reversi[choiceRow - 1][choiceCol - 1] = 1;
            } else {
                reversi[choiceRow - 1][choiceCol - 1] = 2;
            }
        //in case no choices for player. we send to server a move = point(0,0).
        } else {
            choiceRow = 0;
            choiceCol = 0;
        }
        //Sending the move to the other client.
        try {
            Point result = client.sendMove(choiceRow, choiceCol);
        } catch (const char *msg) {
            cout << "Failed to send exercise to server. Reason: " << msg << endl;
            try {
                //We can not write to the socket but in case of writing we clean the port.
                client.writeToSocket("aa");
            } catch (const char *msg) {
                cout << "Reason:" << msg << endl;
                exit(0);
            }
        }
    } else { //This player is not that player so we will get it through the socket.
        cout << "Waiting for the other player" << endl;
        try {
            //Getting the move of the other player
            Point move = client.getMove();
            choiceRow = move.getX();
            choiceCol = move.getY();
            //in case the player had no choices, we dont change anything.
            if (choiceRow != 0) {
                //converting the piece according to the player choice.
                if ((playersDivide % 2) + 1 == 1) {
                    reversi[choiceRow - 1][choiceCol - 1] = 1;
                } else {
                    reversi[choiceRow - 1][choiceCol - 1] = 2;
                }
            }
        } catch (const char *msg) {
            cout << "Failed to get exercise to server. Reason: " << msg << endl;
            try {
                //We can not write to the socket but in case of writing we clean the port.
                client.writeToSocket("aa");
            } catch (const char *msg) {
                cout << "Reason:" << msg << endl;
                exit(0);
            }
           // client.closeSocket();
           // exit(0);
        }
    }
    return Point(choiceRow, choiceCol);
}
