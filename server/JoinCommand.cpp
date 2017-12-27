/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#include "JoinCommand.h"
//  Excecutes the commend.
void JoinCommand::execute(vector<string> args, GameCollection &gameCollection) {
    // Getting the name of the game.
    string gameName = args[0];
    int clientSocket2 = atoi(args[1].c_str());
    cout << "Player 2 connected" << endl;
    if (clientSocket2 == -1) {
        throw "Error on accept";
    }
    // Search if there is already game in this name
    if (gameCollection.searchGame(gameName) != -1) {
        gameCollection.joinGame(gameName, clientSocket2);
    } else { // Send -1 to socket
        int x = -1;
        int n = write(clientSocket2, &x, sizeof(x));
        if (n == -1) {
            throw "Error writing arg1 to socket";
        }
    }

    int clientSocket1 = gameCollection.getGame(gameName).getSocket1();
    cout << "socket 1:" << clientSocket1 << endl;

    cout << "socket 2: " << clientSocket2 << endl;
    //Sending activation for player 1 that waited for player 2 to connect.
    // The first player - his number is 1
    sendActivation(clientSocket1);

    handleClients(clientSocket1, clientSocket2);

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