/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "StartCommand.h"
int StartCommand::execute(vector<string> args, GameCollection *gameCollection) {
    //  The name of the game we want to start.
    string gameName = args[0];
    int clientSocket1 = atoi(args[1].c_str());
    cout << "Player 1 connected" << endl;
    if (clientSocket1 == -1) {
        throw "Error on accept";
    }
    // Search if there is already game in this name
    // There is no already game in this name
    if (gameCollection->searchGame(gameName) == -1) {
        gameCollection->addGame(gameName);
        cout << "Waiting for another opponent..." << endl;
        gameCollection->joinGame(gameName, clientSocket1);
        /*
         * writing # to the socket means the client successfully started a game.
         */
        char x = '#';
        int n = write(clientSocket1, &x, sizeof(x));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
        return 1; //OK
    } else { // Send -1 to socket
        char x = '-';
        int n = write(clientSocket1, &x, sizeof(x));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
        return 0; //Didn't start.
    }
}
