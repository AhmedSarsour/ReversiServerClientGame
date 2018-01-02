/*
 *      student 1: ahmed sarsour 315397059
 *      student 2: Eliad Arzuan  206482622
 */

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
#include <pthread.h>
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
    /**
     * clientHandle: this function handles the commands between the client and the server.
     * @param clientSocket1
     */
    static void clientHandle(int clientSocket1);

    int getSocket() {
        return this->serverSocket;
    }
private:
    int port; // The port we want to login the server.
    int serverSocket; // the socket's file descriptor
    pthread_t serverThreadId; //The thread of clients handle in the game.
    /**
     * readString.
     * Reading a string from socket until space.
     * @return the string it read.
     */
    static string readString(int socket, int *size);
    // Converting int to string - static because we want to use them in static functions.
    /**
     * intToStringHelper
     * @param x a number.
     * @param str an empty string
     * @return the int converted to string.
     */
    static string intToStringHelper(int x, string str) {
        if (x == 0) {
            return str;
        }
        char ch = (char) ((x % 10 + '0'));
        // Put the char in the end because moves by the digits.
        return intToStringHelper(x / 10, str) + ch;
    }
    /**
     * intToString.
     * @param num a number.
     * Here we put empty string and prevent put it all the time.
     * @return the int converted to string.
     */
    static string intToString(int num) {
        return intToStringHelper(num, "");
    }


};
#endif //SERVER_H
