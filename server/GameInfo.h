/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
/**
 * GameInfo.
 * This class holds info about a game - name, currentPlayers and the sockets of the players.
 */

#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <iostream>
using namespace std;
class GameInfo {
public:
    /**
     * The constructor.
     * @param name the name of the game we want to create.
     * Initialize the name, and the other parameters to 0.
     */
    GameInfo(string &name) :
            name(name) {
        // Initializing the sockets to 0.
        this->socket1[0] = 0;
        this->socket2[0] = 0;
        this->numPlayers = new int;
        *numPlayers = 0;
    }
    /**
     * getName
     * @return the name of this game.
     */
    string getName() {
        return this->name;
    }
    /**
     * getNumPlayers.
     * @return the current players in the game.
     */
    int getNumPlayers() {
        return this->numPlayers[0];
    }
    /**
     * getSocket1.
     * @return the socket of the first client.
     */
    int getSocket1() {
        return this->socket1[0];
    }
    /**
     * getSocket2.
     * @return the socket of the second client.
     */
    int getSocket2() {
        return this->socket2[0];
    }
    /**
     * setNumPlayers
     * @param num the number of players we want to set.
     * Setting the number of current players.
     */
    void setNumPlayers(int num) {
        *numPlayers = num;
    }
    /**
     * setSocket1.
     * Setting the socket of the first client.
     * @param sock1 a socket.
     */
    void setSocket1(int sock1) {
        this->socket1[0] = sock1;
    }
    /**
     * setSocket2.
     * Setting the socket of the second client.
     * @param sock2 a socket.
     */
    void setSocket2(int sock2) {
        this->socket2[0] = sock2;
    }

private:
    string name;    //The name of the game.
    int*numPlayers; //The current players in the game.
    int socket1[1]; // Array of 1 int instead of pointer.
    int socket2[1]; // Array of 1 int instead of pointer.
};

#endif //GAMEINFO_H