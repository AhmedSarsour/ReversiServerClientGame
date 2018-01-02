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
     * @return 0 - something wrong otherwise - ok
     */
    int execute(vector<string> args, GameCollection *gameCollection);
};

#endif //STARTCOMMAND_H
