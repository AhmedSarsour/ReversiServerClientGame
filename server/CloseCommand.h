/*
 *      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */
#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H
#include "Command.h"
#include <iostream>
/**
 * CloseCommand.
 * Close is command that is sent to the server after the player does the last move in the game (because the server
 * does not really know when the game over).
 * In this command the server has to:
   1. Close the game.
   2. Delete it from the game moves.
   3. Close the thread that handles this game.
 */
class CloseCommand: public Command {
public:
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * @param gameCollection a games collection.
     */
    void execute(vector<string> args, GameCollection &gameCollection){
        string gameName = args[0];
        //  Getting the sockets from the gameCollection.
        int clientSocket1 = gameCollection.getGame(gameName).getSocket1();
        int clientSocket2 = gameCollection.getGame(gameName).getSocket2();
        // Close communication with the players
        close(clientSocket1);
        close (clientSocket2);
        // Remove the game from list of games
        gameCollection.removeGame(gameName);
    }
};
#endif //CLOSECOMMAND_H
