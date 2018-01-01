/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#include <unistd.h>
#include "GameCollection.h"
//  Adding the game.
void GameCollection::addGame(string game) {
// Insert the game to the vector
    this->games.push_back(GameInfo(game));
}
//  Searcing a game.
int GameCollection::searchGame(string game) {
    for (int i = 0; i < this->games.size(); i++) {
        if (this->games[i].getName().compare(game) == 0) {
            return i;
        }
    }
    return -1;
}
//  Getting a game by his name.
GameInfo GameCollection::getGame(string game) {
    // First search the game.
    int search = searchGame(game);
    if (search != -1) {
        return this->games[search];
    }
}
//  Joing the client to the game.
bool GameCollection::joinGame(string game, int socket) {
    //First searching the game.
    int search = searchGame(game);
    if (search == -1) {
        return false;
    }
    // Getting the number of current players in the game.
    int numPlayers = this->games[search].getNumPlayers();
    // Can join the game only if there are no players or 1 player.
    if (numPlayers == 0 || numPlayers == 1) {
        // Increase number of players.
        this->games[search].setNumPlayers(numPlayers + 1);
        if (numPlayers == 0) { // FirstPlayer
            this->games[search].setSocket1(socket);
        }

        if (numPlayers == 1) { // Second player
            this->games[search].setSocket2(socket);
        }
        // Can join the game.
        return true;
    }
    return false;
}
//  Getting the avaliable games.
vector<string> GameCollection::getAvailableGames() {
    vector < string > available;
    for (int i = 0; i < games.size(); i++) {
        // Can join the game - there are zero or 1 players
        // Otherwise won't join to the vector there are already two players.
        if (games[i].getNumPlayers() == 0 || games[i].getNumPlayers() == 1)
            available.push_back(games[i].getName());
    }
    // Return the games the player can join
    return available;
}

void GameCollection::closeAllGames() {
    for (int i = 0; i < this->games.size(); i++) {
        //Getting the sockets of the games
        int socket1 = games[i].getSocket1();
        int socket2 = games[i].getSocket2();
        // In case we created the socket close it
        if (socket1 != 0) {
            close(socket1);
        }
        // In case we created the socket close it
        if (socket2 != 0) {
            cout << "Closing the socket" << socket1 <<  endl;
            close(socket2);
        }

        games[i].closeThread();
    }
}