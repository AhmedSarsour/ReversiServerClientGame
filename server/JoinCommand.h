/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef JOINCOMMAND_H
#define JOINCOMMAND_H
#include "Command.h"
#include <iostream>
#include "Server.h"
/**
 * JoinCommand.
 * A command to join a player to exists game.
 */
class JoinCommand: public Command {
public:
    typedef struct  {
        int clientSocket2;
        string gameName;
        GameCollection * gameCollection;
        //Server* server;
    }ThreadArgs;
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * @param gameCollection a games collection.
     * This args[0] - gameName args[1] - socket
     * @return 0 - something wrong otherwise - ok
     */
    int execute(vector<string> args, GameCollection *gameCollection);

private:

    /**
    * HandleClients.
    * Handle with the both clients.
    * @param clientSocket1 The socket of the first player.
    * @param clientSocket2 The socket of the second player.
    */
    static void handleClients(int client1Socket, int clientSocket2);
    // Send a message just for the client waiting for it.
    /**
     * SendActivation
     * Sends a message to the player by the socket of the player. The player on the client side will wait untill
     * he got a message (by the function read).
     * @param socket the socket of the specific player.
     */
    static void sendActivation(int socket);
    /**
     * sendInt.
     * Sending int through the socket.
     * @param socket the socket we want to send to.
     * @param msg the message we want to send.
     */
    static void sendInt(int socket, int msg);
    /**
     * sendMove.
     * Sending a move through the socket.
     * @param socket the socket of the other client.
     * @param x the x cordinate.
     * @param y the y cordinate.
     */
    static void sendMove(int socket, int x, int y);


    static void* clientHandle(void * arguments);

};



#endif //JOINCOMMAND_H
