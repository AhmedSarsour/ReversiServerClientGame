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
    GameInfo(string &name);
    /**
     * getName
     * @return the name of this game.
     */
    string getName();
    /**
     * getNumPlayers.
     * @return the current players in the game.
     */
    int getNumPlayers();
    /**
     * getSocket1.
     * @return the socket of the first client.
     */
    int getSocket1();
    /**
     * getSocket2.
     * @return the socket of the second client.
     */
    int getSocket2();
    /**
     * setNumPlayers
     * @param num the number of players we want to set.
     * Setting the number of current players.
     */
    void setNumPlayers(int num);
    /**
     * setSocket1.
     * Setting the socket of the first client.
     * @param sock1 a socket.
     */
    void setSocket1(int sock1);
    /**
     * setSocket2.
     * Setting the socket of the second client.
     * @param sock2 a socket.
     */
    void setSocket2(int sock2);

    void setThread(pthread_t thread);

    void closeThread();

private:
    string name;    //The name of the game.
    int*numPlayers; //The current players in the game.
    int socket1[1]; // Array of 1 int instead of pointer.
    int socket2[1]; // Array of 1 int instead of pointer.
    pthread_t thread;
};

#endif //GAMEINFO_H