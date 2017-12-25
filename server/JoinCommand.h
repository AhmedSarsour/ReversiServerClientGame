/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_JOINCOMMAND_H
#define REVERSI_JOINCOMMAND_H
#include "Command.h"
#include <iostream>
class JoinCommand: public Command {
public:
    //we get a vector of the name of the game we wanna get. (so maybe we need to make a function that
    //gives us the available list of commands ( a string vector of names might do the job).
    void execute(vector<string> args) {
        //we need to do something like  handleClients(client1, client2);
    }
};

#endif //REVERSI_JOINCOMMAND_H
