/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H
#include "Command.h"
#include <iostream>
#include <cstdlib>
/**
 * ListCommand.
 * This command send to the client list of avaliable games that he can join.
 */
class ListCommand: public Command {
public:
    /**
     * Excecute.
     * @param args the arguments to the function to do.
     * In our function we get clientSocket as an argument.
     * @param gameCollection a games collection.
     * @return 0 in our case because we want to continue after it getting commands.
     */
    int execute(vector<string> args, GameCollection *gameCollection);
};
#endif //LISTCOMMAND_H
