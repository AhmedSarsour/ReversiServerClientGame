/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "StartCommand.h"
pthread_mutex_t startMutex;
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
    pthread_mutex_lock(&startMutex);
    int searchGame = gameCollection->searchGame(gameName);
    pthread_mutex_unlock(&startMutex);
    if (searchGame == -1) {
        //Locking - gamecollection is collaborated.
        pthread_mutex_lock(&startMutex);
        gameCollection->addGame(gameName);
        pthread_mutex_unlock(&startMutex); //Unlocking
        cout << "Waiting for another opponent..." << endl;
        // Mutex because gameCollection is collaberated memmory.
        pthread_mutex_lock(&startMutex);
        gameCollection->joinGame(gameName, clientSocket1);
        pthread_mutex_unlock(&startMutex);  // Unlocking the mutex
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
