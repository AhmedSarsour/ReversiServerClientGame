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
#include "ThreadPool.h"
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
   // static void* clientHandle(void * arguments);

    int getSocket();
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
    static string intToStringHelper(int x, string str);
    /**
     * intToString.
     * @param num a number.
     * Here we put empty string and prevent put it all the time.
     * @return the int converted to string.
     */
    static string intToString(int num);

    ThreadPool * getThreadPool(){
        return this->threadPool;
    }
private:
    int port; // The port we want to login the server.
    long serverSocket; // the socket's file descriptor
    pthread_t serverThreadId; //The thread of clients handle in the game.
    ThreadPool* threadPool; //Our thread pool.


};
#endif //SERVER_H
