/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H
#include "Command.h"
#include <iostream>
#include <cstdlib>

/**
 * StarCommand.
 * This command starts new game that will add to the gameCollection.
 * If there is already game in this name we will send error code -1 to the client.
 */
class StartCommand: public Command {
public:
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * @param gameCollection a games collection.
     * This args - args[0] - gameName args[1] - socket
     */
    void execute(vector<string> args, GameCollection &gameCollection){
        //  The name of the game we want to start.
        string gameName = args[0];
        int clientSocket1 = atoi(args[1].c_str());
        cout << "Player 1 connected" << endl;

        if (clientSocket1 == -1) {
            throw "Error on accept";
        }

        // Search if there is already game in this name
        // There is no already game in this name
        if (gameCollection.searchGame(gameName) == -1) {
            gameCollection.addGame(gameName);
            cout << "Waiting for another opponent..." << endl;
            gameCollection.joinGame(gameName, clientSocket1);
            int x;
            int n = read(clientSocket1, &x, sizeof(x));
            if (n == -1) {
                throw "Error writing arg1 to socket";
            }
        } else { // Send -1 to socket
            int x = -1;
            int n = write(clientSocket1, &x, sizeof(x));
            if (n == -1) {
                throw "Error writing arg1 to socket";
            }
        }





    }
};

#endif //STARTCOMMAND_H
