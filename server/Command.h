/*
 * student 1: Ahmed Sarsour. 315397059
 * student 2: Eliad Arzuan.  206482622
 */

#ifndef COMMAND_H
#define COMMAND_H
#include<vector>
#include <string>
#include "GameCollection.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include<unistd.h>

using namespace std;
/**
 *  Command.
 *  The command interface.
 */
class Command {
public:
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * @param gameCollection a games collection.
     */
    virtual int execute(vector<string> args, GameCollection *gameCollection) {}
    /**
     * The destructor of our class.
     */
    virtual~Command() {}
};
#endif //COMMAND_H
