//
// Created by eliad1998 on 05/12/17.
//

#ifndef SERVER_H
#define SERVER_H
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include <cstdlib>
#include "GameCollection.h"
#include "CommandsManager.h"

class Server {
public:
    /**
     * The constructor of our class
     * @param port
     */
    Server(int port);
    /**
     * Start.
     * Starts the server.
     */
    void start();
    /**
     * Stop.
     * Stops the server.
     */
    void stop();
    void clientHandle(int clientSocket1);
private:
    int port; // The port we want to login the server.
    int serverSocket; // the socket's file descriptor
};


#endif //SERVER_H
