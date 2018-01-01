/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "JoinCommand.h"
//  Excecutes the commend.
static typedef struct  {
    int clientSocket2;
    string gameName;
    GameCollection * gameCollection;
    // We save pointer to j because we wanna use the join command static functions.
    JoinCommand *joinCommand;
}ThreadArgs;
int JoinCommand::execute(vector<string> args, GameCollection &gameCollection) {

    // Getting the name of the game.
    string gameName = args[0];
    //NOTE: clientSocket2 is the socket for the guy who did join-command!.
    int clientSocket2 = atoi(args[1].c_str());
    if (clientSocket2 == -1) {
        throw "Error on accept";
    }
   // vector<pthread_t> threads;
    // Search if there is already game in this name.
    if (gameCollection.searchGame(gameName) != -1) {
        // Here we will open the thread
        ThreadArgs threadArgs;
        threadArgs.clientSocket2 = atoi(args[1].c_str());
        threadArgs.gameName = args[0];
        threadArgs.gameCollection = &gameCollection;
        threadArgs.joinCommand = this;
        //threads.push_back(NULL);
     //   index++;
       // cout << "Now Index is " << index << endl;
        //pthread_t  t;
        pthread_t  threadId =  gameCollection.getGame(gameName).getThread();
        int rc = pthread_create(&threadId, NULL, clientHandle, &threadArgs);
        if (rc) {
            cout << "Error unable to create thread, " << rc << endl;
            exit(-1);
        }
        return 1;
    }
    else { // Send '+' (as a signal) to the player's socket telling him "no such game".
        char x = '+';
        int n = write(clientSocket2, &x, sizeof(x));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
        return 0;

    }
}
void *JoinCommand::clientHandle(void *arguments) {
    ThreadArgs threadArgs = *((ThreadArgs *) arguments);    //Here we will do the thread
    // Stack after it probably by getting threadargs
    JoinCommand j = *threadArgs.joinCommand;
    // Getting the name of the game.
    string gameName = threadArgs.gameName;

    GameCollection gameCollection = *threadArgs.gameCollection;
    // There is this game.
    // Now we can get the first socket
    int clientSocket1 = gameCollection.getGame(gameName).getSocket1();
    int clientSocket2 = threadArgs.clientSocket2;
    if (clientSocket2 == -1) {
        throw "Error on accept";
    }
    cout << "socket 1:" << clientSocket1 << endl;
    cout << "socket 2: " << threadArgs.clientSocket2 << endl;
    cout << "Player 2 connected" << endl;
    gameCollection.joinGame(gameName, clientSocket2);
    //writing # to the client means he succesfully joined the game.
    char x = '#';
    int n = write(clientSocket2, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    //Sending activation for player 1 that waited for player 2 to connect.
    // The first player - his number is 1
    sendActivation(clientSocket1);

    j.handleClients(clientSocket1, clientSocket2);
}
//  Sending int through the socket.
void JoinCommand::sendInt(int socket, int msg) {
    int x = msg;
    int n = write(socket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
}


//Send move to the server
void JoinCommand::sendMove(int socket, int x, int y) {
    // Write the point arguments to the socket
    int n = write(socket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
    n = write(socket, &y, sizeof(y));
    if (n == -1) {
        throw "Error writing arg2 to socket";
    }
}

// Handle requests from a specific lib
void JoinCommand::handleClients(int clientSocket1, int clientSocket2) {
    int arg1, arg2;
    char op;
    int playersDivide = 1;
    while (true) {
        // Read new exercise arguments
        // The first Player.
        if (playersDivide % 2 == 1) {
            if (playersDivide == 1) {
                sendInt(clientSocket1, 1);
                sendInt(clientSocket2, 2);
            }
            int n = read(clientSocket1, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(clientSocket1, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            cout << "X played : (" << arg1 << "," << arg2 << ")" << endl;
            // Send activation for player 2 that waited for player 1 to do a move.
            // Sending activation just for waiting.
            //sendActivation(clientSocket2);
            // Sending the point arguments to the other player.
            sendMove(clientSocket2, arg1, arg2);
            // The second Player.
        } else {
            int n = read(clientSocket2, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(clientSocket2, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            cout << "O played : (" << arg1 << "," << arg2 << ")" << endl;
            // Sending the point arguments to the other player.
            // sendActivation(clientSocket1);
            sendMove(clientSocket1, arg1, arg2);
            // Sending activation just for waiting.
            // Send activation for player 1 that waited for player 2 to do a move.
        }
        playersDivide++;
    }
}
//  Sending activation to the other player.
    void JoinCommand::sendActivation(int socket) {
        int x = -1;
        int n = write(socket, &x, sizeof(x));
        if (n == -1) {
            throw "Error sending activation";
        }
    }