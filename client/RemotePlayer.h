//
// Created by eliad1998 on 06/12/17.
//

#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "Player.h"
#include "Client.h"

class RemotePlayer: public Player {
public:
    /**
 * RemotePlayer constructor.
 * @param pName.
 * @param playerXorY 1 if the current client is x, 2 if y
 * function: build the player and saves his name.
 */
    RemotePlayer(string pName, int playerXorY, Client &client);
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
 * function: the  player gets to play his turn, he gets a list of
 * avaiable choices, picks one, and the function converts the piece of
 * pick choice, and then returns the choice he pick.
 */
    Point playTurn(int** reversi, PointsList* choicesList,
                   int playersDivide) ;
    bool playerKind(){
        return true;
    }
    ~RemotePlayer(){
    }
private:
    string name;//The name of the player (for example x on console board).
    int boardRows, boardCols;//The rows and columns number.
    Client &client;
    int playerXorY;
};
#endif //REVERSI_REMOTEPLAYER_H
