/*
 *      student 1: ahmed sarsour 315397059
 *      student 2: Eliad Arzuan  206482622
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <unistd.h>
#include <cstdlib>
#include "Point.h"

class Client {
public:
    /**
     * The constructor of our class.
     * We will initialize a socket so we need ip and port.
     * @param serverIP the ip of the server.
     * @param serverPort the port of the server.
     */
    Client(const char *serverIP, int serverPort);
    /**
     * ConnectToServer.
     * Connecting this player to the server.
     */
    void connectToServer();
    /**
     * sendMove.
     * Sending move to the server.
     * @param x x cordinate of the board.
     * @param y y cordinate of the board.
     * @return the move the player sent.
     */
    Point sendMove(int x, int y);
    /**
     * getMove.
     * @return the move from the other player.
     */
    Point getMove();
    /**
     * Wait.
     * The player waiting to get activation message from the server. The process won't stop until he got the message.
     */
    int wait();
    /**
     * writeToSocket:it writes the given string in the client's socket.
     * @param command the command we write to the socket.
     */
    void writeToSocket(string command);
    /**
     * readOperation.
     * @return int.
     * this function reads what the server had written on the socket,
     * and does things according to what it read.
     */
    int readOperation();

    void closeSocket() {
        close(clientSocket);
    }
private:
    const char *serverIP;
    int serverPort;
    int clientSocket; //The socket of this client.
    /**
     * this function reads what the list_games option command had given on the socket.
     * , it prints the list of the available games to the client.
     */
    void readListGames();
/**
 * checkProblem
 * @param n the result of sending to socket.
 * In case of bad result close the communication with the user.
 */
    void checkProblem(int n) {
        if (n == -1) {
            // Closing the client socket.
           // close(clientSocket);
            throw "Error writing to socket probebly the server was closed ";
        }

        if (n == 0) {
            // Closing the client socket.
          //  close(clientSocket);
            throw "Client disconnected";
        }
    }


};

#endif //CLIENT_H
