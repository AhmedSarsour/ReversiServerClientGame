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
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    struct sockaddr_in client2Address;
    socklen_t client2AddressLen;

    int playersDivide = 1;
    while (true) {
        cout << "Waiting for client connections..." << endl;
        // Accept a new client connection
        int clientSocket = accept(serverSocket, (struct
                sockaddr *)&clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;

        if (clientSocket == -1) {
            throw "Error on accept";
        }
        cout << "Waiting for another opponent..." << endl;
        int client2Socket = accept(serverSocket, (struct
                sockaddr *)&client2Address, &client2AddressLen);
        cout << "Client2 connected" << endl;
        if (client2Socket == -1) {
            throw "Error on accept";
        }
//        int x = 1;
//        int n = write(serverSocket, &x, sizeof(x));
//        if (n == -1) {
//            throw "Error writing arg1 to socket";
//        }
//        x = 2;
//        n = write(serverSocket, &x, sizeof(x));
//        if (n == -1) {
//            throw "Error writing arg1 to socket";
//        }
        handleClient(clientSocket, client2Socket);
        // Close communication with the client
        close(clientSocket);
        close (client2Socket);
    }
}
// Handle requests from a specific client
void Server::handleClient(int clientSocket, int client2Socket) {
    int arg1, arg2;
    char op;
    int playersDivide = 1;
    while (true) {
        // Read new exercise arguments
        if (playersDivide % 2 == 1) {
            int n = read(clientSocket, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(clientSocket, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            cout << "X played : (" << arg1 << "," << arg2 << ")" << endl;
        } else {
            int n = read(client2Socket, &arg1, sizeof(arg1));
            if (n == -1) {
                cout << "Error reading arg1" << endl;
                return;
            }
            if (n == 0) {
                cout << "Client disconnected" << endl;
                return;
            }
            n = read(client2Socket, &arg2, sizeof(arg2));
            if (n == -1) {
                cout << "Error reading arg2" << endl;
                return;
            }
            cout << "O played : (" << arg1 << "," << arg2 << ")" << endl;
        }
        playersDivide++;
    }
}

void Server::stop() {
    close(serverSocket);
}