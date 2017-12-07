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
    cout << "The player is " << playersDivide << endl;
    int player = playersDivide % 2 + 1;
    if (player == this->playerXorY) {
        int looper = 1;
        do {
            cout << "your choices are: ";
            //printing the list of availabe choices.
            choices->runOnElms();
            cout << endl << endl;
            cout << "Please enter your move row,col: ";
            cin >> choiceRow >> choiceCol;
            looper = 0;
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

        //Sending the move to the other client.
        try {
            cout << "sending: " << Point(choiceRow, choiceCol) << endl;
            Point result = client.sendMove(choiceRow, choiceCol);
        } catch (const char *msg) {
            cout << "Failed to send exercise toserver. Reason: " << msg << endl;
        }
    } else { //This player is not that player so we will get it through the socket.
        cout << "Waiting for the other player" << endl;
        try {
            //Getting the move of the other player
            Point move = client.getMove();
            choiceRow = move.getX();
            choiceCol = move.getY();

            cout << "move is " << move << endl;
            //converting the piece according to the player choice.
            if ((playersDivide % 2) + 1 == 1) {
                reversi[choiceRow - 1][choiceCol - 1] = 1;
            } else {
                reversi[choiceRow - 1][choiceCol - 1] = 2;
            }
        } catch (const char *msg) {
            cout << "Failed to get exercise to server. Reason: " << msg << endl;
        }
    }
    return Point(choiceRow, choiceCol);
}
