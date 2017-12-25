/*      student 1: Ahmed Sarsour. 315397059
 *      student 2: Eliad Arzuan.  206482622
 */

#ifndef REVERSI_LISTCOMMAND_H
#define REVERSI_LISTCOMMAND_H
#include "Command.h"
#include <iostream>
//i think there is no need to create this class, we just make a function in the server,
//that sends the vector of available games into the client(the client needs another function).
class ListCommand: public Command {
public:
    //gets an empty vector string. we need to return a list of available games
    void execute(vector<string> args) {
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
        }
        cout << endl;
    }
};

#endif //REVERSI_LISTCOMMAND_H
