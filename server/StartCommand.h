/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_STARTCOMMAND_H
#define REVERSI_STARTCOMMAND_H
#include "Command.h"
#include <iostream>
//firstOfAll, we check the  validity of the given name in the server,
//if the name is valid(no other games with same name). then we execute this class.

//another way is making another function for this class, that function gets a vector
// of available games.
class StartCommand: public Command {
public:
    //i think: we get a vector with only one string in it which is the name of the game.
    void execute(vector<string> args) {

    }
};

#endif //REVERSI_STARTCOMMAND_H
