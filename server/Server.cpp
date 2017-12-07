#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<stdio.h>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2 //2 Players
Server::Server(int port): port(port), serverSocket(0) {
    cout << "server" << endl;
}
void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    // Checks if the binding is ok
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the lib socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    struct sockaddr_in client2Address;
    socklen_t client2AddressLen;

    int playersDivide = 1;
    while (true) {
        cout << "Waiting for the players connections..." << endl;
        // Accept a new player connection
        int clientSocket1 = accept(serverSocket, (struct
                sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Player 1 connected" << endl;

        if (clientSocket1 == -1) {
            throw "Error on accept";
        }
        cout << "Waiting for another opponent..." << endl;
        int clientSocket2 = accept(serverSocket, (struct
                sockaddr *)&client2Address, &client2AddressLen);
        cout << "Player 2 connected" << endl;
        if (clientSocket2 == -1) {
            throw "Error on accept";
        }
        //Sending activation for player 1 that waited for player 2 to connect.
        // The first player - his number is 1
        sendActivation(clientSocket1);

//        x = 2;
//        n = write(serverSocket, &x, sizeof(x));
//        if (n == -1) {
//            throw "Error writing arg1 to socket";
//        }
        handleClients(clientSocket1, clientSocket2);
        // Close communication with the players
        close(clientSocket1);
        close (clientSocket2);
    }
}
// Handle requests from a specific lib
void Server::handleClients(int clientSocket1, int clientSocket2) {
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

void Server::stop() {
    close(serverSocket);
}

void Server::sendActivation(int socket) {
    int x = -1;
    int n = write(socket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
}


void Server::sendInt(int socket, int msg) {
    int x = msg;
    int n = write(socket, &x, sizeof(x));
    if (n == -1) {
        throw "Error writing arg1 to socket";
    }
}


//Send move to the server
void Server::sendMove(int socket, int x, int y) {
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