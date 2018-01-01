/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef GAMECOLLECTION_H
#define GAMECOLLECTION_H

#include <vector>
#include <iostream>
#include "GameInfo.h"
using namespace std;
/**
 *  GameCollection.
 *  Collection of games.
 *  Hold all the games that clients added and manage them.
 */
class GameCollection {
private:
    vector<GameInfo> games; //Vector of games.
public:
    /**
     * Default constructor..
     */
    GameCollection() {
    }
    /**
     * addGame.
     * @param game the name of the game we want to add.
     */
    void addGame(string game);
    /**
     * joinGame.
     * Joining a client to the game by updating the current players number in the game and writing the socket of the
     * client.
     * @param game the name of the game we want to join.
     * @param socket the socket of the player we want to join.
     * @return true - succeeded, false- otherwise.
     */
    bool joinGame(string game, int socket); // Socket the socket of the current player
    /**
     * getGame
     * @param game a game name.
     * @return the GameInfo of this game.
     */
    GameInfo getGame(string game);
    /**
     * searchGame.
     * @param game the game name.
     * @return the index of game in games, -1 if didn't found.
     */
    int searchGame(string game);
    /**
     * getAvailableGames
     * @return
     */
    vector<string> getAvailableGames();
    /**
     * removeGame
     * @param game the game we want to remove.
     * Removes the game from the collection.
     */
    void removeGame(string &game) {
        //Finding the index of the game we want to remove.
        int index = searchGame(game);
        //Found the game.
        if (index != -1) {
            // Erasing the game
            this->games.erase(this->games.begin() + index);
        }
    }
/**
 * Closing all the games in this current gameCollection.
 */
    void closeAllGames();
};

#endif //GAMECOLLECTION_H
